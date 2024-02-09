/*
   function RouterUpdate
   @param: Sunscription, Routes
   @return: Routes
*/

function RouteUpdate(subscription, routes) {
    let firstSubscribedModule = null;        //Finding the first Subscriber Module
    for (let moduleData of subscription) {
        if (moduleData.isSub) {
            firstSubscribedModule = moduleData.name; 
            break;
        }
    }

    // If no module is subscribed, set all components to 'UN' and redirect to '/'

    if (!firstSubscribedModule) {
        for (let route of routes) {
            route.comp = 'UN';
            route['redirect-to'] = '/';
        }
        return routes;
    }

    // Updating routes based on subscription

    for (let route of routes) {

        let moduleData = subscription.find(data => data.name === route.name);

        if (!moduleData || !moduleData.isSub) {
            route.comp = 'UN';
            route['redirect-to'] = firstSubscribedModule;

        } else if (route.subComp) {

            // Update sub-components based on subscription

            for (let subComp of route.subComp) {
                let subModuleData = moduleData.subMod ? moduleData.subMod.find(data => data.name === subComp.name) : null;
                if (!subModuleData || !subModuleData.isSub) {
                    subComp.comp = 'UN';
                }
            }
        } else {

            // If a module is subscribed, but doesn't have subComp, replace with 'UN'
            
            route.comp = 'UN';
            route['redirect-to'] = firstSubscribedModule;
        }
    }

    return routes;
}

// Given routes and subscription data
const routes = [
    {
        name: 'M1',
        comp: 'C1',
    },
    {
        name: 'M2',
        comp: 'C2',
    },
    {
        name: 'M3',
        subComp: [
            {
                name: 'M3A',
                comp: 'C3A',
            },
            {
                name: 'M3B',
                comp: 'C3B',
            },
        ],
    },
    {
        name: 'M4',
        subComp: [
            {
                name: 'M4A',
                comp: 'C4A',
            },
            {
                name: 'M4B',
                comp: 'C4B',
            },
        ],
    },
    {
        name: 'M5',
        subComp: [
            {
                name: 'M5A',
                comp: 'C5A',
            },
            {
                name: 'M5B',
                subComp: [
                    {
                        name: 'M5BA',
                        comp: 'C5BA',
                    },
                    {
                        name: 'M5BB',
                        comp: 'C5BB',
                    },
                    {
                        name: 'M5BC',
                        comp: 'C5BC',
                    },
                ],
            },
            {
                name: 'M5C',
                comp: 'C5C',
            },
        ],
    },
];

const subscription = [
    {
        name: 'M1',
        isSub: true,
    },
    {
        name: 'M2',
        isSub: false,
    },
    {
        name: 'M3',
        isSub: false,
        subMod: [
            {
                name: 'M3A',
                isSub: true,
            },
            {
                name: 'M3B',
                isSub: true,
            },
        ],
    },
    {
        name: 'M4',
        isSub: true,
        subMod: [
            {
                name: 'M4A',
                isSub: false,
            },
            {
                name: 'M4B',
                isSub: true,
            },
        ],
    },
    {
        name: 'M5',
        isSub: true,
        subMod: [
            {
                name: 'M5A',
                isSub: false,
            },
            {
                name: 'M5B',
                isSub: true,
                subMod: [
                    {
                        name: 'M5BA',
                        isSub: false,
                    },
                    {
                        name: 'M5BB',
                        isSub: true,
                    },
                    {
                        name: 'M5BC',
                        isSub: false,
                    },
                ],
            },
            {
                name: 'M5C',
                isSub: true,
            },
        ],
    },
];

// Call the function to update routes
const updatedRoutes = RouteUpdate(subscription, routes);

// Output the updated routes
console.log(JSON.stringify(updatedRoutes));
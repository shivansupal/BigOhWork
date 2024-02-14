const API_URL = "https://picsum.photos/v2/list";
const imageContainer = document.getElementById("imageContainer");
const likedImagesContainer = document.getElementById("likedImagesContainer");
const searchInput = document.getElementById("searchImageInput");
const paginationContainer = document.getElementById("paginationContainer");
const offsetSelect = document.getElementById("offset");

// Variables
let currentPage = 1;
let totalPages = 1;
let offset = parseInt(offsetSelect.value);

//Search Images Function
function searchImages() {
    const sortFilter = document.getElementById("sortFilter");
    const sortOrder = sortFilter.value;
    const searchTerm = searchInput.value.toLowerCase(); // Convert the search term to lowercase

    fetch(API_URL)
        .then(response => response.json())
        .then(data => {
            if (currentPage === 1) {
                imageContainer.innerHTML = "";
            }

            // Filter images based on the author name
            const filteredData = data.filter(image => image.author.toLowerCase().includes(searchTerm));

            if (sortOrder === "asc") {
                filteredData.sort((a, b) => (a.author > b.author) ? 1 : -1);
            } else if (sortOrder === "desc") {
                filteredData.sort((a, b) => (a.author < b.author) ? 1 : -1);
            }

            filteredData.slice((currentPage - 1) * offset, currentPage * offset).forEach(image => {
                const imageCard = createImageCard(image);
                imageContainer.appendChild(imageCard);
            });

            totalPages = Math.ceil(filteredData.length / offset);
            renderPagination();
        })
        .catch(error => {
            console.error('Error:', error);
        });
}

function renderPagination() {
    paginationContainer.innerHTML = "";

    for (let i = 1; i <= Math.min(totalPages, 4); i++) {
        const pageButton = document.createElement("button");
        pageButton.textContent = i;
        pageButton.addEventListener("click", () => {
            currentPage = i;
            searchImages();
        });

        paginationContainer.appendChild(pageButton);
    }

    if (currentPage < totalPages) {
        const nextButton = document.createElement("button");
        nextButton.textContent = "Next";
        nextButton.addEventListener("click", () => {
            currentPage++;
            searchImages();
        });

        paginationContainer.appendChild(nextButton);
    }
}

// Set Offset Function
function setOffset() {
    offset = parseInt(offsetSelect.value);
    currentPage = 1;
    searchImages();
}

// Create Image Card Function
function createImageCard(image) {
    const imageCard = document.createElement("div");
    imageCard.className = "image-card";

    const imageLink = document.createElement("a");
    imageLink.href = image.url;
    imageLink.target = "_blank";

    const imageElement = document.createElement("div");
    imageElement.className = "image";
    const img = document.createElement("img");
    img.src = image.download_url;
    
    img.alt = image.author;
    imageElement.appendChild(img);

    const authorName = document.createElement("div");
    authorName.className = "author-name";
    authorName.textContent = `Author: ${image.author}`;

    const likeButton = document.createElement("button");
    likeButton.className = "like-button";
    likeButton.textContent = "Like";
    likeButton.addEventListener("click", () => {
        toggleLike(likeButton, image);
    });

    imageLink.appendChild(imageElement);
    imageCard.appendChild(imageLink);
    imageCard.appendChild(authorName);
    imageCard.appendChild(likeButton);

    return imageCard;
}

// Toggle Like Function
function toggleLike(likeButton, image) {
    if (likeButton.textContent === "Like") {
        likeButton.textContent = "Unlike";
        likeButton.style.backgroundColor = "#ff6b6b"; // Change color to indicate liked

        // Add the liked image to local storage
        addLikedImageToStorage(image);

        // Add the liked image to the Liked Images section
        const likedImageCard = createLikedImageCard(image);
        likedImagesContainer.appendChild(likedImageCard);
    } else {
        likeButton.textContent = "Like";
        likeButton.style.backgroundColor = "#4CAF50"; // Reset color

        // Remove the liked image from local storage
        removeLikedImageFromStorage(image.id);

        // Remove the liked image from the Liked Images section
        const likedImageCard = likedImagesContainer.querySelector(`[data-id="${image.id}"]`);
        likedImagesContainer.removeChild(likedImageCard);
    }
}

// Add Liked Image to Storage Function
function addLikedImageToStorage(image) {
    let likedImages = JSON.parse(localStorage.getItem('likedImages')) || [];
    likedImages.push(image);
    localStorage.setItem('likedImages', JSON.stringify(likedImages));
}

// Remove Liked Image from Storage Function
function removeLikedImageFromStorage(imageId) {
    let likedImages = JSON.parse(localStorage.getItem('likedImages')) || [];
    likedImages = likedImages.filter(img => img.id !== imageId);
    localStorage.setItem('likedImages', JSON.stringify(likedImages));
}

// Create Liked Image Card Function
function createLikedImageCard(image) {
    const likedImageCard = document.createElement("div");
    likedImageCard.className = "liked-image-card";
    likedImageCard.setAttribute("data-id", image.id);

    const img = document.createElement("img");
    img.src = image.download_url;
    img.alt = image.author;
    likedImageCard.appendChild(img);

    const likedImageDetails = document.createElement("div");
    likedImageDetails.className = "liked-image-details";
    likedImageDetails.innerHTML = `
        <p class="author">${image.author}</p>
        <button class="unlike-button" onclick="unlikeImage('${image.id}')">Unlike</button>
    `;
    likedImageCard.appendChild(likedImageDetails);

    return likedImageCard;
}

// Unlike Image Function
function unlikeImage(imageId) {
    // Remove the liked image from local storage
    removeLikedImageFromStorage(imageId);

    // Remove the liked image from the Liked Images section
    const likedImageCard = likedImagesContainer.querySelector(`[data-id="${imageId}"]`);
    likedImagesContainer.removeChild(likedImageCard);

    // Reset the Like button in the main image container
    const likeButton = imageContainer.querySelector(`[data-id="${imageId}"] .like-button`);
    if (likeButton) {
        likeButton.textContent = "Like";
        likeButton.style.backgroundColor = "#4CAF50"; // Reset color
    }
}

// Initial Search Images Call

// Rest of your existing JavaScript code remains unchanged

// Initial Search Images Call
searchImages();
            
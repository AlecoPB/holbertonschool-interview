#!/usr/bin/env node

const axios = require('axios');

// Ensure the script receives a movie ID
if (process.argv.length < 3) {
  console.error('Usage: node script.js <Movie ID>');
  process.exit(1);
}

const movieId = process.argv[2]; // Get the movie ID from arguments
const apiUrl = `https://swapi.dev/api/films/${movieId}/`;

// Function to fetch character names
async function fetchCharacterNames() {
  try {
    // Fetch movie details
    const response = await axios.get(apiUrl);
    const filmData = response.data;
    const characters = filmData.characters;

    console.log(`Movie: ${filmData.title}`);
    console.log('Characters:');

    // Fetch character names in order
    for (const characterUrl of characters) {
      const characterResponse = await axios.get(characterUrl);
      console.log(characterResponse.data.name);
    }
  } catch (error) {
    console.error('Error fetching data:', error.message);
  }
}

// Run the function
fetchCharacterNames();

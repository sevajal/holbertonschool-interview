#!/usr/bin/node

const request = require('request');
const movie = process.argv[2];
const url = 'https://swapi.dev/api/films/';
request(url + movie, async function (error, response, body) {
  if (error) {
    throw error;
  } else {
    const characters = JSON.parse(body).characters;
    for (const character of characters) {
      const names = await new Promise((resolve, reject) => {
        request(character, (error, names, bodyCharacters) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(bodyCharacters).name);
          }
        });
      });
      console.log(names);
    }
  }
});

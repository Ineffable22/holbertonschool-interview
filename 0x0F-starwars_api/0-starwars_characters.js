#!/usr/bin/node
const request = require('request');

const URL = 'https://swapi-api.hbtn.io/api/films/';
request.get(URL + process.argv[2], async (error, response, body) => {
  if (response.statusCode === 200 && error === null) {
    const linkChars = JSON.parse(body).characters;
    const linkCharsList = chr => {
      const promise = new Promise((resolve, reject) => {
        request.get(chr, (error, response, body) => {
          if (error) {
            reject(error);
          } else {
            resolve(body);
          }
        });
      });
      return promise;
    };
    for (let i = 0; i < linkChars.length; i++) {
      const result = await linkCharsList(linkChars[i]);
      console.log(JSON.parse(result).name);
    }
  }
});

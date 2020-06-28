var http = require("http");
var express = require('express');
var app = express();
var mysql = require('mysql');
var bodyParser = require('body-parser');

app.use( bodyParser.json() );       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
}));

var server = app.listen(1000, "localhost", function () {
 
  var host = server.address().address
  var port = server.address().port
 
  console.log("Example app listening at http://%s:%s", host, port)
 
});

var connection = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "root",
  database: "db212lab4"
});

app.get('/', function (req, res) {
  res.sendFile(__dirname + '/Index.html')
});

app.get('/about', function (req, res) {
  res.sendFile(__dirname + '/About.html')
});



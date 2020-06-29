var http = require("http");
var express = require('express');
var app = express();
var mysql = require('mysql');
var bodyParser = require('body-parser');
var fs = require('fs');

app.use('/routes',express.static('routes'))
app.use('/Code',express.static('Code'))


app.use( bodyParser.json() );       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
  extended: true
}));

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Our app is running on port ${ PORT }`);
});

// var server = app.listen(1000, "localhost", function () {
 
//   var host = server.address().address
//   var port = server.address().port
 
//   console.log("Example app listening at http://%s:%s", host, port)
 
// });

var folders = fs.readdirSync(__dirname + '/Code');
var folder;

app.get('/Code/DS/Details',function(req,res){
    var files = fs.readdirSync(__dirname + '/Code/DS');
    res.send(JSON.stringify(files))
});

app.get('/Code/Algo/Details',function(req,res){
    var files = fs.readdirSync(__dirname + '/Code/Algo');
    res.send(JSON.stringify(files))
});

app.get('/angular.js',function(req,res){
    res.sendFile(__dirname + '/angular.js')
});

app.get('/', function (req, res) {
  res.sendFile(__dirname + '/Index.html')
});

app.get('/about', function (req, res) {
  res.sendFile(__dirname + '/About.html')
});



var app = angular.module("CodeApp", []);
app.controller("codeCtrl", function($scope,$http) {

  	$scope.products = ["Milk", "Bread", "Cheese"];
	$http.get('/Code/DS/Details')
	   .then(
	       function(response){
	         $scope.DS_files = response.data;
	         console.log(response.data)
	       }, 
	       function(response){
	         // failure call back
	       }
	    );

 	$http.get('/Code/Algo/Details')
   .then(
       function(response){
         $scope.Algo_files = response.data;
         console.log(response.data)
       }, 
       function(response){
         // failure call back
       }
    );

});
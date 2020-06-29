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


fetch('https://api.rss2json.com/v1/api.json?rss_url=https://medium.com/feed/@jinit245')
   .then((res) => res.json())
   .then((data) => {
       // Fillter the array
       const res = data.items //This is an array with the content. No feed, no info about author etc..
       const posts = res.filter(item => item.categories.length > 0) // That's the main trick* !
       
       console.log(res)
       function toText(node) {
         let tag = document.createElement('div')
         tag.innerHTML = node
         node = tag.innerText
         return node
      }
       function shortenText(text,startingPoint ,maxLength) {
       return text.length > maxLength?
          text.slice(startingPoint, maxLength):
          text
      }
      
      let output = '';
      posts.forEach((item) => {
      	$('.blog1Name')[0].innerHTML = item.title;
         output += `
         <div class="blog__post">
           <div class="blog__content">
              <div class="blog_preview">
                 <p class="blog__intro text-left">${item.content}</p>
              </div>
              <hr>
              <div class="blog__info">
                 <span class="blog__author">${item.author} - </span>
                 <span class="blog__date">${shortenText(item.pubDate,0 ,10)}</span>
              </div>
           </div>
         </div>`
      })
      $('.blog1')[0].innerHTML = output
    });

});
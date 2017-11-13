const fs =require("fs");
const path=require("path");
var list="";
var rd = require('rd');
var url= path.resolve(__dirname, '.')
rd.eachSync('../FreeWorldgit', function (f, s) {
  let tail=f.split(".")
  let feng=f.split("\\")


  if(feng.indexOf(".git")!=-1||
  	feng.indexOf("node_modules")!=-1)
  	{
  		return	
  	}
  console.log(f)

  if(tail[1]){
  	f=f.substring(url.length,f.length)+"\n";
  	f="."+f
  	list+="git add "+f+"\n"


  }else{
  	//console.log(f)
  }

	

});
//console.log(list)
// fs.exists(__dirname + '/add.bat', function (exists) {
// 	if(exists){
// 		fs.writeFile(__dirname + "/add.bat", list,  function(err) {});
// 	}else{
// 		fs.writeFile(__dirname + "/add.bat", list,  function(err) {});
// 	}
// });
fs.writeFile(__dirname + "/add.bat", list,  function(err) {});
//appendFile 追加
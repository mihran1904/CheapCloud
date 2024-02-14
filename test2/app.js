// Requiring express to handle routing 
const express = require("express"); 
const bodyParser = require('body-parser');
// The fileUpload npm package for handling 
// file upload functionality 
const fileUpload = require("express-fileupload"); 
const { request } = require("http");
const path = require("path");
// Creating app 
const app = express(); 
const fs = require('fs');


// Passing fileUpload as a middleware 
app.use(fileUpload()); 
app.use(bodyParser.json());
app.use(express.urlencoded({extended:true}));
// For handling the upload request 

app.post("/upload", function (req, res) { 

// When a file has been uploaded 
if (req.files && Object.keys(req.files).length !== 0) { 
	
	// Uploaded path 
	const uploadedFile = req.files.uploadFile; 

	// Logging uploading file 
	console.log(uploadedFile); 

	// Upload path 
	const uploadPath = __dirname 
		+ "/uploads/" + uploadedFile.name; 

	// To save the file using mv() function 
	uploadedFile.mv(uploadPath, function (err) { 
	if (err) { 
		console.log(err); 
		res.send("Failed !!"); 
	} else res.send("Successfully Uploaded !!"); 
	}); 
} else res.send("No file uploaded !!"); 
}); 

let fileName;

app.post('/fileNameInput',(req, res) => {
    const fileName = req.body.fileName;
    fileName = res.status(201).JSON.stringify(fileName);
    console.log("file name:" + fileName);
});
// To handle the download file request 
app.get("/download", function (req, res) { 
// logic for search file in directory for download
// start the search in the current directory
//searchFile('./', fileName);
fileName = req.body.fileName;
console.log(res.status(201).json(fileName));
const filePath = path.resolve("/uploads","fileName");
console.log(filePath);
res.send("fileName");
    // The res.download() talking file path to be downloaded 
    res.download(__dirname,filePath, function (err) { 
        if (err) { 
            res.send({
                error : err,
                msg   : "Problem downloading the file"
            })
        } 
    });
 
}); 

// GET request to the root of the app 
app.get("/", function (req, res) { 

// Sending index.html file as response to the client 
res.sendFile(__dirname + "/index.html"); 
}); 

// Makes app listen to port 3000 
app.listen(3000, function (req, res) { 
console.log("Started listening to port 3000"); 
});

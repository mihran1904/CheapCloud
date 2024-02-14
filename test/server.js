const express = require('express');
const path = require('path');
const morgan = require('morgan');
const fileUpload = require('express-fileupload');
const app = express();
const fs = require('fs');
app.set('view engine', 'ejs');

const PORT = 3000;

const createPath = (page) => path.resolve(__dirname, 'ejs-views', `${page}.ejs`);

app.listen(PORT, (error) => {
  error ? console.log(error) : console.log(`listening port ${PORT}`);
});

app.use(morgan(':method :url :status :res[content-length] - :response-time ms'));

app.use(fileUpload()); 

app.use(express.urlencoded({ extended: false }));

app.use(express.static('styles'));

app.get('/', (req, res) => {
    const title = 'Home';
    res.render(createPath('index'), { title });
  });

app.post('/fileUpload-post', (req, res) => {

  // When a file has been uploaded 
if (req.files && Object.keys(req.files).length !== 0) { 
	
	// Uploaded path 
	const uploadedFile = req.files.uploadFile; 

	// Logging uploading file 
	console.log(uploadedFile); 

	// Upload path 
	const uploadPath = __dirname 
		+ "/uploaded_files/" + uploadedFile.name; 

	// To save the file using mv() function 
	uploadedFile.mv(uploadPath, function (err) { 
	if (err) { 
		console.log(err); 
		res.send("Failed !!"); 
	} else 
  res.send("Successfully Uploaded !!"); 
	}); 
} else res.send("No file uploaded !!");
});


app.get('/file-upload', (req, res) => {
  const title = 'File-Upload';
  res.render(createPath('file-upload'), { title });
});
// for download file
app.post('/fileDownload-post',(req,res) => {
  const fileName = req.body.title;

  // Check if the file exists in the 'uploaded' directory
  const filePath = path.join(__dirname, 'uploaded_files', fileName);
  if (fs.existsSync(filePath)) {
    // If the file exists, initiate a download
    res.download(filePath, fileName, (err) => {
      if (err) {
        console.error(err);
        res.status(500).send('Internal Server Error');
      }
    });
  } else {
    // If the file doesn't exist, send an error response
    res.status(404).send('File not found');
  }
})

app.get('/download-file',(req,res) => {
  const title = 'File-Download';
  res.render(createPath('download-file'),{ title });
})

app.use((req, res) => {
  const title = 'Error Page';
  res
    .status(404)
    .render(createPath('error'), { title });
});





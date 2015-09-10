## How to run
1. [Download](http://sourceforge.net/projects/levent/files/libevent/libevent-2.1/libevent-2.1.5-beta.tar.gz/download)
2. Install libevent  

     ```
     $ ./configure   
     $ make    
     $ sudo make install   
     ```
     
2. Run makefile 
     ```
     make
     ```
3. Server is now running.  
Open your browser and go to `http://localhost:8080/[FILE_NAME.html]` 

## Configuring
1. The default html directory is in `html` folder.  
2. The default port is `8080`
3. The `html folder` and `port` can be changed in the `server.config` file

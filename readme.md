## How to Run
1. [Install](https://github.com/libevent/libevent) libevent on your machine.
2. Compile `main.cpp`  

      g++ -o tes main.cpp -levent

3. Run `./tes`
4. Open your browser and head to `http://localhost:8080/[FILE_NAME.html]` 

## Few things you need to know
1. The default html directory is `html`.  
This can be changed this by altering the `html_dir` variable in `main.cpp`.  
In the future, this html directory should be able to be changed from a configuration file.  
2. Program still returning a segmentation fault when using port 80. I don't know why.   
For now just use port 8080 instead.
3. This program still need really much improvement.

## Reference
1. https://www.ruilog.com/notebook/view/6dff2291fe2e.html
2. https://github.com/libevent/libevent/blob/master/sample/http-server.c
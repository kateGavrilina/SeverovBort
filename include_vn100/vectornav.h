/**
 * \file
 *
 * \section LICENSE
 * MIT License (MIT)
 *
 * Copyright (c) 2011 VectorNav Technologies, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * \section DESCRIPTION
 * This header file includes all of the header file inclusions needed to use
 * all of the features of the VectorNav C/C++ Library.
 *
 * \mainpage VectorNav C/C++ Library
 * The VectorNav C/C++ Library allows interfacing with VectorNav's orientation
 * and inertial sensor products.
 *
 * \section Samples
 * The folder <em>samples</em> contains sample projects that can be immediately
 * compiled in various environments. The following sections walk through compiling
 * and running the samples provided.
 *
 * \section linuxSample Linux Sample
 *
 * -# Open the file <tt>main.c</tt> and change the configuration defines at the
 *    top to your environment specifics.
 *     - For the COM_PORT define, normal physical COM ports typically will be
 *       in the form of <tt>/dev/ttyS1</tt>. If you are using an FTDI
 *       USB-to-Serial chip (typically found on USB cables supplied with VN-100
 *       Rugged Kits or on a VN-100 Development Board), the necessary drivers
 *       are already include in kernel version 2.6.31 and later and can be
 *       accessed in the form of <tt>/dev/ttyUSB0</tt>.
 *     - For the BAUD_RATE define, change it to the currently saved baudrate
 *       speed of your VectorNav device.
 * -# From a terminal window, browse to the folder <em>samples/linux</em> and
 *    compile by typing the command <tt>make</tt>.
 * -# The sample program may then be run by executing the command <tt>./main</tt> .
 *        - Some Linux flavors may require administrative access to the COM
 *          port. If you receive an error message indicating invalid access
 *          privileges, try exeucting the command as <tt>sudo ./main</tt> .
 *
 * \section includingInExistingProject Including in Existing Projects
 * The following sections provide guidance for using the library in your project.
 *
 * \subsection microsoftVisualStudioUsage Microsoft Visual Studio
 * The following steps will walk you through including the VectorNav C/C++ Library
 * into your existing C or C++ project. You can also find an example usage of the
 * library at \ref windows_basic.c "windows_basic.c".
 *
 * -# Add the code files src/vn100.c and src/arch/win32/vncp_services.c to your project.
 *     - Right-click on your project file and select <em>Add -> Existing Item...</em> and browse
 *       to where you extracted the library files and select the two file.
 * -# Add an additional include directory to the libraries \c include folder.
 *     - Right-click on your project file and select Properties. On the property
 *       pages, browse to <em>Configuration Properties -> C/C++ -> General</em>. For the property
 *       field <em>Additional Include Directories</em>, add a link to the library's
 *       \c include folder.
 * -# Disable usage of precompiled headers for your project.
 *     - Right-click on your project file and select Properties. Browse to the section
 *       <em>Configuration Properties -> C/C++ -> Precompiled Header</em> and select the option
 *       <em>Not Using Precompiled Headers</em>.
 * -# Add the include line <tt>#include "vectornav.h"</tt> to the top of your code file
 *    to get access to all of the types and functions provided by the library.
 *
 * \subsection linuxUsage Linux
 * The following steps will walk you through adding the VectorNav C/C++ Library
 * to your Linux project. You can also find an example usage of the library at
 * \ref linux_basic.c "linux_basic.c".
 *
 * -# Add lines to your makefile to compile the code files src/vn100.c and src/arch/linux/vncp_services.c.
 *     - Example lines...
 *         - <tt>gcc -c -Iinclude src/vn100.c</tt>
 *         - <tt>gcc -c -Iinclude src/arch/linux/vncp_services.c</tt>
 * -# When you link the all of the compiled files together, you will need to
 *    add a reference to the pthread library as well as the output object files
 *    from the previous step.
 *     - Example linker command: <tt>gcc -lpthread main.o vn100.o vncp_services.o -o main</tt>
 * -# In code files where you wish to access the functionality of the library,
 *    add the line <tt>#include "vectornav.h"</tt> at the top of the code file.
 *    You will also need to add a reference to the include directory when you
 *    compile your code file.
 *
 * \example windows_basic.c
 * Here is an example of using compling the library on Windows using Microsoft's
 * Visual Studio. This example will open a connection to a VN-100 device,
 * display the current yaw, pitch, roll attitude for ten seconds, and then
 * close the connection to the device. Note that in this examples, the thread calling
 * the function \ref vn100_getYawPitchRoll will block for several milliseconds while the
 * underlying function mechanisms sends a request to the VN-100 sensor over the
 * serial port and waits for a response. If it is important to not block the thread,
 * consider only retrieving the latest asynchronous data packet received from the
 * sensor by calling the function \ref vn100_getCurrentAsyncData. An example of
 * using this function may be found in \ref windows_async.c "windows_async.c".
 *
 * \example windows_async.c
 * This example shows how to retrieve the lastest asynchronous data packet received
 * from the VN-100 sensor by using the function \ref vn100_getCurrentAsyncData. This
 * function is useful since it does not block while a command transaction is performed
 * with the sensor. The library's backend thread is constantly servicing the COM port
 * and when asychronous data is received from the sensor, it saves a copy in memory
 * making it immediately accessible on the call to \ref vn100_getCurrentAsyncData.
 *
 * \example linux_basic.c
 * This example shows how to use the VectorNav C/C++ Library in a Linux based
 * environment. This example will opan a connection to a VN-100 device, display
 * the current yaw, pitch, roll attitude for ten seconds, and then close the
 * connection to the device. Note that in this examples, the thread calling
 * the function \ref vn100_getYawPitchRoll will block for several milliseconds while the
 * underlying function mechanisms sends a request to the VN-100 sensor over the
 * serial port and waits for a response. If it is important to not block the thread,
 * consider only retrieving the latest asynchronous data packet received from the
 * sensor by calling the function \ref vn100_getCurrentAsyncData. An example of
 * using this function may be found in \ref linux_async.c "linux_async.c".
 *
 * \example linux_async.c
 * This example shows how to retrieve the lastest asynchronous data packet received
 * from the VN-100 sensor by using the function \ref vn100_getCurrentAsyncData. This
 * function is useful since it does not block while a command transaction is performed
 * with the sensor. The library's backend thread is constantly servicing the COM port
 * and when asychronous data is received from the sensor, it saves a copy in memory
 * making it immediately accessible on the call to \ref vn100_getCurrentAsyncData.
 */
#ifndef _VECTORNAV_H_
#define _VECTORNAV_H_

#include "include_vn100/vn100.h"
#include "include_vn100/vn_math.h"

#endif /* VECTORNAV_H */

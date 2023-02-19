New-Item -ItemType Directory -Force -Path bin
New-Item -ItemType Directory -Force -Path obj

gcc -Iinc\ -c .\src\ihashi.c -o .\obj\ihashi.o
gcc -Iinc\ -c .\src\defs.c -o .\obj\defs.o
ar rvs .\bin\libihashi.a .\obj\ihashi.o .\obj\defs.o
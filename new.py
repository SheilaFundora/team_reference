import os.path as path
import sys

if __name__ == '__main__':

    if len( sys.argv ) == 1:
        sys.stdout.write( "new < new_file_name > < relative path >...\n" )
        sys.exit(0)

    path_real = str( path.split( sys.argv[0] )[0] )

    # DEBUG
    # sys.argv.append( "main.py"); sys.argv.append("Input")
    # print( path_real )

    for i in range( 2, len( sys.argv )):
        path_real += ( path.sep )
        path_real += ( sys.argv[ i ] )

    path_real += ( path.sep + sys.argv[ 1 ] )

    try:
        file = open( path_real, "x" )
        ext = path_real.split( "." )[-1]
        if ext == "cpp":
            file.write( "#include <bits/stdc++.h>\n\nusing namespace std; \n\nint main(){\n\n\treturn 0;\n}" )
        elif ext == 'h':
            file.write( "#include <bits/stdc++.h>\n\nusing namespace std;\n\n" )
        elif ext == 'py':
            file.write( "import sys\nimport math\n\n\n\nif __name__ == \"__main__\":\n\n\tpass\n")
        else:
            file.write( path_real )
    except FileExistsError:
        sys.stdout.write( "new < new_file_name > < relative path >...\n" )
        sys.stdout.write( "File exist...:\n" + path_real )
    else:
        file.close()

class Solution {
public:
    string entityParser(string text) {
        string retval;
        for(int pos=0; pos<text.length(); ++pos){
            if( text[pos] == '&' ) {
                string::size_type end = text.find(';',pos);
                bool match = false;
                if( end != string::npos ){
                    switch(end - pos){
                        case 6: if( !text.compare(pos,7,"&frasl;",0,7) ){ retval += '/'; match = true; } break; // warning: mess with length/position a bit
                        case 4: if( !text.compare(pos,5,"&amp;",0,5)   ){ retval += '&'; match = true; } break; // error: forgot to put '!' / invert result
                        case 3: if( !text.compare(pos,4,"&gt;",0,4)    ){ retval += '>'; match = true; }
                                if( !text.compare(pos,4,"&lt;",0,4)    ){ retval += '<'; match = true; } break;
                        case 5: if( !text.compare(pos,5,"&quot;",0,5)  ){ retval += '"'; match = true; }
                                if( !text.compare(pos,5,"&apos;",0,5)  ){ retval +='\''; match = true; } break;
                    }
                }
                if( match ) pos = end;
                else retval += text[pos]; // error: typo '=' -> '+='
            } else
                retval += text[pos];            
        }
        return retval;
    }
};

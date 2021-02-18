xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 204;
 13.03062;30.24969;60.99688;,
 19.51633;23.37639;43.20650;,
 19.51633;26.75650;41.90066;,
 13.03062;33.62977;59.69099;,
 -21.29186;36.91025;55.90941;,
 -21.29186;29.55617;36.87462;,
 -39.52812;29.55617;36.87462;,
 -39.52812;36.91025;55.90941;,
 -25.36782;35.67502;54.88936;,
 -25.36782;29.32771;38.46016;,
 -25.36782;20.09875;42.02578;,
 -25.36782;26.44615;58.45498;,
 -39.52812;26.21759;60.04053;,
 -39.52812;18.86358;41.00572;,
 -21.29186;18.86358;41.00572;,
 -21.29186;26.21759;60.04053;,
 -21.29186;18.86358;41.00572;,
 -39.52812;18.86358;41.00572;,
 -39.52812;29.55617;36.87462;,
 -39.52812;64.52440;145.92894;,
 -21.29186;64.52440;145.92894;,
 -21.29186;66.29999;145.24298;,
 -39.52812;66.29999;145.24298;,
 -39.52812;26.21759;60.04053;,
 -21.29186;26.21759;60.04053;,
 -21.29186;33.61187;79.17961;,
 -39.52812;33.61187;79.17961;,
 6.50946;40.54063;77.57877;,
 6.50946;37.16046;78.88465;,
 -39.52812;36.91025;55.90941;,
 -39.52812;44.30462;75.04862;,
 -21.29186;44.30462;75.04862;,
 -26.24227;36.68064;57.52934;,
 -26.24227;27.47672;61.08529;,
 -26.24227;33.84155;77.55975;,
 -26.24227;43.04549;74.00372;,
 -21.29186;41.04411;98.41651;,
 -39.52812;41.04411;98.41651;,
 -0.04507;47.48684;95.55798;,
 -0.04509;44.10672;96.86388;,
 -39.52812;51.73668;94.28542;,
 -21.29186;51.73668;94.28542;,
 -25.68168;44.07354;76.70393;,
 -25.68168;34.89594;80.24967;,
 -25.68168;41.27497;96.76118;,
 -25.68168;50.45280;93.21534;,
 -21.29186;48.00179;116.42570;,
 -39.52812;48.00179;116.42570;,
 -6.18127;53.98977;112.38972;,
 -6.18127;50.60960;113.69553;,
 -39.52812;58.69457;112.29464;,
 -21.29186;58.69457;112.29464;,
 -25.33406;51.50127;95.68147;,
 -25.33406;42.15702;99.29154;,
 -25.33406;48.23733;115.02975;,
 -25.33406;57.58173;111.41959;,
 -21.29186;54.94220;134.38992;,
 -39.52812;54.94220;134.38992;,
 -12.30217;60.47640;129.17923;,
 -12.30217;57.09629;130.48509;,
 -39.52812;65.63493;130.25882;,
 -21.29186;65.63493;130.25882;,
 -24.88130;58.41774;113.92474;,
 -24.88130;49.30286;117.44630;,
 -24.88130;55.21906;132.75972;,
 -24.88130;64.33401;129.23816;,
 -21.29186;59.66172;142.76517;,
 -39.52812;59.66172;142.76517;,
 -15.32580;63.27256;137.63094;,
 -15.32580;60.70874;138.62146;,
 -39.52812;67.77248;139.63153;,
 -21.29186;67.77248;139.63153;,
 -28.75738;65.15231;131.12286;,
 -28.75738;55.88055;134.70500;,
 -28.75738;59.97281;141.96732;,
 -28.75738;67.00571;139.25032;,
 -16.82077;63.85561;142.11853;,
 -16.82077;63.29436;142.33539;,
 -39.52812;29.32771;38.46016;,
 -39.52812;35.67502;54.88936;,
 -39.52812;20.09875;42.02578;,
 -39.52812;26.44615;58.45498;,
 -39.52812;27.47672;61.08529;,
 -39.52812;36.68064;57.52934;,
 -39.52812;33.84155;77.55975;,
 -39.52812;43.04549;74.00372;,
 -39.52812;34.89594;80.24967;,
 -39.52812;44.07354;76.70393;,
 -39.52812;41.27497;96.76118;,
 -39.52812;50.45280;93.21534;,
 -39.52812;42.15702;99.29154;,
 -39.52812;51.50127;95.68147;,
 -39.52812;48.23733;115.02975;,
 -39.52812;57.58173;111.41959;,
 -39.52812;49.30286;117.44630;,
 -39.52812;58.41774;113.92474;,
 -39.52812;55.21906;132.75972;,
 -39.52812;64.33401;129.23816;,
 -39.52812;55.88055;134.70500;,
 -39.52812;65.15231;131.12286;,
 -39.52812;59.97281;141.96732;,
 -39.52812;67.00571;139.25032;,
 13.03062;30.24969;-60.99688;,
 13.03062;33.62977;-59.69099;,
 19.51633;26.75650;-41.90066;,
 19.51633;23.37639;-43.20650;,
 -21.29186;36.91025;-55.90941;,
 -39.52812;36.91025;-55.90941;,
 -39.52812;29.55617;-36.87462;,
 -21.29186;29.55617;-36.87462;,
 -25.36782;35.67502;-54.88936;,
 -25.36782;26.44615;-58.45498;,
 -25.36782;20.09875;-42.02574;,
 -25.36782;29.32771;-38.46016;,
 -39.52812;26.21760;-60.04053;,
 -21.29186;26.21760;-60.04053;,
 -21.29186;18.86358;-41.00572;,
 -39.52812;18.86358;-41.00572;,
 -21.29186;18.86358;-41.00572;,
 -39.52812;29.55617;-36.87462;,
 -39.52812;18.86358;-41.00572;,
 -39.52812;64.52440;-145.92894;,
 -39.52812;66.29999;-145.24298;,
 -21.29186;66.29999;-145.24298;,
 -21.29186;64.52440;-145.92894;,
 -39.52812;26.21760;-60.04053;,
 -39.52812;33.61187;-79.17961;,
 -21.29186;33.61187;-79.17961;,
 -21.29186;26.21760;-60.04053;,
 6.50946;37.16051;-78.88465;,
 6.50946;40.54063;-77.57877;,
 -21.29186;44.30459;-75.04854;,
 -39.52812;44.30459;-75.04854;,
 -39.52812;36.91025;-55.90941;,
 -26.24227;36.68064;-57.52934;,
 -26.24227;43.04549;-74.00372;,
 -26.24227;33.84155;-77.55975;,
 -26.24227;27.47672;-61.08531;,
 -39.52812;41.04411;-98.41651;,
 -21.29186;41.04411;-98.41651;,
 -0.04509;44.10672;-96.86388;,
 -0.04507;47.48680;-95.55798;,
 -21.29186;51.73668;-94.28542;,
 -39.52812;51.73668;-94.28542;,
 -25.68168;44.07354;-76.70393;,
 -25.68168;50.45280;-93.21534;,
 -25.68168;41.27497;-96.76118;,
 -25.68168;34.89594;-80.24967;,
 -39.52812;48.00179;-116.42570;,
 -21.29186;48.00179;-116.42570;,
 -6.18127;50.60960;-113.69558;,
 -6.18127;53.98977;-112.38973;,
 -21.29186;58.69458;-112.29464;,
 -39.52812;58.69458;-112.29464;,
 -25.33406;51.50127;-95.68147;,
 -25.33406;57.58173;-111.41959;,
 -25.33406;48.23733;-115.02978;,
 -25.33406;42.15702;-99.29154;,
 -39.52812;54.94225;-134.38992;,
 -21.29186;54.94225;-134.38992;,
 -12.30217;57.09629;-130.48509;,
 -12.30217;60.47634;-129.17923;,
 -21.29186;65.63493;-130.25882;,
 -39.52812;65.63493;-130.25882;,
 -24.88130;58.41774;-113.92474;,
 -24.88130;64.33401;-129.23816;,
 -24.88130;55.21906;-132.75961;,
 -24.88130;49.30286;-117.44630;,
 -39.52812;59.66172;-142.76517;,
 -21.29186;59.66172;-142.76517;,
 -15.32580;60.70874;-138.62146;,
 -15.32580;63.27256;-137.63094;,
 -21.29186;67.77248;-139.63153;,
 -39.52812;67.77248;-139.63153;,
 -28.75738;65.15231;-131.12286;,
 -28.75738;67.00571;-139.25032;,
 -28.75738;59.97281;-141.96725;,
 -28.75738;55.88055;-134.70500;,
 -16.82077;63.29436;-142.33539;,
 -16.82077;63.85561;-142.11853;,
 -39.52812;35.67502;-54.88936;,
 -39.52812;29.32771;-38.46016;,
 -39.52812;20.09875;-42.02574;,
 -39.52812;26.44615;-58.45498;,
 -39.52812;36.68064;-57.52934;,
 -39.52812;27.47672;-61.08531;,
 -39.52812;33.84155;-77.55975;,
 -39.52812;43.04549;-74.00372;,
 -39.52812;44.07354;-76.70393;,
 -39.52812;34.89594;-80.24967;,
 -39.52812;41.27497;-96.76118;,
 -39.52812;50.45280;-93.21534;,
 -39.52812;51.50127;-95.68147;,
 -39.52812;42.15702;-99.29154;,
 -39.52812;48.23733;-115.02978;,
 -39.52812;57.58173;-111.41959;,
 -39.52812;58.41774;-113.92474;,
 -39.52812;49.30286;-117.44630;,
 -39.52812;55.21906;-132.75961;,
 -39.52812;64.33401;-129.23816;,
 -39.52812;65.15231;-131.12286;,
 -39.52812;55.88055;-134.70500;,
 -39.52812;59.97281;-141.96725;,
 -39.52812;67.00571;-139.25032;;
 
 188;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,5;,
 4;19,20,21,22;,
 4;23,24,25,26;,
 4;0,3,27,28;,
 4;4,29,30,31;,
 4;32,33,34,35;,
 4;26,25,36,37;,
 4;28,27,38,39;,
 4;31,30,40,41;,
 4;42,43,44,45;,
 4;37,36,46,47;,
 4;39,38,48,49;,
 4;41,40,50,51;,
 4;52,53,54,55;,
 4;47,46,56,57;,
 4;49,48,58,59;,
 4;51,50,60,61;,
 4;62,63,64,65;,
 4;57,56,66,67;,
 4;59,58,68,69;,
 4;61,60,70,71;,
 4;72,73,74,75;,
 4;67,66,20,19;,
 4;69,68,76,77;,
 4;71,70,22,21;,
 4;70,67,19,22;,
 4;7,6,78,79;,
 4;6,13,80,78;,
 4;13,12,81,80;,
 4;12,7,79,81;,
 4;79,78,9,8;,
 4;78,80,10,9;,
 4;80,81,11,10;,
 4;81,79,8,11;,
 4;29,23,82,83;,
 4;23,26,84,82;,
 4;26,30,85,84;,
 4;30,29,83,85;,
 4;83,82,33,32;,
 4;82,84,34,33;,
 4;84,85,35,34;,
 4;85,83,32,35;,
 4;30,26,86,87;,
 4;26,37,88,86;,
 4;37,40,89,88;,
 4;40,30,87,89;,
 4;87,86,43,42;,
 4;86,88,44,43;,
 4;88,89,45,44;,
 4;89,87,42,45;,
 4;40,37,90,91;,
 4;37,47,92,90;,
 4;47,50,93,92;,
 4;50,40,91,93;,
 4;91,90,53,52;,
 4;90,92,54,53;,
 4;92,93,55,54;,
 4;93,91,52,55;,
 4;50,47,94,95;,
 4;47,57,96,94;,
 4;57,60,97,96;,
 4;60,50,95,97;,
 4;95,94,63,62;,
 4;94,96,64,63;,
 4;96,97,65,64;,
 4;97,95,62,65;,
 4;60,57,98,99;,
 4;57,67,100,98;,
 4;67,70,101,100;,
 4;70,60,99,101;,
 4;99,98,73,72;,
 4;98,100,74,73;,
 4;100,101,75,74;,
 4;101,99,72,75;,
 4;24,16,1,0;,
 4;16,5,2,1;,
 4;5,4,3,2;,
 4;4,31,27,3;,
 4;25,24,0,28;,
 4;31,41,38,27;,
 4;36,25,28,39;,
 4;41,51,48,38;,
 4;46,36,39,49;,
 4;51,61,58,48;,
 4;56,46,49,59;,
 4;61,71,68,58;,
 4;66,56,59,69;,
 4;71,21,76,68;,
 4;21,20,77,76;,
 4;20,66,69,77;,
 4;102,103,104,105;,
 4;106,107,108,109;,
 4;110,111,112,113;,
 4;114,115,116,117;,
 4;118,109,119,120;,
 4;121,122,123,124;,
 4;125,126,127,128;,
 4;102,129,130,103;,
 4;106,131,132,133;,
 4;134,135,136,137;,
 4;126,138,139,127;,
 4;129,140,141,130;,
 4;131,142,143,132;,
 4;144,145,146,147;,
 4;138,148,149,139;,
 4;140,150,151,141;,
 4;142,152,153,143;,
 4;154,155,156,157;,
 4;148,158,159,149;,
 4;150,160,161,151;,
 4;152,162,163,153;,
 4;164,165,166,167;,
 4;158,168,169,159;,
 4;160,170,171,161;,
 4;162,172,173,163;,
 4;174,175,176,177;,
 4;168,121,124,169;,
 4;170,178,179,171;,
 4;172,123,122,173;,
 4;173,122,121,168;,
 4;107,180,181,108;,
 4;108,181,182,117;,
 4;117,182,183,114;,
 4;114,183,180,107;,
 4;180,110,113,181;,
 4;181,113,112,182;,
 4;182,112,111,183;,
 4;183,111,110,180;,
 4;133,184,185,125;,
 4;125,185,186,126;,
 4;126,186,187,132;,
 4;132,187,184,133;,
 4;184,134,137,185;,
 4;185,137,136,186;,
 4;186,136,135,187;,
 4;187,135,134,184;,
 4;132,188,189,126;,
 4;126,189,190,138;,
 4;138,190,191,143;,
 4;143,191,188,132;,
 4;188,144,147,189;,
 4;189,147,146,190;,
 4;190,146,145,191;,
 4;191,145,144,188;,
 4;143,192,193,138;,
 4;138,193,194,148;,
 4;148,194,195,153;,
 4;153,195,192,143;,
 4;192,154,157,193;,
 4;193,157,156,194;,
 4;194,156,155,195;,
 4;195,155,154,192;,
 4;153,196,197,148;,
 4;148,197,198,158;,
 4;158,198,199,163;,
 4;163,199,196,153;,
 4;196,164,167,197;,
 4;197,167,166,198;,
 4;198,166,165,199;,
 4;199,165,164,196;,
 4;163,200,201,158;,
 4;158,201,202,168;,
 4;168,202,203,173;,
 4;173,203,200,163;,
 4;200,174,177,201;,
 4;201,177,176,202;,
 4;202,176,175,203;,
 4;203,175,174,200;,
 4;128,102,105,118;,
 4;118,105,104,109;,
 4;109,104,103,106;,
 4;106,103,130,131;,
 4;127,129,102,128;,
 4;131,130,141,142;,
 4;139,140,129,127;,
 4;142,141,151,152;,
 4;149,150,140,139;,
 4;152,151,161,162;,
 4;159,160,150,149;,
 4;162,161,171,172;,
 4;169,170,160,159;,
 4;172,171,179,123;,
 4;123,179,178,124;,
 4;124,178,170,169;;
 
 MeshMaterialList {
  12;
  188;
  11,
  11,
  4,
  11,
  11,
  11,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  4,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  4,
  4,
  4,
  4,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11;;
  Material {
   0.640000;0.640000;0.640000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.800000;0.784314;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;1.000000;0.980392;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.656000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.511373;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.639216;0.000000;;
  }
  Material {
   0.000000;0.800000;0.784000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.621176;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.614902;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.781176;0.762353;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.621176;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  167;
  0.049914;-0.928888;0.366981;,
  0.045049;-0.929352;0.366436;,
  0.064443;0.934342;-0.350504;,
  0.058194;0.934393;-0.351458;,
  0.000000;0.932803;-0.360387;,
  0.000000;0.932803;-0.360388;,
  0.000000;-0.932804;0.360384;,
  0.000000;-0.932804;0.360384;,
  0.000000;-0.932803;0.360387;,
  0.062386;-0.927611;0.368301;,
  0.080414;0.934020;-0.348051;,
  0.000000;0.932804;-0.360385;,
  0.000000;-0.932804;0.360386;,
  0.082742;-0.925233;0.370267;,
  0.106273;0.932955;-0.343949;,
  0.000000;0.932803;-0.360387;,
  0.000000;-0.932805;0.360383;,
  0.121621;-0.919758;0.373167;,
  0.154548;0.929069;-0.336075;,
  0.000000;0.932803;-0.360387;,
  0.000000;-0.904360;0.426770;,
  0.182064;-0.882664;0.433310;,
  0.228392;0.937254;-0.263422;,
  0.000000;0.956379;-0.292129;,
  0.000000;-0.729251;0.684246;,
  0.242287;-0.718166;0.652330;,
  0.299073;0.954175;0.010296;,
  0.000000;0.999869;0.016197;,
  0.000000;-0.103887;0.994589;,
  0.337648;-0.130747;0.932148;,
  0.368165;0.704640;0.606578;,
  0.000000;0.745590;0.666405;,
  -1.000000;0.000000;0.000000;,
  0.946754;0.116027;0.300323;,
  0.946754;0.116027;0.300325;,
  0.946754;0.116026;0.300323;,
  0.946754;0.116023;0.300325;,
  0.946754;0.116023;0.300327;,
  0.900525;0.400917;0.168285;,
  0.946754;0.116025;0.300323;,
  0.838777;0.517510;0.169225;,
  0.875870;-0.110407;0.469747;,
  0.797929;0.427460;0.424955;,
  0.776216;-0.052989;0.628236;,
  0.049915;-0.928888;-0.366981;,
  0.045049;-0.929352;-0.366437;,
  0.064443;0.934342;0.350504;,
  0.058194;0.934393;0.351458;,
  0.000000;0.932803;0.360387;,
  0.000000;0.932803;0.360388;,
  0.000000;-0.932804;-0.360384;,
  0.000000;-0.932804;-0.360385;,
  0.000000;-0.932803;-0.360387;,
  0.062387;-0.927611;-0.368301;,
  0.080414;0.934020;0.348051;,
  0.000000;0.932804;0.360385;,
  0.000000;-0.932804;-0.360386;,
  0.082742;-0.925233;-0.370266;,
  0.106273;0.932955;0.343950;,
  0.000000;0.932803;0.360387;,
  0.000000;-0.932804;-0.360384;,
  0.121620;-0.919758;-0.373168;,
  0.154549;0.929069;0.336075;,
  0.000000;0.932803;0.360387;,
  0.000000;-0.904361;-0.426769;,
  0.182062;-0.882664;-0.433309;,
  0.228394;0.937254;0.263422;,
  0.000000;0.956379;0.292129;,
  0.000000;-0.729253;-0.684244;,
  0.242287;-0.718168;-0.652328;,
  0.299073;0.954175;-0.010296;,
  0.000000;0.999869;-0.016197;,
  0.000000;-0.103887;-0.994589;,
  0.337648;-0.130747;-0.932148;,
  0.368165;0.704640;-0.606578;,
  0.000000;0.745590;-0.666405;,
  0.946754;0.116028;-0.300323;,
  0.946754;0.116027;-0.300325;,
  0.946754;0.116027;-0.300323;,
  0.946754;0.116025;-0.300324;,
  0.946754;0.116025;-0.300326;,
  0.900525;0.400917;-0.168284;,
  0.946754;0.116027;-0.300323;,
  0.838777;0.517509;-0.169225;,
  0.875870;-0.110407;-0.469747;,
  0.797929;0.427460;-0.424955;,
  0.776216;-0.052989;-0.628236;,
  0.044943;-0.360022;-0.931861;,
  0.000000;-0.360390;-0.932802;,
  0.000000;-0.932804;0.360383;,
  0.000000;0.360389;0.932802;,
  0.000000;0.932803;-0.360387;,
  0.000000;-0.360392;-0.932801;,
  0.000000;0.360389;0.932802;,
  0.000000;0.932804;-0.360384;,
  0.000000;-0.360395;-0.932800;,
  0.000000;-0.932803;0.360387;,
  0.000000;0.360386;0.932803;,
  0.000000;0.932806;-0.360379;,
  0.000000;-0.360387;-0.932803;,
  0.000000;-0.932801;0.360392;,
  0.000000;0.360381;0.932805;,
  0.000000;0.932805;-0.360381;,
  0.000000;-0.360384;-0.932804;,
  0.000000;-0.932802;0.360390;,
  0.000000;0.360390;0.932802;,
  0.000000;0.932805;-0.360381;,
  0.000000;-0.360388;-0.932803;,
  0.000000;-0.932804;0.360385;,
  0.000000;0.360388;0.932802;,
  0.000000;0.871206;-0.490918;,
  0.000000;-0.360369;-0.932810;,
  0.000000;-0.974970;0.222335;,
  0.090004;-0.923969;0.371727;,
  0.099704;-0.922603;0.372643;,
  0.089796;-0.358926;-0.929037;,
  0.128616;0.931906;-0.339129;,
  0.116186;0.932743;-0.341309;,
  0.160311;0.929052;-0.333410;,
  0.124531;-0.918725;0.374749;,
  0.211373;0.922310;-0.323522;,
  0.164933;-0.911179;0.377557;,
  0.305632;0.902499;-0.303454;,
  0.241570;-0.892752;0.380314;,
  0.366962;0.884303;-0.288699;,
  0.358282;-0.831147;0.425239;,
  0.421185;-0.777929;0.466294;,
  0.044943;-0.360022;0.931861;,
  0.000000;-0.360390;0.932802;,
  0.000000;-0.932804;-0.360383;,
  0.000000;0.360386;-0.932803;,
  0.000000;0.932803;0.360386;,
  0.000000;-0.360392;0.932801;,
  0.000000;0.360391;-0.932801;,
  0.000000;0.932804;0.360385;,
  0.000000;-0.360395;0.932800;,
  0.000000;-0.932803;-0.360387;,
  0.000000;0.360386;-0.932803;,
  0.000000;0.932806;0.360379;,
  0.000000;-0.360387;0.932803;,
  0.000000;-0.932801;-0.360392;,
  0.000000;0.360381;-0.932805;,
  0.000000;0.932806;0.360380;,
  0.000000;-0.360387;0.932803;,
  0.000000;-0.932802;-0.360390;,
  0.000000;0.360390;-0.932802;,
  0.000000;0.932804;0.360383;,
  0.000000;-0.360378;0.932806;,
  0.000000;-0.932804;-0.360385;,
  0.000000;0.360388;-0.932802;,
  0.000000;0.871204;0.490921;,
  0.000000;-0.360362;0.932813;,
  0.000000;-0.974970;-0.222335;,
  0.099704;-0.922603;-0.372643;,
  0.090004;-0.923969;-0.371727;,
  0.089796;-0.358926;0.929037;,
  0.116186;0.932743;0.341309;,
  0.128616;0.931907;0.339129;,
  0.160312;0.929052;0.333409;,
  0.124532;-0.918725;-0.374749;,
  0.211374;0.922309;0.323522;,
  0.164933;-0.911179;-0.377557;,
  0.305634;0.902499;0.303453;,
  0.241568;-0.892752;-0.380314;,
  0.366965;0.884302;0.288697;,
  0.358279;-0.831148;-0.425239;,
  0.421182;-0.777931;-0.466292;;
  188;
  4;33,34,34,33;,
  4;2,3,5,4;,
  4;32,32,32,32;,
  4;6,7,1,0;,
  4;87,88,88,87;,
  4;28,29,30,31;,
  4;6,0,9,8;,
  4;33,33,35,35;,
  4;2,4,11,10;,
  4;32,32,32,32;,
  4;8,9,13,12;,
  4;35,35,36,36;,
  4;10,11,15,14;,
  4;32,32,32,32;,
  4;12,13,17,16;,
  4;36,36,37,37;,
  4;14,15,19,18;,
  4;32,32,32,32;,
  4;16,17,21,20;,
  4;37,37,38,39;,
  4;18,19,23,22;,
  4;32,32,32,32;,
  4;20,21,25,24;,
  4;39,38,40,41;,
  4;22,23,27,26;,
  4;32,32,32,32;,
  4;24,25,29,28;,
  4;41,40,42,43;,
  4;26,27,31,30;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;89,89,89,89;,
  4;90,90,90,90;,
  4;91,91,91,91;,
  4;92,92,92,92;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;93,93,93,93;,
  4;94,94,94,94;,
  4;95,95,95,95;,
  4;96,96,96,96;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;97,97,97,97;,
  4;98,98,98,98;,
  4;99,99,99,99;,
  4;100,100,100,100;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;101,101,101,101;,
  4;102,102,102,102;,
  4;103,103,103,103;,
  4;104,104,104,104;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;105,105,105,105;,
  4;106,106,106,106;,
  4;107,107,107,107;,
  4;108,108,108,108;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;109,109,109,109;,
  4;110,110,110,110;,
  4;111,111,111,111;,
  4;112,112,112,112;,
  4;0,1,113,114;,
  4;87,87,115,115;,
  4;3,2,116,117;,
  4;2,10,118,116;,
  4;9,0,114,119;,
  4;10,14,120,118;,
  4;13,9,119,121;,
  4;14,18,122,120;,
  4;17,13,121,123;,
  4;18,22,124,122;,
  4;21,17,123,125;,
  4;22,26,40,38;,
  4;25,21,125,126;,
  4;26,30,42,40;,
  4;30,29,43,42;,
  4;29,25,41,43;,
  4;76,76,77,77;,
  4;46,48,49,47;,
  4;32,32,32,32;,
  4;50,44,45,51;,
  4;127,127,128,128;,
  4;72,75,74,73;,
  4;50,52,53,44;,
  4;76,78,78,76;,
  4;46,54,55,48;,
  4;32,32,32,32;,
  4;52,56,57,53;,
  4;78,79,79,78;,
  4;54,58,59,55;,
  4;32,32,32,32;,
  4;56,60,61,57;,
  4;79,80,80,79;,
  4;58,62,63,59;,
  4;32,32,32,32;,
  4;60,64,65,61;,
  4;80,82,81,80;,
  4;62,66,67,63;,
  4;32,32,32,32;,
  4;64,68,69,65;,
  4;82,84,83,81;,
  4;66,70,71,67;,
  4;32,32,32,32;,
  4;68,72,73,69;,
  4;84,86,85,83;,
  4;70,74,75,71;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;129,129,129,129;,
  4;130,130,130,130;,
  4;131,131,131,131;,
  4;132,132,132,132;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;133,133,133,133;,
  4;134,134,134,134;,
  4;135,135,135,135;,
  4;136,136,136,136;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;137,137,137,137;,
  4;138,138,138,138;,
  4;139,139,139,139;,
  4;140,140,140,140;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;141,141,141,141;,
  4;142,142,142,142;,
  4;143,143,143,143;,
  4;144,144,144,144;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;145,145,145,145;,
  4;146,146,146,146;,
  4;147,147,147,147;,
  4;148,148,148,148;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;32,32,32,32;,
  4;149,149,149,149;,
  4;150,150,150,150;,
  4;151,151,151,151;,
  4;152,152,152,152;,
  4;44,153,154,45;,
  4;127,155,155,127;,
  4;47,156,157,46;,
  4;46,157,158,54;,
  4;53,159,153,44;,
  4;54,158,160,58;,
  4;57,161,159,53;,
  4;58,160,162,62;,
  4;61,163,161,57;,
  4;62,162,164,66;,
  4;65,165,163,61;,
  4;66,81,83,70;,
  4;69,166,165,65;,
  4;70,83,85,74;,
  4;74,85,86,73;,
  4;73,86,84,69;;
 }
 MeshTextureCoords {
  204;
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.250000;,
  0.375000;0.500000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.625000;0.500000;,
  0.375000;0.750000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.750000;,
  0.625000;0.000000;,
  0.875000;0.250000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;;
 }
}

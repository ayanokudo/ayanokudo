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
 80;
 -20.02338;57.91156;60.87466;,
 -20.02338;78.76529;32.17189;,
 -15.22285;83.15079;34.12445;,
 -15.22285;61.12377;64.44224;,
 -20.02338;27.18625;78.61393;,
 -15.22285;28.66972;83.17952;,
 -20.02338;-8.09800;82.32251;,
 -15.22285;-8.59981;87.09679;,
 -20.02338;-41.84019;71.35896;,
 -15.22285;-44.24041;75.51640;,
 -20.02338;-68.20586;47.61914;,
 -15.22285;-72.08961;50.44091;,
 -20.02338;-82.63633;15.20790;,
 -15.22285;-87.33195;16.20601;,
 -20.02338;-82.63634;-20.27069;,
 -15.22285;-87.33195;-21.26878;,
 -20.02338;-68.20588;-52.68196;,
 -15.22285;-72.08961;-55.50372;,
 -20.02338;-41.84019;-76.42179;,
 -15.22285;-44.24043;-80.57915;,
 -20.02338;-8.09800;-87.38521;,
 -15.22285;-8.59981;-92.15958;,
 -20.02338;27.18621;-83.67674;,
 -15.22285;28.66966;-88.24241;,
 -20.02338;57.91156;-65.93750;,
 -15.22285;61.12373;-69.50501;,
 -20.02338;78.76529;-37.23467;,
 -15.22285;83.15079;-39.18723;,
 -20.02338;86.14178;-2.53139;,
 -15.22285;90.94231;-2.53139;,
 -20.02338;78.76529;32.17189;,
 -15.22285;83.15079;34.12445;,
 -20.02338;87.53641;36.07701;,
 -20.02338;64.33604;68.00970;,
 -20.02338;30.15315;87.74516;,
 -20.02338;-9.10163;91.87106;,
 -20.02338;-46.64075;79.67385;,
 -20.02338;-75.97341;53.26263;,
 -20.02338;-92.02760;17.20411;,
 -20.02338;-92.02760;-22.26685;,
 -20.02338;-75.97341;-58.32536;,
 -20.02338;-46.64077;-84.73668;,
 -20.02338;-9.10163;-96.93385;,
 -20.02338;30.15315;-92.80794;,
 -20.02338;64.33598;-73.07256;,
 -20.02338;87.53641;-41.13985;,
 -20.02338;95.74294;-2.53139;,
 -20.02338;87.53641;36.07701;,
 -24.82401;83.15079;34.12445;,
 -24.82401;61.12377;64.44224;,
 -24.82401;28.66972;83.17952;,
 -24.82401;-8.59981;87.09679;,
 -24.82401;-44.24041;75.51640;,
 -24.82401;-72.08961;50.44091;,
 -24.82401;-87.33195;16.20601;,
 -24.82401;-87.33195;-21.26878;,
 -24.82401;-72.08961;-55.50372;,
 -24.82401;-44.24043;-80.57915;,
 -24.82401;-8.59981;-92.15958;,
 -24.82401;28.66966;-88.24241;,
 -24.82401;61.12373;-69.50501;,
 -24.82401;83.15079;-39.18723;,
 -24.82401;90.94231;-2.53139;,
 -24.82401;83.15079;34.12445;,
 -20.02338;78.76529;32.17189;,
 -20.02338;57.91156;60.87466;,
 -20.02338;27.18625;78.61393;,
 -20.02338;-8.09800;82.32251;,
 -20.02338;-41.84019;71.35896;,
 -20.02338;-68.20586;47.61914;,
 -20.02338;-82.63633;15.20790;,
 -20.02338;-82.63634;-20.27069;,
 -20.02338;-68.20588;-52.68196;,
 -20.02338;-41.84019;-76.42179;,
 -20.02338;-8.09800;-87.38521;,
 -20.02338;27.18621;-83.67674;,
 -20.02338;57.91156;-65.93750;,
 -20.02338;78.76529;-37.23467;,
 -20.02338;86.14178;-2.53139;,
 -20.02338;78.76529;32.17189;;
 
 60;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;8,6,7,9;,
 4;10,8,9,11;,
 4;12,10,11,13;,
 4;14,12,13,15;,
 4;16,14,15,17;,
 4;18,16,17,19;,
 4;20,18,19,21;,
 4;22,20,21,23;,
 4;24,22,23,25;,
 4;26,24,25,27;,
 4;28,26,27,29;,
 4;30,28,29,31;,
 4;3,2,32,33;,
 4;5,3,33,34;,
 4;7,5,34,35;,
 4;9,7,35,36;,
 4;11,9,36,37;,
 4;13,11,37,38;,
 4;15,13,38,39;,
 4;17,15,39,40;,
 4;19,17,40,41;,
 4;21,19,41,42;,
 4;23,21,42,43;,
 4;25,23,43,44;,
 4;27,25,44,45;,
 4;29,27,45,46;,
 4;31,29,46,47;,
 4;33,32,48,49;,
 4;34,33,49,50;,
 4;35,34,50,51;,
 4;36,35,51,52;,
 4;37,36,52,53;,
 4;38,37,53,54;,
 4;39,38,54,55;,
 4;40,39,55,56;,
 4;41,40,56,57;,
 4;42,41,57,58;,
 4;43,42,58,59;,
 4;44,43,59,60;,
 4;45,44,60,61;,
 4;46,45,61,62;,
 4;47,46,62,63;,
 4;49,48,64,65;,
 4;50,49,65,66;,
 4;51,50,66,67;,
 4;52,51,67,68;,
 4;53,52,68,69;,
 4;54,53,69,70;,
 4;55,54,70,71;,
 4;56,55,71,72;,
 4;57,56,72,73;,
 4;58,57,73,74;,
 4;59,58,74,75;,
 4;60,59,75,76;,
 4;61,60,76,77;,
 4;62,61,77,78;,
 4;63,62,78,79;;
 
 MeshMaterialList {
  12;
  60;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
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
  60;
  0.707108;-0.645973;-0.287606;,
  0.707110;-0.473145;-0.525480;,
  0.707110;-0.218507;-0.672496;,
  0.707110;0.073912;-0.703230;,
  0.707110;0.353552;-0.612369;,
  0.707110;0.572059;-0.415625;,
  0.707108;0.691654;-0.147015;,
  0.707107;0.691655;0.147015;,
  0.707108;0.572060;0.415626;,
  0.707109;0.353552;0.612370;,
  0.707113;0.073913;0.703227;,
  0.707113;-0.218506;0.672493;,
  0.707109;-0.473146;0.525481;,
  0.707106;-0.645975;0.287606;,
  0.707107;-0.707107;-0.000000;,
  0.707113;0.645968;0.287603;,
  0.707111;0.473144;0.525479;,
  0.707110;0.218507;0.672495;,
  0.707111;-0.073912;0.703229;,
  0.707113;-0.353550;0.612367;,
  0.707113;-0.572057;0.415623;,
  0.707110;-0.691652;0.147014;,
  0.707109;-0.691653;-0.147015;,
  0.707112;-0.572058;-0.415623;,
  0.707114;-0.353550;-0.612366;,
  0.707111;-0.073912;-0.703230;,
  0.707108;0.218507;-0.672498;,
  0.707112;0.473143;-0.525479;,
  0.707115;0.645967;-0.287603;,
  0.707115;0.707099;0.000000;,
  -0.707106;0.645975;0.287606;,
  -0.707104;0.473149;0.525485;,
  -0.707103;0.218509;0.672502;,
  -0.707104;-0.073913;0.703236;,
  -0.707105;-0.353554;0.612374;,
  -0.707105;-0.572063;0.415627;,
  -0.707103;-0.691659;0.147016;,
  -0.707102;-0.691660;-0.147016;,
  -0.707105;-0.572064;-0.415627;,
  -0.707107;-0.353554;-0.612372;,
  -0.707103;-0.073912;-0.703237;,
  -0.707101;0.218510;-0.672504;,
  -0.707105;0.473148;-0.525484;,
  -0.707108;0.645973;-0.287606;,
  -0.707108;0.707106;0.000000;,
  -0.707103;-0.473150;-0.525485;,
  -0.707101;-0.645980;-0.287609;,
  -0.707103;-0.218509;-0.672502;,
  -0.707102;0.073913;-0.703238;,
  -0.707103;0.353556;-0.612375;,
  -0.707103;0.572065;-0.415629;,
  -0.707101;0.691661;-0.147017;,
  -0.707100;0.691661;0.147017;,
  -0.707101;0.572066;0.415630;,
  -0.707102;0.353556;0.612376;,
  -0.707106;0.073914;0.703234;,
  -0.707106;-0.218508;0.672500;,
  -0.707101;-0.473151;0.525486;,
  -0.707099;-0.645981;0.287609;,
  -0.707099;-0.707114;-0.000000;;
  60;
  4;1,0,0,1;,
  4;2,1,1,2;,
  4;3,2,2,3;,
  4;4,3,3,4;,
  4;5,4,4,5;,
  4;6,5,5,6;,
  4;7,6,6,7;,
  4;8,7,7,8;,
  4;9,8,8,9;,
  4;10,9,9,10;,
  4;11,10,10,11;,
  4;12,11,11,12;,
  4;13,12,12,13;,
  4;14,13,13,14;,
  4;0,14,14,0;,
  4;16,15,15,16;,
  4;17,16,16,17;,
  4;18,17,17,18;,
  4;19,18,18,19;,
  4;20,19,19,20;,
  4;21,20,20,21;,
  4;22,21,21,22;,
  4;23,22,22,23;,
  4;24,23,23,24;,
  4;25,24,24,25;,
  4;26,25,25,26;,
  4;27,26,26,27;,
  4;28,27,27,28;,
  4;29,28,28,29;,
  4;15,29,29,15;,
  4;31,30,30,31;,
  4;32,31,31,32;,
  4;33,32,32,33;,
  4;34,33,33,34;,
  4;35,34,34,35;,
  4;36,35,35,36;,
  4;37,36,36,37;,
  4;38,37,37,38;,
  4;39,38,38,39;,
  4;40,39,39,40;,
  4;41,40,40,41;,
  4;42,41,41,42;,
  4;43,42,42,43;,
  4;44,43,43,44;,
  4;30,44,44,30;,
  4;45,46,46,45;,
  4;47,45,45,47;,
  4;48,47,47,48;,
  4;49,48,48,49;,
  4;50,49,49,50;,
  4;51,50,50,51;,
  4;52,51,51,52;,
  4;53,52,52,53;,
  4;54,53,53,54;,
  4;55,54,54,55;,
  4;56,55,55,56;,
  4;57,56,56,57;,
  4;58,57,57,58;,
  4;59,58,58,59;,
  4;46,59,59,46;;
 }
 MeshTextureCoords {
  80;
  0.066667;1.000000;,
  0.000000;1.000000;,
  0.000000;0.750000;,
  0.066667;0.750000;,
  0.133333;1.000000;,
  0.133333;0.750000;,
  0.200000;1.000000;,
  0.200000;0.750000;,
  0.266667;1.000000;,
  0.266667;0.750000;,
  0.333333;1.000000;,
  0.333333;0.750000;,
  0.400000;1.000000;,
  0.400000;0.750000;,
  0.466667;1.000000;,
  0.466667;0.750000;,
  0.533333;1.000000;,
  0.533333;0.750000;,
  0.600000;1.000000;,
  0.600000;0.750000;,
  0.666667;1.000000;,
  0.666667;0.750000;,
  0.733333;1.000000;,
  0.733333;0.750000;,
  0.800000;1.000000;,
  0.800000;0.750000;,
  0.866667;1.000000;,
  0.866667;0.750000;,
  0.933333;1.000000;,
  0.933333;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.000000;0.500000;,
  0.066667;0.500000;,
  0.133333;0.500000;,
  0.200000;0.500000;,
  0.266667;0.500000;,
  0.333333;0.500000;,
  0.400000;0.500000;,
  0.466667;0.500000;,
  0.533333;0.500000;,
  0.600000;0.500000;,
  0.666667;0.500000;,
  0.733333;0.500000;,
  0.800000;0.500000;,
  0.866667;0.500000;,
  0.933333;0.500000;,
  1.000000;0.500000;,
  0.000000;0.250000;,
  0.066667;0.250000;,
  0.133333;0.250000;,
  0.200000;0.250000;,
  0.266667;0.250000;,
  0.333333;0.250000;,
  0.400000;0.250000;,
  0.466667;0.250000;,
  0.533333;0.250000;,
  0.600000;0.250000;,
  0.666667;0.250000;,
  0.733333;0.250000;,
  0.800000;0.250000;,
  0.866667;0.250000;,
  0.933333;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.066667;0.000000;,
  0.133333;0.000000;,
  0.200000;0.000000;,
  0.266667;0.000000;,
  0.333333;0.000000;,
  0.400000;0.000000;,
  0.466667;0.000000;,
  0.533333;0.000000;,
  0.600000;0.000000;,
  0.666667;0.000000;,
  0.733333;0.000000;,
  0.800000;0.000000;,
  0.866667;0.000000;,
  0.933333;0.000000;,
  1.000000;0.000000;;
 }
}

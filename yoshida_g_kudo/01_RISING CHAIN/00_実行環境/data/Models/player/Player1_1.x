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
 -19.19260;43.40530;44.03460;,
 -19.19260;58.71220;22.96640;,
 -15.66890;61.93125;24.39960;,
 -15.66890;45.76315;46.65320;,
 -19.19260;20.85250;57.05550;,
 -15.66890;21.94135;60.40675;,
 -19.19260;-5.04660;59.77760;,
 -15.66890;-5.41495;63.28195;,
 -19.19260;-29.81380;51.73025;,
 -15.66890;-31.57560;54.78185;,
 -19.19260;-49.16660;34.30490;,
 -15.66890;-52.01735;36.37610;,
 -19.19260;-59.75870;10.51460;,
 -15.66890;-63.20540;11.24725;,
 -19.19260;-59.75875;-15.52710;,
 -15.66890;-63.20540;-16.25975;,
 -19.19260;-49.16660;-39.31745;,
 -15.66890;-52.01735;-41.38860;,
 -19.19260;-29.81385;-56.74275;,
 -15.66890;-31.57565;-59.79440;,
 -19.19260;-5.04660;-64.79010;,
 -15.66890;-5.41495;-68.29450;,
 -19.19260;20.85245;-62.06805;,
 -15.66890;21.94135;-65.41930;,
 -19.19260;43.40530;-49.04715;,
 -15.66890;45.76310;-51.66575;,
 -19.19260;58.71220;-27.97895;,
 -15.66890;61.93125;-29.41215;,
 -19.19260;64.12660;-2.50625;,
 -15.66890;67.65035;-2.50625;,
 -19.19260;58.71220;22.96640;,
 -15.66890;61.93125;24.39960;,
 -19.19260;65.15030;25.83280;,
 -19.19260;48.12090;49.27185;,
 -19.19260;23.03020;63.75790;,
 -19.19260;-5.78325;66.78640;,
 -19.19260;-33.33750;57.83350;,
 -19.19260;-54.86805;38.44730;,
 -19.19260;-66.65205;11.97985;,
 -19.19260;-66.65205;-16.99235;,
 -19.19260;-54.86805;-43.45980;,
 -19.19260;-33.33750;-62.84600;,
 -19.19260;-5.78325;-71.79890;,
 -19.19260;23.03020;-68.77050;,
 -19.19260;48.12085;-54.28440;,
 -19.19260;65.15030;-30.84535;,
 -19.19260;71.17395;-2.50625;,
 -19.19260;65.15030;25.83280;,
 -22.71625;61.93125;24.39960;,
 -22.71625;45.76315;46.65320;,
 -22.71625;21.94135;60.40675;,
 -22.71625;-5.41495;63.28195;,
 -22.71625;-31.57560;54.78185;,
 -22.71625;-52.01735;36.37610;,
 -22.71625;-63.20540;11.24725;,
 -22.71625;-63.20540;-16.25975;,
 -22.71625;-52.01735;-41.38860;,
 -22.71625;-31.57565;-59.79440;,
 -22.71625;-5.41495;-68.29450;,
 -22.71625;21.94135;-65.41930;,
 -22.71625;45.76310;-51.66575;,
 -22.71625;61.93125;-29.41215;,
 -22.71625;67.65035;-2.50625;,
 -22.71625;61.93125;24.39960;,
 -19.19260;58.71220;22.96640;,
 -19.19260;43.40530;44.03460;,
 -19.19260;20.85250;57.05550;,
 -19.19260;-5.04660;59.77760;,
 -19.19260;-29.81380;51.73025;,
 -19.19260;-49.16660;34.30490;,
 -19.19260;-59.75870;10.51460;,
 -19.19260;-59.75875;-15.52710;,
 -19.19260;-49.16660;-39.31745;,
 -19.19260;-29.81385;-56.74275;,
 -19.19260;-5.04660;-64.79010;,
 -19.19260;20.85245;-62.06805;,
 -19.19260;43.40530;-49.04715;,
 -19.19260;58.71220;-27.97895;,
 -19.19260;64.12660;-2.50625;,
 -19.19260;58.71220;22.96640;;
 
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
   0.656000;0.656000;0.656000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;1.000000;0.980000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;1.000000;0.980000;;
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
   1.000000;0.639000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.639000;0.000000;;
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
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.184000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.184000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.708800;0.708800;0.708800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.184000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  60;
  0.707107;-0.645974;-0.287606;,
  0.707106;-0.473148;-0.525482;,
  0.707106;-0.218508;-0.672500;,
  0.707104;0.073914;-0.703236;,
  0.707104;0.353554;-0.612375;,
  0.707107;0.572061;-0.415627;,
  0.707106;0.691655;-0.147015;,
  0.707105;0.691657;0.147016;,
  0.707105;0.572063;0.415627;,
  0.707107;0.353553;0.612372;,
  0.707108;0.073913;0.703232;,
  0.707107;-0.218508;0.672499;,
  0.707105;-0.473148;0.525483;,
  0.707106;-0.645974;0.287607;,
  0.707109;-0.707105;-0.000000;,
  0.707102;0.645979;0.287608;,
  0.707103;0.473150;0.525485;,
  0.707103;0.218509;0.672502;,
  0.707108;-0.073912;0.703232;,
  0.707111;-0.353551;0.612369;,
  0.707106;-0.572062;0.415626;,
  0.707102;-0.691660;0.147016;,
  0.707102;-0.691660;-0.147016;,
  0.707105;-0.572064;-0.415628;,
  0.707106;-0.353554;-0.612373;,
  0.707105;-0.073913;-0.703235;,
  0.707105;0.218509;-0.672501;,
  0.707104;0.473149;-0.525484;,
  0.707102;0.645979;-0.287608;,
  0.707101;0.707113;0.000000;,
  -0.707107;0.645974;0.287605;,
  -0.707108;0.473146;0.525482;,
  -0.707108;0.218508;0.672497;,
  -0.707113;-0.073911;0.703227;,
  -0.707116;-0.353549;0.612365;,
  -0.707111;-0.572058;0.415623;,
  -0.707107;-0.691655;0.147015;,
  -0.707107;-0.691655;-0.147015;,
  -0.707110;-0.572060;-0.415624;,
  -0.707111;-0.353551;-0.612369;,
  -0.707110;-0.073913;-0.703230;,
  -0.707110;0.218507;-0.672496;,
  -0.707109;0.473146;-0.525481;,
  -0.707107;0.645974;-0.287606;,
  -0.707106;0.707107;0.000000;,
  -0.707112;-0.473144;-0.525478;,
  -0.707113;-0.645969;-0.287604;,
  -0.707111;-0.218507;-0.672495;,
  -0.707109;0.073913;-0.703231;,
  -0.707110;0.353551;-0.612370;,
  -0.707112;0.572057;-0.415624;,
  -0.707111;0.691650;-0.147014;,
  -0.707110;0.691652;0.147015;,
  -0.707111;0.572058;0.415624;,
  -0.707112;0.353551;0.612368;,
  -0.707113;0.073912;0.703227;,
  -0.707112;-0.218506;0.672494;,
  -0.707111;-0.473145;0.525479;,
  -0.707112;-0.645970;0.287605;,
  -0.707114;-0.707100;-0.000000;;
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
  0.066670;1.000000;,
  0.000000;1.000000;,
  0.000000;0.750000;,
  0.066670;0.750000;,
  0.133330;1.000000;,
  0.133330;0.750000;,
  0.200000;1.000000;,
  0.200000;0.750000;,
  0.266670;1.000000;,
  0.266670;0.750000;,
  0.333330;1.000000;,
  0.333330;0.750000;,
  0.400000;1.000000;,
  0.400000;0.750000;,
  0.466670;1.000000;,
  0.466670;0.750000;,
  0.533330;1.000000;,
  0.533330;0.750000;,
  0.600000;1.000000;,
  0.600000;0.750000;,
  0.666670;1.000000;,
  0.666670;0.750000;,
  0.733330;1.000000;,
  0.733330;0.750000;,
  0.800000;1.000000;,
  0.800000;0.750000;,
  0.866670;1.000000;,
  0.866670;0.750000;,
  0.933330;1.000000;,
  0.933330;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.000000;0.500000;,
  0.066670;0.500000;,
  0.133330;0.500000;,
  0.200000;0.500000;,
  0.266670;0.500000;,
  0.333330;0.500000;,
  0.400000;0.500000;,
  0.466670;0.500000;,
  0.533330;0.500000;,
  0.600000;0.500000;,
  0.666670;0.500000;,
  0.733330;0.500000;,
  0.800000;0.500000;,
  0.866670;0.500000;,
  0.933330;0.500000;,
  1.000000;0.500000;,
  0.000000;0.250000;,
  0.066670;0.250000;,
  0.133330;0.250000;,
  0.200000;0.250000;,
  0.266670;0.250000;,
  0.333330;0.250000;,
  0.400000;0.250000;,
  0.466670;0.250000;,
  0.533330;0.250000;,
  0.600000;0.250000;,
  0.666670;0.250000;,
  0.733330;0.250000;,
  0.800000;0.250000;,
  0.866670;0.250000;,
  0.933330;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.066670;0.000000;,
  0.133330;0.000000;,
  0.200000;0.000000;,
  0.266670;0.000000;,
  0.333330;0.000000;,
  0.400000;0.000000;,
  0.466670;0.000000;,
  0.533330;0.000000;,
  0.600000;0.000000;,
  0.666670;0.000000;,
  0.733330;0.000000;,
  0.800000;0.000000;,
  0.866670;0.000000;,
  0.933330;0.000000;,
  1.000000;0.000000;;
 }
}

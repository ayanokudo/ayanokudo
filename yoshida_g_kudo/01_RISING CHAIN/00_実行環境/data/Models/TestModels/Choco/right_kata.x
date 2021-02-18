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
 66;
 -4.15491;-38.64368;-0.27168;,
 -3.91916;-30.02401;1.07450;,
 -1.95848;-29.66068;-4.29329;,
 -2.42212;-38.03596;-4.99706;,
 2.77466;-29.51000;-6.51676;,
 1.76151;-37.78414;-6.95414;,
 5.94489;-38.03596;-4.99706;,
 7.50778;-29.66068;-4.29329;,
 7.67766;-38.64368;-0.27168;,
 9.46821;-30.02401;1.07450;,
 5.94489;-39.25140;4.45370;,
 7.50778;-30.38734;6.44230;,
 1.76151;-39.50321;6.41109;,
 2.77466;-30.53772;8.66577;,
 -1.95848;-30.38734;6.44230;,
 -2.42212;-39.25140;4.45370;,
 -3.91916;-30.02401;1.07450;,
 -4.15491;-38.64368;-0.27168;,
 -4.08563;-22.35731;2.42067;,
 -4.01271;-15.58839;2.42067;,
 -1.80089;-15.60678;-3.57943;,
 -1.89730;-22.23837;-3.58957;,
 3.44910;-14.88369;-6.06475;,
 3.38558;-22.18914;-6.07911;,
 8.66203;-13.84233;-3.57943;,
 8.66845;-22.23837;-3.58957;,
 10.78387;-13.09313;2.42067;,
 10.85653;-22.35731;2.42067;,
 8.57204;-13.07504;8.42077;,
 8.66845;-22.47623;8.43091;,
 3.32206;-13.79814;10.90610;,
 3.38558;-22.52577;10.92043;,
 -1.89085;-14.83920;8.42077;,
 -1.89730;-22.47623;8.43091;,
 -4.01271;-15.58839;2.42067;,
 -4.08563;-22.35731;2.42067;,
 4.18670;-2.46375;-12.32559;,
 8.85013;-2.78735;-7.45453;,
 11.46486;-1.86404;0.63431;,
 8.73939;-1.84179;9.30481;,
 2.27028;-2.73278;12.36702;,
 5.65079;9.54570;-10.98253;,
 8.85013;6.99853;-7.45453;,
 10.37725;7.92184;0.63431;,
 8.73939;7.94438;9.30481;,
 5.49259;12.00065;12.47644;,
 8.15257;14.73558;0.63431;,
 -0.54121;-10.00707;12.04131;,
 2.32379;8.65909;9.14437;,
 4.26905;10.65915;0.48414;,
 -0.03271;-2.11554;9.06434;,
 -2.08876;-7.43528;8.82615;,
 2.43950;6.86378;-8.01134;,
 -3.07577;-10.96904;6.17842;,
 -4.62750;-11.51694;1.79053;,
 -3.00996;-11.53039;-2.59741;,
 1.36880;-1.91882;-8.99353;,
 0.82938;-11.00157;-4.41494;,
 5.81151;-40.31395;-0.27163;,
 4.62529;-40.72998;2.96324;,
 4.62529;-39.89791;-3.50650;,
 1.76146;-40.90237;4.30322;,
 1.76146;-39.72553;-4.84629;,
 -1.10254;-40.72998;2.96324;,
 -1.10254;-39.89791;-3.50650;,
 -2.28876;-40.31395;-0.27163;;
 
 67;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;6,5,4,7;,
 4;8,6,7,9;,
 4;10,8,9,11;,
 4;12,10,11,13;,
 4;12,13,14,15;,
 4;15,14,16,17;,
 4;18,19,20,21;,
 4;21,20,22,23;,
 4;23,22,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;29,28,30,31;,
 4;31,30,32,33;,
 4;33,32,34,35;,
 4;22,36,37,24;,
 4;24,37,38,26;,
 4;26,38,39,28;,
 4;28,39,40,30;,
 4;36,41,42,37;,
 4;37,42,43,38;,
 4;38,43,44,39;,
 4;39,44,45,40;,
 4;42,41,46,43;,
 4;43,46,45,44;,
 4;21,2,1,18;,
 4;23,4,2,21;,
 4;7,4,23,25;,
 4;9,7,25,27;,
 4;11,9,27,29;,
 4;13,11,29,31;,
 4;33,14,13,31;,
 4;35,16,14,33;,
 4;47,32,30,40;,
 3;48,49,50;,
 3;50,49,51;,
 3;49,52,51;,
 3;51,52,53;,
 3;53,52,54;,
 3;54,52,55;,
 3;52,56,55;,
 3;56,57,55;,
 4;20,34,54,55;,
 4;34,32,53,54;,
 4;32,47,51,53;,
 4;47,40,50,51;,
 4;40,45,48,50;,
 4;45,46,49,48;,
 4;46,41,52,49;,
 4;41,36,56,52;,
 4;36,22,57,56;,
 4;22,20,55,57;,
 3;58,59,60;,
 3;59,61,60;,
 3;60,61,62;,
 3;61,63,62;,
 3;62,63,64;,
 3;63,65,64;,
 4;0,3,64,65;,
 4;3,5,62,64;,
 4;5,6,60,62;,
 4;6,8,58,60;,
 4;8,10,59,58;,
 4;10,12,61,59;,
 4;12,15,63,61;,
 4;15,0,65,63;;
 
 MeshMaterialList {
  1;
  67;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  69;
  -0.914616;-0.401347;-0.048964;,
  -0.665603;-0.364290;-0.651357;,
  -0.000521;-0.391381;-0.920229;,
  0.635826;-0.441726;-0.632932;,
  0.863492;-0.500899;-0.058996;,
  0.639721;-0.568001;0.517815;,
  -0.001543;-0.586238;0.810137;,
  -0.668789;-0.500917;0.549366;,
  -0.999981;-0.005662;-0.002247;,
  -0.738489;0.039906;-0.673084;,
  0.000337;0.031605;-0.999500;,
  0.738151;-0.023807;-0.674216;,
  0.996377;-0.084974;-0.003551;,
  0.735160;-0.131783;0.664961;,
  -0.001921;-0.136316;0.990664;,
  -0.739925;-0.078845;0.668052;,
  -0.997549;-0.069962;-0.000853;,
  0.037225;-0.070852;-0.996792;,
  0.775403;-0.120636;-0.619836;,
  0.999423;-0.033427;0.005969;,
  0.743616;-0.024115;0.668171;,
  0.103124;-0.110711;0.988488;,
  -0.741279;-0.105406;0.662868;,
  0.658433;-0.175864;-0.731805;,
  0.843919;-0.106534;-0.525787;,
  0.999964;-0.008329;0.001677;,
  0.777646;-0.032230;0.627875;,
  0.312554;-0.167598;0.934998;,
  0.890461;0.152045;-0.428906;,
  0.972907;0.230397;-0.019218;,
  0.865290;0.131626;0.483681;,
  0.780448;0.170910;0.601407;,
  0.834725;0.200249;-0.512966;,
  0.916320;0.399114;-0.032637;,
  -0.999994;0.003358;0.000836;,
  -0.738072;0.083151;-0.669579;,
  -0.000371;0.056351;-0.998411;,
  0.732248;-0.063790;-0.678044;,
  0.982034;-0.188066;-0.015500;,
  0.719892;-0.269659;0.639562;,
  -0.002999;-0.258440;0.966022;,
  -0.736405;-0.135294;0.662875;,
  -0.738808;-0.023431;-0.673508;,
  -0.053556;-0.336138;0.940289;,
  -0.995009;0.096448;-0.025579;,
  -0.781837;-0.040627;-0.622157;,
  -0.954503;0.157890;0.252973;,
  -0.940888;0.253052;0.225156;,
  -0.920370;0.268618;0.284189;,
  -0.907481;0.391809;0.151536;,
  -0.880006;0.472927;-0.043931;,
  -0.918657;0.344988;-0.192491;,
  -0.738485;-0.092809;-0.667852;,
  -0.537984;-0.201602;-0.818492;,
  -0.240177;-0.912710;-0.330569;,
  -0.465734;-0.878162;-0.109192;,
  0.000001;-0.933374;-0.358906;,
  0.191023;-0.937723;-0.290149;,
  0.465733;-0.878163;-0.109192;,
  0.260298;-0.958703;0.114601;,
  0.000000;-0.989285;0.146000;,
  -0.206761;-0.976334;0.063412;,
  -0.856556;0.113834;0.503342;,
  -0.780477;0.219733;0.585298;,
  -0.825520;0.467353;0.316383;,
  -0.720384;0.689169;-0.078055;,
  -0.779081;0.454672;-0.431632;,
  -0.766537;-0.048008;-0.640403;,
  -0.758227;-0.257021;-0.599193;;
  67;
  4;0,34,35,1;,
  4;1,35,36,2;,
  4;3,2,36,37;,
  4;4,3,37,38;,
  4;5,4,38,39;,
  4;6,5,39,40;,
  4;6,40,41,7;,
  4;7,41,34,0;,
  4;8,16,42,9;,
  4;9,42,17,10;,
  4;10,17,18,11;,
  4;11,18,19,12;,
  4;12,19,20,13;,
  4;13,20,21,14;,
  4;14,21,22,15;,
  4;15,22,16,8;,
  4;17,23,24,18;,
  4;18,24,25,19;,
  4;19,25,26,20;,
  4;20,26,27,21;,
  4;23,32,28,24;,
  4;24,28,29,25;,
  4;25,29,30,26;,
  4;26,30,31,27;,
  4;28,32,33,29;,
  4;29,33,31,30;,
  4;9,35,34,8;,
  4;10,36,35,9;,
  4;37,36,10,11;,
  4;38,37,11,12;,
  4;39,38,12,13;,
  4;40,39,13,14;,
  4;15,41,40,14;,
  4;8,34,41,15;,
  4;43,22,21,27;,
  3;49,50,48;,
  3;48,50,47;,
  3;50,51,47;,
  3;47,51,46;,
  3;46,51,44;,
  3;44,51,45;,
  3;51,52,45;,
  3;52,53,45;,
  4;42,16,44,45;,
  4;16,22,46,44;,
  4;22,62,47,46;,
  4;62,63,48,47;,
  4;63,64,49,48;,
  4;64,65,50,49;,
  4;65,66,51,50;,
  4;66,67,52,51;,
  4;67,68,53,52;,
  4;17,42,45,53;,
  3;58,59,57;,
  3;59,60,57;,
  3;57,60,56;,
  3;60,61,56;,
  3;56,61,54;,
  3;61,55,54;,
  4;0,1,54,55;,
  4;1,2,56,54;,
  4;2,3,57,56;,
  4;3,4,58,57;,
  4;4,5,59,58;,
  4;5,6,60,59;,
  4;6,7,61,60;,
  4;7,0,55,61;;
 }
 MeshTextureCoords {
  66;
  1.450054;1.611583;,
  1.438329;1.509543;,
  1.510311;1.510449;,
  1.514751;1.612268;,
  1.583156;1.511235;,
  1.582003;1.614220;,
  1.650281;1.615754;,
  1.656927;1.511375;,
  1.717676;1.617871;,
  1.729996;1.512376;,
  1.782962;1.623302;,
  1.801526;1.517513;,
  1.845888;1.634581;,
  1.871199;1.529771;,
  1.938977;1.550895;,
  1.906742;1.652938;,
  2.005255;1.580528;,
  1.965960;1.677815;,
  1.423435;1.418911;,
  1.424385;1.354581;,
  1.510898;1.355532;,
  1.504107;1.424238;,
  1.578713;1.327962;,
  1.582757;1.421601;,
  1.665160;1.317792;,
  1.664798;1.421123;,
  1.750265;1.315726;,
  1.744431;1.422881;,
  1.832972;1.322219;,
  1.819957;1.427923;,
  1.916014;1.338904;,
  1.892630;1.439227;,
  1.989094;1.377080;,
  1.963153;1.460991;,
  2.065466;1.413841;,
  2.035994;1.491797;,
  1.557165;1.171098;,
  1.641887;1.185115;,
  1.742070;1.188258;,
  1.848896;1.196314;,
  1.945045;1.213245;,
  1.609136;1.037685;,
  1.659116;1.080343;,
  1.752750;1.083454;,
  1.852375;1.090844;,
  1.905433;1.043706;,
  1.760295;1.002510;,
  1.986242;1.290568;,
  1.905433;1.043706;,
  1.760295;1.002510;,
  1.945045;1.213245;,
  1.986242;1.290568;,
  1.609136;1.037685;,
  1.989094;1.377080;,
  2.065466;1.413841;,
  1.510898;1.355532;,
  1.557165;1.171098;,
  1.578713;1.327962;,
  1.717676;1.617871;,
  1.782962;1.623302;,
  1.650281;1.615754;,
  1.845888;1.634581;,
  1.582003;1.614220;,
  1.906742;1.652938;,
  1.514751;1.612268;,
  1.450054;1.611583;;
 }
}

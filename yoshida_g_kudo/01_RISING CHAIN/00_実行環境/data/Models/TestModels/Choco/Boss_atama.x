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
 303;
 -21.78334;3.70364;-81.91062;,
 -25.44753;4.53176;-76.70763;,
 -22.68525;9.97424;-77.48991;,
 -18.81315;7.00438;-84.31689;,
 -27.12054;7.90707;-71.51231;,
 -26.01839;12.67905;-70.27914;,
 -23.92718;16.79607;-69.85777;,
 -20.12835;13.84795;-77.74343;,
 -15.99366;10.54782;-85.31440;,
 -18.30938;15.22038;-77.36459;,
 -13.44041;10.70975;-87.31750;,
 -23.71080;18.79843;-67.30799;,
 -22.72956;16.20708;-69.00495;,
 -18.51156;13.05283;-76.59217;,
 -14.79603;9.95883;-84.46160;,
 -20.52946;8.91406;-75.95484;,
 -17.19634;6.20926;-83.16561;,
 -24.40158;11.88392;-69.12786;,
 -25.92291;7.31809;-70.65948;,
 -23.83074;3.73664;-75.55636;,
 -20.58570;3.11464;-81.05782;,
 -25.64973;2.36423;-75.93520;,
 -21.03651;1.29688;-83.15087;,
 -28.24176;6.97156;-69.11314;,
 -27.12054;7.90707;-71.51231;,
 -25.44753;4.53176;-76.70763;,
 -21.78334;3.70364;-81.91062;,
 -28.24176;6.97156;-69.11314;,
 -26.41088;13.22726;-67.36390;,
 -25.92291;7.31809;-70.65948;,
 -24.40158;11.88392;-69.12786;,
 -22.72956;16.20708;-69.00495;,
 -23.71080;18.79843;-67.30799;,
 -20.58570;3.11464;-81.05782;,
 -21.03651;1.29688;-83.15087;,
 -16.80387;5.66104;-86.08088;,
 -17.19634;6.20926;-83.16561;,
 -13.44041;10.70975;-87.31750;,
 -14.79603;9.95883;-84.46160;,
 21.78334;3.70362;-81.91064;,
 18.81314;7.00438;-84.31689;,
 22.68525;9.97424;-77.48992;,
 25.44753;4.53176;-76.70763;,
 26.01839;12.67905;-70.27914;,
 27.12056;7.90707;-71.51232;,
 20.12835;13.84795;-77.74345;,
 23.92718;16.79607;-69.85778;,
 15.99367;10.54781;-85.31440;,
 13.44042;10.70974;-87.31750;,
 18.30938;15.22038;-77.36459;,
 23.71080;18.79843;-67.30801;,
 18.51156;13.05284;-76.59217;,
 22.72956;16.20707;-69.00495;,
 14.79605;9.95883;-84.46160;,
 17.19634;6.20926;-83.16563;,
 20.52948;8.91406;-75.95484;,
 24.40159;11.88392;-69.12786;,
 23.83074;3.73664;-75.55636;,
 25.92292;7.31810;-70.65948;,
 20.58570;3.11464;-81.05782;,
 21.03652;1.29688;-83.15087;,
 25.64973;2.36423;-75.93520;,
 28.24176;6.97156;-69.11314;,
 25.44753;4.53176;-76.70763;,
 27.12056;7.90707;-71.51232;,
 21.78334;3.70362;-81.91064;,
 26.41088;13.22726;-67.36390;,
 28.24176;6.97156;-69.11314;,
 24.40159;11.88392;-69.12786;,
 25.92292;7.31810;-70.65948;,
 23.71080;18.79843;-67.30801;,
 22.72956;16.20707;-69.00495;,
 20.58570;3.11464;-81.05782;,
 17.19634;6.20926;-83.16563;,
 16.80389;5.66104;-86.08088;,
 21.03652;1.29688;-83.15087;,
 13.44042;10.70974;-87.31750;,
 14.79605;9.95883;-84.46160;,
 2.77768;-1.60585;-108.64179;,
 0.00000;-3.59119;-109.00899;,
 0.00000;1.11777;-109.48112;,
 4.70896;1.11777;-109.00899;,
 -2.77768;-1.60585;-108.64179;,
 -4.70896;1.11777;-109.00899;,
 -3.48813;4.60590;-108.64179;,
 0.00000;4.73719;-109.00899;,
 3.48813;4.60590;-108.64179;,
 0.00000;6.30684;-107.59260;,
 4.70896;5.82674;-107.59260;,
 -4.70896;5.82674;-107.59260;,
 -3.48813;4.60590;-106.54340;,
 0.00000;4.73719;-106.17619;,
 3.48813;4.60590;-106.54340;,
 0.00000;1.11777;-105.70408;,
 4.70896;1.11777;-106.17619;,
 -4.70896;1.11777;-106.17619;,
 -2.77768;-1.60585;-106.54340;,
 0.00000;-3.59119;-106.17619;,
 2.77768;-1.60585;-106.54340;,
 0.00000;-5.16085;-107.59260;,
 3.62460;-2.82669;-107.59260;,
 -3.62460;-2.82669;-107.59260;,
 -2.77768;-1.60585;-108.64179;,
 0.00000;-3.59119;-109.00899;,
 2.77768;-1.60585;-108.64179;,
 -3.62460;-2.82669;-107.59260;,
 -6.27863;1.11777;-107.59260;,
 -2.77768;-1.60585;-106.54340;,
 -4.70896;1.11777;-106.17619;,
 -3.48813;4.60590;-106.54340;,
 -4.70896;5.82674;-107.59260;,
 2.77768;-1.60585;-106.54340;,
 3.62460;-2.82669;-107.59260;,
 6.27863;1.11777;-107.59260;,
 4.70896;1.11777;-106.17619;,
 4.70896;5.82674;-107.59260;,
 3.48813;4.60590;-106.54340;,
 -23.82423;-6.90920;-76.93058;,
 -46.91994;-6.57336;-54.03361;,
 -46.91994;-6.35005;-54.03361;,
 -23.82423;-6.01420;-76.93058;,
 -46.76437;-6.35005;-53.87341;,
 -23.20073;-6.01420;-76.28849;,
 -46.76437;-6.57336;-53.87341;,
 -23.20073;-6.90920;-76.28849;,
 -46.91994;-6.57336;-54.03361;,
 -23.82423;-6.90920;-76.93058;,
 -46.76437;-6.57336;-53.87341;,
 -46.76437;-6.35005;-53.87341;,
 -23.20073;-6.90920;-76.28849;,
 -23.20073;-6.01420;-76.28849;,
 23.82424;-6.90920;-76.93056;,
 23.82424;-6.01420;-76.93056;,
 46.91995;-6.35005;-54.03361;,
 46.91995;-6.57336;-54.03361;,
 23.20074;-6.01420;-76.28849;,
 46.76437;-6.35005;-53.87341;,
 23.20074;-6.90920;-76.28849;,
 46.76437;-6.57336;-53.87341;,
 23.82424;-6.90920;-76.93056;,
 46.91995;-6.57336;-54.03361;,
 46.76437;-6.35005;-53.87341;,
 46.76437;-6.57336;-53.87341;,
 23.20074;-6.90920;-76.28849;,
 23.20074;-6.01420;-76.28849;,
 -23.82426;-5.03879;-76.81786;,
 -46.91994;-2.28263;-54.08492;,
 -46.91994;-2.06057;-54.10856;,
 -23.82424;-4.14882;-76.91256;,
 -46.76436;-2.04362;-53.94927;,
 -23.20073;-4.08089;-76.27409;,
 -46.76437;-2.26569;-53.92562;,
 -23.20073;-4.97087;-76.17939;,
 -46.91994;-2.28263;-54.08492;,
 -23.82426;-5.03879;-76.81786;,
 -46.76437;-2.26569;-53.92562;,
 -46.76436;-2.04362;-53.94927;,
 -23.20073;-4.97087;-76.17939;,
 -23.20073;-4.08089;-76.27409;,
 23.82426;-5.03879;-76.81786;,
 23.82424;-4.14882;-76.91256;,
 46.91994;-2.06057;-54.10856;,
 46.91994;-2.28263;-54.08492;,
 23.20073;-4.08089;-76.27410;,
 46.76437;-2.04362;-53.94927;,
 23.20073;-4.97087;-76.17939;,
 46.76437;-2.26569;-53.92561;,
 23.82426;-5.03879;-76.81786;,
 46.91994;-2.28263;-54.08492;,
 46.76437;-2.04362;-53.94927;,
 46.76437;-2.26569;-53.92561;,
 23.20073;-4.97087;-76.17939;,
 23.20073;-4.08089;-76.27410;,
 -0.14886;40.05236;-64.78495;,
 -0.14886;40.55182;-37.95177;,
 16.07113;37.18143;-43.21809;,
 16.27470;37.09352;-57.79447;,
 -0.14886;25.48598;-79.86503;,
 11.01682;17.39267;-77.65537;,
 -0.14886;-27.29135;-58.85332;,
 29.02208;-12.81091;-60.45762;,
 29.68176;-13.61404;-29.74857;,
 -0.14886;-27.31534;-27.96049;,
 6.35736;-17.92542;-97.51758;,
 18.85456;-19.11814;-78.21479;,
 -0.14886;-25.56545;-92.70391;,
 -0.14886;-22.16887;-99.06592;,
 2.67637;-12.49724;-104.98956;,
 -0.14886;-14.90266;-103.90948;,
 6.35736;-0.49811;-104.34229;,
 -0.14886;1.58165;-108.08024;,
 -0.14886;8.86782;-105.04599;,
 7.70616;2.73840;-100.03735;,
 23.33994;-5.98824;-78.08894;,
 10.75933;-8.61940;-96.22498;,
 39.42744;0.04529;-32.33379;,
 33.71343;2.25692;-62.88700;,
 25.94055;30.13573;-44.13476;,
 23.69304;31.18243;-56.51717;,
 31.47442;45.48452;-43.03829;,
 32.77914;40.23444;-45.23211;,
 29.67069;42.25726;-56.25628;,
 28.65177;47.46041;-56.72962;,
 18.48674;7.90886;-76.32880;,
 29.43899;35.46134;-43.78635;,
 25.65008;40.33205;-41.37009;,
 16.07113;37.18143;-43.21809;,
 25.94055;30.13573;-44.13476;,
 25.65008;40.33205;-41.37009;,
 22.56253;42.42580;-58.51368;,
 16.27470;37.09352;-57.79447;,
 16.07113;37.18143;-43.21809;,
 25.77287;37.74200;-57.70969;,
 23.69304;31.18243;-56.51717;,
 25.77287;37.74200;-57.70969;,
 23.69304;31.18243;-56.51717;,
 31.47442;45.48452;-43.03829;,
 15.66678;-24.36209;-77.64605;,
 24.03819;-15.91030;-64.63490;,
 -0.14886;-27.19837;-60.57667;,
 -0.14886;-32.30009;-88.01340;,
 12.73953;29.89081;-23.09168;,
 0.33005;34.51680;-23.76968;,
 38.11956;-1.35419;-2.51918;,
 33.01654;-8.71619;3.89932;,
 42.21305;9.32580;-1.25768;,
 0.33005;-22.77869;-14.00018;,
 -0.14886;40.05236;-64.78495;,
 -16.57245;37.09352;-57.79447;,
 -16.36889;37.18143;-43.21809;,
 -0.14886;40.55182;-37.95177;,
 -0.14886;25.48598;-79.86503;,
 -11.31458;17.39267;-77.65537;,
 -0.14886;-27.29135;-58.85332;,
 -0.14886;-27.31534;-27.96049;,
 -29.97948;-13.61404;-29.74857;,
 -29.31980;-12.81091;-60.45762;,
 -6.65508;-17.92542;-97.51758;,
 -0.14886;-22.16887;-99.06592;,
 -0.14886;-25.56545;-92.70391;,
 -19.15232;-19.11814;-78.21479;,
 -2.97410;-12.49724;-104.98956;,
 -0.14886;-14.90266;-103.90948;,
 -6.65508;-0.49811;-104.34229;,
 -0.14886;1.58165;-108.08024;,
 -0.14886;8.86782;-105.04599;,
 -8.00388;2.73840;-100.03735;,
 -23.63769;-5.98824;-78.08894;,
 -11.05709;-8.61940;-96.22498;,
 -39.72516;0.04529;-32.33379;,
 -34.01118;2.25692;-62.88700;,
 -26.14027;29.87698;-43.85239;,
 -23.79681;30.96838;-56.76350;,
 -31.77217;45.48452;-43.03829;,
 -28.95195;47.46041;-56.72962;,
 -30.02967;42.51602;-56.49145;,
 -33.27084;40.40684;-44.99664;,
 -18.78447;7.90886;-76.32880;,
 -29.78805;35.42996;-43.48914;,
 -26.14027;29.87698;-43.85239;,
 -16.36889;37.18143;-43.21809;,
 -25.94782;40.33205;-41.37009;,
 -25.94782;40.33205;-41.37009;,
 -16.36889;37.18143;-43.21809;,
 -16.57245;37.09352;-57.79447;,
 -22.86028;42.42580;-58.51368;,
 -25.96545;37.80798;-58.00690;,
 -23.79681;30.96838;-56.76350;,
 -25.96545;37.80798;-58.00690;,
 -23.79681;30.96838;-56.76350;,
 -31.77217;45.48452;-43.03829;,
 -15.79533;-24.36209;-77.64605;,
 -0.14886;-32.30009;-88.01340;,
 -0.14886;-27.19837;-60.57667;,
 -24.16671;-15.91030;-64.63490;,
 -12.07944;29.89081;-23.09168;,
 0.33005;34.51680;-23.76968;,
 -32.35646;-8.71619;3.89932;,
 -37.45946;-1.35419;-2.51918;,
 -41.55296;9.32580;-1.25768;,
 0.33005;-22.77869;-14.00018;,
 29.72373;8.29502;7.14259;,
 9.03909;22.72763;-8.18062;,
 26.85090;0.79975;6.25728;,
 23.26959;-4.36695;10.76181;,
 0.33005;-14.23607;-1.80016;,
 0.33005;25.97419;-8.65644;,
 -8.37900;22.72763;-8.18062;,
 -22.60950;-4.36695;10.76181;,
 -29.06364;8.29502;7.14259;,
 -26.19081;0.79975;6.25728;,
 10.51715;-16.24657;-68.94329;,
 14.14464;-13.99633;-62.60798;,
 12.36652;-15.10210;-64.09835;,
 9.37983;-18.11747;-68.74036;,
 -3.41886;-18.54681;-74.11260;,
 -3.41886;-20.94955;-72.43917;,
 -10.19878;-16.24657;-68.94329;,
 -3.41886;-18.54681;-74.11260;,
 -3.41886;-20.94955;-72.43917;,
 -9.00111;-18.11747;-68.74036;,
 -13.82627;-13.99633;-62.60798;,
 -11.98779;-15.10210;-64.09835;;
 
 194;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;2,5,6,7;,
 4;3,2,7,8;,
 4;8,7,9,10;,
 4;7,6,11,9;,
 4;9,11,12,13;,
 4;10,9,13,14;,
 4;14,13,15,16;,
 4;13,12,17,15;,
 4;15,17,18,19;,
 4;16,15,19,20;,
 4;20,19,21,22;,
 4;19,18,23,21;,
 4;21,23,24,25;,
 4;22,21,25,26;,
 4;4,27,28,5;,
 4;27,29,30,28;,
 4;28,30,31,32;,
 4;5,28,32,6;,
 4;33,34,35,36;,
 4;34,0,3,35;,
 4;35,3,8,37;,
 4;36,35,37,38;,
 4;39,40,41,42;,
 4;42,41,43,44;,
 4;41,45,46,43;,
 4;40,47,45,41;,
 4;47,48,49,45;,
 4;45,49,50,46;,
 4;49,51,52,50;,
 4;48,53,51,49;,
 4;53,54,55,51;,
 4;51,55,56,52;,
 4;55,57,58,56;,
 4;54,59,57,55;,
 4;59,60,61,57;,
 4;57,61,62,58;,
 4;61,63,64,62;,
 4;60,65,63,61;,
 4;44,43,66,67;,
 4;67,66,68,69;,
 4;66,70,71,68;,
 4;43,46,70,66;,
 4;72,73,74,75;,
 4;75,74,40,39;,
 4;74,76,47,40;,
 4;73,77,76,74;,
 4;78,79,80,81;,
 4;79,82,83,80;,
 4;80,83,84,85;,
 4;81,80,85,86;,
 4;86,85,87,88;,
 4;85,84,89,87;,
 4;87,89,90,91;,
 4;88,87,91,92;,
 4;92,91,93,94;,
 4;91,90,95,93;,
 4;93,95,96,97;,
 4;94,93,97,98;,
 4;98,97,99,100;,
 4;97,96,101,99;,
 4;99,101,102,103;,
 4;100,99,103,104;,
 4;82,105,106,83;,
 4;105,107,108,106;,
 4;106,108,109,110;,
 4;83,106,110,84;,
 4;111,112,113,114;,
 4;112,78,81,113;,
 4;113,81,86,115;,
 4;114,113,115,116;,
 4;117,118,119,120;,
 4;120,119,121,122;,
 4;122,121,123,124;,
 4;124,123,125,126;,
 4;118,127,128,119;,
 4;129,117,120,130;,
 4;131,132,133,134;,
 4;132,135,136,133;,
 4;135,137,138,136;,
 4;137,139,140,138;,
 4;134,133,141,142;,
 4;143,144,132,131;,
 4;145,146,147,148;,
 4;148,147,149,150;,
 4;150,149,151,152;,
 4;152,151,153,154;,
 4;146,155,156,147;,
 4;157,145,148,158;,
 4;159,160,161,162;,
 4;160,163,164,161;,
 4;163,165,166,164;,
 4;165,167,168,166;,
 4;162,161,169,170;,
 4;171,172,160,159;,
 4;173,174,175,176;,
 4;177,173,176,178;,
 4;179,180,181,182;,
 4;183,184,185,186;,
 4;187,183,186,188;,
 4;189,187,188,190;,
 4;191,192,189,190;,
 4;191,177,178,192;,
 4;193,194,189,192;,
 4;193,184,183,194;,
 4;187,189,194,183;,
 4;195,181,180,196;,
 4;197,195,196,198;,
 4;199,200,201,202;,
 4;178,176,198,203;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,213,210,209;,
 4;214,204,207,215;,
 4;200,216,205,204;,
 4;208,199,202,209;,
 4;209,202,201,212;,
 4;201,200,204,214;,
 4;193,196,180,184;,
 4;203,198,196,193;,
 4;203,193,192,178;,
 4;217,218,219,220;,
 4;221,175,174,222;,
 4;181,195,223,224;,
 4;195,197,225,223;,
 4;197,175,221,225;,
 4;182,181,224,226;,
 4;227,228,229,230;,
 4;231,232,228,227;,
 4;233,234,235,236;,
 4;237,238,239,240;,
 4;241,242,238,237;,
 4;243,244,242,241;,
 4;245,244,243,246;,
 4;245,246,232,231;,
 4;247,246,243,248;,
 4;247,248,237,240;,
 4;241,237,248,243;,
 4;249,250,236,235;,
 4;251,252,250,249;,
 4;253,254,255,256;,
 4;232,257,252,228;,
 4;258,259,260,261;,
 4;262,263,264,265;,
 4;266,265,264,267;,
 4;268,269,259,258;,
 4;256,258,261,270;,
 4;262,265,254,253;,
 4;265,266,255,254;,
 4;255,268,258,256;,
 4;247,240,236,250;,
 4;257,247,250,252;,
 4;257,232,246,247;,
 4;271,272,273,274;,
 4;275,276,230,229;,
 4;235,277,278,249;,
 4;249,278,279,251;,
 4;251,279,275,229;,
 4;234,280,277,235;,
 3;281,282,283;,
 3;283,282,284;,
 3;284,282,285;,
 3;282,286,285;,
 3;286,287,285;,
 3;285,287,288;,
 3;287,289,288;,
 3;289,290,288;,
 4;276,275,287,286;,
 4;275,279,289,287;,
 4;279,278,290,289;,
 4;278,277,288,290;,
 4;277,226,285,288;,
 4;226,224,284,285;,
 4;224,223,283,284;,
 4;223,225,281,283;,
 4;225,221,282,281;,
 4;221,276,286,282;,
 4;291,292,293,294;,
 4;180,179,219,218;,
 4;295,291,294,296;,
 4;297,298,299,300;,
 4;233,236,274,273;,
 4;301,297,300,302;,
 4;184,180,292,291;,
 4;180,218,293,292;,
 4;218,217,294,293;,
 4;185,184,291,295;,
 4;217,220,296,294;,
 4;240,239,298,297;,
 4;272,271,300,299;,
 4;236,240,297,301;,
 4;271,274,302,300;,
 4;274,236,301,302;;
 
 MeshMaterialList {
  9;
  194;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
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
  7,
  0,
  0,
  0,
  7,
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
  7,
  0,
  0,
  0,
  7,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  6,
  0,
  6,
  6,
  0,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6,
  6;;
  Material {
   0.168000;0.056000;0.096000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.168000;0.056000;0.096000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.552000;0.536000;0.104000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.088000;0.016000;0.064000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.600000;0.600000;0.600000;1.000000;;
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
   0.248000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.160000;0.248000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.096000;0.096000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  255;
  -0.768001;0.118920;-0.629311;,
  -0.902566;0.224903;-0.367142;,
  -0.598962;0.461606;-0.654343;,
  -0.714294;0.552442;-0.429642;,
  0.878436;-0.264960;0.397677;,
  0.763099;-0.174126;0.622383;,
  0.689594;-0.597911;0.408612;,
  0.555024;-0.491930;0.670786;,
  -0.538556;0.481985;-0.691121;,
  0.642285;-0.346745;0.683548;,
  0.614791;-0.569394;0.545731;,
  0.796037;-0.467834;0.384001;,
  0.475997;-0.525416;0.705240;,
  0.654800;-0.666231;0.356894;,
  -0.852881;0.152396;-0.499369;,
  -0.843835;0.384117;-0.374696;,
  -0.602910;0.582652;-0.544992;,
  -0.690088;0.263028;-0.674236;,
  -0.696727;0.606561;-0.382957;,
  0.858032;-0.135821;0.495312;,
  -0.757027;0.370360;-0.538279;,
  -0.460919;0.715033;-0.525625;,
  0.755299;-0.373387;0.538615;,
  0.490113;-0.691253;0.530998;,
  -0.895111;0.375470;-0.240413;,
  0.802217;-0.538170;0.258497;,
  0.768001;0.118922;-0.629310;,
  0.902567;0.224902;-0.367141;,
  0.598962;0.461606;-0.654343;,
  0.714294;0.552442;-0.429642;,
  -0.878436;-0.264961;0.397676;,
  -0.763098;-0.174126;0.622383;,
  -0.689594;-0.597911;0.408610;,
  -0.555025;-0.491929;0.670785;,
  0.538556;0.481986;-0.691120;,
  -0.642286;-0.346745;0.683547;,
  -0.614791;-0.569393;0.545732;,
  -0.796038;-0.467834;0.384000;,
  -0.476000;-0.525416;0.705240;,
  -0.654800;-0.666232;0.356892;,
  0.852881;0.152395;-0.499369;,
  0.843835;0.384117;-0.374695;,
  0.602910;0.582652;-0.544993;,
  0.690089;0.263029;-0.674236;,
  0.696727;0.606561;-0.382957;,
  -0.858032;-0.135822;0.495312;,
  0.757026;0.370360;-0.538279;,
  0.460917;0.715034;-0.525625;,
  -0.755299;-0.373387;0.538615;,
  -0.490113;-0.691252;0.530998;,
  0.895112;0.375470;-0.240411;,
  -0.802217;-0.538171;0.258495;,
  0.368123;-0.371619;-0.852282;,
  -0.368123;-0.371619;-0.852282;,
  0.274550;0.358652;-0.892183;,
  -0.274550;0.358652;-0.892183;,
  0.274552;0.358653;0.892182;,
  -0.274552;0.358653;0.892182;,
  0.368124;-0.371620;0.852281;,
  -0.368124;-0.371620;0.852281;,
  0.355043;0.464871;-0.811073;,
  -0.363183;-0.050358;0.930356;,
  0.000000;-0.360886;0.932610;,
  0.363183;-0.050358;0.930356;,
  -0.462635;-0.467244;0.753427;,
  0.462635;-0.467244;0.753427;,
  0.000000;-0.360886;-0.932610;,
  -0.363183;-0.050357;-0.930356;,
  0.000000;0.404714;-0.914443;,
  0.363183;-0.050357;-0.930356;,
  -0.355043;0.464871;-0.811073;,
  0.000000;0.404715;0.914443;,
  0.000000;-0.008241;-0.999966;,
  0.000000;0.642822;-0.766015;,
  0.000000;-0.008242;0.999966;,
  0.000000;-0.568307;0.822817;,
  -0.586238;-0.091240;-0.804984;,
  0.586240;-0.091241;0.804983;,
  -0.704045;0.000000;-0.710156;,
  -0.007409;0.999947;0.007194;,
  0.689228;0.000000;0.724544;,
  0.704045;0.000000;-0.710156;,
  0.007408;0.999947;0.007194;,
  -0.689228;0.000000;0.724544;,
  -0.704045;-0.075144;-0.706169;,
  -0.007412;0.995096;-0.098631;,
  0.689228;0.076680;0.720476;,
  0.704045;-0.075144;-0.706169;,
  0.007413;0.995096;-0.098632;,
  -0.689228;0.076728;0.720470;,
  0.333675;0.849523;0.408622;,
  0.662350;-0.749040;0.015188;,
  0.978168;-0.186399;-0.091889;,
  0.985360;-0.032810;-0.167299;,
  0.626762;0.539214;-0.562511;,
  0.660735;-0.479484;-0.577516;,
  0.475929;-0.357573;-0.803513;,
  0.667373;0.011479;-0.744635;,
  0.754390;0.390201;-0.527863;,
  0.644822;0.511169;-0.568252;,
  0.825828;-0.153217;-0.542709;,
  0.848438;0.054436;-0.526489;,
  0.692398;0.420745;-0.586138;,
  -0.000267;-0.999956;0.009358;,
  0.598739;-0.799965;-0.039582;,
  0.933121;-0.018917;-0.359064;,
  0.133327;0.969247;0.206845;,
  0.452139;0.749172;-0.484058;,
  0.858209;0.206193;-0.470066;,
  0.942549;-0.189719;-0.274969;,
  0.950712;0.245328;-0.189633;,
  0.286161;-0.210950;0.934672;,
  -0.571216;0.806551;0.152275;,
  0.163985;-0.082324;-0.983022;,
  0.902391;-0.338692;0.266417;,
  0.996224;-0.010427;-0.086186;,
  0.455530;-0.844782;0.280778;,
  0.000053;0.896471;0.443102;,
  0.203331;-0.973091;0.108403;,
  0.765039;-0.456049;-0.454680;,
  0.000872;-0.913306;0.407274;,
  0.000054;0.981419;0.191876;,
  -0.000000;-0.417957;-0.908467;,
  0.554715;0.616659;-0.558590;,
  -0.455535;-0.839622;0.295843;,
  -0.877845;-0.191125;0.439158;,
  -0.998325;-0.003197;-0.057763;,
  -0.133702;0.967308;0.215499;,
  -0.980482;-0.180642;-0.077611;,
  -0.663866;-0.747387;0.026347;,
  0.000906;-0.995174;0.098119;,
  -0.765039;-0.456050;-0.454680;,
  -0.660734;-0.479485;-0.577516;,
  -0.475929;-0.357574;-0.803513;,
  -0.667372;0.011479;-0.744636;,
  -0.000000;0.125991;-0.992031;,
  -0.754389;0.390202;-0.527863;,
  -0.825827;-0.153217;-0.542710;,
  -0.933200;-0.016811;-0.358963;,
  -0.858239;0.208021;-0.469205;,
  -0.453173;0.748883;-0.483537;,
  -0.598689;-0.799915;-0.041333;,
  -0.987170;-0.027944;-0.157212;,
  -0.945939;-0.174633;-0.273317;,
  -0.943905;0.274923;-0.182921;,
  -0.258987;-0.180618;0.948843;,
  0.571182;0.806581;0.152246;,
  -0.131694;-0.052116;-0.989920;,
  -0.848468;0.054638;-0.526419;,
  -0.627407;0.538916;-0.562076;,
  -0.693149;0.420624;-0.585337;,
  -0.333672;0.845908;0.416056;,
  0.000000;0.921465;-0.388461;,
  0.209941;-0.711859;-0.670210;,
  -0.000000;0.566730;0.823904;,
  0.079129;0.577191;0.812766;,
  0.050709;0.691938;0.720173;,
  -0.741897;-0.163925;0.650168;,
  0.446958;0.342887;0.826231;,
  0.000000;0.237157;0.971471;,
  0.072960;0.424129;0.902658;,
  0.225795;0.192409;0.954984;,
  -0.541452;0.109066;0.833627;,
  -0.084486;0.545004;0.834166;,
  0.417323;-0.899413;0.129994;,
  0.398145;-0.890312;0.220966;,
  -0.001061;-0.990078;0.140515;,
  -0.001568;-0.970667;0.240422;,
  -0.401020;-0.889304;0.219823;,
  -0.419387;-0.899124;0.125259;,
  0.400166;-0.908466;0.120647;,
  0.585449;-0.629416;-0.510965;,
  0.699577;-0.707539;-0.099903;,
  0.361198;-0.432899;-0.825914;,
  -0.692273;-0.619556;-0.370013;,
  -0.388081;-0.912330;0.130560;,
  -0.683416;-0.725525;-0.080969;,
  0.896326;0.047559;0.440837;,
  0.752995;-0.106400;0.649366;,
  0.911174;-0.230973;0.341195;,
  -0.891517;-0.011775;-0.452835;,
  -0.938109;0.170034;-0.301729;,
  -0.759314;0.029215;-0.650068;,
  0.535430;-0.328061;0.778261;,
  -0.628334;0.165360;-0.760166;,
  -0.896326;0.047559;0.440837;,
  -0.752995;-0.106399;0.649367;,
  -0.911174;-0.230974;0.341194;,
  0.891517;-0.011777;-0.452834;,
  0.938110;0.170032;-0.301726;,
  0.759315;0.029217;-0.650067;,
  -0.535431;-0.328061;0.778261;,
  0.628335;0.165362;-0.760165;,
  0.000000;0.642825;0.766013;,
  -0.355046;0.464874;0.811070;,
  0.355046;0.464874;0.811070;,
  0.000000;-0.568305;-0.822818;,
  -0.462633;-0.467241;-0.753430;,
  0.462633;-0.467241;-0.753430;,
  -0.586240;-0.091241;0.804983;,
  0.586238;-0.091240;-0.804984;,
  -0.007409;-0.999947;0.007194;,
  -0.717408;0.000000;0.696653;,
  0.717413;0.000000;-0.696648;,
  0.007408;-0.999947;0.007194;,
  0.717383;0.000000;0.696679;,
  -0.717405;0.000000;-0.696656;,
  -0.007409;-0.993575;0.112935;,
  -0.717377;0.073780;0.692768;,
  0.717393;-0.073718;-0.692757;,
  0.007411;-0.993575;0.112932;,
  0.717406;0.073782;0.692737;,
  -0.717389;-0.073724;-0.692761;,
  0.091744;-0.258155;0.961738;,
  -0.502718;0.860580;0.081713;,
  0.020454;-0.170800;-0.985093;,
  0.811710;-0.514354;-0.276706;,
  0.468914;-0.155148;0.869511;,
  -0.632522;0.742368;0.220920;,
  0.302854;0.008492;-0.952999;,
  0.489941;0.812152;0.316809;,
  0.371457;0.839344;0.396890;,
  -0.554715;0.616660;-0.558590;,
  -0.560705;-0.727096;-0.396158;,
  -0.644822;0.511169;-0.568252;,
  -0.066264;-0.229341;0.971088;,
  0.502718;0.860580;0.081713;,
  0.011176;-0.147146;-0.989052;,
  -0.811710;-0.514355;-0.276705;,
  -0.441347;-0.124669;0.888634;,
  0.632461;0.742437;0.220864;,
  -0.270686;0.044449;-0.961641;,
  -0.490703;0.805676;0.331807;,
  -0.371679;0.835705;0.404292;,
  -0.753082;-0.354140;0.554485;,
  -0.824386;-0.083314;0.559864;,
  -0.549023;-0.302465;0.779158;,
  -0.625246;0.219541;0.748912;,
  0.000000;-0.819150;0.573579;,
  -0.038291;-0.818549;0.573159;,
  0.038291;-0.818549;0.573159;,
  0.625246;0.219541;0.748912;,
  0.549023;-0.302465;0.779159;,
  0.245102;0.848750;0.468560;,
  -0.635465;-0.454819;-0.623959;,
  0.034096;-0.943050;0.330900;,
  0.026234;0.787584;-0.615649;,
  0.028985;0.808665;-0.587555;,
  0.008419;0.819917;-0.572421;,
  -0.008383;-0.939128;0.343465;,
  0.004063;0.810473;-0.585762;,
  -0.041838;-0.942266;0.332241;,
  -0.003722;0.820098;-0.572210;,
  -0.027812;0.808956;-0.587211;,
  -0.025158;0.787737;-0.615498;;
  194;
  4;0,14,20,17;,
  4;14,1,15,20;,
  4;20,15,3,16;,
  4;17,20,16,2;,
  4;2,16,21,8;,
  4;16,3,18,21;,
  4;177,178,5,19;,
  4;179,177,19,4;,
  4;4,19,22,11;,
  4;19,5,9,22;,
  4;22,9,7,10;,
  4;11,22,10,6;,
  4;6,10,23,13;,
  4;10,7,12,23;,
  4;180,181,1,14;,
  4;182,180,14,0;,
  4;1,181,24,15;,
  4;12,7,9,183;,
  4;183,9,5,178;,
  4;15,24,18,3;,
  4;6,13,25,11;,
  4;182,0,17,184;,
  4;184,17,2,8;,
  4;11,25,179,4;,
  4;26,43,46,40;,
  4;40,46,41,27;,
  4;46,42,29,41;,
  4;43,28,42,46;,
  4;28,34,47,42;,
  4;42,47,44,29;,
  4;185,45,31,186;,
  4;187,30,45,185;,
  4;30,37,48,45;,
  4;45,48,35,31;,
  4;48,36,33,35;,
  4;37,32,36,48;,
  4;32,39,49,36;,
  4;36,49,38,33;,
  4;188,40,27,189;,
  4;190,26,40,188;,
  4;27,41,50,189;,
  4;38,191,35,33;,
  4;191,186,31,35;,
  4;41,29,44,50;,
  4;32,37,51,39;,
  4;190,192,43,26;,
  4;192,34,28,43;,
  4;37,30,187,51;,
  4;52,66,72,69;,
  4;66,53,67,72;,
  4;72,67,55,68;,
  4;69,72,68,54;,
  4;54,68,73,60;,
  4;68,55,70,73;,
  4;193,194,57,71;,
  4;195,193,71,56;,
  4;56,71,74,63;,
  4;71,57,61,74;,
  4;74,61,59,62;,
  4;63,74,62,58;,
  4;58,62,75,65;,
  4;62,59,64,75;,
  4;196,197,53,66;,
  4;198,196,66,52;,
  4;53,197,76,67;,
  4;64,59,61,199;,
  4;199,61,57,194;,
  4;67,76,70,55;,
  4;58,65,77,63;,
  4;198,52,69,200;,
  4;200,69,54,60;,
  4;63,77,195,56;,
  4;78,78,78,78;,
  4;79,79,79,79;,
  4;80,80,80,80;,
  4;201,201,201,201;,
  4;202,202,202,202;,
  4;203,203,203,203;,
  4;81,81,81,81;,
  4;82,82,82,82;,
  4;83,83,83,83;,
  4;204,204,204,204;,
  4;205,205,205,205;,
  4;206,206,206,206;,
  4;84,84,84,84;,
  4;85,85,85,85;,
  4;86,86,86,86;,
  4;207,207,207,207;,
  4;208,208,208,208;,
  4;209,209,209,209;,
  4;87,87,87,87;,
  4;88,88,88,88;,
  4;89,89,89,89;,
  4;210,210,210,210;,
  4;211,211,211,211;,
  4;212,212,212,212;,
  4;152,121,106,107;,
  4;123,152,107,94;,
  4;103,104,91,130;,
  4;95,119,118,153;,
  4;96,95,153,122;,
  4;97,96,122,135;,
  4;99,98,97,135;,
  4;99,123,94,98;,
  4;101,100,97,98;,
  4;101,119,95,100;,
  4;96,97,100,95;,
  4;92,91,104,105;,
  4;93,92,105,108;,
  4;110,109,109,110;,
  4;94,107,108,102;,
  4;111,111,213,213;,
  4;112,112,214,106;,
  4;113,215,215,113;,
  4;216,216,93,108;,
  4;217,217,111,111;,
  4;112,218,218,112;,
  4;113,219,219,113;,
  4;109,109,216,216;,
  4;101,105,104,119;,
  4;102,108,105,101;,
  4;102,101,98,94;,
  4;165,164,166,167;,
  4;90,106,121,117;,
  4;91,92,114,116;,
  4;92,93,115,114;,
  4;220,106,90,221;,
  4;130,91,116,120;,
  4;152,140,127,121;,
  4;222,149,140,152;,
  4;103,130,129,141;,
  4;132,223,223,131;,
  4;133,122,153,132;,
  4;134,135,122,133;,
  4;224,135,134,136;,
  4;224,136,149,222;,
  4;148,136,134,137;,
  4;148,137,132,131;,
  4;133,132,137,134;,
  4;128,138,141,129;,
  4;142,139,138,128;,
  4;144,144,143,143;,
  4;149,150,139,140;,
  4;145,225,225,145;,
  4;146,127,226,146;,
  4;147,147,227,227;,
  4;228,139,142,228;,
  4;229,145,145,229;,
  4;146,146,230,230;,
  4;147,147,231,231;,
  4;143,228,228,143;,
  4;148,131,141,138;,
  4;150,148,138,139;,
  4;150,149,136,148;,
  4;168,167,166,169;,
  4;151,117,121,127;,
  4;129,124,125,128;,
  4;128,125,126,142;,
  4;232,233,151,127;,
  4;130,120,124,129;,
  3;162,163,161;,
  3;161,163,160;,
  3;160,163,159;,
  3;163,154,159;,
  3;154,155,159;,
  3;159,155,158;,
  3;155,156,158;,
  3;234,157,235;,
  4;117,151,155,154;,
  4;151,233,156,155;,
  4;236,125,157,234;,
  4;125,237,235,157;,
  4;124,120,238,239;,
  4;120,116,240,238;,
  4;241,241,161,160;,
  4;114,242,242,161;,
  4;221,90,163,243;,
  4;90,117,154,163;,
  4;171,170,172,171;,
  4;104,103,166,164;,
  4;173,171,171,173;,
  4;174,244,244,174;,
  4;103,141,169,166;,
  4;175,174,174,176;,
  4;245,104,170,245;,
  4;246,247,247,246;,
  4;247,248,248,247;,
  4;118,245,245,249;,
  4;248,250,250,248;,
  4;251,118,249,251;,
  4;250,252,252,250;,
  4;141,251,251,175;,
  4;252,253,253,252;,
  4;253,254,254,253;;
 }
 MeshTextureCoords {
  303;
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.125000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;0.250000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;0.250000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.575400;0.793600;,
  0.583900;0.743700;,
  0.626400;0.761000;,
  0.617600;0.783100;,
  0.582400;0.869900;,
  0.619900;0.865900;,
  0.779800;0.867200;,
  0.713900;0.826400;,
  0.747300;0.771300;,
  0.816200;0.810200;,
  0.666100;0.941600;,
  0.691400;0.895800;,
  0.691700;0.961900;,
  0.674700;0.965400;,
  0.650300;0.951100;,
  0.648500;0.969600;,
  0.633000;0.937800;,
  0.617000;0.954100;,
  0.603500;0.932300;,
  0.631200;0.918900;,
  0.669300;0.880900;,
  0.652000;0.929200;,
  0.713700;0.759900;,
  0.684200;0.815100;,
  0.645700;0.760900;,
  0.633400;0.789000;,
  0.959700;0.067600;,
  0.961500;0.076400;,
  0.932400;0.073800;,
  0.937100;0.067900;,
  0.643600;0.868500;,
  0.960400;0.093400;,
  0.972800;0.092800;,
  0.970600;0.109900;,
  0.956000;0.108900;,
  0.961500;0.052900;,
  0.930200;0.058500;,
  0.925600;0.044000;,
  0.952900;0.036100;,
  0.920500;0.061100;,
  0.915100;0.047100;,
  0.924900;0.087600;,
  0.925200;0.105800;,
  0.969700;0.076100;,
  0.691400;0.895800;,
  0.713900;0.826400;,
  0.779800;0.867200;,
  0.691700;0.961900;,
  0.626500;0.718900;,
  0.584600;0.717900;,
  0.746000;0.685400;,
  0.770400;0.684100;,
  0.726900;0.671800;,
  0.836500;0.782700;,
  0.424600;0.793600;,
  0.382400;0.783100;,
  0.373600;0.761000;,
  0.416100;0.743700;,
  0.417600;0.869900;,
  0.380100;0.865900;,
  0.220200;0.867200;,
  0.183800;0.810200;,
  0.252700;0.771300;,
  0.286100;0.826400;,
  0.333900;0.941600;,
  0.325300;0.965400;,
  0.308300;0.961900;,
  0.308600;0.895800;,
  0.349700;0.951100;,
  0.351500;0.969600;,
  0.367000;0.937800;,
  0.383000;0.954100;,
  0.396500;0.932300;,
  0.368800;0.918900;,
  0.330700;0.880900;,
  0.348000;0.929200;,
  0.286300;0.759900;,
  0.315800;0.815100;,
  0.354300;0.760900;,
  0.366600;0.789000;,
  0.040300;0.067600;,
  0.062900;0.067900;,
  0.067600;0.073800;,
  0.038600;0.076400;,
  0.356400;0.868500;,
  0.039600;0.093400;,
  0.044000;0.108900;,
  0.029500;0.110000;,
  0.027300;0.092800;,
  0.038600;0.052900;,
  0.047100;0.036100;,
  0.074400;0.044000;,
  0.069800;0.058500;,
  0.079500;0.061100;,
  0.084900;0.047100;,
  0.075100;0.087600;,
  0.074800;0.105800;,
  0.030300;0.076100;,
  0.308600;0.895800;,
  0.308300;0.961900;,
  0.220200;0.867200;,
  0.286100;0.826400;,
  0.373500;0.718900;,
  0.415400;0.718000;,
  0.229600;0.684100;,
  0.254000;0.685400;,
  0.273100;0.671800;,
  0.163500;0.782700;,
  0.726900;0.671800;,
  0.626500;0.718900;,
  0.746000;0.685400;,
  0.770400;0.684100;,
  0.836500;0.782700;,
  0.415400;0.718000;,
  0.373500;0.718900;,
  0.229600;0.684100;,
  0.273100;0.671800;,
  0.254000;0.685400;,
  0.691400;0.895800;,
  0.713900;0.826400;,
  0.713900;0.826400;,
  0.691400;0.895800;,
  0.691700;0.961900;,
  0.691700;0.961900;,
  0.308600;0.895800;,
  0.308300;0.961900;,
  0.308300;0.961900;,
  0.308600;0.895800;,
  0.286100;0.826400;,
  0.286100;0.826400;;
 }
}

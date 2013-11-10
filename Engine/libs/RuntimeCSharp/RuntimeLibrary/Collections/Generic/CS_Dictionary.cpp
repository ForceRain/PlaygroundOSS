﻿/* 
   Copyright 2013 KLab Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "CS_Dictionary.h"

namespace System {
namespace Collections {
namespace Generic {

static const u32 _dictionary_primeArray[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,233,239,251,257,263,269,277,281,293,307,311,317,331,337,347,353,359,367,373,379,383,389,397,401,409,419,431,439,449,457,463,479,487,499,509,521,541,547,557,563,569,577,587,593,599,607,617,631,641,653,661,673,683,691,701,709,719,727,739,751,761,769,787,797,809,821,839,853,863,877,887,907,919,929,941,953,967,977,991,1009,1021,1033,1049,1061,1087,1103,1117,1129,1151,1163,1181,1193,1213,1229,1249,1277,1291,1307,1321,1361,1381,1399,1423,1439,1459,1481,1499,1523,1543,1559,1579,1597,1613,1637,1657,1693,1721,1741,1759,1777,1801,1823,1847,1867,1889,1913,1933,1973,1993,2017,2039,2063,2087,2111,2137,2161,2203,2237,2267,2293,2333,2357,2381,2411,2437,2467,2503,2531,2557,2591,2617,2647,2677,2707,2741,2777,2819,2851,2887,2917,2953,2999,3037,3079,3119,3163,3203,3251,3299,3343,3389,3433,3469,3511,3547,3583,3623,3671,3709,3761,3803,3847,3889,3929,3989,4049,4091,4133,4177,4219,4271,4327,4373,4421,4481,4547,4597,4643,4691,4751,4799,4861,4919,4969,5021,5077,5147,5209,5273,5333,5387,5441,5501,5557,5623,5683,5741,5801,5861,5923,5987,6047,6113,6197,6263,6329,6397,6469,6547,6619,6689,6761,6829,6899,6971,7043,7121,7193,7283,7369,7451,7529,7607,7687,7789,7867,7949,8039,8123,8209,8293,8377,8461,8563,8663,8753,8849,8941,9041,9133,9227,9323,9419,9521,9619,9719,9817,9923,10037,10139,10243,10357,10463,10589,10709,10831,10949,11059,11171,11287,11411,11527,11657,11777,11897,12037,12161,12289,12413,12539,12671,12799,12941,13093,13229,13367,13513,13649,13789,13931,14071,14221,14369,14519,14669,14821,14983,15137,15289,15443,15601,15761,15919,16087,16249,16417,16603,16787,16963,17137,17317,17491,17669,17851,18041,18223,18413,18617,18839,19031,19231,19427,19661,19861,20063,20269,20477,20693,20903,21121,21341,21557,21773,21991,22229,22453,22679,22907,23143,23399,23633,23873,24113,24359,24611,24859,25111,25367,25621,25889,26153,26417,26683,26951,27239,27527,27803,28087,28387,28687,28979,29269,29567,29863,30169,30491,30803,31121,31469,31793,32117,32441,32771,33107,33457,33797,34141,34483,34841,35201,35569,35933,36293,36671,37039,37423,37799,38177,38561,38953,39343,39749,40151,40559,40973,41387,41801,42221,42649,43093,43541,43987,44449,44909,45361,45817,46279,46747,47221,47699,48179,48661,49157,49663,50177,50683,51193,51713,52237,52769,53299,53849,54401,54949,55501,56081,56659,57241,57829,58411,58997,59611,60209,60821,61441,62057,62683,63311,63949,64591,65239,65899,66569,67247,67927,68611,69313,70009,70717,71429,72161,72883,73613,74353,75109,75869,76631,77417,78193,78977,79769,80567,81373,82189,83023,83857,84697,85549,86413,87281,88169,89051,89959,90863,91781,92699,93629,94573,95527,96487,97453,98429,99431,100447,101461,102481,103511,104549,105601,106661,107741,108821,109913,111029,112153,113279,114419,115571,116731,117899,119083,120277,121487,122719,123953,125197,126457,127727,129011,130303,131611,132929,134263,135607,136973,138349,139739,141157,142573,143999,145441,146917,148387,149873,151379,152897,154439,156007,157571,159157,160751,162359,163987,165653,167311,168991,170689,172399,174137,175891,177677,179461,181273,183089,184949,186799,188677,190573,192497,194431,196379,198343,200329,202339,204367,206411,208489,210599,212777,214913,217069,219251,221447,223667,225919,228181,230467,232777,235111,237467,239843,242243,244667,247141,249647,252151,254699,257249,259823,262433,265079,267737,270421,273127,275881,278651,281509,284341,287191,290083,292993,295937,298897,301897,304933,308003,311099,314213,317363,320539,323759,326999,330271,333581,336929,340321,343727,347167,350657,354169,357727,361313,364937,368593,372289,376021,379787,383587,387433,391331,395251,399221,403219,407257,411337,415469,419651,423853,428093,432389,436717,441101,445537,450001,454507,459061,463663,468319,473009,477749,482527,487363,492251,497177,502171,507193,512269,517393,522569,527803,533089,538423,543811,549257,554753,560311,565919,571579,577307,583087,588923,594821,600791,606811,612889,619019,625213,631469,637787,644167,650609,657121,663709,670349,677057,683831,690671,697579,704563,711617,718741,725929,733189,740521,747941,755437,763001,770639,778357,786151,794023,801973,809993,818093,826279,834569,842923,851359,859891,868493,877181,885959,894869,903827,912869,922021,931267,940607,950023,959533,969131,978839,988643,998537};


	

}
}
}
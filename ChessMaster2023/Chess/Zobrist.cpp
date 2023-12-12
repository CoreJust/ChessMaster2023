/*
*	ChessMaster, a free UCI / Xboard chess engine
*	Copyright (C) 2023 Ilyin Yegor
*
*	ChessMaster is free software : you can redistribute it and /or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*
*	ChessMaster is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with ChessMaster. If not, see <https://www.gnu.org/licenses/>.
*/

#include "Zobrist.h"

namespace zobrist {
	const Hash PIECE[Piece::VALUES_COUNT][Square::VALUES_COUNT] = {
		{
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul
		}, {
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
			0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul
		}, {
			0x9d4f956136c7cc53u, 0x80aeb28101a3de33u, 0x03e0265ea1978d42u, 0x34d81ae6bea45566u,
			0xff8cb61a32be9a44u, 0x81563103a4083e82u, 0x29921b549291bb21u, 0x10218dc9019af633u,
			0x170b0a3598502e35u, 0xdcb2a36a97f92854u, 0x21ee3fba8d672f8au, 0xb96c34e68d85ba1eu,
			0xd9c02c22bb6c3d05u, 0xb866993fa35e73e5u, 0x009c04c311c718deu, 0xffe99d44047937eeu,
			0x7cc2a698a2967489u, 0x44cd13cf3388b9d4u, 0x0ab5087bbdc25691u, 0xf39708f799838071u,
			0xc08c0ddaa9223a07u, 0x143d0e669a73ffa4u, 0xfd04810a2a0c3babu, 0xae7a2169bfecfef7u,
			0xf53700f4a976b8bbu, 0xe2458e973404743cu, 0x2a488ff00e39a14au, 0x95e3b1950275e9d3u,
			0x5ec112fd2f4c4055u, 0xaaf0bc71b34a3c67u, 0xa1713d482d01c91du, 0x5bada846029b42ddu,
			0x99491c5431edf379u, 0x0a0182cb17becf54u, 0x33de9b06887d0feau, 0x9f7c225b9fd267f3u,
			0xd55033e49677c63du, 0x223737790a84e317u, 0x3ba5103b1e67f009u, 0xcffe3d0686cab373u,
			0xc3f910623a184cafu, 0xa4888b93a3a9e927u, 0x81ca0c4e2c5e53e7u, 0xf42b3008a8af2cc2u,
			0xfb49118b0450594cu, 0x5f6783b497659adeu, 0x3c85a2423c1fb885u, 0xb486aff69a62c8c9u,
			0x026731680132eb8au, 0xfe0038390b5895fcu, 0x95808bf437cc9ff6u, 0x645b98779bc33a72u,
			0x7ddc9d8b83a36e50u, 0xc7781d7e13cf0924u, 0x1817155b862953e4u, 0x5b011e8386e8d32fu,
			0x03d438510f994678u, 0xee2f142418fe705du, 0x7f96afc82ed9f80bu, 0x1d170aa527657374u,
			0x7d322d922f11b3edu, 0x8d5925353c8e004bu, 0xd309a653a6acaddau, 0x9f258f7726778d34u
		}, {
			0x1fe9b7f11a1dc915u, 0x5368b2d929feff6du, 0xc7ac2cb8b79a859cu, 0x155c026b2d20906au,
			0xe99f9e6d9c48b0e4u, 0x8bfe14473d2886ebu, 0x92c48aea9debef48u, 0xf8862d79bf07d173u,
			0x1de6aa7f86380bc4u, 0x2e00b62109e1f03du, 0xfe08a7e02feeef6au, 0x21ff004526d98235u,
			0x9b97352c1aedbacfu, 0x765d345a0cfc6b31u, 0x67033fce11547ad1u, 0x1b388654a84c9411u,
			0x7a688c7a2d264a7au, 0x7fe6a7070c9915eau, 0xdd1788f8a0b9699eu, 0x907ca20631279606u,
			0x544b3c38b03c5d39u, 0x92fca76ba2d7ceddu, 0xf4b4245a94db9a61u, 0x2f4f0433a6cabb29u,
			0xaaef8cfa80cfca7bu, 0xbeaa198bb0abdb98u, 0x7a62ab5abdb69da8u, 0xdc759b9501490047u,
			0xff05ae94b235148bu, 0x05a222b735ebce9cu, 0xbee128008624dfe2u, 0xb454a7a99a0d5e68u,
			0x1729a39483508451u, 0x0153beb0b30a8927u, 0x61d103d13210cc63u, 0x60931864279bcdc0u,
			0x80f299dc2a15c8fbu, 0x25102086a7b8fbebu, 0xebf8097d02dd3b97u, 0xb98e004719c88cf6u,
			0x18eda3a9375bb87eu, 0xb7bcac980ff636c0u, 0xf42a1b4c2affbed8u, 0xf70e8642bd198027u,
			0x6c51a68bbc6bbd61u, 0x54d00412a8543ee0u, 0x77040cf62aef242cu, 0x15a734dcb4544354u,
			0xba85b9cbbb975d98u, 0xd2b7bb9197b4068bu, 0xd86fa7983d0c3828u, 0x5de3adfb1295d1e7u,
			0x1053103c8603da8bu, 0x7bd88bb39ba0a0e5u, 0x2e08ae69205adef4u, 0x4c5a34d6ad35d5d2u,
			0x0c24b979a5e73f96u, 0xc5d2a158ad8ffe73u, 0x055cb1f9bcbf26ceu, 0xeaeba839b3071809u,
			0x2d84ae99b5750966u, 0x9aeb897a2f4fe101u, 0x71ecbdb08f3897eeu, 0x370ba1bba169bc54u
		}, {
			0xc6658e8b2ec5ea4cu, 0x6e9c95b32984168bu, 0x67aa99ac98bf668au, 0x126a8dc1b25716f2u,
			0x06bf2ab127181a6bu, 0x995b0773bfc7880du, 0x10d21b641799279bu, 0xe5f016121e084b89u,
			0x3c62a42e8543d039u, 0xf2653e003c25745cu, 0x44f1be460cad3ec7u, 0x71a6a0d38a136a3bu,
			0x0b701cf22952441eu, 0x6b4f8114acd6ea56u, 0xbe1c0faeb5f4a4adu, 0x89e8109527d505f7u,
			0x78a53f892f40158du, 0x021784752ce75df8u, 0xc88683c3a9fad335u, 0x923787041077d229u,
			0x61b0a45c254416d2u, 0x634b19de8b903e23u, 0xfcadb4bf056f6c86u, 0x8ef999abab59b917u,
			0x0cf11b650208dedfu, 0x48798dc181d3b9e4u, 0x2cabad0f8fd20f3eu, 0x46ec37e72c85191eu,
			0x7b1b344104ca1397u, 0x3b0c975c22dfe264u, 0x939bbb8b9ca1f74eu, 0xda8e3dda29c6c898u,
			0xc0ebbef5a63062b5u, 0x4b8db53e8c772e36u, 0x544338130029d0bau, 0xfa463a9f22f908f7u,
			0x7462b6bab26a74d1u, 0x1b4b8ce9a23ad712u, 0xcec9383cadad9697u, 0x47babc523d15475cu,
			0xb0d02a03af14b0acu, 0x1eac8fbe0db46b9eu, 0xc642002185b5f27du, 0x45d393a025622040u,
			0x0f9f24a41095b871u, 0x7b5ea66fbb1f760bu, 0x68420cf3a09e92c9u, 0x47c0bb25ab8eb1b5u,
			0x1c441f7a147129c0u, 0xbbea9a9eafece73du, 0x813c396427429b5cu, 0xf2fc0ecf38be1410u,
			0xb029b4a7390485c0u, 0x85ac00c695239763u, 0x3b939c5c227aa2c5u, 0x5d2409ac83c60014u,
			0x6ffc05561e98f569u, 0x5a7301b2322d4246u, 0x9a74ba039ba053e7u, 0xf91186542cbf2ee3u,
			0x9991b38c9dd9020fu, 0x9599b7db8502dd99u, 0x3c6b36e386f32f31u, 0xa4d62218a21c1c0au
		}, {
			0x68c3812f3cbffff7u, 0x7a4aa30f2833b38cu, 0x6bda953a8d05800cu, 0x140284ea3647f8fdu,
			0xfce0869e2f59f5a6u, 0xe9d2a44197312b53u, 0x85310f179d88c7c2u, 0xbb83969c0262c763,
			0xa3008b2837e1b7a1u, 0xbe8410a122d35adfu, 0x5e4c8685b0ce7938u, 0xc718377393463e44u,
			0x6c8a99a2336815a1u, 0xbe9cbbb10abb701fu, 0xedc6ba093f1750dcu, 0x4602010827f7d222,
			0xa4050001a773d367u, 0x03411d7d1ddd2720u, 0x88de2d6f39b7a169u, 0x492c988e0dc7a8f5u,
			0x7d661c980040c490u, 0xbaa80c8b09da6fd3u, 0x6d95911a00a6cad2u, 0x64e3ab992ebdc096,
			0x228619eaaa262ba8u, 0x0fe3b5ed2af93e0du, 0x4df7b0e900319680u, 0x09322ffe09a07959u,
			0xfdb1b32ca815f07eu, 0x824b257396c207cdu, 0xd67714c328ceacbfu, 0x5ad788d49d9ea8f9,
			0x6c5b3b5aa93c81b8u, 0xae868ffe3b3835c3u, 0xc1721cc1130d1773u, 0x2ee5129a339c99bau,
			0x13ed00f43fc9f5a8u, 0xe33731ef0cb20a0eu, 0xe9d502f601a90610u, 0xcaf6b8728f1c99ca,
			0x32bc8854bacb3e5fu, 0x534133bc9c564146u, 0x76d98cdd13bd46c9u, 0x0c0c948b30c67eeau,
			0x6f1ab6ae05330501u, 0xc7b6a6a4913271bbu, 0x72ec165e9912a908u, 0x56053d9c3494c24c,
			0x9e8627a48bf88058u, 0x63618b7a1df7ecfdu, 0xcfab807e9a96bd20u, 0xfdb7838b359d98bcu,
			0xbefe07848d595aacu, 0x19ee359d2d54a79du, 0xb90bada288e9253fu, 0x37af3d2c817dab03,
			0x74742c20933d7ad3u, 0x04b33c081eeceb34u, 0xa997157fa310eba7u, 0x5581a927055fd289u,
			0xac5d864a3ab5c485u, 0x771d0a840ef556a2u, 0x39d31aa1874c921eu, 0xebcc83f2bea87e3b
		}, {
			0xa70337dd8c0bda15u, 0xb67222ed0e0ce672u, 0x143d07621c6ea222u, 0x6224afe4a0f2468du,
			0x74049a35bd0d1295u, 0x4563b2b22b6400bdu, 0x47e28e0537ba1fbdu, 0xd94137181417d502,
			0x81c0876ba61111fdu, 0x8a5cb60425eab3c5u, 0x2a19289fa450eebcu, 0x6a538c25aa738e52u,
			0x3ee7133b81307f57u, 0xf043ac2f0ea98c8cu, 0x8603a6dd34bbcf60u, 0x5f861fac90b40890,
			0x6bc70f041d7882b5u, 0x0b64b187087d4f2cu, 0xd1e7bc349516ad30u, 0x2f2b3a69a8519c45u,
			0x1a9e3efe252fb102u, 0xd39e8159bf6e2ca7u, 0x89500f2f08a065f3u, 0x257801f83dfc1ad8,
			0x1c0c3e163f333b1cu, 0x042bb600a0aba2e2u, 0xf84f90548f6ef5deu, 0x8cde00b529a0e92fu,
			0xf1a6aa68ad7cf420u, 0x030b99140d258aecu, 0x39e102b3263f3d10u, 0x770612c0a218a294,
			0x08a71459aac30305u, 0xea0e35bc20c71985u, 0x8b6a800c326a523cu, 0x2068ba1f2e6ea7dau,
			0x86c10a50a93bd36eu, 0x937bbf23884ed5dcu, 0xef60a29b0bf316a5u, 0x0889bbfcbecc3ec1,
			0x5310bb11347d19bau, 0xe4613d083fcb4a99u, 0x61049e8237bc7f50u, 0xd0d1090f1702a598u,
			0xad2f88b51881fe5eu, 0x3e78906f33b2751du, 0x934bb4d283d7c776u, 0x9c06131714b43f23,
			0x3c6406488fc84475u, 0x63b482749e9d3706u, 0x14db0a3717f9803au, 0x406791813b1f3abdu,
			0x00f63a001a967f95u, 0xfd682f3f9da1cdf6u, 0xc3300b3f2c0b319au, 0xfe68972a0e875cbe,
			0xf1630e2f1dbca7a6u, 0xb0989d039f40a60cu, 0xdcdb2129be3b988fu, 0x30a524e32f4894e1u,
			0x898888ad264b160bu, 0xff3e95158d50c9fau, 0x918238230769f721u, 0x40b99533a35bde4c
		}, {
			0x49251a95a4a9c8a8u, 0xe3141d4d03103f3cu, 0x88d118240ef91ccdu, 0x84d116b19a568fa1u,
			0x442a0d771832c138u, 0xdc0ebac42461984bu, 0xf0e5802d2e2dff8cu, 0x1f28bf86bb260464,
			0xa8a280f897d2af4eu, 0xc5efb6292d6c0f10u, 0xa0580c932f35ef55u, 0xdb5926ea379aea64u,
			0x728631bf9aaa5142u, 0x58449a8fa0a24f9cu, 0xfed23e2b9ee27038u, 0x4e7434838a0a3942,
			0x97eb1491194ff377u, 0x1282089394c7661cu, 0xdba298140417468cu, 0x143434978815bc19u,
			0x7157b38e1c102c28u, 0x462f004a144b849fu, 0x4fdc96fea55b8de7u, 0x28b624c9811457df,
			0xce34ba0c2451da83u, 0x46ae2955bd47f31bu, 0x0999b01a368d3551u, 0x38d403fe861bb609u,
			0xcf5d890f13167cf6u, 0xd0a62b169c12adb0u, 0x1a5c819da0b194b4u, 0x5b1e875e25acf772,
			0xa9d50e630e9b32c7u, 0x2b0f06fc9a7ff52bu, 0x92953ef135e90f98u, 0x7376367584fa537eu,
			0xbb973857891f7ce7u, 0x9bd986fa3db555cfu, 0x9c3e027a037ef90fu, 0x3b46907920d6477c,
			0x5c870017aac11209u, 0x9a3b32158caa6851u, 0x3ea18f01141d2cecu, 0x90603ca5a0393a4bu,
			0x4586a4a6008259efu, 0x7894991b993bd122u, 0xb53caac0141e1239u, 0x747127c3826e383e,
			0x27a4907632696405u, 0x9801ad7105ec41f2u, 0xcbbc9e0a29fefae8u, 0x172190c912daab41u,
			0x7d7003a522c56d32u, 0x9f7c340482388173u, 0xb926bf95b4ee94c8u, 0xf4cc2699ac6ab33d,
			0x5f3bb57f0752fe93u, 0x38239240867ae7b1u, 0x596903c2b6a915a2u, 0x46a21fbfbbd22387u,
			0xc3e31e5d3076fe55u, 0xb7393de3093a0f3fu, 0xdfad22681efe2c85u, 0x7f47953f99b5d07c
		}, {
			0xaf2911578e999bafu, 0x38301a2faf3dcdeau, 0x49972f802ca6400bu, 0x040701500a756438u,
			0x0551886288ca518fu, 0xbdd38478aa2881fcu, 0x283b0d8e88e3372fu, 0x753a37e69f8ee58a,
			0xefa61fd015265f92u, 0x093c1910a1587cbfu, 0xa9089a61197c4b02u, 0xb2288fc022bc627au,
			0x6f669d2d07d65b60u, 0xd69f0ed228a4c951u, 0xe83327f4058b0363u, 0x92cc078c3bfaf439,
			0xb07138a7a2f8f5adu, 0x5099aaa1aabb7bf0u, 0xbe10290d8eba3d7bu, 0x30468f1715141871u,
			0x6193a2482ce28603u, 0x3a5a115cb07387bbu, 0xc93a90879ed912afu, 0x369e9c0ca00687a9,
			0x08feb5cc218259dfu, 0xbf6a97ed28ce3eb8u, 0x11d538393d8e24d7u, 0xbd1481d98710efe7u,
			0x7ed6371fa0e15b00u, 0x931aa37b2b898017u, 0x97eab981a02683adu, 0x7f212eae105ab795,
			0x9fe591769cc5e0fcu, 0xb98a0bbe906258b6u, 0x76f18170a58a1f89u, 0xa00d8f9e9f402ca7u,
			0x3a6eb30827754215u, 0x8452117294e599e5u, 0x986d8a92b04cfd4cu, 0xab2d3de79d3a43fb,
			0xcf1f3f682596f74cu, 0x94ce9ae52af2aa6cu, 0x47b0865a30e01f9bu, 0xaab8b74e3469cd01u,
			0xe01fb281053467b4u, 0xc60b08aa29cf95ccu, 0x08bfa02791e7594fu, 0xdf4603a2a5c1bd9c,
			0xd846ae2e3bdcaf09u, 0x2848146fbbe59dc3u, 0x5c5023f698a5fd2au, 0x29e6096324cffa4au,
			0x2c6c0c74ade67383u, 0xb82a0beb0319d213u, 0x02efb2a62b949ecbu, 0xdad9b37b03283e80,
			0x54769a5989ba34f5u, 0xe5a9257f865e1e3bu, 0x81a912760db96e49u, 0x8aa885ee1c9654b0u,
			0xb2bfbd370f947353u, 0x4fcdbbd20b6dd5a9u, 0x5baa256706549cbdu, 0xbf7f24bd82e9fb70
		}, {
			0xd10f042391dba329u, 0x8dc62193ba94a27cu, 0x2e8fb5763d74dbddu, 0x87c737c0994dd454u,
			0x4f7bb2f816d3939au, 0x72b297cf24ba4dd2u, 0xd5e21e2a0fda96a6u, 0xd375a838a9510874,
			0xd6cc0bf1a60bf2cau, 0x544326b9a9ad8cd2u, 0x2c2bba08ab2551c3u, 0x6ec20ea813d70694u,
			0x3589bd8510b46db3u, 0x835410f68eb109aau, 0x4a260c36b0b5d8e3u, 0xd48da0c70e854973,
			0x7d5923480273d956u, 0x9dab1fb1b25920a8u, 0xc12f97213cff61ffu, 0x536391e9374c414du,
			0xeb51332c9fa70e91u, 0xf81ebc913be5c5fbu, 0xdd6b23cb3d19444cu, 0x6f30afc202d2ba38,
			0xec6a99563ec5092eu, 0x366089c60b3e15b9u, 0xb90310b2ac711471u, 0x699e8247147fa6c9u,
			0x60111c9a1ede5e3du, 0x92690a41a38b1222u, 0xb28a925fac9d59fau, 0xdb0d90b00a22f2fc,
			0x52d785939d41dda5u, 0x5d7f0c032a6ed424u, 0xe0802f89894cd20eu, 0xfe2f0d99a53fc353u,
			0x5b48a2628c3d72f6u, 0xf4e4268d35e03220u, 0x83ef22e59a5c735eu, 0x103e0c481bf8443e,
			0x02d9a1032cfe9982u, 0x9c1cbf7602a5a0ecu, 0x6c31ac8d1605275eu, 0xf7db0108bb946dbbu,
			0xd4fa9a462e98f7adu, 0xb6db271b0d6dd319u, 0x65d4bd0905326cb9u, 0xa485aeb3a6af5f3f,
			0x164b077034227582u, 0x84893f702888da77u, 0x6e9603fdabef56ffu, 0xd8b4034f18ff37d6u,
			0x8dea3c6d83f96287u, 0xdf723ef408454fd8u, 0x408a0c7097fc9fa2u, 0x189085cebabf8e87,
			0x1913a4be2cf41acau, 0x91281ec006ec59a8u, 0x5d9b35438b6af284u, 0x1cb91f6eb994385eu,
			0x161e0d3a8ba3c505u, 0x70fc16e3bbeb2d37u, 0x9579a920056c97c9u, 0xd9610bad86f7ef28
		}, {
			0x6ed69af9b66faf18u, 0x5bd63b798d164cf1u, 0x67b9920609654043u, 0x581182032ee06ff4u,
			0x4aa735378a4f5759u, 0x5aabbcc73c150bccu, 0x29db99ff8b146df1u, 0x71db187c806e7d23,
			0xae142d5c928338f6u, 0xf703a724ae6d4f49u, 0x69c0138aac2fd398u, 0x6925aba2b2ece6b1u,
			0x44ee3ac6bd44d83au, 0xb66328fcbac7a0a7u, 0xa4aa92f3286240b7u, 0x33b98833a9a9c8f2,
			0x86a33c733fc16e74u, 0x29b6afc413a0e444u, 0x9d008a4f16e58416u, 0xd58a850c96be46adu,
			0x26910e3abc5e15d3u, 0xa77d09e79ea14f5fu, 0xa46db8c8081af2bcu, 0xda6ca7e991797f8a,
			0x40788caa0419b872u, 0xb39106e18c98881eu, 0xef2321860b36541fu, 0x26728d469668eaafu,
			0x2b0e217e150dd6afu, 0xb691a76a2c1673d1u, 0x423cb4378e15e79bu, 0x06e43563bb04b9a6,
			0xe2ab92bb181078c2u, 0x1eee8fc910a57776u, 0xff40b13ca931f726u, 0x45dab866bef9a783u,
			0x7624ae67bf76df8cu, 0x15908e4988a4ae7eu, 0x06c2b37289adab43u, 0xa279039a850fd844,
			0x3fb58ce788f848adu, 0xa024a7c9bbc2dbcfu, 0xd424a99a0b8c1436u, 0x27c821d51db8ac79u,
			0x841783f504af59dau, 0x73053c6dac15190bu, 0x3c7ba96535fe9c77u, 0xac2eb0f6ad372d26,
			0x29b1043c2339076eu, 0x2cc3b67233d58810u, 0x3a8da61eabda5869u, 0x1b8c068d1768f3e6u,
			0xc9ea3b912cfd8a40u, 0x3554151eb9ba0ac0u, 0x31f6b4f50226e74du, 0x9df225943b313352,
			0x75123cacb9000014u, 0x6aa186033023a9fau, 0xb53f142ab7be7253u, 0xd4d3b4413acbde8fu,
			0x15feb668aca4c36au, 0x52c4971682b2a5e8u, 0xb51a959324476da9u, 0x3ced120f8ddfbba4
		}, {
			0xa880bdd984558f7bu, 0x325fafe18ec1dd4bu, 0x2d162d3018783d3du, 0x4ce5a818332cc717u,
			0xced4b7212b3cecccu, 0x45bebb61983a4beau, 0x3426a90f028f8d10u, 0x286b10b30ce4d395,
			0xed7e2c12228c8217u, 0xb97e22519796d424u, 0x21c70ee6249ca081u, 0xb9532eaea7fb92d3u,
			0x05953cf29586eaf4u, 0x5fcb9ee514e81e48u, 0x9fc1a42934908adeu, 0xa04f85d2356802b4,
			0x544f2c27a2e00506u, 0xbcbc22d83692d6c4u, 0x29842a96a46ef3c2u, 0x76bb30829b6a3891u,
			0xf3531b728b06ebc9u, 0x9076015f80a733e7u, 0xee42377f87de6e00u, 0x08530c82b3f967a1,
			0x4d28b7c83980b7a9u, 0x5efb973e94dca5e7u, 0xb43512b3a1dd33e1u, 0x3b90aad7b4cb4b99u,
			0x67ccadcc8b6e9455u, 0xe79402f4ad2b3524u, 0xdf0087098c90fc90u, 0x9aa4a4c98b009b95,
			0x9761a0ec15300253u, 0x05d79f11ab05d2acu, 0xbb332e8a0d38ded3u, 0xff0f9805146d6937u,
			0xc302bf160922d7d5u, 0xa65710a835331f00u, 0x30e824390641f4fdu, 0x41ddabde8081900f,
			0x8db3ab16018454ccu, 0xc8e69bdf3e49eb16u, 0x0789a58119753621u, 0x5a7ea1b382d7193cu,
			0xe576978e0f775e3bu, 0x3a8910a22dc777a0u, 0xb4b48d3aac4db889u, 0x9641926ba158b751,
			0x9a798c921122b4cfu, 0xe8f8817685cd368cu, 0xb837325920675167u, 0x626e1b1d080bbe7bu,
			0xa86c31deb0f4baadu, 0x99d0166b3f7912cdu, 0x7f351433b21245ccu, 0x32fd9acbac7cbce1,
			0x50730a2535ddb4d1u, 0x8214a3482a051f2fu, 0xb095172c1ab3bdb6u, 0xb2f80c65883dd745u,
			0xaa6120c0ba983e84u, 0xbd27046b87c4cfbeu, 0x1a8d92c02ae3ee5cu, 0x9a233fe3bfa1f0e4
		}, {
			0x960c94c3838d9451u, 0xd16386cba796e389u, 0x86a42ef432aca2ccu, 0x7e43b1fe8e3369bfu,
			0x1404a0b4819c23f3u, 0x9beb9b9e21299e2cu, 0xdcc43358be4d4403u, 0xdf2498db36b51bcb,
			0x950a30119e281e2bu, 0x4bb320408d2aab63u, 0xbc3f941c1c6b087du, 0x974a9fcc9b051af9u,
			0x877dac08217af5e3u, 0xb78ebaaf8512928du, 0x1b6a27d99d41075au, 0x724fa1a319c086ba,
			0xee5d1a6633d16d0cu, 0x76bb80ee032e8828u, 0x7eb99ff82d990101u, 0xdef61c4a2d5026f9u,
			0x719682d493a16074u, 0xdb08aafa09f70394u, 0xc2e807f084638618u, 0xe0e3258e1253827b,
			0x1a7a82b026f956d5u, 0x209f82de0c0b7f15u, 0xd0388c3ab86583b7u, 0x70f8a2fb17a85987u,
			0x5e4da9850a02672fu, 0x1d70a4e10ecae61cu, 0xc0d6b2d5b00d68d9u, 0x6e4f26e1a216a8c8,
			0x78fa18279ca2ca58u, 0x1a3a81dc2190f5c7u, 0xe4578f713d61d914u, 0xb1cf34760d9a986fu,
			0x19e2bc6f31402bd3u, 0x0f3735a8a38b93a7u, 0xca5f9d3a1817208au, 0x266c8d15364dfb9e,
			0xa4d4238e9ea20ddfu, 0x4e62a3b6323a5ec2u, 0xce61084207c05d20u, 0xf7ff88a392f04402u,
			0xf917bd1116f1d4d0u, 0x3567abb8ba82fedau, 0x8e7f908a301e10efu, 0xcabe9b12ab140dc0,
			0xd0a3887205de4da3u, 0xb927287d066e75edu, 0x7f9290ae119611f9u, 0x955a08ff12e92793u,
			0xe970075597ddc3ceu, 0x34e60ada018277feu, 0x4845922bafc00b1eu, 0xb7b32d7536a23b34,
			0x1335b527ab8d8902u, 0x9f823e8f1c914949u, 0x379d26473c4b24adu, 0xaf26afdc09e9b27eu,
			0xf345b4423d7d8652u, 0xd823a6e333203ab7u, 0x55d288a72141e9e4u, 0x69031d29843d9ee8
		}, {
			0x077a87b7bc178d9cu, 0x30e18837bf966fabu, 0x8464bf51a00340eeu, 0x642c27b727f3e7ebu,
			0xc23619f2156dccceu, 0xcd32a57c3ee29292u, 0x0bb320dc864ce2cau, 0xd60838f525dfe5c5,
			0x04b8215b0d55dd33u, 0x15a1a8f1b7286506u, 0xd92a8b2b9b9c5b8eu, 0x1b0c06fd34088f23u,
			0xaaa830082920c906u, 0xcdab845c33470d76u, 0x0fa506042a73862au, 0x09b923a5beb36505,
			0xe4cd2f2f3a947686u, 0x7fb5120621748870u, 0x14a09273ba667bd4u, 0x8e3a90643470a1e5u,
			0x695cac609e2e43d2u, 0x0f358eb6a290ce64u, 0x5260921b85ab0b05u, 0x8c1dbb0b1487e01a,
			0xb86e95621483e5f4u, 0x007e11bf1a2323a6u, 0xeb2eb61c16d093a1u, 0x96ab3db026ff2479u,
			0xf690bca798c71f3du, 0x5027152fb8f396b7u, 0x4fbe9f9b808bfc76u, 0x19e383ab2847713e,
			0x8774206d3666a0d2u, 0x641800281c4570c5u, 0xdaae3bf281acb5e9u, 0xa61895b91282c52cu,
			0xfac48e71bfd02b84u, 0xc031854bbbae1c71u, 0x2b290675072f7decu, 0x1025af3d8e73aaf1,
			0x5d161e512851c3e6u, 0xf098874fbf9546d1u, 0x50aa39dd1e6d5934u, 0x604a1ea63602bcccu,
			0x66fa1c7ea31e0d9au, 0x239f95b1ba48beb7u, 0x51dc9b54097175a9u, 0x29a612ebb26a4073,
			0xb4301fdb896ba1ecu, 0xad5033859db9d631u, 0x28a0291c87676a1fu, 0x345018332000bf30u,
			0xe4f623f729b8f5a2u, 0x8e95ba6aa7d54a52u, 0x0d2896de03300745u, 0x6c12a59081a1be4b,
			0x755aa5b3a20fcca8u, 0xd2e91fd82fc6b846u, 0x6257a97ca484f738u, 0x895f26a4a7cf803bu,
			0xd8ac18ee3d556ad4u, 0x53b9867c2cc5f6d5u, 0x0eea1f480f623040u, 0x398d31e183b3d5b0
		}
	};

	const Hash SIDE[Color::VALUES_COUNT] = {
		0xad1534d76ee22478,
		0x99c3d5949fcc5f7f
	};

	const Hash EP[File::VALUES_COUNT] = {
		0xb464f9c619169ea0,
		0x1d76f322f4c79c1f,
		0x83aa0824e258f148,
		0x3272b2f1070e0605,
		0x1a42793eac83c3e9,
		0xedc39960c163ea16,
		0xf233372f5bdab522,
		0x1c238893f82941f5,
	};

	const Hash CASTLING[64] = { 
		0x23A178F905F40B94,
		0x4835DA3FE5C725D9,
		0xDAC0E152F66B4FE9,
		0x32285B4059DAF5BB,
		0xDF33824EDF0C029E,
		0xE32D67CC22181213,
		0xA6B2F2E672D3E2AD,
		0xCC82668866B1C5C3,
		0x88C053FFB4E0983C,
		0xCDFA46775E5BB2BE,
		0x99DC7094BCDD23A8,
		0x93C3339CAE8038BC,
		0x01702A7FCC62384C,
		0x8CF821902E538592,
		0x2D76500A0826E535,
		0x25A18887013E95FA,
		0x693FFF1BF4624B24,
		0xD416195B1A1E625B,
		0x0867171DE10E7DC1,
		0x95B9B625AA2889F5,
		0x0C031856B35B4797,
		0x27ABFC9DFC70DC40,
		0xD3D00D9E3304519C,
		0x66BF52047DE8E610,
		0xBA411AF150CD5A55,
		0x78D47B2B79140F33,
		0xDB637074AA026FEA,
		0x8F832F0AFB53EA44,
		0x2DFD7A0076747A30,
		0x2674B6B5C32FD180,
		0x183705328003206E,
		0x8675476A80CBCD8E,
		0xBEE4D22D72573AE0,
		0xFB65769E96666340,
		0x11B67784304BF91A,
		0x1912FB3EABA2AFE4,
		0xF2B662F8FAC2324B,
		0x1D1199A4978DD510,
		0xFFB73FD1A457A705,
		0xC78BA0F009B35D40,
		0xD8EDB357C91430D6,
		0xBADB489DAFDCC0DC,
		0xAD534EF06876D081,
		0xB7F8C886E1732671,
		0x0AEAED169FA7E6CE,
		0xEB0586848D588D19,
		0x7E1A980599E92991,
		0x9D880BDBC889957E,
		0xD95EBA0EB851FBF,
		0x3F47C71675DC09F7,
		0x07052FBE1EBCFFB7,
		0x939BA174CFDF852D,
		0xB930228878C50E00,
		0x6CBA1411E085AA67,
		0xD6A0E5784F634284,
		0xEB2927F2580188FA,
		0x6169D4862EA33F53,
		0x1523958BEACA6C3C,
		0x5217F31E442BBE3E,
		0xBD7D2857159EB08D,
		0x5E003B7243047728,
		0x5951B7CA95D5CE4D,
		0xF32390EE2F00B0DB,
		0xEFEFB654D862A61F,
	};
}
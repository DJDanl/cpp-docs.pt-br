---
title: Classe tiled_index | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency::tiled_index
dev_langs:
- C++
helpviewer_keywords:
- tiled_index class
ms.assetid: 0ce2ae26-f1bb-4436-b473-a9e1b619bb38
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 2c10721f40bd1c90a196ba82655482f35a8e10d8
ms.lasthandoff: 02/25/2017

---
# <a name="tiledindex-class"></a>Classe tiled_index
Fornece um índice em uma [tiled_extent](tiled-extent-class.md) objeto. Essa classe tem propriedades para acessar elementos relativo à origem do bloco local e relativo à origem global. Para obter mais informações sobre espaços de lado a lado, consulte [blocos usando](../../../parallel/amp/using-tiles.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <
    int _Dim0,  
    int _Dim1 = 0,  
    int _Dim2 = 0  
>  
class tiled_index : public _Tiled_index_base<3>;  
 
template <
    int _Dim0,  
    int _Dim1  
>  
class tiled_index<_Dim0, _Dim1, 0> : public _Tiled_index_base<2>;  
 
template <
    int _Dim0  
>  
class tiled_index<_Dim0, 0, 0> : public _Tiled_index_base<1>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Dim0`  
 O comprimento da dimensão mais significativo.  
  
 `_Dim1`  
 O comprimento da dimensão próximo a mais significativa.  
  
 `_Dim2`  
 O comprimento da dimensão menos significativo.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor tiled_index](#ctor)|Inicializa uma nova instância da classe `tile_index`.|  

  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método get_tile_extent](#tiled_index__get_tile_extent)|Retorna um [extensão](extent-class.md) objeto que tem os valores de `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.|  


  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Barrier](#tiled_index__barrier)|Armazena um [tile_barrier](tile-barrier-class.md) objeto que representa uma barreira no bloco atual de threads.|  
|||  
|[Constante global](#tiled_index__global)|Armazena um [índice](index-class.md) objeto de índice de ordem 1, 2 ou 3 que representa global em um [grade](http://msdn.microsoft.com/en-us/f7d1b6a6-586c-4345-b09a-bfc26c492cb0) objeto.|  
|[Constante local](#tiled_index__local)|Armazena um `index` o objeto de índice de ordem 1, 2 ou 3 que representa a relação no bloco atual de um [tiled_extent](tiled-extent-class.md) objeto.|  
|[Constante Rank](#tiled_index__rank)|Armazena a classificação do `tiled_index` objeto.|  
|[Constante Tile](#tiled_index__tile)|Armazena um `index` objeto de classificação 1, 2 ou 3 que representa as coordenadas do bloco atual de uma `tiled_extent` objeto.|  
|[Constante tile_dim0](#tiled_index__tile_dim0)|Armazena o comprimento da dimensão mais significativo.|  
|[Constante tile_dim1](#tiled_index__tile_dim1)|Armazena o comprimento da dimensão próximo a mais significativa.|  
|[Constante tile_dim2](#tiled_index__tile_dim2)|Armazena o comprimento da dimensão menos significativo.|  
|[Constante tile_origin](#tiled_index__tile_origin)|Armazena um `index` objeto de coordenadas de ordem 1, 2 ou 3 que representa global da origem do bloco atual em um `tiled_extent` objeto.|  

  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados tile_extent](#tile_extent)|Obtém um [extensão](extent-class.md) objeto que tem os valores de `tiled_index` argumentos de modelo `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.|  

  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Tiled_index_base`  
  
 `tiled_index`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  


## <a name="a-nametiledindexctora--tiledindex-constructor"></a><a name="tiled_index__ctor"></a>Construtor tiled_index  
Inicializa uma nova instância da classe `tiled_index`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
tiled_index(  
    const index<rank>& _Global,  
    const index<rank>& _Local,  
    const index<rank>& _Tile,  
    const index<rank>& _Tile_origin,  
    const tile_barrier& _Barrier ) restrict(amp,cpu);  
  
tiled_index(  
    const tiled_index& _Other ) restrict(amp,cpu);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Global`  
 Global [índice](index-class.md) do construído `tiled_index`.  
  
 `_Local`  
 Local [índice](index-class.md) do construído`tiled_index`  
  
 `_Tile`  
 O bloco [índice](index-class.md) do construído`tiled_index`  
  
 `_Tile_origin`  
 A origem do bloco [índice](index-class.md) do construído`tiled_index`  
  
 `_Barrier`  
 O [tile_barrier](tile-barrier-class.md) objeto o construído `tiled_index`.  
  
 `_Other`  
 O `tile_index` objeto a ser copiado para o construído `tiled_index`.  
  
## <a name="overloads"></a>Sobrecargas  
  
|||  
|-|-|  
|Nome|Descrição|  
|`tiled_index(const index<rank>& _Global, const index<rank>& _Local, const index<rank>& _Tile, const index<rank>& _Tile_origin, const tile_barrier& _Barrier restrict(amp,cpu);`|Inicializa uma nova instância de `tile_index` classe do índice de bloco em coordenadas globais e a posição relativa no bloco em coordenadas locais. O `_Global` e `_Tile_origin` parâmetros são computados.|  
|`tiled_index(    const tiled_index& _Other) restrict(amp,cpu);`|Inicializa uma nova instância de `tile_index` classe copiando especificado `tiled_index` objeto.|  


## <a name="a-nametiledindexgettileextenta--gettileextent"></a><a name="tiled_index__get_tile_extent"></a>get_tile_extent
Retorna um [extensão](extent-class.md) objeto que tem os valores de `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
extent<rank> get_tile_extent()restrict(amp,cpu);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um `extent` objeto que tem os valores de `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.  

## <a name="a-nametiledindexbarriera--barrier"></a><a name="tiled_index__barrier"></a>barreira   
Armazena um [tile_barrier](tile-barrier-class.md) objeto que representa uma barreira no bloco atual de threads.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
const tile_barrier barrier;  
```  

## <a name="a-nametiledindexglobala--global"></a><a name="tiled_index__global"></a>global   
Armazena um [índice](index-class.md) objeto de classificação 1, 2 ou 3, que representa o índice de um objeto global.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
const index<rank> global;  
```  
  
## <a name="a-nametiledindexlocala--local"></a><a name="tiled_index__local"></a>local   
Armazena um [índice](index-class.md) o objeto de índice de ordem 1, 2 ou 3 que representa a relação no bloco atual de um [tiled_extent](tiled-extent-class.md) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
const index<rank> local;  
```  
  
## <a name="a-nametiledindexranka--rank"></a><a name="tiled_index__rank"></a>classificação   
Armazena a classificação do `tiled_index` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static const int rank = _Rank;  
```  

## <a name="a-nametiledindextilea--tile"></a><a name="tiled_index__tile"></a>lado a lado   
Armazena um [índice](index-class.md) objeto de classificação 1, 2 ou 3 que representa as coordenadas do bloco atual de um [tiled_extent](tiled-extent-class.md) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
const index<rank> tile;  
```  
  
## <a name="a-nametiledindextiledim0a--tiledim0"></a><a name="tiled_index__tile_dim0"></a>tile_dim0  
Armazena o comprimento da dimensão mais significativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim0 = _Dim0;  
```  
   
## <a name="a-nametiledindextiledim1a--tiledim1"></a><a name="tiled_index__tile_dim1"></a>tile_dim1   
Armazena o comprimento da dimensão próximo a mais significativa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim1 = _Dim1;  
```  
## <a name="a-nametiledindextiledim2a--tiledim2"></a><a name="tiled_index__tile_dim2"></a>tile_dim2   
Armazena o comprimento da dimensão menos significativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim2 = _Dim2;  
```  
## <a name="a-nametiledindextileorigina--tileorigin"></a><a name="tiled_index__tile_origin"></a>tile_origin   
Armazena um [índice](index-class.md) objeto de coordenadas de ordem 1, 2 ou 3 que representa global da origem do bloco atual dentro de um [tiled_extent](tiled-extent-class.md) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
const index<rank> tile_origin  
```  
## <a name="a-nametileextenta--tileextent"></a><a name="tile_extent"></a>tile_extent
  Obtém um [extensão](extent-class.md) objeto que tem os valores de `tiled_index` argumentos de modelo `tiled_index` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_tile_extent)) extent<rank> tile_extent;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)


---
title: Classe tiled_extent | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- tiled_extent
- AMP/tiled_extent
- AMP/Concurrency::tiled_extent::tiled_extent
- AMP/Concurrency::tiled_extent::get_tile_extent
- AMP/Concurrency::tiled_extent::pad
- AMP/Concurrency::tiled_extent::truncate
- AMP/Concurrency::tiled_extent::tile_dim0
- AMP/Concurrency::tiled_extent::tile_dim1
- AMP/Concurrency::tiled_extent::tile_dim2
- AMP/Concurrency::tiled_extent::tile_extent
dev_langs:
- C++
ms.assetid: 671ecaf8-c7b0-4ac8-bbdc-e30bd92da7c0
caps.latest.revision: 9
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: e295b56290435a1d87ac2f0dbc0951850600534d
ms.lasthandoff: 03/31/2017

---
# <a name="tiledextent-class"></a>Classe tiled_extent
Um `tiled_extent` objeto é um `extent` objeto de um a três dimensões que subdivide o espaço de extensão em uma, duas ou blocos tridimensionais.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
template <
    int _Dim0,  
    int _Dim1,  
    int _Dim2  
>  
class tiled_extent : public Concurrency::extent<3>;  
 
template <
    int _Dim0,  
    int _Dim1  
>  
class tiled_extent<_Dim0, _Dim1, 0> : public Concurrency::extent<2>;  
 
template <
    int _Dim0  
>  
class tiled_extent<_Dim0, 0, 0> : public Concurrency::extent<1>;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Dim0`  
 O comprimento da dimensão mais significativo.  
  
 `_Dim1`  
 O comprimento da dimensão próximo ao mais significativo.  
  
 `_Dim2`  
 O comprimento da dimensão menos significativo.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de tiled_extent](#ctor)|Inicializa uma nova instância da classe `tiled_extent`.|  

  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_tile_extent](#get_tile_extent)|Retorna um `extent` que captura os valores do objeto de `tiled_extent` argumentos de template `_Dim0`, `_Dim1`, e `_Dim2`.|  
|[preenchimento](#pad)|Retorna um novo `tiled_extent` objeto com extensões ajustada a ser divisível por dimensões lado a lado.|  
|[Truncar](#truncate)|Retorna um novo `tiled_extent` objeto com extensões ajustada para baixo para ser divisível por dimensões lado a lado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Copia o conteúdo de especificado `tiled_index` deste objeto.|  

  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante tile_dim0](#tile_dim0)|Armazena o comprimento da dimensão mais significativo.|  
|[Constante tile_dim1](#tile_dim1)|Armazena o comprimento da dimensão próximo ao mais significativo.|  
|[Constante tile_dim2](#tile_dim2)|Armazena o comprimento da dimensão menos significativo.|  

  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tile_extent](#tile_extent)|Obtém um `extent` que captura os valores do objeto de `tiled_extent` argumentos de template `_Dim0`, `_Dim1`, e `_Dim2`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `extent`  
  
 `tiled_extent`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  

## <a name="ctor"></a> tiled_extent construtor  
Inicializa uma nova instância da classe `tiled_extent`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent();  
  
tiled_extent(  
    const Concurrency::extent<rank>& _Other );  
  
tiled_extent(  
    const tiled_extent& _Other );  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `extent` ou `tiled_extent` objeto a ser copiado.  
  

  

## <a name="get_tile_extent"></a> get_tile_extent   
Retorna um `extent` que captura os valores do objeto de `tiled_extent` argumentos de template `_Dim0`, `_Dim1`, e `_Dim2`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
Concurrency::extent<rank> get_tile_extent() const restrict(amp,cpu);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `extent` que captura as dimensões desse objeto `tiled_extent` instância.  
  

## <a name="pad"></a>  pad   
Retorna um novo `tiled_extent` objeto com extensões ajustada a ser divisível por dimensões lado a lado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent pad() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo `tiled_extent` objeto, por valor. 
## <a name="truncate"></a> truncar   
Retorna um novo `tiled_extent` objeto com extensões ajustada para baixo para ser divisível por dimensões lado a lado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent truncate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um novo `tiled_extent` objeto com extensões ajustada para baixo para ser divisível por dimensões lado a lado.  

## <a name="operator_eq"></a> operador =   
Copia o conteúdo de especificado `tiled_index` deste objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent&  operator= (  
    const tiled_extent& _Other ) restrict (amp, cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `tiled_index` objeto do qual copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `tiled_index` instância.  

## <a name="tile_dim0"></a> tile_dim0   
Armazena o comprimento da dimensão mais significativo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim0 = _Dim0;  
```  
  
## <a name="tile_dim1"></a> tile_dim1   
Armazena o comprimento da dimensão próximo ao mais significativo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim1 = _Dim1;  
```  
## <a name="tile_dim2"></a> tile_dim2   
Armazena o comprimento da dimensão menos significativo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim2 = _Dim2;  
```  
## <a name="tile_extent"></a> tile_extent   
  Obtém um `extent` que captura os valores do objeto de `tiled_extent` argumentos de template `_Dim0`, `_Dim1`, e `_Dim2`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_tile_extent)) Concurrency::extent<rank> tile_extent;  
```  
  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)


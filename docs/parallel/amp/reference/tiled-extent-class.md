---
title: Classe tiled_extent | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency::tiled_extent
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: c2f7ebdb9c82ae24cf74064e710ddfb177670359
ms.lasthandoff: 02/25/2017

---
# <a name="tiledextent-class"></a>Classe tiled_extent
A `tiled_extent` objeto é uma `extent` objeto de um a três dimensões que subdivide o espaço de extensão em uma, duas ou blocos tridimensionais.  
  
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
 O comprimento da dimensão próximo a mais significativa.  
  
 `_Dim2`  
 O comprimento da dimensão menos significativo.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor tiled_extent](#ctor)|Inicializa uma nova instância da classe `tiled_extent`.|  

  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método get_tile_extent](#tiled_extent__get_tile_extent)|Retorna um `extent` que captura os valores do objeto de `tiled_extent` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.|  
|[Método de preenchimento](#tiled_extent__pad)|Retorna um novo `tiled_extent` objeto com extensões ajustado para cima para ser divisível por dimensões lado a lado.|  
|[Método truncar](#tiled_extent__truncate)|Retorna um novo `tiled_extent` objeto com extensões ajustada para baixo para ser divisível por dimensões lado a lado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador Operator =](#operator_eq)|Copia o conteúdo especificado `tiled_index` deste objeto.|  

  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante tile_dim0](#tiled_extent__tile_dim0)|Armazena o comprimento da dimensão mais significativo.|  
|[Constante tile_dim1](#tiled_extent__tile_dim1)|Armazena o comprimento da dimensão próximo a mais significativa.|  
|[Constante tile_dim2](#tiled_extent__tile_dim2)|Armazena o comprimento da dimensão menos significativo.|  

  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados tile_extent](#tiled_extent__tile_extent)|Obtém um `extent` que captura os valores do objeto de `tiled_extent` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `extent`  
  
 `tiled_extent`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  

## <a name="tiled_extent__ctor"></a> construtor tiled_extent  
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
  

  

## <a name="tiled_extent__get_tile_extent"></a> get_tile_extent   
Retorna um `extent` que captura os valores do objeto de `tiled_extent` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
Concurrency::extent<rank> get_tile_extent() const restrict(amp,cpu);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `extent` que captura as dimensões desse objeto `tiled_extent` instância.  
  

## <a name="tiled_extent__pad"></a>  pad   
Retorna um novo `tiled_extent` objeto com extensões ajustado para cima para ser divisível por dimensões lado a lado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent pad() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo `tiled_extent` objeto por valor. 
## <a name="tiled_extent__truncate"></a> truncar   
Retorna um novo `tiled_extent` objeto com extensões ajustada para baixo para ser divisível por dimensões lado a lado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent truncate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um novo `tiled_extent` objeto com extensões ajustada para baixo para ser divisível por dimensões lado a lado.  

## <a name="tiled_extent__operator_eq"></a> operador =   
Copia o conteúdo especificado `tiled_index` deste objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
tiled_extent&  operator= (  
    const tiled_extent& _Other ) restrict (amp, cpu);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `tiled_index` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `tiled_index` instância.  

## <a name="tiled_extent__tile_dim0"></a> tile_dim0   
Armazena o comprimento da dimensão mais significativo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim0 = _Dim0;  
```  
  
## <a name="tiled_extent__tile_dim1"></a> tile_dim1   
Armazena o comprimento da dimensão próximo a mais significativa.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim1 = _Dim1;  
```  
## <a name="tiled_extent__tile_dim2"></a> tile_dim2   
Armazena o comprimento da dimensão menos significativo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static const int tile_dim2 = _Dim2;  
```  
## <a name="tiled_extent__tile_extent"></a> tile_extent   
  Obtém um `extent` que captura os valores do objeto de `tiled_extent` argumentos de modelo `_Dim0`, `_Dim1`, e `_Dim2`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
__declspec(property(get= get_tile_extent)) Concurrency::extent<rank> tile_extent;  
```  
  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)


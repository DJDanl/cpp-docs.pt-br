---
title: Classe writeonly_texture_view | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- writeonly_texture_view
- AMP_GRAPHICS/writeonly_texture_view
- AMP_GRAPHICS/Concurrency::graphics::writeonly_texture_view
- AMP_GRAPHICS/Concurrency::graphics::writeonly_texture_view::set
- AMP_GRAPHICS/Concurrency::graphics::rank Constant
dev_langs:
- C++
ms.assetid: 8d117ad3-0a1c-41ae-b29c-7c95fdd4d04d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a6b1bc5c90fd837f56dbd98eddb37f624e78080b
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33695399"
---
# <a name="writeonlytextureview-class"></a>Classe writeonly_texture_view
Fornece acesso writeonly com uma textura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <
    typename value_type,  
    int _Rank  
>  
class writeonly_texture_view;  
 
template <
    typename value_type,  
    int _Rank  
>  
class writeonly_texture_view<value_type, _Rank> : public details::_Texture_base<value_type, _Rank>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `value_type`  
 O tipo dos elementos na textura.  
  
 `_Rank`  
 A classificação da textura.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`scalar_type`||  
|`value_type`|O tipo dos elementos na textura.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de writeonly_texture_view](#ctor)|Inicializa uma nova instância da classe `writeonly_texture_view`.|  
|[~ writeonly_texture_view destruidor](#ctor)|Destrói a `writeonly_texture_view` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[set](#set)|Define o valor do elemento no índice especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Copia especificado `writeonly_texture_view` deste objeto.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante de classificação](#rank)|Obtém a classificação do `writeonly_texture_view` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Texture_base`  
  
 `writeonly_texture_view`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="dtor"></a> ~ writeonly_texture_view 

 Destrói a `writeonly_texture_view` objeto.  
  
```  
~writeonly_texture_view() restrict(amp,cpu);
```  
  
##  <a name="operator_eq"></a> operador = 

 Copia especificado `writeonly_texture_view` deste objeto.  
  
```  
writeonly_texture_view<value_type, _Rank>& operator= (
    const writeonly_texture_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 `writeonly_texture_view` objeto do qual copiar.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `writeonly_texture_view` objeto.  
  
##  <a name="rank"></a> Classificação 

 Obtém a classificação do `writeonly_texture_view` objeto.  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="set"></a> Definir 

 Define o valor do elemento no índice especificado.  
  
```  
void set(
    const index<_Rank>& _Index,  
    const value_type& value) const restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Index`  
 O índice do elemento.  
  
 `value`  
 O novo valor do elemento.  
  
##  <a name="ctor"></a> writeonly_texture_view 

 Inicializa uma nova instância da classe `writeonly_texture_view`.  
  
```  
writeonly_texture_view(
    texture<value_type, 
    _Rank>& _Src) restrict(amp);

 
writeonly_texture_view(
    const writeonly_texture_view<value_type,  
    _Rank>& _Src) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A classificação da textura.  
  
 `value_type`  
 O tipo dos elementos na textura.  
  
 `_Src`  
 A textura que é usada para criar o `writeonly_texture_view`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)

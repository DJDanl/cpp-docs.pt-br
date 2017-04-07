---
title: Classe writeonly_texture_view | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- writeonly_texture_view
- AMP_GRAPHICS/writeonly_texture_view
- AMP_GRAPHICS/Concurrency::graphics::writeonly_texture_view
- AMP_GRAPHICS/Concurrency::graphics::writeonly_texture_view::set
- AMP_GRAPHICS/Concurrency::graphics::rank Constant
dev_langs:
- C++
ms.assetid: 8d117ad3-0a1c-41ae-b29c-7c95fdd4d04d
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 5a051b8db98e36ced89783bfa1de2ab5f514c6bc
ms.lasthandoff: 03/17/2017

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
|[Construtor writeonly_texture_view](#ctor)|Inicializa uma nova instância da classe `writeonly_texture_view`.|  
|[~ writeonly_texture_view destruidor](#ctor)|Destrói o `writeonly_texture_view` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[set](#set)|Define o valor do elemento no índice especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Copia especificado `writeonly_texture_view` objeto a este.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Rank](#rank)|Obtém a classificação do `writeonly_texture_view` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `_Texture_base`  
  
 `writeonly_texture_view`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_graphics.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="dtor"></a>~ writeonly_texture_view 

 Destrói o `writeonly_texture_view` objeto.  
  
```  
~writeonly_texture_view() restrict(amp,cpu);
```  
  
##  <a name="operator_eq"></a>operador = 

 Copia especificado `writeonly_texture_view` objeto a este.  
  
```  
writeonly_texture_view<value_type, _Rank>& operator= (
    const writeonly_texture_view<value_type, _Rank>& _Other) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 `writeonly_texture_view`objeto a ser copiado do.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `writeonly_texture_view` objeto.  
  
##  <a name="rank"></a>classificação 

 Obtém a classificação do `writeonly_texture_view` objeto.  
  
```  
static const int rank = _Rank;  
```  
  
##  <a name="set"></a>definir 

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
  
##  <a name="ctor"></a>writeonly_texture_view 

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
 A textura é usada para criar o `writeonly_texture_view`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)


---
title: Operadores &lt;allocators&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: []
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
caps.latest.revision: 11
manager: ghogen
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 0a2da6c72e8900c0cea86c30c6b8511e6b256ff9
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;
|||  
|-|-|  
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|  
  
##  <a name="op_neq"></a>  operator!=  
 Testa a desigualdade entre objetos do alocador de uma classe especificada.  
  
```
template <class Type, class Sync>  
bool operator!=(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um dos objetos alocadores a serem testados quanto à desigualdade.|  
|`right`|Um dos objetos alocadores a serem testados quanto à desigualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os objetos alocadores não forem iguais, **false** se eles forem iguais.  
  
### <a name="remarks"></a>Comentários  
 O operador de modelo retorna `!(left == right)`.  
  
##  <a name="op_eq_eq"></a>  operator==  
 Testa a igualdade entre objetos do alocador de uma classe especificada.  
  
```
template <class Type, class Sync>  
bool operator==(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um dos objetos alocadores a serem testados quanto à igualdade.|  
|`right`|Um dos objetos alocadores a serem testados quanto à igualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os objetos alocadores forem iguais, **false** se eles não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Esse operador de modelo retorna `left.equals(right)`.  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)





---
title: Operadores &lt;allocators&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6185bc74c530d6327d0ac37a5425a7653ba36841
ms.lasthandoff: 02/25/2017

---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;
|||  
|-|-|  
|[operator!=](#operator_neq)|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_neq"></a>  operator!=  
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
  
##  <a name="operator_eq_eq"></a>  operator==  
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





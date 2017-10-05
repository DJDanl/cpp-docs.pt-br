---
title: Operadores &lt;allocators&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/std::operator!=
- allocators/std::operator==
dev_langs:
- C++
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
caps.latest.revision: 11
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: c6b19eb0c4f8d63ce288ce47a759e949714daf5e
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

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





---
title: Operadores &lt;forward_list&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 57492e09-3836-4dbc-9ae5-78ecf506c190
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a560de0a7587b5552fc663bdd2b44734a66b5f73
ms.lasthandoff: 02/25/2017

---
# <a name="ltforwardlistgt-operators"></a>Operadores &lt;forward_list&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|[operator&gt;=](#operator_gt__eq)|  
|[operator&lt;](#operator_lt_)|[operator&lt;=](#operator_lt__eq)|[operator==](#operator_eq_eq)|  
  
##  <a name="a-nameoperatoreqeqa--operator"></a><a name="operator_eq_eq"></a>  operator==  
 Testa se o objeto da lista de encaminhamento à esquerda do operador é igual ao objeto da lista de encaminhamento à direita.  
  
```
bool operator==(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="remarks"></a>Comentários  
 Esta função de modelo sobrecarrega `operator==` para comparar dois objetos da classe de modelo `forward_list`. A função retorna `distance(left.begin(), end()) == distance(right.begin(),right.end()) && equal(left. begin(),left. end(),right.begin())`.  
  
##  <a name="a-nameoperatorneqa--operator"></a><a name="operator_neq"></a>  operator!=  
 Testa se o objeto da lista de encaminhamento à esquerda do operador não é igual ao objeto da lista de encaminhamento à direita.  
  
```
bool operator!=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se as listas não forem iguais; **false** se as listas forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Esta função do modelo retorna `!(left == right)`.  
  
##  <a name="a-nameoperatorlta--operatorlt"></a><a name="operator_lt_"></a>  operator&lt;  
 Testa se o objeto da lista de encaminhamento à esquerda do operador é menor que o objeto da lista de encaminhamento à direita.  
  
```
bool operator<(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esta função de modelo sobrecarrega `operator<` para comparar dois objetos da classe de modelo `forward_list`. A função retorna `lexicographical_compare(lhs. begin(), lhs. end(), rhs.begin(), rhs.end())`.  
  
##  <a name="a-nameoperatorlteqa--operatorlt"></a><a name="operator_lt__eq"></a>  operator&lt;=  
 Testa se o objeto da lista de encaminhamento à esquerda do operador é menor ou igual ao objeto da lista de encaminhamento à direita.  
  
```
bool operator<=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esta função do modelo retorna `!(right < left)`.  
  
##  <a name="a-nameoperatorgta--operatorgt"></a><a name="operator_gt_"></a>  operator&gt;  
 Testa se o objeto da lista de encaminhamento à esquerda do operador é maior que o objeto da lista de encaminhamento à direita.  
  
```
bool operator>(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esta função do modelo retorna `right < left`.  
  
##  <a name="a-nameoperatorgteqa--operatorgt"></a><a name="operator_gt__eq"></a>  operator&gt;=  
 Testa se o objeto da lista de encaminhamento à esquerda do operador é maior ou igual ao objeto da lista de encaminhamento à direita.  
  
```
bool operator>=(
    const forward_list <Type, Allocator>& left,
    const forward_list <Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `forward_list`.|  
|`right`|Um objeto do tipo `forward_list`.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a lista de encaminhamento no lado esquerdo do operador for maior que ou igual à lista de encaminhamento à direita do operador; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 A função do modelo retorna `!(left < right)`.  
  
## <a name="see-also"></a>Consulte também  
 [<forward_list>](../standard-library/forward-list.md)





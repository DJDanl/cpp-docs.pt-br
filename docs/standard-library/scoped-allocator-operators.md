---
title: Operadores &lt;scoped_allocator&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- scoped_allocator/std::operator!=
- scoped_allocator/std::operator==
dev_langs:
- C++
ms.assetid: 4dfe0805-cc6e-479f-887f-a1c164f73837
caps.latest.revision: 
manager: ghogen
ms.openlocfilehash: 2b4a7cd767385fd0eb3b7bfb0c98cd6bd3a411e6
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltscopedallocatorgt-operators"></a>Operadores &lt;scoped_allocator&gt;
|||  
|-|-|  
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|  
  
##  <a name="op_neq"></a>  operator!=  
 Testa dois objetos `scoped_allocator_adaptor` quanto à desigualdade.  
  
```cpp  
template <class Outer, class... Inner>  
bool operator!=(
    const scoped_allocator_adaptor<Outer, Inner...>& left,  
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 O objeto `scoped_allocator_adaptor` à esquerda.  
  
 `right`  
 O objeto `scoped_allocator_adaptor` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `!(left == right)`  
  
##  <a name="op_eq_eq"></a>  operator==  
 Testa dois objetos `scoped_allocator_adaptor` quanto à igualdade.  
  
```cpp  
template <class Outer, class... Inner>  
bool operator==(
    const scoped_allocator_adaptor<Outer, Inner...>& left,  
    const scoped_allocator_adaptor<Outer, Inner...>& right) noexcept;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 O objeto `scoped_allocator_adaptor` à esquerda.  
  
 `right`  
 O objeto `scoped_allocator_adaptor` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `left.outer_allocator() == right.outer_allocator() && left.inner_allocator() == right.inner_allocator()`  
  
## <a name="see-also"></a>Consulte também  
 [<scoped_allocator>](../standard-library/scoped-allocator.md)


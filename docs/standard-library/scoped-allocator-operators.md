---
title: "Operadores &lt;scoped_allocator&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.tgt_pltfrm: ""
ms.topic: "article"
ms.assetid: 4dfe0805-cc6e-479f-887f-a1c164f73837
caps.latest.revision: 10
manager: "ghogen"
---
# <a name="ltscopedallocatorgt-operators"></a>Operadores &lt;scoped_allocator&gt;
|||  
|-|-|  
|[operator!=](#operator_neq)|[operator==](#operator_eq_eq)|  
  
##  <a name="a-nameoperatorneqa--operator"></a><a name="operator_neq"></a>  operator!=  
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
  
##  <a name="a-nameoperatoreqeqa--operator"></a><a name="operator_eq_eq"></a>  operator==  
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


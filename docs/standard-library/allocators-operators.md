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
dev_langs: C++
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
caps.latest.revision: "11"
manager: ghogen
ms.openlocfilehash: 986d972bdc778ddd47c2c0098955f2b570c881ce
ms.sourcegitcommit: a7e4956c1150273e8dd39fda8b41655a6cf2cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/08/2017
---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;

Essas são as funções de operador de modelo global definidas no &lt;alocadores&gt;. Para funções de operador de membro de classe, consulte a documentação da classe.

|||
|-|-|
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|

##  <a name="op_neq"></a>  operator!=

Testa a desigualdade entre objetos do alocador de uma classe especificada.

```cpp
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

```cpp
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

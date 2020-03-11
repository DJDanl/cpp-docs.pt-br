---
title: Operadores &lt;alocadores&gt;
ms.date: 11/04/2016
f1_keywords:
- allocators/std::operator!=
- allocators/std::operator==
ms.assetid: b55d67cb-3c69-46bf-ad40-e845fb096c4e
ms.openlocfilehash: b7429e298cdf14d727fc481db6c4a3bf8574b5e7
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78875952"
---
# <a name="ltallocatorsgt-operators"></a>Operadores &lt;alocadores&gt;

Essas são as funções de operador de modelo global definidas em &lt;alocadores&gt;. Para funções de operador de membro de classe, consulte a documentação da classe.

|||
|-|-|
|[operator!=](#op_neq)|[operator==](#op_eq_eq)|

## <a name="op_neq"></a>  operator!=

Testa a desigualdade entre objetos do alocador de uma classe especificada.

```cpp
template <class Type, class Sync>
bool operator!=(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*left*|Um dos objetos alocadores a serem testados quanto à desigualdade.|
|*right*|Um dos objetos alocadores a serem testados quanto à desigualdade.|

### <a name="return-value"></a>Valor retornado

**true** se os objetos alocadores não forem iguais, **false** se eles forem iguais.

### <a name="remarks"></a>Comentários

O operador de modelo retorna `!(left == right)`.

## <a name="op_eq_eq"></a>  operator==

Testa a igualdade entre objetos do alocador de uma classe especificada.

```cpp
template <class Type, class Sync>
bool operator==(
    const allocator_base<Type, Sync>& left,
    const allocator_base<Type, Sync>& right);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*left*|Um dos objetos alocadores a serem testados quanto à igualdade.|
|*right*|Um dos objetos alocadores a serem testados quanto à igualdade.|

### <a name="return-value"></a>Valor retornado

**true** se os objetos alocadores forem iguais, **false** se eles não forem iguais.

### <a name="remarks"></a>Comentários

Esse operador de modelo retorna `left.equals(right)`.

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)

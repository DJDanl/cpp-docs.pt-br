---
title: Estrutura hash
ms.date: 11/04/2016
f1_keywords:
- typeindex/std::hash
ms.assetid: e5a41202-ef3b-45d0-b3a7-4c2dbdc0487a
ms.openlocfilehash: ef620867a5c31c7bd2030803edd6eaea6bbb5726
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68243716"
---
# <a name="hash-structure"></a>Estrutura hash

A classe de modelo define seu método como um `val.hash_code()` de retorno. O método define uma função de hash que é usada para mapear valores do tipo [type_index](../standard-library/type-index-class.md) para uma distribuição de valores de índice.

## <a name="syntax"></a>Sintaxe

```cpp
template <> struct hash<type_index>
: public unary_function<type_index, size_t>
{ // hashes a typeinfo object
    size_t operator()(type_index val) const;
};
```

## <a name="specialized-types"></a>Tipos especializados

### <a name="system_error"></a> \<system_error >

```cpp
template <class T> struct hash;
template <> struct hash<error_code>;
template <> struct hash<error_condition>;
```

## <a name="see-also"></a>Consulte também

[\<typeindex>](../standard-library/typeindex.md)<br/>

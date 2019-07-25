---
title: Classe is_trivial
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivial
helpviewer_keywords:
- is_trivial
ms.assetid: 6beb11d4-2f38-4c7e-9959-ca5d26250df7
ms.openlocfilehash: 1d218848fd65ca68022e3e66df02201582626711
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457430"
---
# <a name="istrivial-class"></a>Classe is_trivial

Testa se o tipo é um tipo trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivial;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for um tipo trivial, caso contrário, será false. Tipos triviais são tipos escalares, tipos de classe copiados de forma trivial, matrizes desses tipos e versões desses tipos qualificadas por CV.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)

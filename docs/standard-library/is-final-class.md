---
title: Classe is_final
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_final
helpviewer_keywords:
- is_final
ms.assetid: 9dbad82f-6685-4909-94e8-98e4a93994b9
ms.openlocfilehash: 14efbeb33193cc674c6e766b880e89d9b76d140a
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452650"
---
# <a name="isfinal-class"></a>Classe is_final

Testa se o tipo é um tipo de classe marcado como `final`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_final;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for `final`um tipo de classe marcado, caso contrário, será false. Se *T* for um tipo de classe, ele deverá ser um tipo completo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)\
[Especificador final](../cpp/final-specifier.md)

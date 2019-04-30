---
title: Classe is_final
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_final
helpviewer_keywords:
- is_final
ms.assetid: 9dbad82f-6685-4909-94e8-98e4a93994b9
ms.openlocfilehash: f605b160f6ed71aaafcc7c391e17180e4b243444
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346437"
---
# <a name="isfinal-class"></a>Classe is_final

Testa se o tipo é um tipo de classe marcado como `final`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_final;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é um tipo de classe marcado `final`, caso contrário, será falsa. Se *T* é um tipo de classe, ele deve ser um tipo completo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
[Especificador final](../cpp/final-specifier.md)<br/>

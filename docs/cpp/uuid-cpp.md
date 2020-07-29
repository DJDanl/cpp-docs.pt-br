---
title: uuid (C++)
ms.date: 11/04/2016
f1_keywords:
- uuid_cpp
helpviewer_keywords:
- __declspec keyword [C++], uuid
- uuid __declspec keyword
ms.assetid: 9d004621-09bc-4a8d-871b-648f5d5102d7
ms.openlocfilehash: f775820fe7f84c5081a213ca9ecb07d617716a9d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226978"
---
# <a name="uuid-c"></a>uuid (C++)

**Específico da Microsoft**

O compilador anexa um GUID a uma classe ou estrutura declarada ou definida (somente definições de objeto COM completas) com o **`uuid`** atributo.

## <a name="syntax"></a>Sintaxe

```
__declspec( uuid("ComObjectGUID") ) declarator
```

## <a name="remarks"></a>Comentários

O **`uuid`** atributo usa uma cadeia de caracteres como seu argumento. Essa cadeia de caracteres nomeia um GUID no formato normal do registro com ou sem os delimitadores **{}** . Por exemplo:

```cpp
struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IUnknown;
struct __declspec(uuid("{00020400-0000-0000-c000-000000000046}")) IDispatch;
```

Esse atributo poderá ser aplicado a uma redeclaração. Isso permite que os cabeçalhos do sistema forneçam as definições de interfaces, como `IUnknown` , e a redeclaração em algum outro cabeçalho (como \<comdef.h> ) para fornecer o GUID.

A palavra-chave [__uuidof](../cpp/uuidof-operator.md) pode ser aplicada para recuperar o GUID de constante anexado a um tipo definido pelo usuário.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)

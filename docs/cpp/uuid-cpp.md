---
title: uuid (C++)
ms.date: 11/04/2016
f1_keywords:
- uuid_cpp
helpviewer_keywords:
- __declspec keyword [C++], uuid
- uuid __declspec keyword
ms.assetid: 9d004621-09bc-4a8d-871b-648f5d5102d7
ms.openlocfilehash: 09e40d38382bea0f902fda03d15d24e0cf1a627d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187798"
---
# <a name="uuid-c"></a>uuid (C++)

**Seção específica da Microsoft**

O compilador anexa um GUID a uma classe ou estrutura declarada ou definida (somente definições de objeto COM completas) com o atributo **UUID** .

## <a name="syntax"></a>Sintaxe

```
__declspec( uuid("ComObjectGUID") ) declarator
```

## <a name="remarks"></a>Comentários

O atributo **UUID** usa uma cadeia de caracteres como seu argumento. Essa cadeia de caracteres nomeia um GUID no formato normal do registro com ou sem os delimitadores **{}** . Por exemplo:

```cpp
struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IUnknown;
struct __declspec(uuid("{00020400-0000-0000-c000-000000000046}")) IDispatch;
```

Esse atributo poderá ser aplicado a uma redeclaração. Isso permite que os cabeçalhos do sistema forneçam as definições de interfaces, como `IUnknown`, e a redeclaração em algum outro cabeçalho (como \<comdef. h >) para fornecer o GUID.

A palavra-chave [__uuidof](../cpp/uuidof-operator.md) pode ser aplicada para recuperar o GUID de constante anexado a um tipo definido pelo usuário.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)

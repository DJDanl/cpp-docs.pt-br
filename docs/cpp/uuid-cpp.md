---
title: UUID (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- uuid_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], uuid
- uuid __declspec keyword
ms.assetid: 9d004621-09bc-4a8d-871b-648f5d5102d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 44799b507fb9c27cb1d9f166e86228ed6003a0d8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46086181"
---
# <a name="uuid-c"></a>uuid (C++)

**Seção específica da Microsoft**

O compilador anexa o GUID a uma classe ou estrutura declarada ou definida (completo COM definições de objeto apenas) com o **uuid** atributo.

## <a name="syntax"></a>Sintaxe

```
__declspec( uuid("ComObjectGUID") ) declarator
```

## <a name="remarks"></a>Comentários

O **uuid** atributo utiliza uma cadeia de caracteres como seu argumento. Essa cadeia de caracteres nomeia um GUID no formato normal do registro com ou sem o **{}** delimitadores. Por exemplo:

```cpp
struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IUnknown;
struct __declspec(uuid("{00020400-0000-0000-c000-000000000046}")) IDispatch;
```

Esse atributo poderá ser aplicado a uma redeclaração. Isso permite que os cabeçalhos do sistema fornecer as definições das interfaces, como `IUnknown`e a redeclaração em algum outro cabeçalho (como \<comdef >) para fornecer o GUID.

A palavra-chave [uuidof](../cpp/uuidof-operator.md) podem ser aplicados para recuperar o GUID da constante anexado a um tipo definido pelo usuário.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
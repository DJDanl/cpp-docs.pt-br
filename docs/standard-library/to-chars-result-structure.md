---
title: to_chars_result struct
ms.date: 07/22/2020
f1_keywords:
- charconv/std::to_chars_result
helpviewer_keywords:
- to_chars_result class
- to_chars_result structure
ms.openlocfilehash: a840b8d030f0ed0d2a4afcc57e1bef1161c76ff3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212055"
---
# <a name="to_chars_result-struct"></a>to_chars_result struct

## <a name="syntax"></a>Sintaxe

```cpp
struct to_chars_result {
    char* ptr;
    errc ec;
};
```

## <a name="members"></a>Membros

|Membro|Descrição|
|--|--|
|`ptr`| Se `ec` for igual a `errc{}` , a conversão foi bem-sucedida e `ptr` é o ponteiro de uma extremidade passada dos caracteres gravados. Caso contrário, `ptr` tem o valor do `to_chars()` parâmetro `last` e o conteúdo do intervalo \[ primeiro, último) não é especificado.|
|`ec` | O código de erro de conversão. Para obter códigos de erro específicos, consulte [`errc`](system-error-enums.md#errc) .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<charconv>

**Namespace:** std

**Opção de compilador:** /std: c++ 17 ou posterior, é necessário

## <a name="see-also"></a>Confira também

[to_chars](charconv-functions.md#to_chars)
---
title: Struct to_chars_result
ms.date: 07/22/2020
f1_keywords:
- charconv/std::to_chars_result
helpviewer_keywords:
- to_chars_result class
- to_chars_result structure
ms.openlocfilehash: 4e46d1cc9d0b6a02d731ad25c2e85c99300d7234
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509651"
---
# <a name="to_chars_result-struct"></a>Struct to_chars_result

## <a name="syntax"></a>Sintaxe

```cpp
struct to_chars_result {
    char* ptr;
    errc ec;
};
```

## <a name="members"></a>Membros

|Membro|DESCRIÇÃO|
|--|--|
|`ptr`| Se `ec` for igual a `errc{}` , a conversão foi bem-sucedida e `ptr` é o ponteiro de uma extremidade passada dos caracteres gravados. Caso contrário, `ptr` tem o valor do `to_chars()` parâmetro `last` e o conteúdo do intervalo \[ primeiro, último) não é especificado.|
|`ec` | O código de erro de conversão. Para obter códigos de erro específicos, consulte [`errc`](system-error-enums.md#errc) .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<charconv>

**Namespace:** std

**Opção de compilador:** /std: c++ 17 ou posterior, é necessário

## <a name="see-also"></a>Consulte também

[to_chars](charconv-functions.md#to_chars)

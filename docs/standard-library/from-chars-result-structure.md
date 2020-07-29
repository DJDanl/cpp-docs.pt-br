---
title: from_chars_result struct
ms.date: 7/23/2020
f1_keywords:
- std::from_chars_result
helpviewer_keywords:
- from_chars_result class
- from_chars_result structure
ms.openlocfilehash: 5a5dcfe6e5b59644e6ebf55d68ce43975e7d3c9d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215758"
---
# <a name="from_chars_result-struct"></a>from_chars_result struct

## <a name="syntax"></a>Sintaxe

```cpp
struct from_chars_result {
    const char* ptr;
    errc ec;
};
```

|Membro|Descrição|
|--|--|
|`ptr`| Se `ec` for igual a `errc{}` , a conversão foi bem-sucedida e `ptr` aponta para o primeiro caractere que não faz parte do número reconhecido. |
|`ec` | O código de erro de conversão. Para obter códigos de erro específicos, consulte [`errc`](system-error-enums.md#errc) .|

### <a name="remarks"></a>Comentários

Um exemplo: a análise `"1729cats"` como um inteiro decimal terá sucesso e `ptr` apontará para `'c'` qual é o primeiro não dígito e também é um ponto de extremidade `"1729"` .

Se nenhum caractere corresponder a um padrão numérico, `from_chars_result.ptr` apontar para `first` e `from_chars_result.ec` for `errc::invalid_argument` .

Se apenas alguns caracteres corresponderem a um padrão numérico, `from_chars_result.ptr` o apontará para o primeiro caractere que não corresponde ao padrão ou terá o valor do `last` parâmetro se todos os caracteres forem correspondentes.

Se o valor analisado não couber no intervalo para o tipo de conversão que está sendo feito, `from_chars_result.ec` será `errc::result_out_of_range` .

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<charconv>

**Namespace:** std

**Opção de compilador:** /std: c++ 17 ou posterior, é necessário

## <a name="see-also"></a>Confira também

[from_chars](charconv-functions.md#from_chars)

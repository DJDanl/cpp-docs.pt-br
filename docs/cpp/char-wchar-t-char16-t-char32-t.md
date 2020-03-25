---
title: char, wchar_t, char16_t, char32_t
ms.date: 02/14/2018
ms.assetid: 6b33e9f5-455b-4e49-8f12-a150cbfe2e5b
ms.openlocfilehash: 8d109ec452df33b774848229837ed3e2eae80dc4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181012"
---
# <a name="char-wchar_t-char16_t-char32_t"></a>char, wchar_t, char16_t, char32_t

Os tipos **Char**, **wchar_t**, **char16_t** e **char32_t** são tipos internos que representam caracteres alfanuméricos, bem como glifos não alfanuméricos e caracteres não imprimíveis.

## <a name="syntax"></a>Sintaxe

```cpp
char     ch1{ 'a' };  // or { u8'a' }
wchar_t  ch2{ L'a' };
char16_t ch3{ u'a' };
char32_t ch4{ U'a' };
```

## <a name="remarks"></a>Comentários

O tipo **Char** era o tipo de caractere original em C C++e. O tipo de **caractere não assinado** geralmente é usado para representar um *byte*, que não é um tipo interno no C++. O tipo **Char** pode ser usado para armazenar caracteres do conjunto de caracteres ASCII ou de qualquer um dos conjuntos de caracteres ISO-8859, e bytes individuais de caracteres de byte múltiplo, como Shift-JIS ou a codificação UTF-8 do conjunto de caracteres Unicode. As cadeias de caracteres do tipo **Char** são chamadas de cadeias de caracteres *estreitas* , mesmo quando usadas para codificar personagens de byte múltiplo. No compilador Microsoft, **Char** é um tipo de 8 bits.

O tipo de **wchar_t** é um tipo de caractere largo definido pela implementação. No compilador da Microsoft, ele representa um caractere largo de 16 bits usado para armazenar o Unicode codificado como UTF-16LE, o tipo de caractere nativo em sistemas operacionais Windows. As versões de caracteres largos das funções de biblioteca do universal C Runtime (UCRT) usam **wchar_t** e seus tipos de ponteiro e de matriz como parâmetros e valores de retorno, assim como as versões de caracteres largos da API nativa do Windows.

Os tipos **char16_t** e **char32_t** representam caracteres de 16 bits e 32 bits de largura, respectivamente. O Unicode codificado como UTF-16 pode ser armazenado no tipo de **char16_t** , e o Unicode codificado como utf-32 pode ser armazenado no tipo de **char32_t** . Cadeias desses tipos e **wchar_t** são conhecidas como cadeias de caracteres *grandes* , embora o termo geralmente se refira especificamente a cadeias de caracteres do tipo **wchar_t** .

Na biblioteca C++ padrão, o tipo de `basic_string` é especializado para cadeias de caracteres estreitas e largas. Use `std::string` quando os caracteres são do tipo **Char**, `std::u16string` quando os caracteres são do tipo **char16_t**, `std::u32string` quando os caracteres são do tipo **char32_t**e `std::wstring` quando os caracteres são do tipo **wchar_t**. Outros tipos que representam texto, incluindo `std::stringstream` e `std::cout` têm especializações para cadeias de caracteres estreitas e largos.

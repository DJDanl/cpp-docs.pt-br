---
title: char, wchar_t, char16_t, char32_t
ms.date: 02/14/2018
ms.assetid: 6b33e9f5-455b-4e49-8f12-a150cbfe2e5b
ms.openlocfilehash: 6efbae1b8f6155410b823f1abef35c3dec90d458
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232333"
---
# <a name="char-wchar_t-char16_t-char32_t"></a>char, wchar_t, char16_t, char32_t

Os tipos **`char`** , **`wchar_t`** **`char16_t`** e **`char32_t`** são tipos internos que representam caracteres alfanuméricos, bem como glifos não alfanuméricos e caracteres não imprimíveis.

## <a name="syntax"></a>Sintaxe

```cpp
char     ch1{ 'a' };  // or { u8'a' }
wchar_t  ch2{ L'a' };
char16_t ch3{ u'a' };
char32_t ch4{ U'a' };
```

## <a name="remarks"></a>Comentários

O **`char`** tipo era o tipo de caractere original em C e C++. O tipo **`unsigned char`** é geralmente usado para representar um *byte*, que não é um tipo interno em C++. O **`char`** tipo pode ser usado para armazenar caracteres do conjunto de caracteres ASCII ou de qualquer um dos conjuntos de caracteres ISO-8859 e bytes individuais de caracteres de byte múltiplo, como Shift-JIS ou a codificação UTF-8 do conjunto de caracteres Unicode. As cadeias de caracteres do **`char`** tipo são chamadas de cadeias *restritas* , mesmo quando usadas para codificar os personagens com vários bytes. No compilador Microsoft, **`char`** é um tipo de 8 bits.

O **`wchar_t`** tipo é um tipo de caractere largo definido pela implementação. No compilador da Microsoft, ele representa um caractere largo de 16 bits usado para armazenar o Unicode codificado como UTF-16LE, o tipo de caractere nativo em sistemas operacionais Windows. As versões de caracteres largos das funções de biblioteca de tempo de execução universal C (UCRT) usam **`wchar_t`** e seus tipos de ponteiro e de matriz como parâmetros e valores de retorno, assim como as versões de caracteres largos da API nativa do Windows.

Os **`char16_t`** **`char32_t`** tipos e representam caracteres largos de 16 e 32 bits, respectivamente. O Unicode codificado como UTF-16 pode ser armazenado no **`char16_t`** tipo, e o Unicode codificado como UTF-32 pode ser armazenado no **`char32_t`** tipo. Cadeias desses tipos e **`wchar_t`** são todas conhecidas como cadeias de caracteres *largos* , embora o termo geralmente se refira especificamente a cadeias de caracteres do **`wchar_t`** tipo.

Na biblioteca C++ Standard, o `basic_string` tipo é especializado para cadeias de caracteres estreitas e largas. Use `std::string` quando os caracteres forem do tipo **`char`** , `std::u16string` quando os caracteres forem do tipo **`char16_t`** , `std::u32string` quando os caracteres forem do tipo **`char32_t`** e `std::wstring` quando os caracteres forem do tipo **`wchar_t`** . Outros tipos que representam texto, incluindo `std::stringstream` e `std::cout` têm especializações para cadeias de caracteres estreitas e largos.

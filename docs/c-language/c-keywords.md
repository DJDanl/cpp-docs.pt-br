---
title: Palavras-chave C
description: Palavras-chave nas extensões de compilador C e Microsoft C padrão.
ms.date: 10/15/2020
helpviewer_keywords:
- keywords [C]
- redefining keywords
- Microsoft-specific keywords
ms.assetid: 2d932335-97bf-45cd-b367-4ae00db0ff42
ms.openlocfilehash: 24981c8d70cb56b4578fd905a30ccc57eaa83d45
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176226"
---
# <a name="c-keywords"></a>Palavras-chave C

*Palavras-chave* são palavras que têm um significado especial para o compilador do C. Nas fases de conversão 7 e 8, um identificador não pode ter a mesma grafia e caso como uma palavra-chave C. Para obter mais informações, consulte [fases de tradução](../preprocessor/phases-of-translation.md) na referência do *pré-processador*. Para obter mais informações sobre identificadores, consulte [identificadores](../c-language/c-identifiers.md).

## <a name="standard-c-keywords"></a>Palavras-chave C padrão

A linguagem C usa as seguintes palavras-chave:

:::row:::
    :::column:::
        **`auto`**\
        **`break`**\
        **`case`**\
        **`char`**\
        **`const`**\
        **`continue`**\
        **`default`**\
        **`do`**\
        **`double`**\
        **`else`**\
        **`enum`**
    :::column-end:::
    :::column:::
        **`extern`**\
        **`float`**\
        **`for`**\
        **`goto`**\
        **`if`**\
        **`inline`**<sup>1, um</sup>\
        **`int`**\
        **`long`**\
        **`register`**\
        **`restrict`**<sup>1, um</sup>\
        **`return`**
    :::column-end:::
    :::column:::
        **`short`**\
        **`signed`**\
        **`sizeof`**\
        **`static`**\
        **`struct`**\
        **`switch`**\
        **`typedef`**\
        **`union`**\
        **`unsigned`**\
        **`void`**\
        **`volatile`**
    :::column-end:::
    :::column:::
        **`while`**\
        **`_Alignas`**<sup>2, um</sup>\
        **`_Alignof`**<sup>2, um</sup>\
        **`_Atomic`**<sup>2, b</sup>\
        **`_Bool`**<sup>1, um</sup>\
        **`_Complex`**<sup>1, b</sup>\
        **`_Generic`**<sup>2, um</sup>\
        **`_Imaginary`**<sup>1, b</sup>\
        **`_Noreturn`**<sup>2, um</sup>\
        **`_Static_assert`**<sup>2, um</sup>\
        **`_Thread_local`**<sup>2, b</sup>
    :::column-end:::
:::row-end:::

<sup>1</sup>  palavras-chave introduzidas no C99 ISO.

<sup>2</sup>   palavras-chave introduzidas no C11 ISO.

<sup>a</sup>  partir do Visual Studio 2019 versão 16,8, essas palavras-chave têm suporte no código compilado como C quando as **`/std:c11`** **`/std:c17`** Opções de compilador ou são especificadas.

<sup>b</sup>  a partir do Visual Studio 2019 versão 16,8, essas palavras-chave são reconhecidas, mas não têm suporte do compilador no código compilado como C quando as **`/std:c11`** **`/std:c17`** Opções do compilador ou são especificadas.

Você não pode redefinir palavras-chave. No entanto, você pode especificar o texto para substituir palavras-chave antes da compilação usando as [diretivas](../preprocessor/preprocessor-directives.md)de pré-processador C.

## <a name="microsoft-specific-c-keywords"></a>Palavras-chave C específicas da Microsoft

Os padrões ANSI e ISO C permitem que identificadores com dois sublinhados à esquerda sejam reservados para implementações de compilador. A Convenção da Microsoft é preceder nomes de palavras-chave específicos da Microsoft com sublinhados duplos. Essas palavras não podem ser usadas como nomes de identificador. Para obter uma descrição das regras para identificadores de nomenclatura, incluindo o uso de sublinhados duplos, consulte [identificadores](../c-language/c-identifiers.md).

As palavras-chave e os identificadores especiais a seguir são reconhecidos pelo compilador Microsoft C:

:::row:::
    :::column:::
        **`__asm`**<sup>05</sup>\
        **`dllimport`**<sup>quatro</sup>\
        **`__int8`**<sup>05</sup>\
        **`naked`**<sup>quatro</sup>\
        **`__based`**<sup>3, 5</sup>
    :::column-end:::
    :::column:::
        **`__except`**<sup>05</sup>\
        **`__int16`**<sup>05</sup>\
        **`__stdcall`**<sup>05</sup>\
        **`__cdecl`**<sup>05</sup>\
        **`__fastcall`**
    :::column-end:::
    :::column:::
        **`__int32`**<sup>05</sup>\
        **`thread`**<sup>quatro</sup>\
        **`__declspec`**<sup>05</sup>\
        **`__finally`**<sup>05</sup>\
        **`__int64`**<sup>05</sup>
    :::column-end:::
    :::column:::
        **`__try`**<sup>05</sup>\
        **`dllexport`**<sup>quatro</sup>\
        **`__inline`**<sup>05</sup>\
        **`__leave`**<sup>05</sup>\
        **`static_assert`**<sup>152</sup>
    :::column-end:::
:::row-end:::

<sup>3</sup> a **`__based`** palavra-chave tem usos limitados para compilações de destino de 32 bits e 64 bits.

<sup>4</sup> esses são os identificadores especiais quando usados com **`__declspec`** o; seu uso em outros contextos é irrestrito.

<sup>5</sup> para compatibilidade com versões anteriores, essas palavras-chave estão disponíveis com dois sublinhados à esquerda e um único sublinhado à esquerda quando as extensões da Microsoft estão habilitadas.

<sup>6</sup> se você não incluir <Assert. h>, o compilador do Microsoft Visual C **`static_assert`** será mapeado para a **`_Static_assert`** palavra-chave C11.

As extensões da Microsoft são ativadas por padrão. Para auxiliar na criação de código portátil, você pode desabilitar extensões da Microsoft especificando a opção [/za \( Disable Language Extensions)](../build/reference/za-ze-disable-language-extensions.md) durante a compilação. Quando você usa essa opção, algumas palavras-chave específicas da Microsoft são desabilitadas.

Quando as extensões do Microsoft são habilitadas, você pode usar as palavras-chave listadas acima em seus programas. Para conformidade com os padrões, a maioria dessas palavras-chave é precedida por um duplo sublinhado. As quatro exceções,,, **`dllexport`** **`dllimport`** **`naked`** e **`thread`** , são usadas apenas com **`__declspec`** e não exigem um sublinhado duplo à esquerda. Para compatibilidade com versões anteriores, há suporte para as versões de sublinhado único do restante das palavras-chave.

## <a name="see-also"></a>Confira também

[Elementos de C](../c-language/elements-of-c.md)

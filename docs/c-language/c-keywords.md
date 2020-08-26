---
title: Palavras-chave C
ms.date: 10/09/2018
helpviewer_keywords:
- keywords [C]
- redefining keywords
- Microsoft-specific keywords
ms.assetid: 2d932335-97bf-45cd-b367-4ae00db0ff42
ms.openlocfilehash: 1b49da349a6552022dfd9e8e66e85634f4694645
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838770"
---
# <a name="c-keywords"></a>Palavras-chave C

“Palavras-chave” são palavras que têm um significado especial para o compilador C. Nas fases 7 e 8 da conversão, um identificador não pode ter a mesma ortografia e caixa (maiúscula/minúscula) que a palavra-chave C. (Consulte uma descrição das [fases de tradução](../preprocessor/phases-of-translation.md) na *referência do pré-processador*; para obter informações sobre identificadores, consulte [identificadores](../c-language/c-identifiers.md).) A linguagem C usa as seguintes palavras-chave:

:::row:::
    :::column:::
        **`auto`**\
        **`double`**\
        **`int`**\
        **`struct`**\
        **`break`**\
        **`else`**\
        **`long`**\
        **`switch`**
    :::column-end:::
    :::column:::
        **`case`**\
        **`enum`**\
        **`register`**\
        **`typedef`**\
        **`char`**\
        **`extern`**\
        **`return`**\
        **`union`**
    :::column-end:::
    :::column:::
        **`const`**\
        **`float`**\
        **`short`**\
        **`unsigned`**\
        **`continue`**\
        **`for`**\
        **`signed`**\
        **`void`**
    :::column-end:::
    :::column:::
        **`default`**\
        **`goto`**\
        **`sizeof`**\
        **`volatile`**\
        **`do`**\
        **`if`**\
        **`static`**\
        **`while`**
    :::column-end:::
:::row-end:::

Você não pode redefinir palavras-chave. No entanto, você pode especificar o texto a ser substituído por palavras-chave antes da compilação usando [diretivas de pré-processador](../preprocessor/preprocessor-directives.md) C.

**Específico da Microsoft**

O padrão ANSI C permite que os identificadores com dois sublinhados iniciais sejam reservados para implementações de compilador. Portanto, a convenção da Microsoft é preceder nomes de palavras-chave específicas da Microsoft com sublinhados duplos. Essas palavras não podem ser usadas como nomes de identificadores. Para obter uma descrição das regras ANSI para nomear identificadores, inclusive o uso de sublinhados duplos, consulte [Identificadores](../c-language/c-identifiers.md).

As palavras-chave e os identificadores especiais a seguir são reconhecidos pelo compilador Microsoft C:

:::row:::
    :::column:::
        **`__asm`**<sup>Beta</sup>\
        **`dllimport`**<sup>2</sup>\
        **`__int8`**<sup>Beta</sup>\
        **`naked`**<sup>2</sup>\
        **`__based`**<sup>1, 3</sup>
    :::column-end:::
    :::column:::
        **`__except`**<sup>Beta</sup>\
        **`__int16`**<sup>Beta</sup>\
        **`__stdcall`**<sup>Beta</sup>\
        **`__cdecl`**<sup>Beta</sup>\
        **`__fastcall`**
    :::column-end:::
    :::column:::
        **`__int32`**<sup>Beta</sup>\
        **`thread`**<sup>2</sup>\
        **`__declspec`**<sup>Beta</sup>\
        **`__finally`**<sup>Beta</sup>\
        **`__int64`**<sup>Beta</sup>
    :::column-end:::
    :::column:::
        **`__try`**<sup>Beta</sup>\
        **`dllexport`**<sup>2</sup>\
        **`__inline`**<sup>Beta</sup>\
        **`__leave`**<sup>Beta</sup>
    :::column-end:::
:::row-end:::

<sup>1</sup> a **`__based`** palavra-chave tem usos limitados para compilações de destino de 32 bits e 64 bits.

<sup>2</sup> esses são identificadores especiais quando usados com **`__declspec`** o; seu uso em outros contextos não é restrito.

<sup>3</sup> Para compatibilidade com versões anteriores, essas palavras-chave estão disponíveis com dois sublinhados à esquerda e um único sublinhado à esquerda quando as extensões da Microsoft estão habilitadas.

As extensões da Microsoft são ativadas por padrão. Para garantir que seus programas sejam totalmente portáteis, você poderá desabilitar as extensões da Microsoft especificando a opção [/Za \(Desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) durante a compilação. Ao fazer isso, algumas palavras-chave específicas da Microsoft são desabilitadas.

Quando as extensões do Microsoft são habilitadas, você pode usar as palavras-chave listadas acima em seus programas. Para estar em conformidade com o ANSI, a maioria dessas palavras-chave são precedidas por um sublinhado duplo. As quatro exceções, **`dllexport`** , **`dllimport`** , **`naked`** e **`thread`** , são usadas apenas com **`__declspec`** e, portanto, não exigem um sublinhado duplo à esquerda. Para compatibilidade com versões anteriores, há suporte para as versões de sublinhado único do restante das palavras-chave.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Elementos de C](../c-language/elements-of-c.md)

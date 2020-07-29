---
title: Palavras-chave C
ms.date: 10/09/2018
helpviewer_keywords:
- keywords [C]
- redefining keywords
- Microsoft-specific keywords
ms.assetid: 2d932335-97bf-45cd-b367-4ae00db0ff42
ms.openlocfilehash: 081235f987d3f6f8dbfd3abb4af9d70688b7fd98
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87200706"
---
# <a name="c-keywords"></a>Palavras-chave C

“Palavras-chave” são palavras que têm um significado especial para o compilador C. Nas fases 7 e 8 da conversão, um identificador não pode ter a mesma ortografia e caixa (maiúscula/minúscula) que a palavra-chave C. (Consulte uma descrição das [fases de tradução](../preprocessor/phases-of-translation.md) na *referência do pré-processador*; para obter informações sobre identificadores, consulte [identificadores](../c-language/c-identifiers.md).) A linguagem C usa as seguintes palavras-chave:

:::row:::
    :::column:::
        **`auto`**<br/>
        **`double`**<br/>
        **`int`**<br/>
        **`struct`**<br/>
        **`break`**<br/>
        **`else`**<br/>
        **`long`**<br/>
        **`switch`**<br/>
    :::column-end:::
    :::column:::
        **`case`**<br/>
        **`enum`**<br/>
        **`register`**<br/>
        **`typedef`**<br/>
        **`char`**<br/>
        **`extern`**<br/>
        **`return`**<br/>
        **`union`**<br/>
    :::column-end:::
    :::column:::
        **`const`**<br/>
        **`float`**<br/>
        **`short`**<br/>
        **`unsigned`**<br/>
        **`continue`**<br/>
        **`for`**<br/>
        **`signed`**<br/>
        **`void`**<br/>
    :::column-end:::
    :::column:::
        **`default`**<br/>
        **`goto`**<br/>
        **`sizeof`**<br/>
        **`volatile`**<br/>
        **`do`**<br/>
        **`if`**<br/>
        **`static`**<br/>
        **`while`**<br/>
    :::column-end:::
:::row-end:::

Você não pode redefinir palavras-chave. No entanto, você pode especificar o texto a ser substituído por palavras-chave antes da compilação usando [diretivas de pré-processador](../preprocessor/preprocessor-directives.md) C.

**Específico da Microsoft**

O padrão ANSI C permite que os identificadores com dois sublinhados iniciais sejam reservados para implementações de compilador. Portanto, a convenção da Microsoft é preceder nomes de palavras-chave específicas da Microsoft com sublinhados duplos. Essas palavras não podem ser usadas como nomes de identificadores. Para obter uma descrição das regras ANSI para nomear identificadores, inclusive o uso de sublinhados duplos, consulte [Identificadores](../c-language/c-identifiers.md).

As palavras-chave e os identificadores especiais a seguir são reconhecidos pelo compilador Microsoft C:

:::row:::
    :::column:::
        **`__asm`**<sup>Beta</sup><br/>
        **`dllimport`**<sup>2</sup><br/>
        **`__int8`**<sup>Beta</sup><br/>
        **`naked`**<sup>2</sup><br/>
        **`__based`**<sup>1, 3</sup><br/>
    :::column-end:::
    :::column:::
        **`__except`**<sup>Beta</sup><br/>
        **`__int16`**<sup>Beta</sup><br/>
        **`__stdcall`**<sup>Beta</sup><br/>
        **`__cdecl`**<sup>Beta</sup><br/>
        **`__fastcall`**<br/>
    :::column-end:::
    :::column:::
        **`__int32`**<sup>Beta</sup><br/>
        **`thread`**<sup>2</sup><br/>
        **`__declspec`**<sup>Beta</sup><br/>
        **`__finally`**<sup>Beta</sup><br/>
        **`__int64`**<sup>Beta</sup><br/>
    :::column-end:::
    :::column:::
        **`__try`**<sup>Beta</sup><br/>
        **`dllexport`**<sup>2</sup><br/>
        **`__inline`**<sup>Beta</sup><br/>
        **`__leave`**<sup>Beta</sup><br/>
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

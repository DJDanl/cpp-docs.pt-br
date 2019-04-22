---
title: setlocale
ms.date: 11/04/2016
f1_keywords:
- setlocale_CPP
- vc-pragma.setlocale
helpviewer_keywords:
- pragmas, setlocale
- setlocale pragma
ms.assetid: e60b43d9-fbdf-4c4e-ac85-805523a13b86
ms.openlocfilehash: b2f28a14b4d4585575a39dd9a936a56a84eeddc4
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59022419"
---
# <a name="setlocale"></a>setlocale

Define a localidade (país/região e idioma) que será usada na tradução de literais de cadeia de caracteres e constantes de caracteres amplos.

## <a name="syntax"></a>Sintaxe

```
#pragma setlocale( "[locale-string]" )
```

## <a name="remarks"></a>Comentários

Como o algoritmo para converter caracteres multibyte para caracteres amplos pode variar de acordo com a localidade ou a compilação pode ocorrer em uma localidade diferente de onde um arquivo executável será executado, esse pragma fornece uma maneira de especificar a localidade de destino no momento da compilação. Isso garante que as cadeias de caracteres amplos sejam armazenadas no formato correto.

O padrão *cadeia de caracteres de localidade* é "".

A localidade "C" mapeia cada caractere na cadeia de caracteres para seu valor como um **wchar_t** (curto sem sinal). Outros valores válidos para `setlocale` são as entradas que se encontram em de [cadeias de caracteres de idioma](../c-runtime-library/language-strings.md) lista. Por exemplo, você pode emitir:

```cpp
#pragma setlocale("dutch")
```

A capacidade de emitir uma cadeia de caracteres de idioma depende da página de código e do suporte à ID de idioma no seu computador.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
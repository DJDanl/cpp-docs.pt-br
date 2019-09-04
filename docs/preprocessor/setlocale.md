---
title: Pragma setlocale
ms.date: 08/29/2019
f1_keywords:
- setlocale_CPP
- vc-pragma.setlocale
helpviewer_keywords:
- pragmas, setlocale
- setlocale pragma
ms.assetid: e60b43d9-fbdf-4c4e-ac85-805523a13b86
ms.openlocfilehash: 219354595e5c63b2f13211d43bfa517d97413251
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218170"
---
# <a name="setlocale-pragma"></a>Pragma setlocale

Define a *localidade*, o país, a região e o idioma a ser usado ao converter constantes de caractere largo e literais de cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

> **#pragma setlocalize ("** [ *locale-String* ] **")**

## <a name="remarks"></a>Comentários

Como o algoritmo para converter caracteres multibyte em caracteres largos pode variar por localidade, ou a compilação pode ocorrer em uma localidade diferente de onde um arquivo executável será executado, esse pragma fornece uma maneira de especificar a localidade de destino no momento da compilação. Ele garante que cadeias de caracteres largos sejam armazenadas no formato correto.

A *cadeia de caracteres de localidade* padrão é "".

A localidade "C" mapeia cada caractere na cadeia de caracteres para seu valor como um **wchar_t**. Outros valores válidos para `setlocale` o são as entradas encontradas na lista de cadeias de [caracteres de idioma](../c-runtime-library/language-strings.md) . Por exemplo, você pode especificar:

```cpp
#pragma setlocale("dutch")
```

A capacidade de especificar uma cadeia de caracteres de idioma depende da página de código e do suporte à ID de idioma no seu computador.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)

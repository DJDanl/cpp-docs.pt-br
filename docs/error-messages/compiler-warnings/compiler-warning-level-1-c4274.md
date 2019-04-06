---
title: Compilador aviso (nível 1) C4274
ms.date: 11/04/2016
f1_keywords:
- C4274
helpviewer_keywords:
- C4274
ms.assetid: 5a948680-7ed1-469f-978d-ae99d154e161
ms.openlocfilehash: f73fa8e09baab127e7755ebe3def69c2fb585744
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59028450"
---
# <a name="compiler-warning-level-1-c4274"></a>Compilador aviso (nível 1) C4274

\#ident ignored; see documentation for #pragma comment(exestr, 'string')

O `#ident` diretiva, que insere uma cadeia de caracteres especificada pelo usuário no objeto ou arquivo executável, foi preterida. Consequentemente, o compilador ignora a diretiva.

> [!CAUTION]
>  Aviso C4274 aconselham a usar o [#pragma comment (exestr, 'string')](../../preprocessor/comment-c-cpp.md) diretiva. No entanto, esse conselho é preterido e será revisado em uma versão futura do compilador. Se você usar o `#pragma` diretiva, a ferramenta do vinculador (LINK.exe) ignora o produzido pela diretiva de registro de comentário e emite o aviso [LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md). Em vez da `#ident` diretiva, é recomendável que você use uma cadeia de caracteres do recurso de versão do arquivo em seu aplicativo.

## <a name="to-correct-this-error"></a>Para corrigir este erro

- Remover o `#ident "` *cadeia de caracteres* `"` diretiva.

## <a name="see-also"></a>Consulte também

[comment (C/C++)](../../preprocessor/comment-c-cpp.md)<br/>
[Aviso LNK4229 (Ferramentas de Vinculador)](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)<br/>
[Trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md)
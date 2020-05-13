---
title: Aviso do compilador (nível 1) C4274
ms.date: 11/04/2016
f1_keywords:
- C4274
helpviewer_keywords:
- C4274
ms.assetid: 5a948680-7ed1-469f-978d-ae99d154e161
ms.openlocfilehash: 5d005fccc5920aea61698a65edf9284d56366a1d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377073"
---
# <a name="compiler-warning-level-1-c4274"></a>Aviso do compilador (nível 1) C4274

\#ident ignorado; consulte a documentação para #pragma comentário (exestr, 'string')

A `#ident` diretiva, que insere uma seqüência de string especificada pelo usuário no objeto ou no arquivo executável, é preterida. Consequentemente, o compilador ignora a diretiva.

> [!CAUTION]
> Aviso C4274 aconselha que você use a diretiva [#pragma comment (exestr, 'string').](../../preprocessor/comment-c-cpp.md) No entanto, este conselho é preterido e será revisado em uma futura versão do compilador. Se você `#pragma` usar a diretiva, a ferramenta linker (LINK.exe) ignorará o registro de comentários produzido pela diretiva e emite o aviso [LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md). Em vez `#ident` da diretiva, recomendamos que você use uma seqüência de recursos da versão do arquivo em seu aplicativo.

## <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova `#ident "`a diretiva de *seqüência.* `"`

## <a name="see-also"></a>Confira também

[comment (C/C++)](../../preprocessor/comment-c-cpp.md)<br/>
[Ferramentas de linker aviso LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)<br/>
[Trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md)

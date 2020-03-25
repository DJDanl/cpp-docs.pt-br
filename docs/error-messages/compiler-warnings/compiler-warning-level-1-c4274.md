---
title: Aviso do compilador (nível 1) C4274
ms.date: 11/04/2016
f1_keywords:
- C4274
helpviewer_keywords:
- C4274
ms.assetid: 5a948680-7ed1-469f-978d-ae99d154e161
ms.openlocfilehash: 5f2350f275f883e7bf18aa1621d08b34132e8dfb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175840"
---
# <a name="compiler-warning-level-1-c4274"></a>Aviso do compilador (nível 1) C4274

ident \#ignorado; consulte a documentação para #pragma comentário (exestr, ' String ')

A diretiva `#ident`, que insere uma cadeia de caracteres especificada pelo usuário no objeto ou arquivo executável, é preterida. Consequentemente, o compilador ignora a diretiva.

> [!CAUTION]
>  Aviso C4274 aconselha você a usar a diretiva de [Comentário de #pragma (exestr, ' String ')](../../preprocessor/comment-c-cpp.md) . No entanto, esse Conselho foi preterido e será revisado em uma versão futura do compilador. Se você usar a diretiva `#pragma`, a ferramenta de vinculador (LINK. exe) ignorará o registro de comentário produzido pela diretiva e emitirá o aviso [LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md). Em vez da diretiva `#ident`, recomendamos que você use uma cadeia de caracteres de recurso de versão de arquivo em seu aplicativo.

## <a name="to-correct-this-error"></a>Para corrigir esse erro

- Remova a diretiva de`"` de `#ident "`*cadeia de caracteres* .

## <a name="see-also"></a>Confira também

[comment (C/C++)](../../preprocessor/comment-c-cpp.md)<br/>
[Aviso das ferramentas de vinculador LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)<br/>
[Trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md)

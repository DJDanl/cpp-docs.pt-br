---
title: Aviso LNK4070 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4070
helpviewer_keywords:
- LNK4070
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
ms.openlocfilehash: 391a477625b51fd37eacc5d455801ce90d2abbc2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193999"
---
# <a name="linker-tools-warning-lnk4070"></a>Aviso LNK4070 (Ferramentas de Vinculador)

/OUT: diretiva de nome de arquivo em. EXP difere do nome de arquivo de saída ' FileName '; ignorando diretiva

O `filename` especificado na instrução [Name](../../build/reference/name-c-cpp.md) ou [library](../../build/reference/library.md) quando o arquivo. exp foi criado difere do `filename` de saída que foi assumido por padrão ou especificado com a opção [/out](../../build/reference/out-output-file-name.md) .

Você verá esse aviso se alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo. def do projeto não foi atualizado. Atualize manualmente o arquivo. def para resolver este aviso.

Um programa cliente que usa a DLL resultante pode ter problemas.

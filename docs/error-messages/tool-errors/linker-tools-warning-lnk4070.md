---
title: Aviso LNK4070 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4070
helpviewer_keywords:
- LNK4070
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
ms.openlocfilehash: e7139b21f053ea8633356c7194cd719a6a4aef35
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622970"
---
# <a name="linker-tools-warning-lnk4070"></a>Aviso LNK4070 (Ferramentas de Vinculador)

/Out: filename diretiva em. EXP difere do nome de arquivo de saída 'filename'; Ignorando diretiva

O `filename` especificado na [nome](../../build/reference/name-c-cpp.md) ou [biblioteca](../../build/reference/library.md) difere de instrução quando o arquivo. EXP foi criado a partir da saída `filename` que foi considerado por padrão ou especificado com o [/Out](../../build/reference/out-output-file-name.md) opção.

Você verá este aviso se você alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo. def do projeto não foi atualizado. Atualize manualmente o arquivo. def para resolver este aviso.

Um programa cliente que usa a DLL resultante poderá ter problemas.
---
title: Ferramentas de vinculador LNK4070 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4070
dev_langs:
- C++
helpviewer_keywords:
- LNK4070
ms.assetid: f95f179a-fff9-427e-bd51-466b3934517f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9cfb4ae1c5440742c491d9615a2b4929a9b04f66
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106920"
---
# <a name="linker-tools-warning-lnk4070"></a>Aviso LNK4070 (Ferramentas de Vinculador)

/Out: filename diretiva em. EXP difere do nome de arquivo de saída 'filename'; Ignorando diretiva

O `filename` especificado na [nome](../../build/reference/name-c-cpp.md) ou [biblioteca](../../build/reference/library.md) difere de instrução quando o arquivo. EXP foi criado a partir da saída `filename` que foi considerado por padrão ou especificado com o [/Out](../../build/reference/out-output-file-name.md) opção.

Você verá este aviso se você alterar o nome de um arquivo de saída no ambiente de desenvolvimento e onde o arquivo. def do projeto não foi atualizado. Atualize manualmente o arquivo. def para resolver este aviso.

Um programa cliente que usa a DLL resultante poderá ter problemas.
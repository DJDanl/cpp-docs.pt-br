---
title: NMAKE Erro Fatal U1056 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1056
dev_langs:
- C++
helpviewer_keywords:
- U1056
ms.assetid: da855728-b69e-413c-83ed-df912126215e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e0a83c62bedf995708d5e99fee19f05696d05c2d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46065682"
---
# <a name="nmake-fatal-error-u1056"></a>Erro fatal U1056 (NMAKE)

não é possível encontrar o processador de comando

O processador de comando não estava no caminho especificado na **COMSPEC** ou **caminho** variáveis de ambiente.

NMAKE usa COMMAND.COM ou CMD. EXE como um processador de comando ao executar comandos. Ele procura o processador de comando pela primeira vez em que o caminho definido **COMSPEC**. Se **COMSPEC** não existir, pesquisas NMAKE os diretórios especificados na **caminho**.
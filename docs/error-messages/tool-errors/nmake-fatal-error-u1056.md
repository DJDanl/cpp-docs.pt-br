---
title: Erro fatal U1056 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1056
helpviewer_keywords:
- U1056
ms.assetid: da855728-b69e-413c-83ed-df912126215e
ms.openlocfilehash: b15b14c04dd91ae648ea4311612c122f04f90477
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50635923"
---
# <a name="nmake-fatal-error-u1056"></a>Erro fatal U1056 (NMAKE)

não é possível encontrar o processador de comando

O processador de comando não estava no caminho especificado na **COMSPEC** ou **caminho** variáveis de ambiente.

NMAKE usa COMMAND.COM ou CMD. EXE como um processador de comando ao executar comandos. Ele procura o processador de comando pela primeira vez em que o caminho definido **COMSPEC**. Se **COMSPEC** não existir, pesquisas NMAKE os diretórios especificados na **caminho**.
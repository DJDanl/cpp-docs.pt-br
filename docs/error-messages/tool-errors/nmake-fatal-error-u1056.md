---
title: Erro fatal U1056 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1056
helpviewer_keywords:
- U1056
ms.assetid: da855728-b69e-413c-83ed-df912126215e
ms.openlocfilehash: 10131e518fa608292fff58672ede36390bcd665b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182897"
---
# <a name="nmake-fatal-error-u1056"></a>Erro fatal U1056 (NMAKE)

Não é possível encontrar processador de comando

O processador de comando não estava no caminho especificado nas variáveis de ambiente **COMSPEC** ou **Path** .

NMAKE usa COMMAND.COM ou CMD. EXE como um processador de comando ao executar comandos. Ele procura o processador de comando primeiro no caminho definido em **COMSPEC**. Se o **COMSPEC** não existir, o NMAKE pesquisará os diretórios especificados em **Path**.

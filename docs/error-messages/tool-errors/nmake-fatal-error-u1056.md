---
title: NMAKE Erro Fatal U1056 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1056
dev_langs:
- C++
helpviewer_keywords:
- U1056
ms.assetid: da855728-b69e-413c-83ed-df912126215e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 41db646e2559051c11de5265900dde8ad0a03214
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1056"></a>Erro fatal U1056 (NMAKE)
não é possível encontrar o processador de comando  
  
 O processador de comandos não estava no caminho especificado no **COMSPEC** ou **caminho** variáveis de ambiente.  
  
 NMAKE usa COMMAND.COM ou CMD. EXE como um processador de comando ao executar comandos. Ele procura o processador de comando primeiro no caminho definido **COMSPEC**. Se **COMSPEC** não existir, pesquisas NMAKE os diretórios especificados em **caminho**.
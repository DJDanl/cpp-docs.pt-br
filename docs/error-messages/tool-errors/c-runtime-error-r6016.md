---
title: R6016 de erro de tempo de execução C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6016
dev_langs:
- C++
helpviewer_keywords:
- R6016
ms.assetid: 7bd3f274-d9c4-4bc4-8252-80bf168c4c3a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f366ceff24ce65e6f7869f9709f547651687c327
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33306928"
---
# <a name="c-runtime-error-r6016"></a>R6016 de erro de tempo de execução do C
não há espaço suficiente para dados do thread  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória muito baixa, um bug no aplicativo, ou por um bug em um suplemento ou extensão usada pelo aplicativo.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o aplicativo.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover, repare ou reinstale o add-ins ou extensões usadas pelo aplicativo.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro ocorre porque o programa não recebeu memória insuficiente do sistema operacional para concluir uma [beginthread](../../c-runtime-library/reference/beginthread-beginthreadex.md) ou `_beginthreadex` chamada ou thread armazenamento local não foi inicializado por `_beginthread` ou `_beginthreadex`.  
  
 Quando um thread novo é iniciado, a biblioteca deve criar um banco de dados interno para o thread. Se o banco de dados não pode ser expandido usando memória fornecida pelo sistema operacional, ele não inicia e o processo de chamada para. Isso pode acontecer quando muitos threads foram criados pelo processo, ou se o armazenamento de thread local se esgotou.  
  
 É recomendável que um executável que chama a biblioteca de tempo de execução do C (CRT) deve usar `_beginthreadex` para criação de thread em vez da API do Windows `CreateThread`. `_beginthreadex` inicializa o armazenamento estático interno usado por muitas funções CRT no armazenamento de thread local. Se você usar `CreateThread` para criar um thread, o CRT pode finalizar o processo com R6016 quando for feita uma chamada para uma função CRT que exija o armazenamento estático interno inicializado.
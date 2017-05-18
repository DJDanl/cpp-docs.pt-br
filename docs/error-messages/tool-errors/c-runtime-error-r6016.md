---
title: "R6016 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6016
dev_langs:
- C++
helpviewer_keywords:
- R6016
ms.assetid: 7bd3f274-d9c4-4bc4-8252-80bf168c4c3a
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9db3505f2012fe576c41b486e644dc204e418e3f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6016"></a>R6016 de erro de tempo de execução do C
não há espaço suficiente para dados do thread  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, um bug no aplicativo, ou por um bug em um suplemento ou extensão usada pelo aplicativo.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o aplicativo.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para remover, reparar ou reinstalar o add-ins ou extensões usadas pelo aplicativo.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre porque o programa não recebeu memória suficiente do sistema operacional para concluir uma [beginthread](../../c-runtime-library/reference/beginthread-beginthreadex.md) ou `_beginthreadex` chamada ou thread armazenamento local não foi inicializado por `_beginthread` ou `_beginthreadex`.  
  
 Quando um thread novo é iniciado, a biblioteca deve criar um banco de dados interno para o thread. Se o banco de dados não pode ser expandido usando memória fornecida pelo sistema operacional, ele não inicia e o processo de chamada para. Isso pode acontecer quando muitos threads foram criados pelo processo, ou se o armazenamento de thread local se esgotou.  
  
 Recomendamos que use um executável que chama a biblioteca de tempo de execução do C (CRT) `_beginthreadex` para criação do thread em vez da API do Windows `CreateThread`. `_beginthreadex` inicializa o armazenamento estático interno usado por muitas funções CRT no armazenamento de thread local. Se você usar `CreateThread` para criar um thread, o CRT pode finalizar o processo com R6016 quando for feita uma chamada para uma função CRT que exija o armazenamento estático interno inicializado.

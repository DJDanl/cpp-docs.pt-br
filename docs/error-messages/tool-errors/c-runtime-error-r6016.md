---
title: "R6016 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "R6016"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6016"
ms.assetid: 7bd3f274-d9c4-4bc4-8252-80bf168c4c3a
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6016 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não há espaço suficiente para dados de thread  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, um bug no aplicativo, ou por um bug em um suplemento ou extensão usada pelo aplicativo.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o aplicativo.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para remover, reparar ou reinstalar o add\-ins ou extensões usadas pelo aplicativo.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre porque o programa não recebeu memória suficiente do sistema operacional para concluir um [beginthread](../Topic/_beginthread,%20_beginthreadex.md) ou `_beginthreadex` chamada ou thread armazenamento local não foi inicializado por `_beginthread` ou `_beginthreadex`.  
  
 Quando um novo thread é iniciado, a biblioteca deve criar um banco de dados interno para o thread. Se o banco de dados não pode ser expandido usando memória fornecida pelo sistema operacional, o thread não começa e pára o processo de chamada. Isso pode acontecer quando muitos threads foram criados pelo processo, ou se o armazenamento local de thread tiver se esgotado.  
  
 Recomendamos que use um executável que chama a biblioteca de tempo de execução do C \(CRT\) `_beginthreadex` para criação do thread em vez da API do Windows `CreateThread`.`_beginthreadex` inicializa o armazenamento estático interno usado por muitas funções CRT no armazenamento local de thread. Se você usar `CreateThread` para criar um thread, o CRT pode finalizar o processo com R6016 quando é feita uma chamada para uma função CRT que requer armazenamento estático interno inicializado.
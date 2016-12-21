---
title: "R6018 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6018"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6018"
ms.assetid: f6dd40d1-a119-4d8b-b39e-97350ea23349
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6018 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Erro inesperado de heap  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por um defeito no código do aplicativo.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 O programa encontrou um erro inesperado ao executar uma operação de gerenciamento de memória.  
  
 Esse erro geralmente ocorre se o programa inadvertidamente altera os dados da pilha de tempo de execução. No entanto, ele também pode ser causado por um erro interno no tempo de execução ou código do sistema operacional.  
  
 Para corrigir esse problema, procure bugs de corrupção de heap no seu código. Para obter mais informações e exemplos, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md). Em seguida, verifique se estão usando os redistribuíveis mais recentes para sua implantação do aplicativo. Para obter mais informações, veja [Implantação no Visual C\+\+](../../ide/deployment-in-visual-cpp.md).
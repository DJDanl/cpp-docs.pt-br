---
title: "R6026 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6026"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6026"
ms.assetid: 7ea751f8-fc20-46ab-99ef-84c95ca0b6b4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6026 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não há espaço suficiente para inicialização stdio  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa. Ele também pode ser causado por um bug no aplicativo, por danos das bibliotecas do Visual C\+\+ usa ou por um driver.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para remover o novo aplicativo ou driver e tente novamente o seu aplicativo.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C\+\+ redistribuível.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre quando não há memória livre suficiente disponível para inicializar o suporte de e\/s padrão em tempo de execução C. Esse erro normalmente ocorre durante a inicialização do aplicativo. Verifique se o seu aplicativo e os drivers e dlls que carrega não corromper a pilha na inicialização.
---
title: "R6032 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6032"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6032"
ms.assetid: 52092a63-cc51-444a-bfc3-fad965a3558e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6032 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não há espaço suficiente para obter informações de localidade  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa ou por um bug no programa.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 O tempo de execução mantém informações sobre a localidade em cada thread para que ele possa processar chamadas a funções sensíveis à localidade. Se a alocação de memória para obter essa informação falhar, o tempo de execução é impossível prosseguir porque muitos de seus recursos básicos dependem dele.
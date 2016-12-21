---
title: "R6024 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6024"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6024"
ms.assetid: 0fb11c0f-9b81-4cab-81bd-4785742946a5
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6024 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não há espaço suficiente para a tabela OnExit\/atexit  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Esse erro geralmente é causado por uma condição de memória extremamente baixa, ou raramente, por um bug no programa ou por danos das bibliotecas do Visual C\+\+ que ele usa.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C\+\+ redistribuível.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre porque não havia nenhuma memória disponível para o `_onexit` ou `atexit` função. Esse erro é causado por uma condição de memória insuficiente. Você pode considerar pré\-alocação de buffers na inicialização do aplicativo para ajudar a salvar os dados do usuário e executar um aplicativo limpo sair em condições de pouca memória.
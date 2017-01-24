---
title: "R6028 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6028"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6028"
ms.assetid: 81e99079-4388-4244-a4f7-4641c508871c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6028 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não foi possível inicializar o heap  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, um bug no programa, ou os drivers de hardware com defeito.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para remover o novo aplicativo ou driver e tente novamente o seu aplicativo.  
> -   Verifique o site do fornecedor do hardware ou **Windows Update** no **Painel de controle** atualizações de software e driver.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre quando o sistema operacional falha ao criar o pool de memória para o aplicativo. Especificamente, o C Runtime \(CRT\) chamou a função do Win32 `HeapCreate`, que retornou NULL indicando uma falha.  
  
 Se esse erro ocorrer durante a inicialização do aplicativo, o sistema poderá não atender a solicitações do heap porque drivers defeituosos são carregados. Verifique o Windows Update ou o site do seu fornecedor de hardware para obter drivers atualizados.
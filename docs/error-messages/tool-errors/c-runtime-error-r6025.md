---
title: "R6025 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6025"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6025"
ms.assetid: afa06d98-9c36-445b-b3e7-b6409bc8e779
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6025 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

chamada de função virtual pura  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. O motivo mais comum para esse erro é um bug no aplicativo ou uma instalação corrompida.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Nenhum objeto instanciado para lidar com a chamada de função virtual pura.  
  
 Esse erro é causado por chamar uma função virtual em uma classe base abstrata através de um ponteiro que é criado por uma conversão para o tipo da classe derivada, mas é, na verdade, um ponteiro para a classe base. Isso pode ocorrer quando a conversão de um **void \*** em um ponteiro para uma classe quando o **void \*** foi criado durante a construção da classe base.  
  
 Para obter mais informações, consulte o [suporte da Microsoft](http://go.microsoft.com/fwlink/?LinkId=75220) site.
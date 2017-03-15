---
title: "Fun&#231;&#227;o exit | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "Exit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função exit"
ms.assetid: 26ce439f-81e2-431c-9ff8-a09a96f32127
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o exit
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A função **exit**, declarada no arquivo de inclusão padrão STDLIB.H, encerra um programa C\+\+.  
  
 O valor fornecido como argumento para **exit** é retornado para o sistema operacional como o código de retorno ou o código de saída do programa.  Por convenção, um código de retorno de zero indica que o programa foi encerrado com êxito.  
  
> [!NOTE]
>  Você pode usar as constantes `EXIT_FAILURE` e `EXIT_SUCCESS`, definidas em STDLIB.H, para indicar o êxito ou a falha do programa.  
  
 Emitir uma instrução `return` da função **main** é equivalente à chamada da função **exit** com o valor de retorno como seu argumento.  
  
 Para obter mais informações, consulte [exit](../c-runtime-library/reference/exit-exit-exit.md) na *Referência da biblioteca em tempo de execução*.  
  
## Consulte também  
 [Término do programa](../Topic/Program%20Termination.md)
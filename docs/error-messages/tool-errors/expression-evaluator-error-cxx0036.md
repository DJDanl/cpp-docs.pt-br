---
title: "Erro CXX0036 (avaliador de express&#227;o) | Microsoft Docs"
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
  - "CXX0036"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CAN0036"
  - "CXX0036"
ms.assetid: 383404be-df5b-4eec-b113-df21bb5d269d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro CXX0036 (avaliador de express&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

contexto incorreto {…} especificação  
  
 Essa mensagem pode ser gerada por alguns dos vários erros no uso do operador de contexto \(**{}**\).  
  
-   A sintaxe do operador de contexto \(**{}**\) foi especificada incorretamente.  
  
     A sintaxe do operador de contexto é:  
  
     {*função*,*módulo*,*dlls*}*expressão*  
  
     Isso especifica o contexto *de expressão*.  O operador de contexto tem a mesma prioridade e uso de que uma conversão de tipos.  
  
     As vírgulas à direita podem ser omitidos.  Se algum da *função*, do *módulo*, ou *da DLL* contém uma vírgula literal, coloque o nome inteiro entre parênteses.  
  
-   O nome da função foi escrito incorretamente, ou não existe na biblioteca especificada do módulo ou de vínculo dinâmico\) nativa.  
  
     2.0 Porque C é uma linguagem com diferenciação de maiúsculas e minúsculas, *a função* deve ser fornecida em caso exato conforme definida na origem.  
  
-   O módulo ou a DLL não poderiam ser encontradas.  
  
     Verifique o nome de caminho completo do módulo ou da DLL especificado.  
  
 Esse erro é idêntico a CAN0036.
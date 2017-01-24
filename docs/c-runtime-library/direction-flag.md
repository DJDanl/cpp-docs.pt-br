---
title: "Sinalizador de dire&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.flags"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "sinalizador de direção"
ms.assetid: 0836b4af-dbbb-4ab8-a4b2-156f2e2099e2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sinalizador de dire&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O sinalizador de direção é um específico do sinalizador de CPU para processadores Intel 80x86.  Se aplica a todas as instruções do assembly que usam o prefixo do representante \(repetir\-se\), como MOV, MOVSD, MOVSW, e outros.  Os endereços fornecidos para as instruções aplicáveis são gerados se o sinalizador de direção estiver desmarcada.  
  
 As rotinas de tempo de execução C presumem que o sinalizador de direção será limpo.  Se você estiver usando outras funções com as funções de tempo de execução C, você deve assegurar que as outras funções saam do sinalizador de direção sozinho ou o para restaurar a sua condição original.  Aguardar o sinalizador de direção estar claro na entrada faz o código em tempo de execução mais rápida e eficiente.  
  
 Funções da biblioteca de tempo de execução C, como a cadeia de caracteres\- manipulação e as rotinas de buffer\- manipulação, esperam o sinalizador de direção ser apagado.  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
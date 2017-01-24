---
title: "_except_handler3 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_except_handler3"
apilocation: 
  - "msvcrt.dll"
  - "msvcr90.dll"
  - "msvcr80.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
  - "msvcr110.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_except_handler3"
  - "except_handler3"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _except_handler3"
  - "Função except_handler3"
ms.assetid: b0c64898-0ae5-48b7-9724-80135a0813e2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _except_handler3
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Função CRT interna.  Usada por uma estrutura para encontrar o manipulador de exceção apropriado para processar a exceção atual.  
  
## Sintaxe  
  
```  
int _except_handler3(    PEXCEPTION_RECORD exception_record,    PEXCEPTION_REGISTRATION registration,    PCONTEXT context,    PEXCEPTION_REGISTRATION dispatcher );  
```  
  
#### Parâmetros  
 \[in\] `exception_record`  
 Informações sobre a exceção específica.  
  
 \[in\] `registration`  
 O registro que indica qual tabela de escopo deve ser usada para encontrar o manipulador de exceção.  
  
 \[in\] `context`  
 Reservado.  
  
 \[in\] `dispatcher`  
 Reservado.  
  
## Valor de retorno  
 Caso uma exceção deva ser desconsiderada, retorna `DISPOSITION_DISMISS`.  Caso a exceção deva ser passada um nível acima para os manipuladores de exceção de encapsulamento, retorna `DISPOSITION_CONTINUE_SEARCH`.  
  
## Comentários  
 Caso encontre um manipulador de exceção apropriado, o método passa a exceção para o manipulador.  Nessa situação, esse método não retorna ao código que o chamou e o valor retornado é irrelevante.  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)
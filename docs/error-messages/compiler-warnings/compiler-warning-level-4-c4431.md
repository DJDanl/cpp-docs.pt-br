---
title: "Aviso do compilador (n&#237;vel 4) C4431 | Microsoft Docs"
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
  - "C4431"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4431"
ms.assetid: 58434ab6-dd8d-427b-953a-602fb7453ae6
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4431
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

especificador ausente do tipo int \- assumido.Observação: 2.0 C não oferece suporte ao int  
  
 Esse erro pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: Visual C\+\+ não cria sem identificadores como tipo int por padrão.  O tipo de um identificador deve ser especificado explicitamente.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para maiores informações.  
  
## Exemplo  
 O exemplo a seguir produz C4431.  
  
```  
// C4431.c  
// compile with: /c /W4  
#pragma warning(default:4431)  
i;   // C4431  
int i;   // OK  
```
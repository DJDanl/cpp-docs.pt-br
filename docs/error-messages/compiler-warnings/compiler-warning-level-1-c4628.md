---
title: "Aviso do compilador (n&#237;vel 1) C4628 | Microsoft Docs"
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
  - "C4628"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4628"
ms.assetid: 20fdc6f8-5f6a-40cc-aff8-c7ccf3d8ec26
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4628
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

dígrafos sem suporte com \- o Ze.Sequência “dígrafo” de caracteres não interpretado como token alternativo para o “exemplo”  
  
 Os dígrafos não têm suporte em [\/Ze](../../build/reference/za-ze-disable-language-extensions.md).  Esse aviso é seguido por um erro.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
 O seguinte exemplo gera C4628:  
  
```  
// C4628.cpp  
// compile with: /WX  
#pragma warning(default : 4628)  
int main()  
<%   // C4628 <% digraph for {  
}  
```
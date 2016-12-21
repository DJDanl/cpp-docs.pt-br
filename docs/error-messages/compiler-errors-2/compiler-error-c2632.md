---
title: "Erro do Compilador C2632 | Microsoft Docs"
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
  - "C2632"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2632"
ms.assetid: b15a6b1b-42d2-4e1b-8660-e6bfde61052d
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2632
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o tipo “\- 1 " seguido do tipo “\- 2 " é ilegal  
  
 Esse erro pode ser causado se estiver faltando um código entre dois especificadores do tipo.  
  
 O seguinte exemplo gera C2632:  
  
```  
// C2632.cpp  
int float i;   // C2632  
```  
  
 Esse erro também pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual Studio .NET 2003.  `bool` é agora um tipo apropriado.  Em versões anteriores, era um `bool` typedef, e você pode criar identificadores com esse nome.  
  
 O seguinte exemplo gera C2632:  
  
```  
// C2632_2.cpp  
// compile with: /LD  
void f(int bool);   // C2632  
```  
  
 Para resolver este erro de modo que o código seja válido em versões do Visual Studio .NET. 2003 e do Visual Studio .NET do Visual C\+\+, renomeie o identificador.
---
title: "Erro do Compilador C2449 | Microsoft Docs"
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
  - "C2449"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2449"
ms.assetid: 544bf0b6-daa0-40e8-9f21-8e583d472a2d
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2449
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

encontrado “{” no escopo do arquivo \(cabeçalho de falta de função?\)  
  
 Uma chave aberta ocorre no escopo do arquivo.  
  
 Esse erro pode ser causado por um ponto\-e\-vírgula entre um cabeçalho da função e a chave de abertura da definição de função.  
  
 O seguinte exemplo gera C2499:  
  
```  
// C2449.c  
// compile with: /c  
void __stdcall func(void) {}   // OK  
void __stdcall func(void);  // extra semicolon on this line  
{                         // C2449 detected here  
```
---
title: "Erro do Compilador C2447 | Microsoft Docs"
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
  - "C2447"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2447"
ms.assetid: d1bd6e9a-ee42-4510-ae5e-6b0378f7b931
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2447
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“{”: cabeçalho de função ausente \(lista formal antiga?\)  
  
 O compilador encontrou uma chave de abertura inesperada no escopo global.  Na maioria dos casos, isso é causado por um cabeçalho malformado, uma declaração posicionada incorretamente ou por um ponto\-e\-vírgula disperso.  Para resolver esse problema, verifique se a chave de abertura segue um cabeçalho de função formado corretamente e não é precedida de uma declaração ou um ponto\-e\-vírgula disperso.  
  
 Esse erro também pode ser causado por uma lista de argumentos formais em linguagem C antiga.  Para resolver esse problema, refatore a lista de argumentos para usar um estilo moderno, ou seja, incluído entre parênteses.  
  
 O seguinte exemplo gera C2447:  
  
```  
// C2447.cpp  
int c;  
{}       // C2447  
```
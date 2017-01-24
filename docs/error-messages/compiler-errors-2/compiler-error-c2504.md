---
title: "Erro do Compilador C2504 | Microsoft Docs"
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
  - "C2504"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2504"
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2504
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: classe base indeterminada  
  
 A classe base é declarada mas nunca definida.  Causas possíveis:  
  
1.  Perder inclui o arquivo.  
  
2.  Classe base externo não declarada com [extern](../../cpp/using-extern-to-specify-linkage.md).  
  
 O seguinte exemplo gera C2504:  
  
```  
// C2504.cpp  
// compile with: /c  
class A;  
class B : public A {};   // C2504  
```  
  
 \/\/OK  
  
```  
class C{};  
class D : public C {};  
```
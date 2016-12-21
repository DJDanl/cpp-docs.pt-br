---
title: "Compiler Error C3209 | Microsoft Docs"
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
  - "C3209"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3209"
ms.assetid: 1de44e39-69d1-4894-8f89-ff92136e8e5d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compiler Error C3209
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'class': classe genérica deve ser gerenciada ou classe do WinRT  
  
 Uma classe genérica deve ser uma classe gerenciada ou uma classe de tempo de execução do Windows.  
  
 O exemplo a seguir gera C3209 e mostra como corrigi\-lo:  
  
```  
// C3209.cpp  
// compile with: /clr  
generic <class T>  
class C {};   // C3209  
  
// OK - ref class can be generic  
generic <class T>  
ref class D {};  
```
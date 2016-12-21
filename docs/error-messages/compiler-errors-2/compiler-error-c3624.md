---
title: "Erro do Compilador C3624 | Microsoft Docs"
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
  - "C3624"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3624"
ms.assetid: eaac6a4f-eb11-4e4d-ab12-124ba995c5cf
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3624
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: o uso desse tipo requer uma referência ao assembly assembly  
  
 Um assembly \(referência\) necessárias de compilar seu código não tiver sido especificada; passe o assembly a política de [\#using](../../preprocessor/hash-using-directive-cpp.md) .  
  
 O seguinte exemplo gera C3624:  
  
```  
// C3624.cpp  
// compile with: /clr /c  
#using <System.Windows.Forms.dll>  
  
// Uncomment the following 2 lines to resolve.  
// #using <System.dll>  
// #using <System.Drawing.dll>  
  
using namespace System;  
  
public ref class MyForm : public Windows::Forms::Form {};   // C3624  
```  
  
 O seguinte exemplo gera C3624:  
  
```  
// C3624_b.cpp  
// compile with: /clr:oldSyntax /c  
#using <System.Windows.Forms.dll>  
  
// Uncomment the following 2 lines to resolve.  
// #using <System.dll>  
// #using <System.Drawing.dll>  
  
using namespace System;  
  
public __gc class MyForm : public Windows::Forms::Form {};   // C3624  
```
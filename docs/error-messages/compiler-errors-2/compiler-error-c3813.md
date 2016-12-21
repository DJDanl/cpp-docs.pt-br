---
title: "Erro do Compilador C3813 | Microsoft Docs"
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
  - "C3813"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3813"
ms.assetid: ffdbc489-71bf-4cd6-988c-f824c9ab3ceb
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3813
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

uma declaração de propriedade só pode aparecer dentro da definição de um gerenciado ou tipo WinRT  
  
 Um [propriedade](../../misc/property.md) só pode ser declarada dentro de um gerenciado ou tempo de execução do Windows tipo.  Não oferecem suporte a tipos nativos do `property` palavra\-chave.  
  
 O exemplo a seguir gera C3813 e mostra como corrigi\-lo:  
  
```  
// C3813.cpp  
// compile by using: cl /c /clr C3813.cpp  
class A  
{  
   property int Int; // C3813  
};  
  
ref class B  
{  
   property int Int; // OK - declared within managed type  
};  
```
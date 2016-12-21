---
title: "Erro do Compilador C2951 | Microsoft Docs"
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
  - "C2951"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2951"
ms.assetid: c6f95aa2-c894-425b-a51c-d40d70c8daa1
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2951
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

as declarações de tipo são permitidas apenas no GAC, no namespace, ou no escopo da classe  
  
 Você não pode declarar uma parte externa ou do modelo genérico da classe global ou um escopo do namespace.  Se você executa seu genérico ou declarações de modelo incluir arquivos, certifique\-se de que o arquivo incluir está no escopo global.  
  
 O seguinte exemplo gera C2951:  
  
```  
// C2951.cpp  
template <class T>  
class A {};  
  
int main() {  
   template <class T>   // C2951  
   class B {};  
}  
```  
  
 C2951 também pode ocorrer ao usar produtos genéricas:  
  
```  
// C2951b.cpp  
// compile with: /clr /c  
  
// OK  
generic <class T>   
ref class GC { };  
  
int main() {  
   generic <class T> ref class GC2 {};   // C2951  
}  
```
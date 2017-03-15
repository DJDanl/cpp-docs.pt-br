---
title: "Convers&#245;es padr&#227;o e convers&#227;o boxing impl&#237;cita | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "boxing, implícito"
ms.assetid: 33f7fc7d-5674-44a2-a859-0e6a04fae519
caps.latest.revision: 6
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es padr&#227;o e convers&#227;o boxing impl&#237;cita
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma conversão padrão será escolhida pelo compilador sobre uma conversão que requer o com.  
  
## Exemplo  
  
```  
// clr_implicit_boxing_Std_conversion.cpp  
// compile with: /clr  
int f3(int ^ i) {   // requires boxing  
   return 1;  
}  
  
int f3(char c) {   // no boxing required, standard conversion  
   return 2;  
}  
  
int main() {  
   int i = 5;  
   System::Console::WriteLine(f3(i));  
}  
```  
  
 **2**   
## Consulte também  
 [Boxing](../windows/boxing-cpp-component-extensions.md)
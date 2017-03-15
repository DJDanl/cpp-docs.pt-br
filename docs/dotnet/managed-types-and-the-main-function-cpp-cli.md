---
title: "Tipos gerenciados e a fun&#231;&#227;o principal (C++/CLI) | Microsoft Docs"
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
  - "Função main, em aplicativos gerenciados"
  - "código gerenciado, função main()"
ms.assetid: 9d0e9620-58c4-4dac-a0e1-ffeb95f80fa5
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos gerenciados e a fun&#231;&#227;o principal (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao escrever um aplicativo usando **\/clr**, os argumentos da função de **main\(\)** não podem ser de um tipo gerenciado.  
  
 Um exemplo de uma assinatura é apropriada:  
  
```  
// managed_types_and_main.cpp  
// compile with: /clr  
int main(int, char*[], char*[]) {}  
```  
  
## Consulte também  
 [Tipos gerenciados](../Topic/Managed%20Types%20\(C++-CLI\).md)
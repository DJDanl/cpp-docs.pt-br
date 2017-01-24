---
title: "Aviso do compilador (n&#237;vel 1) C4269 | Microsoft Docs"
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
  - "C4269"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4269"
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4269
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: os dados automática “const” inicializados com o construtor padrão gerado por compilador gerenciem resultados não confiável  
  
 Uma instância automática de **const** de uma classe não trivial é inicializada com um construtor padrão completo gerado.  
  
## Exemplo  
  
```  
// C4269.cpp  
// compile with: /c /LD /W1  
class X {  
public:  
   int m_data;  
};  
  
void g() {  
   const X x1;   // C4269  
};  
```  
  
 Considerando que essa instância da classe é gerada na pilha, o valor inicial de `m_data` pode ser qualquer coisa.  Além disso, desde que é uma instância de **const** , o valor de `m_data` nunca pode ser alterado.
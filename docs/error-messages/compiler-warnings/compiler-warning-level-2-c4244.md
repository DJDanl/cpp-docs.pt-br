---
title: "Aviso do compilador (n&#237;vel 2) C4244 | Microsoft Docs"
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
  - "C4244"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4244"
ms.assetid: 2c19d157-21d1-42c2-a6c0-3f30f2ce3813
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4244
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“argumento”: conversão do tipo “\- 1 " para o tipo “\- 2 ", possível perda de dados  
  
 Um tipo de ponto flutuante foi convertido em um tipo inteiro.  Uma possível perda de dados pode ter ocorrido.  
  
 Se você obtiver C4244, você deve alterar seu programa para usar tipos compatíveis, ou adicionar qualquer lógica em seu código, para assegurar que o intervalo de valores possíveis sempre é compatível com os tipos que você está usando.  
  
 C4244 também pode ser acionado no nível 3, e 4; consulte [Aviso do compilador \(níveis 3 e 4\) C4244](../Topic/Compiler%20Warning%20\(levels%203%20and%204\)%20C4244.md) para obter mais informações.  
  
## Exemplo  
 O seguinte exemplo gera C4244:  
  
```  
// C4244_level2.cpp  
// compile with: /W2  
  
int f(int x){ return 0; }  
int main() {  
   double x = 10.1;  
   int i = 10;  
   return (f(x));   // C4244  
   // try the following line instead  
   // return (f(i));  
}  
```
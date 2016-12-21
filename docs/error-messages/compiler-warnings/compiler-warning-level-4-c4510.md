---
title: "Aviso do compilador (n&#237;vel 4) C4510 | Microsoft Docs"
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
  - "C4510"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4510"
ms.assetid: fd28d1d4-ad27-4dad-94c0-9dba46c93180
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4510
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: o construtor padrão não pôde ser gerado  
  
 O compilador não pode gerar um construtor padrão para a classe especificada e nenhum construtor definido pelo usuário foi criado.  Você não poderá criar objetos desse tipo.  
  
 Há várias situações que impedem o compilador gerencia um construtor padrão, incluindo:  
  
-   Um membro de dados de const.  
  
-   Um membro de dados que é uma referência.  
  
 Você precisa criar um construtor padrão definida pelo usuário para a classe que inicializa esses membros.  
  
 O seguinte exemplo gera C4510:  
  
```  
// C4510.cpp  
// compile with: /W4  
struct A {  
   const int i;  
   int &j;  
   A& operator=( const A& ); // C4510 expected  
   // uncomment the following line to resolve this C4510  
   // A(int ii, int &jj) : i(ii), j(jj) {}  
};   // C4510  
  
int main() {  
}  
```
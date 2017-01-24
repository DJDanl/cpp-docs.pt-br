---
title: "Erro das Ferramentas de Vinculador LNK2020 | Microsoft Docs"
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
  - "LNK2020"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2020"
ms.assetid: 4dd017d0-5e83-471b-ac8a-538ac1ed6870
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2020
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“token de token não resolvido”  
  
 Semelhante a um erro externo indefinido, exceto que a referência é através de metadados.  Nos metadados, todas as funções e dados devem ser definidos.  
  
 Para resolver:  
  
-   Define a função ou os dados ausentes, ou  
  
-   Inclua o arquivo ou a biblioteca de objeto em que a função ou os dados ausentes já estejam definidos.  
  
## Exemplo  
 O exemplo a seguir produz LNK2020.  
  
```  
// LNK2020.cpp  
// compile with: /clr /LD  
ref struct A {  
   A(int x);   // LNK2020  
   static int f();   // LNK2020  
};  
  
// OK  
ref struct B {  
   B(int x) {}  
   static int f() { return 0; }  
};  
```  
  
## Exemplo  
 LNK2020 também ocorrerá se você criar uma variável de tipo gerenciado do modelo, mas também não cria uma instância do tipo.  
  
 O exemplo a seguir produz LNK2020.  
  
```  
// LNK2020_b.cpp  
// compile with: /clr   
  
template <typename T>  
ref struct Base {  
   virtual void f1() {};  
};  
  
template <typename T>  
ref struct Base2 {  
   virtual void f1() {};  
};  
  
int main() {  
   Base<int>^ p;   // LNK2020  
   Base2<int>^ p2 = gcnew Base2<int>();   // OK  
};  
```
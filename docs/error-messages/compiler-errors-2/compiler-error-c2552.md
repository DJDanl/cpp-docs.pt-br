---
title: C2552 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2552
dev_langs:
- C++
helpviewer_keywords:
- C2552
ms.assetid: 0e0ab759-788a-4faf-9337-80d4b9e2e8c9
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0e001837ca3d9ea9e5c5db1770188d030e21d7d9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2552"></a>C2552 de erro do compilador
"identificador": não agregados não podem ser inicializados com a lista de inicializadores  
  
 O identificador agregado foi inicializado incorretamente.  
  
 [Agregações](../../c-language/initializing-aggregate-types.md) são definidos como:  
  
-   Matrizes  
  
-   Classes, estruturas e uniões sem:  
  
    -   Construtores  
  
    -   Membros particulares ou protegidos  
  
    -   Classes base  
  
    -   Funções virtuais  
  
 Além disso, o Visual C++ não permite tipos de dados em uma agregação que contenha construtores.  
  
 A seguir encontram-se os motivos que podem fazer com que o C2552 seja acionado quando houver uma tentativa de fazer uma inicialização de agregação em um tipo:  
  
-   O tipo tem um ou vários construtores definidos pelo usuário.  
  
-   O tipo tem um ou mais membros de dados particulares, não estáticos.  
  
-   O tipo tem uma ou mais funções virtuais.  
  
-   O tipo tem uma classe base.  
  
-   O tipo é uma classe ref ou interface CLR.  
  
-   O tipo tem uma matriz de dimensão não fixa (matriz zero) cujos elementos têm destruidores.  
  
 O seguinte exemplo gera C2552:  
  
```  
// C2552.cpp  
// compile with: /clr  
#include <string>  
using namespace std;  
  
struct Pair_Incorrect {  
private:  
   string m_name;  
   double m_val;  
};  
  
struct Pair_Correct1 {  
public:  
   Pair_Correct1(string name, double val)  
      : m_name(name), m_val(val) {}  
  
private:  
   string m_name;  
   double m_val;  
};  
  
struct Pair_Correct2 {  
public:  
   string m_name;  
   double m_val;  
};  
  
int main() {  
   // To fix, add a constructor to this class and use it for   
   // initializing the data members, see Pair_Correct1 (below)  
   // or  
   // Do not have any private or protected non-static data members,   
   // see Pair_Correct2 (below).  Pair_Correct2 is not recommended in   
   // case your object model requires some non-static data members to   
   // be private or protected  
  
   string name("John");  
   Pair_Incorrect pair1 = { name, 0.0 };   // C2552  
  
   // initialize a CLR immutable value type that has a constructor  
   System::DateTime dt = {2001, 4, 12, 22, 16, 49, 844};   // C2552   
  
   Pair_Correct1 pair2( name, 0.0 );  
   Pair_Correct1 pair3 = Pair_Correct1( name, 0.0 );  
   Pair_Correct2 pair4 = { name, 0.0 };  
   System::DateTime dt2(2001, 4, 12, 22, 16, 49, 844);  
}  
```

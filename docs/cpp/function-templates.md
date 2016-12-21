---
title: "Modelos de fun&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "modelos de função"
  - "modelos de função, sobre modelos de função"
  - "modelos, Função "
ms.assetid: 59b56a4b-0689-4161-9c07-25021562e2a7
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de fun&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os modelos de classe definem uma família de classes relacionadas que se baseiam nos argumentos de tipo passados para a classe na instanciação.  Os modelos de função são semelhantes aos modelos de classe, mas definem uma família de funções.  Com modelos de função, você pode especificar um conjunto de funções que se baseiam no mesmo código, mas atuam em tipos ou classes diferentes.  O modelo de função a seguir permuta dois itens:  
  
```  
// function_templates1.cpp  
template< class T > void MySwap( T& a, T& b ) {  
   T c(a);   
   a = b;   
   b = c;  
}  
int main() {  
}  
```  
  
 Esse código define uma família de funções que permutam os valores dos argumentos.  A partir desse modelo, você pode gerar funções que permutarão os tipos `int` e **long**, além de tipos definidos pelo usuário.  `MySwap` permutará até mesmo classes se o operador de atribuição e o construtor de cópia da classe estiverem definidos corretamente.  
  
 Além disso, o modelo de função impedirá a permuta de objetos de tipos diferentes, pois o compilador conhece os tipos dos parâmetros `a` e `b` em tempo de compilação.  
  
 Embora essa função possa ser executada por uma função sem modelo, usando ponteiros nulos, a versão com modelo oferece segurança de tipos.  Considere as seguintes chamadas:  
  
```  
int j = 10;  
int k = 18;  
CString Hello = "Hello, Windows!";  
MySwap( j, k );          //OK  
MySwap( j, Hello );      //error  
```  
  
 A segunda chamada de `MySwap` dispara um erro em tempo de compilação, pois o compilador não pode gerar uma função `MySwap` com parâmetros de tipos diferentes.  Se fossem usados ponteiros nulos, as duas chamadas de função seriam compiladas corretamente, mas a função não funcionaria adequadamente em tempo de execução.  
  
 A especificação explícita dos argumentos de um modelo de função é permitida.  Por exemplo:  
  
```  
// function_templates2.cpp  
template<class T> void f(T) {}  
int main(int j) {  
   f<char>(j);   // Generate the specialization f(char).  
   // If not explicitly specified, f(int) would be deduced.  
}  
```  
  
 Quando o argumento de modelo é especificado explicitamente, as conversões implícitas normais são realizadas para converter o argumento da função no tipo dos parâmetros correspondentes do modelo de função.  No exemplo acima, o compilador converterá \(`char j`\) no tipo `int`.  
  
## Consulte também  
 [Modelos](../Topic/Templates%20\(C++\).md)   
 [Instanciação do modelo de função](../cpp/function-template-instantiation.md)   
 [Instanciação explícita](../Topic/Explicit%20Instantiation.md)   
 [Especialização explícita de modelos de função](../cpp/explicit-specialization-of-function-templates.md)
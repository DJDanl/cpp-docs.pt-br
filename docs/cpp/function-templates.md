---
title: Modelos de função | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function templates
- templates, function
- function templates, about function templates
ms.assetid: 59b56a4b-0689-4161-9c07-25021562e2a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c871ae13e333d8d3f7fa1bf0cce29bc1309d0c62
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39403359"
---
# <a name="function-templates"></a>Modelos de função
Os modelos de classe definem uma família de classes relacionadas que se baseiam nos argumentos de tipo passados para a classe na instanciação. Os modelos de função são semelhantes aos modelos de classe, mas definem uma família de funções. Com modelos de função, você pode especificar um conjunto de funções que se baseiam no mesmo código, mas atuam em tipos ou classes diferentes. O modelo de função a seguir permuta dois itens:  
  
```cpp
// function_templates1.cpp  
template< class T > void MySwap( T& a, T& b ) {  
   T c(a);   
   a = b;   
   b = c;  
}  
int main() {  
}  
```  
  
 Esse código define uma família de funções que permutam os valores dos argumentos. Com base neste modelo, você pode gerar funções que permutarão **int** e **longo** tipos e também tipos definidos pelo usuário. `MySwap` permutará até mesmo classes se o operador de atribuição e o construtor de cópia da classe estiverem definidos corretamente.  
  
 Além disso, o modelo de função impedirá você de permuta de objetos de tipos diferentes, pois o compilador conhece os tipos dos *uma* e *b* parâmetros em tempo de compilação.  
  
 Embora essa função possa ser executada por uma função sem modelo, usando ponteiros nulos, a versão com modelo oferece segurança de tipos. Considere as seguintes chamadas:  
  
```cpp
int j = 10;  
int k = 18;  
CString Hello = "Hello, Windows!";  
MySwap( j, k );          //OK  
MySwap( j, Hello );      //error  
```  
  
 A segunda chamada de `MySwap` dispara um erro em tempo de compilação, pois o compilador não pode gerar uma função `MySwap` com parâmetros de tipos diferentes. Se fossem usados ponteiros nulos, as duas chamadas de função seriam compiladas corretamente, mas a função não funcionaria adequadamente em tempo de execução.  
  
 A especificação explícita dos argumentos de um modelo de função é permitida. Por exemplo:  
  
```cpp
// function_templates2.cpp  
template<class T> void f(T) {}  
int main(int j) {  
   f<char>(j);   // Generate the specialization f(char).  
   // If not explicitly specified, f(int) would be deduced.  
}  
```  
  
 Quando o argumento de modelo é especificado explicitamente, as conversões implícitas normais são realizadas para converter o argumento da função no tipo dos parâmetros correspondentes do modelo de função. No exemplo acima, o compilador converterá `char j` digitar **int**.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos](../cpp/templates-cpp.md)   
 [Instanciação do modelo de função](../cpp/function-template-instantiation.md)   
 [Instanciação explícita](../cpp/explicit-instantiation.md)   
 [Especialização explícita de modelos de função](../cpp/explicit-specialization-of-function-templates.md)
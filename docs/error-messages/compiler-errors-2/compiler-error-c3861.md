---
title: 'C3861: erro de compilador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3861
dev_langs:
- C++
helpviewer_keywords:
- C3861
ms.assetid: 0a1eee30-b3db-41b1-b1e5-35949c3924d7
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 82656822d408be4b2fc085abe8a007469c822a65
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3861"></a>C3861: erro de compilador

> '*identificador*': identificador não encontrado  
  
O compilador não foi capaz de resolver uma referência a um identificador, até mesmo usando pesquisa dependente de argumento.  
  
Para corrigir esse erro, compare o uso de *identificador* para a declaração do identificador de caso e a ortografia. Verifique [operadores de resolução do escopo](../../cpp/scope-resolution-operator.md) e namespace [usando diretivas](../../cpp/namespaces-cpp.md#using_directives) está sendo usado corretamente. Se o identificador for declarado em um arquivo de cabeçalho, verifique se o cabeçalho incluído antes que o identificador é referenciado. Se o identificador deve ser visível externamente, certifique-se de que ela é declarada em qualquer arquivo de origem que usa. Além disso, verifique a definição ou declaração do identificador não é excluída por [diretivas de compilação condicional](../../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md). 

As alterações para remover funções obsoletas da biblioteca de tempo de execução do C no Visual Studio 2015 podem causar c3861:. Para resolver esse erro, remova as referências a essas funções ou substituí-los com seus alternativas seguras, se houver. Para obter mais informações, consulte [funções obsoletas](../../c-runtime-library/obsolete-functions.md).  

Se o erro c3861: aparecer após a migração de projeto de versões mais antigas do compilador, você poderá ter problemas relacionados a versões com suporte do Windows. Visual C++ não oferece mais suporte ao direcionamento de Windows 95, Windows 98, Windows ME, Windows NT ou Windows 2000. Se suas macros WINVER ou _WIN32_WINNT são atribuídas a uma dessas versões do Windows, você deve modificar as macros. Para obter mais informações, consulte [modificando WINVER e _WIN32_WINNT](../../porting/modifying-winver-and-win32-winnt.md).
  
## <a name="example"></a>Exemplo  

O exemplo a seguir gera c3861: porque o identificador não está definido.  
  
```cpp  
// C3861.cpp  
void f2(){}  
int main() {  
   f();    // C3861  
   f2();   // OK  
}  
```  
  
## <a name="example"></a>Exemplo  

O exemplo a seguir gera c3861: porque um identificador só é visível no escopo de arquivo de sua definição, a menos que ela é declarada em outros arquivos de origem que usá-lo.  
  
```cpp  
// C3861_a1.cpp
// Compile with: cl /EHsc /W4 C3861_a1.cpp C3861_a2.cpp  
#include <iostream>
// Uncomment the following line to fix:
// int f();  // declaration makes external function visible
int main() {  
   std::cout << f() << std::endl;    // C3861
}  
```  
  
```cpp  
// C3861_a2.cpp  
int f() {  // declared and defined here
   return 42;  
}
```  
  
## <a name="example"></a>Exemplo  

Classes de exceção na biblioteca padrão C++ exigem o `std` namespace.  
  
```cpp  
// C3861_b.cpp  
// compile with: /EHsc  
#include <iostream>  
int main() {  
   try {  
      throw exception("Exception");   // C3861  
      // try the following line instead  
      // throw std::exception("Exception");  
   }  
   catch (...) {  
      std::cout << "caught an exception" << std::endl;  
   }  
}  
```  
## <a name="example"></a>Exemplo  

Funções obsoletas foram removidas da biblioteca CRT.  
  
```cpp  
// C3861_c.cpp  
#include <stdio.h>  
int main() {  
   char line[21]; // room for 20 chars + '\0'  
   gets( line );  // C3861  
   // Use gets_s instead.  
   printf( "The line entered was: %s\n", line );  
}  
```
O exemplo a seguir gera C3767 porque o compilador não pode usar pesquisa dependente de argumento para FriendFunc:  
  
```  
namespace N {  
   class C {  
      friend void FriendFunc() {}  
      friend void AnotherFriendFunc(C* c) {}  
   };  
}  
  
int main() {  
   using namespace N;  
   FriendFunc();   // C3861 error  
   C* pC = new C();  
   AnotherFriendFunc(pC);   // found via argument-dependent lookup  
}  
```  
  
Para corrigir o erro, declare um amigo no escopo de classe e defini-lo no escopo de namespace:  
  

classe MyClass {  
   int m_private;  
   func() de void Friend;  
};  
  
{func() void  
   S MyClass;  
   s.m_private = 0;  
}  
  
int Main () {  
   Func();  
}  
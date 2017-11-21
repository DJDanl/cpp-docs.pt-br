---
title: "Especificações de exceção (lançar) (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- exceptions [C++], exception specifications
- throwing exceptions [C++], throw keyword
- C++ exception handling [C++], throwing exceptions
- throw keyword [C++], throw() vs. throw(...)
- throw keyword [C++], exception specifications
ms.assetid: 4d3276df-6f31-4c7f-8cab-b9d2d003a629
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e308d95f25b25a99fecde976d8ba6433316f460f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="exception-specifications-throw-noexcept-c"></a>Especificações de exceção (lançar, noexcept) (C++)
Especificações de exceção são um recurso de linguagem C++ que indicam a intenção do programador sobre os tipos de exceção que pode ser propagada por uma função. Você pode especificar que uma função pode não ser encerrado ou por uma exceção usando uma *especificação de exceção*. O compilador pode usar essas informações para otimizar a chamadas para a função e encerrar o programa se uma exceção inesperada ignora a função. Há dois tipos de especificação de exceção. O *noexcept especificação* é novo no C++ 11. Especifica se o conjunto de exceções potenciais que podem escapar a função está vazio. O *especificação de exceção dinâmico*, ou `throw(optional_type_list)` especificação foi preterido no C++ 11 e apenas parcialmente com suporte pelo Visual Studio. Essa especificação de exceção foi projetada para fornecer informações de resumo sobre quais exceções podem ser geradas fora de uma função, mas na prática, ele foi encontrado para ser problemático. Uma especificação de exceção dinâmico que revelar um pouco úteis foi o incondicional `throw()` especificação. Por exemplo, a declaração da função:  
  
```cpp  
void MyFunction(int i) throw();  
```  
  
 informa o compilador que a função não lança exceções. É equivalente a usar [nothrow](../cpp/nothrow-cpp.md). Seu uso é considerado opcional.  
  
No C++ 11 padrão ISO, o [noexcept](../cpp/noexcept-cpp.md) operador foi introduzido como uma substituição. Há suporte no Visual Studio 2015 e posteriores. Sempre que possível, use um `noexcept` expressão para especificar se uma função pode lançar exceções. Por exemplo, use essa declaração de função em vez de acima:  
  
```cpp  
void MyFunction(int i) noexcept;  
```  
  
Enquanto o Visual C++ dá suporte totalmente o `noexcept` expressão, entregas de ISO C++ padrão em sua implementação de especificações de exceções dinâmicas.  A tabela a seguir resume a implementação do Visual C++ de especificações de exceção:  
  
|Especificação de exceção|Significado|  
|-----------------------------|-------------|  
|`noexcept`<br/>`noexcept(true)`<br/>`throw()`|A função não gera uma exceção. No entanto, se uma exceção será lançada fora de uma função marcada `throw()`, as chamadas de compilador do Visual C++ `std::terminate`, não `std::unexpected`. Consulte [std::unexpected](../c-runtime-library/reference/unexpected-crt.md) para obter mais informações. Se uma função é marcada como `noexcept`, `noexcept(true)`, ou `throw()`, o compilador do Visual C++ pressupõe que a função não lança exceções C++ e gera o código adequadamente. Porque otimizações de código podem ser executadas pelo compilador C++ baseado na suposição de que a função não gerará as exceções do C++, se uma função lançar uma exceção, o programa pode não ser executada corretamente.|  
|`noexcept(false)`<br/>`throw(...)`<br/>Não há especificação|A função pode lançar uma exceção de qualquer tipo.|  
|`throw(type)`|A função pode gerar uma exceção do tipo `type`. No Visual C++, essa sintaxe é aceita, mas ele será interpretado como `noexcept(false)`.|  
  
 Se o tratamento de exceção é usado em um aplicativo, deve haver uma função na pilha de chamadas identificadores geradas exceções antes de sair do escopo externo de uma função marcados `noexcept`, `noexcept(true)`, ou `throw()`. Se todas as funções chamadas entre o que lança uma exceção e o que lida com a exceção são especificados como `noexcept`, `noexcept(true)`, ou `throw()`, o programa é encerrado quando a função noexcept propaga a exceção.  
  
 O comportamento de exceção de uma função depende dos seguintes fatores:  
  
-   Se você estiver compilando a função em C ou C++.  
  
-   Qual [/EH](../build/reference/eh-exception-handling-model.md) opção de compilador que você usa.  
  
-   Se a especificação de exceção for determinada explicitamente.  
  
 As especificações explícitas de exceção não são permitidas em funções C. Uma função C não deve para lançar exceções em **/EHsc**e pode gerar exceções estruturadas em **/EHs**, **/EHa**, ou **/EHac**.  
  
 A tabela a seguir resume se uma função C++ potencialmente pode gerar em várias opções de tratamento de exceção do compilador:  
  
|Função|/EHsc|/EHs|/EHa|/EHac|  
|--------------|------------|-----------|-----------|------------|  
|Função C++ sem especificação de exceção|Sim|Sim|Sim|Sim|  
|Função C++ com `noexcept`, `noexcept(true)`, ou `throw()` especificação de exceção|Não|Não|Sim|Sim|  
|Função C++ com `noexcept(false)`, `throw(...)`, ou `throw(type)` especificação de exceção|Sim|Sim|Sim|Sim|  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// exception_specification.cpp  
// compile with: /EHs  
#include <stdio.h>  
  
void handler() {  
   printf_s("in handler\n");  
}  
  
void f1(void) throw(int) {  
   printf_s("About to throw 1\n");  
   if (1)  
      throw 1;  
}  
  
void f5(void) throw() {  
   try {  
      f1();  
   }  
   catch(...) {  
      handler();  
    }  
}  
  
// invalid, doesn't handle the int exception thrown from f1()  
// void f3(void) throw() {  
//   f1();  
// }  
  
void __declspec(nothrow) f2(void) {  
   try {  
      f1();  
   }  
   catch(int) {  
      handler();  
    }  
}  
  
// only valid if compiled without /EHc   
// /EHc means assume extern "C" functions don't throw exceptions  
extern "C" void f4(void);  
void f4(void) {  
   f1();  
}  
  
int main() {  
   f2();  
  
   try {  
      f4();  
   }  
   catch(...) {  
      printf_s("Caught exception from f4\n");  
   }  
   f5();  
}  
```  
  
```Output  
About to throw 1  
in handler  
About to throw 1  
Caught exception from f4  
About to throw 1  
in handler  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções try, throw e catch (C++)](../cpp/try-throw-and-catch-statements-cpp.md)   
 [Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)
---
title: "Especifica&#231;&#245;es de exce&#231;&#227;o (lan&#231;ar) (C++) | Microsoft Docs"
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
  - "Tratamento de exceções em C++, lançando exceções"
  - "exceções, especificações de exceção"
  - "palavra-chave throw [C++], especificações de exceção"
  - "palavra-chave throw [C++], throw() vs. throw(...)"
  - "lançando exceções, palavra-chave throw"
ms.assetid: 4d3276df-6f31-4c7f-8cab-b9d2d003a629
caps.latest.revision: 20
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especifica&#231;&#245;es de exce&#231;&#227;o (lan&#231;ar) (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As especificações de exceção são um recurso da linguagem C\+\+ que foi preterido no C\+\+11.  Elas foram criadas para fornecer informações resumidas sobre exceções que podem ser lançadas fora de uma função, mas na prática foi verificado que eram problemáticas.  A especificação de uma exceção que provou ser um pouco útil era a especificação de throw\(\).  Por exemplo:  
  
```  
void MyFunction(int i) throw();  
```  
  
 informa o compilador que a função não lança exceções.  É o equivalente a usar [\_\_declspec\(nothrow\)](../Topic/nothrow%20\(C++\).md).  Seu uso é considerado opcional.  
  
 **\(C \+ \+ 11\)** no ISO do C\+\+ 11 Standard, [noexcept](../Topic/noexcept%20\(C++\).md) operador foi introduzida e é suportado no Visual Studio de 2015 e versões posteriores.  Sempre que possível, use `noexcept` para especificar se uma função pode lançar exceções.  
  
 O Visual C\+\+ parte do padrão ISO C\+\+ em sua implementação de especificações de exceção.  A tabela a seguir resume a implementação do Visual C\+\+ de especificações de exceção:  
  
|Especificação de exceção|Significado|  
|------------------------------|-----------------|  
|throw\(\)|A função não gera uma exceção.  No entanto, se uma exceção for lançada fora de uma função marcada como Throw \(\), o compilador do Visual C\+\+ não chamará inesperado \(consulte [unexpected](../Topic/unexpected%20\(CRT\).md) e [unexpected](../Topic/unexpected%20\(%3Cexception%3E\).md) para obter mais informações\).  Se uma função for marcada com throw\(\), o compilador Visual C\+\+ assumirá que a função não lança exceções de C\+\+ e gerará o código corretamente.  Devido às otimizações de código que podem ser realizadas pelo compilador C\+\+ \(baseado na suposição de que a função não gera nenhuma exceção de C\+\+\) se uma função gerar uma exceção, o programa pode não executar corretamente.|  
|throw\(...\)|A função pode gerar uma exceção.|  
|throw\(`type`\)|A função pode gerar uma exceção do tipo `type`.  No entanto, no Visual C\+\+ .NET, isso é interpretado como throw\(...\).  Consulte [Especificadores de exceção de função](../misc/15-4-function-exception-specifiers.md).|  
  
 Se a manipulação de exceção for usada em um aplicativo, deverá haver uma ou mais funções que tratam as exceções lançadas.  Todas as funções chamadas entre a que lança uma exceção e aquela que lida com a exceção devem ser capazes de lançar a exceção.  
  
 O comportamento de lançamento de uma função depende dos fatores a seguir:  
  
-   Se você estiver compilando a função em C ou C\+\+.  
  
-   Qual opção do compilador [\/EH](../build/reference/eh-exception-handling-model.md) você usa.  
  
-   Se a especificação de exceção for determinada explicitamente.  
  
 As especificações explícitas de exceção não são permitidas em funções C.  
  
 A tabela a seguir resume o comportamento de lançamento de uma função:  
  
|Função|\/EHsc|\/EHs|\/EHa|\/EHac|  
|------------|------------|-----------|-----------|------------|  
|Função C|throw\(\)|throw\(...\)|throw\(...\)|throw\(...\)|  
|Função C\+\+ sem especificação de exceção|throw\(...\)|throw\(...\)|throw\(...\)|throw\(...\)|  
|Função C\+\+ com a especificação de exceção throw\(\)|throw\(\)|throw\(\)|throw\(...\)|throw\(...\)|  
|Função C\+\+ com a especificação de exceção throw\(...\)|throw\(...\)|throw\(...\)|throw\(...\)|throw\(...\)|  
|Função C\+\+ com a especificação de exceção throw\(`type`\)|throw\(...\)|throw\(...\)|throw\(...\)|throw\(...\)|  
  
## Exemplo  
  
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
  
  **Prestes a lançar 1**  
**no manipulador**  
**Prestes a lançar 1**  
**Exceção detectada de f4**  
**Prestes a lançar 1**  
**no manipulador**   
## Consulte também  
 [Instruções try, throw e catch \(C\+\+\)](../cpp/try-throw-and-catch-statements-cpp.md)   
 [Tratamento de exceções C\+\+](../cpp/cpp-exception-handling.md)
---
title: "deprecated (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "deprecated"
  - "deprecated_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], deprecated"
  - "palavra-chave __declspec preterida"
ms.assetid: beef1129-9434-4cb3-8392-f1eb29e04805
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deprecated (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

\(Específico para Microsoft\) A não ser pelas exceções descritas a seguir, a declaração **deprecated** oferece a mesma funcionalidade que o pragma [deprecated](../Topic/deprecated%20\(C-C++\).md):  
  
-   A declaração **deprecated** permite especificar formatos específicos de sobrecargas de função como preteridos, enquanto o formato do pragma se aplica a todos os formatos sobrecarregados de um nome de função.  
  
-   A declaração **deprecated** permite que você especifique uma mensagem que será exibida no tempo de compilação.  O texto da mensagem pode ser de uma macro.  
  
-   As macros podem ser marcadas como preteridas com o pragma **deprecated**.  
  
 Se o compilador encontrar o uso de um identificador preterido, um aviso [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) será lançado.  
  
## Exemplo  
 O exemplo a seguir mostra como marcar funções como preteridas e como especificar uma mensagem que será exibida no tempo de compilação, quando a função preterida for usada.  
  
```  
// deprecated.cpp  
// compile with: /W3  
#define MY_TEXT "function is deprecated"  
void func1(void) {}  
__declspec(deprecated) void func1(int) {}  
__declspec(deprecated("** this is a deprecated function **")) void func2(int) {}  
__declspec(deprecated(MY_TEXT)) void func3(int) {}  
  
int main() {  
   func1();  
   func1(1);   // C4996  
   func2(1);   // C4996  
   func3(1);   // C4996  
}  
```  
  
## Exemplo  
 O exemplo a seguir mostra como marcar classes como preteridas e como especificar uma mensagem que será exibida no tempo de compilação, quando a classe preterida for usada.  
  
```  
// deprecate_class.cpp  
// compile with: /W3  
struct __declspec(deprecated) X {  
   void f(){}  
};  
  
struct __declspec(deprecated("** X2 is deprecated **")) X2 {  
   void f(){}  
};  
  
int main() {  
   X x;   // C4996  
   X2 x2;   // C4996  
}  
```  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)
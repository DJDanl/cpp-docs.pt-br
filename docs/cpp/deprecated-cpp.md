---
title: obsoleto (C++) | Microsoft Docs
ms.custom: ''
ms.date: 03/28/2017
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- deprecated_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], deprecated
- deprecated __declspec keyword
ms.assetid: beef1129-9434-4cb3-8392-f1eb29e04805
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1ec2506b406166ac5316de4724db27a6cd7ffcc1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="deprecated-c"></a>deprecated (C++)
Este tópico é sobre específicos do Microsoft preterido declspec declaração. Para obter informações sobre o C++ 14 `[[deprecated]]` atributo e orientações sobre quando usar esse atributo versus o declspec específicas da Microsoft ou pragma, consulte [atributos padrão do C++](attributes.md).

 Com as exceções indicadas abaixo, o **preterido** declaração oferece a mesma funcionalidade que o [preterido](../preprocessor/deprecated-c-cpp.md) pragma:  
  
-   O **preterido** declaração permite que você especifique formas específicas de sobrecargas de função como preterido, enquanto que o formulário de pragma se aplica a todas as formas sobrecarregadas de um nome de função.  
  
-   O **preterido** declaração permite que você especifique uma mensagem que será exibido no tempo de compilação. O texto da mensagem pode ser de uma macro.  
  
-   Macros só podem ser marcadas como preteridos com o **preterido** pragma.  
  
 Se o compilador encontra o uso de um identificador preterido ou o padrão [ `[[deprecated]]` ](attributes.md) atributo, um [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) aviso é gerado.  
  
## <a name="example"></a>Exemplo  
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
  
## <a name="example"></a>Exemplo  
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
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
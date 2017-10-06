---
title: obsoleto (C++) | Microsoft Docs
ms.custom: 
ms.date: 03/28/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- deprecated_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], deprecated
- deprecated __declspec keyword
ms.assetid: beef1129-9434-4cb3-8392-f1eb29e04805
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 9ac25648e2d19da82f6c213992699c237e05c01e
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="deprecated-c"></a>deprecated (C++)
Este tópico é sobre específicos do Microsoft preterido declspec declaração. Para obter informações sobre o C++ 14 `[[deprecated]]` atributo e orientações sobre quando usar esse atributo versus o declspec específicas da Microsoft ou pragma, consulte [atributos padrão do C++](attributes2.md).

 Com as exceções indicadas abaixo, o **preterido** declaração oferece a mesma funcionalidade que o [preterido](../preprocessor/deprecated-c-cpp.md) pragma:  
  
-   O **preterido** declaração permite que você especifique formas específicas de sobrecargas de função como preterido, enquanto que o formulário de pragma se aplica a todas as formas sobrecarregadas de um nome de função.  
  
-   O **preterido** declaração permite que você especifique uma mensagem que será exibido no tempo de compilação. O texto da mensagem pode ser de uma macro.  
  
-   Macros só podem ser marcadas como preteridos com o **preterido** pragma.  
  
 Se o compilador encontra o uso de um identificador preterido ou o padrão [ `[[deprecated]]` ](attributes2.md) atributo, um [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) aviso é gerado.  
  
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
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)

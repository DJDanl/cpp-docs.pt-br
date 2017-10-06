---
title: "Referências (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- objects [C++], referencing
- references [C++]
- references, to pointers
- declarations, references
- references, declaring
- referencing objects, declarator syntax
ms.assetid: 68156f7f-97a0-4b66-b26d-b25ade5e3bd8
caps.latest.revision: 12
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
ms.openlocfilehash: fb208f61d2da9e7daa7a53ac68fdcdfcdf1acab4
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="references-c"></a>Referências (C++)
Uma referência, como um ponteiro, armazena o endereço de um objeto que está localizado em outro lugar na memória. Ao contrário de um ponteiro, uma referência depois que ele é inicializado não pode ser feita se referir a um objeto diferente ou definido como null. Há dois tipos de referências: referências lvalue que se referem a uma nomeada referências variável e rvalue que se referem a um [objeto temporário](../cpp/temporary-objects.md). A & operador significa uma referência lvalue e a & & operador significa uma referência rvalue ou uma referência universal (rvalue ou lvalue), dependendo do contexto.  
  
 As referências podem ser declaradas usando a seguinte sintaxe:  
  
```  
[storage-class-specifiers] [cv-qualifiers] type-specifiers   
[ms-modifier] declarator [= expression];  
```  
  
 Qualquer declarador válido que especifique uma referência pode ser usado. A menos que se trate de uma referência para um tipo de matriz ou função, a seguinte sintaxe simplificada se aplica:  
  
```  
[storage-class-specifiers] [cv-qualifiers] type-specifiers [& or &&]   
[cv-qualifiers] identifier [= expression];  
```  
  
 As referências são declaradas usando a seguinte sequência:  
  
 1. Os especificadores da declaração:  
  
-   Um especificador de classe de armazenamento opcional.  
  
-   Opcional **const** e/ou `volatile` qualificadores.  
  
-   O especificador de tipo: o nome de um tipo.  
  
-   2. O declarador:  
  
-   Um modificador opcional específico da Microsoft. Para obter mais informações, consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).  
  
-   A & operador ou & & operador.  
  
-   Opcional **const** e/ou `volatile` qualificadores.  
  
-   O identificador.  
  
 3. Um inicializador opcional.  
  
 Os formulários de declaradores mais complexos para ponteiros para funções e matrizes também se aplicam a referências a matrizes e funções, consulte [ponteiros](../cpp/pointers-cpp.md) e [declaradores](http://msdn.microsoft.com/en-us/8a7b9b51-92bd-4ac0-b3fe-0c4abe771838).  
  
 Vários declaradores e inicializadores podem aparecer em uma lista separada por vírgulas após um único especificador de declaração. Por exemplo:  
  
```  
int &i;   
int &i, &j;   
```  
  
 As referências, os ponteiros e os objetos podem ser declarados juntos:  
  
```  
int &ref, *ptr, k;   
```  
  
 Uma referência contém o endereço de um objeto, mas se comporta sintaticamente como um objeto.  
  
 No programa a seguir, observe que o nome do objeto, `Today`, e a referência ao objeto, `TodayRef`, podem ser usados de forma idêntica em programas:  
  
## <a name="example"></a>Exemplo  
  
```  
// references.cpp  
#include <stdio.h>  
struct S {  
   short i;  
};  
  
int main() {  
   S  s;   // Declare the object.  
   S& SRef = s;   // Declare the reference.  
   s.i = 3;  
  
   printf_s("%d\n", s.i);  
   printf_s("%d\n", SRef.i);  
  
   SRef.i = 4;  
   printf_s("%d\n", s.i);  
   printf_s("%d\n", SRef.i);  
}  
```  
  
```Output  
3  
3  
4  
4  
```  
  
## <a name="comment"></a>Comentário  
 Tópicos desta seção:  
  
-   [Argumentos de função de tipo de referência](../cpp/reference-type-function-arguments.md)  
  
-   [Retornos de função de tipo de referência](../cpp/reference-type-function-returns.md)  
  
-   [Referências a ponteiros](../cpp/references-to-pointers.md)  
  


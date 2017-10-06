---
title: classe (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- class_cpp
dev_langs:
- C++
helpviewer_keywords:
- class types [C++], class statements
- class keyword [C++]
ms.assetid: dd23c09f-6598-4069-8bff-69c7f2518b9f
caps.latest.revision: 8
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
ms.openlocfilehash: 7cdd7b7cefcd9f3826cfe426008bdf1eefde82f6
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="class-c"></a>class (C++)
A palavra-chave `class` declara um tipo de classe ou define um objeto de um tipo de classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [template-spec]  
       class [ms-decl-spec] [tag [: base-list ]]  
{  
   member-list  
} [declarators];  
[ class ] tag declarators;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `template-spec`  
 Especificações de modelo opcionais. Para obter mais informações, consulte [modelos](templates-cpp.md).  
  
 `class`  
 A palavra-chave `class`.  
  
 `ms-decl-spec`  
 Especificação de classe de armazenamento opcional. Para obter mais informações, consulte o [declspec](../cpp/declspec.md) palavra-chave.  
  
 `tag`  
 O nome do tipo dado à classe. A marca se torna uma palavra reservada no escopo da classe. A marca é opcional. Se omitida, uma classe anônima será definida. Para obter mais informações, consulte [tipos de classe anônima](../cpp/anonymous-class-types.md).  
  
 `base-list`  
 A lista opcional de classes ou estruturas da qual esta classe derivará seus membros. Consulte [Classes Base](../cpp/base-classes.md) para obter mais informações. Cada nome de classe ou estrutura de base pode ser precedido por um especificador de acesso ([pública](../cpp/public-cpp.md), [privada](../cpp/private-cpp.md), [protegido](../cpp/protected-cpp.md)) e o [virtual](../cpp/virtual-cpp.md) palavra-chave. Consulte a tabela de acesso de membro em [controlando o acesso a membros de classe](member-access-control-cpp.md) para obter mais informações.  
  
 `member-list`  
 Lista de membros da classe. Consulte [visão geral de membro de classe](../cpp/class-member-overview.md) para obter mais informações.  
  
 `declarators`  
 Lista de declaradores que especifica os nomes de uma ou mais instâncias do tipo da classe. Os declaradores podem incluir listas de inicializadores se todos os membros de dados da classe forem `public`. Isso é mais comum nas estruturas, cujos membros de dados são `public` por padrão, em vez de classes. Consulte [visão geral dos declaradores](../cpp/overview-of-declarators.md) para obter mais informações.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre as classes em geral, consulte um dos seguintes tópicos:  
  
-   [struct](../cpp/struct-cpp.md)  
  
-   [union](../cpp/unions.md)  
  
-   [multiple_inheritance](../cpp/inheritance-keywords.md)  
  
-   [Single_Inheritance](../cpp/inheritance-keywords.md)  
  
-   [virtual_inheritance](../cpp/inheritance-keywords.md)  
  
 Para obter informações sobre classes gerenciadas e estruturas, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md)  
  
## <a name="example"></a>Exemplo  
  
```  
// class.cpp  
// compile with: /EHsc  
// Example of the class keyword  
// Exhibits polymorphism/virtual functions.  
  
#include <iostream>  
#include <string>  
#define TRUE = 1  
using namespace std;  
  
class dog  
{  
public:  
   dog()  
   {  
      _legs = 4;  
      _bark = true;  
   }  
  
   void setDogSize(string dogSize)  
   {  
      _dogSize = dogSize;  
   }  
   virtual void setEars(string type)      // virtual function  
   {  
      _earType = type;  
   }  
  
private:  
   string _dogSize, _earType;  
   int _legs;  
   bool _bark;  
  
};  
  
class breed : public dog  
{  
public:  
   breed( string color, string size)  
   {  
      _color = color;  
      setDogSize(size);  
   }  
  
   string getColor()  
   {  
      return _color;  
   }  
  
   // virtual function redefined  
   void setEars(string length, string type)  
   {  
      _earLength = length;  
      _earType = type;  
   }  
  
protected:  
   string _color, _earLength, _earType;  
};  
  
int main()  
{  
   dog mongrel;  
   breed labrador("yellow", "large");  
   mongrel.setEars("pointy");  
   labrador.setEars("long", "floppy");  
   cout << "Cody is a " << labrador.getColor() << " labrador" << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Classes e Structs](../cpp/classes-and-structs-cpp.md)

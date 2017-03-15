---
title: "class (C++) | Microsoft Docs"
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
  - "class_cpp"
  - "class"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave class [C++]"
  - "tipos de classes, instruções class"
ms.assetid: dd23c09f-6598-4069-8bff-69c7f2518b9f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# class (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave `class` declara um tipo de classe ou define um objeto de um tipo de classe.  
  
## Sintaxe  
  
```  
  
      [template-spec]  
       class [ms-decl-spec] [tag [: base-list ]]  
{  
   member-list  
} [declarators];  
[ class ] tag declarators;  
```  
  
#### Parâmetros  
 `template-spec`  
 Especificações de modelo opcionais.  Para obter mais informações, consulte [Especificações de modelo](../Topic/Template%20Specifications.md).  
  
 `class`  
 A palavra\-chave `class`.  
  
 `ms-decl-spec`  
 Especificação de classe de armazenamento opcional.  Para obter mais informações, consulte a palavra\-chave [\_\_declspec](../cpp/declspec.md).  
  
 `tag`  
 O nome do tipo dado à classe.  A marca se torna uma palavra reservada no escopo da classe.  A marca é opcional.  Se omitida, uma classe anônima será definida.  Para obter mais informações, consulte [Tipos anônimos de classes](../cpp/anonymous-class-types.md).  
  
 `base-list`  
 A lista opcional de classes ou estruturas da qual esta classe derivará seus membros.  Consulte [Classes base](../cpp/base-classes.md) para obter mais informações.  Cada classe base ou nome da estrutura pode ser precedido por um especificador de acesso \([público](../cpp/public-cpp.md), [particular](../Topic/private%20\(C++\).md), [protegido](../Topic/protected%20\(C++\).md)\) e pela palavra\-chave [virtual](../cpp/virtual-cpp.md).  Consulte a tabela de acesso dos membros em [Controlando o acesso aos membros da classe](../misc/controlling-access-to-class-members.md) para obter mais informações.  
  
 `member-list`  
 Lista de membros da classe.  Consulte [Visão geral de membros de classe](../Topic/Class%20Member%20Overview.md) para obter mais informações.  
  
 `declarators`  
 Lista de declaradores que especifica os nomes de uma ou mais instâncias do tipo da classe.  Os declaradores podem incluir listas de inicializadores se todos os membros de dados da classe forem `public`.  Isso é mais comum nas estruturas, cujos membros de dados são `public` por padrão, em vez de classes.  Consulte [Visão geral dos declaradores](../cpp/overview-of-declarators.md) para obter mais informações.  
  
## Comentários  
 Para obter mais informações sobre as classes em geral, consulte um dos seguintes tópicos:  
  
-   [struct](../cpp/struct-cpp.md)  
  
-   [union](../cpp/unions.md)  
  
-   [\_\_multiple\_inheritance](../cpp/inheritance-keywords.md)  
  
-   [\_\_single\_inheritance](../cpp/inheritance-keywords.md)  
  
-   [\_\_virtual\_inheritance](../cpp/inheritance-keywords.md)  
  
 Para obter mais informações sobre classes e estruturas gerenciadas, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
## Exemplo  
  
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
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Classes e structs](../Topic/Classes%20and%20Structs%20\(C++\).md)
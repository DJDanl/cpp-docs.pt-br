---
title: "Única herança | Microsoft Docs"
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
- single inheritance
- base classes [C++], indirect
- scope, scope resolution operator
- operators [C++], scope resolution
- scope resolution operator
- derived classes [C++], single base class
- inheritance, single
ms.assetid: 1cb946ed-8b1b-4cf1-bde0-d9cecbfdc622
caps.latest.revision: 13
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
ms.openlocfilehash: b716d383d001b8e0812eaba76322aa3c7b66b8f4
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="single-inheritance"></a>Herança única
Na “herança única”, uma forma comum de herança, as classes têm apenas uma classe base. Considere a relação lustrada na figura a seguir.  
  
 ![Único básico &#45; gráfico de herança](../cpp/media/vc38xj1.gif "vc38XJ1")  
Gráfico simples de herança única  
  
 Observe a progressão de geral a específico na figura. Outro atributo comum encontrado no design da maioria das hierarquias de classes é que a classe derivada tem um “tipo de” relação com a classe base. Na figura, `Book` é um tipo de `PrintedDocument`, e `PaperbackBook` é um tipo de `book`.  
  
 Outro item de observação na figura: `Book` é uma classe derivada (de `PrintedDocument`) e uma classe base (`PaperbackBook` é derivado de `Book`). Uma declaração estrutural de uma hierarquia de classes é mostrada no exemplo a seguir:  
  
```  
// deriv_SingleInheritance.cpp  
// compile with: /LD  
class PrintedDocument {};  
  
// Book is derived from PrintedDocument.  
class Book : public PrintedDocument {};  
  
// PaperbackBook is derived from Book.  
class PaperbackBook : public Book {};  
```  
  
 `PrintedDocument` é considerado uma classe "base direta" de `Book`; é uma classe "base indireta“ de `PaperbackBook`. A diferença é que uma classe base direta aparece na lista base de uma declaração de classe, e uma base indireta, não.  
  
 A classe base da qual cada classe é derivada é declarada antes da declaração da classe derivada. Não é suficiente para fornecer uma declaração de referência de encaminhamento para uma classe base; deve ser uma declaração completa.  
  
 No exemplo anterior, o especificador de acesso **pública** é usado. O significado de herança público, protegido e privado descrito no [controle de acesso de membro.](../cpp/member-access-control-cpp.md)  
  
 Uma classe pode servir como a classe base para muitas aulas específicas, como ilustrado na figura a seguir.  
  
 ![Gráfico acíclico direcionado](../cpp/media/vc38xj2.gif "vc38XJ2")  
Exemplo de gráfico acíclico direcionado  
  
 No diagrama mostrado acima, chamado “gráfico acíclico direcionado” (ou “DAG”), algumas das classes são classes base para mais de uma classe derivada. No entanto, o contrário não é verdadeiro: há apenas uma classe base direta para qualquer classe derivada especificada. O gráfico na figura denota uma estrutura de "herança única".  
  
> [!NOTE]
>  Os gráficos acíclicos direcionados não são exclusivos da herança única. Também são usados para denotar gráficos de herança múltipla. Este tópico é abordado em [várias heranças](http://msdn.microsoft.com/en-us/3b74185e-2beb-4e29-8684-441e51d2a2ca).  
  
 Na herança, a classe derivada contém os membros da classe base mais os novos membros que você adicionar. Como resultado, uma classe derivada pode se referir a membros da classe base (a menos que esses membros sejam redefinidos na classe derivada). O operador de resolução de escopo (`::`) pode ser usado para fazer referência a membros de classes base diretas e indiretas quando esses membros são redefinidos na classe derivada. Considere este exemplo:  
  
```  
// deriv_SingleInheritance2.cpp  
// compile with: /EHsc /c  
#include <iostream>  
using namespace std;  
class Document {  
public:  
   char *Name;   // Document name.  
   void PrintNameOf();   // Print name.  
};  
  
// Implementation of PrintNameOf function from class Document.  
void Document::PrintNameOf() {  
   cout << Name << endl;  
}  
  
class Book : public Document {  
public:  
   Book( char *name, long pagecount );  
private:  
   long  PageCount;  
};  
  
// Constructor from class Book.  
Book::Book( char *name, long pagecount ) {  
   Name = new char[ strlen( name ) + 1 ];  
   strcpy_s( Name, strlen(Name), name );  
   PageCount = pagecount;  
};  
```  
  
 Observe que o construtor para `Book` (`Book::Book`) tem acesso ao membro de dados, `Name`. Em um programa, um objeto do tipo `Book` pode ser criado e usado como segue:  
  
```  
//  Create a new object of type Book. This invokes the  
//   constructor Book::Book.  
Book LibraryBook( "Programming Windows, 2nd Ed", 944 );  
  
...  
  
//  Use PrintNameOf function inherited from class Document.  
LibraryBook.PrintNameOf();  
```  
  
 Como o exemplo acima mostra, o membro da classe e os dados e as funções herdados são usados de forma idêntica. Se a implementação para chamadas da classe `Book` para uma reimplementação da função `PrintNameOf`, a função que pertence à classe `Document` pode ser chamada somente usando o operador de resolução de escopo (`::`):  
  
```  
// deriv_SingleInheritance3.cpp  
// compile with: /EHsc /LD  
#include <iostream>  
using namespace std;  
  
class Document {  
public:  
   char *Name;          // Document name.  
   void  PrintNameOf() {}  // Print name.  
};  
  
class Book : public Document {  
   Book( char *name, long pagecount );  
   void PrintNameOf();  
   long  PageCount;  
};  
  
void Book::PrintNameOf() {  
   cout << "Name of book: ";  
   Document::PrintNameOf();  
}  
```  
  
 Os ponteiros e as referências a classes derivadas podem ser convertidos implicitamente em ponteiros e as referências às suas classes base, se houver uma classe base acessível inequívoca. O código a seguir demonstra esse conceito usando ponteiros (o mesmo princípio se aplica às referências):  
  
```  
// deriv_SingleInheritance4.cpp  
// compile with: /W3  
struct Document {  
   char *Name;  
   void PrintNameOf() {}  
};  
  
class PaperbackBook : public Document {};  
  
int main() {  
   Document * DocLib[10];   // Library of ten documents.  
   for (int i = 0 ; i < 10 ; i++)  
      DocLib[i] = new Document;  
}  
```  
  
 No exemplo anterior, diferentes tipos são criados. No entanto, como todos esses tipos são derivados da classe `Document`, há uma conversão implícita em `Document *`. Como resultado, `DocLib` é uma "lista heterogênea” (uma lista em que nem todos os objetos são do mesmo tipo) que contém tipos diferentes de objetos.  
  
 Como a classe `Document` tem uma função `PrintNameOf`, ela pode imprimir o nome de cada livro na biblioteca, embora possa omitir informações específicas do tipo de documento (número de páginas de `Book`, número de bytes de `HelpFile`, e assim por diante).  
  
> [!NOTE]
>  Forçar a classe base a implementar uma função como `PrintNameOf` normalmente não é o melhor design. [Funções virtuais](../cpp/virtual-functions.md) oferece outras alternativas de design.  
  


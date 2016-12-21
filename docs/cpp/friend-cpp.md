---
title: "friend (C++) | Microsoft Docs"
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
  - "Friend"
  - "friend_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes friend"
  - "palavra-chave friend [C++]"
  - "acesso de membro, de funções friend"
ms.assetid: 8fe9ee55-d56f-40cd-9075-d9fb1375aff4
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# friend (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em algumas circunstâncias, é mais conveniente conceder acesso de membro às funções que não são membros de uma classe ou a todas as funções de uma classe separada.  O implementador de classe pode declarar que seus amigos.  Uma classe ou função não pode declarar como um amigo de qualquer classe.  Em uma declaração de classe, use o `friend` palavra\-chave e o nome de uma função não\-membro ou outra classe para conceder acesso aos membros particulares e protegidos da sua classe.  
  
## Sintaxe  
  
```  
  
        friend class-name;  
friend function-declarator;  
```  
  
## Declarações de amigo  
 Se você declarar uma função de amigo que não foi declarada anteriormente, essa função é exportada para o escopo de envolvimento sem classe.  
  
 As funções declaradas em uma declaração de amigo são tratadas como se tivessem sido declaradas usando a palavra\-chave `extern`.  \(Para obter mais informações sobre `extern`, consulte[Especificadores de classe de armazenamento estático](http://msdn.microsoft.com/pt-br/3ba9289a-a412-4a17-b319-ceb2c087df48).\)  
  
 Ainda que as funções com escopo global possam ser declaradas como amigos antes dos protótipos, as funções de membro não podem ser declaradas como amigos antes da aparência de sua declaração completa da classe.  O exemplo de código a seguir mostra porque isso falha:  
  
```  
class ForwardDeclared;   // Class name is known.  
class HasFriends  
{  
    friend int ForwardDeclared::IsAFriend();   // C2039 error expected  
};  
```  
  
 O exemplo anterior insere o nome da classe `ForwardDeclared` no escopo, mas a declaração completa — especificamente, a parte que declara a função `IsAFriend` — não é conhecida.  Consequentemente, a declaração `friend` na classe `HasFriends` gera um erro.  
  
 Para declarar duas classes que são amigas da outro, a segunda classe inteira deve ser especificada como amiga de primeira classe.  A razão para essa restrição é que o compilador tem informações suficientes para declarar funções individuais de amigo somente no ponto onde a segunda classe é declarada.  
  
> [!NOTE]
>  Embora a segunda classe inteira deve ser amiga da primeira classe, você pode selecionar quais funções na primeira classe serão amigas da segunda classe.  
  
## funções friend  
 Uma função `friend` é uma função que não é membro de uma classe, mas que tem acesso a membros particulares e protegidos da classe.  As funções friend não são consideradas membros de classe; elas são funções externas normais que recebem privilégios de acesso especiais.  Amigos não estão no escopo da classe, e não são chamadas usando os operadores de seleção de membro \(**.** e –**\>**\) a menos que sejam membros de outra classe.  Uma função `friend` é declarada pela classe que está concedendo acesso.  A declaração `friend` pode ser colocada em qualquer lugar da declaração da classe.  Ela não é afetada pelas palavras\-chave de controle de acesso.  
  
 O exemplo a seguir mostra uma classe `Point` e uma função friend, `ChangePrivate`.  A função `friend` tem acesso ao membro de dados particular do objeto `Point` que ela recebe como um parâmetro.  
  
```  
// friend_functions.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
class Point  
{  
    friend void ChangePrivate( Point & );  
public:  
    Point( void ) : m_i(0) {}  
    void PrintPrivate( void ){cout << m_i << endl; }  
  
private:  
    int m_i;  
};  
  
void ChangePrivate ( Point &i ) { i.m_i++; }  
  
int main()  
{  
   Point sPoint;  
   sPoint.PrintPrivate();  
   ChangePrivate(sPoint);  
   sPoint.PrintPrivate();  
// Output: 0  
           1  
}  
```  
  
## Membros de classe como amigos  
 As funções de membro da classe podem ser declaradas como amigos em outras classes.  Considere o exemplo a seguir:  
  
```  
// classes_as_friends1.cpp  
// compile with: /c  
class B;  
  
class A {  
public:  
   int Func1( B& b );  
  
private:  
   int Func2( B& b );  
};  
  
class B {  
private:  
   int _b;  
  
   // A::Func1 is a friend function to class B  
   // so A::Func1 has access to all members of B  
   friend int A::Func1( B& );  
};  
  
int A::Func1( B& b ) { return b._b; }   // OK  
int A::Func2( B& b ) { return b._b; }   // C2248  
```  
  
 No exemplo anterior, somente a função `A::Func1( B& )` tem acesso de amigo para classificar `B`.  Em virtude disso, o acesso ao membro particular `_b` está correto em `Func1` da classe `A` mas não em `Func2`.  
  
 Uma classe `friend` é uma classe cujas funções membro são as funções amigas de uma classe, ou seja, cujas funções membro tenham acesso aos outros membros particulares e protegidos da classe.  Suponha que a declaração `friend` na classe `B` fosse:  
  
```  
friend class A;  
```  
  
 Nesse caso, todas as funções membro na classe `A` receberão acesso de amigo para classificar `B`.  O código a seguir é um exemplo de uma classe de amigo:  
  
```  
// classes_as_friends2.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
class YourClass {  
friend class YourOtherClass;  // Declare a friend class  
public:  
   YourClass() : topSecret(0){}  
   void printMember() { cout << topSecret << endl; }  
private:  
   int topSecret;  
};  
  
class YourOtherClass {  
public:  
   void change( YourClass& yc, int x ){yc.topSecret = x;}  
};  
  
int main() {  
   YourClass yc1;  
   YourOtherClass yoc1;  
   yc1.printMember();  
   yoc1.change( yc1, 5 );  
   yc1.printMember();  
}  
```  
  
 A amizade não é mútua a menos que explicitamente especificada como tal.  No exemplo anterior, as funções membro de `YourClass` não podem acessar os membros privados de `YourOtherClass`.  
  
 Um tipo gerenciado não pode ter nenhuma função de amigo, classes de amigo ou interfaces de amigo.  
  
 A amizade não é herdada, o que significa que as classes derivadas de `YourOtherClass` não podem acessar os membros privados de `YourClass`.  A amizade não é transitiva, assim as classes que são amigos de `YourOtherClass` não podem acessar membros privados de `YourClass`.  
  
 A figura a seguir mostra quatro declarações de classe: `Base`, `Derived`, `aFriend` e `anotherFriend`.  Somente a classe `aFriend` tem acesso direto aos membros privados de `Base` \(e a todos os membros que `Base` pode ter herdado\).  
  
 ![Gráfico de implicações de relacionamento de amigo](../cpp/media/vc38v41.png "vc38V41")  
Implicações da relação de amigo  
  
## Definições de amigo embutidas  
 As funções friend podem ser definidas nas declarações de classe.  Essas funções são funções embutidas, e como funções membro embutidas, se comportam como se fossem definidas imediatamente após todos os membros de classe terem sido vistos, mas antes que o escopo de classe seja fechado \(o final da declaração de classe\).  
  
 As funções friend definidas dentro de declarações de classe não são consideradas no escopo da classe delimitadora; elas estão no escopo do arquivo.  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)
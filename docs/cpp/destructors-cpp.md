---
title: "Destruidores (C++) | Microsoft Docs"
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
  - "Operador ~, especificando destruidores"
  - "destruindo objetos, destruidores"
  - "destruidores, sobre destruidores"
  - "destruidores, C++"
  - "objetos [C++], destruindo"
  - "Visual C++, destruidores"
ms.assetid: afa859b0-f3bc-4c4d-b250-c68b335b6004
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Destruidores (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções de “destruidor” são o oposto das funções de construtor.  Elas são chamadas quando os objetos são destruídos \(desalocados\).  Designe uma função como o destruidor de uma classe inserindo um til \(`~`\) antes do nome da classe.  Por exemplo, o destruidor da classe `String` é declarado: `~String()`.  
  
 Em uma compilação de \/clr, o destruidor tem uma função especial, liberando recursos gerenciados e não gerenciados.  Consulte [Destruidores e finalizadores em Visual C\+\+](../misc/destructors-and-finalizers-in-visual-cpp.md) para obter mais informações.  
  
 Em geral, o destruidor é usado para “limpeza” quando um objeto não é mais necessário.  Observe a considere a seguinte declaração de uma classe `String`:  
  
```  
// spec1_destructors.cpp  
#include <string.h>  
  
class String {  
public:  
   String( char *ch );  // Declare constructor  
   ~String();           //  and destructor.  
private:  
   char    *_text;  
   size_t  sizeOfText;  
};  
  
// Define the constructor.  
String::String( char *ch ) {  
   sizeOfText = strlen( ch ) + 1;  
  
   // Dynamically allocate the correct amount of memory.  
   _text = new char[ sizeOfText ];  
  
   // If the allocation succeeds, copy the initialization string.  
   if( _text )  
      strcpy_s( _text, sizeOfText, ch );  
}  
  
// Define the destructor.  
String::~String() {  
   // Deallocate the memory that was previously reserved  
   //  for this string.  
   if (_text)  
      delete[] _text;  
}  
  
int main() {  
   String str("The piper in the glen...");  
}  
```  
  
 No exemplo anterior, o destruidor `String::~String` usa o operador `delete` para desalocar o espaço alocado dinamicamente para o armazenamento de texto.  
  
## Destruidores Delcaring  
 Os destruidores são funções com o mesmo nome da classe, mas precedidos por um til \(`~`\)  
  
 A primeira forma da sintaxe é usada para os destruidores declarados ou definidos dentro de uma declaração de classe; a segunda forma é usada para os destruidores definidos fora de uma declaração da classe.  
  
 Várias regras controlam a declaração de destruidores.  Destruidores:  
  
-   Não aceitam argumentos.  
  
-   Não podem especificar nenhum tipo de retorno \(que inclui `void`\).  
  
-   Não podem retornar um valor usando a instrução `return`.  
  
-   Não podem ser declarados como **const**, `volatile` ou **static**.  No entanto, eles podem ser chamados para destruir objetos declarados como **const**, `volatile` ou **static**.  
  
-   Eles podem ser declarados como **virtual**.  Usando destruidores virtuais, você pode destruir objetos sem conhecer o tipo deles — o destruidor correto para o objeto é invocado usando o mecanismo de função virtual.  Observe que os destruidores também podem ser declarados como funções virtuais puras para classes abstratas.  
  
## Usando destruidores  
 Os destruidores são chamados quando ocorre um dos seguintes eventos:  
  
-   Um objeto alocado usando o operador **new** é desalocado explicitamente usando o operador **delete**.  Quando os objetos são desalocados usando o operador **delete**, a memória é liberada para o "objeto mais derivado", ou o objeto que é um objeto completo e não um subobjeto que representa uma classe base.  Essa desalocação do "objeto mais derivado" só tem funcionamento garantido com destruidores virtuais.  A desalocação pode falhar em situações de herança múltipla em que as informações de tipo não correspondem ao tipo subjacente do objeto propriamente dito.  
  
-   Um objeto local \(automático\) com escopo de bloco sai do escopo.  
  
-   O tempo de vida de um objeto temporário termina.  
  
-   Um programa é encerrado e existem objetos globais ou estáticos.  
  
-   O destruidor é chamado explicitamente usando o nome totalmente qualificado da função de destruidor.  \(Para obter mais informações, consulte [Chamadas de destruidor explícitas](../misc/explicit-destructor-calls.md).\)  
  
 Os casos descritos na lista acima asseguram que todos os objetos possam ser destruídos com métodos definidos pelo usuário.  
  
 Se uma classe base ou um membro de dados tem um destruidor acessível e se uma classe derivada não declara um destruidor, o compilador gera um.  Esse destruidor gerado pelo compilador chama o destruidor da classe base e os destruidores dos membros do tipo derivado.  Os destruidores padrão são públicos.  \(Para obter mais informações sobre acessibilidade, consulte [Especificadores de acesso para classes base](../misc/access-specifiers-for-base-classes.md).\)  
  
 Os destruidores podem chamar funções de membro de classe e acessar dados de membros de classe livremente.  Quando uma função virtual é chamada em um destruidor, a função chamada é aquela que corresponde à classe que está sendo destruída.  \(Para obter mais informações, consulte [Ordem de destruição](../misc/order-of-destruction.md).\)  
  
 Há duas restrições no uso de destruidores.  A primeira é que não é possível obter o endereço de um destruidor.  A segunda é que as classes derivadas não herdam os destruidores da classe base.  Em vez disso, como explicado anteriormente, elas sempre substituem os destruidores da classe base.  
  
## Ordem de destruição  
 Quando um objeto sai do escopo ou é excluído, a sequência de eventos em sua destruição completa é a seguinte:  
  
1.  O destruidor da classe é chamado e o corpo da função de destruidor é executado.  
  
2.  Os destruidores para objetos dos membros não estáticos são chamados na ordem inversa em que aparecem na declaração da classe.  A lista de inicialização opcional dos membros, usada na construção desses membros, não afeta a ordem de \(construção ou\) destruição.  \(Para obter mais informações sobre a inicialização de membros, consulte [Inicializando bases e membros](http://msdn.microsoft.com/pt-br/2f71377e-2b6b-49da-9a26-18e9b40226a1).\)  
  
3.  Os destruidores de classes base não virtuais são chamados na ordem inversa da declaração.  
  
4.  Os destruidores de classes base virtuais são chamados na ordem inversa da declaração.  
  
```  
// order_of_destruction.cpp  
#include <stdio.h>  
  
struct A1      { virtual ~A1() { printf("A1 dtor\n"); } };  
struct A2 : A1 { virtual ~A2() { printf("A2 dtor\n"); } };  
struct A3 : A2 { virtual ~A3() { printf("A3 dtor\n"); } };  
  
struct B1      { ~B1() { printf("B1 dtor\n"); } };  
struct B2 : B1 { ~B2() { printf("B2 dtor\n"); } };  
struct B3 : B2 { ~B3() { printf("B3 dtor\n"); } };  
  
int main() {  
   A1 * a = new A3;  
   delete a;  
   printf("\n");  
  
   B1 * b = new B3;  
   delete b;  
   printf("\n");  
  
   B3 * b2 = new B3;  
   delete b2;  
}  
  
Output: A3 dtor  
A2 dtor  
A1 dtor  
  
B1 dtor  
  
B3 dtor  
B2 dtor  
B1 dtor  
  
```  
  
### Classes base virtuais  
 Destruidores para classes base virtuais são chamados na ordem inversa de sua aparência em um gráfico acíclico direcionado \(profundidade, esquerda para direita, ordem de publicação transversal\).  a figura a seguir mostra um gráfico de herança.  
  
 ![De InheritanceGraphVirtualBaseClasses](../cpp/media/vc392j1.png "vc392J1")  
Gráfico de herança mostrando classes base virtuais  
  
 A lista a seguir mostra os cabeçalhos de classe das classes mostradas.  
  
```  
class A  
class B  
class C : virtual public A, virtual public B  
class D : virtual public A, virtual public B  
class E : public C, public D, virtual public B  
```  
  
 Para determinar a ordem de destruição das classes base virtuais de um objeto do tipo `E`, o compilador cria uma lista aplicando o seguinte algoritmo:  
  
1.  Percorrer o gráfico à esquerda, a partir do ponto mais profundo do gráfico \(nesse caso, `E`\).  
  
2.  Executar percurso à esquerda até que todos os nós sejam visitados.  Tomar nota do nome do nó atual.  
  
3.  Retornar ao nó anterior \(para baixo e à direita\) para descobrir se o nó que está sendo recordado é uma classe base virtual.  
  
4.  Se o nó recordado for uma classe base virtual, verificar a lista para ver se ela já foi inserida.  Se não for uma classe base virtual, ignora\-la.  
  
5.  Se o nó recordado ainda não estiver na lista, adiciona\-lo à parte inferior da lista.  
  
6.  Percorrer o gráfico acima e ao longo do caminho seguinte à direita.  
  
7.  Vá para a etapa 2.  
  
8.  Quando o último caminho acima tiver sido é esgotado, tomar nota o nome do nó atual.  
  
9. Vá para a etapa 3.  
  
10. Continuar esse processo até que o nó final seja novamente o nó atual.  
  
 Portanto, para a classe `E`, a ordem de destruição é:  
  
1.  A classe base não virtual `E`.  
  
2.  A classe base não virtual `D`.  
  
3.  A classe base não virtual `C`.  
  
4.  A classe base virtual `B`.  
  
5.  A classe base virtual `A`.  
  
 Esse processo gera uma lista ordenada de entradas exclusivas.  Nenhum nome de classe aparece duas vezes.  Depois que a lista é construída, ela é percorrida na ordem inversa e o destruidor de cada uma das classes na lista, da última até a primeira, é chamado.  
  
 A ordem de construção ou de destruição primeiro é muito importante quando os construtores ou os destruidores em uma classe se baseiam em outro componente criado antes ou que dura por mais tempo — por exemplo, se o destruidor de `A` \(mostrada na figura anterior\) depende que `B` ainda esteja presente quando o código for executado, ou vice\-versa.  
  
 Essas interdependências entre classes em um gráfico de herança são inerentemente perigosas, pois as classes derivadas posteriormente podem alterar qual é o caminho mais à esquerda, alterando assim a ordem de construção e destruição.  
  
### Classes base não virtuais  
 Os destruidores de classes base não virtuais são chamados na ordem inversa da qual os nomes da classe base são declarados.  Considere a seguinte declaração de classe:  
  
```  
class MultInherit : public Base1, public Base2  
...  
```  
  
 No exemplo anterior, o destruidor de `Base2` é chamado antes de destruidor de `Base1`.  
  
## Chamadas de destruidor explícitas  
 Chamar um destruidor de forma explícita raramente é necessário.  No entanto, pode ser útil realizar a limpeza dos objetos colocados em endereços absolutos.  Esses objetos são normalmente alocados usando um operador **new** definido pelo usuário que usa um argumento de posicionamento.  O operador **delete** não pode desalocar essa memória porque ela não está alocada do armazenamento livre \(para obter mais informações, consulte [Os operadores new e delete](../cpp/new-and-delete-operators.md)\).  Entretanto, uma chamada para o destruidor pode realizar uma limpeza apropriada.  Para chamar explicitamente o destruidor de um objeto, `s`, da classe `String`, use uma das seguintes instruções:  
  
```  
s.String::~String();     // Nonvirtual call  
ps->String::~String();   // Nonvirtual call  
  
s.~String();       // Virtual call  
ps->~String();     // Virtual call  
```  
  
 A notação de chamadas explícitas aos destruidores, mostrada anteriormente, pode ser usada independentemente de o tipo definir um destruidor.  Isso permite fazer essas chamadas explícitas sem saber se há um destruidor definido para o tipo.  Uma chamada explícita para um destruidor que não tem nenhum definido não tem efeito.  
  
## Consulte também  
 [Funções de membro especiais](../misc/special-member-functions-cpp.md)
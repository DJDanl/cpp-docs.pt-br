---
title: Destruidores (C++)
ms.date: 07/20/2019
helpviewer_keywords:
- objects [C++], destroying
- destructors, C++
ms.assetid: afa859b0-f3bc-4c4d-b250-c68b335b6004
ms.openlocfilehash: 5da7659d2d45bca9efba21be2cd0bf581d539780
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221660"
---
# <a name="destructors-c"></a>Destruidores (C++)

Um destruidor é uma função membro que é invocada automaticamente quando o objeto sai do escopo ou destruído explicitamente por uma chamada para **`delete`** . Um destruidor tem o mesmo nome que a classe, precedida por um til ( `~` ). Por exemplo, o destruidor da classe `String` é declarado: `~String()`.

Se você não definir um destruidor, o compilador fornecerá um padrão; para muitas classes, isso é suficiente. Você só precisa definir um destruidor personalizado quando a classe armazena identificadores para recursos do sistema que precisam ser liberados ou ponteiros que possuem a memória para a qual apontam.

Observe a considere a seguinte declaração de uma classe `String`:

```cpp
// spec1_destructors.cpp
#include <string>

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
   delete[] _text;
}

int main() {
   String str("The piper in the glen...");
}
```

No exemplo anterior, o destruidor `String::~String` usa o **`delete`** operador para desalocar o espaço alocado dinamicamente para armazenamento de texto.

## <a name="declaring-destructors"></a>Declarando destruidores

Os destruidores são funções com o mesmo nome da classe, mas precedidos por um til ( `~` )

Várias regras controlam a declaração de destruidores. Destruidores:

- Não aceitam argumentos.

- Não retornar um valor (ou **`void`** ).

- Não pode ser declarado como **`const`** , **`volatile`** ou **`static`** . No entanto, eles podem ser invocados para a destruição de objetos declarados como **`const`** , **`volatile`** ou **`static`** .

- Pode ser declarado como **`virtual`** . Usando destruidores virtuais, você pode destruir objetos sem conhecer o tipo deles — o destruidor correto para o objeto é invocado usando o mecanismo de função virtual. Observe que os destruidores também podem ser declarados como funções virtuais puras para classes abstratas.

## <a name="using-destructors"></a>Usando destruidores

Os destruidores são chamados quando ocorre um dos seguintes eventos:

- Um objeto local (automático) com escopo de bloco sai do escopo.

- Um objeto alocado usando o **`new`** operador é explicitamente desalocado usando **`delete`** .

- O tempo de vida de um objeto temporário termina.

- Um programa é encerrado e existem objetos globais ou estáticos.

- O destruidor é chamado explicitamente usando o nome totalmente qualificado da função de destruidor.

Os destruidores podem chamar funções de membro de classe e acessar dados de membros de classe livremente.

Há duas restrições sobre o uso de destruidores:

- Você não pode obter seu endereço.

- Classes derivadas não herdam o destruidor de sua classe base.

## <a name="order-of-destruction"></a>Ordem de destruição

Quando um objeto sai do escopo ou é excluído, a sequência de eventos em sua destruição completa é a seguinte:

1. O destruidor da classe é chamado e o corpo da função de destruidor é executado.

1. Os destruidores para objetos dos membros não estáticos são chamados na ordem inversa em que aparecem na declaração da classe. A lista de inicialização de membro opcional usada na construção desses membros não afeta a ordem de construção ou destruição.

1. Os destruidores para classes de base não virtuais são chamados na ordem inversa da declaração.

1. Os destruidores de classes base virtuais são chamados na ordem inversa da declaração.

```cpp
// order_of_destruction.cpp
#include <cstdio>

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

### <a name="virtual-base-classes"></a>Classes base virtuais

Os destruidores para as classes base virtuais são chamados na ordem inversa de sua aparência em um grafo acíclico direcionado (profundidade-primeiro, da esquerda para a direita, passagem de ordem dupla). a figura a seguir descreve um grafo de herança.

![Grafo de herança que mostra as classes base virtuais](../cpp/media/vc392j1.gif "Grafo de herança que mostra as classes base virtuais") <br/>
Grafo de herança que mostra as classes base virtuais

A lista a seguir mostra os cabeçalhos de classe das classes mostradas.

```cpp
class A
class B
class C : virtual public A, virtual public B
class D : virtual public A, virtual public B
class E : public C, public D, virtual public B
```

Para determinar a ordem de destruição das classes base virtuais de um objeto do tipo `E`, o compilador cria uma lista aplicando o seguinte algoritmo:

1. Percorrer o gráfico à esquerda, a partir do ponto mais profundo do gráfico (nesse caso, `E`).

1. Executar percurso à esquerda até que todos os nós sejam visitados. Tomar nota do nome do nó atual.

1. Retornar ao nó anterior (para baixo e à direita) para descobrir se o nó que está sendo recordado é uma classe base virtual.

1. Se o nó recordado for uma classe base virtual, verificar a lista para ver se ela já foi inserida. Se não for uma classe base virtual, ignora-la.

1. Se o nó recordado ainda não estiver na lista, adiciona-lo à parte inferior da lista.

1. Percorrer o gráfico acima e ao longo do caminho seguinte à direita.

1. Vá para a etapa 2.

1. Quando o último caminho acima tiver sido é esgotado, tomar nota o nome do nó atual.

1. Vá para a etapa 3.

1. Continuar esse processo até que o nó final seja novamente o nó atual.

Portanto, para a classe `E`, a ordem de destruição é:

1. A classe base não virtual `E` .

1. A classe base não virtual `D` .

1. A classe base não virtual `C` .

1. A classe base virtual `B`.

1. A classe base virtual `A`.

Esse processo gera uma lista ordenada de entradas exclusivas. Nenhum nome de classe aparece duas vezes. Depois que a lista é construída, ela é percorrida na ordem inversa e o destruidor de cada uma das classes na lista, da última até a primeira, é chamado.

A ordem de construção ou de destruição primeiro é muito importante quando os construtores ou os destruidores em uma classe se baseiam em outro componente criado antes ou que dura por mais tempo — por exemplo, se o destruidor de `A` (mostrada na figura anterior) depende que `B` ainda esteja presente quando o código for executado, ou vice-versa.

Essas interdependências entre classes em um grafo de herança são inerentemente perigosas, pois as classes derivadas posteriormente podem alterar qual é o caminho mais à esquerda, alterando assim a ordem de construção e destruição.

### <a name="non-virtual-base-classes"></a>Classes base não virtuais

Os destruidores para classes de base não virtuais são chamados na ordem inversa em que os nomes de classe base são declarados. Considere a seguinte declaração de classe:

```cpp
class MultInherit : public Base1, public Base2
...
```

No exemplo anterior, o destruidor de `Base2` é chamado antes de destruidor de `Base1`.

## <a name="explicit-destructor-calls"></a>Chamadas explícitas de destruidores

Chamar um destruidor de forma explícita raramente é necessário. No entanto, pode ser útil realizar a limpeza dos objetos colocados em endereços absolutos. Esses objetos são normalmente alocados usando um operador definido pelo usuário **`new`** que usa um argumento de posicionamento. O **`delete`** operador não pode desalocar esta memória porque ela não está alocada do armazenamento gratuito (para obter mais informações, consulte [os operadores New e Delete](../cpp/new-and-delete-operators.md)). Entretanto, uma chamada para o destruidor pode realizar uma limpeza apropriada. Para chamar explicitamente o destruidor de um objeto, `s`, da classe `String`, use uma das seguintes instruções:

```cpp
s.String::~String();     // non-virtual call
ps->String::~String();   // non-virtual call

s.~String();       // Virtual call
ps->~String();     // Virtual call
```

A notação de chamadas explícitas aos destruidores, mostrada anteriormente, pode ser usada independentemente de o tipo definir um destruidor. Isso permite fazer essas chamadas explícitas sem saber se há um destruidor definido para o tipo. Uma chamada explícita para um destruidor que não tem nenhum definido não tem efeito.

## <a name="robust-programming"></a>Programação robusta

Uma classe precisa de um destruidor se adquirir um recurso e gerenciar o recurso com segurança, provavelmente precisará implementar um construtor de cópia e uma atribuição de cópia.

Se essas funções especiais não forem definidas pelo usuário, elas serão definidas implicitamente pelo compilador. Os construtores e operadores de atribuição gerados implicitamente executam a cópia superficial, memberwise, que é quase certamente errado se um objeto estiver gerenciando um recurso.

No próximo exemplo, o construtor de cópia gerado implicitamente fará os ponteiros `str1.text` e `str2.text` se referirem à mesma memória e, quando retornamos `copy_strings()` , essa memória será excluída duas vezes, o que é um comportamento indefinido:

```cpp
void copy_strings()
{
   String str1("I have a sense of impending disaster...");
   String str2 = str1; // str1.text and str2.text now refer to the same object
} // delete[] _text; deallocates the same memory twice
  // undefined behavior
```

Definir explicitamente um destruidor, um construtor de cópia ou um operador de atribuição de cópia impede a definição implícita do construtor de movimentação e o operador de atribuição de movimentação. Nesse caso, a falha ao fornecer operações de movimentação é geralmente, se a cópia for cara, uma oportunidade de otimização perdida.

## <a name="see-also"></a>Confira também

[Copiar construtores e operadores de atribuição de cópia](../cpp/copy-constructors-and-copy-assignment-operators-cpp.md)</br>
[Mover construtores e mover operadores de atribuição](../cpp/move-constructors-and-move-assignment-operators-cpp.md)

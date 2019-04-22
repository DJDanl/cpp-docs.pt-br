---
title: Operador new (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 69fee812-1c28-4882-8fda-d1ad17860004
ms.openlocfilehash: bcb7784e59966510970bd9b3ae0157ae982e462d
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58768062"
---
# <a name="new-operator-c"></a>Operador new (C++)

Aloca memória para um objeto ou uma matriz de objetos do *nome do tipo* do repositório livre e retorna um ponteiro adequadamente tipado, diferente de zero para o objeto.

> [!NOTE]
>  Extensões de componentes do Microsoft C++ fornece suporte para o **novo** palavra-chave para adicionar entradas de slot a vtable. Para obter mais informações, consulte [novo (novo slot em vtable)](../extensions/new-new-slot-in-vtable-cpp-component-extensions.md)

## <a name="syntax"></a>Sintaxe

```
[::] new [placement] new-type-name [new-initializer]
[::] new [placement] ( type-name ) [new-initializer]
```

## <a name="remarks"></a>Comentários

Caso contrário, **novos** retorna zero ou lança uma exceção, consulte [o novo e excluir operadores](../cpp/new-and-delete-operators.md) para obter mais informações. Você pode alterar esse comportamento padrão escrevendo uma rotina de manipulação de exceção personalizada e chamando o [set_new_handler](../c-runtime-library/reference/set-new-handler.md) a função de biblioteca de tempo de execução com o nome de função como seu argumento.

Para obter informações sobre como criar um objeto no heap gerenciado, consulte [gcnew](../extensions/ref-new-gcnew-cpp-component-extensions.md).

Quando **novo** é usado para alocar memória para um objeto de classe do C++, o construtor do objeto é chamado depois que a memória é alocada.

Use o [exclua](../cpp/delete-operator-cpp.md) operador para desalocar a memória alocada com o **novo** operador.

O exemplo a seguir aloca e depois libera uma matriz bidimensional de caracteres de tamanho `dim` por 10. Ao alocar uma matriz multidimensional, todas as dimensões, exceto a primeira, devem ser expressões de constantes que são avaliadas como valores positivos; a dimensão mais à esquerda da matriz pode ser qualquer expressão que seja avaliada como um valor positivo. Ao alocar uma matriz usando o **novos** operador, a primeira dimensão pode ser zero — o **novos** operador retorna um ponteiro exclusivo.

```cpp
char (*pchar)[10] = new char[dim][10];
delete [] pchar;
```

O *nome do tipo* não pode conter **const**, **volátil**, declarações de classe nem declarações de enumeração. Dessa forma, a expressão a seguir é inválida:

```cpp
volatile char *vch = new volatile char[20];
```

O **novo** operador não aloca tipos de referência porque eles não são objetos.

O **novo** operador não pode ser usado para alocar uma função, mas ele pode ser usado para alocar ponteiros para funções. O exemplo a seguir aloca e depois libera uma matriz de sete ponteiros para funções que retornam inteiros.

```cpp
int (**p) () = new (int (*[7]) ());
delete *p;
```

Se você usar o operador **novos** sem qualquer argumento extra e compilar com o [/GX](../build/reference/gx-enable-exception-handling.md), [/EHa](../build/reference/eh-exception-handling-model.md), ou [/EHs](../build/reference/eh-exception-handling-model.md) opção, o compilador realizará Gerar código para chamar o operador **excluir** se o construtor gerará uma exceção.

A lista a seguir descreve os elementos de gramática do **novo**:

*placement*<br/>
Fornece uma maneira de passar argumentos adicionais se você sobrecarregar **novo**.

*type-name*<br/>
Especifica o tipo a ser alocado; pode ser um tipo definido pelo usuário ou interno. Se a especificação de tipo for complicada, poderá ficar entre parênteses para forçar a ordem de associação.

*initializer*<br/>
Fornece um valor para o objeto inicializado. Não é possível especificar inicializadores para matrizes. O **novo** operador criará matrizes de objetos somente se a classe tem um construtor padrão.

## <a name="example"></a>Exemplo

O exemplo de código a seguir aloca uma matriz de caracteres e um objeto da classe `CName` e depois os libera.

```cpp
// expre_new_Operator.cpp
// compile with: /EHsc
#include <string.h>

class CName {
public:
   enum {
      sizeOfBuffer = 256
   };

   char m_szFirst[sizeOfBuffer];
   char m_szLast[sizeOfBuffer];

public:
   void SetName(char* pszFirst, char* pszLast) {
     strcpy_s(m_szFirst, sizeOfBuffer, pszFirst);
     strcpy_s(m_szLast, sizeOfBuffer, pszLast);
   }

};

int main() {
   // Allocate memory for the array
   char* pCharArray = new char[CName::sizeOfBuffer];
   strcpy_s(pCharArray, CName::sizeOfBuffer, "Array of characters");

   // Deallocate memory for the array
   delete [] pCharArray;
   pCharArray = NULL;

   // Allocate memory for the object
   CName* pName = new CName;
   pName->SetName("Firstname", "Lastname");

   // Deallocate memory for the object
   delete pName;
   pName = NULL;
}
```

## <a name="example"></a>Exemplo

Se você usar o formato do **novos** operador, o formulário com argumentos além do tamanho da alocação, o compilador não oferece suporte a um formulário de posicionamento da **excluir** operador se o construtor lança uma exceção. Por exemplo:

```cpp
// expre_new_Operator2.cpp
// C2660 expected
class A {
public:
   A(int) { throw "Fail!"; }
};
void F(void) {
   try {
      // heap memory pointed to by pa1 will be deallocated
      // by calling ::operator delete(void*).
      A* pa1 = new A(10);
   } catch (...) {
   }
   try {
      // This will call ::operator new(size_t, char*, int).
      // When A::A(int) does a throw, we should call
      // ::operator delete(void*, char*, int) to deallocate
      // the memory pointed to by pa2.  Since
      // ::operator delete(void*, char*, int) has not been implemented,
      // memory will be leaked when the deallocation cannot occur.

      A* pa2 = new(__FILE__, __LINE__) A(20);
   } catch (...) {
   }
}

int main() {
   A a;
}
```

## <a name="initializing-object-allocated-with-new"></a>Inicializando o objeto alocado com new

Um recurso opcional *inicializador* campo está incluído na gramática para o **novos** operador. Isso permite que os novos objetos sejam inicializados com construtores definidos pelo usuário. Para obter mais informações sobre como a inicialização é feita, consulte [inicializadores](../cpp/initializers.md). O exemplo a seguir ilustra como usar uma expressão de inicialização com o **novo** operador:

```cpp
// expre_Initializing_Objects_Allocated_with_new.cpp
class Acct
{
public:
    // Define default constructor and a constructor that accepts
    //  an initial balance.
    Acct() { balance = 0.0; }
    Acct( double init_balance ) { balance = init_balance; }
private:
    double balance;
};

int main()
{
    Acct *CheckingAcct = new Acct;
    Acct *SavingsAcct = new Acct ( 34.98 );
    double *HowMuch = new double ( 43.0 );
    // ...
}
```

Neste exemplo, o objeto `CheckingAcct` é alocado usando o **nova** operador, mas nenhuma inicialização padrão é especificado. Portanto, o construtor padrão da classe, `Acct()`, é chamado. O objeto `SavingsAcct` é então alocado da mesma maneira, mas ele é inicializado explicitamente como 34,98. Como 34,98 é do tipo **duplas**, o construtor que usa um argumento desse tipo é chamado para manipular a inicialização. Por fim, o tipo sem classe `HowMuch` é inicializado como 43,0.

Se um objeto for de um tipo de classe e essa classe tiver construtores (como no exemplo anterior), o objeto pode ser inicializado com o **novo** operador somente se uma das seguintes condições for atendida:

- Os argumentos fornecidos no inicializador concordam com os de um construtor.

- A classe tem um construtor padrão (um construtor um que pode ser chamado sem argumentos).

Nenhuma inicialização explícita por elemento pode ser feita ao alocar matrizes usando o **novo** operador; somente o construtor padrão, se estiver presente, é chamado. Ver [argumentos padrão](../cpp/default-arguments.md) para obter mais informações.

Se a alocação de memória falhar (**operador new** retorna um valor de 0), nenhuma inicialização será executada. Isso protege contra tentativas de inicialização de dados que não existem.

Assim como acontece com as chamadas de função, a ordem em que as expressões inicializadas são avaliadas não está definida. Além disso, você não deve confiar que essas expressões serão totalmente avaliadas antes que a alocação da memória seja executada. Se a alocação de memória falhar e o **novo** operador retorna zero, algumas expressões no inicializador não podem ser avaliados completamente.

## <a name="lifetime-of-objects-allocated-with-new"></a>Tempo de vida de objetos alocados com novo

Objetos alocados com o **novo** operador não são destruídos quando o escopo no qual eles são definidos é fechado. Porque o **novo** operador retorna um ponteiro para os objetos que ele atribui, o programa deve definir um ponteiro com escopo apropriado para acessar esses objetos. Por exemplo:

```cpp
// expre_Lifetime_of_Objects_Allocated_with_new.cpp
// C2541 expected
int main()
{
    // Use new operator to allocate an array of 20 characters.
    char *AnArray = new char[20];

    for( int i = 0; i < 20; ++i )
    {
        // On the first iteration of the loop, allocate
        //  another array of 20 characters.
        if( i == 0 )
        {
            char *AnotherArray = new char[20];
        }
    }

    delete [] AnotherArray; // Error: pointer out of scope.
    delete [] AnArray;      // OK: pointer still in scope.
}
```

Uma vez que o ponteiro `AnotherArray` sai do escopo no exemplo, o objeto não pode mais ser excluído.

## <a name="how-new-works"></a>Como new funciona

O *alocação-expression* — a expressão que contém o **novos** operador — faz três coisas:

- Localiza e reserva o armazenamento para que o objeto ou objetos sejam alocados. Quando essa fase for concluída, a quantidade correta de armazenamento é alocada, mas ela ainda não é um objeto.

- Inicializa o(s) objeto(s). Após a conclusão da inicialização, informações suficientes estão presentes para que o armazenamento alocado seja um objeto.

- Retorna um ponteiro para o objeto (s) de um tipo de ponteiro derivado *novo nome de tipo* ou *nome do tipo*. O programa usa esse ponteiro para acessar o objeto recentemente alocado.

O **novos** operador invoca a função **operador new**. Para matrizes de qualquer tipo e para objetos que não são do **classe**, **struct**, ou **união** tipos, uma função global, **:: operador new**, é chamado para alocar o armazenamento. Objetos de tipo de classe podem definir seus próprios **operador new** função de membro estático em uma base por classe.

Quando o compilador encontra a **novos** operador para alocar um objeto do tipo **tipo**, ele emite uma chamada para `type` **:: operador new (sizeof (** `type` **))** ou, se não definido pelo usuário **operador new** estiver definido, **:: operador new (sizeof (** `type` **))**. Portanto, o **novo** operador pode alocar a quantidade correta de memória para o objeto.

> [!NOTE]
>  O argumento **operador new** é do tipo `size_t`. Esse tipo é definido em \<Direct. h >, \<malloc >, \<h >, \<Search. h >, \<stddef. h >, \<stdio. h >, \<stdlib. h >, \<String. h >, e \<time. h >.

Uma opção na gramática permite a especificação de *posicionamento* (consulte a gramática do [operador new](../cpp/new-operator-cpp.md)). O *posicionamento* parâmetro pode ser usado apenas para implementações definidas pelo usuário **operador new**; ele permite que informações adicionais a serem passados para **operador new**. Uma expressão com um *posicionamento* campo, como `T *TObject = new ( 0x0040 ) T;` é convertido para `T *TObject = T::operator new( sizeof( T ), 0x0040 );` se a classe T tiver o operador de membro novo, caso contrário, a `T *TObject = ::operator new( sizeof( T ), 0x0040 );`.

A intenção original do *posicionamento* campo era permitir que os objetos dependentes de hardware a ser alocado em endereços especificados pelo usuário.

> [!NOTE]
>  Embora o exemplo anterior mostra apenas um argumento na *posicionamento* campo, não há nenhuma restrição de quantos argumentos extras podem ser passados para **operador new** dessa maneira.

Mesmo quando **operador new** foi definido para um tipo de classe, o operador global pode ser usado com o formulário deste exemplo:

```cpp
T *TObject =::new TObject;
```

O operador de resolução de escopo (`::`) força o uso do global **nova** operador.

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[novo e excluir operadores](../cpp/new-and-delete-operators.md)
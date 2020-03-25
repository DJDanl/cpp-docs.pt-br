---
title: Operador new (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 69fee812-1c28-4882-8fda-d1ad17860004
ms.openlocfilehash: 21e67f8d44673a15e5d3a5994597caae4cc01a2e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161120"
---
# <a name="new-operator-c"></a>Operador new (C++)

Aloca memória para um objeto ou matriz de objetos do *tipo nome* da loja gratuita e retorna um ponteiro digitado adequadamente, diferente de zero para o objeto.

> [!NOTE]
>  As C++ extensões de componente da Microsoft fornecem suporte para a **nova** palavra-chave para adicionar entradas de slot vtable. Para obter mais informações, consulte [novo (novo slot em vtable)](../extensions/new-new-slot-in-vtable-cpp-component-extensions.md)

## <a name="syntax"></a>Sintaxe

```
[::] new [placement] new-type-name [new-initializer]
[::] new [placement] ( type-name ) [new-initializer]
```

## <a name="remarks"></a>Comentários

Se não for bem-sucedida, **New** retornará zero ou lançará uma exceção; consulte [os operadores novo e excluir](../cpp/new-and-delete-operators.md) para obter mais informações. Você pode alterar esse comportamento padrão escrevendo uma rotina de tratamento de exceção personalizada e chamando a função de biblioteca de tempo de execução [_set_new_handler](../c-runtime-library/reference/set-new-handler.md) com seu nome de função como seu argumento.

Para obter informações sobre como criar um objeto no heap gerenciado, consulte [gcnew](../extensions/ref-new-gcnew-cpp-component-extensions.md).

Quando **New** é usado para alocar memória para C++ um objeto de classe, o construtor do objeto é chamado depois que a memória é alocada.

Use o operador [delete](../cpp/delete-operator-cpp.md) para desalocar a memória alocada com o operador **New** .

O exemplo a seguir aloca e depois libera uma matriz bidimensional de caracteres de tamanho `dim` por 10. Ao alocar uma matriz multidimensional, todas as dimensões, exceto a primeira, devem ser expressões de constantes que são avaliadas como valores positivos; a dimensão mais à esquerda da matriz pode ser qualquer expressão que seja avaliada como um valor positivo. Ao alocar uma matriz usando o operador **New** , a primeira dimensão pode ser zero — o **novo** operador retorna um ponteiro exclusivo.

```cpp
char (*pchar)[10] = new char[dim][10];
delete [] pchar;
```

O *nome do tipo* não pode conter **const**, **volatile**, declarações de classe ou declarações de enumeração. Dessa forma, a expressão a seguir é inválida:

```cpp
volatile char *vch = new volatile char[20];
```

O operador **New** não aloca tipos de referência porque eles não são objetos.

O operador **New** não pode ser usado para alocar uma função, mas pode ser usado para alocar ponteiros para funções. O exemplo a seguir aloca e depois libera uma matriz de sete ponteiros para funções que retornam inteiros.

```cpp
int (**p) () = new (int (*[7]) ());
delete *p;
```

Se você usar o operador **novo** sem nenhum argumento extra e compilar com a opção [/GX](../build/reference/gx-enable-exception-handling.md), [/EHA](../build/reference/eh-exception-handling-model.md)ou [o/EHS](../build/reference/eh-exception-handling-model.md) , o compilador irá gerar código para chamar Operator **delete** se o Construtor lançar uma exceção.

A lista a seguir descreve os elementos de gramática do **novo**:

*Placement*<br/>
Fornece uma maneira de passar argumentos adicionais se você sobrecarregar o **novo**.

*nome do tipo*<br/>
Especifica o tipo a ser alocado; pode ser um tipo definido pelo usuário ou interno. Se a especificação de tipo for complicada, poderá ficar entre parênteses para forçar a ordem de associação.

*initializer*<br/>
Fornece um valor para o objeto inicializado. Não é possível especificar inicializadores para matrizes. O **novo** operador criará matrizes de objetos somente se a classe tiver um construtor padrão.

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

Se você usar a nova forma de posicionamento do operador **New** , o formulário com argumentos além do tamanho da alocação, o compilador não oferecerá suporte a uma forma de posicionamento do operador **delete** se o Construtor lançar uma exceção. Por exemplo:

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

## <a name="initializing-object-allocated-with-new"></a>Inicializando objeto alocado com novo

Um campo de *inicializador* opcional é incluído na gramática para o **novo** operador. Isso permite que os novos objetos sejam inicializados com construtores definidos pelo usuário. Para obter mais informações sobre como a inicialização é feita, consulte [inicializadores](../cpp/initializers.md). O exemplo a seguir ilustra como usar uma expressão de inicialização com o **novo** operador:

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

Neste exemplo, o objeto `CheckingAcct` é alocado usando o **novo** operador, mas nenhuma inicialização padrão é especificada. Portanto, o construtor padrão da classe, `Acct()`, é chamado. O objeto `SavingsAcct` é então alocado da mesma maneira, mas ele é inicializado explicitamente como 34,98. Como 34,98 é do tipo **Double**, o construtor que usa um argumento desse tipo é chamado para manipular a inicialização. Por fim, o tipo sem classe `HowMuch` é inicializado como 43,0.

Se um objeto for de um tipo de classe e essa classe tiver construtores (como no exemplo anterior), o objeto poderá ser inicializado pelo **novo** operador somente se uma dessas condições for atendida:

- Os argumentos fornecidos no inicializador concordam com os de um construtor.

- A classe tem um construtor padrão (um construtor um que pode ser chamado sem argumentos).

Nenhuma inicialização explícita por elemento pode ser feita ao alocar matrizes usando o **novo** operador; somente o construtor padrão, se presente, é chamado. Consulte [argumentos padrão](../cpp/default-arguments.md) para obter mais informações.

Se a alocação de memória falhar (o**operador New** retorna um valor de 0), nenhuma inicialização é executada. Isso protege contra tentativas de inicialização de dados que não existem.

Assim como acontece com as chamadas de função, a ordem em que as expressões inicializadas são avaliadas não está definida. Além disso, você não deve confiar que essas expressões serão totalmente avaliadas antes que a alocação da memória seja executada. Se a alocação de memória falhar e o **novo** operador retornar zero, algumas expressões no inicializador poderão não ser completamente avaliadas.

## <a name="lifetime-of-objects-allocated-with-new"></a>Tempo de vida dos objetos alocados com o novo

Os objetos alocados com o **novo** operador não são destruídos quando o escopo no qual eles são definidos é encerrado. Como o **novo** operador retorna um ponteiro para os objetos alocados, o programa deve definir um ponteiro com escopo adequado para acessar esses objetos. Por exemplo:

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

## <a name="how-new-works"></a>Como funciona o novo

A expressão de *alocação* — a expressão que contém o operador **New** — faz três coisas:

- Localiza e reserva o armazenamento para que o objeto ou objetos sejam alocados. Quando essa fase for concluída, a quantidade correta de armazenamento é alocada, mas ela ainda não é um objeto.

- Inicializa o(s) objeto(s). Após a conclusão da inicialização, informações suficientes estão presentes para que o armazenamento alocado seja um objeto.

- Retorna um ponteiro para os objetos de um tipo de ponteiro derivado de *New-Type-Name* ou *Type-Name*. O programa usa esse ponteiro para acessar o objeto recentemente alocado.

O **novo** operador invoca o operador de função **novo**. Para matrizes de qualquer tipo e para objetos que não são dos tipos **Class**, **struct**ou **Union** , uma função global, **:: operator new**, é chamada para alocar armazenamento. Objetos de tipo de classe podem definir seu próprio **operador nova** função de membro estático em uma base por classe.

Quando o compilador encontra o **novo** operador para alocar um objeto do **tipo Type, ele**emite uma chamada para `type` **:: operator new (sizeof (** `type` **))** ou, se nenhum operador definido pelo usuário **novo** estiver definido, **:: operator new (sizeof (** `type` **))** . Portanto, o **novo** operador pode alocar a quantidade correta de memória para o objeto.

> [!NOTE]
>  O argumento para o **operador New** é do tipo `size_t`. Esse tipo é definido em \<Direct. h >, \<malloc. h >, \<Memory. h >, \<Search. h >, \<stddef. h >, \<stdio. h >, \<STDLIB. h >, \<String. h > e \<time. h >.

Uma opção na gramática permite a especificação do *posicionamento* (consulte a gramática para [novo operador](../cpp/new-operator-cpp.md)). O parâmetro de *posicionamento* só pode ser usado para implementações definidas pelo usuário do **operador New**; Ele permite que informações extras sejam passadas para o **operador novo**. Uma expressão com um campo de *posicionamento* como `T *TObject = new ( 0x0040 ) T;` é convertida em `T *TObject = T::operator new( sizeof( T ), 0x0040 );` se a classe t tiver um operador membro novo, caso contrário, para `T *TObject = ::operator new( sizeof( T ), 0x0040 );`.

A intenção original do campo de *posicionamento* era permitir que os objetos dependentes de hardware sejam alocados em endereços especificados pelo usuário.

> [!NOTE]
>  Embora o exemplo anterior mostre apenas um argumento no campo de *posicionamento* , não há nenhuma restrição de quantos argumentos extras podem ser passados para o **operador novo** dessa forma.

Mesmo quando o **operador New** tiver sido definido para um tipo de classe, o operador global poderá ser usado usando a forma deste exemplo:

```cpp
T *TObject =::new TObject;
```

O operador de resolução de escopo (`::`) força o uso do operador **New** global.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[operadores New e Delete](../cpp/new-and-delete-operators.md)

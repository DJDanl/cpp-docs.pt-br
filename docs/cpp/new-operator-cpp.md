---
title: Operador new (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 69fee812-1c28-4882-8fda-d1ad17860004
ms.openlocfilehash: ac89bf37b8aaaa9d77393b714a233f8a4c998139
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367867"
---
# <a name="new-operator-c"></a>Operador new (C++)

Aloca a memória para um objeto ou matriz de objetos de *nome de tipo* a partir do free store e retorna um ponteiro não zero digitado adequadamente para o objeto.

> [!NOTE]
> O Microsoft C++ Component Extensions oferece suporte para a **nova** palavra-chave para adicionar entradas de slot vtable. Para obter mais informações, consulte [o novo (novo slot em vtable)](../extensions/new-new-slot-in-vtable-cpp-component-extensions.md)

## <a name="syntax"></a>Sintaxe

```
[::] new [placement] new-type-name [new-initializer]
[::] new [placement] ( type-name ) [new-initializer]
```

## <a name="remarks"></a>Comentários

Se não tiver sucesso, **novos** retornos zero ou lança uma exceção; consulte [Os novos e exclusem operadores](../cpp/new-and-delete-operators.md) para obter mais informações. Você pode alterar esse comportamento padrão escrevendo uma rotina personalizada de manipulação de exceções e chamando a [função de](../c-runtime-library/reference/set-new-handler.md) biblioteca de tempo de execução _set_new_handler com o nome da função como argumento.

Para obter informações sobre como criar um objeto no heap gerenciado, consulte [gcnew](../extensions/ref-new-gcnew-cpp-component-extensions.md).

Quando **o novo** é usado para alocar memória para um objeto de classe C++, o construtor do objeto é chamado depois que a memória é alocada.

Use o operador [de exclusão](../cpp/delete-operator-cpp.md) para desalocar a memória alocada com o **novo** operador.

O exemplo a seguir aloca e depois libera uma matriz bidimensional de caracteres de tamanho `dim` por 10. Ao alocar uma matriz multidimensional, todas as dimensões, exceto a primeira, devem ser expressões de constantes que são avaliadas como valores positivos; a dimensão mais à esquerda da matriz pode ser qualquer expressão que seja avaliada como um valor positivo. Ao alocar uma matriz usando o **novo** operador, a primeira dimensão pode ser zero — o **novo** operador retorna um ponteiro único.

```cpp
char (*pchar)[10] = new char[dim][10];
delete [] pchar;
```

O *nome de tipo* não pode conter **declarações const,** **voláteis,** de classe ou declarações de enumeração. Dessa forma, a expressão a seguir é inválida:

```cpp
volatile char *vch = new volatile char[20];
```

O **novo** operador não aloca tipos de referência porque não são objetos.

O **novo** operador não pode ser usado para alocar uma função, mas pode ser usado para alocar ponteiros para funções. O exemplo a seguir aloca e depois libera uma matriz de sete ponteiros para funções que retornam inteiros.

```cpp
int (**p) () = new (int (*[7]) ());
delete *p;
```

Se você usar o **operador novo** sem quaisquer argumentos extras e compilar com a opção [/GX](../build/reference/gx-enable-exception-handling.md), [/EHa](../build/reference/eh-exception-handling-model.md), ou [/EHs,](../build/reference/eh-exception-handling-model.md) o compilador gerará código para excluir o **operador** de chamadas se o construtor lançar uma exceção.

A lista a seguir descreve os elementos gramaticais do **novo**:

*Colocação*<br/>
Fornece uma maneira de passar argumentos adicionais se você sobrecarregar **novos**.

*nome de tipo*<br/>
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

Se você usar a nova forma de colocação do **novo** operador, o formulário com argumentos além do tamanho da alocação, o compilador não suportará uma forma de colocação do operador de **exclusão** se o construtor lançar uma exceção. Por exemplo:

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

## <a name="initializing-object-allocated-with-new"></a>Inicialização de objeto alocado com novo

Um campo *de inicialização* opcional está incluído na gramática para o **novo** operador. Isso permite que os novos objetos sejam inicializados com construtores definidos pelo usuário. Para obter mais informações sobre como a inicialização é feita, consulte [Inicializadores](../cpp/initializers.md). O exemplo a seguir ilustra como usar uma expressão de inicialização com o **novo** operador:

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

Neste exemplo, o `CheckingAcct` objeto é alocado usando o **novo** operador, mas nenhuma inicialização padrão é especificada. Portanto, o construtor padrão da classe, `Acct()`, é chamado. O objeto `SavingsAcct` é então alocado da mesma maneira, mas ele é inicializado explicitamente como 34,98. Como 34.98 é do tipo **duplo,** o construtor que toma um argumento desse tipo é chamado para lidar com a inicialização. Por fim, o tipo sem classe `HowMuch` é inicializado como 43,0.

Se um objeto for de um tipo de classe e essa classe tiver construtores (como no exemplo anterior), o objeto só poderá ser inicializado pelo **novo** operador se uma dessas condições for atendida:

- Os argumentos fornecidos no inicializador concordam com os de um construtor.

- A classe tem um construtor padrão (um construtor um que pode ser chamado sem argumentos).

Nenhuma inicialização explícita por elemento pode ser feita ao alocar matrizes usando o **novo** operador; apenas o construtor padrão, se presente, é chamado. Consulte [Argumentos padrão](../cpp/default-arguments.md) para obter mais informações.

Se a alocação de memória falhar **(operador novo** retorna um valor de 0), nenhuma inicialização será realizada. Isso protege contra tentativas de inicialização de dados que não existem.

Assim como acontece com as chamadas de função, a ordem em que as expressões inicializadas são avaliadas não está definida. Além disso, você não deve confiar que essas expressões serão totalmente avaliadas antes que a alocação da memória seja executada. Se a alocação de memória falhar e o **novo** operador retornar zero, algumas expressões no inicializador podem não ser completamente avaliadas.

## <a name="lifetime-of-objects-allocated-with-new"></a>Vida útil dos objetos alocados com novos

Os objetos alocados com o **novo** operador não são destruídos quando o escopo em que são definidos é retirado. Como o **novo** operador retorna um ponteiro para os objetos que aloca, o programa deve definir um ponteiro com escopo adequado para acessar esses objetos. Por exemplo:

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

A *expressão de alocação* — a expressão que contém o **novo** operador — faz três coisas:

- Localiza e reserva o armazenamento para que o objeto ou objetos sejam alocados. Quando essa fase for concluída, a quantidade correta de armazenamento é alocada, mas ela ainda não é um objeto.

- Inicializa o(s) objeto(s). Após a conclusão da inicialização, informações suficientes estão presentes para que o armazenamento alocado seja um objeto.

- Retorna um ponteiro para o objeto(s) de um tipo de ponteiro derivado de *nome novo ou* nome de *tipo*. O programa usa esse ponteiro para acessar o objeto recentemente alocado.

O **novo** operador invoca o **novo operador**de função . Para matrizes de qualquer tipo, e para objetos que não são de **classe,** **struct**ou tipos **de união,** uma função global, **::operador novo**, é chamado para alocar armazenamento. Objetos do tipo classe podem definir sua própria função de membro estático do **operador** em uma base por classe.

Quando o compilador encontra o **novo** operador para alocar um objeto `type`do **tipo,** ele emite uma chamada para **::operador novo (sizeof)** `type` **ou,** se não for definido **um novo operador** definido pelo usuário, **::operador novo (sizeof)** `type` **.** Portanto, o **novo** operador pode alocar a quantidade correta de memória para o objeto.

> [!NOTE]
> O argumento para **operador** `size_t`novo é do tipo . Este tipo é \<definido em \<direct.h>, \<malloc.h \<>, memory.h>, \<search.h>, stddef.h>, \< \< \<stdio.h>, \<stdlib.h>, string.h> e time.h>.

Uma opção na gramática permite especificação de *colocação* (ver a Gramática para [novo Operador](../cpp/new-operator-cpp.md)). O parâmetro de *colocação* só pode ser utilizado para implementações definidas pelo usuário de **novos operadores;** permite que informações extras sejam passadas para o **operador novo**. Uma expressão com um `T *TObject = new ( 0x0040 ) T;` campo de `T *TObject = T::operator new( sizeof( T ), 0x0040 );` *colocação* como é traduzida `T *TObject = ::operator new( sizeof( T ), 0x0040 );`para se a classe T tiver o operador membro novo, caso contrário a .

A intenção original do campo de *colocação* era permitir que objetos dependentes de hardware fossem alocados em endereços especificados pelo usuário.

> [!NOTE]
> Embora o exemplo anterior mostre apenas um argumento no campo de *colocação,* não há restrição sobre quantos argumentos extras podem ser passados para **o operador novo** desta forma.

Mesmo quando **o operador novo** foi definido para um tipo de classe, o operador global pode ser usado usando a forma deste exemplo:

```cpp
T *TObject =::new TObject;
```

O operador de`::`resolução de escopo ( ) força o uso do **novo** operador global.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[novos e excluir operadores](../cpp/new-and-delete-operators.md)

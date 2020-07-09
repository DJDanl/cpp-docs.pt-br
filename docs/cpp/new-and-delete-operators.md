---
title: Operadores new e delete
description: Os operadores novo e excluir da linguagem C++ permitem o controle sobre a alocação.
ms.date: 07/07/2020
helpviewer_keywords:
- new keyword [C++]
- delete keyword [C++]
ms.openlocfilehash: e609d1fdbd4f945ab8709c554d1396100027c4c1
ms.sourcegitcommit: e17cc8a478b51739d67304d7d82422967b35f716
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/08/2020
ms.locfileid: "86127860"
---
# <a name="new-and-delete-operators"></a>Operadores `new` e `delete`

O C++ dá suporte à alocação dinâmica e à desalocação de objetos usando os [`new`](new-operator-cpp.md) [`delete`](delete-operator-cpp.md) operadores e. Esses operadores alocam memória para objetos de um pool chamado de repositório livre. O **`new`** operador chama a função especial [`operator new`](new-operator-cpp.md) e o **`delete`** operador chama a função especial [`operator delete`](delete-operator-cpp.md) .

A **`new`** função na biblioteca padrão c++ dá suporte ao comportamento especificado no padrão c++, que deve gerar uma `std::bad_alloc` exceção se a alocação de memória falhar. Se você ainda quiser a versão sem lançamento do **`new`** , vincule seu programa com o *`nothrownew.obj`* . No entanto, quando você vincula com *`nothrownew.obj`* , o padrão **`operator new`** na biblioteca C++ Standard não funciona mais.

Para obter uma lista dos arquivos de biblioteca na biblioteca de tempo de execução C e na biblioteca padrão C++, consulte [recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

## <a name="the-new-operator"></a><a id="new_operator"> </a> O `new` operador

O compilador traduz uma instrução como esta em uma chamada para a função **`operator new`** :

```cpp
char *pch = new char[BUFFER_SIZE];
```

Se a solicitação for de zero bytes de armazenamento, o **`operator new`** retornará um ponteiro para um objeto distinto. Ou seja, chamadas repetidas para **`operator new`** retornar ponteiros diferentes. Se não houver memória suficiente para a solicitação de alocação, **`operator new`** o lançará uma `std::bad_alloc` exceção. Ou, ele retornará **`nullptr`** se você tiver vinculado ao suporte de não lançamento **`operator new`** .

Você pode escrever uma rotina que tente liberar memória e tentar a alocação novamente. Para obter mais informações, consulte [`_set_new_handler`](../c-runtime-library/reference/set-new-handler.md). Para obter detalhes sobre o esquema de recuperação, consulte a seção [lidando com memória insuficiente](#handling-insufficient-memory) .

Os dois escopos para **`operator new`** funções são descritos na tabela a seguir.

### <a name="scope-for-operator-new-functions"></a>Escopo para `operator new` funções

| Operador | Escopo |
|--|--|
| **`::operator new`** | Global |
| *nome da classe***`::operator new`** | Classe |

O primeiro argumento **`operator new`** deve ser do tipo `size_t` , definido em \<stddef.h> e o tipo de retorno é sempre **`void*`** .

A **`operator new`** função global é chamada quando o **`new`** operador é usado para alocar objetos de tipos internos, objetos do tipo de classe que não contêm funções definidas pelo usuário **`operator new`** e matrizes de qualquer tipo. Quando o **`new`** operador é usado para alocar objetos de um tipo de classe onde um **`operator new`** é definido, essa classe **`operator new`** é chamada.

Uma **`operator new`** função definida para uma classe é uma função membro estática (que não pode ser virtual) que oculta a **`operator new`** função global para objetos desse tipo de classe. Considere o caso em que **`new`** é usado para alocar e definir a memória para um determinado valor:

```cpp
#include <malloc.h>
#include <memory.h>

class Blanks
{
public:
    Blanks(){}
    void *operator new( size_t stAllocateBlock, char chInit );
};
void *Blanks::operator new( size_t stAllocateBlock, char chInit )
{
    void *pvTemp = malloc( stAllocateBlock );
    if( pvTemp != 0 )
        memset( pvTemp, chInit, stAllocateBlock );
    return pvTemp;
}
// For discrete objects of type Blanks, the global operator new function
// is hidden. Therefore, the following code allocates an object of type
// Blanks and initializes it to 0xa5
int main()
{
   Blanks *a5 = new(0xa5) Blanks;
   return a5 != 0;
}
```

O argumento fornecido entre parênteses para **`new`** é passado `Blanks::operator new` como o `chInit` argumento. No entanto, a **`operator new`** função global está oculta, causando um código como o seguinte para gerar um erro:

```cpp
Blanks *SomeBlanks = new Blanks;
```

O compilador oferece suporte à matriz de membros **`new`** e **`delete`** operadores em uma declaração de classe. Por exemplo:

```cpp
class MyClass
{
public:
   void * operator new[] (size_t)
   {
      return 0;
   }
   void   operator delete[] (void*)
   {
   }
};

int main()
{
   MyClass *pMyClass = new MyClass[5];
   delete [] pMyClass;
}
```

### <a name="handling-insufficient-memory"></a>Manipulação de memória insuficiente

O teste de alocação de memória com falha pode ser feito conforme mostrado aqui:

```cpp
#include <iostream>
using namespace std;
#define BIG_NUMBER 100000000
int main() {
   int *pI = new int[BIG_NUMBER];
   if( pI == 0x0 ) {
      cout << "Insufficient memory" << endl;
      return -1;
   }
}
```

Há outra maneira de lidar com falhas de solicitações de alocação de memória. Escreva uma rotina de recuperação personalizada para lidar com essa falha e, em seguida, registre sua função chamando a [`_set_new_handler`](../c-runtime-library/reference/set-new-handler.md) função de tempo de execução.

## <a name="the-delete-operator"></a><a id="delete_operator"> </a> O `delete` operador

A memória que é alocada dinamicamente usando o **`new`** operador pode ser liberada usando o **`delete`** operador. O operador Delete chama a **`operator delete`** função, que libera a memória de volta para o pool disponível. O uso do **`delete`** operador também faz com que o destruidor de classe (se houver) seja chamado.

Há funções globais e com escopo de classe **`operator delete`** . Apenas uma **`operator delete`** função pode ser definida para uma determinada classe; se definida, ela ocultará a **`operator delete`** função global. A **`operator delete`** função global é sempre chamada para matrizes de qualquer tipo.

A **`operator delete`** função global. Existem dois formulários para as **`operator delete`** funções global e membro de classe **`operator delete`** :

```cpp
void operator delete( void * );
void operator delete( void *, size_t );
```

Somente um dos dois formulários anteriores pode estar presente para uma determinada classe. O primeiro formulário usa um único argumento do tipo **`void *`** , que contém um ponteiro para o objeto a ser desalocado. O segundo formulário, a desalocação dimensionada, usa dois argumentos: o primeiro é um ponteiro para o bloco de memória a ser desalocado e o segundo é o número de bytes a serem desalocados. O tipo de retorno de ambos os formulários é **`void`** ( **`operator delete`** não pode retornar um valor).

A intenção do segundo formulário é acelerar a pesquisa da categoria de tamanho correta do objeto a ser excluído. Essas informações geralmente não são armazenadas perto da própria alocação e provavelmente não são armazenadas em cache. O segundo formulário é útil quando uma **`operator delete`** função de uma classe base é usada para excluir um objeto de uma classe derivada.

A **`operator delete`** função é estática, portanto, não pode ser virtual. A **`operator delete`** função obedece ao controle de acesso, conforme descrito em [controle de acesso de membro](member-access-control-cpp.md).

O exemplo a seguir mostra as funções definidas pelo usuário **`operator new`** e **`operator delete`** projetadas para alocações de log e desalocações de memória:

```cpp
#include <iostream>
using namespace std;

int fLogMemory = 0;      // Perform logging (0=no; nonzero=yes)?
int cBlocksAllocated = 0;  // Count of blocks allocated.

// User-defined operator new.
void *operator new( size_t stAllocateBlock ) {
   static int fInOpNew = 0;   // Guard flag.

   if ( fLogMemory && !fInOpNew ) {
      fInOpNew = 1;
      clog << "Memory block " << ++cBlocksAllocated
          << " allocated for " << stAllocateBlock
          << " bytes\n";
      fInOpNew = 0;
   }
   return malloc( stAllocateBlock );
}

// User-defined operator delete.
void operator delete( void *pvMem ) {
   static int fInOpDelete = 0;   // Guard flag.
   if ( fLogMemory && !fInOpDelete ) {
      fInOpDelete = 1;
      clog << "Memory block " << cBlocksAllocated--
          << " deallocated\n";
      fInOpDelete = 0;
   }

   free( pvMem );
}

int main( int argc, char *argv[] ) {
   fLogMemory = 1;   // Turn logging on
   if( argc > 1 )
      for( int i = 0; i < atoi( argv[1] ); ++i ) {
         char *pMem = new char[10];
         delete[] pMem;
      }
   fLogMemory = 0;  // Turn logging off.
   return cBlocksAllocated;
}
```

O código anterior pode ser usado para detectar "vazamento de memória", ou seja, memória alocada no armazenamento gratuito, mas nunca liberada. Para detectar vazamentos, os **`new`** operadores globais e **`delete`** são redefinidos para contar a alocação e a desalocação da memória.

O compilador oferece suporte à matriz de membros **`new`** e **`delete`** operadores em uma declaração de classe. Por exemplo:

```cpp
// spec1_the_operator_delete_function2.cpp
// compile with: /c
class X  {
public:
   void * operator new[] (size_t) {
      return 0;
   }
   void operator delete[] (void*) {}
};

void f() {
   X *pX = new X[5];
   delete [] pX;
}
```

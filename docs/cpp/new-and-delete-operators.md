---
title: Operadores new e delete
ms.date: 11/19/2019
helpviewer_keywords:
- new keyword [C++]
- delete keyword [C++]
ms.assetid: fa721b9e-0374-4f04-bb87-032ea775bcc8
ms.openlocfilehash: 2fd665ce2570bbe7750684057cdf7f517f6f64f3
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445450"
---
# <a name="new-and-delete-operators"></a>Operadores new e delete

C++dá suporte à alocação dinâmica e à desalocação de objetos usando os operadores [New](new-operator-cpp.md) e [delete](delete-operator-cpp.md) . Esses operadores alocam memória para objetos de um pool chamado de repositório livre. O operador **New** chama o [operador](new-operator-cpp.md)de função especial New e o operador **delete** chama a função especial [delete do operador](delete-operator-cpp.md).

A **nova** função na biblioteca C++ padrão dá suporte ao comportamento especificado no C++ padrão, que deve gerar uma exceção std:: bad_alloc se a alocação de memória falhar. Se você ainda quiser a versão sem lançamento do **novo**, vincule seu programa com nothrownew. obj. No entanto, quando você vincula com nothrownew. obj, o **operador** padrão novo C++ na biblioteca padrão não funciona mais.

Para obter uma lista dos arquivos de biblioteca que compõem a biblioteca de tempo de C++ execução C e a biblioteca padrão, consulte [recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

##  <a id="new_operator"> </a> O novo operador

Quando uma instrução como a seguinte é encontrada em um programa, ela se traduz em uma chamada para o operador de função **novo**:

```cpp
char *pch = new char[BUFFER_SIZE];
```

Se a solicitação for de zero bytes de armazenamento, o **operador New** retornará um ponteiro para um objeto distinto (ou seja, chamadas repetidas para o **operador New** retornam ponteiros diferentes). Se não houver memória suficiente para a solicitação de alocação, o **operador New** lançará uma exceção de `std::bad_alloc` ou retornará **nullptr** se você tiver vinculado em um operador de não lançamento **novo** suporte.

Você pode escrever uma rotina que tente liberar memória e tentar a alocação novamente; consulte [_set_new_handler](../c-runtime-library/reference/set-new-handler.md) para obter mais informações. Para obter mais detalhes sobre o esquema de recuperação, consulte a seção lidando com memória insuficiente neste tópico.

Os dois escopos para funções **operador novas** são descritos na tabela a seguir.

### <a name="scope-for-operator-new-functions"></a>Escopo para funções novas do operador

|Operador|Escopo|
|--------------|-----------|
|**: operador novo**|Global|
|*Class-Name* **:: operador novo**|Classe|

O primeiro argumento para o **operador New** deve ser do tipo `size_t` (um tipo definido em \<stddef. h >) e o tipo de retorno é sempre **nulo** <strong>\*</strong>.

A função **operador global New** é chamada quando o operador **New** é usado para alocar objetos de tipos internos, objetos do tipo de classe que não contêm funções de **operador novas** e matrizes de qualquer tipo. Quando o operador **New** é usado para alocar objetos de um tipo de classe em que um **operador New** é definido, o **operador New** da classe é chamado.

Uma **nova** função de operador definida para uma classe é uma função membro estática (que não pode, portanto, ser virtual) que oculta a **nova função operador** global para objetos desse tipo de classe. Considere o caso em que **New** é usado para alocar e definir a memória para um determinado valor:

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

O argumento fornecido entre parênteses para **New** é passado para `Blanks::operator new` como o argumento `chInit`. No entanto, a função global **Operator New** é oculta, causando um código como o seguinte para gerar um erro:

```cpp
Blanks *SomeBlanks = new Blanks;
```

O compilador dá suporte aos operadores **New** e **delete** de membros em uma declaração de classe. Por exemplo:

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

Há outra maneira de lidar com falhas nas solicitações de alocação de memória. Escreva uma rotina de recuperação personalizada para lidar com essa falha e, em seguida, registre sua função chamando o [_set_new_handler](../c-runtime-library/reference/set-new-handler.md) função de tempo de execução.

##  <a id="delete_operator"> </a> O operador Delete

A memória que é alocada dinamicamente usando o operador **New** pode ser liberada usando o operador **delete** . O operador Delete chama a função **Operator Delete** , que libera a memória de volta para o pool disponível. O uso do operador **delete** também faz com que o destruidor de classe (se houver) seja chamado.

Há funções de **exclusão de operador** global e com escopo de classe. Somente uma função de **exclusão de operador** pode ser definida para uma determinada classe; Se definido, ele ocultará a função global do **operador Delete** . A função global de **operador Delete** é sempre chamada para matrizes de qualquer tipo.

A função global **Operator Delete** . Existem dois formulários para as funções excluir **operador** global e operador de membro de classe **delete** :

```cpp
void operator delete( void * );
void operator delete( void *, size_t );
```

Somente um dos dois formulários anteriores pode estar presente para uma determinada classe. O primeiro formulário usa um único argumento do tipo `void *`, que contém um ponteiro para o objeto a ser desalocado. A segunda forma – a desalocação dimensionada — usa dois argumentos, o primeiro deles é um ponteiro para o bloco de memória a ser desalocado e o segundo é o número de bytes a serem desalocados. O tipo de retorno de ambos os formulários é **void** (o**operador Delete** não pode retornar um valor).

A intenção do segundo formulário é acelerar a pesquisa da categoria de tamanho correta do objeto a ser excluído, o que geralmente não é armazenado próximo à alocação e provavelmente não armazenado em cache. O segundo formulário é útil quando uma função de **exclusão de operador** de uma classe base é usada para excluir um objeto de uma classe derivada.

A função de **exclusão do operador** é estática; Portanto, não pode ser virtual. A função de **exclusão do operador** obedece ao controle de acesso, conforme descrito em [controle de acesso de membro](member-access-control-cpp.md).

O exemplo a seguir mostra o operador definido pelo usuário **novo** e funções de **exclusão de operador** criadas para alocações de log e desalocações de memória:

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

O código anterior pode ser usado para detectar "vazamento de memória” – ou seja, a memória atribuída no repositório livre, mas nunca liberada. Para executar essa detecção, os operadores global **New** e **delete** são redefinidos para contar a alocação e a desalocação da memória.

O compilador dá suporte aos operadores **New** e **delete** de membros em uma declaração de classe. Por exemplo:

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

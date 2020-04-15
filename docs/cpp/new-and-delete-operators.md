---
title: Operadores new e delete
ms.date: 11/19/2019
helpviewer_keywords:
- new keyword [C++]
- delete keyword [C++]
ms.assetid: fa721b9e-0374-4f04-bb87-032ea775bcc8
ms.openlocfilehash: fd170c1500e2d80879fdd89f7d825930189ae942
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367881"
---
# <a name="new-and-delete-operators"></a>Operadores new e delete

C++ suporta alocação dinâmica e desalocação de objetos usando os [novos](new-operator-cpp.md) e [excluir](delete-operator-cpp.md) operadores. Esses operadores alocam memória para objetos de um pool chamado de repositório livre. O **novo** operador chama o operador de função especial [de novo](new-operator-cpp.md), e o operador de **exclusão** chama o operador de função especial [de excluir](delete-operator-cpp.md).

A **nova** função na Biblioteca Padrão C++ suporta o comportamento especificado no padrão C++, que é lançar uma exceção std::bad_alloc se a alocação de memória falhar. Se você ainda quiser a versão não-lançamento do **novo,** vincule seu programa com nothrownew.obj. No entanto, quando você se vincula com nothrownew.obj, o operador padrão **novo** na Biblioteca Padrão C++ não funciona mais.

Para obter uma lista dos arquivos da biblioteca que compõem a Biblioteca C Runtime e a Biblioteca Padrão C++, consulte [CRT Library Features](../c-runtime-library/crt-library-features.md).

## <a name="the-new-operator"></a><a id="new_operator"> </a> O novo operador

Quando uma declaração como a seguinte é encontrada em um programa, ela se traduz em uma chamada para o operador de função **novo**:

```cpp
char *pch = new char[BUFFER_SIZE];
```

Se a solicitação for para zero bytes de armazenamento, **o operador novo** retorna um ponteiro para um objeto distinto (ou seja, chamadas repetidas para operador **novo** retorno diferentes ponteiros). Se houver memória insuficiente para a solicitação `std::bad_alloc` de alocação, o operador **nova** lançará uma exceção ou retorna **nullptr** se você tiver vinculado em novo suporte de operador não-throw. **operator new**

Você pode escrever uma rotina que tenta liberar a memória e tentar novamente a alocação; consulte [_set_new_handler](../c-runtime-library/reference/set-new-handler.md) para obter mais informações. Para obter mais detalhes sobre o esquema de recuperação, consulte a seção Manipulação de memória insuficiente deste tópico.

Os dois escopos para **as novas** funções do operador estão descritos na tabela a seguir.

### <a name="scope-for-operator-new-functions"></a>Escopo para novas funções do operador

|Operador|Escopo|
|--------------|-----------|
|**::operador novo**|Global|
|*nome de classe* **::operador novo**|Classe|

O primeiro argumento para **o novo operador** deve ser do tipo `size_t` (um tipo definido \<em stddef.h>), e o tipo de retorno é sempre **nulo** <strong>\*</strong>.

A **nova** função do operador global é chamada quando o **novo** operador é usado para alocar objetos de tipos incorporados, objetos do tipo de classe que não contêm novas funções do **operador** definidas pelo usuário e matrizes de qualquer tipo. Quando o **novo** operador é usado para alocar objetos de um tipo de classe onde um **novo operador** é definido, o **novo operador** dessa classe é chamado.

Uma nova função do **operador** definida para uma classe é uma função de membro estático (que não pode, portanto, ser virtual) que oculta a nova função do **operador** global para objetos desse tipo de classe. Considere o caso em que **o novo** é usado para alocar e definir a memória para um determinado valor:

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

O argumento fornecido entre parênteses `Blanks::operator new` ao `chInit` **novo** é passado para o argumento. No entanto, a nova função do **operador** global está oculta, fazendo com que códigos como o seguinte gerem um erro:

```cpp
Blanks *SomeBlanks = new Blanks;
```

O compilador suporta **a matriz** de membros nova e **exclui** os operadores em uma declaração de classe. Por exemplo:

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

### <a name="handling-insufficient-memory"></a>Manuseio de memória insuficiente

Os testes para alocação de memória com falha podem ser feitos conforme mostrado aqui:

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

Há outra maneira de lidar com solicitações de alocação de memória com falha. Escreva uma rotina de recuperação personalizada para lidar com essa falha e registre sua função chamando a função de tempo de execução [_set_new_handler.](../c-runtime-library/reference/set-new-handler.md)

## <a name="the-delete-operator"></a><a id="delete_operator"> </a> O operador de exclusão

A memória que é alocada dinamicamente usando o **novo** operador pode ser liberada usando o operador **de exclusão.** O operador de exclusão chama a função **de exclusão** do operador, que libera a memória de volta para o pool disponível. O uso do operador **de exclusão** também faz com que o destruidor de classes (se houver um) seja chamado.

Existem funções de **exclusão** de operadores globais e com escopo de classe. Apenas uma função **de exclusão do operador** pode ser definida para uma determinada classe; se definido, ele oculta a função de **exclusão** do operador global. A função **de exclusão do operador** global é sempre chamada para matrizes de qualquer tipo.

A função **de exclusão do operador** global. Existem dois formulários para que o operador global **exclua** e **exclua** funções do operador de classe:

```cpp
void operator delete( void * );
void operator delete( void *, size_t );
```

Apenas uma das duas formas anteriores pode estar presente para uma determinada classe. A primeira forma tem um `void *`único argumento de tipo, que contém um ponteiro para o objeto para desalocar. O segundo formulário — desalocação de tamanho — leva dois argumentos, o primeiro é um ponteiro para o bloco de memória para desalocar e o segundo é o número de bytes para desalocar. O tipo de devolução de ambos os formulários é **nulo** (**a exclusão do operador** não pode retornar um valor).

A intenção do segundo formulário é acelerar a busca pela categoria de tamanho correto do objeto a ser excluído, que muitas vezes não é armazenado perto da alocação em si e provavelmente sem cache. O segundo formulário é útil quando uma função de **exclusão** de um operador de uma classe base é usada para excluir um objeto de uma classe derivada.

A função **de exclusão do operador** é estática; portanto, não pode ser virtual. A função **de exclusão do operador** obedece ao controle de acesso, conforme descrito no Controle de Acesso ao [Membro](member-access-control-cpp.md).

O exemplo a seguir mostra **funções de exclusão de operadoras** definidas pelo usuário e **de exclusão** de operadoras projetadas para registrar alocações e desalocações de memória:

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

O código anterior pode ser usado para detectar "vazamento de memória” – ou seja, a memória atribuída no repositório livre, mas nunca liberada. Para realizar essa detecção, os operadores **globais novos** e **excluídos** são redefinidos para contar a alocação e a desalocação da memória.

O compilador suporta **a matriz** de membros nova e **exclui** os operadores em uma declaração de classe. Por exemplo:

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

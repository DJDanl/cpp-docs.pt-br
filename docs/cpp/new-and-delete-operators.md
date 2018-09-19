---
title: novo e excluir operadores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- delete_cpp
- new
dev_langs:
- C++
helpviewer_keywords:
- new keyword [C++], dynamic allocation of objects
- nothrownew.obj
- delete keyword [C++], syntax
ms.assetid: fa721b9e-0374-4f04-bb87-032ea775bcc8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b205be3c2417453faa54c9d24ac28216ee0af5cf
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060520"
---
# <a name="new-and-delete-operators"></a>Operadores new e delete

C++ oferece suporte a alocação dinâmica e desalocação de objetos usando o [novos](../cpp/new-operator-cpp.md) e [excluir](../cpp/delete-operator-cpp.md) operadores. Esses operadores alocam memória para objetos de um pool chamado de repositório livre. O **novos** operador chama a função especial [operador new](../cpp/new-operator-cpp.md)e o **excluir** operador chama a função especial [operador delete](../cpp/delete-operator-cpp.md).

O **novo** função na biblioteca padrão C++ oferece suporte o comportamento especificado no padrão do C++, que deve lançar uma exceção std:: bad_alloc se a alocação de memória falhar. Se você ainda desejar a versão de não lançamento do **novo**, vincule seu programa com nothrownew. No entanto, quando você vincular com nothrownew, o padrão **operador new** na biblioteca padrão C++ não funciona mais.

Para obter uma lista dos arquivos de biblioteca que compõem a biblioteca de tempo de execução do C e a biblioteca padrão C++, consulte [recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

##  <a id="new_operator"> </a> O novo operador

Quando uma instrução como a seguinte é encontrada em um programa, ele converte em uma chamada para a função **operador new**:

```cpp
char *pch = new char[BUFFER_SIZE];
```

Se a solicitação for para zero bytes de armazenamento, **operador new** retorna um ponteiro para um objeto distinto (ou seja, chamadas repetidas para **operador new** retornam ponteiros diferentes). Se não houver memória insuficiente para a solicitação de alocação **operador new** lança uma exceção std:: bad_alloc ou retorna **nullptr** se você tiver vinculado não jogando **operador new** dão suporte.

Você pode escrever uma rotina que tenta liberar a memória e repetir a alocação; ver [set_new_handler](../c-runtime-library/reference/set-new-handler.md) para obter mais informações. Para obter mais detalhes sobre o esquema de recuperação, consulte a seção de memória insuficiente do tratamento deste tópico.


Os dois escopos para **operador new** funções são descritas na tabela a seguir.

### <a name="scope-for-operator-new-functions"></a>Escopo para funções operator new

|Operador|Escopo|
|--------------|-----------|
|**:: operador new**|Global|
|*nome da classe* **:: operador new**|Classe|

O primeiro argumento para **operador new** deve ser do tipo `size_t` (um tipo definido no \<stddef. h >), e o tipo de retorno é sempre **void** <strong>\*</strong>.

Global **operador new** função é chamada quando o **novos** operador é usado para alocar objetos de tipos internos, objetos do tipo de classe que não contêm definidos pelo usuário **operador new** funções e matrizes de qualquer tipo. Quando o **novos** operador é usado para alocar objetos de um tipo de classe onde um **operador new** for definido, essa classe **operador new** é chamado.

Uma **operador new** função definida para uma classe é uma função de membro estático (que não é possível, portanto, ser virtual) que oculta global **operador new** função para objetos desse tipo de classe. Considere o caso em que **novo** é usado para alocar e definir memória para um determinado valor:

```cpp
// spec1_the_operator_new_function1.cpp
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

O argumento fornecido entre parênteses para **novos** é passado para `Blanks::operator new` como o `chInit` argumento. No entanto, a global **operador new** função é ocultada, fazendo com que o código como o seguinte para gerar um erro:

```cpp
Blanks *SomeBlanks = new Blanks;
```

Em tipos do Visual C++ 5.0 e anterior, sem classe e todas as matrizes (independentemente de serem de **classe** tipo) alocados usando o **novos** operador sempre usado global **operador new** função.

Começando com o Visual C++ 5.0, o compilador dá suporte a matriz de membros **novos** e **excluir** operadores em uma declaração de classe. Por exemplo:

```cpp
// spec1_the_operator_new_function2.cpp
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

Os testes para alocação de memória com falha podem ser feitos com código, como este:

```cpp
// insufficient_memory_conditions.cpp
// compile with: /EHsc
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

Há outra maneira de lidar com solicitações de alocação de memória com falha: escrever uma rotina de recuperação personalizada para lidar com essa falha, em seguida, registre sua função chamando o [set_new_handler](../c-runtime-library/reference/set-new-handler.md) função de tempo de execução.

##  <a id="delete_operator"> </a> O operador delete

Memória alocada dinamicamente usando o **novos** operador pode ser liberado usando o **excluir** operador. O operador delete chama a **operador delete** função, que libera memória para o pool disponível. Usando o **excluir** operador também faz com que o destruidor da classe (se houver) a ser chamado.

Há global e do escopo da classe **operador delete** funções. Somente um **operador delete** função pode ser definida para uma determinada classe; se definido, ele oculta global **operador delete** função. Global **operador delete** função sempre é chamada para matrizes de qualquer tipo.

Global **operador delete** função. Existem duas formas para global **operador delete** e membro da classe **operador delete** funções:

```cpp
void operator delete( void * );
void operator delete( void *, size_t );
```

Apenas uma das duas formas anteriores pode estar presente para uma determinada classe. A primeira forma usa um único argumento do tipo `void *`, que contém um ponteiro para o objeto a ser desalocado. O segundo formulário — a desalocação de tamanho — leva dois argumentos, o primeiro deles é um ponteiro para o bloco de memória para desalocar e o segundo é o número de bytes a ser desalocado. É o tipo de retorno de ambos os formulários **void** (**operador delete** não pode retornar um valor).

A intenção a segunda forma é para acelerar a pesquisa para a categoria de tamanho correto do objeto a ser excluído, que geralmente não é armazenado perto a alocação em si e provavelmente eliminado do cache; a segunda forma é particularmente útil quando um **operador delete** função de uma classe base é usada para excluir um objeto de uma classe derivada.

O **operador delete** função é estática; portanto, não pode ser virtual. O **operador delete** função obedece o controle de acesso, conforme descrito em [controle de acesso de membro](../cpp/member-access-control-cpp.md).

O exemplo a seguir mostra o definido pelo usuário **operador new** e **operador delete** funções projetadas para registrar alocações e Desalocações de memória:

```cpp
// spec1_the_operator_delete_function1.cpp
// compile with: /EHsc
// arguments: 3
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

O código anterior pode ser usado para detectar "vazamento de memória” – ou seja, a memória atribuída no repositório livre, mas nunca liberada. Para executar essa detecção global **novos** e **excluir** operadores são redefinidos para contar a alocação e desalocação de memória.

Começando com o Visual C++ 5.0, o compilador dá suporte a matriz de membros **novos** e **excluir** operadores em uma declaração de classe. Por exemplo:

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
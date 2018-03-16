---
title: novo e excluir operadores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3af862988502ac0d1908c466aae5e62b753509c2
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="new-and-delete-operators"></a>Operadores new e delete

C++ dá suporte à alocação dinâmica e a desalocação de objetos usando o [novo](../cpp/new-operator-cpp.md) e [excluir](../cpp/delete-operator-cpp.md) operadores. Esses operadores alocam memória para objetos de um pool chamado de repositório livre. O `new` operador chama a função especial [operador novo](../cpp/new-operator-cpp.md)e o `delete` operador chama a função especial [operador delete](../cpp/delete-operator-cpp.md).  
  
 O `new` o comportamento especificado no C++ padrão, que é lançar uma exceção std:: bad_alloc se a alocação de memória não oferece suporte a função na biblioteca padrão C++. Se ainda quiser que a versão de não lançamento do `new`, vincular seu programa com nothrownew.obj. No entanto, quando você vincula com nothrownew.obj, o padrão `operator new` na biblioteca padrão C++ não funciona mais.  
  
 Para obter uma lista dos arquivos de biblioteca que compõem a biblioteca de tempo de execução do C e a biblioteca padrão C++, consulte [recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).  
  
##  <a id="new_operator"> </a> O novo operador  
 Quando uma instrução como a seguinte é encontrada em um programa, ela converte-se em uma chamada para a função `operator new`:  
  
```cpp  
char *pch = new char[BUFFER_SIZE];  
```  
  
Se a solicitação for para zero bytes de armazenamento, **operador novo** retorna um ponteiro para um objeto distinto (ou seja, repetidas chamadas para **operador novo** retornam ponteiros diferentes). Se não houver memória suficiente para a solicitação de alocação, **operador novo** lança uma exceção std:: bad_alloc ou retorna **nullptr** se você tiver vinculado não lançar `operator new` suporte.  
  
Você pode escrever uma rotina que tente liberar memória e tente novamente a alocação; consulte [set_new_handler](../c-runtime-library/reference/set-new-handler.md) para obter mais informações. Para obter mais detalhes sobre o esquema de recuperação, consulte a seção de memória insuficiente de tratamento deste tópico.  

  
Os dois escopos para funções `operator new` são descritos na tabela a seguir.  
  
### <a name="scope-for-operator-new-functions"></a>Escopo para funções operator new  
  
|Operador|Escopo|  
|--------------|-----------|  
|**:: operador novo**|Global|  
|*nome da classe* **:: operador novo**|Classe|  
  
 O primeiro argumento para **operador novo** deve ser do tipo **size_t** (um tipo definido em \<stddef.h >), e o tipo de retorno é sempre **void \***  .  
  
 Global **operador novo** função é chamada quando o **novo** operador é usado para alocar objetos dos tipos internos, objetos de tipo de classe que não contêm definidas pelo usuário **novo operador** funções e matrizes de qualquer tipo. Quando o **novo** operador é usado para alocar os objetos de um tipo de classe onde um **operador novo** for definida, essa classe **operador novo** é chamado.  
  
 Um **operador novo** função definida para uma classe é uma função de membro estático (que não é possível, portanto, ser virtual) que oculta global **operador novo** função para objetos desse tipo de classe. Considere o caso onde **novo** é usada para alocar e definir a memória para um determinado valor:  
  
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
  
 O argumento fornecido entre parênteses para **novo** é passado para `Blanks::operator new` como o `chInit` argumento. No entanto, global **operador novo** função é ocultada, fazendo com que o código como o seguinte para gerar um erro:  
  
```cpp  
Blanks *SomeBlanks = new Blanks;  
```  
  
 Em tipos do Visual C++ nonclass 5.0 e anterior e todas as matrizes (independentemente de se eles foram de **classe** tipo) alocado usando o **novo** operador sempre usado global **novo operador** função.  
  
 A partir do Visual C++ 5.0, o compilador dá suporte a matriz de membros **novo** e **excluir** operadores em uma declaração de classe. Por exemplo:  
  
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
  
### <a name="handling-insufficient-memory"></a>Tratamento de memória insuficiente  
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
  
 Há outras maneiras de tratar as solicitações de alocação de memória com falha: escrever uma rotina de recuperação personalizada para tratar essa falha, em seguida, registrar a função chamando o [set_new_handler](../c-runtime-library/reference/set-new-handler.md) função do tempo de execução.  
  
##  <a id="delete_operator"> </a> O operador delete  
 Memória alocada dinamicamente usando a **novo** operador pode ser liberado usando a **excluir** operador. As chamadas de operador delete a **operador delete** função, o que libera memória para o pool disponível. Usando o **excluir** operador também faz com que o destruidor de classe (se houver) a ser chamado.  
  
 Há global e escopo de classe **operador delete** funções. Apenas uma **operador delete** função pode ser definida para uma determinada classe; se definido, ele oculta global **operador delete** função. Global **operador delete** função sempre é chamada para matrizes de qualquer tipo.  
  
 Global **operador delete** função. Existem duas formas para global **operador delete** e membro de classe **operador delete** funções:  
  
```cpp  
void operator delete( void * );  
void operator delete( void *, size_t );  
```  
  
 Somente um dos dois formulários de anterior pode estar presente para uma determinada classe. O primeiro formulário aceita um único argumento de tipo **void \*** , que contém um ponteiro para o objeto a ser desalocada. O segundo formulário — tamanho desalocação — leva dois argumentos, o primeiro deles é um ponteiro para o bloco de memória para desalocar e o segundo é o número de bytes a ser desalocada. É o tipo de retorno de ambos os formulários `void` (**operador delete** não pode retornar um valor).  
  
 A intenção do segundo formulário é para acelerar a pesquisa para a categoria de tamanho correto do objeto a ser excluído, que geralmente não é armazenado próximos a alocação em si e provavelmente eliminado do cache; o segundo formulário é particularmente útil quando um **operador delete** função de uma classe base é usada para excluir um objeto de uma classe derivada.  
  
 O **operador delete** função é estática; portanto, não pode ser virtual. O `operator delete` função obedece ao controle de acesso, conforme descrito em [controle de acesso de membro](../cpp/member-access-control-cpp.md).  
  
 O exemplo a seguir mostra definidos pelo usuário **operador novo** e **operador delete** funções projetadas para registrar as alocações e Desalocações de memória:  
  
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
  
 O código anterior pode ser usado para detectar "vazamento de memória” – ou seja, a memória atribuída no repositório livre, mas nunca liberada. Para executar essa detecção global **novo** e **excluir** operadores são redefinidos para contagem de alocação e desalocação de memória.  
  
 A partir do Visual C++ 5.0, o compilador dá suporte a matriz de membros **novo** e **excluir** operadores em uma declaração de classe. Por exemplo:  
  
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


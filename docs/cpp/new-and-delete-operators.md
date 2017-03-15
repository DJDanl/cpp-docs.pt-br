---
title: "Operadores new e delete | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "delete_cpp"
  - "new_cpp"
  - "new"
  - "delete"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave delete [C++], sintaxe"
  - "palavra-chave new [C++], alocação dinâmica de objetos"
  - "nothrownew.obj"
ms.assetid: fa721b9e-0374-4f04-bb87-032ea775bcc8
caps.latest.revision: 16
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores new e delete
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

C\+\+ oferece suporte a alocação dinâmica e desalocação de objetos usando os operadores [new](../cpp/new-operator-cpp.md) e [delete](../cpp/delete-operator-cpp.md).  Esses operadores alocam memória para objetos de um pool chamado de repositório livre.  O operador `new` chama a função especial [operator new](../misc/operator-new-function.md) e o operador `delete` chama a função especial [operator delete](../Topic/operator%20delete%20Function.md).  
  
 No [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] .NET 2002, a função `new`na biblioteca padrão C\+\+ oferecerá suporte ao comportamento especificado no padrão do C\+\+, que é gerar uma exceção std::bad\_alloc se a alocação de memória falhar.  
  
 A função `new` da biblioteca em tempo de execução do C também gerará uma exceção std::bad\_alloc se a alocação de memória falhar.  
  
 Se você ainda desejar a versão sem geração de `new` para a biblioteca em tempo de execução de C, vincule seu programa com nothrownew.obj.  No entanto, quando você vincular com nothrownew.obj, `new` na biblioteca padrão C\+\+ não funcionará.  
  
 Para obter uma lista dos arquivos de biblioteca que compõem a biblioteca de tempo de execução do C e a biblioteca C\+\+ padrão, consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).  
  
## O novo operador  
 Quando uma instrução como a seguinte é encontrada em um programa, ela converte\-se em uma chamada para a função `operator new`:  
  
```  
char *pch = new char[BUFFER_SIZE];  
```  
  
 Se a solicitação for para zero bytes de armazenamento, **novo operador** retorna um ponteiro para um objeto distinto \(ou seja, chamadas repetidas para **novo operador** retornam ponteiros diferentes\).  Se não houver memória suficiente para a solicitação de alocação, **novo operador** retorna **nulo** ou gera uma exceção \(consulte [o novo e excluir operadores](../cpp/new-and-delete-operators.md) para obter mais informações\).  
  
 Você pode escrever uma rotina que tenta liberar a memória e repetir a alocação; consulte [\_set\_new\_handler](../Topic/_set_new_handler.md) para obter mais informações.  Para obter mais detalhes no esquema de recuperação, consulte o seguinte tópico, [Administrando condições de memória insuficientes](../Topic/Handling%20Insufficient%20Memory%20Conditions.md).  
  
 Os dois escopos para funções `operator new` são descritos na tabela a seguir.  
  
### Escopo para funções operator new  
  
|Operador|Escopo|  
|--------------|------------|  
|**::operator new**|Global|  
|*class\-name* **::operator new**|Classe|  
  
 O primeiro argumento para **novo operador** deve ser do tipo **size\_t** \(um tipo definido em STDDEF. H\) e o tipo de retorno é sempre **void \***.  
  
 Global **novo operador** função é chamada quando o **novo** operador é usado para alocar objetos dos tipos internos, objetos de tipo de classe que não contêm definido pelo usuário **novo operador** funções e matrizes de qualquer tipo.  Quando o **novo** operador é usado para alocar objetos de um tipo de classe onde um **novo operador** for definida, essa classe **novo operador** é chamado.  
  
 Um **novo operador** função definida para uma classe é uma função de membro estático \(que não pode, portanto, ser virtual\) que oculta global **novo operador** função para objetos desse tipo de classe.  Considere o caso em que **new** é usado para alocar e definir memória para um valor específico:  
  
```  
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
  
 O argumento fornecido entre parênteses para **new** é passado para `Blanks::operator new` como o argumento `chInit`.  No entanto, a global **novo operador** função é ocultada, fazendo com que o código como o seguinte para gerar um erro:  
  
```  
Blanks *SomeBlanks = new Blanks;  
```  
  
 Em tipos do Visual C\+\+ sem classe 5.0 e anterior e todas as matrizes \(independentemente de serem de **classe** tipo\) alocados usando o **novo** operador usado sempre global **novo operador** função.  
  
 A partir do Visual C\+\+ 5.0, o compilador oferece suporte aos operadores **new** e **delete** da matriz de membros em uma declaração de classe.  Por exemplo:  
  
```  
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
  
### Manipulação de memória insuficiente  
 Os testes para alocação de memória com falha podem ser feitos com código, como este:  
  
```  
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
  
 Há outra maneira de resolver solicitações de alocação de memória com falha: escrever uma rotina de recuperação personalizada para resolver essa falha e depois registrar a função chamando a função em tempo de execução [\_set\_new\_handler](../Topic/_set_new_handler.md).  
  
## O operador delete  
 A memória que é atribuída dinamicamente usando o operador **new** pode ser liberada usando o operador **delete**.  O operador delete chama o **operador delete** função, que libera memória no pool disponível.  Usar o operador **delete** também faz com que o destruidor da classe \(se houver\) seja chamado.  
  
 Há global e do escopo da classe **operador delete** funções.  Apenas uma **operador delete** função pode ser definida para uma determinada classe; se definida, oculta global **operador delete** função.  Global **operador delete** função sempre é chamada para matrizes de qualquer tipo.  
  
 Global **operador delete** função, se declarada, usa um único argumento do tipo **void \***, que contém um ponteiro para o objeto a ser desalocado.  O tipo de retorno é `void` \(**operador delete** não pode retornar um valor\).  Existem duas formas de membro de classe **operador delete** funções:  
  
```  
void operator delete( void * );  
void operator delete( void *, size_t );  
```  
  
 Somente uma das duas variantes de precedência pode estar presente para uma determinada classe.  A primeira forma funciona conforme descrito para `operator delete` global.  A segunda forma usa dois argumentos, o primeiro deles é um ponteiro para o bloco de memória a ser desalocado e o segundo é o número de bytes a ser desalocado.  A segunda forma é particularmente útil quando um **operador delete** função de uma classe base é usada para excluir um objeto de uma classe derivada.  
  
 O **operador delete** função é estática; portanto, não pode ser virtual.  A função `operator delete` obedece o controle de acesso, conforme descrito em [Controle de acesso de membros](../cpp/member-access-control-cpp.md).  
  
 O exemplo a seguir mostra definidos pelo usuário **novo operador** e **operador delete** funções projetadas para registrar alocações e Desalocações de memória:  
  
```  
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
  
 O código anterior pode ser usado para detectar "vazamento de memória” – ou seja, a memória atribuída no repositório livre, mas nunca liberada.  Para executar essa detecção, os operadores **new** e **delete** globais são redefinidos para contar a alocação e a desalocação de memória.  
  
 A partir do Visual C\+\+ 5.0, o compilador oferece suporte aos operadores **new** e **delete** da matriz de membros em uma declaração de classe.  Por exemplo:  
  
```  
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
  
## Consulte também  
 [Funções de membro especiais](../misc/special-member-functions-cpp.md)
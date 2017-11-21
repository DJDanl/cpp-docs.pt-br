---
title: Operador New (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: new keyword [C++]
ms.assetid: 69fee812-1c28-4882-8fda-d1ad17860004
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 05b83a284dcf599890985f1f01d8327ac5ef75e4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="new-operator-c"></a>Operador new (C++)
Aloca memória para um objeto ou uma matriz de objetos do *nome do tipo* de livre armazenar e retorna um ponteiro tipado adequadamente, diferente de zero para o objeto.  
  
> [!NOTE]
>  As Extensões de Componentes do Microsoft C++ fornecem suporte para a palavra-chave `new` a fim de adicionar entradas de slot a vtable. Para obter mais informações, consulte [novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[::] new [placement] new-type-name [new-initializer]  
[::] new [placement] ( type-name ) [new-initializer]  
```  
  
## <a name="remarks"></a>Comentários  
 Se não houver êxito, **novo** retorna zero ou gera uma exceção; consulte [o novo e excluir operadores](../cpp/new-and-delete-operators.md) para obter mais informações. Você pode alterar esse comportamento padrão ao escrever uma rotina de tratamento de exceções personalizada e chamar o [set_new_handler](../c-runtime-library/reference/set-new-handler.md) função de biblioteca de tempo de execução com o nome da função como seu argumento.  
  
 Para obter informações sobre como criar um objeto no heap gerenciado, consulte [gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md).  
  
 Quando **novo** é usada para alocar memória para um objeto de classe do C++, o construtor do objeto é chamado depois que a memória é alocada.  
  
 Use o [excluir](../cpp/delete-operator-cpp.md) operador desalocar a memória alocada com o **novo** operador.  
  
 O exemplo a seguir aloca e depois libera uma matriz bidimensional de caracteres de tamanho `dim` por 10. Ao alocar uma matriz multidimensional, todas as dimensões, exceto a primeira, devem ser expressões de constantes que são avaliadas como valores positivos; a dimensão mais à esquerda da matriz pode ser qualquer expressão que seja avaliada como um valor positivo. Ao alocar uma matriz usando o **novo** operador, a primeira dimensão pode ser zero — o **novo** operador retorna um ponteiro exclusivo.  
  
```  
char (*pchar)[10] = new char[dim][10];  
delete [] pchar;  
```  
  
 O *nome do tipo* não pode conter **const**, `volatile`, declarações de classe ou declarações de enumeração. Dessa forma, a expressão a seguir é inválida:  
  
```  
volatile char *vch = new volatile char[20];  
```  
  
 O **novo** operador não aloca tipos de referência, porque eles não são objetos.  
  
 O **novo** operador não pode ser usado para alocar uma função, mas ele pode ser usado para alocar ponteiros para funções. O exemplo a seguir aloca e depois libera uma matriz de sete ponteiros para funções que retornam inteiros.  
  
```  
int (**p) () = new (int (*[7]) ());  
delete *p;  
```  
  
 Se você usar o operador **novo** sem quaisquer argumentos adicionais e compile com o [/GX](../build/reference/gx-enable-exception-handling.md), [/EHa](../build/reference/eh-exception-handling-model.md), ou [/EHs](../build/reference/eh-exception-handling-model.md) opção, o compilador será Gerar código para chamar o operador **excluir** se o construtor lançará uma exceção.  
  
 A lista a seguir descreve os elementos de gramática de **novo**:  
  
 *posicionamento*  
 Fornece uma maneira de passar argumentos adicionais se você sobrecarregar **novo**.  
  
 *nome do tipo*  
 Especifica o tipo a ser alocado; pode ser um tipo definido pelo usuário ou interno. Se a especificação de tipo for complicada, poderá ficar entre parênteses para forçar a ordem de associação.  
  
 *initializer*  
 Fornece um valor para o objeto inicializado. Não é possível especificar inicializadores para matrizes. O **novo** operador irá criar matrizes de objetos somente se a classe tiver um construtor padrão.  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir aloca uma matriz de caracteres e um objeto da classe `CName` e depois os libera.  
  
```  
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
 Se você usar o novo formulário de posicionamento do **novo** operador, o formulário com argumentos além do tamanho de alocação, o compilador não suporta uma forma de posicionamento do **excluir** operador se a construtor lançará uma exceção. Por exemplo:  
  
```  
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
  
## <a name="initializing-object-allocated-with-new"></a>Inicializando o objeto alocado com novo  
 Um recurso opcional *inicializador* campo é incluído na gramática para o **novo** operador. Isso permite que os novos objetos sejam inicializados com construtores definidos pelo usuário. Para obter mais informações sobre como a inicialização é feita, consulte [inicializadores](../cpp/initializers.md). O exemplo a seguir ilustra como usar uma expressão de inicialização com o **novo** operador:  
  
```  
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
  
 Neste exemplo, o objeto `CheckingAcct` é alocado usando o **novo** operador, mas sem inicialização padrão é especificado. Portanto, o construtor padrão da classe, `Acct()`, é chamado. O objeto `SavingsAcct` é então alocado da mesma maneira, mas ele é inicializado explicitamente como 34,98. Porque 34.98 é do tipo **duplo**, o construtor que usa um argumento de tipo é chamado para manipular a inicialização. Por fim, o tipo sem classe `HowMuch` é inicializado como 43,0.  
  
 Se um objeto é de um tipo de classe e classe tem construtores (como no exemplo anterior), o objeto pode ser inicializado pelo **novo** operador somente se uma das seguintes condições for atendida:  
  
-   Os argumentos fornecidos no inicializador concordam com os de um construtor.  
  
-   A classe tem um construtor padrão (um construtor um que pode ser chamado sem argumentos).  
  
 Nenhuma inicialização explícita por elemento pode ser feita quando a alocação de matrizes usando o **novo** operador; apenas o construtor padrão, se presente, é chamado. Consulte [argumentos padrão](../cpp/default-arguments.md) para obter mais informações.  
  
 Se a alocação de memória falhar (`operator new` retorna um valor de 0), nenhuma inicialização será executada. Isso protege contra tentativas de inicialização de dados que não existem.  
  
 Assim como acontece com as chamadas de função, a ordem em que as expressões inicializadas são avaliadas não está definida. Além disso, você não deve confiar que essas expressões serão totalmente avaliadas antes que a alocação da memória seja executada. Se a alocação de memória falhar e o **novo** operador retorna zero, algumas expressões no inicializador não podem ser avaliados completamente.  
  
## <a name="lifetime-of-objects-allocated-with-new"></a>Tempo de vida de objetos alocados com novo  
 Objetos alocados com o **novo** operador não são destruídos quando o escopo no qual eles são definidos for fechado. Porque o **novo** operador retorna um ponteiro para os objetos que ele aloca, o programa deve definir um ponteiro com escopo adequado para acessá-los. Por exemplo:  
  
```  
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
 O *alocação expressão* – a expressão que contém o **novo** operador — faz três coisas:  
  
-   Localiza e reserva o armazenamento para que o objeto ou objetos sejam alocados. Quando essa fase for concluída, a quantidade correta de armazenamento é alocada, mas ela ainda não é um objeto.  
  
-   Inicializa o(s) objeto(s). Após a conclusão da inicialização, informações suficientes estão presentes para que o armazenamento alocado seja um objeto.  
  
-   Retorna um ponteiro para os objetos de um tipo de ponteiro é derivado de *novo nome de tipo* ou *nome do tipo*. O programa usa esse ponteiro para acessar o objeto recentemente alocado.  
  
 O **novo** operador invoca a função `operator new`. Para matrizes de qualquer tipo e para objetos que não são de **classe**, `struct`, ou **união** tipos, uma função global, **:: operador novo**, é chamado para alocar armazenamento. Os objetos de tipo de classe podem definir sua própria função de membro estático `operator new` em uma base por classe.  
  
 Quando o compilador encontra o **novo** operador para alocar um objeto do tipo `type`, ele emite uma chamada para `type` **:: operador new (sizeof (** `type` **))**  ou, se não definida pelo usuário `operator new` for definida, **:: operador new (sizeof (** `type` **))**. Portanto, o **novo** operador pode alocar a quantidade correta de memória para o objeto.  
  
> [!NOTE]
>  O argumento `operator new` é do tipo **size_t**. Este tipo é definido em DIRECT.H, MALLOC.H, MEMORY.H, SEARCH.H, STDDEF.H, STDIO.H, STDLIB.H, STRING.H e TIME.H.  
  
 Uma opção na gramática permite a especificação de *posicionamento* (consulte a gramática para [novo operador](../cpp/new-operator-cpp.md)). O *posicionamento* parâmetro pode ser usado somente para implementações definido pelo usuário de `operator new`; ela permite que informações adicionais a serem passados para `operator new`. Uma expressão com um *posicionamento* campo como `T *TObject = new ( 0x0040 ) T;` é convertido em `T *TObject = T::operator new( sizeof( T ), 0x0040 );` se a classe T possui membro operador novo, caso contrário, para `T *TObject = ::operator new( sizeof( T ), 0x0040 );`.  
  
 A intenção original do *posicionamento* campo foi permitir que os objetos dependentes de hardware a ser alocada em endereços especificados pelo usuário.  
  
> [!NOTE]
>  Embora o exemplo anterior mostra apenas um argumento no *posicionamento* campo, não há nenhuma restrição em quantos argumentos adicionais podem ser passados para `operator new` dessa maneira.  
  
 Mesmo quando `operator new` for definido para um tipo de classe, o operador global pode ser usado com o formato deste exemplo:  
  
```  
T *TObject =::new TObject;  
```  
  
 O operador de resolução do escopo (`::`) força o uso de global **novo** operador.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [novo e excluir operadores](../cpp/new-and-delete-operators.md)
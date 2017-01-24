---
title: "Operador new (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave new [C++]"
ms.assetid: 69fee812-1c28-4882-8fda-d1ad17860004
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador new (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Aloca memória para um objeto ou uma matriz de objetos de *type\-name* do repositório livre e retorna um ponteiro diferente de zero e adequadamente tipado para o objeto.  
  
> [!NOTE]
>  As Extensões de Componentes do Microsoft C\+\+ fornecem suporte para a palavra\-chave `new` a fim de adicionar entradas de slot a vtable.  Para obter mais informações, consulte [new \(new slot in vtable\)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)  
  
## Sintaxe  
  
```  
[::] new [placement] new-type-name [new-initializer]  
[::] new [placement] ( type-name ) [new-initializer]  
```  
  
## Comentários  
 Caso não seja bem\-sucedido, **new** retorna zero ou lança uma exceção; consulte [Os operadores new e delete](../cpp/new-and-delete-operators.md) para obter mais informações.  Você pode alterar esse comportamento padrão escrevendo uma rotina de manipulação de exceção personalizada e chamando a função [\_set\_new\_handler](../Topic/_set_new_handler.md) da biblioteca em tempo de execução com o nome da sua função como argumento.  
  
 Para obter informações sobre como criar um objeto no heap gerenciado, consulte [gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md).  
  
 Quando **new** é usado para alocar memória para um objeto de classe do C\+\+, o construtor do objeto é chamado após a memória ser alocada.  
  
 Use o operador [delete](../cpp/delete-operator-cpp.md) para desalocar a memória alocada com o operador **new**.  
  
 O exemplo a seguir aloca e depois libera uma matriz bidimensional de caracteres de tamanho `dim` por 10.  Ao alocar uma matriz multidimensional, todas as dimensões, exceto a primeira, devem ser expressões de constantes que são avaliadas como valores positivos; a dimensão mais à esquerda da matriz pode ser qualquer expressão que seja avaliada como um valor positivo.  Ao alocar uma matriz usando o operador **new**, a primeira dimensão pode ser zero: o operador **new** retorna um ponteiro exclusivo.  
  
```  
char (*pchar)[10] = new char[dim][10];  
delete [] pchar;  
```  
  
 *type\-name* não pode conter **const**, `volatile`, declarações de classe nem declarações de enumeração.  Dessa forma, a expressão a seguir é inválida:  
  
```  
volatile char *vch = new volatile char[20];  
```  
  
 O operador **new** não aloca tipos de referência porque eles não são objetos.  
  
 O operador **new** não pode ser usado para alocar uma função, mas pode ser usado para alocar ponteiros para funções.  O exemplo a seguir aloca e depois libera uma matriz de sete ponteiros para funções que retornam inteiros.  
  
```  
int (**p) () = new (int (*[7]) ());  
delete *p;  
```  
  
 Se você usar o operador **new** sem nenhum argumento extra e o compilar com a opção [\/GX](../Topic/-GX%20\(Enable%20Exception%20Handling\).md), [\/EHa](../build/reference/eh-exception-handling-model.md) ou [\/EHs](../build/reference/eh-exception-handling-model.md), o compilador irá gerar um código para chamar o operador **delete** caso o construtor lance uma exceção.  
  
 A lista a seguir descreve os elementos de gramática de **new**:  
  
 *placement*  
 Fornece uma maneira de passar argumentos adicionais se você sobrecarregar **new**.  
  
 *type\-name*  
 Especifica o tipo a ser alocado; pode ser um tipo definido pelo usuário ou interno.  Se a especificação de tipo for complicada, poderá ficar entre parênteses para forçar a ordem de associação.  
  
 *initializer*  
 Fornece um valor para o objeto inicializado.  Não é possível especificar inicializadores para matrizes.  O operador **new** só criará matrizes de objetos se a classe tiver um construtor padrão.  
  
## Exemplo  
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
  
## Exemplo  
 Se você usar o formato do operador **new** com "placement" \- o formato com argumentos além do tamanho da alocação \-, o compilador não dará suporte ao formato do operador **delete** com "placement" caso o construtor lance uma exceção.  Por exemplo:  
  
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
  
## Inicializando o objeto alocado com novo  
 Um campo opcional *initializer* é incluído na gramática do operador **new**.  Isso permite que os novos objetos sejam inicializados com construtores definidos pelo usuário.  Para obter mais informações sobre como a inicialização é feita, consulte [Inicializadores](../cpp/initializers.md).  O exemplo a seguir ilustra como usar uma expressão de inicialização com o operador **new**:  
  
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
  
 Neste exemplo, o objeto `CheckingAcct` é alocado usando o operador **new**, mas nenhuma inicialização padrão é especificada.  Portanto, o construtor padrão da classe, `Acct()`, é chamado.  O objeto `SavingsAcct` é então alocado da mesma maneira, mas ele é inicializado explicitamente como 34,98.  Como 34,98 é do tipo **double**, o construtor que usa um argumento desse tipo é chamado para manipular a inicialização.  Por fim, o tipo sem classe `HowMuch` é inicializado como 43,0.  
  
 Se um objeto for de um tipo de classe e essa classe tiver construtores \(como no exemplo anterior\), o objeto só poderá ser inicializado pelo operador **new** se uma destas condições for atendida:  
  
-   Os argumentos fornecidos no inicializador concordam com os de um construtor.  
  
-   A classe tem um construtor padrão \(um construtor um que pode ser chamado sem argumentos\).  
  
 O controle de acesso e a ambiguidade são executados em `operator new` e nos construtores de acordo com as regras definidas em [Ambiguidade](http://msdn.microsoft.com/pt-br/0b399cab-40a7-4e79-9278-05f40139a0e1) e em [Inicialização usando as funções de membro especiais](http://msdn.microsoft.com/pt-br/82223d73-64cb-4923-b678-78f9568ff3ca).  
  
 Nenhuma inicialização explícita por elemento pode ser feita ao alocar matrizes usando o operador **new**. Somente o construtor padrão, caso exista, será chamado.  Consulte [Argumentos padrão](../Topic/Default%20Arguments.md) para obter mais informações.  
  
 Se a alocação de memória falhar \(`operator new` retorna um valor de 0\), nenhuma inicialização será executada.  Isso protege contra tentativas de inicialização de dados que não existem.  
  
 Assim como acontece com as chamadas de função, a ordem em que as expressões inicializadas são avaliadas não está definida.  Além disso, você não deve confiar que essas expressões serão totalmente avaliadas antes que a alocação da memória seja executada.  Se a alocação de memória falhar e o operador **new** retornar zero, algumas expressões no inicializador poderão não ser completamente avaliadas.  
  
## Tempo de vida dos objetos alocados com novo  
 Os objetos alocados com o operador **new** não são destruídos quando o escopo em que são definidos é fechado.  Como o operador **new** retorna um ponteiro para os objetos que ele atribui, o programa deve definir um ponteiro com escopo apropriado para acessar esses objetos.  Por exemplo:  
  
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
  
## Como new funciona  
 A *expressão de alocação* — a expressão contento o operador **new** — faz três coisas:  
  
-   Localiza e reserva o armazenamento para que o objeto ou objetos sejam alocados.  Quando essa fase for concluída, a quantidade correta de armazenamento é alocada, mas ela ainda não é um objeto.  
  
-   Inicializa o\(s\) objeto\(s\).  Após a conclusão da inicialização, informações suficientes estão presentes para que o armazenamento alocado seja um objeto.  
  
-   Retorna um ponteiro para objeto\(s\) do tipo de ponteiro derivado de *nome de tipo novo* ou *nome do tipo*.  O programa usa esse ponteiro para acessar o objeto recentemente alocado.  
  
 O operador **new** invoca a função `operator new`.  Para matrizes de qualquer tipo e para objetos que não sejam de **classe**, `struct`, ou **união** tipos, uma função global, **:: operador new**, é chamado para alocar o armazenamento.  Os objetos de tipo de classe podem definir sua própria função de membro estático `operator new` em uma base por classe.  
  
 Quando o compilador encontra a **novo** operador para alocar um objeto do tipo `type`, emite uma chamada para `type`**:: operador new \(sizeof \(** `type` **\)\)** ou, se não definido pelo usuário `operator new` for definida, **:: operador new \(sizeof \(** `type` **\)\)**.  Portanto, o operador **new** pode alocar a quantidade de memória correta para o objeto.  
  
> [!NOTE]
>  O argumento para `operator new` é do tipo **size\_t**.  Este tipo é definido em DIRECT.H, MALLOC.H, MEMORY.H, SEARCH.H, STDDEF.H, STDIO.H, STDLIB.H, STRING.H e TIME.H.  
  
 Uma opção na gramática permite a especificação de *posicionamento* \(consulte a gramática do [operador New](../cpp/new-operator-cpp.md)\).  O parâmetro de *posicionamento* pode ser usado apenas para implementações definidas pelo usuário de `operator new`; ele permite que as informações adicionais sejam passadas para `operator new`.  Uma expressão com um campo de *posicionamento*, como `T *TObject = new ( 0x0040 ) T;`, é traduzida como `T *TObject = T::operator new( sizeof( T ), 0x0040 );` se a classe T tiver o operador novo do membro. Caso contrário, a `T *TObject = ::operator new( sizeof( T ), 0x0040 );`.  
  
 A intenção original do campo de *posicionamento* era permitir que os objetos dependentes de hardware fossem alocados a endereços especificados pelo usuário.  
  
> [!NOTE]
>  Embora o exemplo anterior mostre apenas um argumento no campo de *posicionamento*, não há nenhuma limitação para o número de argumentos adicionais que podem ser passados para `operator new` dessa maneira.  
  
 Mesmo quando `operator new` for definido para um tipo de classe, o operador global pode ser usado com o formato deste exemplo:  
  
```  
T *TObject =::new TObject;  
```  
  
 O operador de resolução do escopo \(`::`\) força o uso do operador global **new**.  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Função operator new](../misc/operator-new-function.md)
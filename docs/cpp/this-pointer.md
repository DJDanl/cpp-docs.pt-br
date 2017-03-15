---
title: "Ponteiro this | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "this"
  - "this_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções de membro não estático"
  - "ponteiros, para instância de classe"
  - "este ponteiro"
ms.assetid: 92e3256a-4ad9-4d46-8be1-d77fad90791f
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ponteiro this
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O ponteiro **this** é um ponteiro acessível somente nas funções de membro não estáticas de um tipo **class**, `struct` ou **union**.  Ele aponta para o objeto para o qual a função de membro é chamada.  As funções de membro estáticas não têm um ponteiro **this**.  
  
## Sintaxe  
  
```  
  
        this   
this->member-identifier  
```  
  
## Comentários  
 O ponteiro **this** de um objeto não faz parte do objeto em si; ele não é refletido no resultado de uma instrução `sizeof` no objeto.  Em vez disso, quando uma função de membro não estática é chamada para um objeto, o endereço do objeto é transmitido pelo compilador como um argumento oculto à função.  Por exemplo, a chamada de função a seguir:  
  
```  
myDate.setMonth( 3 );  
```  
  
 pode ser interpretada desta forma:  
  
```  
setMonth( &myDate, 3 );  
```  
  
 O endereço do objeto está disponível de dentro da função de membro como o ponteiro **this**.  A maioria dos usos de **this** é implícita.  É válido, embora não seja necessário, usar explicitamente **this** ao fazer referência a membros da classe.  Por exemplo:  
  
```  
void Date::setMonth( int mn )  
{  
   month = mn;            // These three statements  
   this->month = mn;      // are equivalent  
   (*this).month = mn;  
}  
```  
  
 A expressão `*this` é geralmente usada para retornar o objeto atual de uma função de membro:  
  
```  
return *this;  
```  
  
 O ponteiro **this** também é usado para proteger contra a autorreferência:  
  
```  
if (&Object != this) {  
// do not execute in cases of self-reference  
```  
  
> [!NOTE]
>  Como o ponteiro **this** é não modificável, as atribuições a **this** não são permitidas.  As implementações anteriores do C\+\+ permitiam atribuições a **this**.  
  
 Ocasionalmente, o ponteiro **this** é usado diretamente — por exemplo, para manipular as estruturas de dados autorreferenciais, onde o endereço do objeto atual é necessário.  
  
## Exemplo  
  
```  
// this_pointer.cpp  
// compile with: /EHsc  
  
#include <iostream>  
#include <string.h>  
  
using namespace std;  
  
class Buf   
{  
public:  
    Buf( char* szBuffer, size_t sizeOfBuffer );  
    Buf& operator=( const Buf & );  
    void Display() { cout << buffer << endl; }  
  
private:  
    char*   buffer;  
    size_t  sizeOfBuffer;  
};  
  
Buf::Buf( char* szBuffer, size_t sizeOfBuffer )  
{  
    sizeOfBuffer++; // account for a NULL terminator  
  
    buffer = new char[ sizeOfBuffer ];  
    if (buffer)  
    {  
        strcpy_s( buffer, sizeOfBuffer, szBuffer );  
        sizeOfBuffer = sizeOfBuffer;  
    }  
}  
  
Buf& Buf::operator=( const Buf &otherbuf )   
{  
    if( &otherbuf != this )   
    {  
        if (buffer)  
            delete [] buffer;  
  
        sizeOfBuffer =  strlen( otherbuf.buffer ) + 1;   
        buffer = new char[sizeOfBuffer];  
        strcpy_s( buffer, sizeOfBuffer, otherbuf.buffer );  
    }  
    return *this;  
}  
  
int main()  
{  
    Buf myBuf( "my buffer", 10 );  
    Buf yourBuf( "your buffer", 12 );  
  
    // Display 'my buffer'  
    myBuf.Display();  
  
    // assignment opperator  
    myBuf = yourBuf;  
  
    // Display 'your buffer'  
    myBuf.Display();  
}  
```  
  
  **meu buffer**  
**seu buffer**   
## Tipo deste ponteiro  
 O tipo de ponteiro **this** pode ser alterado na declaração de função pelas palavras\-chave **const** e `volatile`.  Para declarar uma função como tendo os atributos de uma ou mais dessas palavras\-chave, adicione as palavras\-chave após a lista de argumentos da função.  
  
 Considere este exemplo:  
  
```  
// type_of_this_pointer1.cpp  
class Point  
{  
    unsigned X() const;  
};  
int main()  
{  
}  
```  
  
 O código anterior declara uma função de membro, `X`, em que o ponteiro **this** é tratado como um ponteiro **const** para um objeto **const**.  As combinações de opções *cv\-mod\-list* podem ser usadas, mas sempre modificam o objeto apontado por **this**, não o ponteiro **this** em si.  Portanto, a seguinte declaração declara a função `X`; o ponteiro **this** é um ponteiro **const** para um objeto **const**:  
  
```  
// type_of_this_pointer2.cpp  
class Point  
{  
    unsigned X() const;  
};  
int main()  
{  
}  
```  
  
 O tipo de **isso** em um membro da função é descrito pela seguinte sintaxe, onde *cv\-qualifier\-list* é determinado a partir o declarador de funções de membro e pode ser **const** ou **volátil** \(ou ambos\), e *tipo de classe* é o nome da classe:  
  
 *tipo de classe \[cv\-qualifier\-list\]*  **\* const isso**  
  
 Ou seja, **this** sempre é um ponteiro const; não pode ser reatribuído.  O **const** ou `volatile` usado na declaração de função de membro se aplicam à instância de classe apontada por **isso** no escopo dessa função.  
  
 A tabela a seguir explica mais sobre como esses modificadores funcionam.  
  
### Semântica dos modificadores this  
  
|Modificador|Significado|  
|-----------------|-----------------|  
|**const**|Não pode alterar dados de membros; não pode chamar funções de membro que não sejam **const**.|  
|`volatile`|Os dados de membro são carregados da memória sempre que são acessados; desabilita certas otimizações.|  
  
 É um erro passar um objeto **const** para uma função de membro que não seja **const**.  Da mesma forma, é um erro passar um objeto `volatile` para uma função de membro que não seja `volatile`.  
  
 As funções de membro declaradas como **const** não podem alterar dados de membro — nessas funções, o ponteiro **this** é um ponteiro para um objeto **const**.  
  
> [!NOTE]
>  Os construtores e os destruidores não podem ser declarados como **const** ou `volatile`.  Porém, eles podem ser chamados em objetos **const** ou `volatile`.  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Tipo deste ponteiro](../misc/type-of-this-pointer.md)   
 [Correspondência de argumento e este ponteiro](../misc/argument-matching-and-the-this-pointer.md)
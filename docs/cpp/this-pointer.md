---
title: Este ponteiro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- this_cpp
dev_langs:
- C++
helpviewer_keywords:
- nonstatic member functions [C++]
- pointers, to class instance
- this pointer
ms.assetid: 92e3256a-4ad9-4d46-8be1-d77fad90791f
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 86ccf50a089b1497bdc166ee9367215dc59b3ca1
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="this-pointer"></a>Ponteiro this
O **isso** ponteiro é um ponteiro acessível somente dentro das funções de membro não estático de uma **classe**, `struct`, ou **união** tipo. Ele aponta para o objeto para o qual a função de membro é chamada. Funções membro static não possuem um **isso** ponteiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      this   
this->member-identifier  
```  
  
## <a name="remarks"></a>Comentários  
 Um objeto **isso** ponteiro não é parte do objeto em si; ele não é refletido no resultado de uma `sizeof` instrução no objeto. Em vez disso, quando uma função de membro não estática é chamada para um objeto, o endereço do objeto é transmitido pelo compilador como um argumento oculto à função. Por exemplo, a chamada de função a seguir:  
  
```  
myDate.setMonth( 3 );  
```  
  
 pode ser interpretada desta forma:  
  
```  
setMonth( &myDate, 3 );  
```  
  
 O endereço do objeto está disponível de dentro da função de membro como o **isso** ponteiro. A maioria dos usos do **isso** implícitas. É permitido, embora não seja necessário usar explicitamente **isso** ao fazer referência a membros da classe. Por exemplo:  
  
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
  
 O **isso** ponteiro também é usado para proteger contra a referência:  
  
```  
if (&Object != this) {  
// do not execute in cases of self-reference  
```  
  
> [!NOTE]
>  Porque o **isso** ponteiro é não modificável, atribuições para **isso** não são permitidas. Implementações anteriores do C++ permitido atribuições para **isso**.  
  
 Ocasionalmente, o **isso** ponteiro é usado diretamente — por exemplo manipular dados autorreferência estruturas, onde é necessário o endereço do objeto atual.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
my buffer  
your buffer  
```  
  
## <a name="type-of-the-this-pointer"></a>Tipo deste ponteiro  
 O **isso** tipo ponteiro pode ser modificado na declaração de função, o **const** e `volatile` palavras-chave. Para declarar uma função como tendo os atributos de uma ou mais dessas palavras-chave, adicione as palavras-chave após a lista de argumentos da função.  
  
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
  
 O código anterior declara uma função de membro, `X`, no qual o **isso** ponteiro é tratado como um **const** ponteiro para um **const** objeto. Combinações de *cv-mod-list* opções podem ser usadas, mas eles sempre modificar o objeto apontado pela **isso**, não o **isso** ponteiro em si. Portanto, a declaração a seguir declara a função `X`; o **isso** ponteiro é um **const** ponteiro para um **const** objeto:  
  
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
  
 O tipo de **isso** em um membro da função é descrita pela sintaxe a seguir, onde *VC de qualificador de lista* é determinado a partir de Declarador de funções de membro e pode ser **const**ou **volátil** (ou ambos), e *tipo de classe* é o nome da classe:  
  
 *tipo de classe [lista de qualificador cv]* ** \* const isso  **  
  
 Em outras palavras, **isso** sempre é um ponteiro const; ele não pode ser reatribuído.  O **const** ou `volatile` aplicam qualificadores usados na declaração de função de membro para a instância da classe apontada pelo **isso** no escopo da função.  
  
 A tabela a seguir explica mais sobre como esses modificadores funcionam.  
  
### <a name="semantics-of-this-modifiers"></a>Semântica dos modificadores this  
  
|Modificador|Significado|  
|--------------|-------------|  
|**const**|Não é possível alterar os dados de membro; não é possível chamar funções de membro que não são **const**.|  
|`volatile`|Os dados de membro são carregados da memória sempre que são acessados; desabilita certas otimizações.|  
  
 É um erro para passar um **const** objeto para uma função de membro que não seja **const**. Da mesma forma, é um erro passar um objeto `volatile` para uma função de membro que não seja `volatile`.  
  
 Funções de membro declarado como **const** não é possível alterar os dados de membro — em funções, o **isso** ponteiro é um ponteiro para um **const** objeto.  
  
> [!NOTE]
>  Construtores e destruidores não podem ser declarados como **const** ou `volatile`. No entanto, ele podem ser chamado em **const** ou `volatile` objetos.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 

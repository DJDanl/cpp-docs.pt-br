---
title: esse ponteiro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f63b2d129e0eb6e9986942e4286eb1728d4be797
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39462213"
---
# <a name="this-pointer"></a>Ponteiro this
O **isso** ponteiro for um ponteiro acessível somente dentro de funções de membro não estáticas de uma **classe**, **struct**, ou **união** tipo. Ele aponta para o objeto para o qual a função de membro é chamada. As funções membro estáticas não têm uma **isso** ponteiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
this   
this->member-identifier  
```  
  
## <a name="remarks"></a>Comentários  
 Um objeto **isso** ponteiro não é parte do objeto em si; ele não é refletido no resultado de uma **sizeof** instrução no objeto. Em vez disso, quando uma função de membro não estática é chamada para um objeto, o endereço do objeto é transmitido pelo compilador como um argumento oculto à função. Por exemplo, a chamada de função a seguir:  
  
```cpp 
myDate.setMonth( 3 );  
```  
  
 pode ser interpretada desta forma:  
  
```cpp 
setMonth( &myDate, 3 );  
```  
  
 O endereço do objeto está disponível de dentro da função de membro como o **isso** ponteiro. A maioria dos usos da **isso** são implícitos. É legal, embora não seja necessário usar explicitamente **isso** ao fazer referência a membros da classe. Por exemplo:  
  
```cpp 
void Date::setMonth( int mn )  
{  
   month = mn;            // These three statements  
   this->month = mn;      // are equivalent  
   (*this).month = mn;  
}  
```  
  
 A expressão `*this` é geralmente usada para retornar o objeto atual de uma função de membro:  
  
```cpp 
return *this;  
```  
  
 O **isso** ponteiro também é usado para se proteger contra a autorreferência:  
  
```cpp 
if (&Object != this) {  
// do not execute in cases of self-reference  
```  
  
> [!NOTE]
>  Porque o **isso** ponteiro é não modificável, as atribuições a **isso** não são permitidas. As implementações anteriores do C++ permitiam atribuições a **isso**.  
  
 Ocasionalmente, o **isso** ponteiro é usado diretamente — por exemplo manipular dados autorreferenciais estruturas, onde é necessário o endereço do objeto atual.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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
 O **isso** tipo de ponteiro pode ser modificado na declaração de função pelos **const** e **volátil** palavras-chave. Para declarar uma função como tendo os atributos de uma ou mais dessas palavras-chave, adicione as palavras-chave após a lista de argumentos da função.  
  
 Considere este exemplo:  
  
```cpp 
// type_of_this_pointer1.cpp  
class Point  
{  
    unsigned X() const;  
};  
int main()  
{  
}  
```  
  
 O código anterior declara uma função de membro `X`, no qual o **isso** ponteiro é tratado como um **const** ponteiro para um **const** objeto. Combinações de *cv-mod-list* podem ser usadas, mas sempre modificam o objeto apontado por **isso**, e não o **isso** ponteiro em si. Portanto, a seguinte declaração declara a função `X`; o **isso** ponteiro for um **const** ponteiro para um **const** objeto:  
  
```cpp 
// type_of_this_pointer2.cpp  
class Point  
{  
    unsigned X() const;  
};  
int main()  
{  
}  
```  
  
 O tipo de **isso** em um membro da função é descrito pela seguinte sintaxe, onde *cv-qualifier-list* é determinado pelo declarador das funções de membro e pode ser **const**ou **volátil** (ou ambos), e *tipo de classe* é o nome da classe:  
  
 *tipo de classe [cv-qualifier-list]* **\* const isso**  
  
 Em outras palavras, **isso** é sempre um ponteiro const; ele não pode ser reatribuído.  O **const** ou **volátil** usado na declaração da função de membro se aplicam à instância de classe apontada por **isso** no escopo dessa função.  
  
 A tabela a seguir explica mais sobre como esses modificadores funcionam.  
  
### <a name="semantics-of-this-modifiers"></a>Semântica dos modificadores this  
  
|Modificador|Significado|  
|--------------|-------------|  
|**const**|Não é possível alterar os dados de membro; não é possível invocar funções de membro que não sejam **const**.|  
|**volatile**|Os dados de membro são carregados da memória sempre que são acessados; desabilita certas otimizações.|  
  
 É um erro passar um **const** objeto para uma função de membro que não seja **const**. Da mesma forma, é um erro passar um **volátil** objeto para uma função de membro que não seja **volátil**.  
  
 Funções de membro declaradas como **const** não é possível alterar os dados de membro — nessas funções, o **isso** ponteiro é um ponteiro para um **const** objeto.  
  
> [!NOTE]
>  Construtores e destruidores não podem ser declarados como **const** ou **volátil**. No entanto, eles podem ser invocado na **const** ou **volátil** objetos.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
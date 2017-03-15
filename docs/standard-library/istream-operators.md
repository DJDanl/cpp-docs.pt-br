---
title: Operadores &lt;istream&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 7174da41-f301-4a34-b631-0ab918b188d2
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4c2a2f8c2c2b55e3c14db9e44a4b05041c0ecfc9
ms.lasthandoff: 02/25/2017

---
# <a name="ltistreamgt-operators"></a>Operadores &lt;istream&gt;
 
##  <a name="a-nameoperatorgtgta--operatorgtgt"></a><a name="operator_gt__gt_"></a>  operator&gt;&gt;  
 Extrai caracteres e cadeias de caracteres do fluxo.  
  
```  
template <class Elem, class Tr>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr,   
    Elem* str);

template <class Elem, class Tr>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr,   
    Elem& Ch);

template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,   
    signed char* str);

template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,   
    signed char& Ch);

template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,   
    unsigned char* str);

template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr,   
    unsigned char& Ch);

template <class Elem, class Tr, class Type>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<char, Tr>&& Istr,  
    Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Ch`  
 Um caractere.  
  
 `Istr`  
 Um fluxo.  
  
 ` str`  
 Uma cadeia de caracteres.  
  
 ` val`  
 Um tipo.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo  
  
### <a name="remarks"></a>Comentários  
 A classe `basic_istream` também define vários operadores de extração. Para obter mais informações, consulte [basic_istream::operator>>](../standard-library/basic-istream-class.md#basic_istream__operator_gt__gt_).  
  
 A função de modelo:  
  
```cpp  
template <class Elem, class Tr>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem* str);
```  
  
 extrai até *N* - 1 elementos e os armazena na matriz que começa em _ *Str*. Se `Istr`. [width](../standard-library/ios-base-class.md#ios_base__width) for maior que zero, *N* será `Istr`. **width**; caso contrário, será o tamanho da maior matriz de **Elem** que pode ser declarada. A função sempre armazena o valor **Elem()** após qualquer elemento extraído que armazena. A extração é interrompida prematuramente no final do arquivo, em um caractere com valor **Elem**(0) (que não é extraído) ou em qualquer elemento (que não é extraído) que seria descartado por [ws](../standard-library/istream-functions.md#ws). Se a função não extrair nenhum elemento, ela chamará `Istr`. [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)( **failbit**). Em qualquer caso, chamará `Istr`. **width**(0) e retornará `Istr`.  
  
 **Observação de segurança** a cadeia de caracteres terminada em nulo que está sendo extraída do fluxo de entrada não deve ultrapassar o tamanho do buffer de destino ` str`. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
 A função de modelo:  
  
```cpp  
template <class Elem, class Tr>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem& Ch);
```  
  
 extrai um elemento, se for possível, e o armazena em `Ch`. Caso contrário, chama **is**. [setstate](../standard-library/basic-ios-class.md#basic_ios__setstate)( **failbit**). Em qualquer caso, retorna `Istr`.  
  
 A função de modelo:  
  
```cpp  
template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char* str);
```  
  
 retorna `Istr` >> ( `char`**\***) ` str`.  
  
 A função de modelo:  
  
```cpp  
template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char& Ch);
```  
  
 retorna `Istr` >> ( **char&**) `Ch`.  
  
 A função de modelo:  
  
```cpp  
template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, unsigned char* str);
```  
  
 retorna `Istr` >> ( **char \***) ` str`.  
  
 A função de modelo:  
  
```cpp  
template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, unsigned char& Ch);
```  
  
 retorna `Istr` >> ( **char&**) `Ch`.  
  
 A função de modelo:  
  
```cpp  
template <class Elem, class Tr, class Type>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<char, Tr>&& Istr,  
    Type& val);
```  
  
 retorna `Istr` `>>` ` val` (e converte um `rvalue reference` para `Istr` para um `lvalue` no processo).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istream_op_extract.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   ws( cin );  
   char c[10];  
  
   cin.width( 9 );  
   cin >> c;  
   cout << c << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<istream>](../standard-library/istream.md)



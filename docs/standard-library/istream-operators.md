---
title: Operadores &lt;istream&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- istream/std::operator&gt;&gt;
dev_langs:
- C++
ms.assetid: 7174da41-f301-4a34-b631-0ab918b188d2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dc68ed6c0122fbe1176bfda1d446421677902e6c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltistreamgt-operators"></a>Operadores &lt;istream&gt;
 
##  <a name="op_gt_gt"></a>  operator&gt;&gt;  
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
  
 `str`  
 Uma cadeia de caracteres.  
  
 `val`  
 Um tipo.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo  
  
### <a name="remarks"></a>Comentários  
 A classe `basic_istream` também define vários operadores de extração. Para obter mais informações, consulte [basic_istream::operator>>](../standard-library/basic-istream-class.md#op_gt_gt).  
  
 A função de modelo:  
  
```cpp  
template <class Elem, class Tr>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem* str);
```  
  
 extrai até *N* - 1 elementos e os armazena na matriz que começa em _ *Str*. Se `Istr`. [width](../standard-library/ios-base-class.md#width) for maior que zero, *N* será `Istr`. **width**; caso contrário, será o tamanho da maior matriz de **Elem** que pode ser declarada. A função sempre armazena o valor **Elem()** após qualquer elemento extraído que armazena. A extração é interrompida prematuramente no final do arquivo, em um caractere com valor **Elem**(0) (que não é extraído) ou em qualquer elemento (que não é extraído) que seria descartado por [ws](../standard-library/istream-functions.md#ws). Se a função não extrair nenhum elemento, ela chamará `Istr`. [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, chamará `Istr`. **width**(0) e retornará `Istr`.  
  
 **Observação de segurança** a cadeia de caracteres terminada em nulo que está sendo extraída do fluxo de entrada não deve ultrapassar o tamanho do buffer de destino `str`. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
 A função de modelo:  
  
```cpp  
template <class Elem, class Tr>  
basic_istream<Elem, Tr>& operator>>(
    basic_istream<Elem, Tr>& Istr, Elem& Ch);
```  
  
 extrai um elemento, se for possível, e o armazena em `Ch`. Caso contrário, chama **is**. [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, retorna `Istr`.  
  
 A função de modelo:  
  
```cpp  
template <class Tr>  
basic_istream<char, Tr>& operator>>(
    basic_istream<char, Tr>& Istr, signed char* str);
```  
  
 retorna `Istr` >> ( `char`**\***) `str`.  
  
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
  
 retorna `Istr` >> ( **char \***) `str`.  
  
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
  
 retorna `Istr` `>>` `val` (e converte um `rvalue reference` para `Istr` para um `lvalue` no processo).  
  
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


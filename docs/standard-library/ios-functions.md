---
title: "Funções &lt;ios&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xiosbase/std::defaultfloat
- xiosbase/std::boolalpha
- xiosbase/std::dec
- ios/std::fixed
- ios/std::hex
- ios/std::internal
- ios/std::left
- ios/std::noboolalpha
- ios/std::noshowbase
- ios/std::noshowpoint
- ios/std::noshowpos
- ios/std::noskipws
- ios/std::nounitbuf
- ios/std::nouppercase
- ios/std::oct
- ios/std::right
- ios/std::scientific
- ios/std::showbase
- ios/std::showpoint
- ios/std::showpos
- ios/std::skipws
- ios/std::unitbuf
- ios/std::uppercase
ms.assetid: 1382d53f-e531-4b41-adf6-6a1543512e51
caps.latest.revision: "10"
manager: ghogen
helpviewer_keywords:
- std::defaultfloat [C++]
- std::boolalpha [C++]
- std::dec [C++]
- std::fixed [C++]
- std::hex [C++]
- std::internal [C++]
- std::left [C++]
- std::noboolalpha [C++]
- std::noshowbase [C++]
- std::noshowpoint [C++]
- std::noshowpos [C++]
- std::noskipws [C++]
- std::nounitbuf [C++]
- std::nouppercase [C++]
- std::oct [C++]
- std::right [C++]
- std::scientific [C++]
- std::showbase [C++]
- std::showpoint [C++]
- std::showpos [C++]
- std::skipws [C++]
- std::unitbuf [C++]
- std::uppercase [C++]
ms.openlocfilehash: 621f659ec0a3896013d8b81526f9ec83561d76a8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltiosgt-functions"></a>Funções &lt;ios&gt;
||||  
|-|-|-|  
|[defaultfloat](#ios_defaultfloat)|[boolalpha](#boolalpha)|[dec](#dec)|  
|[fixed](#fixed)|[hex](#hex)|[internal](#internal)|  
|[left](#left)|[noboolalpha](#noboolalpha)|[noshowbase](#noshowbase)|  
|[noshowpoint](#noshowpoint)|[noshowpos](#noshowpos)|[noskipws](#noskipws)|  
|[nounitbuf](#nounitbuf)|[nouppercase](#nouppercase)|[oct](#oct)|  
|[right](#right)|[scientific](#scientific)|[showbase](#showbase)|  
|[showpoint](#showpoint)|[showpos](#showpos)|[skipws](#skipws)|  
|[unitbuf](#unitbuf)|[uppercase](#uppercase)|  
  
##  <a name="boolalpha"></a>  boolalpha  
 Especifica que variáveis do tipo [bool](../cpp/bool-cpp.md) aparecem como **true** ou **false** no fluxo.  
  
```  
ios_base& boolalpha(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, variáveis do tipo `bool` são exibidas como 1 ou 0.  
  
 `boolalpha`chama efetivamente `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::boolalpha`) e, em seguida, retorna `str`.  
  
 [noboolalpha](../standard-library/ios-functions.md#noboolalpha) inverte o efeito de `boolalpha`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_boolalpha.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   bool b = true;  
   cout << b << endl;  
   boolalpha( cout );  
   cout << b << endl;  
   noboolalpha( cout );  
   cout << b << endl;  
   cout << boolalpha << b << endl;  
}  
```  
  
```Output  
1  
true  
1  
true  
```  
  
##  <a name="dec"></a>  dec  
 Especifica que variáveis inteiras aparecem em notação de base 10.  
  
```  
ios_base& dec(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, variáveis inteiras são exibidas na base 10.  
  
 **dec** efetivamente chama `str.`[setf](../standard-library/ios-base-class.md#setf)( `ios_base::dec`**, ios_base::basefield**) e retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_dec.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   int i = 100;  
  
   cout << i << endl;   // Default is base 10  
   cout << hex << i << endl;     
   dec( cout );  
   cout << i << endl;  
   oct( cout );  
   cout << i << endl;  
   cout << dec << i << endl;  
}  
```  
  
```Output  
100  
64  
100  
144  
100  
```  
  
##  <a name="ios_defaultfloat"></a>  &lt;ios&gt; defaultfloat  
 Configura os sinalizadores de um objeto `ios_base` para usar um formato de exibição padrão para valores do tipo float.  
  
```  
ios_base& defaultfloat(ios_base& _Iosbase);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Iosbase`  
 Um objeto `ios_base`.  
  
### <a name="remarks"></a>Comentários  
 O manipulador efetivamente chama _I `osbase.`[ios_base::unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::floatfield)` e retorna _I `osbase`.  
  
##  <a name="fixed"></a>  fixed  
 Especifica que um número de ponto flutuante é exibido em notação de decimal fixo.  
  
```  
ios_base& fixed(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 **fixed** é a notação de exibição padrão para números de ponto flutuante. [scientific](../standard-library/ios-functions.md#scientific) faz com que números de ponto flutuante sejam exibidos usando notação científica.  
  
 O manipulator efetivamente chama * str.*[setf](../standard-library/ios-base-class.md#setf)( `ios_base::fixed`, **ios_base::floatfield**) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_fixed.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   float i = 1.1F;  
  
   cout << i << endl;   // fixed is the default  
   cout << scientific << i << endl;  
   cout.precision( 1 );  
   cout << fixed << i << endl;  
}  
```  
  
```Output  
1.1  
1.100000e+000  
1.1  
```  
  
##  <a name="hex"></a>  hex  
 Especifica que variáveis inteiras devem aparecer em notação de base 16.  
  
```  
ios_base& hex(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, variáveis inteiras são exibidas em notação de base 10. [dec](../standard-library/ios-functions.md#dec) e [oct](../standard-library/ios-functions.md#oct) também alteram a forma como as variáveis inteiras aparecem.  
  
 O manipulador efetivamente chama `str`**.**[setf](../standard-library/ios-base-class.md#setf)( `ios_base::hex`, **ios_base::basefield**) e retorna `str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [dec](../standard-library/ios-functions.md#dec) para ver um exemplo de como usar **hex**.  
  
##  <a name="internal"></a>  internal  
 Faz com que o sinal de um número seja justificado à esquerda e o número seja justificado à direita.  
  
```  
ios_base& internal(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual `str` é derivado.  
  
### <a name="remarks"></a>Comentários  
 [showpos](../standard-library/ios-functions.md#showpos) faz com que o sinal seja exibido para números positivos.  
  
 O manipulador efetivamente chama `str`. [setf](../standard-library/ios-base-class.md#setf)( [ios_base::internal](../standard-library/ios-base-class.md#fmtflags), [ios_base::adjustfield](../standard-library/ios-base-class.md#fmtflags)) e retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_internal.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <iomanip>  
  
int main( void )   
{  
   using namespace std;  
   float i = -123.456F;  
   cout.fill( '.' );  
   cout << setw( 10 ) << i << endl;  
   cout << setw( 10 ) << internal << i << endl;  
}  
```  
  
```Output  
..-123.456  
-..123.456  
```  
  
##  <a name="left"></a>  left  
 Faz com que um texto que não é tão largo quanto a largura de saída apareça no fluxo alinhado à margem esquerda.  
  
```  
ios_base& left(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::left`, **ios_base::adjustfield**) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_left.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   double f1= 5.00;  
   cout.width( 20 );   
   cout << f1 << endl;  
   cout << left << f1 << endl;  
}  
```  
  
```Output  
                   5  
5  
```  
  
##  <a name="noboolalpha"></a>  noboolalpha  
 Especifica que variáveis do tipo [bool](../cpp/bool-cpp.md) apareçam como 1 ou 0 no fluxo.  
  
```  
ios_base& noboolalpha(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `noboolalpha` está em vigor.  
  
 `noboolalpha`chama efetivamente `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::boolalpha`) e, em seguida, retorna `str`.  
  
 [boolalpha](../standard-library/ios-functions.md#boolalpha) inverte o efeito de `noboolalpha`.  
  
### <a name="example"></a>Exemplo  
  Consulte [boolalpha](../standard-library/ios-functions.md#boolalpha) para ver um exemplo de como usar `noboolalpha`.  
  
##  <a name="noshowbase"></a>  noshowbase  
 Desativa a indicação da base da notação em que um número é exibido.  
  
```  
ios_base& noshowbase(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 `noshowbase` fica ativo por padrão. Use [showbase](../standard-library/ios-functions.md#showbase) para indicar a base da notação dos números.  
  
 O manipulator efetivamente chama `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::showbase`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [showbase](../standard-library/ios-functions.md#showbase) para ver um exemplo de como usar `noshowbase`.  
  
##  <a name="noshowpoint"></a>  noshowpoint  
 Exibe somente a parte de número inteiro de números de ponto flutuante cuja parte fracionária é zero.  
  
```  
ios_base& noshowpoint(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 `noshowpoint` é ativado por padrão; use [showpoint](../standard-library/ios-functions.md#showpoint) e [precision](../standard-library/ios-base-class.md#precision) para exibir os zeros após o ponto decimal.  
  
 O manipulator efetivamente chama `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::showpoint`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_noshowpoint.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   double f1= 5.000;  
   cout << f1 << endl;   // noshowpoint is default  
   cout.precision( 4 );  
   cout << showpoint << f1 << endl;  
   cout << noshowpoint << f1 << endl;  
}  
```  
  
```Output  
5  
5.000  
5  
```  
  
##  <a name="noshowpos"></a>  noshowpos  
 Faz com que números positivos não recebam sinalização explícita.  
  
```  
ios_base& noshowpos(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 `noshowpos` fica ativo por padrão.  
  
 O manipulator efetivamente chama `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::showps`), em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [showpos](../standard-library/ios-functions.md#showpos) para ver um exemplo de como usar `noshowpos`.  
  
##  <a name="noskipws"></a>  noskipws  
 Faz com que espaços sejam lidos pelo fluxo de entrada.  
  
```  
ios_base& noskipws(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, [skipws](../standard-library/ios-functions.md#skipws) está em vigor. Quando um espaço em branco é lido no fluxo de entrada, ele sinaliza o final do buffer.  
  
 O manipulator efetivamente chama `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::skipws`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_noskipws.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string>  
  
int main() {  
   using namespace std;     
   string s1, s2, s3;  
   cout << "Enter three strings: ";  
   cin >> noskipws >> s1 >> s2 >> s3;  
   cout << "." << s1  << "." << endl;  
   cout << "." << s2 << "." << endl;  
   cout << "." << s3 << "." << endl;     
}  
```  
  
##  <a name="nounitbuf"></a>  nounitbuf  
 Faz com que a saída seja armazenada em buffer e processada quando o buffer estiver cheio.  
  
```  
ios_base& nounitbuf(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 [unitbuf](../standard-library/ios-functions.md#unitbuf) faz com que o buffer seja processado quando não estiver vazio.  
  
 O manipulator efetivamente chama `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::unitbuf`) e, em seguida, retorna `str`.  
  
##  <a name="nouppercase"></a>  nouppercase  
 Especifica que dígitos hexadecimais e o expoente em notação científica apareçam em letras minúsculas.  
  
```  
ios_base& nouppercase(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 O manipulator efetivamente chama `str`.[ unsetf](../standard-library/ios-base-class.md#unsetf)( `ios_base::uppercase`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [uppercase](../standard-library/ios-functions.md#uppercase) para ver um exemplo de como usar `nouppercase`.  
  
##  <a name="oct"></a>  oct  
 Especifica que variáveis inteiras aparecem em notação de base 8.  
  
```  
ios_base& oct(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual *str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, variáveis inteiras são exibidas em notação de base 10. [dec](../standard-library/ios-functions.md#dec) e [hex](../standard-library/ios-functions.md#hex) também alteram a forma como as variáveis inteiras aparecem.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::oct`, `ios_base::basefield`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [dec](../standard-library/ios-functions.md#dec) para ver um exemplo de como usar **oct**.  
  
##  <a name="right"></a>  right  
 Faz com que um texto que não é tão largo quanto a largura de saída apareça no fluxo alinhado à margem direita.  
  
```  
ios_base& right(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual *str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 [left](../standard-library/ios-functions.md#left) também modifica a justificação do texto.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::right`, `ios_base::adjustfield`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_right.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   double f1= 5.00;  
   cout << f1 << endl;  
   cout.width( 20 );  
   cout << f1 << endl;  
   cout.width( 20 );  
   cout << left << f1 << endl;  
   cout.width( 20 );  
   cout << f1 << endl;  
   cout.width( 20 );  
   cout << right << f1 << endl;  
   cout.width( 20 );  
   cout << f1 << endl;  
}  
```  
  
```Output  
5  
                   5  
5                     
5                     
                   5  
                   5  
```  
  
##  <a name="scientific"></a>  scientific  
 Faz com que números de ponto flutuante sejam exibidos usando notação científica.  
  
```  
ios_base& scientific(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a notação [fixed](../standard-library/ios-functions.md#fixed) está em vigor para números de ponto flutuante.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::scientific`, `ios_base::floatfield`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_scientific.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   float i = 100.23F;  
  
   cout << i << endl;  
   cout << scientific << i << endl;  
}  
```  
  
```Output  
100.23  
1.002300e+002  
```  
  
##  <a name="showbase"></a>  showbase  
 Indica a base da notação em que um número é exibido.  
  
```  
ios_base& showbase(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 A base da notação de um número pode ser alterada com [dec](../standard-library/ios-functions.md#dec), [oct](../standard-library/ios-functions.md#oct) ou [hex](../standard-library/ios-functions.md#hex).  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::showbase`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_showbase.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   int j = 100;  
  
   cout << showbase << j << endl;   // dec is default  
   cout << hex << j << showbase << endl;  
   cout << oct << j << showbase << endl;  
  
   cout << dec << j << noshowbase << endl;  
   cout << hex << j << noshowbase << endl;  
   cout << oct << j << noshowbase << endl;  
}  
```  
  
```Output  
100  
0x64  
0144  
100  
64  
144  
```  
  
##  <a name="showpoint"></a>  showpoint  
 Exibe a parte de número inteiro de um número de ponto flutuante e os dígitos à direita do ponto decimal, mesmo quando a parte fracionária for zero.  
  
```  
ios_base& showpoint(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, [noshowpoint](../standard-library/ios-functions.md#noshowpoint) está em vigor.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::showpoint`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  Consulte [noshowpoint](../standard-library/ios-functions.md#noshowpoint) para ver um exemplo de como usar `showpoint`.  
  
##  <a name="showpos"></a>  showpos  
 Faz com que números positivos recebam sinalização explícita.  
  
```  
ios_base& showpos(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 [noshowpos](../standard-library/ios-functions.md#noshowpos) é o padrão.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::showpos`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_showpos.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   int i = 1;  
  
   cout << noshowpos << i << endl;   // noshowpos is default  
   cout << showpos << i << endl;  
}  
```  
  
```Output  
1  
+1  
```  
  
##  <a name="skipws"></a>  skipws  
 Faz com que espaços não sejam lidos pelo fluxo de entrada.  
  
```  
ios_base& skipws(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual _ *Str* é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `skipws` está em vigor. [noskipws](../standard-library/ios-functions.md#noskipws) faz com que espaços sejam lidos do fluxo de entrada.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( `ios_base::skipws`) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
#include <iostream>  
#include <string>  
  
int main( )   
{  
   using namespace std;  
   char s1, s2, s3;  
   cout << "Enter three characters: ";  
   cin >> skipws >> s1 >> s2 >> s3;  
   cout << "." << s1  << "." << endl;  
   cout << "." << s2 << "." << endl;  
   cout << "." << s3 << "." << endl;  
}  
```  
  
```Output  
  
1 2 3  
  
```  
  
```Output  
  
      1 2 3.1.  
.2.  
.3.  
```  
  
##  <a name="unitbuf"></a>  unitbuf  
 Faz com que a saída seja processada quando o buffer não estiver vazio.  
  
```  
ios_base& unitbuf(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual `str` é derivado.  
  
### <a name="remarks"></a>Comentários  
 Observe que `endl` também libera o buffer.  
  
 [nounitbuf](../standard-library/ios-functions.md#nounitbuf) está em vigor por padrão.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( [ios_base::unitbuf](../standard-library/ios-base-class.md#fmtflags)) e, em seguida, retorna `str`.  
  
##  <a name="uppercase"></a>  uppercase  
 Especifica que dígitos hexadecimais e o expoente em notação científica apareçam em letras maiúsculas.  
  
```  
ios_base& uppercase(ios_base& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto do qual `str` é derivado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, [nouppercase](../standard-library/ios-functions.md#nouppercase) está em vigor.  
  
 O manipulator efetivamente chama `str`.[ SETF](../standard-library/ios-base-class.md#setf)( [ios_base::uppercase](../standard-library/ios-base-class.md#fmtflags)) e, em seguida, retorna `str`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_uppercase.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( void )   
{  
   using namespace std;  
  
   double i = 1.23e100;  
   cout << i << endl;  
   cout << uppercase << i << endl;  
  
   int j = 10;  
   cout << hex << nouppercase << j << endl;  
   cout << hex << uppercase << j << endl;  
}  
```  
  
```Output  
1.23e+100  
1.23E+100  
a  
A  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<ios>](../standard-library/ios.md)


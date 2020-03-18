---
title: Funções &lt;ios&gt;
ms.date: 11/04/2016
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
helpviewer_keywords:
- std::defaultfloat [C++]
- std::boolalpha [C++]
- std::dec [C++]
- std::fixed [C++]
- std::hex [C++]
- std::hexfloat [C++]
- std::io_errc [C++]
- std::internal [C++]
- std::iostream_category [C++]
- std::is_error_code_enum [C++]
- std::left [C++]
- std::make_error_code [C++]
- std::make_error_condition [C++]
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
ms.openlocfilehash: c3b1e2350d0923cbfddf95492842ae126859e29f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421607"
---
# <a name="ltiosgt-functions"></a>Funções &lt;ios&gt;

## <a name="boolalpha"></a>boolalpha

Especifica que variáveis do tipo [bool](../cpp/bool-cpp.md) aparecem como **true** ou **false** no fluxo.

```cpp
ios_base& boolalpha(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, as variáveis do tipo **bool** são exibidas como 1 ou 0.

`boolalpha` chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)(`ios_base::boolalpha`) e, em seguida, retorna *Str*.

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

## <a name="dec"></a>dez

Especifica que variáveis inteiras aparecem em notação de base 10.

```cpp
ios_base& dec(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, variáveis inteiras são exibidas na base 10.

`dec` chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)(`ios_base::dec`, `ios_base::basefield`) e, em seguida, retorna *Str*.

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

## <a name="ios_defaultfloat"></a>&lt;Ios&gt; DefaultFloat

Configura os sinalizadores de um objeto `ios_base` para usar um formato de exibição padrão para valores do tipo float.

```cpp
ios_base& defaultfloat(ios_base& iosbase);
```

### <a name="parameters"></a>parâmetros

*_Iosbase*\
Um objeto `ios_base`.

### <a name="remarks"></a>Comentários

O manipulador chama efetivamente `iosbase.`[ios_base:: unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::floatfield)`, em seguida, retorna *iosbase*.

## <a name="fixed"></a>fixado

Especifica que um número de ponto flutuante é exibido em notação de decimal fixo.

```cpp
ios_base& fixed(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

`fixed` é a notação de exibição padrão para números de ponto flutuante. [scientific](../standard-library/ios-functions.md#scientific) faz com que números de ponto flutuante sejam exibidos usando notação científica.

O manipulador chama efetivamente o *Str*. [setf](../standard-library/ios-base-class.md#setf)(`ios_base::fixed`, `ios_base::floatfield`) e, em seguida, retorna *Str*.

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

## <a name="hex"></a>pressão

Especifica que variáveis inteiras devem aparecer em notação de base 16.

```cpp
ios_base& hex(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, variáveis inteiras são exibidas em notação de base 10. [dec](../standard-library/ios-functions.md#dec) e [oct](../standard-library/ios-functions.md#oct) também alteram a forma como as variáveis inteiras aparecem.

O manipulador chama efetivamente `str` **.** [setf](../standard-library/ios-base-class.md#setf)(`ios_base::hex`, `ios_base::basefield`) e, em seguida, retorna *Str*.

### <a name="example"></a>Exemplo

Consulte [Dec](../standard-library/ios-functions.md#dec) para obter um exemplo de como usar `hex`.

## <a name="hexfloat"></a>hexfloat

```cpp
ios_base& hexfloat (ios_base& str);
```

## <a name="io_errc"></a>io_errc

```cpp
enum class io_errc {
    stream = 1
};
```

## <a name="internal"></a>interno

Faz com que o sinal de um número seja justificado à esquerda e o número seja justificado à direita.

```cpp
ios_base& internal(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

[showpos](../standard-library/ios-functions.md#showpos) faz com que o sinal seja exibido para números positivos.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(`[ios_base:: Internal](../standard-library/ios-base-class.md#fmtflags)`, `[ios_base:: ajustarfield](../standard-library/ios-base-class.md#fmtflags)`)`e, em seguida, retorna *Str*.

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

## <a name="is_error_code_enum"></a>is_error_code_enum

```cpp
template <> struct is_error_code_enum<io_errc> : public true_type { };
```

## <a name="iostream_category"></a>iostream_category

```cpp
const error_category& iostream_category() noexcept;
```

## <a name="left"></a>mantida

Faz com que um texto que não é tão largo quanto a largura de saída apareça no fluxo alinhado à margem esquerda.

```cpp
ios_base& left(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::left, ios_base::adjustfield)`e, em seguida, retorna *Str*.

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

## <a name="make_error_code"></a>make_error_code

```cpp
error_code make_error_code(io_errc e) noexcept;
```

## <a name="make_error_condition"></a>make_error_condition

```cpp
error_condition make_error_condition(io_errc e) noexcept;
```

## <a name="noboolalpha"></a>noboolalpha

Especifica que variáveis do tipo [bool](../cpp/bool-cpp.md) apareçam como 1 ou 0 no fluxo.

```cpp
ios_base& noboolalpha(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, `noboolalpha` está em vigor.

`noboolalpha` chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::boolalpha)`e, em seguida, retorna *Str*.

[boolalpha](../standard-library/ios-functions.md#boolalpha) inverte o efeito de `noboolalpha`.

### <a name="example"></a>Exemplo

Consulte [boolalpha](../standard-library/ios-functions.md#boolalpha) para ver um exemplo de como usar `noboolalpha`.

## <a name="noshowbase"></a>noshowbase

Desativa a indicação da base da notação em que um número é exibido.

```cpp
ios_base& noshowbase(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

`noshowbase` está ativado por padrão. Use [showbase](../standard-library/ios-functions.md#showbase) para indicar a base da notação dos números.

O manipulador chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::showbase)`e, em seguida, retorna *Str*.

### <a name="example"></a>Exemplo

Consulte [showbase](../standard-library/ios-functions.md#showbase) para ver um exemplo de como usar `noshowbase`.

## <a name="noshowpoint"></a>noshowpoint

Exibe somente a parte de número inteiro de números de ponto flutuante cuja parte fracionária é zero.

```cpp
ios_base& noshowpoint(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

`noshowpoint` é ativado por padrão; use [showpoint](../standard-library/ios-functions.md#showpoint) e [precision](../standard-library/ios-base-class.md#precision) para exibir os zeros após o ponto decimal.

O manipulador chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::showpoint)`e, em seguida, retorna *Str*.

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

## <a name="noshowpos"></a>noshowpos

Faz com que números positivos não recebam sinalização explícita.

```cpp
ios_base& noshowpos(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

`noshowpos` está ativado por padrão.

O manipulador chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::showps)`e retorna *Str*.

### <a name="example"></a>Exemplo

Consulte [showpos](../standard-library/ios-functions.md#showpos) para ver um exemplo de como usar `noshowpos`.

## <a name="noskipws"></a>noskipws

Faz com que espaços sejam lidos pelo fluxo de entrada.

```cpp
ios_base& noskipws(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, [skipws](../standard-library/ios-functions.md#skipws) está em vigor. Quando um espaço em branco é lido no fluxo de entrada, ele sinaliza o final do buffer.

O manipulador chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::skipws)`e, em seguida, retorna *Str*.

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

## <a name="nounitbuf"></a>nounitbuf

Faz com que a saída seja armazenada em buffer e processada quando o buffer estiver cheio.

```cpp
ios_base& nounitbuf(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

[unitbuf](../standard-library/ios-functions.md#unitbuf) faz com que o buffer seja processado quando não estiver vazio.

O manipulador chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::unitbuf)`e, em seguida, retorna *Str*.

## <a name="nouppercase"></a>nomaiúsculo

Especifica que dígitos hexadecimais e o expoente em notação científica apareçam em letras minúsculas.

```cpp
ios_base& nouppercase(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

O manipulador chama efetivamente `str.`[unsetf](../standard-library/ios-base-class.md#unsetf)`(ios_base::uppercase)`e, em seguida, retorna *Str*.

### <a name="example"></a>Exemplo

Consulte [uppercase](../standard-library/ios-functions.md#uppercase) para ver um exemplo de como usar `nouppercase`.

## <a name="oct"></a>Outubro

Especifica que variáveis inteiras aparecem em notação de base 8.

```cpp
ios_base& oct(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, variáveis inteiras são exibidas em notação de base 10. [dec](../standard-library/ios-functions.md#dec) e [hex](../standard-library/ios-functions.md#hex) também alteram a forma como as variáveis inteiras aparecem.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::oct, ios_base::basefield)`e, em seguida, retorna *Str*.

### <a name="example"></a>Exemplo

Consulte [Dec](../standard-library/ios-functions.md#dec) para obter um exemplo de como usar `oct`.

## <a name="right"></a>Certo

Faz com que um texto que não é tão largo quanto a largura de saída apareça no fluxo alinhado à margem direita.

```cpp
ios_base& right(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

[left](../standard-library/ios-functions.md#left) também modifica a justificação do texto.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::right, ios_base::adjustfield)`e, em seguida, retorna *Str*.

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

## <a name="scientific"></a>científica

Faz com que números de ponto flutuante sejam exibidos usando notação científica.

```cpp
ios_base& scientific(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, a notação [fixed](../standard-library/ios-functions.md#fixed) está em vigor para números de ponto flutuante.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::scientific, ios_base::floatfield)`e, em seguida, retorna *Str*.

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

## <a name="showbase"></a>base de dados

Indica a base da notação em que um número é exibido.

```cpp
ios_base& showbase(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

A base da notação de um número pode ser alterada com [dec](../standard-library/ios-functions.md#dec), [oct](../standard-library/ios-functions.md#oct) ou [hex](../standard-library/ios-functions.md#hex).

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::showbase)`e, em seguida, retorna *Str*.

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

## <a name="showpoint"></a>ponto de extremidade

Exibe a parte de número inteiro de um número de ponto flutuante e os dígitos à direita do ponto decimal, mesmo quando a parte fracionária for zero.

```cpp
ios_base& showpoint(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, [noshowpoint](../standard-library/ios-functions.md#noshowpoint) está em vigor.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::showpoint)`e, em seguida, retorna *Str*.

### <a name="example"></a>Exemplo

Consulte [noshowpoint](../standard-library/ios-functions.md#noshowpoint) para ver um exemplo de como usar `showpoint`.

## <a name="showpos"></a>showpos

Faz com que números positivos recebam sinalização explícita.

```cpp
ios_base& showpos(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

[noshowpos](../standard-library/ios-functions.md#noshowpos) é o padrão.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::showpos)`e, em seguida, retorna *Str*.

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

## <a name="skipws"></a>skipws

Faz com que espaços não sejam lidos pelo fluxo de entrada.

```cpp
ios_base& skipws(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, `skipws` está em vigor. [noskipws](../standard-library/ios-functions.md#noskipws) faz com que espaços sejam lidos do fluxo de entrada.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(ios_base::skipws)`e, em seguida, retorna *Str*.

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

```Input
1 2 3
```

```Output
Enter three characters: 1 2 3
.1.
.2.
.3.
```

## <a name="unitbuf"></a>unitbuf

Faz com que a saída seja processada quando o buffer não estiver vazio.

```cpp
ios_base& unitbuf(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Observe que `endl` também libera o buffer.

[nounitbuf](../standard-library/ios-functions.md#nounitbuf) está em vigor por padrão.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(`[ios_base:: unitbuf](../standard-library/ios-base-class.md#fmtflags)`)`e, em seguida, retorna *Str*.

## <a name="uppercase"></a>  uppercase

Especifica que dígitos hexadecimais e o expoente em notação científica apareçam em letras maiúsculas.

```cpp
ios_base& uppercase(ios_base& str);
```

### <a name="parameters"></a>parâmetros

\ de *Str*
Uma referência a um objeto do tipo [ios_base](../standard-library/ios-base-class.md) ou um tipo que herda de `ios_base`.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto do qual o *Str* é derivado.

### <a name="remarks"></a>Comentários

Por padrão, [nouppercase](../standard-library/ios-functions.md#nouppercase) está em vigor.

O manipulador chama efetivamente `str.`[setf](../standard-library/ios-base-class.md#setf)`(`[ios_base:: maiúscula](../standard-library/ios-base-class.md#fmtflags)`)`e, em seguida, retorna *Str*.

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

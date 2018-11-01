---
title: Funções &lt;iomanip&gt;
ms.date: 11/04/2016
f1_keywords:
- iomanip/std::get_money
- iomanip/std::get_time
- iomanip/std::put_money
- iomanip/std::put_time
- iomanip/std::quoted
- iomanip/std::resetiosflags
- iomanip/std::setbase
- iomanip/std::setfill
- iomanip/std::setiosflags
- iomanip/std::setprecision
- iomanip/std::setw
ms.assetid: 3ddde610-70cc-4cfa-8a89-3e83d1d356a8
helpviewer_keywords:
- std::get_money [C++]
- std::get_time [C++]
- std::put_money [C++]
- std::put_time [C++]
- std::quoted [C++]
- std::resetiosflags [C++]
- std::setbase [C++]
- std::setfill [C++]
- std::setiosflags [C++]
- std::setprecision [C++]
- std::setw [C++]
ms.openlocfilehash: 3df26de9ef485bc7214e49ce96680cc7300adb93
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50574311"
---
# <a name="ltiomanipgt-functions"></a>Funções &lt;iomanip&gt;

||||
|-|-|-|
|[get_money](#iomanip_get_money)|[get_time](#iomanip_get_time)|[put_money](#iomanip_put_money)|
|[put_time](#iomanip_put_time)|[quoted](#quoted)|[resetiosflags](#resetiosflags)|
|[setbase](#setbase)|[setfill](#setfill)|[setiosflags](#setiosflags)|
|[setprecision](#setprecision)|[setw](#setw)|

## <a name="iomanip_get_money"></a>  get_money

Extrai um valor monetário de um fluxo usando o formato desejado e retorna o valor em um parâmetro.

```cpp
template <class Money>
T7 get_money(Money& _Amount, bool _Intl);
```

### <a name="parameters"></a>Parâmetros

*Amount*<br/>
O valor monetário extraído.

*_Intl*<br/>
Se **verdadeira**, use o formato internacional. O valor padrão é **false**.

### <a name="remarks"></a>Comentários

O manipulador retorna um objeto que, quando extraído do fluxo `str`, se comporta como uma `formatted input function` que chama a função de membro `get` para a faceta de localidade `money_get` associados `str`usando *_ Intl* para indicar o formato internacional. Se for bem-sucedido, a chamada armazena em *Amount* o valor monetário extraído. O manipulador, então, retorna `str`.

`Money` deve ser do tipo `long double` ou uma instanciação de `basic_string` com os mesmos parâmetros de elemento e características que `str`.

## <a name="iomanip_get_time"></a>  get_time

Extrai um valor temporal de um fluxo usando um formato desejado. Retorna o valor em um parâmetro como uma estrutura de tempo.

```cpp
template <class Elem>
T10 put_time(struct tm *_Tptr, const Elem *_Fmt);
```

### <a name="parameters"></a>Parâmetros

*_Tptr*<br/>
O tempo na forma de uma estrutura de tempo.

*_Fmt*<br/>
O formato desejado a ser usado para obter o valor temporal.

### <a name="remarks"></a>Comentários

O manipulador retorna um objeto que, quando extraído do fluxo `str`, se comporta como um `formatted input function` que chama a função membro `get` para a faceta de localidade `time_get` associada a `str`, usando `tptr` para indicar a estrutura de tempo e `fmt` para indicar o início de uma cadeia de caracteres de formato terminada em nulo. Se for bem-sucedida, a chamada armazena na estrutura de tempo os valores associados aos campos de tempo extraídos. O manipulador, então, retorna `str`.

## <a name="iomanip_put_money"></a>  put_money

Insere um valor monetário usando o formato desejado em um fluxo.

```cpp
template <class Money>
T8 put_money(const Money& _Amount, bool _Intl);
```

### <a name="parameters"></a>Parâmetros

*Amount*<br/>
O valor monetário a ser inserido no fluxo.

*_Intl*<br/>
Definido como **verdadeira** se o manipulador precisar usar o formato internacional, **falso** se não for.

### <a name="return-value"></a>Valor de retorno

Retorna `str`.

### <a name="remarks"></a>Comentários

O manipulador retorna um objeto que, quando inserido no fluxo `str`, se comporta como uma função de saída formatada que chama a função membro `put` para a faceta de localidade `money_put` associada a `str`. Se for bem-sucedido, a chamada insere `amount` formatado adequadamente, usando * _Intl` to indicate international format and `str.fill()`, as the fill element. The manipulator then returns `str'.

`Money` deve ser do tipo `long double` ou uma instanciação de `basic_string` com os mesmos parâmetros de elemento e características que `str`.

## <a name="iomanip_put_time"></a>  put_time

Grava um valor temporal de uma estrutura de tempo em um fluxo usando um formato especificado.

```cpp
template <class Elem>
T10 put_time(struct tm* _Tptr, const Elem* _Fmt);
```

### <a name="parameters"></a>Parâmetros

*_Tptr*<br/>
O valor temporal a ser gravado no fluxo, fornecido em uma estrutura de tempo.

*_Fmt*<br/>
O formato desejado para gravar o valor temporal.

### <a name="remarks"></a>Comentários

O manipulador retorna um objeto que, quando inserido no fluxo `str`, se comporta como `formatted output function`. A função de saída chama a função membro `put` para a faceta de localidade `time_put` associada a `str`. Usa a função de saída *_Tptr* para indicar a estrutura de tempo e *_Fmt* para indicar o início de uma cadeia de caracteres de formato terminada em nulo. Se for bem-sucedida, a chamada insere texto literal da cadeia de caracteres de formato e valores convertidos da estrutura de hora. O manipulador, então, retorna `str`.

## <a name="quoted"></a>  quoted

**(Novo no C++14)**  Um manipulador de iostream que permite o ciclo conveniente de cadeias de caracteres, entrando e saindo de fluxos, usando os operadores >> e <<.

```cpp
quoted(std::string str) // or wstring
quoted(const char* str) //or wchar_t*
quoted(std::string str, char delimiter, char escape) // or wide versions
quoted(const char* str, char delimiter, char escape) // or wide versions
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Um std:: String, char\*, cadeia de caracteres literal de cadeia de caracteres literal ou brutos ou uma versão larga de qualquer um deles (por exemplo, std:: wstring, wchar_t\*).

*delimitador*<br/>
Um caractere especificado pelo usuário, ou caractere largo, a ser usado como delimitador para o início e o fim da cadeia de caracteres.

*escape*<br/>
Um caractere especificado pelo usuário, ou caractere largo, a ser usado como caractere de escape para sequências de escape na cadeia de caracteres.

### <a name="remarks"></a>Comentários

Consulte [Usando operadores de inserção e controlando o formato](../standard-library/using-insertion-operators-and-controlling-format.md).

### <a name="example"></a>Exemplo

Este exemplo mostra como usar `quoted` com o delimitador padrão e o caractere de escape usando cadeias de caracteres estreitas. Cadeias de caracteres largas também têm suporte.

```cpp
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void show_quoted_v_nonquoted()
{
    // Results are identical regardless of input string type:
    // string inserted { R"(This is a "sentence".)" }; // raw string literal
    // string inserted { "This is a \"sentence\"." };  // regular string literal
    const char* inserted = "This is a \"sentence\".";  // const char*
    stringstream ss, ss_quoted;
    string extracted, extracted_quoted;

    ss << inserted;
    ss_quoted << quoted(inserted);

    cout << "ss.str() is storing       : " << ss.str() << endl;
    cout << "ss_quoted.str() is storing: " << ss_quoted.str() << endl << endl;

    // Round-trip the strings
    ss >> extracted;
    ss_quoted >> quoted(extracted_quoted);

    cout << "After round trip: " << endl;
    cout << "Non-quoted      : " << extracted << endl;
    cout << "Quoted          : " << extracted_quoted << endl;
}

void main(int argc, char* argv[])
{
    show_quoted_v_nonquoted();

    // Keep console window open in debug mode.
    cout << endl << "Press Enter to exit" << endl;
    string input{};
    getline(cin, input);
}

/* Output:
ss.str() is storing       : This is a "sentence".
ss_quoted.str() is storing: "This is a \"sentence\"."

After round trip:
Non-quoted      : This
Quoted          : This is a "sentence".

Press Enter to exit
*/
```

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como fornecer um caractere delimitador e/ou de escape personalizado:

```cpp
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void show_custom_delimiter()
{
    string inserted{ R"("This" "is" "a" "heavily-quoted" "sentence".)" };
    // string inserted{ "\"This\" \"is\" \"a\" \"heavily-quoted\" \"sentence\"" };
    // const char* inserted{ "\"This\" \"is\" \"a\" \"heavily-quoted\" \"sentence\"" };
    stringstream ss, ss_quoted;
    string extracted;

    ss_quoted << quoted(inserted, '*');
    ss << inserted;
    cout << "ss_quoted.str() is storing: " << ss_quoted.str() << endl;
    cout << "ss.str() is storing       : " << ss.str() << endl << endl;

    // Use the same quoted arguments as on insertion.
    ss_quoted >> quoted(extracted, '*');

    cout << "After round trip: " << endl;
    cout << "Quoted          : " << extracted << endl;

    extracted = {};
    ss >> extracted;
    cout << "Non-quoted      : " << extracted << endl << endl;
}

void show_custom_escape()
{
    string inserted{ R"(\\root\trunk\branch\nest\egg\yolk)" };
    // string inserted{ "\\\\root\\trunk\\branch\\nest\\egg\\yolk" };
    stringstream ss, ss_quoted, ss_quoted_custom;
    string extracted;

    // Use '"' as delimiter and '~' as escape character.
    ss_quoted_custom << quoted(inserted, '"', '~');
    ss_quoted << quoted(inserted);
    ss << inserted;
    cout << "ss_quoted_custom.str(): " << ss_quoted_custom.str() << endl;
    cout << "ss_quoted.str()       : " << ss_quoted.str() << endl;
    cout << "ss.str()              : " << ss.str() << endl << endl;

    // No spaces in this string, so non-quoted behaves same as quoted
    // after round-tripping.
}

void main(int argc, char* argv[])
{
    cout << "Custom delimiter:" << endl;
    show_custom_delimiter();
    cout << "Custom escape character:" << endl;
    show_custom_escape();

    // Keep console window open in debug mode.
    cout << endl << "Press Enter to exit" << endl;
    string input{};
    getline(cin, input);
}
/* Output:
Custom delimiter:
ss_quoted.str() is storing: *"This" "is" "a" "heavily-quoted" "sentence".*
ss.str() is storing       : "This" "is" "a" "heavily-quoted" "sentence".

After round trip:
Quoted          : "This" "is" "a" "heavily-quoted" "sentence".
Non-quoted      : "This"

Custom escape character:
ss_quoted_custom.str(): "\\root\trunk\branch\nest\egg\yolk"
ss_quoted.str()       : "\\\\root\\trunk\\branch\\nest\\egg\\yolk"
ss.str()              : \\root\trunk\branch\nest\egg\yolk

Press Enter to exit
*/

```

## <a name="resetiosflags"></a>  resetiosflags

Limpa os sinalizadores especificados.

```cpp
T1 resetiosflags(ios_base::fmtflags Mask);
```

### <a name="parameters"></a>Parâmetros

*Máscara*<br/>
Os sinalizadores a limpar.

### <a name="return-value"></a>Valor de retorno

O manipulador retorna um objeto que, quando extraído ou inserido no fluxo `str`, chamadas **str**. [SETF](../standard-library/ios-base-class.md#setf)( `ios_base::` [fmtflags](../standard-library/ios-base-class.md#fmtflags), _ *máscara*) e, em seguida, retorna `str`.

### <a name="example"></a>Exemplo

Consulte [setw](../standard-library/iomanip-functions.md#setw) para ver um exemplo de como usar `resetiosflags`.

## <a name="setbase"></a>  setbase

Define a base para inteiros.

```cpp
T3 setbase(int _Base);
```

### <a name="parameters"></a>Parâmetros

*Base*<br/>
A base numérica.

### <a name="return-value"></a>Valor de retorno

O manipulador retorna um objeto que, quando extraído ou inserido no fluxo `str`, chamadas **str**. `setf`( **máscara**, [ios_base:: BaseField](../standard-library/ios-base-class.md#fmtflags)) e, em seguida, retorna `str`. Aqui, `mask` é determinado da seguinte maneira:

- Se _ *Base* for 8, então `mask` é `ios_base::` [oct](../standard-library/ios-functions.md#oct).

- Se _ *Base* for 10, então mask será `ios_base::`[dec](../standard-library/ios-functions.md#dec).

- Se _ *Base* for 16, então `mask` é `ios_base::` [hex](../standard-library/ios-functions.md#hex).

- Se _ *Base* for qualquer outro valor, então mask será `ios_base::`[fmtflags](../standard-library/ios-base-class.md#fmtflags)(0).

### <a name="example"></a>Exemplo

Consulte [setw](../standard-library/iomanip-functions.md#setw) para ver um exemplo de como usar `setbase`.

## <a name="setfill"></a>  setfill

Define o caractere que será usado para preencher espaços em uma exibição justificada à direita.

```cpp
template <class Elem>
T4 setfill(Elem Ch);
```

### <a name="parameters"></a>Parâmetros

*CH*<br/>
O caractere que será usado para preencher espaços em uma exibição justificada à direita.

### <a name="return-value"></a>Valor de retorno

O manipulador de modelo retorna um objeto que, quando extraído ou inserido no fluxo `str`, chamadas **str**. [preenchimento](../standard-library/basic-ios-class.md#fill)(`Ch`) e, em seguida, retorna `str`. O tipo `Elem` deve ser o mesmo que o tipo de elemento para o fluxo `str`.

### <a name="example"></a>Exemplo

Consulte [setw](../standard-library/iomanip-functions.md#setw) para ver um exemplo de como usar `setfill`.

## <a name="setiosflags"></a>  setiosflags

Define os sinalizadores especificados.

```cpp
T2 setiosflags(ios_base::fmtflags Mask);
```

### <a name="parameters"></a>Parâmetros

*Máscara*<br/>
Os sinalizadores a serem definidos.

### <a name="return-value"></a>Valor de retorno

O manipulador retorna um objeto que, quando extraído ou inserido no fluxo `str`, chamadas **str**. [SETF](../standard-library/ios-base-class.md#setf)(_ *máscara*) e, em seguida, retorna `str`.

### <a name="example"></a>Exemplo

Consulte [setw](../standard-library/iomanip-functions.md#setw) para ver um exemplo de como usar `setiosflags`.

## <a name="setprecision"></a>  setprecision

Define a precisão dos valores de ponto flutuante.

```cpp
T5 setprecision(streamsize Prec);
```

### <a name="parameters"></a>Parâmetros

*prec*<br/>
A precisão dos valores de ponto flutuante.

### <a name="return-value"></a>Valor de retorno

O manipulador retorna um objeto que, quando extraído ou inserido no fluxo `str`, chamadas **str**. [precisão](../standard-library/ios-base-class.md#precision)(`Prec`) e, em seguida, retorna `str`.

### <a name="example"></a>Exemplo

Consulte [setw](../standard-library/iomanip-functions.md#setw) para ver um exemplo de como usar `setprecision`.

## <a name="setw"></a>  setw

Especifica a largura do campo de exibição para o elemento seguinte no fluxo.

```cpp
T6 setw(streamsize Wide);
```

### <a name="parameters"></a>Parâmetros

*Ampla*<br/>
A largura do campo de exibição.

### <a name="return-value"></a>Valor de retorno

O manipulador retorna um objeto que, quando extraído ou inserido no fluxo `str`, chamadas **str**. [largura](../standard-library/ios-base-class.md#width)(_ *ampla*), em seguida, retorna `str`.

### <a name="remarks"></a>Comentários

setw define a largura somente para o elemento seguinte no fluxo e deve ser inserido antes de cada elemento cuja largura você deseja especificar.

### <a name="example"></a>Exemplo

```cpp
// iomanip_setw.cpp
// compile with: /EHsc
// Defines the entry point for the console application.
//
// Sample use of the following manipulators:
//   resetiosflags
//   setiosflags
//   setbase
//   setfill
//   setprecision
//   setw

#include <iostream>
#include <iomanip>

using namespace std;

const double   d1 = 1.23456789;
const double   d2 = 12.3456789;
const double   d3 = 123.456789;
const double   d4 = 1234.56789;
const double   d5 = 12345.6789;
const long      l1 = 16;
const long      l2 = 256;
const long      l3 = 1024;
const long      l4 = 4096;
const long      l5 = 65536;
int         base = 10;

void DisplayDefault( )
{
   cout << endl << "default display" << endl;
   cout << "d1 = " << d1 << endl;
   cout << "d2 = " << d2 << endl;
   cout << "d3 = " << d3 << endl;
   cout << "d4 = " << d4 << endl;
   cout << "d5 = " << d5 << endl;
}

void DisplayWidth( int n )
{
   cout << endl << "fixed width display set to " << n << ".\n";
   cout << "d1 = " << setw(n) << d1 << endl;
   cout << "d2 = " << setw(n) << d2 << endl;
   cout << "d3 = " << setw(n) << d3 << endl;
   cout << "d4 = " << setw(n) << d4 << endl;
   cout << "d5 = " << setw(n) << d5 << endl;
}

void DisplayLongs( )
{
   cout << setbase(10);
   cout << endl << "setbase(" << base << ")" << endl;
   cout << setbase(base);
   cout << "l1 = " << l1 << endl;
   cout << "l2 = " << l2 << endl;
   cout << "l3 = " << l3 << endl;
   cout << "l4 = " << l4 << endl;
   cout << "l5 = " << l5 << endl;
}

int main( int argc, char* argv[] )
{
   DisplayDefault( );

   cout << endl << "setprecision(" << 3 << ")" << setprecision(3);
   DisplayDefault( );

   cout << endl << "setprecision(" << 12 << ")" << setprecision(12);
   DisplayDefault( );

   cout << setiosflags(ios_base::scientific);
   cout << endl << "setiosflags(" << ios_base::scientific << ")";
   DisplayDefault( );

   cout << resetiosflags(ios_base::scientific);
   cout << endl << "resetiosflags(" << ios_base::scientific << ")";
   DisplayDefault( );

   cout << endl << "setfill('" << 'S' << "')" << setfill('S');
   DisplayWidth(15);
   DisplayDefault( );

   cout << endl << "setfill('" << ' ' << "')" << setfill(' ');
   DisplayWidth(15);
   DisplayDefault( );

   cout << endl << "setprecision(" << 8 << ")" << setprecision(8);
   DisplayWidth(10);
   DisplayDefault( );

   base = 16;
   DisplayLongs( );

   base = 8;
   DisplayLongs( );

   base = 10;
   DisplayLongs( );

   return   0;
}
```

```Output

default display
d1 = 1.23457
d2 = 12.3457
d3 = 123.457
d4 = 1234.57
d5 = 12345.7

setprecision(3)
default display
d1 = 1.23
d2 = 12.3
d3 = 123
d4 = 1.23e+003
d5 = 1.23e+004

setprecision(12)
default display
d1 = 1.23456789
d2 = 12.3456789
d3 = 123.456789
d4 = 1234.56789
d5 = 12345.6789

setiosflags(4096)
default display
d1 = 1.234567890000e+000
d2 = 1.234567890000e+001
d3 = 1.234567890000e+002
d4 = 1.234567890000e+003
d5 = 1.234567890000e+004

resetiosflags(4096)
default display
d1 = 1.23456789
d2 = 12.3456789
d3 = 123.456789
d4 = 1234.56789
d5 = 12345.6789

setfill('S')
fixed width display set to 15.
d1 = SSSSS1.23456789
d2 = SSSSS12.3456789
d3 = SSSSS123.456789
d4 = SSSSS1234.56789
d5 = SSSSS12345.6789

default display
d1 = 1.23456789
d2 = 12.3456789
d3 = 123.456789
d4 = 1234.56789
d5 = 12345.6789

setfill(' ')
fixed width display set to 15.
d1 =      1.23456789
d2 =      12.3456789
d3 =      123.456789
d4 =      1234.56789
d5 =      12345.6789

default display
d1 = 1.23456789
d2 = 12.3456789
d3 = 123.456789
d4 = 1234.56789
d5 = 12345.6789

setprecision(8)
fixed width display set to 10.
d1 =  1.2345679
d2 =  12.345679
d3 =  123.45679
d4 =  1234.5679
d5 =  12345.679

default display
d1 = 1.2345679
d2 = 12.345679
d3 = 123.45679
d4 = 1234.5679
d5 = 12345.679

setbase(16)
l1 = 10
l2 = 100
l3 = 400
l4 = 1000
l5 = 10000

setbase(8)
l1 = 20
l2 = 400
l3 = 2000
l4 = 10000
l5 = 200000

setbase(10)
l1 = 16
l2 = 256
l3 = 1024
l4 = 4096
l5 = 65536
```

## <a name="see-also"></a>Consulte também

[\<iomanip>](../standard-library/iomanip.md)<br/>

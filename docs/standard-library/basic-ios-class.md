---
title: Classe basic_ios
ms.date: 11/04/2016
f1_keywords:
- ios/std::basic_ios
- ios/std::basic_ios::char_type
- ios/std::basic_ios::int_type
- ios/std::basic_ios::off_type
- ios/std::basic_ios::pos_type
- ios/std::basic_ios::traits_type
- ios/std::basic_ios::bad
- ios/std::basic_ios::clear
- ios/std::basic_ios::copyfmt
- ios/std::basic_ios::eof
- ios/std::basic_ios::exceptions
- ios/std::basic_ios::fail
- ios/std::basic_ios::fill
- ios/std::basic_ios::good
- ios/std::basic_ios::imbue
- ios/std::basic_ios::init
- ios/std::basic_ios::move
- ios/std::basic_ios::narrow
- ios/std::basic_ios::rdbuf
- ios/std::basic_ios::rdstate
- ios/std::basic_ios::set_rdbuf
- ios/std::basic_ios::setstate
- ios/std::basic_ios::swap
- ios/std::basic_ios::tie
- ios/std::basic_ios::widen
- ios/std::basic_ios::explicit operator bool
helpviewer_keywords:
- std::basic_ios [C++]
- std::basic_ios [C++], char_type
- std::basic_ios [C++], int_type
- std::basic_ios [C++], off_type
- std::basic_ios [C++], pos_type
- std::basic_ios [C++], traits_type
- std::basic_ios [C++], bad
- std::basic_ios [C++], clear
- std::basic_ios [C++], copyfmt
- std::basic_ios [C++], eof
- std::basic_ios [C++], exceptions
- std::basic_ios [C++], fail
- std::basic_ios [C++], fill
- std::basic_ios [C++], good
- std::basic_ios [C++], imbue
- std::basic_ios [C++], init
- std::basic_ios [C++], move
- std::basic_ios [C++], narrow
- std::basic_ios [C++], rdbuf
- std::basic_ios [C++], rdstate
- std::basic_ios [C++], set_rdbuf
- std::basic_ios [C++], setstate
- std::basic_ios [C++], swap
- std::basic_ios [C++], tie
- std::basic_ios [C++], widen
ms.assetid: 4fdcd8e1-62d2-4611-8a70-1e4f58434007
ms.openlocfilehash: ab8e9e0243a298f5ef39b38b3fd345572cafa587
ms.sourcegitcommit: 8caaf5e00aeb727741a273aecafa15de293426cf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2020
ms.locfileid: "91806547"
---
# <a name="basic_ios-class"></a>Classe basic_ios

O modelo de classe descreve as funções de armazenamento e membro comuns a fluxos de entrada (do modelo de classe [basic_istream](../standard-library/basic-istream-class.md)) e fluxos de saída (do modelo de classe [basic_ostream](../standard-library/basic-ostream-class.md)) que dependem dos parâmetros do modelo. (A classe [ios_base](../standard-library/ios-base-class.md) descreve o que é comum e não depende de parâmetros de modelo.) Um objeto da classe **basic_ios \<class Elem, class Traits> ** ajuda a controlar um fluxo com elementos do tipo `Elem` , cujas características de caractere são determinadas pela classe `Traits` .

## <a name="syntax"></a>Sintaxe

```cpp

template <class Elem, class Traits>
class basic_ios : public ios_base
```

### <a name="parameters"></a>Parâmetros

*Elem*\
Um tipo de caractere.

*Características*\
Um tipo que fornece informações sobre o tipo de caractere, usa como padrão `char_traits < Elem >` .

## <a name="remarks"></a>Comentários

Um objeto da classe **basic_ios \<class Elem, class Traits> ** armazena:

- Um ponteiro de ligação para um objeto do tipo [basic_istream](../standard-library/basic-istream-class.md) **\<Elem, Traits>** .

- Um ponteiro de buffer de fluxo para um objeto do tipo [basic_streambuf](../standard-library/basic-streambuf-class.md) **\<Elem, Traits >** .

- [Informações de formatação](../standard-library/ios-base-class.md).

- [Informações de estado de fluxo](../standard-library/ios-base-class.md) em um objeto base do tipo [ios_base](../standard-library/ios-base-class.md).

- Um caractere de preenchimento em um objeto do tipo `char_type`.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_ios](#basic_ios)|Constrói a classe `basic_ios`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um sinônimo para o parâmetro de modelo `Elem`.|
|[int_type](#int_type)|Um sinônimo de `Traits::int_type`.|
|[off_type](#off_type)|Um sinônimo de `Traits::off_type`.|
|[pos_type](#pos_type)|Um sinônimo de `Traits::pos_type`.|
|[traits_type](#traits_type)|Um sinônimo para o parâmetro de modelo `Traits`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[ruim](#bad)|Indica a perda de integridade do buffer de fluxo.|
|[clear](#clear)|Limpa todos os sinalizadores de erro.|
|[copyfmt](#copyfmt)|Copia sinalizadores de um fluxo para outro.|
|[EOF](#eof)|Indica se o final de um fluxo foi atingido.|
|[exceptions](#exceptions)|Indica quais exceções serão lançadas pelo fluxo.|
|[recuperação](#fail)|Indica falha ao extrair um campo válido de um fluxo.|
|[ficar](#fill)|Especifica ou retorna o caractere que será usado quando o texto não for tão grande quanto o fluxo.|
|[good](#good)|Indica que o fluxo está em boas condições.|
|[imbue](#imbue)|Altera a localidade.|
|[init](#init)|Chamado por construtores `basic_ios`.|
|[move](#move)|Move todos os valores, exceto o ponteiro para o buffer de fluxo, do parâmetro para o objeto atual.|
|[narrow](#narrow)|Localiza o char equivalente para um determinado `char_type`.|
|[rdbuf](#rdbuf)|Encaminha o fluxo para um buffer especificado.|
|[rdstate](#rdstate)|Lê o estado dos bits para sinalizadores.|
|[set_rdbuf](#set_rdbuf)|Atribui um buffer de fluxo para ser o buffer de leitura para esse objeto de fluxo.|
|[setstate](#setstate)|Define sinalizadores adicionais.|
|[permuta](#swap)|Troca os valores nesse objeto `basic_ios` por aqueles de outro objeto `basic_ios`. Os ponteiros para buffers de fluxo não são trocados.|
|[tie](#tie)|Garante que um fluxo seja processado antes de outro.|
|[widen](#widen)|Localiza o `char_type` equivalente a um determinado char.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[explicit operator bool](#op_bool)|Permite o uso de um `basic_ios` objeto como um **`bool`** . Conversão de tipo automática é desabilitada para evitar efeitos colaterais comuns não intencionais.|
|[operator void *](#op_void_star)|Indica se o fluxo ainda é válido.|
|[operador!](#op_not)|Indica se o fluxo não é inválido.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<ios>

**Namespace:** std

## <a name="basic_iosbad"></a><a name="bad"></a> basic_ios:: inadequado

Indica a perda de integridade do buffer de fluxo

```cpp
bool bad() const;
```

### <a name="return-value"></a>Valor Retornado

**`true`** Se `rdstate & badbit` for diferente de zero; caso contrário, **`false`** .

Para obter mais informações sobre `badbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_bad.cpp
// compile with: /EHsc
#include <iostream>

int main( void )
{
    using namespace std;
    bool b = cout.bad( );
    cout << boolalpha;
    cout << b << endl;

    b = cout.good( );
    cout << b << endl;
}
```

## <a name="basic_iosbasic_ios"></a><a name="basic_ios"></a> basic_ios:: basic_ios

Constrói a classe basic_ios.

```cpp
explicit basic_ios(basic_streambuf<Elem,  Traits>* sb);
basic_ios();
```

### <a name="parameters"></a>Parâmetros

*SB*\
Buffer padrão para armazenar elementos de entrada ou saída.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa seus objetos de membro chamando [init](#init)(_ *Sb*). O segundo construtor (protegido) deixa seus objetos do membro não inicializados. Uma chamada posterior para `init` deve inicializar o objeto antes que ele possa ser destruído com segurança.

## <a name="basic_ioschar_type"></a><a name="char_type"></a> basic_ios:: char_type

Um sinônimo para o parâmetro de modelo `Elem`.

```cpp
typedef Elem char_type;
```

## <a name="basic_iosclear"></a><a name="clear"></a> basic_ios:: Clear

Limpa todos os sinalizadores de erro.

```cpp
void clear(iostate state = goodbit, bool reraise = false);
void clear(io_state state);
```

### <a name="parameters"></a>Parâmetros

*status*\
Adicional Os sinalizadores que você deseja definir depois de limpar todos os sinalizadores. Assume o padrão de `goodbit`.

*reraise*\
Adicional Especifica se a exceção deve ser gerada novamente. O padrão é **`false`** (não irá gerar novamente a exceção).

### <a name="remarks"></a>Comentários

Os sinalizadores são `goodbit` , `failbit` , `eofbit` e `badbit` . Teste esses sinalizadores com [good](#good), [bad](#bad), [eof](#eof) e [fail](#fail)

A função de membro substitui as informações de estado de fluxo armazenadas com:

`state` &#124; `(`[rdbuf](#rdbuf) != 0 **goodbit** : **badbit**)

Se as `state` **&** [exceções](#exceptions) forem diferentes de zero, ele gera um objeto de [falha](../standard-library/ios-base-class.md#failure)de classe.

### <a name="example"></a>Exemplo

Consulte [rdstate](#rdstate) e [getline](../standard-library/string-functions.md#getline) para obter exemplos usando `clear` .

## <a name="basic_ioscopyfmt"></a><a name="copyfmt"></a> basic_ios:: copyfmt

Copia sinalizadores de um fluxo para outro.

```cpp
basic_ios<Elem, Traits>& copyfmt(
const basic_ios<Elem, Traits>& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O fluxo cujos sinalizadores você deseja copiar.

### <a name="return-value"></a>Valor Retornado

O **`this`** objeto para o fluxo para o qual você está copiando os sinalizadores.

### <a name="remarks"></a>Comentários

A função membro relata o evento de **apagamento \_ **de eventos de retorno de chamada. Em seguida, ele copia da *direita* para ** \* esse** caractere de preenchimento, o ponteiro de ligação e as informações de formatação. Antes de alterar a máscara de exceção, ele relata o evento de retorno de chamada `copyfmt_event` . Se, após a cópia estar concluída, **state &**[exceptions](#exceptions) for diferente de zero, a função chamará [clear](#clear) efetivamente com o argumento [rdstate](#rdstate). Ele retorna ** \* isso**.

### <a name="example"></a>Exemplo

```cpp
// basic_ios_copyfmt.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
    using namespace std;
    ofstream x( "test.txt" );
    int i = 10;

    x << showpos;
    cout << i << endl;
    cout.copyfmt( x );
    cout << i << endl;
}
```

## <a name="basic_ioseof"></a><a name="eof"></a> basic_ios:: EOF

Indica se o final de um fluxo foi atingido.

```cpp
bool eof() const;
```

### <a name="return-value"></a>Valor Retornado

**`true`** Se o final do fluxo tiver sido atingido, **`false`** caso contrário.

### <a name="remarks"></a>Comentários

A função membro retornará **`true`** se [rdstate](#rdstate) `& eofbit` for diferente de zero. Para obter mais informações sobre `eofbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_eof.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{
    fstream   fs;
    int n = 1;
    fs.open( "basic_ios_eof.txt" );   // an empty file
    cout << boolalpha
    cout << fs.eof() << endl;
    fs >> n;   // Read the char in the file
    cout << fs.eof() << endl;
}
```

## <a name="basic_iosexceptions"></a><a name="exceptions"></a> basic_ios:: exceções

Indica quais exceções serão lançadas pelo fluxo.

```cpp
iostate exceptions() const;
void exceptions(iostate Newexcept);
void exceptions(io_state Newexcept);
```

### <a name="parameters"></a>Parâmetros

*Newexcept*\
Os sinalizadores que você deseja que gerem uma exceção.

### <a name="return-value"></a>Valor Retornado

Os sinalizadores atualmente especificados para gerar uma exceção para o fluxo.

### <a name="remarks"></a>Comentários

A primeira função membro retorna a máscara de exceção armazenada. A segunda função membro armazena *_Except* na máscara de exceção e retorna seu valor armazenado anterior. Observe que armazenar uma nova máscara de exceção pode lançar uma exceção assim como a chamada [clear](#clear)( [rdstate](#rdstate) ).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_exceptions.cpp
// compile with: /EHsc /GR
#include <iostream>

int main( )
{
    using namespace std;

    cout << cout.exceptions( ) << endl;
    cout.exceptions( ios::eofbit );
    cout << cout.exceptions( ) << endl;
    try
    {
        cout.clear( ios::eofbit );   // Force eofbit on
    }
    catch ( exception &e )
    {
        cout.clear( );
        cout << "Caught the exception." << endl;
        cout << "Exception class: " << typeid(e).name()  << endl;
        cout << "Exception description: " << e.what() << endl;
    }
}
```

```Output
0
1
Caught the exception.
Exception class: class std::ios_base::failure
Exception description: ios_base::eofbit set
```

## <a name="basic_iosfail"></a><a name="fail"></a> basic_ios:: falha

Indica falha ao extrair um campo válido de um fluxo.

```cpp
bool fail() const;
```

### <a name="return-value"></a>Valor Retornado

**`true`** Se [rdstate](#rdstate) `& (badbit|failbit)` for diferente de zero, caso contrário **`false`** .

Para obter mais informações sobre `failbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_fail.cpp
// compile with: /EHsc
#include <iostream>

int main( void )
{
    using namespace std;
    bool b = cout.fail( );
    cout << boolalpha;
    cout << b << endl;
}
```

## <a name="basic_iosfill"></a><a name="fill"></a> basic_ios:: Fill

Especifica ou retorna o caractere que será usado quando o texto não for tão grande quanto o fluxo.

```cpp
char_type fill() const;
char_type fill(char_type Char);
```

### <a name="parameters"></a>Parâmetros

*º*\
O caractere que você deseja usar como caractere de preenchimento.

### <a name="return-value"></a>Valor Retornado

O caractere de preenchimento atual.

### <a name="remarks"></a>Comentários

A primeira função membro retorna o caractere de preenchimento armazenado. A segunda função de membro armazena *Char* no caractere de preenchimento e retorna seu valor armazenado anterior.

### <a name="example"></a>Exemplo

```cpp
// basic_ios_fill.cpp
// compile with: /EHsc
#include <iostream>
#include <iomanip>

int main( )
{
    using namespace std;

    cout << setw( 5 ) << 'a' << endl;
    cout.fill( 'x' );
    cout << setw( 5 ) << 'a' << endl;
    cout << cout.fill( ) << endl;
}
```

```Output
a
xxxxa
x
```

## <a name="basic_iosgood"></a><a name="good"></a> basic_ios:: bom

Indica que o fluxo está em boas condições.

```cpp
bool good() const;
```

### <a name="return-value"></a>Valor Retornado

**`true`** Se [rdstate](#rdstate) `== goodbit` (nenhum sinalizador de estado estiver definido), caso contrário, **`false`** .

Para obter mais informações sobre `goodbit`, consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate).

### <a name="example"></a>Exemplo

Consulte [basic_ios::bad](#bad) para obter um exemplo de como usar `good`.

## <a name="basic_iosimbue"></a><a name="imbue"></a> basic_ios:: imbue

Altera a localidade.

```cpp
locale imbue(const locale& Loc);
```

### <a name="parameters"></a>Parâmetros

*Localização*\
Uma cadeia de caracteres de localidade.

### <a name="return-value"></a>Valor Retornado

A localidade anterior.

### <a name="remarks"></a>Comentários

Se [rdbuf](#rdbuf) não for um ponteiro nulo, a função membro chamará

`rdbuf`-> [pubimbue](../standard-library/basic-streambuf-class.md#pubimbue)(_ *Loc*)

Em qualquer caso, retorna [ios_base::imbue](../standard-library/ios-base-class.md#imbue)(_ *Loc*).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_imbue.cpp
// compile with: /EHsc
#include <iostream>
#include <locale>

int main( )
{
    using namespace std;

    cout.imbue( locale( "french_france" ) );
    double x = 1234567.123456;
    cout << x << endl;
}
```

## <a name="basic_iosinit"></a><a name="init"></a> basic_ios:: init

Chamado por construtores basic_ios.

```cpp
void init(basic_streambuf<Elem,Traits>* _Sb, bool _Isstd = false);
```

### <a name="parameters"></a>Parâmetros

*_Sb*\
Buffer padrão para armazenar elementos de entrada ou saída.

*_Isstd*\
Especifica se esse é um fluxo padrão.

### <a name="remarks"></a>Comentários

A função membro armazena valores em todos os objetos membro, de modo que:

- [rdbuf](#rdbuf) retorna *_Sb.*

- [tie](#tie) retorna um ponteiro nulo.

- [rdstate](#rdstate) retornará [goodbit](../standard-library/ios-base-class.md#iostate) se *_Sb* for diferente de zero; caso contrário, retornará [badbit](../standard-library/ios-base-class.md#iostate).

- [exceções](#exceptions) retorna `goodbit` .

- [flags](../standard-library/ios-base-class.md#flags) retorna [skipws](../standard-library/ios-base-class.md#fmtflags) &#124; [dec](../standard-library/ios-base-class.md#fmtflags).

- [width](../standard-library/ios-base-class.md#width) retorna 0.

- [precision](../standard-library/ios-base-class.md#precision) retorna 6.

- [fill](#fill) retorna o caractere de espaço.

- [getloc](../standard-library/ios-base-class.md#getloc) retorna `locale::classic`.

- [iword](../standard-library/ios-base-class.md#iword) retorna zero e [pword](../standard-library/ios-base-class.md#pword) retorna um ponteiro nulo para todos os valores de argumento.

## <a name="basic_iosint_type"></a><a name="int_type"></a> basic_ios:: int_type

Um sinônimo de `traits_type::int_type`.

```cpp
typedef typename traits_type::int_type int_type;
```

## <a name="basic_iosmove"></a><a name="move"></a> basic_ios:: mover

Move todos os valores, exceto o ponteiro para o buffer de fluxo, do parâmetro para o objeto atual.

```cpp
void move(basic_ios&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto `ios_base` do qual mover valores.

### <a name="remarks"></a>Comentários

A função de membro protegido move todos os valores armazenados à *direita* para **`*this`** , exceto o armazenado `stream buffer pointer` , que não foi alterado à *direita* e definido como um ponteiro nulo no **`*this`** . O armazenado `tie pointer` é definido como um ponteiro nulo à *direita*.

## <a name="basic_iosnarrow"></a><a name="narrow"></a> basic_ios:: Narrow

Localiza o char equivalente para um determinado `char_type`.

```cpp
char narrow(char_type Char, char Default = '\0') const;
```

### <a name="parameters"></a>Parâmetros

*º*\
O **`char`** a ser convertido.

*Os*\
O **`char`** que você deseja retornar se nenhum equivalente for encontrado.

### <a name="return-value"></a>Valor Retornado

O equivalente **`char`** a um determinado `char_type` .

### <a name="remarks"></a>Comentários

A função membro retorna [use_facet](../standard-library/basic-filebuf-class.md#open) \<ctype\<E> > ( [getloc](../standard-library/ios-base-class.md#getloc)()). `narrow` ( `Char`, `Default`).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_narrow.cpp
// compile with: /EHsc
#include <ios>
#include <iostream>
#include <wchar.h>

int main( )
{
    using namespace std;
    wchar_t *x = L"test";
    char y[10];
    cout << x[0] << endl;
    wcout << x << endl;
    y[0] = wcout.narrow( x[0] );
    cout << y[0] << endl;
}
```

## <a name="basic_iosoff_type"></a><a name="off_type"></a> basic_ios:: off_type

Um sinônimo de `traits_type::off_type`.

```cpp
typedef typename traits_type::off_type off_type;
```

## <a name="basic_iosoperator-void-"></a><a name="op_void_star"></a> basic_ios:: Operator void *

Indica se o fluxo ainda é válido.

```cpp
operator void *() const;
```

### <a name="return-value"></a>Valor Retornado

O operador retorna um ponteiro nulo apenas se [fail](#fail).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_opgood.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
    using namespace std;
    cout << (bool)(&cout != 0) << endl;   // Stream is still good
}
```

```Output
1
```

## <a name="basic_iosoperator"></a><a name="op_not"></a> basic_ios:: Operator!

Indica se o fluxo não é inválido.

```cpp
bool operator!() const;
```

### <a name="return-value"></a>Valor Retornado

Retorna [fail](#fail).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_opbad.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
    using namespace std;
    cout << !cout << endl;   // Stream is not bad
}
```

```Output
0
```

## <a name="basic_iosoperator-bool"></a><a name="op_bool"></a> basic_ios:: Operator bool

Permite o uso de um `basic_ios` objeto como um **`bool`** . Conversão de tipo automática é desabilitada para evitar efeitos colaterais comuns não intencionais.

```cpp
explicit operator bool() const;
```

### <a name="remarks"></a>Comentários

O operador retornará um valor conversível **`false`** somente se `fail()` . O tipo de retorno é conversível somente para **`bool`** , não para `void *` ou outro tipo escalar conhecido.

## <a name="basic_iospos_type"></a><a name="pos_type"></a> basic_ios::p os_type

Um sinônimo de `traits_type::pos_type`.

```cpp
typedef typename traits_type::pos_type pos_type;
```

## <a name="basic_iosrdbuf"></a><a name="rdbuf"></a> basic_ios:: rdbuf

Encaminha o fluxo para um buffer especificado.

```cpp
basic_streambuf<Elem, Traits> *rdbuf() const;
basic_streambuf<Elem, Traits> *rdbuf(
basic_streambuf<Elem, Traits>* _Sb);
```

### <a name="parameters"></a>Parâmetros

*_Sb*\
Um fluxo.

### <a name="remarks"></a>Comentários

A primeira função membro retorna o ponteiro de buffer de fluxo armazenado.

A segunda função de membro armazena *_Sb* no ponteiro de buffer de fluxo armazenado e retorna o valor armazenado anteriormente.

### <a name="example"></a>Exemplo

```cpp
// basic_ios_rdbuf.cpp
// compile with: /EHsc
#include <ios>
#include <iostream>
#include <fstream>

int main( )
{
    using namespace std;
    ofstream file( "rdbuf.txt" );
    streambuf *x = cout.rdbuf( file.rdbuf( ) );
    cout << "test" << endl;   // Goes to file
    cout.rdbuf(x);
    cout << "test2" << endl;
}
```

```Output
test2
```

## <a name="basic_iosrdstate"></a><a name="rdstate"></a> basic_ios:: rdstate

Lê o estado dos bits para sinalizadores.

```cpp
iostate rdstate() const;
```

### <a name="return-value"></a>Valor Retornado

As informações de estado de fluxo armazenadas.

### <a name="example"></a>Exemplo

```cpp
// basic_ios_rdstate.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>
using namespace std;

void TestFlags( ios& x )
{
    cout << ( x.rdstate( ) & ios::badbit ) << endl;
    cout << ( x.rdstate( ) & ios::failbit ) << endl;
    cout << ( x.rdstate( ) & ios::eofbit ) << endl;
    cout << endl;
}

int main( )
{
    fstream x( "c:\test.txt", ios::out );
    x.clear( );
    TestFlags( x );
    x.clear( ios::badbit | ios::failbit | ios::eofbit );
    TestFlags( x );
}
```

```Output
0
0
0

4
2
1
```

## <a name="basic_iossetstate"></a><a name="setstate"></a> basic_ios:: SetState

Define sinalizadores adicionais.

```cpp
void setstate(iostate _State);
```

### <a name="parameters"></a>Parâmetros

*_State*\
Sinalizadores adicionais a serem definidos.

### <a name="remarks"></a>Comentários

A função membro efetivamente chama [clear](#clear)(_ *State* &#124; [rdstate](#rdstate)).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_setstate.cpp
// compile with: /EHsc
#include <ios>
#include <iostream>
using namespace std;

int main( )
{
    bool b = cout.bad( );
    cout << b << endl;   // Good
    cout.clear( ios::badbit );
    b = cout.bad( );
    // cout.clear( );
    cout << b << endl;   // Is bad, good
    b = cout.fail( );
    cout << b << endl;   // Not failed
    cout.setstate( ios::failbit );
    b = cout.fail( );
    cout.clear( );
    cout << b << endl;   // Is failed, good
    return 0;
}
```

```Output
0
1
```

## <a name="basic_iosset_rdbuf"></a><a name="set_rdbuf"></a> basic_ios:: set_rdbuf

Atribui um buffer de fluxo para ser o buffer de leitura para esse objeto de fluxo.

```cpp
void set_rdbuf(
basic_streambuf<Elem, Tr>* strbuf)
```

### <a name="parameters"></a>Parâmetros

*strbuf*\
O buffer de fluxo para se tornar o buffer de leitura.

### <a name="remarks"></a>Comentários

A função membro protegido armazena *strbuf* no `stream buffer pointer` . Ele não chama `clear` .

## <a name="basic_iostie"></a><a name="tie"></a> basic_ios:: tie

Garante que um fluxo seja processado antes de outro.

```cpp
basic_ostream<Elem, Traits> *tie() const;
basic_ostream<Elem, Traits> *tie(
basic_ostream<Elem, Traits>* str);
```

### <a name="parameters"></a>Parâmetros

*Str*\
Um fluxo.

### <a name="return-value"></a>Valor Retornado

A primeira função membro retorna o ponteiro de ligação armazenado. A segunda função de membro armazena *Str* no ponteiro de ligação e retorna seu valor armazenado anterior.

### <a name="remarks"></a>Comentários

`tie` faz dois fluxos serem sincronizados de modo que operações em um fluxo ocorram depois da conclusão das operações no outro fluxo.

### <a name="example"></a>Exemplo

Neste exemplo, ao vincular cin a cout, garante-se que a cadeia de caracteres "Digite um número:" vá para o console antes de o número em si ser extraído do cin. Isso elimina a possibilidade de que a cadeia de caracteres "Digite um número:" ainda esteja no buffer quando o número for lido, para termos certeza de que o usuário de fato tem um prompt para responder. Por padrão, cin e cout estão vinculados.

```cpp
#include <ios>
#include <iostream>

int main( )
{
    using namespace std;
    int i;
    cin.tie( &cout );
    cout << "Enter a number:";
    cin >> i;
}
```

## <a name="basic_iostraits_type"></a><a name="traits_type"></a> basic_ios:: traits_type

Um sinônimo para o parâmetro de modelo `Traits`.

```cpp
typedef Traits traits_type;
```

## <a name="basic_ioswiden"></a><a name="widen"></a> basic_ios:: ampliação

Localiza o equivalente `char_type` a um determinado **`char`** .

```cpp
char_type widen(char Char) const;
```

### <a name="parameters"></a>Parâmetros

*º*\
O caractere a ser convertido.

### <a name="return-value"></a>Valor Retornado

Localiza o equivalente `char_type` a um determinado **`char`** .

### <a name="remarks"></a>Comentários

A função membro retorna [use_facet](../standard-library/basic-filebuf-class.md#open) <  **CType** \< **E**> > ( [getloc](../standard-library/ios-base-class.md#getloc)). `widen`( `Char`).

### <a name="example"></a>Exemplo

```cpp
// basic_ios_widen.cpp
// compile with: /EHsc
#include <ios>
#include <iostream>
#include <wchar.h>

int main( )
{
    using namespace std;
    char *z = "Hello";
    wchar_t y[2] = {0,0};
    cout << z[0] << endl;
    y[0] = wcout.widen( z[0] );
    wcout << &y[0] << endl;
}
```

## <a name="basic_iosswap"></a><a name="swap"></a> basic_ios:: swap

Troca os valores nesse objeto `basic_ios` por aqueles de outro objeto `basic_ios`. Porém, os ponteiros para os buffers de fluxo não são trocados.

```cpp
void swap(basic_ios&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto `basic_ios` usado para trocar valores.

### <a name="remarks"></a>Comentários

A função membro protegido troca todos os valores armazenados *à direita* com **`*this`** , exceto o armazenado `stream buffer pointer` .

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)

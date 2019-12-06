---
title: Classe locale
ms.date: 03/19/2019
f1_keywords:
- xlocale/std::locale
- xlocale/std::locale::category
- xlocale/std::locale::combine
- xlocale/std::locale::name
- xlocale/std::locale::classic
- xlocale/std::locale::global
- xlocale/std::locale::operator( )
- xlocale/std::locale::facet
- xlocale/std::locale::id
helpviewer_keywords:
- std::locale [C++]
- std::locale [C++], category
- std::locale [C++], combine
- std::locale [C++], name
- std::locale [C++], classic
- std::locale [C++], global
- std::locale [C++], facet
- std::locale [C++], id
ms.assetid: 7dd6d271-472d-4750-8fb5-ea8f55fbef62
ms.openlocfilehash: 551bca93a30bee52dc4c838864df28cb747d91df
ms.sourcegitcommit: 6ddfb8be5e5923a4d90a2c0f93f76a27ce7ac299
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/06/2019
ms.locfileid: "74898838"
---
# <a name="locale-class"></a>Classe locale

A classe que descreve um objeto de localidade que encapsula informações específicas à cultura como um conjunto de facetas que definem coletivamente um ambiente localizado específico.

## <a name="syntax"></a>Sintaxe

```cpp
class locale;
```

## <a name="remarks"></a>Comentários

Uma faceta é um ponteiro para um objeto de uma classe derivada da classe [facet](#facet_class) que tem um objeto público da forma:

```cpp
static locale::id id;
```

Você pode definir um conjunto de final aberto dessas facetas. Também é possível construir um objeto de localidade que designa um número arbitrário de facetas.

Os grupos predefinidos dessas facetas representam as [categorias de localidade](#category) normalmente gerenciadas na Biblioteca C Padrão pela função `setlocale`.

A `collate` de categoria (LC_COLLATE) inclui as facetas:

```cpp
collate<char>
collate<wchar_t>
```

A `ctype` de categoria (LC_CTYPE) inclui as facetas:

```cpp
ctype<char>
ctype<wchar_t>
codecvt<char, char, mbstate_t>
codecvt<wchar_t, char, mbstate_t>
codecvt<char16_t, char, mbstate_t>
codecvt<char32_t, char, mbstate_t>
```

A `monetary` de categoria (LC_MONETARY) inclui as facetas:

```cpp
moneypunct<char, false>
moneypunct<wchar_t, false>
moneypunct<char, true>
moneypunct<wchar_t, true>
money_get<char, istreambuf_iterator<char>>
money_get<wchar_t, istreambuf_iterator<wchar_t>>
money_put<char, ostreambuf_iterator<char>>
money_put<wchar_t, ostreambuf_iterator<wchar_t>>
```

A `numeric` de categoria (LC_NUMERIC) inclui as facetas:

```cpp
num_get<char, istreambuf_iterator<char>>
num_get<wchar_t, istreambuf_iterator<wchar_t>>
num_put<char, ostreambuf_iterator<char>>
num_put<wchar_t, ostreambuf_iterator<wchar_t>>
numpunct<char>
numpunct<wchar_t>
```

A `time` de categoria (LC_TIME) inclui as facetas:

```cpp
time_get<char, istreambuf_iterator<char>>
time_get<wchar_t, istreambuf_iterator<wchar_t>>
time_put<char, ostreambuf_iterator<char>>
time_put<wchar_t, ostreambuf_iterator<wchar_t>>
```

A `messages` de categoria (LC_MESSAGES) inclui as facetas:

```cpp
messages<char>
messages<wchar_t>
```

(A última categoria é exigida pelo POSIX, mas não pelo padrão C.)

Algumas dessas facetas predefinidas são usadas pelas classes `iostream`, para controlar a conversão de valores numéricos de e para sequências de texto.

Um objeto da localidade de classe também armazena um nome de localidade como um objeto da classe [string](../standard-library/string-typedefs.md#string). Usar um nome inválido de localidade para construir uma faceta ou um objeto de localidade lançará um objeto da classe [runtime_error](../standard-library/runtime-error-class.md). O nome da localidade armazenada será `"*"` se o objeto de localidade não puder ter certeza de que uma localidade em estilo C corresponde exatamente à representada pelo objeto. Caso contrário, você pode estabelecer uma localidade correspondente na biblioteca C padrão, para algum `locale_object`de objeto de localidade, chamando `setlocale(LC_ALL , locale_object.`[nome](#name)`().c_str())`.

Nessa implementação, também é possível chamar a função membro estática:

```cpp
static locale empty();
```

para construir um objeto de localidade que não tenha nenhuma faceta. Também é uma localidade transparente. Se o modelo funcionar [has_facet](../standard-library/locale-functions.md#has_facet) e [use_facet](../standard-library/locale-functions.md#use_facet) não conseguir localizar a faceta solicitada em uma localidade transparente, eles consultarão primeiro a localidade global e, em seguida, se isso for transparente, a localidade clássica. Portanto, você pode escrever:

```cpp
cout.imbue(locale::empty());
```

As inserções subsequentes para [`cout`](../standard-library/iostream.md#cout) são mediadas pelo estado atual da localidade global. Você ainda pode escrever:

```cpp
locale loc(locale::empty(),
    locale::classic(),
    locale::numeric);

cout.imbue(loc);
```

As regras de formatação numérica para inserções subsequentes em `cout` permanecem iguais as da localidade C, mesmo que a localidade global forneça regras que se modificam para inserção de valores monetários e de data.

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

|Construtor|Descrição|
|-|-|
|[locale](#locale)|Cria uma localidade, ou uma cópia de uma localidade, ou uma cópia da localidade em que uma faceta ou uma categoria foi substituída por uma faceta ou categoria de outra localidade.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[category](#category)|Um tipo de inteiro que fornece valores de bitmask para denotar famílias padrão de facetas.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[combine](#combine)|Insere uma faceta de uma localidade especificada em uma localidade de destino.|
|[name](#name)|Retorna o nome da localidade armazenado.|

### <a name="static-functions"></a>Funções estáticas

|||
|-|-|
|[classic](#classic)|A função membro estática retorna um objeto de localidade que representa a localidade C clássica.|
|[global](#global)|Redefine o local padrão do programa.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Atribui uma localidade.|
|[operator!=](#op_neq)|Testa a desigualdade de duas localidades.|
|[operator( )](#op_call)|Compara dois objetos `basic_string`.|
|[operator==](#op_eq_eq)|Testa a igualdade de duas localidades.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[facet](#facet_class)|Uma classe que serve como a classe base para todas as facetas de localidade.|
|[`id`](#id_class)|A classe do membro fornece uma identificação exclusiva da faceta usada como um índice para procurar facetas em uma localidade.|

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="category"></a>  locale::category

Um tipo de inteiro que fornece valores de bitmask para denotar famílias padrão de facetas.

```cpp
typedef int category;
static const int collate = LC_COLLATE;
static const int ctype = LC_CTYPE;
static const int monetary = LC_MONETARY;
static const int numeric = LC_NUMERIC;
static const int time = LC_TIME;
static const int messages = LC_MESSAGES;
static const int all = LC_ALL;
static const int none = 0;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para um tipo **int** que pode representar um grupo de elementos distintos de um tipo de bitmask local para a localidade de classe ou pode ser usado para representar qualquer uma das categorias de localidade C correspondentes. Os elementos são:

- `collate`, correspondente à categoria C LC_COLLATE

- `ctype`, correspondente à categoria C LC_CTYPE

- `monetary`, correspondente à categoria C LC_MONETARY

- `numeric`, correspondente à categoria C LC_NUMERIC

- `time`, correspondente à categoria C LC_TIME

- `messages`, correspondente à categoria POSIX LC_MESSAGES

Dois valores mais úteis são:

- `none`, correspondente a nenhuma das categorias de C

- `all`, correspondente à União C de todas as categorias LC_ALL

Você pode representar um grupo arbitrário de categorias usando `OR` com essas constantes, como em `monetary` &#124; `time`.

## <a name="classic"></a>  locale::classic

A função membro estática retorna um objeto de localidade que representa a localidade C clássica.

```cpp
static const locale& classic();
```

### <a name="return-value"></a>Valor retornado

Uma referência à localidade C.

### <a name="remarks"></a>Comentários

A localidade C clássica é a localidade ASCII em inglês dos EUA dentro da biblioteca C padrão. É a localidade que é usada implicitamente em programas que não são internacionalizados.

### <a name="example"></a>Exemplo

```cpp
// locale_classic.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main( )
{
   locale loc1( "german" );
   locale loc2 = locale::global( loc1 );
   cout << "The name of the previous locale is: " << loc2.name( )
        << "." << endl;
   cout << "The name of the current locale is: " << loc1.name( )
        << "." << endl;

   if (loc2 == locale::classic( ) )
      cout << "The previous locale was classic." << endl;
   else
      cout << "The previous locale was not classic." << endl;

   if (loc1 == locale::classic( ) )
      cout << "The current locale is classic." << endl;
   else
      cout << "The current locale is not classic." << endl;
}
```

```Output
The name of the previous locale is: C.
The name of the current locale is: German_Germany.1252.
The previous locale was classic.
The current locale is not classic.
```

## <a name="combine"></a>  locale::combine

Insere uma faceta de uma localidade especificada em uma localidade de destino.

```cpp
template <class Facet>
locale combine(const locale& source_locale) const;
```

### <a name="parameters"></a>Parâmetros

*source_locale*\
A localidade que contém a faceta a ser inserida na localidade de destino.

### <a name="return-value"></a>Valor retornado

A função membro retorna um objeto Locale que substitui ou adiciona a **\*essa** faceta `Facet` listada em *source_locale*.

### <a name="example"></a>Exemplo

```cpp
// locale_combine.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <tchar.h>
using namespace std;

int main() {
   locale loc ( "German_germany" );
   _TCHAR * s1 = _T("Das ist wei\x00dfzz."); // \x00df is the German sharp-s; it comes before z in the German alphabet
   _TCHAR * s2 = _T("Das ist weizzz.");
   int result1 = use_facet<collate<_TCHAR> > ( loc ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc ) << result1 << endl;

   locale loc2 ( "C" );
   int result2 = use_facet<collate<_TCHAR> > ( loc2 ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc2 )  << result2 << endl;

   locale loc3 = loc2.combine<collate<_TCHAR> > (loc);
   int result3 = use_facet<collate<_TCHAR> > ( loc3 ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc3 ) << result3 << endl;
}
```

## <a name="facet_class"></a>  Classe facet

Uma classe que serve como a classe base para todas as facetas de localidade.

```cpp
class facet {
protected:
    explicit facet(size_t references = 0);
    virtual ~facet();
private:
    facet(const facet&) // not defined
    void operator=(const facet&) // not defined
};
```

### <a name="remarks"></a>Comentários

Não é possível copiar ou atribuir um objeto da classe `facet`. É possível construir e destruir objetos derivados da classe `locale::facet`, mas não objetos da classe base correta. Normalmente, você constrói um objeto `_Myfac` derivado de `facet` ao construir um `locale`, como no `locale loc(locale::classic(), new _Myfac);`

Nesses casos, o construtor para a classe base `facet` deve ter um argumento de *referências* zero. Quando o objeto não for mais necessário, ele será excluído, de modo que você só fornecerá um argumento de *referências* sem zero nesses casos raros em que você assumirá a responsabilidade pelo tempo de vida do objeto.

## <a name="global"></a>  locale::global

Redefine a localidade padrão do programa. Essa chamada afeta a localidade global para C e C++.

```cpp
static locale global(const locale& new_default_locale);
```

### <a name="parameters"></a>Parâmetros

*new_default_locale*\
A localidade a ser usada como localidade padrão pelo programa.

### <a name="return-value"></a>Valor retornado

A localidade anterior antes da redefinição da localidade padrão.

### <a name="remarks"></a>Comentários

Na inicialização do programa, a localidade global será a mesma que a localidade clássica. A função `global()` chama `setlocale( LC_ALL, loc.name. c_str())` para estabelecer uma localidade correspondente na biblioteca C padrão.

### <a name="example"></a>Exemplo

```cpp
// locale_global.cpp
// compile by using: /EHsc
#include <locale>
#include <iostream>
#include <tchar.h>
using namespace std;

int main( )
{
   locale loc ( "German_germany" );
   locale loc1;
   cout << "The initial locale is: " << loc1.name( ) << endl;
   locale loc2 = locale::global ( loc );
   locale loc3;
   cout << "The current locale is: " << loc3.name( ) << endl;
   cout << "The previous locale was: " << loc2.name( ) << endl;
}
```

```Output
The initial locale is: C
The current locale is: German_Germany.1252
The previous locale was: C
```

## <a name="id_class"></a>  Classe id

A classe do membro fornece uma identificação exclusiva da faceta usada como um índice para procurar facetas em uma localidade.

```cpp
class id
{
   protected:    id();
   private:      id(const id&)
   void operator=(const id&)  // not defined
};
```

### <a name="remarks"></a>Comentários

A classe membro descreve o objeto de membro estático exigido por cada faceta de localidade exclusiva. Não é possível copiar ou atribuir um objeto da classe `id`.

## <a name="locale"></a>  locale::locale

Cria uma localidade, ou uma cópia de uma localidade, ou uma cópia da localidade em que uma faceta ou uma categoria foi substituída por uma faceta ou categoria de outra localidade. Também inclui um destruidor.

```cpp
locale();

explicit locale(const char* locale_name, category new_category = all);
explicit locale(const string& locale_name);
locale(const locale& from_locale);
locale(const locale& from_locale, const locale& Other, category new_category);
locale(const locale& from_locale, const char* locale_name, category new_category);

template <class Facet>
locale(const locale& from_locale, const Facet* new_facet);

~locale();
```

### <a name="parameters"></a>Parâmetros

*locale_name*\
Nome de uma localidade.

*from_locale*\
Uma localidade que deve ser copiada ao construir uma nova localidade.

*Outros*\
Uma localidade da qual se deve selecionar uma categoria.

*new_category*\
A categoria a ser substituída na localidade construída.

*new_facet*\
A faceta a ser substituída na localidade construída.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa o objeto de acordo com a localidade global. O segundo e o terceiro construtores inicializam todas as categorias de localidade para que o comportamento seja consistente com o nome de localidade *locale_name*. Os construtores restantes copiam *from_locale*, com as exceções indicadas:

`locale(const locale& from_locale, const locale& Other, category new_category);`

Substitui de *outras* facetas que correspondem a uma categoria c para a qual c & *new_category* é diferente de zero.

`locale(const locale& from_locale, const char* locale_name, category new_category);`

`locale(const locale& from_locale, const string& locale_name, category new_category);`

Substitui de `locale(locale_name, all)` as facetas correspondentes a uma categoria *replace_category* para a qual `replace_category & new_category` é diferente de zero.

`template<class Facet> locale(const locale& from_locale, Facet* new_facet);`

Substitui (ou adiciona) à *from_locale* da faceta *new_facet*, se *new_facet* não for um ponteiro nulo.

Se o nome da localidade *locale_name* for um ponteiro nulo ou for inválido, a função lançará [runtime_error](../standard-library/runtime-error-class.md).

### <a name="example"></a>Exemplo

```cpp
// locale_locale.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <tchar.h>
using namespace std;

int main( ) {

   // Second constructor
   locale loc ( "German_germany" );
   _TCHAR * s1 = _T("Das ist wei\x00dfzz."); // \x00df is the German sharp-s, it comes before z in the German alphabet
   _TCHAR * s2 = _T("Das ist weizzz.");
   int result1 = use_facet<collate<_TCHAR> > ( loc ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc ) << result1 << endl;

   // The first (default) constructor
   locale loc2;
   int result2 = use_facet<collate<_TCHAR> > ( loc2 ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc2 )  << result2 << endl;

   // Third constructor
   locale loc3 (loc2,loc, _M_COLLATE );
   int result3 = use_facet<collate<_TCHAR> > ( loc3 ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc3 ) << result3 << endl;

   // Fourth constructor
   locale loc4 (loc2, "German_Germany", _M_COLLATE );
   int result4 = use_facet<collate<_TCHAR> > ( loc4 ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << isalpha (_T ( '\x00df' ), loc4 ) << result4 << endl;
}
```

## <a name="name"></a>  locale::name

Retorna o nome da localidade armazenado.

```cpp
string name() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que fornece o nome da localidade.

### <a name="example"></a>Exemplo

```cpp
// locale_name.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main( )
{
   locale loc1( "german" );
   locale loc2 = locale::global( loc1 );
   cout << "The name of the previous locale is: "
        << loc2.name( ) << "." << endl;
   cout << "The name of the current locale is: "
        << loc1.name( ) << "." << endl;
}
```

```Output
The name of the previous locale is: C.
The name of the current locale is: German_Germany.1252.
```

## <a name="op_eq"></a>Localidade:: operador =

Atribui uma localidade.

```cpp
const locale& operator=(const locale& other) noexcept;
```

## <a name="op_neq"></a>  locale::operator!=

Testa a desigualdade de duas localidades.

```cpp
bool operator!=(const locale& right) const;
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
Uma das localidades que terá sua desigualdade testada.

### <a name="return-value"></a>Valor retornado

Um valor booliano que será **verdadeiro** se as localidades não forem cópias da mesma localidade. Será **false** se as localidades forem cópias da mesma localidade.

### <a name="remarks"></a>Comentários

Duas localidades são iguais se forem a mesma localidade, se uma for uma cópia do outro, ou se tiverem nomes idênticos.

### <a name="example"></a>Exemplo

```cpp
// locale_op_ne.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main( )
{
   locale loc1( "German_Germany" );
   locale loc2( "German_Germany" );
   locale loc3( "English" );

   if ( loc1 != loc2 )
      cout << "locales loc1 (" << loc1.name( )
      << ") and\n loc2 (" << loc2.name( ) << ") are not equal." << endl;
   else
      cout << "locales loc1 (" << loc1.name( )
      << ") and\n loc2 (" << loc2.name( ) << ") are equal." << endl;

   if ( loc1 != loc3 )
      cout << "locales loc1 (" << loc1.name( )
      << ") and\n loc3 (" << loc3.name( ) << ") are not equal." << endl;
   else
      cout << "locales loc1 (" << loc1.name( )
      << ") and\n loc3 (" << loc3.name( ) << ") are equal." << endl;
}
```

```Output
locales loc1 (German_Germany.1252) and
loc2 (German_Germany.1252) are equal.
locales loc1 (German_Germany.1252) and
loc3 (English_United States.1252) are not equal.
```

## <a name="op_call"></a>  locale::operator()

Compara dois objetos `basic_string`.

```cpp
template <class CharType, class Traits, class Allocator>
bool operator()(
    const basic_string<CharType, Traits, Allocator>& left,
    const basic_string<CharType, Traits, Allocator>& right) const;
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
A cadeia de caracteres à esquerda.

\ *à direita*
A cadeia de caracteres à direita.

### <a name="return-value"></a>Valor retornado

A função membro retornará:

- –1 se a primeira sequência comparar menos do que a segunda sequência.

- +1 se a segunda sequência comparar menos do que a primeira sequência.

- 0 se as sequências forem equivalentes.

### <a name="remarks"></a>Comentários

A função membro é executada efetivamente:

```cpp
const collate<CharType>& fac = use_fac<collate<CharType>>(*this);

return (fac.compare(left.begin(), left.end(), right.begin(), right.end()) < 0);
```

Isso significa que você pode usar um objeto de localidade como um objeto de função.

### <a name="example"></a>Exemplo

```cpp
// locale_op_compare.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
#include <locale>

int main( )
{
   using namespace std;
   wchar_t *sa = L"ztesting";
   wchar_t *sb = L"\0x00DFtesting";
   basic_string<wchar_t> a( sa );
   basic_string<wchar_t> b( sb );

   locale loc( "German_Germany" );
   cout << loc( a,b ) << endl;

   const collate<wchar_t>& fac = use_facet<collate<wchar_t> >( loc );
   cout << ( fac.compare( sa, sa + a.length( ),
       sb, sb + b.length( ) ) < 0) << endl;
}
```

```Output
0
0
```

## <a name="op_eq_eq"></a>  locale::operator==

Testa a igualdade de duas localidades.

```cpp
bool operator==(const locale& right) const;
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
Uma das localidades que terá sua igualdade testada.

### <a name="return-value"></a>Valor retornado

Um valor booliano que será **verdadeiro** se as localidades forem cópias da mesma localidade. Será **false** se as localidades não forem cópias da mesma localidade.

### <a name="remarks"></a>Comentários

Duas localidades são iguais se forem a mesma localidade, se uma for uma cópia do outro, ou se tiverem nomes idênticos.

### <a name="example"></a>Exemplo

```cpp
// locale_op_eq.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main( )
{
   locale loc1( "German_Germany" );
   locale loc2( "German_Germany" );
   locale loc3( "English" );

   if ( loc1 == loc2 )
      cout << "locales loc1 (" << loc1.name( )
      << ")\n and loc2 (" << loc2.name( ) << ") are equal."
      << endl;
   else
      cout << "locales loc1 (" << loc1.name( )
      << ")\n and loc2 (" << loc2.name( ) << ") are not equal."
      << endl;

   if ( loc1 == loc3 )
      cout << "locales loc1 (" << loc1.name( )
      << ")\n and loc3 (" << loc3.name( ) << ") are equal."
      << endl;
   else
      cout << "locales loc1 (" << loc1.name( )
      << ")\n and loc3 (" << loc3.name( ) << ") are not equal."
      << endl;
}
```

```Output
locales loc1 (German_Germany.1252)
and loc2 (German_Germany.1252) are equal.
locales loc1 (German_Germany.1252)
and loc3 (English_United States.1252) are not equal.
```

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)\
[Páginas de código](../c-runtime-library/code-pages.md)\
[Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

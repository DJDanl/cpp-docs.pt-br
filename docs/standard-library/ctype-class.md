---
title: Classe ctype
ms.date: 11/04/2016
f1_keywords:
- xlocale/std::ctype
- xlocale/std::ctype::char_type
- xlocale/std::ctype::do_is
- xlocale/std::ctype::do_narrow
- xlocale/std::ctype::do_scan_is
- xlocale/std::ctype::do_scan_not
- xlocale/std::ctype::do_tolower
- xlocale/std::ctype::do_toupper
- xlocale/std::ctype::do_widen
- xlocale/std::ctype::is
- xlocale/std::ctype::narrow
- xlocale/std::ctype::scan_is
- xlocale/std::ctype::scan_not
- xlocale/std::ctype::tolower
- xlocale/std::ctype::toupper
- xlocale/std::ctype::widen
helpviewer_keywords:
- std::ctype [C++]
- std::ctype [C++], char_type
- std::ctype [C++], do_is
- std::ctype [C++], do_narrow
- std::ctype [C++], do_scan_is
- std::ctype [C++], do_scan_not
- std::ctype [C++], do_tolower
- std::ctype [C++], do_toupper
- std::ctype [C++], do_widen
- std::ctype [C++], is
- std::ctype [C++], narrow
- std::ctype [C++], scan_is
- std::ctype [C++], scan_not
- std::ctype [C++], tolower
- std::ctype [C++], toupper
- std::ctype [C++], widen
ms.assetid: 3627154c-49d9-47b5-b28f-5bbedee38e3b
ms.openlocfilehash: dae6f62a0eda9263986a77b82754596d17be94e5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373162"
---
# <a name="ctype-class"></a>Classe ctype

Uma classe que fornece uma faceta usada para classificar caracteres, fazer conversões de letras maiúsculas e minúsculas, bem como fazer a conversão entre o conjunto de caracteres nativos e o conjunto usado pela localidade.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class ctype : public ctype_base;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em `id`. Os critérios de classificação são fornecidos em um tipo de bitmask aninhado em ctype_base da classe base.

A Biblioteca Padrão C++ define duas especializações explícitas deste modelo de classe:

- `ctype<char>`, uma especialização explícita cujas diferenças são descritas separadamente. Para obter mais informações, consulte [ctype&lt;char&gt; Class](../standard-library/ctype-char-class.md).

- `ctype<wchar_t>`, que trata os elementos como caracteres largos.

Outras especializações `ctype<CharType>`do modelo de classe:

- Converta um valor *ch* do tipo *CharType* para `(char)ch`um valor de tipo **char** com a expressão .

- Converta um *byte* de valor de **tipo char** `CharType(byte)`para um valor do tipo *CharType* com a expressão .

Todas as outras operações são realizadas em valores **de char** da mesma forma que para a especialização `ctype<char>`explícita .

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[ctype](#ctype)|Construtor para objetos da classe `ctype` que atuam como facetas de localidade para caracteres.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que descreve um caractere usado por uma localidade.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[do_is](#do_is)|Uma função virtual chamada para testar se um único caractere tem um atributo específico ou para classificar os atributos de cada caractere em um intervalo e armazená-los em uma matriz.|
|[do_narrow](#do_narrow)|Uma função virtual chamada para `CharType` converter um caractere de tipo usado por um local para o caractere correspondente do tipo **char** no conjunto de caracteres nativos.|
|[do_scan_is](#do_scan_is)|Uma função virtual chamada para localizar o primeiro caractere em um intervalo que corresponda a uma máscara especificada.|
|[do_scan_not](#do_scan_not)|Uma função virtual chamada para localizar o primeiro caractere em um intervalo que não corresponda a uma máscara especificada.|
|[do_tolower](#do_tolower)|Uma função virtual chamada para converter um caractere ou um intervalo em letras minúsculas.|
|[do_toupper](#do_toupper)|Uma função virtual chamada para converter um caractere ou um intervalo em letras maiúsculas.|
|[do_widen](#do_widen)|Uma função virtual chamada para converter um caractere de **tipo char** no `CharType` caractere nativo definido para o caractere correspondente do tipo usado por um local.|
|[É](#is)|Testa se um único caractere tem um atributo específico ou classifica os atributos de cada caractere em um intervalo e os armazena em uma matriz.|
|[narrow](#narrow)|Converte um caractere do tipo `CharType` usado por uma localidade em caractere correspondente do tipo char no conjunto de caracteres nativos.|
|[scan_is](#scan_is)|Localiza o primeiro caractere em um intervalo que corresponda a uma máscara especificada.|
|[scan_not](#scan_not)|Localiza o primeiro caractere em um intervalo que não corresponda a uma máscara especificada.|
|[Tolower](#tolower)|Converte um caractere ou um intervalo de caracteres em letras minúsculas.|
|[Toupper](#toupper)|Converte um caractere ou um intervalo de caracteres em letras maiúsculas.|
|[widen](#widen)|Converte um caractere de **tipo char** no caractere nativo `CharType` definido para o caractere correspondente do tipo usado por um local.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="ctypechar_type"></a><a name="char_type"></a>ctype::char_type

Um tipo que descreve um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *CharType*.

### <a name="example"></a>Exemplo

Consulte a função de membro [widen](#widen) para obter um exemplo que usa `char_type` como um valor retornado.

## <a name="ctypectype"></a><a name="ctype"></a>ctype::ctype

Construtor para objetos da classe ctype que servem como facetas de localidade para caracteres.

```cpp
explicit ctype(size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o *parâmetro _Refs* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: Esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa `locale::facet` seu objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)( `_Refs`).

## <a name="ctypedo_is"></a><a name="do_is"></a>ctype::do_is

Uma função virtual chamada para testar se um único caractere tem um atributo específico ou para classificar os atributos de cada caractere em um intervalo e armazená-los em uma matriz.

```cpp
virtual bool do_is(
    mask maskVal,
    CharType ch) const;

virtual const CharType *do_is(
    const CharType* first,
    const CharType* last,
    mask* dest) const;
```

### <a name="parameters"></a>Parâmetros

*máscaraVal*\
O valor de máscara para o qual o caractere será testado.

*Ch*\
O caractere cujos atributos devem ser testados.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo cujos atributos devem ser classificados.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo cujos atributos devem ser classificados.

*Dest*\
Um ponteiro para o início da matriz na qual os valores de máscara que caracterizam os atributos de cada um dos caracteres devem ser armazenados.

### <a name="return-value"></a>Valor retornado

A primeira função de membro retorna um valor booliano que será **true** se o caractere testado tiver o atributo descrito pelo valor de máscara; **false** se não tiver o atributo.

A segunda função de membro retorna uma matriz que contém os valores de máscara que caracterizam os atributos de cada um dos caracteres no intervalo.

### <a name="remarks"></a>Comentários

Os valores de máscara que classificam os atributos dos caracteres são fornecidos pela classe [ctype_base](../standard-library/ctype-base-class.md), da qual ctype é derivado. A primeira função de membro pode aceitar expressões para o primeiro parâmetro chamado bitmasks e formado pela combinação de valores de máscara pelos operadores bit a bit lógicos (&#124; , & , ^ , ~).

### <a name="example"></a>Exemplo

Consulte o exemplo de [is](#is), que chama `do_is`.

## <a name="ctypedo_narrow"></a><a name="do_narrow"></a>ctype::do_narrow

Uma função virtual chamada para `CharType` converter um caractere de tipo usado por um local para o caractere correspondente do tipo **char** no conjunto de caracteres nativos.

```cpp
virtual char do_narrow(
    CharType ch,
    char default = '\0') const;

virtual const CharType* do_narrow(
    const CharType* first,
    const CharType* last,
    char default,
    char* dest) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere do tipo `Chartype` usado pela localidade a ser convertido.

*Padrão*\
O valor padrão a ser atribuído pela função `CharType` de membro a caracteres do tipo que não possuem caracteres de contrapartida do tipo **char**.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres a ser convertido.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres a ser convertido.

*Dest*\
Um ponteiro const para o primeiro caractere do tipo **char** na faixa de destino que armazena a gama de caracteres convertidos.

### <a name="return-value"></a>Valor retornado

A primeira função de membro protegido retorna o caractere nativo do `CharType` tipo char que corresponde ao caractere parâmetro do tipo ou *padrão* se nenhuma contraparte for definida.

A segunda função de membro protegida retorna um ponteiro para o intervalo de destino dos caracteres nativos convertidos de caracteres do tipo `CharType`.

### <a name="remarks"></a>Comentários

A segunda função de `dest`modelo `I`de `do_narrow`membro `first` `I`protegido `default`armazena `I` em [ ] `last`  -  `first`o valor ( [ ], ), para no intervalo [0, ).

### <a name="example"></a>Exemplo

Consulte o exemplo de [narrow](#narrow), que chama `do_narrow`.

## <a name="ctypedo_scan_is"></a><a name="do_scan_is"></a>ctype::do_scan_is

Uma função virtual chamada para localizar o primeiro caractere em um intervalo que corresponda a uma máscara especificada.

```cpp
virtual const CharType *do_scan_is(
    mask maskVal,
    const CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*máscaraVal*\
O valor de máscara que deve ter correspondência com um caractere.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo a ser examinado.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo a ser examinado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro caractere em um intervalo que corresponde a uma máscara especificada. Se não existir tal valor, a função retorna *por último*.

### <a name="remarks"></a>Comentários

A função de membro protegido `ptr` retorna o `first` `last`menor ponteiro na `maskVal` \* `ptr`faixa [ ) para o qual [do_is](#do_is)( ) é verdade.

### <a name="example"></a>Exemplo

Consulte o exemplo de [scan_is](#scan_is), que chama `do_scan_is`.

## <a name="ctypedo_scan_not"></a><a name="do_scan_not"></a>ctype::do_scan_not

Uma função virtual chamada para localizar o primeiro caractere em um intervalo que não corresponda a uma máscara especificada.

```cpp
virtual const CharType *do_scan_not(
    mask maskVal,
    const CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*máscaraVal*\
O valor de máscara que não deve ter correspondência com um caractere.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo a ser examinado.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo a ser examinado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro caractere em um intervalo que não corresponde a uma máscara especificada. Se não existir tal valor, a função retorna *por último*.

### <a name="remarks"></a>Comentários

A função de membro protegido `ptr` retorna o `first` `last`menor ponteiro na `maskVal` \* `ptr`faixa [ , ) para o qual [do_is](#do_is)( ) é falso.

### <a name="example"></a>Exemplo

Consulte o exemplo de [scan_not](#scan_not), que chama `do_scan_not`.

## <a name="ctypedo_tolower"></a><a name="do_tolower"></a>ctype::do_tolower

Uma função virtual chamada para converter um caractere ou um intervalo de caracteres em letras minúsculas.

```cpp
virtual CharType do_tolower(CharType ch) const;

virtual const CharType *do_tolower(
    CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere a ser convertido em letras minúsculas.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

### <a name="return-value"></a>Valor retornado

A primeira função de membro protegido retorna a forma minúscula do parâmetro *ch*. Se não existir nenhuma forma minúscula, ela retorna *ch*. A segunda função de membro protegido retorna *por último*.

### <a name="remarks"></a>Comentários

A segunda função de modelo `first` de `I`membro `I` protegido substitui cada `last`  -  `first`elemento `do_tolower`[ `first` `I`], para no intervalo [0, ] com [ ]).

### <a name="example"></a>Exemplo

Consulte o exemplo de [tolower](#tolower), que chama `do_tolower`.

## <a name="ctypedo_toupper"></a><a name="do_toupper"></a>ctype::do_toupper

Uma função virtual chamada para converter um caractere ou um intervalo em letras maiúsculas.

```cpp
virtual CharType do_toupper(CharType ch) const;

virtual const CharType *do_toupper(
    CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere a ser convertido em maiúsculas.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

### <a name="return-value"></a>Valor retornado

A primeira função de membro protegido retorna a forma maiúscula do parâmetro *ch*. Se não houver forma maiúscula, ela retorna *ch*. A segunda função de membro protegido retorna *por último*.

### <a name="remarks"></a>Comentários

A segunda função de modelo `first` de `I`membro `I` protegido substitui cada `last`  -  `first`elemento `do_toupper`[ `first` `I`], para no intervalo [0, ] com [ ]).

### <a name="example"></a>Exemplo

Consulte o exemplo de [toupper](#toupper), que chama `do_toupper`.

## <a name="ctypedo_widen"></a><a name="do_widen"></a>ctype::do_amp

Uma função virtual chamada para converter um caractere de **tipo char** no `CharType` caractere nativo definido para o caractere correspondente do tipo usado por um local.

```cpp
virtual CharType do_widen(char byte) const;

virtual const char *do_widen(
    const char* first,
    const char* last,
    CharType* dest) const;
```

### <a name="parameters"></a>Parâmetros

*Byte*\
O caráter do tipo **char** no caractere nativo definido para ser convertido.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres a ser convertido.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres a ser convertido.

*Dest*\
Um ponteiro para o primeiro caractere do tipo `CharType` no intervalo de destino que armazena o intervalo convertido de caracteres.

### <a name="return-value"></a>Valor retornado

A primeira função de membro `CharType` protegido retorna o caractere do tipo que corresponde ao caractere parâmetro do tipo **de char**nativo .

A segunda função de membro protegido retorna um `CharType` ponteiro para a faixa de destino de caracteres do tipo usado por um local convertido a partir de caracteres nativos do tipo **char**.

### <a name="remarks"></a>Comentários

A segunda função de modelo de membro protegida armazena em `dest`[ `I`] o valor `do_widen`( `first`[ `I`]), para `I` no intervalo [0, `last` - `first`).

### <a name="example"></a>Exemplo

Consulte o exemplo de [widen](#widen), que chama `do_widen`.

## <a name="ctypeis"></a><a name="is"></a>ctype::é

Testa se um único caractere tem um atributo específico ou classifica os atributos de cada caractere em um intervalo e os armazena em uma matriz.

```cpp
bool is(mask maskVal, CharType ch) const;

const CharType *is(
    const CharType* first,
    const CharType* last,
    mask* dest) const;
```

### <a name="parameters"></a>Parâmetros

*máscaraVal*\
O valor de máscara para o qual o caractere será testado.

*Ch*\
O caractere cujos atributos devem ser testados.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo cujos atributos devem ser classificados.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo cujos atributos devem ser classificados.

*Dest*\
Um ponteiro para o início da matriz na qual os valores de máscara que caracterizam os atributos de cada um dos caracteres devem ser armazenados.

### <a name="return-value"></a>Valor retornado

A primeira função do membro retorna **verdadeira** se o caractere testado tiver o atributo descrito pelo valor da máscara; **falso** se ele não tem o atributo.

A segunda função de membro retorna um ponteiro para o último caractere no intervalo cujos atributos devem ser classificados.

### <a name="remarks"></a>Comentários

Os valores de máscara que classificam os atributos dos caracteres são fornecidos pela [Classe ctype_base](../standard-library/ctype-base-class.md), da qual ctype é derivado. A primeira função de membro pode aceitar expressões para o primeiro parâmetro chamado bitmasks e formado pela combinação de valores de máscara pelos operadores bit a bit lógicos (&#124; , & , ^ , ~).

### <a name="example"></a>Exemplo

```cpp
// ctype_is.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main() {
   locale loc1 ( "German_Germany" ), loc2 ( "English_Australia" );

   if (use_facet<ctype<char> > ( loc1 ).is( ctype_base::alpha, 'a' ))
      cout << "The character 'a' in locale loc1 is alphabetic."
           << endl;
   else
      cout << "The character 'a' in locale loc1 is not alphabetic."
           << endl;

   if (use_facet<ctype<char> > ( loc2 ).is( ctype_base::alpha, '!' ))
      cout << "The character '!' in locale loc2 is alphabetic."
           << endl;
   else
      cout << "The character '!' in locale loc2 is not alphabetic."
           << endl;

   char *string = "Hello, my name is John!";
   ctype<char>::mask maskarray[30];
   use_facet<ctype<char> > ( loc2 ).is(
      string, string + strlen(string), maskarray );
   for (unsigned int i = 0; i < strlen(string); i++) {
      cout << string[i] << ": "
           << (maskarray[i] & ctype_base::alpha  "alpha"
                                                : "not alpha")
           << endl;;
   };
}
```

## <a name="ctypenarrow"></a><a name="narrow"></a>ctype::estreito

Converte caracteres `CharType` do tipo usados por um local para os caracteres correspondentes do tipo **char** no conjunto de caracteres nativos.

```cpp
char narrow(CharType ch, char default = '\0') const;

const CharType* narrow(
    const CharType* first,
    const CharType* last,
    char default,
    char* dest) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere do tipo `Chartype` usado pela localidade a ser convertido.

*Padrão*\
O valor padrão a ser atribuído pela função `CharType` de membro a caracteres do tipo que não possuem caracteres de contrapartida do tipo **char**.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres a ser convertido.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres a ser convertido.

*Dest*\
Um ponteiro const para o primeiro caractere do tipo **char** na faixa de destino que armazena a gama de caracteres convertidos.

### <a name="return-value"></a>Valor retornado

A função do primeiro membro **char** retorna o caractere nativo do tipo `CharType default` char que corresponde ao caractere parâmetro do tipo se não a contrapartida for definida.

A segunda função de membro retorna um ponteiro para o intervalo de destino dos caracteres nativos convertidos de caracteres do tipo `CharType`.

### <a name="remarks"></a>Comentários

A função do primeiro`ch` `default`membro retorna [do_narrow](#do_narrow)( , ). A função do segundo`first` `last`membro `default` `dest`retorna [do_narrow](#do_narrow) ( , , , ). Somente os caracteres de origem básicos têm a garantia de terem uma imagem inversa exclusiva `CharType` em `narrow`. Para esses caracteres de origem básicos, a seguinte invariável se mantém: `narrow` ( [widen](#widen) ( **c** ), 0 ) == **c**.

### <a name="example"></a>Exemplo

```cpp
// ctype_narrow.cpp
// compile with: /EHsc /W3
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "english" );
   wchar_t *str1 = L"\x0392fhello everyone";
   char str2 [16];
   bool result1 = (use_facet<ctype<wchar_t> > ( loc1 ).narrow
      ( str1, str1 + wcslen(str1), 'X', &str2[0] ) != 0);  // C4996
   str2[wcslen(str1)] = '\0';
   wcout << str1 << endl;
   cout << &str2[0] << endl;
}
```

```Output
Xhello everyone
```

## <a name="ctypescan_is"></a><a name="scan_is"></a>ctype::scan_is

Localiza o primeiro caractere em um intervalo que corresponda a uma máscara especificada.

```cpp
const CharType *scan_is(
    mask maskVal,
    const CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*máscaraVal*\
O valor de máscara que deve ter correspondência com um caractere.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo a ser examinado.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo a ser examinado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro caractere em um intervalo que corresponde a uma máscara especificada. Se não existir tal valor, a função retorna *por último*.

### <a name="remarks"></a>Comentários

A função do`maskVal`membro `first` `last`retorna [do_scan_is](#do_scan_is)( , , ).

### <a name="example"></a>Exemplo

```cpp
// ctype_scan_is.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "German_Germany" );

   char *string = "Hello, my name is John!";

   const char* i = use_facet<ctype<char> > ( loc1 ).scan_is
      ( ctype_base::punct, string, string + strlen(string) );
   cout << "The first punctuation is \"" << *i << "\" at position: "
      << i - string << endl;
}
```

```Output
The first punctuation is "," at position: 5
```

## <a name="ctypescan_not"></a><a name="scan_not"></a>ctype::scan_not

Localiza o primeiro caractere em um intervalo que não corresponda a uma máscara especificada.

```cpp
const CharType *scan_not(
    mask maskVal,
    const CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*máscaraVal*\
O valor de máscara que não deve ter correspondência com um caractere.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo a ser examinado.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo a ser examinado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o primeiro caractere em um intervalo que não corresponde a uma máscara especificada. Se não existir tal valor, a função retorna *por último*.

### <a name="remarks"></a>Comentários

A função do`maskVal`membro `first` `last`retorna [do_scan_not](#do_scan_not)( , , ).

### <a name="example"></a>Exemplo

```cpp
// ctype_scan_not.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "German_Germany" );

   char *string = "Hello, my name is John!";

   const char* i = use_facet<ctype<char> > ( loc1 ).scan_not
      ( ctype_base::alpha, string, string + strlen(string) );
   cout << "First nonalpha character is \"" << *i << "\" at position: "
      << i - string << endl;
}
```

```Output
First nonalpha character is "," at position: 5
```

## <a name="ctypetolower"></a><a name="tolower"></a>ctype::tolower

Converte um caractere ou um intervalo de caracteres em letras minúsculas.

```cpp
CharType tolower(CharType ch) const;

const CharType *tolower(CharType* first, const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere a ser convertido em letras minúsculas.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

### <a name="return-value"></a>Valor retornado

A função do primeiro membro retorna a forma minúscula do parâmetro *ch*. Se não existir nenhuma forma minúscula, ela retorna *ch*.

A função do segundo membro retorna *por último*.

### <a name="remarks"></a>Comentários

A função do [do_tolower](#do_tolower)primeiro`ch`membro retorna do_tolower ( ). A função do segundo`first` `last`membro retorna [do_tolower](#do_tolower)( , ).

### <a name="example"></a>Exemplo

```cpp
// ctype_tolower.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "German_Germany" );

   char string[] = "HELLO, MY NAME IS JOHN";

   use_facet<ctype<char> > ( loc1 ).tolower
      ( string, string + strlen(string) );
   cout << "The lowercase string is: " << string << endl;
}
```

```Output
The lowercase string is: hello, my name is john
```

## <a name="ctypetoupper"></a><a name="toupper"></a>ctype::toupper

Converte um caractere ou um intervalo de caracteres em letras maiúsculas.

```cpp
CharType toupper(CharType ch) const;
const CharType *toupper(CharType* first, const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Ch*\
O caractere a ser convertido em maiúsculas.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres cujas maiúsculas e minúsculas devem ser convertidas.

### <a name="return-value"></a>Valor retornado

A função do primeiro membro retorna a forma maiúscula do parâmetro *ch*. Se não houver forma maiúscula, ela retorna *ch*.

A função do segundo membro retorna *por último*.

### <a name="remarks"></a>Comentários

A função do [do_toupper](#do_toupper)primeiro`ch`membro retorna do_toupper ( ). A função do segundo `first` `last`membro retorna [do_toupper](#do_toupper)( , ).

### <a name="example"></a>Exemplo

```cpp
// ctype_toupper.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "German_Germany" );

   char string[] = "Hello, my name is John";

   use_facet<ctype<char> > ( loc1 ).toupper
      ( string, string + strlen(string) );
   cout << "The uppercase string is: " << string << endl;
}
```

```Output
The uppercase string is: HELLO, MY NAME IS JOHN
```

## <a name="ctypewiden"></a><a name="widen"></a>ctype::ampliação

Converte um caractere de **tipo char** no caractere nativo `CharType` definido para o caractere correspondente do tipo usado por um local.

```cpp
CharType widen(char byte) const;
const char *widen(const char* first, const char* last, CharType* dest) const;
```

### <a name="parameters"></a>Parâmetros

*Byte*\
O caractere do tipo char no conjunto de caracteres nativo a ser convertido.

*Primeiro*\
Um ponteiro para o primeiro caractere no intervalo de caracteres a ser convertido.

*Última*\
Um ponteiro para o caractere imediatamente após o último caractere no intervalo de caracteres a ser convertido.

*Dest*\
Um ponteiro para o primeiro caractere do tipo `CharType` no intervalo de destino que armazena o intervalo convertido de caracteres.

### <a name="return-value"></a>Valor retornado

A função do primeiro membro `CharType` retorna o caractere do tipo que corresponde ao caractere parâmetro do tipo **de char**nativo .

A segunda função de membro retorna um ponteiro `CharType` para a faixa de destino de caracteres do tipo usado por um local convertido a partir de caracteres nativos do tipo **char**.

### <a name="remarks"></a>Comentários

A função do [do_widen](#do_widen)primeiro`byte`membro retorna do_widen ( ). A função do segundo`first` `last`membro `dest`retorna [do_widen](#do_widen)( , , ).

### <a name="example"></a>Exemplo

```cpp
// ctype_widen.cpp
// compile with: /EHsc /W3
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc1 ( "English" );
   char *str1 = "Hello everyone!";
   wchar_t str2 [16];
   bool result1 = (use_facet<ctype<wchar_t> > ( loc1 ).widen
      ( str1, str1 + strlen(str1), &str2[0] ) != 0);  // C4996
   str2[strlen(str1)] = '\0';
   cout << str1 << endl;
   wcout << &str2[0] << endl;

   ctype<wchar_t>::char_type charT;
   charT = use_facet<ctype<char> > ( loc1 ).widen( 'a' );
}
```

```Output
Hello everyone!
Hello everyone!
```

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

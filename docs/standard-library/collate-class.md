---
title: Classe collate
ms.date: 11/04/2016
f1_keywords:
- locale/std::collate
- locale/std::collate::char_type
- locale/std::collate::string_type
- locale/std::collate::compare
- locale/std::collate::do_compare
- locale/std::collate::do_hash
- locale/std::collate::do_transform
- locale/std::collate::hash
- locale/std::collate::transform
helpviewer_keywords:
- std::collate [C++]
- std::collate [C++], char_type
- std::collate [C++], string_type
- std::collate [C++], compare
- std::collate [C++], do_compare
- std::collate [C++], do_hash
- std::collate [C++], do_transform
- std::collate [C++], hash
- std::collate [C++], transform
ms.assetid: 92168798-9628-4a2e-be6e-fa62dcd4d6a6
ms.openlocfilehash: f05c2e9482f8a0bada3868fdc946d4d26a0e0e1d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371930"
---
# <a name="collate-class"></a>Classe collate

Um modelo de classe que descreve um objeto que pode servir como uma faceta local para controlar a ordem e o agrupamento de caracteres dentro de uma string, comparações entre eles e o hashing de strings.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class collate : public locale::facet;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em `id`. Em algumas linguagens, os caracteres são agrupados e tratados como um único caractere e, em outras, caracteres individuais são tratados como se fossem dois caracteres. Os serviços de agrupamento fornecidos pela classe collate fornecem o meio de classificar esses casos.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[Collate](#collate)|O construtor para objetos da classe `collate` que serve como uma faceta de localidade para tratar convenções de classificação de cadeia de caracteres.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que descreve um caractere do tipo `CharType`.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Comparar](#compare)|Compara duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.|
|[do_compare](#do_compare)|Uma função virtual chamada para comparar duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.|
|[do_hash](#do_hash)|Uma função virtual chamada para determinar o valor de hash das sequências de acordo com as respectivas regras específicas de faceta.|
|[do_transform](#do_transform)|Uma função virtual chamada para converter uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.|
|[Hash](#hash)|Determina o valor de hash da sequência de acordo com suas regras específicas de faceta.|
|[Transformar](#transform)|Converte uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="collatechar_type"></a><a name="char_type"></a>collate::char_type

Um tipo que descreve um caractere do tipo `CharType`.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

## <a name="collatecollate"></a><a name="collate"></a>collate::collate

O construtor de objetos da classe collate que funciona como uma faceta de localidade para manipular convenções de classificação de cadeia de caracteres.

```cpp
public:
    explicit collate(
    size_t _Refs = 0);

protected:
    collate(
const char* _Locname,
    size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

*_Locname*\
O nome da localidade.

### <a name="remarks"></a>Comentários

Os valores possíveis para o *parâmetro _Refs* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: Esses valores não estão definidos.

O construtor inicializa seu objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)(`_Refs`).

## <a name="collatecompare"></a><a name="compare"></a>collate::compare

Compara duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.

```cpp
int compare(const CharType* first1,
    const CharType* last1,
    const CharType* first2,
    const CharType* last2) const;
```

### <a name="parameters"></a>Parâmetros

*primeiro1*\
Ponteiro para o primeiro elemento na primeira sequência a ser comparada.

*último1*\
Ponteiro para o último elemento na primeira sequência a ser comparada.

*primeiro2*\
Ponteiro para o primeiro elemento na segunda sequência a ser comparada.

*último2*\
Ponteiro para o último elemento na segunda sequência a ser comparada.

### <a name="return-value"></a>Valor retornado

A função membro retornará:

- –1 se a primeira sequência comparar menos do que a segunda sequência.

- +1 se a segunda sequência comparar menos do que a primeira sequência.

- 0 se as sequências forem equivalentes.

### <a name="remarks"></a>Comentários

A primeira sequência comparará menos se ela tiver o elemento menor do par desigual mais antigo nas sequências ou, se não existir nenhum par desigual, mas a primeira sequência for menor.

A função do `first1`membro `last1` `first2`retorna `last2` [do_compare](#do_compare)( , , , ).

### <a name="example"></a>Exemplo

```cpp
// collate_compare.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <tchar.h>
using namespace std;

int main() {
   locale loc ( "German_germany" );
   _TCHAR * s1 = _T("Das ist wei\x00dfzz."); // \x00df is the German sharp-s, it comes before z in the German alphabet
   _TCHAR * s2 = _T("Das ist weizzz.");
   int result1 = use_facet<collate<_TCHAR> > ( loc ).
      compare ( s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << result1 << endl;

   locale loc2 ( "C" );
   int result2 = use_facet<collate<_TCHAR> > ( loc2 ).
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );
   cout << result2 << endl;
}
```

## <a name="collatedo_compare"></a><a name="do_compare"></a>colito::do_compare

Uma função virtual chamada para comparar duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.

```cpp
virtual int do_compare(const CharType* first1,
    const CharType* last1,
    const CharType* first2,
    const CharType* last2) const;
```

### <a name="parameters"></a>Parâmetros

*primeiro1*\
Ponteiro para o primeiro elemento na primeira sequência a ser comparada.

*último1*\
Ponteiro para o último elemento na primeira sequência a ser comparada.

*primeiro2*\
Ponteiro para o primeiro elemento na segunda sequência a ser comparada.

*último2*\
Ponteiro para o último elemento na segunda sequência a ser comparada.

### <a name="return-value"></a>Valor retornado

A função membro retornará:

- –1 se a primeira sequência comparar menos do que a segunda sequência.

- +1 se a segunda sequência comparar menos do que a primeira sequência.

- 0 se as sequências forem equivalentes.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido compara a seqüência em [ * primeiro1, Last1)* com a seqüência em *[ first2, last2*). Ele compara valores `operator<` aplicando entre pares `CharType`de elementos correspondentes do tipo . A primeira sequência comparará menos se ela tiver o elemento menor do par desigual mais antigo nas sequências ou, se não existir nenhum par desigual, mas a primeira sequência for menor.

### <a name="example"></a>Exemplo

Consulte o exemplo de [collate::compare](#compare), que chama `do_compare`.

## <a name="collatedo_hash"></a><a name="do_hash"></a>colito::do_hash

Uma função virtual chamada para determinar o valor de hash das sequências de acordo com as respectivas regras específicas de faceta.

```cpp
virtual long do_hash(const CharType* first, const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Um ponteiro para o primeiro caractere na sequência cujo valor será determinado.

*Última*\
Um ponteiro para o último caractere na sequência cujo valor será determinado.

### <a name="return-value"></a>Valor retornado

Um valor de hash do tipo **longo** da sequência.

### <a name="remarks"></a>Comentários

Um valor de hash pode ser útil, por exemplo, na distribuição de sequências de maneira pseudo-aleatória em uma matriz de listas.

### <a name="example"></a>Exemplo

Consulte o exemplo de [hash](#hash), que chama `do_hash`.

## <a name="collatedo_transform"></a><a name="do_transform"></a>colito::do_transform

Uma função virtual chamada para converter uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.

```cpp
virtual string_type do_transform(const CharType* first, const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Um ponteiro para o primeiro caractere na sequência a ser convertida.

*Última*\
Um ponteiro para o último caractere na sequência a ser convertida.

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que é a sequência de caracteres transformados.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido retorna um objeto de classe `first` `last` [string_type](#string_type) cuja seqüência controlada é uma cópia da seqüência [ . Se uma classe derivada decollate\< **CharType**> substituir [do_compare](#do_compare), ela também deverá substituir `do_transform` para haver correspondência. Quando passadas para `collate::compare`, duas cadeias de caracteres transformadas devem produzir o mesmo resultado que você obteria ao passar as cadeias de caracteres não transformadas para serem comparadas na classe derivada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [transform](#transform), que chama `do_transform`.

## <a name="collatehash"></a><a name="hash"></a>collate::hash

Determina o valor de hash da sequência de acordo com suas regras específicas de faceta.

```cpp
long hash(const CharType* first, const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Um ponteiro para o primeiro caractere na sequência cujo valor será determinado.

*Última*\
Um ponteiro para o último caractere na sequência cujo valor será determinado.

### <a name="return-value"></a>Valor retornado

Um valor de hash do tipo **longo** da sequência.

### <a name="remarks"></a>Comentários

A função do `first`membro `last`retorna [do_hash](#do_hash)( , ).

Um valor de hash pode ser útil, por exemplo, na distribuição de sequências de maneira pseudo-aleatória em uma matriz de listas.

### <a name="example"></a>Exemplo

```cpp
// collate_hash.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <tchar.h>
using namespace std;

int main( )
{
   locale loc ( "German_germany" );
   _TCHAR * s1 = _T("\x00dfzz abc."); // \x00df is the German sharp-s (looks like beta), it comes before z in the alphabet
   _TCHAR * s2 = _T("zzz abc."); // \x00df is the German sharp-s (looks like beta), it comes before z in the alphabet

   long r1 = use_facet< collate<_TCHAR> > ( loc ).
      hash (s1, &s1[_tcslen( s1 )-1 ]);
   long r2 =  use_facet< collate<_TCHAR> > ( loc ).
      hash (s2, &s2[_tcslen( s2 )-1 ] );
   cout << r1 << " " << r2 << endl;
}
```

```Output
541187293 551279837
```

## <a name="collatestring_type"></a><a name="string_type"></a>collate::string_type

Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.

```cpp
typedef basic_string<CharType> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias da seqüência de origem.

### <a name="example"></a>Exemplo

Para obter um exemplo de como declarar e usar `string_type`, consulte [transform](#transform).

## <a name="collatetransform"></a><a name="transform"></a>collate::transformar

Converte uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.

```cpp
string_type transform(const CharType* first, const CharType* last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Um ponteiro para o primeiro caractere na sequência a ser convertida.

*Última*\
Um ponteiro para o último caractere na sequência a ser convertida.

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que contém a sequência de caracteres transformados.

### <a name="remarks"></a>Comentários

A função do`first`membro `last`retorna [do_transform](#do_transform)( ).

### <a name="example"></a>Exemplo

```cpp
// collate_transform.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <tchar.h>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   _TCHAR* s1 = _T("\x00dfzz abc.");
   // \x00df is the German sharp-s (looks like beta),
   // it comes before z in the alphabet
   _TCHAR* s2 = _T("zzz abc.");

   collate<_TCHAR>::string_type r1;   // OK for typedef
   r1 = use_facet< collate<_TCHAR> > ( loc ).
      transform (s1, &s1[_tcslen( s1 )-1 ]);

   cout << r1 << endl;

   basic_string<_TCHAR> r2 = use_facet< collate<_TCHAR> > ( loc ).
      transform (s2, &s2[_tcslen( s2 )-1 ]);

   cout << r2 << endl;

   int result1 = use_facet<collate<_TCHAR> > ( loc ).compare
      (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );

   cout << _tcscmp(r1.c_str( ),r2.c_str( )) << result1
      << _tcscmp(s1,s2) <<endl;
}
```

```Output

-1-11
```

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

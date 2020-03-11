---
title: Classe time_put
ms.date: 11/04/2016
f1_keywords:
- xloctime/std::time_put
- locale/std::time_put::char_type
- locale/std::time_put::iter_type
- locale/std::time_put::do_put
- locale/std::time_put::put
helpviewer_keywords:
- std::time_put [C++]
- std::time_put [C++], char_type
- std::time_put [C++], iter_type
- std::time_put [C++], do_put
- std::time_put [C++], put
ms.assetid: df79493e-3331-48d2-97c3-ac3a745f0791
ms.openlocfilehash: 2c0ae501693a8abffc72a23be9c427f31bad65b6
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78867307"
---
# <a name="time_put-class"></a>Classe time_put

O modelo de classe descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores de tempo para sequências do tipo `CharType`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType,
    class OutputIterator = ostreambuf_iterator<CharType>>
class time_put : public locale::facet;
```

### <a name="parameters"></a>parâmetros

\ *CharType*
O tipo usado em um programa para codificar caracteres.

\ *OutputIterator*
O tipo de iterador no qual as funções put de tempo gravam sua saída.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|DESCRIÇÃO|
|-|-|
|[time_put](#time_put)|O construtor para objetos do tipo `time_put`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|DESCRIÇÃO|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[iter_type](#iter_type)|Um tipo que descreve um iterador de saída.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|DESCRIÇÃO|
|-|-|
|[do_put](#do_put)|Uma função virtual que gera informações de hora e data como uma sequência de `CharType`s.|
|[put](#put)|Gera informações de hora e data como uma sequência de `CharType`s.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<localidade >

**Namespace:** std

## <a name="char_type"></a>  time_put::char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

## <a name="do_put"></a>  time_put::do_put

Uma função virtual que gera informações de hora e data como uma sequência de `CharType`s.

```cpp
virtual iter_type do_put(
    iter_type next,
    ios_base& _Iosbase,
    const tm* _Pt,
    char _Fmt,
    char _Mod = 0) const;
```

### <a name="parameters"></a>parâmetros

*próximo*\
Um iterador de saída no qual a sequência de caracteres que representa a data e hora deve ser inserida.

*_Iosbase*\
Não utilizado.

*_Pt*\
As informações de data e hora que estão sendo geradas.

*_Fmt*\
O formato da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.

*_Mod*\
Um modificador do formato. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.

### <a name="return-value"></a>Valor retornado

Um iterador para a primeira posição após o último elemento inserido.

### <a name="remarks"></a>Comentários

A função de membro protegido virtual gera elementos sequenciais que começam em `next` de valores de tempo armazenados no objeto \* `_Pt`, do tipo `tm`. A função retorna um iterador que designa o próximo local a inserir um elemento após a saída gerada.

A saída é gerada pelas mesmas regras usadas pelo `strftime`, com um último argumento de *_Pt*, para gerar uma série de elementos **Char** em uma matriz. Cada elemento **Char** é presumido para mapear para um elemento equivalente do tipo `CharType` por um mapeamento simples de um-para-um. Se *_Mod* for igual a zero, o formato efetivo será "% F", em que F é substituído por *_Fmt*. Caso contrário, o formato efetivo é "% MF", onde M é substituído por *_Mod*.

### <a name="example"></a>Exemplo

Consulte o exemplo de [put](#put), que chama `do_put`.

## <a name="iter_type"></a>  time_put::iter_type

Um tipo que descreve um iterador de saída.

```cpp
typedef OutputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `OutputIterator`.

## <a name="put"></a>  time_put::put

Gera informações de hora e data como uma sequência de `CharType`s.

```cpp
iter_type put(iter_type next,
    ios_base& _Iosbase,
    char_type _Fill,
    const tm* _Pt,
    char _Fmt,
    char _Mod = 0) const;

iter_type put(iter_type next,
    ios_base& _Iosbase,
    char_type _Fill,
    const tm* _Pt,
    const CharType* first,
    const CharType* last) const;
```

### <a name="parameters"></a>parâmetros

*próximo*\
Um iterador de saída no qual a sequência de caracteres que representa a data e hora deve ser inserida.

*_Iosbase*\
Não utilizado.

*_Fill*\
O caractere do tipo `CharType` usado para espaçamento.

*_Pt*\
As informações de data e hora que estão sendo geradas.

*_Fmt*\
O formato da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.

*_Mod*\
Um modificador do formato. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.

*primeiro*\
O início da cadeia de caracteres de formatação da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.

*última*\
O final da cadeia de caracteres de formatação da saída. Consulte [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter valores válidos.

### <a name="return-value"></a>Valor retornado

Um iterador para a primeira posição após o último elemento inserido.

### <a name="remarks"></a>Comentários

A primeira função de membro retorna [do_put](#do_put)(`next`, `_Iosbase`, `_Fill`, `_Pt`, `_Fmt`, `_Mod`). A segunda função de membro copia para \* `next` + + qualquer elemento no intervalo [`first`, `last`) diferente de um percentual (%). Para um percentual seguido por um caractere *C* no intervalo [`first`, `last`), a função avalia `next` = `do_put`(`next`, `_Iosbase`, `_Fill`, `_Pt`, *C*, 0) e ignora *c*. Se, no entanto, *C* for um caractere qualificador do set EOQ #, seguido por um caractere `C2` no intervalo [`first`, `last`), a função avaliará `next` = `do_put`(`next`, `_Iosbase`, `_Fill`, `_Pt`, `C2`, *C*) e ignorará `C2`anteriores.

### <a name="example"></a>Exemplo

```cpp
// time_put_put.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
int main( )
{
   locale loc;
   basic_stringstream<char> pszPutI;
   ios_base::iostate st = 0;
   struct tm t;
   memset( &t, 0, sizeof( struct tm ) );

   t.tm_hour = 5;
   t.tm_min = 30;
   t.tm_sec = 40;
   t.tm_year = 00;
   t.tm_mday = 4;
   t.tm_mon = 6;

   pszPutI.imbue( loc );
   char *pattern = "x: %X %x";
   use_facet <time_put <char> >
   (loc).put(basic_ostream<char>::_Iter(pszPutI.rdbuf( )),
          pszPutI, ' ', &t, pattern, pattern+strlen(pattern));

      cout << "num_put( ) = " << pszPutI.rdbuf( )->str( ) << endl;

      char strftimebuf[255];
      strftime(&strftimebuf[0], 255, pattern, &t);
      cout << "strftime( ) = " << &strftimebuf[0] << endl;
}
```

```Output
num_put( ) = x: 05:30:40 07/04/00
strftime( ) = x: 05:30:40 07/04/00
```

## <a name="time_put"></a>  time_put::time_put

Construtor para objetos do tipo `time_put`.

```cpp
explicit time_put(size_t _Refs = 0);
```

### <a name="parameters"></a>parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \> 1: esses valores não estão definidos.

O construtor inicializa seu objeto base com [locale:: faceta](../standard-library/locale-class.md#facet_class)( *_Refs*).

## <a name="see-also"></a>Confira também

[\<locale>](../standard-library/locale.md)\
[Classe time_base](../standard-library/time-base-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

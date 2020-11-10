---
title: Typedefs `<ios>`
description: Descreve os TYPEDEFs da biblioteca de modelos padrão (STL) do C++ `<ios>` que dão suporte à `ios` classe da `iostream` biblioteca antiga.
ms.date: 11/06/2020
f1_keywords:
- iosfwd/std::ios
- iosfwd/std::streamoff
- iosfwd/std::streampos
- iosfwd/std::streamsize
- iosfwd/std::wios
- iosfwd/std::wstreampos
ms.openlocfilehash: b9dbed64c88a00f5ca065e23c4af2f3922634ece
ms.sourcegitcommit: b38485bb3a9d479e0c5d64ffc3d841fa2c2b366f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2020
ms.locfileid: "94441262"
---
# <a name="ios-typedefs"></a>Typedefs `<ios>`

## `ios`

Dá suporte à `ios` classe da `iostream` biblioteca antiga.

```cpp
typedef basic_ios<char, char_traits<char>> ios;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [`basic_ios`](../standard-library/basic-ios-class.md) , especializado para elementos do tipo **`char`** com características de caractere padrão.

## `streamoff`

Dá suporte a operações internas.

```cpp
#ifdef _WIN64
    typedef __int64 streamoff;
#else
    typedef long streamoff;
#endif
```

### <a name="remarks"></a>Comentários

O tipo é um inteiro assinado. Ele descreve um objeto que pode armazenar um deslocamento de byte em operações de posicionamento de fluxo. Sua representação tem pelo menos 32 bits de valor. Não é necessariamente grande o suficiente para representar uma posição de byte arbitrária dentro de um fluxo. O valor `streamoff(-1)` geralmente indica um deslocamento errado.

## `streampos`

Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.

```cpp
typedef fpos<mbstate_t> streampos;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para [`fpos`](../standard-library/fpos-class.md) <  `mbstate_t`>.

### <a name="example"></a>Exemplo

```cpp
// ios_streampos.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;

   ofstream x( "iostream.txt" );
   x << "testing";
   streampos y = x.tellp( );
   cout << streamoff( y ) << '\n';
}
```

```Output
7
```

## `streamsize`

Indica o tamanho do fluxo.

```cpp
#ifdef _WIN64
    typedef __int64 streamsize;
#else
    typedef int streamsize;
#endif
```

### <a name="remarks"></a>Comentários

O tipo é um inteiro com sinal que descreve um objeto que pode armazenar uma contagem do número de elementos envolvidos em várias operações de fluxo. Sua representação tem pelo menos 16 bits. Não é necessariamente grande o suficiente para representar uma posição de byte arbitrária dentro de um fluxo.

### <a name="example"></a>Exemplo

Depois de compilar e executar o programa a seguir, examine o arquivo `test.txt` para ver o efeito da configuração `streamsize` .

```cpp
// ios_streamsize.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;
   char a[16] = "any such text";
   ofstream x( "test.txt" );
   streamsize y = 6;
   x.write( a, y );
}
```

## `wios`

Dá suporte à `wios` classe da `iostream` biblioteca antiga.

```cpp
typedef basic_ios<wchar_t, char_traits<wchar_t>> wios;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [`basic_ios`](../standard-library/basic-ios-class.md) , especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## `wstreampos`

Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.

```cpp
typedef fpos<mbstate_t> wstreampos;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para [`fpos`](../standard-library/fpos-class.md) <  `mbstate_t`>.

### <a name="example"></a>Exemplo

```cpp
// ios_wstreampos.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;
   wofstream xw( "wiostream.txt" );
   xw << L"testing";
   wstreampos y = xw.tellp( );
   cout << streamoff( y ) << '\n';
}
```

```Output
7
```

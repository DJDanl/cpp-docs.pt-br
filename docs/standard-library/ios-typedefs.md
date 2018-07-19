---
title: Typedefs &lt;ios&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- iosfwd/std::ios
- iosfwd/std::streamoff
- iosfwd/std::streampos
- iosfwd/std::streamsize
- iosfwd/std::wios
- iosfwd/std::wstreampos
ms.assetid: 0b962632-3439-44de-bf26-20c67a7f0ff3
ms.openlocfilehash: d79e3361d58165ac356e2ef75c0a3fd1a4cb4f26
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38963635"
---
# <a name="ltiosgt-typedefs"></a>Typedefs &lt;ios&gt;

||||
|-|-|-|
|[ios](#ios)|[streamoff](#streamoff)|[streampos](#streampos)|
|[streamsize](#streamsize)|[wios](#wios)|[wstreampos](#wstreampos)|

## <a name="ios"></a>  ios

Dá suporte à classe ios da biblioteca iostream antiga.

```cpp
typedef basic_ios<char, char_traits<char>> ios;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a classe de modelo [basic_ios](../standard-library/basic-ios-class.md), especializado para elementos do tipo **char** com características de caractere padrão.

## <a name="streamoff"></a>  streamoff

Dá suporte a operações internas.

```cpp
#ifdef _WIN64
    typedef __int64 streamoff;
#else
    typedef long streamoff;
#endif
```

### <a name="remarks"></a>Comentários

O tipo é um inteiro com sinal que descreve um objeto que pode armazenar um deslocamento de byte envolvido em várias operações de posicionamento de fluxo. Sua representação tem pelo menos 32 bits de valor. Ela não é necessariamente grande o suficiente para representar uma posição de byte arbitrária dentro de um fluxo. O valor `streamoff(-1)` geralmente indica um deslocamento incorreto.

## <a name="streampos"></a>  streampos

Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.

```cpp
typedef fpos<mbstate_t> streampos;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de [fpos](../standard-library/fpos-class.md)< `mbstate_t`>.

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
   cout << y << endl;
}
```

```Output
7
```

## <a name="streamsize"></a>  streamsize

Indica o tamanho do fluxo.

```cpp
#ifdef _WIN64
    typedef __int64 streamsize;
#else
    typedef int streamsize;
#endif
```

### <a name="remarks"></a>Comentários

O tipo é um inteiro com sinal que descreve um objeto que pode armazenar uma contagem do número de elementos envolvidos em várias operações de fluxo. Sua representação tem pelo menos 16 bits. Ela não é necessariamente grande o suficiente para representar uma posição de byte arbitrária dentro de um fluxo.

### <a name="example"></a>Exemplo

Após compilar e executar o programa a seguir, examine o arquivo test.txt para ver o efeito da configuração `streamsize`.

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

## <a name="wios"></a>  wios

Dá suporte à classe wios da biblioteca iostream antiga.

```cpp
typedef basic_ios<wchar_t, char_traits<wchar_t>> wios;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a classe de modelo [basic_ios](../standard-library/basic-ios-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="wstreampos"></a>  wstreampos

Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.

```cpp
typedef fpos<mbstate_t> wstreampos;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de [fpos](../standard-library/fpos-class.md)< `mbstate_t`>.

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
   cout << y << endl;
}
```

```Output
7
```

## <a name="see-also"></a>Consulte também

[\<ios>](../standard-library/ios.md)<br/>

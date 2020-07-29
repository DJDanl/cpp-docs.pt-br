---
title: typedefs &lt;fstream&gt;
ms.date: 11/04/2016
f1_keywords:
- fstream/std::filebuf
- fstream/std::fstream
- fstream/std::ifstream
- fstream/std::ofstream
- fstream/std::wfilebuf
- fstream/std::wfstream
- fstream/std::wifstream
- fstream/std::wofstream
ms.assetid: 8dddef2d-7f17-42a6-ba08-6f6f20597d23
ms.openlocfilehash: a0f62f951fb6de4b32a27511ae38e1346cbc22e3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215745"
---
# <a name="ltfstreamgt-typedefs"></a>typedefs &lt;fstream&gt;

||||
|-|-|-|
|[filebuf](#filebuf)|[fstream](#fstream)|[ifstream](#ifstream)|
|[ofstream](#ofstream)|[wfilebuf](#wfilebuf)|[wfstream](#wfstream)|
|[wifstream](#wifstream)|[wofstream](#wofstream)|

## <a name="filebuf"></a><a name="filebuf"></a>filebuf

Um tipo `basic_filebuf` especializado em **`char`** parâmetros de modelo.

```cpp
typedef basic_filebuf<char, char_traits<char>> filebuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_filebuf](../standard-library/basic-filebuf-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="fstream"></a><a name="fstream"></a>fstream

Um tipo `basic_fstream` especializado em **`char`** parâmetros de modelo.

```cpp
typedef basic_fstream<char, char_traits<char>> fstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_fstream](../standard-library/basic-fstream-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="ifstream"></a><a name="ifstream"></a>ifstream

Define um fluxo a ser usado para ler dados de caractere de byte único em série de um arquivo. `ifstream`é um typedef que especializa o modelo de classe `basic_ifstream` para **`char`** .

Também há `wifstream` um typedef que é especializado `basic_ifstream` para ler caracteres de **`wchar_t`** largura dupla. Para saber mais, consulte [wifstream](../standard-library/fstream-typedefs.md#wifstream).

```cpp
typedef basic_ifstream<char, char_traits<char>> ifstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ifstream](../standard-library/basic-ifstream-class.md), especializado para elementos do tipo char com características de caractere padrão. Um exemplo é

```cpp
using namespace std;

ifstream infile("existingtextfile.txt");

if (!infile.bad())
{
    // Dump the contents of the file to cout.
    cout << infile.rdbuf();infile.close();
}
```

## <a name="ofstream"></a><a name="ofstream"></a>ofstream

Um tipo `basic_ofstream` especializado em **`char`** parâmetros de modelo.

```cpp
typedef basic_ofstream<char, char_traits<char>> ofstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ofstream](../standard-library/basic-ofstream-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="wfstream"></a><a name="wfstream"></a>wfstream

Um tipo `basic_fstream` especializado em **`wchar_t`** parâmetros de modelo.

```cpp
typedef basic_fstream<wchar_t, char_traits<wchar_t>> wfstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_fstream](../standard-library/basic-fstream-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="wifstream"></a><a name="wifstream"></a>wifstream

Um tipo `basic_ifstream` especializado em **`wchar_t`** parâmetros de modelo.

```cpp
typedef basic_ifstream<wchar_t, char_traits<wchar_t>> wifstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ifstream](../standard-library/basic-ifstream-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="wofstream"></a><a name="wofstream"></a>wofstream

Um tipo `basic_ofstream` especializado em **`wchar_t`** parâmetros de modelo.

```cpp
typedef basic_ofstream<wchar_t, char_traits<wchar_t>> wofstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ofstream](../standard-library/basic-ofstream-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="wfilebuf"></a><a name="wfilebuf"></a>wfilebuf

Um tipo `basic_filebuf` especializado em **`wchar_t`** parâmetros de modelo.

```cpp
typedef basic_filebuf<wchar_t, char_traits<wchar_t>> wfilebuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_filebuf](../standard-library/basic-filebuf-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="see-also"></a>Confira também

[\<fstream>](../standard-library/fstream.md)

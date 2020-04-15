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
ms.openlocfilehash: 57e481c131a6e4a1111b1ed88217b891d6fc96a8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317188"
---
# <a name="ltfstreamgt-typedefs"></a>typedefs &lt;fstream&gt;

||||
|-|-|-|
|[filebuf](#filebuf)|[fstream](#fstream)|[ifstream](#ifstream)|
|[ofstream](#ofstream)|[wfilebuf](#wfilebuf)|[wfstream](#wfstream)|
|[wifstream](#wifstream)|[wofstream](#wofstream)|

## <a name="filebuf"></a><a name="filebuf"></a>filebuf

Um `basic_filebuf` tipo especializado em parâmetros de modelo **de char.**

```cpp
typedef basic_filebuf<char, char_traits<char>> filebuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de modelo de classe [basic_filebuf,](../standard-library/basic-filebuf-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="fstream"></a><a name="fstream"></a>fstream

Um `basic_fstream` tipo especializado em parâmetros de modelo **de char.**

```cpp
typedef basic_fstream<char, char_traits<char>> fstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_fstream,](../standard-library/basic-fstream-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="ifstream"></a><a name="ifstream"></a>ifstream

Define um fluxo a ser usado para ler dados de caractere de byte único em série de um arquivo. `ifstream`é um typedef que é `basic_ifstream` especializado o modelo de classe para **char**.

Há também `wifstream`, um typedef `basic_ifstream` especializado para ler **wchar_t** caracteres de dupla largura. Para saber mais, consulte [wifstream](../standard-library/fstream-typedefs.md#wifstream).

```cpp
typedef basic_ifstream<char, char_traits<char>> ifstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_ifstream,](../standard-library/basic-ifstream-class.md)especializado para elementos de tipo char com traços de caractere padrão. Um exemplo é

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

Um `basic_ofstream` tipo especializado em parâmetros de modelo **de char.**

```cpp
typedef basic_ofstream<char, char_traits<char>> ofstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_ofstream,](../standard-library/basic-ofstream-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="wfstream"></a><a name="wfstream"></a>wfstream

Um `basic_fstream` tipo especializado em parâmetros de modelo **wchar_t.**

```cpp
typedef basic_fstream<wchar_t, char_traits<wchar_t>> wfstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de modelo de classe [basic_fstream,](../standard-library/basic-fstream-class.md)especializado para elementos do tipo **wchar_t** com traços de caractere padrão.

## <a name="wifstream"></a><a name="wifstream"></a>wifstream

Um `basic_ifstream` tipo especializado em parâmetros de modelo **wchar_t.**

```cpp
typedef basic_ifstream<wchar_t, char_traits<wchar_t>> wifstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_ifstream,](../standard-library/basic-ifstream-class.md)especializado para elementos do tipo **wchar_t** com traços de caractere padrão.

## <a name="wofstream"></a><a name="wofstream"></a>wofstream

Um `basic_ofstream` tipo especializado em parâmetros de modelo **wchar_t.**

```cpp
typedef basic_ofstream<wchar_t, char_traits<wchar_t>> wofstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de modelo de classe [basic_ofstream,](../standard-library/basic-ofstream-class.md)especializado para elementos de tipo **wchar_t** com traços de caractere padrão.

## <a name="wfilebuf"></a><a name="wfilebuf"></a>wfilebuf

Um `basic_filebuf` tipo especializado em parâmetros de modelo **wchar_t.**

```cpp
typedef basic_filebuf<wchar_t, char_traits<wchar_t>> wfilebuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_filebuf,](../standard-library/basic-filebuf-class.md)especializado para elementos do tipo **wchar_t** com traços de caractere padrão.

## <a name="see-also"></a>Confira também

[\<fstream>](../standard-library/fstream.md)

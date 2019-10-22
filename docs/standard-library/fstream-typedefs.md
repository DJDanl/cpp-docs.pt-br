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
ms.openlocfilehash: 3f4104b28f5becfdbf62ede16faa81e855fcac8c
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689649"
---
# <a name="ltfstreamgt-typedefs"></a>typedefs &lt;fstream&gt;

||||
|-|-|-|
|[filebuf](#filebuf)|[fstream](#fstream)|[ifstream](#ifstream)|
|[ofstream](#ofstream)|[wfilebuf](#wfilebuf)|[wfstream](#wfstream)|
|[wifstream](#wifstream)|[wofstream](#wofstream)|

## <a name="filebuf"></a>  filebuf

Um tipo `basic_filebuf` especializado em parâmetros de modelo **Char** .

```cpp
typedef basic_filebuf<char, char_traits<char>> filebuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_filebuf](../standard-library/basic-filebuf-class.md), especializado para elementos do tipo **Char** com características de caractere padrão.

## <a name="fstream"></a>  fstream

Um tipo `basic_fstream` especializado em parâmetros de modelo **Char** .

```cpp
typedef basic_fstream<char, char_traits<char>> fstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_fstream](../standard-library/basic-fstream-class.md), especializado para elementos do tipo **Char** com características de caractere padrão.

## <a name="ifstream"></a>  ifstream

Define um fluxo a ser usado para ler dados de caractere de byte único em série de um arquivo. `ifstream` é um typedef que especializa o modelo de classe `basic_ifstream` para **Char**.

Também há `wifstream`, um typedef que especializa `basic_ifstream` para ler os caracteres de **wchar_t** de largura dupla. Para saber mais, consulte [wifstream](../standard-library/fstream-typedefs.md#wifstream).

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

## <a name="ofstream"></a>  ofstream

Um tipo `basic_ofstream` especializado em parâmetros de modelo **Char** .

```cpp
typedef basic_ofstream<char, char_traits<char>> ofstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ofstream](../standard-library/basic-ofstream-class.md), especializado para elementos do tipo **Char** com características de caractere padrão.

## <a name="wfstream"></a>  wfstream

Um tipo `basic_fstream` especializado em parâmetros de modelo **wchar_t** .

```cpp
typedef basic_fstream<wchar_t, char_traits<wchar_t>> wfstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_fstream](../standard-library/basic-fstream-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="wifstream"></a>  wifstream

Um tipo `basic_ifstream` especializado em parâmetros de modelo **wchar_t** .

```cpp
typedef basic_ifstream<wchar_t, char_traits<wchar_t>> wifstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ifstream](../standard-library/basic-ifstream-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="wofstream"></a>  wofstream

Um tipo `basic_ofstream` especializado em parâmetros de modelo **wchar_t** .

```cpp
typedef basic_ofstream<wchar_t, char_traits<wchar_t>> wofstream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ofstream](../standard-library/basic-ofstream-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="wfilebuf"></a>  wfilebuf

Um tipo `basic_filebuf` especializado em parâmetros de modelo **wchar_t** .

```cpp
typedef basic_filebuf<wchar_t, char_traits<wchar_t>> wfilebuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_filebuf](../standard-library/basic-filebuf-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="see-also"></a>Consulte também

[\<fstream>](../standard-library/fstream.md)

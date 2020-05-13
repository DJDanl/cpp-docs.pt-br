---
title: Typedefs &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::iostream
- istream/std::istream
- istream/std::wiostream
- istream/std::wistream
ms.assetid: 55bc1f84-53a7-46ca-a36f-ac6ef75d0374
ms.openlocfilehash: e9228bddcc3b99503b6b5f0e93b5ed6eeed773d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363088"
---
# <a name="ltistreamgt-typedefs"></a>Typedefs &lt;istream&gt;

||||
|-|-|-|
|[iostream](#iostream)|[Istream](#istream)|[wiostream](#wiostream)|
|[wistream](#wistream)|

## <a name="iostream"></a><a name="iostream"></a>Iostream

Um `basic_iostream` tipo especializado em **char**.

```cpp
typedef basic_iostream<char, char_traits<char>> iostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_iostream,](../standard-library/basic-iostream-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="istream"></a><a name="istream"></a>Istream

Um `basic_istream` tipo especializado em **char**.

```cpp
typedef basic_istream<char, char_traits<char>> istream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_istream,](../standard-library/basic-istream-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="wiostream"></a><a name="wiostream"></a>wiostream

Um `basic_iostream` tipo especializado em **wchar_t**.

```cpp
typedef basic_iostream<wchar_t, char_traits<wchar_t>> wiostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de modelo de classe [basic_iostream,](../standard-library/basic-iostream-class.md)especializado para elementos do tipo **wchar_t** com traços de caractere padrão.

## <a name="wistream"></a><a name="wistream"></a>wistream

Um `basic_istream` tipo especializado em **wchar_t**.

```cpp
typedef basic_istream<wchar_t, char_traits<wchar_t>> wistream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de modelo de classe [basic_istream,](../standard-library/basic-istream-class.md)especializado para elementos de tipo **wchar_t** com traços de caractere padrão.

## <a name="see-also"></a>Confira também

[\<istream>](../standard-library/istream.md)

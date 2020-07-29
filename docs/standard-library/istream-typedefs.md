---
title: Typedefs &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::iostream
- istream/std::istream
- istream/std::wiostream
- istream/std::wistream
ms.assetid: 55bc1f84-53a7-46ca-a36f-ac6ef75d0374
ms.openlocfilehash: 1e162dc9fb784bda5b4b9834d083012cf76ed6e3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217708"
---
# <a name="ltistreamgt-typedefs"></a>Typedefs &lt;istream&gt;

||||
|-|-|-|
|[iostream](#iostream)|[IStream](#istream)|[wiostream](#wiostream)|
|[wistream](#wistream)|

## <a name="iostream"></a><a name="iostream"></a>iostream

Um tipo `basic_iostream` especializado em **`char`** .

```cpp
typedef basic_iostream<char, char_traits<char>> iostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_iostream](../standard-library/basic-iostream-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="istream"></a><a name="istream"></a>IStream

Um tipo `basic_istream` especializado em **`char`** .

```cpp
typedef basic_istream<char, char_traits<char>> istream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_istream](../standard-library/basic-istream-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="wiostream"></a><a name="wiostream"></a>wiostream

Um tipo `basic_iostream` especializado em **`wchar_t`** .

```cpp
typedef basic_iostream<wchar_t, char_traits<wchar_t>> wiostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_iostream](../standard-library/basic-iostream-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="wistream"></a><a name="wistream"></a>wistream

Um tipo `basic_istream` especializado em **`wchar_t`** .

```cpp
typedef basic_istream<wchar_t, char_traits<wchar_t>> wistream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_istream](../standard-library/basic-istream-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="see-also"></a>Confira também

[\<istream>](../standard-library/istream.md)

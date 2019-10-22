---
title: Typedefs &lt;istream&gt;
ms.date: 11/04/2016
f1_keywords:
- istream/std::iostream
- istream/std::istream
- istream/std::wiostream
- istream/std::wistream
ms.assetid: 55bc1f84-53a7-46ca-a36f-ac6ef75d0374
ms.openlocfilehash: 9a25e4aa9ee42ea36d1bb8d6b196b36ff5c97758
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689484"
---
# <a name="ltistreamgt-typedefs"></a>Typedefs &lt;istream&gt;

||||
|-|-|-|
|[iostream](#iostream)|[istream](#istream)|[wiostream](#wiostream)|
|[wistream](#wistream)|

## <a name="iostream"></a>  iostream

Um tipo `basic_iostream` especializado em **Char**.

```cpp
typedef basic_iostream<char, char_traits<char>> iostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_iostream](../standard-library/basic-iostream-class.md), especializado para elementos do tipo **Char** com características de caractere padrão.

## <a name="istream"></a>  istream

Um tipo `basic_istream` especializado em **Char**.

```cpp
typedef basic_istream<char, char_traits<char>> istream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_istream](../standard-library/basic-istream-class.md), especializado para elementos do tipo **Char** com características de caractere padrão.

## <a name="wiostream"></a>  wiostream

Um tipo `basic_iostream` especializado em **wchar_t**.

```cpp
typedef basic_iostream<wchar_t, char_traits<wchar_t>> wiostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_iostream](../standard-library/basic-iostream-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="wistream"></a>  wistream

Um tipo `basic_istream` especializado em **wchar_t**.

```cpp
typedef basic_istream<wchar_t, char_traits<wchar_t>> wistream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_istream](../standard-library/basic-istream-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="see-also"></a>Consulte também

[\<istream>](../standard-library/istream.md)

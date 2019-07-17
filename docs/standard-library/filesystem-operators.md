---
title: Operadores &lt;filesystem&gt;
ms.date: 11/04/2016
f1_keywords:
- FILESYSTEM/std::experimental::filesystem::operator==
- FILESYSTEM/std::experimental::filesystem::operator!=
- FILESYSTEM/std::experimental::filesystem::operator<
- FILESYSTEM/std::experimental::filesystem::operator<=
- FILESYSTEM/std::experimental::filesystem::operator>
- FILESYSTEM/std::experimental::filesystem::operator>=
- FILESYSTEM/std::experimental::filesystem::operator/
- FILESYSTEM/std::experimental::filesystem::operator<<
- FILESYSTEM/std::experimental::filesystem::operator>>
ms.assetid: 102c4833-aa3b-41a8-8998-f5003c546bfd
ms.openlocfilehash: 819c91e707e50a190aa58eda62f8e07f3451b033
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68240722"
---
# <a name="ltfilesystemgt-operators"></a>Operadores &lt;filesystem&gt;

Os operadores executam uma comparação léxica de dois caminhos como cadeias de caracteres. Use o `equivalent` função para determinar se dois caminhos (por exemplo, um caminho relativo e um caminho absoluto) se referem ao mesmo arquivo ou diretório no disco.

Para obter mais informações, consulte [Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="operator"></a>operator==

```cpp
bool operator==(const path& left, const path& right) noexcept;
```

A função retorna left.native() == right.native().

## <a name="operator"></a>operator!=

```cpp
bool operator!=(const path& left, const path& right) noexcept;
```

A função retorna !(left == right).

## <a name="operator"></a>operador <

```cpp
bool operator<(const path& left, const path& right) noexcept;
```

A função retorna left.native() < right.native().

## <a name="operator"></a>Operador <=

```cpp
bool operator<=(const path& left, const path& right) noexcept;
```

A função retorna !(right \< left).

## <a name="operator"></a>Operador >

```cpp
bool operator>(const path& left, const path& right) noexcept;
```

A função retorna direita \< esquerda.

## <a name="operator"></a>Operador >=

```cpp
bool operator>=(const path& left, const path& right) noexcept;
```

A função retorna !(left < right).

## <a name="operator"></a>operator/

```cpp
path operator/(const path& left, const path& right);
```

A função executa:

```cpp
basic_string<Elem, Traits> str;
path ans = left;
return (ans /= right);
```

## <a name="operator"></a>Operador <<

```cpp
template <class Elem, class Traits>
basic_ostream<Elem, Traits>& operator<<(basic_ostream<Elem, Traits>& os, const path& pval);
```

A função retorna os << pval.string\<Elem, Traits>().

## <a name="operator"></a>Operador >>

```cpp
template <class Elem, class Traits>
basic_istream<Elem, Traits>& operator<<(basic_istream<Elem, Traits>& is, const path& pval);
```

A função executa:

```cpp
basic_string<Elem, Traits> str;
is>> str;
pval = str;
return (is);
```

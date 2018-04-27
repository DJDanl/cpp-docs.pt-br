---
title: Operadores &lt;filesystem&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
ms.assetid: 102c4833-aa3b-41a8-8998-f5003c546bfd
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 237287af88a7bf726948e0b17e5d1f3980ab459f
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltfilesystemgt-operators"></a>Operadores &lt;filesystem&gt;

Os operadores executam uma comparação léxica de dois caminhos como cadeias de caracteres. Use a função **equivalent** para determinar se dois caminhos (por exemplo, um caminho relativo e um caminho absoluto) fazem referência ao mesmo arquivo ou diretório no disco.

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

## <a name="see-also"></a>Consulte também

[Classe Path (biblioteca padrão do C++)](../standard-library/path-class.md)<br/>
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>

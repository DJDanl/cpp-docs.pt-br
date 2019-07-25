---
title: '&lt;cstddef&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cstddef>
helpviewer_keywords:
- cstddef header
ms.assetid: be8d1e39-5974-41ee-b41d-eafa6c82ffce
ms.openlocfilehash: 87d268977ee46112fedce517e66a9e68071863db
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457566"
---
# <a name="ltcstddefgt"></a>&lt;cstddef&gt;

Inclui o cabeçalho \<de biblioteca padrão C stddef. h > e adiciona nomes associados `std` ao namespace. A inclusão desse cabeçalho garante que os nomes declarados usando vínculo externo no cabeçalho da biblioteca padrão C sejam `std` declarados no namespace.

> [!NOTE]
> \<cstddef > inclui o tipo **byte** e não inclui o tipo **wchar_t**.

## <a name="syntax"></a>Sintaxe

```cpp
#include <cstddef>
```

## <a name="namespace-and-macros"></a>Namespace e macros

```cpp
namespace std {
    using ptrdiff_t = see definition;
    using size_t = see definition;
    using max_align_t = see definition;
    using nullptr_t = decltype(nullptr);
}

#define NULL  // an implementation-defined null pointer constant
#define offsetof(type, member-designator)
```

### <a name="parameters"></a>Parâmetros

*ptrdiff_t*\
Um tipo de inteiro assinado definido por implementação que pode conter a diferença de dois subscritos em um objeto de matriz.

*size_t*\
Um tipo de inteiro sem sinal definido pela implementação que é grande o suficiente para conter o tamanho em bytes de qualquer objeto.

*max_align_t*\
Um tipo de POD cujo requisito de alinhamento é, pelo menos, tão grande quanto o de cada tipo escalar, e cujo requisito de alinhamento tem suporte em cada contexto.

*nullptr_t*\
Um sinônimo para o tipo de uma expressão **nullptr** . Embora um endereço **nullptr** não possa ser obtido, o endereço de outro objeto *nullptr_t* que é um lvalue pode ser obtido.

## <a name="byte-class"></a>Classe de byte

```cpp
enum class byte : unsigned char {};

template <class IntType>
    constexpr byte& operator<<=(byte& b, IntType shift) noexcept;
    constexpr byte operator<<(byte b, IntType shift) noexcept;
    constexpr byte& operator>>=(byte& b, IntType shift) noexcept;
    constexpr byte operator>>(byte b, IntType shift) noexcept;

constexpr byte& operator|=(byte& left, byte right) noexcept;
constexpr byte operator|(byte left, byte right) noexcept;
constexpr byte& operator&=(byte& left, byte right) noexcept;
constexpr byte operator&(byte left, byte right) noexcept;
constexpr byte& operator^=(byte& left, byte right) noexcept;
constexpr byte operator^(byte left, byte right) noexcept;
constexpr byte operator~(byte b) noexcept;

template <class IntType>
    IntType to_integer(byte b) noexcept;
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

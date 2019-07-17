---
title: '&lt;cstddef&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cstddef>
helpviewer_keywords:
- cstddef header
ms.assetid: be8d1e39-5974-41ee-b41d-eafa6c82ffce
ms.openlocfilehash: 15d13a3af35cb41950df8aeba0c86d779e701ddb
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68244441"
---
# <a name="ltcstddefgt"></a>&lt;cstddef&gt;

Inclui o cabeçalho da biblioteca padrão C \<stddef. h > e adiciona os nomes associados ao `std` namespace. Inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca padrão C são declarados no `std` namespace.

> [!NOTE]
> \<cstddef > inclui o tipo **bytes** e não inclui o tipo **wchar_t**.

## <a name="syntax"></a>Sintaxe

```cpp
#include <cstddef>
```

## <a name="namespace-and-macros"></a>Namespace e Macros

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
Uma implementação definida, tipo de inteiro que pode conter a diferença de dois subscritos em um objeto de matriz com sinal.

*size_t*\
Um tipo de inteiro sem sinal definido pela implementação que é grande o suficiente para conter o tamanho em bytes de qualquer objeto.

*max_align_t*\
Um tipo POD cujo requisito de alinhamento é pelo menos tão grande que todos os tipos escalares, e cujo requisito de alinhamento é suportado em cada contexto.

*nullptr_t*\
Um sinônimo para o tipo de um **nullptr** expressão. Embora uma **nullptr** endereço não pode ser usado, o endereço de outro *nullptr_t* objeto que é um lvalue pode ser executado.

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

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>

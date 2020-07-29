---
title: '&lt;funções de span &gt;'
ms.date: 05/28/2020
f1_keywords:
- span/std::span::as_bytes
- span/std::as_writable_bytes
helpviewer_keywords:
- std::span [C++], as_writable_bytes
- std::as_bytes [C++]
ms.openlocfilehash: f51c99d2f2a051a07cefcb985fdb46340fefb3ee
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217435"
---
# <a name="ltspangt-functions"></a>&lt;funções de span &gt;

O \<span> cabeçalho inclui as seguintes funções não-membro que operam em objetos de **span** .

| **Funções não membro** | **Descrição** |
|-|-|
|[as_bytes](#as_bytes) | Obtenha uma exibição somente leitura da representação de objeto dos elementos no span. |
|[as_writable_bytes](#as_writable_bytes) | Obtenha uma exibição de leitura/gravação da representação de objeto dos elementos no span. |

## <a name="as_bytes"></a>`as_bytes`

Obtenha uma exibição somente leitura da representação de objeto dos elementos no span.

```cpp
template <class T, size_t Extent>
auto as_bytes(span<T, Extent> s) noexcept;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo dos elementos no span.

*Tention*\
O número de elementos no span (se conhecido em tempo de compilação), caso contrário, `dynamic_extent` indicando que o número de elementos não é conhecido até o tempo de execução.

*&*\
O intervalo para obter a representação bruta de.

### <a name="return-value"></a>Valor retornado

Um `span<const byte, S>` para o primeiro item armazenado no span onde `S` é`{reinterpret_cast<const std::byte*>(s.data()), s.size_bytes()}`

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

void main()
{
    int a[] = { 0,1,2 };
    span <int> mySpan(a);
    auto bytes = std::as_bytes(mySpan);
}
```

## <a name="as_writable_bytes"></a>`as_writable_bytes`

Se `T` não estiver **`const`** , obtém uma exibição de leitura/gravação da representação de byte bruto dos elementos no span.

```cpp
template <class T, size_t Extent>
auto as_writable_bytes(span<T, Extent> s) noexcept;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo dos elementos no span.

*Tention*\
O número de elementos no span (se conhecido em tempo de compilação), caso contrário, `dynamic_extent` indicando que o número de elementos não é conhecido até o tempo de execução.

*&*\
O intervalo para obter a representação bruta de.

### <a name="return-value"></a>Valor retornado

Um `span<byte, S>` para o primeiro item armazenado no span onde `S` é`{reinterpret_cast<std::byte*>(s.data()), s.size_bytes()}`

### <a name="example"></a>Exemplo

```cpp
#include <span>
#include <iostream>

using namespace std;

void main()
{
    int a[] = { 0,1,2 };
    span <int> mySpan(a);
    auto bytes = as_writable_bytes(mySpan);
}
```

## <a name="see-also"></a>Confira também

[\<span>](span.md)

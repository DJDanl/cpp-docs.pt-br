---
title: Classe messages_base
ms.date: 11/04/2016
f1_keywords:
- xlocmes/std::messages_base
helpviewer_keywords:
- messages_base class
ms.assetid: 9aad38c6-4c13-445d-b096-364bd0836efb
ms.openlocfilehash: b0fe7d66842fb77c6fd03f62b012babcbc9f7f3a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215641"
---
# <a name="messages_base-class"></a>Classe messages_base

A classe base descreve um **`int`** tipo para o catálogo de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
struct messages_base : locale::facet {
    typedef int catalog;
    explicit messages_base(size_t _Refs = 0)
};
```

## <a name="remarks"></a>Comentários

O catálogo de tipos é um sinônimo para **`int`** o tipo que descreve os possíveis valores de retorno das mensagens:: [do_open](../standard-library/messages-class.md#do_open).

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<locale>

**Namespace:** std

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

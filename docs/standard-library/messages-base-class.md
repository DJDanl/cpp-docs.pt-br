---
title: Classe messages_base
ms.date: 11/04/2016
f1_keywords:
- xlocmes/std::messages_base
helpviewer_keywords:
- messages_base class
ms.assetid: 9aad38c6-4c13-445d-b096-364bd0836efb
ms.openlocfilehash: 79b6cb5f0b0c219e959f53fdc667f4c8af273cef
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68451844"
---
# <a name="messagesbase-class"></a>Classe messages_base

A classe base descreve um tipo **int** para o catálogo de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
struct messages_base : locale::facet {
    typedef int catalog;
    explicit messages_base(size_t _Refs = 0)
};
```

## <a name="remarks"></a>Comentários

O catálogo de tipos é um sinônimo para o tipo **int** que descreve os possíveis valores de retorno das mensagens:: [do_open](../standard-library/messages-class.md#do_open).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

---
title: Typedefs &lt;new&gt;
ms.date: 11/04/2016
f1_keywords:
- new/std::new_handler
ms.assetid: aef01de1-06b5-4b6c-aebc-2c9f423d7e47
ms.openlocfilehash: 85c8d0c2974f734783e3d9c2ad1269f84d605dec
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62223630"
---
# <a name="ltnewgt-typedefs"></a>Typedefs &lt;new&gt;

| |
| - |
|[new_handler](#new_handler)|

## <a name="new_handler"></a>  new_handler

O tipo aponta para uma função adequada para uso como um manipulador new.

```cpp
typedef void (*new_handler)();
```

### <a name="remarks"></a>Comentários

Esse tipo de função do manipulador é chamado pelo **operatornew** ou `operator new[]` quando eles não podem atender uma solicitação de armazenamento adicional.

### <a name="example"></a>Exemplo

Consulte [set_new_handler](../standard-library/new-functions.md#set_new_handler) para obter um exemplo usando `new_handler` como um valor retornado.

## <a name="see-also"></a>Consulte também

[\<new>](../standard-library/new.md)<br/>

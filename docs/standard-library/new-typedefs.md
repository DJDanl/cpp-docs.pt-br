---
title: Typedefs &lt;new&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- new/std::new_handler
ms.assetid: aef01de1-06b5-4b6c-aebc-2c9f423d7e47
caps.latest.revision: 7
manager: ghogen
ms.openlocfilehash: 53a13168986171d3240cc15e405fc08b3db07e96
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltnewgt-typedefs"></a>Typedefs &lt;new&gt;

||
|-|
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

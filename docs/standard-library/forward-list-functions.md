---
title: Funções &lt;forward_list&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- forward_list/std::swap
ms.assetid: 0d6bc656-7049-4651-a4bd-c9a805e47756
caps.latest.revision: 11
manager: ghogen
ms.openlocfilehash: 7b990c760a94589967d5e2020082cb1f48250dac
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltforwardlistgt-functions"></a>Funções &lt;forward_list&gt;

||
|-|
|[swap](#swap)|

## <a name="swap"></a>  swap

Troca os elementos de duas listas de encaminhamento.

```cpp
void swap(
    forward_list <Type, Allocator>& left,
    forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`left`|Um objeto do tipo `forward_list`.|
|`right`|Um objeto do tipo `forward_list`.|

### <a name="remarks"></a>Comentários

Esta função de modelo executa `left.swap(right)`.

## <a name="see-also"></a>Consulte também

[<forward_list>](../standard-library/forward-list.md)<br/>

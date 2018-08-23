---
title: 'Método comptr:: Internaladdref | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::InternalAddRef
dev_langs:
- C++
helpviewer_keywords:
- InternalAddRef method
ms.assetid: f8e860ef-c56e-42a6-a712-77aaab1464ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7d9217a91b6b6ceda3a0743f94186dc52cbb7f80
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613344"
---
# <a name="comptrinternaladdref-method"></a>Método ComPtr::InternalAddRef

Incrementa a contagem de referência da interface associada a este **ComPtr**.

## <a name="syntax"></a>Sintaxe

```cpp
void InternalAddRef() const;
```

## <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe ComPtr](../windows/comptr-class.md)
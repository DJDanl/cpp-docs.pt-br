---
title: Membro de dados ComPtr::ptr_ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::ptr_
dev_langs:
- C++
helpviewer_keywords:
- ptr_ data member
ms.assetid: c84f9dda-8ff9-422d-91f2-1a41206bf9ad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8c1e1a8bc076144d80358191cd8eca209057b869
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42599171"
---
# <a name="comptrptr-data-member"></a>Membro de dados ComPtr::ptr_

Contém um ponteiro para a interface que está associado e gerenciada por esse **ComPtr**.

## <a name="syntax"></a>Sintaxe

```cpp
InterfaceType *ptr_;
```

## <a name="remarks"></a>Comentários

**PTR _** é um membro de dados interno, protegido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe ComPtr](../windows/comptr-class.md)
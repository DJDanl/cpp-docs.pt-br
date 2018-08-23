---
title: 'Construtor mutex:: mutex | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex::Mutex
dev_langs:
- C++
helpviewer_keywords:
- Mutex, constructor
ms.assetid: 504afcdc-775a-4c98-a06f-4fb4663eba3f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 62a1fc796188c38dfbd3aff004eba15b7e30ea89
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600499"
---
# <a name="mutexmutex-constructor"></a>Construtor Mutex::Mutex

Inicializa uma nova instância dos **Mutex** classe.

## <a name="syntax"></a>Sintaxe

```cpp
explicit Mutex(
   HANDLE h
);

Mutex(
   _Inout_ Mutex&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*  
Um identificador ou uma referência de rvalue a um identificador para um **Mutex** objeto.

## <a name="remarks"></a>Comentários

O primeiro construtor inicializa um **Mutex** objeto do identificador especificado. O segundo construtor inicializa um **Mutex** objeto de identificador especificado e, em seguida, move o propriedade do mutex para atual **Mutex** objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também
[Classe Mutex](../windows/mutex-class1.md)
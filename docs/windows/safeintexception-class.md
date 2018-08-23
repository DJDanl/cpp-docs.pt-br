---
title: Classe SafeIntException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeIntException Class
dev_langs:
- C++
helpviewer_keywords:
- SafeIntException class
ms.assetid: 88bef958-1f48-4d55-ad4f-d1f9581a293a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e5996d4e86275dd154e4c6931a55416885929abf
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42603655"
---
# <a name="safeintexception-class"></a>Classe SafeIntException

O `SafeInt` classe usa **SafeIntException** para identificar o motivo pelo qual uma operação matemática não pode ser concluída.

## <a name="syntax"></a>Sintaxe

```cpp
class SafeIntException;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

[SafeIntException::SafeIntException](../windows/safeintexception-safeintexception.md)  
Cria uma **SafeIntException** objeto.

## <a name="remarks"></a>Comentários

O [classe SafeInt](../windows/safeint-class.md) é a única classe que usa o **SafeIntException** classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Classe SafeIntException](../windows/safeintexception-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** safeint

**Namespace:** MSL:: Utilities

## <a name="see-also"></a>Consulte também

[Biblioteca SafeInt](../windows/safeint-library.md)  
[Classe SafeInt](../windows/safeint-class.md)
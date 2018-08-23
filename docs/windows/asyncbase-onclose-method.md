---
title: 'Método asyncbase:: OnClose | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::OnClose
dev_langs:
- C++
helpviewer_keywords:
- OnClose method
ms.assetid: 96766450-c262-4611-8534-7d190b799142
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fd6bd03b1e5aa3f690d93a5c51cc6664e0547c2e
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42597343"
---
# <a name="asyncbaseonclose-method"></a>Método AsyncBase::OnClose

Quando substituído em uma classe derivada, fecha uma operação assíncrona.

## <a name="syntax"></a>Sintaxe

```cpp
virtual void OnClose(
   void
) = 0;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)  
[Método AsyncBase::Close](../windows/asyncbase-close-method.md)
---
title: Variáveis globais da ATL | Microsoft Docs
ms.custom: ''
ms.date: 12/06/2017
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ATLBASE/_pAtlModule
dev_langs:
- C++
helpviewer_keywords:
- global variables, ATL
- _pAtlModule
ms.assetid: e881a319-99ca-4f5d-8a0b-34b3dcd0f37f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d33c2a3de5b94f522833db67dfb190ede3a8a63
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50054947"
---
# <a name="atl-global-variables"></a>Variáveis globais da ATL

## <a name="patlmodule"></a>_pAtlModule

Uma variável global armazenar um ponteiro para o módulo atual.

```cpp
__declspec(selectany) CAtlModule * _pAtlModule
```

### <a name="remarks"></a>Comentários

Métodos nessa variável global podem ser usados para fornecer a funcionalidade que a classe (agora obsoleta) CComModule fornecida no Visual C++ 6.0.

### <a name="example"></a>Exemplo

```cpp
LONG lLocks = _pAtlModule->GetLockCount();
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

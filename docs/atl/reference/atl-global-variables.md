---
title: Variáveis globais da ATL
ms.date: 12/06/2017
f1_keywords:
- ATLBASE/_pAtlModule
helpviewer_keywords:
- global variables, ATL
- _pAtlModule
ms.assetid: e881a319-99ca-4f5d-8a0b-34b3dcd0f37f
ms.openlocfilehash: 4f98b31d2454b7c6e903e5b5b87bceb4ddcb6961
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62248154"
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

---
title: "Variáveis globais ATL | Microsoft Docs"
ms.custom: 
ms.date: 12/06/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: ATLBASE/_pAtlModule
dev_langs: C++
helpviewer_keywords:
- global variables, ATL
- _pAtlModule
ms.assetid: e881a319-99ca-4f5d-8a0b-34b3dcd0f37f
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bcf9a88e57d351a3fb6647f6deea3eccbad33bf8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atl-global-variables"></a>Variáveis globais do ATL

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
 **Cabeçalho:** atlbase  


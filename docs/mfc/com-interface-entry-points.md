---
title: Pontos de entrada de Interface COM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- entry points, COM interfaces
- state management, OLE/COM interfaces
- MFC COM, COM interface entry points
- OLE, interface entry points
- MFC, managing state data
- COM interfaces, entry points
ms.assetid: 9e7421dc-0731-4748-9e1b-90acbaf26d77
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 699c6e3dbe5ecd95c947c13374a2e7964307ff79
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040005"
---
# <a name="com-interface-entry-points"></a>Pontos de entrada da interface COM
Para funções de membro de uma interface COM, use o [METHOD_PROLOGUE](com-interface-entry-points.md#method_prologue) macro para manter o estado global apropriado ao chamar métodos de uma interface exportado.  
  
 Normalmente, funções de membro das interfaces implementadas por `CCmdTarget`-objetos derivados já usam essa macro para fornecer a inicialização automática do `pThis` ponteiro. Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#5](../mfc/codesnippet/cpp/com-interface-entry-points_1.cpp)]  
  
 Para obter mais informações, consulte [38 de observação técnica](../mfc/tn038-mfc-ole-iunknown-implementation.md) no MFC/OLE `IUnknown` implementação.  
  
 O `METHOD_PROLOGUE` macro é definida como:  
  
```cpp
#define METHOD_PROLOGUE(theClass, localClass) \
    theClass* pThis = \
    ((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \
    AFX_MANAGE_STATE(pThis->m_pModuleState) \

```
  
 A parte da macro referentes ao gerenciamento de estado global é:  
  
 `AFX_MANAGE_STATE( pThis->m_pModuleState )`  
  
 Nesta expressão, *m_pModuleState* é considerado como uma variável de membro do objeto contentor. Ele é implementado pelos `CCmdTarget` classe base e é inicializada com o valor apropriado pelo `COleObjectFactory`, quando o objeto é instanciado.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)


---
title: Pontos de entrada da interface COM
ms.date: 03/27/2019
helpviewer_keywords:
- entry points, COM interfaces
- state management, OLE/COM interfaces
- MFC COM, COM interface entry points
- OLE, interface entry points
- MFC, managing state data
- COM interfaces, entry points
ms.assetid: 9e7421dc-0731-4748-9e1b-90acbaf26d77
ms.openlocfilehash: 132dd7394119081dcaeb098c2088782ff5d40ae4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619335"
---
# <a name="com-interface-entry-points"></a>Pontos de entrada da interface COM

Para funções de membro de uma interface COM, use a `METHOD_PROLOGUE` macro para manter o estado global adequado ao chamar métodos de uma interface exportada.

Normalmente, as funções de membro de interfaces implementadas por `CCmdTarget` objetos derivados já usam essa macro para fornecer inicialização automática do `pThis` ponteiro. Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#5](codesnippet/cpp/com-interface-entry-points_1.cpp)]

Para obter informações adicionais, consulte a [Observação técnica 38](tn038-mfc-ole-iunknown-implementation.md) sobre implementação de MFC/OLE `IUnknown` .

A `METHOD_PROLOGUE` macro é definida como:

```cpp
#define METHOD_PROLOGUE(theClass, localClass) \
    theClass* pThis = \
    ((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \
    AFX_MANAGE_STATE(pThis->m_pModuleState) \
```

A parte da macro preocupada com o gerenciamento do estado global é:

`AFX_MANAGE_STATE( pThis->m_pModuleState )`

Nessa expressão, *m_pModuleState* é considerada uma variável de membro do objeto contentor. Ele é implementado pela `CCmdTarget` classe base e é inicializado com o valor apropriado pelo `COleObjectFactory` , quando o objeto é instanciado.

## <a name="see-also"></a>Consulte também

[Gerenciando os dados de estado dos módulos MFC](managing-the-state-data-of-mfc-modules.md)

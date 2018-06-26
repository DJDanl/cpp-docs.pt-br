---
title: Pontos de entrada COM Interface | Microsoft Docs
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
ms.openlocfilehash: d7f52aee6a276410ba6a90fd662a2fad8d258e92
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929881"
---
# <a name="com-interface-entry-points"></a>Pontos de entrada da interface COM
Para funções de membro de uma interface COM, use o [METHOD_PROLOGUE](com-interface-entry-points.md#method_prologue) macro para manter o estado global apropriado ao chamar métodos da interface exportada.  
  
 Em geral, funções de membro de interfaces implementadas por `CCmdTarget`-objetos derivados já usam essa macro para fornecer a inicialização automática do `pThis` ponteiro. Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#5](../mfc/codesnippet/cpp/com-interface-entry-points_1.cpp)]  
  
 Para obter mais informações, consulte [38 de observação técnica](../mfc/tn038-mfc-ole-iunknown-implementation.md) em MFC/OLE `IUnknown` implementação.  
  
 O `METHOD_PROLOGUE` macro é definida como:  
  
 `#define METHOD_PROLOGUE(theClass, localClass) \`  
  
 `theClass* pThis = \`  
  
 `((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \`  
  
 `AFX_MANAGE_STATE(pThis->m_pModuleState) \`  
  
 A parte da macro referentes ao gerenciamento de estado global é:  
  
 `AFX_MANAGE_STATE( pThis->m_pModuleState )`  
  
 Nesta expressão, *m_pModuleState* é considerado como uma variável de membro do objeto contentor. É implementado pelo `CCmdTarget` classe base e é inicializado para o valor apropriado pelo `COleObjectFactory`, quando o objeto é instanciado.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)


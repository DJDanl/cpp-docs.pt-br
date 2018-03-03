---
title: Pontos de entrada COM Interface | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 010df3546a6ac2b6276281c39efdd76abd5ec222
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="com-interface-entry-points"></a>Pontos de entrada da interface COM
Para funções de membro de uma interface COM, use o [METHOD_PROLOGUE](com-interface-entry-points.md#method_prologue) macro para manter o estado global apropriado ao chamar métodos da interface exportada.  
  
 Em geral, funções de membro de interfaces implementadas por `CCmdTarget`-objetos derivados já usam essa macro para fornecer a inicialização automática do `pThis` ponteiro. Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#5](../mfc/codesnippet/cpp/com-interface-entry-points_1.cpp)]  
  
 Para obter mais informações, consulte [38 de observação técnica](../mfc/tn038-mfc-ole-iunknown-implementation.md) em MFC/OLE **IUnknown** implementação.  
  
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


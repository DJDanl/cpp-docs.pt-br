---
title: "Pontos de entrada da interface COM | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interfaces COM, pontos de entrada"
  - "pontos de entrada, Interfaces COM"
  - "MFC COM, pontos de entrada da interface COM"
  - "MFC, gerenciando dados de estado"
  - "OLE, pontos de entrada da interface"
  - "gerenciamento de estado, Interfaces OLE/COM"
ms.assetid: 9e7421dc-0731-4748-9e1b-90acbaf26d77
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pontos de entrada da interface COM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para funções de membro de uma interface COM, use a macro de [METHOD\_PROLOGUE](../Topic/METHOD_PROLOGUE.md) para manter o estado global apropriado ao chamar métodos de uma interface exportada.  
  
 Normalmente, as funções de membro das interfaces implementadas por `CCmdTarget`\- os objetos derivados já usam esta macro para fornecer a inicialização automática do ponteiro de `pThis` .  Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#5](../mfc/codesnippet/CPP/com-interface-entry-points_1.cpp)]  
  
 Para obter mais informações, consulte [Observação 38 técnica](../mfc/tn038-mfc-ole-iunknown-implementation.md) na implementação de MFC\/OLE **IUnknown** .  
  
 A macro de `METHOD_PROLOGUE` é definido como:  
  
 `#define METHOD_PROLOGUE(theClass, localClass) \`  
  
 `theClass* pThis = \`  
  
 `((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \`  
  
 `AFX_MANAGE_STATE(pThis->m_pModuleState) \`  
  
 A parte de macro estado relacionado com gerenciar o estado global é:  
  
 `AFX_MANAGE_STATE( pThis->m_pModuleState )`  
  
 Nessa expressão, *o m\_pModuleState* é considerado como uma variável de membro do objeto contentor.  É implementado pela classe base de `CCmdTarget` e inicializado com o valor apropriado por `COleObjectFactory`, quando é criada uma instância do objeto.  
  
## Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)
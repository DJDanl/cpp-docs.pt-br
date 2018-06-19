---
title: Classe COleControlModule | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- OleControlModule
dev_langs:
- C++
helpviewer_keywords:
- OLE control modules [MFC]
- MFC ActiveX controls [MFC], OLE control modules
- COleControlModule class [MFC]
- control modules [MFC]
ms.assetid: 0721724d-d4af-4eda-ad34-5a2b27810dd4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 597639145385f4aabcba0e83fef855f7a0779f9b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33369733"
---
# <a name="colecontrolmodule-class"></a>Classe COleControlModule
A classe base da qual você derivar um objeto de módulo de controle OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleControlModule : public CWinApp  
```  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções de membro para inicializar o módulo de controle. Cada módulo de controle OLE que usa as classes Microsoft Foundation só pode conter um objeto derivado de `COleControlModule`. Esse objeto é construído quando outros objetos globais C++ são construídos. Declarar derivada `COleControlModule` objeto no nível global.  
  
 Para obter mais informações sobre como usar o `COleControlModule` de classe, consulte o [CWinApp](../../mfc/reference/cwinapp-class.md) classe e o artigo [controles ActiveX](../../mfc/mfc-activex-controls.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 [CWinApp](../../mfc/reference/cwinapp-class.md)  
  
 `COleControlModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC TESTHELP](../../visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)




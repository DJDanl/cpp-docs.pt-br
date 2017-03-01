---
title: Classe COleControlModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleControlModule
dev_langs:
- C++
helpviewer_keywords:
- OLE control modules
- MFC ActiveX controls, OLE control modules
- COleControlModule class
- control modules
ms.assetid: 0721724d-d4af-4eda-ad34-5a2b27810dd4
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5c6fbfc8699d7d66c40b0458972d8b6ef0dcc705
ms.openlocfilehash: 2e77c386875d25f47f0cc07eb3b7d315f1678c56
ms.lasthandoff: 02/25/2017

---
# <a name="colecontrolmodule-class"></a>Classe COleControlModule
A classe base da qual você derivar um objeto de módulo de controle OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleControlModule : public CWinApp  
```  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece funções de membro para inicializar o módulo de controle. Cada módulo de controle OLE que usa as Microsoft Foundation classes só pode conter um objeto derivado de `COleControlModule`. Esse objeto é criado quando outros objetos globais do C++ são construídos. Declarar derivada `COleControlModule` objeto no nível global.  
  
 Para obter mais informações sobre como usar o `COleControlModule` classe, consulte o [CWinApp](../../mfc/reference/cwinapp-class.md) classe e o artigo [controles ActiveX](../../mfc/mfc-activex-controls.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 [CWinApp](../../mfc/reference/cwinapp-class.md)  
  
 `COleControlModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC TESTHELP](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)





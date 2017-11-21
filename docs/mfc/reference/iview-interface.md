---
title: Interface IView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IView
- No header/IView
- No header/IView::OnActivateView
- No header/IView::OnInitialUpdate
- No header/IView::OnUpdate
dev_langs: C++
helpviewer_keywords:
- views [MFC]
- IView class [MFC]
- views [MFC], classes
ms.assetid: 9321f299-486e-4551-bee9-d2c4a7b91548
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 144cea65ddfa5153fb117c9570b101a1ce99eb32
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="iview-interface"></a>Interface IView
Implementa vários métodos que [CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição para um controle gerenciado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
interface class IView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IView::OnActivateView](#onactivateview)|Chamado pelo MFC quando uma exibição é ativada ou desativada.|  
|[IView::OnInitialUpdate](#oninitialupdate)|Chamado pelo framework depois que a exibição é anexado ao documento pela primeira vez, mas antes do modo de exibição é exibido inicialmente.|  
|[IView::OnUpdate](#onupdate)|Chamado pelo MFC depois que o documento do modo de exibição foi modificado; Essa função permite que o modo de exibição atualizar sua exibição para refletir as modificações.|  
  
## <a name="remarks"></a>Comentários  
 `IView`implementa vários métodos que `CWinFormsView` usa para encaminhar as notificações de exibição comuns para um controle gerenciado hospedado. Esses são [OnInitialUpdate](#oninitialupdate), [OnUpdate](#onupdate) e [OnActivateView](#onactivateview).  
  
 `IView`é semelhante a [CView](../../mfc/reference/cview-class.md), mas é usado somente com os modos de exibição gerenciados e controles.  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  

## <a name="requirements"></a>Requisitos  
 Cabeçalho: afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  

## <a name="onactivateview"></a>IView::OnActivateView  
Chamado pelo MFC quando uma exibição é ativada ou desativada.
```
void OnActivateView(bool activate);
```
## <a name="parameters"></a>Parâmetros
`activate`  
Indica se o modo de exibição está sendo ativada ou desativada.  

## <a name="oninitialupdate"></a>IView::OnInitialUpdate
Chamado pelo framework depois que a exibição é anexado ao documento pela primeira vez, mas antes do modo de exibição é exibido inicialmente.
```
void OnInitialUpdate();
```

## <a name="onupdate"></a>IView::OnUpdate 
Chamado pelo MFC depois que o documento do modo de exibição foi modificado.  
```
void OnUpdate();
```
## <a name="remarks"></a>Comentários  
Essa função permite que o modo de exibição atualizar sua exibição para refletir as modificações.

## <a name="see-also"></a>Consulte também  
 [Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)

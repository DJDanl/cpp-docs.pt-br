---
title: Classe CMFCTasksPaneTask | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCTasksPaneTask
- AFXTASKSPANE/CMFCTasksPaneTask
- AFXTASKSPANE/CMFCTasksPaneTask::CMFCTasksPaneTask
- AFXTASKSPANE/CMFCTasksPaneTask::SetACCData
- AFXTASKSPANE/CMFCTasksPaneTask::m_bAutoDestroyWindow
- AFXTASKSPANE/CMFCTasksPaneTask::m_bIsBold
- AFXTASKSPANE/CMFCTasksPaneTask::m_dwUserData
- AFXTASKSPANE/CMFCTasksPaneTask::m_hwndTask
- AFXTASKSPANE/CMFCTasksPaneTask::m_nIcon
- AFXTASKSPANE/CMFCTasksPaneTask::m_nWindowHeight
- AFXTASKSPANE/CMFCTasksPaneTask::m_pGroup
- AFXTASKSPANE/CMFCTasksPaneTask::m_rect
- AFXTASKSPANE/CMFCTasksPaneTask::m_strName
- AFXTASKSPANE/CMFCTasksPaneTask::m_uiCommandID
dev_langs:
- C++
helpviewer_keywords:
- CMFCTasksPaneTask [MFC], CMFCTasksPaneTask
- CMFCTasksPaneTask [MFC], SetACCData
- CMFCTasksPaneTask [MFC], m_bAutoDestroyWindow
- CMFCTasksPaneTask [MFC], m_bIsBold
- CMFCTasksPaneTask [MFC], m_dwUserData
- CMFCTasksPaneTask [MFC], m_hwndTask
- CMFCTasksPaneTask [MFC], m_nIcon
- CMFCTasksPaneTask [MFC], m_nWindowHeight
- CMFCTasksPaneTask [MFC], m_pGroup
- CMFCTasksPaneTask [MFC], m_rect
- CMFCTasksPaneTask [MFC], m_strName
- CMFCTasksPaneTask [MFC], m_uiCommandID
ms.assetid: c5a7513b-cd8f-4e2e-b16f-650e1fe30954
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ee7c04ee4cd581395ff03763c2ebe50b421986d2
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45711133"
---
# <a name="cmfctaskspanetask-class"></a>Classe CMFCTasksPaneTask
O `CMFCTasksPaneTask` é uma classe auxiliar que representa as tarefas para o controle do painel de tarefas ( [CMFCTasksPane](../../mfc/reference/cmfctaskspane-class.md)). O objeto de tarefa representa um item no grupo de tarefas ( [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md)). Cada tarefa pode ter um comando que a estrutura executa quando um usuário clica na tarefa e um ícone que aparece à esquerda do nome da tarefa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCTasksPaneTask : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTask::CMFCTasksPaneTask](#cmfctaskspanetask)|Cria e inicializa um objeto `CMFCTasksPaneTask`.|  
|`CMFCTasksPaneTask::~CMFCTasksPaneTask`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTask::SetACCData](#setaccdata)|Determina os dados de acessibilidade para a tarefa atual.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTask::m_bAutoDestroyWindow](#m_bautodestroywindow)|Determina se a janela de tarefas será destruída automaticamente.|  
|[CMFCTasksPaneTask::m_bIsBold](#m_bisbold)|Determina se a estrutura desenha um rótulo de tarefa em negrito.|  
|[CMFCTasksPaneTask::m_dwUserData](#m_dwuserdata)|Contém dados definidos pelo usuário que o framework associa a tarefa. Definido como zero se a tarefa não tem nenhum dado associado.|  
|[CMFCTasksPaneTask::m_hwndTask](#m_hwndtask)|Um identificador para a janela de tarefas.|  
|[CMFCTasksPaneTask::m_nIcon](#m_nicon)|O índice na lista de imagens da imagem que a estrutura é exibido ao lado da tarefa.|  
|[CMFCTasksPaneTask::m_nWindowHeight](#m_nwindowheight)|A altura da janela de tarefas. Se a tarefa não tem nenhuma janela de tarefas, esse valor é zero.|  
|[CMFCTasksPaneTask::m_pGroup](#m_pgroup)|Um ponteiro para o `CMFCTasksPaneTaskGroup` que essa tarefa pertence.|  
|[CMFCTasksPaneTask::m_rect](#m_rect)|Especifica o retângulo delimitador da tarefa.|  
|[CMFCTasksPaneTask::m_strName](#m_strname)|O nome da tarefa.|  
|[CMFCTasksPaneTask::m_uiCommandID](#m_uicommandid)|Especifica a ID de comando do comando que a estrutura executa quando o usuário clica na tarefa. Se esse valor não é uma ID de comando válido, a tarefa será tratada como um simple rótulo.|  
  
## <a name="remarks"></a>Comentários  
 A ilustração a seguir mostra um grupo de tarefas que contém três tarefas:  
  
 ![Grupo de tarefas, expandido](../../mfc/reference/media/nexttaskgrpexpand.png "nexttaskgrpexpand")  
  
> [!NOTE]
>  Se uma tarefa não tiver uma ID de comando válido, ele será tratado como um simple rótulo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxTasksPane.h  
  
##  <a name="cmfctaskspanetask"></a>  CMFCTasksPaneTask::CMFCTasksPaneTask  
 Cria e inicializa um objeto `CMFCTasksPaneTask`.  
  
```  
CMFCTasksPaneTask(
    CMFCTasksPaneTaskGroup* pGroup,  
    LPCTSTR lpszName,  
    int nIcon,  
    UINT uiCommandID,  
    DWORD dwUserData = 0,  
    HWND hwndTask = NULL,  
    BOOL bAutoDestroyWindow = FALSE,  
    int nWindowHeight = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pGroup*  
 Especifica o [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) ao qual a tarefa pertence.  
  
 *lpszName*  
 Especifica o nome da tarefa.  
  
 *nIcon*  
 Especifica o índice da imagem da tarefa na lista de imagens.  
  
 *uiCommandID*  
 Especifica a ID de comando do comando que é executado quando a tarefa é clicada.  
  
 *dwUserData*  
 Dados definidos pelo usuário.  
  
 *hwndTask*  
 Especifica o identificador para a janela de tarefas.  
  
 *bAutoDestroyWindow*  
 Se for TRUE, a janela de tarefas será destruída automaticamente.  
  
 *nWindowHeight*  
 Especifica a altura da janela de tarefas.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_bautodestroywindow"></a>  CMFCTasksPaneTask::m_bAutoDestroyWindow  
 Determina se a janela de tarefas será destruída automaticamente.  
  
```  
BOOL m_bAutoDestroyWindow;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina como TRUE para especificar que a janela de tarefas ( [CMFCTasksPaneTask::m_hwndTask](#m_hwndtask)) deve ser destruída automaticamente; caso contrário, FALSE.  
  
##  <a name="m_bisbold"></a>  CMFCTasksPaneTask::m_bIsBold  
 Determina se um rótulo de tarefa é desenhado com texto em negrito.  
  
```  
BOOL m_bIsBold;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina este membro True para exibir texto em negrito para o rótulo de tarefa.  
  
##  <a name="m_dwuserdata"></a>  CMFCTasksPaneTask::m_dwUserData  
 Contém dados definidos pelo usuário que está associados à tarefa. Definido como zero, se nenhum dado estiver associado à tarefa.  
  
```  
DWORD m_dwUserData;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_hwndtask"></a>  CMFCTasksPaneTask::m_hwndTask  
 Um identificador para a janela de tarefas.  
  
```  
HWND m_hwndTask;  
```  
  
### <a name="remarks"></a>Comentários  
 Para adicionar uma janela de tarefas, chame [CMFCTasksPane::AddWindow](../../mfc/reference/cmfctaskspane-class.md#addwindow).  
  
##  <a name="m_nicon"></a>  CMFCTasksPaneTask::m_nIcon  
 A posição de índice em uma lista de imagens que identifica a imagem exibida ao lado de tarefa especificada.  
  
```  
int m_nIcon;  
```  
  
### <a name="remarks"></a>Comentários  
 A lista de imagens é definida por [CMFCTasksPane::SetIconsList](../../mfc/reference/cmfctaskspane-class.md#seticonslist).  
  
 Definir `m_nIcon` como -1 se você quiser exibir a tarefa sem uma imagem.  
  
##  <a name="m_nwindowheight"></a>  CMFCTasksPaneTask::m_nWindowHeight  
 A altura da janela de tarefas. Se a tarefa não tem nenhuma janela de tarefas, esse valor é zero.  
  
```  
int m_nWindowHeight;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_pgroup"></a>  CMFCTasksPaneTask::m_pGroup  
 Ponteiro para o [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) ao qual pertence essa tarefa.  
  
```  
CMFCTasksPaneTaskGroup* m_pGroup;  
```  
  
### <a name="remarks"></a>Comentários  
 Cada tarefa deve ter um grupo pai. Adicionar grupos a um painel de tarefas chamando [CMFCTasksPane::AddGroup](../../mfc/reference/cmfctaskspane-class.md#addgroup).  
  
##  <a name="m_rect"></a>  CMFCTasksPaneTask::m_rect  
 Especifica o retângulo delimitador da tarefa.  
  
```  
CRect m_rect;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor é calculado pelo framework quando a tarefa é desenhada.  
  
##  <a name="m_strname"></a>  CMFCTasksPaneTask::m_strName  
 O nome da tarefa.  
  
```  
CString m_strName;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_uicommandid"></a>  CMFCTasksPaneTask::m_uiCommandID  
 Especifica a ID de comando do comando que é executado quando o usuário clica na tarefa. Se esse valor não é uma ID de comando válido, a tarefa será tratada como um simple rótulo.  
  
```  
UINT m_uiCommandID;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setaccdata"></a>  CMFCTasksPaneTask::SetACCData  
 Determina os dados de acessibilidade para a tarefa atual.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
*pParent*<br/>
[in] Representa a janela pai da tarefa atual.  
  
*data*<br/>
[out] Um objeto do tipo `CAccessibilityData` que é preenchida com os dados de acessibilidade da tarefa atual.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o *dados* parâmetro estava com êxito preenchida com os dados de acessibilidade da tarefa atual; caso contrário, FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)

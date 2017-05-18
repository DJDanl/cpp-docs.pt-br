---
title: Classe CMFCTasksPaneTask | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- CMFCTasksPaneTask class
ms.assetid: c5a7513b-cd8f-4e2e-b16f-650e1fe30954
caps.latest.revision: 27
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 20713b45c4b6aadc5cdfeaadb6ed269aaf7b337f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctaskspanetask-class"></a>Classe CMFCTasksPaneTask
O `CMFCTasksPaneTask` classe é uma classe auxiliar que representa as tarefas para o controle do painel de tarefas ( [CMFCTasksPane](../../mfc/reference/cmfctaskspane-class.md)). O objeto de tarefa representa um item no grupo de tarefas ( [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md)). Cada tarefa pode ter um comando que a estrutura é executado quando um usuário clica na tarefa e um ícone que aparece à esquerda do nome da tarefa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCTasksPaneTask : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTask::CMFCTasksPaneTask](#cmfctaskspanetask)|Cria e inicializa um `CMFCTasksPaneTask` objeto.|  
|`CMFCTasksPaneTask::~CMFCTasksPaneTask`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTask::SetACCData](#setaccdata)|Determina os dados de acessibilidade para a tarefa atual.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTask::m_bAutoDestroyWindow](#m_bautodestroywindow)|Determina se a janela de tarefas é destruída automaticamente.|  
|[CMFCTasksPaneTask::m_bIsBold](#m_bisbold)|Determina se o framework desenha um rótulo de tarefa em negrito.|  
|[CMFCTasksPaneTask::m_dwUserData](#m_dwuserdata)|Contém dados definidos pelo usuário que a estrutura associa a tarefa. Defina como zero se a tarefa não tiver nenhum dado associado.|  
|[CMFCTasksPaneTask::m_hwndTask](#m_hwndtask)|Um identificador para a janela de tarefas.|  
|[CMFCTasksPaneTask::m_nIcon](#m_nicon)|O índice na lista de imagens da imagem que a estrutura é exibido ao lado da tarefa.|  
|[CMFCTasksPaneTask::m_nWindowHeight](#m_nwindowheight)|A altura da janela de tarefas. Se a tarefa não tem nenhuma janela de tarefas, esse valor é zero.|  
|[CMFCTasksPaneTask::m_pGroup](#m_pgroup)|Um ponteiro para o `CMFCTasksPaneTaskGroup` que essa tarefa pertence.|  
|[CMFCTasksPaneTask::m_rect](#m_rect)|Especifica o retângulo delimitador da tarefa.|  
|[CMFCTasksPaneTask::m_strName](#m_strname)|O nome da tarefa.|  
|[CMFCTasksPaneTask::m_uiCommandID](#m_uicommandid)|Especifica a ID de comando do comando que a estrutura é executado quando o usuário clica na tarefa. Se esse valor não é uma ID de comando válidos, a tarefa é tratada como um simple rótulo.|  
  
## <a name="remarks"></a>Comentários  
 A ilustração a seguir mostra um grupo de tarefas que contém três tarefas:  
  
 ![Grupo de tarefas expandido](../../mfc/reference/media/nexttaskgrpexpand.png "nexttaskgrpexpand")  
  
> [!NOTE]
>  Se uma tarefa não tiver uma ID de comando válido, ele será tratado como um simple rótulo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxTasksPane.h  
  
##  <a name="cmfctaskspanetask"></a>CMFCTasksPaneTask::CMFCTasksPaneTask  
 Cria e inicializa um `CMFCTasksPaneTask` objeto.  
  
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
 `pGroup`  
 Especifica o [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) ao qual a tarefa pertence.  
  
 `lpszName`  
 Especifica o nome da tarefa.  
  
 `nIcon`  
 Especifica o índice da imagem da tarefa na lista de imagens.  
  
 `uiCommandID`  
 Especifica a ID de comando do comando que é executado quando a tarefa é clicada.  
  
 `dwUserData`  
 Dados definidos pelo usuário.  
  
 `hwndTask`  
 Especifica o identificador para a janela de tarefas.  
  
 `bAutoDestroyWindow`  
 Se `TRUE`, a janela tarefas será destruída automaticamente.  
  
 `nWindowHeight`  
 Especifica a altura da janela de tarefas.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_bautodestroywindow"></a>CMFCTasksPaneTask::m_bAutoDestroyWindow  
 Determina se a janela de tarefas é destruída automaticamente.  
  
```  
BOOL m_bAutoDestroyWindow;  
```  
  
### <a name="remarks"></a>Comentários  
 Definido como `TRUE` para especificar que a janela de tarefas ( [CMFCTasksPaneTask::m_hwndTask](#m_hwndtask)) deve ser destruído automaticamente; caso contrário, `FALSE`.  
  
##  <a name="m_bisbold"></a>CMFCTasksPaneTask::m_bIsBold  
 Determina se um rótulo de tarefa é desenhado em negrito.  
  
```  
BOOL m_bIsBold;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir esse membro como `TRUE` para exibir o texto em negrito para o rótulo da tarefa.  
  
##  <a name="m_dwuserdata"></a>CMFCTasksPaneTask::m_dwUserData  
 Contém dados definidos pelo usuário que está associados à tarefa. Definido como zero se nenhum dado associado à tarefa.  
  
```  
DWORD m_dwUserData;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_hwndtask"></a>CMFCTasksPaneTask::m_hwndTask  
 Um identificador para a janela de tarefas.  
  
```  
HWND m_hwndTask;  
```  
  
### <a name="remarks"></a>Comentários  
 Para adicionar uma janela de tarefa, chame [CMFCTasksPane::AddWindow](../../mfc/reference/cmfctaskspane-class.md#addwindow).  
  
##  <a name="m_nicon"></a>CMFCTasksPaneTask::m_nIcon  
 A posição de índice em uma lista de imagens que identifica a imagem que é exibida próximo à tarefa especificada.  
  
```  
int m_nIcon;  
```  
  
### <a name="remarks"></a>Comentários  
 A lista de imagens é definida por [CMFCTasksPane::SetIconsList](../../mfc/reference/cmfctaskspane-class.md#seticonslist).  
  
 Definir `m_nIcon` como -1 se você deseja exibir a tarefa sem uma imagem.  
  
##  <a name="m_nwindowheight"></a>CMFCTasksPaneTask::m_nWindowHeight  
 A altura da janela de tarefas. Se a tarefa não tem nenhuma janela de tarefas, esse valor é zero.  
  
```  
int m_nWindowHeight;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_pgroup"></a>CMFCTasksPaneTask::m_pGroup  
 Ponteiro para o [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) ao qual pertence essa tarefa.  
  
```  
CMFCTasksPaneTaskGroup* m_pGroup;  
```  
  
### <a name="remarks"></a>Comentários  
 Cada tarefa deve ter um grupo pai. Adicionar grupos a um painel de tarefas chamando [CMFCTasksPane::AddGroup](../../mfc/reference/cmfctaskspane-class.md#addgroup).  
  
##  <a name="m_rect"></a>CMFCTasksPaneTask::m_rect  
 Especifica o retângulo delimitador da tarefa.  
  
```  
CRect m_rect;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor é calculado pela estrutura quando a tarefa é desenhada.  
  
##  <a name="m_strname"></a>CMFCTasksPaneTask::m_strName  
 O nome da tarefa.  
  
```  
CString m_strName;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_uicommandid"></a>CMFCTasksPaneTask::m_uiCommandID  
 Especifica a ID de comando do comando que é executado quando o usuário clica na tarefa. Se esse valor não é uma ID de comando válidos, a tarefa é tratada como um simple rótulo.  
  
```  
UINT m_uiCommandID;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setaccdata"></a>CMFCTasksPaneTask::SetACCData  
 Determina os dados de acessibilidade para a tarefa atual.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParent`  
 Representa a janela pai da tarefa atual.  
  
 [out] `data`  
 Um objeto do tipo `CAccessibilityData` que é preenchida com os dados de acessibilidade da tarefa atual.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o `data` parâmetro estava com êxito preenchido com os dados de acessibilidade da tarefa atual; caso contrário, `FALSE`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)


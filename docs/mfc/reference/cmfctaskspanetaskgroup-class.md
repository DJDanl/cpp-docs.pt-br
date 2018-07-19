---
title: Classe CMFCTasksPaneTaskGroup | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCTasksPaneTaskGroup
- AFXTASKSPANE/CMFCTasksPaneTaskGroup
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::SetACCData
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_bIsBottom
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_bIsCollapsed
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_bIsSpecial
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_lstTasks
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_rect
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_rectGroup
- AFXTASKSPANE/CMFCTasksPaneTaskGroup::m_strName
dev_langs:
- C++
helpviewer_keywords:
- CMFCTasksPaneTaskGroup [MFC], CMFCTasksPaneTaskGroup
- CMFCTasksPaneTaskGroup [MFC], SetACCData
- CMFCTasksPaneTaskGroup [MFC], m_bIsBottom
- CMFCTasksPaneTaskGroup [MFC], m_bIsCollapsed
- CMFCTasksPaneTaskGroup [MFC], m_bIsSpecial
- CMFCTasksPaneTaskGroup [MFC], m_lstTasks
- CMFCTasksPaneTaskGroup [MFC], m_rect
- CMFCTasksPaneTaskGroup [MFC], m_rectGroup
- CMFCTasksPaneTaskGroup [MFC], m_strName
ms.assetid: 2111640b-a46e-4b27-b033-29e88632b86a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e2f53aa98d7743ccee804ed7a89df160368c8a23
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37849153"
---
# <a name="cmfctaskspanetaskgroup-class"></a>Classe CMFCTasksPaneTaskGroup
O `CMFCTasksPaneTaskGroup` classe é uma classe auxiliar usada pelo [CMFCTasksPane](../../mfc/reference/cmfctaskspane-class.md) controle. Objetos do tipo `CMFCTasksPaneTaskGroup` representam uma *grupo de tarefas*. O grupo de tarefas é uma lista de itens exibida pela estrutura em uma caixa separada que tem um botão de recolhimento. A caixa pode ter uma legenda opcional (nome de grupo). Se um grupo estiver recolhido, a lista de tarefas não está visível.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCTasksPaneTaskGroup : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup](#cmfctaskspanetaskgroup)|Constrói um objeto `CMFCTasksPaneTaskGroup`.|  
|`CMFCTasksPaneTaskGroup::~CMFCTasksPaneTaskGroup`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTaskGroup::SetACCData](#setaccdata)|Determina os dados de acessibilidade para o grupo de tarefa atual.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTasksPaneTaskGroup::m_bIsBottom](#m_bisbottom)|Determina se o grupo de tarefas é alinhado à parte inferior do controle do painel de tarefas.|  
|[CMFCTasksPaneTaskGroup::m_bIsCollapsed](#m_biscollapsed)|Determina se o grupo de tarefas é recolhido.|  
|[CMFCTasksPaneTaskGroup::m_bIsSpecial](#m_bisspecial)|Determina se o grupo de tarefas é *especial.* O framework exibe legendas especiais em uma cor diferente.|  
|[CMFCTasksPaneTaskGroup::m_lstTasks](#m_lsttasks)|Contém a lista interna de tarefas.|  
|[CMFCTasksPaneTaskGroup::m_rect](#m_rect)|Especifica o retângulo delimitador da legenda do grupo.|  
|[CMFCTasksPaneTaskGroup::m_rectGroup](#m_rectgroup)|Especifica o retângulo delimitador do grupo.|  
|[CMFCTasksPaneTaskGroup::m_strName](#m_strname)|Especifica o nome do grupo.|  
  
## <a name="remarks"></a>Comentários  
 A ilustração a seguir mostra um grupo de tarefas expandido:  
  
 ![Grupo de tarefas, expandido](../../mfc/reference/media/nexttaskgrpexpand.png "nexttaskgrpexpand")  
  
 A ilustração a seguir mostra um grupo de tarefas recolhido:  
  
 ![Grupo de tarefas recolhido](../../mfc/reference/media/nexttaskgrpcollapse.png "nexttaskgrpcollapse")  
  
 A ilustração a seguir mostra um grupo de tarefas sem uma legenda:  
  
 ![Grupo de tarefas sem uma legenda](../../mfc/reference/media/nexttaskgrpnocapt.png "nexttaskgrpnocapt")  
  
 A ilustração a seguir mostra dois grupos de tarefas. O primeiro grupo de tarefas está marcado como especial, definindo o `m_bIsSpecial` sinalizador como TRUE, enquanto o segundo grupo de tarefas não é especial. Observe como a legenda para o primeiro grupo de tarefas é mais escura do que o segundo grupo de tarefas:  
  
 ![Grupo de tarefas especiais](../../mfc/reference/media/nexttaskgrpspecial.png "nexttaskgrpspecial")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxTasksPane.h  
  
##  <a name="cmfctaskspanetaskgroup"></a>  CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup  
 Constrói um objeto `CMFCTasksPaneTaskGroup`.  
  
```  
CMFCTasksPaneTaskGroup(
    LPCTSTR lpszName,  
    BOOL bIsBottom,  
    BOOL bIsSpecial=FALSE,  
    BOOL bIsCollapsed=FALSE,  
    CMFCTasksPanePropertyPage* pPage=NULL,  
    HICON hIcon=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Especifica o nome do grupo da legenda do grupo.  
  
 *bIsBottom*  
 Especifica se o grupo é alinhado à parte inferior do controle do painel de tarefas.  
  
 *bIsSpecial*  
 Especifica se o grupo é designado como *especial* e, portanto, se a legenda do grupo é preenchida com uma cor diferente.  
  
 *bIsCollapsed*  
 Especifica se o grupo é recolhido.  
  
 *Página*  
 Especifica a página de propriedade pertencente a esse grupo de tarefas.  
  
 *hIcon*  
 Especifica o ícone exibido na legenda do grupo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_bisbottom"></a>  CMFCTasksPaneTaskGroup::m_bIsBottom  
 Determina se o grupo de tarefas é alinhado à parte inferior do controle do painel de tarefas.  
  
```  
BOOL m_bIsBottom;  
```  
  
### <a name="remarks"></a>Comentários  
 Apenas um grupo pode ser alinhado à parte inferior do controle do painel de tarefas. Esse grupo de trabalho deve ser adicionado pela última vez. Para obter mais informações, consulte [CMFCTasksPane::AddGroup](../../mfc/reference/cmfctaskspane-class.md#addgroup).  
  
##  <a name="m_biscollapsed"></a>  CMFCTasksPaneTaskGroup::m_bIsCollapsed  
 Determina se o grupo de tarefas é recolhido.  
  
```  
BOOL m_bIsCollapsed;  
```  
  
### <a name="remarks"></a>Comentários  
 Você pode habilitar ou desabilitar a capacidade de recolher grupos no painel de tarefas chamando [CMFCTasksPane::EnableGroupCollapse](../../mfc/reference/cmfctaskspane-class.md#enablegroupcollapse).  
  
##  <a name="m_bisspecial"></a>  CMFCTasksPaneTaskGroup::m_bIsSpecial  
 Determina se o grupo de tarefas está *especial* e se a legenda para um grupo de tarefas especiais deve ser identificada por uma cor diferente.  
  
```  
BOOL m_bIsSpecial;  
```  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo estiver usando o tema visual do Windows XP e `m_bIsSpecial` for FALSE, a estrutura chama `DrawThemeBackground` com o sinalizador EBP_NORMALGROUPBACKGROUND. Se `m_bIsSpecial` for TRUE, a estrutura chama `DrawThemeBackground` com o sinalizador EBP_SPECIALGROUPBACKGROUND.  
  
##  <a name="m_lsttasks"></a>  CMFCTasksPaneTaskGroup::m_lstTasks  
 Contém a lista interna de tarefas.  
  
```  
CObList m_lstTasks;  
```  
  
### <a name="remarks"></a>Comentários  
 Para preencher essa lista, chame [CMFCTasksPane::AddTask](../../mfc/reference/cmfctaskspane-class.md#addtask).  
  
##  <a name="m_rect"></a>  CMFCTasksPaneTaskGroup::m_rect  
 Especifica o retângulo delimitador da legenda do grupo.  
  
```  
CRect m_rect;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor é calculado automaticamente pela estrutura.  
  
##  <a name="m_rectgroup"></a>  CMFCTasksPaneTaskGroup::m_rectGroup  
 Especifica o retângulo delimitador do grupo.  
  
```  
CRect m_rectGroup;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor é calculado automaticamente pela estrutura.  
  
##  <a name="m_strname"></a>  CMFCTasksPaneTaskGroup::m_strName  
 Especifica o nome do grupo.  
  
```  
CString m_strName;  
```  
  
### <a name="remarks"></a>Comentários  
 Se esse valor estiver vazio, não é exibida na legenda do grupo e o grupo não pode ser recolhido.  
  
##  <a name="setaccdata"></a>  CMFCTasksPaneTaskGroup::SetACCData  
 Determina os dados de acessibilidade para o grupo de tarefa atual.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pParent*  
 Representa a janela pai do grupo de tarefas atual.  
  
 [out] *dados*  
 Um objeto do tipo `CAccessibilityData` que é preenchida com os dados de acessibilidade do grupo de tarefas atual.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o *dados* parâmetro estava com êxito preenchida com os dados de acessibilidade do grupo de tarefas atual; caso contrário, FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCTasksPane](../../mfc/reference/cmfctaskspane-class.md)   
 [Classe CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)

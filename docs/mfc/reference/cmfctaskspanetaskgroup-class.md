---
title: Classe CMFCTasksPaneTaskGroup
ms.date: 11/19/2018
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
ms.openlocfilehash: 4c24eba646bede462a5f3cfb85715278cfa7daee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366266"
---
# <a name="cmfctaskspanetaskgroup-class"></a>Classe CMFCTasksPaneTaskGroup

A `CMFCTasksPaneTaskGroup` classe é uma classe auxiliar usada pelo controle [CMFCTasksPane.](../../mfc/reference/cmfctaskspane-class.md) Objetos `CMFCTasksPaneTaskGroup` de tipo representam um *grupo de tarefas*. O grupo de tarefas é uma lista de itens que a estrutura exibe em uma caixa separada que tem um botão de colapso. A caixa pode ter uma legenda opcional (nome do grupo). Se um grupo for colapsado, a lista de tarefas não será visível.

## <a name="syntax"></a>Sintaxe

```
class CMFCTasksPaneTaskGroup : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup](#cmfctaskspanetaskgroup)|Constrói um objeto `CMFCTasksPaneTaskGroup`.|
|`CMFCTasksPaneTaskGroup::~CMFCTasksPaneTaskGroup`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCTasksPaneTaskGroup::SetACCData](#setaccdata)|Determina os dados de acessibilidade para o grupo de tarefas atual.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCTasksPaneTaskGroup::m_bIsBottom](#m_bisbottom)|Determina se o grupo de tarefas está alinhado à parte inferior do controle do painel de tarefas.|
|[CMFCTasksPaneTaskGroup::m_bIsCollapsed](#m_biscollapsed)|Determina se o grupo de trabalho está em colapso.|
|[CMFCTasksPaneTaskGroup::m_bIsSpecial](#m_bisspecial)|Determina se o grupo de trabalho é *especial.* A estrutura exibe legendas especiais em uma cor diferente.|
|[CMFCTasksPaneTaskGroup::m_lstTasks](#m_lsttasks)|Contém a lista interna de tarefas.|
|[CMFCTasksPaneTaskGroup::m_rect](#m_rect)|Especifica o retângulo delimitador da legenda de grupo.|
|[CMFCTasksPaneTaskGroup::m_rectGroup](#m_rectgroup)|Especifica o retângulo delimitador do grupo.|
|[CMFCTasksPaneTaskGroup::m_strName](#m_strname)|Especifica o nome do grupo.|

## <a name="remarks"></a>Comentários

A ilustração a seguir mostra um grupo de tarefas expandido:

![Grupo de trabalho, expandido](../../mfc/reference/media/nexttaskgrpexpand.png "Grupo de trabalho, expandido")

A ilustração a seguir mostra um grupo de trabalho em colapso:

![Grupo de trabalho colapsado](../../mfc/reference/media/nexttaskgrpcollapse.png "Grupo de trabalho colapsado")

A ilustração a seguir mostra um grupo de tarefas sem uma legenda:

![Grupo de tarefas sem legenda](../../mfc/reference/media/nexttaskgrpnocapt.png "Grupo de tarefas sem legenda")

A ilustração a seguir mostra dois grupos de tarefas. O primeiro grupo de tarefas `m_bIsSpecial` é marcado como especial definindo a bandeira como TRUE, enquanto o segundo grupo de tarefas não é especial. Observe como a legenda do primeiro grupo de tarefas é mais escura que o segundo grupo de tarefas:

![Grupo de trabalho especial](../../mfc/reference/media/nexttaskgrpspecial.png "Grupo de trabalho especial")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctaskspanetaskgroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxTasksPane.h

## <a name="cmfctaskspanetaskgroupcmfctaskspanetaskgroup"></a><a name="cmfctaskspanetaskgroup"></a>CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup

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

*lpszName*<br/>
Especifica o nome do grupo na legenda do grupo.

*bIsBottom*<br/>
Especifica se o grupo está alinhado à parte inferior do controle do painel de tarefas.

*bIsSpecial*<br/>
Especifica se o grupo é designado como *especial* e, portanto, se a legenda de grupo está preenchida com uma cor diferente.

*bIsCollapsed*<br/>
Especifica se o grupo está em colapso.

*pPage*<br/>
Especifica a página de propriedade a que esse grupo de tarefas pertence.

*Hicon*<br/>
Especifica o ícone exibido na legenda do grupo.

### <a name="remarks"></a>Comentários

## <a name="cmfctaskspanetaskgroupm_bisbottom"></a><a name="m_bisbottom"></a>CMFCTasksPaneTaskGroup::m_bIsBottom

Determina se o grupo de tarefas está alinhado à parte inferior do controle do painel de tarefas.

```
BOOL m_bIsBottom;
```

### <a name="remarks"></a>Comentários

Apenas um grupo pode ser alinhado à parte inferior do controle do painel de tarefas. Este grupo de tarefas deve ser adicionado por último. Para obter mais informações, consulte [CMFCTasksPane::AddGroup](../../mfc/reference/cmfctaskspane-class.md#addgroup).

## <a name="cmfctaskspanetaskgroupm_biscollapsed"></a><a name="m_biscollapsed"></a>CMFCTasksPaneTaskGroup::m_bIsCollapsed

Determina se o grupo de trabalho está em colapso.

```
BOOL m_bIsCollapsed;
```

### <a name="remarks"></a>Comentários

Você pode ativar ou desativar a capacidade de colapsar grupos no painel de tarefas chamando [CMFCTasksPane::EnableGroupCollapse](../../mfc/reference/cmfctaskspane-class.md#enablegroupcollapse).

## <a name="cmfctaskspanetaskgroupm_bisspecial"></a><a name="m_bisspecial"></a>CMFCTasksPaneTaskGroup::m_bIsSpecial

Determina se o grupo de tarefas é *especial* e se a legenda de um grupo de tarefas especial deve ser identificada por uma cor diferente.

```
BOOL m_bIsSpecial;
```

### <a name="remarks"></a>Comentários

Se o aplicativo estiver usando o `m_bIsSpecial` tema visual do `DrawThemeBackground` Windows XP e for FALSO, a estrutura será chamada com a bandeira EBP_NORMALGROUPBACKGROUND. Se `m_bIsSpecial` for VERDADE, `DrawThemeBackground` a estrutura chama com a bandeira EBP_SPECIALGROUPBACKGROUND.

## <a name="cmfctaskspanetaskgroupm_lsttasks"></a><a name="m_lsttasks"></a>CMFCTasksPaneTaskGroup::m_lstTasks

Contém a lista interna de tarefas.

```
CObList m_lstTasks;
```

### <a name="remarks"></a>Comentários

Para preencher esta lista, ligue para [CMFCTasksPane::AddTask](../../mfc/reference/cmfctaskspane-class.md#addtask).

## <a name="cmfctaskspanetaskgroupm_rect"></a><a name="m_rect"></a>CMFCTasksPaneTaskGroup::m_rect

Especifica o retângulo delimitador da legenda de grupo.

```
CRect m_rect;
```

### <a name="remarks"></a>Comentários

Esse valor é calculado automaticamente pelo framework.

## <a name="cmfctaskspanetaskgroupm_rectgroup"></a><a name="m_rectgroup"></a>CMFCTasksPaneTaskGroup::m_rectGroup

Especifica o retângulo delimitador do grupo.

```
CRect m_rectGroup;
```

### <a name="remarks"></a>Comentários

Esse valor é calculado automaticamente pelo framework.

## <a name="cmfctaskspanetaskgroupm_strname"></a><a name="m_strname"></a>CMFCTasksPaneTaskGroup::m_strName

Especifica o nome do grupo.

```
CString m_strName;
```

### <a name="remarks"></a>Comentários

Se esse valor estiver vazio, a legenda de grupo não será exibida e o grupo não poderá ser desbloqueado.

## <a name="cmfctaskspanetaskgroupsetaccdata"></a><a name="setaccdata"></a>CMFCTasksPaneTaskGroup::SetACCData

Determina os dados de acessibilidade para o grupo de tarefas atual.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
[em] Representa a janela pai do grupo de tarefas atual.

*dados*<br/>
[fora] Um objeto `CAccessibilityData` de tipo que é preenchido com os dados de acessibilidade do grupo de tarefas atual.

### <a name="return-value"></a>Valor retornado

TRUE se o parâmetro *de dados* foi preenchido com sucesso com os dados de acessibilidade do grupo de tarefas atual; caso contrário, FALSE.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCTasksPane](../../mfc/reference/cmfctaskspane-class.md)<br/>
[Classe CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)

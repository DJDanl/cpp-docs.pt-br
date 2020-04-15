---
title: Classe CMFCTasksPaneTask
ms.date: 11/19/2018
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
ms.openlocfilehash: 49fccdf161da7deb1fd88a12a107df40bafdae92
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375861"
---
# <a name="cmfctaskspanetask-class"></a>Classe CMFCTasksPaneTask

A `CMFCTasksPaneTask` classe é uma classe auxiliar que representa tarefas para o controle do painel de tarefas [(CMFCTasksPane).](../../mfc/reference/cmfctaskspane-class.md) O objeto de tarefa representa um item no grupo de tarefas [(CMFCTasksPaneTaskGroup).](../../mfc/reference/cmfctaskspanetaskgroup-class.md) Cada tarefa pode ter um comando que a estrutura executa quando um usuário clica na tarefa e um ícone que aparece à esquerda do nome da tarefa.

## <a name="syntax"></a>Sintaxe

```
class CMFCTasksPaneTask : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCTasksPaneTask::CMFCTasksPaneTask](#cmfctaskspanetask)|Cria e inicializa um objeto `CMFCTasksPaneTask`.|
|`CMFCTasksPaneTask::~CMFCTasksPaneTask`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCTasksPaneTask::SetACCData](#setaccdata)|Determina os dados de acessibilidade para a tarefa atual.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCTasksPaneTask::m_bAutoDestroyWindow](#m_bautodestroywindow)|Determina se a janela de tarefas é automaticamente destruída.|
|[CMFCTasksPaneTask::m_bIsBold](#m_bisbold)|Determina se a estrutura desenha um rótulo de tarefa em texto em negrito.|
|[CMFCTasksPaneTask::m_dwUserData](#m_dwuserdata)|Contém dados definidos pelo usuário que a estrutura associa à tarefa. Definir como zero se a tarefa não tiver dados associados.|
|[CMFCTasksPaneTask::m_hwndTask](#m_hwndtask)|Uma alça para a janela da tarefa.|
|[CMFCTasksPaneTask::m_nIcon](#m_nicon)|O índice na lista de imagens da imagem que o framework exibe ao lado da tarefa.|
|[CMFCTasksPaneTask::m_nWindowHeight](#m_nwindowheight)|A altura da janela de tarefas. Se a tarefa não tiver janela de tarefa, esse valor é zero.|
|[CMFCTasksPaneTask::m_pGroup](#m_pgroup)|Um indicador `CMFCTasksPaneTaskGroup` para o que esta tarefa pertence.|
|[CMFCTasksPaneTask::m_rect](#m_rect)|Especifica o retângulo delimitador da tarefa.|
|[CMFCTasksPaneTask::m_strName](#m_strname)|O nome da tarefa.|
|[CMFCTasksPaneTask::m_uiCommandID](#m_uicommandid)|Especifica o ID de comando do comando que a estrutura executa quando o usuário clica na tarefa. Se esse valor não for um ID de comando válido, a tarefa será tratada como um rótulo simples.|

## <a name="remarks"></a>Comentários

A ilustração a seguir mostra um grupo de tarefas que contém três tarefas:

![Grupo de trabalho, expandido](../../mfc/reference/media/nexttaskgrpexpand.png "Grupo de trabalho, expandido")

> [!NOTE]
> Se uma tarefa não tiver um ID de comando válido, ela será tratada como um rótulo simples.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxTasksPane.h

## <a name="cmfctaskspanetaskcmfctaskspanetask"></a><a name="cmfctaskspanetask"></a>CMFCTasksPaneTask::CMFCTasksPaneTask

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

*pGroup*<br/>
Especifica o [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) ao qual a tarefa pertence.

*lpszName*<br/>
Especifica o nome da tarefa.

*nÍcone*<br/>
Especifica o índice da imagem da tarefa na lista de imagens.

*uiCommandID*<br/>
Especifica o ID de comando do comando que é executado quando a tarefa é clicada.

*dwUserData*<br/>
Dados definidos pelo usuário.

*hwndTask*<br/>
Especifica a alça para a janela da tarefa.

*bAutoDestroyWindow*<br/>
Se TRUE, a janela de tarefas será destruída automaticamente.

*nWindowHeight*<br/>
Especifica a altura da janela de tarefas.

### <a name="remarks"></a>Comentários

## <a name="cmfctaskspanetaskm_bautodestroywindow"></a><a name="m_bautodestroywindow"></a>CMFCTasksPaneTask::m_bAutoDestroyWindow

Determina se a janela de tarefas é automaticamente destruída.

```
BOOL m_bAutoDestroyWindow;
```

### <a name="remarks"></a>Comentários

Definido como TRUE para especificar que a janela de tarefas [(CMFCTasksPaneTask::m_hwndTask)](#m_hwndtask)deve ser destruída automaticamente; caso contrário, FALSE.

## <a name="cmfctaskspanetaskm_bisbold"></a><a name="m_bisbold"></a>CMFCTasksPaneTask::m_bIsBold

Determina se um rótulo de tarefa é desenhado em texto em negrito.

```
BOOL m_bIsBold;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para exibir texto em negrito para o rótulo da tarefa.

## <a name="cmfctaskspanetaskm_dwuserdata"></a><a name="m_dwuserdata"></a>CMFCTasksPaneTask::m_dwUserData

Contém dados definidos pelo usuário que estão associados à tarefa. Definir como zero se nenhum dado estiver associado à tarefa.

```
DWORD m_dwUserData;
```

### <a name="remarks"></a>Comentários

## <a name="cmfctaskspanetaskm_hwndtask"></a><a name="m_hwndtask"></a>CMFCTasksPaneTask::m_hwndTask

Uma alça para a janela da tarefa.

```
HWND m_hwndTask;
```

### <a name="remarks"></a>Comentários

Para adicionar uma janela de tarefas, ligue para [CMFCTasksPane::AddWindow](../../mfc/reference/cmfctaskspane-class.md#addwindow).

## <a name="cmfctaskspanetaskm_nicon"></a><a name="m_nicon"></a>CMFCTasksPaneTask::m_nIcon

A posição de índice em uma lista de imagens que identifica uma imagem exibida ao lado da tarefa especificada.

```
int m_nIcon;
```

### <a name="remarks"></a>Comentários

A lista de imagens é definida por [CMFCTasksPane::SetIconsList](../../mfc/reference/cmfctaskspane-class.md#seticonslist).

Defina `m_nIcon` para -1 se você quiser exibir a tarefa sem uma imagem.

## <a name="cmfctaskspanetaskm_nwindowheight"></a><a name="m_nwindowheight"></a>CMFCTasksPaneTask::m_nWindowHeight

A altura da janela de tarefas. Se a tarefa não tiver janela de tarefa, esse valor é zero.

```
int m_nWindowHeight;
```

### <a name="remarks"></a>Comentários

## <a name="cmfctaskspanetaskm_pgroup"></a><a name="m_pgroup"></a>CMFCTasksPaneTask::m_pGroup

Ponteiro para o [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md) ao qual essa tarefa pertence.

```
CMFCTasksPaneTaskGroup* m_pGroup;
```

### <a name="remarks"></a>Comentários

Toda tarefa deve ter um grupo de pais. Você adiciona grupos a um painel de tarefas ligando para [CMFCTasksPane::AddGroup](../../mfc/reference/cmfctaskspane-class.md#addgroup).

## <a name="cmfctaskspanetaskm_rect"></a><a name="m_rect"></a>CMFCTasksPaneTask::m_rect

Especifica o retângulo delimitador da tarefa.

```
CRect m_rect;
```

### <a name="remarks"></a>Comentários

Esse valor é calculado pelo quadro quando a tarefa é desenhada.

## <a name="cmfctaskspanetaskm_strname"></a><a name="m_strname"></a>CMFCTasksPaneTask::m_strName

O nome da tarefa.

```
CString m_strName;
```

### <a name="remarks"></a>Comentários

## <a name="cmfctaskspanetaskm_uicommandid"></a><a name="m_uicommandid"></a>CMFCTasksPaneTask::m_uiCommandID

Especifica o ID de comando do comando que é executado quando o usuário clica na tarefa. Se esse valor não for um ID de comando válido, a tarefa será tratada como um rótulo simples.

```
UINT m_uiCommandID;
```

### <a name="remarks"></a>Comentários

## <a name="cmfctaskspanetasksetaccdata"></a><a name="setaccdata"></a>CMFCTasksPaneTask::SetACCData

Determina os dados de acessibilidade para a tarefa atual.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
[em] Representa a janela pai da tarefa atual.

*dados*<br/>
[fora] Um objeto `CAccessibilityData` de tipo que é preenchido com os dados de acessibilidade da tarefa atual.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o parâmetro *de dados* foi preenchido com sucesso com os dados de acessibilidade da tarefa atual; caso contrário, FALSE.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)

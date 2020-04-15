---
title: Classe CAnimationGroup
ms.date: 03/27/2019
f1_keywords:
- CAnimationGroup
- AFXANIMATIONCONTROLLER/CAnimationGroup
- AFXANIMATIONCONTROLLER/CAnimationGroup::CAnimationGroup
- AFXANIMATIONCONTROLLER/CAnimationGroup::Animate
- AFXANIMATIONCONTROLLER/CAnimationGroup::ApplyTransitions
- AFXANIMATIONCONTROLLER/CAnimationGroup::FindAnimationObject
- AFXANIMATIONCONTROLLER/CAnimationGroup::GetGroupID
- AFXANIMATIONCONTROLLER/CAnimationGroup::RemoveKeyframes
- AFXANIMATIONCONTROLLER/CAnimationGroup::RemoveTransitions
- AFXANIMATIONCONTROLLER/CAnimationGroup::Schedule
- AFXANIMATIONCONTROLLER/CAnimationGroup::SetAutodestroyTransitions
- AFXANIMATIONCONTROLLER/CAnimationGroup::AddKeyframes
- AFXANIMATIONCONTROLLER/CAnimationGroup::AddTransitions
- AFXANIMATIONCONTROLLER/CAnimationGroup::CreateTransitions
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_bAutoclearTransitions
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_bAutodestroyAnimationObjects
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_bAutodestroyKeyframes
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_lstAnimationObjects
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_lstKeyFrames
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_pStoryboard
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_nGroupID
- AFXANIMATIONCONTROLLER/CAnimationGroup::m_pParentController
helpviewer_keywords:
- CAnimationGroup [MFC], CAnimationGroup
- CAnimationGroup [MFC], Animate
- CAnimationGroup [MFC], ApplyTransitions
- CAnimationGroup [MFC], FindAnimationObject
- CAnimationGroup [MFC], GetGroupID
- CAnimationGroup [MFC], RemoveKeyframes
- CAnimationGroup [MFC], RemoveTransitions
- CAnimationGroup [MFC], Schedule
- CAnimationGroup [MFC], SetAutodestroyTransitions
- CAnimationGroup [MFC], AddKeyframes
- CAnimationGroup [MFC], AddTransitions
- CAnimationGroup [MFC], CreateTransitions
- CAnimationGroup [MFC], m_bAutoclearTransitions
- CAnimationGroup [MFC], m_bAutodestroyAnimationObjects
- CAnimationGroup [MFC], m_bAutodestroyKeyframes
- CAnimationGroup [MFC], m_lstAnimationObjects
- CAnimationGroup [MFC], m_lstKeyFrames
- CAnimationGroup [MFC], m_pStoryboard
- CAnimationGroup [MFC], m_nGroupID
- CAnimationGroup [MFC], m_pParentController
ms.assetid: 8bc18ceb-33a2-41d0-9731-71811adacab7
ms.openlocfilehash: 28d305e2107f7b9a8fd2164eb0ec9678d62ef8fa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369739"
---
# <a name="canimationgroup-class"></a>Classe CAnimationGroup

Implementa um grupo de animação, que combina um storyboard de animação, objetos de animação e transições para definir uma animação.

## <a name="syntax"></a>Sintaxe

```
class CAnimationGroup;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationGroup::CAnimationGroup](#canimationgroup)|Constrói um grupo de animação.|
|[CAnimationGroup::~CAnimationGroup](#_dtorcanimationgroup)|O destruidor. Chamado quando um grupo de animação está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationGroup::Animate](#animate)|Anima um grupo.|
|[CAnimationGroup::Aplicartransições](#applytransitions)|Aplica transições para objetos de animação.|
|[CAnimationGroup::FindAnimationObject](#findanimationobject)|Encontra um objeto de animação que contém a variável de animação especificada.|
|[CAnimationGroup::GetGroupID](#getgroupid)|Retorna GroupID.|
|[CAnimationGroup::RemoveKeyframes](#removekeyframes)|Remove e, opcionalmente, destrói todos os quadros-chave que pertencem a um grupo de animação.|
|[CAnimationGroup::RemoveTransitions](#removetransitions)|Remove transições de objetos de animação que pertencem a um grupo de animação.|
|[CAnimationGroup::Programação](#schedule)|Agenda uma animação no horário especificado.|
|[CAnimationGroup::SetAutodestroyTransitions](#setautodestroytransitions)|Direciona todos os objetos de animação que pertencem ao grupo dedestruir automaticamente as transições.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationGroup::AddKeyframes](#addkeyframes)|Um ajudante que adiciona quadros-chave a um storyboard.|
|[CAnimationGroup::AddTransitions](#addtransitions)|Um ajudante que adiciona transições a um storyboard.|
|[CAnimationGroup::CreateTransitions](#createtransitions)|Um ajudante que cria objetos de transição COM.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationGroup::m_bAutoclearTransitions](#m_bautocleartransitions)|Especifica como limpar transições de objetos de animação que pertencem ao grupo. Se este membro for TRUE, as transições serão removidas automaticamente quando uma animação foi agendada. Caso contrário, você precisa remover transições manualmente.|
|[CAnimationGroup::m_bAutodestroyAnimationObjects](#m_bautodestroyanimationobjects)|Especifica como destruir objetos de animação. Se este parâmetro for TRUE, os objetos de animação serão destruídos automaticamente quando o grupo for destruído. Caso contrário, os objetos de animação devem ser destruídos manualmente. O valor padrão é FALSE. Defina esse valor como TRUE somente se todos os objetos de animação pertencentes ao grupo forem alocados dinamicamente com o novo operador.|
|[CAnimationGroup::m_bAutodestroyKeyframes](#m_bautodestroykeyframes)|Especifica como destruir quadros-chave. Se esse valor for TRUE, todos os quadros-chave serão removidos e destruídos; caso contrário, eles são removidos apenas da lista. O valor padrão é TRUE.|
|[CAnimationGroup::m_lstAnimationObjects](#m_lstanimationobjects)|Contém uma lista de objetos de animação.|
|[CAnimationGroup::m_lstKeyFrames](#m_lstkeyframes)|Contém uma lista de quadros-chave.|
|[CAnimationGroup::m_pStoryboard](#m_pstoryboard)|Aponta para o storyboard de animação. Este ponteiro é válido somente após a chamada em Animate.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationGroup::m_nGroupID](#m_ngroupid)|Um identificador único do grupo de animação.|
|[CAnimationGroup::m_pParentController](#m_pparentcontroller)|Um ponteiro para o controlador de animação a que este grupo pertence.|

## <a name="remarks"></a>Comentários

Os grupos de animação são criados automaticamente pelo controlador de animação (CAnimationController) quando você adiciona objetos de animação usando CAnimationController::AddAnimationObject. Um grupo de animação é identificado pelo GroupID, que geralmente é tomado como um parâmetro para manipular grupos de animação. O GroupID é retirado do primeiro objeto de animação que está sendo adicionado a um novo grupo de animação. Um storyboard de animação encapsulado é criado depois que você chama CAnimationController::AnimateGroup e pode ser acessado através de m_pStoryboard de membros públicos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAnimationGroup`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationgroupcanimationgroup"></a><a name="_dtorcanimationgroup"></a>CAnimationGroup::~CAnimationGroup

O destruidor. Chamado quando um grupo de animação está sendo destruído.

```
~CAnimationGroup();
```

## <a name="canimationgroupaddkeyframes"></a><a name="addkeyframes"></a>CAnimationGroup::AddKeyframes

Um ajudante que adiciona quadros-chave a um storyboard.

```
void AddKeyframes(IUIAnimationStoryboard* pStoryboard, BOOL bAddDeep);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um objeto COM storyboard.

*bAddDeep*<br/>
Especifica se esse método deve adicionar aos quadros-chave do storyboard que dependem de outros quadros-chave.

## <a name="canimationgroupaddtransitions"></a><a name="addtransitions"></a>CAnimationGroup::AddTransitions

Um ajudante que adiciona transições a um storyboard.

```
void AddTransitions(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDependOnKeyframes);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um objeto COM storyboard.

*bDependOnkeyframes*

## <a name="canimationgroupanimate"></a><a name="animate"></a>CAnimationGroup::Animate

Anima um grupo.

```
BOOL Animate(
    IUIAnimationManager* pManager,
    IUIAnimationTimer* pTimer,
    BOOL bScheduleNow);
```

### <a name="parameters"></a>Parâmetros

*pManager*<br/>
*pTimer*
*bScheduleNow*

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método cria um storyboard interno, cria e aplica transições e agenda uma animação se bScheduleNow for TRUE. Se bScheduleNow for FALSE, você precisa chamar Agendapara iniciar a animação na hora especificada.

## <a name="canimationgroupapplytransitions"></a><a name="applytransitions"></a>CAnimationGroup::Aplicartransições

Aplica transições para objetos de animação.

```
void ApplyTransitions();
```

### <a name="remarks"></a>Comentários

Este método ASSERTS no modo de depuração se storyboard não tiver sido criado. Ele cria todas as transições primeiro, depois adiciona quadros-chave "estáticos" (quadros-chave que dependem de deslocamentos), adiciona transições que não dependem de quadros-chave, adiciona quadros-chave dependendo de transições e outros quadros-chave e, finalmente, adiciona transições que dependem de quadros-chave.

## <a name="canimationgroupcanimationgroup"></a><a name="canimationgroup"></a>CAnimationGroup::CAnimationGroup

Constrói um grupo de animação.

```
CAnimationGroup(CAnimationController* pParentController, UINT32 nGroupID);
```

### <a name="parameters"></a>Parâmetros

*controlador a pParentController*<br/>
Um ponteiro para o controlador de animação que cria um grupo.

*nGroupID*<br/>
Especifica groupID.

## <a name="canimationgroupcreatetransitions"></a><a name="createtransitions"></a>CAnimationGroup::CreateTransitions

Um ajudante que cria objetos de transição COM.

```
BOOL CreateTransitions();
```

### <a name="return-value"></a>Valor retornado

TRUE é o método bem sucedido, caso contrário FALSE.

## <a name="canimationgroupfindanimationobject"></a><a name="findanimationobject"></a>CAnimationGroup::FindAnimationObject

Encontra um objeto de animação que contém a variável de animação especificada.

```
CAnimationBaseObject* FindAnimationObject(IUIAnimationVariable* pVariable);
```

### <a name="parameters"></a>Parâmetros

*pVariable*<br/>
Um ponteiro para a variável animação.

### <a name="return-value"></a>Valor retornado

Um ponteiro para objeto de animação ou NULL se o objeto de animação não for encontrado.

## <a name="canimationgroupgetgroupid"></a><a name="getgroupid"></a>CAnimationGroup::GetGroupID

Retorna GroupID.

```
UINT32 GetGroupID() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador de grupo.

## <a name="canimationgroupm_bautocleartransitions"></a><a name="m_bautocleartransitions"></a>CAnimationGroup::m_bAutoclearTransitions

Especifica como limpar transições de objetos de animação que pertencem ao grupo. Se este membro for TRUE, as transições serão removidas automaticamente quando uma animação foi agendada. Caso contrário, você precisa remover transições manualmente.

```
BOOL m_bAutoclearTransitions;
```

## <a name="canimationgroupm_bautodestroyanimationobjects"></a><a name="m_bautodestroyanimationobjects"></a>CAnimationGroup::m_bAutodestroyAnimationObjects

Especifica como destruir objetos de animação. Se este parâmetro for TRUE, os objetos de animação serão destruídos automaticamente quando o grupo for destruído. Caso contrário, os objetos de animação devem ser destruídos manualmente. O valor padrão é FALSE. Defina esse valor como TRUE somente se todos os objetos de animação pertencentes ao grupo forem alocados dinamicamente com o novo operador.

```
BOOL m_bAutodestroyAnimationObjects;
```

## <a name="canimationgroupm_bautodestroykeyframes"></a><a name="m_bautodestroykeyframes"></a>CAnimationGroup::m_bAutodestroyKeyframes

Especifica como destruir quadros-chave. Se esse valor for TRUE, todos os quadros-chave serão removidos e destruídos; caso contrário, eles são removidos apenas da lista. O valor padrão é TRUE.

```
BOOL m_bAutodestroyKeyframes;
```

## <a name="canimationgroupm_lstanimationobjects"></a><a name="m_lstanimationobjects"></a>CAnimationGroup::m_lstAnimationObjects

Contém uma lista de objetos de animação.

```
CObList m_lstAnimationObjects;
```

## <a name="canimationgroupm_lstkeyframes"></a><a name="m_lstkeyframes"></a>CAnimationGroup::m_lstKeyFrames

Contém uma lista de quadros-chave.

```
CObList m_lstKeyFrames;
```

## <a name="canimationgroupm_ngroupid"></a><a name="m_ngroupid"></a>CAnimationGroup::m_nGroupID

Um identificador único do grupo de animação.

```
UINT32 m_nGroupID;
```

## <a name="canimationgroupm_pparentcontroller"></a><a name="m_pparentcontroller"></a>CAnimationGroup::m_pParentController

Um ponteiro para o controlador de animação a que este grupo pertence.

```
CAnimationController* m_pParentController;
```

## <a name="canimationgroupm_pstoryboard"></a><a name="m_pstoryboard"></a>CAnimationGroup::m_pStoryboard

Aponta para o storyboard de animação. Este ponteiro é válido somente após a chamada em Animate.

```
ATL::CComPtr<IUIAnimationStoryboard> m_pStoryboard;
```

## <a name="canimationgroupremovekeyframes"></a><a name="removekeyframes"></a>CAnimationGroup::RemoveKeyframes

Remove e, opcionalmente, destrói todos os quadros-chave que pertencem a um grupo de animação.

```
void RemoveKeyframes();
```

### <a name="remarks"></a>Comentários

Se m_bAutodestroyKeyframes membro for TRUE, os quadros-chave serão removidos e destruídos, caso contrário, os quadros-chave serão removidos da lista interna de quadros-chave.

## <a name="canimationgroupremovetransitions"></a><a name="removetransitions"></a>CAnimationGroup::RemoveTransitions

Remove transições de objetos de animação que pertencem a um grupo de animação.

```
void RemoveTransitions();
```

### <a name="remarks"></a>Comentários

Se m_bAutoclearTransitions bandeira estiver definida como TRUE, esse método será loopondo sobre todos os objetos de animação que pertencem ao grupo e chama CAnimationObject::ClearTransitions(FALSE).

## <a name="canimationgroupschedule"></a><a name="schedule"></a>CAnimationGroup::Programação

Agenda uma animação no horário especificado.

```
BOOL Schedule(IUIAnimationTimer* pTimer, UI_ANIMATION_SECONDS time);
```

### <a name="parameters"></a>Parâmetros

*pTimer*<br/>
Um ponteiro para o temporizador de animação.

*time*<br/>
Especifica o tempo para agendar a animação.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; FALSE se o método falhar ou se Animar não tiver sido chamado com bScheduleNow definido como FALSE.

### <a name="remarks"></a>Comentários

Ligue para esta função para agendar uma animação na hora especificada. Você deve chamar Animate com bScheduleNow definido como FALSE primeiro.

## <a name="canimationgroupsetautodestroytransitions"></a><a name="setautodestroytransitions"></a>CAnimationGroup::SetAutodestroyTransitions

Direciona todos os objetos de animação que pertencem ao grupo dedestruir automaticamente as transições.

```
void SetAutodestroyTransitions(BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoDestroy*<br/>
Especifica como destruir transições.

### <a name="remarks"></a>Comentários

Defina esse valor como FALSO somente se você alocar transições na pilha. O valor padrão é TRUE, portanto é altamente recomendável alocar objetos de transição usando novos operadores.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)

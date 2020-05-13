---
title: Classe CBaseKeyFrame
ms.date: 11/04/2016
f1_keywords:
- CBaseKeyFrame
- AFXANIMATIONCONTROLLER/CBaseKeyFrame
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::CBaseKeyFrame
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::AddToStoryboard
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::GetAnimationKeyframe
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::IsAdded
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::IsKeyframeAtOffset
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::m_bAdded
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::m_bIsKeyframeAtOffset
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::m_keyframe
helpviewer_keywords:
- CBaseKeyFrame [MFC], CBaseKeyFrame
- CBaseKeyFrame [MFC], AddToStoryboard
- CBaseKeyFrame [MFC], GetAnimationKeyframe
- CBaseKeyFrame [MFC], IsAdded
- CBaseKeyFrame [MFC], IsKeyframeAtOffset
- CBaseKeyFrame [MFC], m_bAdded
- CBaseKeyFrame [MFC], m_bIsKeyframeAtOffset
- CBaseKeyFrame [MFC], m_keyframe
ms.assetid: 285a2eff-e7c4-43be-b5aa-737727e6866d
ms.openlocfilehash: 3fcd55f6a157f4b837090a3608fb509b870aae5d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352983"
---
# <a name="cbasekeyframe-class"></a>Classe CBaseKeyFrame

Implementa a funcionalidade básica de um quadro-chave.

## <a name="syntax"></a>Sintaxe

```
class CBaseKeyFrame : public CObject;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cbasekeyframe::CBasekeyframe](#cbasekeyframe)|Constrói um objeto de quadro-chave.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CBaseKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave ao storyboard.|
|[CBaseKeyFrame::GetAnimationKeyframe](#getanimationkeyframe)|Retorna o valor do quadro-chave subjacente.|
|[cbasekeyframe::isadded](#isadded)|Conta se um quadro-chave foi adicionado ao storyboard.|
|[CBaseKeyFrame::IskeyframeAtOffset](#iskeyframeatoffset)|Especifica se o quadro-chave deve ser adicionado ao storyboard no offset ou após a transição.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CBaseKeyFrame::m_bAdded](#m_badded)|Especifica se esse quadro-chave foi adicionado a um storyboard.|
|[cBaseKeyFrame::m_bIsKeyframeAtOffset](#m_biskeyframeatoffset)|Especifica se esse quadro-chave deve ser adicionado ao storyboard em um deslocamento de outro quadro-chave existente ou no final de alguma transição.|
|[CBaseKeyFrame::m_keyframe](#m_keyframe)|Representa um quadro-chave da API do Windows Animation. Quando um quadro-chave não é inicializado, ele é definido para o valor predefinido UI_ANIMATION_KEYFRAME_STORYBOARD_START.|

## <a name="remarks"></a>Comentários

Encapsula UI_ANIMATION_KEYFRAME variável. Serve como uma classe base para qualquer implementação de quadro-chave. Um quadro-chave representa um momento no tempo dentro de um storyboard e pode ser usado para especificar os tempos de início e fim das transições. Existem dois tipos de quadros-chave - quadros-chave adicionados ao storyboard no deslocamento especificado (no tempo) ou quadros-chave adicionados após a transição especificada. Como as durações de algumas transições não podem ser conhecidas antes do início da animação, os valores reais de alguns quadros-chave são determinados apenas em tempo de execução. Como os quadros-chave podem depender de transições, que por sua vez dependem de quadros-chave, é importante evitar recursões infinitas ao construir cadeias de quadros- chaveiros.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CBaseKeyFrame`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="cbasekeyframeaddtostoryboard"></a><a name="addtostoryboard"></a>CBaseKeyFrame::AddToStoryboard

Adiciona um quadro-chave ao storyboard.

```
virtual BOOL AddToStoryboard(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDeepAdd);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um storyboard.

*bDeepAdd*<br/>
Se este parâmetro for TRUE e o quadro-chave a ser adicionado depende de algum outro quadro-chave ou transição, este método tentará adicionar este quadro-chave ou a transição para storyboard primeiro.

### <a name="return-value"></a>Valor retornado

TRUE se o quadro-chave foi adicionado ao storyboard com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método é chamado para adicionar um quadro-chave ao storyboard.

## <a name="cbasekeyframecbasekeyframe"></a><a name="cbasekeyframe"></a>cbasekeyframe::CBasekeyframe

Constrói um objeto de quadro-chave.

```
CBaseKeyFrame();
```

## <a name="cbasekeyframegetanimationkeyframe"></a><a name="getanimationkeyframe"></a>CBaseKeyFrame::GetAnimationKeyframe

Retorna o valor do quadro-chave subjacente.

```
UI_ANIMATION_KEYFRAME GetAnimationKeyframe() const;
```

### <a name="return-value"></a>Valor retornado

Um quadro-chave atual. O valor padrão é UI_ANIMATION_KEYFRAME_STORYBOARD_START.

### <a name="remarks"></a>Comentários

Este é um acessório para o valor do quadro-chave subjacente.

## <a name="cbasekeyframeisadded"></a><a name="isadded"></a>cbasekeyframe::isadded

Conta se um quadro-chave foi adicionado ao storyboard.

```
BOOL IsAdded() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se um quadro-chave for adicionado a um storyboard; otehrwise FALSE.

### <a name="remarks"></a>Comentários

Na classe base IsAdded sempre retorna TRUE, mas é substituído em classes derivadas.

## <a name="cbasekeyframeiskeyframeatoffset"></a><a name="iskeyframeatoffset"></a>CBaseKeyFrame::IskeyframeAtOffset

Especifica se o quadro-chave deve ser adicionado ao storyboard no offset ou após a transição.

```
BOOL IsKeyframeAtOffset() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o quadro-chave deve ser adicionado ao storyboard em algum deslocamento especificado. FALSE se o quadro-chave deve ser adicionado ao storyboard após alguma transição.

### <a name="remarks"></a>Comentários

Especifica se o quadro-chave deve ser adicionado ao storyboard no offset. A transição ou deslocamento deve ser especificada em uma classe derivada.

## <a name="cbasekeyframem_badded"></a><a name="m_badded"></a>CBaseKeyFrame::m_bAdded

Especifica se esse quadro-chave foi adicionado a um storyboard.

```
BOOL m_bAdded;
```

## <a name="cbasekeyframem_biskeyframeatoffset"></a><a name="m_biskeyframeatoffset"></a>cBaseKeyFrame::m_bIsKeyframeAtOffset

Especifica se esse quadro-chave deve ser adicionado ao storyboard em um deslocamento de outro quadro-chave existente ou no final de alguma transição.

```
BOOL m_bIsKeyframeAtOffset;
```

## <a name="cbasekeyframem_keyframe"></a><a name="m_keyframe"></a>CBaseKeyFrame::m_keyframe

Representa um quadro-chave da API do Windows Animation. Quando um quadro-chave não é inicializado, ele é definido para o valor predefinido UI_ANIMATION_KEYFRAME_STORYBOARD_START.

```
UI_ANIMATION_KEYFRAME m_keyframe;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)

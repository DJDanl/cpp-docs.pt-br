---
title: Classe CKeyFrame
ms.date: 11/04/2016
f1_keywords:
- CKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame::CKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame::AddToStoryboard
- AFXANIMATIONCONTROLLER/CKeyFrame::AddToStoryboardAfterTransition
- AFXANIMATIONCONTROLLER/CKeyFrame::AddToStoryboardAtOffset
- AFXANIMATIONCONTROLLER/CKeyFrame::GetExistingKeyframe
- AFXANIMATIONCONTROLLER/CKeyFrame::GetOffset
- AFXANIMATIONCONTROLLER/CKeyFrame::GetTransition
- AFXANIMATIONCONTROLLER/CKeyFrame::m_offset
- AFXANIMATIONCONTROLLER/CKeyFrame::m_pExistingKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame::m_pTransition
helpviewer_keywords:
- CKeyFrame [MFC], CKeyFrame
- CKeyFrame [MFC], AddToStoryboard
- CKeyFrame [MFC], AddToStoryboardAfterTransition
- CKeyFrame [MFC], AddToStoryboardAtOffset
- CKeyFrame [MFC], GetExistingKeyframe
- CKeyFrame [MFC], GetOffset
- CKeyFrame [MFC], GetTransition
- CKeyFrame [MFC], m_offset
- CKeyFrame [MFC], m_pExistingKeyFrame
- CKeyFrame [MFC], m_pTransition
ms.assetid: d050a562-20f6-4c65-8ce5-ccb3aef1a20e
ms.openlocfilehash: f535503338a82c7cc70455ae6a08cdab0f13c624
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372288"
---
# <a name="ckeyframe-class"></a>Classe CKeyFrame

Representa um quadro-chave de animação.

## <a name="syntax"></a>Sintaxe

```
class CKeyFrame : public CBaseKeyFrame;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[ckeyframe::CkeyFrame](#ckeyframe)|Sobrecarregado. Constrói um quadro-chave que depende de outro quadro-chave.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave a um storyboard. (Substitui [cbasekeyframe::AddToStoryboard](../../mfc/reference/cbasekeyframe-class.md#addtostoryboard).)|
|[CKeyFrame::AddToStoryboardAfterTransition](#addtostoryboardaftertransition)|Adiciona um quadro-chave ao storyboard após a transição.|
|[CkeyFrame::AddToStoryboardAtOffset](#addtostoryboardatoffset)|Adiciona um quadro-chave ao storyboard no offset.|
|[CKeyFrame::GetExistingKeyframe](#getexistingkeyframe)|Devolve um ponteiro a um quadro-chave do qual este quadro-chave depende.|
|[ckeyframe::getOffset](#getoffset)|Retorna um deslocamento de outro quadro-chave.|
|[CkeyFrame::GetTransition](#gettransition)|Retorna um ponteiro para uma transição que depende deste quadro-chave.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CKeyFrame::m_offset](#m_offset)|Especifica a compensação deste quadro-chave de um quadro-chave armazenado em m_pExistingKeyFrame.|
|[CkeyFrame::m_pExistingKeyFrame](#m_pexistingkeyframe)|Armazena um ponteiro para um keframe existente. Este quadro-chave é adicionado ao storyboard com m_offset ao quadro-chave existente.|
|[CKeyFrame::m_pTransition](#m_ptransition)|Armazena um ponteiro para transação que começa neste quadro-chave.|

## <a name="remarks"></a>Comentários

Esta classe implementa um quadro-chave de animação. Um quadro-chave representa um momento no tempo dentro de um storyboard e pode ser usado para especificar os tempos de início e fim das transições. Um quadro-chave pode ser baseado em outro quadro-chave e ter um deslocamento (em segundos) a partir dele, ou pode ser baseado em uma transição e representar um momento no tempo em que essa transição termina.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CBaseKeyframe](../../mfc/reference/cbasekeyframe-class.md)

[CKeyFrame](../../mfc/reference/ckeyframe-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="ckeyframeaddtostoryboard"></a><a name="addtostoryboard"></a>CKeyFrame::AddToStoryboard

Adiciona um quadro-chave a um storyboard.

```
virtual BOOL AddToStoryboard(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDeepAdd);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um storyboard.

*bDeepAdd*<br/>
Especifica se deve adicionar quadro-chave ou transição recursivamente.

### <a name="return-value"></a>Valor retornado

TRUE, se o quadro-chave foi adicionado com sucesso.

### <a name="remarks"></a>Comentários

Este método adiciona um quadro-chave ao storyboard. Se depender de outro quadro-chave ou transição e bDeepAdd for TRUE, este método tentará adicioná-los recursivamente.

## <a name="ckeyframeaddtostoryboardaftertransition"></a><a name="addtostoryboardaftertransition"></a>CKeyFrame::AddToStoryboardAfterTransition

Adiciona um quadro-chave ao storyboard após a transição.

```
BOOL AddToStoryboardAfterTransition(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDeepAdd);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um storyboard.

*bDeepAdd*<br/>
Especifica se deve adicionar uma transição recursivamente.

### <a name="return-value"></a>Valor retornado

TRUE, se o quadro-chave foi adicionado com sucesso.

### <a name="remarks"></a>Comentários

Esta função é chamada pela estrutura para adicionar um quadro-chave ao storyboard após a transição.

## <a name="ckeyframeaddtostoryboardatoffset"></a><a name="addtostoryboardatoffset"></a>CkeyFrame::AddToStoryboardAtOffset

Adiciona um quadro-chave ao storyboard no offset.

```
virtual BOOL AddToStoryboardAtOffset(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDeepAdd);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um storyboard.

*bDeepAdd*<br/>
Especifica se adicionar um quadro-chave este quadro-chave depende recursivamente.

### <a name="return-value"></a>Valor retornado

TRUE, se o quadro-chave foi adicionado com sucesso.

### <a name="remarks"></a>Comentários

Esta função é chamada pela estrutura para adicionar um quadro-chave ao storyboard no offset.

## <a name="ckeyframeckeyframe"></a><a name="ckeyframe"></a>ckeyframe::CkeyFrame

Constrói um quadro-chave que depende de uma transição.

```
CKeyFrame(CBaseTransition* pTransition);

CKeyFrame(
    CBaseKeyFrame* pKeyframe,
    UI_ANIMATION_SECONDS offset = 0.0);
```

### <a name="parameters"></a>Parâmetros

*pTransição*<br/>
Um ponteiro para uma transição.

*pKeyframe*<br/>
Um ponteiro para o quadro-chave.

*deslocamento*<br/>
Deslocamento, em segundos, do quadro-chave especificado por pKeyframe.

### <a name="remarks"></a>Comentários

O quadro-chave construído representará um momento no tempo dentro de um storyboard quando a transição especificada terminar.

## <a name="ckeyframegetexistingkeyframe"></a><a name="getexistingkeyframe"></a>CKeyFrame::GetExistingKeyframe

Devolve um ponteiro a um quadro-chave do qual este quadro-chave depende.

```
CBaseKeyFrame* GetExistingKeyframe();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para quadro-chave ou NULL se este quadro-chave não depender de outro quadro-chave.

### <a name="remarks"></a>Comentários

Este é um acessório para um quadro-chave do qual este quadro-chave depende.

## <a name="ckeyframegetoffset"></a><a name="getoffset"></a>ckeyframe::getOffset

Retorna um deslocamento de outro quadro-chave.

```
UI_ANIMATION_SECONDS GetOffset();
```

### <a name="return-value"></a>Valor retornado

Um deslocamento em segundos de outro quadro-chave.

### <a name="remarks"></a>Comentários

Este método deve ser chamado para determinar um deslocamento em segundos de outro quadro-chave.

## <a name="ckeyframegettransition"></a><a name="gettransition"></a>CkeyFrame::GetTransition

Retorna um ponteiro para uma transição que depende deste quadro-chave.

```
CBaseTransition* GetTransition();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para transição, ou NULL se este quadro-chave não depender da transição.

### <a name="remarks"></a>Comentários

Este é um acessório para uma transição que este quadro-chave depende.

## <a name="ckeyframem_offset"></a><a name="m_offset"></a>CKeyFrame::m_offset

Especifica a compensação deste quadro-chave de um quadro-chave armazenado em m_pExistingKeyFrame.

```
UI_ANIMATION_SECONDS m_offset;
```

## <a name="ckeyframem_pexistingkeyframe"></a><a name="m_pexistingkeyframe"></a>CkeyFrame::m_pExistingKeyFrame

Armazena um ponteiro para um keframe existente. Este quadro-chave é adicionado ao storyboard com m_offset ao quadro-chave existente.

```
CBaseKeyFrame* m_pExistingKeyFrame;
```

## <a name="ckeyframem_ptransition"></a><a name="m_ptransition"></a>CKeyFrame::m_pTransition

Armazena um ponteiro para transação que começa neste quadro-chave.

```
CBaseTransition* m_pTransition;
```

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)

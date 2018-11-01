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
ms.openlocfilehash: b6ebe5ba78a259014f62bdf04f30e856a57f1aba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451071"
---
# <a name="ckeyframe-class"></a>Classe CKeyFrame

Representa um quadro-chave de animação.

## <a name="syntax"></a>Sintaxe

```
class CKeyFrame : public CBaseKeyFrame;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CKeyFrame::CKeyFrame](#ckeyframe)|Sobrecarregado. Constrói um quadro-chave que depende de outro quadro-chave.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave a um storyboard. (Substitui [CBaseKeyFrame::AddToStoryboard](../../mfc/reference/cbasekeyframe-class.md#addtostoryboard).)|
|[CKeyFrame::AddToStoryboardAfterTransition](#addtostoryboardaftertransition)|Adiciona um quadro-chave para criar um storyboard depois de transição.|
|[CKeyFrame::AddToStoryboardAtOffset](#addtostoryboardatoffset)|Adiciona um quadro-chave para criar um storyboard no deslocamento.|
|[CKeyFrame::GetExistingKeyframe](#getexistingkeyframe)|Retorna um ponteiro para um quadro-chave que depende de seu quadro-chave.|
|[CKeyFrame::GetOffset](#getoffset)|Retorna um deslocamento de outro quadro-chave.|
|[CKeyFrame::GetTransition](#gettransition)|Retorna um ponteiro para uma transição que depende de seu quadro-chave.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CKeyFrame::m_offset](#m_offset)|Especifica o deslocamento do seu quadro-chave de um quadro-chave armazenado no m_pExistingKeyFrame.|
|[CKeyFrame::m_pExistingKeyFrame](#m_pexistingkeyframe)|Armazena um ponteiro para um keframe existente. Este quadro-chave é adicionado ao storyboard com m_offset ao quadro chave existente.|
|[CKeyFrame::m_pTransition](#m_ptransition)|Armazena um ponteiro para transtion que começa em seu quadro-chave.|

## <a name="remarks"></a>Comentários

Essa classe implementa um quadro-chave de animação. Um quadro-chave representa um momento específico dentro de um storyboard e pode ser usado para especificar os horários de início e término de transições. Um quadro-chave pode ser baseado em outro quadros-chave e têm um deslocamento (em segundos) a partir dele, ou pode se basear em uma transição e representa um ponto no tempo quando termina a essa transição.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CBaseKeyFrame](../../mfc/reference/cbasekeyframe-class.md)

[CKeyFrame](../../mfc/reference/ckeyframe-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="addtostoryboard"></a>  CKeyFrame::AddToStoryboard

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
Especifica se deve adicionar o quadro-chave ou fazer a transição de recursivamente.

### <a name="return-value"></a>Valor de retorno

TRUE se o quadro-chave foi adicionada com êxito.

### <a name="remarks"></a>Comentários

Esse método adiciona um quadro-chave para criar um storyboard. Se ele depende de outro quadro-chave ou uma transição e bDeepAdd for TRUE, esse método tentará adicioná-los recursivamente.

##  <a name="addtostoryboardaftertransition"></a>  CKeyFrame::AddToStoryboardAfterTransition

Adiciona um quadro-chave para criar um storyboard depois de transição.

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

### <a name="return-value"></a>Valor de retorno

TRUE se o quadro-chave foi adicionada com êxito.

### <a name="remarks"></a>Comentários

Essa função é chamada pelo framework para adicionar um quadro-chave para criar um storyboard depois de transição.

##  <a name="addtostoryboardatoffset"></a>  CKeyFrame::AddToStoryboardAtOffset

Adiciona um quadro-chave para criar um storyboard no deslocamento.

```
virtual BOOL AddToStoryboardAtOffset(
    IUIAnimationStoryboard* pStoryboard,
    BOOL bDeepAdd);
```

### <a name="parameters"></a>Parâmetros

*pStoryboard*<br/>
Um ponteiro para um storyboard.

*bDeepAdd*<br/>
Especifica se adicionar um quadro-chave esse quadro-chave dependem recursivamente.

### <a name="return-value"></a>Valor de retorno

TRUE se o quadro-chave foi adicionada com êxito.

### <a name="remarks"></a>Comentários

Essa função é chamada pelo framework para adicionar um quadro-chave para criar um storyboard no deslocamento.

##  <a name="ckeyframe"></a>  CKeyFrame::CKeyFrame

Constrói um quadro-chave que depende de uma transição.

```
CKeyFrame(CBaseTransition* pTransition);

CKeyFrame(
    CBaseKeyFrame* pKeyframe,
    UI_ANIMATION_SECONDS offset = 0.0);
```

### <a name="parameters"></a>Parâmetros

*pTransition*<br/>
Um ponteiro para uma transição.

*pKeyframe*<br/>
Um ponteiro para o quadro-chave.

*deslocamento*<br/>
Deslocamento, em segundos, de quadro-chave especificada pelo pKeyframe.

### <a name="remarks"></a>Comentários

O quadro-chave construído representará um momento específico dentro de um storyboard quando termina a transição especificada.

##  <a name="getexistingkeyframe"></a>  CKeyFrame::GetExistingKeyframe

Retorna um ponteiro para um quadro-chave que depende de seu quadro-chave.

```
CBaseKeyFrame* GetExistingKeyframe();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para o quadro-chave, ou nulo se esse quadro-chave não depende de outro quadro-chave.

### <a name="remarks"></a>Comentários

Esse é um acessador para um quadro-chave que depende de seu quadro-chave.

##  <a name="getoffset"></a>  CKeyFrame::GetOffset

Retorna um deslocamento de outro quadro-chave.

```
UI_ANIMATION_SECONDS GetOffset();
```

### <a name="return-value"></a>Valor de retorno

Um deslocamento em segundos a partir de outro quadro-chave.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para determinar um deslocamento em segundos a partir de outro quadro-chave.

##  <a name="gettransition"></a>  CKeyFrame::GetTransition

Retorna um ponteiro para uma transição que depende de seu quadro-chave.

```
CBaseTransition* GetTransition();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro válido para a transição, ou nulo se esse quadro-chave não depende de transição.

### <a name="remarks"></a>Comentários

Esse é um acessador para uma transição que depende de seu quadro-chave.

##  <a name="m_offset"></a>  CKeyFrame::m_offset

Especifica o deslocamento do seu quadro-chave de um quadro-chave armazenado no m_pExistingKeyFrame.

```
UI_ANIMATION_SECONDS m_offset;
```

##  <a name="m_pexistingkeyframe"></a>  CKeyFrame::m_pExistingKeyFrame

Armazena um ponteiro para um keframe existente. Este quadro-chave é adicionado ao storyboard com m_offset ao quadro chave existente.

```
CBaseKeyFrame* m_pExistingKeyFrame;
```

##  <a name="m_ptransition"></a>  CKeyFrame::m_pTransition

Armazena um ponteiro para transtion que começa em seu quadro-chave.

```
CBaseTransition* m_pTransition;
```

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)

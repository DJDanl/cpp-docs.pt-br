---
title: Classe CMFCRibbonStatusBar
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonStatusBar
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::AddDynamicElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::AddElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::AddExtendedElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::AddSeparator
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::Create
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::CreateEx
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::FindByID
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::FindElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::GetCount
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::GetElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::GetExCount
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::GetExElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::GetExtendedArea
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::GetSpace
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::IsBottomFrame
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::IsExtendedElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::IsInformationMode
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::RecalcLayout
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::RemoveAll
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::RemoveElement
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::SetInformation
- AFXRIBBONSTATUSBAR/CMFCRibbonStatusBar::OnDrawInformation
helpviewer_keywords:
- CMFCRibbonStatusBar [MFC], AddDynamicElement
- CMFCRibbonStatusBar [MFC], AddElement
- CMFCRibbonStatusBar [MFC], AddExtendedElement
- CMFCRibbonStatusBar [MFC], AddSeparator
- CMFCRibbonStatusBar [MFC], Create
- CMFCRibbonStatusBar [MFC], CreateEx
- CMFCRibbonStatusBar [MFC], FindByID
- CMFCRibbonStatusBar [MFC], FindElement
- CMFCRibbonStatusBar [MFC], GetCount
- CMFCRibbonStatusBar [MFC], GetElement
- CMFCRibbonStatusBar [MFC], GetExCount
- CMFCRibbonStatusBar [MFC], GetExElement
- CMFCRibbonStatusBar [MFC], GetExtendedArea
- CMFCRibbonStatusBar [MFC], GetSpace
- CMFCRibbonStatusBar [MFC], IsBottomFrame
- CMFCRibbonStatusBar [MFC], IsExtendedElement
- CMFCRibbonStatusBar [MFC], IsInformationMode
- CMFCRibbonStatusBar [MFC], RecalcLayout
- CMFCRibbonStatusBar [MFC], RemoveAll
- CMFCRibbonStatusBar [MFC], RemoveElement
- CMFCRibbonStatusBar [MFC], SetInformation
- CMFCRibbonStatusBar [MFC], OnDrawInformation
ms.assetid: 921eb57f-3b40-49fa-a38c-3f2fb6dc2893
ms.openlocfilehash: 8d90e01db022c33edd654e83af05e9986799f2b9
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754051"
---
# <a name="cmfcribbonstatusbar-class"></a>Classe CMFCRibbonStatusBar

A `CMFCRibbonStatusBar` classe implementa um controle de barra de status que pode exibir elementos de fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonStatusBar : public CMFCRibbonBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonStatusBar::AddDynamicelement](#adddynamicelement)|Adiciona um elemento dinâmico à barra de status da fita.|
|[CMFCRibbonStatusBar::AddElement](#addelement)|Adiciona um novo elemento de fita à barra de status da fita.|
|[CMFCRibbonStatusBar::AddExtendedElement](#addextendedelement)|Adiciona um elemento de fita à área estendida da barra de status da fita.|
|[CMFCRibbonStatusBar::AddSeparator](#addseparator)|Adiciona um separador à barra de status da fita.|
|[CMFCRibbonStatusBar::Criar](#create)|Cria uma barra de status de fita.|
|[CMFCRibbonStatusBar::CreateEx](#createex)|Cria uma barra de status de fita com um estilo estendido.|
|[CMFCRibbonstatusbar::Findbyid](#findbyid)||
|[CMFCRibbonStatusBar::Findelement](#findelement)|Retorna um ponteiro para o elemento que tem o ID de comando especificado.|
|[CMFCRibbonStatusBar::GetCount](#getcount)|Retorna o número de elementos localizados na área principal da barra de status da fita.|
|[CMFCRibbonStatusBar::GetElement](#getelement)|Retorna um ponteiro para o elemento localizado em um índice especificado.|
|[CMFCRibbonstatusbar::GetExCount](#getexcount)|Retorna o número de elementos localizados na área estendida da barra de status da fita.|
|[CMFCRibbonstatusbar::getexelement](#getexelement)|Retorna um ponteiro para o elemento que está localizado em um índice especificado na área estendida da barra de status da faixa de opções.|
|[CMFCRibbonStatusBar::getExtendedarea](#getextendedarea)||
|[CMFCRibbonStatusBar::GetSpace](#getspace)||
|[CMFCRibbonstatusBar::isbottomframe](#isbottomframe)||
|[CMFCRibbonStatusBar::IsextendedElement](#isextendedelement)||
|[CMFCRibbonStatusBar::IsInformationMode](#isinformationmode)|Determina se o modo de informação está habilitado para a barra de status da fita.|
|[CMFCRibbonStatusBar::RecalcLayout](#recalclayout)|(Substitui [cmfcribbonbar::RecalcLayout](../../mfc/reference/cmfcribbonbar-class.md#recalclayout).)|
|[CMFCRibbonstatusBar::removeAll](#removeall)|Remove todos os elementos da barra de status da fita.|
|[CMFCRibbonStatusBar::RemoveElement](#removeelement)|Remove o elemento que tem um ID de comando especificado da barra de status da fita.|
|[CMFCRibbonStatusBar::setInformation](#setinformation)|Ativa ou desativa o modo de informação da barra de status da fita.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonStatusBar::OnDrawInformation](#ondrawinformation)|Exibe a seqüência de informações que aparece na barra de status da fita quando o modo de informação estiver ativado.|

## <a name="remarks"></a>Comentários

Os usuários podem alterar a visibilidade dos elementos da fita em uma barra de status de fita usando o menu de contexto incorporado para a barra de status da fita. Você pode adicionar ou remover elementos dinamicamente.

Uma barra de status de fita tem duas áreas: uma área principal e uma área estendida. A área estendida é exibida no lado direito da barra de status da fita e aparece em uma cor diferente da área principal.

Normalmente, a área principal da barra de status exibe notificações de status e a área estendida exibe controles de exibição. A área estendida permanece visível o maior tempo possível quando o usuário redimensionar a barra de status da fita.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonStatusBar` usar vários métodos na classe. O exemplo mostra como adicionar um novo elemento de fita à barra de status da fita, adicionar um elemento de fita à área estendida da barra de status da fita, adicionar um separador e habilitar o modo regular para a barra de status da fita.

[!code-cpp[NVC_MFC_RibbonApp#15](../../mfc/reference/codesnippet/cpp/cmfcribbonstatusbar-class_1.cpp)]
[!code-cpp[NVC_MFC_RibbonApp#16](../../mfc/reference/codesnippet/cpp/cmfcribbonstatusbar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)

[Cmfcribbonstatusbar](../../mfc/reference/cmfcribbonstatusbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonstatusbar.h

## <a name="cmfcribbonstatusbaradddynamicelement"></a><a name="adddynamicelement"></a>CMFCRibbonStatusBar::AddDynamicelement

Adiciona um elemento dinâmico à barra de status da fita.

```cpp
void AddDynamicElement(CMFCRibbonBaseElement* pElement);
```

### <a name="parameters"></a>Parâmetros

*pElement*<br/>
[em] Um ponteiro para um elemento dinâmico.

### <a name="remarks"></a>Comentários

Ao contrário dos elementos regulares, os elementos dinâmicos não são personalizáveis e o menu personalizador da barra de status não os exibe.

## <a name="cmfcribbonstatusbaraddelement"></a><a name="addelement"></a>CMFCRibbonStatusBar::AddElement

Adiciona um novo elemento de fita à barra de status da fita.

```cpp
void AddElement(
    CMFCRibbonBaseElement* pElement,
    LPCTSTR lpszLabel,
    BOOL bIsVisible=TRUE);
```

### <a name="parameters"></a>Parâmetros

*pElement*<br/>
[em] Um ponteiro para o elemento adicionado.

*lpszLabel*<br/>
[em] Um rótulo de texto do elemento.

*bIsVisible*<br/>
[em] TRUE se você quiser adicionar o elemento como visível, FALSE se você quiser adicionar o elemento como escondido.

## <a name="cmfcribbonstatusbaraddextendedelement"></a><a name="addextendedelement"></a>CMFCRibbonStatusBar::AddExtendedElement

Adiciona um elemento de fita à área estendida da barra de status da fita.

```cpp
void AddExtendedElement(
    CMFCRibbonBaseElement* pElement,
    LPCTSTR lpszLabel,
    BOOL bIsVisible=TRUE);
```

### <a name="parameters"></a>Parâmetros

*pElement*<br/>
[em] Um ponteiro para o elemento adicionado.

*lpszLabel*<br/>
[em] O rótulo de texto do elemento.

*bIsVisible*<br/>
[em] TRUE se você quiser adicionar o elemento como visível, FALSE se você quiser adicionar o elemento como escondido.

### <a name="remarks"></a>Comentários

A área estendida está do lado direito do controle da barra de status.

## <a name="cmfcribbonstatusbaraddseparator"></a><a name="addseparator"></a>CMFCRibbonStatusBar::AddSeparator

Adiciona um separador à barra de status da fita.

```cpp
void AddSeparator();
```

### <a name="remarks"></a>Comentários

O framework adiciona um separador após o método [CMFCRibbonStatusBar::AddElement](#addelement). insere o último elemento.

## <a name="cmfcribbonstatusbarcreate"></a><a name="create"></a>CMFCRibbonStatusBar::Criar

Cria uma barra de status de fita.

```
BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle=WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,
    UINT nID=AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[em] Um ponteiro para a janela dos pais.

*Dwstyle*<br/>
[em] Uma combinação lógica ou de estilos de controle.

*nID*<br/>
[em] A id de controle da barra de status.

### <a name="return-value"></a>Valor retornado

TRUE se a barra de status for criada com sucesso, FALSO de outra forma.

## <a name="cmfcribbonstatusbarcreateex"></a><a name="createex"></a>CMFCRibbonStatusBar::CreateEx

Cria uma barra de status de fita que tem um estilo estendido.

```
BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle=0,
    DWORD dwStyle=WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,
    UINT nID=AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Um ponteiro para a janela dos pais.

*dwCtrlStyle*<br/>
Uma combinação lógica ou de estilos adicionais para criar o objeto da barra de status.

*Dwstyle*<br/>
O estilo de controle da barra de status.

*nID*<br/>
A id de controle da barra de status.

### <a name="return-value"></a>Valor retornado

TRUE se a barra de status for criada com sucesso, FALSO de outra forma.

## <a name="cmfcribbonstatusbarfindbyid"></a><a name="findbyid"></a>CMFCRibbonstatusbar::Findbyid

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
CMFCRibbonBaseElement* FindByID(UINT uiCmdID, BOOL = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *uiCmdID*<br/>
[em] *BOOL*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarfindelement"></a><a name="findelement"></a>CMFCRibbonStatusBar::Findelement

Retorna um ponteiro para o elemento que tem o ID de comando especificado.

```
CMFCRibbonBaseElement* FindElement(UINT uiID);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] A id do elemento.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o elemento que tem o ID de comando especificado. NULO se não houver tal elemento.

## <a name="cmfcribbonstatusbargetcount"></a><a name="getcount"></a>CMFCRibbonStatusBar::GetCount

Retorna o número de elementos localizados na área principal da barra de status da fita.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos localizados na área principal da barra de status da fita.

## <a name="cmfcribbonstatusbargetelement"></a><a name="getelement"></a>CMFCRibbonStatusBar::GetElement

Retorna um ponteiro para o elemento localizado em um índice especificado.

```
CMFCRibbonBaseElement* GetElement(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica um índice baseado em zero de um elemento localizado na área principal do controle da barra de status.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o elemento localizado no índice especificado. NULO se o índice for negativo ou exceder o número de elementos na barra de status.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbargetexcount"></a><a name="getexcount"></a>CMFCRibbonstatusbar::GetExCount

Retorna o número de elementos localizados na área estendida da barra de status da fita.

```
int GetExCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos localizados na área estendida da barra de status da fita.

## <a name="cmfcribbonstatusbargetexelement"></a><a name="getexelement"></a>CMFCRibbonstatusbar::getexelement

Retorna um ponteiro para o elemento que está localizado em um índice especificado na área estendida da barra de status da faixa de opções. A área estendida está do lado direito do controle da barra de status.

```
CMFCRibbonBaseElement* GetExElement(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice baseado em zero de um elemento localizado na área estendida do controle da barra de status.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o elemento que está localizado em um índice especificado na área estendida da barra de status da faixa de opções. NULL se *nIndex* for negativo ou exceder o número de elementos na área estendida da barra de status da fita.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbargetextendedarea"></a><a name="getextendedarea"></a>CMFCRibbonStatusBar::getExtendedarea

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual BOOL GetExtendedArea(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

[em] *rect*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbargetspace"></a><a name="getspace"></a>CMFCRibbonStatusBar::GetSpace

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
int GetSpace() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarisbottomframe"></a><a name="isbottomframe"></a>CMFCRibbonstatusBar::isbottomframe

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
BOOL IsBottomFrame() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarisextendedelement"></a><a name="isextendedelement"></a>CMFCRibbonStatusBar::IsextendedElement

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
BOOL IsExtendedElement(CMFCRibbonBaseElement* pElement) const;
```

### <a name="parameters"></a>Parâmetros

[em] *pElement*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarisinformationmode"></a><a name="isinformationmode"></a>CMFCRibbonStatusBar::IsInformationMode

Determina se o modo de informação está habilitado para a barra de status da fita.

```
BOOL IsInformationMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a barra de status puder funcionar no modo de informação; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

No modo de informação, a barra de status oculta todos os painéis regulares e exibe uma seqüência de mensagens.

## <a name="cmfcribbonstatusbarondrawinformation"></a><a name="ondrawinformation"></a>CMFCRibbonStatusBar::OnDrawInformation

Exibe a seqüência de string que aparece na barra de status da fita quando o modo de informação estiver ativado.

```
virtual void OnDrawInformation(
    CDC* pDC,
    CString& strInfo,
    CRect rectInfo);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*strInfo*<br/>
[em] A seqüência de informações.

*rectInfo*<br/>
[em] O retângulo delimitador.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada se você quiser personalizar a aparência da seqüência de informações na barra de status. Use o [método CMFCRibbonStatusBar::SetInformation](#setinformation) para colocar a barra de status no modo de informação. Neste modo, a barra de status oculta todos os painéis e exibe a seqüência de informações especificada pelo *strInfo*.

## <a name="cmfcribbonstatusbarrecalclayout"></a><a name="recalclayout"></a>CMFCRibbonStatusBar::RecalcLayout

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual void RecalcLayout();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonstatusbarremoveall"></a><a name="removeall"></a>CMFCRibbonstatusBar::removeAll

Remove todos os elementos da barra de status da fita.

```cpp
void RemoveAll();
```

## <a name="cmfcribbonstatusbarremoveelement"></a><a name="removeelement"></a>CMFCRibbonStatusBar::RemoveElement

Remove o elemento que tem um ID de comando especificado da barra de status da fita.

```
BOOL RemoveElement(UINT uiID);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] O ID do elemento para remover da barra de status.

### <a name="return-value"></a>Valor retornado

TRUE se um elemento com o *uiID* especificado for removido. FALSO de outra forma.

## <a name="cmfcribbonstatusbarsetinformation"></a><a name="setinformation"></a>CMFCRibbonStatusBar::setInformation

Ativa ou desativa o modo de informação da barra de status da fita.

```cpp
void SetInformation(LPCTSTR lpszInfo);
```

### <a name="parameters"></a>Parâmetros

*lpszInfo*<br/>
[em] A seqüência de informações.

### <a name="remarks"></a>Comentários

Use este método para colocar a barra de status no modo de informação. Neste modo, a barra de status oculta todos os painéis e exibe a seqüência de informações especificada pelo *lpszInfo*.

Quando o lpszInfo é NULL, a barra de status volta para o modo regular.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)<br/>
[Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)

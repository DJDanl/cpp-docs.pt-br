---
title: Classe CMFCMenuButton
ms.date: 07/15/2019
f1_keywords:
- CMFCMenuButton
- AFXMENUBUTTON/CMFCMenuButton
- AFXMENUBUTTON/CMFCMenuButton::CMFCMenuButton
- AFXMENUBUTTON/CMFCMenuButton::PreTranslateMessage
- AFXMENUBUTTON/CMFCMenuButton::SizeToContent
- AFXMENUBUTTON/CMFCMenuButton::m_bOSMenu
- AFXMENUBUTTON/CMFCMenuButton::m_bRightArrow
- AFXMENUBUTTON/CMFCMenuButton::m_bStayPressed
- AFXMENUBUTTON/CMFCMenuButton::m_hMenu
- AFXMENUBUTTON/CMFCMenuButton::m_nMenuResult
- AFXMENUBUTTON/CMFCMenuButton::m_bDefaultClick
helpviewer_keywords:
- CMFCMenuButton [MFC], CMFCMenuButton
- CMFCMenuButton [MFC], PreTranslateMessage
- CMFCMenuButton [MFC], SizeToContent
- CMFCMenuButton [MFC], m_bOSMenu
- CMFCMenuButton [MFC], m_bRightArrow
- CMFCMenuButton [MFC], m_bStayPressed
- CMFCMenuButton [MFC], m_hMenu
- CMFCMenuButton [MFC], m_nMenuResult
- CMFCMenuButton [MFC], m_bDefaultClick
ms.assetid: 53d3d459-1e5a-47c5-8b7f-2e61f6af5187
ms.openlocfilehash: 929fc1c8166f249fe3babc724b2c0bcd9cb99676
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369679"
---
# <a name="cmfcmenubutton-class"></a>Classe CMFCMenuButton

Um botão que exibe um menu pop-up e relata as seleções do menu do usuário.

## <a name="syntax"></a>Sintaxe

```
class CMFCMenuButton : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton::CMFCMenuButton](#cmfcmenubutton)|Constrói um objeto `CMFCMenuButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton::PreTraduzirmensagem](#pretranslatemessage)|Chamado pela estrutura para traduzir mensagens de janela antes de serem enviadas. (Substitui `CMFCButton::PreTranslateMessage`.)|
|[CMFCMenubutton::SizeToContent](#sizetocontent)|Altera o tamanho do botão de acordo com seu texto e tamanho da imagem.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton::m_bOSMenu](#m_bosmenu)|Especifica se é exibido o menu pop-up do sistema padrão ou se usa [CContextMenuManager::TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).|
|[CMFCMenuButton::m_bRightArrow](#m_brightarrow)|Especifica se o menu pop-up aparecerá por baixo ou à direita do botão.|
|[CMFCMenuButton::m_bStayPressed](#m_bstaypressed)|Especifica se o botão de menu muda seu estado após o usuário soltar o botão.|
|[CMFCMenuButton::m_hMenu](#m_hmenu)|Uma alça para o menu do Windows conectado.|
|[CMFCMenuButton::m_nMenuResult](#m_nmenuresult)|Um identificador que indica qual item o usuário selecionou no menu pop-up.|
|[CMFCMenuButton::m_bDefaultClick](#m_bdefaultclick)| Permitir o processamento padrão (no botão texto/imagem).|

## <a name="remarks"></a>Comentários

A `CMFCMenuButton` classe é derivada da [Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md) que, por sua vez, é derivada da [Classe CButton](../../mfc/reference/cbutton-class.md). Portanto, você pode `CMFCMenuButton` usar em seu código `CButton`da mesma maneira que você usaria .

Quando você `CMFCMenuButton`cria um , você deve passar em uma alça para o menu pop-up associado. Em seguida, `CMFCMenuButton::SizeToContent`chame a função . `CMFCMenuButton::SizeToContent`verifica se o tamanho do botão é suficiente para incluir uma seta que aponta para o local onde a janela pop-up aparecerá - ou seja, por baixo ou à direita do botão.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir a alça do menu anexado ao botão, redimensionar o botão de acordo com seu texto e tamanho da imagem e definir o menu pop-up exibido pela estrutura. Este trecho de código faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#38](../../mfc/reference/codesnippet/cpp/cmfcmenubutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#39](../../mfc/reference/codesnippet/cpp/cmfcmenubutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[Cmfcbutton](../../mfc/reference/cmfcbutton-class.md)

[Cmfcmenubutton](../../mfc/reference/cmfcmenubutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenubutton.h

## <a name="cmfcmenubuttoncmfcmenubutton"></a><a name="cmfcmenubutton"></a>CMFCMenuButton::CMFCMenuButton

Constrói um novo objeto [CMFCMenuButton.](../../mfc/reference/cmfcmenubutton-class.md)

```
CMFCMenuButton();
```

## <a name="cmfcmenubuttonm_bosmenu"></a><a name="m_bosmenu"></a>CMFCMenuButton::m_bOSMenu

Uma variável de membro booleano que indica qual menu pop-up o framework exibe.

```
BOOL m_bOSMenu;
```

### <a name="remarks"></a>Comentários

Se `m_bOSMenu` for TRUE, a estrutura `TrackPopupMenu` chama o método herdado para este objeto. Caso contrário, a estrutura chama [CContextMenuManager::TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).

## <a name="cmfcmenubuttonm_brightarrow"></a><a name="m_brightarrow"></a>CMFCMenuButton::m_bRightArrow

Uma variável de membro booleano que indica a localização do menu pop-up.

```
BOOL m_bRightArrow;
```

### <a name="remarks"></a>Comentários

Quando o usuário pressiona o botão de menu, o aplicativo mostra um menu pop-up. A estrutura exibirá o menu pop-up sob o botão ou à direita do botão. O botão também tem uma pequena seta que indica onde o menu pop-up aparecerá. Se `m_bRightArrow` for VERDADE, a estrutura exibe o menu pop-up à direita do botão. Caso contrário, ele exibe o menu pop-up sob o botão.

## <a name="cmfcmenubuttonm_bstaypressed"></a><a name="m_bstaypressed"></a>CMFCMenuButton::m_bStayPressed

Uma variável de membro booleano que indica se o botão de menu aparece pressionado enquanto o usuário faz uma seleção do menu pop-up.

```
BOOL m_bStayPressed;
```

### <a name="remarks"></a>Comentários

Se `m_bStayPressed` o membro for FALSE, o botão de menu não será pressionado quando os usos clicam no botão. Neste caso, o framework exibe apenas o menu pop-up.

Se `m_bStayPressed` o membro for TRUE, o botão de menu será pressionado quando o usuário clicar no botão. Ele permanece pressionado até que o usuário feche o menu pop-up, seja fazendo uma seleção ou cancelando.

## <a name="cmfcmenubuttonm_hmenu"></a><a name="m_hmenu"></a>CMFCMenuButton::m_hMenu

A alça do menu anexado.

```
HMENU m_hMenu;
```

### <a name="remarks"></a>Comentários

A estrutura exibe o menu indicado por esta variável de membro quando o usuário clica no botão menu.

## <a name="cmfcmenubuttonm_nmenuresult"></a><a name="m_nmenuresult"></a>CMFCMenuButton::m_nMenuResult

Um inteiro que indica qual item o usuário seleciona no menu pop-up.

```
int m_nMenuResult;
```

### <a name="remarks"></a>Comentários

O valor desta variável membro é zero se o usuário cancelar o menu sem fazer uma seleção ou se ocorrer um erro.

## <a name="cmfcmenubuttonm_bdefaultclick"></a><a name="m_bdefaultclick"></a>CMFCMenuButton::m_bDefaultClick

Permite o processamento padrão de texto ou imagens no botão.

```
BOOL  m_bDefaultClick;
```

### <a name="remarks"></a>Comentários

A configuração m_bDefaultClick a falso faz com que o botão mostre o menu quando você clica em qualquer lugar no botão.

## <a name="cmfcmenubuttonm_nmenuresult"></a><a name="m_nmenuresult"></a>CMFCMenuButton::m_nMenuResult

Um inteiro que indica qual item o usuário seleciona no menu pop-up.

```
int m_nMenuResult;
```

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubuttonpretranslatemessage"></a><a name="pretranslatemessage"></a>CMFCMenuButton::PreTraduzirmensagem

Chamado pela estrutura para traduzir mensagens de janela antes de serem enviadas.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
[em] Aponta para uma estrutura [MSG](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser processada.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem foi traduzida e não deve ser despachada; 0 se a mensagem não foi traduzida e deve ser despachada.

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubuttonsizetocontent"></a><a name="sizetocontent"></a>CMFCMenubutton::SizeToContent

Altera o tamanho do botão de acordo com o tamanho do texto e o tamanho da imagem.

```
virtual CSize SizeToContent(BOOL bCalcOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
[em] Um parâmetro booleano que indica se este método redimensiona o botão .

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o novo tamanho para o botão.

### <a name="remarks"></a>Comentários

Se você chamar esta função e *bCalcOnly* é TRUE, `SizeToContent` calculará apenas o novo tamanho do botão.

O novo tamanho do botão é calculado para se encaixar no texto do botão, imagem e seta. A estrutura também adiciona margens predefinidas de 10 pixels para a borda horizontal e 5 pixels para a borda vertical.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)

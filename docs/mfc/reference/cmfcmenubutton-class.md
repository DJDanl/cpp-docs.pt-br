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
ms.openlocfilehash: 2f8ef341d7f460ed6b0ec23cb8a490842eb67cbc
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743263"
---
# <a name="cmfcmenubutton-class"></a>Classe CMFCMenuButton

Um botão que exibe um menu pop-up e relatórios sobre as seleções de menu do usuário.

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
|[CMFCMenuButton::P reTranslateMessage](#pretranslatemessage)|Chamado pelo Framework para traduzir as mensagens de janela antes que elas sejam expedidas. (Substitui `CMFCButton::PreTranslateMessage`.)|
|[CMFCMenuButton::SizeToContent](#sizetocontent)|Altera o tamanho do botão de acordo com o tamanho do texto e da imagem.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton:: m_bOSMenu](#m_bosmenu)|Especifica se deseja exibir o menu pop-up do sistema padrão ou usar [CContextMenuManager:: TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).|
|[CMFCMenuButton:: m_bRightArrow](#m_brightarrow)|Especifica se o menu pop-up aparecerá abaixo ou à direita do botão.|
|[CMFCMenuButton:: m_bStayPressed](#m_bstaypressed)|Especifica se o botão de menu muda seu estado depois que o usuário libera o botão.|
|[CMFCMenuButton:: m_hMenu](#m_hmenu)|Um identificador para o menu do Windows anexado.|
|[CMFCMenuButton:: m_nMenuResult](#m_nmenuresult)|Um identificador que indica qual item o usuário selecionou no menu pop-up.|
|[CMFCMenuButton:: m_bDefaultClick](#m_bdefaultclick)| Permitir processamento padrão (no texto do botão/imagem).|

## <a name="remarks"></a>Comentários

A `CMFCMenuButton` classe é derivada da [classe CMFCButton](../../mfc/reference/cmfcbutton-class.md) que, por sua vez, é derivada da [classe CButton](../../mfc/reference/cbutton-class.md). Portanto, você pode usar `CMFCMenuButton` o em seu código da mesma maneira que usaria `CButton` .

Ao criar um `CMFCMenuButton` , você deve passar um identificador para o menu pop-up associado. Em seguida, chame a função `CMFCMenuButton::SizeToContent` . `CMFCMenuButton::SizeToContent` verifica se o tamanho do botão é suficiente para incluir uma seta que aponta para o local onde a janela pop-up será exibida-ou seja, abaixo ou à direita do botão.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir o identificador do menu anexado ao botão, redimensionar o botão de acordo com o tamanho do texto e da imagem e definir o menu pop-up que é exibido pela estrutura. Este trecho de código faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#38](../../mfc/reference/codesnippet/cpp/cmfcmenubutton-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#39](../../mfc/reference/codesnippet/cpp/cmfcmenubutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[CMFCButton](../../mfc/reference/cmfcbutton-class.md)

[CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenubutton. h

## <a name="cmfcmenubuttoncmfcmenubutton"></a><a name="cmfcmenubutton"></a> CMFCMenuButton::CMFCMenuButton

Constrói um novo objeto [CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md) .

```
CMFCMenuButton();
```

## <a name="cmfcmenubuttonm_bosmenu"></a><a name="m_bosmenu"></a> CMFCMenuButton:: m_bOSMenu

Uma variável de membro booliana que indica qual menu pop-up a estrutura exibe.

```
BOOL m_bOSMenu;
```

### <a name="remarks"></a>Comentários

Se `m_bOSMenu` for true, a estrutura chamará o `TrackPopupMenu` método herdado para esse objeto. Caso contrário, a estrutura chamará [CContextMenuManager:: TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).

## <a name="cmfcmenubuttonm_brightarrow"></a><a name="m_brightarrow"></a> CMFCMenuButton:: m_bRightArrow

Uma variável de membro booliana que indica o local do menu pop-up.

```
BOOL m_bRightArrow;
```

### <a name="remarks"></a>Comentários

Quando o usuário pressiona o botão de menu, o aplicativo mostra um menu pop-up. A estrutura exibirá o menu pop-up sob o botão ou à direita do botão. O botão também tem uma pequena seta que indica onde o menu pop-up será exibido. Se `m_bRightArrow` for true, a estrutura exibirá o menu pop-up à direita do botão. Caso contrário, ele exibirá o menu pop-up sob o botão.

## <a name="cmfcmenubuttonm_bstaypressed"></a><a name="m_bstaypressed"></a> CMFCMenuButton:: m_bStayPressed

Uma variável de membro booliana que indica se o botão de menu aparece pressionado enquanto o usuário faz uma seleção no menu pop-up.

```
BOOL m_bStayPressed;
```

### <a name="remarks"></a>Comentários

Se o `m_bStayPressed` membro for false, o botão de menu não será pressionado quando o usar clicar no botão. Nesse caso, a estrutura exibe apenas o menu pop-up.

Se o `m_bStayPressed` membro for true, o botão de menu será pressionado quando o usuário clicar no botão. Ela permanece pressionada até que o usuário feche o menu pop-up, seja fazendo uma seleção ou cancelando.

## <a name="cmfcmenubuttonm_hmenu"></a><a name="m_hmenu"></a> CMFCMenuButton:: m_hMenu

O identificador para o menu anexado.

```
HMENU m_hMenu;
```

### <a name="remarks"></a>Comentários

A estrutura exibe o menu indicado por essa variável de membro quando o usuário clica no botão de menu.

## <a name="cmfcmenubuttonm_nmenuresult"></a><a name="m_nmenuresult"></a> CMFCMenuButton:: m_nMenuResult

Um inteiro que indica qual item o usuário seleciona no menu pop-up.

```
int m_nMenuResult;
```

### <a name="remarks"></a>Comentários

O valor dessa variável de membro será zero se o usuário cancelar o menu sem fazer uma seleção ou se ocorrer um erro.

## <a name="cmfcmenubuttonm_bdefaultclick"></a><a name="m_bdefaultclick"></a> CMFCMenuButton:: m_bDefaultClick

Permite o processamento padrão de texto ou imagens no botão.

```
BOOL  m_bDefaultClick;
```

### <a name="remarks"></a>Comentários

Definir m_bDefaultClick como false faz com que o botão mostre o menu quando você clica em qualquer lugar do botão.

## <a name="cmfcmenubuttonpretranslatemessage"></a><a name="pretranslatemessage"></a> CMFCMenuButton::P reTranslateMessage

Chamado pelo Framework para traduzir as mensagens de janela antes que elas sejam expedidas.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
no Aponta para uma estrutura [msg](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser processada.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a mensagem foi convertida e não deve ser expedida; 0 se a mensagem não foi convertida e deve ser expedida.

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubuttonsizetocontent"></a><a name="sizetocontent"></a> CMFCMenuButton::SizeToContent

Altera o tamanho do botão de acordo com o tamanho do texto e da imagem.

```
virtual CSize SizeToContent(BOOL bCalcOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
no Um parâmetro booliano que indica se esse método redimensiona o botão.

### <a name="return-value"></a>Valor Retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que especifica o novo tamanho do botão.

### <a name="remarks"></a>Comentários

Se você chamar essa função e *bCalcOnly* for true, `SizeToContent` o calculará apenas o novo tamanho do botão.

O novo tamanho do botão é calculado para ajustar o texto do botão, a imagem e a seta. A estrutura também adiciona margens predefinidas de 10 pixels para a borda horizontal e 5 pixels para a borda vertical.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)

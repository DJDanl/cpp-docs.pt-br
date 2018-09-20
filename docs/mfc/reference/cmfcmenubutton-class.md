---
title: Classe CMFCMenuButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CMFCMenuButton [MFC], CMFCMenuButton
- CMFCMenuButton [MFC], PreTranslateMessage
- CMFCMenuButton [MFC], SizeToContent
- CMFCMenuButton [MFC], m_bOSMenu
- CMFCMenuButton [MFC], m_bRightArrow
- CMFCMenuButton [MFC], m_bStayPressed
- CMFCMenuButton [MFC], m_hMenu
- CMFCMenuButton [MFC], m_nMenuResult
ms.assetid: 53d3d459-1e5a-47c5-8b7f-2e61f6af5187
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 31f487267074af185b6393496823ac9965a4a6b5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46411489"
---
# <a name="cmfcmenubutton-class"></a>Classe CMFCMenuButton

Um botão que exibe um menu pop-up e relata de seleções de menu do usuário.

## <a name="syntax"></a>Sintaxe

```
class CMFCMenuButton : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton::CMFCMenuButton](#cmfcmenubutton)|Constrói um objeto `CMFCMenuButton`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton::PreTranslateMessage](#pretranslatemessage)|Chamado pelo framework para converter as mensagens da janela antes de serem expedidas. (Substitui `CMFCButton::PreTranslateMessage`.)|
|[CMFCMenuButton::SizeToContent](#sizetocontent)|Altera o tamanho do botão de acordo com seu tamanho de texto e imagem.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenuButton::m_bOSMenu](#m_bosmenu)|Especifica se deve exibir o menu pop-up do sistema padrão ou usar [CContextMenuManager::TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).|
|[CMFCMenuButton::m_bRightArrow](#m_brightarrow)|Especifica se o menu pop-up será exibida abaixo ou à direita do botão.|
|[CMFCMenuButton::m_bStayPressed](#m_bstaypressed)|Especifica se o botão de menu muda seu estado depois que o usuário libera o botão.|
|[CMFCMenuButton::m_hMenu](#m_hmenu)|Um identificador para o menu do Windows anexado.|
|[CMFCMenuButton::m_nMenuResult](#m_nmenuresult)|Um identificador que indica qual item o usuário selecionado no menu pop-up.|

## <a name="remarks"></a>Comentários

O `CMFCMenuButton` classe é derivada do [classe CMFCButton](../../mfc/reference/cmfcbutton-class.md) que, por sua vez, deriva de [classe CButton](../../mfc/reference/cbutton-class.md). Portanto, você pode usar `CMFCMenuButton` em seu código da mesma maneira que você usaria `CButton`.

Quando você cria um `CMFCMenuButton`, você deverá passar um identificador para o menu pop-up associado. Em seguida, chame a função `CMFCMenuButton::SizeToContent`. `CMFCMenuButton::SizeToContent` verifica se o tamanho do botão é suficiente para incluir uma seta que aponta para o local onde a janela pop-up será exibida - ou seja, abaixo ou à direita do botão.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir o identificador do menu anexado ao botão, redimensionar o botão de acordo com seu tamanho de texto e imagem e o menu pop-up que é exibido pela estrutura. Este trecho de código é parte do [exemplo de novos controles](../../visual-cpp-samples.md).

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

**Cabeçalho:** afxmenubutton.h

##  <a name="cmfcmenubutton"></a>  CMFCMenuButton::CMFCMenuButton

Constrói um novo [CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md) objeto.

```
CMFCMenuButton();
```

##  <a name="m_bosmenu"></a>  CMFCMenuButton::m_bOSMenu

Uma variável de membro booleano que indica quais menu pop-up de exibida pela estrutura.

```
BOOL m_bOSMenu;
```

### <a name="remarks"></a>Comentários

Se `m_bOSMenu` for TRUE, o framework chama o herdadas `TrackPopupMenu` método para esse objeto. Caso contrário, o framework chama [CContextMenuManager::TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).

##  <a name="m_brightarrow"></a>  CMFCMenuButton::m_bRightArrow

Uma variável de membro booleano que indica o local do menu pop-up.

```
BOOL m_bRightArrow;
```

### <a name="remarks"></a>Comentários

Quando o usuário pressiona o botão de menu, o aplicativo mostra um menu pop-up. O framework exibirá um menu pop-up sob o botão ou à direita do botão. O botão também tem uma pequena seta que indica onde o menu pop-up será exibida. Se `m_bRightArrow` for TRUE, a estrutura exibe o menu pop-up à direita do botão. Caso contrário, ele exibe o menu pop-up sob o botão.

##  <a name="m_bstaypressed"></a>  CMFCMenuButton::m_bStayPressed

Uma variável de membro booleano que indica se o botão de menu aparece pressionado enquanto o usuário faz uma seleção no menu pop-up.

```
BOOL m_bStayPressed;
```

### <a name="remarks"></a>Comentários

Se o `m_bStayPressed` membro for FALSE, o menu não se tornar pressionado quando os usos clica no botão. Nesse caso, o framework exibe apenas o menu pop-up.

Se o `m_bStayPressed` membro for TRUE, o menu se torna pressionado quando o usuário clica no botão. Ela permanece pressionada até depois que o usuário fecha um menu pop-up, fazendo uma seleção ou Cancelar.

##  <a name="m_hmenu"></a>  CMFCMenuButton::m_hMenu

O identificador para o menu anexado.

```
HMENU m_hMenu;
```

### <a name="remarks"></a>Comentários

O framework exibe o menu indicado por essa variável de membro, quando o usuário clica no botão de menu.

##  <a name="m_nmenuresult"></a>  CMFCMenuButton::m_nMenuResult

Um inteiro que indica qual item o usuário seleciona o menu pop-up.

```
int m_nMenuResult;
```

### <a name="remarks"></a>Comentários

O valor dessa variável de membro é zero, se o usuário cancelar o menu sem fazer uma seleção ou se ocorrer um erro.

##  <a name="pretranslatemessage"></a>  CMFCMenuButton::PreTranslateMessage

Chamado pelo framework para converter as mensagens da janela antes de serem expedidas.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
[in] Aponta para um [MSG](../../mfc/reference/msg-structure1.md) estrutura que contém a mensagem a ser processada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem foi traduzida e não deve ser expedida; 0 se a mensagem não foi traduzida e deve ser expedida.

### <a name="remarks"></a>Comentários

##  <a name="sizetocontent"></a>  CMFCMenuButton::SizeToContent

Altera o tamanho do botão de acordo com seu tamanho de texto e o tamanho da imagem.

```
virtual CSize SizeToContent(BOOL bCalcOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
[in] Um parâmetro booliano que indica se esse método é redimensionado no botão.

### <a name="return-value"></a>Valor de retorno

Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o novo tamanho do botão.

### <a name="remarks"></a>Comentários

Se você chamar essa função e *bCalcOnly* for TRUE, `SizeToContent` calculará o novo tamanho do botão.

O novo tamanho do botão é calculado de acordo com o texto do botão, a imagem e a seta. A estrutura também adiciona margens predefinidas de 10 pixels da borda horizontal e 5 pixels da borda vertical.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)

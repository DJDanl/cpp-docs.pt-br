---
title: Classe CMFCDesktopAlertWnd
ms.date: 10/18/2018
f1_keywords:
- CMFCDesktopAlertWnd
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::Create
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetAnimationSpeed
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetAnimationType
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetAutoCloseTime
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetCaptionHeight
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetDialogSize
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetLastPos
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::GetTransparency
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::HasSmallCaption
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::OnBeforeShow
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::OnClickLinkButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::OnCommand
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::OnDraw
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::ProcessCommand
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::SetAnimationSpeed
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::SetAnimationType
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::SetAutoCloseTime
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::SetSmallCaption
- AFXDESKTOPALERTWND/CMFCDesktopAlertWnd::SetTransparency
helpviewer_keywords:
- CMFCDesktopAlertWnd [MFC], Create
- CMFCDesktopAlertWnd [MFC], GetAnimationSpeed
- CMFCDesktopAlertWnd [MFC], GetAnimationType
- CMFCDesktopAlertWnd [MFC], GetAutoCloseTime
- CMFCDesktopAlertWnd [MFC], GetCaptionHeight
- CMFCDesktopAlertWnd [MFC], GetDialogSize
- CMFCDesktopAlertWnd [MFC], GetLastPos
- CMFCDesktopAlertWnd [MFC], GetTransparency
- CMFCDesktopAlertWnd [MFC], HasSmallCaption
- CMFCDesktopAlertWnd [MFC], OnBeforeShow
- CMFCDesktopAlertWnd [MFC], OnClickLinkButton
- CMFCDesktopAlertWnd [MFC], OnCommand
- CMFCDesktopAlertWnd [MFC], OnDraw
- CMFCDesktopAlertWnd [MFC], ProcessCommand
- CMFCDesktopAlertWnd [MFC], SetAnimationSpeed
- CMFCDesktopAlertWnd [MFC], SetAnimationType
- CMFCDesktopAlertWnd [MFC], SetAutoCloseTime
- CMFCDesktopAlertWnd [MFC], SetSmallCaption
- CMFCDesktopAlertWnd [MFC], SetTransparency
ms.assetid: 73a2dd7b-ea84-4ae2-9830-7cf6e8dd2425
ms.openlocfilehash: 3ff74f5025d888077b51f8191f043237597dfdbe
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58776967"
---
# <a name="cmfcdesktopalertwnd-class"></a>Classe CMFCDesktopAlertWnd

O `CMFCDesktopAlertWnd` classe implementa a funcionalidade de uma caixa de diálogo sem janela restrita que aparece na tela para informar ao usuário sobre um evento.

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.
## <a name="syntax"></a>Sintaxe

```
class CMFCDesktopAlertWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDesktopAlertWnd::Create](#create)|Cria e inicializa a janela de alerta da área de trabalho.|
|[CMFCDesktopAlertWnd::GetAnimationSpeed](#getanimationspeed)|Retorna a velocidade da animação.|
|[CMFCDesktopAlertWnd::GetAnimationType](#getanimationtype)|Retorna o tipo de animação.|
|[CMFCDesktopAlertWnd::GetAutoCloseTime](#getautoclosetime)|Retorna o tempo limite de fechamento automático.|
|[CMFCDesktopAlertWnd::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda.|
|[CMFCDesktopAlertWnd::GetDialogSize](#getdialogsize)||
|[CMFCDesktopAlertWnd::GetLastPos](#getlastpos)|Retorna a última posição válida da janela de alerta da área de trabalho na tela.|
|[CMFCDesktopAlertWnd::GetTransparency](#gettransparency)|Retorna o nível de transparência.|
|[CMFCDesktopAlertWnd::HasSmallCaption](#hassmallcaption)|Determina se a janela da área de trabalho de alerta é exibida com a legenda curta.|
|[CMFCDesktopAlertWnd::OnBeforeShow](#onbeforeshow)||
|[CMFCDesktopAlertWnd::OnClickLinkButton](#onclicklinkbutton)|Chamado pelo framework quando o usuário clica em um botão de link localizado no menu de alerta da área de trabalho.|
|[CMFCDesktopAlertWnd::OnCommand](#oncommand)|O framework chama essa função membro, quando o usuário seleciona um item de um menu, quando um controle filho envia uma mensagem de notificação, ou quando um pressionamento de tecla de aceleração é traduzido. (Substitui [CWnd::OnCommand](../../mfc/reference/cwnd-class.md#oncommand).)|
|[CMFCDesktopAlertWnd::OnDraw](#ondraw)||
|[CMFCDesktopAlertWnd::ProcessCommand](#processcommand)||
|[CMFCDesktopAlertWnd::SetAnimationSpeed](#setanimationspeed)|Define a velocidade da animação nova.|
|[CMFCDesktopAlertWnd::SetAnimationType](#setanimationtype)|Define o tipo de animação.|
|[CMFCDesktopAlertWnd::SetAutoCloseTime](#setautoclosetime)|Define o tempo limite de fechamento automático.|
|[CMFCDesktopAlertWnd::SetSmallCaption](#setsmallcaption)|Alterna entre as legendas de pequenas e normais.|
|[CMFCDesktopAlertWnd::SetTransparency](#settransparency)|Define o nível de transparência.|

## <a name="remarks"></a>Comentários

Uma janela de alerta da área de trabalho pode ser transparente, ela pode aparecer com efeitos de animação e ele poderá desaparecer (após um atraso especificado ou quando o usuário descartá-lo clicando no botão Fechar).

Uma janela de alerta da área de trabalho também pode conter uma caixa de diálogo padrão que por sua vez, contém um ícone, o texto da mensagem (um rótulo) e um link. Como alternativa, uma janela de alerta da área de trabalho pode conter uma caixa de diálogo personalizada de recursos do aplicativo.

Você cria uma janela de alerta da área de trabalho em duas etapas. Primeiro, chame o construtor para construir o `CMFCDesktopAlertWnd` objeto. Em segundo lugar, chame o [CMFCDesktopAlertWnd::Create](#create) função de membro para criar a janela e anexá-lo para o `CMFCDesktopAlertWnd` objeto.

O `CMFCDesktopAlertWnd` objeto cria uma caixa de diálogo filho especiais que preenche a área de cliente da janela de alerta da área de trabalho. A caixa de diálogo é responsável por todos os controles são posicionados nele.

Para exibir uma caixa de diálogo na janela pop-up, siga estas etapas:

1. Derive uma classe de `CMFCDesktopAlertDialog`.

1. Crie um modelo de caixa de diálogo filho nos recursos.

1. Chame [CMFCDesktopAlertWnd::Create](#create) usando a ID do recurso de modelo de caixa de diálogo e um ponteiro para as informações de classe de tempo de execução da classe derivada.

1. A caixa de diálogo personalizada para lidar com todas as notificações provenientes os controles hospedados de programa ou programar os controles hospedados para lidar com essas notificações diretamente.

Use as seguintes funções para controlar o comportamento da janela de alerta da área de trabalho:

- Definir o tipo de animação chamando [CMFCDesktopAlertWnd::SetAnimationType](#setanimationtype). As opções válidas incluem Desdobrar, deslize e desaparecer.

- Definir a velocidade de quadro de animação chamando [CMFCDesktopAlertWnd::SetAnimationSpeed](#setanimationspeed).

- Definir o nível de transparência chamando [CMFCDesktopAlertWnd::SetTransparency](#settransparency).

- Alterar o tamanho da legenda para pequeno chamando [CMFCDesktopAlertWnd::SetSmallCaption](#setsmallcaption). Legenda curta é 7 pixels de altura.

## <a name="example"></a>Exemplo

O exemplo a seguir ilustra como usar vários métodos na `CMFCDesktopAlertWnd` classe para configurar um `CMFCDesktopAlertWnd` objeto. O exemplo mostra como definir um tipo de animação, definir a transparência da janela pop-up, especifique que a janela de alerta exibe uma legenda curta e definir o tempo decorrido antes que a janela de alerta é fechado automaticamente. O exemplo também demonstra como criar e inicializar a janela de alerta da área de trabalho. Este trecho de código faz parte do [amostra de demonstração de alerta da área de trabalho](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DesktopAlertDemo#1](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwnd-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDesktopAlertWnd.h

##  <a name="create"></a>  CMFCDesktopAlertWnd::Create

Cria e inicializa a janela de alerta da área de trabalho.

```
virtual BOOL Create(
    CWnd* pWndOwner,
    UINT uiDlgResID,
    HMENU hMenu = NULL,
    CPoint ptPos = CPoint(-1,-1),
    CRuntimeClass* pRTIDlgBar = RUNTIME_CLASS(CMFCDesktopAlertDialog));

virtual BOOL Create(
    CWnd* pWndOwner,
    CMFCDesktopAlertWndInfo& params,
    HMENU hMenu = NULL,
    CPoint ptPos = CPoint(-1,-1));
```

### <a name="parameters"></a>Parâmetros

*pWndOwner*<br/>
[no, out] Especifica o proprietário da janela de alerta. O proprietário receberá todas as notificações para a janela de alerta da área de trabalho. Esse valor não pode ser NULL.

*uiDlgResID*<br/>
[in] Especifica a ID do recurso da janela de alerta.

*hMenu*<br/>
[in] Especifica o menu que é exibido quando o usuário clica no botão de menu. Se for NULL, o botão de menu não é exibido.

*ptPos*<br/>
[in] Especifica a posição inicial em que a janela de alerta é exibida, usando coordenadas da tela. Se esse parâmetro for (-1, -1), a janela de alerta é exibida no canto inferior direito da tela.

*pRTIDlgBar*<br/>
[in] Informações de classe de tempo de execução para uma classe de caixa de diálogo personalizada que abrange a área de cliente da janela de alerta.

*params*<br/>
[in] Especifica os parâmetros que são usados para criar uma janela de alerta.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se a janela de alerta foi criada com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame esse método para criar uma janela de alerta. A área de cliente da janela de alerta contém uma caixa de diálogo filho que hospeda todos os controles que são exibidos ao usuário.

A primeira sobrecarga do método cria uma janela de alerta que contém uma caixa de diálogo filho que é carregada de recursos do aplicativo. A primeira sobrecarga do método também pode especificar informações de classe de tempo de execução para uma classe de caixa de diálogo personalizadas.

A segunda sobrecarga do método cria uma janela de alerta que contém controles padrão. Você pode especificar os controles para exibir, modificando o [classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md).

##  <a name="getanimationspeed"></a>  CMFCDesktopAlertWnd::GetAnimationSpeed

Retorna a velocidade da animação.

```
UINT GetAnimationSpeed() const;
```

### <a name="return-value"></a>Valor de retorno

A velocidade da animação da janela de alerta, em milissegundos.

### <a name="remarks"></a>Comentários

A velocidade da animação descreve quão rápido a janela de alerta abre e fecha.

##  <a name="getanimationtype"></a>  CMFCDesktopAlertWnd::GetAnimationType

Retorna o tipo de animação.

```
CMFCPopupMenu::ANIMATION_TYPE GetAnimationType();
```

### <a name="return-value"></a>Valor de retorno

Um dos seguintes tipos de animação:

- NO_ANIMATION

- DESDOBRAR

- SLIDE

- ESMAECIMENTO

- SYSTEM_DEFAULT_ANIMATION

##  <a name="getautoclosetime"></a>  CMFCDesktopAlertWnd::GetAutoCloseTime

Retorna o tempo limite de fechamento automático.

```
int GetAutoCloseTime() const;
```

### <a name="return-value"></a>Valor de retorno

O tempo, em milissegundos, após o qual a janela de alerta será fechada automaticamente.

### <a name="remarks"></a>Comentários

Use esse método para determinar quanto tempo deve decorrer antes da janela de alerta será fechada automaticamente.

##  <a name="getcaptionheight"></a>  CMFCDesktopAlertWnd::GetCaptionHeight

Retorna a altura da legenda.

```
virtual int GetCaptionHeight();
```

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, da legenda.

### <a name="remarks"></a>Comentários

Esse método pode ser substituído em uma classe derivada. A implementação padrão de qualquer um dos: retorna o valor de altura de legenda curta (7 pixels) se a janela pop-up deve exibir a legenda curta ou o valor obtido da função de API do Windows `GetSystemMetrics(SM_CYSMCAPTION)`.

##  <a name="getlastpos"></a>  CMFCDesktopAlertWnd::GetLastPos

Retorna a última posição da janela de alerta da área de trabalho na tela.

```
CPoint GetLastPos() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponto em coordenadas da tela.

### <a name="remarks"></a>Comentários

Esse método retorna a última posição válida da janela de alerta na tela.

##  <a name="gettransparency"></a>  CMFCDesktopAlertWnd::GetTransparency

Retorna o nível de transparência.

```
BYTE GetTransparency() const;
```

### <a name="return-value"></a>Valor de retorno

Um nível de transparência entre 0 e 255, inclusive. Quanto maior o valor, o mais opaco a janela.

### <a name="remarks"></a>Comentários

Use esse método para recuperar o atual nível de transparência da janela de alerta.

##  <a name="hassmallcaption"></a>  CMFCDesktopAlertWnd::HasSmallCaption

Determina se a janela de alerta da área de trabalho tem uma legenda curta ou uma legenda de tamanho regular.

```
BOOL HasSmallCaption() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a janela pop-up é exibida com uma legenda curta; FALSE se a janela pop-up é exibida com uma legenda de tamanho regular.

### <a name="remarks"></a>Comentários

Use esse método para determinar se a janela pop-up tem uma legenda curta ou uma legenda de tamanho regular. Por padrão, a legenda curta é 7 pixels de altura. Você pode obter a altura da legenda do tamanho regular chamando a função de API do Windows `GetSystemMetrics(SM_CYCAPTION)`.

##  <a name="onbeforeshow"></a>  CMFCDesktopAlertWnd::OnBeforeShow

```
virtual BOOL OnBeforeShow(CPoint&);
```

### <a name="parameters"></a>Parâmetros

[in] *CPoint &*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onclicklinkbutton"></a>  CMFCDesktopAlertWnd::OnClickLinkButton

Chamado pelo framework quando o usuário clica em um botão de link localizado no menu de alerta da área de trabalho.

```
virtual BOOL OnClickLinkButton(UINT uiCmdID);
```

### <a name="parameters"></a>Parâmetros

*uiCmdID*<br/>
[in] Esse parâmetro não é usado.

### <a name="return-value"></a>Valor de retorno

Sempre FALSE.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada se você quiser ser notificado quando um usuário clica no link na janela de alerta.

##  <a name="oncommand"></a>  CMFCDesktopAlertWnd::OnCommand

```
virtual BOOL OnCommand(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

[in] *wParam*<br/>

[in] *lParam*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ondraw"></a>  CMFCDesktopAlertWnd::OnDraw

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="remarks"></a>Comentários

##  <a name="processcommand"></a>  CMFCDesktopAlertWnd::ProcessCommand

```
BOOL ProcessCommand(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

[in] *hwnd*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="setanimationspeed"></a>  CMFCDesktopAlertWnd::SetAnimationSpeed

Define a velocidade da animação nova.

```
void SetAnimationSpeed(UINT nSpeed);
```

### <a name="parameters"></a>Parâmetros

*nSpeed*<br/>
[in] Especifica a velocidade da animação nova, em milissegundos.

### <a name="remarks"></a>Comentários

Chame esse método para definir a velocidade da animação para a janela de alerta. A velocidade da animação padrão é 30 milissegundos.

##  <a name="setanimationtype"></a>  CMFCDesktopAlertWnd::SetAnimationType

Define o tipo de animação.

```
void SetAnimationType(CMFCPopupMenu::ANIMATION_TYPE type);
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
[in] Especifica o tipo de animação.

### <a name="remarks"></a>Comentários

Chame esse método para definir o tipo de animação. É possível especificar um dos seguintes valores:

- NO_ANIMATION

- DESDOBRAR

- SLIDE

- ESMAECIMENTO

- SYSTEM_DEFAULT_ANIMATION

##  <a name="setautoclosetime"></a>  CMFCDesktopAlertWnd::SetAutoCloseTime

Define o tempo limite de fechamento automático.

```
void SetAutoCloseTime(int nTime);
```

### <a name="parameters"></a>Parâmetros

*nTime*<br/>
[in] O tempo, em milissegundos, decorrido antes que a janela de alerta é fechado automaticamente.

### <a name="remarks"></a>Comentários

A janela de alerta é fechada automaticamente após o tempo especificado se o usuário interage com a janela.

##  <a name="setsmallcaption"></a>  CMFCDesktopAlertWnd::SetSmallCaption

Alterna entre as legendas de pequenas e de tamanho regular.

```
void SetSmallCaption(BOOL bSmallCaption = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSmallCaption*<br/>
[in] TRUE para especificar que a janela de alerta exibe uma legenda curta; Caso contrário, FALSE para especificar que a janela de alerta exibe uma legenda de tamanho regular.

### <a name="remarks"></a>Comentários

Chame esse método para exibir a legenda pequena ou de tamanho regular. Por padrão, a legenda curta é 7 pixels de altura. Você pode obter o tamanho da legenda regular chamando a função de API do Windows `GetSystemMetrics(SM_CYCAPTION)`.

##  <a name="settransparency"></a>  CMFCDesktopAlertWnd::SetTransparency

Define o nível de transparência da janela pop-up.

```
void SetTransparency(BYTE nTransparency);
```

### <a name="parameters"></a>Parâmetros

*nTransparency*<br/>
[in] Especifica o nível de transparência. Esse valor deve estar entre 0 e 255, inclusive. Quanto maior o valor, o mais opaco a janela.

### <a name="remarks"></a>Comentários

Chame essa função para definir o nível de transparência da janela pop-up.

##  <a name="getdialogsize"></a>  CMFCDesktopAlertWnd::GetDialogSize

```
virtual CSize GetDialogSize();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)<br/>
[Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)

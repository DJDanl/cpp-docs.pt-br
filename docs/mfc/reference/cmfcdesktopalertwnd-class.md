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
ms.openlocfilehash: f9c59258cf757b5468985a954640ccec1543512b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367643"
---
# <a name="cmfcdesktopalertwnd-class"></a>Classe CMFCDesktopAlertWnd

A `CMFCDesktopAlertWnd` classe implementa a funcionalidade de uma caixa de diálogo modeless que aparece na tela para informar o usuário sobre um evento.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCDesktopAlertWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDesktopAlertWnd::Criar](#create)|Cria e inicializa a janela de alerta da área de trabalho.|
|[CMFCDesktopAlertWnd::GetAnimationSpeed](#getanimationspeed)|Retorna a velocidade da animação.|
|[CMFCDesktopAlertWnd:GetAnimationType](#getanimationtype)|Retorna o tipo de animação.|
|[CMFCDesktopAlertWnd::GetAutoCloseTime](#getautoclosetime)|Retorna o tempo de fechamento automático.|
|[CMFCDesktopAlertWnd::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda.|
|[CMFCDesktopAlertWnd::GetDialogSize](#getdialogsize)||
|[CMFCDesktopAlertWnd::GetLastPos](#getlastpos)|Retorna a última posição válida da janela de alerta da área de trabalho na tela.|
|[CMFCDesktopAlertWnd::GetTransparency](#gettransparency)|Retorna o nível de transparência.|
|[CMFCDesktopAlertWnd::HasSmallCaption](#hassmallcaption)|Determina se a janela de alerta da área de trabalho é exibida com a pequena legenda.|
|[CMFCDesktopAlertWnd::OnBeforeShow](#onbeforeshow)||
|[CMFCDesktopAlertWnd:OnClickLinkButton](#onclicklinkbutton)|Chamado pela estrutura quando o usuário clica em um botão de link localizado no menu de alerta da área de trabalho.|
|[CMFCDesktopAlertWnd::OnCommand](#oncommand)|A estrutura chama essa função de membro quando o usuário seleciona um item de um menu, quando um controle de criança envia uma mensagem de notificação ou quando uma tecla do acelerador é traduzida. (Substitui [cwnd::OnCommand](../../mfc/reference/cwnd-class.md#oncommand).)|
|[CMFCDesktopAlertWnd::OnDraw](#ondraw)||
|[CMFCDesktopAlertWnd::ProcessCommand](#processcommand)||
|[CMFCDesktopAlertWnd::SetAnimationSpeed](#setanimationspeed)|Define a nova velocidade de animação.|
|[CMFCDesktopAlertWnd::SetAnimationType](#setanimationtype)|Define o tipo de animação.|
|[CMFCDesktopAlertWnd::SetAutoCloseTime](#setautoclosetime)|Define o tempo de fechamento automático.|
|[CMFCDesktopAlertWnd::SetSmallCaption](#setsmallcaption)|Alterna entre legendas pequenas e normais.|
|[CMFCDesktopAlertWnd::SetTransparência](#settransparency)|Define o nível de transparência.|

## <a name="remarks"></a>Comentários

Uma janela de alerta de desktop pode ser transparente, pode aparecer com efeitos de animação e pode desaparecer (após um atraso especificado ou quando o usuário a descarta clicando no botão de fechamento).

Uma janela de alerta de área de trabalho também pode conter uma caixa de diálogo padrão que, por sua vez, contém um ícone, um texto de mensagem (um rótulo) e um link. Alternativamente, uma janela de alerta de desktop pode conter uma caixa de diálogo personalizada dos recursos do aplicativo.

Você cria uma janela de alerta de desktop em dois passos. Primeiro, chame o construtor `CMFCDesktopAlertWnd` para construir o objeto. Em segundo lugar, chame o [CMFCDesktopAlertWnd::Crie](#create) a função `CMFCDesktopAlertWnd` de membro para criar a janela e anexá-la ao objeto.

O `CMFCDesktopAlertWnd` objeto cria uma caixa de diálogo filho especial que preenche a área cliente da janela de alerta da área de trabalho. O diálogo possui todos os controles que estão posicionados sobre ele.

Para exibir uma caixa de diálogo personalizada na janela popup, siga estas etapas:

1. Derivar uma `CMFCDesktopAlertDialog`classe de .

1. Crie um modelo de caixa de diálogo filho nos recursos.

1. Chamada [CMFCDesktopAlertWnd::Crie](#create) usando o ID de recurso do modelo da caixa de diálogo e um ponteiro para as informações da classe de tempo de execução da classe derivada.

1. Programe a caixa de diálogo personalizada para lidar com todas as notificações provenientes dos controles hospedados ou programe os controles hospedados para lidar diretamente com essas notificações.

Use as seguintes funções para controlar o comportamento da janela de alerta da área de trabalho:

- Defina o tipo de animação chamando [CMFCDesktopAlertWnd::SetAnimationType](#setanimationtype). As opções válidas incluem desdobrar, deslizar e desaparecer.

- Defina a velocidade do quadro de animação chamando [CMFCDesktopAlertWnd::SetAnimationSpeed](#setanimationspeed).

- Defina o nível de transparência chamando [CMFCDesktopAlertWnd::SetTransparency](#settransparency).

- Altere o tamanho da legenda para pequeno, chamando [CMFCDesktopAlertWnd::SetSmallCaption](#setsmallcaption). A pequena legenda tem 7 pixels de altura.

## <a name="example"></a>Exemplo

O exemplo a seguir ilustra como usar `CMFCDesktopAlertWnd` vários métodos `CMFCDesktopAlertWnd` na classe para configurar um objeto. O exemplo mostra como definir um tipo de animação, definir a transparência da janela pop-up, especificar que a janela de alerta exibe uma pequena legenda e definir o tempo que se desenrola antes que a janela de alerta feche automaticamente. O exemplo também demonstra como criar e inicializar a janela de alerta da área de trabalho. Este trecho de código faz parte da [amostra de demonstração de alerta de área de trabalho](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DesktopAlertDemo#1](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwnd-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cmfcdesktopalertwnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDesktopAlertWnd.h

## <a name="cmfcdesktopalertwndcreate"></a><a name="create"></a>CMFCDesktopAlertWnd::Criar

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
[dentro, fora] Especifica o proprietário da janela de alerta. Esse proprietário receberá todas as notificações para a janela de alerta da área de trabalho. Este valor não pode ser NULO.

*uiDlgResID*<br/>
[em] Especifica o ID de recurso da janela de alerta.

*Hmenu*<br/>
[em] Especifica o menu que é exibido quando o usuário clica no botão menu. Se NULO, o botão de menu não será exibido.

*ptPos*<br/>
[em] Especifica a posição inicial onde a janela de alerta é exibida, usando coordenadas de tela. Se este parâmetro for (-1, -1), a janela de alerta será exibida no canto inferior direito da tela.

*pRTIDlgBar*<br/>
[em] Informações da classe runtime para uma classe de caixa de diálogo personalizada que cobre a área cliente da janela de alerta.

*params*<br/>
[em] Especifica parâmetros usados para criar uma janela de alerta.

### <a name="return-value"></a>Valor retornado

TRUE se a janela de alerta foi criada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame este método para criar uma janela de alerta. A área cliente da janela de alerta contém uma caixa de diálogo filho que hospeda todos os controles exibidos ao usuário.

A primeira sobrecarga de método cria uma janela de alerta que contém uma caixa de diálogo filho que é carregada a partir dos recursos do aplicativo. A primeira sobrecarga de método também pode especificar informações de classe de tempo de execução para uma classe de caixa de diálogo personalizada.

A segunda sobrecarga do método cria uma janela de alerta que contém controles padrão. Você pode especificar quais controles exibir modificando a [classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md).

## <a name="cmfcdesktopalertwndgetanimationspeed"></a><a name="getanimationspeed"></a>CMFCDesktopAlertWnd::GetAnimationSpeed

Retorna a velocidade da animação.

```
UINT GetAnimationSpeed() const;
```

### <a name="return-value"></a>Valor retornado

A velocidade de animação da janela de alerta, em milissegundos.

### <a name="remarks"></a>Comentários

A velocidade de animação descreve a rapidez com que a janela de alerta abre e fecha.

## <a name="cmfcdesktopalertwndgetanimationtype"></a><a name="getanimationtype"></a>CMFCDesktopAlertWnd:GetAnimationType

Retorna o tipo de animação.

```
CMFCPopupMenu::ANIMATION_TYPE GetAnimationType();
```

### <a name="return-value"></a>Valor retornado

Um dos seguintes tipos de animação:

- NO_ANIMATION

- Desdobrar

- Slide

- Desaparecer

- SYSTEM_DEFAULT_ANIMATION

## <a name="cmfcdesktopalertwndgetautoclosetime"></a><a name="getautoclosetime"></a>CMFCDesktopAlertWnd::GetAutoCloseTime

Retorna o tempo de fechamento automático.

```
int GetAutoCloseTime() const;
```

### <a name="return-value"></a>Valor retornado

O tempo, em milissegundos, após o qual a janela de alerta será automaticamente fechada.

### <a name="remarks"></a>Comentários

Use este método para determinar quanto tempo deve passar antes que a janela de alerta feche automaticamente.

## <a name="cmfcdesktopalertwndgetcaptionheight"></a><a name="getcaptionheight"></a>CMFCDesktopAlertWnd::GetCaptionHeight

Retorna a altura da legenda.

```
virtual int GetCaptionHeight();
```

### <a name="return-value"></a>Valor retornado

A altura, em pixels, da legenda.

### <a name="remarks"></a>Comentários

Este método pode ser substituído em uma classe derivada. A implementação padrão quer: retorna o valor de altura da pequena legenda (7 pixels) se a janela `GetSystemMetrics(SM_CYSMCAPTION)`pop-up deve exibir a pequena legenda ou o valor obtido na função API do Windows .

## <a name="cmfcdesktopalertwndgetlastpos"></a><a name="getlastpos"></a>CMFCDesktopAlertWnd::GetLastPos

Retorna a última posição da janela de alerta da área de trabalho na tela.

```
CPoint GetLastPos() const;
```

### <a name="return-value"></a>Valor retornado

Um ponto, nas coordenadas da tela.

### <a name="remarks"></a>Comentários

Este método retorna a última posição válida da janela de alerta na tela.

## <a name="cmfcdesktopalertwndgettransparency"></a><a name="gettransparency"></a>CMFCDesktopAlertWnd::GetTransparency

Retorna o nível de transparência.

```
BYTE GetTransparency() const;
```

### <a name="return-value"></a>Valor retornado

Um nível de transparência entre 0 e 255, inclusive. Quanto maior o valor, mais opaca a janela.

### <a name="remarks"></a>Comentários

Use este método para recuperar o nível de transparência atual da janela de alerta.

## <a name="cmfcdesktopalertwndhassmallcaption"></a><a name="hassmallcaption"></a>CMFCDesktopAlertWnd::HasSmallCaption

Determina se a janela de alerta da área de trabalho tem uma pequena legenda ou uma legenda de tamanho normal.

```
BOOL HasSmallCaption() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a janela pop-up for exibida com uma pequena legenda; FALSO se a janela pop-up for exibida com uma legenda de tamanho regular.

### <a name="remarks"></a>Comentários

Use este método para determinar se a janela pop-up tem uma pequena legenda ou uma legenda de tamanho normal. Por padrão, a pequena legenda tem 7 pixels de altura. Você pode obter a altura da legenda de tamanho `GetSystemMetrics(SM_CYCAPTION)`normal chamando a função API do Windows .

## <a name="cmfcdesktopalertwndonbeforeshow"></a><a name="onbeforeshow"></a>CMFCDesktopAlertWnd::OnBeforeShow

```
virtual BOOL OnBeforeShow(CPoint&);
```

### <a name="parameters"></a>Parâmetros

[em] *CPoint&*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndonclicklinkbutton"></a><a name="onclicklinkbutton"></a>CMFCDesktopAlertWnd:OnClickLinkButton

Chamado pela estrutura quando o usuário clica em um botão de link localizado no menu de alerta da área de trabalho.

```
virtual BOOL OnClickLinkButton(UINT uiCmdID);
```

### <a name="parameters"></a>Parâmetros

*uiCmdID*<br/>
[em] Este parâmetro não é usado.

### <a name="return-value"></a>Valor retornado

Sempre FALSE.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada se você quiser ser notificado quando um usuário clicar no link na janela de alerta.

## <a name="cmfcdesktopalertwndoncommand"></a><a name="oncommand"></a>CMFCDesktopAlertWnd::OnCommand

```
virtual BOOL OnCommand(
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

[em] *wParam*<br/>

[em] *IParam*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndondraw"></a><a name="ondraw"></a>CMFCDesktopAlertWnd::OnDraw

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndprocesscommand"></a><a name="processcommand"></a>CMFCDesktopAlertWnd::ProcessCommand

```
BOOL ProcessCommand(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

[em] *hwnd*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcdesktopalertwndsetanimationspeed"></a><a name="setanimationspeed"></a>CMFCDesktopAlertWnd::SetAnimationSpeed

Define a nova velocidade de animação.

```
void SetAnimationSpeed(UINT nSpeed);
```

### <a name="parameters"></a>Parâmetros

*nVelocidade*<br/>
[em] Especifica a nova velocidade de animação, em milissegundos.

### <a name="remarks"></a>Comentários

Chame este método para definir a velocidade de animação para a janela de alerta. A velocidade de animação padrão é de 30 milissegundos.

## <a name="cmfcdesktopalertwndsetanimationtype"></a><a name="setanimationtype"></a>CMFCDesktopAlertWnd::SetAnimationType

Define o tipo de animação.

```
void SetAnimationType(CMFCPopupMenu::ANIMATION_TYPE type);
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
[em] Especifica o tipo de animação.

### <a name="remarks"></a>Comentários

Chame este método para definir o tipo de animação. É possível especificar um dos seguintes valores:

- NO_ANIMATION

- Desdobrar

- Slide

- Desaparecer

- SYSTEM_DEFAULT_ANIMATION

## <a name="cmfcdesktopalertwndsetautoclosetime"></a><a name="setautoclosetime"></a>CMFCDesktopAlertWnd::SetAutoCloseTime

Define o tempo de fechamento automático.

```
void SetAutoCloseTime(int nTime);
```

### <a name="parameters"></a>Parâmetros

*Ntime*<br/>
[em] A hora, em milissegundos, que se desenrola antes que a janela de alerta feche automaticamente.

### <a name="remarks"></a>Comentários

A janela de alerta é automaticamente fechada após o tempo especificado se o usuário não interagir com a janela.

## <a name="cmfcdesktopalertwndsetsmallcaption"></a><a name="setsmallcaption"></a>CMFCDesktopAlertWnd::SetSmallCaption

Alterna entre legendas pequenas e de tamanho normal.

```
void SetSmallCaption(BOOL bSmallCaption = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSmallCaption*<br/>
[em] TRUE para especificar que a janela de alerta exibe uma pequena legenda; caso contrário, FALSE para especificar que a janela de alerta exibe uma legenda de tamanho regular.

### <a name="remarks"></a>Comentários

Chame este método para exibir a legenda de tamanho pequeno ou regular. Por padrão, a pequena legenda tem 7 pixels de altura. Você pode obter o tamanho da legenda regular `GetSystemMetrics(SM_CYCAPTION)`chamando a função API do Windows .

## <a name="cmfcdesktopalertwndsettransparency"></a><a name="settransparency"></a>CMFCDesktopAlertWnd::SetTransparência

Define o nível de transparência da janela popup.

```
void SetTransparency(BYTE nTransparency);
```

### <a name="parameters"></a>Parâmetros

*nTransparência*<br/>
[em] Especifica o nível de transparência. Este valor deve ser entre 0 e 255, inclusive. Quanto maior o valor, mais opaca a janela.

### <a name="remarks"></a>Comentários

Chame esta função para definir o nível de transparência da janela popup.

## <a name="cmfcdesktopalertwndgetdialogsize"></a><a name="getdialogsize"></a>CMFCDesktopAlertWnd::GetDialogSize

```
virtual CSize GetDialogSize();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)<br/>
[Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)

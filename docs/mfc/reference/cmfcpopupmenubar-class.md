---
title: Classe CMFCPopupMenuBar
ms.date: 11/04/2016
f1_keywords:
- CMFCPopupMenuBar
- AFXPOPUPMENUBAR/CMFCPopupMenuBar
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::AdjustSizeImmediate
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::BuildOrigItems
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::CloseDelayedSubMenu
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::ExportToMenu
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::FindDestintationToolBar
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::GetCurrentMenuImageSize
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::GetDefaultMenuId
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::GetLastCommandIndex
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::GetOffset
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::ImportFromMenu
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::IsDropDownListMode
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::IsPaletteMode
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::IsRibbonPanel
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::IsRibbonPanelInRegularMode
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::LoadFromHash
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::RestoreDelayedSubMenu
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::SetButtonStyle
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::SetOffset
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::StartPopupMenuTimer
- AFXPOPUPMENUBAR/CMFCPopupMenuBar::m_bDisableSideBarInXPMode
helpviewer_keywords:
- CMFCPopupMenuBar [MFC], AdjustSizeImmediate
- CMFCPopupMenuBar [MFC], BuildOrigItems
- CMFCPopupMenuBar [MFC], CloseDelayedSubMenu
- CMFCPopupMenuBar [MFC], ExportToMenu
- CMFCPopupMenuBar [MFC], FindDestintationToolBar
- CMFCPopupMenuBar [MFC], GetCurrentMenuImageSize
- CMFCPopupMenuBar [MFC], GetDefaultMenuId
- CMFCPopupMenuBar [MFC], GetLastCommandIndex
- CMFCPopupMenuBar [MFC], GetOffset
- CMFCPopupMenuBar [MFC], ImportFromMenu
- CMFCPopupMenuBar [MFC], IsDropDownListMode
- CMFCPopupMenuBar [MFC], IsPaletteMode
- CMFCPopupMenuBar [MFC], IsRibbonPanel
- CMFCPopupMenuBar [MFC], IsRibbonPanelInRegularMode
- CMFCPopupMenuBar [MFC], LoadFromHash
- CMFCPopupMenuBar [MFC], RestoreDelayedSubMenu
- CMFCPopupMenuBar [MFC], SetButtonStyle
- CMFCPopupMenuBar [MFC], SetOffset
- CMFCPopupMenuBar [MFC], StartPopupMenuTimer
- CMFCPopupMenuBar [MFC], m_bDisableSideBarInXPMode
ms.assetid: 4c93c459-7f70-4240-8c63-280bb811e374
ms.openlocfilehash: c0ba90246d19e8dd07c856eec6a518a8513ee665
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751926"
---
# <a name="cmfcpopupmenubar-class"></a>Classe CMFCPopupMenuBar

Uma barra de menu embutida em um menu pop-up.

## <a name="syntax"></a>Sintaxe

```
class CMFCPopupMenuBar : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPopupMenubar::Ajustartamanhoimediato](#adjustsizeimmediate)|Recalcula imediatamente o layout de um painel. (Substitui [cpane::adjustSizeImmediate](../../mfc/reference/cpane-class.md#adjustsizeimmediate).)|
|[CMFCPopupMenuBar::BuildOrigItems](#buildorigitems)|Carrega itens do menu pop-up a partir de um recurso de menu especificado.|
|[CMFCPopupMenuBar::FechamentoDesatrasadoMenuSubmenu](#closedelayedsubmenu)|Fecha um botão de menu pop-up atrasado.|
|[CMFCPopupMenuBar::ExportToMenu](#exporttomenu)|Constrói um menu a partir dos botões popup-menu.|
|[CMFCPopupMenuBar::FindDestintationToolBar](#finddestintationtoolbar)|Localiza a barra de ferramentas onde está um ponto especificado.|
|[CMFCPopupMenuBar::GetCurrentMenuImageSize](#getcurrentmenuimagesize)|Indica o tamanho das imagens do botão de menu.|
|[CMFCPopupMenubar::GetDefaultMenuId](#getdefaultmenuid)|Retorna o identificador do item de menu padrão.|
|[CMFCPopupMenuBar::GetLastCommandIndex](#getlastcommandindex)|Obtém o índice do comando menu mais recentemente invocado.|
|[CMFCPopupMenubar::GetOffset](#getoffset)|Obtém o deslocamento de linha da barra de menu popup.|
|[CMFCPopupMenuBar::ImportarMenuDeSícelo](#importfrommenu)|Importa botões do menu pop-up de um menu especificado.|
|[CMFCPopupMenuBar::IsDropDownListaMode](#isdropdownlistmode)|Indica se a barra de menu pop-up está no modo lista suspenso.|
|[CMFCPopupMenuBar::IsPaletteMode](#ispalettemode)|Indica se a barra de menu pop-up está no modo paleta.|
|[CMFCPopupMenubar::IsRibbonPanel](#isribbonpanel)|Indica se este é um painel de fita (FALSE por padrão).|
|[CMFCPopupMenuBar::IsRibbonPanelInRegularMode](#isribbonpanelinregularmode)|Indica se este é um painel de fita no modo regular (FALSE por padrão).|
|[CMFCPopupMenubar::LoadFromHash](#loadfromhash)|Carrega um menu arquivado.|
|[CMFCPopupMenuBar::RestaurarDesofinalMenu](#restoredelayedsubmenu)|Restaura um botão de menu atrasado para fechar a barra de menu pop-up.|
|[CMFCPopupMenuBar::SetButtonStyle](#setbuttonstyle)|Define o estilo do botão da barra de ferramentas no índice dado. (Substitui [cmfctoolbar::SetButtonStyle](../../mfc/reference/cmfctoolbar-class.md#setbuttonstyle).)|
|[CMFCPopupMenuBar::SetOffset](#setoffset)|Define o deslocamento de linha da barra de menu popup.|
|[CMFCPopupMenuBar::StartPopupMenuTimer](#startpopupmenutimer)|Inicia o temporizador para um botão de menu popup atrasado especificado.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCPopupMenubar::m_bDisableSideBarInXPMode](#m_bdisablesidebarinxpmode)|Especifica se a barra lateral cinza será exibida quando o aplicativo tiver uma aparência do Windows XP.|

## <a name="remarks"></a>Comentários

O `CMFCPopupMenuBar` é criado ao mesmo tempo que uma [classe CMFCPopupMenu e](../../mfc/reference/cmfcpopupmenu-class.md) incorporado dentro dele. O `CMFCPopupMenuBar` cobre toda a `CMFCPopupMenu` área do cliente do objeto. Ele suporta entrada de teclado e mouse. Ele também comunica essa `CMFCPopupMenu` entrada para a janela de quadro de nível superior.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra `CMFCPopupMenuBar` como `CMFCPopupMenu` inicializar um objeto a partir de um objeto. Este trecho de código faz parte da [amostra Draw Client](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#7](../../mfc/reference/codesnippet/cpp/cmfcpopupmenubar-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[Cmfctoolbar](../../mfc/reference/cmfctoolbar-class.md)

[Cmfcpopupmenubar](../../mfc/reference/cmfcpopupmenubar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpopupmenubar.h

## <a name="cmfcpopupmenubaradjustsizeimmediate"></a><a name="adjustsizeimmediate"></a>CMFCPopupMenubar::Ajustartamanhoimediato

Recalcula imediatamente o layout do painel da barra de menu popup. (Substitui [cpane::AdjustSizeImmediate](../../mfc/reference/cpane-class.md#adjustsizeimmediate).

```
virtual void AdjustSizeImmediate(BOOL bRecalcLayout);
```

### <a name="parameters"></a>Parâmetros

*bRecalcLayout*<br/>
[em] TRUE para recalcular automaticamente o layout do painel da barra de menu popup; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarbuildorigitems"></a><a name="buildorigitems"></a>CMFCPopupMenuBar::BuildOrigItems

Carrega itens do menu pop-up a partir de um recurso de menu especificado.

```
BOOL BuildOrigItems(UINT uiMenuResID);
```

### <a name="parameters"></a>Parâmetros

*uiMenuResID*<br/>
[em] Especifica o ID do menu do recurso do menu a ser carregado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido ou FALSO se não for.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarclosedelayedsubmenu"></a><a name="closedelayedsubmenu"></a>CMFCPopupMenuBar::FechamentoDesatrasadoMenuSubmenu

Fecha um botão de menu pop-up que foi atrasado.

```
virtual void CloseDelayedSubMenu();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarexporttomenu"></a><a name="exporttomenu"></a>CMFCPopupMenuBar::ExportToMenu

Constrói um menu a partir dos botões do menu popup.

```
virtual HMENU ExportToMenu() const;
```

### <a name="return-value"></a>Valor retornado

Retorna uma alça para o novo menu.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarfinddestintationtoolbar"></a><a name="finddestintationtoolbar"></a>CMFCPopupMenuBar::FindDestintationToolBar

Localiza a barra de ferramentas onde está um ponto especificado.

```
CMFCToolBar* FindDestintationToolBar(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] Um ponto na tela.

### <a name="return-value"></a>Valor retornado

Retorna uma alça para a barra de ferramentas onde o ponto está, se houver um, ou NULO, se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubargetcurrentmenuimagesize"></a><a name="getcurrentmenuimagesize"></a>CMFCPopupMenuBar::GetCurrentMenuImageSize

Indica o tamanho das imagens do botão de menu.

```
virtual CSize GetCurrentMenuImageSize() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o tamanho das imagens do botão de menu na barra de ferramentas.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubargetdefaultmenuid"></a><a name="getdefaultmenuid"></a>CMFCPopupMenubar::GetDefaultMenuId

Retorna o identificador do item de menu padrão.

```
UINT GetDefaultMenuId() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o identificador do item de menu padrão na barra de menu popup.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubargetlastcommandindex"></a><a name="getlastcommandindex"></a>CMFCPopupMenuBar::GetLastCommandIndex

Obtém o índice do comando menu mais recentemente invocado.

```
static int __stdcall GetLastCommandIndex();
```

### <a name="return-value"></a>Valor retornado

Retorna o índice do último comando de menu que foi invocado.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubargetoffset"></a><a name="getoffset"></a>CMFCPopupMenubar::GetOffset

Obtém o deslocamento de linha da barra de menu popup.

```
int GetOffset() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o deslocamento de linha da barra de menu pop-up.

### <a name="remarks"></a>Comentários

Este valor está definido usando [CMFCPopupMenuBar:SetOffset](#setoffset).

## <a name="cmfcpopupmenubarimportfrommenu"></a><a name="importfrommenu"></a>CMFCPopupMenuBar::ImportarMenuDeSícelo

Importa botões do menu pop-up de um menu especificado.

```
virtual BOOL ImportFromMenu(
    HMENU hMenu,
    BOOL bShowAllCommands = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
[em] O menu a partir do qual importar os botões do menu popup.

*bShowAllCommands*<br/>
[em] TRUE se todos os comandos no menu forem importados, ou FALSO se os raramente utilizados puderem ser escondidos.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se os botões do menu foram importados com sucesso do menu ou FALSO, se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarisdropdownlistmode"></a><a name="isdropdownlistmode"></a>CMFCPopupMenuBar::IsDropDownListaMode

Indica se a barra de menu pop-up está no modo lista suspenso.

```
BOOL IsDropDownListMode() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a barra de menu pop-up estiver no modo lista suspenso ou FALSA se não for.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarispalettemode"></a><a name="ispalettemode"></a>CMFCPopupMenuBar::IsPaletteMode

Indica se a barra de menu pop-up está no modo paleta.

```
BOOL IsPaletteMode() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o modo paleta estiver ativado, ou FALSO se não.

### <a name="remarks"></a>Comentários

Quando a barra de menu é definida para o modo paleta, os itens do menu aparecem em várias colunas e um número limitado de linhas.

## <a name="cmfcpopupmenubarisribbonpanel"></a><a name="isribbonpanel"></a>CMFCPopupMenubar::IsRibbonPanel

Indica se este é um painel de fita (FALSE por padrão).

```
virtual BOOL IsRibbonPanel() const;
```

### <a name="return-value"></a>Valor retornado

Retorna FALSO por padrão, indicando que este não é um painel de fita.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarisribbonpanelinregularmode"></a><a name="isribbonpanelinregularmode"></a>CMFCPopupMenuBar::IsRibbonPanelInRegularMode

Indica se este é um painel de fita no modo regular (FALSE por padrão).

```
virtual BOOL IsRibbonPanelInRegularMode() const;
```

### <a name="return-value"></a>Valor retornado

Retorna FALSE por padrão, indicando que este não é um painel de fita no modo regular.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarloadfromhash"></a><a name="loadfromhash"></a>CMFCPopupMenubar::LoadFromHash

Carrega um menu arquivado.

```
BOOL LoadFromHash(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
[em] Uma alça para o menu arquivado para carregar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o menu estiver carregado com sucesso, ou FALSE se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarm_bdisablesidebarinxpmode"></a><a name="m_bdisablesidebarinxpmode"></a>CMFCPopupMenubar::m_bDisableSideBarInXPMode

Um parâmetro booleano que indica se seu aplicativo tem uma barra lateral cinza quando tem uma aparência do Windows XP.

```
BOOL m_bDisableSideBarInXPMode;
```

### <a name="remarks"></a>Comentários

Se esta variável de membro estiver definida como FALSE e seu aplicativo tiver uma aparência do Windows XP, a estrutura desenhará uma barra lateral cinza em seu aplicativo.

O valor padrão é FALSE.

## <a name="cmfcpopupmenubarrestoredelayedsubmenu"></a><a name="restoredelayedsubmenu"></a>CMFCPopupMenuBar::RestaurarDesofinalMenu

Restaura um botão de menu atrasado para fechar a barra de menu pop-up.

```
virtual void RestoreDelayedSubMenu();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarsetbuttonstyle"></a><a name="setbuttonstyle"></a>CMFCPopupMenuBar::SetButtonStyle

Define o estilo do botão da barra de ferramentas no índice dado. (Substitui [cmfctoolbar::SetButtonStyle](../../mfc/reference/cmfctoolbar-class.md#setbuttonstyle).)

```
virtual void SetButtonStyle(
    int nIndex,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] O índice baseado em zero do botão da barra de ferramentas cujo estilo deve ser definido.

*nStyle*<br/>
[em] O estilo do botão. Consulte [Os estilos de controle](../../mfc/reference/toolbar-control-styles.md) da barra de ferramentas para a lista dos estilos de botão disponíveis da barra de ferramentas.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarsetoffset"></a><a name="setoffset"></a>CMFCPopupMenuBar::SetOffset

Define o deslocamento de linha da barra de menu popup.

```cpp
void SetOffset(int iOffset);
```

### <a name="parameters"></a>Parâmetros

*iOffset*<br/>
[em] O número de linhas que a barra de menu popup deve ser compensado.

### <a name="remarks"></a>Comentários

## <a name="cmfcpopupmenubarstartpopupmenutimer"></a><a name="startpopupmenutimer"></a>CMFCPopupMenuBar::StartPopupMenuTimer

Inicia o temporizador para um botão de menu popup atrasado especificado.

```cpp
void StartPopupMenuTimer(
    CMFCToolBarMenuButton* pMenuButton,
    int nDelayFactor = 1);
```

### <a name="parameters"></a>Parâmetros

*pMenuButton*<br/>
[em] Pointer para o botão menu para que defina o temporizador de atraso.

*nDelayFactor*<br/>
[em] Um fator de atraso, igual a pelo menos um, para multiplicar pelo tempo de atraso do menu padrão (geralmente entre meio segundo e cinco segundos).

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)<br/>
[Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)

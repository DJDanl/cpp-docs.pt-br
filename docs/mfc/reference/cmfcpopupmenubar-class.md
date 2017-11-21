---
title: Classe CMFCPopupMenuBar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
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
caps.latest.revision: "32"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6be3c3b6028bab04ae3d8ec32f9063d26012778e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cmfcpopupmenubar-class"></a>Classe CMFCPopupMenuBar
Uma barra de menus incorporada em um menu pop-up.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPopupMenuBar : public CMFCToolBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPopupMenuBar::AdjustSizeImmediate](#adjustsizeimmediate)|Recalcula o layout de um painel imediatamente. (Substitui [CPane::AdjustSizeImmediate](../../mfc/reference/cpane-class.md#adjustsizeimmediate).)|  
|[CMFCPopupMenuBar::BuildOrigItems](#buildorigitems)|Carrega os itens de menu pop-up de um recurso de menu especificado.|  
|[CMFCPopupMenuBar::CloseDelayedSubMenu](#closedelayedsubmenu)|Fecha um botão de menu pop-up atrasada.|  
|[CMFCPopupMenuBar::ExportToMenu](#exporttomenu)|Cria um menu de botões de menu pop-up.|  
|[CMFCPopupMenuBar::FindDestintationToolBar](#finddestintationtoolbar)|Localiza a barra de ferramentas em que se encontra um ponto especificado.|  
|[CMFCPopupMenuBar::GetCurrentMenuImageSize](#getcurrentmenuimagesize)|Indica o tamanho das imagens de botão de menu.|  
|[CMFCPopupMenuBar::GetDefaultMenuId](#getdefaultmenuid)|Retorna o identificador do item de menu padrão.|  
|[CMFCPopupMenuBar::GetLastCommandIndex](#getlastcommandindex)|Obtém o índice do comando de menu invocado mais recentemente.|  
|[CMFCPopupMenuBar::GetOffset](#getoffset)|Obtém o deslocamento da linha da barra de menus pop-up.|  
|[CMFCPopupMenuBar::ImportFromMenu](#importfrommenu)|Importa os botões de menu pop-up de um menu especificado.|  
|[CMFCPopupMenuBar::IsDropDownListMode](#isdropdownlistmode)|Indica se a barra de menus pop-up está no modo de lista drop-down.|  
|[CMFCPopupMenuBar::IsPaletteMode](#ispalettemode)|Indica se a barra de menus pop-up está no modo de paleta.|  
|[CMFCPopupMenuBar::IsRibbonPanel](#isribbonpanel)|Indica se este é um painel de faixa de opções ( `FALSE` por padrão).|  
|[CMFCPopupMenuBar::IsRibbonPanelInRegularMode](#isribbonpanelinregularmode)|Indica se este é um painel de faixa de opções no modo normal ( `FALSE` por padrão).|  
|[CMFCPopupMenuBar::LoadFromHash](#loadfromhash)|Carrega um menu arquivado.|  
|[CMFCPopupMenuBar::RestoreDelayedSubMenu](#restoredelayedsubmenu)|Restaura um botão de menu atrasada para fechar a barra de menus pop-up.|  
|[CMFCPopupMenuBar::SetButtonStyle](#setbuttonstyle)|Define o estilo do botão de barra de ferramentas no índice especificado. (Substitui [CMFCToolBar::SetButtonStyle](../../mfc/reference/cmfctoolbar-class.md#setbuttonstyle).)|  
|[CMFCPopupMenuBar::SetOffset](#setoffset)|Define o deslocamento da linha da barra de menus pop-up.|  
|[CMFCPopupMenuBar::StartPopupMenuTimer](#startpopupmenutimer)|Inicia o temporizador para um botão de menu pop-up atrasada especificado.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPopupMenuBar::m_bDisableSideBarInXPMode](#m_bdisablesidebarinxpmode)|Especifica se a barra lateral cinza será exibida quando o aplicativo tem uma aparência do Windows XP.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCPopupMenuBar` é criado ao mesmo tempo como uma [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) e inseridos dentro dele. O `CMFCPopupMenuBar` abrange a área do cliente todo o `CMFCPopupMenu` objeto. Ele dá suporte a entrada de mouse e teclado. Ele também se comunica que a entrada para o `CMFCPopupMenu` e para a janela do quadro de nível superior.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como inicializar um `CMFCPopupMenuBar` de objeto um `CMFCPopupMenu` objeto. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient#7](../../mfc/reference/codesnippet/cpp/cmfcpopupmenubar-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpopupmenubar.h  
  
##  <a name="adjustsizeimmediate"></a>CMFCPopupMenuBar::AdjustSizeImmediate  
 Recalcula o layout do painel de barra de menu pop-up imediatamente. (Substitui [CPane::AdjustSizeImmediate](../../mfc/reference/cpane-class.md#adjustsizeimmediate).  
  
```  
virtual void AdjustSizeImmediate(BOOL bRecalcLayout);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bRecalcLayout`  
 `TRUE`para recalcular automaticamente o layout do painel barra do menu pop-up; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="buildorigitems"></a>CMFCPopupMenuBar::BuildOrigItems  
 Carrega os itens de menu pop-up de um recurso de menu especificado.  
  
```  
BOOL BuildOrigItems(UINT uiMenuResID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMenuResID`  
 Especifica a ID do menu do recurso de menu para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se for bem-sucedido ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="closedelayedsubmenu"></a>CMFCPopupMenuBar::CloseDelayedSubMenu  
 Fecha um botão de menu pop-up que foi adiado.  
  
```  
virtual void CloseDelayedSubMenu();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="exporttomenu"></a>CMFCPopupMenuBar::ExportToMenu  
 Cria um menu de botões de menu pop-up.  
  
```  
virtual HMENU ExportToMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador para o novo menu.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="finddestintationtoolbar"></a>CMFCPopupMenuBar::FindDestintationToolBar  
 Localiza a barra de ferramentas em que se encontra um ponto especificado.  
  
```  
CMFCToolBar* FindDestintationToolBar(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Um ponto na tela.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador para a barra de ferramentas em que se encontra o ponto, se therei for um, ou `NULL` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcurrentmenuimagesize"></a>CMFCPopupMenuBar::GetCurrentMenuImageSize  
 Indica o tamanho das imagens de botão de menu.  
  
```  
virtual CSize GetCurrentMenuImageSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho das imagens de botão de menu na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdefaultmenuid"></a>CMFCPopupMenuBar::GetDefaultMenuId  
 Retorna o identificador do item de menu padrão.  
  
```  
UINT GetDefaultMenuId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador do item de menu padrão na barra de menus pop-up.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getlastcommandindex"></a>CMFCPopupMenuBar::GetLastCommandIndex  
 Obtém o índice do comando de menu invocado mais recentemente.  
  
```  
static int __stdcall GetLastCommandIndex();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice do último comando de menu que tenha sido chamado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getoffset"></a>CMFCPopupMenuBar::GetOffset  
 Obtém o deslocamento da linha da barra de menus pop-up.  
  
```  
int GetOffset() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o deslocamento da linha da barra de menus pop-up.  
  
### <a name="remarks"></a>Comentários  
 Esse valor é definido usando [CMFCPopupMenuBar::SetOffset](#setoffset).  
  
##  <a name="importfrommenu"></a>CMFCPopupMenuBar::ImportFromMenu  
 Importa os botões de menu pop-up de um menu especificado.  
  
```  
virtual BOOL ImportFromMenu(
    HMENU hMenu,  
    BOOL bShowAllCommands = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hMenu`  
 O menu do qual importar os botões de menu pop-up.  
  
 [in] `bShowAllCommands`  
 `TRUE`Se todos os comandos no menu devem ser importados, ou `FALSE` se aqueles usados raramente podem estar ocultos.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se os botões de menu foram importados com êxito no menu, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isdropdownlistmode"></a>CMFCPopupMenuBar::IsDropDownListMode  
 Indica se a barra de menus pop-up está no modo de lista drop-down.  
  
```  
BOOL IsDropDownListMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a barra de menus pop-up está no modo de lista drop-down, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ispalettemode"></a>CMFCPopupMenuBar::IsPaletteMode  
 Indica se a barra de menus pop-up está no modo de paleta.  
  
```  
BOOL IsPaletteMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se o modo de paleta é habilitado, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
 Quando a barra de menu é definida para o modo de paleta, itens de menu aparecem em várias colunas e um número limitado de linhas.  
  
##  <a name="isribbonpanel"></a>CMFCPopupMenuBar::IsRibbonPanel  
 Indica se este é um painel de faixa de opções ( `FALSE` por padrão).  
  
```  
virtual BOOL IsRibbonPanel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `FALSE` por padrão, indicando que esse não é um painel de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isribbonpanelinregularmode"></a>CMFCPopupMenuBar::IsRibbonPanelInRegularMode  
 Indica se este é um painel de faixa de opções no modo normal ( `FALSE` por padrão).  
  
```  
virtual BOOL IsRibbonPanelInRegularMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `FALSE` por padrão, indicando que esse não é um painel de faixa de opções no modo normal.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="loadfromhash"></a>CMFCPopupMenuBar::LoadFromHash  
 Carrega um menu arquivado.  
  
```  
BOOL LoadFromHash(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hMenu`  
 Um identificador para o menu arquivado para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se o menu é carregado com êxito, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_bdisablesidebarinxpmode"></a>CMFCPopupMenuBar::m_bDisableSideBarInXPMode  
 Um parâmetro booliano que indica se o seu aplicativo tem uma barra lateral cinza quando ele tem uma aparência do Windows XP.  
  
```  
BOOL m_bDisableSideBarInXPMode;  
```  
  
### <a name="remarks"></a>Comentários  
 Se essa variável de membro é definido como `FALSE` e seu aplicativo tem uma aparência do Windows XP, o framework desenha uma barra lateral cinza em seu aplicativo.  
  
 O valor padrão é `FALSE`.  
  
##  <a name="restoredelayedsubmenu"></a>CMFCPopupMenuBar::RestoreDelayedSubMenu  
 Restaura um botão de menu atrasada para fechar a barra de menus pop-up.  
  
```  
virtual void RestoreDelayedSubMenu();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setbuttonstyle"></a>CMFCPopupMenuBar::SetButtonStyle  
 Define o estilo do botão de barra de ferramentas no índice especificado. (Substitui [CMFCToolBar::SetButtonStyle](../../mfc/reference/cmfctoolbar-class.md#setbuttonstyle).)  
  
```  
virtual void SetButtonStyle(
    int nIndex,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice de base zero do botão da barra de ferramentas cujo estilo será definido.  
  
 [in] `nStyle`  
 O estilo do botão. Consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para a lista de estilos de botão da barra de ferramentas disponíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setoffset"></a>CMFCPopupMenuBar::SetOffset  
 Define o deslocamento da linha da barra de menus pop-up.  
  
```  
void SetOffset(int iOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iOffset`  
 O número de linhas que a barra de menus pop-up deve ser deslocada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="startpopupmenutimer"></a>CMFCPopupMenuBar::StartPopupMenuTimer  
 Inicia o temporizador para um botão de menu pop-up atrasada especificado.  
  
```  
void StartPopupMenuTimer(
    CMFCToolBarMenuButton* pMenuButton,  
    int nDelayFactor = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuButton`  
 Ponteiro para o botão de menu para o qual definir o temporizador de atraso.  
  
 [in] `nDelayFactor`  
 Um fator atraso, de igual a pelo menos um multiplicar pelo tempo de atraso do menu padrão (geralmente entre meio segundo e cinco segundos).  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)   
 [Classe CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)

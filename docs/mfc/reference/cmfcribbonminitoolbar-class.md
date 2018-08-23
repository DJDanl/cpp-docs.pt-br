---
title: Classe CMFCRibbonMiniToolBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonMiniToolBar
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::IsContextMenuMode
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::IsRibbonMiniToolBar
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::SetCommands
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::Show
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::ShowWithContextMenu
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonMiniToolBar [MFC], IsContextMenuMode
- CMFCRibbonMiniToolBar [MFC], IsRibbonMiniToolBar
- CMFCRibbonMiniToolBar [MFC], SetCommands
- CMFCRibbonMiniToolBar [MFC], Show
- CMFCRibbonMiniToolBar [MFC], ShowWithContextMenu
ms.assetid: 7017e963-aeaf-4fe9-b540-e15a7ed41e94
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 789a8165a12977d11220d299e2c99549121dba64
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42539954"
---
# <a name="cmfcribbonminitoolbar-class"></a>Classe CMFCRibbonMiniToolBar
Implementa uma barra de ferramentas pop-up contextual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonMiniToolBar : public CMFCRibbonPanelMenu  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonMiniToolBar::CMFCRibbonMiniToolBar`|Construtor padrão.|  
|`CMFCRibbonMiniToolBar::~CMFCRibbonMiniToolBar`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonMiniToolBar::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CMFCRibbonMiniToolBar::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|  
|[CMFCRibbonMiniToolBar::IsContextMenuMode](#iscontextmenumode)||  
|[CMFCRibbonMiniToolBar::IsRibbonMiniToolBar](#isribbonminitoolbar)|(Substitui `CMFCPopupMenu::IsRibbonMiniToolBar`.)|  
|[CMFCRibbonMiniToolBar::SetCommands](#setcommands)|Define a lista de comandos a ser exibido na barra de ferramentas.|  
|[CMFCRibbonMiniToolBar::Show](#show)|Exibe a Minibarra de ferramentas em coordenadas da tela especificadas.|  
|[CMFCRibbonMiniToolBar::ShowWithContextMenu](#showwithcontextmenu)|Exibe a Minibarra de ferramentas junto com um menu de contexto.|  
  
## <a name="remarks"></a>Comentários  
 A Minibarra de ferramentas normalmente é exibida depois que o usuário seleciona um objeto em um documento. Por exemplo, depois que o usuário seleciona um bloco de texto de programa de processamento de uma palavra, o aplicativo exibe uma Minibarra de ferramentas que contém os comandos de formatação de texto.  
  
 A Minibarra de ferramentas se torna transparente quando o ponteiro do mouse está fora dos limites da Minibarra de ferramentas.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)  
  
 [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)  
  
 `CMFCRibbonPanelMenu`  
  
 [CMFCRibbonMiniToolBar](../../mfc/reference/cmfcribbonminitoolbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonMiniToolBar.h  
  
##  <a name="setcommands"></a>  CMFCRibbonMiniToolBar::SetCommands  
 Define a lista de comandos a ser exibido na barra de ferramentas.  
  
```  
void SetCommands(
    CMFCRibbonBar* pRibbonBar,  
    const CList<UINT,UINT>& lstCommands);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pRibbonBar*  
 A barra de faixa de opções que a Minibarra de ferramentas de pesquisa para os botões Exibir.  
  
 [in] *lstCommands*  
 A lista de comandos a ser exibido na Minibarra de ferramentas. Todas as categorias de faixa de opções são pesquisadas para localizar os botões associados.  
  
### <a name="remarks"></a>Comentários  
 Use essa função para definir a lista de comandos a serem exibidos no Minibarra de ferramentas.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetCommands` método da `CMFCRibbonMiniToolBar` classe. Este trecho de código faz parte de [amostra de demonstração do MS Office 2007](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo#9](../../mfc/reference/codesnippet/cpp/cmfcribbonminitoolbar-class_1.cpp)]  
  
##  <a name="show"></a>  CMFCRibbonMiniToolBar::Show  
 Exibe a Minibarra de ferramentas em coordenadas da tela especificadas.  
  
```  
BOOL Show(
    int x,  
    int y);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *x*  
 Especifica a posição horizontal da Minibarra de ferramentas em coordenadas da tela.  
  
 [in] *y*  
 Especifica a posição vertical da Minibarra de ferramentas em coordenadas da tela.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se a Minibarra de ferramentas foi exibido com êxito; Caso contrário, FALSE.  
  
##  <a name="showwithcontextmenu"></a>  CMFCRibbonMiniToolBar::ShowWithContextMenu  
 Exibe a Minibarra de ferramentas junto com um menu de contexto.  
  
```  
BOOL ShowWithContextMenu(
    int x,  
    int y,  
    UINT uiMenuResID,  
    CWnd* pWndOwner);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *x*  
 Especifica a posição horizontal do menu de contexto em coordenadas da tela.  
  
 [in] *y*  
 Especifica a posição vertical do menu de contexto em coordenadas da tela.  
  
 [in] *uiMenuResID*  
 Especifica a ID de recurso do menu de contexto para exibir.  
  
 [in] *pWndOwner*  
 Identifica a janela que recebe mensagens do menu de contexto.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se o menu de contexto foi exibido com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use essa função para exibir uma Minibarra de ferramentas que tem um menu de contexto. O menu de contexto é posicionadas 15 pixels abaixo a Minibarra de ferramentas.  
  
##  <a name="iscontextmenumode"></a>  CMFCRibbonMiniToolBar::IsContextMenuMode  
 Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.  
  
```  
BOOL IsContextMenuMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isribbonminitoolbar"></a>  CMFCRibbonMiniToolBar::IsRibbonMiniToolBar  
 Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.  
  
```  
virtual BOOL IsRibbonMiniToolBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

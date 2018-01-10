---
title: Classe CSplitButton | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSplitButton
- AFXCMN/CSplitButton
- AFXCMN/CSplitButton::CSplitButton
- AFXCMN/CSplitButton::Create
- AFXCMN/CSplitButton::SetDropDownMenu
- AFXCMN/CSplitButton::OnDropDown
dev_langs: C++
helpviewer_keywords:
- CSplitButton [MFC], CSplitButton
- CSplitButton [MFC], Create
- CSplitButton [MFC], SetDropDownMenu
- CSplitButton [MFC], OnDropDown
ms.assetid: 6844d0a9-6408-4e44-9b5f-57628ed8bad6
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e4188647b821fc233835ea4780804848c4b03228
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csplitbutton-class"></a>Classe CSplitButton
O `CSplitButton` classe representa um controle de botão de divisão. O controle de botão de divisão executa um comportamento padrão quando um usuário clica a parte principal do botão e um menu suspenso é exibido quando um usuário clica na seta suspensa do botão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSplitButton : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitButton::CSplitButton](#csplitbutton)|Constrói um objeto `CSplitButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitButton::Create](#create)|Cria um controle de botão de divisão com estilos especificados e a anexa ao atual `CSplitButton` objeto.|  
|[CSplitButton::SetDropDownMenu](#setdropdownmenu)|Define o menu suspenso é exibido quando um usuário clica na seta do menu suspenso do controle de botão de divisão atual.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitButton::OnDropDown](#ondropdown)|Manipula o `BCN_DROPDOWN` notificação de que o sistema envia quando um usuário clica na seta do menu suspenso do controle de botão de divisão atual.|  
  
## <a name="remarks"></a>Comentários  
 O `CSplitButton` classe é derivada do [CButton](../../mfc/reference/cbutton-class.md) classe. O controle de botão de divisão é um controle de botão cujo estilo é `BS_SPLITBUTTON`. Ele exibe um menu personalizado quando um usuário clica na seta suspensa. Para obter mais informações, consulte o `BS_SPLITBUTTON` e `BS_DEFSPLITBUTTON` estilos em [estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb775951).  
  
 A figura a seguir mostra uma caixa de diálogo que contém um controle de pager e um controle de botão de divisão (1). A seta suspensa (2) já foi clicado, e o submenu (3) é exibida.  
  
 ![Caixa de diálogo com um controle splitbutton e pager. ] (../../mfc/reference/media/splitbutton_pager.png "splitbutton_pager")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 `CSplitButton`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
 Essa classe é suportada no [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] e posterior.  
  
 Requisitos adicionais para esta classe são descritos em [criar requisitos para Vista controles comuns do Windows](../../mfc/build-requirements-for-windows-vista-common-controls.md).  
  
##  <a name="create"></a>CSplitButton::Create  
 Cria um controle de botão de divisão com estilos especificados e a anexa ao atual `CSplitButton` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `dwStyle`|Uma combinação bit a bit (ou) de estilos a ser aplicada ao controle. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).|  
|[in] `rect`|Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle.|  
|[in] `pParentWnd`|Um ponteiro não nulo para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle.|  
|[in] `nID`|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
##  <a name="csplitbutton"></a>CSplitButton::CSplitButton  
 Constrói um objeto `CSplitButton`. Os parâmetros do construtor especificar um submenu que é exibido quando um usuário clica na seta do menu suspenso do controle de botão de divisão.  
  
```  
CSplitButton();

 
CSplitButton(
    UINT nMenuId,   
    UINT nSubMenuId)  
CSplitButton(CMenu* pMenu)  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nMenuId`|A ID de recurso da barra de menus.|  
|[in] `nSubMenuId`|A ID de recurso de um submenu.|  
|[in] `pMenu`|Um ponteiro para um [CMenu](../../mfc/reference/cmenu-class.md) objeto que especifica um submenu. O `CSplitButton` objeto exclui o `CMenu` objeto e seus associados `HMENU` quando o `CSplitButton` objeto sai do escopo.|  
  
### <a name="remarks"></a>Comentários  
 Use o [CSplitButton::Create](#create) método para criar um controle de botão de divisão e anexá-lo para o `CSplitButton` objeto.  
  
##  <a name="ondropdown"></a>CSplitButton::OnDropDown  
 Manipula o `BCN_DROPDOWN` notificação de que o sistema envia quando um usuário clica na seta do menu suspenso do controle de botão de divisão atual.  
  
```  
afx_msg void OnDropDown(
    NMHDR* pNMHDR,   
    LRESULT* pResult);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pNMHDR`|Ponteiro para um [NMHDR](http://msdn.microsoft.com/library/windows/desktop/bb775514) estrutura que contém informações sobre o [BCN_DROPDOWN](http://msdn.microsoft.com/library/windows/desktop/bb775983) notificação.|  
|[out] `pResult`|(Não usado; nenhum valor é retornado). Valor de retorno de [BCN_DROPDOWN](http://msdn.microsoft.com/library/windows/desktop/bb775983) notificação.|  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário clica na seta suspensa em um controle de botão de divisão, o sistema envia um `BCN_DROPDOWN` notificação de mensagem, que o `OnDropDown` identificadores de método. No entanto, o `CSplitButton` objeto não encaminhar o `BCN_DROPDOWN` notificação para o controle que contém o controle de botão de divisão. Consequentemente, contendo o controle não oferece suporte uma ação personalizada em resposta à notificação.  
  
 Para implementar uma ação personalizada que dá suporte ao controle que o contém, use um [CButton](../../mfc/reference/cbutton-class.md) objeto com um estilo de `BS_SPLITBUTTON` em vez de um `CSplitButton` objeto. Em seguida, implemente um manipulador para o `BCN_DROPDOWN` notificação no `CButton` objeto. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).  
  
 Para implementar uma ação personalizada que o botão de divisão próprio controle oferece suporte, use [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md). Derive sua própria classe do `CSplitButton` de classe e denomine-, por exemplo, CMySplitButton. Em seguida, adicione o mapa de mensagem a seguir ao seu aplicativo para lidar com o `BCN_DROPDOWN` notificação:  
  
```  
BEGIN_MESSAGE_MAP(CMySplitButton,
    CSplitButton)  
    ON_NOTIFY_REFLECT(BCN_DROPDOWN, &CMySplitButton::OnDropDown)  
END_MESSAGE_MAP()  
```  
  
##  <a name="setdropdownmenu"></a>CSplitButton::SetDropDownMenu  
 Define o menu suspenso é exibido quando um usuário clica na seta do menu suspenso do controle de botão de divisão atual.  
  
```  
void SetDropDownMenu(
    UINT nMenuId,   
    UINT nSubMenuId);  
  
void SetDropDownMenu(CMenu* pMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nMenuId`|A ID de recurso da barra de menus.|  
|[in] `nSubMenuId`|A ID de recurso de um submenu.|  
|[in] `pMenu`|Ponteiro para um [CMenu](../../mfc/reference/cmenu-class.md) objeto que especifica um submenu. O `CSplitButton` objeto exclui o `CMenu` objeto e seus associados `HMENU` quando o `CSplitButton` objeto sai do escopo.|  
  
### <a name="remarks"></a>Comentários  
 O `nMenuId` parâmetro identifica uma barra de menus, que é uma lista de itens da barra de menu. O `nSubMenuId` parâmetro é um número de índice baseado em zero que identifica um submenu, que é a lista suspensa dos itens de menu associado a cada item da barra de menu. Por exemplo, um aplicativo típico tem um menu que contém os itens da barra de menu, "File", "Editar" e "Ajuda". O item de barra de menu "Arquivo" tem um submenu que contém os itens de menu "Aberta", "Fechar" e "Exit". Quando você clicar na seta do menu suspenso do controle de botão de divisão, o controle exibe o submenu especificado, não a barra de menus.  
  
 A figura a seguir mostra uma caixa de diálogo que contém um controle de pager e um controle de botão de divisão (1). A seta suspensa (2) já foi clicado, e o submenu (3) é exibida.  
  
 ![Caixa de diálogo com um controle splitbutton e pager. ] (../../mfc/reference/media/splitbutton_pager.png "splitbutton_pager")  
  
### <a name="example"></a>Exemplo  
 A primeira instrução no exemplo de código a seguir demonstra o [CSplitButton::SetDropDownMenu](#setdropdownmenu) método. Criamos o menu com o Visual Studio editor de recurso, que são nomeadas automaticamente a ID de barra de menu, `IDR_MENU1`. O `nSubMenuId` parâmetro, que é zero, refere-se ao submenu somente da barra de menus.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/csplitbutton-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSplitButton](../../mfc/reference/csplitbutton-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)

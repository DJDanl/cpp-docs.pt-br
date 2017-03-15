---
title: Classe CSplitButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CSplitButton class
ms.assetid: 6844d0a9-6408-4e44-9b5f-57628ed8bad6
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b4c038a177d5c501d4baad8eaa208af0e76ce231
ms.lasthandoff: 02/25/2017

---
# <a name="csplitbutton-class"></a>Classe CSplitButton
O `CSplitButton` classe representa um controle de botão de divisão. O controle de botão de divisão executa um comportamento padrão quando um usuário clica na parte principal do botão e exibe um menu suspenso quando um usuário clica na seta suspensa do botão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSplitButton : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitButton::CSplitButton](#csplitbutton)|Constrói um objeto `CSplitButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitButton::Create](#create)|Cria um controle de botão de divisão com estilos especificados e o anexa à atual `CSplitButton` objeto.|  
|[CSplitButton::SetDropDownMenu](#setdropdownmenu)|Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle de botão de divisão atual.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSplitButton::OnDropDown](#ondropdown)|Manipula o `BCN_DROPDOWN` notificação de que o sistema envia quando um usuário clica na seta suspensa do controle de botão de divisão atual.|  
  
## <a name="remarks"></a>Comentários  
 O `CSplitButton` classe é derivada do [CButton](../../mfc/reference/cbutton-class.md) classe. O controle de botão de divisão é um controle de botão cujo estilo é `BS_SPLITBUTTON`. Ele exibe um menu personalizado quando um usuário clica na seta suspensa. Para obter mais informações, consulte o `BS_SPLITBUTTON` e `BS_DEFSPLITBUTTON` estilos em [estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb775951).  
  
 A figura a seguir mostra uma caixa de diálogo que contém um controle de paginação e um controle de botão de divisão (1). A seta suspensa (2) já foi clicado e o submenu (3) é exibida.  
  
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
  
 Requisitos adicionais para esta classe são descritos em [criar requisitos para Windows Vista controles comuns](../../mfc/build-requirements-for-windows-vista-common-controls.md).  
  
##  <a name="a-namecreatea--csplitbuttoncreate"></a><a name="create"></a>CSplitButton::Create  
 Cria um controle de botão de divisão com estilos especificados e o anexa à atual `CSplitButton` objeto.  
  
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
|[in] `dwStyle`|Uma combinação bit a bit (OR) de estilos a ser aplicado ao controle. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/button-styles.md).|  
|[in] `rect`|Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle.|  
|[in] `pParentWnd`|Um ponteiro não-null para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle.|  
|[in] `nID`|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
##  <a name="a-namecsplitbuttona--csplitbuttoncsplitbutton"></a><a name="csplitbutton"></a>CSplitButton::CSplitButton  
 Constrói um objeto `CSplitButton`. Os parâmetros do construtor especificar um submenu é exibido quando um usuário clica na seta suspensa do controle de botão de divisão.  
  
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
|[in] `pMenu`|Um ponteiro para um [CMenu](../../mfc/reference/cmenu-class.md) objeto que especifica um submenu. O `CSplitButton` exclusões do objeto de `CMenu` objeto e seus associados `HMENU` quando o `CSplitButton` objeto sai do escopo.|  
  
### <a name="remarks"></a>Comentários  
 Use o [CSplitButton::Create](#create) método para criar um controle de botão de divisão e anexá-lo a `CSplitButton` objeto.  
  
##  <a name="a-nameondropdowna--csplitbuttonondropdown"></a><a name="ondropdown"></a>CSplitButton::OnDropDown  
 Manipula o `BCN_DROPDOWN` notificação de que o sistema envia quando um usuário clica na seta suspensa do controle de botão de divisão atual.  
  
```  
afx_msg void OnDropDown(
    NMHDR* pNMHDR,   
    LRESULT* pResult);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pNMHDR`|Ponteiro para uma [NMHDR](http://msdn.microsoft.com/library/windows/desktop/bb775514) estrutura que contém informações sobre o [BCN_DROPDOWN](http://msdn.microsoft.com/library/windows/desktop/bb775983) notificação.|  
|[out] `pResult`|(Não usado, nenhum valor será retornado.) Valor de retorno do [BCN_DROPDOWN](http://msdn.microsoft.com/library/windows/desktop/bb775983) notificação.|  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário clica na seta suspensa em um controle de botão de divisão, o sistema envia uma `BCN_DROPDOWN` notificação de mensagem, que o `OnDropDown` identificadores de método. No entanto, o `CSplitButton` objeto não encaminhar o `BCN_DROPDOWN` notificação para o controle que contém o controle de botão de divisão. Consequentemente, contendo o controle não oferece suporte uma ação personalizada em resposta à notificação.  
  
 Para implementar uma ação personalizada que oferece suporte ao controle que o contém, use uma [CButton](../../mfc/reference/cbutton-class.md) o objeto com um estilo de `BS_SPLITBUTTON` em vez de um `CSplitButton` objeto. Em seguida, implemente um manipulador para o `BCN_DROPDOWN` notificação no `CButton` objeto. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/button-styles.md).  
  
 Para implementar uma ação personalizada que o botão de divisão de controle em si oferece suporte, use [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md). Derivar sua própria classe a partir de `CSplitButton` classe e nomeie-a, por exemplo, CMySplitButton. Em seguida, adicione o mapa de mensagem a seguir ao seu aplicativo para tratar o `BCN_DROPDOWN` notificação:  
  
```  
BEGIN_MESSAGE_MAP(CMySplitButton,
    CSplitButton)  
    ON_NOTIFY_REFLECT(BCN_DROPDOWN, &CMySplitButton::OnDropDown)  
END_MESSAGE_MAP()  
```  
  
##  <a name="a-namesetdropdownmenua--csplitbuttonsetdropdownmenu"></a><a name="setdropdownmenu"></a>CSplitButton::SetDropDownMenu  
 Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle de botão de divisão atual.  
  
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
|[in] `pMenu`|Ponteiro para uma [CMenu](../../mfc/reference/cmenu-class.md) objeto que especifica um submenu. O `CSplitButton` exclusões do objeto de `CMenu` objeto e seus associados `HMENU` quando o `CSplitButton` objeto sai do escopo.|  
  
### <a name="remarks"></a>Comentários  
 O `nMenuId` parâmetro identifica uma barra de menus, que é uma lista de itens da barra de menu. O `nSubMenuId` parâmetro é um número de índice baseado em zero que identifica um submenu, que é a lista suspensa de itens de menu associados a cada item da barra de menu. Por exemplo, um aplicativo típico tem um menu que contém os itens de barra de menu, "Arquivo", "Editar" e "Ajuda". O item de barra de menu "Arquivo" tem um submenu que contém os itens de menu, "Open", "Fechar" e "Exit". Quando a seta suspensa do controle botão de divisão é clicada, o controle exibe o submenu especificado, não a barra de menus.  
  
 A figura a seguir mostra uma caixa de diálogo que contém um controle de paginação e um controle de botão de divisão (1). A seta suspensa (2) já foi clicado e o submenu (3) é exibida.  
  
 ![Caixa de diálogo com um controle splitbutton e pager. ] (../../mfc/reference/media/splitbutton_pager.png "splitbutton_pager")  
  
### <a name="example"></a>Exemplo  
 A primeira instrução no exemplo de código a seguir demonstra o [CSplitButton::SetDropDownMenu](#setdropdownmenu) método. Criamos o menu com o Visual Studio editor de recursos, que automaticamente o nome a ID de barra de menu, `IDR_MENU1`. O `nSubMenuId` parâmetro, que é zero, refere-se ao submenu somente da barra de menus.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&1;](../../mfc/reference/codesnippet/cpp/csplitbutton-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSplitButton](../../mfc/reference/csplitbutton-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)


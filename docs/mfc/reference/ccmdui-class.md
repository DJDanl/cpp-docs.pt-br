---
title: Classe CCmdUI | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCmdUI
dev_langs:
- C++
helpviewer_keywords:
- user interfaces, updating
- states, updating user interface object
- updating user interfaces for commands
- commands [C++], updating UI
- CCmdUI class
- toolbars [C++], updating
- command user interface
- menus [C++], updating as context changes
- buttons [C++], updating as context changes
ms.assetid: 04eaaaf5-f510-48ab-b425-94665ba24766
caps.latest.revision: 21
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: beb84a0f0f96c7a8acb5c432c7402b3e62b94518
ms.lasthandoff: 02/25/2017

---
# <a name="ccmdui-class"></a>Classe CCmdUI
É usado somente em uma `ON_UPDATE_COMMAND_UI` manipulador em um `CCmdTarget`-classe derivada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCmdUI  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCmdUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comando para continuar a rotear a mensagem atual a cadeia de manipuladores.|  
|[CCmdUI::Enable](#enable)|Habilita ou desabilita o item de interface do usuário para este comando.|  
|[CCmdUI::SetCheck](#setcheck)|Define o estado de seleção do item de interface do usuário para este comando.|  
|[CCmdUI::SetRadio](#setradio)|Como o `SetCheck` função de membro, mas opera em grupos de opção.|  
|[CCmdUI::SetText](#settext)|Define o texto do item de interface do usuário para este comando.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCmdUI::m_nID](#m_nid)|A ID do objeto de interface do usuário.|  
|[CCmdUI::m_nIndex](#m_nindex)|O índice do objeto de interface do usuário.|  
|[CCmdUI::m_pMenu](#m_pmenu)|Aponta para o menu representado pelo `CCmdUI` objeto.|  
|[CCmdUI::m_pOther](#m_pother)|Aponta para o objeto de janela que enviou a notificação.|  
|[CCmdUI::m_pSubMenu](#m_psubmenu)|Aponta para o submenu independente representado pelo `CCmdUI` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CCmdUI`não tem uma classe base.  
  
 Quando um usuário de seu aplicativo apanha um menu, cada item de menu precisa saber se ele deve ser exibido como habilitado ou desabilitado. O destino de um comando de menu fornece essas informações ao implementar um `ON_UPDATE_COMMAND_UI` manipulador. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use a janela Propriedades para criar um protótipo de entrada e a função de mapa de mensagem para cada manipulador.  
  
 Quando o menu é retirado, a estrutura de procura e chama cada um `ON_UPDATE_COMMAND_UI` manipulador, cada manipulador chama `CCmdUI` como funções de membro **habilitar** e **verificar**, e a estrutura adequadamente exibe cada item de menu.  
  
 Um item de menu pode ser substituído por um botão da barra de controle ou outro objeto de interface do usuário de comando sem alterar o código dentro de `ON_UPDATE_COMMAND_UI` manipulador.  
  
 A tabela a seguir resume o efeito `CCmdUI`de funções de membro têm nos diversos itens de interface do usuário do comando.  
  
|Item de Interface do usuário|Habilitar|SetCheck|SetRadio|SetText|  
|--------------------------|------------|--------------|--------------|-------------|  
|Item de menu|Habilita ou desabilita|(×) Ou desmarca|Verificações de ponto (•)|Conjuntos de texto do item|  
|Botão de barra de ferramentas|Habilita ou desabilita|Seleciona e desmarca, ou indeterminado|Mesmo que`SetCheck`|(Não aplicável)|  
|Painel da barra de status|Torna o texto visível ou invisível|Borda de conjuntos pop-out ou normal|Mesmo que`SetCheck`|Define o texto do painel|  
|Botão normal`CDialogBar`|Habilita ou desabilita|Marca ou desmarca a caixa de seleção|Mesmo que`SetCheck`|Conjuntos de texto de botão|  
|Controle normal`CDialogBar`|Habilita ou desabilita|(Não aplicável)|(Não aplicável)|Define o texto da janela|  
  
 Para obter mais informações sobre o uso dessa classe, consulte [como objetos de Interface do usuário de atualização](../../mfc/how-to-update-user-interface-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CCmdUI`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecontinueroutinga--ccmduicontinuerouting"></a><a name="continuerouting"></a>CCmdUI::ContinueRouting  
 Chame essa função de membro para informar o mecanismo de roteamento de comando para continuar a rotear a mensagem atual a cadeia de manipuladores.  
  
```  
void ContinueRouting();
```  
  
### <a name="remarks"></a>Comentários  
 Essa é uma função de membro avançado que deve ser usada em conjunto com um `ON_COMMAND_EX` manipulador retorna **FALSE**. Para obter mais informações, consulte [técnico 6 Observação](../../mfc/tn006-message-maps.md).  
  
##  <a name="a-nameenablea--ccmduienable"></a><a name="enable"></a>CCmdUI::Enable  
 Chame essa função de membro para habilitar ou desabilitar o item de interface do usuário para este comando.  
  
```  
virtual void Enable(BOOL bOn = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bOn`  
 **TRUE** para habilitar o item **FALSE** desabilitá-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[46 NVC_MFCDocView](../../mfc/codesnippet/cpp/ccmdui-class_1.cpp)]  
  
 [!code-cpp[47 NVC_MFCDocView](../../mfc/codesnippet/cpp/ccmdui-class_2.cpp)]  
  
##  <a name="a-namemnida--ccmduimnid"></a><a name="m_nid"></a>CCmdUI::m_nID  
 A ID do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo `CCmdUI` objeto.  
  
```  
UINT m_nID;  
```  
  
##  <a name="a-namemnindexa--ccmduimnindex"></a><a name="m_nindex"></a>CCmdUI::m_nIndex  
 O índice do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo `CCmdUI` objeto.  
  
```  
UINT m_nIndex;  
```  
  
##  <a name="a-namempmenua--ccmduimpmenu"></a><a name="m_pmenu"></a>CCmdUI::m_pMenu  
 Ponteiro (do `CMenu` tipo) no menu representado pelo `CCmdUI` objeto.  
  
```  
CMenu* m_pMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 **NULO** se o item não for um menu.  
  
##  <a name="a-namempsubmenua--ccmduimpsubmenu"></a><a name="m_psubmenu"></a>CCmdUI::m_pSubMenu  
 Ponteiro (do `CMenu` tipo) para o submenu independente representado pelo `CCmdUI` objeto.  
  
```  
CMenu* m_pSubMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 **NULO** se o item não for um menu. Se o submenu é um pop-up, `m_nID` contém a ID do primeiro item no menu pop-up. Para obter mais informações, consulte [21 de nota técnica](../../mfc/tn021-command-and-message-routing.md).  
  
##  <a name="a-namempothera--ccmduimpother"></a><a name="m_pother"></a>CCmdUI::m_pOther  
 Ponteiro (do tipo `CWnd`) para o objeto de janela, como uma barra de status ou ferramenta que enviou a notificação.  
  
```  
CWnd* m_pOther;  
```  
  
### <a name="remarks"></a>Comentários  
 **NULO** se o item é um menu ou uma não - `CWnd` objeto.  
  
##  <a name="a-namesetchecka--ccmduisetcheck"></a><a name="setcheck"></a>CCmdUI::SetCheck  
 Chame essa função de membro para definir o item de interface do usuário para esse comando para o estado de seleção apropriadas.  
  
```  
virtual void SetCheck(int nCheck = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCheck`  
 Especifica o estado de seleção para definir. Se 0, desmarca; Se 1, verifica; e se 2, define indeterminado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro funciona para itens de menu e botões da barra de ferramentas. O estado indeterminado se aplica somente aos botões de barra de ferramentas.  
  
##  <a name="a-namesetradioa--ccmduisetradio"></a><a name="setradio"></a>CCmdUI::SetRadio  
 Chame essa função de membro para definir o item de interface do usuário para esse comando para o estado de seleção apropriadas.  
  
```  
virtual void SetRadio(BOOL bOn = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bOn`  
 **TRUE** para habilitar o item; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro opera como `SetCheck`, exceto que ele opera em itens de interface do usuário, atuando como parte de um grupo de opção. Desmarcar os outros itens no grupo não é automática, a menos que os próprios itens mantêm o comportamento do grupo de opção.  
  
##  <a name="a-namesettexta--ccmduisettext"></a><a name="settext"></a>CCmdUI::SetText  
 Chame essa função de membro para definir o texto do item de interface do usuário para este comando.  
  
```  
virtual void SetText(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Um ponteiro para uma cadeia de caracteres de texto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[48 NVC_MFCDocView](../../mfc/codesnippet/cpp/ccmdui-class_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)


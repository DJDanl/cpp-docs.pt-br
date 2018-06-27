---
title: Classe CCmdUI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CCmdUI
- AFXWIN/CCmdUI
- AFXWIN/CCmdUI::ContinueRouting
- AFXWIN/CCmdUI::Enable
- AFXWIN/CCmdUI::SetCheck
- AFXWIN/CCmdUI::SetRadio
- AFXWIN/CCmdUI::SetText
- AFXWIN/CCmdUI::m_nID
- AFXWIN/CCmdUI::m_nIndex
- AFXWIN/CCmdUI::m_pMenu
- AFXWIN/CCmdUI::m_pOther
- AFXWIN/CCmdUI::m_pSubMenu
dev_langs:
- C++
helpviewer_keywords:
- CCmdUI [MFC], ContinueRouting
- CCmdUI [MFC], Enable
- CCmdUI [MFC], SetCheck
- CCmdUI [MFC], SetRadio
- CCmdUI [MFC], SetText
- CCmdUI [MFC], m_nID
- CCmdUI [MFC], m_nIndex
- CCmdUI [MFC], m_pMenu
- CCmdUI [MFC], m_pOther
- CCmdUI [MFC], m_pSubMenu
ms.assetid: 04eaaaf5-f510-48ab-b425-94665ba24766
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3dd417872ab4009a9e0f6c06fc0958f5780de477
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36954146"
---
# <a name="ccmdui-class"></a>Classe CCmdUI
É usado somente em um `ON_UPDATE_COMMAND_UI` manipulador em um `CCmdTarget`-classe derivada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCmdUI  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCmdUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comando para rotear a mensagem atual para a cadeia de manipuladores de continuar.|  
|[CCmdUI::Enable](#enable)|Habilita ou desabilita o item de interface do usuário para este comando.|  
|[CCmdUI::SetCheck](#setcheck)|Define o estado de seleção do item de interface do usuário para esse comando.|  
|[CCmdUI::SetRadio](#setradio)|Como o `SetCheck` função de membro, mas funciona em grupos de opção.|  
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
 `CCmdUI` não tem uma classe base.  
  
 Quando um usuário de seu aplicativo recebe para baixo de um menu, cada item de menu precisa saber se ele deve ser exibido como habilitado ou desabilitado. O destino de um comando de menu fornece essas informações ao implementar um `ON_UPDATE_COMMAND_UI` manipulador. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use a janela Propriedades para criar um protótipo de função e de entrada de mapa de mensagem para cada manipulador de.  
  
 Quando o menu é movido para baixo, o framework pesquisa e chama cada `ON_UPDATE_COMMAND_UI` chamadas do manipulador, cada manipulador `CCmdUI` , como funções de membro `Enable` e `Check`, e a estrutura adequadamente exibe cada item de menu.  
  
 Um item de menu pode ser substituído por um botão da barra de controle ou outro objeto de interface do usuário do comando sem alterar o código dentro do `ON_UPDATE_COMMAND_UI` manipulador.  
  
 A tabela a seguir resume o efeito `CCmdUI`de funções de membro tiver nos diversos itens de interface do usuário do comando.  
  
|Item de Interface do usuário|Habilitar|SetCheck|SetRadio|SetText|  
|--------------------------|------------|--------------|--------------|-------------|  
|Item de menu|Habilita ou desabilita a|Marca ou desmarca|Verifica usando um ponto|Texto de item de conjuntos|  
|Botão de barra de ferramentas|Habilita ou desabilita a|Seleciona, desmarca, ou indeterminado|Mesmo que `SetCheck`|(Não aplicável)|  
|Painel da barra de status|Torna o texto visível ou invisível|Borda de pop-out ou normal de conjuntos|Mesmo que `SetCheck`|Define o texto do painel|  
|Botão normal `CDialogBar`|Habilita ou desabilita a|Marca ou desmarca a caixa de seleção|Mesmo que `SetCheck`|Conjuntos de texto de botão|  
|Controle normal `CDialogBar`|Habilita ou desabilita a|(Não aplicável)|(Não aplicável)|Define o texto da janela|  
  
 Para obter mais informações sobre o uso dessa classe, consulte [como objetos de atualização de Interface do usuário](../../mfc/how-to-update-user-interface-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CCmdUI`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="continuerouting"></a>  CCmdUI::ContinueRouting  
 Chame essa função de membro para informar o mecanismo de roteamento de comando para rotear a mensagem atual para a cadeia de manipuladores de continuar.  
  
```  
void ContinueRouting();
```  
  
### <a name="remarks"></a>Comentários  
 Essa é uma função de membro avançado que deve ser usada em conjunto com um `ON_COMMAND_EX` manipulador retorna **FALSE**. Para obter mais informações, consulte [6 de observação técnica](../../mfc/tn006-message-maps.md).  
  
##  <a name="enable"></a>  CCmdUI::Enable  
 Chame essa função de membro para habilitar ou desabilitar o item de interface do usuário para este comando.  
  
```  
virtual void Enable(BOOL bOn = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bOn*  
 **TRUE** para habilitar o item **FALSE** para desabilitá-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#46](../../mfc/codesnippet/cpp/ccmdui-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCDocView#47](../../mfc/codesnippet/cpp/ccmdui-class_2.cpp)]  
  
##  <a name="m_nid"></a>  CCmdUI::m_nID  
 A ID do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo `CCmdUI` objeto.  
  
```  
UINT m_nID;  
```  
  
##  <a name="m_nindex"></a>  CCmdUI::m_nIndex  
 O índice do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo `CCmdUI` objeto.  
  
```  
UINT m_nIndex;  
```  
  
##  <a name="m_pmenu"></a>  CCmdUI::m_pMenu  
 Ponteiro (de `CMenu` tipo) ao menu representado pelo `CCmdUI` objeto.  
  
```  
CMenu* m_pMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 **NULO** se o item não é um menu.  
  
##  <a name="m_psubmenu"></a>  CCmdUI::m_pSubMenu  
 Ponteiro (de `CMenu` tipo) para o submenu independente representado pelo `CCmdUI` objeto.  
  
```  
CMenu* m_pSubMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 **NULO** se o item não é um menu. Se o submenu é um pop-up, *m_nID* contém a ID do primeiro item no menu pop-up. Para obter mais informações, consulte [21 de observação técnica](../../mfc/tn021-command-and-message-routing.md).  
  
##  <a name="m_pother"></a>  CCmdUI::m_pOther  
 Ponteiro (do tipo `CWnd`) para o objeto de janela, como uma barra de status ou ferramenta que enviou a notificação.  
  
```  
CWnd* m_pOther;  
```  
  
### <a name="remarks"></a>Comentários  
 **NULO** se o item é um menu ou não `CWnd` objeto.  
  
##  <a name="setcheck"></a>  CCmdUI::SetCheck  
 Chame essa função de membro para definir o item de interface do usuário para este comando para o estado de seleção apropriada.  
  
```  
virtual void SetCheck(int nCheck = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nVerifique*  
 Especifica o estado de seleção para definir. Se 0, desmarca; Se 1, verifica; e se 2, define indeterminado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro funciona para itens de menu e botões de barra de ferramentas. O estado indeterminado se aplica somente aos botões de barra de ferramentas.  
  
##  <a name="setradio"></a>  CCmdUI::SetRadio  
 Chame essa função de membro para definir o item de interface do usuário para este comando para o estado de seleção apropriada.  
  
```  
virtual void SetRadio(BOOL bOn = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bOn`  
 **TRUE** para habilitar o item; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro opera como `SetCheck`, exceto que ela opera em itens de interface do usuário atuando como parte de um grupo de opção. Desmarcar os outros itens do grupo não é automática, a menos que os itens se mantêm o comportamento do grupo de opção.  
  
##  <a name="settext"></a>  CCmdUI::SetText  
 Chame essa função de membro para definir o texto do item de interface do usuário para esse comando.  
  
```  
virtual void SetText(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszText*  
 Um ponteiro para uma cadeia de caracteres de texto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#48](../../mfc/codesnippet/cpp/ccmdui-class_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

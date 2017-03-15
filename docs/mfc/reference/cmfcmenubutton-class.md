---
title: Classe CMFCMenuButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCMenuButton
dev_langs:
- C++
helpviewer_keywords:
- CMFCMenuButton class
ms.assetid: 53d3d459-1e5a-47c5-8b7f-2e61f6af5187
caps.latest.revision: 32
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 65c334ce68dbbbae2b21da2c40aa9420cdeb51bd
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcmenubutton-class"></a>Classe CMFCMenuButton
Um botão que exibe um menu pop-up e relatórios sobre as seleções de menu do usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCMenuButton : public CMFCButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCMenuButton::CMFCMenuButton](#cmfcmenubutton)|Constrói um objeto `CMFCMenuButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCMenuButton::PreTranslateMessage](#pretranslatemessage)|Chamado pela estrutura para converter as mensagens de janela antes de serem distribuídos. (Substitui `CMFCButton::PreTranslateMessage`.)|  
|[CMFCMenuButton::SizeToContent](#sizetocontent)|Altera o tamanho do botão de acordo com seu tamanho de texto e imagem.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCMenuButton::m_bOSMenu](#m_bosmenu)|Especifica se deve exibir o menu pop-up de sistema padrão ou usar [CContextMenuManager::TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).|  
|[CMFCMenuButton::m_bRightArrow](#m_brightarrow)|Especifica se o menu pop-up aparecerá abaixo ou à direita do botão.|  
|[CMFCMenuButton::m_bStayPressed](#m_bstaypressed)|Especifica se o botão de menu muda seu estado depois que o usuário solta o botão.|  
|[CMFCMenuButton::m_hMenu](#m_hmenu)|Um identificador para o menu do Windows anexado.|  
|[CMFCMenuButton::m_nMenuResult](#m_nmenuresult)|Um identificador que indica que o item selecionado pelo usuário no menu pop-up.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCMenuButton` classe é derivada do [CMFCButton classe](../../mfc/reference/cmfcbutton-class.md) que, por sua vez, deriva de [CButton classe](../../mfc/reference/cbutton-class.md). Portanto, você pode usar `CMFCMenuButton` em seu código da mesma maneira que você usaria `CButton`.  
  
 Quando você cria um `CMFCMenuButton`, você deve passar em um identificador para o menu pop-up associado. Em seguida, chame a função `CMFCMenuButton::SizeToContent`. `CMFCMenuButton::SizeToContent`verifica se o tamanho do botão é suficiente para incluir uma seta que aponta para o local onde a janela pop-up será exibida - ou seja, abaixo ou à direita do botão.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como definir o identificador do menu anexado ao botão, redimensionar o botão de acordo com seu tamanho de texto e imagem e definir o menu pop-up que é exibido pelo framework. Este trecho de código é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls&38;](../../mfc/reference/codesnippet/cpp/cmfcmenubutton-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls&#39;](../../mfc/reference/codesnippet/cpp/cmfcmenubutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCButton](../../mfc/reference/cmfcbutton-class.md)  
  
 [CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmenubutton.h  
  
##  <a name="a-namecmfcmenubuttona--cmfcmenubuttoncmfcmenubutton"></a><a name="cmfcmenubutton"></a>CMFCMenuButton::CMFCMenuButton  
 Constrói um novo [CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md) objeto.  
  
```  
CMFCMenuButton();
```  
  
##  <a name="a-namembosmenua--cmfcmenubuttonmbosmenu"></a><a name="m_bosmenu"></a>CMFCMenuButton::m_bOSMenu  
 Uma variável de membro booleano que indica qual menu pop-up a estrutura exibe.  
  
```  
BOOL m_bOSMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `m_bOSMenu` é `TRUE`, o framework chama o herdadas `TrackPopupMenu` método desse objeto. Caso contrário, o framework chama [CContextMenuManager::TrackPopupMenu](../../mfc/reference/ccontextmenumanager-class.md#trackpopupmenu).  
  
##  <a name="a-namembrightarrowa--cmfcmenubuttonmbrightarrow"></a><a name="m_brightarrow"></a>CMFCMenuButton::m_bRightArrow  
 Uma variável de membro booleano que indica o local do menu pop-up.  
  
```  
BOOL m_bRightArrow;  
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário pressiona o botão de menu, o aplicativo mostra um menu pop-up. O framework exibirá o menu pop-up do botão ou à direita do botão. O botão também tem uma pequena seta que indica onde o menu pop-up será exibida. Se `m_bRightArrow` é `TRUE`, o framework exibe o menu pop-up à direita do botão. Caso contrário, ele exibe o menu pop-up do botão.  
  
##  <a name="a-namembstaypresseda--cmfcmenubuttonmbstaypressed"></a><a name="m_bstaypressed"></a>CMFCMenuButton::m_bStayPressed  
 Uma variável de membro booleano que indica se o botão de menu aparece pressionado enquanto o usuário faz uma seleção no menu pop-up.  
  
```  
BOOL m_bStayPressed;  
```  
  
### <a name="remarks"></a>Comentários  
 Se o `m_bStayPressed` membro é `FALSE`, o botão de menu não se tornar pressionado quando os usos clica no botão. Nesse caso, o framework exibe apenas o menu pop-up.  
  
 Se o `m_bStayPressed` membro é `TRUE`, o botão de menu torna-se pressionada quando o usuário clica no botão. Ela permanece pressionada até depois que o usuário fecha o menu pop-up, fazendo uma seleção ou Cancelar.  
  
##  <a name="a-namemhmenua--cmfcmenubuttonmhmenu"></a><a name="m_hmenu"></a>CMFCMenuButton::m_hMenu  
 O identificador para o menu anexado.  
  
```  
HMENU m_hMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 O framework exibe o menu indicado por essa variável de membro quando o usuário clica no botão de menu.  
  
##  <a name="a-namemnmenuresulta--cmfcmenubuttonmnmenuresult"></a><a name="m_nmenuresult"></a>CMFCMenuButton::m_nMenuResult  
 Um inteiro que indica qual item o usuário seleciona o menu pop-up.  
  
```  
int m_nMenuResult;  
```  
  
### <a name="remarks"></a>Comentários  
 O valor dessa variável de membro é zero se o usuário cancelar o menu sem fazer uma seleção ou se ocorrer um erro.  
  
##  <a name="a-namepretranslatemessagea--cmfcmenubuttonpretranslatemessage"></a><a name="pretranslatemessage"></a>CMFCMenuButton::PreTranslateMessage  
 Chamado pela estrutura para converter as mensagens de janela antes de serem distribuídos.  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMsg`  
 Aponta para um [MSG](../../mfc/reference/msg-structure1.md) estrutura que contém a mensagem para processar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi convertida e não deve ser enviada; 0 se a mensagem não foi convertida e deve ser enviada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesizetocontenta--cmfcmenubuttonsizetocontent"></a><a name="sizetocontent"></a>CMFCMenuButton::SizeToContent  
 Altera o tamanho do botão de acordo com seu tamanho de texto e o tamanho da imagem.  
  
```  
virtual CSize SizeToContent(BOOL bCalcOnly = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCalcOnly`  
 Um parâmetro booleano que indica se esse método é redimensionado o botão.  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o novo tamanho do botão.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar essa função e `bCalcOnly` é `TRUE`, `SizeToContent` calculará o novo tamanho do botão.  
  
 O novo tamanho do botão é calculado de acordo com o texto do botão, a imagem e a seta. A estrutura também adiciona margens predefinidas de 10 pixels da borda horizontal e 5 pixels da borda vertical.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)


---
title: Classe COleControlContainer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleControlContainer
- AFXOCC/COleControlContainer
- AFXOCC/COleControlContainer::COleControlContainer
- AFXOCC/COleControlContainer::AttachControlSite
- AFXOCC/COleControlContainer::BroadcastAmbientPropertyChange
- AFXOCC/COleControlContainer::CheckDlgButton
- AFXOCC/COleControlContainer::CheckRadioButton
- AFXOCC/COleControlContainer::CreateControl
- AFXOCC/COleControlContainer::CreateOleFont
- AFXOCC/COleControlContainer::FindItem
- AFXOCC/COleControlContainer::FreezeAllEvents
- AFXOCC/COleControlContainer::GetAmbientProp
- AFXOCC/COleControlContainer::GetDlgItem
- AFXOCC/COleControlContainer::GetDlgItemInt
- AFXOCC/COleControlContainer::GetDlgItemText
- AFXOCC/COleControlContainer::HandleSetFocus
- AFXOCC/COleControlContainer::HandleWindowlessMessage
- AFXOCC/COleControlContainer::IsDlgButtonChecked
- AFXOCC/COleControlContainer::OnPaint
- AFXOCC/COleControlContainer::OnUIActivate
- AFXOCC/COleControlContainer::OnUIDeactivate
- AFXOCC/COleControlContainer::ScrollChildren
- AFXOCC/COleControlContainer::SendDlgItemMessage
- AFXOCC/COleControlContainer::SetDlgItemInt
- AFXOCC/COleControlContainer::SetDlgItemText
- AFXOCC/COleControlContainer::m_crBack
- AFXOCC/COleControlContainer::m_crFore
- AFXOCC/COleControlContainer::m_listSitesOrWnds
- AFXOCC/COleControlContainer::m_nWindowlessControls
- AFXOCC/COleControlContainer::m_pOleFont
- AFXOCC/COleControlContainer::m_pSiteCapture
- AFXOCC/COleControlContainer::m_pSiteFocus
- AFXOCC/COleControlContainer::m_pSiteUIActive
- AFXOCC/COleControlContainer::m_pWnd
- AFXOCC/COleControlContainer::m_siteMap
dev_langs:
- C++
helpviewer_keywords:
- COleControlContainer [MFC], COleControlContainer
- COleControlContainer [MFC], AttachControlSite
- COleControlContainer [MFC], BroadcastAmbientPropertyChange
- COleControlContainer [MFC], CheckDlgButton
- COleControlContainer [MFC], CheckRadioButton
- COleControlContainer [MFC], CreateControl
- COleControlContainer [MFC], CreateOleFont
- COleControlContainer [MFC], FindItem
- COleControlContainer [MFC], FreezeAllEvents
- COleControlContainer [MFC], GetAmbientProp
- COleControlContainer [MFC], GetDlgItem
- COleControlContainer [MFC], GetDlgItemInt
- COleControlContainer [MFC], GetDlgItemText
- COleControlContainer [MFC], HandleSetFocus
- COleControlContainer [MFC], HandleWindowlessMessage
- COleControlContainer [MFC], IsDlgButtonChecked
- COleControlContainer [MFC], OnPaint
- COleControlContainer [MFC], OnUIActivate
- COleControlContainer [MFC], OnUIDeactivate
- COleControlContainer [MFC], ScrollChildren
- COleControlContainer [MFC], SendDlgItemMessage
- COleControlContainer [MFC], SetDlgItemInt
- COleControlContainer [MFC], SetDlgItemText
- COleControlContainer [MFC], m_crBack
- COleControlContainer [MFC], m_crFore
- COleControlContainer [MFC], m_listSitesOrWnds
- COleControlContainer [MFC], m_nWindowlessControls
- COleControlContainer [MFC], m_pOleFont
- COleControlContainer [MFC], m_pSiteCapture
- COleControlContainer [MFC], m_pSiteFocus
- COleControlContainer [MFC], m_pSiteUIActive
- COleControlContainer [MFC], m_pWnd
- COleControlContainer [MFC], m_siteMap
ms.assetid: f7ce9246-0fb7-4f07-a83a-6c2390d0fdf8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0b59a1ef4d1a70063c15b7de41963abc60dd341a
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37041923"
---
# <a name="colecontrolcontainer-class"></a>Classe COleControlContainer
Atua como um contêiner de controle para controles ActiveX.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleControlContainer : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControlContainer::COleControlContainer](#colecontrolcontainer)|Constrói um objeto `COleControlContainer`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControlContainer::AttachControlSite](#attachcontrolsite)|Cria um site de controle, hospedado pelo contêiner.|  
|[COleControlContainer::BroadcastAmbientPropertyChange](#broadcastambientpropertychange)|Informa hospedados todos os controles que uma propriedade de ambiente foi alterado.|  
|[COleControlContainer::CheckDlgButton](#checkdlgbutton)|Modifica o controle de botão especificado.|  
|[COleControlContainer::CheckRadioButton](#checkradiobutton)|Seleciona o botão de opção especificado de um grupo.|  
|[COleControlContainer::CreateControl](#createcontrol)|Cria um controle ActiveX hospedado.|  
|[COleControlContainer::CreateOleFont](#createolefont)|Cria uma fonte OLE.|  
|[COleControlContainer::FindItem](#finditem)|Retorna um site personalizado do controle especificado.|  
|[COleControlContainer::FreezeAllEvents](#freezeallevents)|Determina se o site do controle está aceitando os eventos.|  
|[COleControlContainer::GetAmbientProp](#getambientprop)|Recupera a propriedade de ambiente especificada.|  
|[COleControlContainer::GetDlgItem](#getdlgitem)|Recupera o controle de caixa de diálogo especificada.|  
|[COleControlContainer::GetDlgItemInt](#getdlgitemint)|Recupera o valor do controle de caixa de diálogo especificada.|  
|[COleControlContainer::GetDlgItemText](#getdlgitemtext)|Recupera a legenda do controle de caixa de diálogo especificada.|  
|[COleControlContainer::HandleSetFocus](#handlesetfocus)|Determina se o contêiner manipula mensagens WM_SETFOCUS.|  
|[COleControlContainer::HandleWindowlessMessage](#handlewindowlessmessage)|Manipula mensagens enviadas para um controle sem janelas.|  
|[COleControlContainer::IsDlgButtonChecked](#isdlgbuttonchecked)|Determina o estado do botão especificado.|  
|[COleControlContainer::OnPaint](#onpaint)|Chamado para redesenhar uma parte do contêiner.|  
|[COleControlContainer::OnUIActivate](#onuiactivate)|Chamado quando um controle está prestes a ser ativado no local.|  
|[COleControlContainer::OnUIDeactivate](#onuideactivate)|Chamado quando um controle está prestes a ser desativada.|  
|[COleControlContainer::ScrollChildren](#scrollchildren)|Chamado pelo framework quando as mensagens de rolagem são recebidas de uma janela filho.|  
|[COleControlContainer::SendDlgItemMessage](#senddlgitemmessage)|Envia uma mensagem para o controle especificado.|  
|[COleControlContainer::SetDlgItemInt](#setdlgitemint)|Define o valor do controle especificado.|  
|[COleControlContainer::SetDlgItemText](#setdlgitemtext)|Define o texto do controle especificado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControlContainer::m_crBack](#m_crback)|A cor de plano de fundo do contêiner.|  
|[COleControlContainer::m_crFore](#m_crfore)|A cor de primeiro plano do contêiner.|  
|[COleControlContainer::m_listSitesOrWnds](#m_listsitesorwnds)|Uma lista de sites com suporte do controle.|  
|[COleControlContainer::m_nWindowlessControls](#m_nwindowlesscontrols)|O número de controles sem janelas hospedados.|  
|[COleControlContainer::m_pOleFont](#m_polefont)|Um ponteiro para a fonte OLE do site do controle personalizado.|  
|[COleControlContainer::m_pSiteCapture](#m_psitecapture)|Ponteiro para o site de controle de captura.|  
|[COleControlContainer::m_pSiteFocus](#m_psitefocus)|Ponteiro para o controle que atualmente tem foco de entrada.|  
|[COleControlContainer::m_pSiteUIActive](#m_psiteuiactive)|Ponteiro para o controle que está sendo ativado no local.|  
|[COleControlContainer::m_pWnd](#m_pwnd)|Ponteiro para a janela de implementar o contêiner de controle.|  
|[COleControlContainer::m_siteMap](#m_sitemap)|O mapa do site.|  
  
## <a name="remarks"></a>Comentários  
 Isso é feito fornecendo suporte para um ou mais sites de controle ActiveX (implementado pelo `COleControlSite`). `COleControlContainer` implementa totalmente a [IOleInPlaceFrame](http://msdn.microsoft.com/library/windows/desktop/ms692770) e [IOleContainer](http://msdn.microsoft.com/library/windows/desktop/ms690103) interfaces, permitindo que os controles ActiveX independentes atender suas qualificações como itens no local.  
  
 Normalmente, essa classe é usada em conjunto com `COccManager` e `COleControlSite` para implementar um contêiner de controle ActiveX personalizado, com sites personalizados para um ou mais controles ActiveX.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `COleControlContainer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxocc.h  
  
##  <a name="attachcontrolsite"></a>  COleControlContainer::AttachControlSite  
 Chamado pelo framework para criar e anexar um site de controle.  
  
```  
virtual void AttachControlSite(
    CWnd* pWnd,  
    UINT nIDC = 0);

 
void AttachControlSite(
    CWnd* pWnd,  
    UINT nIDC = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWnd*  
 Um ponteiro para um `CWnd` objeto.  
  
 *nIDC*  
 A ID do controle a ser anexado.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se você quiser personalizar esse processo.  
  
> [!NOTE]
>  Use o primeiro formulário dessa função, se você está vinculando estaticamente a biblioteca do MFC. Use o segundo formulário se você está vinculando dinamicamente a biblioteca do MFC.  
  
##  <a name="broadcastambientpropertychange"></a>  COleControlContainer::BroadcastAmbientPropertyChange  
 Informa hospedados todos os controles que uma propriedade de ambiente foi alterado.  
  
```  
virtual void BroadcastAmbientPropertyChange(DISPID dispid);
```  
  
### <a name="parameters"></a>Parâmetros  
 *DISPID*  
 A ID de expedição da propriedade de ambiente que está sendo alterada.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pelo framework quando uma propriedade de ambiente tiver alterado o valor. Substitua essa função para personalizar esse comportamento.  
  
##  <a name="checkdlgbutton"></a>  COleControlContainer::CheckDlgButton  
 Modifica o estado atual do botão.  
  
```  
virtual void CheckDlgButton(
    int nIDButton,  
    UINT nCheck);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDButton*  
 A ID do botão a ser modificado.  
  
 *nVerifique*  
 Especifica o estado do botão. Pode ser um dos seguintes:  
  
- **BST_CHECKED** define o estado do botão ativação.  
  
- **BST_INDETERMINATE** define o estado do botão como cinza, que indica um estado indeterminado. Use esse valor somente se o botão tem o **BS_3STATE** ou **BS_AUTO3STATE** estilo.  
  
- **BST_UNCHECKED** define o estado do botão como desmarcados.  
  
##  <a name="checkradiobutton"></a>  COleControlContainer::CheckRadioButton  
 Seleciona um botão de opção especificado em um grupo e limpa os botões restantes no grupo.  
  
```  
virtual void CheckRadioButton(
    int nIDFirstButton,  
    int nIDLastButton,  
    int nIDCheckButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDFirstButton*  
 Especifica o identificador do primeiro botão de opção no grupo.  
  
 *nIDLastButton*  
 Especifica o identificador do último botão de opção no grupo.  
  
 *nIDCheckButton*  
 Especifica o identificador do botão de opção a ser verificada.  
  
##  <a name="colecontrolcontainer"></a>  COleControlContainer::COleControlContainer  
 Constrói um objeto `COleControlContainer`.  
  
```  
explicit COleControlContainer(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWnd*  
 Um ponteiro para a janela pai do contêiner de controle.  
  
### <a name="remarks"></a>Comentários  
 Depois que o objeto foi criado com êxito, adicionar um site de controle personalizado com uma chamada para `AttachControlSite`.  
  
##  <a name="createcontrol"></a>  COleControlContainer::CreateControl  
 Cria um controle ActiveX, hospedado pelo especificado `COleControlSite` objeto.  
  
```  
BOOL CreateControl(
    CWnd* pWndCtrl,  
    REFCLSID clsid,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    UINT nID,  
    CFile* pPersist =NULL,  
    BOOL bStorage =FALSE,  
    BSTR bstrLicKey =NULL,  
    COleControlSite** ppNewSite =NULL);

 
BOOL CreateControl(
    CWnd* pWndCtrl,  
    REFCLSID clsid,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const POINT* ppt,  
    const SIZE* psize,  
    UINT nID,  
    CFile* pPersist =NULL,  
    BOOL bStorage =FALSE,  
    BSTR bstrLicKey =NULL,  
    COleControlSite** ppNewSite =NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndCtrl*  
 Um ponteiro para o objeto de janela que representa o controle.  
  
 *clsid*  
 A ID exclusiva de classe do controle.  
  
 *lpszWindowName*  
 Um ponteiro para o texto a ser exibido no controle. Define o valor da propriedade de legenda ou o texto do controle (se houver). Se **nulo**, propriedade de legenda ou o texto do controle não será alterada.  
  
 *dwStyle*  
 Estilos de Windows. Os estilos disponíveis são listados sob o **comentários** seção.  
  
 *Rect*  
 Especifica o tamanho e a posição do controle. Ele pode ser um `CRect` objeto ou um `RECT` estrutura.  
  
 *nID*  
 Especifica a ID de janela filho do controle  
  
 *pPersist*  
 Um ponteiro para um `CFile` que contém o estado persistente para o controle. O valor padrão é **nulo**, indicando que o controle inicializa a próprio sem restaurar o estado de qualquer armazenamento persistente. Se não **nulo**, ele deve ser um ponteiro para um `CFile`-derivados do objeto que contém os dados do controle persistente, na forma de um fluxo ou de armazenamento. Esses dados podem ter sido salvo em uma ativação anterior do cliente. O `CFile` pode conter outros dados, mas deve ter o ponteiro de leitura-gravação definido como o primeiro byte de dados persistentes no momento da chamada para `CreateControl`.  
  
 *bStorage*  
 Indica se os dados em *pPersist* devem ser interpretadas como `IStorage` ou `IStream` dados. Se os dados em *pPersist* é um armazenamento *bStorage* devem ser **TRUE**. Se os dados em *pPersist* é um fluxo *bStorage* devem ser **FALSE**. O valor padrão é **FALSE**.  
  
 *bstrLicKey*  
 Dados opcionais de chave de licença. Esses dados é necessária somente para a criação de controles que exigem uma chave de licença de tempo de execução. Se o controle dá suporte ao licenciamento, você deve fornecer uma chave de licença para a criação do controle seja bem-sucedida. O valor padrão é **nulo**.  
  
 *ppNewSite*  
 Um ponteiro para o site de controle existente que hospedará o controle que está sendo criado. O valor padrão é **nulo**, indicando que um novo site de controle será automaticamente criado e anexado ao novo controle.  
  
 *ppt*  
 Um ponteiro para um **ponto** estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor de *psize*. O *ppt* e *psize* os valores são um método opcional para especificar o tamanho e a posição do controle.  
  
 *psize*  
 Um ponteiro para um **tamanho** estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de *ppt*. O *ppt* e *psize* os valores são um método opcional para especificar o tamanho e a posição do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Apenas um subconjunto das janelas de *dwStyle* sinalizadores são suportados pelo `CreateControl`:  
  
- **WS_VISIBLE** cria uma janela que é visível inicialmente. Necessário se você quiser que o controle esteja visível imediatamente, como janelas comuns.  
  
- **WS_DISABLED** cria uma janela que é inicialmente desabilitada. Uma janela desabilitada não pode receber entrada do usuário. Pode ser definido se o controle tiver uma propriedade Enabled.  
  
- **WS_BORDER** cria uma janela com uma borda de linha fina. Pode ser definido se o controle tem uma propriedade BorderStyle.  
  
- **WS_GROUP** Especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para o próximo usando as teclas de direção. Todos os controles definidos com o **WS_GROUP** após o primeiro controle pertencem ao mesmo grupo de estilo. O próximo controle com o **WS_GROUP** estilo encerra o grupo e inicia o próximo grupo.  
  
- **WS_TABSTOP** Especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do **WS_TABSTOP** estilo.  
  
 Use a segunda sobrecarga para criar controles de tamanho padrão.  
  
##  <a name="createolefont"></a>  COleControlContainer::CreateOleFont  
 Cria uma fonte OLE.  
  
```  
void CreateOleFont(CFont* pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pFont*  
 Um ponteiro para a fonte a ser usada pelo contêiner de controle.  
  
##  <a name="finditem"></a>  COleControlContainer::FindItem  
 Localiza um site personalizado que hospeda o item especificado.  
  
```  
virtual COleControlSite* FindItem(UINT nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 O identificador do item a ser localizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um site personalizado do item especificado.  
  
##  <a name="freezeallevents"></a>  COleControlContainer::FreezeAllEvents  
 Determina se o contêiner irá ignorar os eventos dos sites do controle anexado ou aceitá-los.  
  
```  
void FreezeAllEvents(BOOL bFreeze);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bFreeze*  
 Diferente de zero se os eventos serão processados; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O controle não é necessário para interromper eventos acionados, se solicitado pelo contêiner de controle. Ele pode continuar acionando mas todos os eventos subsequentes serão ignorados pelo contêiner de controle.  
  
##  <a name="getambientprop"></a>  COleControlContainer::GetAmbientProp  
 Recupera o valor de uma propriedade de ambiente especificada.  
  
```  
virtual BOOL GetAmbientProp(
    COleControlSite* pSite,  
    DISPID dispid,  
    VARIANT* pvarResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSite*  
 Um ponteiro para um site de controle do qual a propriedade de ambiente será recuperada.  
  
 *DISPID*  
 A ID de expedição da propriedade ambiente desejada.  
  
 *pVarResult*  
 Um ponteiro para o valor da propriedade de ambiente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="getdlgitem"></a>  COleControlContainer::GetDlgItem  
 Recupera um ponteiro para a janela de controle ou filho especificada na caixa de diálogo ou em outra janela.  
  
```  
virtual CWnd* GetDlgItem(int nID) const;  
  
virtual void GetDlgItem(
    int nID,  
    HWND* phWnd) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 Identificador do item da caixa de diálogo para recuperar.  
  
 *phWnd*  
 Um ponteiro para o identificador do item de caixa de diálogo especificada objeto de janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela do item da caixa de diálogo.  
  
##  <a name="getdlgitemint"></a>  COleControlContainer::GetDlgItemInt  
 Recupera o valor do texto traduzido do controle especificado.  
  
```  
virtual UINT GetDlgItemInt(
    int nID,  
    BOOL* lpTrans,  
    BOOL bSigned) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 O identificador do controle.  
  
 *lpTrans*  
 Ponteiro para uma variável booleana que recebe um valor de êxito/falha de função ( **TRUE** indica êxito, **FALSE** indica falha).  
  
 *bSigned*  
 Especifica se a função deve examinar o texto de um sinal de menos no início e retornar um valor inteiro se encontrar um. Se o *bSigned* parâmetro é **TRUE**, especificando o valor a ser recuperado é um valor inteiro com sinal, converter o valor de retorno para um **int** tipo. Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a variável apontada pelo *lpTrans* é definido como **TRUE**, e o valor de retorno é o valor traduzido do texto do controle.  
  
 Se a função falhar, a variável apontada pelo *lpTrans* é definido como **FALSE**, e o valor de retorno é zero. Observe que, como zero é um possível valor traduzido, um valor de retorno de zero, não por si só indica falha.  
  
 Se *lpTrans* é **nulo**, a função não retorna nenhuma informação sobre o êxito ou falha.  
  
### <a name="remarks"></a>Comentários  
 A função converte o texto recuperado pela remoção de todos os espaços adicionais no início do texto e, em seguida, converter os dígitos decimais. A função para a conversão quando atingir o final do texto ou encontrar um caractere numérico.  
  
 Esta função retornará zero se o valor convertido é maior do que **INT_MAX** (para números assinados) ou **UINT_MAX** (para números sem sinal).  
  
##  <a name="getdlgitemtext"></a>  COleControlContainer::GetDlgItemText  
 Recupera o texto do controle especificado.  
  
```  
virtual int GetDlgItemText(
    int nID,  
    LPTSTR lpStr,  
    int nMaxCount) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 O identificador do controle.  
  
 *lpStr*  
 Ponteiro para o texto do controle.  
  
 *nMaxCount*  
 Especifica o tamanho máximo, em caracteres, da cadeia de caracteres a serem copiados para o buffer apontado pelo *lpStr*. Se o comprimento da cadeia de caracteres excede o limite, a cadeia de caracteres está truncada.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função tiver êxito, o valor de retorno Especifica o número de caracteres copiados para o buffer, não incluindo o caractere null de terminação.  
  
 Se a função falhar, o valor retornado será zero. Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
##  <a name="handlesetfocus"></a>  COleControlContainer::HandleSetFocus  
 Determina se o contêiner manipula mensagens WM_SETFOCUS.  
  
```  
virtual BOOL HandleSetFocus();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contêiner manipula mensagens WM_SETFOCUS; Caso contrário, zero.  
  
##  <a name="handlewindowlessmessage"></a>  COleControlContainer::HandleWindowlessMessage  
 Processa as mensagens de janela para controles sem janelas.  
  
```  
virtual BOOL HandleWindowlessMessage(
    UINT message,  
    WPARAM wParam,  
    LPARAM lParam,  
    LRESULT* plResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 *message*  
 O identificador para a mensagem de janela, fornecida pelo Windows.  
  
 *wParam*  
 Parâmetro da mensagem; fornecido pelo Windows. Especifica informações adicionais de mensagem específica. O conteúdo deste parâmetro depende do valor da *mensagem* parâmetro.  
  
 *lParam*  
 Parâmetro da mensagem; fornecido pelo Windows. Especifica informações adicionais de mensagem específica. O conteúdo deste parâmetro depende do valor da *mensagem* parâmetro.  
  
 *plResult*  
 Código de resultado do Windows. Especifica o resultado do processamento de mensagem e depende da mensagem enviada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Substitua esta função para personalizar o tratamento de mensagens de controle sem janelas.  
  
##  <a name="isdlgbuttonchecked"></a>  COleControlContainer::IsDlgButtonChecked  
 Determina o estado do botão especificado.  
  
```  
virtual UINT IsDlgButtonChecked(int nIDButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDButton*  
 O identificador do controle de botão.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno de um botão criado com o **BS_AUTOCHECKBOX**, **BS_AUTORADIOBUTTON**, **BS_AUTO3STATE**, **BS_CHECKBOX**, **BS_RADIOBUTTON**, ou **BS_3STATE** estilo. Pode ser um dos seguintes:  
  
- **BST_CHECKED** botão está marcado.  
  
- **BST_INDETERMINATE** botão estiver acinzentado, que indica um estado indeterminado (aplica-se apenas se o botão tiver o **BS_3STATE** ou **BS_AUTO3STATE** estilo).  
  
- **BST_UNCHECKED** botão está desmarcado.  
  
### <a name="remarks"></a>Comentários  
 Se o botão é um controle de três estados, a função de membro determina se ele estiver esmaecido, marcada, ou nenhum deles.  
  
##  <a name="m_crback"></a>  COleControlContainer::m_crBack  
 A cor de plano de fundo do contêiner.  
  
```  
COLORREF m_crBack;  
```  
  
##  <a name="m_crfore"></a>  COleControlContainer::m_crFore  
 A cor de primeiro plano do contêiner.  
  
```  
COLORREF m_crFore;  
```  
  
##  <a name="m_listsitesorwnds"></a>  COleControlContainer::m_listSitesOrWnds  
 Uma lista de controle sites hospedados pelo contêiner.  
  
```  
CTypedPtrList<CPtrList, COleControlSiteOrWnd*> m_listSitesOrWnds;  
```  
  
##  <a name="m_nwindowlesscontrols"></a>  COleControlContainer::m_nWindowlessControls  
 O número de controles sem janelas hospedado pelo contêiner de controle.  
  
```  
int m_nWindowlessControls;  
```  
  
##  <a name="m_polefont"></a>  COleControlContainer::m_pOleFont  
 Um ponteiro para a fonte OLE do site do controle personalizado.  
  
```  
LPFONTDISP m_pOleFont;  
```  
  
##  <a name="m_psitecapture"></a>  COleControlContainer::m_pSiteCapture  
 Ponteiro para o site de controle de captura.  
  
```  
COleControlSite* m_pSiteCapture;  
```  
  
##  <a name="m_psitefocus"></a>  COleControlContainer::m_pSiteFocus  
 Um ponteiro para o site de controle que atualmente tem foco de entrada.  
  
```  
COleControlSite* m_pSiteFocus;  
```  
  
##  <a name="m_psiteuiactive"></a>  COleControlContainer::m_pSiteUIActive  
 Um ponteiro para o site de controle que é ativado no local.  
  
```  
COleControlSite* m_pSiteUIActive;  
```  
  
##  <a name="m_pwnd"></a>  COleControlContainer::m_pWnd  
 Um ponteiro para o objeto de janela associado ao contêiner.  
  
```  
CWnd* m_pWnd;  
```  
  
##  <a name="m_sitemap"></a>  COleControlContainer::m_siteMap  
 O mapa do site.  
  
```  
CMapPtrToPtr m_siteMap;  
```  
  
##  <a name="onpaint"></a>  COleControlContainer::OnPaint  
 Chamado pelo framework para manipular solicitações WM_PAINT.  
  
```  
virtual BOOL OnPaint(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Um ponteiro para o contexto de dispositivo usado pelo contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi tratada; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Substitua esta função para personalizar o processo de pintura.  
  
##  <a name="onuiactivate"></a>  COleControlContainer::OnUIActivate  
 Chamado pelo framework quando o site de controle, apontada pelo *pSite*, está prestes a ser ativado no local.  
  
```  
virtual void OnUIActivate(COleControlSite* pSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSite*  
 Um ponteiro para o site de controle prestes a ser ativado no local.  
  
### <a name="remarks"></a>Comentários  
 Ativação no local significa que o menu principal do contêiner é substituído por um menu composto no local.  
  
##  <a name="onuideactivate"></a>  COleControlContainer::OnUIDeactivate  
 Chamado pelo framework quando o site de controle, apontada pelo *pSite*, está prestes a ser desativado.  
  
```  
virtual void OnUIDeactivate(COleControlSite* pSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSite*  
 Um ponteiro para o site de controle prestes a ser desativada.  
  
### <a name="remarks"></a>Comentários  
 Quando essa notificação é recebida, o contêiner deve reinstalar sua interface de usuário e definir o foco.  
  
##  <a name="scrollchildren"></a>  COleControlContainer::ScrollChildren  
 Chamado pelo framework quando as mensagens de rolagem são recebidas de uma janela filho.  
  
```  
virtual void ScrollChildren(
    int dx,  
    int dy);
```  
  
### <a name="parameters"></a>Parâmetros  
 *DX*  
 A quantidade, em pixels, da rolagem ao longo do eixo x.  
  
 *dy*  
 A quantidade, em pixels, da rolagem ao longo do eixo y.  
  
##  <a name="senddlgitemmessage"></a>  COleControlContainer::SendDlgItemMessage  
 Envia uma mensagem para o controle especificado.  
  
```  
virtual LRESULT SendDlgItemMessage(
    int nID,  
    UINT message,  
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 Especifica o identificador do controle que recebe a mensagem.  
  
 *message*  
 Especifica a mensagem a ser enviada.  
  
 *wParam*  
 Especifica informações adicionais de mensagem específica.  
  
 *lParam*  
 Especifica informações adicionais de mensagem específica.  
  
##  <a name="setdlgitemint"></a>  COleControlContainer::SetDlgItemInt  
 Define o texto de um controle em uma caixa de diálogo para a representação de cadeia de caracteres de um valor inteiro especificado.  
  
```  
virtual void SetDlgItemInt(
    int nID,  
    UINT nValue,  
    BOOL bSigned);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 O identificador do controle.  
  
 *Nvalor*  
 O valor inteiro a ser exibido.  
  
 *bSigned*  
 Especifica se o *Nvalor* parâmetro está assinado ou não assinado. Se esse parâmetro for **TRUE**, *Nvalor* está assinado. Se esse parâmetro for **TRUE** e *Nvalor* é menor que zero, um sinal de subtração sinal é colocado antes do primeiro dígito na cadeia de caracteres. Se esse parâmetro for **FALSE**, *Nvalor* não está assinado.  
  
##  <a name="setdlgitemtext"></a>  COleControlContainer::SetDlgItemText  
 Define o texto do controle especificado, usando o texto contido em *lpszString*.  
  
```  
virtual void SetDlgItemText(
    int nID,  
    LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 O identificador do controle.  
  
 *lpszString*  
 Ponteiro para o texto do controle.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)   
 [Classe COccManager](../../mfc/reference/coccmanager-class.md)

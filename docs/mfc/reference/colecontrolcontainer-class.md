---
title: Classe COleControlContainer
ms.date: 11/04/2016
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
ms.openlocfilehash: 3aa2515b1731eafcb5e3bcfa22a56ebbc1cdfdfb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504320"
---
# <a name="colecontrolcontainer-class"></a>Classe COleControlContainer

Atua como um contêiner de controle para controles ActiveX.

## <a name="syntax"></a>Sintaxe

```
class COleControlContainer : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlContainer::COleControlContainer](#colecontrolcontainer)|Constrói um objeto `COleControlContainer`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlContainer::AttachControlSite](#attachcontrolsite)|Cria um site de controle, hospedado pelo contêiner.|
|[COleControlContainer::BroadcastAmbientPropertyChange](#broadcastambientpropertychange)|Informa todos os controles hospedados que uma propriedade de ambiente alterou.|
|[COleControlContainer::CheckDlgButton](#checkdlgbutton)|Modifica o controle de botão especificado.|
|[COleControlContainer::CheckRadioButton](#checkradiobutton)|Seleciona o botão de opção especificado de um grupo.|
|[COleControlContainer::CreateControl](#createcontrol)|Cria um controle ActiveX hospedado.|
|[COleControlContainer::CreateOleFont](#createolefont)|Cria uma fonte OLE.|
|[COleControlContainer::FindItem](#finditem)|Retorna o site personalizado do controle especificado.|
|[COleControlContainer::FreezeAllEvents](#freezeallevents)|Determina se o site de controle está aceitando eventos.|
|[COleControlContainer::GetAmbientProp](#getambientprop)|Recupera a propriedade de ambiente especificada.|
|[COleControlContainer::GetDlgItem](#getdlgitem)|Recupera o controle de diálogo especificado.|
|[COleControlContainer::GetDlgItemInt](#getdlgitemint)|Recupera o valor do controle de caixa de diálogo especificado.|
|[COleControlContainer::GetDlgItemText](#getdlgitemtext)|Recupera a legenda do controle de caixa de diálogo especificado.|
|[COleControlContainer::HandleSetFocus](#handlesetfocus)|Determina se o contêiner manipula mensagens WM_SETFOCUS.|
|[COleControlContainer::HandleWindowlessMessage](#handlewindowlessmessage)|Lida com mensagens enviadas a um controle sem janela.|
|[COleControlContainer::IsDlgButtonChecked](#isdlgbuttonchecked)|Determina o estado do botão especificado.|
|[COleControlContainer::OnPaint](#onpaint)|Chamado para redesenhar uma parte do contêiner.|
|[COleControlContainer::OnUIActivate](#onuiactivate)|Chamado quando um controle está prestes a ser ativado no local.|
|[COleControlContainer::OnUIDeactivate](#onuideactivate)|Chamado quando um controle está prestes a ser desativado.|
|[COleControlContainer::ScrollChildren](#scrollchildren)|Chamado pelo Framework quando as mensagens de rolagem são recebidas de uma janela filho.|
|[COleControlContainer::SendDlgItemMessage](#senddlgitemmessage)|Envia uma mensagem para o controle especificado.|
|[COleControlContainer::SetDlgItemInt](#setdlgitemint)|Define o valor do controle especificado.|
|[COleControlContainer::SetDlgItemText](#setdlgitemtext)|Define o texto do controle especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlContainer::m_crBack](#m_crback)|A cor do plano de fundo do contêiner.|
|[COleControlContainer::m_crFore](#m_crfore)|A cor de primeiro plano do contêiner.|
|[COleControlContainer::m_listSitesOrWnds](#m_listsitesorwnds)|Uma lista dos sites de controle com suporte.|
|[COleControlContainer::m_nWindowlessControls](#m_nwindowlesscontrols)|O número de controles hospedados sem janela.|
|[COleControlContainer::m_pOleFont](#m_polefont)|Um ponteiro para a fonte OLE do site de controle personalizado.|
|[COleControlContainer::m_pSiteCapture](#m_psitecapture)|Ponteiro para o site de controle de captura.|
|[COleControlContainer::m_pSiteFocus](#m_psitefocus)|Ponteiro para o controle que atualmente tem o foco de entrada.|
|[COleControlContainer::m_pSiteUIActive](#m_psiteuiactive)|Ponteiro para o controle que está no local ativado no momento.|
|[COleControlContainer::m_pWnd](#m_pwnd)|Ponteiro para a janela que implementa o contêiner de controle.|
|[COleControlContainer::m_siteMap](#m_sitemap)|O mapa do site.|

## <a name="remarks"></a>Comentários

Isso é feito fornecendo suporte para um ou mais sites de controle ActiveX (implementados `COleControlSite`pelo). `COleControlContainer`implementa totalmente as interfaces [IOleInPlaceFrame](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceframe) e [IOleContainer](/windows/win32/api/oleidl/nn-oleidl-iolecontainer) , permitindo que os controles ActiveX contidos atendam suas qualificações como itens in-loco.

Normalmente, essa classe é usada em conjunto com `COccManager` e `COleControlSite` para implementar um contêiner personalizado de controle ActiveX, com sites personalizados para um ou mais controles ActiveX.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleControlContainer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxocc. h

##  <a name="attachcontrolsite"></a>  COleControlContainer::AttachControlSite

Chamado pelo Framework para criar e anexar um site de controle.

```
virtual void AttachControlSite(
    CWnd* pWnd,
    UINT nIDC = 0);

void AttachControlSite(
    CWnd* pWnd,
    UINT nIDC = 0);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para um `CWnd` objeto.

*nIDC*<br/>
A ID do controle a ser anexado.

### <a name="remarks"></a>Comentários

Substitua essa função se desejar personalizar esse processo.

> [!NOTE]
>  Use a primeira forma dessa função se você estiver vinculando estaticamente à biblioteca do MFC. Use o segundo formulário se você estiver vinculando dinamicamente à biblioteca do MFC.

##  <a name="broadcastambientpropertychange"></a>  COleControlContainer::BroadcastAmbientPropertyChange

Informa todos os controles hospedados que uma propriedade de ambiente alterou.

```
virtual void BroadcastAmbientPropertyChange(DISPID dispid);
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
A ID de expedição da propriedade de ambiente que está sendo alterada.

### <a name="remarks"></a>Comentários

Essa função é chamada pelo Framework quando uma propriedade de ambiente tem um valor alterado. Substitua essa função para personalizar esse comportamento.

##  <a name="checkdlgbutton"></a>  COleControlContainer::CheckDlgButton

Modifica o estado atual do botão.

```
virtual void CheckDlgButton(
    int nIDButton,
    UINT nCheck);
```

### <a name="parameters"></a>Parâmetros

*nIDButton*<br/>
A ID do botão a ser modificado.

*nVerifique*<br/>
Especifica o estado do botão. Pode ser um dos seguintes:

- BST_CHECKED define o estado do botão como marcado.

- BST_INDETERMINATE define o estado do botão como esmaecido, indicando um estado indeterminado. Use esse valor somente se o botão tiver o estilo BS_3STATE ou BS_AUTO3STATE.

- BST_UNCHECKED Define o estado do botão como limpo.

##  <a name="checkradiobutton"></a>  COleControlContainer::CheckRadioButton

Seleciona um botão de opção especificado em um grupo e limpa os botões restantes no grupo.

```
virtual void CheckRadioButton(
    int nIDFirstButton,
    int nIDLastButton,
    int nIDCheckButton);
```

### <a name="parameters"></a>Parâmetros

*nIDFirstButton*<br/>
Especifica o identificador do primeiro botão de opção no grupo.

*nIDLastButton*<br/>
Especifica o identificador do último botão de opção no grupo.

*nIDCheckButton*<br/>
Especifica o identificador do botão de opção a ser verificado.

##  <a name="colecontrolcontainer"></a>  COleControlContainer::COleControlContainer

Constrói um objeto `COleControlContainer`.

```
explicit COleControlContainer(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para a janela pai do contêiner de controle.

### <a name="remarks"></a>Comentários

Depois que o objeto tiver sido criado com êxito, adicione um site de controle personalizado com uma `AttachControlSite`chamada para.

##  <a name="createcontrol"></a>  COleControlContainer::CreateControl

Cria um controle ActiveX, hospedado pelo objeto especificado `COleControlSite` .

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

*pWndCtrl*<br/>
Um ponteiro para o objeto de janela que representa o controle.

*clsid*<br/>
A ID de classe exclusiva do controle.

*lpszWindowName*<br/>
Um ponteiro para o texto a ser exibido no controle. Define o valor da legenda do controle ou da propriedade Text (se houver). Se for NULL, a legenda do controle ou a propriedade Text não será alterada.

*dwStyle*<br/>
Estilos do Windows. Os estilos disponíveis são listados na seção **comentários** .

*rect*<br/>
Especifica o tamanho e a posição do controle. Pode ser um `CRect` objeto ou uma `RECT` estrutura.

*nID*<br/>
Especifica a ID da janela filho do controle.

*pPersist*<br/>
Um ponteiro para um `CFile` que contém o estado persistente do controle. O valor padrão é NULL, indicando que o controle inicializa a si mesmo sem restaurar seu estado a partir de qualquer armazenamento persistente. Se não for NULL, deve ser um ponteiro para um `CFile`objeto derivado que contém os dados persistentes do controle, na forma de um fluxo ou um armazenamento. Esses dados podem ter sido salvos em uma ativação anterior do cliente. O `CFile` pode conter outros dados, mas deve ter seu ponteiro de leitura/gravação definido como o primeiro byte de dados persistentes no momento da chamada para `CreateControl`.

*bStorage*<br/>
Indica se os dados em *pPersist* devem ser interpretados `IStream` como `IStorage` ou dados. Se os dados no *pPersist* forem um armazenamento, *BSTORAGE* deverá ser verdadeiro. Se os dados em *pPersist* forem um fluxo, *BSTORAGE* deverá ser false. O valor padrão é FALSE.

*bstrLicKey*<br/>
Dados de chave de licença opcionais. Esses dados são necessários apenas para a criação de controles que exigem uma chave de licença em tempo de execução. Se o controle oferecer suporte a licenciamento, você deverá fornecer uma chave de licença para que a criação do controle seja realizada com sucesso. O valor padrão é NULL.

*ppNewSite*<br/>
Um ponteiro para o site de controle existente que hospedará o controle que está sendo criado. O valor padrão é NULL, indicando que um novo site de controle será criado automaticamente e anexado ao novo controle.

*ppt*<br/>
Um ponteiro para uma `POINT` estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor de *psize*. Os valores de *ppt* e *psize* são um método opcional para especificar o tamanho e a posição do controle.

*psize*<br/>
Um ponteiro para uma `SIZE` estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de *ppt*. Os valores de *ppt* e *psize* são um método opcional para especificar o tamanho e a posição do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Somente um subconjunto dos sinalizadores *dwStyle* do Windows tem suporte `CreateControl`no:

- WS_VISIBLE cria uma janela que inicialmente é visível. Necessário se você quiser que o controle seja visível imediatamente, como janelas comuns.

- WS_DISABLED Cria uma janela que está inicialmente desabilitada. Uma janela desabilitada não pode receber entrada do usuário. Pode ser definido se o controle tiver uma propriedade habilitada.

- WS_BORDER cria uma janela com uma borda de linha fina. Pode ser definido se o controle tiver uma propriedade BorderStyle.

- WS_GROUP especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para o próximo usando as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP encerra o grupo e inicia o próximo grupo.

- WS_TABSTOP especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do estilo WS_TABSTOP.

Use a segunda sobrecarga para criar controles de tamanho padrão.

##  <a name="createolefont"></a>  COleControlContainer::CreateOleFont

Cria uma fonte OLE.

```
void CreateOleFont(CFont* pFont);
```

### <a name="parameters"></a>Parâmetros

*pFont*<br/>
Um ponteiro para a fonte a ser usada pelo contêiner de controle.

##  <a name="finditem"></a>  COleControlContainer::FindItem

Localiza o site personalizado que hospeda o item especificado.

```
virtual COleControlSite* FindItem(UINT nID) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do item a ser encontrado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o site personalizado do item especificado.

##  <a name="freezeallevents"></a>  COleControlContainer::FreezeAllEvents

Determina se o contêiner irá ignorar eventos dos sites de controle anexados ou aceitá-los.

```
void FreezeAllEvents(BOOL bFreeze);
```

### <a name="parameters"></a>Parâmetros

*bFreeze*<br/>
Diferente de zero se os eventos forem processados; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  O controle não é necessário para parar de acionar eventos, se solicitado pelo contêiner de controle. Ele pode continuar acionando, mas todos os eventos subsequentes serão ignorados pelo contêiner de controle.

##  <a name="getambientprop"></a>  COleControlContainer::GetAmbientProp

Recupera o valor de uma propriedade de ambiente especificada.

```
virtual BOOL GetAmbientProp(
    COleControlSite* pSite,
    DISPID dispid,
    VARIANT* pvarResult);
```

### <a name="parameters"></a>Parâmetros

*pSite*<br/>
Um ponteiro para um site de controle do qual a propriedade de ambiente será recuperada.

*dispid*<br/>
A ID de expedição da propriedade de ambiente desejada.

*pVarResult*<br/>
Um ponteiro para o valor da propriedade de ambiente.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="getdlgitem"></a>  COleControlContainer::GetDlgItem

Recupera um ponteiro para o controle especificado ou a janela filho em uma caixa de diálogo ou outra janela.

```
virtual CWnd* GetDlgItem(int nID) const;

virtual void GetDlgItem(
    int nID,
    HWND* phWnd) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Identificador do item de diálogo a ser recuperado.

*phWnd*<br/>
Um ponteiro para o identificador do objeto de janela do item de diálogo especificado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela do item de diálogo.

##  <a name="getdlgitemint"></a>  COleControlContainer::GetDlgItemInt

Recupera o valor do texto traduzido do controle fornecido.

```
virtual UINT GetDlgItemInt(
    int nID,
    BOOL* lpTrans,
    BOOL bSigned) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*lpTrans*<br/>
Ponteiro para uma variável booliana que recebe um valor de êxito/falha de função (verdadeiro indica êxito, falso indica falha).

*bSigned*<br/>
Especifica se a função deve examinar o texto de um sinal de subtração no início e retornar um valor inteiro assinado, caso encontre um. Se o parâmetro *bSigned* for true, especificando que o valor a ser recuperado é um valor inteiro assinado, converta o valor de retorno para um tipo **int** . Para obter informações de erro estendidas, chame [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, a variável apontada por *lpTrans* será definida como true e o valor de retorno será o valor traduzido do texto de controle.

Se a função falhar, a variável apontada por *lpTrans* será definida como false e o valor de retorno será zero. Observe que, como zero é um valor traduzido possível, um valor de retorno igual a zero não indica falha.

Se *lpTrans* for NULL, a função não retornará nenhuma informação sobre êxito ou falha.

### <a name="remarks"></a>Comentários

A função traduz o texto recuperado removendo espaços extras no início do texto e, em seguida, convertendo os dígitos decimais. A função interrompe a tradução quando atinge o final do texto ou encontra um caractere não numérico.

Essa função retornará zero se o valor traduzido for maior que INT_MAX (para números assinados) ou UINT_MAX (para números não assinados).

##  <a name="getdlgitemtext"></a>  COleControlContainer::GetDlgItemText

Recupera o texto do controle fornecido.

```
virtual int GetDlgItemText(
    int nID,
    LPTSTR lpStr,
    int nMaxCount) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*lpStr*<br/>
Ponteiro para o texto do controle.

*nMaxCount*<br/>
Especifica o comprimento máximo, em caracteres, da cadeia de caracteres a ser copiada para o buffer apontado por *LPSTR*. Se o comprimento da cadeia de caracteres exceder o limite, a cadeia de caracteres será truncada.

### <a name="return-value"></a>Valor de retorno

Se a função for realizada com sucesso, o valor de retorno especificará o número de caracteres copiados para o buffer, não incluindo o caractere nulo de terminação.

Se a função falhar, o valor retornado será zero. Para obter informações de erro estendidas, chame [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

##  <a name="handlesetfocus"></a>  COleControlContainer::HandleSetFocus

Determina se o contêiner manipula mensagens WM_SETFOCUS.

```
virtual BOOL HandleSetFocus();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o contêiner manipula mensagens WM_SETFOCUSs; caso contrário, zero.

##  <a name="handlewindowlessmessage"></a>  COleControlContainer::HandleWindowlessMessage

Processa mensagens da janela para controles sem janela.

```
virtual BOOL HandleWindowlessMessage(
    UINT message,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT* plResult);
```

### <a name="parameters"></a>Parâmetros

*message*<br/>
O identificador da mensagem de janela, fornecido pelo Windows.

*wParam*<br/>
Parâmetro da mensagem; fornecido pelo Windows. Especifica informações adicionais específicas da mensagem. O conteúdo desse parâmetro depende do valor do parâmetro *Message* .

*lParam*<br/>
Parâmetro da mensagem; fornecido pelo Windows. Especifica informações adicionais específicas da mensagem. O conteúdo desse parâmetro depende do valor do parâmetro *Message* .

*plResult*<br/>
Código de resultado do Windows. Especifica o resultado do processamento da mensagem e depende da mensagem enviada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar a manipulação de mensagens de controle sem janelas.

##  <a name="isdlgbuttonchecked"></a>  COleControlContainer::IsDlgButtonChecked

Determina o estado do botão especificado.

```
virtual UINT IsDlgButtonChecked(int nIDButton) const;
```

### <a name="parameters"></a>Parâmetros

*nIDButton*<br/>
O identificador do controle de botão.

### <a name="return-value"></a>Valor de retorno

O valor de retorno, de um botão criado com o estilo BS_AUTOCHECKBOX, BS_AUTORADIOBUTTON, BS_AUTO3STATE, BS_CHECKBOX, BS_RADIOBUTTON ou BS_3STATE. Pode ser um dos seguintes:

- O botão BST_CHECKED está marcado.

- O botão BST_INDETERMINATE está acinzentado, indicando um estado indeterminado (aplica-se somente se o botão tiver o estilo BS_3STATE ou BS_AUTO3STATE).

- O botão BST_UNCHECKED está desmarcado.

### <a name="remarks"></a>Comentários

Se o botão for um controle de três Estados, a função de membro determinará se ele está esmaecido, marcado ou não.

##  <a name="m_crback"></a>  COleControlContainer::m_crBack

A cor do plano de fundo do contêiner.

```
COLORREF m_crBack;
```

##  <a name="m_crfore"></a>  COleControlContainer::m_crFore

A cor de primeiro plano do contêiner.

```
COLORREF m_crFore;
```

##  <a name="m_listsitesorwnds"></a>  COleControlContainer::m_listSitesOrWnds

Uma lista dos sites de controle hospedados pelo contêiner.

```
CTypedPtrList<CPtrList, COleControlSiteOrWnd*> m_listSitesOrWnds;
```

##  <a name="m_nwindowlesscontrols"></a>  COleControlContainer::m_nWindowlessControls

O número de controles sem janela hospedados pelo contêiner de controle.

```
int m_nWindowlessControls;
```

##  <a name="m_polefont"></a>  COleControlContainer::m_pOleFont

Um ponteiro para a fonte OLE do site de controle personalizado.

```
LPFONTDISP m_pOleFont;
```

##  <a name="m_psitecapture"></a>  COleControlContainer::m_pSiteCapture

Ponteiro para o site de controle de captura.

```
COleControlSite* m_pSiteCapture;
```

##  <a name="m_psitefocus"></a>  COleControlContainer::m_pSiteFocus

Um ponteiro para o site de controle que atualmente tem o foco de entrada.

```
COleControlSite* m_pSiteFocus;
```

##  <a name="m_psiteuiactive"></a>  COleControlContainer::m_pSiteUIActive

Um ponteiro para o site de controle que está no local ativado.

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

Chamado pelo Framework para lidar com solicitações WM_PAINT.

```
virtual BOOL OnPaint(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto do dispositivo usado pelo contêiner.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem foi tratada; caso contrário, zero.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar o processo de pintura.

##  <a name="onuiactivate"></a>  COleControlContainer::OnUIActivate

Chamado pelo Framework quando o site de controle, apontado por *pSite*, está prestes a ser ativado no local.

```
virtual void OnUIActivate(COleControlSite* pSite);
```

### <a name="parameters"></a>Parâmetros

*pSite*<br/>
Um ponteiro para o site de controle prestes a ser ativado no local.

### <a name="remarks"></a>Comentários

A ativação in-loco significa que o menu principal do contêiner é substituído por um menu composto no local.

##  <a name="onuideactivate"></a>  COleControlContainer::OnUIDeactivate

Chamado pelo Framework quando o site de controle, apontado por *pSite*, está prestes a ser desativado.

```
virtual void OnUIDeactivate(COleControlSite* pSite);
```

### <a name="parameters"></a>Parâmetros

*pSite*<br/>
Um ponteiro para o site de controle prestes a ser desativado.

### <a name="remarks"></a>Comentários

Quando essa notificação é recebida, o contêiner deve reinstalar sua interface do usuário e se concentrar.

##  <a name="scrollchildren"></a>  COleControlContainer::ScrollChildren

Chamado pelo Framework quando as mensagens de rolagem são recebidas de uma janela filho.

```
virtual void ScrollChildren(
    int dx,
    int dy);
```

### <a name="parameters"></a>Parâmetros

*dx*<br/>
A quantidade, em pixels, de rolagem ao longo do eixo x.

*dy*<br/>
O valor, em pixels, de rolagem ao longo do eixo y.

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

*nID*<br/>
Especifica o identificador do controle que recebe a mensagem.

*message*<br/>
Especifica a mensagem a ser enviada.

*wParam*<br/>
Especifica informações adicionais específicas da mensagem.

*lParam*<br/>
Especifica informações adicionais específicas da mensagem.

##  <a name="setdlgitemint"></a>  COleControlContainer::SetDlgItemInt

Define o texto de um controle em uma caixa de diálogo para a representação de cadeia de caracteres de um valor inteiro especificado.

```
virtual void SetDlgItemInt(
    int nID,
    UINT nValue,
    BOOL bSigned);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*nValue*<br/>
O valor inteiro a ser exibido.

*bSigned*<br/>
Especifica se o parâmetro *nvalor* é assinado ou não assinado. Se esse parâmetro for TRUE, *nvalor* será assinado. Se esse parâmetro for TRUE e *nvalor* for menor que zero, um sinal de subtração será colocado antes do primeiro dígito na cadeia de caracteres. Se esse parâmetro for FALSE, *nvalor* não será assinado.

##  <a name="setdlgitemtext"></a>  COleControlContainer::SetDlgItemText

Define o texto do controle especificado, usando o texto contido em *lpszString*.

```
virtual void SetDlgItemText(
    int nID,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*lpszString*<br/>
Ponteiro para o texto do controle.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)<br/>
[Classe COccManager](../../mfc/reference/coccmanager-class.md)

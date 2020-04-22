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
ms.openlocfilehash: 83171e012db7ef2cce459d35cfc689746afd062c
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749018"
---
# <a name="colecontrolcontainer-class"></a>Classe COleControlContainer

Atua como um recipiente de controle para controles ActiveX.

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
|[COleControlContainer::AttachControlSite](#attachcontrolsite)|Cria um local de controle, hospedado pelo contêiner.|
|[COleControlContainer::BroadcastAmbientPropertyChange](#broadcastambientpropertychange)|Informa todos os controles hospedados que uma propriedade ambiente mudou.|
|[COleControlContainer::CheckDlgButton](#checkdlgbutton)|Modifica o controle de botão especificado.|
|[COleControlContainer::CheckRadioButton](#checkradiobutton)|Seleciona o botão de rádio especificado de um grupo.|
|[COleControlContainer::CreateControl](#createcontrol)|Cria um controle ActiveX hospedado.|
|[COleControlContainer::CreateOleFont](#createolefont)|Cria uma fonte OLE.|
|[COleControlContainer::FindItem](#finditem)|Retorna o site personalizado do controle especificado.|
|[COleControlContainer::FreezeAllEvents](#freezeallevents)|Determina se o local de controle está aceitando eventos.|
|[COleControlContainer::GetAmbientProp](#getambientprop)|Recupera a propriedade ambiente especificada.|
|[COleControlContainer::GetDlgItem](#getdlgitem)|Recupera o controle de diálogo especificado.|
|[COleControlContainer::GetDlgItemInt](#getdlgitemint)|Recupera o valor do controle de diálogo especificado.|
|[COleControlContainer::GetDlgItemText](#getdlgitemtext)|Recupera a legenda do controle de diálogo especificado.|
|[COleControlContainer::HandleSetFocus](#handlesetfocus)|Determina se o contêiner lida com mensagens WM_SETFOCUS.|
|[COleControlContainer::HandleWindowlessMessage](#handlewindowlessmessage)|Lida com mensagens enviadas para um controle sem janelas.|
|[COleControlContainer::IsDlgButtonChecked](#isdlgbuttonchecked)|Determina o estado do botão especificado.|
|[COleControlContainer::OnPaint](#onpaint)|Chamado para repintar uma parte do recipiente.|
|[COleControlContainer::OnUIActivate](#onuiactivate)|Chamado quando um controle está prestes a ser ativado no local.|
|[COleControlContainer::OnUIDeActivate](#onuideactivate)|Chamado quando um controle está prestes a ser desativado.|
|[COleControlContainer::ScrollChildren](#scrollchildren)|Chamado pela estrutura quando as mensagens de rolagem são recebidas de uma janela de criança.|
|[COleControlContainer::SendDlgItemMessage](#senddlgitemmessage)|Envia uma mensagem para o controle especificado.|
|[COleControlContainer::SetDlgItemInt](#setdlgitemint)|Define o valor do controle especificado.|
|[COleControlContainer::SetDlgItemText](#setdlgitemtext)|Define o texto do controle especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleControlContainer::m_crBack](#m_crback)|A cor de fundo do recipiente.|
|[COleControlContainer::m_crFore](#m_crfore)|A cor do primeiro plano do recipiente.|
|[COleControlContainer::m_listSitesOrWnds](#m_listsitesorwnds)|Uma lista dos sites de controle suportados.|
|[COleControlContainer::m_nWindowlessControls](#m_nwindowlesscontrols)|O número de controles sem janelas hospedados.|
|[COleControlContainer::m_pOleFont](#m_polefont)|Um ponteiro para a fonte OLE do site de controle personalizado.|
|[COleControlContainer::m_pSiteCapture](#m_psitecapture)|Ponteiro para o local de controle de captura.|
|[COleControlContainer::m_pSiteFocus](#m_psitefocus)|Ponteiro para o controle que atualmente tem foco de entrada.|
|[COleControlContainer::m_pSiteUIActive](#m_psiteuiactive)|Ponteiro para o controle que está atualmente ativado no local.|
|[COleControlContainer::m_pWnd](#m_pwnd)|Ponteiro para a janela que implementa o recipiente de controle.|
|[COleControlContainer::m_siteMap](#m_sitemap)|O mapa do local.|

## <a name="remarks"></a>Comentários

Isso é feito fornecendo suporte para um ou `COleControlSite`mais sites de controle ActiveX (implementados por ). `COleControlContainer`implementa totalmente as interfaces [IOleInPlaceFrame](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceframe) e [IOleContainer,](/windows/win32/api/oleidl/nn-oleidl-iolecontainer) permitindo que os controles ActiveX contidos cumpram suas qualificações como itens no local.

Geralmente, essa classe é usada `COccManager` `COleControlSite` em conjunto com e para implementar um contêiner de controle ActiveX personalizado, com sites personalizados para um ou mais controles ActiveX.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleControlContainer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxocc.h

## <a name="colecontrolcontainerattachcontrolsite"></a><a name="attachcontrolsite"></a>COleControlContainer::AttachControlSite

Chamado pela estrutura para criar e anexar um site de controle.

```
virtual void AttachControlSite(
    CWnd* pWnd,
    UINT nIDC = 0);

void AttachControlSite(
    CWnd* pWnd,
    UINT nIDC = 0);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para um objeto `CWnd`.

*nIDC*<br/>
A id do controle a ser anexada.

### <a name="remarks"></a>Comentários

Anular esta função se você quiser personalizar este processo.

> [!NOTE]
> Use a primeira forma desta função se você estiver se vinculando estáticamente à biblioteca DoM. Use o segundo formulário se estiver vinculado dinamicamente à biblioteca DoM.

## <a name="colecontrolcontainerbroadcastambientpropertychange"></a><a name="broadcastambientpropertychange"></a>COleControlContainer::BroadcastAmbientPropertyChange

Informa todos os controles hospedados que uma propriedade ambiente mudou.

```
virtual void BroadcastAmbientPropertyChange(DISPID dispid);
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
A id de despacho da propriedade ambiental sendo alterada.

### <a name="remarks"></a>Comentários

Essa função é chamada pela estrutura quando uma propriedade ambiente mudou de valor. Anular essa função para personalizar esse comportamento.

## <a name="colecontrolcontainercheckdlgbutton"></a><a name="checkdlgbutton"></a>COleControlContainer::CheckDlgButton

Modifica o estado atual do botão.

```
virtual void CheckDlgButton(
    int nIDButton,
    UINT nCheck);
```

### <a name="parameters"></a>Parâmetros

*nIDButton*<br/>
O ID do botão a ser modificado.

*Ncheck*<br/>
Especifica o estado do botão. Um dos seguintes pode ser feito:

- BST_CHECKED Define o estado do botão para verificação.

- BST_INDETERMINATE Define o estado do botão para acinzentado, indicando um estado indeterminado. Use este valor somente se o botão tiver o estilo BS_3STATE ou BS_AUTO3STATE.

- BST_UNCHECKED Define o estado do botão para limpar.

## <a name="colecontrolcontainercheckradiobutton"></a><a name="checkradiobutton"></a>COleControlContainer::CheckRadioButton

Seleciona um botão de rádio especificado em um grupo e limpa os botões restantes no grupo.

```
virtual void CheckRadioButton(
    int nIDFirstButton,
    int nIDLastButton,
    int nIDCheckButton);
```

### <a name="parameters"></a>Parâmetros

*nIDFirstButton*<br/>
Especifica o identificador do primeiro botão de rádio do grupo.

*nIDLastButton*<br/>
Especifica o identificador do último botão de rádio do grupo.

*nIDCheckButton*<br/>
Especifica o identificador do botão de rádio a ser verificado.

## <a name="colecontrolcontainercolecontrolcontainer"></a><a name="colecontrolcontainer"></a>COleControlContainer::COleControlContainer

Constrói um objeto `COleControlContainer`.

```
explicit COleControlContainer(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para a janela pai do recipiente de controle.

### <a name="remarks"></a>Comentários

Uma vez que o objeto tenha sido criado com `AttachControlSite`sucesso, adicione um site de controle personalizado com uma chamada para .

## <a name="colecontrolcontainercreatecontrol"></a><a name="createcontrol"></a>COleControlContainer::CreateControl

Cria um controle ActiveX, hospedado `COleControlSite` pelo objeto especificado.

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
Um ponteiro para o objeto da janela representando o controle.

*clsid*<br/>
A identificação única da classe do controle.

*lpszWindowName*<br/>
Um ponteiro para o texto a ser exibido no controle. Define o valor da propriedade Legenda ou Texto do controle (se houver). Se NULA, a propriedade Legenda ou Texto do controle não será alterada.

*Dwstyle*<br/>
Estilos de windows. Os estilos disponíveis estão listados na seção **Observações.**

*Rect*<br/>
Especifica o tamanho e a posição do controle. Pode ser um `CRect` objeto `RECT` ou uma estrutura.

*nID*<br/>
Especifica a id da janela do filho do controle.

*Ppersist*<br/>
Um ponteiro `CFile` para um estado persistente para o controle. O valor padrão é NULL, indicando que o controle se inicia sem restaurar seu estado de qualquer armazenamento persistente. Se não for NULO, deve `CFile`ser um ponteiro para um objeto derivado que contenha os dados persistentes do controle, na forma de um fluxo ou de um armazenamento. Esses dados poderiam ter sido salvos em uma ativação prévia do cliente. O `CFile` pode conter outros dados, mas deve ter seu ponteiro de leitura de gravação definido `CreateControl`para o primeiro byte de dados persistentes no momento da chamada para .

*Bstorage*<br/>
Indica se os dados em *pPersist* devem ser interpretados como `IStorage` ou `IStream` dados. Se os dados em *pPersist* forem um armazenamento, *bArmazenamento* deve ser VERDADEIRO. Se os dados em *pPersist* forem um fluxo, *bArmazenamento* deve ser FALSO. O valor padrão é FALSE.

*bstrlickey*<br/>
Dados de chave de licença opcionais. Esses dados são necessários apenas para criar controles que requerem uma chave de licença em tempo de execução. Se o controle suportar o licenciamento, você deve fornecer uma chave de licença para a criação do controle para ter sucesso. O valor padrão é NULL.

*ppNewSite*<br/>
Um ponteiro para o local de controle existente que hospedará o controle que está sendo criado. O valor padrão é NULL, indicando que um novo site de controle será criado automaticamente e anexado ao novo controle.

*Ppt*<br/>
Um ponteiro `POINT` para uma estrutura que contém o canto superior esquerdo do controle. O tamanho do controle é determinado pelo valor do *tamanho*. Os valores *ppt* e *psize* são um método opcional de especificar o tamanho e a posição do controle.

*Psize*<br/>
Um ponteiro `SIZE` para uma estrutura que contém o tamanho do controle. O canto superior esquerdo é determinado pelo valor de *ppt*. Os valores *ppt* e *psize* são um método opcional de especificar o tamanho e a posição do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Apenas um subconjunto das bandeiras *dwStyle* do Windows são suportados por: `CreateControl`

- WS_VISIBLE Cria uma janela que é inicialmente visível. Necessário se você quiser que o controle seja visível imediatamente, como janelas comuns.

- WS_DISABLED Cria uma janela inicialmente desativada. Uma janela desativada não pode receber entrada do usuário. Pode ser definido se o controle tiver uma propriedade Habilitada.

- WS_BORDER cria uma janela com uma borda de linha fina. Pode ser definido se o controle tiver uma propriedade BorderStyle.

- WS_GROUP Especifica o primeiro controle de um grupo de controles. O usuário pode alterar o foco do teclado de um controle no grupo para o próximo usando as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o WS_GROUP estilo termina o grupo e começa o próximo grupo.

- WS_TABSTOP Especifica um controle que pode receber o foco do teclado quando o usuário pressiona a tecla TAB. Pressionar a tecla TAB altera o foco do teclado para o próximo controle do estilo WS_TABSTOP.

Use a segunda sobrecarga para criar controles de tamanho padrão.

## <a name="colecontrolcontainercreateolefont"></a><a name="createolefont"></a>COleControlContainer::CreateOleFont

Cria uma fonte OLE.

```cpp
void CreateOleFont(CFont* pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
Um ponteiro para a fonte a ser usado pelo recipiente de controle.

## <a name="colecontrolcontainerfinditem"></a><a name="finditem"></a>COleControlContainer::FindItem

Encontra o site personalizado que hospeda o item especificado.

```
virtual COleControlSite* FindItem(UINT nID) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do item a ser encontrado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o site personalizado do item especificado.

## <a name="colecontrolcontainerfreezeallevents"></a><a name="freezeallevents"></a>COleControlContainer::FreezeAllEvents

Determina se o contêiner ignorará os eventos dos locais de controle anexados ou os aceitará.

```cpp
void FreezeAllEvents(BOOL bFreeze);
```

### <a name="parameters"></a>Parâmetros

*bFreeze*<br/>
Não zero se os eventos forem processados; caso contrário, 0.

### <a name="remarks"></a>Comentários

> [!NOTE]
> O controle não é necessário para parar os eventos de disparo se solicitado pelo recipiente de controle. Pode continuar disparando, mas todos os eventos subseqüentes serão ignorados pelo contêiner de controle.

## <a name="colecontrolcontainergetambientprop"></a><a name="getambientprop"></a>COleControlContainer::GetAmbientProp

Recupera o valor de uma propriedade ambiente especificada.

```
virtual BOOL GetAmbientProp(
    COleControlSite* pSite,
    DISPID dispid,
    VARIANT* pvarResult);
```

### <a name="parameters"></a>Parâmetros

*Psite*<br/>
Um ponteiro para um local de controle do qual a propriedade ambiente será recuperada.

*Dispid*<br/>
A id de despacho da propriedade ambiental desejada.

*Pvarresult*<br/>
Um ponteiro para o valor da propriedade ambiente.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="colecontrolcontainergetdlgitem"></a><a name="getdlgitem"></a>COleControlContainer::GetDlgItem

Recupera um ponteiro para o controle especificado ou janela do filho em uma caixa de diálogo ou outra janela.

```
virtual CWnd* GetDlgItem(int nID) const;

virtual void GetDlgItem(
    int nID,
    HWND* phWnd) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Identificador do item de diálogo a ser recuperado.

*PhWnd*<br/>
Um ponteiro para a alça do objeto da janela do item de diálogo especificado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do item de diálogo.

## <a name="colecontrolcontainergetdlgitemint"></a><a name="getdlgitemint"></a>COleControlContainer::GetDlgItemInt

Recupera o valor do texto traduzido do controle dado.

```
virtual UINT GetDlgItemInt(
    int nID,
    BOOL* lpTrans,
    BOOL bSigned) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*Lptrans*<br/>
Ponteiro para uma variável booleana que recebe um valor de sucesso/falha de função (TRUE indica sucesso, FALSE indica falha).

*assinado*<br/>
Especifica se a função deve examinar o texto para um sinal de menos no início e retornar um valor inteiro assinado se encontrar um. Se o parâmetro *bSigned* for TRUE, especificando que o valor a ser recuperado é um valor inteiro assinado, lance o valor de retorno para um tipo **int.** Para obter informações de erro estendidas, ligue para [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="return-value"></a>Valor retornado

Se for bem-sucedida, a variável apontada por *lpTrans* é definida como TRUE, e o valor de retorno é o valor traduzido do texto de controle.

Se a função falhar, a variável apontada por *lpTrans* será definida como FALSE, e o valor de retorno será zero. Observe que, uma vez que zero é um possível valor traduzido, um valor de retorno de zero por si só não indica falha.

Se *lpTrans* for NULL, a função não retorna nenhuma informação sobre sucesso ou falha.

### <a name="remarks"></a>Comentários

A função traduz o texto recuperado retirando quaisquer espaços extras no início do texto e, em seguida, convertendo os dígitos decimais. A função pára de traduzir quando chega ao final do texto ou encontra um caractere não numérico.

Esta função retorna zero se o valor traduzido for maior do que INT_MAX (para números assinados) ou UINT_MAX (para números não assinados).

## <a name="colecontrolcontainergetdlgitemtext"></a><a name="getdlgitemtext"></a>COleControlContainer::GetDlgItemText

Recupera o texto do controle dado.

```
virtual int GetDlgItemText(
    int nID,
    LPTSTR lpStr,
    int nMaxCount) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*Lpstr*<br/>
Ponteiro para o texto do controle.

*Nmaxcount*<br/>
Especifica o comprimento máximo, em caracteres, da seqüência a ser copiada para o buffer apontado por *lpStr*. Se o comprimento da seqüência exceder o limite, a seqüência será truncada.

### <a name="return-value"></a>Valor retornado

Se a função for bem-sucedida, o valor de retorno especifica rá o número de caracteres copiados para o buffer, sem incluir o caractere nulo final.

Se a função falhar, o valor retornado será zero. Para obter informações de erro estendidas, ligue para [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## <a name="colecontrolcontainerhandlesetfocus"></a><a name="handlesetfocus"></a>COleControlContainer::HandleSetFocus

Determina se o contêiner lida com mensagens WM_SETFOCUS.

```
virtual BOOL HandleSetFocus();
```

### <a name="return-value"></a>Valor retornado

Não zero se o contêiner manusear mensagens WM_SETFOCUS; caso contrário, zero.

## <a name="colecontrolcontainerhandlewindowlessmessage"></a><a name="handlewindowlessmessage"></a>COleControlContainer::HandleWindowlessMessage

Processa mensagens de janela para controles sem janelas.

```
virtual BOOL HandleWindowlessMessage(
    UINT message,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT* plResult);
```

### <a name="parameters"></a>Parâmetros

*message*<br/>
O identificador da mensagem da janela, fornecido pelo Windows.

*wParam*<br/>
parâmetro da mensagem; fornecido pelo Windows. Especifica informações específicas de mensagens adicionais. O conteúdo deste parâmetro depende do valor do parâmetro da *mensagem.*

*lParam*<br/>
parâmetro da mensagem; fornecido pelo Windows. Especifica informações específicas de mensagens adicionais. O conteúdo deste parâmetro depende do valor do parâmetro da *mensagem.*

*plResult*<br/>
Código de resultados do Windows. Especifica o resultado do processamento da mensagem e depende da mensagem enviada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar o manuseio de mensagens de controle sem janelas.

## <a name="colecontrolcontainerisdlgbuttonchecked"></a><a name="isdlgbuttonchecked"></a>COleControlContainer::IsDlgButtonChecked

Determina o estado do botão especificado.

```
virtual UINT IsDlgButtonChecked(int nIDButton) const;
```

### <a name="parameters"></a>Parâmetros

*nIDButton*<br/>
O identificador do controle do botão.

### <a name="return-value"></a>Valor retornado

O valor de retorno, a partir de um botão criado com o estilo BS_AUTOCHECKBOX, BS_AUTORADIOBUTTON, BS_AUTO3STATE, BS_CHECKBOX, BS_RADIOBUTTON ou BS_3STATE. Um dos seguintes pode ser feito:

- BST_CHECKED Button está verificado.

- BST_INDETERMINATE botão é acinzentado, indicando um estado indeterminado (só se aplica se o botão tiver o estilo BS_3STATE ou BS_AUTO3STATE).

- BST_UNCHECKED Button está liberado.

### <a name="remarks"></a>Comentários

Se o botão for um controle de três estados, a função do membro determina se ele está escurecido, verificado ou nenhum dos dois.

## <a name="colecontrolcontainerm_crback"></a><a name="m_crback"></a>COleControlContainer::m_crBack

A cor de fundo do recipiente.

```
COLORREF m_crBack;
```

## <a name="colecontrolcontainerm_crfore"></a><a name="m_crfore"></a>COleControlContainer::m_crFore

A cor do primeiro plano do recipiente.

```
COLORREF m_crFore;
```

## <a name="colecontrolcontainerm_listsitesorwnds"></a><a name="m_listsitesorwnds"></a>COleControlContainer::m_listSitesOrWnds

Uma lista dos locais de controle hospedados pelo contêiner.

```
CTypedPtrList<CPtrList, COleControlSiteOrWnd*> m_listSitesOrWnds;
```

## <a name="colecontrolcontainerm_nwindowlesscontrols"></a><a name="m_nwindowlesscontrols"></a>COleControlContainer::m_nWindowlessControls

O número de controles sem janelas hospedados pelo recipiente de controle.

```
int m_nWindowlessControls;
```

## <a name="colecontrolcontainerm_polefont"></a><a name="m_polefont"></a>COleControlContainer::m_pOleFont

Um ponteiro para a fonte OLE do site de controle personalizado.

```
LPFONTDISP m_pOleFont;
```

## <a name="colecontrolcontainerm_psitecapture"></a><a name="m_psitecapture"></a>COleControlContainer::m_pSiteCapture

Ponteiro para o local de controle de captura.

```
COleControlSite* m_pSiteCapture;
```

## <a name="colecontrolcontainerm_psitefocus"></a><a name="m_psitefocus"></a>COleControlContainer::m_pSiteFocus

Um ponteiro para o local de controle que atualmente tem foco de entrada.

```
COleControlSite* m_pSiteFocus;
```

## <a name="colecontrolcontainerm_psiteuiactive"></a><a name="m_psiteuiactive"></a>COleControlContainer::m_pSiteUIActive

Um ponteiro para o local de controle que está ativado no local.

```
COleControlSite* m_pSiteUIActive;
```

## <a name="colecontrolcontainerm_pwnd"></a><a name="m_pwnd"></a>COleControlContainer::m_pWnd

Um ponteiro para o objeto da janela associado ao recipiente.

```
CWnd* m_pWnd;
```

## <a name="colecontrolcontainerm_sitemap"></a><a name="m_sitemap"></a>COleControlContainer::m_siteMap

O mapa do local.

```
CMapPtrToPtr m_siteMap;
```

## <a name="colecontrolcontaineronpaint"></a><a name="onpaint"></a>COleControlContainer::OnPaint

Chamado pelo quadro para lidar com WM_PAINT pedidos.

```
virtual BOOL OnPaint(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto do dispositivo usado pelo recipiente.

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem foi tratada; caso contrário, zero.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar o processo de pintura.

## <a name="colecontrolcontaineronuiactivate"></a><a name="onuiactivate"></a>COleControlContainer::OnUIActivate

Chamado pela estrutura quando o local de controle, apontado por *pSite,* está prestes a ser ativado no local.

```
virtual void OnUIActivate(COleControlSite* pSite);
```

### <a name="parameters"></a>Parâmetros

*Psite*<br/>
Um ponteiro para o local de controle prestes a ser ativado no local.

### <a name="remarks"></a>Comentários

A ativação no local significa que o menu principal do contêiner é substituído por um menu composto no local.

## <a name="colecontrolcontaineronuideactivate"></a><a name="onuideactivate"></a>COleControlContainer::OnUIDeActivate

Chamado pela estrutura quando o site de controle, apontado por *pSite,* está prestes a ser desativado.

```
virtual void OnUIDeactivate(COleControlSite* pSite);
```

### <a name="parameters"></a>Parâmetros

*Psite*<br/>
Um ponteiro para o local de controle prestes a ser desativado.

### <a name="remarks"></a>Comentários

Quando essa notificação é recebida, o contêiner deve reinstalar sua interface de usuário e ter foco.

## <a name="colecontrolcontainerscrollchildren"></a><a name="scrollchildren"></a>COleControlContainer::ScrollChildren

Chamado pela estrutura quando as mensagens de rolagem são recebidas de uma janela de criança.

```
virtual void ScrollChildren(
    int dx,
    int dy);
```

### <a name="parameters"></a>Parâmetros

*Dx*<br/>
A quantidade, em pixels, de rolagem ao longo do eixo x.

*Dy*<br/>
A quantidade, em pixels, de rolagem ao longo do eixo y.

## <a name="colecontrolcontainersenddlgitemmessage"></a><a name="senddlgitemmessage"></a>COleControlContainer::SendDlgItemMessage

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
Especifica informações específicas de mensagens adicionais.

*lParam*<br/>
Especifica informações específicas de mensagens adicionais.

## <a name="colecontrolcontainersetdlgitemint"></a><a name="setdlgitemint"></a>COleControlContainer::SetDlgItemInt

Define o texto de um controle em uma caixa de diálogo para a representação de seqüência de strings de um valor inteiro especificado.

```
virtual void SetDlgItemInt(
    int nID,
    UINT nValue,
    BOOL bSigned);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O identificador do controle.

*Nvalue*<br/>
O valor inteiro a ser exibido.

*assinado*<br/>
Especifica se o parâmetro *nValue* está assinado ou não assinado. Se este parâmetro for TRUE, *nValue* será assinado. Se este parâmetro for TRUE e *nValue* for menor que zero, um sinal de menos será colocado antes do primeiro dígito na seqüência. Se este parâmetro for FALSO, *nValue* não será assinado.

## <a name="colecontrolcontainersetdlgitemtext"></a><a name="setdlgitemtext"></a>COleControlContainer::SetDlgItemText

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

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleControlSite](../../mfc/reference/colecontrolsite-class.md)<br/>
[Classe COccManager](../../mfc/reference/coccmanager-class.md)

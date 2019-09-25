---
title: CNetAddressCtrl Class
ms.date: 11/19/2018
f1_keywords:
- CNetAddressCtrl
- AFXCMN/CNetAddressCtrl
- AFXCMN/CNetAddressCtrl::CNetAddressCtrl
- AFXCMN/CNetAddressCtrl::Create
- AFXCMN/CNetAddressCtrl::CreateEx
- AFXCMN/CNetAddressCtrl::DisplayErrorTip
- AFXCMN/CNetAddressCtrl::GetAddress
- AFXCMN/CNetAddressCtrl::GetAllowType
- AFXCMN/CNetAddressCtrl::SetAllowType
helpviewer_keywords:
- CNetAddressCtrl [MFC], CNetAddressCtrl
- CNetAddressCtrl [MFC], Create
- CNetAddressCtrl [MFC], CreateEx
- CNetAddressCtrl [MFC], DisplayErrorTip
- CNetAddressCtrl [MFC], GetAddress
- CNetAddressCtrl [MFC], GetAllowType
- CNetAddressCtrl [MFC], SetAllowType
ms.assetid: cb4c6aca-3f49-4b52-b76c-65f57096155b
ms.openlocfilehash: 5e485c22bcc4bf35f61226d84345102052689f89
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69504527"
---
# <a name="cnetaddressctrl-class"></a>CNetAddressCtrl Class

A `CNetAddressCtrl` classe representa o controle de endereço de rede, que pode ser usado para inserir e validar o formato de IPv4, IPv6 e endereços DNS nomeados.

## <a name="syntax"></a>Sintaxe

```
class CNetAddressCtrl : public CEdit
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CNetAddressCtrl::CNetAddressCtrl](#cnetaddressctrl)|Constrói um objeto `CNetAddressCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CNetAddressCtrl::Create](#create)|Cria um controle de endereço de rede com os estilos especificados e anexa-o `CNetAddressCtrl` ao objeto atual.|
|[CNetAddressCtrl::CreateEx](#createex)|Cria um controle de endereço de rede com os estilos estendidos especificados e anexa- `CNetAddressCtrl` o ao objeto atual.|
|[CNetAddressCtrl::DisplayErrorTip](#displayerrortip)|Exibe uma dica de balão de erro quando o usuário insere um endereço de rede sem suporte no controle de endereço de rede atual.|
|[CNetAddressCtrl::GetAddress](#getaddress)|Recupera uma representação validada e analisada do endereço de rede associado ao controle de endereço de rede atual.|
|[CNetAddressCtrl::GetAllowType](#getallowtype)|Recupera o tipo de endereço de rede ao qual o controle de endereço de rede atual pode dar suporte.|
|[CNetAddressCtrl::SetAllowType](#setallowtype)|Define o tipo de endereço de rede ao qual o controle de endereço de rede atual pode dar suporte.|

## <a name="remarks"></a>Comentários

O controle de endereço de rede verifica se o formato do endereço que o usuário insere está correto. O controle, na verdade, não se conecta ao endereço de rede. O método [CNetAddressCtrl:: SetAllowType](#setallowtype) especifica um ou mais tipos de endereço que o método [CNetAddressCtrl:: GetAddress](#getaddress) pode analisar e verificar. Um endereço pode estar na forma de um IPv4, IPv6 ou endereço nomeado para um servidor, rede, host ou destino de mensagem de difusão. Se o formato do endereço estiver incorreto, você poderá usar o método [CNetAddressCtrl::D isplayerrortip](#displayerrortip) para exibir uma caixa de mensagem InfoTip que aponta graficamente para a caixa de texto do controle de endereço de rede e exibir uma mensagem de erro predefinida.

A `CNetAddressCtrl` classe é derivada da classe [CEdit](../../mfc/reference/cedit-class.md) . Consequentemente, o controle de endereço de rede fornece acesso a todas as mensagens de controle de edição do Windows.

A figura a seguir descreve uma caixa de diálogo que contém um controle de endereço de rede. A caixa de texto (1) do controle de endereço de rede contém um endereço de rede inválido. A mensagem infotip (2) será exibida se o endereço de rede for inválido.

![Caixa de diálogo com um controle de endereço de rede e InfoTip.](../../mfc/reference/media/cnetaddctrl.png "Caixa de diálogo com um controle de endereço de rede e InfoTip.")

## <a name="example"></a>Exemplo

O exemplo de código a seguir é uma parte de uma caixa de diálogo que valida um endereço de rede. Os manipuladores de eventos para três botões de opção especificam que o endereço de rede pode ser um dos três tipos de endereço. O usuário insere um endereço na caixa de texto do controle de rede e, em seguida, pressiona um botão para validar o endereço. Se o endereço for válido, uma mensagem de êxito será exibida; caso contrário, a mensagem de erro InfoTip predefinida será exibida.

[!code-cpp[NVC_MFC_CNetAddressCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cnetaddressctrl-class_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo de código a seguir do arquivo de cabeçalho de caixa de diálogo define as variáveis [NC_ADDRESS](/windows/win32/api/shellapi/ns-shellapi-nc_address) e [NET_ADDRESS_INFO](/windows/win32/shell/hkey-type) exigidas pelo método [CNetAddressCtrl:: GetAddress](#getaddress) .

[!code-cpp[NVC_MFC_CNetAddressCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cnetaddressctrl-class_2.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

`CNetAddressCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

Essa classe tem suporte no Windows Vista e versões posteriores.

Os requisitos adicionais para essa classe são descritos em [requisitos de compilação para controles comuns do Windows Vista](../../mfc/build-requirements-for-windows-vista-common-controls.md).

##  <a name="cnetaddressctrl"></a>  CNetAddressCtrl::CNetAddressCtrl

Constrói um objeto `CNetAddressCtrl`.

```
CNetAddressCtrl();
```

### <a name="remarks"></a>Comentários

Use o método [CNetAddressCtrl:: Create](#create) ou [CNetAddressCtrl:: CreateEx](#createex) para criar um controle de rede e anexá `CNetAddressCtrl` -lo ao objeto.

##  <a name="create"></a>  CNetAddressCtrl::Create

Cria um controle de endereço de rede com os estilos especificados e anexa-o `CNetAddressCtrl` ao objeto atual.

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
|*dwStyle*|no Uma combinação de bits e de estilos que deve ser aplicada ao controle. Para obter mais informações, consulte [Editar estilos](../../mfc/reference/styles-used-by-mfc.md#edit-styles).|
|*rect*|no Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém a posição e o tamanho do controle.|
|*pParentWnd*|no Um ponteiro não nulo para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle.|
|*nID*|no A ID do controle.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

##  <a name="createex"></a>  CNetAddressCtrl::CreateEx

Cria um controle de endereço de rede com os estilos estendidos especificados e anexa- `CNetAddressCtrl` o ao objeto atual.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwExStyle*|no Uma combinação de bits (ou) de estilos estendidos a ser aplicada ao controle. Para obter mais informações, consulte o parâmetro *dwExStyle* da função [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) .|
|*dwStyle*|no Uma combinação de bits (ou) de estilos a ser aplicada ao controle. Para obter mais informações, consulte [Editar estilos](../../mfc/reference/styles-used-by-mfc.md#edit-styles).|
|*rect*|no Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém a posição e o tamanho do controle.|
|*pParentWnd*|no Um ponteiro não nulo para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle.|
|*nID*|no A ID do controle.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

##  <a name="displayerrortip"></a>  CNetAddressCtrl::DisplayErrorTip

Exibe uma mensagem de erro na dica de balão associada ao controle de endereço de rede atual.

```
HRESULT DisplayErrorTip();
```

### <a name="return-value"></a>Valor de retorno

O valor `S_OK` se esse método for bem-sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

Use o método [CNetAddressCtrl:: SetAllowType](#setallowtype) para especificar os tipos de endereços aos quais o controle de endereço de rede atual pode dar suporte. Use o método [CNetAddressCtrl:: GetAddress](#getaddress) para validar e analisar o endereço de rede que o usuário insere. Use o método [CNetAddressCtrl::D isplayerrortip](#displayerrortip) para exibir uma mensagem de erro InfoTip se o método [CNetAddressCtrl:: GetAddress](#getaddress) não for bem-sucedido.

Essa mensagem invoca a macro [NetAddr_DisplayErrorTip](/windows/win32/api/shellapi/nf-shellapi-netaddr_displayerrortip) , que é descrita na SDK do Windows. Essa macro envia a `NCM_DISPLAYERRORTIP` mensagem.

##  <a name="getaddress"></a>  CNetAddressCtrl::GetAddress

Recupera uma representação validada e analisada do endereço de rede que está associado ao controle de endereço de rede atual.

```
HRESULT GetAddress(PNC_ADDRESS pAddress) const;
```

### <a name="parameters"></a>Parâmetros

*pAddress*<br/>
[entrada, saída] Ponteiro para uma estrutura [NC_ADDRESS](/windows/win32/api/shellapi/ns-shellapi-nc_address) .  Defina o membro *pAddrInfo* dessa estrutura como o endereço de uma estrutura [NET_ADDRESS_INFO](/windows/win32/shell/hkey-type) antes de chamar o método GetAddress.

### <a name="return-value"></a>Valor de retorno

O valor S_OK se esse método for bem-sucedido; caso contrário, um código de erro COM. Para obter mais informações sobre os possíveis códigos de erro, consulte a seção valor de retorno da macro [NetAddr_GetAddress](/windows/win32/api/shellapi/nf-shellapi-netaddr_getaddress) .

### <a name="remarks"></a>Comentários

Se esse método for bem-sucedido, a estrutura [NET_ADDRESS_INFO](/windows/win32/shell/hkey-type) conterá informações adicionais sobre o endereço de rede.

Use o método [CNetAddressCtrl:: SetAllowType](#setallowtype) para especificar os tipos de endereços aos quais o controle de endereço de rede atual pode dar suporte. Use o método [CNetAddressCtrl:: GetAddress](#getaddress) para validar e analisar o endereço de rede que o usuário insere. Use o método [CNetAddressCtrl::D isplayerrortip](#displayerrortip) para exibir uma mensagem de erro InfoTip se o método [CNetAddressCtrl:: GetAddress](#getaddress) não for bem-sucedido.

Esse método invoca a macro [NetAddr_GetAddress](/windows/win32/api/shellapi/nf-shellapi-netaddr_getaddress) , que é descrita na SDK do Windows. Essa macro envia a mensagem NCM_GETADDRESS.

##  <a name="getallowtype"></a>  CNetAddressCtrl::GetAllowType

Recupera o tipo de endereço de rede ao qual o controle de endereço de rede atual pode dar suporte.

```
DWORD GetAllowType() const;
```

### <a name="return-value"></a>Valor de retorno

Uma combinação de bits (ou) de sinalizadores que especifica os tipos de endereços aos quais o controle de endereço de rede pode dar suporte. Para obter mais informações, consulte [NET_STRING](/windows/win32/shell/net-string).

### <a name="remarks"></a>Comentários

Essa mensagem invoca a macro [NetAddr_GetAllowType](/windows/win32/api/shellapi/nf-shellapi-netaddr_getallowtype) , que é descrita na SDK do Windows. Essa macro envia a mensagem NCM_GETALLOWTYPE.

##  <a name="setallowtype"></a>  CNetAddressCtrl::SetAllowType

Define o tipo de endereço de rede ao qual o controle de endereço de rede atual pode dar suporte.

```
HRESULT SetAllowType(DWORD dwAddrMask);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwAddrMask*|no Uma combinação de bits (ou) de sinalizadores que especifica os tipos de endereços aos quais o controle de endereço de rede pode dar suporte. Para obter mais informações, consulte [NET_STRING](/windows/win32/shell/net-string).|

### <a name="return-value"></a>Valor de retorno

S_OK se esse método for bem-sucedido; caso contrário, um código de erro COM.

### <a name="remarks"></a>Comentários

Use o método [CNetAddressCtrl:: SetAllowType](#setallowtype) para especificar os tipos de endereços aos quais o controle de endereço de rede atual pode dar suporte. Use o método [CNetAddressCtrl:: GetAddress](#getaddress) para validar e analisar o endereço de rede que o usuário insere. Use o método [CNetAddressCtrl::D isplayerrortip](#displayerrortip) para exibir uma mensagem de erro InfoTip se o método [CNetAddressCtrl:: GetAddress](#getaddress) não for bem-sucedido.

Essa mensagem invoca a macro [NetAddr_SetAllowType](/windows/win32/api/shellapi/nf-shellapi-netaddr_setallowtype) , que é descrita na SDK do Windows. Essa macro envia a mensagem NCM_SETALLOWTYPE.

## <a name="see-also"></a>Consulte também

[Classe CNetAddressCtrl](../../mfc/reference/cnetaddressctrl-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)

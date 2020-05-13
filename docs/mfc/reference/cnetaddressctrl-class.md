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
ms.openlocfilehash: c6f391966ef6657363e8f23e5666a57a935b08e1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752781"
---
# <a name="cnetaddressctrl-class"></a>CNetAddressCtrl Class

A `CNetAddressCtrl` classe representa o controle de endereço de rede, que você pode usar para inserir e validar o formato de endereços IPv4, IPv6 e DNS nomeados.

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
|[CNetAddressCtrl::Criar](#create)|Cria um controle de endereço de rede com `CNetAddressCtrl` estilos especificados e anexa-o ao objeto atual.|
|[CNetAddressCtrl::CreateEx](#createex)|Cria um controle de endereço de rede com estilos `CNetAddressCtrl` estendidos especificados e anexa-o ao objeto atual.|
|[CNetAddressCtrl::DisplayErrorTip](#displayerrortip)|Exibe uma dica de balão de erro quando o usuário insere um endereço de rede sem suporte no controle atual do endereço de rede.|
|[CNetAddressCtrl::GetAddress](#getaddress)|Recupera uma representação validada e parsed do endereço de rede associado ao controle de endereço de rede atual.|
|[CNetAddressCtrl::GetAllowType](#getallowtype)|Recupera o tipo de endereço de rede que o controle atual de endereço de rede pode suportar.|
|[CNetAddressCtrl::SetAllowType](#setallowtype)|Define o tipo de endereço de rede que o controle atual de endereço de rede pode suportar.|

## <a name="remarks"></a>Comentários

O controle de endereço de rede verifica se o formato do endereço que o usuário insere está correto. O controle não se conecta ao endereço de rede. O método [CNetAddressCtrl::SetAllowType](#setallowtype) especifica um ou mais tipos de endereço que o método [CNetAddressCtrl::GetAddress](#getaddress) pode analisar e verificar. Um endereço pode ser na forma de um IPv4, IPv6 ou endereço nomeado para um servidor, rede, host ou destino de mensagem de transmissão. Se o formato do endereço estiver incorreto, você poderá usar o método [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) para exibir uma caixa de mensagem de infotip que aponta graficamente para a caixa de texto do controle de endereço de rede e exibe uma mensagem de erro predefinida.

A `CNetAddressCtrl` classe é derivada da classe [CEdit.](../../mfc/reference/cedit-class.md) Consequentemente, o controle de endereço susceptino de acesso a todas as mensagens de controle de edição do Windows.

A figura a seguir mostra uma caixa de diálogo que contém um controle de endereço de rede. A caixa de texto (1) para o controle de endereço de rede contém um endereço de rede inválido. A mensagem infotip (2) é exibida se o endereço da rede estiver inválido.

![Dialoge com um controle de endereço de rede e infotip.](../../mfc/reference/media/cnetaddctrl.png "Dialoge com um controle de endereço de rede e infotip.")

## <a name="example"></a>Exemplo

O exemplo de código a seguir é uma parte de uma caixa de diálogo que valida um endereço de rede. Os manipuladores de eventos para três botões de rádio especificam que o endereço de rede pode ser um dos três tipos de endereço. O usuário insere um endereço na caixa de texto do controle de rede e pressiona um botão para validar o endereço. Se o endereço for válido, uma mensagem de sucesso será exibida; caso contrário, a mensagem de erro de infotip predefinida é exibida.

[!code-cpp[NVC_MFC_CNetAddressCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cnetaddressctrl-class_1.cpp)]

## <a name="example"></a>Exemplo

O exemplo de código a seguir do arquivo de cabeçalho de diálogo define as variáveis [NC_ADDRESS](/windows/win32/api/shellapi/ns-shellapi-nc_address) e [NET_ADDRESS_INFO](/windows/win32/shell/hkey-type) que são exigidas pelo método [CNetAddressCtrl::GetAddress.](#getaddress)

[!code-cpp[NVC_MFC_CNetAddressCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cnetaddressctrl-class_2.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

`CNetAddressCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

Esta classe é suportada no Windows Vista e depois.

Requisitos adicionais para esta classe são descritos em [Build Requirements for Windows Vista Common Controls](../../mfc/build-requirements-for-windows-vista-common-controls.md).

## <a name="cnetaddressctrlcnetaddressctrl"></a><a name="cnetaddressctrl"></a>CNetAddressCtrl::CNetAddressCtrl

Constrói um objeto `CNetAddressCtrl`.

```
CNetAddressCtrl();
```

### <a name="remarks"></a>Comentários

Use o método [CNetAddressCtrl::Create](#create) ou [CNetAddressCtrl::CreateEx](#createex) para criar `CNetAddressCtrl` um controle de rede e anexá-lo ao objeto.

## <a name="cnetaddressctrlcreate"></a><a name="create"></a>CNetAddressCtrl::Criar

Cria um controle de endereço de rede com `CNetAddressCtrl` estilos especificados e anexa-o ao objeto atual.

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
|*Dwstyle*|[em] Uma combinação de estilos a ser aplicada ao controle. Para obter mais informações, consulte [Editar estilos](../../mfc/reference/styles-used-by-mfc.md#edit-styles).|
|*Rect*|[em] Uma referência a uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que contenha a posição e o tamanho do controle.|
|*Pparentwnd*|[em] Um ponteiro não nulo para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle.|
|*nID*|[em] A id do controle.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="cnetaddressctrlcreateex"></a><a name="createex"></a>CNetAddressCtrl::CreateEx

Cria um controle de endereço de rede com estilos `CNetAddressCtrl` estendidos especificados e anexa-o ao objeto atual.

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
|*Dwexstyle*|[em] Uma combinação bitwise (OR) de estilos estendidos a serem aplicados ao controle. Para obter mais informações, consulte o parâmetro *dwExStyle* da função [CreateWindowEx.](/windows/win32/api/winuser/nf-winuser-createwindowexw)|
|*Dwstyle*|[em] Uma combinação bitwise (OR) de estilos a serem aplicados ao controle. Para obter mais informações, consulte [Editar estilos](../../mfc/reference/styles-used-by-mfc.md#edit-styles).|
|*Rect*|[em] Uma referência a uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que contenha a posição e o tamanho do controle.|
|*Pparentwnd*|[em] Um ponteiro não nulo para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle.|
|*nID*|[em] A id do controle.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="cnetaddressctrldisplayerrortip"></a><a name="displayerrortip"></a>CNetAddressCtrl::DisplayErrorTip

Exibe uma mensagem de erro na ponta do balão associada ao controle atual do endereço de rede.

```
HRESULT DisplayErrorTip();
```

### <a name="return-value"></a>Valor retornado

O `S_OK` valor se este método for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

Use o método [CNetAddressCtrl::SetAllowType](#setallowtype) para especificar os tipos de endereços que o controle atual de endereços de rede pode suportar. Use o método [CNetAddressCtrl::GetAddress](#getaddress) para validar e analisar o endereço de rede que o usuário insere. Use o método [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) para exibir uma dica de infotip de mensagem de erro se o método [CNetAddressCtrl::GetAddress](#getaddress) não tiver sucesso.

Esta mensagem invoca a [macro NetAddr_DisplayErrorTip,](/windows/win32/api/shellapi/nf-shellapi-netaddr_displayerrortip) que é descrita no SDK do Windows. Essa macro `NCM_DISPLAYERRORTIP` envia a mensagem.

## <a name="cnetaddressctrlgetaddress"></a><a name="getaddress"></a>CNetAddressCtrl::GetAddress

Recupera uma representação validada e parsed do endereço de rede que está associada ao controle de endereço de rede atual.

```
HRESULT GetAddress(PNC_ADDRESS pAddress) const;
```

### <a name="parameters"></a>Parâmetros

*pAddress*<br/>
[dentro, fora] Ponteiro para uma estrutura [NC_ADDRESS.](/windows/win32/api/shellapi/ns-shellapi-nc_address)  Defina o membro *pAddrInfo* desta estrutura para o endereço de uma estrutura [de NET_ADDRESS_INFO](/windows/win32/shell/hkey-type) antes de chamar o método GetAddress.

### <a name="return-value"></a>Valor retornado

O valor S_OK se esse método for bem sucedido; caso contrário, um código de erro COM. Para obter mais informações sobre os possíveis códigos de erro, consulte a seção Valor de retorno da [macro NetAddr_GetAddress.](/windows/win32/api/shellapi/nf-shellapi-netaddr_getaddress)

### <a name="remarks"></a>Comentários

Se este método for bem sucedido, a estrutura [NET_ADDRESS_INFO](/windows/win32/shell/hkey-type) contém informações adicionais sobre o endereço da rede.

Use o método [CNetAddressCtrl::SetAllowType](#setallowtype) para especificar os tipos de endereços que o controle atual de endereço de rede pode suportar. Use o método [CNetAddressCtrl::GetAddress](#getaddress) para validar e analisar o endereço de rede que o usuário insere. Use o método [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) para exibir uma dica de infotip de mensagem de erro se o método [CNetAddressCtrl::GetAddress](#getaddress) não tiver sucesso.

Este método invoca a [macro NetAddr_GetAddress,](/windows/win32/api/shellapi/nf-shellapi-netaddr_getaddress) que é descrita no Windows SDK. Essa macro envia a mensagem NCM_GETADDRESS.

## <a name="cnetaddressctrlgetallowtype"></a><a name="getallowtype"></a>CNetAddressCtrl::GetAllowType

Recupera o tipo de endereço de rede que o controle atual de endereço de rede pode suportar.

```
DWORD GetAllowType() const;
```

### <a name="return-value"></a>Valor retornado

Uma combinação bitwise (OR) de sinalizadores que especifica os tipos de endereços que o controle de endereço de rede pode suportar. Para obter mais informações, consulte [NET_STRING](/windows/win32/shell/net-string).

### <a name="remarks"></a>Comentários

Esta mensagem invoca a [NetAddr_GetAllowType](/windows/win32/api/shellapi/nf-shellapi-netaddr_getallowtype) macro, que é descrita no SDK do Windows. Essa macro envia a mensagem NCM_GETALLOWTYPE.

## <a name="cnetaddressctrlsetallowtype"></a><a name="setallowtype"></a>CNetAddressCtrl::SetAllowType

Define o tipo de endereço de rede que o controle atual de endereço de rede pode suportar.

```
HRESULT SetAllowType(DWORD dwAddrMask);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwAddrMask*|[em] Uma combinação bitwise (OR) de sinalizadores que especifica os tipos de endereços que o controle de endereço de rede pode suportar. Para obter mais informações, consulte [NET_STRING](/windows/win32/shell/net-string).|

### <a name="return-value"></a>Valor retornado

S_OK se este método for bem sucedido; caso contrário, um código de erro COM.

### <a name="remarks"></a>Comentários

Use o método [CNetAddressCtrl::SetAllowType](#setallowtype) para especificar os tipos de endereços que o controle atual de endereços de rede pode suportar. Use o método [CNetAddressCtrl::GetAddress](#getaddress) para validar e analisar o endereço de rede que o usuário insere. Use o método [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) para exibir uma dica de infotip de mensagem de erro se o método [CNetAddressCtrl::GetAddress](#getaddress) não tiver sucesso.

Esta mensagem invoca a [NetAddr_SetAllowType](/windows/win32/api/shellapi/nf-shellapi-netaddr_setallowtype) macro, que é descrita no SDK do Windows. Essa macro envia a mensagem NCM_SETALLOWTYPE.

## <a name="see-also"></a>Confira também

[Classe CNetAddressCtrl](../../mfc/reference/cnetaddressctrl-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)

---
title: Classe CIPAddressCtrl
ms.date: 11/04/2016
f1_keywords:
- CIPAddressCtrl
- AFXCMN/CIPAddressCtrl
- AFXCMN/CIPAddressCtrl::CIPAddressCtrl
- AFXCMN/CIPAddressCtrl::ClearAddress
- AFXCMN/CIPAddressCtrl::Create
- AFXCMN/CIPAddressCtrl::CreateEx
- AFXCMN/CIPAddressCtrl::GetAddress
- AFXCMN/CIPAddressCtrl::IsBlank
- AFXCMN/CIPAddressCtrl::SetAddress
- AFXCMN/CIPAddressCtrl::SetFieldFocus
- AFXCMN/CIPAddressCtrl::SetFieldRange
helpviewer_keywords:
- CIPAddressCtrl [MFC], CIPAddressCtrl
- CIPAddressCtrl [MFC], ClearAddress
- CIPAddressCtrl [MFC], Create
- CIPAddressCtrl [MFC], CreateEx
- CIPAddressCtrl [MFC], GetAddress
- CIPAddressCtrl [MFC], IsBlank
- CIPAddressCtrl [MFC], SetAddress
- CIPAddressCtrl [MFC], SetFieldFocus
- CIPAddressCtrl [MFC], SetFieldRange
ms.assetid: 9764d2f4-cb14-4ba8-b799-7f57a55a47c6
ms.openlocfilehash: 28aa0e7137647bc49406dab1e82b9c2b05ca3538
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372348"
---
# <a name="cipaddressctrl-class"></a>Classe CIPAddressCtrl

Fornece a funcionalidade do controle de endereço IP comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CIPAddressCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CIPAddressCtrl::CIPAddressCtrl](#cipaddressctrl)|Constrói um objeto `CIPAddressCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CIPAddressCtrl::ClearAddress](#clearaddress)|Limpa o conteúdo do controle de endereço IP.|
|[CIPAddressCtrl::Criar](#create)|Cria um controle de endereço IP `CIPAddressCtrl` e o anexa a um objeto.|
|[CIPAddressCtrl::CreateEx](#createex)|Cria um controle de endereço IP com os estilos `CIPAddressCtrl` estendidos do Windows especificados e o anexa a um objeto.|
|[CIPAddressCtrl::GetAddress](#getaddress)|Recupera os valores de endereço para todos os quatro campos no Controle de Endereço IP.|
|[CIPAddressCtrl::IsBlank](#isblank)|Determina se todos os campos do controle de endereço IP estão vazios.|
|[CIPAddressCtrl::SetAddressAddress](#setaddress)|Define os valores de endereço para todos os quatro campos no Controle de Endereço IP.|
|[CIPAddressCtrl::SetFieldFocus](#setfieldfocus)|Define o foco do teclado para o campo especificado no controle de endereço ip.|
|[CIPAddressCtrl::SetFieldRange](#setfieldrange)|Define o intervalo no campo especificado no controle de endereço ip.|

## <a name="remarks"></a>Comentários

Um controle de endereço IP, um controle semelhante a um controle de edição, permite que você insira e manipule um endereço numérico no formato IP (Internet Protocol).

Este controle (e, `CIPAddressCtrl` portanto, a classe) está disponível apenas para programas executados sob o Microsoft Internet Explorer 4.0 e posteriores. Eles também estarão disponíveis em versões futuras do Windows e Windows NT.

Para obter informações mais gerais sobre o controle de endereçoip, consulte [controles de endereço IP](/windows/win32/Controls/ip-address-controls) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CIPAddressCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cipaddressctrlcipaddressctrl"></a><a name="cipaddressctrl"></a>CIPAddressCtrl::CIPAddressCtrl

Cria um objeto `CIPAddressCtrl`.

```
CIPAddressCtrl();
```

## <a name="cipaddressctrlclearaddress"></a><a name="clearaddress"></a>CIPAddressCtrl::ClearAddress

Limpa o conteúdo do controle de endereço IP.

```
void ClearAddress();
```

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ipm-clearaddress)Win32 IPM_CLEARADDRESS , conforme descrito no SDK do Windows.

## <a name="cipaddressctrlcreate"></a><a name="create"></a>CIPAddressCtrl::Criar

Cria um controle de endereço IP `CIPAddressCtrl` e o anexa a um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
O estilo do controle de endereço IP. Aplique uma combinação de estilos de janela. Você deve incluir o estilo WS_CHILD porque o controle deve ser uma janela de criança. Consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no Windows SDK para obter uma lista de estilos de janelas.

*Rect*<br/>
Uma referência ao tamanho e posição do controle de endereço IP. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/previous-versions/dd162897\(v=vs.85\))

*Pparentwnd*<br/>
Um ponteiro para a janela pai do controle de endereço ip. Não deve ser NULO.

*nID*<br/>
O ID do controle de endereço IP.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CIPAddressCtrl` um objeto em dois passos.

1. Chame o construtor, que `CIPAddressCtrl` cria o objeto.

1. Chamada `Create`, que cria o controle de endereço IP.

Se você quiser usar estilos de janelas estendidos `Create`com o controle, chame [CreateEx](#createex) em vez de .

## <a name="cipaddressctrlcreateex"></a><a name="createex"></a>CIPAddressCtrl::CreateEx

Chame esta função para criar um controle (uma `CIPAddressCtrl` janela filho) e associá-la com o objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
O estilo do controle de endereço IP. Aplique uma combinação de estilos de janela. Você deve incluir o estilo WS_CHILD porque o controle deve ser uma janela de criança. Consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no Windows SDK para obter uma lista de estilos de janelas.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="cipaddressctrlgetaddress"></a><a name="getaddress"></a>CIPAddressCtrl::GetAddress

Recupera os valores de endereço para todos os quatro campos no Controle de Endereço IP.

```
int GetAddress(
    BYTE& nField0,
    BYTE& nField1,
    BYTE& nField2,
    BYTE& nField3);

int GetAddress(DWORD& dwAddress);
```

### <a name="parameters"></a>Parâmetros

*nField0*<br/>
Uma referência ao valor do campo 0 a partir de um endereço IP embalado.

*nField1*<br/>
Uma referência ao valor do campo 1 a partir de um endereço IP embalado.

*nField2*<br/>
Uma referência ao valor do campo 2 a partir de um endereço IP embalado.

*nField3*<br/>
Uma referência ao valor do campo 3 a partir de um endereço IP embalado.

*Dwaddress*<br/>
Uma referência ao endereço de um valor DWORD que recebe o endereço IP. Consulte **Observações** de uma tabela que mostra como *dwAddress* é preenchido.

### <a name="return-value"></a>Valor retornado

O número de campos não em branco no controle de endereço ip.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ipm-getaddress)Win32 IPM_GETADDRESS , conforme descrito no SDK do Windows. No primeiro protótipo acima, os números nos campos 0 a 3 do controle, lidos da esquerda para a direita, respectivamente, povoam os quatro parâmetros. No segundo protótipo acima, *dwAddress* é povoado da seguinte forma.

|Campo|Bits contendo o valor do campo|
|-----------|-------------------------------------|
|0|24 a 31|
|1|16 a 23|
|2|8 a 15|
|3|0 a 7|

## <a name="cipaddressctrlisblank"></a><a name="isblank"></a>CIPAddressCtrl::IsBlank

Determina se todos os campos do controle de endereço IP estão vazios.

```
BOOL IsBlank() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se todos os campos de controle de endereço IP estiverem vazios; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ipm-isblank)Win32 IPM_ISBLANK , conforme descrito no SDK do Windows.

## <a name="cipaddressctrlsetaddress"></a><a name="setaddress"></a>CIPAddressCtrl::SetAddressAddress

Define os valores de endereço para todos os quatro campos no Controle de Endereço IP.

```
void SetAddress(
    BYTE nField0,
    BYTE nField1,
    BYTE nField2,
    BYTE nField3);

void SetAddress(DWORD dwAddress);
```

### <a name="parameters"></a>Parâmetros

*nField0*<br/>
O valor do campo 0 a partir de um endereço IP embalado.

*nField1*<br/>
O valor do campo 1 a partir de um endereço IP embalado.

*nField2*<br/>
O valor do campo 2 a partir de um endereço IP embalado.

*nField3*<br/>
O valor do campo 3 a partir de um endereço IP embalado.

*Dwaddress*<br/>
Um valor DWORD que contém o novo endereço IP. Consulte **Observações** de uma tabela que mostra como o valor do DWORD é preenchido.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [IPM_SETADDRESS](/windows/win32/Controls/ipm-setaddress)de mensagem Win32 , conforme descrito no SDK do Windows. No primeiro protótipo acima, os números nos campos 0 a 3 do controle, lidos da esquerda para a direita, respectivamente, povoam os quatro parâmetros. No segundo protótipo acima, *dwAddress* é povoado da seguinte forma.

|Campo|Bits contendo o valor do campo|
|-----------|-------------------------------------|
|0|24 a 31|
|1|16 a 23|
|2|8 a 15|
|3|0 a 7|

## <a name="cipaddressctrlsetfieldfocus"></a><a name="setfieldfocus"></a>CIPAddressCtrl::SetFieldFocus

Define o foco do teclado para o campo especificado no controle de endereço ip.

```
void SetFieldFocus(WORD nField);
```

### <a name="parameters"></a>Parâmetros

*nField*<br/>
Índice de campo baseado em zero para o qual o foco deve ser definido. Se esse valor for maior do que o número de campos, o foco será definido no primeiro campo em branco. Se todos os campos não estiverem em branco, o foco será definido no primeiro campo.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [IPM_SETFOCUS](/windows/win32/Controls/ipm-setfocus)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="cipaddressctrlsetfieldrange"></a><a name="setfieldrange"></a>CIPAddressCtrl::SetFieldRange

Define o intervalo no campo especificado no controle de endereço ip.

```
void SetFieldRange(
    int nField,
    BYTE nLower,
    BYTE nUpper);
```

### <a name="parameters"></a>Parâmetros

*nField*<br/>
Índice de campo baseado em zero ao qual o intervalo será aplicado.

*Nlower*<br/>
Uma referência a um inteiro recebendo o limite inferior do campo especificado neste controle de endereço IP.

*Nupper*<br/>
Uma referência a um inteiro recebendo o limite superior do campo especificado neste controle de endereço IP.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [IPM_SETRANGE](/windows/win32/Controls/ipm-setrange)de mensagem Win32 , conforme descrito no SDK do Windows. Use os dois *parâmetros, nLower* e *nUpper,* para indicar os limites inferior e superior do campo, em vez do parâmetro *wRange* usado com a mensagem Win32.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

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
ms.openlocfilehash: fe8e3109b110c27ab32dc1a4f9a132f1e1c18638
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505825"
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
|[CIPAddressCtrl::Create](#create)|Cria um controle de endereço IP e o anexa a um `CIPAddressCtrl` objeto.|
|[CIPAddressCtrl::CreateEx](#createex)|Cria um controle de endereço IP com os estilos estendidos do Windows especificados e o anexa `CIPAddressCtrl` a um objeto.|
|[CIPAddressCtrl::GetAddress](#getaddress)|Recupera os valores de endereço para todos os quatro campos no controle de endereço IP.|
|[CIPAddressCtrl::IsBlank](#isblank)|Determina se todos os campos no controle de endereço IP estão vazios.|
|[CIPAddressCtrl::SetAddress](#setaddress)|Define os valores de endereço para todos os quatro campos no controle de endereço IP.|
|[CIPAddressCtrl::SetFieldFocus](#setfieldfocus)|Define o foco do teclado para o campo especificado no controle de endereço IP.|
|[CIPAddressCtrl::SetFieldRange](#setfieldrange)|Define o intervalo no campo especificado no controle de endereço IP.|

## <a name="remarks"></a>Comentários

Um controle de endereço IP, um controle semelhante a um controle de edição, permite que você insira e manipule um endereço numérico no formato IP (Internet Protocol).

Esse controle (e, portanto `CIPAddressCtrl` , a classe) está disponível somente para programas em execução no Microsoft Internet Explorer 4,0 e posterior. Eles também estarão disponíveis em versões futuras do Windows e do Windows NT.

Para obter mais informações gerais sobre o controle de endereço IP, consulte [controles de endereço IP](/windows/win32/Controls/ip-address-controls) na SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CIPAddressCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="cipaddressctrl"></a>  CIPAddressCtrl::CIPAddressCtrl

Cria um objeto `CIPAddressCtrl`.

```
CIPAddressCtrl();
```

##  <a name="clearaddress"></a>  CIPAddressCtrl::ClearAddress

Limpa o conteúdo do controle de endereço IP.

```
void ClearAddress();
```

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [IPM_CLEARADDRESS](/windows/win32/Controls/ipm-clearaddress)do Win32, conforme descrito na SDK do Windows.

##  <a name="create"></a>  CIPAddressCtrl::Create

Cria um controle de endereço IP e o anexa a um `CIPAddressCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
O estilo do controle de endereço IP. Aplicar uma combinação de estilos de janela. Você deve incluir o estilo WS_CHILD porque o controle deve ser uma janela filho. Consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows para obter uma lista de estilos do Windows.

*rect*<br/>
Uma referência ao tamanho e à posição do controle de endereço IP. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) .

*pParentWnd*<br/>
Um ponteiro para a janela pai do controle de endereço IP. Ele não deve ser nulo.

*nID*<br/>
A ID do controle de endereço IP.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização tiver sido bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CIPAddressCtrl` objeto em duas etapas.

1. Chame o construtor, que cria o `CIPAddressCtrl` objeto.

1. Chamada `Create`, que cria o controle de endereço IP.

Se você quiser usar estilos estendidos do Windows com seu controle, chame [CreateEx](#createex) em `Create`vez de.

##  <a name="createex"></a>  CIPAddressCtrl::CreateEx

Chame essa função para criar um controle (uma janela filho) e associá-lo `CIPAddressCtrl` ao objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
O estilo do controle de endereço IP. Aplicar uma combinação de estilos de janela. Você deve incluir o estilo WS_CHILD porque o controle deve ser uma janela filho. Consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows para obter uma lista de estilos do Windows.

*rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo estilo estendido do Windows **WS_EX_** do prefácio.

##  <a name="getaddress"></a>  CIPAddressCtrl::GetAddress

Recupera os valores de endereço para todos os quatro campos no controle de endereço IP.

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
Uma referência ao valor campo 0 de um endereço IP empacotado.

*nField1*<br/>
Uma referência ao valor de campo 1 de um endereço IP embalado.

*nField2*<br/>
Uma referência ao valor do campo 2 de um endereço IP embalado.

*nField3*<br/>
Uma referência ao valor do campo 3 de um endereço IP embalado.

*dwAddress*<br/>
Uma referência ao endereço de um valor DWORD que recebe o endereço IP. Consulte **comentários** para uma tabela que mostra como o *dwAddress* é preenchido.

### <a name="return-value"></a>Valor de retorno

O número de campos não vazios no controle de endereço IP.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [IPM_GETADDRESS](/windows/win32/Controls/ipm-getaddress)do Win32, conforme descrito na SDK do Windows. No primeiro protótipo acima, os números nos campos 0 a 3 do controle, leitura da esquerda para a direita respectivamente, populem os quatro parâmetros. No segundo protótipo acima, o *dwAddress* é populado da seguinte maneira.

|Campo|Bits que contém o valor do campo|
|-----------|-------------------------------------|
|0|24 a 31|
|1|16 a 23|
|2|8 a 15|
|3|0 a 7|

##  <a name="isblank"></a>  CIPAddressCtrl::IsBlank

Determina se todos os campos no controle de endereço IP estão vazios.

```
BOOL IsBlank() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se todos os campos de controle de endereço IP estiverem vazios; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [IPM_ISBLANK](/windows/win32/Controls/ipm-isblank)do Win32, conforme descrito na SDK do Windows.

##  <a name="setaddress"></a>  CIPAddressCtrl::SetAddress

Define os valores de endereço para todos os quatro campos no controle de endereço IP.

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
O valor do campo 0 de um endereço IP empacotado.

*nField1*<br/>
O valor do campo 1 de um endereço IP empacotado.

*nField2*<br/>
O valor do campo 2 de um endereço IP embalado.

*nField3*<br/>
O valor do campo 3 de um endereço IP empacotado.

*dwAddress*<br/>
Um valor DWORD que contém o novo endereço IP. Consulte **comentários** para uma tabela que mostra como o valor DWORD é preenchido.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [IPM_SETADDRESS](/windows/win32/Controls/ipm-setaddress)do Win32, conforme descrito na SDK do Windows. No primeiro protótipo acima, os números nos campos 0 a 3 do controle, leitura da esquerda para a direita respectivamente, populem os quatro parâmetros. No segundo protótipo acima, o *dwAddress* é populado da seguinte maneira.

|Campo|Bits que contém o valor do campo|
|-----------|-------------------------------------|
|0|24 a 31|
|1|16 a 23|
|2|8 a 15|
|3|0 a 7|

##  <a name="setfieldfocus"></a>  CIPAddressCtrl::SetFieldFocus

Define o foco do teclado para o campo especificado no controle de endereço IP.

```
void SetFieldFocus(WORD nField);
```

### <a name="parameters"></a>Parâmetros

*nField*<br/>
Índice de campo baseado em zero ao qual o foco deve ser definido. Se esse valor for maior que o número de campos, o foco será definido como o primeiro campo em branco. Se todos os campos não estiverem em branco, o foco será definido como o primeiro campo.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [IPM_SETFOCUS](/windows/win32/Controls/ipm-setfocus)do Win32, conforme descrito na SDK do Windows.

##  <a name="setfieldrange"></a>  CIPAddressCtrl::SetFieldRange

Define o intervalo no campo especificado no controle de endereço IP.

```
void SetFieldRange(
    int nField,
    BYTE nLower,
    BYTE nUpper);
```

### <a name="parameters"></a>Parâmetros

*nField*<br/>
Índice de campo baseado em zero ao qual o intervalo será aplicado.

*nLower*<br/>
Uma referência a um inteiro que recebe o limite inferior do campo especificado neste controle de endereço IP.

*nUpper*<br/>
Uma referência a um inteiro que recebe o limite superior do campo especificado neste controle de endereço IP.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [IPM_SETRANGE](/windows/win32/Controls/ipm-setrange)do Win32, conforme descrito na SDK do Windows. Use os dois parâmetros, *nLower* e *nUpper*, para indicar os limites inferior e superior do campo, em vez do parâmetro *wRange* usado com a mensagem do Win32.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

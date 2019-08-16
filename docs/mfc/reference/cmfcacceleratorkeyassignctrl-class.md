---
title: Classe CMFCAcceleratorKeyAssignCtrl
ms.date: 10/18/2018
f1_keywords:
- CMFCAcceleratorKeyAssignCtrl
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::GetAccel
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::IsFocused
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::IsKeyDefined
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::ResetKey
helpviewer_keywords:
- CMFCAcceleratorKeyAssignCtrl [MFC], CMFCAcceleratorKeyAssignCtrl
- CMFCAcceleratorKeyAssignCtrl [MFC], GetAccel
- CMFCAcceleratorKeyAssignCtrl [MFC], IsFocused
- CMFCAcceleratorKeyAssignCtrl [MFC], IsKeyDefined
- CMFCAcceleratorKeyAssignCtrl [MFC], PreTranslateMessage
- CMFCAcceleratorKeyAssignCtrl [MFC], ResetKey
ms.assetid: 89fb8e62-596e-4e71-8c9a-32740347aaab
ms.openlocfilehash: 5e57bf149fdbc293692c613afcabcf2d11d32221
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505466"
---
# <a name="cmfcacceleratorkeyassignctrl-class"></a>Classe CMFCAcceleratorKeyAssignCtrl

A `CMFCAcceleratorKeyAssignCtrl` classe estende a [Classe CEdit](../../mfc/reference/cedit-class.md) para dar suporte a botões adicionais do sistema, como Alt, Control e Shift.

## <a name="syntax"></a>Sintaxe

```
class CMFCAcceleratorKeyAssignCtrl : public CEdit
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl](#cmfcacceleratorkeyassignctrl)|Constrói um objeto `CMFCAcceleratorKeyAssignCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel)|Recupera a `ACCEL` estrutura de uma tecla de atalho pressionada `CMFCAcceleratorKeyAssignCtrl` no objeto.|
|[CMFCAcceleratorKeyAssignCtrl:: IsFocused](#isfocused)||
|[CMFCAcceleratorKeyAssignCtrl::IsKeyDefined](#iskeydefined)|Determina se uma tecla de atalho foi definida.|
|[CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage](#pretranslatemessage)|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para traduzir as mensagens de janela antes que elas sejam expedidas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) do Windows. (Substitui [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCAcceleratorKeyAssignCtrl::ResetKey](#resetkey)|Redefine a tecla de atalho.|

## <a name="remarks"></a>Comentários

Essa classe estende a funcionalidade da classe `CEdit` com suporte a teclas de atalho, também conhecidas como teclas de aceleração. A `CMFCAcceleratorKeyAssignCtrl` classe funciona como uma [Classe CEdit](../../mfc/reference/cedit-class.md) e também pode reconhecer botões do sistema.

Essa classe mapeia combinações de teclas de atalho físicas para valores de cadeia de caracteres. Por exemplo, suponha que a combinação de teclas ALT + B seja mapeada para a cadeia de caracteres "ALT + B". Quando o usuário pressiona essa combinação de teclas em um `CMFCAcceleratorKeyAssignCtrl` objeto, "ALT + B" é exibido para o usuário. Para obter mais informações sobre o mapeamento entre teclas de atalho e um formato de cadeia de caracteres, consulte [classe CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCAcceleratorKeyAssignCtrl` objeto e usar seu `ResetKey` método para redefinir a tecla de atalho.

[!code-cpp[NVC_MFC_RibbonApp#31](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkeyassignctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

`CMFCAcceleratorKeyAssignCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxacceleratorkeyassignctrl. h

##  <a name="cmfcacceleratorkeyassignctrl"></a>CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl

Constrói um objeto [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) .

```
CMFCAcceleratorKeyAssignCtrl();
```

##  <a name="getaccel"></a>CMFCAcceleratorKeyAssignCtrl::GetAccel

Recupera a `ACCEL` estrutura de uma tecla de atalho pressionada no objeto [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) .

```
ACCEL const* GetAccel() const;
```

### <a name="return-value"></a>Valor de retorno

Uma `ACCEL` estrutura que descreve a tecla de atalho.

### <a name="remarks"></a>Comentários

Use essa função para recuperar a `ACCEL` estrutura de uma tecla de atalho inserida pelo usuário em `CMFCAcceleratorKeyAssignCtrl` seu objeto.

##  <a name="isfocused"></a>CMFCAcceleratorKeyAssignCtrl:: IsFocused

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
BOOL IsFocused() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="iskeydefined"></a>CMFCAcceleratorKeyAssignCtrl::IsKeyDefined

Determina se uma tecla de atalho foi definida no objeto [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) .

```
BOOL IsKeyDefined() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário já pressionou uma combinação válida de chaves que definem uma tecla de atalho; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use essa função para determinar se o usuário inseriu uma chave de atalho válida `CMFCAcceleratorKeyAssignCtrl` em seu objeto. Se houver uma tecla de atalho, você poderá usar o método [CMFCAcceleratorKeyAssignCtrl:: GetAccel](#getaccel) para `ACCEL` obter a estrutura associada a essa tecla de atalho.

##  <a name="pretranslatemessage"></a>  CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

no *pMsg*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="resetkey"></a>CMFCAcceleratorKeyAssignCtrl::ResetKey

Redefine a tecla de atalho.

```
void ResetKey();
```

### <a name="remarks"></a>Comentários

A função limpa o texto de controle de edição. Isso inclui qualquer tecla de atalho que o usuário pressionou.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md)

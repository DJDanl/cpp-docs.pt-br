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
ms.openlocfilehash: bd096657de56c0b6daa07004a927b92f1293ddf3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50454412"
---
# <a name="cmfcacceleratorkeyassignctrl-class"></a>Classe CMFCAcceleratorKeyAssignCtrl

O `CMFCAcceleratorKeyAssignCtrl` classe estende a [classe CEdit](../../mfc/reference/cedit-class.md) para dar suporte a botões adicionais do sistema como ALT, CONTROL e SHIFT.

## <a name="syntax"></a>Sintaxe

```
class CMFCAcceleratorKeyAssignCtrl : public CEdit
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl](#cmfcacceleratorkeyassignctrl)|Constrói um objeto `CMFCAcceleratorKeyAssignCtrl`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel)|Recupera o `ACCEL` estrutura para uma tecla de atalho pressionado a `CMFCAcceleratorKeyAssignCtrl` objeto.|
|[CMFCAcceleratorKeyAssignCtrl::IsFocused](#isfocused)||
|[CMFCAcceleratorKeyAssignCtrl::IsKeyDefined](#iskeydefined)|Determina se uma tecla de atalho foi definida.|
|[CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage](#pretranslatemessage)|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCAcceleratorKeyAssignCtrl::ResetKey](#resetkey)|Redefine a tecla de atalho.|

## <a name="remarks"></a>Comentários

Essa classe estende a funcionalidade do `CEdit` classe, oferecendo suporte a teclas de atalho, também conhecido como teclas de aceleração. O `CMFCAcceleratorKeyAssignCtrl` classe funciona como um [classe CEdit](../../mfc/reference/cedit-class.md) e também consegue reconhecer os botões de sistema.

Essa classe mapeia combinações de teclas de atalho físico para os valores de cadeia de caracteres. Por exemplo, suponha que a combinação de teclas ALT + B é mapeado para a cadeia de caracteres "Alt + B". Quando o usuário pressiona essa combinação de teclas em um `CMFCAcceleratorKeyAssignCtrl` do objeto, "Alt + B" é exibida ao usuário. Para obter mais informações sobre o mapeamento entre um formato de cadeia de caracteres e teclas de atalho, consulte [classe CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar uma `CMFCAcceleratorKeyAssignCtrl` do objeto e usar seu `ResetKey` método para redefinir a tecla de atalho.

[!code-cpp[NVC_MFC_RibbonApp#31](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkeyassignctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

`CMFCAcceleratorKeyAssignCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxacceleratorkeyassignctrl.h

##  <a name="cmfcacceleratorkeyassignctrl"></a>  CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl

Constrói uma [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) objeto.

```
CMFCAcceleratorKeyAssignCtrl();
```

##  <a name="getaccel"></a>  CMFCAcceleratorKeyAssignCtrl::GetAccel

Recupera o `ACCEL` estrutura para uma tecla de atalho pressionado a [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) objeto.

```
ACCEL const* GetAccel() const;
```

### <a name="return-value"></a>Valor de retorno

Um `ACCEL` estrutura que descreve a tecla de atalho.

### <a name="remarks"></a>Comentários

Use essa função para recuperar o `ACCEL` estrutura de uma tecla de atalho que o usuário inseriu em sua `CMFCAcceleratorKeyAssignCtrl` objeto.

##  <a name="isfocused"></a>  CMFCAcceleratorKeyAssignCtrl::IsFocused

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
BOOL IsFocused() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="iskeydefined"></a>  CMFCAcceleratorKeyAssignCtrl::IsKeyDefined

Determina se uma tecla de atalho foi definida na [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) objeto.

```
BOOL IsKeyDefined() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário pressionou já uma combinação válida de chaves que definem uma tecla de atalho; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use esta função para determinar se o usuário inseriu uma tecla de atalho válido em seu `CMFCAcceleratorKeyAssignCtrl` objeto. Se existir uma tecla de atalho, você pode usar [CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel) método para obter o `ACCEL` estrutura associada a essa tecla de atalho.

##  <a name="pretranslatemessage"></a>  CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

[in] *pMsg*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="resetkey"></a>  CMFCAcceleratorKeyAssignCtrl::ResetKey

Redefine a tecla de atalho.

```
void ResetKey();
```

### <a name="remarks"></a>Comentários

A função limpa o texto de controle de edição. Isso inclui quaisquer teclas de atalho que o usuário pressionou.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md)

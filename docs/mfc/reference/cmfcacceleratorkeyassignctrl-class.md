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
ms.openlocfilehash: c7b60d9e695351e0c1d97b6629ff19664fcd6d05
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369935"
---
# <a name="cmfcacceleratorkeyassignctrl-class"></a>Classe CMFCAcceleratorKeyAssignCtrl

A `CMFCAcceleratorKeyAssignCtrl` classe estende a [Classe CEdit](../../mfc/reference/cedit-class.md) para suportar botões extras do sistema, como ALT, CONTROL e SHIFT.

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
|[CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel)|Recupera a `ACCEL` estrutura para uma tecla de atalho pressionada no `CMFCAcceleratorKeyAssignCtrl` objeto.|
|[CMFCAcceleratorKeyAssignCtrl::IsFocused](#isfocused)||
|[CMFCAcceleratorKeyAssignCtrl::IsKeyDefined](#iskeydefined)|Determina se uma tecla de atalho foi definida.|
|[CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage](#pretranslatemessage)|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para traduzir mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. (Substitui [cwnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCAcceleratorKeyAssignCtrl::ResetKey](#resetkey)|Redefine a tecla de atalho.|

## <a name="remarks"></a>Comentários

Esta classe amplia a `CEdit` funcionalidade da classe suportando teclas de atalho, também conhecidas como teclas do acelerador. A `CMFCAcceleratorKeyAssignCtrl` classe funciona como uma [Classe CEdit](../../mfc/reference/cedit-class.md) e também pode reconhecer botões do sistema.

Esta classe mapeia combinações de teclas de atalho físicos para valores de seqüência. Por exemplo, suponha que a combinação de teclas ALT + B esteja mapeada para a string "Alt + B". Quando o usuário pressiona esta `CMFCAcceleratorKeyAssignCtrl` combinação de teclas em um objeto, "Alt + B" é exibido para o usuário. Para obter mais informações sobre o mapeamento entre teclas de atalho e um formato de seqüência, consulte [CMFCAcceleratorKey Class](../../mfc/reference/cmfcacceleratorkey-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCAcceleratorKeyAssignCtrl` demonstra como `ResetKey` construir um objeto e usar seu método para redefinir a tecla de atalho.

[!code-cpp[NVC_MFC_RibbonApp#31](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkeyassignctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

`CMFCAcceleratorKeyAssignCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxacceleratorkeyassignctrl.h

## <a name="cmfcacceleratorkeyassignctrlcmfcacceleratorkeyassignctrl"></a><a name="cmfcacceleratorkeyassignctrl"></a>CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl

Constrói um objeto [CMFCAcceleratorKeyAssignCtrl.](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md)

```
CMFCAcceleratorKeyAssignCtrl();
```

## <a name="cmfcacceleratorkeyassignctrlgetaccel"></a><a name="getaccel"></a>CMFCAcceleratorKeyAssignCtrl::GetAccel

Recupera a `ACCEL` estrutura para uma tecla de atalho pressionada no objeto [CMFCAcceleratorKeyAssignCtrl.](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md)

```
ACCEL const* GetAccel() const;
```

### <a name="return-value"></a>Valor retornado

Uma `ACCEL` estrutura que descreve a chave de atalho.

### <a name="remarks"></a>Comentários

Use esta função `ACCEL` para recuperar a estrutura para uma `CMFCAcceleratorKeyAssignCtrl` chave de atalho que o usuário inseriu em seu objeto.

## <a name="cmfcacceleratorkeyassignctrlisfocused"></a><a name="isfocused"></a>CMFCAcceleratorKeyAssignCtrl::IsFocused

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
BOOL IsFocused() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcacceleratorkeyassignctrliskeydefined"></a><a name="iskeydefined"></a>CMFCAcceleratorKeyAssignCtrl::IsKeyDefined

Determina se uma tecla de atalho foi definida no objeto [CMFCAcceleratorKeyAssignCtrl.](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md)

```
BOOL IsKeyDefined() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário já tiver pressionado uma combinação válida de teclas que definem uma tecla de atalho; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use esta função para determinar se o usuário `CMFCAcceleratorKeyAssignCtrl` inseriu uma chave de atalho válida em seu objeto. Se existir uma tecla de atalho, você pode usar o método [CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel) para obter a estrutura associada a `ACCEL` esta tecla de atalho.

## <a name="cmfcacceleratorkeyassignctrlpretranslatemessage"></a><a name="pretranslatemessage"></a>CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

[em] *pMsg*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcacceleratorkeyassignctrlresetkey"></a><a name="resetkey"></a>CMFCAcceleratorKeyAssignCtrl::ResetKey

Redefine a tecla de atalho.

```
void ResetKey();
```

### <a name="remarks"></a>Comentários

A função limpa o texto de controle de edição. Isso inclui todas as teclas de atalho que o usuário pressionou.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md)

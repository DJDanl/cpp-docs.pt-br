---
title: Classe CMFCAcceleratorKey
ms.date: 11/04/2016
f1_keywords:
- CMFCAcceleratorKey
- AFXACCELERATORKEY/CMFCAcceleratorKey
- AFXACCELERATORKEY/CMFCAcceleratorKey::CMFCAcceleratorKey
- AFXACCELERATORKEY/CMFCAcceleratorKey::Format
- AFXACCELERATORKEY/CMFCAcceleratorKey::SetAccelerator
helpviewer_keywords:
- CMFCAcceleratorKey [MFC], CMFCAcceleratorKey
- CMFCAcceleratorKey [MFC], Format
- CMFCAcceleratorKey [MFC], SetAccelerator
ms.assetid: d140fbf7-23db-45ea-a63e-414a5ec7b3d5
ms.openlocfilehash: 7d66e7043325bbbd324f3ac443368787a653ebe1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369921"
---
# <a name="cmfcacceleratorkey-class"></a>Classe CMFCAcceleratorKey

Uma classe auxiliar que implementa mapeamento e formatação de chaves virtuais.

## <a name="syntax"></a>Sintaxe

```
class CMFCAcceleratorKey : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAcceleratorKey::CMFCAcceleratorKey](#cmfcacceleratorkey)|Constrói um objeto `CMFCAcceleratorKey`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAcceleratorKey::Formato](#format)|Traduz a estrutura ACCEL para sua representação visual.|
|[CMFCAcceleratorKey::SetAccelerator](#setaccelerator)|Define a tecla `CMFCAcceleratorKey` de atalho para o objeto.|

## <a name="remarks"></a>Comentários

As teclas do acelerador também são conhecidas como teclas de atalho. Se você quiser exibir atalhos de teclado que um usuário insere, o [CMFCAcceleratorKeyAssignCtrl Class](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) mapeia atalhos de teclado, como Alt+Shift+S, para um formato de texto personalizado, como "Alt + Shift + S". Cada `CMFCAcceleratorKey` objeto mapeia uma única tecla de atalho para um formato de texto.

Para obter mais informações sobre como usar teclas de atalho e tabelas do acelerador, consulte [CKeyboardManager Class](../../mfc/reference/ckeyboardmanager-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCAcceleratorKey` demonstra como construir `Format` um objeto e como usar seu método.

[!code-cpp[NVC_MFC_RibbonApp#30](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkey-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMFCAcceleratorKey`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxacceleratorkey.h

## <a name="cmfcacceleratorkeycmfcacceleratorkey"></a><a name="cmfcacceleratorkey"></a>CMFCAcceleratorKey::CMFCAcceleratorKey

Constrói um objeto [CMFCAcceleratorKey.](../../mfc/reference/cmfcacceleratorkey-class.md)

```
CMFCAcceleratorKey();
CMFCAcceleratorKey(LPACCEL lpAccel);
```

### <a name="parameters"></a>Parâmetros

*LpAccel*<br/>
[em] Um ponteiro para uma tecla de atalho.

### <a name="remarks"></a>Comentários

Se você não fornecer uma chave `CMFCAccleratorKey`de atalho ao criar um , use o método [CMFCAcceleratorKey::SetAccelerator](#setaccelerator) para associar uma chave de atalho com o seu `CMFCAcceleratorKey` objeto.

## <a name="cmfcacceleratorkeyformat"></a><a name="format"></a>CMFCAcceleratorKey::Formato

Traduz a estrutura ACCEL para seu valor de string associado.

```
void Format(CString& str) const;
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
[fora] Uma referência `CString` a um objeto onde o método escreve a tecla de atalho traduzida.

### <a name="remarks"></a>Comentários

Este método recupera o formato de seqüência da tecla de atalho associada. Você pode definir o formato de string de um objeto [CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md) usando o construtor ou o método [CMFCAcceleratorKey::SetAccelerator](#setaccelerator).

## <a name="cmfcacceleratorkeysetaccelerator"></a><a name="setaccelerator"></a>CMFCAcceleratorKey::SetAccelerator

Define a tecla de atalho para o objeto [CMFCAcceleratorKey.](../../mfc/reference/cmfcacceleratorkey-class.md)

```
void SetAccelerator(LPACCEL lpAccel);
```

### <a name="parameters"></a>Parâmetros

*LpAccel*<br/>
[em] Um ponteiro para uma tecla de atalho.

### <a name="remarks"></a>Comentários

Use este método para definir `CMFCAcceleratorKey` a tecla de atalho para um `CMFCAcceleratorKey`se você não forneceu uma chave de atalho quando você criou o .

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)

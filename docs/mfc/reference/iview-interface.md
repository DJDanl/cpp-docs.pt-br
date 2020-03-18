---
title: Interface do IView
ms.date: 11/04/2016
f1_keywords:
- IView
- AFXWINFORMS/IView
- AFXWINFORMS/IView::OnActivateView
- AFXWINFORMS/IView::OnInitialUpdate
- AFXWINFORMS/IView::OnUpdate
helpviewer_keywords:
- views [MFC]
- IView class [MFC]
- views [MFC], classes
ms.assetid: 9321f299-486e-4551-bee9-d2c4a7b91548
ms.openlocfilehash: 22e08a70ff4cc742406a1489899c0ba1df7eb664
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420816"
---
# <a name="iview-interface"></a>Interface do IView

Implementa vários métodos que o [CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição a um controle gerenciado.

## <a name="syntax"></a>Sintaxe

```
interface class IView
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[IView:: OnActivateView](#onactivateview)|Chamado pelo MFC quando uma exibição é ativada ou desativada.|
|[IView:: OnInitialUpdate](#oninitialupdate)|Chamado pelo Framework depois que a exibição é anexada primeiro ao documento, mas antes de a exibição ser inicialmente exibida.|
|[IView:: OnUpdate](#onupdate)|Chamado pelo MFC após a modificação do documento da exibição; Essa função permite que a exibição Atualize sua exibição para refletir as modificações.|

## <a name="remarks"></a>Comentários

`IView` implementa vários métodos que o `CWinFormsView` usa para encaminhar notificações de exibição comuns a um controle gerenciado hospedado. São [OnInitialUpdate](#oninitialupdate), [OnUpdate](#onupdate) e [OnActivateView](#onactivateview).

`IView` é semelhante a [cvisualização](../../mfc/reference/cview-class.md), mas é usado somente com exibições e controles gerenciados.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="requirements"></a>Requisitos

Header: afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)

## <a name="onactivateview"></a>IView:: OnActivateView

Chamado pelo MFC quando uma exibição é ativada ou desativada.
```
void OnActivateView(bool activate);
```

## <a name="parameters"></a>parâmetros

*ativar*<br/>
Indica se a exibição está sendo ativada ou desativada.

## <a name="oninitialupdate"></a>IView:: OnInitialUpdate

Chamado pelo Framework depois que a exibição é anexada primeiro ao documento, mas antes de a exibição ser inicialmente exibida.
```
void OnInitialUpdate();
```

## <a name="onupdate"></a>IView:: OnUpdate

Chamado pelo MFC após a modificação do documento da exibição.
```
void OnUpdate();
```

## <a name="remarks"></a>Comentários

Essa função permite que a exibição Atualize sua exibição para refletir as modificações.

## <a name="see-also"></a>Confira também

[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)

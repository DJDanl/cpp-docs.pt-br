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
ms.openlocfilehash: e8afa7a5f5a7692f88ace4da08209b80f902b603
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445670"
---
# <a name="iview-interface"></a>Interface do IView

Implementa vários métodos que o [CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição a um controle gerenciado.

## <a name="syntax"></a>Sintaxe

```
interface class IView
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IView:: OnActivateView](#onactivateview)|Chamado pelo MFC quando uma exibição é ativada ou desativada.|
|[IView:: OnInitialUpdate](#oninitialupdate)|Chamado pelo Framework depois que a exibição é anexada primeiro ao documento, mas antes de a exibição ser inicialmente exibida.|
|[IView:: OnUpdate](#onupdate)|Chamado pelo MFC após a modificação do documento da exibição; Essa função permite que a exibição Atualize sua exibição para refletir as modificações.|

## <a name="remarks"></a>Comentários

`IView` implementa vários métodos que o `CWinFormsView` usa para encaminhar notificações de exibição comuns a um controle gerenciado hospedado. São [OnInitialUpdate](#oninitialupdate), [OnUpdate](#onupdate) e [OnActivateView](#onactivateview).

`IView` é semelhante a [cvisualização](../../mfc/reference/cview-class.md), mas é usado somente com exibições e controles gerenciados.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

Header: afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)

## <a name="onactivateview"></a>IView:: OnActivateView

Chamado pelo MFC quando uma exibição é ativada ou desativada.

```
void OnActivateView(bool activate);
```

## <a name="parameters"></a>Parâmetros

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

## <a name="see-also"></a>Consulte também

[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)

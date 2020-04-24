---
title: Interface IView
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
ms.openlocfilehash: dfe77699a51ad2670c703d02e13e9062e76debcd
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751286"
---
# <a name="iview-interface"></a>Interface IView

Implementa vários métodos que [o CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição para um controle gerenciado.

## <a name="syntax"></a>Sintaxe

```
interface class IView
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iView::OnActivateView](#onactivateview)|Chamado por MFC quando uma exibição é ativada ou desativada.|
|[iView::OnInitialUpdate](#oninitialupdate)|Chamado pelo framework após a exibição é anexado primeiro ao documento, mas antes que a exibição seja exibida inicialmente.|
|[IView::OnUpdate](#onupdate)|Chamado por MFC após a modificação do documento da exibição; esta função permite que a exibição atualize seu display para refletir modificações.|

## <a name="remarks"></a>Comentários

`IView`implementa vários métodos que `CWinFormsView` usam para encaminhar notificações de exibição comuns para um controle gerenciado hospedado. Estes são [OnInitialUpdate,](#oninitialupdate) [OnUpdate](#onupdate) e [OnActivateView](#onactivateview).

`IView`é semelhante ao [CView,](../../mfc/reference/cview-class.md)mas é usado apenas com visualizações e controles gerenciados.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="requirements"></a>Requisitos

Cabeçalho: afxwinforms.h (definido em montagem atlmfc\lib\mfcmifc80.dll)

## <a name="iviewonactivateview"></a><a name="onactivateview"></a>iView::OnActivateView

Chamado por MFC quando uma exibição é ativada ou desativada.

```cpp
void OnActivateView(bool activate);
```

## <a name="parameters"></a>Parâmetros

*Ativar*<br/>
Indica se a visão está sendo ativada ou desativada.

## <a name="iviewoninitialupdate"></a><a name="oninitialupdate"></a>iView::OnInitialUpdate

Chamado pelo framework após a exibição é anexado primeiro ao documento, mas antes que a exibição seja exibida inicialmente.

```cpp
void OnInitialUpdate();
```

## <a name="iviewonupdate"></a><a name="onupdate"></a>IView::OnUpdate

Chamado por MFC depois que o documento da exibição foi modificado.

```cpp
void OnUpdate();
```

## <a name="remarks"></a>Comentários

Esta função permite que a visualização atualize seu display para refletir modificações.

## <a name="see-also"></a>Confira também

[Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)

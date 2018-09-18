---
title: Classe CAxDialogImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CAxDialogImpl
- ATLWIN/ATL::CAxDialogImpl
- ATLWIN/ATL::CAxDialogImpl::AdviseSinkMap
- ATLWIN/ATL::CAxDialogImpl::Create
- ATLWIN/ATL::CAxDialogImpl::DestroyWindow
- ATLWIN/ATL::CAxDialogImpl::DoModal
- ATLWIN/ATL::CAxDialogImpl::EndDialog
- ATLWIN/ATL::CAxDialogImpl::GetDialogProc
- ATLWIN/ATL::CAxDialogImpl::GetIDD
- ATLWIN/ATL::CAxDialogImpl::IsDialogMessage
- ATLWIN/ATL::CAxDialogImpl::m_bModal
dev_langs:
- C++
helpviewer_keywords:
- CAxDialogImpl class
- ATL, dialog boxes
ms.assetid: 817df483-3fa8-44e7-8487-72ba0881cd27
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a22b04bd0a362824e20621eaa7f66cafd0e55cf5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024487"
---
# <a name="caxdialogimpl-class"></a>Classe CAxDialogImpl

Essa classe implementa uma caixa de diálogo (modal ou sem-modo) que hospeda controles ActiveX.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TBase = CWindow>
class ATL_NO_VTABLE CAxDialogImpl : public CDialogImplBaseT<TBase>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CAxDialogImpl`.

*Tdígitos de base*<br/>
A classe de janela base para `CDialogImplBaseT`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxDialogImpl::AdviseSinkMap](#advisesinkmap)|Chame esse método para recomendar ou não recomendar todas as entradas no mapa de eventos do objeto coletor mapa.|
|[CAxDialogImpl::Create](#create)|Chame esse método para criar uma caixa de diálogo sem janela restrita.|
|[CAxDialogImpl::DestroyWindow](#destroywindow)|Chame esse método para destruir uma caixa de diálogo sem janela restrita.|
|[CAxDialogImpl::DoModal](#domodal)|Chame esse método para criar uma caixa de diálogo modal.|
|[CAxDialogImpl::EndDialog](#enddialog)|Chame esse método para destruir uma caixa de diálogo modal.|
|[CAxDialogImpl::GetDialogProc](#getdialogproc)|Chame esse método para obter um ponteiro para o `DialogProc` função de retorno de chamada.|
|[CAxDialogImpl::GetIDD](#getidd)|Chame esse método para obter a ID de recurso de modelo de caixa de diálogo|
|[CAxDialogImpl::IsDialogMessage](#isdialogmessage)|Chame esse método para determinar se uma mensagem destina-se para essa caixa de diálogo e, se for, processar a mensagem.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAxDialogImpl::m_bModal](#m_bmodal)|Uma variável que existe apenas na depuração compilações e é definido como verdadeiro se a caixa de diálogo modal.|

## <a name="remarks"></a>Comentários

`CAxDialogImpl` permite que você crie uma caixa de diálogo modal ou sem janela restrita. `CAxDialogImpl` fornece o procedimento de caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens para manipuladores adequados.

`CAxDialogImpl` deriva `CDialogImplBaseT`, que por sua vez deriva *tdígitos de base* (por padrão, `CWindow`) e `CMessageMap`.

Sua classe deve definir um membro IDD que especifica a ID de recurso de modelo de caixa de diálogo. Por exemplo, adicionando um objeto de caixa de diálogo do ATL usando o **Adicionar classe** caixa de diálogo adiciona automaticamente a linha a seguir à sua classe:

[!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/caxdialogimpl-class_1.h)]

em que `MyDialog` é o **Short name** inseridas no Assistente de caixa de diálogo do ATL.

Ver [implementar uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações.

Observe que um controle ActiveX em uma caixa de diálogo modal criado com `CAxDialogImpl` não oferecerá suporte a teclas de aceleração. Para dar suporte a teclas de aceleração criada com uma caixa de diálogo `CAxDialogImpl`, crie uma caixa de diálogo sem janela restrita e, usando seu próprio loop de mensagem, use [CAxDialogImpl::IsDialogMessage](#isdialogmessage) depois de obter uma mensagem da fila para lidar com um tecla de aceleração.

Para obter mais informações sobre `CAxDialogImpl`, consulte [perguntas frequentes sobre contenção de controle do ATL](../../atl/atl-control-containment-faq.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMessageMap](../../atl/reference/cmessagemap-class.md)

`TBase`

`CWindowImplRoot`

`CDialogImplBaseT`

`CAxDialogImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="advisesinkmap"></a>  CAxDialogImpl::AdviseSinkMap

Chame esse método para recomendar ou não recomendar todas as entradas no mapa de eventos do objeto coletor mapa.

```
HRESULT AdviseSinkMap(bool bAdvise);
```

### <a name="parameters"></a>Parâmetros

*bAdvise*<br/>
Definido como true se todas as entradas de coletor devem ser avisado; entradas de receptor false se todos os forem unadvised.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="create"></a>  CAxDialogImpl::Create

Chame esse método para criar uma caixa de diálogo sem janela restrita.

```
HWND Create(HWND hWndParent, LPARAM dwInitParam = NULL);
HWND Create(HWND hWndParent, RECT&, LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
[in] O identificador para a janela do proprietário.

*dwInitParam*<br/>
[in] Especifica o valor para passar para a caixa de diálogo do *lParam* parâmetro da mensagem WM_INITDIALOG.

*RECT &AMP;*<br/>
Este parâmetro não é usado. Esse parâmetro é passado pelo `CComControl`.

### <a name="return-value"></a>Valor de retorno

O identificador para a caixa de diálogo recém-criado.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao `CAxDialogImpl` objeto. Para criar uma caixa de diálogo modal, chame [DoModal](#domodal).

A segunda substituição é fornecida somente para caixas de diálogo podem ser usadas com [CComControl](../../atl/reference/ccomcontrol-class.md).

##  <a name="destroywindow"></a>  CAxDialogImpl::DestroyWindow

Chame esse método para destruir uma caixa de diálogo sem janela restrita.

```
BOOL DestroyWindow();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a janela for destruída com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Não chame `DestroyWindow` destruir uma caixa de diálogo modal. Chame [EndDialog](#enddialog) em vez disso.

##  <a name="domodal"></a>  CAxDialogImpl::DoModal

Chame esse método para criar uma caixa de diálogo modal.

```
INT_PTR DoModal(
    HWND hWndParent = ::GetActiveWindow(),
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
[in] O identificador para a janela do proprietário. O valor padrão é o valor de retorno de [GetActiveWindow](https://msdn.microsoft.com/library/windows/desktop/ms646292) função do Win32.

*dwInitParam*<br/>
[in] Especifica o valor para passar para a caixa de diálogo do *lParam* parâmetro da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o valor de *nRetCode* parâmetro especificado na chamada para [EndDialog](#enddialog); caso contrário, -1.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao `CAxDialogImpl` objeto.

Para criar uma caixa de diálogo sem janela restrita, chame [criar](#create).

##  <a name="enddialog"></a>  CAxDialogImpl::EndDialog

Chame esse método para destruir uma caixa de diálogo modal.

```
BOOL EndDialog(int nRetCode);
```

### <a name="parameters"></a>Parâmetros

*nRetCode*<br/>
[in] O valor a ser retornado por [DoModal](#domodal).

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de diálogo é destruída; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`EndDialog` deve ser chamado por meio do procedimento de caixa de diálogo. Depois que a caixa de diálogo é destruída, o Windows usa o valor de *nRetCode* como o valor de retorno para `DoModal`, que criou a caixa de diálogo.

> [!NOTE]
>  Não chame `EndDialog` destruir uma caixa de diálogo sem janela restrita. Chame [DestroyWindow](#destroywindow) em vez disso.

##  <a name="getdialogproc"></a>  CAxDialogImpl::GetDialogProc

Chame esse método para obter um ponteiro para o `DialogProc` função de retorno de chamada.

```
virtual DLGPROC GetDialogProc();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o `DialogProc` função de retorno de chamada.

### <a name="remarks"></a>Comentários

O `DialogProc` é uma função de retorno de chamada definida pelo aplicativo.

##  <a name="getidd"></a>  CAxDialogImpl::GetIDD

Chame esse método para obter a ID de recurso de modelo de caixa de diálogo.

```
int GetIDD();
```

### <a name="return-value"></a>Valor de retorno

Retorna a ID de recurso de modelo de caixa de diálogo.

##  <a name="isdialogmessage"></a>  CAxDialogImpl::IsDialogMessage

Chame esse método para determinar se uma mensagem destina-se para essa caixa de diálogo e, se for, processar a mensagem.

```
BOOL IsDialogMessage(LPMSG pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Ponteiro para um [MSG](https://msdn.microsoft.com/library/windows/desktop/ms644958) estrutura que contém a mensagem a ser verificado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a mensagem tiver sido processada, FALSE caso contrário.

### <a name="remarks"></a>Comentários

Este método destina-se a ser chamado de dentro de um loop de mensagem.

##  <a name="m_bmodal"></a>  CAxDialogImpl::m_bModal

Uma variável que existe apenas na depuração compilações e é definido como verdadeiro se a caixa de diálogo modal.

```
bool m_bModal;
```

## <a name="see-also"></a>Consulte também

[Classe CDialogImpl](../../atl/reference/cdialogimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

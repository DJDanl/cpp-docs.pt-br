---
title: Classe CAxDialogImpl
ms.date: 11/04/2016
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
helpviewer_keywords:
- CAxDialogImpl class
- ATL, dialog boxes
ms.assetid: 817df483-3fa8-44e7-8487-72ba0881cd27
ms.openlocfilehash: d8e60a817d197f67c14318a7d50ddf796e570142
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318734"
---
# <a name="caxdialogimpl-class"></a>Classe CAxDialogImpl

Esta classe implementa uma caixa de diálogo (modal ou modeless) que hospeda controles ActiveX.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TBase = CWindow>
class ATL_NO_VTABLE CAxDialogImpl : public CDialogImplBaseT<TBase>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CAxDialogImpl`.

*Tbase*<br/>
A classe da `CDialogImplBaseT`janela base para .

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAxDialogImpl::AdviseSinkMap](#advisesinkmap)|Chame este método para aconselhar ou desaconselhar todas as entradas no mapa de eventos do mapa do dissipador do objeto.|
|[CAxDialogImpl::Criar](#create)|Chame este método para criar uma caixa de diálogo modeless.|
|[CAxDialogImpl::DestroyWindow](#destroywindow)|Chame este método para destruir uma caixa de diálogo modeless.|
|[CAxDialogImpl::DoModal](#domodal)|Chame este método para criar uma caixa de diálogo modal.|
|[CAxDialogImpl::EndDialog](#enddialog)|Chame este método para destruir uma caixa de diálogo modal.|
|[CAxDialogImpl::GetDialogProc](#getdialogproc)|Chame este método para obter `DialogProc` um ponteiro para a função de retorno de chamada.|
|[CAxDialogImpl::GetIDD](#getidd)|Chame este método para obter o modelo de diálogo ID de recurso|
|[CAxDialogImpl::IsDialogMessage](#isdialogmessage)|Chame este método para determinar se uma mensagem é destinada a esta caixa de diálogo e, se for, processe a mensagem.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAxDialogImpl::m_bModal](#m_bmodal)|Uma variável que só existe em compilações de depuração e é definida como verdadeira se a caixa de diálogo for modal.|

## <a name="remarks"></a>Comentários

`CAxDialogImpl`permite que você crie uma caixa de diálogo modal ou modeless. `CAxDialogImpl`fornece o procedimento da caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens aos manipuladores apropriados.

`CAxDialogImpl`deriva de `CDialogImplBaseT`, que por sua vez deriva `CWindow`de `CMessageMap` *TBase* (por padrão, ) e .

Sua classe deve definir um membro do IDD que especifica o ID de recurso do modelo de diálogo. Por exemplo, adicionar um objeto de diálogo ATL usando a caixa de diálogo **Adicionar classe** adiciona automaticamente a seguinte linha à sua classe:

[!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/caxdialogimpl-class_1.h)]

onde `MyDialog` está o **nome Curto** inserido no Assistente de Diálogo ATL.

Consulte [Implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações.

Observe que um controle ActiveX em uma `CAxDialogImpl` caixa de diálogo modal criada com não suportará as teclas do acelerador. Para suportar as teclas do `CAxDialogImpl`acelerador em uma caixa de diálogo criada com , crie uma caixa de diálogo modeless e, usando seu próprio loop de mensagem, use [CAxDialogImpl::IsDialogMessage](#isdialogmessage) depois de receber uma mensagem da fila para lidar com uma chave do acelerador.

Para obter `CAxDialogImpl`mais informações sobre , consulte [ATL Control Containment FAQ](../../atl/atl-control-containment-faq.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmessagemap](../../atl/reference/cmessagemap-class.md)

`TBase`

`CWindowImplRoot`

`CDialogImplBaseT`

`CAxDialogImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="caxdialogimpladvisesinkmap"></a><a name="advisesinkmap"></a>CAxDialogImpl::AdviseSinkMap

Chame este método para aconselhar ou desaconselhar todas as entradas no mapa de eventos do mapa do dissipador do objeto.

```
HRESULT AdviseSinkMap(bool bAdvise);
```

### <a name="parameters"></a>Parâmetros

*bAconselhar*<br/>
Definido como verdadeiro se todas as entradas da pia forem aconselhadas; falso se todas as entradas da pia devem ser desaconselhadas.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="caxdialogimplcreate"></a><a name="create"></a>CAxDialogImpl::Criar

Chame este método para criar uma caixa de diálogo modeless.

```
HWND Create(HWND hWndParent, LPARAM dwInitParam = NULL);
HWND Create(HWND hWndParent, RECT&, LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
[em] A alça da janela do dono.

*dwInitParam*<br/>
[em] Especifica o valor a ser repassar para a caixa de diálogo no parâmetro *lParam* da mensagem WM_INITDIALOG.

*&RECT*<br/>
Este parâmetro não é usado. Este parâmetro é passado `CComControl`por .

### <a name="return-value"></a>Valor retornado

A alça da caixa de diálogo recém-criada.

### <a name="remarks"></a>Comentários

Esta caixa de diálogo é `CAxDialogImpl` automaticamente anexada ao objeto. Para criar uma caixa de diálogo modal, ligue para [DoModal](#domodal).

A segunda substituição é fornecida apenas para que as caixas de diálogo possam ser usadas com [CComControl](../../atl/reference/ccomcontrol-class.md).

## <a name="caxdialogimpldestroywindow"></a><a name="destroywindow"></a>CAxDialogImpl::DestroyWindow

Chame este método para destruir uma caixa de diálogo modeless.

```
BOOL DestroyWindow();
```

### <a name="return-value"></a>Valor retornado

VERDADE se a janela for destruída com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Não ligue `DestroyWindow` para destruir uma caixa de diálogo modal. Em vez disso, ligue [para enddialog.](#enddialog)

## <a name="caxdialogimpldomodal"></a><a name="domodal"></a>CAxDialogImpl::DoModal

Chame este método para criar uma caixa de diálogo modal.

```
INT_PTR DoModal(
    HWND hWndParent = ::GetActiveWindow(),
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
[em] A alça da janela do dono. O valor padrão é o valor de retorno da função [GetActiveWindow](/windows/win32/api/winuser/nf-winuser-getactivewindow) Win32.

*dwInitParam*<br/>
[em] Especifica o valor a ser repassar para a caixa de diálogo no parâmetro *lParam* da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o valor do parâmetro *nRetCode* especificado na chamada para [EndDialog](#enddialog); caso contrário, -1.

### <a name="remarks"></a>Comentários

Esta caixa de diálogo é `CAxDialogImpl` automaticamente anexada ao objeto.

Para criar uma caixa de diálogo modeless, chame [Criar](#create).

## <a name="caxdialogimplenddialog"></a><a name="enddialog"></a>CAxDialogImpl::EndDialog

Chame este método para destruir uma caixa de diálogo modal.

```
BOOL EndDialog(int nRetCode);
```

### <a name="parameters"></a>Parâmetros

*Nretcode*<br/>
[em] O valor a ser devolvido pela [DoModal](#domodal).

### <a name="return-value"></a>Valor retornado

VERDADE se a caixa de diálogo for destruída; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`EndDialog`deve ser chamado através do procedimento da caixa de diálogo. Depois que a caixa de diálogo é destruída, o Windows usa `DoModal`o valor do *nRetCode* como o valor de retorno para , que criou a caixa de diálogo.

> [!NOTE]
> Não ligue `EndDialog` para destruir uma caixa de diálogo modeladora. Em vez [disso, ligue para DestroyWindow.](#destroywindow)

## <a name="caxdialogimplgetdialogproc"></a><a name="getdialogproc"></a>CAxDialogImpl::GetDialogProc

Chame este método para obter `DialogProc` um ponteiro para a função de retorno de chamada.

```
virtual DLGPROC GetDialogProc();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `DialogProc` para a função de retorno de chamada.

### <a name="remarks"></a>Comentários

A `DialogProc` função é uma função de retorno de chamada definida pelo aplicativo.

## <a name="caxdialogimplgetidd"></a><a name="getidd"></a>CAxDialogImpl::GetIDD

Chame este método para obter o iD de recurso do modelo de diálogo.

```
int GetIDD();
```

### <a name="return-value"></a>Valor retornado

Retorna o modelo de diálogo ID de recurso.

## <a name="caxdialogimplisdialogmessage"></a><a name="isdialogmessage"></a>CAxDialogImpl::IsDialogMessage

Chame este método para determinar se uma mensagem é destinada a esta caixa de diálogo e, se for, processe a mensagem.

```
BOOL IsDialogMessage(LPMSG pMsg);
```

### <a name="parameters"></a>Parâmetros

*pMsg*<br/>
Pointer para uma estrutura [MSG](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser verificada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a mensagem tiver sido processada, FALSA de outra forma.

### <a name="remarks"></a>Comentários

Este método destina-se a ser chamado de dentro de um loop de mensagem.

## <a name="caxdialogimplm_bmodal"></a><a name="m_bmodal"></a>CAxDialogImpl::m_bModal

Uma variável que só existe em compilações de depuração e é definida como verdadeira se a caixa de diálogo for modal.

```
bool m_bModal;
```

## <a name="see-also"></a>Confira também

[Classe CDialogImpl](../../atl/reference/cdialogimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

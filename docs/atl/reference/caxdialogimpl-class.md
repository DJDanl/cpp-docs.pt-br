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
ms.openlocfilehash: 548d2aed0644187b4b8dee1e472b581f1f92d6a1
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418009"
---
# <a name="caxdialogimpl-class"></a>Classe CAxDialogImpl

Essa classe implementa uma caixa de diálogo (modal ou sem janela restrita) que hospeda controles ActiveX.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TBase = CWindow>
class ATL_NO_VTABLE CAxDialogImpl : public CDialogImplBaseT<TBase>
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `CAxDialogImpl`.

*TBase*<br/>
A classe da janela base para `CDialogImplBaseT`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAxDialogImpl::AdviseSinkMap](#advisesinkmap)|Chame esse método para aconselhar ou cancelar todas as entradas no mapa de eventos do mapa do coletor do objeto.|
|[CAxDialogImpl:: criar](#create)|Chame esse método para criar uma caixa de diálogo sem janela restrita.|
|[CAxDialogImpl::D estroyWindow](#destroywindow)|Chame esse método para destruir uma caixa de diálogo sem janela restrita.|
|[CAxDialogImpl::D oModal](#domodal)|Chame esse método para criar uma caixa de diálogo modal.|
|[CAxDialogImpl:: EndDialog](#enddialog)|Chame esse método para destruir uma caixa de diálogo modal.|
|[CAxDialogImpl::GetDialogProc](#getdialogproc)|Chame esse método para obter um ponteiro para a função de retorno de chamada `DialogProc`.|
|[CAxDialogImpl::GetIDD](#getidd)|Chamar este método para obter a ID de recurso do modelo de caixa de diálogo|
|[CAxDialogImpl::IsDialogMessage](#isdialogmessage)|Chame esse método para determinar se uma mensagem é destinada a essa caixa de diálogo e, se for, processar a mensagem.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CAxDialogImpl:: m_bModal](#m_bmodal)|Uma variável que existe somente em compilações de depuração e é definida como true se a caixa de diálogo for modal.|

## <a name="remarks"></a>Comentários

`CAxDialogImpl` permite que você crie uma caixa de diálogo modal ou sem janela restrita. `CAxDialogImpl` fornece o procedimento da caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens para os manipuladores apropriados.

`CAxDialogImpl` deriva de `CDialogImplBaseT`, que, por sua vez, deriva de *TBase* (por padrão, `CWindow`) e `CMessageMap`.

Sua classe deve definir um membro IDD que especifica a ID de recurso do modelo de caixa de diálogo. Por exemplo, adicionar um objeto de caixa de diálogo ATL usando a caixa de diálogo **Adicionar classe** adiciona automaticamente a seguinte linha à sua classe:

[!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/caxdialogimpl-class_1.h)]

onde `MyDialog` é o **nome curto** inserido no assistente de caixa de diálogo do ATL.

Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações.

Observe que um controle ActiveX em uma caixa de diálogo modal criada com `CAxDialogImpl` não dará suporte a teclas de aceleração. Para dar suporte a teclas do acelerador em uma caixa de diálogo criada com `CAxDialogImpl`, crie uma caixa de diálogo sem janela restrita e, usando seu próprio loop de mensagem, use [CAxDialogImpl:: IsDialogMessage](#isdialogmessage) depois de obter uma mensagem da fila para manipular uma tecla aceleradora.

Para obter mais informações sobre `CAxDialogImpl`, consulte [FAQ de contenção de controle ATL](../../atl/atl-control-containment-faq.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMessageMap](../../atl/reference/cmessagemap-class.md)

`TBase`

`CWindowImplRoot`

`CDialogImplBaseT`

`CAxDialogImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="advisesinkmap"></a>CAxDialogImpl::AdviseSinkMap

Chame esse método para aconselhar ou cancelar todas as entradas no mapa de eventos do mapa do coletor do objeto.

```
HRESULT AdviseSinkMap(bool bAdvise);
```

### <a name="parameters"></a>parâmetros

*bAdvise*<br/>
Defina como true se todas as entradas do coletor forem recomendadas; false se todas as entradas do coletor forem desaconselhadas.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="create"></a>CAxDialogImpl:: criar

Chame esse método para criar uma caixa de diálogo sem janela restrita.

```
HWND Create(HWND hWndParent, LPARAM dwInitParam = NULL);
HWND Create(HWND hWndParent, RECT&, LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>parâmetros

*hWndParent*<br/>
no O identificador para a janela do proprietário.

*dwInitParam*<br/>
no Especifica o valor a ser passado para a caixa de diálogo no parâmetro *lParam* da mensagem de WM_INITDIALOG.

*RECT &*<br/>
Este parâmetro não é usado. Esse parâmetro é passado por `CComControl`.

### <a name="return-value"></a>Valor retornado

O identificador para a caixa de diálogo recém-criada.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao objeto `CAxDialogImpl`. Para criar uma caixa de diálogo modal, chame [DoModal](#domodal).

A segunda substituição é fornecida apenas para que as caixas de diálogo possam ser usadas com [CComControl](../../atl/reference/ccomcontrol-class.md).

##  <a name="destroywindow"></a>CAxDialogImpl::D estroyWindow

Chame esse método para destruir uma caixa de diálogo sem janela restrita.

```
BOOL DestroyWindow();
```

### <a name="return-value"></a>Valor retornado

TRUE se a janela for destruída com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Não chame `DestroyWindow` para destruir uma caixa de diálogo modal. Em vez disso, chame [EndDialog](#enddialog) .

##  <a name="domodal"></a>CAxDialogImpl::D oModal

Chame esse método para criar uma caixa de diálogo modal.

```
INT_PTR DoModal(
    HWND hWndParent = ::GetActiveWindow(),
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>parâmetros

*hWndParent*<br/>
no O identificador para a janela do proprietário. O valor padrão é o valor de retorno da função Win32 [GetActiveWindow](/windows/win32/api/winuser/nf-winuser-getactivewindow) .

*dwInitParam*<br/>
no Especifica o valor a ser passado para a caixa de diálogo no parâmetro *lParam* da mensagem de WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o valor do parâmetro *nRetCode* especificado na chamada para [EndDialog](#enddialog); caso contrário,-1.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao objeto `CAxDialogImpl`.

Para criar uma caixa de diálogo sem janela restrita, chame [Create](#create).

##  <a name="enddialog"></a>CAxDialogImpl:: EndDialog

Chame esse método para destruir uma caixa de diálogo modal.

```
BOOL EndDialog(int nRetCode);
```

### <a name="parameters"></a>parâmetros

*nRetCode*<br/>
no O valor a ser retornado por [DoModal](#domodal).

### <a name="return-value"></a>Valor retornado

TRUE se a caixa de diálogo for destruída; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`EndDialog` deve ser chamado por meio do procedimento da caixa de diálogo. Depois que a caixa de diálogo é destruída, o Windows usa o valor de *nRetCode* como o valor de retorno para `DoModal`, que criou a caixa de diálogo.

> [!NOTE]
>  Não chame `EndDialog` para destruir uma caixa de diálogo sem janela restrita. Em vez disso, chame [DestroyWindow](#destroywindow) .

##  <a name="getdialogproc"></a>CAxDialogImpl::GetDialogProc

Chame esse método para obter um ponteiro para a função de retorno de chamada `DialogProc`.

```
virtual DLGPROC GetDialogProc();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função de retorno de chamada `DialogProc`.

### <a name="remarks"></a>Comentários

A função `DialogProc` é uma função de retorno de chamada definida pelo aplicativo.

##  <a name="getidd"></a>CAxDialogImpl::GetIDD

Chame esse método para obter a ID de recurso do modelo de caixa de diálogo.

```
int GetIDD();
```

### <a name="return-value"></a>Valor retornado

Retorna a ID de recurso do modelo de caixa de diálogo.

##  <a name="isdialogmessage"></a>CAxDialogImpl::IsDialogMessage

Chame esse método para determinar se uma mensagem é destinada a essa caixa de diálogo e, se for, processar a mensagem.

```
BOOL IsDialogMessage(LPMSG pMsg);
```

### <a name="parameters"></a>parâmetros

*pMsg*<br/>
Ponteiro para uma estrutura de [msg](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser verificada.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se a mensagem tiver sido processada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método deve ser chamado de dentro de um loop de mensagem.

##  <a name="m_bmodal"></a>CAxDialogImpl:: m_bModal

Uma variável que existe somente em compilações de depuração e é definida como true se a caixa de diálogo for modal.

```
bool m_bModal;
```

## <a name="see-also"></a>Confira também

[Classe CDialogImpl](../../atl/reference/cdialogimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

---
title: Classe CDialogImpl
ms.date: 11/04/2016
f1_keywords:
- CDialogImpl
- ATLWIN/ATL::CDialogImpl
- ATLWIN/ATL::Create
- ATLWIN/ATL::DestroyWindow
- ATLWIN/ATL::DoModal
- ATLWIN/ATL::EndDialog
- ATLWIN/ATL::GetDialogProc
- ATLWIN/ATL::MapDialogRect
- ATLWIN/ATL::OnFinalMessage
- ATLWIN/ATL::DialogProc
- ATLWIN/ATL::StartDialogProc
helpviewer_keywords:
- dialog boxes, ATL
- CDialogImpl class
ms.assetid: d430bc7b-8a28-4ad3-9507-277bdd2c2c2e
ms.openlocfilehash: b92b5130b31e88565d79b59a24b2bd377d0d84c0
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834720"
---
# <a name="cdialogimpl-class"></a>Classe CDialogImpl

Essa classe fornece métodos para criar uma caixa de diálogo modal ou sem janela restrita.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T,
    class TBase = CWindow>
    class ATL_NO_VTABLE CDialogImpl : public CDialogImplBaseT<TBase>
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `CDialogImpl` .

*TBase*<br/>
A classe base da sua nova classe. A classe base padrão é [CWindow](../../atl/reference/cwindow-class.md).

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Função|Descrição|
|-|-|
|[Criar](#create)|Cria uma caixa de diálogo sem janela restrita.|
|[DestroyWindow](#destroywindow)|Destrói uma caixa de diálogo sem janela restrita.|
|[DoModal](#domodal)|Cria uma caixa de diálogo modal.|
|[EndDialog](#enddialog)|Destrói uma caixa de diálogo modal.|

### <a name="cdialogimplbaset-methods"></a>Métodos CDialogImplBaseT

|Função|Descrição|
|-|-|
|[GetDialogProc](#getdialogproc)|Retorna o procedimento da caixa de diálogo atual.|
|[MapDialogRect](#mapdialogrect)|Mapeia as unidades da caixa de diálogo do retângulo especificado para as unidades da tela (pixels).|
|[OnFinalMessage](#onfinalmessage)|Chamado depois de receber a última mensagem, normalmente WM_NCDESTROY.|

### <a name="static-functions"></a>Funções estáticas

|Função|Descrição|
|-|-|
|[DialogProc](#dialogproc)|Processa as mensagens enviadas para a caixa de diálogo.|
|[StartDialogProc](#startdialogproc)|Chamado quando a primeira mensagem é recebida para processar mensagens enviadas para a caixa de diálogo.|

## <a name="remarks"></a>Comentários

Com `CDialogImpl` o, você pode criar uma caixa de diálogo modal ou sem janela restrita. `CDialogImpl` fornece o procedimento da caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens para os manipuladores apropriados.

O destruidor de classe base `~CWindowImplRoot` garante que a janela tenha desaparecido antes de destruir o objeto.

`CDialogImpl` deriva de `CDialogImplBaseT` , que, por sua vez, deriva de `CWindowImplRoot` .

> [!NOTE]
> Sua classe deve definir um `IDD` membro que especifica a ID de recurso do modelo de caixa de diálogo. Por exemplo, o assistente de projeto do ATL adiciona automaticamente a seguinte linha à sua classe:

[!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/cdialogimpl-class_1.h)]

em que `MyDlg` é o **nome curto** inserido na página **nomes** do assistente.

|Para saber mais sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando caixas de diálogo na ATL|[Classes de janela do ATL](../../atl/atl-window-classes.md)|
|Assistente de Projeto da ATL|[Como criar um projeto da ATL](../../atl/reference/creating-an-atl-project.md)|
|Caixas de diálogo|[Caixas de diálogo](/windows/win32/dlgbox/dialog-boxes) e tópicos subsequentes no SDK do Windows|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

## <a name="cdialogimplcreate"></a><a name="create"></a> CDialogImpl:: criar

Cria uma caixa de diálogo sem janela restrita.

```
HWND Create(
    HWND hWndParent,
    LPARAM dwInitParam = NULL );

HWND Create(
    HWND hWndParent,
    RECT&,
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>parâmetros

*hWndParent*<br/>
no O identificador para a janela do proprietário.

**Rect&** *Rect* [in] uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que especifica o tamanho e a posição da caixa de diálogo.

*dwInitParam*<br/>
no Especifica o valor a ser passado para a caixa de diálogo no parâmetro *lParam* da mensagem de WM_INITDIALOG.

### <a name="return-value"></a>Valor Retornado

O identificador para a caixa de diálogo recém-criada.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao `CDialogImpl` objeto. Para criar uma caixa de diálogo modal, chame [DoModal](#domodal). A segunda substituição acima é usada somente com [CComControl](../../atl/reference/ccomcontrol-class.md).

## <a name="cdialogimpldestroywindow"></a><a name="destroywindow"></a> CDialogImpl::D estroyWindow

Destrói uma caixa de diálogo sem janela restrita.

```
BOOL DestroyWindow();
```

### <a name="return-value"></a>Valor Retornado

TRUE se a caixa de diálogo foi destruída com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Retornará TRUE se a caixa de diálogo tiver sido destruída com êxito; caso contrário, FALSE.

## <a name="cdialogimpldialogproc"></a><a name="dialogproc"></a> CDialogImpl::D ialogProc

Essa função estática implementa o procedimento da caixa de diálogo.

```
static LRESULT CALLBACK DialogProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>parâmetros

*hWnd*<br/>
no O identificador para a caixa de diálogo.

*uMsg*<br/>
no A mensagem enviada para a caixa de diálogo.

*wParam*<br/>
no Informações adicionais específicas da mensagem.

*lParam*<br/>
no Informações adicionais específicas da mensagem.

### <a name="return-value"></a>Valor Retornado

TRUE se a mensagem for processada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`DialogProc` usa o mapa de mensagem padrão para direcionar mensagens para os manipuladores apropriados.

Você pode substituir `DialogProc` para fornecer um mecanismo diferente para lidar com mensagens.

## <a name="cdialogimpldomodal"></a><a name="domodal"></a> CDialogImpl::D oModal

Cria uma caixa de diálogo modal.

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

### <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, o valor do parâmetro *nRetCode* especificado na chamada para [EndDialog](#enddialog). Caso contrário, -1.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao `CDialogImpl` objeto.

Para criar uma caixa de diálogo sem janela restrita, chame [Create](#create).

## <a name="cdialogimplenddialog"></a><a name="enddialog"></a> CDialogImpl:: EndDialog

Destrói uma caixa de diálogo modal.

```
BOOL EndDialog(int nRetCode);
```

### <a name="parameters"></a>parâmetros

*nRetCode*<br/>
no O valor a ser retornado por [CDialogImpl::D omodal](#domodal).

### <a name="return-value"></a>Valor Retornado

TRUE se a caixa de diálogo for destruída; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`EndDialog` deve ser chamado por meio do procedimento da caixa de diálogo. Depois que a caixa de diálogo é destruída, o Windows usa o valor de *nRetCode* como o valor de retorno para `DoModal` , que criou a caixa de diálogo.

> [!NOTE]
> Não chame `EndDialog` para destruir uma caixa de diálogo sem janela restrita. Chame [CWindow::D estroywindow](../../atl/reference/cwindow-class.md#destroywindow) em vez disso.

## <a name="cdialogimplgetdialogproc"></a><a name="getdialogproc"></a> CDialogImpl::GetDialogProc

Retorna `DialogProc` o procedimento da caixa de diálogo atual.

```
virtual WNDPROC GetDialogProc();
```

### <a name="return-value"></a>Valor Retornado

O procedimento da caixa de diálogo atual.

### <a name="remarks"></a>Comentários

Substitua esse método para substituir o procedimento da caixa de diálogo pelo seu próprio.

## <a name="cdialogimplmapdialogrect"></a><a name="mapdialogrect"></a> CDialogImpl::MapDialogRect

Converte (mapeia) as unidades da caixa de diálogo do retângulo especificado em unidades de tela (pixels).

```
BOOL MapDialogRect(LPRECT lpRect);
```

### <a name="parameters"></a>parâmetros

*lpRect*<br/>
Aponta para uma `CRect` estrutura Object ou [Rect](/windows/win32/api/windef/ns-windef-rect) que deve receber as coordenadas do cliente da atualização que inclui a região de atualização.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a atualização for concluída com sucesso; 0 se a atualização falhar. Para obter outras informações sobre o erro, chame `GetLastError`.

### <a name="remarks"></a>Comentários

A função substitui as coordenadas na estrutura especificada `RECT` pelas coordenadas convertidas, o que permite que a estrutura seja usada para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa de diálogo.

## <a name="cdialogimplonfinalmessage"></a><a name="onfinalmessage"></a> CDialogImpl::OnFinalMessage

Chamado depois de receber a última mensagem (normalmente `WM_NCDESTROY` ).

```
virtual void OnFinalMessage(HWND hWnd);
```

### <a name="parameters"></a>parâmetros

*hWnd*<br/>
no Um identificador para a janela que está sendo destruída.

### <a name="remarks"></a>Comentários

Observe que, se você quiser excluir automaticamente o objeto na destruição de janela, poderá chamar **delete** . aqui.

## <a name="cdialogimplstartdialogproc"></a><a name="startdialogproc"></a> CDialogImpl::StartDialogProc

Chamado apenas uma vez, quando a primeira mensagem é recebida, para processar as mensagens enviadas para a caixa de diálogo.

```
static LRESULT CALLBACK StartDialogProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>parâmetros

*hWnd*<br/>
no O identificador para a caixa de diálogo.

*uMsg*<br/>
no A mensagem enviada para a caixa de diálogo.

*wParam*<br/>
no Informações adicionais específicas da mensagem.

*lParam*<br/>
no Informações adicionais específicas da mensagem.

### <a name="return-value"></a>Valor Retornado

O procedimento de janela.

### <a name="remarks"></a>Comentários

Após a chamada inicial para `StartDialogProc` , `DialogProc` é definida como um procedimento de caixa de diálogo e outras chamadas vão lá.

## <a name="see-also"></a>Confira também

[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

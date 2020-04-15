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
ms.openlocfilehash: 900a312c97d7b83eac93a372be39a006b3c4344d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327060"
---
# <a name="cdialogimpl-class"></a>Classe CDialogImpl

Esta classe fornece métodos para criar uma caixa de diálogo modal ou modeless.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T,
    class TBase = CWindow>
    class ATL_NO_VTABLE CDialogImpl : public CDialogImplBaseT<TBase>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `CDialogImpl`.

*Tbase*<br/>
A classe base da sua nova classe. A classe base padrão é [CWindow](../../atl/reference/cwindow-class.md).

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Criar](#create)|Cria uma caixa de diálogo modeless.|
|[Destroywindow](#destroywindow)|Destrói uma caixa de diálogo modeless.|
|[Domodal](#domodal)|Cria uma caixa de diálogo modal.|
|[Enddialog](#enddialog)|Destrói uma caixa de diálogo modal.|

### <a name="cdialogimplbaset-methods"></a>Métodos CDialogImplBaseT

|||
|-|-|
|[GetDialogProc](#getdialogproc)|Retorna o procedimento atual da caixa de diálogo.|
|[Mapdialogrect](#mapdialogrect)|Mapeia as unidades da caixa de diálogo do retângulo especificado para unidades de tela (pixels).|
|[OnFinalMessage](#onfinalmessage)|Chamado depois de receber a última mensagem, tipicamente WM_NCDESTROY.|

### <a name="static-functions"></a>Funções estáticas

|||
|-|-|
|[Dialogproc](#dialogproc)|Processa mensagens enviadas para a caixa de diálogo.|
|[StartDialogProc](#startdialogproc)|Chamado quando a primeira mensagem é recebida para processar mensagens enviadas para a caixa de diálogo.|

## <a name="remarks"></a>Comentários

Com `CDialogImpl` você pode criar uma caixa de diálogo modal ou modeless. `CDialogImpl`fornece o procedimento da caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens aos manipuladores apropriados.

O destruidor da classe `~CWindowImplRoot` base garante que a janela se foi antes de destruir o objeto.

`CDialogImpl`deriva de `CDialogImplBaseT`, que por `CWindowImplRoot`sua vez deriva de .

> [!NOTE]
> Sua classe deve `IDD` definir um membro que especifica o ID de recurso do modelo de diálogo. Por exemplo, o Assistente de Projeto ATL adiciona automaticamente a seguinte linha à sua classe:

[!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/cdialogimpl-class_1.h)]

onde `MyDlg` está o **nome curto** inserido na página **Nomes** do assistente.

|Para saber mais sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando caixas de diálogo no ATL|[Classes de janela atl](../../atl/atl-window-classes.md)|
|Assistente de Projeto da ATL|[Como criar um projeto da ATL](../../atl/reference/creating-an-atl-project.md)|
|Caixas de diálogo|[Caixas de diálogo](/windows/win32/dlgbox/dialog-boxes) e tópicos subseqüentes no Windows SDK|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cdialogimplcreate"></a><a name="create"></a>CDialogImpl::Criar

Cria uma caixa de diálogo modeless.

```
HWND Create(
    HWND hWndParent,
    LPARAM dwInitParam = NULL );

HWND Create(
    HWND hWndParent,
    RECT&,
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
[em] A alça da janela do dono.

**RECT&** *rect* [in] Uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) especificando o tamanho e a posição da caixa de diálogo.

*dwInitParam*<br/>
[em] Especifica o valor a ser repassar para a caixa de diálogo no parâmetro *lParam* da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

A alça da caixa de diálogo recém-criada.

### <a name="remarks"></a>Comentários

Esta caixa de diálogo é `CDialogImpl` automaticamente anexada ao objeto. Para criar uma caixa de diálogo modal, ligue para [DoModal](#domodal). A segunda substituição acima é usada apenas com [CComControl](../../atl/reference/ccomcontrol-class.md).

## <a name="cdialogimpldestroywindow"></a><a name="destroywindow"></a>CDialogImpl::DestroyWindow

Destrói uma caixa de diálogo modeless.

```
BOOL DestroyWindow();
```

### <a name="return-value"></a>Valor retornado

VERDADE se a caixa de diálogo foi destruída com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Retorna TRUE se a caixa de diálogo foi destruída com sucesso; caso contrário, FALSO.

## <a name="cdialogimpldialogproc"></a><a name="dialogproc"></a>CDialogImpl::DialogProc

Esta função estática implementa o procedimento da caixa de diálogo.

```
static LRESULT CALLBACK DialogProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] A alça da caixa de diálogo.

*Umsg*<br/>
[em] A mensagem enviada para a caixa de diálogo.

*wParam*<br/>
[em] Informações específicas de mensagem adicionais.

*lParam*<br/>
[em] Informações específicas de mensagem adicionais.

### <a name="return-value"></a>Valor retornado

VERDADE se a mensagem for processada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`DialogProc`usa o mapa de mensagens padrão para direcionar mensagens aos manipuladores apropriados.

Você pode `DialogProc` substituir para fornecer um mecanismo diferente para lidar com mensagens.

## <a name="cdialogimpldomodal"></a><a name="domodal"></a>CDialogImpl::DoModal

Cria uma caixa de diálogo modal.

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

Se for bem-sucedido, o valor do parâmetro *nRetCode* especificado na chamada para [EndDialog](#enddialog). Caso contrário, -1.

### <a name="remarks"></a>Comentários

Esta caixa de diálogo é `CDialogImpl` automaticamente anexada ao objeto.

Para criar uma caixa de diálogo modeless, chame [Criar](#create).

## <a name="cdialogimplenddialog"></a><a name="enddialog"></a>CDialogImpl::EndDialog

Destrói uma caixa de diálogo modal.

```
BOOL EndDialog(int nRetCode);
```

### <a name="parameters"></a>Parâmetros

*Nretcode*<br/>
[em] O valor a ser devolvido por [CDialogImpl::DoModal](#domodal).

### <a name="return-value"></a>Valor retornado

VERDADE se a caixa de diálogo for destruída; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`EndDialog`deve ser chamado através do procedimento de diálogo. Depois que a caixa de diálogo é destruída, o Windows usa `DoModal`o valor do *nRetCode* como o valor de retorno para , que criou a caixa de diálogo.

> [!NOTE]
> Não ligue `EndDialog` para destruir uma caixa de diálogo modeladora. Ligue para [CWindow::DestroyWindow.](../../atl/reference/cwindow-class.md#destroywindow)

## <a name="cdialogimplgetdialogproc"></a><a name="getdialogproc"></a>CDialogImpl::GetDialogProc

Retorna `DialogProc`, o procedimento atual da caixa de diálogo.

```
virtual WNDPROC GetDialogProc();
```

### <a name="return-value"></a>Valor retornado

O procedimento atual da caixa de diálogo.

### <a name="remarks"></a>Comentários

Substitua este método para substituir o procedimento de diálogo pelo seu.

## <a name="cdialogimplmapdialogrect"></a><a name="mapdialogrect"></a>CDialogImpl::MapDialogRect

Converte (mapas) as unidades da caixa de diálogo do retângulo especificado para unidades de tela (pixels).

```
BOOL MapDialogRect(LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `CRect` um objeto ou estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que deve receber as coordenadas do cliente da atualização que inclui a região de atualização.

### <a name="return-value"></a>Valor retornado

Não zero se a atualização for bem sucedida; 0 se a atualização falhar. Para obter outras informações sobre o erro, chame `GetLastError`.

### <a name="remarks"></a>Comentários

A função substitui as coordenadas `RECT` na estrutura especificada pelas coordenadas convertidas, o que permite que a estrutura seja usada para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa de diálogo.

## <a name="cdialogimplonfinalmessage"></a><a name="onfinalmessage"></a>CDialogImpl::OnFinalMessage

Chamado após receber a última `WM_NCDESTROY`mensagem (tipicamente ).

```
virtual void OnFinalMessage(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] Uma alça da janela sendo destruída.

### <a name="remarks"></a>Comentários

Observe que se você quiser excluir automaticamente seu objeto após a destruição da janela, você pode chamar **de excluir isso;** aqui.

## <a name="cdialogimplstartdialogproc"></a><a name="startdialogproc"></a>CDialogImpl::StartDialogProc

Chamado apenas uma vez, quando a primeira mensagem é recebida, para processar mensagens enviadas para a caixa de diálogo.

```
static LRESULT CALLBACK StartDialogProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] A alça da caixa de diálogo.

*Umsg*<br/>
[em] A mensagem enviada para a caixa de diálogo.

*wParam*<br/>
[em] Informações específicas de mensagem adicionais.

*lParam*<br/>
[em] Informações específicas de mensagem adicionais.

### <a name="return-value"></a>Valor retornado

O procedimento da janela.

### <a name="remarks"></a>Comentários

Após a chamada `StartDialogProc` `DialogProc` inicial para , é definido como um procedimento de diálogo, e novas chamadas vão para lá.

## <a name="see-also"></a>Confira também

[Begin_msg_map](message-map-macros-atl.md#begin_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

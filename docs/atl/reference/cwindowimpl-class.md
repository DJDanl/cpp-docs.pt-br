---
title: Classe CWindowImpl
ms.date: 11/04/2016
f1_keywords:
- CWindowImpl
- ATLWIN/ATL::CWindowImpl
- ATLWIN/ATL::CWindowImpl::Create
- ATLWIN/ATL::CWindowImpl::DefWindowProc
- ATLWIN/ATL::CWindowImpl::GetCurrentMessage
- ATLWIN/ATL::CWindowImpl::GetWindowProc
- ATLWIN/ATL::CWindowImpl::OnFinalMessage
- ATLWIN/ATL::CWindowImpl::SubclassWindow
- ATLWIN/ATL::CWindowImpl::UnsubclassWindow
- ATLWIN/ATL::CWindowImpl::GetWndClassInfo
- ATLWIN/ATL::CWindowImpl::WindowProc
- ATLWIN/ATL::CWindowImpl::m_pfnSuperWindowProc
helpviewer_keywords:
- CWindowImpl class
- subclassing windows, ATL
ms.assetid: 02eefd45-a0a6-4d1b-99f6-dbf627e2cc2f
ms.openlocfilehash: d7f7f7363eb123181bd6e0389663810346094cba
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330291"
---
# <a name="cwindowimpl-class"></a>Classe CWindowImpl

Fornece métodos para criar ou subclassificar uma janela.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TBase = CWindow, class TWinTraits = CControlWinTraits>
class ATL_NO_VTABLE CWindowImpl : public CWindowImplBaseT<TBase, TWinTraits>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua nova classe, `CWindowImpl`derivada de .

*Tbase*<br/>
A classe base da sua classe. Por padrão, a classe base é [CWindow](../../atl/reference/cwindow-class.md).

*Twintraits*<br/>
Uma [classe de traços](../../atl/understanding-window-traits.md) que define estilos para sua janela. O padrão é `CControlWinTraits`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWindowImpl::Criar](#create)|Cria uma janela.|

### <a name="cwindowimplbaset-methods"></a>Métodos CWindowImplBaset

|||
|-|-|
|[Defwindowproc](#defwindowproc)|Fornece processamento de mensagens padrão.|
|[GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|
|[GetWindowProc](#getwindowproc)|Retorna o procedimento atual da janela.|
|[OnFinalMessage](#onfinalmessage)|Chamado após a última mensagem ser recebida (tipicamente WM_NCDESTROY).|
|[Subclasswindow](#subclasswindow)|Subclasses de uma janela.|
|[Janela de subclasse](#unsubclasswindow)|Restaura uma janela subclassificada anteriormente.|

### <a name="static-methods"></a>Métodos estáticos

|||
|-|-|
|[Getwndclassinfo](#getwndclassinfo)|Retorna uma instância estática do [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md), que gerencia as informações da classe de janela.|
|[Windowproc](#windowproc)|Processa mensagens enviadas para a janela.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[M_pfnsuperwindowproc](#m_pfnsuperwindowproc)|Aponta para o procedimento original da janela da classe janela.|

## <a name="remarks"></a>Comentários

Você pode `CWindowImpl` usar para criar uma janela ou subclasse uma janela existente. o `CWindowImpl` procedimento da janela usa um mapa de mensagem para direcionar mensagens aos manipuladores apropriados.

`CWindowImpl::Create`cria uma janela com base nas informações da classe de janela gerenciadas pelo [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md). `CWindowImpl`contém a [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro, o que significa `CWndClassInfo` registrar uma nova classe de janela. Se você quiser superclassificar uma classe de janela `CWindowImpl` existente, obtenha sua classe e inclua a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro. Neste caso, `CWndClassInfo` registra uma classe de janela que é baseada `CWindowImpl::WindowProc`em uma classe existente, mas usa . Por exemplo:

[!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwindowimpl-class_1.h)]

> [!NOTE]
> Como `CWndClassInfo` gerencia as informações para apenas uma classe de janela, cada janela criada através de uma instância de é baseada na mesma classe de `CWindowImpl` janela.

`CWindowImpl`também suporta subclasse de janela. O `SubclassWindow` método anexa uma janela `CWindowImpl` existente ao objeto e `CWindowImpl::WindowProc`altera o procedimento da janela para . Cada instância `CWindowImpl` de pode subclasse uma janela diferente.

> [!NOTE]
> Para qualquer `CWindowImpl` objeto, `Create` ligue `SubclassWindow`para qualquer um ou . Não invoque ambos os métodos no mesmo objeto.

Além disso, o `CWindowImpl`ATL fornece [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) para criar uma janela contida em outro objeto.

O destruidor da classe base `CWindowImplRoot`(~ ) garante que a janela se foi antes que o objeto seja destruído.

`CWindowImpl`deriva de `CWindowImplBaseT`, que `CWindowImplRoot`deriva de , `TBase` que deriva de e [CMessageMap](../../atl/reference/cmessagemap-class.md).

|Para saber mais sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando janelas no ATL|[Classes de janela atl](../../atl/atl-window-classes.md)|
|Assistente de Projeto da ATL|[Como criar um projeto da ATL](../../atl/reference/creating-an-atl-project.md)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmessagemap](../../atl/reference/cmessagemap-class.md)

`TBase`

`CWindowImplRoot`

`CWindowImplBaseT`

`CWindowImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cwindowimplcreate"></a><a name="create"></a>CWindowImpl::Criar

Cria uma janela baseada em uma nova classe de janela.

```
HWND Create(
    HWND hWndParent,
    _U_RECT rect = NULL,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
[em] A alça da janela dos pais ou dodo.

*Rect*<br/>
[em] Uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) especificando a posição da janela. O `RECT` pode ser passado por ponteiro ou por referência.

*szWindowName*<br/>
[em] Especifica o nome da janela. O valor padrão é NULL.

*Dwstyle*<br/>
[em] O estilo da janela. Este valor é combinado com o estilo fornecido pela classe de traços para a janela. O valor padrão dá às classes de características controle total sobre o estilo. Para obter uma lista de valores possíveis, consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows.

*Dwexstyle*<br/>
[em] O estilo de janela estendida. Este valor é combinado com o estilo fornecido pela classe de traços para a janela. O valor padrão dá às classes de características controle total sobre o estilo. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Menuorid*<br/>
[em] Para uma janela infantil, o identificador da janela. Para uma janela de nível superior, uma alça de menu para a janela. O valor padrão é **0U**.

*lpCreateParam*<br/>
[em] Um ponteiro para dados de criação de janelas. Para obter uma descrição completa, consulte a descrição do parâmetro final para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw).

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, a alça para a janela recém-criada. Caso contrário, NULL.

### <a name="remarks"></a>Comentários

`Create`primeiro registra a classe da janela se ela ainda não foi registrada. A janela recém-criada é automaticamente `CWindowImpl` anexada ao objeto.

> [!NOTE]
> Não ligue `Create` se você já chamou [SubclassWindow](#subclasswindow).

Para usar uma classe de janela baseada em uma classe `CWindowImpl` de janela existente, obtenha sua classe e inclua a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro. O procedimento de janela da classe de janela existente é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc). Para obter mais informações, consulte a visão geral do [CWindowImpl.](../../atl/reference/cwindowimpl-class.md)

> [!NOTE]
> Se 0 for usado como o valor para o parâmetro *MenuOrID,* ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.

## <a name="cwindowimpldefwindowproc"></a><a name="defwindowproc"></a>CWindowImpl::DefWindowProc

Chamado pelo [WindowProc](#windowproc) para processar mensagens não tratadas pelo mapa de mensagens.

```
LRESULT DefWindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);

LRESULT DefWindowProc();
```

### <a name="parameters"></a>Parâmetros

*Umsg*<br/>
[em] A mensagem enviada para a janela.

*wParam*<br/>
[em] Informações específicas de mensagem adicionais.

*lParam*<br/>
[em] Informações específicas de mensagem adicionais.

### <a name="return-value"></a>Valor retornado

O resultado do processamento de mensagens.

### <a name="remarks"></a>Comentários

Por padrão, `DefWindowProc` chama a função [CallWindowProc](/windows/win32/api/winuser/nf-winuser-callwindowprocw) Win32 para enviar as informações da mensagem para o procedimento de janela especificado no [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

A função sem parâmetros recupera automaticamente os parâmetros necessários da mensagem atual.

## <a name="cwindowimplgetcurrentmessage"></a><a name="getcurrentmessage"></a>CWindowImpl::GetCurrentMessage

Retorna a mensagem atual, `MSG` embalada na estrutura.

```
const MSG* GetCurrentMessage();
```

### <a name="return-value"></a>Valor retornado

A mensagem atual.

## <a name="cwindowimplgetwindowproc"></a><a name="getwindowproc"></a>CWindowImpl::GetWindowProc

Retorna `WindowProc`, o procedimento da janela atual.

```
virtual WNDPROC GetWindowProc();
```

### <a name="return-value"></a>Valor retornado

O procedimento atual da janela.

### <a name="remarks"></a>Comentários

Substitua este método para substituir o procedimento da janela pelo seu próprio.

## <a name="cwindowimplgetwndclassinfo"></a><a name="getwndclassinfo"></a>CWindowImpl::GetWndClassInfo

Chamado por [Criar](#create) para acessar as informações da classe de janela.

```
static CWndClassInfo& GetWndClassInfo();
```

### <a name="return-value"></a>Valor retornado

Uma instância estática de [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md).

### <a name="remarks"></a>Comentários

Por padrão, `CWindowImpl` obtém esse método através da [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro, que especifica uma nova classe de janela.

Para superclasse uma classe de janela `CWindowImpl` existente, obtenha sua classe `GetWndClassInfo`e inclua a [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro para substituir . Para obter mais informações, consulte a visão geral do [CWindowImpl.](../../atl/reference/cwindowimpl-class.md)

Além de usar as macros DECLARE_WND_CLASS `GetWndClassInfo` e DECLARE_WND_SUPERCLASS, você pode substituir com sua própria implementação.

## <a name="cwindowimplm_pfnsuperwindowproc"></a><a name="m_pfnsuperwindowproc"></a>CWindowImpl::m_pfnSuperWindowProc

Dependendo da janela, aponta para um dos seguintes procedimentos de janela.

```
WNDPROC m_pfnSuperWindowProc;
```

### <a name="remarks"></a>Comentários

|Tipo de janela|Procedimento de janela|
|--------------------|----------------------|
|Uma janela baseada em uma nova classe de janela, especificada através da [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro.|A função [DefWindowProc](/windows/win32/api/winuser/nf-winuser-defwindowprocw) Win32.|
|Uma janela baseada em uma classe de janela que modifica uma classe existente, especificada através da [macro DECLARE_WND_SUPERCLASS.](window-class-macros.md#declare_wnd_superclass)|O procedimento de janela da classe de janela existente.|
|Uma janela subclassificada.|O procedimento original da janela da janela subclassificada.|

[CWindowImpl::DefWindowProc](#defwindowproc) envia informações de mensagem `m_pfnSuperWindowProc`para o procedimento de janela salvo em .

## <a name="cwindowimplonfinalmessage"></a><a name="onfinalmessage"></a>CWindowImpl::OnFinalMessage

Chamado após receber a última mensagem (tipicamente WM_NCDESTROY).

```
virtual void OnFinalMessage(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] Uma alça da janela sendo destruída.

### <a name="remarks"></a>Comentários

A implementação `OnFinalMessage` padrão de não faz nada, mas você pode substituir esta função para lidar com a limpeza antes de destruir uma janela. Se você quiser excluir automaticamente seu objeto após a destruição da janela, você pode chamar **de excluir isso;** nesta função.

## <a name="cwindowimplsubclasswindow"></a><a name="subclasswindow"></a>CWindowImpl::SubclassWindow

Subclasses da janela identificada por *hWnd* `CWindowImpl` e anexa-a ao objeto.

```
BOOL SubclassWindow(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] A alça da janela sendo subclassificada.

### <a name="return-value"></a>Valor retornado

TRUE se a janela for subclassificada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A janela subclassificada agora usa [CWindowImpl::WindowProc](#windowproc). O procedimento original da janela é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

> [!NOTE]
> Não ligue `SubclassWindow` se você já chamou [Criar](#create).

## <a name="cwindowimplunsubclasswindow"></a><a name="unsubclasswindow"></a>CWindowImpl::UnsubclassWindow

Destaca a janela subclassificada do `CWindowImpl` objeto e restaura o procedimento original da janela, salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

```
HWND UnsubclassWindow();
```

### <a name="return-value"></a>Valor retornado

A alça da janela anteriormente subclassificada.

## <a name="cwindowimplwindowproc"></a><a name="windowproc"></a>CWindowImpl::WindowProc

Esta função estática implementa o procedimento da janela.

```
static LRESULT CALLBACK WindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] A alça da janela.

*Umsg*<br/>
[em] A mensagem enviada para a janela.

*wParam*<br/>
[em] Informações específicas de mensagem adicionais.

*lParam*<br/>
[em] Informações específicas de mensagem adicionais.

### <a name="return-value"></a>Valor retornado

O resultado do processamento de mensagens.

### <a name="remarks"></a>Comentários

`WindowProc`usa o mapa de mensagem padrão (declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)) para direcionar mensagens aos manipuladores apropriados. Se necessário, `WindowProc` chama [DefWindowProc](#defwindowproc) para processamento adicional de mensagens. Se a mensagem final `WindowProc` não for tratada, faça o seguinte:

- Executa unsubclassing se a janela foi subclassificada.

- Limpa o `m_hWnd`.

- Chama [OnFinalMessage](#onfinalmessage) antes que a janela seja destruída.

Você pode `WindowProc` substituir para fornecer um mecanismo diferente para lidar com mensagens.

## <a name="see-also"></a>Confira também

[Begin_msg_map](message-map-macros-atl.md#begin_msg_map)<br/>
[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

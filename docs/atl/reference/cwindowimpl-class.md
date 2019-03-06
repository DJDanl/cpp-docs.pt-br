---
title: Classe CWindowImpl
ms.date: 11/04/2016
f1_keywords:
- CWindowImpl
- ATLWIN/ATL::CWindowImpl
- ATLWIN/ATL::CWindowImpl::Create
- ATLWIN/ATL::DefWindowProc
- ATLWIN/ATL::GetCurrentMessage
- ATLWIN/ATL::GetWindowProc
- ATLWIN/ATL::OnFinalMessage
- ATLWIN/ATL::SubclassWindow
- ATLWIN/ATL::UnsubclassWindow
- ATLWIN/ATL::GetWndClassInfo
- ATLWIN/ATL::WindowProc
- ATLWIN/ATL::m_pfnSuperWindowProc
helpviewer_keywords:
- CWindowImpl class
- subclassing windows, ATL
ms.assetid: 02eefd45-a0a6-4d1b-99f6-dbf627e2cc2f
ms.openlocfilehash: 96807debc7a3af5eca5d7a0c17a7728431733325
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417925"
---
# <a name="cwindowimpl-class"></a>Classe CWindowImpl

Fornece métodos para criar ou uma janela de subclasses.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TBase = CWindow, class TWinTraits = CControlWinTraits>
class ATL_NO_VTABLE CWindowImpl : public CWindowImplBaseT<TBase, TWinTraits>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua nova classe, derivada de `CWindowImpl`.

*TBase*<br/>
A classe base da sua classe. Por padrão, é a classe base [CWindow](../../atl/reference/cwindow-class.md).

*TWinTraits*<br/>
Um [classe de características](../../atl/understanding-window-traits.md) que define estilos para a sua janela. O padrão é `CControlWinTraits`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWindowImpl::Create](#create)|Cria uma janela.|

### <a name="cwindowimplbaset-methods"></a>Métodos de CWindowImplBaseT

|||
|-|-|
|[DefWindowProc](#defwindowproc)|Fornece processamento de mensagem padrão.|
|[GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|
|[GetWindowProc](#getwindowproc)|Retorna o procedimento da janela atual.|
|[OnFinalMessage](#onfinalmessage)|Chamado depois que a última mensagem é recebida (normalmente WM_NCDESTROY).|
|[SubclassWindow](#subclasswindow)|Subclasses uma janela.|
|[UnsubclassWindow](#unsubclasswindow)|Restaura uma janela de subclasse anteriormente.|

### <a name="static-methods"></a>Métodos estáticos

|||
|-|-|
|[GetWndClassInfo](#getwndclassinfo)|Retorna uma instância estática da [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md), que gerencia as informações de classe de janela.|
|[WindowProc](#windowproc)|Processa as mensagens enviadas à janela.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento de janela original da classe de janela.|

## <a name="remarks"></a>Comentários

Você pode usar `CWindowImpl` para criar uma janela ou uma subclasse de uma janela existente. o `CWindowImpl` procedimento de janela usa um mapa de mensagem para direcionar mensagens para manipuladores adequados.

`CWindowImpl::Create` cria uma janela com base nas informações de classe de janela que são gerenciadas pelo [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md). `CWindowImpl` contém o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro, o que significa `CWndClassInfo` registra uma nova classe de janela. Se você quiser superclasse uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua as [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro. Nesse caso, `CWndClassInfo` registra uma classe de janela que se baseia em uma classe existente, mas usa `CWindowImpl::WindowProc`. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwindowimpl-class_1.h)]

> [!NOTE]
>  Porque `CWndClassInfo` gerencia as informações de apenas uma classe de janela, cada janela criada por meio de uma instância do `CWindowImpl` baseia-se da mesma classe de janela.

`CWindowImpl` também dá suporte à criação de classes de janela. O `SubclassWindow` método anexa uma janela existente para o `CWindowImpl` do objeto e altera o procedimento de janela para `CWindowImpl::WindowProc`. Cada instância do `CWindowImpl` pode subclasse uma janela diferente.

> [!NOTE]
>  Para qualquer dado `CWindowImpl` de objeto, chame `Create` ou `SubclassWindow`. Não invoque os dois métodos no mesmo objeto.

Além `CWindowImpl`, a ATL fornece [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) para criar uma janela que está contida em outro objeto.

O destruidor de classe base (~ `CWindowImplRoot`) garante que a janela desapareceu antes que o objeto seja destruído.

`CWindowImpl` deriva `CWindowImplBaseT`, que é derivada de `CWindowImplRoot`, que é derivada de `TBase` e [CMessageMap](../../atl/reference/cmessagemap-class.md).

|Para obter mais informações sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando o windows em ATL|[Classes de janela da ATL](../../atl/atl-window-classes.md)|
|ATL Project Wizard|[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMessageMap](../../atl/reference/cmessagemap-class.md)

`TBase`

`CWindowImplRoot`

`CWindowImplBaseT`

`CWindowImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="create"></a>  CWindowImpl::Create

Cria uma janela com base em uma nova classe de janela.

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

*hWndParent*<br/>
[in] O identificador para a janela pai ou proprietária.

*rect*<br/>
[in] Um [RECT](/previous-versions/dd162897\(v=vs.85\)) especificando a posição da janela de estrutura. O `RECT` pode ser passada por um ponteiro ou referência.

*szWindowName*<br/>
[in] Especifica o nome da janela. O valor padrão é NULL.

*dwStyle*<br/>
[in] O estilo da janela. Esse valor é combinado com o estilo fornecido pela classe de características da janela. O valor padrão fornece as características de controle completo sobre o estilo de classe. Para obter uma lista de valores possíveis, consulte [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) no SDK do Windows.

*dwExStyle*<br/>
[in] O estilo de janela estendidos. Esse valor é combinado com o estilo fornecido pela classe de características da janela. O valor padrão fornece as características de controle completo sobre o estilo de classe. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*MenuOrID*<br/>
[in] Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu da janela. O valor padrão é **0U**.

*lpCreateParam*<br/>
[in] Um ponteiro para dados de criação da janela. Para obter uma descrição completa, consulte a descrição para o parâmetro final [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o identificador para a janela criada recentemente. Caso contrário, nulo.

### <a name="remarks"></a>Comentários

`Create` primeiro, registra a classe de janela se ele ainda não tiver sido registrado. A janela recém-criado é anexada automaticamente ao `CWindowImpl` objeto.

> [!NOTE]
>  Não chame `Create` se você já terá chamado [SubclassWindow](#subclasswindow).

Para usar uma classe de janela que se baseia em uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua as [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro. O procedimento de janela da classe de janela existente é salvo na [m_pfnSuperWindowProc](#m_pfnsuperwindowproc). Para obter mais informações, consulte o [CWindowImpl](../../atl/reference/cwindowimpl-class.md) visão geral.

> [!NOTE]
>  Se 0 for usado como o valor para o *MenuOrID* parâmetro, ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.

##  <a name="defwindowproc"></a>  CWindowImpl::DefWindowProc

Chamado pelo [WindowProc](#windowproc) para processar mensagens não tratadas pelo mapa de mensagens.

```
LRESULT DefWindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);

LRESULT DefWindowProc();
```

### <a name="parameters"></a>Parâmetros

*uMsg*<br/>
[in] A mensagem enviada para a janela.

*wParam*<br/>
[in] Obter informações adicionais específicas de mensagem.

*lParam*<br/>
[in] Obter informações adicionais específicas de mensagem.

### <a name="return-value"></a>Valor de retorno

O resultado do processamento da mensagem.

### <a name="remarks"></a>Comentários

Por padrão, `DefWindowProc` chamadas a [CallWindowProc](/windows/desktop/api/winuser/nf-winuser-callwindowproca) para enviar as informações de mensagem para o procedimento de janela especificado na função do Win32 [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

A função sem nenhum parâmetro recupera os parâmetros necessários automaticamente a mensagem atual.

##  <a name="getcurrentmessage"></a>  CWindowImpl::GetCurrentMessage

Retorna a mensagem atual, empacotada no `MSG` estrutura.

```
const MSG* GetCurrentMessage();
```

### <a name="return-value"></a>Valor de retorno

A mensagem atual.

##  <a name="getwindowproc"></a>  CWindowImpl::GetWindowProc

Retorna `WindowProc`, o procedimento da janela atual.

```
virtual WNDPROC GetWindowProc();
```

### <a name="return-value"></a>Valor de retorno

O procedimento de janela atual.

### <a name="remarks"></a>Comentários

Substitua este método para substituir o procedimento de janela com seus próprios.

##  <a name="getwndclassinfo"></a>  CWindowImpl::GetWndClassInfo

Chamado pelo [criar](#create) para acessar as informações de classe de janela.

```
static CWndClassInfo& GetWndClassInfo();
```

### <a name="return-value"></a>Valor de retorno

Uma instância estática da [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md).

### <a name="remarks"></a>Comentários

Por padrão, `CWindowImpl` obtém esse método por meio de [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro, que especifica uma nova classe de janela.

A superclasse uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua as [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro substituir `GetWndClassInfo`. Para obter mais informações, consulte o [CWindowImpl](../../atl/reference/cwindowimpl-class.md) visão geral.

Além de usar as macros DECLARE_WND_CLASS e DECLARE_WND_SUPERCLASS, você pode substituir `GetWndClassInfo` com sua própria implementação.

##  <a name="m_pfnsuperwindowproc"></a>  CWindowImpl::m_pfnSuperWindowProc

Dependendo da janela, aponta para um dos seguintes procedimentos de janela.

```
WNDPROC m_pfnSuperWindowProc;
```

### <a name="remarks"></a>Comentários

|Tipo de janela|Procedimento de janela|
|--------------------|----------------------|
|Uma janela com base em uma nova classe de janela, especificada por meio de [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro.|O [DefWindowProc](/windows/desktop/api/winuser/nf-winuser-defwindowproca) função do Win32.|
|Uma janela com base em uma classe de janela que modifica uma classe existente, especificada por meio de [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro.|Procedimento de janela da classe de janela existente.|
|Uma janela de subclasse.|A subclasse original procedimento da janela.|

[CWindowImpl::DefWindowProc](#defwindowproc) envia mensagem de informações para o procedimento de janela salvado em `m_pfnSuperWindowProc`.

##  <a name="onfinalmessage"></a>  CWindowImpl::OnFinalMessage

Chamado após o recebimento da última mensagem (normalmente WM_NCDESTROY).

```
virtual void OnFinalMessage(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[in] Um identificador para a janela que está sendo destruído.

### <a name="remarks"></a>Comentários

A implementação padrão de `OnFinalMessage` não faz nada, mas você pode substituir essa função para lidar com a limpeza antes de destruir uma janela. Se você quiser excluir automaticamente seu objeto após a destruição de janela, você pode chamar **excluir este;** nessa função.

##  <a name="subclasswindow"></a>  CWindowImpl::SubclassWindow

Subclasses janela identificada pelo *hWnd* e anexa-o para o `CWindowImpl` objeto.

```
BOOL SubclassWindow(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[in] O identificador para a janela que está sendo uma subclasse.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela com êxito é uma subclasse; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A subclasse janela agora utiliza [CWindowImpl::WindowProc](#windowproc). O procedimento de janela original é salva no [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

> [!NOTE]
>  Não chame `SubclassWindow` se você já terá chamado [criar](#create).

##  <a name="unsubclasswindow"></a>  CWindowImpl::UnsubclassWindow

Desanexa a subclasse na janela de `CWindowImpl` do objeto e restaura o procedimento de janela original, salvos no [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

```
HWND UnsubclassWindow();
```

### <a name="return-value"></a>Valor de retorno

O identificador para a janela anteriormente uma subclasse.

##  <a name="windowproc"></a>  CWindowImpl::WindowProc

A função estática implementa o procedimento de janela.

```
static LRESULT CALLBACK WindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[in] O identificador para a janela.

*uMsg*<br/>
[in] A mensagem enviada para a janela.

*wParam*<br/>
[in] Obter informações adicionais específicas de mensagem.

*lParam*<br/>
[in] Obter informações adicionais específicas de mensagem.

### <a name="return-value"></a>Valor de retorno

O resultado do processamento da mensagem.

### <a name="remarks"></a>Comentários

`WindowProc` usa o mapa de mensagem padrão (declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)) para direcionar mensagens para manipuladores adequados. Se necessário, `WindowProc` chamadas [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais. Se a mensagem final não for tratada, `WindowProc` faz o seguinte:

- Executa unsubclassing se a janela tiver sido unsubclassed.

- Limpa o `m_hWnd`.

- Chamadas [OnFinalMessage](#onfinalmessage) antes que a janela seja destruída.

Você pode substituir `WindowProc` para fornecer um mecanismo diferente para lidar com mensagens.

## <a name="see-also"></a>Consulte também

[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)<br/>
[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

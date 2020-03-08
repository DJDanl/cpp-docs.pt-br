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
ms.openlocfilehash: b8b633dcf4ea14e899ee00552b553476cf697689
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78862952"
---
# <a name="cwindowimpl-class"></a>Classe CWindowImpl

Fornece métodos para criação ou subclasse de uma janela.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TBase = CWindow, class TWinTraits = CControlWinTraits>
class ATL_NO_VTABLE CWindowImpl : public CWindowImplBaseT<TBase, TWinTraits>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua nova classe, derivada de `CWindowImpl`.

*TBase*<br/>
A classe base da sua classe. Por padrão, a classe base é [CWindow](../../atl/reference/cwindow-class.md).

*TWinTraits*<br/>
Uma [classe de características](../../atl/understanding-window-traits.md) que define os estilos para sua janela. O padrão é `CControlWinTraits`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CWindowImpl:: criar](#create)|Cria uma janela.|

### <a name="cwindowimplbaset-methods"></a>Métodos CWindowImplBaseT

|||
|-|-|
|[DefWindowProc](#defwindowproc)|Fornece o processamento de mensagens padrão.|
|[GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|
|[Getwindowproc](#getwindowproc)|Retorna o procedimento da janela atual.|
|[OnFinalMessage](#onfinalmessage)|Chamado depois que a última mensagem é recebida (normalmente WM_NCDESTROY).|
|[SubclassWindow](#subclasswindow)|Subclasses de uma janela.|
|[UnsubclassWindow](#unsubclasswindow)|Restaura uma janela de subclasse anterior.|

### <a name="static-methods"></a>Métodos estáticos

|||
|-|-|
|[GetWndClassInfo](#getwndclassinfo)|Retorna uma instância estática de [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md), que gerencia as informações de classe de janela.|
|[WindowProc](#windowproc)|Processa as mensagens enviadas para a janela.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento de janela original da classe de janela.|

## <a name="remarks"></a>Comentários

Você pode usar `CWindowImpl` para criar uma janela ou uma subclasse de uma janela existente. o procedimento de janela `CWindowImpl` usa um mapa de mensagens para direcionar mensagens para os manipuladores apropriados.

`CWindowImpl::Create` cria uma janela com base nas informações de classe de janela gerenciadas pelo [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md). `CWindowImpl` contém a macro [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) , que significa `CWndClassInfo` registra uma nova classe de janela. Se você quiser superclassear uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) . Nesse caso, `CWndClassInfo` registra uma classe de janela baseada em uma classe existente, mas usa `CWindowImpl::WindowProc`. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwindowimpl-class_1.h)]

> [!NOTE]
>  Como `CWndClassInfo` gerencia as informações de apenas uma classe de janela, cada janela criada por meio de uma instância do `CWindowImpl` é baseada na mesma classe de janela.

`CWindowImpl` também dá suporte à subclasse Window. O método `SubclassWindow` anexa uma janela existente ao objeto `CWindowImpl` e altera o procedimento de janela para `CWindowImpl::WindowProc`. Cada instância do `CWindowImpl` pode subclasse de uma janela diferente.

> [!NOTE]
>  Para qualquer determinado objeto `CWindowImpl`, chame `Create` ou `SubclassWindow`. Não invoque os dois métodos no mesmo objeto.

Além de `CWindowImpl`, a ATL fornece [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) para criar uma janela que está contida em outro objeto.

O destruidor de classe base (~ `CWindowImplRoot`) garante que a janela tenha desaparecido antes que o objeto seja destruído.

`CWindowImpl` deriva de `CWindowImplBaseT`, que deriva de `CWindowImplRoot`, que deriva de `TBase` e [CMessageMap](../../atl/reference/cmessagemap-class.md).

|Para obter mais informações sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando o Windows na ATL|[Classes de janela da ATL](../../atl/atl-window-classes.md)|
|Assistente de Projeto da ATL|[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMessageMap](../../atl/reference/cmessagemap-class.md)

`TBase`

`CWindowImplRoot`

`CWindowImplBaseT`

`CWindowImpl`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlwin. h

##  <a name="create"></a>CWindowImpl:: criar

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
no O identificador para a janela pai ou proprietário.

*Rect*<br/>
no Uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que especifica a posição da janela. O `RECT` pode ser passado por ponteiro ou por referência.

*szWindowName*<br/>
no Especifica o nome da janela. O valor padrão é NULL.

*dwStyle*<br/>
no O estilo da janela. Esse valor é combinado com o estilo fornecido pela classe de características para a janela. O valor padrão fornece à classe de características controle total sobre o estilo. Para obter uma lista de valores possíveis, consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows.

*dwExStyle*<br/>
no O estilo de janela estendida. Esse valor é combinado com o estilo fornecido pela classe de características para a janela. O valor padrão fornece à classe de características controle total sobre o estilo. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*MenuOrID*<br/>
no Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu para a janela. O valor padrão é **0u**.

*lpCreateParam*<br/>
no Um ponteiro para dados de criação de janela. Para obter uma descrição completa, consulte a descrição do parâmetro final para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw).

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o identificador para a janela recém-criada. Caso contrário, NULL.

### <a name="remarks"></a>Comentários

`Create` primeiro registrará a classe de janela se ela ainda não tiver sido registrada. A janela recém-criada é anexada automaticamente ao objeto `CWindowImpl`.

> [!NOTE]
>  Não chame `Create` se você já tiver chamado [SubclassWindow](#subclasswindow).

Para usar uma classe de janela baseada em uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) . O procedimento de janela da classe de janela existente é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc). Para obter mais informações, consulte a visão geral do [CWindowImpl](../../atl/reference/cwindowimpl-class.md) .

> [!NOTE]
>  Se 0 for usado como o valor para o parâmetro *MenuOrID* , ele deverá ser especificado como 0u (o valor padrão) para evitar um erro do compilador.

##  <a name="defwindowproc"></a>CWindowImpl::D efWindowProc

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
no A mensagem enviada para a janela.

*wParam*<br/>
no Informações adicionais específicas da mensagem.

*lParam*<br/>
no Informações adicionais específicas da mensagem.

### <a name="return-value"></a>Valor retornado

O resultado do processamento da mensagem.

### <a name="remarks"></a>Comentários

Por padrão, `DefWindowProc` chama a função Win32 [CallWindowProc](/windows/win32/api/winuser/nf-winuser-callwindowprocw) para enviar as informações da mensagem para o procedimento de janela especificado em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

A função sem parâmetros recupera automaticamente os parâmetros necessários da mensagem atual.

##  <a name="getcurrentmessage"></a>CWindowImpl:: GetCurrentMessage

Retorna a mensagem atual, empacotada na estrutura de `MSG`.

```
const MSG* GetCurrentMessage();
```

### <a name="return-value"></a>Valor retornado

A mensagem atual.

##  <a name="getwindowproc"></a>CWindowImpl:: getwindowproc

Retorna `WindowProc`, o procedimento de janela atual.

```
virtual WNDPROC GetWindowProc();
```

### <a name="return-value"></a>Valor retornado

O procedimento da janela atual.

### <a name="remarks"></a>Comentários

Substitua esse método para substituir o procedimento de janela pelo seu próprio.

##  <a name="getwndclassinfo"></a>CWindowImpl:: GetWndClassInfo

Chamado por [Create](#create) para acessar as informações de classe de janela.

```
static CWndClassInfo& GetWndClassInfo();
```

### <a name="return-value"></a>Valor retornado

Uma instância estática de [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md).

### <a name="remarks"></a>Comentários

Por padrão, `CWindowImpl` obtém esse método por meio da macro [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) , que especifica uma nova classe de janela.

Para supergravar uma classe de janela existente, derive sua classe de `CWindowImpl` e inclua a macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) para substituir `GetWndClassInfo`. Para obter mais informações, consulte a visão geral do [CWindowImpl](../../atl/reference/cwindowimpl-class.md) .

Além de usar as macros DECLARE_WND_CLASS e DECLARE_WND_SUPERCLASS, você pode substituir `GetWndClassInfo` pela sua própria implementação.

##  <a name="m_pfnsuperwindowproc"></a>CWindowImpl:: m_pfnSuperWindowProc

Dependendo da janela, aponta para um dos seguintes procedimentos de janela.

```
WNDPROC m_pfnSuperWindowProc;
```

### <a name="remarks"></a>Comentários

|Tipo de janela|Procedimento de janela|
|--------------------|----------------------|
|Uma janela baseada em uma nova classe de janela, especificada por meio da macro [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) .|A função Win32 [DefWindowProc](/windows/win32/api/winuser/nf-winuser-defwindowprocw) .|
|Uma janela baseada em uma classe de janela que modifica uma classe existente, especificada por meio da macro [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) .|O procedimento de janela da classe de janela existente.|
|Uma janela de subclasse.|O procedimento da janela original da janela de subclasse.|

[CWindowImpl::D efwindowproc](#defwindowproc) envia informações da mensagem para o procedimento de janela salvo em `m_pfnSuperWindowProc`.

##  <a name="onfinalmessage"></a>CWindowImpl:: OnFinalMessage

Chamado depois de receber a última mensagem (normalmente WM_NCDESTROY).

```
virtual void OnFinalMessage(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
no Um identificador para a janela que está sendo destruída.

### <a name="remarks"></a>Comentários

A implementação padrão de `OnFinalMessage` não faz nada, mas você pode substituir essa função para manipular a limpeza antes de destruir uma janela. Se você quiser excluir automaticamente o objeto na destruição de janela, poderá chamar **delete** . nesta função.

##  <a name="subclasswindow"></a>CWindowImpl:: SubclassWindow

Subclasses a janela identificada por *HWND* e a anexa ao objeto `CWindowImpl`.

```
BOOL SubclassWindow(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
no O identificador para a janela que está sendo subclasse.

### <a name="return-value"></a>Valor retornado

TRUE se a janela for subclasseda com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A janela de subclasse agora usa [CWindowImpl:: WindowProc](#windowproc). O procedimento de janela original é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

> [!NOTE]
>  Não chame `SubclassWindow` se você já tiver chamado [Create](#create).

##  <a name="unsubclasswindow"></a>CWindowImpl:: UnsubclassWindow

Desanexa a janela de subclasse do objeto `CWindowImpl` e restaura o procedimento de janela original, salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

```
HWND UnsubclassWindow();
```

### <a name="return-value"></a>Valor retornado

O identificador para a janela anteriormente subclasse.

##  <a name="windowproc"></a>CWindowImpl:: WindowProc

Essa função estática implementa o procedimento de janela.

```
static LRESULT CALLBACK WindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
no O identificador para a janela.

*uMsg*<br/>
no A mensagem enviada para a janela.

*wParam*<br/>
no Informações adicionais específicas da mensagem.

*lParam*<br/>
no Informações adicionais específicas da mensagem.

### <a name="return-value"></a>Valor retornado

O resultado do processamento da mensagem.

### <a name="remarks"></a>Comentários

`WindowProc` usa o mapa de mensagem padrão (declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)) para direcionar mensagens para os manipuladores apropriados. Se necessário, `WindowProc` chama [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais. Se a mensagem final não for tratada, `WindowProc` fará o seguinte:

- Executa unsubclassing se a janela fosse unsubclassed.

- Limpa o `m_hWnd`.

- Chama [OnFinalMessage](#onfinalmessage) antes de a janela ser destruída.

Você pode substituir `WindowProc` para fornecer um mecanismo diferente para lidar com mensagens.

## <a name="see-also"></a>Consulte também

[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)<br/>
[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

---
title: Classe CcontainedWindowT
ms.date: 11/04/2016
f1_keywords:
- CContainedWindowT
- ATLWIN/ATL::CContainedWindowT
- ATLWIN/ATL::CContainedWindowT::CContainedWindowT
- ATLWIN/ATL::CContainedWindowT::Create
- ATLWIN/ATL::CContainedWindowT::DefWindowProc
- ATLWIN/ATL::CContainedWindowT::GetCurrentMessage
- ATLWIN/ATL::CContainedWindowT::RegisterWndSuperclass
- ATLWIN/ATL::CContainedWindowT::SubclassWindow
- ATLWIN/ATL::CContainedWindowT::SwitchMessageMap
- ATLWIN/ATL::CContainedWindowT::UnsubclassWindow
- ATLWIN/ATL::CContainedWindowT::WindowProc
- ATLWIN/ATL::CContainedWindowT::m_dwMsgMapID
- ATLWIN/ATL::CContainedWindowT::m_lpszClassName
- ATLWIN/ATL::CContainedWindowT::m_pfnSuperWindowProc
- ATLWIN/ATL::CContainedWindowT::m_pObject
helpviewer_keywords:
- CContainedWindow class
- contained windows
- CContainedWindowT class
ms.assetid: cde0ca36-9347-4068-995a-d294dae57ca9
ms.openlocfilehash: cde9c73a195303e57758cb4f27184b5136bdaf14
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327209"
---
# <a name="ccontainedwindowt-class"></a>Classe CcontainedWindowT

Esta classe implementa uma janela contida dentro de outro objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class TBase = CWindow, class TWinTraits = CControlWinTraits>
class CContainedWindowT : public TBase
```

#### <a name="parameters"></a>Parâmetros

*Tbase*<br/>
A classe base da sua nova classe. A classe base `CWindow`padrão é .

*Twintraits*<br/>
Uma classe de traços que define estilos para sua janela. O padrão é `CControlWinTraits`.

> [!NOTE]
> [CContainedWindow](ccontainedwindowt-class.md) é uma `CContainedWindowT`especialização de . Se você quiser alterar a classe `CContainedWindowT` base ou características, use diretamente.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Ccontainedwindowt::CcontainedwindowT](#ccontainedwindowt)|Construtor. Inicializa os membros de dados para especificar qual mapa de mensagem processará as mensagens da janela contida.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CcontainedwindowT::Criar](#create)|Cria uma janela.|
|[CContainedWindowT::DefWindowProc](#defwindowproc)|Fornece processamento de mensagens padrão.|
|[Ccontainedwindowt::getCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|
|[CContainedWindowT::RegisterWndSuperclass](#registerwndsuperclass)|Registra a classe da janela da janela contida.|
|[CContainedWindowT::SubclasseJanela](#subclasswindow)|Subclasses de uma janela.|
|[CcontainedwindowT::SwitchMessageMap](#switchmessagemap)|Altera qual mapa de mensagens é usado para processar as mensagens da janela contida.|
|[CContainedWindowT::''''''''''''''''''''''''''](#unsubclasswindow)|Restaura uma janela subclassificada anteriormente.|
|[CcontainedwindowT::WindowProc](#windowproc)|(Estática) Processa mensagens enviadas para a janela contida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::m_dwMsgMapID](#m_dwmsgmapid)|Identifica qual mapa de mensagem processará as mensagens da janela contida.|
|[Ccontainedwindowt::m_lpszClassName](#m_lpszclassname)|Especifica o nome de uma classe de janela existente na qual uma nova classe de janela será baseada.|
|[CContainedWindowT::m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento original da janela da classe janela.|
|[CContainedWindowT::m_pObject](#m_pobject)|Aponta para o objeto que contém.|

## <a name="remarks"></a>Comentários

`CContainedWindowT`implementa uma janela contida dentro de outro objeto. `CContainedWindowT`O procedimento da janela usa um mapa de mensagem no objeto contendo para direcionar mensagens aos manipuladores apropriados. Ao construir `CContainedWindowT` um objeto, você especifica qual mapa de mensagem deve ser usado.

`CContainedWindowT`permite que você crie uma nova janela superclassificando uma classe de janela existente. O `Create` método registra primeiro uma classe de janela que `CContainedWindowT::WindowProc`é baseada em uma classe existente, mas usa . `Create`em seguida, cria uma janela com base nesta nova classe de janela. Cada instância `CContainedWindowT` de pode superclasse uma classe de janela diferente.

`CContainedWindowT`também suporta subclasse de janela. O `SubclassWindow` método anexa uma janela `CContainedWindowT` existente ao objeto e `CContainedWindowT::WindowProc`altera o procedimento da janela para . Cada instância `CContainedWindowT` de pode subclasse uma janela diferente.

> [!NOTE]
> Para qualquer `CContainedWindowT` objeto, `Create` ligue `SubclassWindow`para qualquer um ou . Você não deve invocar ambos os métodos no mesmo objeto.

Quando você usa o **controle Adicionar com base na** opção no Assistente `CContainedWindowT` de Projeto ATL, o assistente adicionará automaticamente um membro de dados à classe que implementa o controle. O exemplo a seguir mostra como a janela contida é declarada:

[!code-cpp[NVC_ATL_Windowing#38](../../atl/codesnippet/cpp/ccontainedwindowt-class_1.h)]

[!code-cpp[NVC_ATL_Windowing#39](../../atl/codesnippet/cpp/ccontainedwindowt-class_2.h)]

[!code-cpp[NVC_ATL_Windowing#40](../../atl/codesnippet/cpp/ccontainedwindowt-class_3.h)]

|Para saber mais sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando janelas no ATL|[Classes de janela atl](../../atl/atl-window-classes.md)|
|Assistente de Projeto da ATL|[Como criar um projeto da ATL](../../atl/reference/creating-an-atl-project.md)|
|Windows|[Windows](/windows/win32/winmsg/windows) e tópicos subseqüentes no Windows SDK|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`CContainedWindowT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="ccontainedwindowtccontainedwindowt"></a><a name="ccontainedwindowt"></a>Ccontainedwindowt::CcontainedwindowT

O construtor inicializa os membros dos dados.

```
CContainedWindowT(
    LPTSTR lpszClassName,
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0);

CContainedWindowT(
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0)
    CContainedWindowT();
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>
[em] O nome de uma classe de janela existente na qual a janela contida será baseada.

*Pobject*<br/>
[em] Um ponteiro para o objeto que contém que declara o mapa da mensagem. A classe deste objeto deve derivar do [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
[em] Identifica o mapa de mensagens que processará as mensagens da janela contida. O valor padrão, 0, especifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para usar um mapa de mensagem alternativo declarado com [ALT_MSG_MAP(msgMapID),](message-map-macros-atl.md#alt_msg_map)passe `msgMapID`.

### <a name="remarks"></a>Comentários

Se você quiser criar uma nova janela através do [Create,](#create)você deve passar o nome de uma classe de janela existente para o parâmetro *lpszClassName.* Por exemplo, consulte a visão geral do [CContainedWindow.](../../atl/reference/ccontainedwindowt-class.md)

Há três construtores:

- O construtor com três argumentos é o que normalmente é chamado.

- O construtor com dois argumentos usa `TBase::GetWndClassName`o nome da classe de .

- O construtor sem argumentos é usado se você quiser fornecer os argumentos mais tarde. Você deve fornecer o nome da classe da janela, o `Create`objeto do mapa da mensagem e o ID do mapa da mensagem quando você ligar mais tarde .

Se você subclassificar uma janela existente através [do SubclassWindow,](#subclasswindow)o valor *lpszClassName* não será usado; portanto, você pode passar NULL para este parâmetro.

## <a name="ccontainedwindowtcreate"></a><a name="create"></a>CcontainedwindowT::Criar

Chama [RegisterWndSuperclass](#registerwndsuperclass) para registrar uma classe de janela baseada em uma classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc).

```
HWND Create(
    HWND hWndParent,
    _U_RECT rect,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);

HWND Create(
    CMessageMap* pObject,
    DWORD dwMsgMapID,
    HWND hWndParent,
    _U_RECT rect,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);

HWND Create(
    LPCTSTR lpszClassName,
    CMessageMap* pObject,
    DWORD dwMsgMapID,
    HWND hWndParent,
    _U_RECT rect,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>
[em] O nome de uma classe de janela existente na qual a janela contida será baseada.

*Pobject*<br/>
[em] Um ponteiro para o objeto que contém que declara o mapa da mensagem. A classe deste objeto deve derivar do [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
[em] Identifica o mapa de mensagens que processará as mensagens da janela contida. O valor padrão, 0, especifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para usar um mapa de mensagem alternativo declarado com [ALT_MSG_MAP(msgMapID),](message-map-macros-atl.md#alt_msg_map)passe `msgMapID`.

*Hwndparent*<br/>
[em] A alça da janela dos pais ou dodo.

*Rect*<br/>
[em] Uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) especificando a posição da janela. O `RECT` pode ser passado por ponteiro ou por referência.

*szWindowName*<br/>
[em] Especifica o nome da janela. O valor padrão é NULL.

*Dwstyle*<br/>
[em] O estilo da janela. O valor padrão é WS_CHILD WS_VISIBLE &#124;. Para obter uma lista de valores possíveis, consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows.

*Dwexstyle*<br/>
[em] O estilo de janela estendida. O valor padrão é 0, ou seja, nenhum estilo estendido. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Menuorid*<br/>
[em] Para uma janela infantil, o identificador da janela. Para uma janela de nível superior, uma alça de menu para a janela. O valor padrão é **0U**.

*lpCreateParam*<br/>
[em] Um ponteiro para dados de criação de janelas. Para obter uma descrição completa, consulte a descrição do parâmetro final para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw).

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, a alça para a janela recém-criada; caso contrário, NULL.

### <a name="remarks"></a>Comentários

O nome da classe da janela existente é salvo em [m_lpszClassName](#m_lpszclassname). `Create`em seguida, cria uma janela baseada nesta nova classe. A janela recém-criada é automaticamente `CContainedWindowT` anexada ao objeto.

> [!NOTE]
> Não ligue `Create` se você já chamou [SubclassWindow](#subclasswindow).

> [!NOTE]
> Se 0 for usado como o valor para o parâmetro *MenuOrID,* ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.

## <a name="ccontainedwindowtdefwindowproc"></a><a name="defwindowproc"></a>CContainedWindowT::DefWindowProc

Chamado pelo [WindowProc](#windowproc) para processar mensagens não tratadas pelo mapa de mensagens.

```
LRESULT DefWindowProc()
LRESULT DefWindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
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

## <a name="ccontainedwindowtgetcurrentmessage"></a><a name="getcurrentmessage"></a>Ccontainedwindowt::getCurrentMessage

Retorna a mensagem atual ().`m_pCurrentMsg`

```
const _ATL_MSG* GetCurrentMessage();
```

### <a name="return-value"></a>Valor retornado

A mensagem atual, `MSG` embalada na estrutura.

## <a name="ccontainedwindowtm_dwmsgmapid"></a><a name="m_dwmsgmapid"></a>CContainedWindowT::m_dwMsgMapID

Contém o identificador do mapa de mensagens atualmente sendo usado para a janela contida.

```
DWORD m_dwMsgMapID;
```

### <a name="remarks"></a>Comentários

Este mapa de mensagem deve ser declarado no objeto contendo.

O mapa de mensagem padrão, declarado com [BEGIN_MSG_MAP,](message-map-macros-atl.md#begin_msg_map)é sempre identificado por zero. Um mapa de mensagem alternativo, declarado com [ALT_MSG_MAP(msgMapID),](message-map-macros-atl.md#alt_msg_map)é identificado por `msgMapID`.

`m_dwMsgMapID`é inicializado pela primeira vez pelo construtor e pode ser alterado ligando para [SwitchMessageMap](#switchmessagemap). Por exemplo, consulte a [visão geral do CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md).

## <a name="ccontainedwindowtm_lpszclassname"></a><a name="m_lpszclassname"></a>Ccontainedwindowt::m_lpszClassName

Especifica o nome de uma classe de janela existente.

```
LPTSTR m_lpszClassName;
```

### <a name="remarks"></a>Comentários

Quando você cria uma janela, [criar](#create) registra uma nova classe de janela baseada nesta classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc).

`m_lpszClassName`é inicializado pelo construtor. Por exemplo, consulte a visão geral do [CContainedWindowT.](../../atl/reference/ccontainedwindowt-class.md)

## <a name="ccontainedwindowtm_pfnsuperwindowproc"></a><a name="m_pfnsuperwindowproc"></a>CContainedWindowT::m_pfnSuperWindowProc

Se a janela contida for `m_pfnSuperWindowProc` subclassificada, aponte para o procedimento de janela original da classe da janela.

```
WNDPROC m_pfnSuperWindowProc;
```

### <a name="remarks"></a>Comentários

Se a janela contida for superclassificada, o que significa que é baseada `m_pfnSuperWindowProc` em uma classe de janela que modifica uma classe existente, aponte para o procedimento de janela da classe de janela existente.

O método [DefWindowProc](#defwindowproc) envia informações de `m_pfnSuperWindowProc`mensagem para o procedimento de janela salvo em .

## <a name="ccontainedwindowtm_pobject"></a><a name="m_pobject"></a>CContainedWindowT::m_pObject

Aponta para o objeto `CContainedWindowT` que contém o objeto.

```
CMessageMap* m_pObject;
```

### <a name="remarks"></a>Comentários

Este contêiner, cuja classe deve derivar do [CMessageMap,](../../atl/reference/cmessagemap-class.md)declara o mapa de mensagem usado pela janela contida.

`m_pObject`é inicializado pelo construtor. Por exemplo, consulte a visão geral do [CContainedWindowT.](../../atl/reference/ccontainedwindowt-class.md)

## <a name="ccontainedwindowtregisterwndsuperclass"></a><a name="registerwndsuperclass"></a>CContainedWindowT::RegisterWndSuperclass

Chamado por [Criar](#create) para registrar a classe da janela da janela contida.

```
ATOM RegisterWndSuperClass();
```

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, um átomo que identifica exclusivamente a classe de janela sendo registrada; caso contrário, zero.

### <a name="remarks"></a>Comentários

Esta classe de janela é baseada em uma classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc). O nome e o procedimento de janela da classe de janela existente são salvos em [m_lpszClassName](#m_lpszclassname) e [m_pfnSuperWindowProc,](#m_pfnsuperwindowproc)respectivamente.

## <a name="ccontainedwindowtsubclasswindow"></a><a name="subclasswindow"></a>CContainedWindowT::SubclasseJanela

Subclasses da janela identificada por *hWnd* `CContainedWindowT` e anexa-a ao objeto.

```
BOOL SubclassWindow(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[em] A alça da janela sendo subclassificada.

### <a name="return-value"></a>Valor retornado

TRUE se a janela for subclassificada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A janela subclassificada agora usa [CContainedWindowT::WindowProc](#windowproc). O procedimento original da janela é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

> [!NOTE]
> Não ligue `SubclassWindow` se você já chamou [Criar](#create).

## <a name="ccontainedwindowtswitchmessagemap"></a><a name="switchmessagemap"></a>CcontainedwindowT::SwitchMessageMap

Altera qual mapa de mensagens será usado para processar as mensagens da janela contida.

```
void SwitchMessageMap(DWORD dwMsgMapID);
```

### <a name="parameters"></a>Parâmetros

*dwMsgMapID*<br/>
[em] O identificador do mapa da mensagem. Para usar o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP,](message-map-macros-atl.md#begin_msg_map)passe zero. Para usar um mapa de mensagem alternativo declarado com [ALT_MSG_MAP(msgMapID),](message-map-macros-atl.md#alt_msg_map)passe `msgMapID`.

### <a name="remarks"></a>Comentários

O mapa da mensagem deve ser definido no objeto contendo.

Inicialmente, você especifica o identificador do mapa de mensagem no construtor.

## <a name="ccontainedwindowtunsubclasswindow"></a><a name="unsubclasswindow"></a>CContainedWindowT::''''''''''''''''''''''''''

Destaca a janela subclassificada do `CContainedWindowT` objeto e restaura o procedimento original da janela, salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

```
HWND UnsubclassWindow(BOOL bForce = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bForce*<br/>
[em] Definido como TRUE para forçar o procedimento original da janela `CContainedWindowT` a ser restaurado mesmo se o procedimento de janela para este objeto não estiver ativo no momento. Se *bForce* estiver definido como FALSE `CContainedWindowT` e o procedimento de janela para este objeto não estiver ativo no momento, o procedimento original da janela não será restaurado.

### <a name="return-value"></a>Valor retornado

A alça da janela anteriormente subclassificada. Se *bForce* estiver definido como FALSE `CContainedWindowT` e o procedimento de janela para este objeto não estiver ativo no momento, retornaNULL.

### <a name="remarks"></a>Comentários

Use este método somente se quiser restaurar o procedimento original da janela antes que a janela seja destruída. Caso contrário, [o WindowProc](#windowproc) fará isso automaticamente quando a janela for destruída.

## <a name="ccontainedwindowtwindowproc"></a><a name="windowproc"></a>CcontainedwindowT::WindowProc

Este método estático implementa o procedimento da janela.

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

`WindowProc`direciona mensagens para o mapa de mensagens identificados por [m_dwMsgMapID](#m_dwmsgmapid). Se necessário, `WindowProc` chama [DefWindowProc](#defwindowproc) para processamento adicional de mensagens.

## <a name="see-also"></a>Confira também

[Classe CWindow](../../atl/reference/cwindow-class.md)<br/>
[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Classe CMessageMap](../../atl/reference/cmessagemap-class.md)<br/>
[Begin_msg_map](message-map-macros-atl.md#begin_msg_map)<br/>
[ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

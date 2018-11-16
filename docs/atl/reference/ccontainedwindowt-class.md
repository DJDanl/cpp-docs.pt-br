---
title: Classe CContainedWindowT
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
ms.openlocfilehash: 96e279e8ab3080c0239f1e41895142ba23c5a7c9
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693967"
---
# <a name="ccontainedwindowt-class"></a>Classe CContainedWindowT

Essa classe implementa uma janela contida dentro de outro objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class TBase = CWindow, class TWinTraits = CControlWinTraits>
class CContainedWindowT : public TBase
```

#### <a name="parameters"></a>Parâmetros

*Tdígitos de base*<br/>
A classe base da sua nova classe. A classe base padrão é `CWindow`.

*TWinTraits*<br/>
Uma classe de características que define os estilos para a sua janela. O padrão é `CControlWinTraits`.

> [!NOTE]
> [CContainedWindow](ccontainedwindowt-class.md) é uma especialização de `CContainedWindowT`. Se você quiser alterar a classe base ou características, use `CContainedWindowT` diretamente.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::CContainedWindowT](#ccontainedwindowt)|Construtor. Inicializa os membros de dados para especificar quais mapa de mensagens irá processar mensagens da janela contido.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::Create](#create)|Cria uma janela.|
|[CContainedWindowT::DefWindowProc](#defwindowproc)|Fornece processamento de mensagem padrão.|
|[CContainedWindowT::GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|
|[CContainedWindowT::RegisterWndSuperclass](#registerwndsuperclass)|Registra a classe de janela da janela contida.|
|[CContainedWindowT::SubclassWindow](#subclasswindow)|Subclasses uma janela.|
|[CContainedWindowT::SwitchMessageMap](#switchmessagemap)|Altera qual mapa de mensagem é usado para processar mensagens da janela contido.|
|[CContainedWindowT::UnsubclassWindow](#unsubclasswindow)|Restaura uma janela de subclasse anteriormente.|
|[CContainedWindowT::WindowProc](#windowproc)|(Estático) Processa as mensagens enviadas para janela contida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::m_dwMsgMapID](#m_dwmsgmapid)|Identifica qual mapa de mensagem irá processar mensagens da janela contido.|
|[CContainedWindowT::m_lpszClassName](#m_lpszclassname)|Especifica o nome de uma classe de janela existente no qual uma nova classe de janela será baseada.|
|[CContainedWindowT::m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento de janela original da classe de janela.|
|[CContainedWindowT::m_pObject](#m_pobject)|Aponta para o objeto recipiente.|

## <a name="remarks"></a>Comentários

`CContainedWindowT` implementa uma janela contida dentro de outro objeto. `CContainedWindowT`'s usos do procedimento de janela mapear de uma mensagem no objeto que contém mensagens diretas para manipuladores adequados. Ao construir um `CContainedWindowT` do objeto, você especifica quais mapa da mensagem deve ser usado.

`CContainedWindowT` permite que você crie uma nova janela, superclassing uma classe de janela existente. O `Create` primeiro, o método registra uma classe de janela que se baseia em uma classe existente, mas usa `CContainedWindowT::WindowProc`. `Create` em seguida, cria uma janela com base nessa nova classe de janela. Cada instância do `CContainedWindowT` pode superclasse uma classe de janela diferentes.

`CContainedWindowT` também dá suporte à criação de classes de janela. O `SubclassWindow` método anexa uma janela existente para o `CContainedWindowT` do objeto e altera o procedimento de janela para `CContainedWindowT::WindowProc`. Cada instância do `CContainedWindowT` pode subclasse uma janela diferente.

> [!NOTE]
>  Para qualquer dado `CContainedWindowT` de objeto, chame `Create` ou `SubclassWindow`. Você não deve chamar os dois métodos no mesmo objeto.

Quando você usa o **adicionar um controle com base em** opção no Assistente de projeto de ATL, o assistente adicionará automaticamente um `CContainedWindowT` membro de dados para a classe que implementa o controle. O exemplo a seguir mostra como a janela contida é declarada:

[!code-cpp[NVC_ATL_Windowing#38](../../atl/codesnippet/cpp/ccontainedwindowt-class_1.h)]

[!code-cpp[NVC_ATL_Windowing#39](../../atl/codesnippet/cpp/ccontainedwindowt-class_2.h)]

[!code-cpp[NVC_ATL_Windowing#40](../../atl/codesnippet/cpp/ccontainedwindowt-class_3.h)]

|Para obter mais informações sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando o windows em ATL|[Classes de janela da ATL](../../atl/atl-window-classes.md)|
|ATL Project Wizard|[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)|
|Windows|[Windows](/windows/desktop/winmsg/windows) e tópicos subsequentes no SDK do Windows|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`CContainedWindowT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="ccontainedwindowt"></a>  CContainedWindowT::CContainedWindowT

O construtor inicializa membros de dados.

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

*lpszClassName*<br/>
[in] O nome de uma classe de janela existente no qual a janela contida será baseada.

*pObject*<br/>
[in] Um ponteiro para o objeto recipiente que declara o mapa da mensagem. Classe do objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
[in] Identifica o mapa de mensagem que irá processar mensagens da janela contido. O valor padrão, 0, especifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para usar um mapa de mensagens alternativos declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), passe `msgMapID`.

### <a name="remarks"></a>Comentários

Se você quiser criar uma nova janela por meio [Create](#create), você deve passar o nome de uma classe de janela existente para o *lpszClassName* parâmetro. Por exemplo, consulte o [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) visão geral.

Há três construtores:

- O construtor com três argumentos é o que normalmente é chamado.

- O construtor com dois argumentos usa o nome da classe de `TBase::GetWndClassName`.

- O construtor sem argumentos é usado para fornecer os argumentos mais tarde. Você deve fornecer o nome de classe de janela, o objeto de mapa de mensagem e o ID de mapa de mensagem quando você chama posteriormente `Create`.

Se você subclasse uma janela existente por meio [SubclassWindow](#subclasswindow), o *lpszClassName* valor não será usado; portanto, é possível passar NULL para esse parâmetro.

##  <a name="create"></a>  CContainedWindowT::Create

Chamadas [RegisterWndSuperclass](#registerwndsuperclass) para registrar uma classe de janela que se baseia em uma classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc).

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

*lpszClassName*<br/>
[in] O nome de uma classe de janela existente no qual a janela contida será baseada.

*pObject*<br/>
[in] Um ponteiro para o objeto recipiente que declara o mapa da mensagem. Classe do objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
[in] Identifica o mapa de mensagem que irá processar mensagens da janela contido. O valor padrão, 0, especifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para usar um mapa de mensagens alternativos declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), passe `msgMapID`.

*hWndParent*<br/>
[in] O identificador para a janela pai ou proprietária.

*Rect*<br/>
[in] Um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) especificando a posição da janela de estrutura. O `RECT` pode ser passada por um ponteiro ou referência.

*szWindowName*<br/>
[in] Especifica o nome da janela. O valor padrão é NULL.

*dwStyle*<br/>
[in] O estilo da janela. O valor padrão é WS_CHILD &#124; WS_VISIBLE. Para obter uma lista de valores possíveis, consulte [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) no SDK do Windows.

*dwExStyle*<br/>
[in] O estilo de janela estendidos. O valor padrão é 0, indicando que nenhum estilo estendido. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*MenuOrID*<br/>
[in] Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu da janela. O valor padrão é **0U**.

*lpCreateParam*<br/>
[in] Um ponteiro para dados de criação da janela. Para obter uma descrição completa, consulte a descrição para o parâmetro final [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o identificador para a janela recém-criado; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

O nome de classe de janela existente é salvo na [m_lpszClassName](#m_lpszclassname). `Create` em seguida, cria uma janela com base nessa nova classe. A janela recém-criado é anexada automaticamente ao `CContainedWindowT` objeto.

> [!NOTE]
>  Não chame `Create` se você já terá chamado [SubclassWindow](#subclasswindow).

> [!NOTE]
>  Se 0 for usado como o valor para o *MenuOrID* parâmetro, ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.

##  <a name="defwindowproc"></a>  CContainedWindowT::DefWindowProc

Chamado pelo [WindowProc](#windowproc) para processar mensagens não tratadas pelo mapa de mensagens.

```
LRESULT DefWindowProc()
LRESULT DefWindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
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

##  <a name="getcurrentmessage"></a>  CContainedWindowT::GetCurrentMessage

Retorna a mensagem atual (`m_pCurrentMsg`).

```
const _ATL_MSG* GetCurrentMessage();
```

### <a name="return-value"></a>Valor de retorno

A mensagem atual, empacotada no `MSG` estrutura.

##  <a name="m_dwmsgmapid"></a>  CContainedWindowT::m_dwMsgMapID

Contém o identificador do mapa de mensagens sendo usado para a janela contida.

```
DWORD m_dwMsgMapID;
```

### <a name="remarks"></a>Comentários

Este mapa de mensagem deve ser declarado no objeto contentor.

O mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), sempre é identificado por zero. Um mapa de mensagens alternativos, declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), é identificado por `msgMapID`.

`m_dwMsgMapID` primeiro é inicializada pelo construtor e pode ser alterado ao chamar [SwitchMessageMap](#switchmessagemap). Por exemplo, consulte o [visão geral de CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md).

##  <a name="m_lpszclassname"></a>  CContainedWindowT::m_lpszClassName

Especifica o nome de uma classe de janela existente.

```
LPTSTR m_lpszClassName;
```

### <a name="remarks"></a>Comentários

Quando você cria uma janela [Create](#create) registra uma nova classe de janela que é baseada nessa classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc).

`m_lpszClassName` é inicializada pelo construtor. Por exemplo, consulte o [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md) visão geral.

##  <a name="m_pfnsuperwindowproc"></a>  CContainedWindowT::m_pfnSuperWindowProc

Se a janela contida em uma subclasse, `m_pfnSuperWindowProc` aponta para o procedimento de janela original da classe de janela.

```
WNDPROC m_pfnSuperWindowProc;
```

### <a name="remarks"></a>Comentários

Se a janela contida for superclasse, o que significa que ele se baseia em uma classe de janela que modifica uma classe existente, `m_pfnSuperWindowProc` aponta para o procedimento de janela da classe de janela existente.

O [DefWindowProc](#defwindowproc) método envia informações sobre a mensagem para o procedimento de janela salvado em `m_pfnSuperWindowProc`.

##  <a name="m_pobject"></a>  CContainedWindowT::m_pObject

Aponta para o objeto que contém o `CContainedWindowT` objeto.

```
CMessageMap* m_pObject;
```

### <a name="remarks"></a>Comentários

Nesse contêiner, cuja classe deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md), declara o mapa de mensagem usado por janela contida.

`m_pObject` é inicializada pelo construtor. Por exemplo, consulte o [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md) visão geral.

##  <a name="registerwndsuperclass"></a>  CContainedWindowT::RegisterWndSuperclass

Chamado pelo [criar](#create) para registrar a classe de janela da janela contida.

```
ATOM RegisterWndSuperClass();
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um átomo que identifica exclusivamente a classe de janela que está sendo registrada; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa classe de janela baseia-se em uma classe existente, mas utiliza [CContainedWindowT::WindowProc](#windowproc). Procedimento de janela e de nome da classe de janela existente são salvos no [m_lpszClassName](#m_lpszclassname) e [m_pfnSuperWindowProc](#m_pfnsuperwindowproc), respectivamente.

##  <a name="subclasswindow"></a>  CContainedWindowT::SubclassWindow

Subclasses janela identificada pelo *hWnd* e anexa-o para o `CContainedWindowT` objeto.

```
BOOL SubclassWindow(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[in] O identificador para a janela que está sendo uma subclasse.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela com êxito é uma subclasse; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A subclasse janela agora utiliza [CContainedWindowT::WindowProc](#windowproc). O procedimento de janela original é salva no [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

> [!NOTE]
>  Não chame `SubclassWindow` se você já terá chamado [criar](#create).

##  <a name="switchmessagemap"></a>  CContainedWindowT::SwitchMessageMap

Alterações de mapa de mensagem que será usado para processar mensagens da janela contido.

```
void SwitchMessageMap(DWORD dwMsgMapID);
```

### <a name="parameters"></a>Parâmetros

*dwMsgMapID*<br/>
[in] O identificador de mapa de mensagem. Para usar o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), transmitir zero. Para usar um mapa de mensagens alternativos declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), passe `msgMapID`.

### <a name="remarks"></a>Comentários

O mapa da mensagem deve ser definido no objeto contentor.

Inicialmente, você especifica o identificador de mapa de mensagem no construtor.

##  <a name="unsubclasswindow"></a>  CContainedWindowT::UnsubclassWindow

Desanexa a subclasse na janela de `CContainedWindowT` do objeto e restaura o procedimento de janela original, salvos no [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

```
HWND UnsubclassWindow(BOOL bForce = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bForce*<br/>
[in] Defina como True para forçar o procedimento de janela original a ser restaurado, mesmo se o procedimento de janela para este `CContainedWindowT` objeto não está ativo no momento. Se *bForce* é definido como FALSE e o procedimento de janela para este `CContainedWindowT` objeto não está ativo no momento, o procedimento de janela original não será restaurado.

### <a name="return-value"></a>Valor de retorno

O identificador para a janela anteriormente uma subclasse. Se *bForce* é definido como FALSE e o procedimento de janela para este `CContainedWindowT` objeto não está ativo no momento, retornará NULL.

### <a name="remarks"></a>Comentários

Use esse método somente se você deseja restaurar o procedimento de janela original antes que a janela seja destruída. Caso contrário, [WindowProc](#windowproc) faz isso automaticamente quando a janela é destruída.

##  <a name="windowproc"></a>  CContainedWindowT::WindowProc

Esse método estático implementa o procedimento de janela.

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

`WindowProc` direciona mensagens ao mapa de mensagens, identificado por [m_dwMsgMapID](#m_dwmsgmapid). Se necessário, `WindowProc` chamadas [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais.

## <a name="see-also"></a>Consulte também

[Classe CWindow](../../atl/reference/cwindow-class.md)<br/>
[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Classe CMessageMap](../../atl/reference/cmessagemap-class.md)<br/>
[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)<br/>
[ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

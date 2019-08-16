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
ms.openlocfilehash: 2eae6e149cf6f7422d0653c1c15f46985d8d55c8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496854"
---
# <a name="ccontainedwindowt-class"></a>Classe CContainedWindowT

Essa classe implementa uma janela contida em outro objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class TBase = CWindow, class TWinTraits = CControlWinTraits>
class CContainedWindowT : public TBase
```

#### <a name="parameters"></a>Parâmetros

*TBase*<br/>
A classe base da sua nova classe. A classe base padrão é `CWindow`.

*TWinTraits*<br/>
Uma classe de características que define os estilos para sua janela. O padrão é `CControlWinTraits`.

> [!NOTE]
> [CContainedWindow](ccontainedwindowt-class.md) é uma especialização `CContainedWindowT`de. Se você quiser alterar a classe base ou as características, use `CContainedWindowT` diretamente.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::CContainedWindowT](#ccontainedwindowt)|Construtor. Inicializa membros de dados para especificar qual mapa de mensagens processará as mensagens da janela contidas.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::Create](#create)|Cria uma janela.|
|[CContainedWindowT::DefWindowProc](#defwindowproc)|Fornece o processamento de mensagens padrão.|
|[CContainedWindowT::GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|
|[CContainedWindowT::RegisterWndSuperclass](#registerwndsuperclass)|Registra a classe Window da janela contida.|
|[CContainedWindowT::SubclassWindow](#subclasswindow)|Subclasses de uma janela.|
|[CContainedWindowT::SwitchMessageMap](#switchmessagemap)|Altera qual mapa de mensagens é usado para processar as mensagens da janela contidas.|
|[CContainedWindowT::UnsubclassWindow](#unsubclasswindow)|Restaura uma janela de subclasse anterior.|
|[CContainedWindowT::WindowProc](#windowproc)|Auto-estática Processa as mensagens enviadas para a janela contida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CContainedWindowT::m_dwMsgMapID](#m_dwmsgmapid)|Identifica qual mapa de mensagens processará as mensagens da janela contidas.|
|[CContainedWindowT::m_lpszClassName](#m_lpszclassname)|Especifica o nome de uma classe de janela existente na qual uma nova classe de janela será baseada.|
|[CContainedWindowT::m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento de janela original da classe de janela.|
|[CContainedWindowT::m_pObject](#m_pobject)|Aponta para o objeto recipiente.|

## <a name="remarks"></a>Comentários

`CContainedWindowT`implementa uma janela contida em outro objeto. `CContainedWindowT`o procedimento de janela do usa um mapa de mensagem no objeto contentor para direcionar mensagens para os manipuladores apropriados. Ao construir um objeto `CContainedWindowT` , você especifica qual mapa de mensagens deve ser usado.

`CContainedWindowT`permite que você crie uma nova janela por meio da superclasse de uma classe de janela existente. O `Create` método primeiro registra uma classe de janela baseada em uma classe existente, mas usa `CContainedWindowT::WindowProc`. `Create`em seguida, cria uma janela com base nessa nova classe de janela. Cada instância de `CContainedWindowT` pode superclasse de uma classe de janela diferente.

`CContainedWindowT`também dá suporte à subclasse Window. O `SubclassWindow` método anexa uma janela existente `CContainedWindowT` ao objeto e altera o procedimento de janela para `CContainedWindowT::WindowProc`. Cada instância do `CContainedWindowT` pode subclasse de uma janela diferente.

> [!NOTE]
>  Para qualquer objeto `CContainedWindowT` específico, `Create` chame ou `SubclassWindow`. Você não deve invocar ambos os métodos no mesmo objeto.

Quando você usa a opção **Adicionar controle com base em** no assistente de projeto do ATL, o assistente adicionará `CContainedWindowT` automaticamente um membro de dados à classe que implementa o controle. O exemplo a seguir mostra como a janela contida é declarada:

[!code-cpp[NVC_ATL_Windowing#38](../../atl/codesnippet/cpp/ccontainedwindowt-class_1.h)]

[!code-cpp[NVC_ATL_Windowing#39](../../atl/codesnippet/cpp/ccontainedwindowt-class_2.h)]

[!code-cpp[NVC_ATL_Windowing#40](../../atl/codesnippet/cpp/ccontainedwindowt-class_3.h)]

|Para obter mais informações sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando o Windows na ATL|[Classes de janela da ATL](../../atl/atl-window-classes.md)|
|Assistente de Projeto da ATL|[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)|
|Windows|[Windows](/windows/win32/winmsg/windows) e tópicos subsequentes no SDK do Windows|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`CContainedWindowT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="ccontainedwindowt"></a>  CContainedWindowT::CContainedWindowT

O construtor inicializa os membros de dados.

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
no O nome de uma classe de janela existente na qual a janela contida será baseada.

*pObject*<br/>
no Um ponteiro para o objeto que a contém que declara o mapa da mensagem. A classe desse objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
no Identifica o mapa de mensagens que processará as mensagens da janela contidas. O valor padrão, 0, especifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para usar um mapa de mensagens alternativo declarado com [ALT_MSG_MAP (msgMapID)](message-map-macros-atl.md#alt_msg_map), `msgMapID`passe.

### <a name="remarks"></a>Comentários

Se você quiser criar uma nova janela por meio de [Create](#create), deverá passar o nome de uma classe de janela existente para o parâmetro *lpszClassName* . Para obter um exemplo, consulte a visão geral do [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) .

Há três construtores:

- O construtor com três argumentos é aquele normalmente chamado.

- O construtor com dois argumentos usa o nome de classe `TBase::GetWndClassName`de.

- O construtor sem argumentos será usado se você quiser fornecer os argumentos mais tarde. Você deve fornecer o nome da classe de janela, o objeto de mapa de mensagem e a ID de `Create`mapa de mensagem quando você chamar mais tarde.

Se você criar uma subclasse de uma janela existente por meio de [SubclassWindow](#subclasswindow), o valor de *lpszClassName* não será usado; Portanto, você pode passar NULL para esse parâmetro.

##  <a name="create"></a>  CContainedWindowT::Create

Chama [RegisterWndSuperclass](#registerwndsuperclass) para registrar uma classe de janela baseada em uma classe existente, mas usa [CContainedWindowT:: WindowProc](#windowproc).

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
no O nome de uma classe de janela existente na qual a janela contida será baseada.

*pObject*<br/>
no Um ponteiro para o objeto que a contém que declara o mapa da mensagem. A classe desse objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
no Identifica o mapa de mensagens que processará as mensagens da janela contidas. O valor padrão, 0, especifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para usar um mapa de mensagens alternativo declarado com [ALT_MSG_MAP (msgMapID)](message-map-macros-atl.md#alt_msg_map), `msgMapID`passe.

*hWndParent*<br/>
no O identificador para a janela pai ou proprietário.

*rect*<br/>
no Uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que especifica a posição da janela. O `RECT` pode ser passado por ponteiro ou por referência.

*szWindowName*<br/>
no Especifica o nome da janela. O valor padrão é NULL.

*dwStyle*<br/>
no O estilo da janela. O valor padrão é WS_CHILD &#124; WS_VISIBLE. Para obter uma lista de valores possíveis, consulte [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) no SDK do Windows.

*dwExStyle*<br/>
no O estilo de janela estendida. O valor padrão é 0, o que significa que não há estilo estendido. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*MenuOrID*<br/>
no Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu para a janela. O valor padrão é **0u**.

*lpCreateParam*<br/>
no Um ponteiro para dados de criação de janela. Para obter uma descrição completa, consulte a descrição do parâmetro final para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw).

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o identificador para a janela recém-criada; caso contrário, NULL.

### <a name="remarks"></a>Comentários

O nome da classe de janela existente é salvo em [m_lpszClassName](#m_lpszclassname). `Create`em seguida, cria uma janela com base nessa nova classe. A janela recém-criada é anexada automaticamente ao `CContainedWindowT` objeto.

> [!NOTE]
>  Não chame `Create` se você já chamou [SubclassWindow](#subclasswindow).

> [!NOTE]
>  Se 0 for usado como o valor para o parâmetro *MenuOrID* , ele deverá ser especificado como 0u (o valor padrão) para evitar um erro do compilador.

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
no A mensagem enviada para a janela.

*wParam*<br/>
no Informações adicionais específicas da mensagem.

*lParam*<br/>
no Informações adicionais específicas da mensagem.

### <a name="return-value"></a>Valor de retorno

O resultado do processamento da mensagem.

### <a name="remarks"></a>Comentários

Por padrão, `DefWindowProc` o chama a função Win32 [CallWindowProc](/windows/win32/api/winuser/nf-winuser-callwindowprocw) para enviar as informações da mensagem para o procedimento de janela especificado em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

##  <a name="getcurrentmessage"></a>  CContainedWindowT::GetCurrentMessage

Retorna a mensagem atual (`m_pCurrentMsg`).

```
const _ATL_MSG* GetCurrentMessage();
```

### <a name="return-value"></a>Valor de retorno

A mensagem atual, empacotada na `MSG` estrutura.

##  <a name="m_dwmsgmapid"></a>  CContainedWindowT::m_dwMsgMapID

Mantém o identificador do mapa de mensagens que está sendo usado no momento para a janela contida.

```
DWORD m_dwMsgMapID;
```

### <a name="remarks"></a>Comentários

Esse mapa de mensagens deve ser declarado no objeto recipiente.

O mapa de mensagem padrão, declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), é sempre identificado por zero. Um mapa de mensagens alternativo, declarado com [ALT_MSG_MAP (msgMapID)](message-map-macros-atl.md#alt_msg_map), é identificado `msgMapID`por.

`m_dwMsgMapID`é inicializado pela primeira vez pelo construtor e pode ser alterado chamando [SwitchMessageMap](#switchmessagemap). Para obter um exemplo, consulte a [visão geral do CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md).

##  <a name="m_lpszclassname"></a>  CContainedWindowT::m_lpszClassName

Especifica o nome de uma classe de janela existente.

```
LPTSTR m_lpszClassName;
```

### <a name="remarks"></a>Comentários

Quando você cria uma janela, [criar](#create) registra uma nova classe de janela com base nessa classe existente, mas usa [CContainedWindowT:: WindowProc](#windowproc).

`m_lpszClassName`é inicializado pelo construtor. Para obter um exemplo, consulte a visão geral do [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md) .

##  <a name="m_pfnsuperwindowproc"></a>  CContainedWindowT::m_pfnSuperWindowProc

Se a janela contida for subclasse, `m_pfnSuperWindowProc` apontará para o procedimento de janela original da classe Window.

```
WNDPROC m_pfnSuperWindowProc;
```

### <a name="remarks"></a>Comentários

Se a janela contida for superclasse, o que significa que ela se baseia em uma classe de janela que modifica uma classe `m_pfnSuperWindowProc` existente, aponta para o procedimento de janela da classe de janela existente.

O método [DefWindowProc](#defwindowproc) envia informações de mensagem para o procedimento de janela `m_pfnSuperWindowProc`salvo em.

##  <a name="m_pobject"></a>  CContainedWindowT::m_pObject

Aponta para o objeto que contém `CContainedWindowT` o objeto.

```
CMessageMap* m_pObject;
```

### <a name="remarks"></a>Comentários

Esse contêiner, cuja classe deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md), declara o mapa de mensagens usado pela janela contida.

`m_pObject`é inicializado pelo construtor. Para obter um exemplo, consulte a visão geral do [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md) .

##  <a name="registerwndsuperclass"></a>  CContainedWindowT::RegisterWndSuperclass

Chamado por [criar](#create) para registrar a classe de janela da janela contida.

```
ATOM RegisterWndSuperClass();
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um Atom que identifica exclusivamente a classe de janela que está sendo registrada; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa classe de janela é baseada em uma classe existente, mas usa [CContainedWindowT:: WindowProc](#windowproc). O nome da classe de janela existente e o procedimento de janela são salvos em [m_lpszClassName](#m_lpszclassname) e [m_pfnSuperWindowProc](#m_pfnsuperwindowproc), respectivamente.

##  <a name="subclasswindow"></a>  CContainedWindowT::SubclassWindow

Subclasses a janela identificada por *HWND* e a anexa ao `CContainedWindowT` objeto.

```
BOOL SubclassWindow(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
no O identificador para a janela que está sendo subclasse.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela for subclasseda com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A janela de subclasse agora usa [CContainedWindowT:: WindowProc](#windowproc). O procedimento de janela original é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

> [!NOTE]
>  Não chame `SubclassWindow` se você já tiver chamado [Create](#create).

##  <a name="switchmessagemap"></a>  CContainedWindowT::SwitchMessageMap

Altera qual mapa de mensagens será usado para processar as mensagens da janela contidas.

```
void SwitchMessageMap(DWORD dwMsgMapID);
```

### <a name="parameters"></a>Parâmetros

*dwMsgMapID*<br/>
no O identificador do mapa de mensagens. Para usar o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), passe zero. Para usar um mapa de mensagens alternativo declarado com [ALT_MSG_MAP (msgMapID)](message-map-macros-atl.md#alt_msg_map), `msgMapID`passe.

### <a name="remarks"></a>Comentários

O mapa de mensagens deve ser definido no objeto contentor.

Inicialmente, você especifica o identificador do mapa de mensagens no construtor.

##  <a name="unsubclasswindow"></a>  CContainedWindowT::UnsubclassWindow

Desanexa a janela de subclasse do `CContainedWindowT` objeto e restaura o procedimento de janela original, salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).

```
HWND UnsubclassWindow(BOOL bForce = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bForce*<br/>
no Defina como true para forçar o procedimento de janela original a ser restaurado mesmo que o procedimento de `CContainedWindowT` janela desse objeto não esteja ativo no momento. Se *bForce* for definido como false e o procedimento de janela para `CContainedWindowT` esse objeto não estiver ativo no momento, o procedimento de janela original não será restaurado.

### <a name="return-value"></a>Valor de retorno

O identificador para a janela anteriormente subclasse. Se *bForce* for definido como false e o procedimento de janela para `CContainedWindowT` esse objeto não estiver ativo no momento, retornará NULL.

### <a name="remarks"></a>Comentários

Use esse método somente se você quiser restaurar o procedimento de janela original antes que a janela seja destruída. Caso contrário, o [WindowProc](#windowproc) fará isso automaticamente quando a janela for destruída.

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
no O identificador para a janela.

*uMsg*<br/>
no A mensagem enviada para a janela.

*wParam*<br/>
no Informações adicionais específicas da mensagem.

*lParam*<br/>
no Informações adicionais específicas da mensagem.

### <a name="return-value"></a>Valor de retorno

O resultado do processamento da mensagem.

### <a name="remarks"></a>Comentários

`WindowProc`direciona mensagens para o mapa de mensagens identificado por [m_dwMsgMapID](#m_dwmsgmapid). Se necessário, `WindowProc` chama [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais.

## <a name="see-also"></a>Consulte também

[Classe CWindow](../../atl/reference/cwindow-class.md)<br/>
[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Classe CMessageMap](../../atl/reference/cmessagemap-class.md)<br/>
[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)<br/>
[ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)

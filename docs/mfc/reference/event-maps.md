---
title: Mapas de evento
ms.date: 09/07/2019
helpviewer_keywords:
- event maps [MFC]
ms.assetid: 1ed53aee-bc53-43cd-834a-6fb935c0d29b
ms.openlocfilehash: c79d2fb1ac73947ddb13adcbd444ff7b5d50bdb4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365744"
---
# <a name="event-maps"></a>Mapas de evento

Sempre que um controle deseja notificar seu contêiner de que alguma ação (determinada pelo desenvolvedor de controle) aconteceu (como um pressionamento de tecla, clique do mouse ou uma alteração no estado do controle) ele chama uma função de disparo de eventos. Esta função notifica o recipiente de controle de que alguma ação importante ocorreu ao disparar o evento relacionado.

A Microsoft Foundation Class Library oferece um modelo de programação otimizado para eventos de disparo. Neste modelo, "mapas de eventos" são usados para designar quais funções disparam quais eventos para um determinado controle. Os mapas de eventos contêm uma macro para cada evento. Por exemplo, um mapa de eventos que dispara um evento de clique de estoque pode ser assim:

[!code-cpp[NVC_MFCAxCtl#16](../../mfc/reference/codesnippet/cpp/event-maps_1.cpp)]

A `EVENT_STOCK_CLICK` macro indica que o controle disparará um evento de clique de estoque toda vez que detectar um clique no mouse. Para obter uma lista mais detalhada de outros eventos de ações, consulte o artigo [ActiveX Controls: Events](../../mfc/mfc-activex-controls-events.md). As macros também estão disponíveis para indicar eventos personalizados.

Embora as macros de mapa de eventos sejam importantes, você geralmente não as insere diretamente. Isso porque a janela **Propriedades** (no **Class View)** cria automaticamente entradas de mapa de eventos em seus arquivos de origem quando você a usa para associar funções de disparo de eventos com eventos. Sempre que você quiser editar ou adicionar uma entrada de mapa de eventos, você pode usar a janela **Propriedades.**

Para suportar mapas de eventos, o MFC fornece as seguintes macros:

## <a name="event-map-macros"></a>Macros do Mapa de Eventos

### <a name="event-map-declaration-and-demarcation"></a>Declaração e Demarcação do Mapa de Eventos

|||
|-|-|
|[DECLARE_EVENT_MAP](#declare_event_map)|Declara que um mapa de eventos será usado em uma classe para mapear eventos para funções de disparo de eventos (deve ser usado na declaração de classe).|
|[BEGIN_EVENT_MAP](#begin_event_map)|Começa a definição de um mapa de eventos (deve ser usado na implementação da classe).|
|[END_EVENT_MAP](#end_event_map)|Termina a definição de um mapa de eventos (deve ser usado na implementação da classe).|

### <a name="event-mapping-macros"></a>Macros de mapeamento de eventos

|||
|-|-|
|[EVENT_CUSTOM](#event_custom)|Indica qual função de disparo de evento disparará o evento especificado.|
|[EVENT_CUSTOM_ID](#event_custom_id)|Indica qual função de disparo de eventos disparará o evento especificado, com um ID de despacho designado.|

### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagens

|||
|-|-|
|[ON_OLEVERB](#on_oleverb)|Indica um verbo personalizado manipulado pelo controle OLE.|
|[ON_STDOLEVERB](#on_stdoleverb)|Substitui um mapeamento verbo padrão do controle OLE.|

## <a name="declare_event_map"></a><a name="declare_event_map"></a>DECLARE_EVENT_MAP

Cada `COleControl`classe derivada do seu programa pode fornecer um mapa de eventos para especificar os eventos que seu controle disparará.

```cpp
DECLARE_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Use a DECLARE_EVENT_MAP macro no final da declaração da sua classe. Em seguida, no arquivo .cpp que define as funções do membro para a classe, use a BEGIN_EVENT_MAP macro, as entradas macro para cada um dos eventos do controle e a macro END_EVENT_MAP para declarar o fim da lista de eventos.

Para obter mais informações sobre mapas de eventos, consulte o artigo [ActiveX Controls: Events](../../mfc/mfc-activex-controls-events.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl.h

## <a name="begin_event_map"></a><a name="begin_event_map"></a>BEGIN_EVENT_MAP

Começa a definição do seu mapa de eventos.

```cpp
BEGIN_EVENT_MAP(theClass,  baseClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe de controle cujo mapa de eventos é este.

*Baseclass*<br/>
Especifica o nome da classe base *doClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (.cpp) que define as funções do membro para sua classe, inicie o mapa de eventos com a macro BEGIN_EVENT_MAP, adicione entradas de macro para cada um de seus eventos e complete o mapa do evento com a macro END_EVENT_MAP.

Para obter mais informações sobre mapas de eventos e a macro BEGIN_EVENT_MAP, consulte o artigo [ActiveX Controls: Events](../../mfc/mfc-activex-controls-events.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl.h

## <a name="end_event_map"></a><a name="end_event_map"></a>END_EVENT_MAP

Use a END_EVENT_MAP macro para finalizar a definição do mapa de eventos.

```cpp
END_EVENT_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl.h

## <a name="event_custom"></a><a name="event_custom"></a>EVENT_CUSTOM

Define uma entrada mapa de eventos para um evento personalizado.

```cpp
EVENT_CUSTOM(pszName, pfnFire,  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
O nome do evento.

*pfnFire*<br/>
O nome da função de disparo do evento.

*Vtsparams*<br/>
Uma lista separada pelo espaço de uma ou mais constantes especificando a lista de parâmetros da função.

### <a name="remarks"></a>Comentários

O parâmetro *vtsParams* é uma lista de valores separados pelo espaço das `VTS_` constantes. Um ou mais desses valores separados por espaços (não commas) especifica míseros da função. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#13](../../mfc/codesnippet/cpp/event-maps_2.cpp)]

especifica uma lista contendo um inteiro de 32 bits representando um valor de `IFontDisp` cor RGB, seguido por um ponteiro para a interface de um objeto de fonte OLE.

As `VTS_` constantes e seus significados são os seguintes:

|Símbolo|Tipo de parâmetro|
|------------|--------------------|
|VTS_I2|**Curto**|
|VTS_I4|**Longas**|
|VTS_R4|**float**|
|VTS_R8|**double**|
|VTS_COLOR|OLE_COLOR|
|VTS_CY|CURRENCY|
|VTS_DATE|DATE|
|VTS_BSTR|**const** __\* char__|
|VTS_DISPATCH|LPDISPATCH|
|VTS_FONT|`IFontDispatch*`|
|VTS_HANDLE|Lidar com|
|VTS_SCODE|SCODE|
|VTS_BOOL|BOOL|
|VTS_VARIANT|`const VARIANT*`|
|VTS_PVARIANT|`VARIANT*`|
|VTS_UNKNOWN|Lpunknown|
|VTS_OPTEXCLUSIVE|OLE_OPTEXCLUSIVE|
|VTS_PICTURE|`IPictureDisp*`|
|VTS_TRISTATE|OLE_TRISTATE|
|VTS_XPOS_PIXELS|Ole_xpos_pixels|
|VTS_YPOS_PIXELS|OLE_YPOS_PIXELS|
|VTS_XSIZE_PIXELS|OLE_XSIZE_PIXELS|
|VTS_YSIZE_PIXELS|OLE_YSIZE_PIXELS|
|TS_XPOS_HIMETRIC|OLE_XPOS_HIMETRIC|
|VTS_YPOS_HIMETRIC|OLE_YPOS_HIMETRIC|
|VTS_XSIZE_HIMETRIC|OLE_XSIZE_HIMETRIC|
|VTS_YSIZE_HIMETRIC|OLE_YSIZE_HIMETRIC|

> [!NOTE]
> Foram definidas constantes adicionais de variantes para todos os tipos de variantes, com exceção de VTS_FONT e VTS_PICTURE, que fornecem um ponteiro para a constante de dados da variante. Essas constantes são `VTS_Pconstantname` nomeadas usando a convenção. Por exemplo, VTS_PCOLOR é um ponteiro para uma VTS_COLOR constante.

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl.h

## <a name="event_custom_id"></a><a name="event_custom_id"></a>EVENT_CUSTOM_ID

Define uma função de disparo de evento para um evento personalizado pertencente ao ID de expedição especificado por *dispid*.

```cpp
EVENT_CUSTOM_ID(
    pszName,
    dispid,
    pfnFire,
    vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Pszname*<br/>
O nome do evento.

*Dispid*<br/>
A id de despacho usada pelo controle ao disparar o evento.

*pfnFire*<br/>
O nome da função de disparo do evento.

*Vtsparams*<br/>
Uma lista variável de parâmetros passados para o recipiente de controle quando o evento é acionado.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de `VTS_` valores separados pelo espaço das constantes. Um ou mais desses valores separados por espaços, não por commas, especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#13](../../mfc/codesnippet/cpp/event-maps_2.cpp)]

especifica uma lista contendo um inteiro de 32 bits representando um valor de `IFontDisp` cor RGB, seguido por um ponteiro para a interface de um objeto de fonte OLE.

Para obter uma `VTS_` lista das constantes, consulte [EVENT_CUSTOM](#event_custom).

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl.h

## <a name="on_oleverb"></a><a name="on_oleverb"></a>ON_OLEVERB

Esta macro define uma entrada de mapa de mensagem que mapeia um verbo personalizado para uma função de membro específica do seu controle.

```cpp
ON_OLEVERB(idsVerbName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*idsVerbName*<br/>
O iD de recurso de string do nome do verbo.

*Memberfxn*<br/>
A função chamada pela estrutura quando o verbo é invocado.

### <a name="remarks"></a>Comentários

O editor de recursos pode ser usado para criar nomes verbos personalizados que são adicionados à sua tabela de strings.

O protótipo de função para *membroFxn* é:

```cpp
BOOL memberFxn(
   LPMSG    lpMsg,
   HWND     hWndParent,
   LPCRECT  lpRect);
```

Os valores dos *parâmetros lpMsg,* *hWndParent*e *lpRect* `IOleObject::DoVerb` são retirados dos parâmetros correspondentes da função membro.

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxole.h

## <a name="on_stdoleverb"></a><a name="on_stdoleverb"></a>ON_STDOLEVERB

Use esta macro para substituir o comportamento padrão de um verbo padrão.

```cpp
ON_STDOLEVERB(iVerb, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
O índice de verbo padrão para o verbo sendo substituído.

*Memberfxn*<br/>
A função chamada pela estrutura quando o verbo é invocado.

### <a name="remarks"></a>Comentários

O índice de verbo `OLEIVERB_`padrão é do formulário, seguido de uma ação. OLEIVERB_SHOW, OLEIVERB_HIDE e OLEIVERB_UIACTIVATE são alguns exemplos de verbos padrão.

Consulte [ON_OLEVERB](#on_oleverb) para obter uma descrição do protótipo de função a ser usado como parâmetro *memberFxn.*

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxole.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

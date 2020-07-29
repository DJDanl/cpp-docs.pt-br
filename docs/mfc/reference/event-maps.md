---
title: Mapas de evento
ms.date: 09/07/2019
helpviewer_keywords:
- event maps [MFC]
ms.assetid: 1ed53aee-bc53-43cd-834a-6fb935c0d29b
ms.openlocfilehash: ef8ee6b87bdeb9d5da9f34d303e0c0fda89443c5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222791"
---
# <a name="event-maps"></a>Mapas de evento

Sempre que um controle deseja notificar seu contêiner de que alguma ação (determinada pelo desenvolvedor de controle) ocorreu (como um pressionamento de tecla, um clique do mouse ou uma alteração no estado do controle), ele chama uma função acionada por evento. Essa função notifica o contêiner de controle de que alguma ação importante ocorreu ao acionar o evento relacionado.

O biblioteca MFC oferece um modelo de programação otimizado para eventos de acionamento. Nesse modelo, "mapas de eventos" são usados para designar quais funções acionam quais eventos para um controle específico. Os mapas de eventos contêm uma macro para cada evento. Por exemplo, um mapa de eventos que dispara um evento de clique de ações pode ser assim:

[!code-cpp[NVC_MFCAxCtl#16](../../mfc/reference/codesnippet/cpp/event-maps_1.cpp)]

A `EVENT_STOCK_CLICK` macro indica que o controle acionará um evento de clique no estoque sempre que detectar um clique do mouse. Para obter uma listagem mais detalhada de outros eventos de estoque, consulte o artigo [controles ActiveX: eventos](../../mfc/mfc-activex-controls-events.md). As macros também estão disponíveis para indicar eventos personalizados.

Embora as macros de mapa de eventos sejam importantes, você geralmente não as insere diretamente. Isso ocorre porque a janela **Propriedades** (em **modo de exibição de classe**) cria automaticamente entradas de mapa de eventos em seus arquivos de origem quando você a usa para associar funções de acionamento de eventos a eventos. Sempre que desejar editar ou adicionar uma entrada de mapa de eventos, você poderá usar a janela **Propriedades** .

Para dar suporte a mapas de eventos, o MFC fornece as seguintes macros:

## <a name="event-map-macros"></a>Macros do mapa de eventos

### <a name="event-map-declaration-and-demarcation"></a>Declaração e demarcador do mapa de eventos

|||
|-|-|
|[DECLARE_EVENT_MAP](#declare_event_map)|Declara que um mapa de eventos será usado em uma classe para mapear eventos para funções de acionamento de eventos (deve ser usado na declaração de classe).|
|[BEGIN_EVENT_MAP](#begin_event_map)|Inicia a definição de um mapa de eventos (deve ser usado na implementação da classe).|
|[END_EVENT_MAP](#end_event_map)|Termina a definição de um mapa de eventos (deve ser usado na implementação da classe).|

### <a name="event-mapping-macros"></a>Macros de mapeamento de eventos

|||
|-|-|
|[EVENT_CUSTOM](#event_custom)|Indica qual função de acionamento de evento acionará o evento especificado.|
|[EVENT_CUSTOM_ID](#event_custom_id)|Indica qual função de acionamento de evento acionará o evento especificado, com uma ID de expedição designada.|

### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagens

|||
|-|-|
|[ON_OLEVERB](#on_oleverb)|Indica um verbo personalizado manipulado pelo controle OLE.|
|[ON_STDOLEVERB](#on_stdoleverb)|Substitui um mapeamento de verbo padrão do controle OLE.|

## <a name="declare_event_map"></a><a name="declare_event_map"></a>DECLARE_EVENT_MAP

Cada `COleControl` classe derivada em seu programa pode fornecer um mapa de eventos para especificar os eventos que seu controle irá disparar.

```cpp
DECLARE_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_EVENT_MAP no final da declaração de sua classe. Em seguida, no arquivo. cpp que define as funções de membro para a classe, use a macro BEGIN_EVENT_MAP, entradas de macro para cada um dos eventos do controle e a macro END_EVENT_MAP para declarar o final da lista de eventos.

Para obter mais informações sobre mapas de eventos, consulte o artigo [controles ActiveX: eventos](../../mfc/mfc-activex-controls-events.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl. h

## <a name="begin_event_map"></a><a name="begin_event_map"></a>BEGIN_EVENT_MAP

Inicia a definição do seu mapa de eventos.

```cpp
BEGIN_EVENT_MAP(theClass,  baseClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe de controle cujo mapeamento de evento é.

*baseClass*<br/>
Especifica o nome da classe base da *classe*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para sua classe, inicie o mapa de eventos com a macro BEGIN_EVENT_MAP e, em seguida, adicione entradas de macro para cada um dos seus eventos e conclua o mapa de eventos com a macro END_EVENT_MAP.

Para obter mais informações sobre mapas de eventos e a macro BEGIN_EVENT_MAP, consulte o artigo [controles ActiveX: eventos](../../mfc/mfc-activex-controls-events.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl. h

## <a name="end_event_map"></a><a name="end_event_map"></a>END_EVENT_MAP

Use a macro END_EVENT_MAP para encerrar a definição do seu mapa de eventos.

```cpp
END_EVENT_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl. h

## <a name="event_custom"></a><a name="event_custom"></a>EVENT_CUSTOM

Define uma entrada de mapa de eventos para um evento personalizado.

```cpp
EVENT_CUSTOM(pszName, pfnFire,  vtsParams)
```

### <a name="parameters"></a>parâmetros

*pszName*<br/>
O nome do evento.

*pfnFire*<br/>
O nome da função de acionamento do evento.

*vtsParams*<br/>
Uma lista separada por espaços de uma ou mais constantes que especificam a lista de parâmetros da função.

### <a name="remarks"></a>Comentários

O parâmetro *vtsParams* é uma lista de valores separados por espaços das `VTS_` constantes. Um ou mais desses valores separados por espaços (e não por vírgulas) especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#13](../../mfc/codesnippet/cpp/event-maps_2.cpp)]

Especifica uma lista que contém um inteiro de 32 bits que representa um valor de cor RGB, seguido por um ponteiro para a `IFontDisp` interface de um objeto de fonte OLE.

As `VTS_` constantes e seus significados são os seguintes:

|Símbolo|Tipo de parâmetro|
|------------|--------------------|
|VTS_I2|**`short`**|
|VTS_I4|**`long`**|
|VTS_R4|**`float`**|
|VTS_R8|**`double`**|
|VTS_COLOR|OLE_COLOR|
|VTS_CY|CURRENCY|
|VTS_DATE|DATE|
|VTS_BSTR|**`const`**__caractere \* __|
|VTS_DISPATCH|LPDISPATCH|
|VTS_FONT|`IFontDispatch*`|
|VTS_HANDLE|PROCESSAMENTO|
|VTS_SCODE|SCODE|
|VTS_BOOL|BOOL|
|VTS_VARIANT|`const VARIANT*`|
|VTS_PVARIANT|`VARIANT*`|
|VTS_UNKNOWN|LPUNKNOWN|
|VTS_OPTEXCLUSIVE|OLE_OPTEXCLUSIVE|
|VTS_PICTURE|`IPictureDisp*`|
|VTS_TRISTATE|OLE_TRISTATE|
|VTS_XPOS_PIXELS|OLE_XPOS_PIXELS|
|VTS_YPOS_PIXELS|OLE_YPOS_PIXELS|
|VTS_XSIZE_PIXELS|OLE_XSIZE_PIXELS|
|VTS_YSIZE_PIXELS|OLE_YSIZE_PIXELS|
|TS_XPOS_HIMETRIC|OLE_XPOS_HIMETRIC|
|VTS_YPOS_HIMETRIC|OLE_YPOS_HIMETRIC|
|VTS_XSIZE_HIMETRIC|OLE_XSIZE_HIMETRIC|
|VTS_YSIZE_HIMETRIC|OLE_YSIZE_HIMETRIC|

> [!NOTE]
> Constantes Variant adicionais foram definidas para todos os tipos de variante, com exceção de VTS_FONT e VTS_PICTURE, que fornecem um ponteiro para a constante de dados Variant. Essas constantes são nomeadas usando a `VTS_Pconstantname` Convenção. Por exemplo, VTS_PCOLOR é um ponteiro para uma constante VTS_COLOR.

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl. h

## <a name="event_custom_id"></a><a name="event_custom_id"></a>EVENT_CUSTOM_ID

Define uma função de acionamento de evento para um evento personalizado que pertence à ID de expedição especificada por *DISPID*.

```cpp
EVENT_CUSTOM_ID(
    pszName,
    dispid,
    pfnFire,
    vtsParams)
```

### <a name="parameters"></a>parâmetros

*pszName*<br/>
O nome do evento.

*DISPID*<br/>
A ID de expedição usada pelo controle ao acionar o evento.

*pfnFire*<br/>
O nome da função de acionamento do evento.

*vtsParams*<br/>
Uma lista variável de parâmetros passada para o contêiner de controle quando o evento é acionado.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados por espaços das `VTS_` constantes. Um ou mais desses valores separados por espaços, não por vírgulas, especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#13](../../mfc/codesnippet/cpp/event-maps_2.cpp)]

Especifica uma lista que contém um inteiro de 32 bits que representa um valor de cor RGB, seguido por um ponteiro para a `IFontDisp` interface de um objeto de fonte OLE.

Para obter uma lista das `VTS_` constantes, consulte [EVENT_CUSTOM](#event_custom).

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxctl. h

## <a name="on_oleverb"></a><a name="on_oleverb"></a>ON_OLEVERB

Essa macro define uma entrada de mapa de mensagem que mapeia um verbo personalizado para uma função de membro específica do seu controle.

```cpp
ON_OLEVERB(idsVerbName,  memberFxn)
```

### <a name="parameters"></a>parâmetros

*idsVerbName*<br/>
A ID de recurso da cadeia de caracteres do nome do verbo.

*memberFxn*<br/>
A função chamada pelo Framework quando o verbo é invocado.

### <a name="remarks"></a>Comentários

O editor de recursos pode ser usado para criar nomes de verbo personalizados que são adicionados à sua tabela de cadeia de caracteres.

O protótipo de função para *memberFxn* é:

```cpp
BOOL memberFxn(
   LPMSG    lpMsg,
   HWND     hWndParent,
   LPCRECT  lpRect);
```

Os valores dos parâmetros *lpMsg*, *hwndParent*e *lpRect* são obtidos dos parâmetros correspondentes da `IOleObject::DoVerb` função membro.

### <a name="requirements"></a>Requisitos

**Cabeçalho** Afxole. h

## <a name="on_stdoleverb"></a><a name="on_stdoleverb"></a>ON_STDOLEVERB

Use esta macro para substituir o comportamento padrão de um verbo padrão.

```cpp
ON_STDOLEVERB(iVerb, memberFxn)
```

### <a name="parameters"></a>parâmetros

*iVerb*<br/>
O índice de verbo padrão para o verbo que está sendo substituído.

*memberFxn*<br/>
A função chamada pelo Framework quando o verbo é invocado.

### <a name="remarks"></a>Comentários

O índice de verbo padrão é do formulário `OLEIVERB_` , seguido por uma ação. OLEIVERB_SHOW, OLEIVERB_HIDE e OLEIVERB_UIACTIVATE são alguns exemplos de verbos padrão.

Consulte [ON_OLEVERB](#on_oleverb) para obter uma descrição do protótipo de função a ser usado como o parâmetro *memberFxn* .

### <a name="requirements"></a>Requisitos

**Cabeçalho** Afxole. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

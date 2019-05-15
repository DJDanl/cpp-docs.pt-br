---
title: Mapas de evento
ms.date: 06/20/2018
helpviewer_keywords:
- event maps [MFC]
ms.assetid: 1ed53aee-bc53-43cd-834a-6fb935c0d29b
ms.openlocfilehash: 98614aa41d3131d28c9e0c7584e5a88c2249ef97
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65612239"
---
# <a name="event-maps"></a>Mapas de evento

Sempre que um controle deseja notificar seu recipiente que alguma ação (determinada pelo desenvolvedor do controle) aconteceu (como um pressionamento de tecla, clique do mouse ou uma alteração no estado do controle), ele chama uma função de acionamento do evento. Essa função notifica o contêiner de controle que ocorreu alguma ação importante disparando o evento relacionado.

A biblioteca Microsoft Foundation Class oferece um modelo de programação com otimização de eventos acionados. Nesse modelo, "evento mapeia" são usadas para designar funções que acionam os eventos para um determinado controle. Mapas de evento contêm uma macro para cada evento. Por exemplo, um mapa de evento que dispara uma ação de clique evento teria esta aparência:

[!code-cpp[NVC_MFCAxCtl#16](../../mfc/reference/codesnippet/cpp/event-maps_1.cpp)]

O `EVENT_STOCK_CLICK` macro indica que o controle será disparado um clique de evento sempre que detecta um mouse de clique de ações. Para obter uma lista mais detalhada de outros eventos de estoque, consulte o artigo [controles ActiveX: Eventos](../../mfc/mfc-activex-controls-events.md). Macros também estão disponíveis para indicar eventos personalizados.

Embora as macros de mapa de evento são importantes, você geralmente não inseri-los diretamente. Isso ocorre porque a janela Propriedades cria automaticamente as entradas de mapa de eventos nos arquivos de origem quando usá-lo para associar funções de acionamento do evento de eventos. Sempre que você deseja editar ou adicionar uma entrada de mapa de evento, você pode usar a janela Propriedades.

Para dar suporte a mapas de evento, o MFC oferece as seguintes macros:

## <a name="event-map-macros"></a>Macros de mapa de evento

### <a name="event-map-declaration-and-demarcation"></a>Declaração de mapa de evento e demarcação

|||
|-|-|
|[DECLARE_EVENT_MAP](#declare_event_map)|Declara que um mapa de eventos será usado em uma classe para mapear eventos para funções de acionamento do evento (deve ser usado na declaração de classe).|
|[BEGIN_EVENT_MAP](#begin_event_map)|Inicia a definição de um mapa de eventos (deve ser usada na implementação da classe).|
|[END_EVENT_MAP](#end_event_map)|Finaliza a definição de um mapa de evento (deve ser usada na implementação da classe).|

### <a name="event-mapping-macros"></a>Macros de mapeamento do evento

|||
|-|-|
|[EVENT_CUSTOM](#event_custom)|Indica qual função de acionamento do evento será acionado o evento especificado.|
|[EVENT_CUSTOM_ID](#event_custom_id)|Indica qual função de acionamento do evento será acionado o evento especificado, com uma ID de expedição designado.|

### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagem

|||
|-|-|
|[ON_OLEVERB](#on_oleverb)|Indica um verbo personalizado manipulado pelo controle OLE.|
|[ON_STDOLEVERB](#on_stdoleverb)|Substitui um mapeamento de verbo padrão do controle OLE.|

##  <a name="declare_event_map"></a>  DECLARE_EVENT_MAP

Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de eventos para especificar os eventos de seu controle será acionado.

```cpp
DECLARE_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_EVENT_MAP no final de sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use a macro BEGIN_EVENT_MAP, entradas de macro para cada um dos eventos do controle e a macro END_EVENT_MAP para declarar o fim da lista de eventos.

Para obter mais informações sobre mapas de evento, consulte o artigo [controles ActiveX: Eventos](../../mfc/mfc-activex-controls-events.md).

### <a name="requirements"></a>Requisitos

**Header** afxctl.h

## <a name="begin_event_map"></a>  BEGIN_EVENT_MAP

Inicia a definição de seu mapa de evento.

```cpp
BEGIN_EVENT_MAP(theClass,  baseClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe do controle cujo evento ser mapeado.

*baseClass*<br/>
Especifica o nome da classe base da *theClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, iniciar o mapa de evento com a macro BEGIN_EVENT_MAP, em seguida, adicione entradas de macro para cada um dos seus eventos e concluir o mapa de evento com a macro END_EVENT_MAP.

Para obter mais informações sobre mapas de evento e a macro BEGIN_EVENT_MAP, consulte o artigo [controles ActiveX: Eventos](../../mfc/mfc-activex-controls-events.md).

### <a name="requirements"></a>Requisitos

**Header** afxctl.h

##  <a name="end_event_map"></a>  END_EVENT_MAP

Use a macro END_EVENT_MAP para finalizar a definição de seu mapa de evento.

```cpp
END_EVENT_MAP()
```

### <a name="requirements"></a>Requisitos

**Header** afxctl.h

## <a name="event_custom"></a>  EVENT_CUSTOM

Define uma entrada de mapa de eventos para um evento personalizado.

```cpp
EVENT_CUSTOM(pszName, pfnFire,  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*pszName*<br/>
O nome do evento.

*pfnFire*<br/>
O nome da função de acionamento do evento.

*vtsParams*<br/>
Uma lista separada por espaços de uma ou mais constantes especificando a lista de parâmetros da função.

### <a name="remarks"></a>Comentários

O *vtsParams* parâmetro é uma lista separada por espaço de valores da `VTS_` constantes. Um ou mais desses valores separados por espaços (não a vírgula) Especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#13](../../mfc/codesnippet/cpp/event-maps_2.cpp)]

Especifica a cor de uma lista que contém um inteiro de 32 bits que representa um RGB valor, seguido por um ponteiro para o `IFontDisp` interface de um objeto de fonte OLE.

O `VTS_` constantes e seus significados são da seguinte maneira:

|Símbolo|Tipo de parâmetro|
|------------|--------------------|
|VTS_I2|**short**|
|VTS_I4|**long**|
|VTS_R4|**float**|
|VTS_R8|**double**|
|VTS_COLOR|OLE_COLOR|
|VTS_CY|MOEDA|
|VTS_DATE|DATE|
|VTS_BSTR|**const** __char\*__|
|VTS_DISPATCH|LPDISPATCH|
|VTS_FONT|`IFontDispatch*`|
|VTS_HANDLE|IDENTIFICADOR|
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
> Constantes de variant adicionais foram definidos para todos os tipos variantes, com exceção do VTS_FONT e VTS_PICTURE, que fornecem um ponteiro para a constante de dados variant. Essas constantes são nomeadas usando o `VTS_Pconstantname` convenção. Por exemplo, VTS_PCOLOR é um ponteiro para uma constante VTS_COLOR.

### <a name="requirements"></a>Requisitos

**Header** afxctl.h

## <a name="event_custom_id"></a>  EVENT_CUSTOM_ID

Define um evento disparando a função para um evento personalizado que pertence à ID de expedição especificado por *dispid*.

```cpp
EVENT_CUSTOM_ID(
  pszName,
  dispid,
  pfnFire,
  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*pszName*<br/>
O nome do evento.

*dispid*<br/>
A ID de expedição usada pelo controle ao acionar o evento.

*pfnFire*<br/>
O nome da função de acionamento do evento.

*vtsParams*<br/>
Uma lista de variáveis de parâmetros passada para o contêiner de controle quando o evento é acionado.

### <a name="remarks"></a>Comentários

O *vtsParams* argumento é uma lista separada por espaço de valores da `VTS_` constantes. Um ou mais desses valores separados por espaços, vírgulas não especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#13](../../mfc/codesnippet/cpp/event-maps_2.cpp)]

Especifica a cor de uma lista que contém um inteiro de 32 bits que representa um RGB valor, seguido por um ponteiro para o `IFontDisp` interface de um objeto de fonte OLE.

Para obter uma lista de `VTS_` constantes, consulte [EVENT_CUSTOM](#event_custom).

### <a name="requirements"></a>Requisitos

**Header** afxctl.h

## <a name="on_oleverb"></a>  ON_OLEVERB

Essa macro define uma entrada de mapa de mensagem que mapeia um verbo personalizado para uma função de membro específico do seu controle.

```cpp
ON_OLEVERB(idsVerbName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*idsVerbName*<br/>
A ID de recurso de cadeia de caracteres do nome do verbo.

*memberFxn*<br/>
A função chamada pelo framework quando o verbo é invocado.

### <a name="remarks"></a>Comentários

O editor de recursos pode ser usado para criar nomes de verbos personalizados que são adicionados à sua tabela de cadeia de caracteres.

O protótipo de função para *memberFxn* é:

```cpp
BOOL memberFxn(
   LPMSG    lpMsg,
   HWND     hWndParent,
   LPCRECT  lpRect);
```

Os valores da *lpMsg*, *hWndParent*, e *lpRect* parâmetros são tirados os parâmetros correspondentes do `IOleObject::DoVerb` função de membro.

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxole.h

## <a name="on_stdoleverb"></a>  ON_STDOLEVERB

Use esta macro para substituir o comportamento padrão de um verbo padrão.

```cpp
ON_STDOLEVERB(iVerb, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*iVerb*<br/>
O índice do verbo padrão para o verbo que está sendo substituído.

*memberFxn*<br/>
A função chamada pelo framework quando o verbo é invocado.

### <a name="remarks"></a>Comentários

O índice do verbo padrão está no formato `OLEIVERB_`, seguido por uma ação. OLEIVERB_SHOW, OLEIVERB_HIDE e OLEIVERB_UIACTIVATE são alguns exemplos de verbos padrão.

Ver [ON_OLEVERB](#on_oleverb) para obter uma descrição do protótipo da função a ser usado como o *memberFxn* parâmetro.

### <a name="requirements"></a>Requisitos

**Cabeçalho** afxole.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

---
title: Mapas de coleta de evento
ms.date: 11/04/2016
helpviewer_keywords:
- event sink maps [MFC]
ms.assetid: a9757eb2-5f4a-45ec-a2cd-ce5eec85b16f
ms.openlocfilehash: 731ed2403aae3332e81702673d1181e9e52399a2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365733"
---
# <a name="event-sink-maps"></a>Mapas de coleta de evento

Quando um controle OLE incorporado dispara um evento, o contêiner do controle recebe o evento usando um mecanismo, chamado de "mapa de afundamento de eventos", fornecido pela MFC. Este mapa de sumidouro de eventos designa funções de manipulador para cada evento específico, bem como parâmetros desses eventos. Para obter mais informações sobre mapas de soca de eventos, consulte o artigo [ActiveX Control Containers](../../mfc/activex-control-containers.md).

### <a name="event-sink-maps"></a>Mapas de coleta de evento

|||
|-|-|
|[BEGIN_EVENTSINK_MAP](#begin_eventsink_map)|Inicia a definição de um mapa de afundamento de eventos.|
|[DECLARE_EVENTSINK_MAP](#declare_eventsink_map)|Declara um mapa de afundamento de eventos.|
|[END_EVENTSINK_MAP](#end_eventsink_map)|Termina a definição de um mapa de afundamento de eventos.|
|[ON_EVENT](#on_event)|Define um manipulador de eventos para um evento específico.|
|[ON_EVENT_RANGE](#on_event_range)|Define um manipulador de eventos para um evento específico disparado a partir de um conjunto de controles OLE.|
|[ON_EVENT_REFLECT](#on_event_reflect)|Recebe eventos disparados pelo controle antes de serem manuseados pelo contêiner do controle.|
|[ON_PROPNOTIFY](#on_propnotify)|Define um manipulador para lidar com notificações de propriedade a partir de um controle OLE.|
|[ON_PROPNOTIFY_RANGE](#on_propnotify_range)|Define um manipulador para lidar com notificações de propriedade a partir de um conjunto de controles OLE.|
|[ON_PROPNOTIFY_REFLECT](#on_propnotify_reflect)|Recebe notificações de propriedade enviadas pelo controle antes de serem tratadas pelo contêiner do controle.|

## <a name="begin_eventsink_map"></a><a name="begin_eventsink_map"></a>BEGIN_EVENTSINK_MAP

Começa a definição do seu mapa de afundamento de eventos.

```
BEGIN_EVENTSINK_MAP(theClass, baseClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe de controle cujo mapa de sumidouro de eventos é este.

*Baseclass*<br/>
Especifica o nome da classe base *doClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (.cpp) que define as funções do membro para sua classe, inicie o mapa do sapateador de eventos com a BEGIN_EVENTSINK_MAP macro, adicione entradas de macro para cada evento a ser notificado e complete o mapa do sumidouro de eventos com a macro END_EVENTSINK_MAP.

Para obter mais informações sobre mapas de sumidouros de eventos e recipientes de controle OLE, consulte o artigo [ActiveX Control Containers](../../mfc/activex-control-containers.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="declare_eventsink_map"></a><a name="declare_eventsink_map"></a>DECLARE_EVENTSINK_MAP

Um contêiner OLE pode fornecer um mapa de sumidouro de eventos para especificar os eventos dos quais seu contêiner será notificado.

```
DECLARE_EVENTSINK_MAP()
```

### <a name="remarks"></a>Comentários

Use a DECLARE_EVENTSINK_MAP macro no final da declaração da sua classe. Então, no. Arquivo CPP que define as funções do membro para a classe, usar o BEGIN_EVENTSINK_MAP macro, entradas de macro para cada um dos eventos a serem notificados e a END_EVENTSINK_MAP macro para declarar o fim da lista de funções de evento.

Para obter mais informações sobre mapas de soca de eventos, consulte o artigo [ActiveX Control Containers](../../mfc/activex-control-containers.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxwin.h

## <a name="end_eventsink_map"></a><a name="end_eventsink_map"></a>END_EVENTSINK_MAP

Termina a definição do seu mapa de afundamento de eventos.

```
END_EVENTSINK_MAP()
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="on_event"></a><a name="on_event"></a>ON_EVENT

Use a macro ON_EVENT para definir uma função de manipulador de eventos para um evento disparado por um controle OLE.

```
ON_EVENT(theClass, id, dispid, pfnHandler,  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe a que este evento afunda mapa pertence.

*id*<br/>
O ID de controle do controle OLE.

*Dispid*<br/>
A id de despacho do evento disparada pelo controle.

*pfnHandler*<br/>
Pointer para uma função de membro que lida com o evento. Esta função deve ter um tipo de retorno BOOL e tipos de parâmetros que correspondam aos parâmetros do evento (ver *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; caso contrário, FALSO.

*Vtsparams*<br/>
Uma seqüência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Estas são as mesmas constantes que são usadas em entradas de mapa de despacho, como DISP_FUNCTION.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados pelo espaço das **VTS_** constantes. Um ou mais desses valores separados por espaços (não commas) especifica míseros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

especifica uma lista contendo um inteiro curto seguido de um BOOL.

Para uma lista das constantes **VTS_,** consulte [EVENT_CUSTOM](event-maps.md#event_custom).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="on_event_range"></a><a name="on_event_range"></a>ON_EVENT_RANGE

Use a ON_EVENT_RANGE macro para definir uma função de manipulador de eventos para um evento acionado por qualquer controle OLE com um ID de controle dentro de uma gama contígua de IDs.

```
ON_EVENT_RANGE(theClass, idFirst, idLast, dispid, pfnHandler,  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe a que este evento afunda mapa pertence.

*idFirst*<br/>
O ID de controle do primeiro controle OLE na gama.

*idLast*<br/>
O ID de controle do último controle OLE na faixa.

*Dispid*<br/>
A id de despacho do evento disparada pelo controle.

*pfnHandler*<br/>
Pointer para uma função de membro que lida com o evento. Esta função deve ter um tipo de retorno BOOL, um primeiro parâmetro do tipo UINT (para o ID de controle) e tipos de parâmetros adicionais que correspondem aos parâmetros do evento (ver *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; caso contrário, FALSO.

*Vtsparams*<br/>
Uma seqüência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. A primeira constante deve ser de tipo VTS_I4, para o id de controle. Estas são as mesmas constantes que são usadas em entradas de mapa de despacho, como DISP_FUNCTION.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados pelo espaço das **VTS_** constantes. Um ou mais desses valores separados por espaços (não commas) especifica míseros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

especifica uma lista contendo um inteiro curto seguido de um BOOL.

Para uma lista das constantes **VTS_,** consulte [EVENT_CUSTOM](event-maps.md#event_custom).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra um manipulador de eventos, para o evento MouseDown, implementado para três controles ( IDC_MYCTRL1 através de IDC_MYCTRL3). A função manipuladora de eventos, `OnRangeMouseDown`é declarada no `CMyDlg`arquivo de cabeçalho da classe de diálogo ( ) como:

[!code-cpp[NVC_MFCAutomation#12](../../mfc/codesnippet/cpp/event-sink-maps_2.h)]

O código abaixo é definido no arquivo de implementação da classe de diálogo.

[!code-cpp[NVC_MFCAutomation#13](../../mfc/codesnippet/cpp/event-sink-maps_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="on_event_reflect"></a><a name="on_event_reflect"></a>ON_EVENT_REFLECT

A macro ON_EVENT_REFLECT, quando usada no mapa de sumidouro de eventos da classe de invólucro de um controle OLE, recebe eventos disparados pelo controle antes de serem manuseados pelo recipiente do controle.

```
ON_EVENT_REFLECT(theClass,  dispid, pfnHandler,  vtsParams)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe a que este evento afunda mapa pertence.

*Dispid*<br/>
A id de despacho do evento disparada pelo controle.

*pfnHandler*<br/>
Pointer para uma função de membro que lida com o evento. Esta função deve ter um tipo de retorno BOOL e tipos de parâmetros que correspondam aos parâmetros do evento (ver *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; caso contrário, FALSO.

*Vtsparams*<br/>
Uma seqüência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Estas são as mesmas constantes que são usadas em entradas de mapa de despacho, como DISP_FUNCTION.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados pelo espaço das **VTS_** constantes.

Um ou mais desses valores separados por espaços (não commas) especifica míseros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

especifica uma lista contendo um inteiro curto seguido de um BOOL.

Para uma lista das constantes **VTS_,** consulte [EVENT_CUSTOM](event-maps.md#event_custom).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="on_propnotify"></a><a name="on_propnotify"></a>ON_PROPNOTIFY

Use a ON_PROPNOTIFY macro para definir uma entrada de mapa de sumidouro de eventos para lidar com notificações de propriedade a partir de um controle OLE.

```
ON_PROPNOTIFY(theClass, id, dispid, pfnRequest, pfnChanged)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe a que este evento afunda mapa pertence.

*id*<br/>
O ID de controle do controle OLE.

*Dispid*<br/>
A id de despacho do imóvel envolvido na notificação.

*pfnRequest*<br/>
Pointer para uma função de `OnRequestEdit` membro que lida com a notificação desta propriedade. Esta função deve ter um tipo de retorno BOOL e um parâmetro **BOOL.** <strong>\*</strong> Esta função deve definir o parâmetro como TRUE para permitir que a propriedade mude e FALSE não permita. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSO.

*pfnChanged*<br/>
Pointer para uma função de `OnChanged` membro que lida com a notificação desta propriedade. A função deve ter um tipo de retorno BOOL e um parâmetro UINT. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados pelo espaço das **VTS_** constantes. Um ou mais desses valores separados por espaços (não commas) especifica míseros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

especifica uma lista contendo um inteiro curto seguido de um BOOL.

Para uma lista das constantes **VTS_,** consulte [EVENT_CUSTOM](event-maps.md#event_custom).

## <a name="on_propnotify_range"></a><a name="on_propnotify_range"></a>ON_PROPNOTIFY_RANGE

Use a macro ON_PROPNOTIFY_RANGE para definir uma entrada de mapa de sumidouro de eventos para lidar com notificações de propriedade de qualquer controle OLE com um ID de controle dentro de uma gama contígua de IDs.

```

ON_PROPNOTIFY_RANGE(theClass, idFirst, idLast, dispid, pfnRequest, pfnChanged)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe a que este evento afunda mapa pertence.

*idFirst*<br/>
O ID de controle do primeiro controle OLE na gama.

*idLast*<br/>
O ID de controle do último controle OLE na faixa.

*Dispid*<br/>
A id de despacho do imóvel envolvido na notificação.

*pfnRequest*<br/>
Pointer para uma função de `OnRequestEdit` membro que lida com a notificação desta propriedade. Esta função deve `BOOL` ter `UINT` um `BOOL*` tipo de retorno e parâmetros. A função deve definir o parâmetro como TRUE para permitir que a propriedade mude e FALSE não permita. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSO.

*pfnChanged*<br/>
Pointer para uma função de `OnChanged` membro que lida com a notificação desta propriedade. A função deve `BOOL` ter um `UINT` tipo de retorno e um parâmetro. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSO.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="on_propnotify_reflect"></a><a name="on_propnotify_reflect"></a>ON_PROPNOTIFY_REFLECT

O ON_PROPNOTIFY_REFLECT macro, quando usado no mapa de sumidouro de eventos da classe de invólucro de um controle OLE, recebe notificações de propriedade enviadas pelo controle antes de serem manuseadas pelo contêiner do controle.

```

ON_PROPNOTIFY_REFLECT(theClass, dispid, pfnRequest, pfnChanged)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe a que este evento afunda mapa pertence.

*Dispid*<br/>
A id de despacho do imóvel envolvido na notificação.

*pfnRequest*<br/>
Pointer para uma função de `OnRequestEdit` membro que lida com a notificação desta propriedade. Esta função deve ter um tipo de retorno BOOL e um parâmetro **BOOL.** <strong>\*</strong> Esta função deve definir o parâmetro como TRUE para permitir que a propriedade mude e FALSE não permita. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSO.

*pfnChanged*<br/>
Pointer para uma função de `OnChanged` membro que lida com a notificação desta propriedade. A função deve ter um tipo de retorno BOOL e sem parâmetros. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSO.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

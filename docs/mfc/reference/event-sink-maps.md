---
title: Mapas de coleta de evento
ms.date: 11/04/2016
helpviewer_keywords:
- event sink maps [MFC]
ms.assetid: a9757eb2-5f4a-45ec-a2cd-ce5eec85b16f
ms.openlocfilehash: 2cbfbc70ae14ccda95c377cb1587bf9d2a1ad3e6
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837258"
---
# <a name="event-sink-maps"></a>Mapas de coleta de evento

Quando um controle OLE inserido dispara um evento, o contêiner do controle recebe o evento usando um mecanismo, chamado de "mapa do coletor de eventos", fornecido pelo MFC. Esse mapa de coletor de eventos designa funções de manipulador para cada evento específico, bem como parâmetros desses eventos. Para obter mais informações sobre mapas de coletor de eventos, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).

### <a name="event-sink-maps"></a>Mapas de coleta de evento

|Nome|Descrição|
|-|-|
|[BEGIN_EVENTSINK_MAP](#begin_eventsink_map)|Inicia a definição de um mapa de coletor de eventos.|
|[DECLARE_EVENTSINK_MAP](#declare_eventsink_map)|Declara um mapa de coletor de eventos.|
|[END_EVENTSINK_MAP](#end_eventsink_map)|Finaliza a definição de um mapa de coletor de eventos.|
|[ON_EVENT](#on_event)|Define um manipulador de eventos para um evento específico.|
|[ON_EVENT_RANGE](#on_event_range)|Define um manipulador de eventos para um evento específico acionado de um conjunto de controles OLE.|
|[ON_EVENT_REFLECT](#on_event_reflect)|Recebe eventos acionados pelo controle antes de serem manipulados pelo contêiner do controle.|
|[ON_PROPNOTIFY](#on_propnotify)|Define um manipulador para manipular notificações de propriedade de um controle OLE.|
|[ON_PROPNOTIFY_RANGE](#on_propnotify_range)|Define um manipulador para manipular notificações de propriedade de um conjunto de controles OLE.|
|[ON_PROPNOTIFY_REFLECT](#on_propnotify_reflect)|Recebe notificações de propriedade enviadas pelo controle antes de serem manipuladas pelo contêiner do controle.|

## <a name="begin_eventsink_map"></a><a name="begin_eventsink_map"></a> BEGIN_EVENTSINK_MAP

Inicia a definição do seu mapa de coletor de eventos.

```
BEGIN_EVENTSINK_MAP(theClass, baseClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe de controle cujo evento de coletor de eventos é mapeado.

*baseClass*<br/>
Especifica o nome da classe base da *classe*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para sua classe, inicie o mapa do coletor de eventos com a macro BEGIN_EVENTSINK_MAP e, em seguida, adicione entradas de macro para cada evento a ser notificado e conclua o mapa do coletor de eventos com a macro END_EVENTSINK_MAP.

Para obter mais informações sobre mapas de coletor de eventos e contêineres de controle OLE, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="declare_eventsink_map"></a><a name="declare_eventsink_map"></a> DECLARE_EVENTSINK_MAP

Um contêiner OLE pode fornecer um mapa de coletor de eventos para especificar os eventos dos quais o contêiner será notificado.

```
DECLARE_EVENTSINK_MAP()
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_EVENTSINK_MAP no final da declaração de sua classe. Em seguida, no. O arquivo CPP que define as funções de membro para a classe, use a macro BEGIN_EVENTSINK_MAP, entradas de macro para cada um dos eventos a serem notificados e a macro END_EVENTSINK_MAP para declarar o final da lista de coletores de eventos.

Para obter mais informações sobre mapas de coletor de eventos, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** Afxwin. h

## <a name="end_eventsink_map"></a><a name="end_eventsink_map"></a> END_EVENTSINK_MAP

Finaliza a definição do seu mapa de coletor de eventos.

```
END_EVENTSINK_MAP()
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="on_event"></a><a name="on_event"></a> ON_EVENT

Use a macro ON_EVENT para definir uma função de manipulador de eventos para um evento disparado por um controle OLE.

```
ON_EVENT(theClass, id, dispid, pfnHandler,  vtsParams)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe à qual este mapa do coletor de eventos pertence.

*id*<br/>
A ID de controle do controle OLE.

*DISPID*<br/>
A ID de expedição do evento disparado pelo controle.

*pfnHandler*<br/>
Ponteiro para uma função de membro que manipula o evento. Essa função deve ter um tipo de retorno BOOL e tipos de parâmetro que correspondam aos parâmetros do evento (consulte *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; caso contrário, FALSE.

*vtsParams*<br/>
Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Essas são as mesmas constantes que são usadas em entradas de mapa de expedição, como DISP_FUNCTION.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados por espaços das constantes **VTS_** . Um ou mais desses valores separados por espaços (e não por vírgulas) especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

Especifica uma lista que contém um inteiro curto seguido por um BOOL.

Para obter uma lista das constantes de **VTS_** , consulte [EVENT_CUSTOM](event-maps.md#event_custom).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="on_event_range"></a><a name="on_event_range"></a> ON_EVENT_RANGE

Use a macro ON_EVENT_RANGE para definir uma função de manipulador de eventos para um evento disparado por qualquer controle OLE que tenha uma ID de controle dentro de um intervalo contíguo de IDs.

```
ON_EVENT_RANGE(theClass, idFirst, idLast, dispid, pfnHandler,  vtsParams)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe à qual este mapa do coletor de eventos pertence.

*idFirst*<br/>
A ID de controle do primeiro controle OLE no intervalo.

*idLast*<br/>
A ID de controle do último controle OLE no intervalo.

*DISPID*<br/>
A ID de expedição do evento disparado pelo controle.

*pfnHandler*<br/>
Ponteiro para uma função de membro que manipula o evento. Essa função deve ter um tipo de retorno BOOL, um primeiro parâmetro do tipo UINT (para a ID de controle) e tipos de parâmetro adicionais que correspondem aos parâmetros do evento (consulte *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; caso contrário, FALSE.

*vtsParams*<br/>
Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. A primeira constante deve ser do tipo VTS_I4, para a ID de controle. Essas são as mesmas constantes que são usadas em entradas de mapa de expedição, como DISP_FUNCTION.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados por espaços das constantes **VTS_** . Um ou mais desses valores separados por espaços (e não por vírgulas) especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

Especifica uma lista que contém um inteiro curto seguido por um BOOL.

Para obter uma lista das constantes de **VTS_** , consulte [EVENT_CUSTOM](event-maps.md#event_custom).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra um manipulador de eventos, para o evento MouseDown, implementado para três controles (IDC_MYCTRL1 por meio de IDC_MYCTRL3). A função do manipulador de eventos, `OnRangeMouseDown` , é declarada no arquivo de cabeçalho da classe da caixa de diálogo ( `CMyDlg` ) como:

[!code-cpp[NVC_MFCAutomation#12](../../mfc/codesnippet/cpp/event-sink-maps_2.h)]

O código a seguir é definido no arquivo de implementação da classe DIALOG.

[!code-cpp[NVC_MFCAutomation#13](../../mfc/codesnippet/cpp/event-sink-maps_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="on_event_reflect"></a><a name="on_event_reflect"></a> ON_EVENT_REFLECT

A macro ON_EVENT_REFLECT, quando usada no mapa do coletor de eventos da classe wrapper de um controle OLE, recebe eventos acionados pelo controle antes de serem manipulados pelo contêiner do controle.

```
ON_EVENT_REFLECT(theClass,  dispid, pfnHandler,  vtsParams)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe à qual este mapa do coletor de eventos pertence.

*DISPID*<br/>
A ID de expedição do evento disparado pelo controle.

*pfnHandler*<br/>
Ponteiro para uma função de membro que manipula o evento. Essa função deve ter um tipo de retorno BOOL e tipos de parâmetro que correspondam aos parâmetros do evento (consulte *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; caso contrário, FALSE.

*vtsParams*<br/>
Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Essas são as mesmas constantes que são usadas em entradas de mapa de expedição, como DISP_FUNCTION.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados por espaços das constantes **VTS_** .

Um ou mais desses valores separados por espaços (e não por vírgulas) especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

Especifica uma lista que contém um inteiro curto seguido por um BOOL.

Para obter uma lista das constantes de **VTS_** , consulte [EVENT_CUSTOM](event-maps.md#event_custom).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="on_propnotify"></a><a name="on_propnotify"></a> ON_PROPNOTIFY

Use a macro ON_PROPNOTIFY para definir uma entrada de mapa de coletor de eventos para manipular notificações de propriedade de um controle OLE.

```
ON_PROPNOTIFY(theClass, id, dispid, pfnRequest, pfnChanged)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe à qual este mapa do coletor de eventos pertence.

*id*<br/>
A ID de controle do controle OLE.

*DISPID*<br/>
A ID de expedição da propriedade envolvida na notificação.

*pfnRequest*<br/>
Ponteiro para uma função de membro que manipula a `OnRequestEdit` notificação para essa propriedade. Essa função deve ter um tipo de retorno BOOL e um parâmetro **bool** <strong>\*</strong> . Essa função deve definir o parâmetro como TRUE para permitir que a propriedade seja alterada e FALSE para não permitir. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSE.

*pfnChanged*<br/>
Ponteiro para uma função de membro que manipula a `OnChanged` notificação para essa propriedade. A função deve ter um tipo de retorno BOOL e um parâmetro UINT. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O argumento *vtsParams* é uma lista de valores separados por espaços das constantes **VTS_** . Um ou mais desses valores separados por espaços (e não por vírgulas) especifica a lista de parâmetros da função. Por exemplo:

[!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]

Especifica uma lista que contém um inteiro curto seguido por um BOOL.

Para obter uma lista das constantes de **VTS_** , consulte [EVENT_CUSTOM](event-maps.md#event_custom).

## <a name="on_propnotify_range"></a><a name="on_propnotify_range"></a> ON_PROPNOTIFY_RANGE

Use a macro ON_PROPNOTIFY_RANGE para definir uma entrada de mapa de coletor de eventos para tratamento de notificações de propriedade de qualquer controle OLE que tenha uma ID de controle dentro de um intervalo contíguo de IDs.

```

ON_PROPNOTIFY_RANGE(theClass, idFirst, idLast, dispid, pfnRequest, pfnChanged)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe à qual este mapa do coletor de eventos pertence.

*idFirst*<br/>
A ID de controle do primeiro controle OLE no intervalo.

*idLast*<br/>
A ID de controle do último controle OLE no intervalo.

*DISPID*<br/>
A ID de expedição da propriedade envolvida na notificação.

*pfnRequest*<br/>
Ponteiro para uma função de membro que manipula a `OnRequestEdit` notificação para essa propriedade. Essa função deve ter um `BOOL` tipo de retorno `UINT` e `BOOL*` parâmetros e. A função deve definir o parâmetro como TRUE para permitir que a propriedade seja alterada e FALSE para não permitir. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSE.

*pfnChanged*<br/>
Ponteiro para uma função de membro que manipula a `OnChanged` notificação para essa propriedade. A função deve ter um `BOOL` tipo de retorno e um `UINT` parâmetro. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSE.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="on_propnotify_reflect"></a><a name="on_propnotify_reflect"></a> ON_PROPNOTIFY_REFLECT

A macro ON_PROPNOTIFY_REFLECT, quando usada no mapa do coletor de eventos da classe wrapper de um controle OLE, recebe notificações de propriedade enviadas pelo controle antes de serem manipuladas pelo contêiner do controle.

```

ON_PROPNOTIFY_REFLECT(theClass, dispid, pfnRequest, pfnChanged)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
A classe à qual este mapa do coletor de eventos pertence.

*DISPID*<br/>
A ID de expedição da propriedade envolvida na notificação.

*pfnRequest*<br/>
Ponteiro para uma função de membro que manipula a `OnRequestEdit` notificação para essa propriedade. Essa função deve ter um tipo de retorno BOOL e um parâmetro **bool** <strong>\*</strong> . Essa função deve definir o parâmetro como TRUE para permitir que a propriedade seja alterada e FALSE para não permitir. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSE.

*pfnChanged*<br/>
Ponteiro para uma função de membro que manipula a `OnChanged` notificação para essa propriedade. A função deve ter um tipo de retorno BOOL e nenhum parâmetro. A função deve retornar TRUE para indicar que a notificação foi tratada; caso contrário, FALSE.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

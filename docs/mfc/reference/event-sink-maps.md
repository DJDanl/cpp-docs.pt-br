---
title: Mapas do coletor de eventos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- event sink maps [MFC]
ms.assetid: a9757eb2-5f4a-45ec-a2cd-ce5eec85b16f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 309474220f081a0eca67d0f83ead21c59eb649e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="event-sink-maps"></a>Mapas de coleta de evento
Quando um controle OLE inserido dispara um evento, o contêiner do controle recebe o evento usando um mecanismo chamado um "mapa coletor de evento," fornecido pelo MFC. Este mapa de coletor de evento designa funções de manipulador para cada evento específico, bem como os parâmetros dos eventos. Para obter mais informações sobre mapas de coleta de eventos, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).  
  
### <a name="event-sink-maps"></a>Mapas de coleta de evento  
  
|||  
|-|-|  
|[BEGIN_EVENTSINK_MAP](#begin_eventsink_map)|Inicia a definição de um mapa de coletor de eventos.|  
|[DECLARE_EVENTSINK_MAP](#declare_eventsink_map)|Declara um mapa de coletor de eventos.|  
|[END_EVENTSINK_MAP](#end_eventsink_map)|Finaliza a definição de um mapa de coletor de eventos.|  
|[ON_EVENT](#on_event)|Define um manipulador de eventos para um evento específico.|  
|[ON_EVENT_RANGE](#on_event_range)|Define um manipulador de eventos para um evento específico acionado a partir de um conjunto de controles OLE.|  
|[ON_EVENT_REFLECT](#on_event_reflect)|Recebe eventos disparados pelo controle antes que elas são manipuladas pelo contêiner do controle.|  
|[ON_PROPNOTIFY](#on_propnotify)|Define um manipulador para tratar notificações de propriedade de um controle OLE.|  
|[ON_PROPNOTIFY_RANGE](#on_propnotify_range)|Define um manipulador para tratar notificações de propriedade de um conjunto de controles OLE.|  
|[ON_PROPNOTIFY_REFLECT](#on_propnotify_reflect)|Recebe notificações de propriedade enviadas pelo controle antes que elas são manipuladas pelo contêiner do controle.|  
  
##  <a name="begin_eventsink_map"></a>BEGIN_EVENTSINK_MAP  
 Começa a definição de seu mapa de coletor de eventos.  
  
```   
BEGIN_EVENTSINK_MAP(theClass, baseClass)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe de controle cujo coletor de eventos mapeá-la.  
  
 `baseClass`  
 Especifica o nome da classe base do `theClass`.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, inicie o mapa de coletor de evento com o `BEGIN_EVENTSINK_MAP` macro, em seguida, adicionar entradas de macro para cada evento para ser notificado sobre e concluir o mapa de coletor de evento com o `END_EVENTSINK_MAP` macro.  
  
 Para obter mais informações sobre mapas de coleta de eventos e os contêineres de controle OLE, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="declare_eventsink_map"></a>DECLARE_EVENTSINK_MAP  
 Um contêiner OLE pode fornecer um mapa de coletor de eventos para especificar os eventos que o contêiner será notificado.  
  
```   
DECLARE_EVENTSINK_MAP()   
```  
  
### <a name="remarks"></a>Comentários  
 Use o `DECLARE_EVENTSINK_MAP` macro no final da sua declaração de classe. Em seguida, no. Funções de arquivo CPP que define o membro da classe, use o `BEGIN_EVENTSINK_MAP` macro, entradas de macro para cada um dos eventos a ser notificado e o `END_EVENTSINK_MAP` macro para declarar o final da lista de coletor de eventos.  
  
 Para obter mais informações sobre mapas de coleta de eventos, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin.h  
  
##  <a name="end_eventsink_map"></a>END_EVENTSINK_MAP  
 Finaliza a definição de seu mapa de coletor de eventos.  
  
```   
END_EVENTSINK_MAP()   
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_event"></a>ON_EVENT  
 Use o `ON_EVENT` macro para definir uma função de manipulador de eventos para um evento acionado por um controle OLE.  
  
```   
ON_EVENT(theClass, id, dispid, pfnHandler,  vtsParams) 
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe à qual pertence este mapa de coletor de eventos.  
  
 `id`  
 A ID do controle do controle OLE.  
  
 `dispid`  
 A ID do evento disparado pelo controle de distribuição.  
  
 `pfnHandler`  
 Ponteiro para uma função de membro que manipula o evento. Essa função deve ter uma **BOOL** tipo de retorno e tipos de parâmetro que corresponderem aos parâmetros do evento (consulte `vtsParams`). A função deve retornar **TRUE** para indicar que o evento foi tratada; caso contrário **FALSE**.  
  
 `vtsParams`  
 Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Essas são as constantes mesmo que são usadas nas entradas de mapa de expedição como `DISP_FUNCTION`.  
  
### <a name="remarks"></a>Comentários  
 O `vtsParams` argumento é uma lista separada dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um valor de inteiro curto seguido por um **BOOL**.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_event_range"></a>ON_EVENT_RANGE  
 Use o `ON_EVENT_RANGE` macro para definir uma função de manipulador de eventos para um evento acionado por qualquer outro controle OLE com uma ID de controle dentro de um intervalo de IDs contíguos.  
  
```   
ON_EVENT_RANGE(theClass, idFirst, idLast, dispid, pfnHandler,  vtsParams)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe à qual pertence este mapa de coletor de eventos.  
  
 `idFirst`  
 A ID de controle do primeiro controle OLE no intervalo.  
  
 `idLast`  
 A ID do controle do controle OLE último no intervalo.  
  
 `dispid`  
 A ID do evento disparado pelo controle de distribuição.  
  
 `pfnHandler`  
 Ponteiro para uma função de membro que manipula o evento. Essa função deve ter uma **BOOL** tipo, um primeiro parâmetro de tipo de retorno **UINT** (para a ID de controle) e tipos de parâmetros adicionais que corresponderem aos parâmetros do evento (consulte `vtsParams`). A função deve retornar **TRUE** para indicar que o evento foi tratada; caso contrário **FALSE**.  
  
 `vtsParams`  
 Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. A primeira constante deve ser do tipo **VTS_I4**, para a ID do controle. Essas são as constantes mesmo que são usadas nas entradas de mapa de expedição como `DISP_FUNCTION`.  
  
### <a name="remarks"></a>Comentários  
 O `vtsParams` argumento é uma lista separada dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um valor de inteiro curto seguido por um **BOOL**.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra um manipulador de eventos, o evento MouseDown, implementado para os três controles ( `IDC_MYCTRL1` por meio de `IDC_MYCTRL3`). A função de manipulador de eventos, `OnRangeMouseDown`, é declarado no arquivo de cabeçalho da classe de caixa de diálogo ( `CMyDlg`) como:  
  
 [!code-cpp[NVC_MFCAutomation#12](../../mfc/codesnippet/cpp/event-sink-maps_2.h)]  
  
 O código a seguir é definido no arquivo de implementação da classe de caixa de diálogo.  
  
 [!code-cpp[NVC_MFCAutomation#13](../../mfc/codesnippet/cpp/event-sink-maps_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_event_reflect"></a>ON_EVENT_REFLECT  
 O `ON_EVENT_REFLECT` macro, quando usada no evento mapa coletor da classe de invólucro de um controle OLE, recebe eventos disparados pelo controle antes que elas são manipuladas pelo contêiner do controle.  
  
```   
ON_EVENT_REFLECT(theClass,  dispid, pfnHandler,  vtsParams) 
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe à qual pertence este mapa de coletor de eventos.  
  
 DISPID  
 A ID do evento disparado pelo controle de distribuição.  
  
 `pfnHandler`  
 Ponteiro para uma função de membro que manipula o evento. Essa função deve ter uma **BOOL** tipo de retorno e os tipos de parâmetro que corresponderem aos parâmetros do evento (consulte `vtsParams`). A função deve retornar **TRUE** para indicar que o evento foi tratada; caso contrário **FALSE**.  
  
 `vtsParams`  
 Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Essas são as constantes mesmo que são usadas nas entradas de mapa de expedição como `DISP_FUNCTION`.  
  
### <a name="remarks"></a>Comentários  
 O `vtsParams` argumento é uma lista separada dos valores a **VTS_** constantes.  
  
 Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um valor de inteiro curto seguido por um **BOOL**.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_propnotify"></a>ON_PROPNOTIFY  
 Use o `ON_PROPNOTIFY` macro para definir uma entrada de mapa do coletor de eventos para lidar com notificações de propriedade de um controle OLE.  
  
```   
ON_PROPNOTIFY(theClass, id, dispid, pfnRequest, pfnChanged)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe à qual pertence este mapa de coletor de eventos.  
  
 `id`  
 A ID do controle do controle OLE.  
  
 `dispid`  
 A ID de expedição da propriedade envolvida na notificação.  
  
 `pfnRequest`  
 Ponteiro para uma função de membro que manipula o **OnRequestEdit** notificação para esta propriedade. Essa função deve ter uma **BOOL** tipo de retorno e um **BOOL\***  parâmetro. Essa função deve definir o parâmetro **TRUE** para permitir que a propriedade a ser alterada e **FALSE** para não permitir. A função deve retornar **TRUE** para indicar que a notificação foi tratada; caso contrário **FALSE**.  
  
 `pfnChanged`  
 Ponteiro para uma função de membro que manipula o **OnChanged** notificação para esta propriedade. A função deve ter uma **BOOL** tipo de retorno e um **UINT** parâmetro. A função deve retornar **TRUE** para indicar que a notificação foi tratada; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 O `vtsParams` argumento é uma lista separada dos valores a **VTS_** constantes. Um ou mais desses valores separados por espaços (não vírgulas) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um valor de inteiro curto seguido por um **BOOL**.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
##  <a name="on_propnotify_range"></a>ON_PROPNOTIFY_RANGE  
 Use o `ON_PROPNOTIFY_RANGE` macro para definir uma entrada de mapa do coletor de eventos para lidar com notificações de propriedade do controle OLE com uma ID de controle dentro de um intervalo de IDs contíguos.  
  
```  
 
ON_PROPNOTIFY_RANGE(theClass, idFirst, idLast, dispid, pfnRequest, pfnChanged)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe à qual pertence este mapa de coletor de eventos.  
  
 `idFirst`  
 A ID de controle do primeiro controle OLE no intervalo.  
  
 `idLast`  
 A ID do controle do controle OLE último no intervalo.  
  
 `dispid`  
 A ID de expedição da propriedade envolvida na notificação.  
  
 `pfnRequest`  
 Ponteiro para uma função de membro que manipula o **OnRequestEdit** notificação para esta propriedade. Essa função deve ter uma **BOOL** tipo de retorno e **UINT** e **BOOL\***  parâmetros. A função deve definir o parâmetro **TRUE** para permitir que a propriedade a ser alterada e **FALSE** para não permitir. A função deve retornar **TRUE** para indicar que a notificação foi tratada; caso contrário **FALSE**.  
  
 `pfnChanged`  
 Ponteiro para uma função de membro que manipula o **OnChanged** notificação para esta propriedade. A função deve ter uma **BOOL** tipo de retorno e um **UINT** parâmetro. A função deve retornar **TRUE** para indicar que a notificação foi tratada; caso contrário **FALSE**.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_propnotify_reflect"></a>ON_PROPNOTIFY_REFLECT  
 O `ON_PROPNOTIFY_REFLECT` macro, quando usada no evento mapa coletor da classe de invólucro de um controle OLE, recebe notificações de propriedade enviadas pelo controle antes que elas são manipuladas pelo contêiner do controle.  
  
```  
 
ON_PROPNOTIFY_REFLECT(theClass, dispid, pfnRequest, pfnChanged)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe à qual pertence este mapa de coletor de eventos.  
  
 `dispid`  
 A ID de expedição da propriedade envolvida na notificação.  
  
 `pfnRequest`  
 Ponteiro para uma função de membro que manipula o **OnRequestEdit** notificação para esta propriedade. Essa função deve ter uma **BOOL** tipo de retorno e um **BOOL\***  parâmetro. Essa função deve definir o parâmetro **TRUE** para permitir que a propriedade a ser alterada e **FALSE** para não permitir. A função deve retornar **TRUE** para indicar que a notificação foi tratada; caso contrário **FALSE**.  
  
 `pfnChanged`  
 Ponteiro para uma função de membro que manipula o **OnChanged** notificação para esta propriedade. A função deve ter uma **BOOL** tipo de retorno e sem parâmetros. A função deve retornar **TRUE** para indicar que a notificação foi tratada; caso contrário **FALSE**.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

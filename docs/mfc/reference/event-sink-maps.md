---
title: Mapas do coletor de eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- event sink maps [MFC]
ms.assetid: a9757eb2-5f4a-45ec-a2cd-ce5eec85b16f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0322d6b304366e598fc3db206d4c2e4b9b9d6315
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37336592"
---
# <a name="event-sink-maps"></a>Mapas de coleta de evento
Quando um controle OLE inserido dispara um evento, o contêiner do controle recebe o evento usando um mecanismo chamado de um "mapa coletor de evento," fornecido pelo MFC. Este mapa de coletor de evento designa as funções de manipulador para cada evento específico, bem como os parâmetros desses eventos. Para obter mais informações sobre mapas de coleta de eventos, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).  
  
### <a name="event-sink-maps"></a>Mapas de coleta de evento  
  
|||  
|-|-|  
|[BEGIN_EVENTSINK_MAP](#begin_eventsink_map)|Inicia a definição de um mapa coletor de evento.|  
|[DECLARE_EVENTSINK_MAP](#declare_eventsink_map)|Declara um mapa coletor de evento.|  
|[END_EVENTSINK_MAP](#end_eventsink_map)|Finaliza a definição de um mapa coletor de evento.|  
|[ON_EVENT](#on_event)|Define um manipulador de eventos para um evento específico.|  
|[ON_EVENT_RANGE](#on_event_range)|Define um manipulador de eventos para um evento específico acionado a partir de um conjunto de controles OLE.|  
|[ON_EVENT_REFLECT](#on_event_reflect)|Recebe eventos acionados pelo controle antes que elas são manipuladas pelo contêiner do controle.|  
|[ON_PROPNOTIFY](#on_propnotify)|Define um manipulador para manipular notificações de propriedade de um controle OLE.|  
|[ON_PROPNOTIFY_RANGE](#on_propnotify_range)|Define um manipulador para manipular notificações de propriedade de um conjunto de controles OLE.|  
|[ON_PROPNOTIFY_REFLECT](#on_propnotify_reflect)|Recebe notificações de propriedade enviadas pelo controle antes que elas são manipuladas pelo contêiner do controle.|  
  
##  <a name="begin_eventsink_map"></a>  BEGIN_EVENTSINK_MAP  
 Inicia a definição de seu mapa de coletor de eventos.  
  
```   
BEGIN_EVENTSINK_MAP(theClass, baseClass)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 Especifica o nome da classe do controle cujo coletor de eventos ser mapeado.  
  
 *baseClass*  
 Especifica o nome da classe base da *theClass*.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, iniciar o mapa do coletor de evento com a macro BEGIN_EVENTSINK_MAP, em seguida, adicionar entradas de macro para cada evento ser notificado sobre e concluir o mapa do coletor de evento com a macro END_EVENTSINK_MAP.  
  
 Para obter mais informações sobre mapas de coleta de eventos e os contêineres de controle OLE, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="declare_eventsink_map"></a>  DECLARE_EVENTSINK_MAP  
 Um contêiner OLE pode fornecer um mapa de coletor de eventos para especificar os eventos de que seu contêiner será notificado.  
  
```   
DECLARE_EVENTSINK_MAP()   
```  
  
### <a name="remarks"></a>Comentários  
 Use a macro DECLARE_EVENTSINK_MAP no final de sua declaração de classe. Em seguida, na. Arquivo CPP que define as funções de membro para a classe, use a macro BEGIN_EVENTSINK_MAP, entradas de macro para cada um dos eventos para ser notificado sobre e a macro END_EVENTSINK_MAP para declarar o fim da lista de coletor de eventos.  
  
 Para obter mais informações sobre mapas de coleta de eventos, consulte o artigo [contêineres de controle ActiveX](../../mfc/activex-control-containers.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxwin. h  
  
##  <a name="end_eventsink_map"></a>  END_EVENTSINK_MAP  
 Finaliza a definição de seu mapa de coletor de eventos.  
  
```   
END_EVENTSINK_MAP()   
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_event"></a>  ON_EVENT  
 Use a macro ON_EVENT para definir uma função de manipulador de eventos para um evento acionado por um controle OLE.  
  
```   
ON_EVENT(theClass, id, dispid, pfnHandler,  vtsParams) 
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 A classe à qual pertence este mapa de coletor de evento.  
  
 *id*  
 A ID de controle do controle OLE.  
  
 *DISPID*  
 A ID de expedição do evento disparado pelo controle.  
  
 *pfnHandler*  
 Ponteiro para uma função de membro que manipula o evento. Essa função deve ter um BOOL retornar o tipo e tipos de parâmetro que correspondem aos parâmetros do evento (consulte *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; Caso contrário, FALSE.  
  
 *vtsParams*  
 Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Esses são as mesmas constantes que são usadas em entradas de mapa de expedição como DISP_FUNCTION.  
  
### <a name="remarks"></a>Comentários  
 O *vtsParams* argumento é uma lista separada por espaço de valores da **VTS_** constantes. Um ou mais desses valores separados por espaços (não a vírgula) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um inteiro curto seguido por um BOOL.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_event_range"></a>  ON_EVENT_RANGE  
 Use a macro ON_EVENT_RANGE para definir uma função de manipulador de eventos para um evento acionado por qualquer outro controle OLE ter uma ID de controle dentro de um intervalo de IDs contíguos.  
  
```   
ON_EVENT_RANGE(theClass, idFirst, idLast, dispid, pfnHandler,  vtsParams)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 A classe à qual pertence este mapa de coletor de evento.  
  
 *idFirst*  
 A ID de controle do primeiro controle OLE no intervalo.  
  
 *idLast*  
 A ID de controle do último controle OLE no intervalo.  
  
 *DISPID*  
 A ID de expedição do evento disparado pelo controle.  
  
 *pfnHandler*  
 Ponteiro para uma função de membro que manipula o evento. Essa função deve ter um BOOL tipo de retorno, um primeiro parâmetro do tipo UINT (para a ID de controle) e tipos de parâmetro adicional que correspondem aos parâmetros do evento (consulte *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; Caso contrário, FALSE.  
  
 *vtsParams*  
 Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. A primeira constante deve ser do tipo VTS_I4, para a ID do controle. Esses são as mesmas constantes que são usadas em entradas de mapa de expedição como DISP_FUNCTION.  
  
### <a name="remarks"></a>Comentários  
 O *vtsParams* argumento é uma lista separada por espaço de valores da **VTS_** constantes. Um ou mais desses valores separados por espaços (não a vírgula) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um inteiro curto seguido por um BOOL.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra um manipulador de eventos para o evento MouseDown, implementado para três controles (IDC_MYCTRL1 por meio de IDC_MYCTRL3). A função de manipulador de eventos `OnRangeMouseDown`, é declarado no arquivo de cabeçalho da classe de caixa de diálogo ( `CMyDlg`) como:  
  
 [!code-cpp[NVC_MFCAutomation#12](../../mfc/codesnippet/cpp/event-sink-maps_2.h)]  
  
 O código a seguir é definido no arquivo de implementação da classe de caixa de diálogo.  
  
 [!code-cpp[NVC_MFCAutomation#13](../../mfc/codesnippet/cpp/event-sink-maps_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_event_reflect"></a>  ON_EVENT_REFLECT  
 A macro ON_EVENT_REFLECT, quando usado no evento mapa coletor da classe de wrapper de um controle OLE, recebe eventos acionados pelo controle antes que elas são manipuladas pelo contêiner do controle.  
  
```   
ON_EVENT_REFLECT(theClass,  dispid, pfnHandler,  vtsParams) 
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 A classe à qual pertence este mapa de coletor de evento.  
  
 DISPID  
 A ID de expedição do evento disparado pelo controle.  
  
 *pfnHandler*  
 Ponteiro para uma função de membro que manipula o evento. Essa função deve ter um BOOL retornar o tipo e tipos de parâmetro que correspondem aos parâmetros do evento (consulte *vtsParams*). A função deve retornar TRUE para indicar que o evento foi tratado; Caso contrário, FALSE.  
  
 *vtsParams*  
 Uma sequência de **VTS_** constantes que especifica os tipos dos parâmetros para o evento. Esses são as mesmas constantes que são usadas em entradas de mapa de expedição como DISP_FUNCTION.  
  
### <a name="remarks"></a>Comentários  
 O *vtsParams* argumento é uma lista separada por espaço de valores da **VTS_** constantes.  
  
 Um ou mais desses valores separados por espaços (não a vírgula) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um inteiro curto seguido por um BOOL.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_propnotify"></a>  ON_PROPNOTIFY  
 Use a macro ON_PROPNOTIFY para definir uma entrada de mapa do coletor de eventos para manipular notificações de propriedade de um controle OLE.  
  
```   
ON_PROPNOTIFY(theClass, id, dispid, pfnRequest, pfnChanged)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 A classe à qual pertence este mapa de coletor de evento.  
  
 *id*  
 A ID de controle do controle OLE.  
  
 *DISPID*  
 A ID de expedição da propriedade envolvida na notificação.  
  
 *pfnRequest*  
 Ponteiro para uma função de membro que manipula o `OnRequestEdit` notificação para essa propriedade. Essa função deve ter um BOOL tipo de retorno e um **BOOL\***  parâmetro. Essa função deve definir o parâmetro como TRUE para permitir que a propriedade a alteração e FALSE para não permitir. A função deve retornar TRUE para indicar que a notificação foi tratada; Caso contrário, FALSE.  
  
 *pfnChanged*  
 Ponteiro para uma função de membro que manipula o `OnChanged` notificação para essa propriedade. A função deve ter um BOOL de tipo de retorno e um parâmetro UINT. A função deve retornar TRUE para indicar que a notificação foi tratada; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 O *vtsParams* argumento é uma lista separada por espaço de valores da **VTS_** constantes. Um ou mais desses valores separados por espaços (não a vírgula) Especifica a lista de parâmetros da função. Por exemplo:  
  
 [!code-cpp[NVC_MFCAutomation#11](../../mfc/codesnippet/cpp/event-sink-maps_1.cpp)]  
  
 Especifica uma lista que contém um inteiro curto seguido por um BOOL.  
  
 Para obter uma lista de **VTS_** constantes, consulte [EVENT_CUSTOM](event-maps.md#event_custom).  
  
##  <a name="on_propnotify_range"></a>  ON_PROPNOTIFY_RANGE  
 Use a macro ON_PROPNOTIFY_RANGE para definir uma entrada de mapa do coletor de eventos para manipular notificações de propriedade de qualquer controle OLE ter uma ID de controle dentro de um intervalo de IDs contíguos.  
  
```  
 
ON_PROPNOTIFY_RANGE(theClass, idFirst, idLast, dispid, pfnRequest, pfnChanged)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 A classe à qual pertence este mapa de coletor de evento.  
  
 *idFirst*  
 A ID de controle do primeiro controle OLE no intervalo.  
  
 *idLast*  
 A ID de controle do último controle OLE no intervalo.  
  
 *DISPID*  
 A ID de expedição da propriedade envolvida na notificação.  
  
 *pfnRequest*  
 Ponteiro para uma função de membro que manipula o `OnRequestEdit` notificação para essa propriedade. Essa função deve ter um tipo de retorno de BOOL e UINT e **BOOL\***  parâmetros. A função deve definir o parâmetro como TRUE para permitir que a propriedade a alteração e FALSE para não permitir. A função deve retornar TRUE para indicar que a notificação foi tratada; Caso contrário, FALSE.  
  
 *pfnChanged*  
 Ponteiro para uma função de membro que manipula o `OnChanged` notificação para essa propriedade. A função deve ter um BOOL de tipo de retorno e um parâmetro UINT. A função deve retornar TRUE para indicar que a notificação foi tratada; Caso contrário, FALSE.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="on_propnotify_reflect"></a>  ON_PROPNOTIFY_REFLECT  
 A macro ON_PROPNOTIFY_REFLECT, quando usado no evento mapa coletor da classe de wrapper de um controle OLE, recebe notificações de propriedade enviadas pelo controle antes que elas são manipuladas pelo contêiner do controle.  
  
```  
 
ON_PROPNOTIFY_REFLECT(theClass, dispid, pfnRequest, pfnChanged)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 A classe à qual pertence este mapa de coletor de evento.  
  
 *DISPID*  
 A ID de expedição da propriedade envolvida na notificação.  
  
 *pfnRequest*  
 Ponteiro para uma função de membro que manipula o `OnRequestEdit` notificação para essa propriedade. Essa função deve ter um BOOL tipo de retorno e um **BOOL\***  parâmetro. Essa função deve definir o parâmetro como TRUE para permitir que a propriedade a alteração e FALSE para não permitir. A função deve retornar TRUE para indicar que a notificação foi tratada; Caso contrário, FALSE.  
  
 *pfnChanged*  
 Ponteiro para uma função de membro que manipula o `OnChanged` notificação para essa propriedade. A função deve ter um BOOL sem parâmetros e tipo de retorno. A função deve retornar TRUE para indicar que a notificação foi tratada; Caso contrário, FALSE.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

---
title: Macros de mapa (ATL) da mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlwin/ATL::ALT_MSG_MAP
- atlwin/ATL::BEGIN_MSG_MAP
- atlwin/ATL::CHAIN_MSG_MAP_ALT
- atlwin/ATL::CHAIN_MSG_MAP_ALT_MEMBER
- atlwin/ATL::CHAIN_MSG_MAP
- atlwin/ATL::CHAIN_MSG_MAP_DYNAMIC
- atlwin/ATL::CHAIN_MSG_MAP_MEMBER
- atlwin/ATL::COMMAND_CODE_HANDLER
- atlwin/ATL::COMMAND_HANDLER
- atlwin/ATL::COMMAND_ID_HANDLER
- atlwin/ATL::COMMAND_RANGE_CODE_HANDLER
- atlwin/ATL::COMMAND_RANGE_HANDLER
- atlwin/ATL::DECLARE_EMPTY_MSG_MAP
- atlwin/ATL::DEFAULT_REFLECTION_HANDLER
- atlwin/ATL::END_MSG_MAP
- atlwin/ATL::FORWARD_NOTIFICATIONS
- atlwin/ATL::MESSAGE_HANDLER
- atlwin/ATL::MESSAGE_RANGE_HANDLER
- atlwin/ATL::NOTIFY_CODE_HANDLER
- atlwin/ATL::NOTIFY_HANDLER
- atlwin/ATL::NOTIFY_ID_HANDLER
- atlwin/ATL::NOTIFY_RANGE_CODE_HANDLER
- atlwin/ATL::NOTIFY_RANGE_HANDLER
- atlwin/ATL::REFLECT_NOTIFICATIONS
- atlwin/ATL::REFLECTED_COMMAND_CODE_HANDLER
- atlwin/ATL::REFLECTED_COMMAND_HANDLER
- atlwin/ATL::REFLECTED_COMMAND_ID_HANDLER
- atlwin/ATL::REFLECTED_COMMAND_RANGE_CODE_HANDLER
- atlwin/ATL::REFLECTED_COMMAND_RANGE_HANDLER
- atlwin/ATL::REFLECTED_NOTIFY_CODE_HANDLER
- atlwin/ATL::REFLECTED_NOTIFY_HANDLER
- atlwin/ATL::REFLECTED_NOTIFY_ID_HANDLER
- atlwin/ATL::REFLECTED_NOTIFY_RANGE_CODE_HANDLER
- atlwin/ATL::REFLECTED_NOTIFY_RANGE_HANDLER
dev_langs:
- C++
ms.assetid: eefdd546-8934-4a30-b263-9c06a8addcbd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f026e7b8190b311b16e86673b6f2271637442df0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32366124"
---
# <a name="message-map-macros-atl"></a>Macros de mapa de mensagem (ATL)
Essas macros definem entradas e mapas de mensagem.  
  
|||  
|-|-|  
|[ALT_MSG_MAP](#alt_msg_map)|Marca o início de um mapa de mensagem alternativo.|  
|[BEGIN_MSG_MAP](#begin_msg_map)|Marca o início do mapa de mensagem padrão.|  
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Está ligado a um mapa de mensagem alternativo na classe base.|  
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Está ligado a um mapa de mensagens alternativos em um membro de dados da classe.|  
|[CHAIN_MSG_MAP](#chain_msg_map)|Está ligado a mapa da mensagem padrão na classe base.|  
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Cadeias de para o mapa de mensagem em outra classe em tempo de execução.|  
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Está ligado a mapa da mensagem padrão em um membro de dados da classe.|  
|[COMMAND_CODE_HANDLER](#command_code_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[COMMAND_HANDLER](#command_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base em como o código de notificação e o identificador do item de menu, o controle ou o acelerador.|  
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, o controle ou o acelerador.|  
|[COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[DECLARE_EMPTY_MSG_MAP](#declare_empty_msg_map)|Implementa um mapa de mensagem vazia.|  
|[DEFAULT_REFLECTION_HANDLER](#default_reflection_handler)|Fornece um manipulador padrão para mensagens refletidas que não são manipuladas caso contrário.|  
|[END_MSG_MAP](#end_msg_map)|Marca o fim de um mapa de mensagem.|  
|[FORWARD_NOTIFICATIONS](#forward_notifications)|Encaminha mensagens de notificação para a janela pai.|  
|[MESSAGE_HANDLER](#message_handler)|Uma mensagem do Windows é mapeado para uma função de manipulador.|  
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mensagens de um intervalo contíguo de Windows é mapeado para uma função de manipulador.|  
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[NOTIFY_HANDLER](#notify_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador de controle.|  
|[NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECT_NOTIFICATIONS](#reflect_notifications)|Reflete as mensagens de notificação de volta para a janela que enviaram.|  
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base em como o código de notificação e o identificador do item de menu, o controle ou o acelerador.|  
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, o controle ou o acelerador.|  
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador de controle.|  
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="alt_msg_map"></a>  ALT_MSG_MAP  
 Marca o início de um mapa de mensagem alternativo.  
  
```
ALT_MSG_MAP(msgMapID)
```  
  
### <a name="parameters"></a>Parâmetros  
 `msgMapID`  
 [in] O identificador de mapa de mensagem.  
  
### <a name="remarks"></a>Comentários  
 ATL identifica cada mapa de mensagem por um número. O mapa da mensagem padrão (declarado com o `BEGIN_MSG_MAP` macro) é identificado por 0. Um mapa de mensagem alternativo é identificado pelo `msgMapID`.  
  
 Mapas de mensagem são usados para processar as mensagens enviadas para uma janela. Por exemplo, [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) permite que você especifique o identificador de um mapa de mensagem no objeto que contém. [CContainedWindow::WindowProc](ccontainedwindowt-class.md#windowproc) , em seguida, usa esse mapa de mensagem para direcionar as mensagens da janela independente para a função de manipulador apropriado ou outro mapa de mensagem. Para obter uma lista de macros que declara as funções de manipulador, consulte [BEGIN_MSG_MAP](#begin_msg_map).  
  
 Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes.  
  
 O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Observe que sempre há exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra o mapa de mensagem padrão e o mapa de uma mensagem alternativo, cada um contendo uma função de manipulador:  
  
 [!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]  
  
 O exemplo a seguir mostra dois mapas de mensagem alternativo. O mapa de mensagem padrão é vazio.  
  
 [!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   

##  <a name="begin_msg_map"></a>  BEGIN_MSG_MAP  
 Marca o início do mapa de mensagem padrão.  
  
```
BEGIN_MSG_MAP(theClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 [in] O nome da classe que contém o mapa da mensagem.  
  
### <a name="remarks"></a>Comentários  
 [CWindowImpl::WindowProc](cwindowimpl-class.md#windowproc) usa o mapa da mensagem padrão para processar as mensagens enviadas à janela. O mapa de mensagem direciona as mensagens para a função de manipulador apropriado ou a outro mapa de mensagem.  

  
 As seguintes macros mapeiam uma mensagem para uma função de manipulador. Essa função deve ser definida em `theClass`.  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[MESSAGE_HANDLER](#message_handler)|Uma mensagem do Windows é mapeado para uma função de manipulador.|  
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mensagens de um intervalo contíguo de Windows é mapeado para uma função de manipulador.|  
|[COMMAND_HANDLER](#command_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base em como o código de notificação e o identificador do item de menu, o controle ou o acelerador.|  
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, o controle ou o acelerador.|  
|[COMMAND_CODE_HANDLER](#command_handler)|Mapeia um **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mapeia um intervalo contíguo de **WM_COMMAND** mensagens para uma função de manipulador, com base no identificador do controle, item de menu ou acelerador.|  
|[NOTIFY_HANDLER](#notify_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador de controle.|  
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia um **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia um intervalo contíguo de **WM_NOTIFY** mensagens para uma função de manipulador, com base no identificador de controle.|  
  
 As seguintes macros direcionam mensagens ao outro mapa de mensagem. Esse processo é chamado de "encadeamento".  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[CHAIN_MSG_MAP](#chain_msg_map)|Está ligado a mapa da mensagem padrão na classe base.|  
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Está ligado a mapa da mensagem padrão em um membro de dados da classe.|  
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Está ligado a um mapa de mensagem alternativo na classe base.|  
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Está ligado a um mapa de mensagens alternativos em um membro de dados da classe.|  
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Está ligado a mapa da mensagem padrão em outra classe em tempo de execução.|  
  
 As seguintes macros direcionam "refletidas" mensagens da janela pai. Por exemplo, um controle normalmente envia mensagens de notificação para sua janela pai para processamento, mas a janela pai pode refletir a mensagem de volta para o controle.  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base em como o código de notificação e o identificador do item de menu, o controle ou o acelerador.|  
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, o controle ou o acelerador.|  
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador de controle.|  
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#102](../../atl/codesnippet/cpp/message-map-macros-atl_3.h)]  
  
 Quando um `CMyExtWindow` objeto recebe um `WM_PAINT` mensagem, a mensagem se destina a `CMyExtWindow::OnPaint` para o processamento real. Se `OnPaint` indica a mensagem requer processamento adicional, a mensagem será, em seguida, ser direcionado para o mapa de mensagem padrão em `CMyBaseWindow`.  
  
 Além de mapa de mensagem padrão, você pode definir um mapa de mensagem alternativo com [ALT_MSG_MAP](#alt_msg_map). Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes. O exemplo a seguir mostra o mapa de mensagem padrão e o mapa de uma mensagem alternativo, cada um contendo uma função de manipulador:  
  
 [!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]  
  
 O exemplo a seguir mostra dois mapas de mensagem alternativo. O mapa de mensagem padrão é vazio.  
  
 [!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]  
  
 O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Observe que sempre há exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="chain_msg_map_alt"></a>  CHAIN_MSG_MAP_ALT  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP_ALT(theChainClass, msgMapID)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theChainClass`  
 [in] O nome da classe base que contém o mapa da mensagem.  
  
 `msgMapID`  
 [in] O identificador de mapa de mensagem.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP_ALT` direciona as mensagens para um mapa de mensagem alternativo em uma classe base. Você deve declarar esse mapa de mensagem alternativo com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens ao mapa de mensagem padrão da classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use `CHAIN_MSG_MAP`. Para obter um exemplo, consulte [CHAIN_MSG_MAP](#chain_msg_map).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="chain_msg_map_alt_member"></a>  CHAIN_MSG_MAP_ALT_MEMBER  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theChainMember`  
 [in] O nome do membro de dados que contém o mapa da mensagem.  
  
 `msgMapID`  
 [in] O identificador de mapa de mensagem.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP_ALT_MEMBER` direciona as mensagens para um mapa de mensagem alternativo em um membro de dados. Você deve declarar esse mapa de mensagem alternativo com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar as mensagens para o mapa de mensagem padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use `CHAIN_MSG_MAP_MEMBER`. Para obter um exemplo, consulte [CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="chain_msg_map"></a>  CHAIN_MSG_MAP  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP(theChainClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theChainClass`  
 [in] O nome da classe base que contém o mapa da mensagem.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP` direciona mensagens ao mapa de mensagem padrão da classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar as mensagens para o mapa de mensagem alternativo de classe base (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT](#chain_msg_map_alt).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#107](../../atl/codesnippet/cpp/message-map-macros-atl_4.h)]  
  
 Este exemplo ilustra o seguinte:  
  
-   Se estiver usando um procedimento de janela `CMyClass`do mapa da mensagem padrão e `OnPaint` não identificador de uma mensagem, a mensagem é direcionada para `CMyBaseClass`do mapa de mensagem padrão para processamento.  
  
-   Se um procedimento de janela é usando o mapa de mensagem alternativo primeiro no `CMyClass`, todas as mensagens são direcionadas para `CMyBaseClass`do mapa da mensagem padrão.  
  
-   Se estiver usando um procedimento de janela `CMyClass`da segunda mensagem alternativa do mapa e `OnChar` não identificador de uma mensagem, a mensagem é direcionada para o mapa de mensagem alternativo especificado em `CMyBaseClass`. `CMyBaseClass` deve ter declarado neste mapa de mensagem com `ALT_MSG_MAP(1)`.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="chain_msg_map_dynamic"></a>  CHAIN_MSG_MAP_DYNAMIC  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP_DYNAMIC(dynaChainID)
```  
  
### <a name="parameters"></a>Parâmetros  
 *dynaChainID*  
 [in] O identificador exclusivo para o mapa de mensagem de um objeto.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP_DYNAMIC` direciona as mensagens, em tempo de execução para o mapa de mensagem padrão em outro objeto. O objeto e seu mapa de mensagem associados *dynaChainID*, que você define através de [CDynamicChain::SetChainEntry](cdynamicchain-class.md#setchainentry). Você deve derivar a classe de `CDynamicChain` para usar `CHAIN_MSG_MAP_DYNAMIC`. Para obter um exemplo, consulte o [CDynamicChain](../../atl/reference/cdynamicchain-class.md) visão geral.  

  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="chain_msg_map_member"></a>  CHAIN_MSG_MAP_MEMBER  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP_MEMBER(theChainMember)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theChainMember`  
 [in] O nome do membro de dados que contém o mapa da mensagem.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP_MEMBER` direciona as mensagens para o mapa de mensagem padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens ao mapa de mensagem alternativo de um membro de dados (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#108](../../atl/codesnippet/cpp/message-map-macros-atl_5.h)]  
  
 Este exemplo ilustra o seguinte:  
  
-   Se estiver usando um procedimento de janela `CMyClass`do mapa da mensagem padrão e `OnPaint` não identificador de uma mensagem, a mensagem é direcionada para `m_obj`do mapa de mensagem padrão para processamento.  
  
-   Se um procedimento de janela é usando o mapa de mensagem alternativo primeiro no `CMyClass`, todas as mensagens são direcionadas para `m_obj`do mapa da mensagem padrão.  
  
-   Se estiver usando um procedimento de janela `CMyClass`da segunda mensagem alternativa do mapa e `OnChar` não identificador de uma mensagem, a mensagem é direcionada para o mapa de mensagem alternativo especificado do `m_obj`. Classe `CMyContainedClass` deve ter declarado neste mapa de mensagem com `ALT_MSG_MAP(1)`.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="command_code_handler"></a>  COMMAND_CODE_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia um [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem com base apenas no código de notificação.  
  
```
COMMAND_CODE_HANDLER(code, func)
```  
  
### <a name="parameters"></a>Parâmetros  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="command_handler"></a>  COMMAND_HANDLER  
 Define uma entrada em um mapa de mensagem.  
  
```
COMMAND_HANDLER(id, code, func)
```    
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, o controle ou o acelerador.  
  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 `COMMAND_HANDLER` mapeia um [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem para a função de manipulador especificado, com base no código de notificação e o identificador do controle. Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing#119](../../atl/codesnippet/cpp/message-map-macros-atl_6.h)]  
  
 Qualquer função especificada em um `COMMAND_HANDLER` macro deve ser definida da seguinte maneira:  
  
 `LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);`  
  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `CommandHandler` é chamado. Se `CommandHandler` não totalmente processa a mensagem, ele deve ser definido `bHandled` para **FALSE** para indicar que a mensagem precisa de processamento adicional.  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Além `COMMAND_HANDLER`, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear um **WM_COMMAND** mensagem independentemente de um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_COMMAND, OnHandlerFunction)` direcionará todas **WM_COMMAND** mensagens para `OnHandlerFunction`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="command_id_handler"></a>  COMMAND_ID_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia um [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem base somente o identificador do item de menu, o controle ou o acelerador.  
  
```
COMMAND_ID_HANDLER(id, func)
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, o controle ou o Acelerador de enviar a mensagem.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="command_range_code_handler"></a>  COMMAND_RANGE_CODE_HANDLER  
 Semelhante ao [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagens com um código de notificação específica de uma variedade de controles para uma função de manipulador único.  
  
```
COMMAND_RANGE_CODE_HANDLER(idFirst, idLast, code, func)
```    
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 Esse intervalo baseia-se o identificador do item de menu, o controle ou o Acelerador de enviar a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="command_range_handler"></a>  COMMAND_RANGE_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagens de uma variedade de controles para uma função de manipulador único.  
  
```
COMMAND_RANGE_HANDLER( idFirst, idLast, func)
```    
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 Esse intervalo baseia-se o identificador do item de menu, o controle ou o Acelerador de enviar a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="declare_empty_msg_map"></a>  DECLARE_EMPTY_MSG_MAP  
 Declara um mapa de mensagem vazia.  
  
```
DECLARE_EMPTY_MSG_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 `DECLARE_EMPTY_MSG_MAP` é uma macro de conveniência que chama as macros [BEGIN_MSG_MAP](#begin_msg_map) e [END_MSG_MAP](#end_msg_map) para criar um mapa de mensagem vazia:  
  
 [!code-cpp[NVC_ATL_Windowing#122](../../atl/codesnippet/cpp/message-map-macros-atl_7.h)]  
  
##  <a name="default_reflection_handler"></a>  DEFAULT_REFLECTION_HANDLER  
 Fornece um manipulador para a janela filho (controle) que receberá padrão refletidas mensagens; o manipulador passará corretamente sem tratamento de mensagens para `DefWindowProc`.  
  
```
DEFAULT_REFLECTION_HANDLER()
```  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="end_msg_map"></a>  END_MSG_MAP  
 Marca o fim de um mapa de mensagem.  
  
```
END_MSG_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 Use sempre o [BEGIN_MSG_MAP](#begin_msg_map) macro para marcar o início de um mapa de mensagem. Use [ALT_MSG_MAP](#alt_msg_map) para declarar os mapas de mensagem alternativo subsequentes.  
  
 Observe que sempre há exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra o mapa de mensagem padrão e o mapa de uma mensagem alternativo, cada um contendo uma função de manipulador:  
  
 [!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]  
  
 O exemplo a seguir mostra dois mapas de mensagem alternativo. O mapa de mensagem padrão é vazio.  
  
 [!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="forward_notifications"></a>  FORWARD_NOTIFICATIONS  
 Encaminha mensagens de notificação para a janela pai.  
  
```
FORWARD_NOTIFICATIONS()
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esta macro como parte de seu mapa de mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="message_handler"></a>  MESSAGE_HANDLER  
 Define uma entrada em um mapa de mensagem.  
  
```
MESSAGE_HANDLER( msg, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `msg`  
 [in] A mensagem do Windows.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 `MESSAGE_HANDLER` mapeia uma mensagem do Windows para a função de manipulador especificado.  
  
 Qualquer função especificada em um `MESSAGE_HANDLER` macro deve ser definida da seguinte maneira:  
  
 `LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);`  
  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `MessageHandler` é chamado. Se `MessageHandler` não totalmente processa a mensagem, ele deve ser definido `bHandled` para **FALSE** para indicar que a mensagem precisa de processamento adicional.  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Além `MESSAGE_HANDLER`, você pode usar [COMMAND_HANDLER](#command_handler) e [NOTIFY_HANDLER](#notify_handler) para mapear [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) e [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagens, respectivamente.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#129](../../atl/codesnippet/cpp/message-map-macros-atl_8.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="message_range_handler"></a>  MESSAGE_RANGE_HANDLER  
 Semelhante ao [MESSAGE_HANDLER](#message_handler), mas mapas de mensagens de um intervalo do Windows para uma função de manipulador único.  
  
```
MESSAGE_RANGE_HANDLER( msgFirst, msgLast, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 *msgFirst*  
 [in] Marca o início de um intervalo contíguo de mensagens.  
  
 *msgLast*  
 [in] Marca o fim de um intervalo contíguo de mensagens.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="notify_code_handler"></a>  NOTIFY_CODE_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia um [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem com base apenas no código de notificação.  
  
```
NOTIFY_CODE_HANDLER(cd, func)
```  
  
### <a name="parameters"></a>Parâmetros  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="notify_handler"></a>  NOTIFY_HANDLER  
 Define uma entrada em um mapa de mensagem.  
  
```
NOTIFY_HANDLER( id, cd, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do controle enviar a mensagem.  
  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 `NOTIFY_HANDLER` mapeia um [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem para a função de manipulador especificado, com base no código de notificação e o identificador do controle.  
  
 Qualquer função especificada em um `NOTIFY_HANDLER` macro deve ser definida da seguinte maneira:  
  
 `LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);`  
  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `NotifyHandler` é chamado. Se `NotifyHandler` não totalmente processa a mensagem, ele deve ser definido `bHandled` para **FALSE** para indicar que a mensagem precisa de processamento adicional.  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagem. Cada mapa de mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Além `NOTIFY_HANDLER`, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear um **WM_NOTIFY** mensagem independentemente de um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_NOTIFY, OnHandlerFunction)` direcionará todas **WM_NOTIFY** mensagens para `OnHandlerFunction`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#130](../../atl/codesnippet/cpp/message-map-macros-atl_9.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="notify_id_handler"></a>  NOTIFY_ID_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia um [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem base apenas o identificador do controle.  
  
```
NOTIFY_ID_HANDLER( id, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do controle enviar a mensagem.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="notify_range_code_handler"></a>  NOTIFY_RANGE_CODE_HANDLER  
 Semelhante ao [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagens com um código de notificação específica de uma variedade de controles para uma função de manipulador único.  
  
```
NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 Esse intervalo baseia-se o identificador do controle enviar a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="notify_range_handler"></a>  NOTIFY_RANGE_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagens de uma variedade de controles para uma função de manipulador único.  
  
```
NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 Esse intervalo baseia-se o identificador do controle enviar a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="reflect_notifications"></a>  REFLECT_NOTIFICATIONS  
 Reflete as mensagens de notificação de volta para a janela filho (controle) que enviaram.  
  
```
REFLECT_NOTIFICATIONS()
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esta macro como parte do mapa de mensagem da janela pai.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="reflected_command_code_handler"></a>  REFLECTED_COMMAND_CODE_HANDLER  
 Semelhante ao [COMMAND_CODE_HANDLER](#command_code_handler), mas mapeia comandos refletidos na janela pai.  
  
```
REFLECTED_COMMAND_CODE_HANDLER( code, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
   
##  <a name="reflected_command_handler"></a>  REFLECTED_COMMAND_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia comandos refletidos na janela pai.  
  
```
REFLECTED_COMMAND_HANDLER( id, code, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, o controle ou o acelerador.  
  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_command_id_handler"></a>  REFLECTED_COMMAND_ID_HANDLER  
 Semelhante ao [COMMAND_ID_HANDLER](#command_id_handler), mas mapeia comandos refletidos na janela pai.  
  
```
REFLECTED_COMMAND_ID_HANDLER( id, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, o controle ou o acelerador.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_command_range_code_handler"></a>  REFLECTED_COMMAND_RANGE_CODE_HANDLER  
 Semelhante ao [COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler), mas mapeia comandos refletidos na janela pai.  
  
```
REFLECTED_COMMAND_RANGE_CODE_HANDLER( idFirst, idLast, code, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_command_range_handler"></a>  REFLECTED_COMMAND_RANGE_HANDLER  
 Semelhante ao [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia comandos refletidos na janela pai.  
  
```
REFLECTED_COMMAND_RANGE_HANDLER( idFirst, idLast, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_notify_code_handler"></a>  REFLECTED_NOTIFY_CODE_HANDLER  
 Semelhante ao [NOTIFY_CODE_HANDLER](#notify_code_handler), mas mapeia notificações refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_CODE_HANDLER_EX( cd, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_notify_handler"></a>  REFLECTED_NOTIFY_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia notificações refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_HANDLER( id, cd, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, o controle ou o acelerador.  
  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_notify_id_handler"></a>  REFLECTED_NOTIFY_ID_HANDLER  
 Semelhante ao [NOTIFY_ID_HANDLER](#notify_id_handler), mas mapeia notificações refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_ID_HANDLER( id, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, o controle ou o acelerador.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="reflected_notify_range_code_handler"></a>  REFLECTED_NOTIFY_RANGE_CODE_HANDLER  
 Semelhante ao [NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler), mas mapeia notificações refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```    
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="reflected_notify_range_handler"></a>  REFLECTED_NOTIFY_RANGE_HANDLER  
 Semelhante ao [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia notificações refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `idFirst`  
 [in] Marca o início de um intervalo contíguo de identificadores de controle.  
  
 `idLast`  
 [in] Marca o fim de um intervalo contíguo de identificadores de controle.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

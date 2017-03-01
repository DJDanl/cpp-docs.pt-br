---
title: Macros de mapa (ATL) da mensagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: eefdd546-8934-4a30-b263-9c06a8addcbd
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 8097982d6574af2ce1ba592dbead8abf6f6433df
ms.lasthandoff: 02/25/2017

---
# <a name="message-map-macros-atl"></a>Macros de mapa de mensagem (ATL)
Essas macros definem entradas e mapas de mensagem.  
  
|||  
|-|-|  
|[ALT_MSG_MAP](#alt_msg_map)|Marca o início de um mapa de mensagens alternativos.|  
|[BEGIN_MSG_MAP](#begin_msg_map)|Marca o início do mapa de mensagens padrão.|  
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Está ligado a um mapa de mensagens alternativos na classe base.|  
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Está ligado a um mapa de mensagens alternativos em um membro de dados da classe.|  
|[CHAIN_MSG_MAP](#chain_msg_map)|Cadeias para o mapa da mensagem padrão na classe base.|  
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Cadeias de mapa de mensagens em outra classe em tempo de execução.|  
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Cadeias para o mapa da mensagem padrão em um membro de dados da classe.|  
|[COMMAND_CODE_HANDLER](#command_code_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[COMMAND_HANDLER](#command_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e o identificador do item de menu, controle ou acelerador.|  
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|  
|[COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[DECLARE_EMPTY_MSG_MAP](#declare_empty_msg_map)|Implementa um mapa de mensagem vazia.|  
|[DEFAULT_REFLECTION_HANDLER](#default_reflection_handler)|Fornece um manipulador padrão para mensagens refletidas que não são manipuladas caso contrário.|  
|[END_MSG_MAP](#end_msg_map)|Marca o fim de um mapa de mensagem.|  
|[FORWARD_NOTIFICATIONS](#forward_notifications)|Encaminha mensagens de notificação para a janela pai.|  
|[MESSAGE_HANDLER](#message_handler)|Uma mensagem do Windows é mapeado para uma função de manipulador.|  
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mensagens de um intervalo contíguo de Windows é mapeado para uma função de manipulador.|  
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[NOTIFY_HANDLER](#notify_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador do controle.|  
|[NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECT_NOTIFICATIONS](#reflect_notifications)|Reflete as mensagens de notificação para a janela que enviaram.|  
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e o identificador do item de menu, controle ou acelerador.|  
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|  
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador do controle.|  
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="a-namealtmsgmapa--altmsgmap"></a><a name="alt_msg_map"></a>ALT_MSG_MAP  
 Marca o início de um mapa de mensagens alternativos.  
  
```
ALT_MSG_MAP(msgMapID)
```  
  
### <a name="parameters"></a>Parâmetros  
 `msgMapID`  
 [in] O identificador de mapa de mensagem.  
  
### <a name="remarks"></a>Comentários  
 ATL identifica cada mapa de mensagem por um número. O mapa da mensagem padrão (declarado com o `BEGIN_MSG_MAP` macro) é identificado por 0. Um mapa de mensagem alternativo é identificado por `msgMapID`.  
  
 Mapas de mensagem são usados para processar as mensagens enviadas para uma janela. Por exemplo, [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) permite que você especifique o identificador de um mapa de mensagem no objeto de recipiente. [CContainedWindow::WindowProc](ccontainedwindowt-class.md#windowproc) , em seguida, usa esse mapa de mensagem para direcionar as mensagens da janela independente para a função de manipulador apropriado ou outro mapa da mensagem. Para obter uma lista de macros que declarar funções de manipulador, consulte [BEGIN_MSG_MAP](#begin_msg_map).  
  
 Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes.  
  
 O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Observe que sempre há exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra o mapa da mensagem padrão e o mapa de uma mensagem alternativo, cada um contendo uma função de manipulador:  
  
 [!code-cpp[NVC_ATL_Windowing&#98;](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]  
  
 O exemplo a seguir mostra dois mapas de mensagens alternativos. O mapa da mensagem padrão é vazio.  
  
 [!code-cpp[NVC_ATL_Windowing&#99;](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   

##  <a name="a-namebeginmsgmapa--beginmsgmap"></a><a name="begin_msg_map"></a>BEGIN_MSG_MAP  
 Marca o início do mapa de mensagens padrão.  
  
```
BEGIN_MSG_MAP(theClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 [in] O nome da classe que contém o mapa da mensagem.  
  
### <a name="remarks"></a>Comentários  
 [CWindowImpl::WindowProc](cwindowimpl-class.md#windowproc) usa o mapa da mensagem padrão para processar as mensagens enviadas para a janela. O mapa da mensagem direciona as mensagens para a função de manipulador apropriado ou outro mapa da mensagem.  

  
 As seguintes macros mapeiam uma mensagem para uma função de manipulador. Essa função deve ser definida em `theClass`.  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[MESSAGE_HANDLER](#message_handler)|Uma mensagem do Windows é mapeado para uma função de manipulador.|  
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mensagens de um intervalo contíguo de Windows é mapeado para uma função de manipulador.|  
|[COMMAND_HANDLER](#command_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e o identificador do item de menu, controle ou acelerador.|  
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|  
|[COMMAND_CODE_HANDLER](#command_handler)|Mapeia uma **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mapeia um intervalo contíguo de **WM_COMMAND** mensagens para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|  
|[NOTIFY_HANDLER](#notify_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador do controle.|  
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia um intervalo contíguo de **WM_NOTIFY** mensagens para uma função de manipulador, com base no identificador do controle.|  
  
 As seguintes macros direcionam mensagens para outro mapa da mensagem. Esse processo é chamado de "encadeamento".  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[CHAIN_MSG_MAP](#chain_msg_map)|Cadeias para o mapa da mensagem padrão na classe base.|  
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Cadeias para o mapa da mensagem padrão em um membro de dados da classe.|  
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Está ligado a um mapa de mensagens alternativos na classe base.|  
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Está ligado a um mapa de mensagens alternativos em um membro de dados da classe.|  
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Cadeias para o mapa da mensagem padrão em outra classe em tempo de execução.|  
  
 As seguintes macros direcionam mensagens "refletida" da janela pai. Por exemplo, um controle normalmente envia mensagens de notificação à sua janela pai para processamento, mas a janela pai pode refletir a mensagem de volta para o controle.  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e o identificador do item de menu, controle ou acelerador.|  
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|  
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia um refletido **WM_COMMAND** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e o identificador do controle.|  
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no identificador do controle.|  
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação.|  
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|  
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia um refletido **WM_NOTIFY** mensagem para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#102;](../../atl/codesnippet/cpp/message-map-macros-atl_3.h)]  
  
 Quando um `CMyExtWindow` objeto recebe um `WM_PAINT` mensagem, a mensagem é direcionada para `CMyExtWindow::OnPaint` o processamento real. Se `OnPaint` indica que a mensagem requer processamento adicional, o mensagem será então ser direcionado para o mapa da mensagem padrão em `CMyBaseWindow`.  
  
 Além do mapa da mensagem padrão, você pode definir um mapa de mensagens alternativos com [ALT_MSG_MAP](#alt_msg_map). Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes. O exemplo a seguir mostra o mapa da mensagem padrão e o mapa de uma mensagem alternativo, cada um contendo uma função de manipulador:  
  
 [!code-cpp[NVC_ATL_Windowing&#98;](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]  
  
 O exemplo a seguir mostra dois mapas de mensagens alternativos. O mapa da mensagem padrão é vazio.  
  
 [!code-cpp[NVC_ATL_Windowing&#99;](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]  
  
 O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Observe que sempre há exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namechainmsgmapalta--chainmsgmapalt"></a><a name="chain_msg_map_alt"></a>CHAIN_MSG_MAP_ALT  
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
 `CHAIN_MSG_MAP_ALT`direciona as mensagens para um mapa de mensagens alternativos em uma classe base. Você deve declarar esse mapa de mensagens alternativos com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens para o mapa da mensagem padrão de uma classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use `CHAIN_MSG_MAP`. Para obter um exemplo, consulte [CHAIN_MSG_MAP](#chain_msg_map).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namechainmsgmapaltmembera--chainmsgmapaltmember"></a><a name="chain_msg_map_alt_member"></a>CHAIN_MSG_MAP_ALT_MEMBER  
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
 `CHAIN_MSG_MAP_ALT_MEMBER`direciona as mensagens para um mapa de mensagens alternativos em um membro de dados. Você deve declarar esse mapa de mensagens alternativos com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens ao mapa de mensagem de um membro de dados padrão (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use `CHAIN_MSG_MAP_MEMBER`. Para obter um exemplo, consulte [CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namechainmsgmapa--chainmsgmap"></a><a name="chain_msg_map"></a>CHAIN_MSG_MAP  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP(theChainClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theChainClass`  
 [in] O nome da classe base que contém o mapa da mensagem.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP`direciona mensagens ao mapa de mensagem padrão de uma classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagens alternativos de uma classe base (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT](#chain_msg_map_alt).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#107;](../../atl/codesnippet/cpp/message-map-macros-atl_4.h)]  
  
 Este exemplo ilustra o seguinte:  
  
-   Se estiver usando um procedimento de janela `CMyClass`do mapa da mensagem padrão e `OnPaint` não alça de uma mensagem, a mensagem é direcionada para `CMyBaseClass`do mapa da mensagem padrão para processamento.  
  
-   Se um procedimento de janela é usando o mapa de mensagens alternativos primeiro em `CMyClass`, todas as mensagens são direcionadas para `CMyBaseClass`do mapa da mensagem padrão.  
  
-   Se estiver usando um procedimento de janela `CMyClass`da segunda mensagem alternativa do mapa e `OnChar` não alça de uma mensagem, a mensagem é direcionada para o mapa de mensagem alternativo especificado em `CMyBaseClass`. `CMyBaseClass`deve ter declarado esse mapa de mensagem com `ALT_MSG_MAP(1)`.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namechainmsgmapdynamica--chainmsgmapdynamic"></a><a name="chain_msg_map_dynamic"></a>CHAIN_MSG_MAP_DYNAMIC  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP_DYNAMIC(dynaChainID)
```  
  
### <a name="parameters"></a>Parâmetros  
 *dynaChainID*  
 [in] O identificador exclusivo para o mapa da mensagem de um objeto.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP_DYNAMIC`direciona mensagens, em tempo de execução para o mapa da mensagem padrão em outro objeto. O objeto e seu mapa de mensagem associados *dynaChainID*, que você define através de [CDynamicChain::SetChainEntry](cdynamicchain-class.md#setchainentry). Você deve derivar a classe de `CDynamicChain` para usar `CHAIN_MSG_MAP_DYNAMIC`. Para obter um exemplo, consulte o [CDynamicChain](../../atl/reference/cdynamicchain-class.md) visão geral.  

  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namechainmsgmapmembera--chainmsgmapmember"></a><a name="chain_msg_map_member"></a>CHAIN_MSG_MAP_MEMBER  
 Define uma entrada em um mapa de mensagem.  
  
```
CHAIN_MSG_MAP_MEMBER(theChainMember)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theChainMember`  
 [in] O nome do membro de dados que contém o mapa da mensagem.  
  
### <a name="remarks"></a>Comentários  
 `CHAIN_MSG_MAP_MEMBER`direciona mensagens ao mapa de mensagem de um membro de dados padrão (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagens alternativos de um membro de dados (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member).  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem `BEGIN_MSG_MAP`. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com `ALT_MSG_MAP`. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#108;](../../atl/codesnippet/cpp/message-map-macros-atl_5.h)]  
  
 Este exemplo ilustra o seguinte:  
  
-   Se estiver usando um procedimento de janela `CMyClass`do mapa da mensagem padrão e `OnPaint` não alça de uma mensagem, a mensagem é direcionada para `m_obj`do mapa da mensagem padrão para processamento.  
  
-   Se um procedimento de janela é usando o mapa de mensagens alternativos primeiro em `CMyClass`, todas as mensagens são direcionadas para `m_obj`do mapa da mensagem padrão.  
  
-   Se estiver usando um procedimento de janela `CMyClass`da segunda mensagem alternativa do mapa e `OnChar` não alça de uma mensagem, a mensagem é direcionada para o mapa de mensagem alternativo especificado do `m_obj`. Classe `CMyContainedClass` deve ter declarado esse mapa de mensagem com `ALT_MSG_MAP(1)`.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namecommandcodehandlera--commandcodehandler"></a><a name="command_code_handler"></a>COMMAND_CODE_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia uma [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem com base apenas no código de notificação.  
  
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
  
##  <a name="a-namecommandhandlera--commandhandler"></a><a name="command_handler"></a>COMMAND_HANDLER  
 Define uma entrada em um mapa de mensagem.  
  
```
COMMAND_HANDLER(id, code, func)
```    
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, controle ou acelerador.  
  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 `COMMAND_HANDLER`mapeia uma [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem para a função de manipulador especificado, com base no código de notificação e o identificador do controle. Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing&#119;](../../atl/codesnippet/cpp/message-map-macros-atl_6.h)]  
  
 Qualquer função especificada em um `COMMAND_HANDLER` macro deve ser definida da seguinte maneira:  
  
 `LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);`  
  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `CommandHandler` é chamado. Se `CommandHandler` não totalmente processa a mensagem, ele deve definir `bHandled` para **FALSE** para indicar que a mensagem precisa continuar o processamento.  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Além `COMMAND_HANDLER`, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear um **WM_COMMAND** mensagem sem considerar um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_COMMAND, OnHandlerFunction)` direcionará todas **WM_COMMAND** mensagens para `OnHandlerFunction`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namecommandidhandlera--commandidhandler"></a><a name="command_id_handler"></a>COMMAND_ID_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia uma [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem base somente o identificador do item de menu, controle ou acelerador.  
  
```
COMMAND_ID_HANDLER(id, func)
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, controle ou acelerador de enviar a mensagem.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namecommandrangecodehandlera--commandrangecodehandler"></a><a name="command_range_code_handler"></a>COMMAND_RANGE_CODE_HANDLER  
 Semelhante ao [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagens com um código de notificação específica em uma variedade de controles para uma função de manipulador único.  
  
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
 Esse intervalo se baseia o identificador do item de menu, controle ou acelerador de enviar a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namecommandrangehandlera--commandrangehandler"></a><a name="command_range_handler"></a>COMMAND_RANGE_HANDLER  
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
 Esse intervalo se baseia o identificador do item de menu, controle ou acelerador de enviar a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namedeclareemptymsgmapa--declareemptymsgmap"></a><a name="declare_empty_msg_map"></a>DECLARE_EMPTY_MSG_MAP  
 Declara um mapa de mensagem vazia.  
  
```
DECLARE_EMPTY_MSG_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 `DECLARE_EMPTY_MSG_MAP`é uma macro de conveniência que chama as macros [BEGIN_MSG_MAP](#begin_msg_map) e [END_MSG_MAP](#end_msg_map) para criar um mapa de mensagem vazia:  
  
 [!code-cpp[NVC_ATL_Windowing&#122;](../../atl/codesnippet/cpp/message-map-macros-atl_7.h)]  
  
##  <a name="a-namedefaultreflectionhandlera--defaultreflectionhandler"></a><a name="default_reflection_handler"></a>DEFAULT_REFLECTION_HANDLER  
 Fornece um manipulador para a janela filho (controle) que receberá padrão refletidas mensagens; o manipulador passará corretamente mensagens sem tratamento para `DefWindowProc`.  
  
```
DEFAULT_REFLECTION_HANDLER()
```  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-nameendmsgmapa--endmsgmap"></a><a name="end_msg_map"></a>END_MSG_MAP  
 Marca o fim de um mapa de mensagem.  
  
```
END_MSG_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 Sempre use o [BEGIN_MSG_MAP](#begin_msg_map) macro para marcar o início de um mapa de mensagem. Use [ALT_MSG_MAP](#alt_msg_map) para declarar mapas de mensagem alternativo subsequentes.  
  
 Observe que sempre há exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra o mapa da mensagem padrão e o mapa de uma mensagem alternativo, cada um contendo uma função de manipulador:  
  
 [!code-cpp[NVC_ATL_Windowing&#98;](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]  
  
 O exemplo a seguir mostra dois mapas de mensagens alternativos. O mapa da mensagem padrão é vazio.  
  
 [!code-cpp[NVC_ATL_Windowing&#99;](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-nameforwardnotificationsa--forwardnotifications"></a><a name="forward_notifications"></a>FORWARD_NOTIFICATIONS  
 Encaminha mensagens de notificação para a janela pai.  
  
```
FORWARD_NOTIFICATIONS()
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esta macro como parte de seu mapa de mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namemessagehandlera--messagehandler"></a><a name="message_handler"></a>MESSAGE_HANDLER  
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
 `MESSAGE_HANDLER`mapeia uma mensagem do Windows para a função de manipulador especificado.  
  
 Qualquer função especificada em um `MESSAGE_HANDLER` macro deve ser definida da seguinte maneira:  
  
 `LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);`  
  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `MessageHandler` é chamado. Se `MessageHandler` não totalmente processa a mensagem, ele deve definir `bHandled` para **FALSE** para indicar que a mensagem precisa continuar o processamento.  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Além `MESSAGE_HANDLER`, você pode usar [COMMAND_HANDLER](#command_handler) e [NOTIFY_HANDLER](#notify_handler) para mapear [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) e [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagens, respectivamente.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#129;](../../atl/codesnippet/cpp/message-map-macros-atl_8.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namemessagerangehandlera--messagerangehandler"></a><a name="message_range_handler"></a>MESSAGE_RANGE_HANDLER  
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
  
##  <a name="a-namenotifycodehandlera--notifycodehandler"></a><a name="notify_code_handler"></a>NOTIFY_CODE_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia uma [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem com base apenas no código de notificação.  
  
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
  
##  <a name="a-namenotifyhandlera--notifyhandler"></a><a name="notify_handler"></a>NOTIFY_HANDLER  
 Define uma entrada em um mapa de mensagem.  
  
```
NOTIFY_HANDLER( id, cd, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do controle enviando a mensagem.  
  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="remarks"></a>Comentários  
 `NOTIFY_HANDLER`mapeia uma [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem para a função de manipulador especificado, com base no código de notificação e o identificador do controle.  
  
 Qualquer função especificada em um `NOTIFY_HANDLER` macro deve ser definida da seguinte maneira:  
  
 `LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);`  
  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `NotifyHandler` é chamado. Se `NotifyHandler` não totalmente processa a mensagem, ele deve definir `bHandled` para **FALSE** para indicar que a mensagem precisa continuar o processamento.  
  
> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativo subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa da mensagem. Cada mapa da mensagem deve ter exatamente uma instância de `BEGIN_MSG_MAP` e `END_MSG_MAP`.  
  
 Além `NOTIFY_HANDLER`, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear um **WM_NOTIFY** mensagem sem considerar um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_NOTIFY, OnHandlerFunction)` direcionará todas **WM_NOTIFY** mensagens para `OnHandlerFunction`.  
  
 Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#130;](../../atl/codesnippet/cpp/message-map-macros-atl_9.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namenotifyidhandlera--notifyidhandler"></a><a name="notify_id_handler"></a>NOTIFY_ID_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia uma [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem base somente o identificador de controle.  
  
```
NOTIFY_ID_HANDLER( id, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do controle enviando a mensagem.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namenotifyrangecodehandlera--notifyrangecodehandler"></a><a name="notify_range_code_handler"></a>NOTIFY_RANGE_CODE_HANDLER  
 Semelhante ao [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagens com um código de notificação específica em uma variedade de controles para uma função de manipulador único.  
  
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
 Esse intervalo se baseia o identificador do controle enviando a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namenotifyrangehandlera--notifyrangehandler"></a><a name="notify_range_handler"></a>NOTIFY_RANGE_HANDLER  
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
 Esse intervalo se baseia o identificador do controle enviando a mensagem.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namereflectnotificationsa--reflectnotifications"></a><a name="reflect_notifications"></a>REFLECT_NOTIFICATIONS  
 Reflete as mensagens de notificação para a janela filho (controle) que enviaram.  
  
```
REFLECT_NOTIFICATIONS()
```  
  
### <a name="remarks"></a>Comentários  
 Especifique esta macro como parte do mapa da mensagem da janela pai.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h   
  
##  <a name="a-namereflectedcommandcodehandlera--reflectedcommandcodehandler"></a><a name="reflected_command_code_handler"></a>REFLECTED_COMMAND_CODE_HANDLER  
 Semelhante ao [COMMAND_CODE_HANDLER](#command_code_handler), mas mapeia comandos serão refletidos na janela pai.  
  
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
   
##  <a name="a-namereflectedcommandhandlera--reflectedcommandhandler"></a><a name="reflected_command_handler"></a>REFLECTED_COMMAND_HANDLER  
 Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia comandos serão refletidos na janela pai.  
  
```
REFLECTED_COMMAND_HANDLER( id, code, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, controle ou acelerador.  
  
 `code`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="a-namereflectedcommandidhandlera--reflectedcommandidhandler"></a><a name="reflected_command_id_handler"></a>REFLECTED_COMMAND_ID_HANDLER  
 Semelhante ao [COMMAND_ID_HANDLER](#command_id_handler), mas mapeia comandos serão refletidos na janela pai.  
  
```
REFLECTED_COMMAND_ID_HANDLER( id, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, controle ou acelerador.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="a-namereflectedcommandrangecodehandlera--reflectedcommandrangecodehandler"></a><a name="reflected_command_range_code_handler"></a>REFLECTED_COMMAND_RANGE_CODE_HANDLER  
 Semelhante ao [COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler), mas mapeia comandos serão refletidos na janela pai.  
  
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

##  <a name="a-namereflectedcommandrangehandlera--reflectedcommandrangehandler"></a><a name="reflected_command_range_handler"></a>REFLECTED_COMMAND_RANGE_HANDLER  
 Semelhante ao [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia comandos serão refletidos na janela pai.  
  
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

##  <a name="a-namereflectednotifycodehandlera--reflectednotifycodehandler"></a><a name="reflected_notify_code_handler"></a>REFLECTED_NOTIFY_CODE_HANDLER  
 Semelhante ao [NOTIFY_CODE_HANDLER](#notify_code_handler), mas mapeia as notificações serão refletidas na janela pai.  
  
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

##  <a name="a-namereflectednotifyhandlera--reflectednotifyhandler"></a><a name="reflected_notify_handler"></a>REFLECTED_NOTIFY_HANDLER  
 Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia as notificações serão refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_HANDLER( id, cd, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, controle ou acelerador.  
  
 `cd`  
 [in] O código de notificação.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="a-namereflectednotifyidhandlera--reflectednotifyidhandler"></a><a name="reflected_notify_id_handler"></a>REFLECTED_NOTIFY_ID_HANDLER  
 Semelhante ao [NOTIFY_ID_HANDLER](#notify_id_handler), mas mapeia as notificações serão refletidas na janela pai.  
  
```
REFLECTED_NOTIFY_ID_HANDLER( id, func )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] O identificador do item de menu, controle ou acelerador.  
  
 `func`  
 [in] O nome da função de manipulador de mensagens.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  

##  <a name="a-namereflectednotifyrangecodehandlera--reflectednotifyrangecodehandler"></a><a name="reflected_notify_range_code_handler"></a>REFLECTED_NOTIFY_RANGE_CODE_HANDLER  
 Semelhante ao [NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler), mas mapeia as notificações serão refletidas na janela pai.  
  
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
  
##  <a name="a-namereflectednotifyrangehandlera--reflectednotifyrangehandler"></a><a name="reflected_notify_range_handler"></a>REFLECTED_NOTIFY_RANGE_HANDLER  
 Semelhante ao [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia as notificações serão refletidas na janela pai.  
  
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


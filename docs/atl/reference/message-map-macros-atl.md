---
title: Macros de mapa de mensagem (ATL)
ms.date: 11/04/2016
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
ms.assetid: eefdd546-8934-4a30-b263-9c06a8addcbd
ms.openlocfilehash: a246e907d401167011b5a3e1306c146a338e233a
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694362"
---
# <a name="message-map-macros-atl"></a>Macros de mapa de mensagem (ATL)

Essas macros definem entradas e mapas de mensagem.

|||
|-|-|
|[ALT_MSG_MAP](#alt_msg_map)|Marca o início de um mapa de mensagens alternativos.|
|[BEGIN_MSG_MAP](#begin_msg_map)|Marca o início do mapa de mensagens padrão.|
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Encadeie a um mapa de mensagem alternativa na classe base.|
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Encadeie a um mapa de mensagens alternativos em um membro de dados da classe.|
|[CHAIN_MSG_MAP](#chain_msg_map)|Cadeias para o mapa de mensagem padrão na classe base.|
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Cadeias de mapa de mensagens em outra classe no tempo de execução.|
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Cadeias para o mapa de mensagem padrão em um membro de dados da classe.|
|[COMMAND_CODE_HANDLER](#command_code_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base no código de notificação.|
|[COMMAND_HANDLER](#command_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base em como o código de notificação e o identificador do controle, item de menu ou acelerador.|
|[COMMAND_ID_HANDLER](#command_id_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base no identificador do controle, item de menu ou acelerador.|
|[COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[DECLARE_EMPTY_MSG_MAP](#declare_empty_msg_map)|Implementa um mapa de mensagem vazio.|
|[DEFAULT_REFLECTION_HANDLER](#default_reflection_handler)|Fornece um manipulador padrão para mensagens refletidas que não são tratadas caso contrário.|
|[END_MSG_MAP](#end_msg_map)|Marca o fim de um mapa de mensagem.|
|[FORWARD_NOTIFICATIONS](#forward_notifications)|Encaminha mensagens de notificação para a janela pai.|
|[MESSAGE_HANDLER](#message_handler)|Mapeia uma mensagem do Windows para uma função de manipulador.|
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mensagens de um intervalo contíguo de Windows é mapeado para uma função de manipulador.|
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no código de notificação.|
|[NOTIFY_HANDLER](#notify_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no código de notificação e o identificador de controle.|
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no identificador do controle.|
|[NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECT_NOTIFICATIONS](#reflect_notifications)|Reflete as mensagens de notificação para a janela que enviaram.|
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base no código de notificação.|
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base em como o código de notificação e o identificador do controle, item de menu ou acelerador.|
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base no identificador do controle, item de menu ou acelerador.|
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no código de notificação.|
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no código de notificação e o identificador de controle.|
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no identificador do controle.|
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base em um intervalo contíguo de identificadores de controle.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="alt_msg_map"></a>  ALT_MSG_MAP

Marca o início de um mapa de mensagens alternativos.

```
ALT_MSG_MAP(msgMapID)
```

### <a name="parameters"></a>Parâmetros

*msgMapID*<br/>
[in] O identificador de mapa de mensagem.

### <a name="remarks"></a>Comentários

ATL identifica cada mapa de mensagem por um número. O mapa de mensagem padrão (declarado com a macro BEGIN_MSG_MAP) é identificado por 0. Um mapa de mensagem alternativa é identificado por *msgMapID*.

Mapas de mensagem são usados para processar as mensagens enviadas para uma janela. Por exemplo, [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) permite que você especifique o identificador de um mapa de mensagem no objeto contentor. [CContainedWindow::WindowProc](ccontainedwindowt-class.md#windowproc) , em seguida, usa esse mapa de mensagem para direcionar as mensagens da janela independente para a função de manipulador apropriado ou ao outro mapa de mensagem. Para obter uma lista de macros que declarar funções de manipulador, consulte [BEGIN_MSG_MAP](#begin_msg_map).

Sempre começam com BEGIN_MSG_MAP um mapa de mensagem. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes.

O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Observe que sempre há exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra o mapa de mensagem padrão e o mapa de uma mensagem alternativa, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O exemplo a seguir mostra dois mapas de mensagem alternativa. O mapa de mensagem padrão é vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="begin_msg_map"></a>  BEGIN_MSG_MAP

Marca o início do mapa de mensagens padrão.

```
BEGIN_MSG_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
[in] O nome da classe que contém o mapa de mensagem.

### <a name="remarks"></a>Comentários

[CWindowImpl::WindowProc](cwindowimpl-class.md#windowproc) usa o mapa de mensagem padrão para processar as mensagens enviadas para a janela. Mapa de mensagens direciona as mensagens para a função de manipulador apropriado ou ao outro mapa de mensagem.

As seguintes macros mapeiam uma mensagem para uma função de manipulador. Essa função deve ser definida em *theClass*.

|Macro|Descrição|
|-----------|-----------------|
|[MESSAGE_HANDLER](#message_handler)|Mapeia uma mensagem do Windows para uma função de manipulador.|
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mensagens de um intervalo contíguo de Windows é mapeado para uma função de manipulador.|
|[COMMAND_HANDLER](#command_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base em como o código de notificação e o identificador do controle, item de menu ou acelerador.|
|[COMMAND_ID_HANDLER](#command_id_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base no identificador do controle, item de menu ou acelerador.|
|[COMMAND_CODE_HANDLER](#command_handler)|Uma mensagem WM_COMMAND é mapeado para uma função do manipulador, com base no código de notificação.|
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mensagens de um intervalo contíguo de WM_COMMAND é mapeado para uma função do manipulador, com base no identificador do controle, item de menu ou acelerador.|
|[NOTIFY_HANDLER](#notify_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no código de notificação e o identificador de controle.|
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no identificador do controle.|
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma mensagem WM_NOTIFY para uma função do manipulador, com base no código de notificação.|
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mensagens de um intervalo contíguo de WM_NOTIFY é mapeado para uma função do manipulador, com base no identificador do controle.|

As seguintes macros direcionam mensagens para outro mapa de mensagem. Esse processo é chamado de "encadeamento".

|Macro|Descrição|
|-----------|-----------------|
|[CHAIN_MSG_MAP](#chain_msg_map)|Cadeias para o mapa de mensagem padrão na classe base.|
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Cadeias para o mapa de mensagem padrão em um membro de dados da classe.|
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Encadeie a um mapa de mensagem alternativa na classe base.|
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Encadeie a um mapa de mensagens alternativos em um membro de dados da classe.|
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Cadeias para o mapa de mensagem padrão em outra classe no tempo de execução.|

As seguintes macros direcionam "refletida" mensagens de janela pai. Por exemplo, um controle normalmente envia mensagens de notificação à sua janela pai para processamento, mas a janela pai pode refletir a mensagem de volta para o controle.

|Macro|Descrição|
|-----------|-----------------|
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base em como o código de notificação e o identificador do controle, item de menu ou acelerador.|
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base no identificador do controle, item de menu ou acelerador.|
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base no código de notificação.|
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função do manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no código de notificação e o identificador de controle.|
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no identificador do controle.|
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no código de notificação.|
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função do manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#102](../../atl/codesnippet/cpp/message-map-macros-atl_3.h)]

Quando um `CMyExtWindow` objeto recebe uma mensagem WM_PAINT, a mensagem é direcionada para `CMyExtWindow::OnPaint` para o processamento real. Se `OnPaint` indica a mensagem que requer processamento adicional, a mensagem será então ser direcionado para o mapa de mensagem padrão no `CMyBaseWindow`.

Além de mapa de mensagens padrão, você pode definir um mapa de mensagens alternativos com [ALT_MSG_MAP](#alt_msg_map). Sempre começam com BEGIN_MSG_MAP um mapa de mensagem. Em seguida, você pode declarar mapas de mensagem alternativo subsequentes. O exemplo a seguir mostra o mapa de mensagem padrão e o mapa de uma mensagem alternativa, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O exemplo a seguir mostra dois mapas de mensagem alternativa. O mapa de mensagem padrão é vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Observe que sempre há exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="chain_msg_map_alt"></a>  CHAIN_MSG_MAP_ALT

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_ALT(theChainClass, msgMapID)
```

### <a name="parameters"></a>Parâmetros

*theChainClass*<br/>
[in] O nome da classe base que contém o mapa de mensagem.

*msgMapID*<br/>
[in] O identificador de mapa de mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_ALT direciona mensagens a um mapa de mensagens alternativos em uma classe base. Você deve declarar esse mapa de mensagens alternativos com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens para o mapa de mensagens de padrão de uma classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use CHAIN_MSG_MAP. Por exemplo, consulte [CHAIN_MSG_MAP](#chain_msg_map).

> [!NOTE]
>  Sempre começam com BEGIN_MSG_MAP um mapa de mensagem. Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com ALT_MSG_MAP. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="chain_msg_map_alt_member"></a>  CHAIN_MSG_MAP_ALT_MEMBER

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID)
```

### <a name="parameters"></a>Parâmetros

*theChainMember*<br/>
[in] O nome do membro de dados que contém o mapa de mensagem.

*msgMapID*<br/>
[in] O identificador de mapa de mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_ALT_MEMBER direciona mensagens a um mapa de mensagens alternativos em um membro de dados. Você deve declarar esse mapa de mensagens alternativos com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens para o mapa de mensagens de padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use CHAIN_MSG_MAP_MEMBER. Por exemplo, consulte [CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member).

> [!NOTE]
>  Sempre começam com BEGIN_MSG_MAP um mapa de mensagem. Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com ALT_MSG_MAP. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="chain_msg_map"></a>  CHAIN_MSG_MAP

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP(theChainClass)
```

### <a name="parameters"></a>Parâmetros

*theChainClass*<br/>
[in] O nome da classe base que contém o mapa de mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP direciona mensagens ao mapa de mensagem padrão de uma classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagens alternativos de classe base (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT](#chain_msg_map_alt).

> [!NOTE]
>  Sempre começam com BEGIN_MSG_MAP um mapa de mensagem. Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com ALT_MSG_MAP. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#107](../../atl/codesnippet/cpp/message-map-macros-atl_4.h)]

Este exemplo ilustra o seguinte:

- Se estiver usando um procedimento de janela `CMyClass`do mapa de mensagem padrão e `OnPaint` não alça de uma mensagem, a mensagem é direcionada para `CMyBaseClass`do mapa de mensagem padrão para processamento.

- Se um procedimento de janela é usando o mapa de mensagens alternativos primeiro na `CMyClass`, todas as mensagens são direcionadas para `CMyBaseClass`do mapa de mensagem padrão.

- Se estiver usando um procedimento de janela `CMyClass`da segunda mensagem alternativa do mapa e `OnChar` não alça de uma mensagem, a mensagem é direcionada para o mapa de mensagem alternativo especificado no `CMyBaseClass`. `CMyBaseClass` deve ter declarado neste mapa de mensagem com ALT_MSG_MAP(1).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="chain_msg_map_dynamic"></a>  CHAIN_MSG_MAP_DYNAMIC

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_DYNAMIC(dynaChainID)
```

### <a name="parameters"></a>Parâmetros

*dynaChainID*<br/>
[in] O identificador exclusivo para o mapa de mensagens de um objeto.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_DYNAMIC direciona mensagens, em tempo de execução para o mapa de mensagem padrão em outro objeto. O objeto e seu mapa de mensagem estão associados *dynaChainID*, que será definido por meio de [CDynamicChain::SetChainEntry](cdynamicchain-class.md#setchainentry). Você deve derivar de sua classe de `CDynamicChain` para usar CHAIN_MSG_MAP_DYNAMIC. Por exemplo, consulte o [CDynamicChain](../../atl/reference/cdynamicchain-class.md) visão geral.

> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com ALT_MSG_MAP. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="chain_msg_map_member"></a>  CHAIN_MSG_MAP_MEMBER

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_MEMBER(theChainMember)
```

### <a name="parameters"></a>Parâmetros

*theChainMember*<br/>
[in] O nome do membro de dados que contém o mapa de mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_MEMBER direciona mensagens ao mapa de mensagens de padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagem alternativa de um membro de dados (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member).

> [!NOTE]
>  Sempre começam com BEGIN_MSG_MAP um mapa de mensagem. Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com ALT_MSG_MAP. O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#108](../../atl/codesnippet/cpp/message-map-macros-atl_5.h)]

Este exemplo ilustra o seguinte:

- Se estiver usando um procedimento de janela `CMyClass`do mapa de mensagem padrão e `OnPaint` não alça de uma mensagem, a mensagem é direcionada para `m_obj`do mapa de mensagem padrão para processamento.

- Se um procedimento de janela é usando o mapa de mensagens alternativos primeiro na `CMyClass`, todas as mensagens são direcionadas para `m_obj`do mapa de mensagem padrão.

- Se estiver usando um procedimento de janela `CMyClass`da segunda mensagem alternativa do mapa e `OnChar` não alça de uma mensagem, a mensagem é direcionada para o mapa de mensagem alternativo especificado do `m_obj`. Classe `CMyContainedClass` deve ter declarado neste mapa de mensagem com ALT_MSG_MAP(1).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="command_code_handler"></a>  COMMAND_CODE_HANDLER

Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia uma [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem com base apenas no código de notificação.

```
COMMAND_CODE_HANDLER(code, func)
```

### <a name="parameters"></a>Parâmetros

*Código*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="command_handler"></a>  COMMAND_HANDLER

Define uma entrada em um mapa de mensagem.

```
COMMAND_HANDLER(id, code, func)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle, item de menu ou acelerador.

*Código*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

COMMAND_HANDLER mapeia uma [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem para a função de manipulador especificado, com base no código de notificação e o identificador de controle. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#119](../../atl/codesnippet/cpp/message-map-macros-atl_6.h)]

Qualquer função especificada em uma macro COMMAND_HANDLER deve ser definida da seguinte maneira:

`LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);`

Os conjuntos de mapa de mensagem `bHandled` como TRUE antes `CommandHandler` é chamado. Se `CommandHandler` não consegue tratar por completo a mensagem, ela deverá definir `bHandled` como FALSE para indicar que a mensagem precisa de processamento adicional.

> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de COMMAND_HANDLER, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear uma mensagem WM_COMMAND sem levar em consideração um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_COMMAND, OnHandlerFunction)` direcionará todas as mensagens WM_COMMAND `OnHandlerFunction`.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="command_id_handler"></a>  COMMAND_ID_HANDLER

Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia uma [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem com base apenas no identificador do controle, item de menu ou acelerador.

```
COMMAND_ID_HANDLER(id, func)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do item de menu, do controle ou do acelerador de envio da mensagem.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="command_range_code_handler"></a>  COMMAND_RANGE_CODE_HANDLER

Semelhante ao [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagens com um código de notificação específica de uma variedade de controles para uma função de manipulador único.

```
COMMAND_RANGE_CODE_HANDLER(idFirst, idLast, code, func)
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*Código*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo se baseia o identificador do item de menu, do controle ou do acelerador de envio da mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="command_range_handler"></a>  COMMAND_RANGE_HANDLER

Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagens de uma variedade de controles para uma função de manipulador único.

```
COMMAND_RANGE_HANDLER( idFirst, idLast, func)
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo se baseia o identificador do item de menu, do controle ou do acelerador de envio da mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="declare_empty_msg_map"></a>  DECLARE_EMPTY_MSG_MAP

Declara um mapa de mensagem vazio.

```
DECLARE_EMPTY_MSG_MAP()
```

### <a name="remarks"></a>Comentários

DECLARE_EMPTY_MSG_MAP é uma macro de conveniência que chama as macros [BEGIN_MSG_MAP](#begin_msg_map) e [END_MSG_MAP](#end_msg_map) para criar um mapa de mensagem vazia:

[!code-cpp[NVC_ATL_Windowing#122](../../atl/codesnippet/cpp/message-map-macros-atl_7.h)]

##  <a name="default_reflection_handler"></a>  DEFAULT_REFLECTION_HANDLER

Fornece um manipulador padrão para a janela filho (controle) que receberão refletidas mensagens; o manipulador passará corretamente sem tratamento de mensagens para `DefWindowProc`.

```
DEFAULT_REFLECTION_HANDLER()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="end_msg_map"></a>  END_MSG_MAP

Marca o fim de um mapa de mensagem.

```
END_MSG_MAP()
```

### <a name="remarks"></a>Comentários

Sempre use a [BEGIN_MSG_MAP](#begin_msg_map) macro para marcar o início de um mapa de mensagem. Use [ALT_MSG_MAP](#alt_msg_map) para declarar os mapas de mensagem alternativo subsequentes.

Observe que sempre há exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra o mapa de mensagem padrão e o mapa de uma mensagem alternativa, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O exemplo a seguir mostra dois mapas de mensagem alternativa. O mapa de mensagem padrão é vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="forward_notifications"></a>  FORWARD_NOTIFICATIONS

Encaminha mensagens de notificação para a janela pai.

```
FORWARD_NOTIFICATIONS()
```

### <a name="remarks"></a>Comentários

Especifique esta macro como parte de seu mapa de mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="message_handler"></a>  MESSAGE_HANDLER

Define uma entrada em um mapa de mensagem.

```
MESSAGE_HANDLER( msg, func )
```

### <a name="parameters"></a>Parâmetros

*msg*<br/>
[in] A mensagem do Windows.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

MESSAGE_HANDLER mapeia uma mensagem do Windows para a função de manipulador especificado.

Qualquer função especificada em uma macro MESSAGE_HANDLER deve ser definida da seguinte maneira:

`LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);`

Os conjuntos de mapa de mensagem `bHandled` como TRUE antes `MessageHandler` é chamado. Se `MessageHandler` não consegue tratar por completo a mensagem, ela deverá definir `bHandled` como FALSE para indicar que a mensagem precisa de processamento adicional.

> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de MESSAGE_HANDLER, você pode usar [COMMAND_HANDLER](#command_handler) e [NOTIFY_HANDLER](#notify_handler) mapear [WM_COMMAND](/windows/desktop/menurc/wm-command) e [WM_NOTIFY](/windows/desktop/controls/wm-notify) mensagens , respectivamente.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#129](../../atl/codesnippet/cpp/message-map-macros-atl_8.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="message_range_handler"></a>  MESSAGE_RANGE_HANDLER

Semelhante ao [MESSAGE_HANDLER](#message_handler), mas os mapas de mensagens de um intervalo do Windows para uma função de manipulador único.

```
MESSAGE_RANGE_HANDLER( msgFirst, msgLast, func )
```

### <a name="parameters"></a>Parâmetros

*msgFirst*<br/>
[in] Marca o início de um intervalo contíguo de mensagens.

*msgLast*<br/>
[in] Marca o fim de um intervalo contíguo de mensagens.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="notify_code_handler"></a>  NOTIFY_CODE_HANDLER

Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia uma [WM_NOTIFY](/windows/desktop/controls/wm-notify) mensagem com base apenas no código de notificação.

```
NOTIFY_CODE_HANDLER(cd, func)
```

### <a name="parameters"></a>Parâmetros

*CD*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="notify_handler"></a>  NOTIFY_HANDLER

Define uma entrada em um mapa de mensagem.

```
NOTIFY_HANDLER( id, cd, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle que está enviando a mensagem.

*CD*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

NOTIFY_HANDLER mapeia uma [WM_NOTIFY](/windows/desktop/controls/wm-notify) mensagem para a função de manipulador especificado, com base no código de notificação e o identificador de controle.

Qualquer função especificada em uma macro NOTIFY_HANDLER deve ser definida da seguinte maneira:

`LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);`

Os conjuntos de mapa de mensagem `bHandled` como TRUE antes `NotifyHandler` é chamado. Se `NotifyHandler` não consegue tratar por completo a mensagem, ela deverá definir `bHandled` como FALSE para indicar que a mensagem precisa de processamento adicional.

> [!NOTE]
>  Sempre começam com um mapa de mensagem [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativa subsequentes com [ALT_MSG_MAP](#alt_msg_map). O [END_MSG_MAP](#end_msg_map) macro marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de NOTIFY_HANDLER, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear uma mensagem WM_NOTIFY sem levar em consideração um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_NOTIFY, OnHandlerFunction)` direcionará todas as mensagens de WM_NOTIFY `OnHandlerFunction`.

Para obter mais informações sobre como usar mapas de mensagem em ATL, consulte [mapas de mensagem](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#130](../../atl/codesnippet/cpp/message-map-macros-atl_9.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="notify_id_handler"></a>  NOTIFY_ID_HANDLER

Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia uma [WM_NOTIFY](/windows/desktop/controls/wm-notify) mensagem com base apenas no identificador do controle.

```
NOTIFY_ID_HANDLER( id, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle que está enviando a mensagem.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="notify_range_code_handler"></a>  NOTIFY_RANGE_CODE_HANDLER

Semelhante ao [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia [WM_NOTIFY](/windows/desktop/controls/wm-notify) mensagens com um código de notificação específica de uma variedade de controles para uma função de manipulador único.

```
NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*CD*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo se baseia o identificador do controle que está enviando a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="notify_range_handler"></a>  NOTIFY_RANGE_HANDLER

Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia [WM_NOTIFY](/windows/desktop/controls/wm-notify) mensagens de uma variedade de controles para uma função de manipulador único.

```
NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo se baseia o identificador do controle que está enviando a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflect_notifications"></a>  REFLECT_NOTIFICATIONS

Reflete as mensagens de notificação para a janela filho (controle) que enviaram.

```
REFLECT_NOTIFICATIONS()
```

### <a name="remarks"></a>Comentários

Especifique esta macro como parte do mapa de mensagens da janela pai.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_command_code_handler"></a>  REFLECTED_COMMAND_CODE_HANDLER

Semelhante ao [COMMAND_CODE_HANDLER](#command_code_handler), mas mapeia comandos refletidos na janela pai.

```
REFLECTED_COMMAND_CODE_HANDLER( code, func )
```

### <a name="parameters"></a>Parâmetros

*Código*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_command_handler"></a>  REFLECTED_COMMAND_HANDLER

Semelhante ao [COMMAND_HANDLER](#command_handler), mas mapeia comandos refletidos na janela pai.

```
REFLECTED_COMMAND_HANDLER( id, code, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle, item de menu ou acelerador.

*Código*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_command_id_handler"></a>  REFLECTED_COMMAND_ID_HANDLER

Semelhante ao [COMMAND_ID_HANDLER](#command_id_handler), mas mapeia comandos refletidos na janela pai.

```
REFLECTED_COMMAND_ID_HANDLER( id, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle, item de menu ou acelerador.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_command_range_code_handler"></a>  REFLECTED_COMMAND_RANGE_CODE_HANDLER

Semelhante ao [COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler), mas mapeia comandos refletidos na janela pai.

```
REFLECTED_COMMAND_RANGE_CODE_HANDLER( idFirst, idLast, code, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*Código*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_command_range_handler"></a>  REFLECTED_COMMAND_RANGE_HANDLER

Semelhante ao [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia comandos refletidos na janela pai.

```
REFLECTED_COMMAND_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_notify_code_handler"></a>  REFLECTED_NOTIFY_CODE_HANDLER

Semelhante ao [NOTIFY_CODE_HANDLER](#notify_code_handler), mas mapeia notificações refletidas na janela pai.

```
REFLECTED_NOTIFY_CODE_HANDLER_EX( cd, func )
```

### <a name="parameters"></a>Parâmetros

*CD*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_notify_handler"></a>  REFLECTED_NOTIFY_HANDLER

Semelhante ao [NOTIFY_HANDLER](#notify_handler), mas mapeia notificações refletidas na janela pai.

```
REFLECTED_NOTIFY_HANDLER( id, cd, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle, item de menu ou acelerador.

*CD*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_notify_id_handler"></a>  REFLECTED_NOTIFY_ID_HANDLER

Semelhante ao [NOTIFY_ID_HANDLER](#notify_id_handler), mas mapeia notificações refletidas na janela pai.

```
REFLECTED_NOTIFY_ID_HANDLER( id, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] O identificador do controle, item de menu ou acelerador.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_notify_range_code_handler"></a>  REFLECTED_NOTIFY_RANGE_CODE_HANDLER

Semelhante ao [NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler), mas mapeia notificações refletidas na janela pai.

```
REFLECTED_NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*CD*<br/>
[in] O código de notificação.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="reflected_notify_range_handler"></a>  REFLECTED_NOTIFY_RANGE_HANDLER

Semelhante ao [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia notificações refletidas na janela pai.

```
REFLECTED_NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[in] Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
[in] Marca o fim de um intervalo contíguo de identificadores de controle.

*func*<br/>
[in] O nome da função de manipulador de mensagens.

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)

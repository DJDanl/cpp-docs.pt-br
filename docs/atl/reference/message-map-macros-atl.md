---
title: Macros de mapa de mensagens (ATL)
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
ms.openlocfilehash: 42fdc7a3f09568b641229e897a2a493994a7ba8a
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417589"
---
# <a name="message-map-macros-atl"></a>Macros de mapa de mensagens (ATL)

Essas macros definem entradas e mapas de mensagens.

|||
|-|-|
|[ALT_MSG_MAP](#alt_msg_map)|Marca o início de um mapa de mensagens alternativo.|
|[BEGIN_MSG_MAP](#begin_msg_map)|Marca o início do mapa de mensagens padrão.|
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Encadeia-se a um mapa de mensagens alternativo na classe base.|
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Encadeia-se a um mapa de mensagens alternativo em um membro de dados da classe.|
|[CHAIN_MSG_MAP](#chain_msg_map)|Encadeia para o mapa de mensagem padrão na classe base.|
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Encadeia para o mapa de mensagens em outra classe em tempo de execução.|
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Encadeia para o mapa de mensagem padrão em um membro de dados da classe.|
|[COMMAND_CODE_HANDLER](#command_code_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no código de notificação.|
|[COMMAND_HANDLER](#command_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no código de notificação e no identificador do item de menu, controle ou acelerador.|
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|
|[COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[DECLARE_EMPTY_MSG_MAP](#declare_empty_msg_map)|Implementa um mapa de mensagens vazio.|
|[DEFAULT_REFLECTION_HANDLER](#default_reflection_handler)|Fornece um manipulador padrão para mensagens refletidas que não são manipuladas de outra forma.|
|[END_MSG_MAP](#end_msg_map)|Marca o final de um mapa de mensagens.|
|[FORWARD_NOTIFICATIONS](#forward_notifications)|Encaminha mensagens de notificação para a janela pai.|
|[MESSAGE_HANDLER](#message_handler)|Mapeia uma mensagem do Windows para uma função de manipulador.|
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mapeia um intervalo contíguo de mensagens do Windows para uma função de manipulador.|
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no código de notificação.|
|[NOTIFY_HANDLER](#notify_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no identificador de controle.|
|[NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no código de notificação e um intervalo contíguo de identificadores de controle.|
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECT_NOTIFICATIONS](#reflect_notifications)|Reflete as mensagens de notificação de volta para a janela que as enviou.|
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e no identificador do item de menu, controle ou acelerador.|
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no identificador de controle.|
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="alt_msg_map"></a>ALT_MSG_MAP

Marca o início de um mapa de mensagens alternativo.

```
ALT_MSG_MAP(msgMapID)
```

### <a name="parameters"></a>parâmetros

*msgMapID*<br/>
no O identificador do mapa de mensagens.

### <a name="remarks"></a>Comentários

A ATL identifica cada mapa de mensagens por um número. O mapa de mensagem padrão (declarado com a macro BEGIN_MSG_MAP) é identificado por 0. Um mapa de mensagens alternativo é identificado por *msgMapID*.

Os mapas de mensagens são usados para processar mensagens enviadas a uma janela. Por exemplo, [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) permite que você especifique o identificador de um mapa de mensagens no objeto contentor. [CContainedWindow:: WindowProc](ccontainedwindowt-class.md#windowproc) usa esse mapa de mensagens para direcionar as mensagens da janela contidas para a função de manipulador apropriada ou para outro mapa de mensagens. Para obter uma lista de macros que declaram funções de manipulador, consulte [BEGIN_MSG_MAP](#begin_msg_map).

Sempre inicie um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagem alternativos subsequentes.

A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Observe que sempre há exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra o mapa de mensagem padrão e um mapa de mensagem alternativo, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O exemplo a seguir mostra dois mapas de mensagens alternativos. O mapa de mensagem padrão está vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="begin_msg_map"></a>BEGIN_MSG_MAP

Marca o início do mapa de mensagens padrão.

```
BEGIN_MSG_MAP(theClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
no O nome da classe que contém o mapa de mensagens.

### <a name="remarks"></a>Comentários

[CWindowImpl:: WindowProc](cwindowimpl-class.md#windowproc) usa o mapa de mensagem padrão para processar mensagens enviadas para a janela. O mapa de mensagens direciona as mensagens para a função de manipulador apropriada ou para outro mapa de mensagens.

As macros a seguir mapeiam uma mensagem para uma função de manipulador. Essa função deve ser definida na *classe*.

|Macro|DESCRIÇÃO|
|-----------|-----------------|
|[MESSAGE_HANDLER](#message_handler)|Mapeia uma mensagem do Windows para uma função de manipulador.|
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mapeia um intervalo contíguo de mensagens do Windows para uma função de manipulador.|
|[COMMAND_HANDLER](#command_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no código de notificação e no identificador do item de menu, controle ou acelerador.|
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|
|[COMMAND_CODE_HANDLER](#command_handler)|Mapeia uma mensagem de WM_COMMAND para uma função de manipulador, com base no código de notificação.|
|[COMMAND_RANGE_HANDLER](#command_range_handler)|Mapeia um intervalo contíguo de mensagens de WM_COMMAND para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|
|[NOTIFY_HANDLER](#notify_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no identificador de controle.|
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma mensagem de WM_NOTIFY para uma função de manipulador, com base no código de notificação.|
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia um intervalo contíguo de mensagens de WM_NOTIFY para uma função de manipulador, com base no identificador de controle.|

As macros a seguir direcionam mensagens para outro mapa de mensagens. Esse processo é chamado de "encadeamento".

|Macro|DESCRIÇÃO|
|-----------|-----------------|
|[CHAIN_MSG_MAP](#chain_msg_map)|Encadeia para o mapa de mensagem padrão na classe base.|
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Encadeia para o mapa de mensagem padrão em um membro de dados da classe.|
|[CHAIN_MSG_MAP_ALT](#chain_msg_map_alt)|Encadeia-se a um mapa de mensagens alternativo na classe base.|
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Encadeia-se a um mapa de mensagens alternativo em um membro de dados da classe.|
|[CHAIN_MSG_MAP_DYNAMIC](#chain_msg_map_dynamic)|Encadeia para o mapa de mensagem padrão em outra classe em tempo de execução.|

As macros a seguir direcionam mensagens "refletidas" da janela pai. Por exemplo, um controle normalmente envia mensagens de notificação para sua janela pai para processamento, mas a janela pai pode refletir a mensagem de volta para o controle.

|Macro|DESCRIÇÃO|
|-----------|-----------------|
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e no identificador do item de menu, controle ou acelerador.|
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no identificador do item de menu, controle ou acelerador.|
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no identificador de controle.|
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base em um intervalo contíguo de identificadores de controle.|
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e em um intervalo contíguo de identificadores de controle.|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#102](../../atl/codesnippet/cpp/message-map-macros-atl_3.h)]

Quando um objeto de `CMyExtWindow` recebe uma mensagem de WM_PAINT, a mensagem é direcionada para `CMyExtWindow::OnPaint` para o processamento real. Se `OnPaint` indicar que a mensagem requer processamento adicional, a mensagem será direcionada para o mapa de mensagem padrão em `CMyBaseWindow`.

Além do mapa de mensagens padrão, você pode definir um mapa de mensagens alternativo com [ALT_MSG_MAP](#alt_msg_map). Sempre inicie um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagem alternativos subsequentes. O exemplo a seguir mostra o mapa de mensagem padrão e um mapa de mensagem alternativo, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O exemplo a seguir mostra dois mapas de mensagens alternativos. O mapa de mensagem padrão está vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Observe que sempre há exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="chain_msg_map_alt"></a>CHAIN_MSG_MAP_ALT

Define uma entrada em um mapa de mensagens.

```
CHAIN_MSG_MAP_ALT(theChainClass, msgMapID)
```

### <a name="parameters"></a>parâmetros

*theChainClass*<br/>
no O nome da classe base que contém o mapa de mensagens.

*msgMapID*<br/>
no O identificador do mapa de mensagens.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_ALT direciona mensagens para um mapa de mensagens alternativo em uma classe base. Você deve ter declarado esse mapa de mensagens alternativo com [ALT_MSG_MAP (msgMapID)](#alt_msg_map). Para direcionar mensagens para um mapa de mensagens padrão de uma classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use CHAIN_MSG_MAP. Para obter um exemplo, consulte [CHAIN_MSG_MAP](#chain_msg_map).

> [!NOTE]
>  Sempre inicie um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com ALT_MSG_MAP. A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="chain_msg_map_alt_member"></a>CHAIN_MSG_MAP_ALT_MEMBER

Define uma entrada em um mapa de mensagens.

```
CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID)
```

### <a name="parameters"></a>parâmetros

*theChainMember*<br/>
no O nome do membro de dados que contém o mapa de mensagens.

*msgMapID*<br/>
no O identificador do mapa de mensagens.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_ALT_MEMBER direciona mensagens para um mapa de mensagens alternativo em um membro de dados. Você deve ter declarado esse mapa de mensagens alternativo com [ALT_MSG_MAP (msgMapID)](#alt_msg_map). Para direcionar mensagens para o mapa de mensagens padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)), use CHAIN_MSG_MAP_MEMBER. Para obter um exemplo, consulte [CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member).

> [!NOTE]
>  Sempre inicie um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com ALT_MSG_MAP. A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="chain_msg_map"></a>CHAIN_MSG_MAP

Define uma entrada em um mapa de mensagens.

```
CHAIN_MSG_MAP(theChainClass)
```

### <a name="parameters"></a>parâmetros

*theChainClass*<br/>
no O nome da classe base que contém o mapa de mensagens.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP direciona mensagens para um mapa de mensagens padrão da classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para um mapa de mensagens alternativo de uma classe base (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT](#chain_msg_map_alt).

> [!NOTE]
>  Sempre inicie um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com ALT_MSG_MAP. A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#107](../../atl/codesnippet/cpp/message-map-macros-atl_4.h)]

Este exemplo ilustra o seguinte:

- Se um procedimento de janela estiver usando o mapa de mensagens padrão do `CMyClass`e `OnPaint` não tratar uma mensagem, a mensagem será direcionada para o mapa de mensagens padrão de `CMyBaseClass`para processamento.

- Se um procedimento de janela estiver usando o primeiro mapa de mensagens alternativo no `CMyClass`, todas as mensagens serão direcionadas para o mapa de mensagens padrão de `CMyBaseClass`.

- Se um procedimento de janela estiver usando o segundo mapa de mensagens alternativo do `CMyClass`e `OnChar` não tratar uma mensagem, a mensagem será direcionada para o mapa de mensagens alternativo especificado no `CMyBaseClass`. `CMyBaseClass` deve ter declarado este mapa de mensagem com ALT_MSG_MAP (1).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="chain_msg_map_dynamic"></a>CHAIN_MSG_MAP_DYNAMIC

Define uma entrada em um mapa de mensagens.

```
CHAIN_MSG_MAP_DYNAMIC(dynaChainID)
```

### <a name="parameters"></a>parâmetros

*dynaChainID*<br/>
no O identificador exclusivo para o mapa de mensagens de um objeto.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_DYNAMIC direciona mensagens, em tempo de execução, para o mapa de mensagem padrão em outro objeto. O objeto e seu mapa de mensagens são associados a *dynaChainID*, que você define por meio de [CDynamicChain:: SetChainEntry](cdynamicchain-class.md#setchainentry). Você deve derivar sua classe de `CDynamicChain` para usar CHAIN_MSG_MAP_DYNAMIC. Para obter um exemplo, consulte a visão geral do [CDynamicChain](../../atl/reference/cdynamicchain-class.md) .

> [!NOTE]
>  Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com ALT_MSG_MAP. A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="chain_msg_map_member"></a>CHAIN_MSG_MAP_MEMBER

Define uma entrada em um mapa de mensagens.

```
CHAIN_MSG_MAP_MEMBER(theChainMember)
```

### <a name="parameters"></a>parâmetros

*theChainMember*<br/>
no O nome do membro de dados que contém o mapa de mensagens.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_MEMBER direciona mensagens para o mapa de mensagens padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagens alternativas de um membro de dados (declarado com [ALT_MSG_MAP](#alt_msg_map)), use [CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member).

> [!NOTE]
>  Sempre inicie um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com ALT_MSG_MAP. A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#108](../../atl/codesnippet/cpp/message-map-macros-atl_5.h)]

Este exemplo ilustra o seguinte:

- Se um procedimento de janela estiver usando o mapa de mensagens padrão do `CMyClass`e `OnPaint` não tratar uma mensagem, a mensagem será direcionada para o mapa de mensagens padrão de `m_obj`para processamento.

- Se um procedimento de janela estiver usando o primeiro mapa de mensagens alternativo no `CMyClass`, todas as mensagens serão direcionadas para o mapa de mensagens padrão de `m_obj`.

- Se um procedimento de janela estiver usando o segundo mapa de mensagens alternativo do `CMyClass`e `OnChar` não tratar uma mensagem, a mensagem será direcionada para o mapa de mensagens alternativo especificado de `m_obj`. A classe `CMyContainedClass` deve ter declarado esse mapa de mensagens com ALT_MSG_MAP (1).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="command_code_handler"></a>COMMAND_CODE_HANDLER

Semelhante a [COMMAND_HANDLER](#command_handler), mas mapeia uma mensagem de [WM_COMMAND](/windows/win32/menurc/wm-command) com base apenas no código de notificação.

```
COMMAND_CODE_HANDLER(code, func)
```

### <a name="parameters"></a>parâmetros

*code*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="command_handler"></a>COMMAND_HANDLER

Define uma entrada em um mapa de mensagens.

```
COMMAND_HANDLER(id, code, func)
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do item de menu, controle ou acelerador.

*code*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

COMMAND_HANDLER mapeia uma mensagem de [WM_COMMAND](/windows/win32/menurc/wm-command) para a função de manipulador especificada, com base no código de notificação e no identificador de controle. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#119](../../atl/codesnippet/cpp/message-map-macros-atl_6.h)]

Qualquer função especificada em uma macro COMMAND_HANDLER deve ser definida da seguinte maneira:

`LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);`

O mapa de mensagens define `bHandled` como TRUE antes que `CommandHandler` seja chamado. Se `CommandHandler` não tratar totalmente a mensagem, ela deverá definir `bHandled` como FALSE para indicar que a mensagem precisa de processamento adicional.

> [!NOTE]
>  Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com [ALT_MSG_MAP](#alt_msg_map). A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de COMMAND_HANDLER, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear uma mensagem de WM_COMMAND sem considerar um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_COMMAND, OnHandlerFunction)` direcionará todas as mensagens de WM_COMMAND para `OnHandlerFunction`.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="command_id_handler"></a>COMMAND_ID_HANDLER

Semelhante a [COMMAND_HANDLER](#command_handler), mas mapeia uma mensagem de [WM_COMMAND](/windows/win32/menurc/wm-command) com base apenas no identificador do item de menu, controle ou acelerador.

```
COMMAND_ID_HANDLER(id, func)
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do item de menu, controle ou acelerador que envia a mensagem.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="command_range_code_handler"></a>COMMAND_RANGE_CODE_HANDLER

Semelhante a [COMMAND_RANGE_HANDLER](#command_range_handler), mas mapeia [WM_COMMAND](/windows/win32/menurc/wm-command) mensagens com um código de notificação específico de um intervalo de controles para uma única função de manipulador.

```
COMMAND_RANGE_CODE_HANDLER(idFirst, idLast, code, func)
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*code*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo é baseado no identificador do item de menu, controle ou acelerador que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="command_range_handler"></a>COMMAND_RANGE_HANDLER

Semelhante a [COMMAND_HANDLER](#command_handler), mas mapeia [WM_COMMAND](/windows/win32/menurc/wm-command) mensagens de um intervalo de controles para uma única função de manipulador.

```
COMMAND_RANGE_HANDLER( idFirst, idLast, func)
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo é baseado no identificador do item de menu, controle ou acelerador que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="declare_empty_msg_map"></a>DECLARE_EMPTY_MSG_MAP

Declara um mapa de mensagens vazio.

```
DECLARE_EMPTY_MSG_MAP()
```

### <a name="remarks"></a>Comentários

DECLARE_EMPTY_MSG_MAP é uma macro de conveniência que chama as macros [BEGIN_MSG_MAP](#begin_msg_map) e [END_MSG_MAP](#end_msg_map) para criar um mapa de mensagens vazio:

[!code-cpp[NVC_ATL_Windowing#122](../../atl/codesnippet/cpp/message-map-macros-atl_7.h)]

##  <a name="default_reflection_handler"></a>DEFAULT_REFLECTION_HANDLER

Fornece um manipulador padrão para a janela filho (controle) que receberá mensagens refletidas; o manipulador passará corretamente mensagens sem tratamento para `DefWindowProc`.

```
DEFAULT_REFLECTION_HANDLER()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="end_msg_map"></a>END_MSG_MAP

Marca o final de um mapa de mensagens.

```
END_MSG_MAP()
```

### <a name="remarks"></a>Comentários

Sempre use a macro [BEGIN_MSG_MAP](#begin_msg_map) para marcar o início de um mapa de mensagens. Use [ALT_MSG_MAP](#alt_msg_map) para declarar mapas de mensagem alternativos subsequentes.

Observe que sempre há exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra o mapa de mensagem padrão e um mapa de mensagem alternativo, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O exemplo a seguir mostra dois mapas de mensagens alternativos. O mapa de mensagem padrão está vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="forward_notifications"></a>FORWARD_NOTIFICATIONS

Encaminha mensagens de notificação para a janela pai.

```
FORWARD_NOTIFICATIONS()
```

### <a name="remarks"></a>Comentários

Especifique essa macro como parte do seu mapa de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="message_handler"></a>MESSAGE_HANDLER

Define uma entrada em um mapa de mensagens.

```
MESSAGE_HANDLER( msg, func )
```

### <a name="parameters"></a>parâmetros

*MSG*<br/>
no A mensagem do Windows.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

MESSAGE_HANDLER mapeia uma mensagem do Windows para a função de manipulador especificada.

Qualquer função especificada em uma macro MESSAGE_HANDLER deve ser definida da seguinte maneira:

`LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);`

O mapa de mensagens define `bHandled` como TRUE antes que `MessageHandler` seja chamado. Se `MessageHandler` não tratar totalmente a mensagem, ela deverá definir `bHandled` como FALSE para indicar que a mensagem precisa de processamento adicional.

> [!NOTE]
>  Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com [ALT_MSG_MAP](#alt_msg_map). A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de MESSAGE_HANDLER, você pode usar [COMMAND_HANDLER](#command_handler) e [NOTIFY_HANDLER](#notify_handler) para mapear mensagens [WM_COMMAND](/windows/win32/menurc/wm-command) e [WM_NOTIFY](/windows/win32/controls/wm-notify) , respectivamente.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#129](../../atl/codesnippet/cpp/message-map-macros-atl_8.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="message_range_handler"></a>MESSAGE_RANGE_HANDLER

Semelhante a [MESSAGE_HANDLER](#message_handler), mas mapeia uma variedade de mensagens do Windows para uma única função de manipulador.

```
MESSAGE_RANGE_HANDLER( msgFirst, msgLast, func )
```

### <a name="parameters"></a>parâmetros

*msgFirst*<br/>
no Marca o início de um intervalo contíguo de mensagens.

*msgLast*<br/>
no Marca o final de um intervalo contíguo de mensagens.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="notify_code_handler"></a>NOTIFY_CODE_HANDLER

Semelhante a [NOTIFY_HANDLER](#notify_handler), mas mapeia uma mensagem de [WM_NOTIFY](/windows/win32/controls/wm-notify) com base apenas no código de notificação.

```
NOTIFY_CODE_HANDLER(cd, func)
```

### <a name="parameters"></a>parâmetros

*cd*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="notify_handler"></a>NOTIFY_HANDLER

Define uma entrada em um mapa de mensagens.

```
NOTIFY_HANDLER( id, cd, func )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do controle que envia a mensagem.

*cd*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

NOTIFY_HANDLER mapeia uma mensagem de [WM_NOTIFY](/windows/win32/controls/wm-notify) para a função de manipulador especificada, com base no código de notificação e no identificador de controle.

Qualquer função especificada em uma macro NOTIFY_HANDLER deve ser definida da seguinte maneira:

`LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);`

O mapa de mensagens define `bHandled` como TRUE antes que `NotifyHandler` seja chamado. Se `NotifyHandler` não tratar totalmente a mensagem, ela deverá definir `bHandled` como FALSE para indicar que a mensagem precisa de processamento adicional.

> [!NOTE]
>  Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagem alternativos subsequentes com [ALT_MSG_MAP](#alt_msg_map). A macro [END_MSG_MAP](#end_msg_map) marca o final do mapa de mensagens. Cada mapa de mensagens deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de NOTIFY_HANDLER, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear uma mensagem de WM_NOTIFY sem considerar um identificador ou código. Nesse caso, `MESSAGE_HANDLER(WM_NOTIFY, OnHandlerFunction)` direcionará todas as mensagens de WM_NOTIFY para `OnHandlerFunction`.

Para obter mais informações sobre como usar mapas de mensagens na ATL, consulte [mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#130](../../atl/codesnippet/cpp/message-map-macros-atl_9.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="notify_id_handler"></a>NOTIFY_ID_HANDLER

Semelhante a [NOTIFY_HANDLER](#notify_handler), mas mapeia uma mensagem de [WM_NOTIFY](/windows/win32/controls/wm-notify) com base apenas no identificador de controle.

```
NOTIFY_ID_HANDLER( id, func )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do controle que envia a mensagem.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="notify_range_code_handler"></a>NOTIFY_RANGE_CODE_HANDLER

Semelhante a [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia [WM_NOTIFY](/windows/win32/controls/wm-notify) mensagens com um código de notificação específico de um intervalo de controles para uma única função de manipulador.

```
NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*cd*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo se baseia no identificador do controle que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="notify_range_handler"></a>NOTIFY_RANGE_HANDLER

Semelhante a [NOTIFY_HANDLER](#notify_handler), mas mapeia [WM_NOTIFY](/windows/win32/controls/wm-notify) mensagens de um intervalo de controles para uma única função de manipulador.

```
NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esse intervalo se baseia no identificador do controle que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflect_notifications"></a>REFLECT_NOTIFICATIONS

Reflete as mensagens de notificação de volta para a janela filho (controle) que as enviou.

```
REFLECT_NOTIFICATIONS()
```

### <a name="remarks"></a>Comentários

Especifique essa macro como parte do mapa de mensagens da janela pai.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_command_code_handler"></a>REFLECTED_COMMAND_CODE_HANDLER

Semelhante a [COMMAND_CODE_HANDLER](#command_code_handler), mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_CODE_HANDLER( code, func )
```

### <a name="parameters"></a>parâmetros

*code*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_command_handler"></a>REFLECTED_COMMAND_HANDLER

Semelhante a [COMMAND_HANDLER](#command_handler), mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_HANDLER( id, code, func )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do item de menu, controle ou acelerador.

*code*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_command_id_handler"></a>REFLECTED_COMMAND_ID_HANDLER

Semelhante a [COMMAND_ID_HANDLER](#command_id_handler), mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_ID_HANDLER( id, func )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do item de menu, controle ou acelerador.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_command_range_code_handler"></a>REFLECTED_COMMAND_RANGE_CODE_HANDLER

Semelhante a [COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler), mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_RANGE_CODE_HANDLER( idFirst, idLast, code, func )
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*code*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_command_range_handler"></a>REFLECTED_COMMAND_RANGE_HANDLER

Semelhante a [COMMAND_RANGE_HANDLER](#command_range_handler), mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_notify_code_handler"></a>REFLECTED_NOTIFY_CODE_HANDLER

Semelhante a [NOTIFY_CODE_HANDLER](#notify_code_handler), mas mapeia as notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_CODE_HANDLER_EX( cd, func )
```

### <a name="parameters"></a>parâmetros

*cd*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_notify_handler"></a>REFLECTED_NOTIFY_HANDLER

Semelhante a [NOTIFY_HANDLER](#notify_handler), mas mapeia as notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_HANDLER( id, cd, func )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do item de menu, controle ou acelerador.

*cd*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_notify_id_handler"></a>REFLECTED_NOTIFY_ID_HANDLER

Semelhante a [NOTIFY_ID_HANDLER](#notify_id_handler), mas mapeia as notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_ID_HANDLER( id, func )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no O identificador do item de menu, controle ou acelerador.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_notify_range_code_handler"></a>REFLECTED_NOTIFY_RANGE_CODE_HANDLER

Semelhante a [NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler), mas mapeia as notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*cd*<br/>
no O código de notificação.

*func*<br/>
no O nome da função do manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="reflected_notify_range_handler"></a>REFLECTED_NOTIFY_RANGE_HANDLER

Semelhante a [NOTIFY_RANGE_HANDLER](#notify_range_handler), mas mapeia as notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>parâmetros

*idFirst*<br/>
no Marca o início de um intervalo contíguo de identificadores de controle.

*idLast*<br/>
no Marca o final de um intervalo contíguo de identificadores de controle.

*func*<br/>
no O nome da função do manipulador de mensagens.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)

---
title: Macros do mapa de mensagens (ATL)
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
ms.openlocfilehash: 157812fa6625869c86dd8a27156a2970a3dc8d4a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326225"
---
# <a name="message-map-macros-atl"></a>Macros do mapa de mensagens (ATL)

Essas macros definem mapas de mensagens e entradas.

|||
|-|-|
|[Alt_msg_map](#alt_msg_map)|Marca o início de um mapa de mensagens alternativo.|
|[Begin_msg_map](#begin_msg_map)|Marca o início do mapa de mensagens padrão.|
|[Chain_msg_map_alt](#chain_msg_map_alt)|Correntes para um mapa de mensagem alternativo na classe base.|
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Correntes para um mapa de mensagem alternativo em um membro de dados da classe.|
|[Chain_msg_map](#chain_msg_map)|Correntes ao mapa de mensagem padrão na classe base.|
|[Chain_msg_map_dynamic](#chain_msg_map_dynamic)|Correntes no mapa de mensagens em outra classe em tempo de execução.|
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Correntes ao mapa de mensagem padrão em um membro de dados da classe.|
|[COMMAND_CODE_HANDLER](#command_code_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no código de notificação.|
|[Command_handler](#command_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no código de notificação e no identificador do item, controle ou acelerador do menu.|
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no identificador do item, controle ou acelerador do menu.|
|[COMMAND_RANGE_CODE_HANDLER](#command_range_code_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no código de notificação e em uma gama contígua de identificadores de controle.|
|[Command_range_handler](#command_range_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base em uma gama contígua de identificadores de controle.|
|[DECLARE_EMPTY_MSG_MAP](#declare_empty_msg_map)|Implementa um mapa de mensagem vazio.|
|[DEFAULT_REFLECTION_HANDLER](#default_reflection_handler)|Fornece um manipulador padrão para mensagens refletidas que não são tratadas de outra forma.|
|[End_msg_map](#end_msg_map)|Marca o fim de um mapa de mensagens.|
|[FORWARD_NOTIFICATIONS](#forward_notifications)|Encaminha mensagens de notificação para a janela pai.|
|[Message_handler](#message_handler)|Mapeia uma mensagem do Windows para uma função de manipulador.|
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mapeia uma gama contígua de mensagens do Windows para uma função de manipulador.|
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no código de notificação.|
|[Notify_handler](#notify_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no identificador de controle.|
|[NOTIFY_RANGE_CODE_HANDLER](#notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no código de notificação e em uma gama contígua de identificadores de controle.|
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base em uma gama contígua de identificadores de controle.|
|[REFLECT_NOTIFICATIONS](#reflect_notifications)|Reflete mensagens de notificação de volta para a janela que as enviou.|
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e no identificador do item, controle ou acelerador do menu.|
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no identificador do item, controle ou acelerador do menu.|
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia uma mensagem de WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e em uma gama contígua de identificadores de controle.|
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base em uma gama contígua de identificadores de controle.|
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia uma mensagem de WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no identificador de controle.|
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e em uma gama contígua de identificadores de controle.|
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base em uma gama contígua de identificadores de controle.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="alt_msg_map"></a><a name="alt_msg_map"></a>Alt_msg_map

Marca o início de um mapa de mensagens alternativo.

```
ALT_MSG_MAP(msgMapID)
```

### <a name="parameters"></a>Parâmetros

*Msgmapid*<br/>
[em] O identificador do mapa da mensagem.

### <a name="remarks"></a>Comentários

O ATL identifica cada mapa de mensagem por um número. O mapa de mensagem padrão (declarado com a BEGIN_MSG_MAP macro) é identificado por 0. Um mapa de mensagem alternativo é identificado pelo *msgMapID*.

Mapas de mensagens são usados para processar mensagens enviadas para uma janela. Por exemplo, [cContainedWindow](../../atl/reference/ccontainedwindowt-class.md) permite especificar o identificador de um mapa de mensagem no objeto contendo. [CContainedWindow::WindowProc](ccontainedwindowt-class.md#windowproc) usa esse mapa de mensagem para direcionar as mensagens da janela contida para a função de manipulador apropriado ou para outro mapa de mensagem. Para obter uma lista de macros que declaram funções de manipulador, consulte [BEGIN_MSG_MAP](#begin_msg_map).

Sempre comece um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes.

A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Note que há sempre exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra o mapa de mensagem padrão e um mapa de mensagem alternativo, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O próximo exemplo mostra dois mapas de mensagens alternativos. O mapa de mensagem padrão está vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="begin_msg_map"></a><a name="begin_msg_map"></a>Begin_msg_map

Marca o início do mapa de mensagens padrão.

```
BEGIN_MSG_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
[em] O nome da classe que contém o mapa de mensagens.

### <a name="remarks"></a>Comentários

[CWindowImpl::WindowProc](cwindowimpl-class.md#windowproc) usa o mapa de mensagem padrão para processar mensagens enviadas à janela. O mapa de mensagens direciona as mensagens para a função de manipulador apropriado ou para outro mapa de mensagem.

As seguintes macros mapeiam uma mensagem para uma função de manipulador. Esta função deve ser definida *noClass*.

|Macro|Descrição|
|-----------|-----------------|
|[Message_handler](#message_handler)|Mapeia uma mensagem do Windows para uma função de manipulador.|
|[MESSAGE_RANGE_HANDLER](#message_range_handler)|Mapeia uma gama contígua de mensagens do Windows para uma função de manipulador.|
|[Command_handler](#command_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no código de notificação e no identificador do item, controle ou acelerador do menu.|
|[COMMAND_ID_HANDLER](#command_id_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no identificador do item, controle ou acelerador do menu.|
|[COMMAND_CODE_HANDLER](#command_handler)|Mapeia uma mensagem WM_COMMAND para uma função de manipulador, com base no código de notificação.|
|[Command_range_handler](#command_range_handler)|Mapeia uma gama contígua de mensagens WM_COMMAND para uma função de manipulador, com base no identificador do item, controle ou acelerador do menu.|
|[Notify_handler](#notify_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[NOTIFY_ID_HANDLER](#notify_id_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no identificador de controle.|
|[NOTIFY_CODE_HANDLER](#notify_code_handler)|Mapeia uma mensagem WM_NOTIFY para uma função de manipulador, com base no código de notificação.|
|[NOTIFY_RANGE_HANDLER](#notify_range_handler)|Mapeia um intervalo contíguo de mensagens WM_NOTIFY para uma função de manipulador, com base no identificador de controle.|

As seguintes macros direcionam mensagens para outro mapa de mensagem. Esse processo é chamado de "encadeamento".

|Macro|Descrição|
|-----------|-----------------|
|[Chain_msg_map](#chain_msg_map)|Correntes ao mapa de mensagem padrão na classe base.|
|[CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member)|Correntes ao mapa de mensagem padrão em um membro de dados da classe.|
|[Chain_msg_map_alt](#chain_msg_map_alt)|Correntes para um mapa de mensagem alternativo na classe base.|
|[CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member)|Correntes para um mapa de mensagem alternativo em um membro de dados da classe.|
|[Chain_msg_map_dynamic](#chain_msg_map_dynamic)|Acorrenta o mapa de mensagem padrão em outra classe em tempo de execução.|

As seguintes macros direcionam mensagens "refletidas" da janela pai. Por exemplo, um controle normalmente envia mensagens de notificação para sua janela pai para processamento, mas a janela pai pode refletir a mensagem de volta ao controle.

|Macro|Descrição|
|-----------|-----------------|
|[REFLECTED_COMMAND_HANDLER](#reflected_command_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e no identificador do item, controle ou acelerador do menu.|
|[REFLECTED_COMMAND_ID_HANDLER](#reflected_command_id_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no identificador do item, controle ou acelerador do menu.|
|[REFLECTED_COMMAND_CODE_HANDLER](#reflected_command_code_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_COMMAND_RANGE_HANDLER](#reflected_command_range_handler)|Mapeia uma mensagem WM_COMMAND refletida para uma função de manipulador, com base em uma gama contígua de identificadores de controle.|
|[REFLECTED_COMMAND_RANGE_CODE_HANDLER](#reflected_command_range_code_handler)|Mapeia uma mensagem de WM_COMMAND refletida para uma função de manipulador, com base no código de notificação e em uma gama contígua de identificadores de controle.|
|[REFLECTED_NOTIFY_HANDLER](#reflected_notify_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e no identificador de controle.|
|[REFLECTED_NOTIFY_ID_HANDLER](#reflected_notify_id_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no identificador de controle.|
|[REFLECTED_NOTIFY_CODE_HANDLER](#reflected_notify_code_handler)|Mapeia uma mensagem de WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação.|
|[REFLECTED_NOTIFY_RANGE_HANDLER](#reflected_notify_range_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base em uma gama contígua de identificadores de controle.|
|[REFLECTED_NOTIFY_RANGE_CODE_HANDLER](#reflected_notify_range_code_handler)|Mapeia uma mensagem WM_NOTIFY refletida para uma função de manipulador, com base no código de notificação e em uma gama contígua de identificadores de controle.|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#102](../../atl/codesnippet/cpp/message-map-macros-atl_3.h)]

Quando `CMyExtWindow` um objeto recebe uma mensagem `CMyExtWindow::OnPaint` WM_PAINT, a mensagem é direcionada para o processamento real. Se `OnPaint` indicar que a mensagem requer mais processamento, a mensagem será direcionada para o mapa de mensagem padrão em `CMyBaseWindow`.

Além do mapa de mensagem padrão, você pode definir um mapa de mensagem alternativo com [ALT_MSG_MAP](#alt_msg_map). Sempre comece um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes. O exemplo a seguir mostra o mapa de mensagem padrão e um mapa de mensagem alternativo, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O próximo exemplo mostra dois mapas de mensagens alternativos. O mapa de mensagem padrão está vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Note que há sempre exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="chain_msg_map_alt"></a><a name="chain_msg_map_alt"></a>Chain_msg_map_alt

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_ALT(theChainClass, msgMapID)
```

### <a name="parameters"></a>Parâmetros

*theChainClass*<br/>
[em] O nome da classe base contendo o mapa de mensagem.

*Msgmapid*<br/>
[em] O identificador do mapa da mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_ALT direciona mensagens para um mapa de mensagens alternativo em uma classe base. Você deve ter declarado este mapa de mensagem alternativo com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens para o mapa de mensagem padrão de uma classe base (declarado com [BEGIN_MSG_MAP),](#begin_msg_map)use CHAIN_MSG_MAP. Por exemplo, veja [CHAIN_MSG_MAP](#chain_msg_map).

> [!NOTE]
> Sempre comece um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com ALT_MSG_MAP. A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="chain_msg_map_alt_member"></a><a name="chain_msg_map_alt_member"></a>CHAIN_MSG_MAP_ALT_MEMBER

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID)
```

### <a name="parameters"></a>Parâmetros

*theChainMember*<br/>
[em] O nome do membro de dados que contém o mapa da mensagem.

*Msgmapid*<br/>
[em] O identificador do mapa da mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_ALT_MEMBER direciona mensagens para um mapa de mensagens alternativo em um membro de dados. Você deve ter declarado este mapa de mensagem alternativo com [ALT_MSG_MAP(msgMapID)](#alt_msg_map). Para direcionar mensagens para o mapa de mensagem padrão de um membro de dados (declarado com [BEGIN_MSG_MAP),](#begin_msg_map)use CHAIN_MSG_MAP_MEMBER. Por exemplo, veja [CHAIN_MSG_MAP_MEMBER](#chain_msg_map_member).

> [!NOTE]
> Sempre comece um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com ALT_MSG_MAP. A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="chain_msg_map"></a><a name="chain_msg_map"></a>Chain_msg_map

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP(theChainClass)
```

### <a name="parameters"></a>Parâmetros

*theChainClass*<br/>
[em] O nome da classe base contendo o mapa de mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP direciona mensagens para o mapa de mensagem padrão de uma classe base (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagens alternativas de uma classe base (declarado com [ALT_MSG_MAP),](#alt_msg_map)use [CHAIN_MSG_MAP_ALT](#chain_msg_map_alt).

> [!NOTE]
> Sempre comece um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com ALT_MSG_MAP. A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#107](../../atl/codesnippet/cpp/message-map-macros-atl_4.h)]

Este exemplo ilustra o seguinte:

- Se um procedimento `CMyClass`de janela estiver `OnPaint` usando o mapa de mensagem `CMyBaseClass`padrão e não manusear uma mensagem, a mensagem será direcionada para o mapa de mensagem padrão para processamento.

- Se um procedimento de janela estiver `CMyClass`usando o primeiro mapa `CMyBaseClass`de mensagem alternativa em , todas as mensagens são direcionadas para o mapa de mensagem padrão.

- Se um procedimento `CMyClass`de janela estiver usando `OnChar` o segundo mapa de mensagem alternativa e não `CMyBaseClass`manusear uma mensagem, a mensagem será direcionada para o mapa de mensagem alternativa especificado em . `CMyBaseClass`deve ter declarado este mapa de mensagem com ALT_MSG_MAP(1).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="chain_msg_map_dynamic"></a><a name="chain_msg_map_dynamic"></a>Chain_msg_map_dynamic

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_DYNAMIC(dynaChainID)
```

### <a name="parameters"></a>Parâmetros

*dynaChainID*<br/>
[em] O identificador exclusivo para o mapa de mensagens de um objeto.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_DYNAMIC direciona mensagens, em tempo de execução, para o mapa de mensagens padrão em outro objeto. O objeto e seu mapa de mensagens estão associados ao *dynaChainID*, que você define através de [CDynamicChain::SetChainEntry](cdynamicchain-class.md#setchainentry). Você deve derivar `CDynamicChain` sua classe para usar CHAIN_MSG_MAP_DYNAMIC. Por exemplo, veja a visão geral do [CDynamicChain.](../../atl/reference/cdynamicchain-class.md)

> [!NOTE]
> Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com ALT_MSG_MAP. A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="chain_msg_map_member"></a><a name="chain_msg_map_member"></a>CHAIN_MSG_MAP_MEMBER

Define uma entrada em um mapa de mensagem.

```
CHAIN_MSG_MAP_MEMBER(theChainMember)
```

### <a name="parameters"></a>Parâmetros

*theChainMember*<br/>
[em] O nome do membro de dados que contém o mapa da mensagem.

### <a name="remarks"></a>Comentários

CHAIN_MSG_MAP_MEMBER direciona mensagens para o mapa de mensagem padrão de um membro de dados (declarado com [BEGIN_MSG_MAP](#begin_msg_map)). Para direcionar mensagens para o mapa de mensagens alternativas de um membro de dados (declarado com [ALT_MSG_MAP),](#alt_msg_map)use [CHAIN_MSG_MAP_ALT_MEMBER](#chain_msg_map_alt_member).

> [!NOTE]
> Sempre comece um mapa de mensagens com BEGIN_MSG_MAP. Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com ALT_MSG_MAP. A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#108](../../atl/codesnippet/cpp/message-map-macros-atl_5.h)]

Este exemplo ilustra o seguinte:

- Se um procedimento `CMyClass`de janela estiver `OnPaint` usando o mapa de mensagem `m_obj`padrão e não manusear uma mensagem, a mensagem será direcionada para o mapa de mensagem padrão para processamento.

- Se um procedimento de janela estiver `CMyClass`usando o primeiro mapa `m_obj`de mensagem alternativa em , todas as mensagens são direcionadas para o mapa de mensagem padrão.

- Se um procedimento `CMyClass`de janela estiver usando `OnChar` o segundo mapa de mensagem alternativa e não `m_obj`manusear uma mensagem, a mensagem será direcionada para o mapa de mensagem alternativa especificado de . A `CMyContainedClass` classe deve ter declarado este mapa de mensagem com ALT_MSG_MAP(1).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="command_code_handler"></a><a name="command_code_handler"></a>COMMAND_CODE_HANDLER

Semelhante ao [COMMAND_HANDLER,](#command_handler)mas mapeia uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) baseada apenas no código de notificação.

```
COMMAND_CODE_HANDLER(code, func)
```

### <a name="parameters"></a>Parâmetros

*Código*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="command_handler"></a><a name="command_handler"></a>Command_handler

Define uma entrada em um mapa de mensagem.

```
COMMAND_HANDLER(id, code, func)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do item do menu, controle ou acelerador.

*Código*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

COMMAND_HANDLER mapeia uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) para a função de manipulador especificada, com base no código de notificação e no identificador de controle. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#119](../../atl/codesnippet/cpp/message-map-macros-atl_6.h)]

Qualquer função especificada em uma COMMAND_HANDLER macro deve ser definida da seguinte forma:

`LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);`

O mapa `bHandled` de mensagem é configurado como TRUE antes `CommandHandler` de ser chamado. Se `CommandHandler` não manusear totalmente a `bHandled` mensagem, ela deve ser definida como FALSE para indicar que a mensagem precisa de mais processamento.

> [!NOTE]
> Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com [ALT_MSG_MAP](#alt_msg_map). A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de COMMAND_HANDLER, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear uma mensagem WM_COMMAND sem levar em conta um identificador ou código. Neste caso, `MESSAGE_HANDLER(WM_COMMAND, OnHandlerFunction)` direcionará todas as `OnHandlerFunction`WM_COMMAND mensagens para .

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="command_id_handler"></a><a name="command_id_handler"></a>COMMAND_ID_HANDLER

Semelhante ao [COMMAND_HANDLER,](#command_handler)mas mapeia uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) baseada apenas no identificador do item, controle ou acelerador do menu.

```
COMMAND_ID_HANDLER(id, func)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do item do menu, controle ou acelerador que envia a mensagem.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="command_range_code_handler"></a><a name="command_range_code_handler"></a>COMMAND_RANGE_CODE_HANDLER

Semelhante ao [COMMAND_RANGE_HANDLER,](#command_range_handler)mas mapeia [WM_COMMAND](/windows/win32/menurc/wm-command) mensagens com um código de notificação específico de uma série de controles para uma única função de manipulador.

```
COMMAND_RANGE_CODE_HANDLER(idFirst, idLast, code, func)
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*Código*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esta faixa é baseada no identificador do item do menu, controle ou acelerador que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="command_range_handler"></a><a name="command_range_handler"></a>Command_range_handler

Semelhante ao [COMMAND_HANDLER,](#command_handler)mas mapeia [WM_COMMAND](/windows/win32/menurc/wm-command) mensagens de uma série de controles para uma única função de manipulador.

```
COMMAND_RANGE_HANDLER( idFirst, idLast, func)
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Esta faixa é baseada no identificador do item do menu, controle ou acelerador que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="declare_empty_msg_map"></a><a name="declare_empty_msg_map"></a>DECLARE_EMPTY_MSG_MAP

Declara um mapa de mensagem vazio.

```
DECLARE_EMPTY_MSG_MAP()
```

### <a name="remarks"></a>Comentários

DECLARE_EMPTY_MSG_MAP é uma macro de conveniência que chama as macros [BEGIN_MSG_MAP](#begin_msg_map) e [END_MSG_MAP](#end_msg_map) para criar um mapa de mensagem vazio:

[!code-cpp[NVC_ATL_Windowing#122](../../atl/codesnippet/cpp/message-map-macros-atl_7.h)]

## <a name="default_reflection_handler"></a><a name="default_reflection_handler"></a>DEFAULT_REFLECTION_HANDLER

Fornece um manipulador padrão para a janela filho (controle) que receberá mensagens refletidas; o manipulador passará corretamente mensagens `DefWindowProc`não manuseadas para .

```
DEFAULT_REFLECTION_HANDLER()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="end_msg_map"></a><a name="end_msg_map"></a>End_msg_map

Marca o fim de um mapa de mensagens.

```
END_MSG_MAP()
```

### <a name="remarks"></a>Comentários

Use sempre a [macro BEGIN_MSG_MAP](#begin_msg_map) para marcar o início de um mapa de mensagens. Use [ALT_MSG_MAP](#alt_msg_map) para declarar mapas de mensagens alternativas subseqüentes.

Note que há sempre exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra o mapa de mensagem padrão e um mapa de mensagem alternativo, cada um contendo uma função de manipulador:

[!code-cpp[NVC_ATL_Windowing#98](../../atl/codesnippet/cpp/message-map-macros-atl_1.h)]

O próximo exemplo mostra dois mapas de mensagens alternativos. O mapa de mensagem padrão está vazio.

[!code-cpp[NVC_ATL_Windowing#99](../../atl/codesnippet/cpp/message-map-macros-atl_2.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="forward_notifications"></a><a name="forward_notifications"></a>FORWARD_NOTIFICATIONS

Encaminha mensagens de notificação para a janela pai.

```
FORWARD_NOTIFICATIONS()
```

### <a name="remarks"></a>Comentários

Especifique esta macro como parte do mapa de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="message_handler"></a><a name="message_handler"></a>Message_handler

Define uma entrada em um mapa de mensagem.

```
MESSAGE_HANDLER( msg, func )
```

### <a name="parameters"></a>Parâmetros

*Msg*<br/>
[em] A mensagem do Windows.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

MESSAGE_HANDLER mapeia uma mensagem do Windows para a função de manipulador especificado.

Qualquer função especificada em uma MESSAGE_HANDLER macro deve ser definida da seguinte forma:

`LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);`

O mapa `bHandled` de mensagem é configurado como TRUE antes `MessageHandler` de ser chamado. Se `MessageHandler` não manusear totalmente a `bHandled` mensagem, ela deve ser definida como FALSE para indicar que a mensagem precisa de mais processamento.

> [!NOTE]
> Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com [ALT_MSG_MAP](#alt_msg_map). A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de MESSAGE_HANDLER, você pode usar [COMMAND_HANDLER](#command_handler) e [NOTIFY_HANDLER](#notify_handler) para mapear [mensagens WM_COMMAND](/windows/win32/menurc/wm-command) e [WM_NOTIFY,](/windows/win32/controls/wm-notify) respectivamente.

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#129](../../atl/codesnippet/cpp/message-map-macros-atl_8.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="message_range_handler"></a><a name="message_range_handler"></a>MESSAGE_RANGE_HANDLER

Semelhante ao [MESSAGE_HANDLER,](#message_handler)mas mapeia uma série de mensagens do Windows para uma única função de manipulador.

```
MESSAGE_RANGE_HANDLER( msgFirst, msgLast, func )
```

### <a name="parameters"></a>Parâmetros

*msgFirst*<br/>
[em] Marca o início de uma gama contígua de mensagens.

*msgLast*<br/>
[em] Marca o fim de uma gama contígua de mensagens.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="notify_code_handler"></a><a name="notify_code_handler"></a>NOTIFY_CODE_HANDLER

Semelhante ao [NOTIFY_HANDLER,](#notify_handler)mas mapeia uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) baseada apenas no código de notificação.

```
NOTIFY_CODE_HANDLER(cd, func)
```

### <a name="parameters"></a>Parâmetros

*Cd*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="notify_handler"></a><a name="notify_handler"></a>Notify_handler

Define uma entrada em um mapa de mensagem.

```
NOTIFY_HANDLER( id, cd, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do controle enviando a mensagem.

*Cd*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

NOTIFY_HANDLER mapeia uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) para a função de manipulador especificada, com base no código de notificação e no identificador de controle.

Qualquer função especificada em uma NOTIFY_HANDLER macro deve ser definida da seguinte forma:

`LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);`

O mapa `bHandled` de mensagem é configurado como TRUE antes `NotifyHandler` de ser chamado. Se `NotifyHandler` não manusear totalmente a `bHandled` mensagem, ela deve ser definida como FALSE para indicar que a mensagem precisa de mais processamento.

> [!NOTE]
> Sempre inicie um mapa de mensagens com [BEGIN_MSG_MAP](#begin_msg_map). Em seguida, você pode declarar mapas de mensagens alternativas subseqüentes com [ALT_MSG_MAP](#alt_msg_map). A [macro END_MSG_MAP](#end_msg_map) marca o fim do mapa de mensagens. Cada mapa de mensagem deve ter exatamente uma instância de BEGIN_MSG_MAP e END_MSG_MAP.

Além de NOTIFY_HANDLER, você pode usar [MESSAGE_HANDLER](#message_handler) para mapear uma mensagem WM_NOTIFY sem levar em conta um identificador ou código. Neste caso, `MESSAGE_HANDLER(WM_NOTIFY, OnHandlerFunction)` direcionará todas as `OnHandlerFunction`mensagens WM_NOTIFY para .

Para obter mais informações sobre o uso de mapas de mensagens no ATL, consulte [Mapas de mensagens](../../atl/message-maps-atl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#130](../../atl/codesnippet/cpp/message-map-macros-atl_9.h)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="notify_id_handler"></a><a name="notify_id_handler"></a>NOTIFY_ID_HANDLER

Semelhante ao [NOTIFY_HANDLER,](#notify_handler)mas mapeia uma mensagem [WM_NOTIFY](/windows/win32/controls/wm-notify) baseada apenas no identificador de controle.

```
NOTIFY_ID_HANDLER( id, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do controle enviando a mensagem.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="notify_range_code_handler"></a><a name="notify_range_code_handler"></a>NOTIFY_RANGE_CODE_HANDLER

Semelhante ao [NOTIFY_RANGE_HANDLER,](#notify_range_handler)mas mapeia [WM_NOTIFY](/windows/win32/controls/wm-notify) mensagens com um código de notificação específico de uma série de controles para uma única função de manipulador.

```
NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*Cd*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Este intervalo é baseado no identificador do controle que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="notify_range_handler"></a><a name="notify_range_handler"></a>NOTIFY_RANGE_HANDLER

Semelhante ao [NOTIFY_HANDLER,](#notify_handler)mas mapeia [WM_NOTIFY](/windows/win32/controls/wm-notify) mensagens de uma série de controles para uma única função de manipulador.

```
NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="remarks"></a>Comentários

Este intervalo é baseado no identificador do controle que envia a mensagem.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflect_notifications"></a><a name="reflect_notifications"></a>REFLECT_NOTIFICATIONS

Reflete mensagens de notificação de volta para a janela criança (controle) que as enviou.

```
REFLECT_NOTIFICATIONS()
```

### <a name="remarks"></a>Comentários

Especifique esta macro como parte do mapa de mensagens da janela pai.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_command_code_handler"></a><a name="reflected_command_code_handler"></a>REFLECTED_COMMAND_CODE_HANDLER

Semelhante ao [COMMAND_CODE_HANDLER,](#command_code_handler)mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_CODE_HANDLER( code, func )
```

### <a name="parameters"></a>Parâmetros

*Código*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_command_handler"></a><a name="reflected_command_handler"></a>REFLECTED_COMMAND_HANDLER

Semelhante ao [COMMAND_HANDLER,](#command_handler)mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_HANDLER( id, code, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do item do menu, controle ou acelerador.

*Código*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_command_id_handler"></a><a name="reflected_command_id_handler"></a>REFLECTED_COMMAND_ID_HANDLER

Semelhante ao [COMMAND_ID_HANDLER,](#command_id_handler)mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_ID_HANDLER( id, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do item do menu, controle ou acelerador.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_command_range_code_handler"></a><a name="reflected_command_range_code_handler"></a>REFLECTED_COMMAND_RANGE_CODE_HANDLER

Semelhante ao [COMMAND_RANGE_CODE_HANDLER,](#command_range_code_handler)mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_RANGE_CODE_HANDLER( idFirst, idLast, code, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*Código*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_command_range_handler"></a><a name="reflected_command_range_handler"></a>REFLECTED_COMMAND_RANGE_HANDLER

Semelhante ao [COMMAND_RANGE_HANDLER,](#command_range_handler)mas os comandos de mapas refletidos da janela pai.

```
REFLECTED_COMMAND_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_notify_code_handler"></a><a name="reflected_notify_code_handler"></a>REFLECTED_NOTIFY_CODE_HANDLER

Semelhante ao [NOTIFY_CODE_HANDLER,](#notify_code_handler)mas mapeia notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_CODE_HANDLER_EX( cd, func )
```

### <a name="parameters"></a>Parâmetros

*Cd*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_notify_handler"></a><a name="reflected_notify_handler"></a>REFLECTED_NOTIFY_HANDLER

Semelhante ao [NOTIFY_HANDLER,](#notify_handler)mas mapeia notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_HANDLER( id, cd, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do item do menu, controle ou acelerador.

*Cd*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_notify_id_handler"></a><a name="reflected_notify_id_handler"></a>REFLECTED_NOTIFY_ID_HANDLER

Semelhante ao [NOTIFY_ID_HANDLER,](#notify_id_handler)mas mapeia notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_ID_HANDLER( id, func )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] O identificador do item do menu, controle ou acelerador.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_notify_range_code_handler"></a><a name="reflected_notify_range_code_handler"></a>REFLECTED_NOTIFY_RANGE_CODE_HANDLER

Semelhante ao [NOTIFY_RANGE_CODE_HANDLER,](#notify_range_code_handler)mas mapeia notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_RANGE_CODE_HANDLER( idFirst, idLast, cd, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*Cd*<br/>
[em] O código de notificação.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="reflected_notify_range_handler"></a><a name="reflected_notify_range_handler"></a>REFLECTED_NOTIFY_RANGE_HANDLER

Semelhante ao [NOTIFY_RANGE_HANDLER,](#notify_range_handler)mas mapeia notificações refletidas da janela pai.

```
REFLECTED_NOTIFY_RANGE_HANDLER( idFirst, idLast, func )
```

### <a name="parameters"></a>Parâmetros

*idFirst*<br/>
[em] Marca o início de uma gama contígua de identificadores de controle.

*idLast*<br/>
[em] Marca o fim de uma gama contígua de identificadores de controle.

*func*<br/>
[em] O nome da função de manipulador de mensagens.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)

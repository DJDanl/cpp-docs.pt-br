---
title: Mapas de conexão
ms.date: 11/04/2016
helpviewer_keywords:
- connection maps
ms.assetid: 1f25a9bc-6d09-4614-99cf-dc38e8ddfa73
ms.openlocfilehash: 947cd09023ef4028a32db8e2e4e8b33f7e04e0dd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374796"
---
# <a name="connection-maps"></a>Mapas de conexão

Os controles OLE são capazes de expor interfaces a outros aplicativos. Essas interfaces só permitem o acesso de um contêiner a esse controle. Se um controle OLE quiser acessar interfaces externas de outros objetos OLE, um ponto de conexão deve ser estabelecido. Este ponto de conexão permite um acesso de saída de controle a mapas de despacho externos, como mapas de eventos ou funções de notificação.

A Biblioteca de Classes da Microsoft Foundation oferece um modelo de programação que suporta pontos de conexão. Neste modelo, "mapas de conexão" são usados para designar interfaces ou pontos de conexão para o controle OLE. Os mapas de conexão contêm uma macro para cada ponto de conexão. Para obter mais informações sobre mapas de conexão, consulte a classe [CConnectionPoint.](../../mfc/reference/cconnectionpoint-class.md)

Normalmente, um controle suportará apenas dois pontos de conexão: um para eventos e outro para notificações de propriedades. Estes são `COleControl` implementados pela classe base e não requerem nenhum trabalho adicional do escritor de controle. Quaisquer pontos de conexão adicionais que você deseja implementar em sua classe devem ser adicionados manualmente. Para suportar mapas e pontos de conexão, o MFC fornece as seguintes macros:

### <a name="connection-map-declaration-and-demarcation"></a>Declaração e Demarcação do Mapa de Conexão

|||
|-|-|
|[BEGIN_CONNECTION_PART](#begin_connection_part)|Declara uma classe incorporada que implementa um ponto de conexão adicional (deve ser usado na declaração de classe).|
|[END_CONNECTION_PART](#end_connection_part)|Termina a declaração de um ponto de conexão (deve ser usado na declaração de classe).|
|[CONNECTION_IID](#connection_iid)|Especifica o ID de interface do ponto de conexão do controle.|
|[DECLARE_CONNECTION_MAP](#declare_connection_map)|Declara que um mapa de conexão será usado em uma classe (deve ser usado na declaração de classe).|
|[BEGIN_CONNECTION_MAP](#begin_connection_map)|Começa a definição de um mapa de conexão (deve ser usado na implementação da classe).|
|[END_CONNECTION_MAP](#end_connection_map)|Termina a definição de um mapa de conexão (deve ser usado na implementação da classe).|
|[CONNECTION_PART](#connection_part)|Especifica um ponto de conexão no mapa de conexão do controle.|

As seguintes funções auxiliam um dissipador no estabelecimento e desconexão de uma conexão usando pontos de conexão:

### <a name="initializationtermination-of-connection-points"></a>Inicialização/Término de Pontos de Conexão

|||
|-|-|
|[AfxConnectionAdvise](#afxconnectionadvise)|Estabelece uma conexão entre uma fonte e uma pia.|
|[AfxConnectionUnadvise](#afxconnectionunadvise)|Quebra uma conexão entre uma fonte e uma pia.|

## <a name="begin_connection_part"></a><a name="begin_connection_part"></a>Begin_connection_part

Use a BEGIN_CONNECTION_PART macro para iniciar a definição de pontos de conexão adicionais além dos pontos de conexão de evento e de notificação de propriedade.

```
BEGIN_CONNECTION_PART(theClass, localClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe de controle cujo ponto de conexão é este.

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="remarks"></a>Comentários

No arquivo de declaração (.h) que define as funções do membro para sua classe, inicie o ponto de conexão com a macro BEGIN_CONNECTION_PART, em seguida, adicione a CONNECTION_IID macro e quaisquer outras funções de membro que deseja implementar e complete o mapa de ponto de conexão com a macro END_CONNECTION_PART.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="end_connection_part"></a><a name="end_connection_part"></a>End_connection_part

Termina a declaração do seu ponto de conexão.

```
END_CONNECTION_PART(localClass)
```

### <a name="parameters"></a>Parâmetros

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="connection_iid"></a><a name="connection_iid"></a>CONNECTION_IID

Use entre as macros BEGIN_CONNECTION_PART e END_CONNECTION_PART para definir um ID de interface para um ponto de conexão suportado pelo controle OLE.

```
CONNECTION_IID(iid)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
O ID de interface da interface chamada pelo ponto de conexão.

### <a name="remarks"></a>Comentários

O argumento *iid* é um ID de interface usado para identificar a interface que o ponto de conexão chamará em seus sinks conectados. Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#10](../../mfc/codesnippet/cpp/connection-maps_1.h)]

especifica um ponto de `ISinkInterface` conexão que chama a interface.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="declare_connection_map"></a><a name="declare_connection_map"></a>DECLARE_CONNECTION_MAP

Cada `COleControl`classe derivada do programa pode fornecer um mapa de conexão para especificar pontos de conexão adicionais que seu controle suporta.

```
DECLARE_CONNECTION_MAP()
```

### <a name="remarks"></a>Comentários

Se o seu controle suportar pontos adicionais, use a macro DECLARE_CONNECTION_MAP no final da declaração de classe. Em seguida, no arquivo .cpp que define as funções do membro para a classe, use a BEGIN_CONNECTION_MAP macro, CONNECTION_PART macros para cada um dos pontos de conexão do controle e a macro END_CONNECTION_MAP para declarar o fim do mapa de conexão.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="begin_connection_map"></a><a name="begin_connection_map"></a>Begin_connection_map

Cada `COleControl`classe derivada do seu programa pode fornecer um mapa de conexão para especificar pontos de conexão que seu controle suportará.

```
BEGIN_CONNECTION_MAP(theClass, theBase)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe de controle cujo mapa de conexão é este.

*theBase*<br/>
Especifica o nome da classe base *doClass*.

### <a name="remarks"></a>Comentários

Na implementação (. CPP) arquivo que define as funções do membro para sua classe, iniciar o mapa de conexão com a BEGIN_CONNECTION_MAP macro e, em seguida, adicionar entradas de macro para cada um dos seus pontos de conexão usando a [CONNECTION_PART](#connection_part) macro. Finalmente, complete o mapa de conexão com a [END_CONNECTION_MAP](#end_connection_map) macro.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="end_connection_map"></a><a name="end_connection_map"></a>END_CONNECTION_MAP

Termina a definição do seu mapa de conexão.

```
END_CONNECTION_MAP()
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="connection_part"></a><a name="connection_part"></a>CONNECTION_PART

Mapeie um ponto de conexão para o controle OLE para um ID de interface específico.

```
CONNECTION_PART(theClass, iid, localClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe de controle cujo ponto de conexão é este.

*Iid*<br/>
O ID de interface da interface chamada pelo ponto de conexão.

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/connection-maps_2.cpp)]

implementa um mapa de conexão, com `IID_ISinkInterface` um ponto de conexão, que chama a interface .

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="afxconnectionadvise"></a><a name="afxconnectionadvise"></a>AfxConnectionAdvise

Chame esta função para estabelecer uma conexão entre uma fonte, especificada por *pUnkSrc,* e uma pia, especificada por *pUnkSink*.

```
BOOL AFXAPI AfxConnectionAdvise(
    LPUNKNOWN pUnkSrc,
    REFIID iid,
    LPUNKNOWN pUnkSink,
    BOOL bRefCount,
    DWORD FAR* pdwCookie);
```

### <a name="parameters"></a>Parâmetros

*pUnkSrc*<br/>
Um ponteiro para o objeto que chama a interface.

*Punksink*<br/>
Um ponteiro para o objeto que implementa a interface.

*Iid*<br/>
O ID de interface da conexão.

*bRefCount*<br/>
TRUE indica que a criação da conexão deve fazer com que a contagem de referência do *pUnkSink* seja incrementada. FALSE indica que a contagem de referência não deve ser incrementada.

*pdwCookie*<br/>
Um ponteiro para um DWORD onde um identificador de conexão é devolvido. Esse valor deve ser passado como parâmetro `AfxConnectionUnadvise` *dwCookie* para quando desconectar a conexão.

### <a name="return-value"></a>Valor retornado

Não zero se uma conexão foi estabelecida; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#8](../../mfc/codesnippet/cpp/connection-maps_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="afxconnectionunadvise"></a><a name="afxconnectionunadvise"></a>AfxConnectionUnadvise

Chame esta função para desconectar uma conexão entre uma fonte, especificada por *pUnkSrc,* e uma pia, especificada por *pUnkSink*.

```
BOOL AFXAPI AfxConnectionUnadvise(
    LPUNKNOWN pUnkSrc,
    REFIID iid,
    LPUNKNOWN pUnkSink,
    BOOL bRefCount,
    DWORD dwCookie);
```

### <a name="parameters"></a>Parâmetros

*pUnkSrc*<br/>
Um ponteiro para o objeto que chama a interface.

*Punksink*<br/>
Um ponteiro para o objeto que implementa a interface.

*Iid*<br/>
O ID de interface da interface do ponto de conexão.

*bRefCount*<br/>
TRUE indica que a desconexão da conexão deve fazer com que a contagem de referência de *pUnkSink* seja decretada. FALSE indica que a contagem de referência não deve ser decretada.

*Dwcookie*<br/>
O identificador de `AfxConnectionAdvise`conexão retornou por .

### <a name="return-value"></a>Valor retornado

Não zero se uma conexão foi desconectada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#9](../../mfc/codesnippet/cpp/connection-maps_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

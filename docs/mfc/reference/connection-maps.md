---
title: Mapas de conexão
ms.date: 11/04/2016
helpviewer_keywords:
- connection maps
ms.assetid: 1f25a9bc-6d09-4614-99cf-dc38e8ddfa73
ms.openlocfilehash: 517017e9e60b86e96daa24f7822538e91c609fb4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841409"
---
# <a name="connection-maps"></a>Mapas de conexão

Os controles OLE são capazes de expor interfaces a outros aplicativos. Essas interfaces só permitem o acesso de um contêiner nesse controle. Se um controle OLE quiser acessar interfaces externas de outros objetos OLE, um ponto de conexão deverá ser estabelecido. Esse ponto de conexão permite que um controle acesse mapas de expedição externos, como mapas de eventos ou funções de notificação.

O biblioteca MFC oferece um modelo de programação que dá suporte a pontos de conexão. Nesse modelo, "mapas de conexão" são usados para designar interfaces ou pontos de conexão para o controle OLE. Os mapas de conexão contêm uma macro para cada ponto de conexão. Para obter mais informações sobre mapas de conexão, consulte a classe [CConnectionPoint](../../mfc/reference/cconnectionpoint-class.md) .

Normalmente, um controle oferecerá suporte a apenas dois pontos de conexão: um para eventos e outro para notificações de propriedade. Eles são implementados pela `COleControl` classe base e não exigem nenhum trabalho adicional pelo gravador de controle. Todos os pontos de conexão adicionais que você deseja implementar em sua classe devem ser adicionados manualmente. Para dar suporte a mapas e pontos de conexão, o MFC fornece as seguintes macros:

### <a name="connection-map-declaration-and-demarcation"></a>Declaração e demarcador de mapa de conexão

|Nome|Descrição|
|-|-|
|[BEGIN_CONNECTION_PART](#begin_connection_part)|Declara uma classe inserida que implementa um ponto de conexão adicional (deve ser usado na declaração de classe).|
|[END_CONNECTION_PART](#end_connection_part)|Encerra a declaração de um ponto de conexão (deve ser usado na declaração de classe).|
|[CONNECTION_IID](#connection_iid)|Especifica a ID da interface do ponto de conexão do controle.|
|[DECLARE_CONNECTION_MAP](#declare_connection_map)|Declara que um mapa de conexão será usado em uma classe (deve ser usado na declaração de classe).|
|[BEGIN_CONNECTION_MAP](#begin_connection_map)|Inicia a definição de um mapa de conexão (deve ser usado na implementação da classe).|
|[END_CONNECTION_MAP](#end_connection_map)|Termina a definição de um mapa de conexão (deve ser usado na implementação da classe).|
|[CONNECTION_PART](#connection_part)|Especifica um ponto de conexão no mapa de conexão do controle.|

As funções a seguir auxiliam um coletor no estabelecimento e desconexão de uma conexão usando pontos de conexão:

### <a name="initializationtermination-of-connection-points"></a>Inicialização/encerramento de pontos de conexão

|Nome|Descrição|
|-|-|
|[AfxConnectionAdvise](#afxconnectionadvise)|Estabelece uma conexão entre uma origem e um coletor.|
|[AfxConnectionUnadvise](#afxconnectionunadvise)|Interrompe uma conexão entre uma origem e um coletor.|

## <a name="begin_connection_part"></a><a name="begin_connection_part"></a> BEGIN_CONNECTION_PART

Use a macro BEGIN_CONNECTION_PART para iniciar a definição de pontos de conexão adicionais além dos pontos de conexão de notificação de evento e propriedade.

```
BEGIN_CONNECTION_PART(theClass, localClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe de controle cujo ponto de conexão é.

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="remarks"></a>Comentários

No arquivo de declaração (. h) que define as funções de membro para sua classe, inicie o ponto de conexão com a macro BEGIN_CONNECTION_PART, em seguida, adicione a macro CONNECTION_IID e outras funções de membro que você deseja implementar e conclua o mapa de ponto de conexão com a macro END_CONNECTION_PART.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="end_connection_part"></a><a name="end_connection_part"></a> END_CONNECTION_PART

Encerra a declaração do seu ponto de conexão.

```
END_CONNECTION_PART(localClass)
```

### <a name="parameters"></a>parâmetros

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="connection_iid"></a><a name="connection_iid"></a> CONNECTION_IID

Use entre as macros BEGIN_CONNECTION_PART e END_CONNECTION_PART para definir uma ID de interface para um ponto de conexão com suporte no seu controle OLE.

```
CONNECTION_IID(iid)
```

### <a name="parameters"></a>parâmetros

*IID*<br/>
A ID da interface chamada pelo ponto de conexão.

### <a name="remarks"></a>Comentários

O argumento *IID* é uma ID de interface usada para identificar a interface que o ponto de conexão chamará em seus coletores conectados. Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#10](../../mfc/codesnippet/cpp/connection-maps_1.h)]

Especifica um ponto de conexão que chama a `ISinkInterface` interface.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="declare_connection_map"></a><a name="declare_connection_map"></a> DECLARE_CONNECTION_MAP

Cada `COleControl` classe derivada em seu programa pode fornecer um mapa de conexão para especificar pontos de conexão adicionais aos quais o controle dá suporte.

```
DECLARE_CONNECTION_MAP()
```

### <a name="remarks"></a>Comentários

Se o controle der suporte a pontos adicionais, use a macro DECLARE_CONNECTION_MAP no final da declaração de sua classe. Em seguida, no arquivo. cpp que define as funções de membro para a classe, use a macro BEGIN_CONNECTION_MAP, CONNECTION_PART macros para cada um dos pontos de conexão do controle e a macro END_CONNECTION_MAP para declarar o final do mapa de conexão.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="begin_connection_map"></a><a name="begin_connection_map"></a> BEGIN_CONNECTION_MAP

Cada `COleControl` classe derivada em seu programa pode fornecer um mapa de conexão para especificar pontos de conexão para os quais seu controle dará suporte.

```
BEGIN_CONNECTION_MAP(theClass, theBase)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe de controle cuja conexão é mapeada.

*Base*<br/>
Especifica o nome da classe base da *classe*.

### <a name="remarks"></a>Comentários

Na implementação (. CPP) que define as funções de membro para sua classe, inicie o mapa de conexão com a macro BEGIN_CONNECTION_MAP e, em seguida, adicione entradas de macro para cada um dos pontos de conexão usando a macro [CONNECTION_PART](#connection_part) . Por fim, conclua o mapa de conexão com a macro [END_CONNECTION_MAP](#end_connection_map) .

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="end_connection_map"></a><a name="end_connection_map"></a> END_CONNECTION_MAP

Finaliza a definição do mapa de conexão.

```
END_CONNECTION_MAP()
```

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="connection_part"></a><a name="connection_part"></a> CONNECTION_PART

Mapeia um ponto de conexão para o controle OLE para uma ID de interface específica.

```
CONNECTION_PART(theClass, iid, localClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe de controle cujo ponto de conexão é.

*IID*<br/>
A ID da interface chamada pelo ponto de conexão.

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/connection-maps_2.cpp)]

implementa um mapa de conexão, com um ponto de conexão, que chama a `IID_ISinkInterface` interface.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="afxconnectionadvise"></a><a name="afxconnectionadvise"></a> AfxConnectionAdvise

Chame essa função para estabelecer uma conexão entre uma origem, especificada por *pUnkSrc*e um coletor, especificado por *pUnkSink*.

```
BOOL AFXAPI AfxConnectionAdvise(
    LPUNKNOWN pUnkSrc,
    REFIID iid,
    LPUNKNOWN pUnkSink,
    BOOL bRefCount,
    DWORD FAR* pdwCookie);
```

### <a name="parameters"></a>parâmetros

*pUnkSrc*<br/>
Um ponteiro para o objeto que chama a interface.

*pUnkSink*<br/>
Um ponteiro para o objeto que implementa a interface.

*IID*<br/>
A ID da interface da conexão.

*bRefCount*<br/>
VERDADEIRO indica que a criação da conexão deve fazer com que a contagem de referência de *pUnkSink* seja incrementada. FALSE indica que a contagem de referência não deve ser incrementada.

*pdwCookie*<br/>
Um ponteiro para um DWORD em que um identificador de conexão é retornado. Esse valor deve ser passado como o parâmetro *dwCookie* ao `AfxConnectionUnadvise` desconectar a conexão.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se uma conexão foi estabelecida; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#8](../../mfc/codesnippet/cpp/connection-maps_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="afxconnectionunadvise"></a><a name="afxconnectionunadvise"></a> AfxConnectionUnadvise

Chame essa função para desconectar uma conexão entre uma origem, especificada por *pUnkSrc*e um coletor, especificado por *pUnkSink*.

```
BOOL AFXAPI AfxConnectionUnadvise(
    LPUNKNOWN pUnkSrc,
    REFIID iid,
    LPUNKNOWN pUnkSink,
    BOOL bRefCount,
    DWORD dwCookie);
```

### <a name="parameters"></a>parâmetros

*pUnkSrc*<br/>
Um ponteiro para o objeto que chama a interface.

*pUnkSink*<br/>
Um ponteiro para o objeto que implementa a interface.

*IID*<br/>
A ID da interface da interface de ponto de conexão.

*bRefCount*<br/>
VERDADEIRO indica que a desconexão da conexão deve fazer com que a contagem de referência de *pUnkSink* seja decrementada. FALSE indica que a contagem de referência não deve ser decrementada.

*dwCookie*<br/>
O identificador de conexão retornado por `AfxConnectionAdvise` .

### <a name="return-value"></a>Valor Retornado

Diferente de zero se uma conexão foi desconectada; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#9](../../mfc/codesnippet/cpp/connection-maps_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

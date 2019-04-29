---
title: Mapas de conexão
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros.maps
helpviewer_keywords:
- connection maps
ms.assetid: 1f25a9bc-6d09-4614-99cf-dc38e8ddfa73
ms.openlocfilehash: cbd993e7172ca9a25f25db18d5d0fa042db847b3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62373291"
---
# <a name="connection-maps"></a>Mapas de conexão

Controles OLE são capazes de expor interfaces para outros aplicativos. Essas interfaces permitem acesso apenas de um contêiner em que o controle. Se um controle OLE quiser acessar as interfaces externas de outros objetos OLE, um ponto de conexão deve ser estabelecido. Esse ponto de conexão permite que um controle de acesso para mapas de expedição externo, como mapas de evento ou funções de notificação de saída.

A biblioteca Microsoft Foundation Class oferece um modelo de programação que dá suporte a pontos de conexão. Nesse modelo, "conexão mapeia" são usadas para designar as interfaces ou pontos de conexão para o controle OLE. Os mapas de Conexão contêm uma macro para cada ponto de conexão. Para obter mais informações sobre mapas de conexão, consulte a [CConnectionPoint](../../mfc/reference/cconnectionpoint-class.md) classe.

Normalmente, um controle oferecerá suporte a apenas dois pontos de conexão: um para eventos e outro para receber notificações de propriedade. Eles são implementados pelo `COleControl` classe base e exigir nenhum trabalho adicional pelo gravador do controle. Os pontos de conexão adicionais que você deseja implementar em sua classe devem ser adicionados manualmente. Para dar suporte a mapas de conexão e pontos, o MFC fornece as seguintes macros:

### <a name="connection-map-declaration-and-demarcation"></a>Declaração de mapa de Conexão e demarcação

|||
|-|-|
|[BEGIN_CONNECTION_PART](#begin_connection_part)|Declara uma classe incorporada que implementa um ponto de conexão adicionais (deve ser usado na declaração de classe).|
|[END_CONNECTION_PART](#end_connection_part)|Termina a declaração de um ponto de conexão (deve ser usado na declaração de classe).|
|[CONNECTION_IID](#connection_iid)|Especifica a ID de interface do ponto de conexão do controle.|
|[DECLARE_CONNECTION_MAP](#declare_connection_map)|Declara que um mapa de conexão será usado em uma classe (deve ser usado na declaração de classe).|
|[BEGIN_CONNECTION_MAP](#begin_connection_map)|Inicia a definição de um mapa de conexão (deve ser usada na implementação da classe).|
|[END_CONNECTION_MAP](#end_connection_map)|Finaliza a definição de um mapa de conexão (deve ser usada na implementação da classe).|
|[CONNECTION_PART](#connection_part)|Especifica um ponto de conexão no mapa de conexão do controle.|

As seguintes funções de auxiliar um coletor em estabelecer e desconectar uma conexão usando os pontos de conexão:

### <a name="initializationtermination-of-connection-points"></a>Inicialização/encerramento dos pontos de Conexão

|||
|-|-|
|[AfxConnectionAdvise](#afxconnectionadvise)|Estabelece uma conexão entre uma origem e um coletor.|
|[AfxConnectionUnadvise](#afxconnectionunadvise)|Interrompe uma conexão entre uma origem e um coletor.|

##  <a name="begin_connection_part"></a>  BEGIN_CONNECTION_PART

Use a macro BEGIN_CONNECTION_PART para começar a definição de pontos de conexão adicionais além os pontos de conexão de notificação de evento e propriedade.

```
BEGIN_CONNECTION_PART(theClass, localClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe do controle cujo conexão ponto, isso é.

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="remarks"></a>Comentários

No arquivo de declaração (. h) que define as funções de membro para a sua classe, iniciar o ponto de conexão com a macro BEGIN_CONNECTION_PART, em seguida, adicione a macro CONNECTION_IID e quaisquer outras funções de membro que você deseja implementar e conclua a conexão ponto de mapa com a macro END_CONNECTION_PART.

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="end_connection_part"></a>  END_CONNECTION_PART

Termina a declaração do seu ponto de conexão.

```
END_CONNECTION_PART(localClass)
```

### <a name="parameters"></a>Parâmetros

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="connection_iid"></a>  CONNECTION_IID

Use entre o BEGIN_CONNECTION_PART e END_CONNECTION_PART macros para definir uma ID de interface para um ponto de conexão compatível com o seu controle OLE.

```
CONNECTION_IID(iid)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
A ID de interface da interface chamado pelo ponto de conexão.

### <a name="remarks"></a>Comentários

O *iid* argumento é uma interface ID usada para identificar a interface que chamará o ponto de conexão em seus coletores conectados. Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#10](../../mfc/codesnippet/cpp/connection-maps_1.h)]

Especifica um ponto de conexão que chama o `ISinkInterface` interface.

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="declare_connection_map"></a>  DECLARE_CONNECTION_MAP

Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de conexão para especificar os pontos de conexão adicionais que dá suporte a seu controle.

```
DECLARE_CONNECTION_MAP()
```

### <a name="remarks"></a>Comentários

Se o controle dá suporte a pontos adicionais, use a macro DECLARE_CONNECTION_MAP no final de sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use a macro BEGIN_CONNECTION_MAP, macros CONNECTION_PART para cada um dos pontos de conexão do controle e a macro END_CONNECTION_MAP para declarar o fim do mapa de conexão.

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="begin_connection_map"></a>  BEGIN_CONNECTION_MAP

Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de conexão para especificar os pontos de conexão que o controle dará suporte.

```
BEGIN_CONNECTION_MAP(theClass, theBase)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe do controle cujo conexão ser mapeado.

*theBase*<br/>
Especifica o nome da classe base da *theClass*.

### <a name="remarks"></a>Comentários

Na implementação (. Arquivo CPP) que define o membro de funções para sua classe, inicie o mapa de conexão com a macro BEGIN_CONNECTION_MAP e adicione entradas de macro para cada um dos seus pontos de conexão usando o [CONNECTION_PART](#connection_part) macro. Por fim, conclua o mapa de conexão com o [END_CONNECTION_MAP](#end_connection_map) macro.

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="end_connection_map"></a>  END_CONNECTION_MAP

Finaliza a definição de seu mapa de conexão.

```
END_CONNECTION_MAP()
```

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="connection_part"></a>  CONNECTION_PART

Mapeia um ponto de conexão para o seu controle OLE para uma ID de interface específica.

```
CONNECTION_PART(theClass, iid, localClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe do controle cujo conexão ponto, isso é.

*iid*<br/>
A ID de interface da interface chamado pelo ponto de conexão.

*localClass*<br/>
Especifica o nome da classe local que implementa o ponto de conexão.

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/connection-maps_2.cpp)]

implementa um mapa de conexão, com um ponto de conexão, que chama o `IID_ISinkInterface` interface.

### <a name="requirements"></a>Requisitos

  **Header** afxdisp.h

##  <a name="afxconnectionadvise"></a>  AfxConnectionAdvise

Chame essa função para estabelecer uma conexão entre uma fonte especificada por *pUnkSrc*e um coletor, especificado por *pUnkSink*.

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

*pUnkSink*<br/>
Um ponteiro para o objeto que implementa a interface.

*iid*<br/>
A ID de interface da conexão.

*bRefCount*<br/>
TRUE indica que a criação de conexão deve causar a contagem de referência de *pUnkSink* a ser incrementado. FALSE indica que a contagem de referência não deve ser incrementada.

*pdwCookie*<br/>
Um ponteiro para um DWORD em que um identificador de conexão é retornado. Esse valor deve ser passado como o *dwCookie* parâmetro `AfxConnectionUnadvise` ao desconectar-se a conexão.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se uma conexão foi estabelecida; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#8](../../mfc/codesnippet/cpp/connection-maps_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="afxconnectionunadvise"></a>  AfxConnectionUnadvise

Chame essa função para desconectar uma conexão entre uma fonte especificada por *pUnkSrc*e um coletor, especificado por *pUnkSink*.

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

*pUnkSink*<br/>
Um ponteiro para o objeto que implementa a interface.

*iid*<br/>
A ID de interface da interface do ponto de conexão.

*bRefCount*<br/>
TRUE indica que a desconectar a conexão deve fazer com que a contagem de referência de *pUnkSink* deve ser decrementado. FALSE indica que a contagem de referência não deve ser decrementada.

*dwCookie*<br/>
O identificador de conexão retornado pelo `AfxConnectionAdvise`.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se uma conexão foi desconectada; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#9](../../mfc/codesnippet/cpp/connection-maps_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

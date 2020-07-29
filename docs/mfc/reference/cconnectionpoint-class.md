---
title: Classe CConnectionPoint
ms.date: 11/04/2016
f1_keywords:
- CConnectionPoint
- AFXDISP/CConnectionPoint
- AFXDISP/CConnectionPoint::CConnectionPoint
- AFXDISP/CConnectionPoint::GetConnections
- AFXDISP/CConnectionPoint::GetContainer
- AFXDISP/CConnectionPoint::GetIID
- AFXDISP/CConnectionPoint::GetMaxConnections
- AFXDISP/CConnectionPoint::GetNextConnection
- AFXDISP/CConnectionPoint::GetStartPosition
- AFXDISP/CConnectionPoint::OnAdvise
- AFXDISP/CConnectionPoint::QuerySinkInterface
helpviewer_keywords:
- CConnectionPoint [MFC], CConnectionPoint
- CConnectionPoint [MFC], GetConnections
- CConnectionPoint [MFC], GetContainer
- CConnectionPoint [MFC], GetIID
- CConnectionPoint [MFC], GetMaxConnections
- CConnectionPoint [MFC], GetNextConnection
- CConnectionPoint [MFC], GetStartPosition
- CConnectionPoint [MFC], OnAdvise
- CConnectionPoint [MFC], QuerySinkInterface
ms.assetid: f0f23a1e-5e8c-41a9-aa6c-1a4793b28e8f
ms.openlocfilehash: f428ec597e0e4a56788fae2455eff80b286fda39
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87183078"
---
# <a name="cconnectionpoint-class"></a>Classe CConnectionPoint

Define um tipo especial de interface usado para se comunicar com outros objetos OLE, chamados de "ponto de conexão".

## <a name="syntax"></a>Sintaxe

```
class CConnectionPoint : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CConnectionPoint::CConnectionPoint](#cconnectionpoint)|Constrói um objeto `CConnectionPoint`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CConnectionPoint:: GetConnections](#getconnections)|Recupera todos os pontos de conexão em um mapa de conexão.|
|[CConnectionPoint:: GetContainer](#getcontainer)|Recupera o contêiner do controle que possui o mapa de conexão.|
|[CConnectionPoint::GetIID](#getiid)|Recupera a ID de interface de um ponto de conexão.|
|[CConnectionPoint::GetMaxConnections](#getmaxconnections)|Recupera o número máximo de pontos de conexão com suporte de um controle.|
|[CConnectionPoint::GetNextConnection](#getnextconnection)|Recupera um ponteiro para o elemento Connection no *PDV*.|
|[CConnectionPoint:: GetStartPosition](#getstartposition)|Inicia uma iteração de mapa retornando um valor de posição que pode ser passado para uma `GetNextConnection` chamada.|
|[CConnectionPoint:: onaconselhe](#onadvise)|Chamado pelo Framework ao estabelecer ou dividir as conexões.|
|[CConnectionPoint::QuerySinkInterface](#querysinkinterface)|Recupera um ponteiro para a interface do coletor solicitada.|

## <a name="remarks"></a>Comentários

Ao contrário das interfaces OLE normais, que são usadas para implementar e expor a funcionalidade de um controle OLE, um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como acionar eventos e alterar notificações.

Uma conexão consiste em duas partes: o objeto que chama a interface, chamado de "origem" e o objeto que implementa a interface, chamado de "coletor". Ao expor um ponto de conexão, uma fonte permite que os coletores estabeleçam conexões a si mesmo. Por meio do mecanismo de ponto de conexão, um objeto de origem Obtém um ponteiro para a implementação do coletor de um conjunto de funções de membro. Por exemplo, para acionar um evento implementado pelo coletor, a origem pode chamar o método apropriado de implementação do coletor.

Por padrão, uma `COleControl` classe derivada implementa dois pontos de conexão: um para eventos e outro para notificações de alteração de propriedade. Essas conexões são usadas, respectivamente, para o acionamento de eventos e para notificar um coletor (por exemplo, o contêiner do controle) quando um valor de propriedade é alterado. O suporte também é fornecido para controles OLE para implementar pontos de conexão adicionais. Para cada ponto de conexão adicional implementado em sua classe de controle, você deve declarar uma "parte de conexão" que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, também precisará declarar um único "mapa de conexão" em sua classe de controle.

O exemplo a seguir demonstra um mapa de conexão simples e um ponto de conexão para o `Sample` controle OLE, que consiste em dois fragmentos de código: a primeira parte declara o mapa de conexão e o ponto; o segundo implementa esse mapa e ponto. O primeiro fragmento é inserido na declaração da classe Control, na **`protected`** seção:

[!code-cpp[NVC_MFCConnectionPoints#7](../../mfc/codesnippet/cpp/cconnectionpoint-class_1.h)]

As macros BEGIN_CONNECTION_PART e END_CONNECTION_PART declaram uma classe incorporada `XSampleConnPt` (derivada de `CConnectionPoint` ) que implementa esse ponto de conexão específico. Se você quiser substituir qualquer `CConnectionPoint` função de membro ou adicionar funções de membro por conta própria, declare-as entre essas duas macros. Por exemplo, a macro CONNECTION_IID substitui a `CConnectionPoint::GetIID` função de membro quando colocada entre essas duas macros.

O segundo fragmento de código é inserido no arquivo de implementação (. CPP) de sua classe de controle. Esse código implementa o mapa de conexão, que inclui o ponto de conexão adicional, `SampleConnPt` :

[!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/cconnectionpoint-class_2.cpp)]

Depois que esses fragmentos de código tiverem sido inseridos, o controle OLE de exemplo expõe um ponto de conexão para a `ISampleSink` interface.

Normalmente, os pontos de conexão dão suporte a "multicast", que é a capacidade de difundir para vários coletores conectados à mesma interface. O fragmento de código a seguir demonstra como realizar o multicast Iterando por meio de cada coletor em um ponto de conexão:

[!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]

Este exemplo recupera o conjunto atual de conexões no `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections` . Em seguida, ele faz a iteração pelas conexões e chamadas `ISampleSink::SinkFunc` em todas as conexões ativas.

Para obter mais informações sobre como usar `CConnectionPoint` o, consulte o artigo [pontos de conexão](../../mfc/connection-points.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CConnectionPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="cconnectionpointcconnectionpoint"></a><a name="cconnectionpoint"></a>CConnectionPoint::CConnectionPoint

Constrói um objeto `CConnectionPoint`.

```
CConnectionPoint();
```

## <a name="cconnectionpointgetconnections"></a><a name="getconnections"></a>CConnectionPoint:: GetConnections

Chame essa função para recuperar todas as conexões ativas para um ponto de conexão.

```
const CPtrArray* GetConnections();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma matriz de conexões ativas (coletores). Alguns dos ponteiros na matriz podem ser nulos. Cada ponteiro não nulo nessa matriz pode ser convertido com segurança em um ponteiro para a interface do coletor usando um operador cast.

## <a name="cconnectionpointgetcontainer"></a><a name="getcontainer"></a>CConnectionPoint:: GetContainer

Chamado pelo Framework para recuperar o `IConnectionPointContainer` para o ponto de conexão.

```
virtual LPCONNECTIONPOINTCONTAINER GetContainer();
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para o contêiner; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Normalmente, essa função é implementada pela macro BEGIN_CONNECTION_PART.

## <a name="cconnectionpointgetiid"></a><a name="getiid"></a>CConnectionPoint::GetIID

Chamado pelo Framework para recuperar a ID de interface de um ponto de conexão.

```
virtual REFIID GetIID() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma referência à ID da interface do ponto de conexão.

### <a name="remarks"></a>Comentários

Substitua essa função para retornar a ID de interface para este ponto de conexão.

## <a name="cconnectionpointgetmaxconnections"></a><a name="getmaxconnections"></a>CConnectionPoint::GetMaxConnections

Chamado pelo Framework para recuperar o número máximo de conexões com suporte pelo ponto de conexão.

```
virtual int GetMaxConnections();
```

### <a name="return-value"></a>Valor retornado

O número máximo de conexões com suporte pelo controle, ou-1, se não houver limite.

### <a name="remarks"></a>Comentários

A implementação padrão retorna-1, indicando que não há limite.

Substitua essa função se desejar limitar o número de coletores que podem se conectar ao seu controle.

## <a name="cconnectionpointgetnextconnection"></a><a name="getnextconnection"></a>CConnectionPoint::GetNextConnection

Recupera um ponteiro para o elemento Connection no *PDV*.

```
LPUNKNOWN GetNextConnection(POSITION& pos) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Especifica uma referência a um valor de posição retornado por uma `GetNextConnection` chamada anterior ou [GetStartPosition](#getstartposition) .

### <a name="return-value"></a>Valor retornado

Um ponteiro para o elemento Connection especificado por *pos*ou NULL.

### <a name="remarks"></a>Comentários

Essa função é mais útil para iterar por todos os elementos no mapa de conexão. Ao iterar, ignore quaisquer nulos retornados dessa função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]

## <a name="cconnectionpointgetstartposition"></a><a name="getstartposition"></a>CConnectionPoint:: GetStartPosition

Inicia uma iteração de mapa retornando um valor de posição que pode ser passado para uma chamada [GetNextConnection](#getnextconnection) .

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que indica uma posição inicial para iterar o mapa; ou NULL se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" não tem significância especial.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CConnectionPoint:: GetNextConnection](#getnextconnection).

## <a name="cconnectionpointonadvise"></a><a name="onadvise"></a>CConnectionPoint:: onaconselhe

Chamado pelo Framework quando uma conexão está sendo estabelecida ou quebrada.

```
virtual void OnAdvise(BOOL bAdvise);
```

### <a name="parameters"></a>parâmetros

*bAdvise*<br/>
TRUE, se uma conexão estiver sendo estabelecida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada.

Substitua essa função se desejar uma notificação quando os coletores se conectarem ou desconectarem do ponto de conexão.

## <a name="cconnectionpointquerysinkinterface"></a><a name="querysinkinterface"></a>CConnectionPoint::QuerySinkInterface

Recupera um ponteiro para a interface do coletor solicitada.

```
virtual HRESULT QuerySinkInterface(
    LPUNKNOWN pUnkSink,
    void** ppInterface);
```

### <a name="parameters"></a>parâmetros

*pUnkSink*<br/>
O identificador da interface do coletor que está sendo solicitada.

*ppInterface*<br/>
Um ponteiro para o ponteiro de interface identificado por *pUnkSink*. Se o objeto não oferecer suporte a essa interface, \* *ppInterface* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)

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
ms.openlocfilehash: a75ce23cf55f26505c2584c3a021b654602a6a2b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57288942"
---
# <a name="cconnectionpoint-class"></a>Classe CConnectionPoint

Define um tipo especial de interface usada para se comunicar com outros objetos OLE, chamados de "ponto de conexão".

## <a name="syntax"></a>Sintaxe

```
class CConnectionPoint : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CConnectionPoint::CConnectionPoint](#cconnectionpoint)|Constrói um objeto `CConnectionPoint`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CConnectionPoint::GetConnections](#getconnections)|Recupera todos os pontos de conexão em um mapa de conexão.|
|[CConnectionPoint::GetContainer](#getcontainer)|Recupera o contêiner do controle que possui o mapa de conexão.|
|[CConnectionPoint::GetIID](#getiid)|Recupera a ID de interface de um ponto de conexão.|
|[CConnectionPoint::GetMaxConnections](#getmaxconnections)|Recupera o número máximo de pontos de conexão com suporte por um controle.|
|[CConnectionPoint::GetNextConnection](#getnextconnection)|Recupera um ponteiro para o elemento de conexão no *pos*.|
|[CConnectionPoint::GetStartPosition](#getstartposition)|Inicia uma iteração de mapa, retornando um valor de posição que pode ser passado para um `GetNextConnection` chamar.|
|[CConnectionPoint::OnAdvise](#onadvise)|Chamado pelo framework quando estabelecer ou interrompendo conexões.|
|[CConnectionPoint::QuerySinkInterface](#querysinkinterface)|Recupera um ponteiro para a interface do coletor solicitada.|

## <a name="remarks"></a>Comentários

Ao contrário de interfaces OLE normais, que são usados para implementar e expor a funcionalidade de um controle OLE, um ponto de conexão implementa uma interface de saída que é capaz de iniciar as ações de outros objetos, como disparar eventos e notificações de alteração.

Uma conexão consiste em duas partes: o objeto que está chamando a interface, chamada de "origem" e o objeto que implementa a interface, chamado de "coletor". Ao expor um ponto de conexão, uma fonte permite coletores estabelecer conexões a mesmo. Por meio do mecanismo de ponto de conexão, um objeto de origem obtém um ponteiro para a implementação do coletor de um conjunto de funções de membro. Por exemplo, para disparar um evento implementado pelo coletor, o código-fonte pode chamar o método apropriado da implementação do coletor.

Por padrão, um `COleControl`-classe derivada implementa dois pontos de conexão: notificações de alteração de um para eventos e outro para a propriedade. Essas conexões são usadas, respectivamente, para acionamento do evento e para notificar um coletor (por exemplo, o contêiner do controle) quando um valor da propriedade foi alterada. Suporte também é fornecido para controles OLE implementar pontos de conexão adicionais. Para cada ponto de conexão adicionais implementado em sua classe de controle, você deve declarar uma "parte de conexão" que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, você também precisa declarar uma única "conexão" mapa em sua classe de controle.

O exemplo a seguir demonstra um mapa de conexão simples e um ponto de conexão de um para o `Sample` controle OLE, consiste em dois fragmentos de código: a primeira parte declara o mapa de conexão e o ponto; a segunda implementa esse mapa e ponto. O primeiro fragmento é inserido na declaração de classe de controle, sob o **protegidos** seção:

[!code-cpp[NVC_MFCConnectionPoints#7](../../mfc/codesnippet/cpp/cconnectionpoint-class_1.h)]

As macros BEGIN_CONNECTION_PART e END_CONNECTION_PART declarar uma classe incorporada, `XSampleConnPt` (derivado de `CConnectionPoint`) que implementa esse ponto de conexão específico. Se você quiser substituir qualquer `CConnectionPoint` funções de membro, ou adicionar funções de membro de sua preferência, declará-los entre essas duas macros. Por exemplo, a macro CONNECTION_IID substitui o `CConnectionPoint::GetIID` quando colocado entre essas duas macros de função de membro.

O segundo fragmento de código é inserido no arquivo de implementação (. CPP) de sua classe de controle. Esse código implementa um mapa de conexão, que inclui o ponto de conexão adicionais, `SampleConnPt`:

[!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/cconnectionpoint-class_2.cpp)]

Depois que esses fragmentos de código foram inseridos, o controle de exemplo OLE expõe um ponto de conexão para o `ISampleSink` interface.

Normalmente, os pontos de conexão dão suporte a "difusão seletiva", que é a capacidade de fazer uma transmissão para vários coletores estabelecidos com a mesma interface. O fragmento de código a seguir demonstra como realizar difusão seletiva iterando por cada coletor em um ponto de conexão:

[!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]

Este exemplo recupera o conjunto atual de conexões na `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections`. Em seguida, itera através de conexões e chama `ISampleSink::SinkFunc` em cada conexão do Active Directory.

Para obter mais informações sobre como usar `CConnectionPoint`, consulte o artigo [pontos de Conexão](../../mfc/connection-points.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CConnectionPoint`

## <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

##  <a name="cconnectionpoint"></a>  CConnectionPoint::CConnectionPoint

Constrói um objeto `CConnectionPoint`.

```
CConnectionPoint();
```

##  <a name="getconnections"></a>  CConnectionPoint::GetConnections

Chame essa função para recuperar todas as conexões ativas para um ponto de conexão.

```
const CPtrArray* GetConnections();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma matriz de conexões ativas (coletores). Alguns dos ponteiros na matriz podem ser NULL. Cada ponteiro não nulo nessa matriz pode ser convertido com segurança em um ponteiro para a interface do coletor usando um operador cast.

##  <a name="getcontainer"></a>  CConnectionPoint::GetContainer

Chamado pelo framework para recuperar o `IConnectionPointContainer` para o ponto de conexão.

```
virtual LPCONNECTIONPOINTCONTAINER GetContainer();
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, um ponteiro para o contêiner; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

Normalmente, essa função é implementada pela macro BEGIN_CONNECTION_PART.

##  <a name="getiid"></a>  CConnectionPoint::GetIID

Chamado pelo framework para recuperar a ID de interface de um ponto de conexão.

```
virtual REFIID GetIID() = 0;
```

### <a name="return-value"></a>Valor de retorno

Uma referência à ID de interface. do ponto de conexão

### <a name="remarks"></a>Comentários

Substitua essa função para retornar a ID de interface para esse ponto de conexão.

##  <a name="getmaxconnections"></a>  CConnectionPoint::GetMaxConnections

Chamado pelo framework para recuperar o número máximo de conexões suportadas pelo ponto de conexão.

```
virtual int GetMaxConnections();
```

### <a name="return-value"></a>Valor de retorno

O número máximo de conexões com suporte pelo controle ou -1 se nenhum limite.

### <a name="remarks"></a>Comentários

A implementação padrão retorna -1, que indica nenhum limite.

Substitua essa função se você quiser limitar o número de Coletores que pode se conectar ao seu controle.

##  <a name="getnextconnection"></a>  CConnectionPoint::GetNextConnection

Recupera um ponteiro para o elemento de conexão no *pos*.

```
LPUNKNOWN GetNextConnection(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
Especifica uma referência a um valor de posição retornado por uma anterior `GetNextConnection` ou [GetStartPosition](#getstartposition) chamar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o elemento de conexão especificado por *pos*, ou nulo.

### <a name="remarks"></a>Comentários

Essa função é mais útil para iterar por meio de todos os elementos no mapa de conexão. Durante a iteração, ignore quaisquer valores nulos retornados de sua função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]

##  <a name="getstartposition"></a>  CConnectionPoint::GetStartPosition

Inicia uma iteração de mapa, retornando um valor de posição que pode ser passado para um [GetNextConnection](#getnextconnection) chamar.

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de posição que indica uma posição inicial para iterar o mapa; ou nulo se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" tem nenhum significado especial.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CConnectionPoint::GetNextConnection](#getnextconnection).

##  <a name="onadvise"></a>  CConnectionPoint::OnAdvise

Chamado pelo framework quando uma conexão está sendo estabelecida ou corrompida.

```
virtual void OnAdvise(BOOL bAdvise);
```

### <a name="parameters"></a>Parâmetros

*bAdvise*<br/>
TRUE se uma conexão está sendo estabelecida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada.

Substitua essa função se você quiser uma notificação quando coletores conectem ou desconectar do seu ponto de conexão.

##  <a name="querysinkinterface"></a>  CConnectionPoint::QuerySinkInterface

Recupera um ponteiro para a interface do coletor solicitada.

```
virtual HRESULT QuerySinkInterface(
    LPUNKNOWN pUnkSink,
    void** ppInterface);
```

### <a name="parameters"></a>Parâmetros

*pUnkSink*<br/>
O identificador da interface do coletor que está sendo solicitado.

*ppInterface*<br/>
Um ponteiro para o ponteiro de interface identificado pelo *pUnkSink*. Se o objeto não dá suporte a essa interface, \* *ppInterface* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

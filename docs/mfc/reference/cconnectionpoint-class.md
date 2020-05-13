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
ms.openlocfilehash: ce72c156ab31b742a42d2960923fc56afff656c0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369437"
---
# <a name="cconnectionpoint-class"></a>Classe CConnectionPoint

Define um tipo especial de interface usado para se comunicar com outros objetos OLE, chamado de "ponto de conexão".

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
|[CConnectionPoint::Obterconexões](#getconnections)|Recupera todos os pontos de conexão em um mapa de conexão.|
|[CConnectionPoint::getContainer](#getcontainer)|Recupera o recipiente do controle que possui o mapa de conexão.|
|[CConnectionPoint::getiid](#getiid)|Recupera o ID de interface de um ponto de conexão.|
|[CConnectionPoint::GetMaxConnections](#getmaxconnections)|Recupera o número máximo de pontos de conexão suportados por um controle.|
|[Ponto de conexão de c::getNextConnection](#getnextconnection)|Recupera um ponteiro para o elemento de conexão em *pos*.|
|[Ponto de conexão::getStartPosition](#getstartposition)|Inicia uma iteração de mapa retornando um valor `GetNextConnection` DE POSIÇÃO que pode ser passado para uma chamada.|
|[CConnectionPoint::OnAdvise](#onadvise)|Chamado pela estrutura ao estabelecer ou quebrar conexões.|
|[CConnectionPoint::QuerySinkInterface](#querysinkinterface)|Recupera um ponteiro para a interface de pia solicitada.|

## <a name="remarks"></a>Comentários

Ao contrário das interfaces OLE normais, que são usadas para implementar e expor a funcionalidade de um controle OLE, um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como eventos de disparo e alterar notificações.

Uma conexão consiste em duas partes: o objeto que chama a interface, chamada de "fonte", e o objeto que implementa a interface, chamado de "pia". Ao expor um ponto de conexão, uma fonte permite que os sinks estabeleçam conexões a si mesmos. Através do mecanismo de ponto de conexão, um objeto de origem obtém um ponteiro para a implementação do sumidouro de um conjunto de funções de membro. Por exemplo, para disparar um evento implementado pela pia, a fonte pode chamar o método apropriado da implementação da pia.

Por padrão, `COleControl`uma classe derivada implementa dois pontos de conexão: um para eventos e outro para notificações de alteração de propriedade. Essas conexões são usadas, respectivamente, para o disparo de eventos e para notificar uma pia (por exemplo, o contêiner do controle) quando um valor de propriedade foi alterado. Também é fornecido suporte para que os controles OLE implementem pontos de conexão adicionais. Para cada ponto de conexão adicional implementado em sua classe de controle, você deve declarar uma "parte de conexão" que implemente o ponto de conexão. Se você implementar um ou mais pontos de conexão, você também precisa declarar um único "mapa de conexão" em sua classe de controle.

O exemplo a seguir demonstra um mapa `Sample` de conexão simples e um ponto de conexão para o controle OLE, consistindo de dois fragmentos de código: a primeira parte declara o mapa de conexão e o ponto; o segundo implementa este mapa e ponto. O primeiro fragmento é inserido na declaração da classe de controle, sob a seção **protegida:**

[!code-cpp[NVC_MFCConnectionPoints#7](../../mfc/codesnippet/cpp/cconnectionpoint-class_1.h)]

As macros BEGIN_CONNECTION_PART e END_CONNECTION_PART `XSampleConnPt` declaram uma `CConnectionPoint`classe incorporada, (derivada) que implementa este ponto de conexão particular. Se você quiser substituir `CConnectionPoint` quaisquer funções de membro ou adicionar funções de membro próprias, declare-as entre essas duas macros. Por exemplo, a CONNECTION_IID `CConnectionPoint::GetIID` macro substitui a função de membro quando colocada entre essas duas macros.

O segundo fragmento de código é inserido no arquivo de implementação (. CPP) da sua classe de controle. Este código implementa o mapa de conexão, `SampleConnPt`que inclui o ponto de conexão adicional:

[!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/cconnectionpoint-class_2.cpp)]

Uma vez que esses fragmentos de código tenham sido inseridos, `ISampleSink` o controle Sample OLE expõe um ponto de conexão para a interface.

Normalmente, os pontos de conexão suportam "multicasting", que é a capacidade de transmitir para vários sinks conectados à mesma interface. O fragmento de código a seguir demonstra como realizar a multicasting iterando através de cada pia em um ponto de conexão:

[!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]

Este exemplo recupera o conjunto atual `SampleConnPt` de conexões no `CConnectionPoint::GetConnections`ponto de conexão com uma chamada para . Em seguida, itera através das `ISampleSink::SinkFunc` conexões e chama em cada conexão ativa.

Para obter mais `CConnectionPoint`informações sobre como usar, consulte o artigo [Pontos de Conexão](../../mfc/connection-points.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CConnectionPoint`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="cconnectionpointcconnectionpoint"></a><a name="cconnectionpoint"></a>CConnectionPoint::CConnectionPoint

Constrói um objeto `CConnectionPoint`.

```
CConnectionPoint();
```

## <a name="cconnectionpointgetconnections"></a><a name="getconnections"></a>CConnectionPoint::Obterconexões

Chame esta função para recuperar todas as conexões ativas para um ponto de conexão.

```
const CPtrArray* GetConnections();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma matriz de conexões ativas (sinks). Alguns dos ponteiros na matriz podem ser NULAS. Cada ponteiro não-NULO nesta matriz pode ser convertido com segurança para um ponteiro para a interface do dissipador usando um operador de molde.

## <a name="cconnectionpointgetcontainer"></a><a name="getcontainer"></a>CConnectionPoint::getContainer

Chamado pela estrutura para `IConnectionPointContainer` recuperar o ponto de conexão.

```
virtual LPCONNECTIONPOINTCONTAINER GetContainer();
```

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, um ponteiro para o recipiente; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esta função é tipicamente implementada pela macro BEGIN_CONNECTION_PART.

## <a name="cconnectionpointgetiid"></a><a name="getiid"></a>CConnectionPoint::getiid

Chamado pela estrutura para recuperar o ID de interface de um ponto de conexão.

```
virtual REFIID GetIID() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao ID de interface do ponto de conexão.

### <a name="remarks"></a>Comentários

Anular esta função para retornar o ID da interface para este ponto de conexão.

## <a name="cconnectionpointgetmaxconnections"></a><a name="getmaxconnections"></a>CConnectionPoint::GetMaxConnections

Chamado pelo framework para recuperar o número máximo de conexões suportadas pelo ponto de conexão.

```
virtual int GetMaxConnections();
```

### <a name="return-value"></a>Valor retornado

O número máximo de conexões suportadas pelo controle, ou -1, se não houver limite.

### <a name="remarks"></a>Comentários

A implementação padrão retorna -1, indicando nenhum limite.

Anular esta função se você quiser limitar o número de pias que podem se conectar ao seu controle.

## <a name="cconnectionpointgetnextconnection"></a><a name="getnextconnection"></a>Ponto de conexão de c::getNextConnection

Recupera um ponteiro para o elemento de conexão em *pos*.

```
LPUNKNOWN GetNextConnection(POSITION& pos) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Especifica uma referência a um valor DE `GetNextConnection` POSIÇÃO retornado por uma chamada anterior ou [GetStartPosition.](#getstartposition)

### <a name="return-value"></a>Valor retornado

Um ponteiro para o elemento de conexão especificado por *pos*, ou NULL.

### <a name="remarks"></a>Comentários

Esta função é mais útil para iterar através de todos os elementos no mapa de conexão. Ao iterar, pule quaisquer NULLs retornados desta função.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]

## <a name="cconnectionpointgetstartposition"></a><a name="getstartposition"></a>Ponto de conexão::getStartPosition

Inicia uma iteração de mapa retornando um valor DE POSIÇÃO que pode ser passado para uma chamada [GetNextConnection.](#getnextconnection)

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que indique uma posição inicial para iterar o mapa; ou NULO se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; portanto, o "primeiro elemento no mapa" não tem significado especial.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CConnectionPoint::GetNextConnection](#getnextconnection).

## <a name="cconnectionpointonadvise"></a><a name="onadvise"></a>CConnectionPoint::OnAdvise

Chamado pela estrutura quando uma conexão está sendo estabelecida ou quebrada.

```
virtual void OnAdvise(BOOL bAdvise);
```

### <a name="parameters"></a>Parâmetros

*bAconselhar*<br/>
VERDADE, se uma conexão está sendo estabelecida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada.

Anular esta função se você quiser notificação quando os dissipadores se conectarem ou desconectarem do ponto de conexão.

## <a name="cconnectionpointquerysinkinterface"></a><a name="querysinkinterface"></a>CConnectionPoint::QuerySinkInterface

Recupera um ponteiro para a interface de pia solicitada.

```
virtual HRESULT QuerySinkInterface(
    LPUNKNOWN pUnkSink,
    void** ppInterface);
```

### <a name="parameters"></a>Parâmetros

*Punksink*<br/>
O identificador da interface do dissipador sendo solicitado.

*ppInterface*<br/>
Um ponteiro para o ponteiro de interface identificado por *pUnkSink*. Se o objeto não suportar \* essa interface, *ppInterface* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

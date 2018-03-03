---
title: Classe CConnectionPoint | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f6a9e9fafc2bbee9959a939815a92c9bc63a650f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[CConnectionPoint::GetNextConnection](#getnextconnection)|Recupera um ponteiro para o elemento de conexão no `pos`.|  
|[CConnectionPoint::GetStartPosition](#getstartposition)|Inicia uma iteração de mapa, retornando um **posição** valor que pode ser passado para um `GetNextConnection` chamar.|  
|[CConnectionPoint::OnAdvise](#onadvise)|Chamado pelo framework quando estabelecer ou interrompendo conexões.|  
|[CConnectionPoint::QuerySinkInterface](#querysinkinterface)|Recupera um ponteiro para a interface do coletor solicitada.|  
  
## <a name="remarks"></a>Comentários  
 Ao contrário das interfaces OLE normais, que são usados para implementar e expor a funcionalidade de um controle OLE, um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como disparar eventos e notificações de alteração.  
  
 Uma conexão consiste em duas partes: o objeto de chamada da interface, chamada de "origem" e o objeto que implementa a interface, chamado "sink". Ao expor um ponto de conexão, uma fonte permite coletores estabelecer conexões a mesmo. Por meio do mecanismo de ponto de conexão, um objeto de fonte obtém um ponteiro para a implementação do coletor de um conjunto de funções de membro. Por exemplo, para disparar um evento implementado pelo coletor, a origem pode chamar o método apropriado de implementação do coletor.  
  
 Por padrão, um `COleControl`-classe derivada implementa dois pontos de conexão: uma para eventos e uma propriedade de notificações de alteração. Essas conexões são usadas, respectivamente, para acionamento de evento e para notificar um coletor (por exemplo, o contêiner do controle) quando um valor de propriedade foi alterado. Suporte também é fornecido para controles OLE implementar pontos de conexão adicionais. Para cada ponto de conexão adicionais implementado em sua classe de controle, você deve declarar uma "parte de conexão" que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, você também precisa declarar um único "mapa de conexão" em sua classe de controle.  
  
 O exemplo a seguir demonstra um mapa de conexão simples e um ponto de conexão de um para o `Sample` controle OLE, consiste em dois fragmentos de código: a primeira parte declara o mapa de conexão e o ponto; a segunda implementa esse mapa e ponto. O primeiro fragmento é inserido na declaração da classe de controle, sob o `protected` seção:  
  
 [!code-cpp[NVC_MFCConnectionPoints#7](../../mfc/codesnippet/cpp/cconnectionpoint-class_1.h)]  
  
 O `BEGIN_CONNECTION_PART` e `END_CONNECTION_PART` macros declarar uma classe incorporada, `XSampleConnPt` (derivado de `CConnectionPoint`) que implementa este ponto de conexão específico. Se você quiser substituir qualquer `CConnectionPoint` funções de membro, ou adicionar funções de membro de sua preferência, declará-los entre essas duas macros. Por exemplo, o `CONNECTION_IID` macro substitui o `CConnectionPoint::GetIID` quando colocada entre essas duas macros de função de membro.  
  
 O segundo fragmento de código é inserido no arquivo de implementação (. CPP) de sua classe de controle. Esse código implementa o mapa de conexão, que inclui o ponto de conexão adicionais, `SampleConnPt`:  
  
 [!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/cconnectionpoint-class_2.cpp)]  
  
 Depois que esses fragmentos de código foram inseridos, o controle OLE do exemplo expõe um ponto de conexão para o **ISampleSink** interface.  
  
 Normalmente, os pontos de conexão oferecem suporte a "multicast", que é a capacidade de difusão para vários coletores conectados à mesma interface. O fragmento de código a seguir demonstra como realizar multicast ao iterar por cada coletor em um ponto de conexão:  
  
 [!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]  
  
 Este exemplo recupera o conjunto atual de conexões no `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections`. Ele itera por meio de conexões e chamadas `ISampleSink::SinkFunc` em cada conexão ativa.  
  
 Para obter mais informações sobre como usar `CConnectionPoint`, consulte o artigo [pontos de Conexão](../../mfc/connection-points.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CConnectionPoint`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="cconnectionpoint"></a>CConnectionPoint::CConnectionPoint  
 Constrói um objeto `CConnectionPoint`.  
  
```  
CConnectionPoint();
```  
  
##  <a name="getconnections"></a>CConnectionPoint::GetConnections  
 Chame essa função para recuperar todas as conexões ativas para um ponto de conexão.  
  
```  
const CPtrArray* GetConnections();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma matriz de conexões ativas (coletores). Alguns dos ponteiros na matriz podem ser NULL. Cada ponteiro nulos nesta matriz pode ser convertido com segurança para um ponteiro para a interface do coletor de uso de um operador de conversão.  
  
##  <a name="getcontainer"></a>CConnectionPoint::GetContainer  
 Chamado pelo framework para recuperar o **IConnectionPointContainer** para o ponto de conexão.  
  
```  
virtual LPCONNECTIONPOINTCONTAINER GetContainer();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para o contêiner; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Essa função é geralmente implementada pelo `BEGIN_CONNECTION_PART` macro.  
  
##  <a name="getiid"></a>CConnectionPoint::GetIID  
 Chamado pelo framework para recuperar a ID de interface de um ponto de conexão.  
  
```  
virtual REFIID GetIID() = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência à ID de interface. do ponto de conexão  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para retornar a ID de interface para este ponto de conexão.  
  
##  <a name="getmaxconnections"></a>CConnectionPoint::GetMaxConnections  
 Chamado pelo framework para recuperar o número máximo de conexões suportadas pelo ponto de conexão.  
  
```  
virtual int GetMaxConnections();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de conexões suportadas pelo controle, ou -1 se não há limite.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão retorna -1, indicando que não há limite.  
  
 Substitua essa função se você deseja limitar o número de receptores que pode se conectar ao seu controle.  
  
##  <a name="getnextconnection"></a>CConnectionPoint::GetNextConnection  
 Recupera um ponteiro para o elemento de conexão no `pos`.  
  
```  
LPUNKNOWN GetNextConnection(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Especifica uma referência a um **posição** valor retornado pelo anterior `GetNextConnection` ou [GetStartPosition](#getstartposition) chamar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o elemento de conexão especificado por `pos`, ou nulo.  
  
### <a name="remarks"></a>Comentários  
 Essa função é mais útil para iterar através de todos os elementos no mapa de conexão. Ao fazer a iteração, ignore quaisquer valores nulos retornados de sua função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCConnectionPoints#4](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]  
  
##  <a name="getstartposition"></a>CConnectionPoint::GetStartPosition  
 Inicia uma iteração de mapa, retornando um **posição** valor que pode ser passado para um [GetNextConnection](#getnextconnection) chamar.  
  
```  
POSITION GetStartPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que indica uma posição inicial para o mapa; de iteração ou **nulo** se o mapa estiver vazio.  
  
### <a name="remarks"></a>Comentários  
 A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" não tem nenhum significado especial.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CConnectionPoint::GetNextConnection](#getnextconnection).  
  
##  <a name="onadvise"></a>CConnectionPoint::OnAdvise  
 Chamado pelo framework quando uma conexão está sendo estabelecida ou corrompida.  
  
```  
virtual void OnAdvise(BOOL bAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAdvise`  
 **TRUE**, se uma conexão está sendo estabelecida; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não fará nada.  
  
 Substitua essa função se desejar notificação quando coletores conectem ou desconectar do seu ponto de conexão.  
  
##  <a name="querysinkinterface"></a>CConnectionPoint::QuerySinkInterface  
 Recupera um ponteiro para a interface do coletor solicitada.  
  
```  
virtual HRESULT QuerySinkInterface(
    LPUNKNOWN pUnkSink,  
    void** ppInterface);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkSink`  
 O identificador da interface do coletor está sendo solicitado.  
  
 `ppInterface`  
 Um ponteiro para o ponteiro de interface identificado por `pUnkSink`. Se o objeto não oferece suporte a essa interface, \* `ppInterface` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)


---
title: Classe CConnectionPoint | Documentos do Microsoft
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
- CConnectionPoint class
ms.assetid: f0f23a1e-5e8c-41a9-aa6c-1a4793b28e8f
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: a511f252bf921433d070059518e6e67b952680eb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cconnectionpoint-class"></a>Classe CConnectionPoint
Define um tipo especial de interface usada para se comunicar com outros objetos OLE, chamados de "ponto de conexão".  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CConnectionPoint : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
|[CConnectionPoint::GetStartPosition](#getstartposition)|Inicia uma iteração de mapa, retornando uma **posição** valor que pode ser passado para um `GetNextConnection` chamar.|  
|[CConnectionPoint::OnAdvise](#onadvise)|Chamado pela estrutura quando estabelecer ou romper conexões.|  
|[CConnectionPoint::QuerySinkInterface](#querysinkinterface)|Recupera um ponteiro para a interface sink solicitada.|  
  
## <a name="remarks"></a>Comentários  
 Ao contrário de interfaces OLE normais, que são usados para implementar e expor a funcionalidade de um controle OLE, um ponto de conexão implementa uma interface de saída que é capaz de iniciar ações em outros objetos, como acionar eventos e notificações de alteração.  
  
 Uma conexão consiste em duas partes: o objeto chamando a interface, chamada de "origem" e o objeto que implementa a interface, chamado "sink". Ao expor um ponto de conexão, uma fonte permite coletores estabelecer conexões a mesmo. Por meio do mecanismo de ponto de conexão, um objeto de origem obtém um ponteiro para a implementação do coletor de um conjunto de funções de membro. Por exemplo, para disparar um evento implementado pelo coletor, a fonte pode chamar o método apropriado de implementação do coletor.  
  
 Por padrão, um `COleControl`-classe derivada implementa dois pontos de conexão: um para eventos e outro para a propriedade notificações de alteração. Essas conexões são usadas, respectivamente, para o acionamento de evento e notificar um coletor (por exemplo, o contêiner do controle) quando um valor de propriedade foi alterada. Suporte também é fornecido para controles OLE implementar pontos de conexão adicionais. Para cada ponto de conexão adicionais implementado em sua classe de controle, você deve declarar uma "parte de conexão" que implementa o ponto de conexão. Se você implementar um ou mais pontos de conexão, você também precisa declarar uma única "mapa de conexão" em sua classe de controle.  
  
 O exemplo a seguir demonstra um mapa de conexão simples e um ponto de uma conexão para o `Sample` de controle OLE, consiste em dois fragmentos de código: a primeira parte declara o mapa da conexão e o ponto; o segundo implementa esse mapa e ponto. O primeiro fragmento é inserido na declaração da classe de controle, sob o `protected` seção:  
  
 [!code-cpp[NVC_MFCConnectionPoints&#7;](../../mfc/codesnippet/cpp/cconnectionpoint-class_1.h)]  
  
 O `BEGIN_CONNECTION_PART` e `END_CONNECTION_PART` macros declarar uma classe incorporada, `XSampleConnPt` (derivada de `CConnectionPoint`) que implementa esse ponto de conexão específico. Se você quiser substituir qualquer `CConnectionPoint` funções de membro, ou adicionar funções de membro de sua preferência, declará-los entre essas duas macros. Por exemplo, o `CONNECTION_IID` macro substitui o `CConnectionPoint::GetIID` quando colocada entre essas duas macros de função de membro.  
  
 O segundo fragmento de código é inserido no arquivo de implementação (. CPP) de sua classe de controle. Esse código implementa um mapa de conexão, que inclui o ponto de conexão adicionais, `SampleConnPt`:  
  
 [!code-cpp[NVC_MFCConnectionPoints n º&2;](../../mfc/codesnippet/cpp/cconnectionpoint-class_2.cpp)]  
  
 Depois que esses fragmentos de código tem sido inseridos, o controle de exemplo OLE expõe um ponto de conexão para o **ISampleSink** interface.  
  
 Normalmente, os pontos de conexão oferecem suporte a "difusão seletiva", que é a capacidade para transmissão para vários coletores conectados à mesma interface. O fragmento de código a seguir demonstra como realizar difusão seletiva iterando por cada coletor em um ponto de conexão:  
  
 [!code-cpp[NVC_MFCConnectionPoints n º&4;](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]  
  
 Este exemplo recupera o conjunto atual de conexões no `SampleConnPt` ponto de conexão com uma chamada para `CConnectionPoint::GetConnections`. Em seguida, itera através de conexões e chama `ISampleSink::SinkFunc` em cada conexão ativa.  
  
 Para obter mais informações sobre como usar o `CConnectionPoint`, consulte o artigo [pontos de Conexão](../../mfc/connection-points.md).  
  
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
 Um ponteiro para uma matriz de conexões ativas (coletores). Alguns dos ponteiros na matriz podem ser NULL. Cada ponteiro não-NULL nesta matriz pode ser convertido com segurança em um ponteiro para a interface de coletor usando um operador cast.  
  
##  <a name="getcontainer"></a>CConnectionPoint::GetContainer  
 Chamado pela estrutura para recuperar o **IConnectionPointContainer** para o ponto de conexão.  
  
```  
virtual LPCONNECTIONPOINTCONTAINER GetContainer();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para o contêiner; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é implementada pelo `BEGIN_CONNECTION_PART` macro.  
  
##  <a name="getiid"></a>CConnectionPoint::GetIID  
 Chamado pela estrutura para recuperar a ID de interface de um ponto de conexão.  
  
```  
virtual REFIID GetIID() = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência à ID de interface. do ponto de conexão  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para retornar a ID de interface para esse ponto de conexão.  
  
##  <a name="getmaxconnections"></a>CConnectionPoint::GetMaxConnections  
 Chamado pela estrutura para recuperar o número máximo de conexões suportadas pelo ponto de conexão.  
  
```  
virtual int GetMaxConnections();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de conexões suportadas pelo controle ou -1 se não há limite.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão retorna -1, indicando que não há limite.  
  
 Substitua essa função se você deseja limitar o número de PIAs que podem se conectar ao seu controle.  
  
##  <a name="getnextconnection"></a>CConnectionPoint::GetNextConnection  
 Recupera um ponteiro para o elemento de conexão no `pos`.  
  
```  
LPUNKNOWN GetNextConnection(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Especifica uma referência a um **posição** valor retornado por uma anterior `GetNextConnection` ou [GetStartPosition](#getstartposition) chamar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o elemento de conexão especificado por `pos`, ou nulo.  
  
### <a name="remarks"></a>Comentários  
 Essa função é mais útil para iterar todos os elementos no mapa de conexão. Durante a iteração, ignore quaisquer valores nulos retornados de sua função.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCConnectionPoints n º&4;](../../mfc/codesnippet/cpp/cconnectionpoint-class_3.cpp)]  
  
##  <a name="getstartposition"></a>CConnectionPoint::GetStartPosition  
 Inicia uma iteração de mapa, retornando uma **posição** valor que pode ser passado para um [GetNextConnection](#getnextconnection) chamar.  
  
```  
POSITION GetStartPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que indica uma posição inicial para o mapa; de iteração ou **nulo** se o mapa estiver vazio.  
  
### <a name="remarks"></a>Comentários  
 A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" não tem nenhum significado especial.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CConnectionPoint::GetNextConnection](#getnextconnection).  
  
##  <a name="onadvise"></a>CConnectionPoint::OnAdvise  
 Chamado pela estrutura quando uma conexão está sendo estabelecida ou corrompida.  
  
```  
virtual void OnAdvise(BOOL bAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAdvise`  
 **TRUE**, se uma conexão está sendo estabelecida; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada.  
  
 Substitua essa função se desejar notificação quando coletores conectem ou desconectar do seu ponto de conexão.  
  
##  <a name="querysinkinterface"></a>CConnectionPoint::QuerySinkInterface  
 Recupera um ponteiro para a interface sink solicitada.  
  
```  
virtual HRESULT QuerySinkInterface(
    LPUNKNOWN pUnkSink,  
    void** ppInterface);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkSink`  
 O identificador da interface do coletor que está sendo solicitado.  
  
 `ppInterface`  
 Um ponteiro para o ponteiro de interface identificado pelo `pUnkSink`. Se o objeto não oferece suporte a essa interface, \* `ppInterface` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)



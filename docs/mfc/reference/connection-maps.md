---
title: "Mapas de Conexão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- connection maps
ms.assetid: 1f25a9bc-6d09-4614-99cf-dc38e8ddfa73
caps.latest.revision: 12
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
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 8947930d20cc65075abe442b233e4c086f10f76e
ms.lasthandoff: 02/25/2017

---
# <a name="connection-maps"></a>Mapas de conexão
Controles OLE são capazes de expor interfaces para outros aplicativos. Essas interfaces somente permitem o acesso de um contêiner em que o controle. Se um controle OLE quiser acessar as interfaces externas de outros objetos OLE, um ponto de conexão deve ser estabelecido. Esse ponto de conexão permite que um controle de acesso para mapas de expedição externos, como mapas de evento ou funções de notificação de saída.  
  
 A biblioteca Microsoft Foundation Class oferece um modelo de programação que oferece suporte a pontos de conexão. Nesse modelo, "conexão mapeia" são usadas para designar as interfaces ou pontos de conexão para o controle OLE. Mapas de Conexão contêm uma macro para cada ponto de conexão. Para obter mais informações sobre mapas de conexão, consulte o [CConnectionPoint](../../mfc/reference/cconnectionpoint-class.md) classe.  
  
 Normalmente, um controle oferecerá suporte apenas dois pontos de conexão: um para eventos e outro para receber notificações de propriedade. Eles são implementados pela `COleControl` classe base e não exigem nenhum trabalho adicional pelo gravador do controle. Os pontos de conexão adicionais que você deseja implementar em sua classe devem ser adicionados manualmente. Para oferecer suporte a mapas de conexão e pontos, o MFC fornece as seguintes macros:  
  
### <a name="connection-map-declaration-and-demarcation"></a>Declaração de mapa de Conexão e demarcação  
  
|||  
|-|-|  
|[BEGIN_CONNECTION_PART](#begin_connection_part)|Declara uma classe incorporada que implementa um ponto de conexão adicionais (deve ser usado na declaração da classe).|  
|[END_CONNECTION_PART](#end_connection_part)|Termina a declaração de um ponto de conexão (deve ser usado na declaração da classe).|  
|[CONNECTION_IID](#connection_iid)|Especifica a ID de interface de ponto de conexão do controle.|  
|[DECLARE_CONNECTION_MAP](#declare_connection_map)|Declara que um mapa de conexão será usado em uma classe (deve ser usado na declaração da classe).|  
|[BEGIN_CONNECTION_MAP](#begin_connection_map)|Começa a definição de um mapa de conexão (deve ser usado na implementação da classe).|  
|[END_CONNECTION_MAP](#end_connection_map)|Termina a definição de um mapa de conexão (deve ser usado na implementação da classe).|  
|[CONNECTION_PART](#connection_part)|Especifica um ponto de conexão no mapa de conexão do controle.|  
  
 As seguintes funções de auxiliar um coletor na criação e desconectar uma conexão usando os pontos de conexão:  
  
### <a name="initializationtermination-of-connection-points"></a>Inicialização/encerramento dos pontos de Conexão  
  
|||  
|-|-|  
|[AfxConnectionAdvise](#afxconnectionadvise)|Estabelece uma conexão entre uma origem e um coletor.|  
|[AfxConnectionUnadvise](#afxconnectionunadvise)|Interrompe uma conexão entre uma origem e um coletor.|  
  
##  <a name="a-namebeginconnectionparta--beginconnectionpart"></a><a name="begin_connection_part"></a>BEGIN_CONNECTION_PART  
 Use o `BEGIN_CONNECTION_PART` macro para começar a definição de pontos de conexão adicionais além os pontos de conexão de notificação de evento e uma propriedade.  
  
```   
BEGIN_CONNECTION_PART(theClass, localClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe de controle cuja conexão ponto, isso é.  
  
 *localClass*  
 Especifica o nome da classe local que implementa o ponto de conexão.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de declaração (. h) que define as funções de membro da sua classe, iniciar o ponto de conexão com o `BEGIN_CONNECTION_PART` macro, em seguida, adicione o `CONNECTION_IID` macro e outras funções de membro que deseja implementar e concluir o mapa de ponto de conexão com o `END_CONNECTION_PART` macro.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameendconnectionparta--endconnectionpart"></a><a name="end_connection_part"></a>END_CONNECTION_PART  
 Termina a declaração do seu ponto de conexão.  
  
```   
END_CONNECTION_PART(localClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *localClass*  
 Especifica o nome da classe local que implementa o ponto de conexão.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameconnectioniida--connectioniid"></a><a name="connection_iid"></a>CONNECTION_IID  
 Use entre o `BEGIN_CONNECTION_PART` e `END_CONNECTION_PART` macros para definir uma identificação de interface para um ponto de conexão com suporte de controle OLE.  
  
```   
CONNECTION_IID(iid)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 A ID de interface da interface chamado pelo ponto de conexão.  
  
### <a name="remarks"></a>Comentários  
 O `iid` argumento é uma interface usada para identificar a interface que chama o ponto de conexão no seus coletores conectados. Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints n º&10;](../../mfc/codesnippet/cpp/connection-maps_1.h)]  
  
 Especifica um ponto de conexão que chama o `ISinkInterface` interface.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-namedeclareconnectionmapa--declareconnectionmap"></a><a name="declare_connection_map"></a>DECLARE_CONNECTION_MAP  
 Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de conexão para especificar pontos de conexão adicionais que dá suporte a seu controle.  
  
```   
DECLARE_CONNECTION_MAP() 
```  
  
### <a name="remarks"></a>Comentários  
 Se o controle suporta pontos adicionais, use o `DECLARE_CONNECTION_MAP` macro no final da sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use o `BEGIN_CONNECTION_MAP` macro `CONNECTION_PART` macros para cada um dos pontos de conexão do controle e o `END_CONNECTION_MAP` macro para declarar o fim do mapa de conexão.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-namebeginconnectionmapa--beginconnectionmap"></a><a name="begin_connection_map"></a>BEGIN_CONNECTION_MAP  
 Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de conexão para especificar os pontos de conexão que darão suporte a seu controle.  
  
```   
BEGIN_CONNECTION_MAP(theClass, theBase)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe de controle cuja conexão mapear isso.  
  
 *theBase*  
 Especifica o nome da classe base da `theClass`.  
  
### <a name="remarks"></a>Comentários  
 Na implementação (. Arquivo CPP) que define as funções de membro para sua classe, inicie o mapa de conexão com o `BEGIN_CONNECTION_MAP` macro, adicione entradas de macro para cada um dos seus pontos de conexão usando o [CONNECTION_PART](#connection_part) macro. Finalmente, conclua o mapa de conexão com o [END_CONNECTION_MAP](#end_connection_map) macro.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameendconnectionmapa--endconnectionmap"></a><a name="end_connection_map"></a>END_CONNECTION_MAP  
 Termina a definição de seu mapa de conexão.  
  
```   
END_CONNECTION_MAP()  
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameconnectionparta--connectionpart"></a><a name="connection_part"></a>CONNECTION_PART  
 Um ponto de conexão para o seu controle OLE é mapeado para uma ID de interface específica.  
  
```   
CONNECTION_PART(theClass, iid, localClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe de controle cuja conexão ponto, isso é.  
  
 `iid`  
 A ID de interface da interface chamado pelo ponto de conexão.  
  
 *localClass*  
 Especifica o nome da classe local que implementa o ponto de conexão.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints n º&2;](../../mfc/codesnippet/cpp/connection-maps_2.cpp)]  
  
 implementa um mapa de conexão, com um ponto de conexão, que chama o `IID_ISinkInterface` interface.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameafxconnectionadvisea--afxconnectionadvise"></a><a name="afxconnectionadvise"></a>AfxConnectionAdvise  
 Chame essa função para estabelecer uma conexão entre uma fonte, especificada por `pUnkSrc`e uma PIA, especificado por `pUnkSink`.  
  
```   
BOOL AFXAPI AfxConnectionAdvise(
    LPUNKNOWN pUnkSrc, 
    REFIID iid, 
    LPUNKNOWN pUnkSink, 
    BOOL bRefCount, 
    DWORD FAR* pdwCookie);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkSrc`  
 Um ponteiro para o objeto que chama a interface.  
  
 `pUnkSink`  
 Um ponteiro para o objeto que implementa a interface.  
  
 `iid`  
 A ID de interface da conexão.  
  
 `bRefCount`  
 **TRUE** indica que a criação de conexão deve causar a contagem de referência de `pUnkSink` a ser incrementado. **FALSE** indica que a contagem de referência não deve ser incrementada.  
  
 `pdwCookie`  
 Um ponteiro para um `DWORD` onde um identificador de conexão é retornado. Esse valor deve ser passado como o `dwCookie` parâmetro `AfxConnectionUnadvise` ao desconectar a conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma conexão foi estabelecida. Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCConnectionPoints n º&8;](../../mfc/codesnippet/cpp/connection-maps_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h 

##  <a name="a-nameafxconnectionunadvisea--afxconnectionunadvise"></a><a name="afxconnectionunadvise"></a>AfxConnectionUnadvise  
 Chame essa função para desconectar uma conexão entre uma fonte, especificada por `pUnkSrc`e uma PIA, especificado por `pUnkSink`.  
  
```   
BOOL AFXAPI AfxConnectionUnadvise(
    LPUNKNOWN pUnkSrc, 
    REFIID iid, 
    LPUNKNOWN pUnkSink, 
    BOOL bRefCount, 
    DWORD dwCookie); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkSrc`  
 Um ponteiro para o objeto que chama a interface.  
  
 `pUnkSink`  
 Um ponteiro para o objeto que implementa a interface.  
  
 `iid`  
 A ID de interface da interface do ponto de conexão.  
  
 `bRefCount`  
 **TRUE** indica que a desconectar a conexão deve causar a contagem de referência de `pUnkSink` a ser diminuída. **FALSE** indica que a contagem de referência não deve ser diminuída.  
  
 `dwCookie`  
 O identificador de conexão retornado por `AfxConnectionAdvise`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a conexão foi desconectada; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCConnectionPoints n º&9;](../../mfc/codesnippet/cpp/connection-maps_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)


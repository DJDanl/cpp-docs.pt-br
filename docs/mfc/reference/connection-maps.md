---
title: Mapas de Conexão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.maps
dev_langs:
- C++
helpviewer_keywords:
- connection maps
ms.assetid: 1f25a9bc-6d09-4614-99cf-dc38e8ddfa73
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28a82cc55e1cbf782603c7b34368fbc3d4ebe4c4
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37079190"
---
# <a name="connection-maps"></a>Mapas de conexão
Controles OLE são capazes de expor interfaces para outros aplicativos. Essas interfaces só permitem acesso de um contêiner em que o controle. Se um controle OLE quer acessar interfaces externas de outros objetos OLE, um ponto de conexão deve ser estabelecido. Esse ponto de conexão permite que um controle de acesso para mapas de expedição externo, como mapas de evento ou funções de notificação de saída.  
  
 A biblioteca Microsoft Foundation Class oferece um modelo de programação que dá suporte a pontos de conexão. Nesse modelo, "conexão mapeia" são usadas para designar as interfaces ou pontos de conexão para o controle OLE. Mapas de Conexão contêm uma macro para cada ponto de conexão. Para obter mais informações sobre mapas de conexão, consulte o [CConnectionPoint](../../mfc/reference/cconnectionpoint-class.md) classe.  
  
 Normalmente, um controle oferecerá suporte a apenas dois pontos de conexão: uma para eventos e outra para notificações de propriedade. Eles são implementados pela `COleControl` classe base e não exigem nenhum trabalho adicional pelo gerador de controle. Pontos de conexão adicionais que você deseja implementar em sua classe devem ser adicionados manualmente. Para dar suporte a mapas de conexão e pontos, MFC fornece as seguintes macros:  
  
### <a name="connection-map-declaration-and-demarcation"></a>Declaração de mapa de Conexão e demarcação  
  
|||  
|-|-|  
|[BEGIN_CONNECTION_PART](#begin_connection_part)|Declara uma classe incorporada que implementa um ponto de conexão adicionais (deve ser usado na declaração da classe).|  
|[END_CONNECTION_PART](#end_connection_part)|Termina a declaração de um ponto de conexão (deve ser usado na declaração da classe).|  
|[CONNECTION_IID](#connection_iid)|Especifica a ID de interface de ponto de conexão do controle.|  
|[DECLARE_CONNECTION_MAP](#declare_connection_map)|Declara que um mapa de conexão será usado em uma classe (deve ser usado na declaração da classe).|  
|[BEGIN_CONNECTION_MAP](#begin_connection_map)|Começa a definição de um mapa de conexão (deve ser usado na implementação de classe).|  
|[END_CONNECTION_MAP](#end_connection_map)|Finaliza a definição de um mapa de conexão (deve ser usado na implementação de classe).|  
|[CONNECTION_PART](#connection_part)|Especifica um ponto de conexão no mapa de conexão do controle.|  
  
 As funções a seguir ajudar um coletor de estabelecer e desconectar uma conexão usando os pontos de conexão:  
  
### <a name="initializationtermination-of-connection-points"></a>Inicialização/término de pontos de Conexão  
  
|||  
|-|-|  
|[AfxConnectionAdvise](#afxconnectionadvise)|Estabelece uma conexão entre uma origem e um coletor.|  
|[AfxConnectionUnadvise](#afxconnectionunadvise)|Interrompe uma conexão entre uma origem e um coletor.|  
  
##  <a name="begin_connection_part"></a>  BEGIN_CONNECTION_PART  
 Use o `BEGIN_CONNECTION_PART` macro para começar a definição de pontos de conexão adicionais além os pontos de conexão de notificação de evento e propriedade.  
  
```   
BEGIN_CONNECTION_PART(theClass, localClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 Especifica o nome da classe de controle cuja conexão ponto isso.  
  
 *localClass*  
 Especifica o nome da classe local que implementa o ponto de conexão.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de declaração (h) que define as funções de membro para a sua classe, iniciar o ponto de conexão com a macro BEGIN_CONNECTION_PART, em seguida, adicionar a macro CONNECTION_IID e outras funções de membro que deseja implementar e concluir a conexão ponto de mapa com a macro END_CONNECTION_PART.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="end_connection_part"></a>  END_CONNECTION_PART  
 Termina a declaração do seu ponto de conexão.  
  
```   
END_CONNECTION_PART(localClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *localClass*  
 Especifica o nome da classe local que implementa o ponto de conexão.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="connection_iid"></a>  CONNECTION_IID  
 Use entre o BEGIN_CONNECTION_PART e END_CONNECTION_PART macros para definir uma ID de interface para um ponto de conexão tem suportada de controle OLE.  
  
```   
CONNECTION_IID(iid)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *IID*  
 A ID de interface da interface chamado pelo ponto de conexão.  
  
### <a name="remarks"></a>Comentários  
 O *iid* argumento é uma interface ID usada para identificar a interface que chamará o ponto de conexão em seus coletores conectados. Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#10](../../mfc/codesnippet/cpp/connection-maps_1.h)]  
  
 Especifica um ponto de conexão que chama o `ISinkInterface` interface.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="declare_connection_map"></a>  DECLARE_CONNECTION_MAP  
 Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de conexão para especificar pontos de conexão adicionais que dá suporte a seu controle.  
  
```   
DECLARE_CONNECTION_MAP() 
```  
  
### <a name="remarks"></a>Comentários  
 Se o controle dá suporte a pontos adicionais, use a macro DECLARE_CONNECTION_MAP no final da sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro para a classe, use a macro BEGIN_CONNECTION_MAP, macros CONNECTION_PART para cada um dos pontos de conexão do controle e a macro END_CONNECTION_MAP para declarar o fim do mapa de conexão.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="begin_connection_map"></a>  BEGIN_CONNECTION_MAP  
 Cada `COleControl`-classe derivada em seu programa pode fornecer um mapa de conexão para especificar pontos de conexão que o controle oferecerá suporte.  
  
```   
BEGIN_CONNECTION_MAP(theClass, theBase)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 Especifica o nome da classe de controle cuja conexão mapeá-la.  
  
 *theBase*  
 Especifica o nome da classe base do *theClass*.  
  
### <a name="remarks"></a>Comentários  
 Na implementação (. Arquivo CPP) que define o membro funções para sua classe, inicie o mapa de conexão com a macro BEGIN_CONNECTION_MAP e adicione entradas de macro para cada um dos seus pontos de conexão usando o [CONNECTION_PART](#connection_part) macro. Finalmente, conclua o mapa de conexão com o [END_CONNECTION_MAP](#end_connection_map) macro.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="end_connection_map"></a>  END_CONNECTION_MAP  
 Finaliza a definição de seu mapa de conexão.  
  
```   
END_CONNECTION_MAP()  
```  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="connection_part"></a>  CONNECTION_PART  
 Um ponto de conexão para o seu controle OLE é mapeado para uma ID de interface específica.  
  
```   
CONNECTION_PART(theClass, iid, localClass)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 Especifica o nome da classe de controle cuja conexão ponto isso.  
  
 *IID*  
 A ID de interface da interface chamado pelo ponto de conexão.  
  
 *localClass*  
 Especifica o nome da classe local que implementa o ponto de conexão.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo:  
  
 [!code-cpp[NVC_MFCConnectionPoints#2](../../mfc/codesnippet/cpp/connection-maps_2.cpp)]  
  
 implementa um mapa de conexão, com um ponto de conexão, que chama o `IID_ISinkInterface` interface.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="afxconnectionadvise"></a>  AfxConnectionAdvise  
 Chamar essa função para estabelecer uma conexão entre uma fonte, especificado por *pUnkSrc*e um coletor, especificado por *pUnkSink*.  
  
```   
BOOL AFXAPI AfxConnectionAdvise(
    LPUNKNOWN pUnkSrc, 
    REFIID iid, 
    LPUNKNOWN pUnkSink, 
    BOOL bRefCount, 
    DWORD FAR* pdwCookie);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnkSrc*  
 Um ponteiro para o objeto que chama a interface.  
  
 *pUnkSink*  
 Um ponteiro para o objeto que implementa a interface.  
  
 *IID*  
 A ID de interface da conexão.  
  
 *bRefCount*  
 **TRUE** indica que a criar a conexão deve fazer com que a contagem de referência de *pUnkSink* a ser incrementado. **FALSE** indica que a contagem de referência não deve ser incrementada.  
  
 *pdwCookie*  
 Um ponteiro para um `DWORD` onde um identificador de conexão é retornado. Esse valor deve ser passado como o *dwCookie* parâmetro `AfxConnectionUnadvise` ao desconectar-se a conexão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma conexão foi estabelecida. Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCConnectionPoints#8](../../mfc/codesnippet/cpp/connection-maps_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h 

##  <a name="afxconnectionunadvise"></a>  AfxConnectionUnadvise  
 Chamar essa função para desconectar uma conexão entre uma fonte, especificado por *pUnkSrc*e um coletor, especificado por *pUnkSink*.  
  
```   
BOOL AFXAPI AfxConnectionUnadvise(
    LPUNKNOWN pUnkSrc, 
    REFIID iid, 
    LPUNKNOWN pUnkSink, 
    BOOL bRefCount, 
    DWORD dwCookie); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnkSrc*  
 Um ponteiro para o objeto que chama a interface.  
  
 *pUnkSink*  
 Um ponteiro para o objeto que implementa a interface.  
  
 *IID*  
 A ID de interface da interface de ponto de conexão.  
  
 *bRefCount*  
 **TRUE** indica que a desconectar a conexão deve causar a contagem de referência de *pUnkSink* ser diminuída. **FALSE** indica que a contagem de referência não deve ser diminuída.  
  
 *dwCookie*  
 O identificador de conexão retornado por `AfxConnectionAdvise`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma conexão foi desconectada; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCConnectionPoints#9](../../mfc/codesnippet/cpp/connection-maps_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

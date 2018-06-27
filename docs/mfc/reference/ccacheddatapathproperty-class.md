---
title: Classe CCachedDataPathProperty | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty::CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty::m_Cache
dev_langs:
- C++
helpviewer_keywords:
- CCachedDataPathProperty [MFC], CCachedDataPathProperty
- CCachedDataPathProperty [MFC], m_Cache
ms.assetid: 0d81356b-4fe5-43f6-aed2-2eb5a5485706
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8b264b2366ce4fb7234d5906222fb4f8aa750212
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951410"
---
# <a name="ccacheddatapathproperty-class"></a>Classe CCachedDataPathProperty
Implementa uma OLE propriedade transferido de forma assíncrona e armazenados em cache em um arquivo de memória de controle.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCachedDataPathProperty : public CDataPathProperty  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCachedDataPathProperty::CCachedDataPathProperty](#ccacheddatapathproperty)|Constrói um objeto `CCachedDataPathProperty`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCachedDataPathProperty::m_Cache](#m_cache)|`CMemFile` objeto no qual os dados em cache.|  
  
## <a name="remarks"></a>Comentários  
 Um arquivo de memória é armazenado na RAM e não no disco e é útil para transferências rápida temporárias.  
  
 Juntamente com `CAysncMonikerFile` e `CDataPathProperty`, `CCachedDataPathProperty` fornece funcionalidade para o uso de monikers assíncronos em controles OLE. Com `CCachedDataPathProperty` objetos, é possível transferir dados de uma fonte de arquivo ou URL de forma assíncrona e armazená-lo em um arquivo de memória por meio de `m_Cache` variável pública. Todos os dados são armazenados no arquivo de memória e não é necessário substituir [OnDataAvailable](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable) , a menos que você deseja observar as notificações e responder. Por exemplo, se você transferir uma grande. Substituir arquivo GIF e desejar notificar seu controle que mais dados são recebidos e ele deve ser redesenhado, `OnDataAvailable` para fazer a notificação.  
  
 A classe `CCachedDataPathProperty` é derivado de `CDataPathProperty`.  
  
 Para obter mais informações sobre como usar monikers assíncronos e controles ActiveX em aplicativos da Internet, consulte os tópicos a seguir:  
  
- [Internet primeiras etapas: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)  
  
- [Internet primeiras etapas: Monikers assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [COleStreamFile](../../mfc/reference/colestreamfile-class.md)  
  
 [CMonikerFile](../../mfc/reference/cmonikerfile-class.md)  
  
 [CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)  
  
 [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)  
  
 `CCachedDataPathProperty`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h  
  
##  <a name="ccacheddatapathproperty"></a>  CCachedDataPathProperty::CCachedDataPathProperty  
 Constrói um objeto `CCachedDataPathProperty`.  
  
```  
CCachedDataPathProperty(COleControl* pControl = NULL);

 
CCachedDataPathProperty(
    LPCTSTR lpszPath,  
    COleControl* pControl = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pControl*  
 Um ponteiro para o objeto de controle ActiveX a ser associado este `CCachedDataPathProperty` objeto.  
  
 *lpszPath*  
 O caminho, o que pode ser absoluta ou relativa, usado para criar um moniker assíncrona que faz referência a localização absoluta real da propriedade. `CCachedDataPathProperty` usa URLs, nomes de arquivos não. Se você quiser um `CCachedDataPathProperty` de objeto para um arquivo, preceda file:// para o caminho.  
  
### <a name="remarks"></a>Comentários  
 O `COleControl` objeto apontada pelo *pControl* é usado pelo [abrir](../../mfc/reference/cdatapathproperty-class.md#open) e recuperados pelas classes derivadas. Se *pControl* é **nulo**, o controle usado com `Open` deve ser definido com [SetControl](../../mfc/reference/cdatapathproperty-class.md#setcontrol). Se *lpszPath* é **nulo**, você pode passar o caminho por meio de `Open` ou defini-lo com [SetPath](../../mfc/reference/cdatapathproperty-class.md#setpath).  
  
##  <a name="m_cache"></a>  CCachedDataPathProperty::m_Cache  
 Contém o nome da classe do arquivo de memória na qual os dados em cache.  
  
```  
CMemFile m_Cache;  
```  
  
### <a name="remarks"></a>Comentários  
 Um arquivo de memória é armazenado na RAM e não no disco.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)

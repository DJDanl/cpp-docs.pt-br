---
title: Classe CCachedDataPathProperty | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty::CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty::m_Cache
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [C++], asynchronous
- CCachedDataPathProperty class
- OLE controls [C++], asynchronous
- asynchronous controls [C++]
- memory files [C++]
ms.assetid: 0d81356b-4fe5-43f6-aed2-2eb5a5485706
caps.latest.revision: 22
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 6e3f54e6429456be24cbe18471abd1705bbe0034
ms.lasthandoff: 02/25/2017

---
# <a name="ccacheddatapathproperty-class"></a>Classe CCachedDataPathProperty
Propriedade transferido de forma assíncrona e armazenado em cache em um arquivo de memória do controle implementa uma OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCachedDataPathProperty : public CDataPathProperty  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCachedDataPathProperty::CCachedDataPathProperty](#ccacheddatapathproperty)|Constrói um objeto `CCachedDataPathProperty`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCachedDataPathProperty::m_Cache](#m_cache)|`CMemFile`objeto no qual os dados em cache.|  
  
## <a name="remarks"></a>Comentários  
 Um arquivo de memória é armazenado na RAM, e não no disco e é útil para transferências rápida temporárias.  
  
 Juntamente com **CAysncMonikerFile** e `CDataPathProperty`, `CCachedDataPathProperty` fornece a funcionalidade para o uso de monikers assíncronos em controles OLE. Com `CCachedDataPathProperty` objetos, é possível transferir dados de forma assíncrona de uma fonte de arquivo ou URL e armazená-lo em um arquivo de memória por meio de `m_Cache` variável pública. Todos os dados são armazenados no arquivo de memória e não é necessário substituir [OnDataAvailable](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable) , a menos que você deseja inspecionar para notificações e responder. Por exemplo, se você transferir uma grande. Substituir arquivo GIF e desejar notificar seu controle que mais dados são recebidos e ele deve ser redesenhado, `OnDataAvailable` para fazer a notificação.  
  
 A classe `CCachedDataPathProperty` é derivado de `CDataPathProperty`.  
  
 Para obter mais informações sobre como usar controles ActiveX e monikers assíncronos em aplicativos da Internet, consulte os seguintes tópicos:  
  
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
 **Cabeçalho:** afxctl.h  
  
##  <a name="ccacheddatapathproperty"></a>CCachedDataPathProperty::CCachedDataPathProperty  
 Constrói um objeto `CCachedDataPathProperty`.  
  
```  
CCachedDataPathProperty(COleControl* pControl = NULL);

 
CCachedDataPathProperty(
    LPCTSTR lpszPath,  
    COleControl* pControl = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pControl`  
 Um ponteiro para o objeto de controle ActiveX a ser associada a essa `CCachedDataPathProperty` objeto.  
  
 `lpszPath`  
 O caminho, que pode ser absoluta ou relativa, usado para criar um moniker assíncrona que faz referência a localização absoluta real da propriedade. `CCachedDataPathProperty`usa URLs, não os nomes de arquivo. Se você quiser um `CCachedDataPathProperty` de objeto para um arquivo, preceda file:// para o caminho.  
  
### <a name="remarks"></a>Comentários  
 O `COleControl` objeto apontado por `pControl` é usado pelo [abrir](../../mfc/reference/cdatapathproperty-class.md#open) e recuperada por classes derivadas. Se `pControl` é **nulo**, o controle usado com **abrir** deve ser definida com [SetControl](../../mfc/reference/cdatapathproperty-class.md#setcontrol). Se `lpszPath` é **nulo**, você pode passar no caminho por meio de **abrir** ou defini-lo com [SetPath](../../mfc/reference/cdatapathproperty-class.md#setpath).  
  
##  <a name="m_cache"></a>CCachedDataPathProperty::m_Cache  
 Contém o nome da classe do arquivo de memória em que dados são armazenados em cache.  
  
```  
CMemFile m_Cache;  
```  
  
### <a name="remarks"></a>Comentários  
 Um arquivo de memória é armazenado na RAM, e não no disco.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)


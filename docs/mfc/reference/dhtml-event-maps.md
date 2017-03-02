---
title: Mapas de evento DHTML | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.macros.shared
dev_langs:
- C++
helpviewer_keywords:
- event map macros
- DHTML, event map macros
- macros, DHTML event map
- DHTML events, event map
- DHTML events
ms.assetid: 9a2c8ae7-7216-4a5e-bc60-6b98695be0c6
caps.latest.revision: 14
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
ms.openlocfilehash: 8be59b52e06241651a2f605ab949efffd0e010d3
ms.lasthandoff: 02/25/2017

---
# <a name="dhtml-event-maps"></a>Mapas de evento DHTML
As macros a seguir podem ser usadas para manipular eventos DHTML.  
  
## <a name="dhtml-event-map-macros"></a>Macros de mapa de evento DHTML  
 As macros a seguir podem ser usadas para manipular eventos DHTML na [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)-classes derivadas.  
  
|||  
|-|-|  
|[BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map)|Marca o início do mapa de evento DHTML.|  
|[BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline)|Marca o início do mapa de evento DHTML.|  
|[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map)|Declara o mapa de evento DHTML.|  
|[DHTML_EVENT](#dhtml_event)|Usado para manipular um evento no nível de documento para um único elemento HTML.|  
|[DHTML_EVENT_AXCONTROL](#dhtml_event_axcontrol)|Usado para manipular um evento disparado por um controle ActiveX.|  
|[DHTML_EVENT_CLASS](#dhtml_event_class)|Usado para manipular um evento no nível do documento para todos os elementos HTML com uma classe CSS específica.|  
|[DHTML_EVENT_ELEMENT](#dhtml_event_element)|Usado para manipular um evento no nível do elemento.|  
|[DHTML_EVENT_ONAFTERUPDATE](#dhtml_event_onafterupdate)|Usado para tratar o **onafterupdate** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONBEFOREUPDATE](#dhtml_event_onbeforeupdate)|Usado para tratar o **onbeforeupdate** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONBLUR](#dhtml_event_onblur)|Usado para tratar o **onblur** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONCHANGE](#dhtml_event_onchange)|Usado para tratar o `onchange` evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONCLICK](#dhtml_event_onclick)|Usado para tratar o **onclick** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONDATAAVAILABLE](#dhtml_event_ondataavailable)|Usado para tratar o **ondataavailable** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONDATASETCHANGED](#dhtml_event_ondatasetchanged)|Usado para tratar o **ondatasetchanged** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONDATASETCOMPLETE](#dhtml_event_ondatasetcomplete)|Usado para tratar o **ondatasetcomplete** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONDBLCLICK](#dhtml_event_ondblclick)|Usado para tratar o **ondblclick** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONDRAGSTART](#dhtml_event_ondragstart)|Usado para tratar o **ondragstart** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONERRORUPDATE](#dhtml_event_onerrorupdate)|Usado para tratar o **onerrorupdate** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONFILTERCHANGE](#dhtml_event_onfilterchange)|Usado para tratar o **onfilterchange** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONFOCUS](#dhtml_event_onfocus)|Usado para tratar o **onfocus** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONHELP](#dhtml_event_onhelp)|Usado para tratar o `onhelp` evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONKEYDOWN](#dhtml_event_onkeydown)|Usado para tratar o **onkeydown** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONKEYPRESS](#dhtml_event_onkeypress)|Usado para tratar o **onkeypress** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONKEYUP](#dhtml_event_onkeyup)|Usado para tratar o **onkeyup** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONMOUSEDOWN](#dhtml_event_onmousedown)|Usado para tratar o **onmousedown** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONMOUSEMOVE](#dhtml_event_onmousemove)|Usado para tratar o `onmousemove` evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONMOUSEOUT](#dhtml_event_onmouseout)|Usado para tratar o **onmouseout** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONMOUSEOVER](#dhtml_event_onmouseover)|Usado para tratar o **onmouseover** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONMOUSEUP](#dhtml_event_onmouseup)|Usado para tratar o **onmouseup** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONRESIZE](#dhtml_event_onresize)|Usado para tratar o **onresize** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONROWENTER](#dhtml_event_onrowenter)|Usado para tratar o **onrowenter** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONROWEXIT](#dhtml_event_onrowexit)|Usado para tratar o **onrowexit** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_ONSELECTSTART](#dhtml_event_onselectstart)|Usado para tratar o **onselectstart** evento a partir de um elemento HTML.|  
|[DHTML_EVENT_TAG](#dhtml_event_tag)|Usado para manipular um evento no nível do documento para todos os elementos com uma determinada marca HTML.|  
|[END_DHTML_EVENT_MAP](#end_dhtml_event_map)|Marca o fim do mapa de evento DHTML.|  
  
## <a name="url-event-map-macros"></a>Macros de mapa de evento de URL  
 As macros a seguir podem ser usadas para manipular eventos DHTML na [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md)-classes derivadas.  
  
|||  
|-|-|  
|[BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map)|Marca o início do mapa de evento DHTML e URL de várias páginas.|  
|[BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map)|Marca o início de um mapa de evento DHTML incorporado.|  
|[BEGIN_URL_ENTRIES](#begin_url_entries)|Marca o início de um mapa de entrada do evento de URL.|  
|[DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map)|Declara o mapa de evento DHTML e URL de várias páginas.|  
|[END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map)|Marca o fim do mapa de evento DHTML e URL de várias páginas.|  
|[END_EMBED_DHTML_EVENT_MAP](#end_embed_dhtml_event_map)|Marca o fim de um mapa de evento DHTML incorporado.|  
|[END_URL_ENTRIES](#end_url_entries)|Marca o fim de um mapa de entrada do evento de URL.|  
|[URL_EVENT_ENTRY](#url_event_entry)|Mapeia um recurso de URL ou HTML para uma página em uma caixa de diálogo com várias páginas.|  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namebegindhtmleventmapa--begindhtmleventmap"></a><a name="begin_dhtml_event_map"></a>BEGIN_DHTML_EVENT_MAP  
 Marca o início do mapa de evento DHTML, quando colocado no arquivo de origem para a classe identificada pelo `className`.  
  
```   
BEGIN_DHTML_EVENT_MAP(className)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de evento DHTML. Essa classe deve derivar diretamente ou indiretamente de [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e incluem o [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) macro dentro de sua definição de classe.  
  
### <a name="remarks"></a>Comentários  
 Adicionar um mapa de evento DHTML à sua classe para fornecer informações para **CDHtmlDialog** que pode ser usado para rotear os eventos disparados por elementos HTML ou controles ActiveX em uma página da web para as funções de manipulador em sua classe.  
  
 Local de `BEGIN_DHTML_EVENT_MAP` seguido de macro no arquivo de implementação (. cpp) da classe `DHTML_EVENT` macros para os eventos de classe é manipular (por exemplo, `DHTML_EVENT_ONMOUSEOVER` para eventos de mouse). Use o [END_DHTML_EVENT_MAP](#end_dhtml_event_map) macro para marcar o fim do mapa de evento. Essas macros implementam a função a seguir:  
  
 `virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namebegindhtmleventmapinlinea--begindhtmleventmapinline"></a><a name="begin_dhtml_event_map_inline"></a>BEGIN_DHTML_EVENT_MAP_INLINE  
 Marca o início do mapa na definição da classe de evento DHTML `className`.  
  
```   
BEGIN_DHTML_EVENT_MAP_INLINE(className)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de evento DHTML. Essa classe deve derivar diretamente ou indiretamente de [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e incluem o [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) macro dentro de sua definição de classe.  
  
### <a name="remarks"></a>Comentários  
 Adicionar um mapa de evento DHTML à sua classe para fornecer informações para **CDHtmlDialog** que pode ser usado para rotear os eventos disparados por elementos HTML ou controles ActiveX em uma página da web para as funções de manipulador em sua classe.  
  
 Local de `BEGIN_DHTML_EVENT_MAP` seguido de macro no arquivo de definição (. h) da classe `DHTML_EVENT` macros para os eventos de classe é manipular (por exemplo, `DHTML_EVENT_ONMOUSEOVER` para eventos de mouse). Use o [END_DHTML_EVENT_MAP_INLINE](http://msdn.microsoft.com/library/0cfec092-20ee-49f3-bc38-56d6a5572db2) macro para marcar o fim do mapa de evento. Essas macros implementam a função a seguir:  
  
 `virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  

  
##  <a name="a-namedeclaredhtmleventmapa--declaredhtmleventmap"></a><a name="declare_dhtml_event_map"></a>DECLARE_DHTML_EVENT_MAP  
 Declara um mapa de evento DHTML em uma definição de classe.  
  
```   
DECLARE_DHTML_EVENT_MAP()   
```  
  
### <a name="remarks"></a>Comentários  
 Essa macro deve ser usada na definição de [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)-classes derivadas.  
  
 Use [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map) ou [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline) para implementar o mapa.  
  
 [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) declara a função a seguir:  
  
 `virtual const DHtmlEventMapEntry* GetDHtmlEventMap( );`  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventa--dhtmlevent"></a><a name="dhtml_event"></a>DHTML_EVENT  
 Manipula (no nível do documento) um evento identificado por `dispid` originada pelo elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT(dispid, elemName,  memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 DISPID do evento a ser manipulada.  
  
 `elemName`  
 Um `LPCWSTR` contendo a ID do elemento HTML fornecimento do evento, ou **nulo** para manipular eventos de documento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventaxcontrola--dhtmleventaxcontrol"></a><a name="dhtml_event_axcontrol"></a>DHTML_EVENT_AXCONTROL  
 Manipula o evento identificado por `dispid` disparado pelo controle ActiveX identificado por `controlName`.  
  
```   
DHTML_EVENT_AXCONTROL(dispid, controlName,  memberFxn)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição do evento a ser manipulada.  
  
 `controlName`  
 Um `LPCWSTR` contém a ID de HTML do controle disparar o evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventclassa--dhtmleventclass"></a><a name="dhtml_event_class"></a>DHTML_EVENT_CLASS  
 Manipula (no nível do documento) um evento identificado por `dispid` originadas por qualquer elemento HTML com a classe CSS identificada por `elemName`.  
  
```   
DHTML_EVENT_CLASS(dispid, elemName,  memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição do evento a ser manipulada.  
  
 `elemName`  
 Um `LPCWSTR` contém a classe CSS dos elementos HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventelementa--dhtmleventelement"></a><a name="dhtml_event_element"></a>DHTML_EVENT_ELEMENT  
 Manipula (o elemento identificado pelo `elemName`) um evento identificado por `dispid`.  
  
```   
DHTML_EVENT_ELEMENT(dispid, elemName,  memberFxn) 
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição do evento a ser manipulada.  
  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
 Se essa macro é usada para manipular eventos nonbubbling, a origem do evento será o elemento identificado pelo `elemName`.  
  
 Se essa macro é usada para tratar eventos, o elemento identificado pelo `elemName` não pode ser a origem do evento (a origem pode ser qualquer elemento contido por `elemName`).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonafterupdatea--dhtmleventonafterupdate"></a><a name="dhtml_event_onafterupdate"></a>DHTML_EVENT_ONAFTERUPDATE  
 Manipula (no nível do documento) do **onafterupdate** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONAFTERUPDATE(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonbeforeupdatea--dhtmleventonbeforeupdate"></a><a name="dhtml_event_onbeforeupdate"></a>DHTML_EVENT_ONBEFOREUPDATE  
 Manipula (no nível do documento) do **onbeforeupdate** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONBEFOREUPDATE(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonblura--dhtmleventonblur"></a><a name="dhtml_event_onblur"></a>DHTML_EVENT_ONBLUR  
 Manipula (no nível do elemento) a **onblur** eventos. Esse é um evento nonbubbling.  
  
```   
DHTML_EVENT_ONBLUR(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonchangea--dhtmleventonchange"></a><a name="dhtml_event_onchange"></a>DHTML_EVENT_ONCHANGE  
 Manipula (no nível do elemento) o `onchange` evento. Esse é um evento nonbubbling.  
  
```   
DHTML_EVENT_ONCHANGE(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonclicka--dhtmleventonclick"></a><a name="dhtml_event_onclick"></a>DHTML_EVENT_ONCLICK  
 Manipula (no nível do documento) do **onclick** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONCLICK(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventondataavailablea--dhtmleventondataavailable"></a><a name="dhtml_event_ondataavailable"></a>DHTML_EVENT_ONDATAAVAILABLE  
 Manipula (no nível do documento) do **ondataavailable** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONDATAAVAILABLE(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventondatasetchangeda--dhtmleventondatasetchanged"></a><a name="dhtml_event_ondatasetchanged"></a>DHTML_EVENT_ONDATASETCHANGED  
 Manipula (no nível do documento) do **ondatasetchanged** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONDATASETCHANGED(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventondatasetcompletea--dhtmleventondatasetcomplete"></a><a name="dhtml_event_ondatasetcomplete"></a>DHTML_EVENT_ONDATASETCOMPLETE  
 Manipula (no nível do documento) do **ondatasetcomplete** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONDATASETCOMPLETE(elemName, memberFxn) 
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventondblclicka--dhtmleventondblclick"></a><a name="dhtml_event_ondblclick"></a>DHTML_EVENT_ONDBLCLICK  
 Manipula (no nível do documento) do **ondblclick** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONDBLCLICK(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventondragstarta--dhtmleventondragstart"></a><a name="dhtml_event_ondragstart"></a>DHTML_EVENT_ONDRAGSTART  
 Manipula (no nível do documento) do **ondragstart** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONDRAGSTART(elemName, memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonerrorupdatea--dhtmleventonerrorupdate"></a><a name="dhtml_event_onerrorupdate"></a>DHTML_EVENT_ONERRORUPDATE  
 Manipula (no nível do documento) do **onerrorupdate** evento foi originado no elemento HTML identificado por `elemName`.  
  
```   
DHTML_EVENT_ONERRORUPDATE(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonfilterchangea--dhtmleventonfilterchange"></a><a name="dhtml_event_onfilterchange"></a>DHTML_EVENT_ONFILTERCHANGE  
 Manipula (no nível do documento) do **onfilterchange** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONFILTERCHANGE(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonfocusa--dhtmleventonfocus"></a><a name="dhtml_event_onfocus"></a>DHTML_EVENT_ONFOCUS  
 Manipula (no nível do elemento) a **onfocus** eventos. Esse é um evento nonbubbling.  
  
```  
 
DHTML_EVENT_ONFOCUS(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonhelpa--dhtmleventonhelp"></a><a name="dhtml_event_onhelp"></a>DHTML_EVENT_ONHELP  
 Manipula (no nível do documento) do `onhelp` evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONHELP(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonkeydowna--dhtmleventonkeydown"></a><a name="dhtml_event_onkeydown"></a>DHTML_EVENT_ONKEYDOWN  
 Manipula (no nível do documento) do **onkeydown** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONKEYDOWN(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonkeypressa--dhtmleventonkeypress"></a><a name="dhtml_event_onkeypress"></a>DHTML_EVENT_ONKEYPRESS  
 Manipula (no nível do documento) do **onkeypress** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONKEYPRESS(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonkeyupa--dhtmleventonkeyup"></a><a name="dhtml_event_onkeyup"></a>DHTML_EVENT_ONKEYUP  
 Manipula (no nível do documento) do **onkeyup** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONKEYUP(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonmousedowna--dhtmleventonmousedown"></a><a name="dhtml_event_onmousedown"></a>DHTML_EVENT_ONMOUSEDOWN  
 Manipula (no nível do documento) do **onmousedown** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONMOUSEDOWN(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonmousemovea--dhtmleventonmousemove"></a><a name="dhtml_event_onmousemove"></a>DHTML_EVENT_ONMOUSEMOVE  
 Manipula (no nível do documento) do `onmousemove` evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONMOUSEMOVE(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonmouseouta--dhtmleventonmouseout"></a><a name="dhtml_event_onmouseout"></a>DHTML_EVENT_ONMOUSEOUT  
 Manipula (no nível do documento) do **onmouseout** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONMOUSEOUT(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonmouseovera--dhtmleventonmouseover"></a><a name="dhtml_event_onmouseover"></a>DHTML_EVENT_ONMOUSEOVER  
 Manipula (no nível do documento) do **onmouseover** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONMOUSEOVER(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonmouseupa--dhtmleventonmouseup"></a><a name="dhtml_event_onmouseup"></a>DHTML_EVENT_ONMOUSEUP  
 Manipula (no nível do documento) do **onmouseup** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONMOUSEUP(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonresizea--dhtmleventonresize"></a><a name="dhtml_event_onresize"></a>DHTML_EVENT_ONRESIZE  
 Manipula (no nível do elemento) a **onresize** eventos. Esse é um evento nonbubbling.  
  
```  
 
DHTML_EVENT_ONRESIZE(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonrowentera--dhtmleventonrowenter"></a><a name="dhtml_event_onrowenter"></a>DHTML_EVENT_ONROWENTER  
 Manipula (no nível do documento) do **onrowenter** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONROWENTER(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonrowexita--dhtmleventonrowexit"></a><a name="dhtml_event_onrowexit"></a>DHTML_EVENT_ONROWEXIT  
 Manipula (no nível do documento) do **onrowexit** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONROWEXIT(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventonselectstarta--dhtmleventonselectstart"></a><a name="dhtml_event_onselectstart"></a>DHTML_EVENT_ONSELECTSTART  
 Manipula (no nível do documento) do **onselectstart** evento foi originado no elemento HTML identificado por `elemName`.  
  
```  
 
DHTML_EVENT_ONSELECTSTART(elemName, memberFxn)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `elemName`  
 Um `LPCWSTR` contém a ID do elemento HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedhtmleventtaga--dhtmleventtag"></a><a name="dhtml_event_tag"></a>DHTML_EVENT_TAG  
 Manipula (no nível do documento) um evento identificado por `dispid` originadas por qualquer elemento HTML com a marca HTML identificada por `elemName`.  
  
```   
DHTML_EVENT_TAG(dispid, elemName,  memberFxn)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição do evento a ser manipulada.  
  
 `elemName`  
 A marca HTML dos elementos HTML fornecimento do evento.  
  
 `memberFxn`  
 A função de manipulador para o evento.  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-nameenddhtmleventmapa--enddhtmleventmap"></a><a name="end_dhtml_event_map"></a>END_DHTML_EVENT_MAP  
 Marca o fim do mapa de evento DHTML.  
  
```   
END_DHTML_EVENT_MAP()   
```  
  
### <a name="remarks"></a>Comentários  
 Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namebegindhtmlurleventmapa--begindhtmlurleventmap"></a><a name="begin_dhtml_url_event_map"></a>BEGIN_DHTML_URL_EVENT_MAP  
 Inicia a definição de um mapa de evento DHTML e URL em uma caixa de diálogo com várias páginas.  
  
```  
BEGIN_DHTML_URL_EVENT_MAP()  
 
```  
  
### <a name="remarks"></a>Comentários  
 Colocar `BEGIN_DHTML_URL_EVENT_MAP` no arquivo de implementação de sua [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md)-classe derivada. Siga-o com [incorporado mapas de evento DHTML](#begin_embed_dhtml_event_map) e [entradas de URL](#begin_url_entries)e feche-o com [END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map). Incluir o [DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map) macro dentro da definição de classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#196;](../../mfc/codesnippet/cpp/dhtml-event-maps_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namebeginembeddhtmleventmapa--beginembeddhtmleventmap"></a><a name="begin_embed_dhtml_event_map"></a>BEGIN_EMBED_DHTML_EVENT_MAP  
 Inicia a definição de um mapa de evento DHTML inseridos em uma caixa de diálogo com várias páginas.  
  
```  
BEGIN_EMBED_DHTML_EVENT_MAP(className, mapName)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de evento. Essa classe deve derivar diretamente ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de evento DHTML inseridos deve estar dentro de uma [mapa de evento DHTML e URL](#begin_dhtml_url_event_map)).  
  
 *mapName*  
 Especifica a página cujo evento mapear isso. Isso corresponde *mapName* no [URL_EVENT_ENTRY](#url_event_entry) macro realmente definição do recurso de URL ou HTML.  
  
### <a name="remarks"></a>Comentários  
 Como uma caixa de diálogo DHTML Multipágina consiste em várias páginas HTML, cada um deles pode gerar eventos DHTML, mapas de evento inseridos são usados para mapear os eventos a manipuladores em uma base por página.  
  
 Mapas de evento incorporado dentro de um mapa de evento DHTML e URL consistem em uma `BEGIN_EMBED_DHTML_EVENT_MAP` seguido de macro [DHTML_EVENT](dhtml-event-maps.md#dhtml_event) macros e um [END_EMBED_DHTML_EVENT_MAP](dhtml-event-maps.md#end_embed_dhtml_event_map) macro.  
  
 Cada mapa de evento incorporado requer um correspondente [entrada de evento de URL](#url_event_entry) para mapear *mapName* (especificado em `BEGIN_EMBED_DHTML_EVENT_MAP`) para um recurso de URL ou HTML.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namebeginurlentriesa--beginurlentries"></a><a name="begin_url_entries"></a>BEGIN_URL_ENTRIES  
 Inicia a definição de um mapa de entrada do evento de URL em uma caixa de diálogo com várias páginas.  
  
```  
BEGIN_URL_ENTRIES(className)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de entrada de evento de URL. Essa classe deve derivar diretamente ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Mapa de entrada de evento a URL deve estar dentro de uma [mapa de evento DHTML e URL](#begin_dhtml_url_event_map)).  
  
### <a name="remarks"></a>Comentários  
 Como uma caixa de diálogo DHTML Multipágina consiste em várias páginas HTML, entradas de URL de eventos são usadas para mapear URLs ou HTML recursos correspondente [incorporado mapas de evento DHTML](#begin_embed_dhtml_event_map). Colocar `URL_EVENT_ENTRY` macros entre `BEGIN_URL_ENTRIES` e [END_URL_ENTRIES](#end_url_entries) macros.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-namedeclaredhtmlurleventmapa--declaredhtmlurleventmap"></a><a name="declare_dhtml_url_event_map"></a>DECLARE_DHTML_URL_EVENT_MAP  
 Declara um mapa de evento DHTML e URL em uma definição de classe.  
  
```  
DECLARE_DHTML_URL_EVENT_MAP()  
 
```  
  
### <a name="remarks"></a>Comentários  
 Essa macro deve ser usada na definição de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md)-classes derivadas.  
  
 Um mapa de evento DHTML e URL contém [incorporado mapas de evento DHTML](#begin_embed_dhtml_event_map) e [entradas de eventos de URL](#begin_url_entries) para mapear eventos DHTML para manipuladores em uma base por página. Use [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) para implementar o mapa.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-nameenddhtmlurleventmapa--enddhtmlurleventmap"></a><a name="end_dhtml_url_event_map"></a>END_DHTML_URL_EVENT_MAP  
 Marca o fim de um mapa de evento DHTML e URL.  
  
```  
END_DHTML_URL_EVENT_MAP(className)  
 
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de evento. Essa classe deve derivar diretamente ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Isso deve corresponder `className` no correspondente [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) macro.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-nameendembeddhtmleventmapa--endembeddhtmleventmap"></a><a name="end_embed_dhtml_event_map"></a>END_EMBED_DHTML_EVENT_MAP  
 Marca o fim de um mapa de evento DHTML incorporado.  
  
```  
END_EMBED_DHTML_EVENT_MAP()  
 
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-nameendurlentriesa--endurlentries"></a><a name="end_url_entries"></a>END_URL_ENTRIES  
 Marca o fim de um mapa de entrada do evento de URL.  
  
```  
END_URL_ENTRIES()  
 
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
  
##  <a name="a-nameurlevententrya--urlevententry"></a><a name="url_event_entry"></a>URL_EVENT_ENTRY  
 Mapeia um recurso de URL ou HTML para uma página em uma caixa de diálogo com várias páginas.  
  
```  
URL_EVENT_ENTRY(className, url,  mapName)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de entrada de evento de URL. Essa classe deve derivar diretamente ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Mapa de entrada de evento a URL deve estar dentro de uma [mapa de evento DHTML e URL](#begin_dhtml_url_event_map)).  
  
 *URL*  
 O recurso de URL ou HTML para a página.  
  
 *mapName*  
 Especifica a página cuja URL é *url*. Isso corresponde *mapName* no [BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map) macro que mapeia eventos desta página.  
  
### <a name="remarks"></a>Comentários  
 Se a página é um recurso HTML, *url* deve ser a representação de cadeia de caracteres do número de identificação do recurso (ou seja, "123", não 123 ou ID_HTMLRES1).  
  
 O identificador de página, *mapName*, é um símbolo arbitrário usado para vincular incorporado mapas de evento DHTML para mapas de entrada do evento de URL. Ele é limitado em escopo para o mapa de evento DHTML e URL.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).  

  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdhtml.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)


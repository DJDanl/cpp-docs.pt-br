---
title: Mapas de evento DHTML
ms.date: 11/04/2016
f1_keywords:
- vc.macros.shared
helpviewer_keywords:
- event map macros [MFC]
- DHTML [MFC], event map macros
- macros [MFC], DHTML event map
- DHTML events [MFC], event map
- DHTML events [MFC]
ms.assetid: 9a2c8ae7-7216-4a5e-bc60-6b98695be0c6
ms.openlocfilehash: 5ae37acd3e0b0c2636e6a3e985490a2feab8fa34
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300538"
---
# <a name="dhtml-event-maps"></a>Mapas de evento DHTML

As macros a seguir podem ser usadas para manipular eventos DHTML.

## <a name="dhtml-event-map-macros"></a>Macros de mapa de evento DHTML

As macros a seguir podem ser usadas para manipular eventos DHTML na [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)-as classes derivadas.

|||
|-|-|
|[BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map)|Marca o início do mapa de evento DHTML.|
|[BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline)|Marca o início do mapa de evento DHTML.|
|[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map)|Declara o mapa de evento DHTML.|
|[DHTML_EVENT](#dhtml_event)|Usado para manipular um evento no nível de documento para um único elemento HTML.|
|[DHTML_EVENT_AXCONTROL](#dhtml_event_axcontrol)|Usado para manipular um evento acionado por um controle ActiveX.|
|[DHTML_EVENT_CLASS](#dhtml_event_class)|Usado para manipular um evento no nível do documento para todos os elementos HTML com uma determinada classe CSS.|
|[DHTML_EVENT_ELEMENT](#dhtml_event_element)|Usado para manipular um evento no nível de elemento.|
|[DHTML_EVENT_ONAFTERUPDATE](#dhtml_event_onafterupdate)|Usado para tratar o `onafterupdate` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONBEFOREUPDATE](#dhtml_event_onbeforeupdate)|Usado para tratar o `onbeforeupdate` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONBLUR](#dhtml_event_onblur)|Usado para tratar o `onblur` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONCHANGE](#dhtml_event_onchange)|Usado para tratar o `onchange` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONCLICK](#dhtml_event_onclick)|Usado para tratar o `onclick` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATAAVAILABLE](#dhtml_event_ondataavailable)|Usado para tratar o `ondataavailable` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATASETCHANGED](#dhtml_event_ondatasetchanged)|Usado para tratar o `ondatasetchanged` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATASETCOMPLETE](#dhtml_event_ondatasetcomplete)|Usado para tratar o `ondatasetcomplete` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDBLCLICK](#dhtml_event_ondblclick)|Usado para tratar o `ondblclick` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDRAGSTART](#dhtml_event_ondragstart)|Usado para tratar o `ondragstart` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONERRORUPDATE](#dhtml_event_onerrorupdate)|Usado para tratar o `onerrorupdate` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONFILTERCHANGE](#dhtml_event_onfilterchange)|Usado para tratar o `onfilterchange` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONFOCUS](#dhtml_event_onfocus)|Usado para tratar o `onfocus` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONHELP](#dhtml_event_onhelp)|Usado para tratar o `onhelp` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYDOWN](#dhtml_event_onkeydown)|Usado para tratar o `onkeydown` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYPRESS](#dhtml_event_onkeypress)|Usado para tratar o `onkeypress` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYUP](#dhtml_event_onkeyup)|Usado para tratar o `onkeyup` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEDOWN](#dhtml_event_onmousedown)|Usado para tratar o `onmousedown` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEMOVE](#dhtml_event_onmousemove)|Usado para tratar o `onmousemove` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEOUT](#dhtml_event_onmouseout)|Usado para tratar o `onmouseout` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEOVER](#dhtml_event_onmouseover)|Usado para tratar o `onmouseover` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEUP](#dhtml_event_onmouseup)|Usado para tratar o `onmouseup` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONRESIZE](#dhtml_event_onresize)|Usado para tratar o `onresize` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONROWENTER](#dhtml_event_onrowenter)|Usado para tratar o `onrowenter` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONROWEXIT](#dhtml_event_onrowexit)|Usado para tratar o `onrowexit` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONSELECTSTART](#dhtml_event_onselectstart)|Usado para tratar o `onselectstart` evento a partir de um elemento HTML.|
|[DHTML_EVENT_TAG](#dhtml_event_tag)|Usado para manipular um evento no nível do documento para todos os elementos com uma determinada marcação HTML.|
|[END_DHTML_EVENT_MAP](#end_dhtml_event_map)|Marca o fim do mapa de evento DHTML.|
|[END_DHTML_EVENT_MAP_INLINE](#end_dhtml_event_map_inline)|Marca o fim do mapa de evento DHTML. |

## <a name="url-event-map-macros"></a>Macros de mapa de evento de URL

As macros a seguir podem ser usadas para manipular eventos DHTML na [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md)-as classes derivadas.

|||
|-|-|
|[BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map)|Marca o início do mapa de evento DHTML e URL de várias páginas.|
|[BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map)|Marca o início de um mapa de evento DHTML incorporado.|
|[BEGIN_URL_ENTRIES](#begin_url_entries)|Marca o início de um mapa de entrada de evento de URL.|
|[DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map)|Declara o mapa de evento DHTML e URL de várias páginas.|
|[END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map)|Marca o fim do mapa de evento DHTML e URL de várias páginas.|
|[END_EMBED_DHTML_EVENT_MAP](#end_embed_dhtml_event_map)|Marca o fim de um mapa de evento DHTML inserido.|
|[END_URL_ENTRIES](#end_url_entries)|Marca o final de um mapa de entrada de evento de URL.|
|[URL_EVENT_ENTRY](#url_event_entry)|Mapeia um recurso de URL ou HTML para uma página em uma caixa de diálogo várias páginas.|

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="begin_dhtml_event_map"></a>  BEGIN_DHTML_EVENT_MAP

Marca o início do mapa de evento DHTML, quando colocado no arquivo de origem para a classe identificada pelo `className`.

```
BEGIN_DHTML_EVENT_MAP(className)
```

### <a name="parameters"></a>Parâmetros

*className*<br/>
O nome da classe que contém o mapa de evento DHTML. Essa classe deve derivam direta ou indiretamente [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e inclua as [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) macro dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicionar um mapa de evento DHTML à sua classe para fornecer informações para `CDHtmlDialog` que pode ser usado para rotear os eventos acionados por elementos HTML ou controles ActiveX em uma página da web para funções de manipulador em sua classe.

Coloque a macro BEGIN_DHTML_EVENT_MAP no arquivo de implementação (. cpp) da classe seguido de macros DHTML_EVENT para os eventos que é lidar com a classe (por exemplo, DHTML_EVENT_ONMOUSEOVER mouseover eventos). Use o [END_DHTML_EVENT_MAP](#end_dhtml_event_map) macro para marcar o final do mapa de evento. Essas macros implementam a função a seguir:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="begin_dhtml_event_map_inline"></a>  BEGIN_DHTML_EVENT_MAP_INLINE

Marca o início do mapa dentro da definição de classe de evento DHTML *className*.

```
BEGIN_DHTML_EVENT_MAP_INLINE(className)
```

### <a name="parameters"></a>Parâmetros

*className*<br/>
O nome da classe que contém o mapa de evento DHTML. Essa classe deve derivam direta ou indiretamente [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e inclua as [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) macro dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicionar um mapa de evento DHTML à sua classe para fornecer informações para `CDHtmlDialog` que pode ser usado para rotear os eventos acionados por elementos HTML ou controles ActiveX em uma página da web para funções de manipulador em sua classe.

Coloque a macro BEGIN_DHTML_EVENT_MAP no arquivo de definição (. h) da classe seguido de macros DHTML_EVENT para os eventos que é lidar com a classe (por exemplo, DHTML_EVENT_ONMOUSEOVER mouseover eventos). Use o [END_DHTML_EVENT_MAP_INLINE](#end_dhtml_event_map_inline) macro para marcar o final do mapa de evento. Essas macros implementam a função a seguir:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="declare_dhtml_event_map"></a>  DECLARE_DHTML_EVENT_MAP

Declara um mapa de evento DHTML em uma definição de classe.

```
DECLARE_DHTML_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Essa macro deve ser usada na definição de [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md)-as classes derivadas.

Use [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map) ou [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline) para implementar o mapa.

[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) declara a função a seguir:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap( );`

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event"></a>  DHTML_EVENT

Lida com (no nível do documento), um evento identificado por *dispid* originada pelo elemento HTML identificado pelo *elemName*.

```
DHTML_EVENT(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
O DISPID do evento a ser manipulado.

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento, ou nulo para manipular eventos de documento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_axcontrol"></a>  DHTML_EVENT_AXCONTROL

Manipula o evento identificado por *dispid* disparado pelo controle ActiveX identificado pelo *controlName*.

```
DHTML_EVENT_AXCONTROL(dispid, controlName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
A ID de expedição do evento a ser manipulado.

*controlName*<br/>
Um LPCWSTR que contém a ID HTML do controle disparar o evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_class"></a>  DHTML_EVENT_CLASS

Lida com (no nível do documento), um evento identificado por *dispid* originadas por qualquer elemento HTML com a classe CSS identificada pelo *elemName*.

```
DHTML_EVENT_CLASS(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
A ID de expedição do evento a ser manipulado.

*elemName*<br/>
Um LPCWSTR que contém a classe CSS de elementos HTML fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_element"></a>  DHTML_EVENT_ELEMENT

Manipula (o elemento identificado pelo *elemName*) um evento identificado pelo *dispid*.

```
DHTML_EVENT_ELEMENT(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
A ID de expedição do evento a ser manipulado.

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

Se essa macro é usada para manipular eventos nonbubbling, a origem do evento será o elemento identificado pelo *elemName*.

Se essa macro é usada para manipular eventos de propagação, o elemento identificado pelo *elemName* não pode ser a origem do evento (a origem pode ser qualquer elemento contido pelo *elemName*).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onafterupdate"></a>  DHTML_EVENT_ONAFTERUPDATE

Manipula (no nível do documento) a `onafterupdate` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONAFTERUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onbeforeupdate"></a>  DHTML_EVENT_ONBEFOREUPDATE

Manipula (no nível do documento) a `onbeforeupdate` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONBEFOREUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onblur"></a>  DHTML_EVENT_ONBLUR

Manipula (no nível de elemento) o `onblur` eventos. Este é um evento nonbubbling.

```
DHTML_EVENT_ONBLUR(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onchange"></a>  DHTML_EVENT_ONCHANGE

Manipula (no nível de elemento) o `onchange` eventos. Este é um evento nonbubbling.

```
DHTML_EVENT_ONCHANGE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onclick"></a>  DHTML_EVENT_ONCLICK

Manipula (no nível do documento) a `onclick` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONCLICK(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_ondataavailable"></a>  DHTML_EVENT_ONDATAAVAILABLE

Manipula (no nível do documento) a `ondataavailable` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONDATAAVAILABLE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_ondatasetchanged"></a>  DHTML_EVENT_ONDATASETCHANGED

Manipula (no nível do documento) a `ondatasetchanged` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONDATASETCHANGED(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_ondatasetcomplete"></a>  DHTML_EVENT_ONDATASETCOMPLETE

Manipula (no nível do documento) a `ondatasetcomplete` evento originada pelo elemento HTML identificado por `elemName`.

```
DHTML_EVENT_ONDATASETCOMPLETE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_ondblclick"></a>  DHTML_EVENT_ONDBLCLICK

Manipula (no nível do documento) a `ondblclick` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONDBLCLICK(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_ondragstart"></a>  DHTML_EVENT_ONDRAGSTART

Manipula (no nível do documento) a `ondragstart` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONDRAGSTART(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onerrorupdate"></a>  DHTML_EVENT_ONERRORUPDATE

Manipula (no nível do documento) a `onerrorupdate` evento originada pelo elemento HTML identificado por *elemName*.

```
DHTML_EVENT_ONERRORUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onfilterchange"></a>  DHTML_EVENT_ONFILTERCHANGE

Manipula (no nível do documento) a `onfilterchange` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONFILTERCHANGE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onfocus"></a>  DHTML_EVENT_ONFOCUS

Manipula (no nível de elemento) o `onfocus` eventos. Este é um evento nonbubbling.

```

DHTML_EVENT_ONFOCUS(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onhelp"></a>  DHTML_EVENT_ONHELP

Manipula (no nível do documento) a `onhelp` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONHELP(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onkeydown"></a>  DHTML_EVENT_ONKEYDOWN

Manipula (no nível do documento) a `onkeydown` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONKEYDOWN(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onkeypress"></a>  DHTML_EVENT_ONKEYPRESS

Manipula (no nível do documento) a `onkeypress` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONKEYPRESS(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onkeyup"></a>  DHTML_EVENT_ONKEYUP

Manipula (no nível do documento) a `onkeyup` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONKEYUP(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onmousedown"></a>  DHTML_EVENT_ONMOUSEDOWN

Manipula (no nível do documento) a `onmousedown` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONMOUSEDOWN(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onmousemove"></a>  DHTML_EVENT_ONMOUSEMOVE

Manipula (no nível do documento) a `onmousemove` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONMOUSEMOVE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onmouseout"></a>  DHTML_EVENT_ONMOUSEOUT

Manipula (no nível do documento) a `onmouseout` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONMOUSEOUT(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onmouseover"></a>  DHTML_EVENT_ONMOUSEOVER

Manipula (no nível do documento) a `onmouseover` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONMOUSEOVER(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onmouseup"></a>  DHTML_EVENT_ONMOUSEUP

Manipula (no nível do documento) a `onmouseup` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONMOUSEUP(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onresize"></a>  DHTML_EVENT_ONRESIZE

Manipula (no nível de elemento) o `onresize` eventos. Este é um evento nonbubbling.

```

DHTML_EVENT_ONRESIZE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onrowenter"></a>  DHTML_EVENT_ONROWENTER

Manipula (no nível do documento) a `onrowenter` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONROWENTER(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onrowexit"></a>  DHTML_EVENT_ONROWEXIT

Manipula (no nível do documento) a `onrowexit` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONROWEXIT(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_onselectstart"></a>  DHTML_EVENT_ONSELECTSTART

Manipula (no nível do documento) a `onselectstart` evento originada pelo elemento HTML identificado por *elemName*.

```

DHTML_EVENT_ONSELECTSTART(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*elemName*<br/>
Um LPCWSTR que contém a ID do elemento HTML de fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="dhtml_event_tag"></a>  DHTML_EVENT_TAG

Lida com (no nível do documento), um evento identificado por `dispid` originadas por qualquer elemento HTML com a marca HTML identificada por *elemName*.

```
DHTML_EVENT_TAG(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
A ID de expedição do evento a ser manipulado.

*elemName*<br/>
A marca HTML dos elementos HTML fornecimento do evento.

*memberFxn*<br/>
A função do manipulador para o evento.

### <a name="remarks"></a>Comentários

Usar essa macro para adicionar uma entrada para o [mapa de evento DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="end_dhtml_event_map"></a>  END_DHTML_EVENT_MAP

Marca o fim do mapa de evento DHTML.

```
END_DHTML_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="begin_dhtml_url_event_map"></a>  BEGIN_DHTML_URL_EVENT_MAP

Inicia a definição de um mapa de evento DHTML e a URL em uma caixa de diálogo várias páginas.

```
BEGIN_DHTML_URL_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Colocar BEGIN_DHTML_URL_EVENT_MAP no arquivo de implementação de sua [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md)-classe derivada. Siga-o com [inseridos mapas de evento DHTML](#begin_embed_dhtml_event_map) e [entradas de URL](#begin_url_entries)e, em seguida, feche-o com [END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map). Incluir o [DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map) macro dentro da definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#196](../../mfc/codesnippet/cpp/dhtml-event-maps_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="begin_embed_dhtml_event_map"></a>  BEGIN_EMBED_DHTML_EVENT_MAP

Inicia a definição de um mapa de evento DHTML inseridos em uma caixa de diálogo várias páginas.

```
BEGIN_EMBED_DHTML_EVENT_MAP(className, mapName)
```

### <a name="parameters"></a>Parâmetros

*className*<br/>
O nome da classe que contém o mapa de evento. Essa classe deve derivam direta ou indiretamente [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de evento DHTML inserido deve estar dentro de um [mapa de evento DHTML e URL](#begin_dhtml_url_event_map)).

*mapName*<br/>
Especifica a página cujo evento ser mapeado. Isso corresponde à *mapName* na [URL_EVENT_ENTRY](#url_event_entry) macro, na verdade, definindo o recurso de URL ou HTML.

### <a name="remarks"></a>Comentários

Como uma caixa de diálogo do DHTML Multipágina consiste em várias páginas HTML, cada um deles pode gerar eventos DHTML, mapas de evento inseridos são usados para mapear eventos a manipuladores em uma base por página.

Mapas de evento incorporado dentro de um mapa de evento DHTML e URL consistem em uma macro BEGIN_EMBED_DHTML_EVENT_MAP seguida [DHTML_EVENT](#dhtml_event) macros e uma [END_EMBED_DHTML_EVENT_MAP](#end_embed_dhtml_event_map) macro.

Cada mapa de evento embedded requer um correspondente [entrada de evento de URL](#url_event_entry) para mapear *mapName* (especificado no BEGIN_EMBED_DHTML_EVENT_MAP) a um recurso de URL ou HTML.

### <a name="example"></a>Exemplo

Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="begin_url_entries"></a>  BEGIN_URL_ENTRIES

Inicia a definição de um mapa de entrada de evento de URL em uma caixa de diálogo várias páginas.

```
BEGIN_URL_ENTRIES(className)
```

### <a name="parameters"></a>Parâmetros

*className*<br/>
O nome da classe que contém o mapa de entrada de evento de URL. Essa classe deve derivam direta ou indiretamente [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Mapa de entrada de evento a URL deve estar dentro de um [mapa de evento DHTML e URL](#begin_dhtml_url_event_map)).

### <a name="remarks"></a>Comentários

Como uma caixa de diálogo do DHTML Multipágina consiste em várias páginas HTML, entradas de evento de URL são usadas para mapear URLs ou HTML recursos correspondente [inseridos mapas de evento DHTML](#begin_embed_dhtml_event_map). Colocar as macros URL_EVENT_ENTRY entre BEGIN_URL_ENTRIES e [END_URL_ENTRIES](#end_url_entries) macros.

### <a name="example"></a>Exemplo

Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="declare_dhtml_url_event_map"></a>  DECLARE_DHTML_URL_EVENT_MAP

Declara um mapa de evento DHTML e a URL em uma definição de classe.

```
DECLARE_DHTML_URL_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Essa macro deve ser usada na definição de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md)-as classes derivadas.

Um mapa de evento DHTML e a URL contém [inseridos mapas de evento DHTML](#begin_embed_dhtml_event_map) e [entradas do evento URL](#begin_url_entries) para mapear eventos DHTML para manipuladores em uma base por página. Use [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) para implementar o mapa.

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="end_dhtml_url_event_map"></a>  END_DHTML_URL_EVENT_MAP

Marca o final de um mapa de evento DHTML e URL.

```
END_DHTML_URL_EVENT_MAP(className)
```

### <a name="parameters"></a>Parâmetros

*className*<br/>
O nome da classe que contém o mapa de evento. Essa classe deve derivam direta ou indiretamente [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Isso deve corresponder ao *className* nas correspondentes [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) macro.

### <a name="example"></a>Exemplo

Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="end_embed_dhtml_event_map"></a>  END_EMBED_DHTML_EVENT_MAP

Marca o fim de um mapa de evento DHTML inserido.

```
END_EMBED_DHTML_EVENT_MAP()
```

### <a name="example"></a>Exemplo

Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="end_url_entries"></a>  END_URL_ENTRIES

Marca o final de um mapa de entrada de evento de URL.

```
END_URL_ENTRIES()
```

### <a name="example"></a>Exemplo

Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="url_event_entry"></a>  URL_EVENT_ENTRY

Mapeia um recurso de URL ou HTML para uma página em uma caixa de diálogo várias páginas.

```
URL_EVENT_ENTRY(className, url,  mapName)
```

### <a name="parameters"></a>Parâmetros

*className*<br/>
O nome da classe que contém o mapa de entrada de evento de URL. Essa classe deve derivam direta ou indiretamente [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Mapa de entrada de evento a URL deve estar dentro de um [mapa de evento DHTML e URL](#begin_dhtml_url_event_map)).

*url*<br/>
O recurso de URL ou HTML da página.

*mapName*<br/>
Especifica a página cuja URL seja *url*. Isso corresponde à *mapName* na [BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map) macro que mapeia eventos a partir desta página.

### <a name="remarks"></a>Comentários

Se a página é um recurso HTML *url* deve ser a representação de cadeia de caracteres do número de ID do recurso (ou seja, "123", não 123 ou ID_HTMLRES1).

O identificador de página *mapName*, é um símbolo arbitrário usado para vincular incorporado mapas de evento DHTML para mapas de entrada de evento de URL. Ela é limitada em escopo para o mapa de evento DHTML e URL.

### <a name="example"></a>Exemplo

Consulte o exemplo na [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Header** afxdhtml.h

##  <a name="end_dhtml_event_map_inline"></a>END_DHTML_EVENT_MAP_INLINE

Marca o fim do mapa de evento DHTML.

### <a name="syntax"></a>Sintaxe

```
END_DHTML_EVENT_MAP_INLINE( )
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)

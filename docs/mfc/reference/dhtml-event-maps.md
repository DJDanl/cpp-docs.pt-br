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
ms.openlocfilehash: 099a08298357d99a3d09ed6fc1209d463f6a4526
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837418"
---
# <a name="dhtml-event-maps"></a>Mapas de evento DHTML

As macros a seguir podem ser usadas para manipular eventos DHTML.

## <a name="dhtml-event-map-macros"></a>Macros de mapa de eventos DHTML

As macros a seguir podem ser usadas para manipular eventos DHTML em classes derivadas de [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md).

|Nome|Descrição|
|-|-|
|[BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map)|Marca o início do mapa de eventos DHTML.|
|[BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline)|Marca o início do mapa de eventos DHTML.|
|[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map)|Declara o mapa de eventos DHTML.|
|[DHTML_EVENT](#dhtml_event)|Usado para lidar com um evento no nível de documento para um único elemento HTML.|
|[DHTML_EVENT_AXCONTROL](#dhtml_event_axcontrol)|Usado para manipular um evento disparado por um controle ActiveX.|
|[DHTML_EVENT_CLASS](#dhtml_event_class)|Usado para lidar com um evento no nível de documento para todos os elementos HTML com uma classe CSS específica.|
|[DHTML_EVENT_ELEMENT](#dhtml_event_element)|Usado para lidar com um evento no nível do elemento.|
|[DHTML_EVENT_ONAFTERUPDATE](#dhtml_event_onafterupdate)|Usado para manipular o `onafterupdate` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONBEFOREUPDATE](#dhtml_event_onbeforeupdate)|Usado para manipular o `onbeforeupdate` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONBLUR](#dhtml_event_onblur)|Usado para manipular o `onblur` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONCHANGE](#dhtml_event_onchange)|Usado para manipular o `onchange` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONCLICK](#dhtml_event_onclick)|Usado para manipular o `onclick` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATAAVAILABLE](#dhtml_event_ondataavailable)|Usado para manipular o `ondataavailable` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATASETCHANGED](#dhtml_event_ondatasetchanged)|Usado para manipular o `ondatasetchanged` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATASETCOMPLETE](#dhtml_event_ondatasetcomplete)|Usado para manipular o `ondatasetcomplete` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDBLCLICK](#dhtml_event_ondblclick)|Usado para manipular o `ondblclick` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDRAGSTART](#dhtml_event_ondragstart)|Usado para manipular o `ondragstart` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONERRORUPDATE](#dhtml_event_onerrorupdate)|Usado para manipular o `onerrorupdate` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONFILTERCHANGE](#dhtml_event_onfilterchange)|Usado para manipular o `onfilterchange` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONFOCUS](#dhtml_event_onfocus)|Usado para manipular o `onfocus` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONHELP](#dhtml_event_onhelp)|Usado para manipular o `onhelp` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYDOWN](#dhtml_event_onkeydown)|Usado para manipular o `onkeydown` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYPRESS](#dhtml_event_onkeypress)|Usado para manipular o `onkeypress` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYUP](#dhtml_event_onkeyup)|Usado para manipular o `onkeyup` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEDOWN](#dhtml_event_onmousedown)|Usado para manipular o `onmousedown` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEMOVE](#dhtml_event_onmousemove)|Usado para manipular o `onmousemove` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEOUT](#dhtml_event_onmouseout)|Usado para manipular o `onmouseout` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEOVER](#dhtml_event_onmouseover)|Usado para manipular o `onmouseover` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEUP](#dhtml_event_onmouseup)|Usado para manipular o `onmouseup` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONRESIZE](#dhtml_event_onresize)|Usado para manipular o `onresize` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONROWENTER](#dhtml_event_onrowenter)|Usado para manipular o `onrowenter` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONROWEXIT](#dhtml_event_onrowexit)|Usado para manipular o `onrowexit` evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONSELECTSTART](#dhtml_event_onselectstart)|Usado para manipular o `onselectstart` evento a partir de um elemento HTML.|
|[DHTML_EVENT_TAG](#dhtml_event_tag)|Usado para manipular um evento no nível de documento para todos os elementos com uma marca HTML específica.|
|[END_DHTML_EVENT_MAP](#end_dhtml_event_map)|Marca o final do mapa de eventos DHTML.|
|[END_DHTML_EVENT_MAP_INLINE](#end_dhtml_event_map_inline)|Marca o final do mapa de eventos DHTML. |

## <a name="url-event-map-macros"></a>Macros do mapa de eventos de URL

As macros a seguir podem ser usadas para manipular eventos DHTML em classes derivadas de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md).

|Nome|Descrição|
|-|-|
|[BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map)|Marca o início do mapa de eventos de URL e DHTML de multipágina.|
|[BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map)|Marca o início de um mapa de eventos DHTML inserido.|
|[BEGIN_URL_ENTRIES](#begin_url_entries)|Marca o início de um mapa de entrada de eventos de URL.|
|[DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map)|Declara o mapa de eventos de URL e DHTML de multipágina.|
|[END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map)|Marca o final do mapa de eventos de URL e DHTML de multipágina.|
|[END_EMBED_DHTML_EVENT_MAP](#end_embed_dhtml_event_map)|Marca o final de um mapa de eventos DHTML inserido.|
|[END_URL_ENTRIES](#end_url_entries)|Marca o final de um mapa de entrada de eventos de URL.|
|[URL_EVENT_ENTRY](#url_event_entry)|Mapeia uma URL ou recurso HTML para uma página em uma caixa de diálogo de multipáginas.|

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="begin_dhtml_event_map"></a><a name="begin_dhtml_event_map"></a> BEGIN_DHTML_EVENT_MAP

Marca o início do mapa de eventos DHTML quando colocado no arquivo de origem para a classe identificada por `className` .

```cpp
BEGIN_DHTML_EVENT_MAP(className)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de eventos DHTML. Essa classe deve derivar direta ou indiretamente do [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e incluir a macro [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicione um mapa de eventos DHTML à sua classe para fornecer informações para `CDHtmlDialog` que possam ser usadas para rotear eventos disparados por elementos HTML ou controles ActiveX em uma página da Web para o manipulador de funções em sua classe.

Coloque a macro BEGIN_DHTML_EVENT_MAP no arquivo de implementação da classe (. cpp) seguido por DHTML_EVENT macros para os eventos que a classe deve manipular (por exemplo, DHTML_EVENT_ONMOUSEOVER para eventos de mouseover). Use a macro [END_DHTML_EVENT_MAP](#end_dhtml_event_map) para marcar o final do mapa de eventos. Essas macros implementam a seguinte função:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="begin_dhtml_event_map_inline"></a><a name="begin_dhtml_event_map_inline"></a> BEGIN_DHTML_EVENT_MAP_INLINE

Marca o início do mapa de eventos DHTML dentro da definição de classe para *ClassName*.

```cpp
BEGIN_DHTML_EVENT_MAP_INLINE(className)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de eventos DHTML. Essa classe deve derivar direta ou indiretamente do [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e incluir a macro [DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicione um mapa de eventos DHTML à sua classe para fornecer informações para `CDHtmlDialog` que possam ser usadas para rotear eventos disparados por elementos HTML ou controles ActiveX em uma página da Web para o manipulador de funções em sua classe.

Coloque a macro BEGIN_DHTML_EVENT_MAP no arquivo de definição da classe (. h) seguido por DHTML_EVENT macros para os eventos que a classe deve manipular (por exemplo, DHTML_EVENT_ONMOUSEOVER para eventos de mouseover). Use a macro [END_DHTML_EVENT_MAP_INLINE](#end_dhtml_event_map_inline) para marcar o final do mapa de eventos. Essas macros implementam a seguinte função:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="declare_dhtml_event_map"></a><a name="declare_dhtml_event_map"></a> DECLARE_DHTML_EVENT_MAP

Declara um mapa de eventos DHTML em uma definição de classe.

```cpp
DECLARE_DHTML_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Essa macro deve ser usada na definição de classes derivadas de [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md).

Use [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map) ou [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline) para implementar o mapa.

[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) declara a seguinte função:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap( );`

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event"></a><a name="dhtml_event"></a> DHTML_EVENT

Manipula (no nível do documento) um evento identificado por *DISPID* originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
O DISPID do evento a ser manipulado.

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento, ou NULL para manipular eventos de documento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_axcontrol"></a><a name="dhtml_event_axcontrol"></a> DHTML_EVENT_AXCONTROL

Manipula o evento identificado por *DISPID* acionado pelo controle ActiveX identificado por *ControlName*.

```cpp
DHTML_EVENT_AXCONTROL(dispid, controlName,  memberFxn)
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
A ID de expedição do evento a ser manipulado.

*controle de origem*<br/>
Um LPCWSTR que mantém a ID HTML do controle que aciona o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_class"></a><a name="dhtml_event_class"></a> DHTML_EVENT_CLASS

Manipula (no nível do documento) um evento identificado por *DISPID* originado por qualquer elemento HTML com a classe CSS identificada por *elemName*.

```cpp
DHTML_EVENT_CLASS(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
A ID de expedição do evento a ser manipulado.

*elemName*<br/>
Um LPCWSTR que mantém a classe CSS dos elementos HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_element"></a><a name="dhtml_event_element"></a> DHTML_EVENT_ELEMENT

Handles (no elemento identificado por *elemName*) um evento identificado por *DISPID*.

```cpp
DHTML_EVENT_ELEMENT(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
A ID de expedição do evento a ser manipulado.

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

Se essa macro for usada para lidar com eventos não-bolha, a origem do evento será o elemento identificado por *elemName*.

Se essa macro for usada para lidar com eventos de bolha, o elemento identificado por *elemName* poderá não ser a origem do evento (a origem poderá ser qualquer elemento contido em *elemName*).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onafterupdate"></a><a name="dhtml_event_onafterupdate"></a> DHTML_EVENT_ONAFTERUPDATE

Manipula (no nível do documento) o `onafterupdate` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONAFTERUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onbeforeupdate"></a><a name="dhtml_event_onbeforeupdate"></a> DHTML_EVENT_ONBEFOREUPDATE

Manipula (no nível do documento) o `onbeforeupdate` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONBEFOREUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onblur"></a><a name="dhtml_event_onblur"></a> DHTML_EVENT_ONBLUR

Manipula (no nível do elemento) o `onblur` evento. Este é um evento não-bolha.

```cpp
DHTML_EVENT_ONBLUR(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onchange"></a><a name="dhtml_event_onchange"></a> DHTML_EVENT_ONCHANGE

Manipula (no nível do elemento) o `onchange` evento. Este é um evento não-bolha.

```cpp
DHTML_EVENT_ONCHANGE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onclick"></a><a name="dhtml_event_onclick"></a> DHTML_EVENT_ONCLICK

Manipula (no nível do documento) o `onclick` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONCLICK(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_ondataavailable"></a><a name="dhtml_event_ondataavailable"></a> DHTML_EVENT_ONDATAAVAILABLE

Manipula (no nível do documento) o `ondataavailable` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDATAAVAILABLE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_ondatasetchanged"></a><a name="dhtml_event_ondatasetchanged"></a> DHTML_EVENT_ONDATASETCHANGED

Manipula (no nível do documento) o `ondatasetchanged` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDATASETCHANGED(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_ondatasetcomplete"></a><a name="dhtml_event_ondatasetcomplete"></a> DHTML_EVENT_ONDATASETCOMPLETE

Manipula (no nível do documento) o `ondatasetcomplete` evento originado pelo elemento HTML identificado por `elemName` .

```cpp
DHTML_EVENT_ONDATASETCOMPLETE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_ondblclick"></a><a name="dhtml_event_ondblclick"></a> DHTML_EVENT_ONDBLCLICK

Manipula (no nível do documento) o `ondblclick` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDBLCLICK(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_ondragstart"></a><a name="dhtml_event_ondragstart"></a> DHTML_EVENT_ONDRAGSTART

Manipula (no nível do documento) o `ondragstart` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDRAGSTART(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onerrorupdate"></a><a name="dhtml_event_onerrorupdate"></a> DHTML_EVENT_ONERRORUPDATE

Manipula (no nível do documento) o `onerrorupdate` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONERRORUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onfilterchange"></a><a name="dhtml_event_onfilterchange"></a> DHTML_EVENT_ONFILTERCHANGE

Manipula (no nível do documento) o `onfilterchange` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONFILTERCHANGE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onfocus"></a><a name="dhtml_event_onfocus"></a> DHTML_EVENT_ONFOCUS

Manipula (no nível do elemento) o `onfocus` evento. Este é um evento não-bolha.

```cpp
DHTML_EVENT_ONFOCUS(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onhelp"></a><a name="dhtml_event_onhelp"></a> DHTML_EVENT_ONHELP

Manipula (no nível do documento) o `onhelp` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONHELP(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onkeydown"></a><a name="dhtml_event_onkeydown"></a> DHTML_EVENT_ONKEYDOWN

Manipula (no nível do documento) o `onkeydown` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONKEYDOWN(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onkeypress"></a><a name="dhtml_event_onkeypress"></a> DHTML_EVENT_ONKEYPRESS

Manipula (no nível do documento) o `onkeypress` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONKEYPRESS(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onkeyup"></a><a name="dhtml_event_onkeyup"></a> DHTML_EVENT_ONKEYUP

Manipula (no nível do documento) o `onkeyup` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONKEYUP(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onmousedown"></a><a name="dhtml_event_onmousedown"></a> DHTML_EVENT_ONMOUSEDOWN

Manipula (no nível do documento) o `onmousedown` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEDOWN(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onmousemove"></a><a name="dhtml_event_onmousemove"></a> DHTML_EVENT_ONMOUSEMOVE

Manipula (no nível do documento) o `onmousemove` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEMOVE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onmouseout"></a><a name="dhtml_event_onmouseout"></a> DHTML_EVENT_ONMOUSEOUT

Manipula (no nível do documento) o `onmouseout` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEOUT(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onmouseover"></a><a name="dhtml_event_onmouseover"></a> DHTML_EVENT_ONMOUSEOVER

Manipula (no nível do documento) o `onmouseover` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEOVER(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onmouseup"></a><a name="dhtml_event_onmouseup"></a> DHTML_EVENT_ONMOUSEUP

Manipula (no nível do documento) o `onmouseup` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEUP(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onresize"></a><a name="dhtml_event_onresize"></a> DHTML_EVENT_ONRESIZE

Manipula (no nível do elemento) o `onresize` evento. Este é um evento não-bolha.

```cpp
DHTML_EVENT_ONRESIZE(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onrowenter"></a><a name="dhtml_event_onrowenter"></a> DHTML_EVENT_ONROWENTER

Manipula (no nível do documento) o `onrowenter` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONROWENTER(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onrowexit"></a><a name="dhtml_event_onrowexit"></a> DHTML_EVENT_ONROWEXIT

Manipula (no nível do documento) o `onrowexit` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONROWEXIT(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_onselectstart"></a><a name="dhtml_event_onselectstart"></a> DHTML_EVENT_ONSELECTSTART

Manipula (no nível do documento) o `onselectstart` evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONSELECTSTART(elemName, memberFxn)
```

### <a name="parameters"></a>parâmetros

*elemName*<br/>
Um LPCWSTR que mantém a ID do elemento HTML que origina o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="dhtml_event_tag"></a><a name="dhtml_event_tag"></a> DHTML_EVENT_TAG

Manipula (no nível do documento) um evento identificado por `dispid` originado por qualquer elemento HTML com a marca HTML identificada por *elemName*.

```cpp
DHTML_EVENT_TAG(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
A ID de expedição do evento a ser manipulado.

*elemName*<br/>
A marca HTML dos elementos HTML que originam o evento.

*memberFxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="end_dhtml_event_map"></a><a name="end_dhtml_event_map"></a> END_DHTML_EVENT_MAP

Marca o final do mapa de eventos DHTML.

```cpp
END_DHTML_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="begin_dhtml_url_event_map"></a><a name="begin_dhtml_url_event_map"></a> BEGIN_DHTML_URL_EVENT_MAP

Inicia a definição de um mapa de eventos de DHTML e de URL em uma caixa de diálogo de multipáginas.

```cpp
BEGIN_DHTML_URL_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Coloque BEGIN_DHTML_URL_EVENT_MAP no arquivo de implementação de sua classe derivada de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Siga-o com [mapas de eventos DHTML inseridos](#begin_embed_dhtml_event_map) e [entradas de URL](#begin_url_entries)e, em seguida, feche-o com [END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map). Inclua a macro [DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map) dentro da definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#196](../../mfc/codesnippet/cpp/dhtml-event-maps_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="begin_embed_dhtml_event_map"></a><a name="begin_embed_dhtml_event_map"></a> BEGIN_EMBED_DHTML_EVENT_MAP

Inicia a definição de um mapa de eventos DHTML inserido em uma caixa de diálogo de multipáginas.

```cpp
BEGIN_EMBED_DHTML_EVENT_MAP(className, mapName)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de eventos. Essa classe deve derivar direta ou indiretamente do [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de eventos DHTML inserido deve estar dentro de um [mapa de eventos DHTML e de URL](#begin_dhtml_url_event_map)).

*mapName*<br/>
Especifica a página cujo mapeamento de evento é. Isso corresponde a *mapname* na macro [URL_EVENT_ENTRY](#url_event_entry) , na verdade, definindo a URL ou o recurso HTML.

### <a name="remarks"></a>Comentários

Como uma caixa de diálogo DHTML multipágina consiste em várias páginas HTML, cada uma delas pode gerar eventos DHTML, os mapas de eventos inseridos são usados para mapear eventos para os manipuladores por página.

Mapas de eventos incorporados em um HTML e um mapa de eventos de URL consistem em uma macro BEGIN_EMBED_DHTML_EVENT_MAP seguida por [DHTML_EVENT](#dhtml_event) macros e uma macro [END_EMBED_DHTML_EVENT_MAP](#end_embed_dhtml_event_map) .

Cada mapa de eventos inserido requer uma [entrada de evento de URL](#url_event_entry) correspondente para mapear *mapname* (especificado em BEGIN_EMBED_DHTML_EVENT_MAP) para uma URL ou recurso HTML.

### <a name="example"></a>Exemplo

Consulte o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="begin_url_entries"></a><a name="begin_url_entries"></a> BEGIN_URL_ENTRIES

Inicia a definição de um mapa de entrada de eventos de URL em uma caixa de diálogo de multipáginas.

```cpp
BEGIN_URL_ENTRIES(className)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de entrada de eventos da URL. Essa classe deve derivar direta ou indiretamente do [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de entrada de evento de URL deve estar dentro de um [mapa de eventos de DHTML e de URL](#begin_dhtml_url_event_map)).

### <a name="remarks"></a>Comentários

Como uma caixa de diálogo DHTML multipágina consiste em várias páginas HTML, as entradas de eventos de URL são usadas para mapear URLs ou recursos HTML para [mapas de eventos DHTML inseridos](#begin_embed_dhtml_event_map)correspondentes. Coloque URL_EVENT_ENTRY macros entre BEGIN_URL_ENTRIES e [END_URL_ENTRIES](#end_url_entries) macros.

### <a name="example"></a>Exemplo

Consulte o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="declare_dhtml_url_event_map"></a><a name="declare_dhtml_url_event_map"></a> DECLARE_DHTML_URL_EVENT_MAP

Declara um mapa de eventos de URL e DHTML em uma definição de classe.

```cpp
DECLARE_DHTML_URL_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Essa macro deve ser usada na definição de classes derivadas de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md).

Um mapa de eventos de DHTML e URL contém [mapas de eventos DHTML inseridos](#begin_embed_dhtml_event_map) e [entradas de eventos de URL](#begin_url_entries) para mapear eventos DHTML para manipuladores por página. Use [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) para implementar o mapa.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="end_dhtml_url_event_map"></a><a name="end_dhtml_url_event_map"></a> END_DHTML_URL_EVENT_MAP

Marca o final de um mapa de eventos de DHTML e de URL.

```cpp
END_DHTML_URL_EVENT_MAP(className)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de eventos. Essa classe deve derivar direta ou indiretamente do [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Isso deve corresponder a *ClassName* na macro [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) correspondente.

### <a name="example"></a>Exemplo

Consulte o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="end_embed_dhtml_event_map"></a><a name="end_embed_dhtml_event_map"></a> END_EMBED_DHTML_EVENT_MAP

Marca o final de um mapa de eventos DHTML inserido.

```cpp
END_EMBED_DHTML_EVENT_MAP()
```

### <a name="example"></a>Exemplo

Consulte o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="end_url_entries"></a><a name="end_url_entries"></a> END_URL_ENTRIES

Marca o final de um mapa de entrada de eventos de URL.

```cpp
END_URL_ENTRIES()
```

### <a name="example"></a>Exemplo

Consulte o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="url_event_entry"></a><a name="url_event_entry"></a> URL_EVENT_ENTRY

Mapeia uma URL ou recurso HTML para uma página em uma caixa de diálogo de multipáginas.

```cpp
URL_EVENT_ENTRY(className, url,  mapName)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de entrada de eventos da URL. Essa classe deve derivar direta ou indiretamente do [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de entrada de evento de URL deve estar dentro de um [mapa de eventos de DHTML e de URL](#begin_dhtml_url_event_map)).

*url*<br/>
A URL ou o recurso HTML da página.

*mapName*<br/>
Especifica a página cuja URL é *URL*. Isso corresponde a *mapname* na macro [BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map) que mapeia eventos desta página.

### <a name="remarks"></a>Comentários

Se a página for um recurso HTML, a *URL* deverá ser a representação da cadeia de caracteres do número de ID do recurso (ou seja, "123", não 123 ou ID_HTMLRES1).

O identificador de página, *mapname*, é um símbolo arbitrário usado para vincular mapas de eventos DHTML incorporados a mapas de entrada de eventos de URL. Ele é limitado no escopo para o mapa de eventos de URL e DHTML.

### <a name="example"></a>Exemplo

Consulte o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml. h

## <a name="end_dhtml_event_map_inline"></a><a name="end_dhtml_event_map_inline"></a> END_DHTML_EVENT_MAP_INLINE

Marca o final do mapa de eventos DHTML.

### <a name="syntax"></a>Sintaxe

```cpp
END_DHTML_EVENT_MAP_INLINE( )
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)

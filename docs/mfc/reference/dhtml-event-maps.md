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
ms.openlocfilehash: 30c755b2901374cffab3ce91d0683811ef6624b6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365801"
---
# <a name="dhtml-event-maps"></a>Mapas de evento DHTML

As seguintes macros podem ser usadas para lidar com eventos DHTML.

## <a name="dhtml-event-map-macros"></a>Macros do mapa de eventos DHTML

As seguintes macros podem ser usadas para lidar com eventos DHTML em classes derivadas do [CDHtmlDialog.](../../mfc/reference/cdhtmldialog-class.md)

|||
|-|-|
|[BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map)|Marca o início do mapa de eventos DHTML.|
|[BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline)|Marca o início do mapa de eventos DHTML.|
|[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map)|Declara o mapa de eventos DHTML.|
|[DHTML_EVENT](#dhtml_event)|Usado para lidar com um evento no nível do documento para um único elemento HTML.|
|[DHTML_EVENT_AXCONTROL](#dhtml_event_axcontrol)|Usado para lidar com um evento disparado por um controle ActiveX.|
|[DHTML_EVENT_CLASS](#dhtml_event_class)|Usado para lidar com um evento no nível de documento para todos os elementos HTML com uma classe CSS particular.|
|[DHTML_EVENT_ELEMENT](#dhtml_event_element)|Usado para lidar com um evento no nível do elemento.|
|[DHTML_EVENT_ONAFTERUPDATE](#dhtml_event_onafterupdate)|Usado para `onafterupdate` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONBEFOREUPDATE](#dhtml_event_onbeforeupdate)|Usado para `onbeforeupdate` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONBLUR](#dhtml_event_onblur)|Usado para `onblur` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONCHANGE](#dhtml_event_onchange)|Usado para `onchange` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONCLICK](#dhtml_event_onclick)|Usado para `onclick` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATAAVAILABLE](#dhtml_event_ondataavailable)|Usado para `ondataavailable` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATASETCHANGED](#dhtml_event_ondatasetchanged)|Usado para `ondatasetchanged` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDATASETCOMPLETE](#dhtml_event_ondatasetcomplete)|Usado para `ondatasetcomplete` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDBLCLICK](#dhtml_event_ondblclick)|Usado para `ondblclick` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONDRAGSTART](#dhtml_event_ondragstart)|Usado para `ondragstart` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONERRORUPDATE](#dhtml_event_onerrorupdate)|Usado para `onerrorupdate` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONFILTERCHANGE](#dhtml_event_onfilterchange)|Usado para `onfilterchange` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONFOCUS](#dhtml_event_onfocus)|Usado para `onfocus` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONHELP](#dhtml_event_onhelp)|Usado para `onhelp` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYDOWN](#dhtml_event_onkeydown)|Usado para `onkeydown` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYPRESS](#dhtml_event_onkeypress)|Usado para `onkeypress` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONKEYUP](#dhtml_event_onkeyup)|Usado para `onkeyup` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEDOWN](#dhtml_event_onmousedown)|Usado para `onmousedown` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEMOVE](#dhtml_event_onmousemove)|Usado para `onmousemove` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEOUT](#dhtml_event_onmouseout)|Usado para `onmouseout` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEOVER](#dhtml_event_onmouseover)|Usado para `onmouseover` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONMOUSEUP](#dhtml_event_onmouseup)|Usado para `onmouseup` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONRESIZE](#dhtml_event_onresize)|Usado para `onresize` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONROWENTER](#dhtml_event_onrowenter)|Usado para `onrowenter` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONROWEXIT](#dhtml_event_onrowexit)|Usado para `onrowexit` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_ONSELECTSTART](#dhtml_event_onselectstart)|Usado para `onselectstart` lidar com o evento a partir de um elemento HTML.|
|[DHTML_EVENT_TAG](#dhtml_event_tag)|Usado para lidar com um evento no nível do documento para todos os elementos com uma tag HTML particular.|
|[END_DHTML_EVENT_MAP](#end_dhtml_event_map)|Marca o fim do mapa de eventos DHTML.|
|[END_DHTML_EVENT_MAP_INLINE](#end_dhtml_event_map_inline)|Marca o fim do mapa de eventos DHTML. |

## <a name="url-event-map-macros"></a>Macros do mapa de eventos de URL

As seguintes macros podem ser usadas para lidar com eventos DHTML em classes derivadas de [CMultiPageDHtmlDialog.](../../mfc/reference/cmultipagedhtmldialog-class.md)

|||
|-|-|
|[BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map)|Marca o início do mapa de eventos DHTML e URL de várias páginas.|
|[BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map)|Marca o início de um mapa de eventos DHTML incorporado.|
|[BEGIN_URL_ENTRIES](#begin_url_entries)|Marca o início de um mapa de entrada de eventos de URL.|
|[DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map)|Declara o mapa de eventos DHTML e URL de várias páginas.|
|[END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map)|Marca o fim do mapa de eventos DHTML e URL de várias páginas.|
|[END_EMBED_DHTML_EVENT_MAP](#end_embed_dhtml_event_map)|Marca o fim de um mapa de eventos DHTML incorporado.|
|[END_URL_ENTRIES](#end_url_entries)|Marca o fim de um mapa de entrada de evento url.|
|[URL_EVENT_ENTRY](#url_event_entry)|Mapeia um recurso DE URL ou HTML para uma página em uma caixa de diálogo de várias páginas.|

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="begin_dhtml_event_map"></a><a name="begin_dhtml_event_map"></a>BEGIN_DHTML_EVENT_MAP

Marca o início do mapa de eventos DHTML quando colocado `className`no arquivo de origem da classe identificada por .

```cpp
BEGIN_DHTML_EVENT_MAP(className)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa de eventos DHTML. Esta classe deve derivar direta ou indiretamente do [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e incluir a [macro DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicione um mapa de evento DHTML `CDHtmlDialog` à sua classe para fornecer informações que possam ser usadas para rotear eventos disparados por elementos HTML ou controles ActiveX em uma página da Web para funções de manipulador em sua classe.

Coloque a BEGIN_DHTML_EVENT_MAP macro no arquivo de implementação da classe (.cpp) seguida de DHTML_EVENT macros para os eventos que a classe deve lidar (por exemplo, DHTML_EVENT_ONMOUSEOVER para eventos de mouseover). Use a [END_DHTML_EVENT_MAP](#end_dhtml_event_map) macro para marcar o fim do mapa do evento. Essas macros implementam a seguinte função:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="begin_dhtml_event_map_inline"></a><a name="begin_dhtml_event_map_inline"></a>BEGIN_DHTML_EVENT_MAP_INLINE

Marca o início do mapa de eventos DHTML dentro da definição de classe para *className*.

```cpp
BEGIN_DHTML_EVENT_MAP_INLINE(className)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa de eventos DHTML. Esta classe deve derivar direta ou indiretamente do [CDHtmlDialog](../../mfc/reference/cdhtmldialog-class.md) e incluir a [macro DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicione um mapa de evento DHTML `CDHtmlDialog` à sua classe para fornecer informações que possam ser usadas para rotear eventos disparados por elementos HTML ou controles ActiveX em uma página da Web para funções de manipulador em sua classe.

Coloque a BEGIN_DHTML_EVENT_MAP macro no arquivo de definição (.h) da classe seguido por DHTML_EVENT macros para os eventos que a classe deve lidar (por exemplo, DHTML_EVENT_ONMOUSEOVER para eventos de mouseover). Use a [macro END_DHTML_EVENT_MAP_INLINE](#end_dhtml_event_map_inline) para marcar o fim do mapa do evento. Essas macros implementam a seguinte função:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap();`

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="declare_dhtml_event_map"></a><a name="declare_dhtml_event_map"></a>DECLARE_DHTML_EVENT_MAP

Declara um mapa de evento DHTML em uma definição de classe.

```cpp
DECLARE_DHTML_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Esta macro deve ser usada na definição de classes derivadas do [CDHtmlDialog.](../../mfc/reference/cdhtmldialog-class.md)

Use [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map) ou [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline) para implementar o mapa.

[DECLARE_DHTML_EVENT_MAP](#declare_dhtml_event_map) declara a seguinte função:

`virtual const DHtmlEventMapEntry* GetDHtmlEventMap( );`

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event"></a><a name="dhtml_event"></a>DHTML_EVENT

Manipula (no nível do documento) um evento identificado por *dispid* originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
O DISPID do evento a ser tratado.

*Elemname*<br/>
Um LPCWSTR contendo o ID do elemento HTML que fornece o evento, ou NULL para lidar com eventos de documentos.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_axcontrol"></a><a name="dhtml_event_axcontrol"></a>DHTML_EVENT_AXCONTROL

Lida com o evento identificado por *dispid* disparado pelo controle ActiveX identificado pelo *controlName*.

```cpp
DHTML_EVENT_AXCONTROL(dispid, controlName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
A id de despacho do evento a ser tratada.

*Controlname*<br/>
Um LPCWSTR segurando o ID HTML do controle disparando o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_class"></a><a name="dhtml_event_class"></a>DHTML_EVENT_CLASS

Lida (no nível do documento) um evento identificado por *dispid* originado por qualquer elemento HTML com a classe CSS identificada por *elemName*.

```cpp
DHTML_EVENT_CLASS(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
A id de despacho do evento a ser tratada.

*Elemname*<br/>
Um LPCWSTR segurando a classe CSS dos elementos HTML que sourcing do evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_element"></a><a name="dhtml_event_element"></a>DHTML_EVENT_ELEMENT

Alças (no elemento identificado por *elemName*) um evento identificado por *dispid*.

```cpp
DHTML_EVENT_ELEMENT(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
A id de despacho do evento a ser tratada.

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

Se essa macro for usada para lidar com eventos não borbulhantes, a fonte do evento será o elemento identificado por *elemName*.

Se esta macro for usada para lidar com eventos borbulhantes, o elemento identificado por *elemName* pode não ser a fonte do evento (a fonte pode ser qualquer elemento contido por *elemName*).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onafterupdate"></a><a name="dhtml_event_onafterupdate"></a>DHTML_EVENT_ONAFTERUPDATE

Alças (no nível do `onafterupdate` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONAFTERUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onbeforeupdate"></a><a name="dhtml_event_onbeforeupdate"></a>DHTML_EVENT_ONBEFOREUPDATE

Alças (no nível do `onbeforeupdate` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONBEFOREUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onblur"></a><a name="dhtml_event_onblur"></a>DHTML_EVENT_ONBLUR

Alças (no nível do `onblur` elemento) o evento. Este é um evento que não é borbulhante.

```cpp
DHTML_EVENT_ONBLUR(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onchange"></a><a name="dhtml_event_onchange"></a>DHTML_EVENT_ONCHANGE

Alças (no nível do `onchange` elemento) o evento. Este é um evento que não é borbulhante.

```cpp
DHTML_EVENT_ONCHANGE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onclick"></a><a name="dhtml_event_onclick"></a>DHTML_EVENT_ONCLICK

Alças (no nível do `onclick` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONCLICK(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_ondataavailable"></a><a name="dhtml_event_ondataavailable"></a>DHTML_EVENT_ONDATAAVAILABLE

Alças (no nível do `ondataavailable` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDATAAVAILABLE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_ondatasetchanged"></a><a name="dhtml_event_ondatasetchanged"></a>DHTML_EVENT_ONDATASETCHANGED

Alças (no nível do `ondatasetchanged` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDATASETCHANGED(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_ondatasetcomplete"></a><a name="dhtml_event_ondatasetcomplete"></a>DHTML_EVENT_ONDATASETCOMPLETE

Alças (no nível do `ondatasetcomplete` documento) o evento originado pelo elemento HTML identificado por `elemName`.

```cpp
DHTML_EVENT_ONDATASETCOMPLETE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_ondblclick"></a><a name="dhtml_event_ondblclick"></a>DHTML_EVENT_ONDBLCLICK

Alças (no nível do `ondblclick` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDBLCLICK(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_ondragstart"></a><a name="dhtml_event_ondragstart"></a>DHTML_EVENT_ONDRAGSTART

Alças (no nível do `ondragstart` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONDRAGSTART(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onerrorupdate"></a><a name="dhtml_event_onerrorupdate"></a>DHTML_EVENT_ONERRORUPDATE

Alças (no nível do `onerrorupdate` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONERRORUPDATE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onfilterchange"></a><a name="dhtml_event_onfilterchange"></a>DHTML_EVENT_ONFILTERCHANGE

Alças (no nível do `onfilterchange` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONFILTERCHANGE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onfocus"></a><a name="dhtml_event_onfocus"></a>DHTML_EVENT_ONFOCUS

Alças (no nível do `onfocus` elemento) o evento. Este é um evento que não é borbulhante.

```cpp
DHTML_EVENT_ONFOCUS(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onhelp"></a><a name="dhtml_event_onhelp"></a>DHTML_EVENT_ONHELP

Alças (no nível do `onhelp` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONHELP(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onkeydown"></a><a name="dhtml_event_onkeydown"></a>DHTML_EVENT_ONKEYDOWN

Alças (no nível do `onkeydown` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONKEYDOWN(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onkeypress"></a><a name="dhtml_event_onkeypress"></a>DHTML_EVENT_ONKEYPRESS

Alças (no nível do `onkeypress` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONKEYPRESS(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onkeyup"></a><a name="dhtml_event_onkeyup"></a>DHTML_EVENT_ONKEYUP

Alças (no nível do `onkeyup` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONKEYUP(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onmousedown"></a><a name="dhtml_event_onmousedown"></a>DHTML_EVENT_ONMOUSEDOWN

Alças (no nível do `onmousedown` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEDOWN(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onmousemove"></a><a name="dhtml_event_onmousemove"></a>DHTML_EVENT_ONMOUSEMOVE

Alças (no nível do `onmousemove` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEMOVE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onmouseout"></a><a name="dhtml_event_onmouseout"></a>DHTML_EVENT_ONMOUSEOUT

Alças (no nível do `onmouseout` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEOUT(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onmouseover"></a><a name="dhtml_event_onmouseover"></a>DHTML_EVENT_ONMOUSEOVER

Alças (no nível do `onmouseover` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEOVER(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onmouseup"></a><a name="dhtml_event_onmouseup"></a>DHTML_EVENT_ONMOUSEUP

Alças (no nível do `onmouseup` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONMOUSEUP(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onresize"></a><a name="dhtml_event_onresize"></a>DHTML_EVENT_ONRESIZE

Alças (no nível do `onresize` elemento) o evento. Este é um evento que não é borbulhante.

```cpp
DHTML_EVENT_ONRESIZE(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onrowenter"></a><a name="dhtml_event_onrowenter"></a>DHTML_EVENT_ONROWENTER

Alças (no nível do `onrowenter` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONROWENTER(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onrowexit"></a><a name="dhtml_event_onrowexit"></a>DHTML_EVENT_ONROWEXIT

Alças (no nível do `onrowexit` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONROWEXIT(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_onselectstart"></a><a name="dhtml_event_onselectstart"></a>DHTML_EVENT_ONSELECTSTART

Alças (no nível do `onselectstart` documento) o evento originado pelo elemento HTML identificado por *elemName*.

```cpp
DHTML_EVENT_ONSELECTSTART(elemName, memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Elemname*<br/>
Um LPCWSTR segurando o ID do elemento HTML que fornece o evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="dhtml_event_tag"></a><a name="dhtml_event_tag"></a>DHTML_EVENT_TAG

Lida (no nível do documento) `dispid` um evento identificado por originado por qualquer elemento HTML com a tag HTML identificada por *elemName*.

```cpp
DHTML_EVENT_TAG(dispid, elemName,  memberFxn)
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
A id de despacho do evento a ser tratada.

*Elemname*<br/>
A tag HTML dos elementos HTML que sourcing do evento.

*Memberfxn*<br/>
A função de manipulador para o evento.

### <a name="remarks"></a>Comentários

Use esta macro para adicionar uma entrada ao [mapa de eventos DHTML](#begin_dhtml_event_map_inline) em sua classe.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="end_dhtml_event_map"></a><a name="end_dhtml_event_map"></a>END_DHTML_EVENT_MAP

Marca o fim do mapa de eventos DHTML.

```cpp
END_DHTML_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP](#begin_dhtml_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="begin_dhtml_url_event_map"></a><a name="begin_dhtml_url_event_map"></a>Begin_dhtml_url_event_map

Inicia a definição de um mapa de eventos DHTML e URL em uma caixa de diálogo de várias páginas.

```cpp
BEGIN_DHTML_URL_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Coloque BEGIN_DHTML_URL_EVENT_MAP no arquivo de implementação da sua classe derivada [cmultipagedhtmldialog.](../../mfc/reference/cmultipagedhtmldialog-class.md) Siga-o com [mapas de eventos DHTML incorporados](#begin_embed_dhtml_event_map) e [entradas de URL](#begin_url_entries)e, em seguida, feche-o com [END_DHTML_URL_EVENT_MAP](#end_dhtml_url_event_map). Inclua a [DECLARE_DHTML_URL_EVENT_MAP](#declare_dhtml_url_event_map) macro dentro da definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#196](../../mfc/codesnippet/cpp/dhtml-event-maps_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="begin_embed_dhtml_event_map"></a><a name="begin_embed_dhtml_event_map"></a>BEGIN_EMBED_DHTML_EVENT_MAP

Inicia a definição de um mapa de evento DHTML incorporado em uma caixa de diálogo de várias páginas.

```cpp
BEGIN_EMBED_DHTML_EVENT_MAP(className, mapName)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa do evento. Esta classe deve derivar direta ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de eventos DHTML incorporado deve estar dentro de um [mapa de eventos DHTML e URL](#begin_dhtml_url_event_map)).

*Mapname*<br/>
Especifica a página cujo mapa de eventos é este. Isso corresponde [ao](#url_event_entry) *mapName* na URL_EVENT_ENTRY macro realmente definindo o recurso URL ou HTML.

### <a name="remarks"></a>Comentários

Como uma caixa de diálogo DHTML de várias páginas consiste em várias páginas HTML, cada uma das quais pode levantar eventos DHTML, mapas de eventos incorporados são usados para mapear eventos para manipuladores em uma base por página.

Mapas de eventos incorporados dentro de um mapa de eventos DHTML e URL consistem em uma macro BEGIN_EMBED_DHTML_EVENT_MAP seguida de [DHTML_EVENT](#dhtml_event) macros e uma de [END_EMBED_DHTML_EVENT_MAP.](#end_embed_dhtml_event_map)

Cada mapa de evento incorporado requer uma entrada de [evento url](#url_event_entry) correspondente para mapear *mapname* (especificado em BEGIN_EMBED_DHTML_EVENT_MAP) para um recurso URL ou HTML.

### <a name="example"></a>Exemplo

Veja o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="begin_url_entries"></a><a name="begin_url_entries"></a>BEGIN_URL_ENTRIES

Inicia a definição de um mapa de entrada de evento URL em uma caixa de diálogo de várias páginas.

```cpp
BEGIN_URL_ENTRIES(className)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa de entrada do evento URL. Esta classe deve derivar direta ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de entrada do evento URL deve estar dentro de um [mapa de eventos DHTML e URL](#begin_dhtml_url_event_map)).

### <a name="remarks"></a>Comentários

Como uma caixa de diálogo DHTML de várias páginas consiste em várias páginas HTML, as entradas de eventos de URL são usadas para mapear URLs ou recursos HTML para [mapas de eventos DHTML incorporados correspondentes](#begin_embed_dhtml_event_map). Coloque URL_EVENT_ENTRY macros entre BEGIN_URL_ENTRIES e [END_URL_ENTRIES](#end_url_entries) macros.

### <a name="example"></a>Exemplo

Veja o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="declare_dhtml_url_event_map"></a><a name="declare_dhtml_url_event_map"></a>DECLARE_DHTML_URL_EVENT_MAP

Declara um mapa de evento DHTML e URL em uma definição de classe.

```cpp
DECLARE_DHTML_URL_EVENT_MAP()
```

### <a name="remarks"></a>Comentários

Esta macro deve ser usada na definição de classes derivadas de [CMultiPageDHtmlDialog.](../../mfc/reference/cmultipagedhtmldialog-class.md)

Um mapa de eventos DHTML e URL contém [mapas de eventos DHTML incorporados](#begin_embed_dhtml_event_map) e [entradas de eventos url](#begin_url_entries) para mapear eventos DHTML para manipuladores em uma base por página. Use [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map) para implementar o mapa.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="end_dhtml_url_event_map"></a><a name="end_dhtml_url_event_map"></a>END_DHTML_URL_EVENT_MAP

Marca o fim de um mapa de eventos DHTML e URL.

```cpp
END_DHTML_URL_EVENT_MAP(className)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa do evento. Esta classe deve derivar direta ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). Isso deve corresponder *a className* na macro [correspondente BEGIN_DHTML_URL_EVENT_MAP.](#begin_dhtml_url_event_map)

### <a name="example"></a>Exemplo

Veja o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="end_embed_dhtml_event_map"></a><a name="end_embed_dhtml_event_map"></a>END_EMBED_DHTML_EVENT_MAP

Marca o fim de um mapa de eventos DHTML incorporado.

```cpp
END_EMBED_DHTML_EVENT_MAP()
```

### <a name="example"></a>Exemplo

Veja o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="end_url_entries"></a><a name="end_url_entries"></a>END_URL_ENTRIES

Marca o fim de um mapa de entrada de evento url.

```cpp
END_URL_ENTRIES()
```

### <a name="example"></a>Exemplo

Veja o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="url_event_entry"></a><a name="url_event_entry"></a>URL_EVENT_ENTRY

Mapeia um recurso DE URL ou HTML para uma página em uma caixa de diálogo de várias páginas.

```cpp
URL_EVENT_ENTRY(className, url,  mapName)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa de entrada do evento URL. Esta classe deve derivar direta ou indiretamente de [CMultiPageDHtmlDialog](../../mfc/reference/cmultipagedhtmldialog-class.md). O mapa de entrada do evento URL deve estar dentro de um [mapa de eventos DHTML e URL](#begin_dhtml_url_event_map)).

*url*<br/>
O recurso URL ou HTML para a página.

*Mapname*<br/>
Especifica a página cuja URL é *url*. Isso corresponde ao *mapaNome* [BEGIN_EMBED_DHTML_EVENT_MAP](#begin_embed_dhtml_event_map) na macro que mapeia eventos a partir desta página.

### <a name="remarks"></a>Comentários

Se a página for um recurso HTML, *url* deve ser a representação de string do número de ID do recurso (ou seja, "123", não 123 ou ID_HTMLRES1).

O identificador de página, *mapName*, é um símbolo arbitrário usado para vincular mapas de eventos DHTML incorporados a mapas de entrada de eventos url. Ele é limitado no escopo do mapa de eventos DHTML e URL.

### <a name="example"></a>Exemplo

Veja o exemplo em [BEGIN_DHTML_URL_EVENT_MAP](#begin_dhtml_url_event_map).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdhtml.h

## <a name="end_dhtml_event_map_inline"></a><a name="end_dhtml_event_map_inline"></a>END_DHTML_EVENT_MAP_INLINE

Marca o fim do mapa de eventos DHTML.

### <a name="syntax"></a>Sintaxe

```cpp
END_DHTML_EVENT_MAP_INLINE( )
```

### <a name="remarks"></a>Comentários

Deve ser usado em conjunto com [BEGIN_DHTML_EVENT_MAP_INLINE](#begin_dhtml_event_map_inline).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)

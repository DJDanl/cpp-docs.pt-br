---
title: Mapas de comando de edição DHTML
ms.date: 11/04/2016
ms.assetid: c1b49876-039e-4a26-bb24-ea98ccf254a1
ms.openlocfilehash: f4bbfb500e8de9594bbaa334b4e227caeaa845da
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837405"
---
# <a name="dhtml-editing-command-maps"></a>Mapas de comando de edição DHTML

As macros a seguir podem ser usadas para mapear comandos de edição DHTML em classes derivadas de [CHtmlEditView](../../mfc/reference/chtmleditview-class.md). Para obter um exemplo de uso, consulte [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="dhtml-editing-command-map-macros"></a>Macros de mapa de comando de edição DHTML

|Nome|Descrição|
|-|-|
|[DECLARE_DHTMLEDITING_CMDMAP](#declare_dhtmlediting_cmdmap)|Declara um mapa de comando de edição DHTML em uma classe.|
|[BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap)|Inicia a definição de um mapa de comando de edição DHTML dentro de uma classe.|
|[END_DHTMLEDITING_CMDMAP](#end_dhtmlediting_cmdmap)|Marca o final de um mapa de comando de edição DHTML.|
|[DHTMLEDITING_CMD_ENTRY](#dhtmlediting_cmd_entry)|Mapeia uma ID de comando para um comando de edição HTML.|
|[DHTMLEDITING_CMD_ENTRY_FUNC](#dhtmlediting_cmd_entry_func)|Mapeia uma ID de comando para um comando de edição HTML e manipulador de mensagens.|
|[DHTMLEDITING_CMD_ENTRY_TYPE](#dhtmlediting_cmd_entry_type)|Mapeia uma ID de comando para um elemento de interface de usuário e comando de edição HTML.|
|[DHTMLEDITING_CMD_ENTRY_FUNC_TYPE](#dhtmlediting_cmd_entry_func_type)|Mapeia uma ID de comando para um comando de edição HTML, um manipulador de mensagens e um elemento de interface do usuário.|

## <a name="declare_dhtmlediting_cmdmap"></a><a name="declare_dhtmlediting_cmdmap"></a> DECLARE_DHTMLEDITING_CMDMAP

Declara um mapa de comando de edição DHTML em uma classe.

```
DECLARE_DHTMLEDITING_CMDMAP(className)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe.

### <a name="remarks"></a>Comentários

Essa macro deve ser usada na definição de classes derivadas de [CHtmlEditView](../../mfc/reference/chtmleditview-class.md).

Use [BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap) para implementar o mapa.

### <a name="example"></a>Exemplo

Consulte o [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="begin_dhtmlediting_cmdmap"></a><a name="begin_dhtmlediting_cmdmap"></a> BEGIN_DHTMLEDITING_CMDMAP

Inicia a definição de um mapa de comando de edição DHTML dentro de uma classe.

```
BEGIN_DHTMLEDITING_CMDMAP(className)
```

### <a name="parameters"></a>parâmetros

*className*<br/>
O nome da classe que contém o mapa de comandos de edição DHTML. Essa classe deve derivar direta ou indiretamente do [CHtmlEditView](../../mfc/reference/chtmleditview-class.md) e incluir a macro [DECLARE_DHTMLEDITING_CMDMAP](#declare_dhtmlediting_cmdmap) dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicione um mapa de comando de edição DHTML à sua classe para mapear comandos de interface do usuário para comandos de edição HTML.

Coloque a macro BEGIN_DHTMLEDITING_CMDMAP no arquivo de implementação da classe (. cpp) seguido por [DHTMLEDITING_CMD_ENTRY](#dhtmlediting_cmd_entry) macros para os comandos que a classe deve mapear (por exemplo, de ID_EDIT_CUT para IDM_CUT). Use a macro [END_DHTMLEDITING_CMDMAP](#end_dhtmlediting_cmdmap) para marcar o final do mapa de eventos.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="end_dhtmlediting_cmdmap"></a><a name="end_dhtmlediting_cmdmap"></a> END_DHTMLEDITING_CMDMAP

Marca o final de um mapa de comando de edição DHTML.

```
END_DHTMLEDITING_CMDMAP()
```

### <a name="remarks"></a>Comentários

Use em conjunto com [BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap).

### <a name="example"></a>Exemplo

Consulte o [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="dhtmlediting_cmd_entry"></a><a name="dhtmlediting_cmd_entry"></a> DHTMLEDITING_CMD_ENTRY

Mapeia uma ID de comando para um comando de edição HTML.

```
DHTMLEDITING_CMD_ENTRY(cmdID,  dhtmlcmdID)
```

### <a name="parameters"></a>parâmetros

*cmdID*<br/>
A ID de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML no qual o *cmdID* mapeia (como IDM_COPY).

### <a name="example"></a>Exemplo

Consulte o [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="dhtmlediting_cmd_entry_func"></a><a name="dhtmlediting_cmd_entry_func"></a> DHTMLEDITING_CMD_ENTRY_FUNC

Mapeia uma ID de comando para um comando de edição HTML e manipulador de mensagens.

```
DHTMLEDITING_CMD_ENTRY_FUNC(cmdID, dhtmlcmdID,  member_func_name)
```

### <a name="parameters"></a>parâmetros

*cmdID*<br/>
A ID de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML no qual o *cmdID* mapeia (como IDM_COPY).

*member_func_name*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="example"></a>Exemplo

Consulte o [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="dhtmlediting_cmd_entry_type"></a><a name="dhtmlediting_cmd_entry_type"></a> DHTMLEDITING_CMD_ENTRY_TYPE

Mapeia uma ID de comando para um elemento de interface de usuário e comando de edição HTML.

```
DHTMLEDITING_CMD_ENTRY_TYPE(cmdID  ,   dhtmlcmdID  ,    elemType)
```

### <a name="parameters"></a>parâmetros

*cmdID*<br/>
A ID de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML no qual o *cmdID* mapeia (como IDM_COPY).

*elemType*<br/>
O tipo de elemento da interface do usuário; um dos AFX_UI_ELEMTYPE_NORMAL, AFX_UI_ELEMTYPE_CHECKBOX ou AFX_UI_ELEMTYPE_RADIO.

### <a name="example"></a>Exemplo

Consulte o [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="dhtmlediting_cmd_entry_func_type"></a><a name="dhtmlediting_cmd_entry_func_type"></a> DHTMLEDITING_CMD_ENTRY_FUNC_TYPE

Mapeia uma ID de comando para um comando de edição HTML, um manipulador de mensagens e um elemento de interface do usuário.

```
DHTMLEDITING_CMD_ENTRY_FUNC_TYPE(cmdID, dhtmlcmdID, member_func_name,  elemType)
```

### <a name="parameters"></a>parâmetros

*cmdID*<br/>
A ID de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML no qual o *cmdID* mapeia (como IDM_COPY).

*member_func_name*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

*elemType*<br/>
O tipo de elemento da interface do usuário; um dos AFX_UI_ELEMTYPE_NORMAL, AFX_UI_ELEMTYPE_CHECKBOX ou AFX_UI_ELEMTYPE_RADIO.

### <a name="example"></a>Exemplo

Consulte o [exemplo de HtmlEdit](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

---
title: Mapas de comando de edição DHTML
ms.date: 11/04/2016
ms.assetid: c1b49876-039e-4a26-bb24-ea98ccf254a1
ms.openlocfilehash: 62b388eb178be018655ea2b2be00d7321da50335
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365815"
---
# <a name="dhtml-editing-command-maps"></a>Mapas de comando de edição DHTML

As seguintes macros podem ser usadas para mapear comandos de edição DHTML em classes derivadas do [CHtmlEditView.](../../mfc/reference/chtmleditview-class.md) Para um exemplo de seu uso, consulte [HTMLEditar Sample](../../overview/visual-cpp-samples.md).

### <a name="dhtml-editing-command-map-macros"></a>Macros do mapa de comando de edição do DHTML

|||
|-|-|
|[DECLARE_DHTMLEDITING_CMDMAP](#declare_dhtmlediting_cmdmap)|Declara um mapa de comando de edição DHTML em uma classe.|
|[BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap)|Inicia a definição de um mapa de comando de edição DHTML dentro de uma classe.|
|[END_DHTMLEDITING_CMDMAP](#end_dhtmlediting_cmdmap)|Marca o fim de um mapa de comando de edição DHTML.|
|[DHTMLEDITING_CMD_ENTRY](#dhtmlediting_cmd_entry)|Mapeia um ID de comando para um comando de edição HTML.|
|[DHTMLEDITING_CMD_ENTRY_FUNC](#dhtmlediting_cmd_entry_func)|Mapeia um ID de comando para um comando de edição HTML e manipulador de mensagens.|
|[DHTMLEDITING_CMD_ENTRY_TYPE](#dhtmlediting_cmd_entry_type)|Mapeia um ID de comando para um comando de edição HTML e elemento de interface do usuário.|
|[DHTMLEDITING_CMD_ENTRY_FUNC_TYPE](#dhtmlediting_cmd_entry_func_type)|Mapeie um ID de comando para um comando de edição HTML, manipulador de mensagens e elemento de interface do usuário.|

## <a name="declare_dhtmlediting_cmdmap"></a><a name="declare_dhtmlediting_cmdmap"></a>DECLARE_DHTMLEDITING_CMDMAP

Declara um mapa de comando de edição DHTML em uma classe.

```
DECLARE_DHTMLEDITING_CMDMAP(className)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe.

### <a name="remarks"></a>Comentários

Esta macro deve ser usada na definição de classes derivadas de [CHtmlEditView.](../../mfc/reference/chtmleditview-class.md)

Use [BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap) para implementar o mapa.

### <a name="example"></a>Exemplo

Consulte [HTMLEditar amostra](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="begin_dhtmlediting_cmdmap"></a><a name="begin_dhtmlediting_cmdmap"></a>BEGIN_DHTMLEDITING_CMDMAP

Inicia a definição de um mapa de comando de edição DHTML dentro de uma classe.

```
BEGIN_DHTMLEDITING_CMDMAP(className)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
O nome da classe que contém o mapa de comando de edição DHTML. Esta classe deve derivar direta ou indiretamente do [CHtmlEditView](../../mfc/reference/chtmleditview-class.md) e incluir a [macro DECLARE_DHTMLEDITING_CMDMAP](#declare_dhtmlediting_cmdmap) dentro de sua definição de classe.

### <a name="remarks"></a>Comentários

Adicione um mapa de comando de edição DHTML à sua classe para mapear comandos de interface do usuário para comandos de edição HTML.

Coloque a BEGIN_DHTMLEDITING_CMDMAP macro no arquivo de implementação da classe (.cpp) seguida de [DHTMLEDITING_CMD_ENTRY](#dhtmlediting_cmd_entry) macros para os comandos que a classe deve mapear (por exemplo, de ID_EDIT_CUT a IDM_CUT). Use a [macro END_DHTMLEDITING_CMDMAP](#end_dhtmlediting_cmdmap) para marcar o fim do mapa do evento.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="end_dhtmlediting_cmdmap"></a><a name="end_dhtmlediting_cmdmap"></a>END_DHTMLEDITING_CMDMAP

Marca o fim de um mapa de comando de edição DHTML.

```
END_DHTMLEDITING_CMDMAP()
```

### <a name="remarks"></a>Comentários

Use em conjunto com [BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap).

### <a name="example"></a>Exemplo

Consulte [HTMLEditar amostra](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="dhtmlediting_cmd_entry"></a><a name="dhtmlediting_cmd_entry"></a>DHTMLEDITING_CMD_ENTRY

Mapeia um ID de comando para um comando de edição HTML.

```
DHTMLEDITING_CMD_ENTRY(cmdID,  dhtmlcmdID)
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O iD de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML para o qual *o cmdID* mapeia (como IDM_COPY).

### <a name="example"></a>Exemplo

Consulte [HTMLEditar amostra](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="dhtmlediting_cmd_entry_func"></a><a name="dhtmlediting_cmd_entry_func"></a>DHTMLEDITING_CMD_ENTRY_FUNC

Mapeia um ID de comando para um comando de edição HTML e manipulador de mensagens.

```
DHTMLEDITING_CMD_ENTRY_FUNC(cmdID, dhtmlcmdID,  member_func_name)
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O iD de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML para o qual *o cmdID* mapeia (como IDM_COPY).

*member_func_name*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="example"></a>Exemplo

Consulte [HTMLEditar amostra](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="dhtmlediting_cmd_entry_type"></a><a name="dhtmlediting_cmd_entry_type"></a>DHTMLEDITING_CMD_ENTRY_TYPE

Mapeia um ID de comando para um comando de edição HTML e elemento de interface do usuário.

```
DHTMLEDITING_CMD_ENTRY_TYPE(cmdID  ,   dhtmlcmdID  ,    elemType)
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O iD de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML para o qual *o cmdID* mapeia (como IDM_COPY).

*elemType*<br/>
O tipo de elemento de interface do usuário; um de AFX_UI_ELEMTYPE_NORMAL, AFX_UI_ELEMTYPE_CHECKBOX ou AFX_UI_ELEMTYPE_RADIO.

### <a name="example"></a>Exemplo

Consulte [HTMLEditar amostra](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="dhtmlediting_cmd_entry_func_type"></a><a name="dhtmlediting_cmd_entry_func_type"></a>DHTMLEDITING_CMD_ENTRY_FUNC_TYPE

Mapeie um ID de comando para um comando de edição HTML, manipulador de mensagens e elemento de interface do usuário.

```
DHTMLEDITING_CMD_ENTRY_FUNC_TYPE(cmdID, dhtmlcmdID, member_func_name,  elemType)
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O iD de comando (como ID_EDIT_COPY).

*dhtmlcmdID*<br/>
O comando de edição HTML para o qual *o cmdID* mapeia (como IDM_COPY).

*member_func_name*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

*elemType*<br/>
O tipo de elemento de interface do usuário; um de AFX_UI_ELEMTYPE_NORMAL, AFX_UI_ELEMTYPE_CHECKBOX ou AFX_UI_ELEMTYPE_RADIO.

### <a name="example"></a>Exemplo

Consulte [HTMLEditar amostra](../../overview/visual-cpp-samples.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxhtml.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

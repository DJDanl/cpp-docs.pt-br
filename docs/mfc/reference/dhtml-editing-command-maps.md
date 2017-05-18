---
title: "Mapas de comando de edição DHTML | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: c1b49876-039e-4a26-bb24-ea98ccf254a1
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 89aa66d3a1e85183baaba21f001b60e080895f7f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="dhtml-editing-command-maps"></a>Mapas de comando de edição DHTML
As macros a seguir podem ser usadas para mapear comandos de edição DHTML [CHtmlEditView](../../mfc/reference/chtmleditview-class.md)-classes derivadas. Para obter um exemplo de uso, consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  
  
### <a name="dhtml-editing-command-map-macros"></a>Macros de mapa de comando de edição DHTML  
  
|||  
|-|-|  
|[DECLARE_DHTMLEDITING_CMDMAP](#declare_dhtmlediting_cmdmap)|Declara um mapa de comando de edição do DHTML em uma classe.|  
|[BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap)|Inicia a definição de um mapa de comando de edição do DHTML dentro de uma classe.|  
|[END_DHTMLEDITING_CMDMAP](#end_dhtmlediting_cmdmap)|Marca o fim de um mapa de comando de edição DHTML.|  
|[DHTMLEDITING_CMD_ENTRY](#dhtmlediting_cmd_entry)|Mapeia uma ID de comando para um comando de edição de HTML.|  
|[DHTMLEDITING_CMD_ENTRY_FUNC](#dhtmlediting_cmd_entry_func)|Mapeia uma ID de comando para um comando de edição de HTML e o manipulador de mensagens.|  
|[DHTMLEDITING_CMD_ENTRY_TYPE](#dhtmlediting_cmd_entry_type)|Mapeia uma ID de comando para um comando de edição de HTML e o elemento de interface do usuário.|  
|[DHTMLEDITING_CMD_ENTRY_FUNC_TYPE](#dhtmlediting_cmd_entry_func_type)|Mapeia uma ID de comando para um comando, o manipulador de mensagens e o elemento de interface do usuário de edição de HTML.|  
  
##  <a name="declare_dhtmlediting_cmdmap"></a>DECLARE_DHTMLEDITING_CMDMAP  
 Declara um mapa de comando de edição do DHTML em uma classe.  
  
```  
DECLARE_DHTMLEDITING_CMDMAP(className)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe.  
  
### <a name="remarks"></a>Comentários  
 Essa macro deve ser usada na definição de [CHtmlEditView](../../mfc/reference/chtmleditview-class.md)-classes derivadas.  
  
 Use [BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap) para implementar o mapa.  
  
### <a name="example"></a>Exemplo  
 Consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
  
##  <a name="begin_dhtmlediting_cmdmap"></a>BEGIN_DHTMLEDITING_CMDMAP  
 Inicia a definição de um mapa de comando de edição do DHTML dentro de uma classe.  
  
```  
BEGIN_DHTMLEDITING_CMDMAP(className)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `className`  
 O nome da classe que contém o mapa de comando de edição DHTML. Essa classe deve derivar diretamente ou indiretamente de [CHtmlEditView](../../mfc/reference/chtmleditview-class.md) e incluem o [DECLARE_DHTMLEDITING_CMDMAP](#declare_dhtmlediting_cmdmap) macro dentro de sua definição de classe.  
  
### <a name="remarks"></a>Comentários  
 Adicione um mapa de comando de edição DHTML à sua classe para mapear comandos de interface do usuário para comandos de edição de HTML.  
  
 Local de `BEGIN_DHTMLEDITING_CMDMAP` seguido de macro no arquivo de implementação (. cpp) da classe [DHTMLEDITING_CMD_ENTRY](#dhtmlediting_cmd_entry) macros para os comandos que a classe é mapear (por exemplo, de **ID_EDIT_CUT** para **IDM_CUT**). Use o [END_DHTMLEDITING_CMDMAP](#end_dhtmlediting_cmdmap) macro para marcar o fim do mapa de evento.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
  
##  <a name="end_dhtmlediting_cmdmap"></a>END_DHTMLEDITING_CMDMAP  
 Marca o fim de um mapa de comando de edição DHTML.  
  
```  
END_DHTMLEDITING_CMDMAP()   
```  
  
### <a name="remarks"></a>Comentários  
 Uso em conjunto com [BEGIN_DHTMLEDITING_CMDMAP](#begin_dhtmlediting_cmdmap).  
  
### <a name="example"></a>Exemplo  
 Consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
  
##  <a name="dhtmlediting_cmd_entry"></a>DHTMLEDITING_CMD_ENTRY  
 Mapeia uma ID de comando para um comando de edição de HTML.  
  
```  
DHTMLEDITING_CMD_ENTRY(cmdID,  dhtmlcmdID)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID de comando (como **ID_EDIT_COPY**).  
  
 `dhtmlcmdID`  
 O comando para o qual de edição de HTML `cmdID` mapeia (como **IDM_COPY**).  
  
### <a name="example"></a>Exemplo  
 Consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
  
##  <a name="dhtmlediting_cmd_entry_func"></a>DHTMLEDITING_CMD_ENTRY_FUNC  
 Mapeia uma ID de comando para um comando de edição de HTML e o manipulador de mensagens.  
  
```  
DHTMLEDITING_CMD_ENTRY_FUNC(cmdID, dhtmlcmdID,  member_func_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID de comando (como **ID_EDIT_COPY**).  
  
 `dhtmlcmdID`  
 O comando para o qual de edição de HTML `cmdID` mapeia (como **IDM_COPY**).  
  
 `member_func_name`  
 O nome da função de manipulador de mensagens para o qual o comando é mapeado.  
  
### <a name="example"></a>Exemplo  
 Consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
  
##  <a name="dhtmlediting_cmd_entry_type"></a>DHTMLEDITING_CMD_ENTRY_TYPE  
 Mapeia uma ID de comando para um comando de edição de HTML e o elemento de interface do usuário.  
  
```  
DHTMLEDITING_CMD_ENTRY_TYPE(cmdID  ,   dhtmlcmdID  ,    elemType)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID de comando (como **ID_EDIT_COPY**).  
  
 `dhtmlcmdID`  
 O comando para o qual de edição de HTML `cmdID` mapeia (como **IDM_COPY**).  
  
 `elemType`  
 O tipo de elemento de interface do usuário; uma das **AFX_UI_ELEMTYPE_NORMAL**, **AFX_UI_ELEMTYPE_CHECKBOX**, ou **AFX_UI_ELEMTYPE_RADIO**.  
  
### <a name="example"></a>Exemplo  
 Consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
  
##  <a name="dhtmlediting_cmd_entry_func_type"></a>DHTMLEDITING_CMD_ENTRY_FUNC_TYPE  
 Mapeia uma ID de comando para um comando, o manipulador de mensagens e o elemento de interface do usuário de edição de HTML.  
  
```  
DHTMLEDITING_CMD_ENTRY_FUNC_TYPE(cmdID, dhtmlcmdID, member_func_name,  elemType)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID de comando (como **ID_EDIT_COPY**).  
  
 `dhtmlcmdID`  
 O comando para o qual de edição de HTML `cmdID` mapeia (como **IDM_COPY**).  
  
 `member_func_name`  
 O nome da função de manipulador de mensagens para o qual o comando é mapeado.  
  
 `elemType`  
 O tipo de elemento de interface do usuário; uma das **AFX_UI_ELEMTYPE_NORMAL**, **AFX_UI_ELEMTYPE_CHECKBOX**, ou **AFX_UI_ELEMTYPE_RADIO**.  
  
### <a name="example"></a>Exemplo  
 Consulte [HTMLEdit exemplo](../../visual-cpp-samples.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxhtml.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)


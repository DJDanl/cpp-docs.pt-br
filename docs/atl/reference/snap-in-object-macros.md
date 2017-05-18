---
title: Snap-In do objeto Macros | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 4e9850c0-e395-4929-86c9-584a81828053
caps.latest.revision: 16
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 13823feb06e7fecb2e81a01f3c88e3664de01d30
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="snap-in-object-macros"></a>Macros de Snap-In do objeto
Essas macros fornecem suporte para extensões de snap-in.  
  
|||  
|-|-|  
|[BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map)|Marca o início do mapa de classe de extensão de snap-in dados para um objeto de Snap-In.|  
|[BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map)|Marca o início do mapa para um objeto de Snap-In da barra de ferramentas.|  
|[END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map)|Marca o fim do mapa de classe de extensão de snap-in dados para um objeto de Snap-In.|  
|[END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map)|Marca o fim do mapa da barra de ferramentas para um objeto de Snap-In.|  
|[EXTENSION_SNAPIN_DATACLASS](#extension_snapin_dataclass)|Cria um membro de dados para a classe de dados da extensão do snap-in.|  
|[EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry)|Insere o mapa de classe de dados de extensão do snap-in do objeto Snap-In de uma classe de snap-in de extensão de dados.|  
|[SNAPINMENUID](#snapinmenuid)|Declara a ID do menu de contexto usado pelo objeto de Snap-In.|  
|[SNAPINTOOLBARID_ENTRY](#snapintoolbarid_entry)|Insere uma barra de ferramentas para o mapa de barra de ferramentas do Snap-In do objeto.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsnap.h 
   
##  <a name="begin_extension_snapin_nodeinfo_map"></a>BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP  
 Marca o início do mapa de classe de extensão de snap-in de dados.  
  
```
BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname)
```  
  
### <a name="parameters"></a>Parâmetros  
 *nome da classe*  
 [in] O nome da classe de extensão de snap-in de dados.  
  
### <a name="remarks"></a>Comentários  
 Inicie seu mapa de extensão do snap-in com a `BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP` macro, adicione entradas para cada um dos seus tipos de dados de snap-in de extensão com o [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) macro e conclua o mapa com o [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) macro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#105;](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]  
  
##  <a name="begin_snapintoolbarid_map"></a>BEGIN_SNAPINTOOLBARID_MAP  
 Declara o início do mapa de ID de barra de ferramentas para o objeto de Snap-In.  
  
```
BEGIN_SNAPINTOOLBARID_MAP(_class)
```  
  
### <a name="parameters"></a>Parâmetros  
 `_class`  
 [in] Especifica a classe de objeto Snap-In.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#106;](../../atl/codesnippet/cpp/snap-in-object-macros_2.h)]  
  
##  <a name="end_extension_snapin_nodeinfo_map"></a>END_EXTENSION_SNAPIN_NODEINFO_MAP  
 Marca o fim do mapa de classe de extensão de snap-in de dados.  
  
```
END_EXTENSION_SNAPIN_NODEINFO_MAP()
```  
  
### <a name="remarks"></a>Comentários  
 Inicie seu mapa de extensão do snap-in com a [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) macro, adicione entradas para cada um dos seus tipos de dados de snap-in de extensão com o [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) macro e conclua o mapa com o `END_EXTENSION_SNAPIN_NODEINFO_MAP` macro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).  
  
##  <a name="end_snapintoolbarid_map"></a>END_SNAPINTOOLBARID_MAP  
 Declara o fim do mapa de ID de barra de ferramentas para o objeto de Snap-In.  
  
```
END_SNAPINTOOLBARID_MAP( _class )
```  
  
### <a name="parameters"></a>Parâmetros  
 `_class`  
 [in] Especifica a classe de objeto Snap-In.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).  
  
##  <a name="extension_snapin_dataclass"></a>EXTENSION_SNAPIN_DATACLASS  
 Adiciona um membro de dados para a classe de dados de extensão do snap-in para um **ISnapInItemImpl**-classe derivada.  
  
```
EXTENSION_SNAPIN_DATACLASS(dataClass )
```  
  
### <a name="parameters"></a>Parâmetros  
 `dataClass`  
 [in] A classe de dados da extensão do snap-in.  
  
### <a name="remarks"></a>Comentários  
 Essa classe também deve ser inserida em um mapa de classe de dados de extensão do snap-in. Inicie seu mapa de classe de dados de snap-in de extensão com o [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) macro, adicione entradas para cada um dos seus tipos de dados de snap-in de extensão com o [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) macro e conclua o mapa com o [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) macro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#105;](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]  
  
##  <a name="extension_snapin_nodeinfo_entry"></a>EXTENSION_SNAPIN_NODEINFO_ENTRY  
 Adiciona uma classe de dados de extensão do snap-in para o mapa de classe de dados de extensão do snap-in.  
  
```
EXTENSION_SNAPIN_NODEINFO_ENTRY( dataClass )
```  
  
### <a name="parameters"></a>Parâmetros  
 `dataClass`  
 [in] A classe de dados da extensão do snap-in.  
  
### <a name="remarks"></a>Comentários  
 Inicie seu mapa de classe de dados de snap-in de extensão com o [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) macro, adicione entradas para cada um dos seus tipos de dados de snap-in de extensão com o `EXTENSION_SNAPIN_NODEINFO_ENTRY` macro e conclua o mapa com o [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) macro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).  
  
##  <a name="snapinmenuid"></a>SNAPINMENUID  
 Use essa macro para declarar o recurso do menu de contexto do objeto Snap-In.  
  
```
SNAPINMENUID( id )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Identifica o menu de contexto do objeto Snap-In.  
  
##  <a name="snapintoolbarid_entry"></a>SNAPINTOOLBARID_ENTRY  
 Use essa macro para inserir uma ID de barra de ferramentas no mapa do ID do objeto Snap-In da barra de ferramentas.  
  
```
SNAPINTOOLBARID_ENTRY( id )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Identifica o controle de barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 O [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map) macro marca o início do mapa de ID da barra de ferramentas; o [END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map) macro marca o fim.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)


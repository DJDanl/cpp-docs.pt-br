---
title: Macros de categoria | Documentos do Microsoft
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
ms.assetid: 223578cb-6180-4787-a8d8-ba3787a5d3ee
caps.latest.revision: 17
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
ms.openlocfilehash: 26eea5cc8ce8e18af84a9ca89e5ddc94272be44c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="category-macros"></a>Macros de categoria
Essas macros definem mapas de categoria.  
  
|||  
|-|-|  
|[BEGIN_CATEGORY_MAP](#begin_category_map)|Marca o início do mapa de categoria.|  
|[END_CATEGORY_MAP](#end_category_map)|Marca o fim do mapa de categoria.|  
|[IMPLEMENTED_CATEGORY](#implemented_category)|Indica as categorias que são implementadas pelo objeto COM.|  
|[REQUIRED_CATEGORY](#required_category)|Indica as categorias que são necessárias do contêiner pelo objeto COM.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  

##  <a name="begin_category_map"></a>BEGIN_CATEGORY_MAP  
 Marca o início do mapa de categoria.  
  
```
BEGIN_CATEGORY_MAP(theClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 [in] O nome da classe que contém o mapa de categoria.  
  
### <a name="remarks"></a>Comentários  
 O mapa de categoria é usado para especificar quais categorias de componente implementará a classe COM e as categorias que ela exige de seu contêiner.  
  
 Adicionar uma [IMPLEMENTED_CATEGORY](#implemented_category) entrada no mapa para cada categoria implementada pela classe COM. Adicionar uma [REQUIRED_CATEGORY](#required_category) entrada no mapa para cada categoria que exige que seus clientes implementar a classe. Marcar o fim do mapa com o [END_CATEGORY_MAP](#end_category_map) macro.  
  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo é registrado, se a classe possui um tipo de [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto).  
  
> [!NOTE]
>  ATL usa o Gerenciador de categorias de componente padrão para registrar categorias de componente. Se o Gerenciador não está presente no sistema quando o módulo é registrado, o registro terá êxito, mas as categorias de componente não serão registradas para a classe.  
  
 Para obter mais informações sobre categorias de componente, consulte [quais são as categorias de componente e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#100;](../../atl/codesnippet/cpp/category-macros_1.h)]  
  
##  <a name="end_category_map"></a>END_CATEGORY_MAP  
 Marca o fim do mapa de categoria.  
  
```
END_CATEGORY_MAP()
```  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_CATEGORY_MAP](#begin_category_map).  
  
##  <a name="implemented_category"></a>IMPLEMENTED_CATEGORY  
 Adicionar uma `IMPLEMENTED_CATEGORY` macro para seu componente [mapa categoria](#begin_category_map) para especificar que ele deve ser registrado como implementar a categoria identificada pelo `catID` parâmetro.  
  
```
IMPLEMENTED_CATEGORY(catID)
```  
  
### <a name="parameters"></a>Parâmetros  
 `catID`  
 [in] A **CATID** constante ou variável que contém o identificador global exclusivo (GUID) para a categoria implementada. O endereço de `catID` será executada e adicionado ao mapa. Consulte a tabela abaixo para obter uma seleção de categorias de estoque.  
  
### <a name="remarks"></a>Comentários  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo é registrado, se a classe possui um tipo de [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.  
  
 Clientes podem usar as informações de categoria registradas para a classe para determinar seus requisitos e recursos sem precisar criar uma instância dela.  
  
 Para obter mais informações sobre categorias de componente, consulte [quais são as categorias de componente e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque  
  
|Descrição|Símbolo|GUID do registro|  
|-----------------|------------|-------------------|  
|Seguro para execução de scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|  
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|  
|Quadro simples contenção de Site|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|  
|Ligação de dados avançada|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|  
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|  
|Objetos com reconhecimento de Internet|Consulte [objetos ciente da Internet](http://msdn.microsoft.com/library/windows/desktop/ms690561) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de exemplo.||  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#100;](../../atl/codesnippet/cpp/category-macros_1.h)]  
  
##  <a name="required_category"></a>REQUIRED_CATEGORY  
 Adicionar uma `REQUIRED_CATEGORY` macro para seu componente [mapa categoria](#begin_category_map) para especificar que ele deve ser registrado como exigir que a categoria identificada pelo `catID` parâmetro.  
  
```
REQUIRED_CATEGORY( catID )
```  
  
### <a name="parameters"></a>Parâmetros  
 `catID`  
 [in] A **CATID** constante ou variável que contém o identificador global exclusivo (GUID) para a categoria desejada. O endereço de `catID` será executada e adicionado ao mapa. Consulte a tabela abaixo para obter uma seleção de categorias de estoque.  
  
### <a name="remarks"></a>Comentários  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo é registrado, se a classe possui um tipo de [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.  
  
 Clientes podem usar as informações de categoria registradas para a classe para determinar seus requisitos e recursos sem precisar criar uma instância dela. Por exemplo, um controle pode exigir que um contêiner suportam vinculação de dados. O contêiner pode descobrir se ele tem os recursos necessários para hospedar o controle, consultando o Gerenciador de categoria para as categorias exigidas pelo controle. Se o contêiner não dá suporte a um recurso necessário, ele pode recusar hospedar o objeto COM.  
  
 Para obter mais informações sobre categorias de componente, incluindo uma lista de exemplos, consulte [quais são as categorias de componente e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque  
  
|Descrição|Símbolo|GUID do registro|  
|-----------------|------------|-------------------|  
|Seguro para execução de scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|  
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|  
|Quadro simples contenção de Site|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|  
|Ligação de dados avançada|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|  
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|  
|Objetos com reconhecimento de Internet|Consulte [objetos ciente da Internet](http://msdn.microsoft.com/library/windows/desktop/ms690561) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de exemplo.||  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#135;](../../atl/codesnippet/cpp/category-macros_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)


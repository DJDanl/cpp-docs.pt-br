---
title: Macros de categoria | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlGetHexValue
- atlbase/ATL::AtlGetVersion
- atlenc/ATL::AtlHexDecode
- atlenc/ATL::AtlHexDecodeGetRequiredLength
- atlenc/ATL::AtlHexEncode
- atlenc/ATL::AtlHexEncodeGetRequiredLength
- atlenc/ATL::AtlHexValue
- atlenc/ATL::BEncode
- atlenc/ATL::BEncodeGetRequiredLength
- atlenc/ATL::EscapeXML
- atlenc/ATL::GetExtendedChars
- atlenc/ATL::IsExtendedChar
- atlenc/ATL::QEncode
- atlenc/ATL::QEncodeGetRequiredLength
- atlenc/ATL::QPDecode
- atlenc/ATL::QPDecodeGetRequiredLength
- atlenc/ATL::QPEncode
- atlenc/ATL::QPEncodeGetRequiredLength
- atlenc/ATL::UUDecode
- atlenc/ATL::UUDecodeGetRequiredLength
- atlenc/ATL::UUEncode
- atlenc/ATL::UUEncodeGetRequiredLength
dev_langs:
- C++
ms.assetid: 223578cb-6180-4787-a8d8-ba3787a5d3ee
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 752a0c0c9de5c726a106ca08a574844369c6bdc5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="category-macros"></a>Macros de categoria
Essas macros definem mapeamentos de categoria.  
  
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
 O mapa de categoria é usado para especificar quais categorias de componente implementa a classe COM e quais categorias requer do seu contêiner.  
  
 Adicionar uma [IMPLEMENTED_CATEGORY](#implemented_category) entrada no mapa para cada categoria implementada pela classe COM. Adicionar um [REQUIRED_CATEGORY](#required_category) entrada no mapa para cada categoria que exige que seus clientes implementar a classe. Marcar o fim do mapa com o [END_CATEGORY_MAP](#end_category_map) macro.  
  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo está registrado, se a classe tiver um tipo de [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) .  
  
> [!NOTE]
>  ATL usa o Gerenciador de categorias de componentes padrão para registrar as categorias de componentes. Se o Gerenciador não está presente no sistema quando o módulo está registrado, o registro terá êxito, mas as categorias de componente não serão registradas para essa classe.  
  
 Para obter mais informações sobre categorias de componentes, consulte [quais são as categorias de componentes e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]  
  
##  <a name="end_category_map"></a>END_CATEGORY_MAP  
 Marca o fim do mapa de categoria.  
  
```
END_CATEGORY_MAP()
```  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [BEGIN_CATEGORY_MAP](#begin_category_map).  
  
##  <a name="implemented_category"></a>IMPLEMENTED_CATEGORY  
 Adicionar uma `IMPLEMENTED_CATEGORY` macro para o seu componente [mapa de categoria](#begin_category_map) para especificar que ele deve ser registrado como implementar a categoria identificada pelo `catID` parâmetro.  
  
```
IMPLEMENTED_CATEGORY(catID)
```  
  
### <a name="parameters"></a>Parâmetros  
 `catID`  
 [in] Um **CATID** constante ou variável que contém o identificador global exclusivo (GUID) para a categoria implementada. O endereço de `catID` será realizada e adicionado ao mapa. Consulte a tabela abaixo para uma seleção de categorias de estoque.  
  
### <a name="remarks"></a>Comentários  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo está registrado, se a classe tiver um tipo de [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.  
  
 Os clientes podem usar as informações de categoria registradas para a classe para determinar seus requisitos e recursos sem a necessidade de criar uma instância dele.  
  
 Para obter mais informações sobre categorias de componentes, consulte [quais são as categorias de componentes e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no SDK do Windows.  
  
### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque  
  
|Descrição|Símbolo|GUID de registro|  
|-----------------|------------|-------------------|  
|Seguro para script|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|  
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|  
|Contenção de Site do quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados avançados|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|  
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|  
|Objetos com reconhecimento de Internet|Consulte [objetos com reconhecimento de Internet](http://msdn.microsoft.com/library/windows/desktop/ms690561) no SDK do Windows para obter uma lista de exemplo.||  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]  
  
##  <a name="required_category"></a>REQUIRED_CATEGORY  
 Adicionar um `REQUIRED_CATEGORY` macro para o seu componente [mapa de categoria](#begin_category_map) para especificar que ele deve ser registrado como exigir a categoria identificada pelo `catID` parâmetro.  
  
```
REQUIRED_CATEGORY( catID )
```  
  
### <a name="parameters"></a>Parâmetros  
 `catID`  
 [in] Um **CATID** constante ou variável que contém o identificador global exclusivo (GUID) para a categoria obrigatória. O endereço de `catID` será realizada e adicionado ao mapa. Consulte a tabela abaixo para uma seleção de categorias de estoque.  
  
### <a name="remarks"></a>Comentários  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo está registrado, se a classe tiver um tipo de [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.  
  
 Os clientes podem usar as informações de categoria registradas para a classe para determinar seus requisitos e recursos sem a necessidade de criar uma instância dele. Por exemplo, um controle pode exigir que um contêiner oferecem suporte à associação de dados. O contêiner pode descobrir se ele tem os recursos necessários para hospedar o controle consultando o Gerenciador de categoria para as categorias exigido pelo controle. Se o contêiner não oferece suporte a um recurso necessário, ele poderá recusar hospedar o objeto COM.  
  
 Para obter mais informações sobre categorias de componentes, incluindo uma lista de exemplos, consulte [quais são as categorias de componentes e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no SDK do Windows.  
  
### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque  
  
|Descrição|Símbolo|GUID de registro|  
|-----------------|------------|-------------------|  
|Seguro para script|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|  
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|  
|Contenção de Site do quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados avançados|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|  
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|  
|Objetos com reconhecimento de Internet|Consulte [objetos com reconhecimento de Internet](http://msdn.microsoft.com/library/windows/desktop/ms690561) no SDK do Windows para obter uma lista de exemplo.||  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#135](../../atl/codesnippet/cpp/category-macros_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

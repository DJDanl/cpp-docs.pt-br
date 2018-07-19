---
title: Macros de categoria | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f1fff338bfce32f8233cd58aa7c0790508ce542c
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882869"
---
# <a name="category-macros"></a>Macros de categoria
Essas macros definem os mapas de categoria.  
  
|||  
|-|-|  
|[BEGIN_CATEGORY_MAP](#begin_category_map)|Marca o início do mapa de categoria.|  
|[END_CATEGORY_MAP](#end_category_map)|Marca o fim do mapa de categoria.|  
|[IMPLEMENTED_CATEGORY](#implemented_category)|Indica as categorias que são implementadas pelo objeto COM.|  
|[REQUIRED_CATEGORY](#required_category)|Indica as categorias que são necessárias para o contêiner pelo objeto COM.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  

##  <a name="begin_category_map"></a>  BEGIN_CATEGORY_MAP  
 Marca o início do mapa de categoria.  
  
```
BEGIN_CATEGORY_MAP(theClass)
```  
  
### <a name="parameters"></a>Parâmetros  
 *theClass*  
 [in] O nome da classe que contém o mapa de categoria.  
  
### <a name="remarks"></a>Comentários  
 O mapa de categoria é usado para especificar quais categorias de componente que implementará a classe COM, além de quais categorias de seu contêiner.  
  
 Adicionar um [IMPLEMENTED_CATEGORY](#implemented_category) entrada no mapa para cada categoria implementada pela classe COM. Adicionar um [REQUIRED_CATEGORY](#required_category) entrada no mapa para cada categoria que exige que seus clientes implementar a classe. Marcar o final do mapa com o [END_CATEGORY_MAP](#end_category_map) macro.  
  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo é registrado, se a classe tiver um associado [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) .  
  
> [!NOTE]
>  ATL usa o Gerenciador de categorias de componentes padrão para registrar as categorias de componentes. Se o Gerenciador não está presente no sistema quando o módulo é registrado, o registro terá êxito, mas as categorias de componente não serão registradas para essa classe.  
  
 Para obter mais informações sobre categorias de componentes, consulte [quais são as categorias de componentes e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]  
  
##  <a name="end_category_map"></a>  END_CATEGORY_MAP  
 Marca o fim do mapa de categoria.  
  
```
END_CATEGORY_MAP()
```  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [BEGIN_CATEGORY_MAP](#begin_category_map).  
  
##  <a name="implemented_category"></a>  IMPLEMENTED_CATEGORY  
 Adicionar uma macro IMPLEMENTED_CATEGORY para o seu componente [mapa de categoria](#begin_category_map) para especificar que deve ser registrado como implementar a categoria identificada pela *catID* parâmetro.  
  
```
IMPLEMENTED_CATEGORY(catID)
```  
  
### <a name="parameters"></a>Parâmetros  
 *catID*  
 [in] Uma constante CATID ou variável que contém o identificador global exclusivo (GUID) para a categoria de implementado. O endereço do *catID* serão tomadas e adicionada ao mapa. Consulte a tabela abaixo para uma seleção de categorias de estoque.  
  
### <a name="remarks"></a>Comentários  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo é registrado, se a classe tiver um associado [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.  
  
 Clientes podem usar as informações de categoria registradas para a classe para determinar seus requisitos e recursos sem ter de criar uma instância dele.  
  
 Para obter mais informações sobre categorias de componentes, consulte [quais são as categorias de componentes e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no SDK do Windows.  
  
### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque  
  
|Descrição|Símbolo|GUID de registro|  
|-----------------|------------|-------------------|  
|Seguro para execução de scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|  
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|  
|Confinamento de Site do quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|  
|Ligação de dados avançada|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|  
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|  
|Objetos com suporte a Internet|Ver [objetos ciente da Internet](http://msdn.microsoft.com/library/windows/desktop/ms690561) no SDK do Windows para obter uma lista de exemplo.||  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]  
  
##  <a name="required_category"></a>  REQUIRED_CATEGORY  
 Adicionar uma macro REQUIRED_CATEGORY para o seu componente [mapa de categoria](#begin_category_map) para especificar que deve ser registrado como exigindo a categoria identificada pela *catID* parâmetro.  
  
```
REQUIRED_CATEGORY( catID )
```  
  
### <a name="parameters"></a>Parâmetros  
 *catID*  
 [in] Uma constante CATID ou variável que contém o identificador global exclusivo (GUID) para a categoria desejada. O endereço do *catID* serão tomadas e adicionada ao mapa. Consulte a tabela abaixo para uma seleção de categorias de estoque.  
  
### <a name="remarks"></a>Comentários  
 As categorias de componente listadas no mapa serão registradas automaticamente quando o módulo é registrado, se a classe tiver um associado [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.  
  
 Clientes podem usar as informações de categoria registradas para a classe para determinar seus requisitos e recursos sem ter de criar uma instância dele. Por exemplo, um controle pode exigir que um contêiner dão suporte à vinculação de dados. O contêiner pode descobrir se ele tem os recursos necessários para hospedar o controle consultando o Gerenciador de categoria para as categorias necessários para esse controle. Se o contêiner não dá suporte a um recurso necessário, ele poderá recusar hospedar o objeto COM.  
  
 Para obter mais informações sobre categorias de componentes, incluindo uma lista de exemplos, consulte [quais são as categorias de componentes e como elas funcionam](http://msdn.microsoft.com/library/windows/desktop/ms694322) no SDK do Windows.  
  
### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque  
  
|Descrição|Símbolo|GUID de registro|  
|-----------------|------------|-------------------|  
|Seguro para execução de scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|  
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|  
|Confinamento de Site do quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|  
|Associação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|  
|Ligação de dados avançada|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|  
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|  
|Objetos com suporte a Internet|Ver [objetos ciente da Internet](http://msdn.microsoft.com/library/windows/desktop/ms690561) no SDK do Windows para obter uma lista de exemplo.||  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#135](../../atl/codesnippet/cpp/category-macros_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

---
title: Macros de categoria
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_CATEGORY_MAP
- atlcom/ATL::END_CATEGORY_MAP
- atlcom/ATL::IMPLEMENTED_CATEGORY
- atlcom/ATL::REQUIRED_CATEGORY
ms.assetid: 223578cb-6180-4787-a8d8-ba3787a5d3ee
ms.openlocfilehash: 411e06cc795827eef356018ba427510fd9eb7c06
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418128"
---
# <a name="category-macros"></a>Macros de categoria

Essas macros definem mapas de categorias.

|||
|-|-|
|[BEGIN_CATEGORY_MAP](#begin_category_map)|Marca o início do mapa de categoria.|
|[END_CATEGORY_MAP](#end_category_map)|Marca o final do mapa de categoria.|
|[IMPLEMENTED_CATEGORY](#implemented_category)|Indica as categorias implementadas pelo objeto COM.|
|[REQUIRED_CATEGORY](#required_category)|Indica as categorias que são necessárias para o contêiner pelo objeto COM.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="begin_category_map"></a>BEGIN_CATEGORY_MAP

Marca o início do mapa de categoria.

```
BEGIN_CATEGORY_MAP(theClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
no O nome da classe que contém o mapa de categoria.

### <a name="remarks"></a>Comentários

O mapa de categoria é usado para especificar quais categorias de componentes a classe COM implementará e quais categorias serão exigidas de seu contêiner.

Adicione uma entrada de [IMPLEMENTED_CATEGORY](#implemented_category) ao mapa para cada categoria implementada pela classe com. Adicione uma entrada de [REQUIRED_CATEGORY](#required_category) ao mapa para cada categoria que a classe exige que seus clientes implementem. Marque o final do mapa com a macro [END_CATEGORY_MAP](#end_category_map) .

As categorias de componentes listadas no mapa serão registradas automaticamente quando o módulo for registrado se a classe tiver um [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto)associados.

> [!NOTE]
>  A ATL usa o Gerenciador de categorias de componentes padrão para registrar categorias de componentes. Se o Gerenciador não estiver presente no sistema quando o módulo estiver registrado, o registro terá sucesso, mas as categorias de componentes não serão registradas para essa classe.

Para obter mais informações sobre categorias de componentes, consulte [o que são categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work) na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]

##  <a name="end_category_map"></a>END_CATEGORY_MAP

Marca o final do mapa de categoria.

```
END_CATEGORY_MAP()
```

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_CATEGORY_MAP](#begin_category_map).

##  <a name="implemented_category"></a>IMPLEMENTED_CATEGORY

Adicione uma macro IMPLEMENTED_CATEGORY ao [mapa de categoria](#begin_category_map) do componente para especificar que ele deve ser registrado como implementando a categoria identificada pelo parâmetro *CATID* .

```
IMPLEMENTED_CATEGORY(catID)
```

### <a name="parameters"></a>parâmetros

*catID*<br/>
no Uma constante de CATID ou variável que contém o GUID (identificador global exclusivo) da categoria implementada. O endereço do *CATID* será obtido e adicionado ao mapa. Consulte a tabela abaixo para obter uma seleção de categorias de estoque.

### <a name="remarks"></a>Comentários

As categorias de componentes listadas no mapa serão registradas automaticamente quando o módulo for registrado se a classe tiver uma macro [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) associada.

Os clientes podem usar as informações de categoria registradas para a classe para determinar seus recursos e requisitos sem precisar criar uma instância dela.

Para obter mais informações sobre categorias de componentes, consulte [o que são categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work) na SDK do Windows.

### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque

|DESCRIÇÃO|Símbolo|GUID do registro|
|-----------------|------------|-------------------|
|Seguro para scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|
|Confinamento de site de quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|
|Vinculação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|
|Ligação de dados avançada|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|
|Objetos com reconhecimento de Internet|Consulte [objetos com reconhecimento da Internet](/windows/win32/com/internet-aware-objects) no SDK do Windows para obter uma lista de exemplos.||

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]

##  <a name="required_category"></a>REQUIRED_CATEGORY

Adicione uma macro REQUIRED_CATEGORY ao [mapa de categoria](#begin_category_map) do componente para especificar que ele deve ser registrado como exigindo a categoria identificada pelo parâmetro *CATID* .

```
REQUIRED_CATEGORY( catID )
```

### <a name="parameters"></a>parâmetros

*catID*<br/>
no Uma constante de CATID ou variável que contém o GUID (identificador global exclusivo) da categoria necessária. O endereço do *CATID* será obtido e adicionado ao mapa. Consulte a tabela abaixo para obter uma seleção de categorias de estoque.

### <a name="remarks"></a>Comentários

As categorias de componentes listadas no mapa serão registradas automaticamente quando o módulo for registrado se a classe tiver uma macro [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) associada.

Os clientes podem usar as informações de categoria registradas para a classe para determinar seus recursos e requisitos sem precisar criar uma instância dela. Por exemplo, um controle pode exigir que um contêiner dê suporte à associação de dados. O contêiner pode descobrir se ele tem os recursos necessários para hospedar o controle consultando o gerente de categoria para as categorias exigidas por esse controle. Se o contêiner não oferecer suporte a um recurso necessário, ele poderá se recusar a hospedar o objeto COM.

Para obter mais informações sobre categorias de componentes, incluindo uma lista de exemplo, consulte [o que são categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work) na SDK do Windows.

### <a name="a-selection-of-stock-categories"></a>Uma seleção de categorias de estoque

|DESCRIÇÃO|Símbolo|GUID do registro|
|-----------------|------------|-------------------|
|Seguro para scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|
|Confinamento de site de quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|
|Vinculação de dados simples|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|
|Ligação de dados avançada|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|
|Objetos com reconhecimento de Internet|Consulte [objetos com reconhecimento da Internet](/windows/win32/com/internet-aware-objects) no SDK do Windows para obter uma lista de exemplos.||

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#135](../../atl/codesnippet/cpp/category-macros_2.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)

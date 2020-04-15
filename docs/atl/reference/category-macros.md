---
title: Categorias Macros
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_CATEGORY_MAP
- atlcom/ATL::END_CATEGORY_MAP
- atlcom/ATL::IMPLEMENTED_CATEGORY
- atlcom/ATL::REQUIRED_CATEGORY
ms.assetid: 223578cb-6180-4787-a8d8-ba3787a5d3ee
ms.openlocfilehash: 1d8bbae4608aa661bbc612604f7d85855f325f5f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321591"
---
# <a name="category-macros"></a>Categorias Macros

Essas macros definem mapas de categoria.

|||
|-|-|
|[BEGIN_CATEGORY_MAP](#begin_category_map)|Marca o início do mapa da categoria.|
|[END_CATEGORY_MAP](#end_category_map)|Marca o fim do mapa da categoria.|
|[Implemented_category](#implemented_category)|Indica categorias que são implementadas pelo objeto COM.|
|[REQUIRED_CATEGORY](#required_category)|Indica as categorias exigidas do contêiner pelo objeto COM.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="begin_category_map"></a><a name="begin_category_map"></a>BEGIN_CATEGORY_MAP

Marca o início do mapa da categoria.

```
BEGIN_CATEGORY_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
[em] O nome da classe que contém o mapa da categoria.

### <a name="remarks"></a>Comentários

O mapa de categorias é usado para especificar quais categorias de componentes a classe COM implementará e quais categorias ela exige de seu contêiner.

Adicione uma [entrada IMPLEMENTED_CATEGORY](#implemented_category) no mapa para cada categoria implementada pela classe COM. Adicione uma [entrada REQUIRED_CATEGORY](#required_category) ao mapa para cada categoria que a classe exige que seus clientes implementem. Marque o final do mapa com a [END_CATEGORY_MAP](#end_category_map) macro.

As categorias de componentes listadas no mapa serão registradas automaticamente quando o módulo for registrado se a classe tiver [um OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO associados](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto).

> [!NOTE]
> A ATL usa o gerenciador de categorias de componentes padrão para registrar categorias de componentes. Se o gerente não estiver presente no sistema quando o módulo estiver registrado, o registro será bem sucedido, mas as categorias de componentes não serão registradas para essa classe.

Para obter mais informações sobre categorias de componentes, consulte [quais são as categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]

## <a name="end_category_map"></a><a name="end_category_map"></a>END_CATEGORY_MAP

Marca o fim do mapa da categoria.

```
END_CATEGORY_MAP()
```

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_CATEGORY_MAP](#begin_category_map).

## <a name="implemented_category"></a><a name="implemented_category"></a>Implemented_category

Adicione uma IMPLEMENTED_CATEGORY macro ao mapa de [categoria](#begin_category_map) do seu componente para especificar que ele deve ser registrado como implementação da categoria identificada pelo parâmetro *catID.*

```
IMPLEMENTED_CATEGORY(catID)
```

### <a name="parameters"></a>Parâmetros

*Catid*<br/>
[em] Uma constante ou variável CATID segurando o identificador globalmente único (GUID) para a categoria implementada. O endereço do *catID* será levado e adicionado ao mapa. Veja a tabela abaixo para uma seleção de categorias de ações.

### <a name="remarks"></a>Comentários

As categorias de componentes listadas no mapa serão registradas automaticamente quando o módulo for registrado se a classe tiver uma [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) associada ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.

Os clientes podem usar as informações da categoria registradas para a classe para determinar seus recursos e requisitos sem ter que criar uma instância dela.

Para obter mais informações sobre categorias de componentes, consulte [quais são as categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work) no SDK do Windows.

### <a name="a-selection-of-stock-categories"></a>Uma Seleção de Categorias de Ações

|Descrição|Símbolo|GUIA DE Registro|
|-----------------|------------|-------------------|
|Seguro para scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|
|Contenção do site do quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|
|Vinculação simples de dados|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|
|Vinculação avançada de dados|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|
|Objetos com reconhecimento de Internet|Consulte [Objetos conscientes](/windows/win32/com/internet-aware-objects) da Internet no SDK do Windows para obter uma lista de amostras.||

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#100](../../atl/codesnippet/cpp/category-macros_1.h)]

## <a name="required_category"></a><a name="required_category"></a>REQUIRED_CATEGORY

Adicione uma REQUIRED_CATEGORY macro ao mapa de [categoria](#begin_category_map) do seu componente para especificar que ele deve ser registrado como exigindo a categoria identificada pelo parâmetro *catID.*

```
REQUIRED_CATEGORY( catID )
```

### <a name="parameters"></a>Parâmetros

*Catid*<br/>
[em] Uma constante ou variável CATID segurando o identificador globalmente único (GUID) para a categoria necessária. O endereço do *catID* será levado e adicionado ao mapa. Veja a tabela abaixo para uma seleção de categorias de ações.

### <a name="remarks"></a>Comentários

As categorias de componentes listadas no mapa serão registradas automaticamente quando o módulo for registrado se a classe tiver uma [OBJECT_ENTRY_AUTO](../../atl/reference/object-map-macros.md#object_entry_auto) associada ou [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](../../atl/reference/object-map-macros.md#object_entry_non_createable_ex_auto) macro.

Os clientes podem usar as informações da categoria registradas para a classe para determinar seus recursos e requisitos sem ter que criar uma instância dela. Por exemplo, um controle pode exigir que um contêiner suporte a vinculação de dados. O contêiner pode descobrir se ele tem os recursos necessários para hospedar o controle consultando o gerente da categoria para as categorias exigidas por esse controle. Se o contêiner não suportar um recurso necessário, ele pode se recusar a hospedar o objeto COM.

Para obter mais informações sobre categorias de componentes, incluindo uma lista de amostras, consulte [quais são as categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work) no SDK do Windows.

### <a name="a-selection-of-stock-categories"></a>Uma Seleção de Categorias de Ações

|Descrição|Símbolo|GUIA DE Registro|
|-----------------|------------|-------------------|
|Seguro para scripts|CATID_SafeForScripting|{7DD95801-9882-11CF-9FA9-00AA006C42C4}|
|Seguro para inicialização|CATID_SafeForInitializing|{7DD95802-9882-11CF-9FA9-00AA006C42C4}|
|Contenção do site do quadro simples|CATID_SimpleFrameControl|{157083E0-2368-11cf-87B9-00AA006C8166}|
|Vinculação simples de dados|CATID_PropertyNotifyControl|{157083E1-2368-11cf-87B9-00AA006C8166}|
|Vinculação avançada de dados|CATID_VBDataBound|{157083E2-2368-11cf-87B9-00AA006C8166}|
|Controles sem janelas|CATID_WindowlessObject|{1D06B600-3AE3-11cf-87B9-00AA006C8166}|
|Objetos com reconhecimento de Internet|Consulte [Objetos conscientes](/windows/win32/com/internet-aware-objects) da Internet no SDK do Windows para obter uma lista de amostras.||

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#135](../../atl/codesnippet/cpp/category-macros_2.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)

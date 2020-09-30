---
title: Classe IDBSchemaRowsetImpl
ms.date: 11/04/2016
f1_keywords:
- IDBSchemaRowsetImpl
- CheckRestrictions
- IDBSchemaRowsetImpl::CheckRestrictions
- IDBSchemaRowsetImpl.CheckRestrictions
- IDBSchemaRowsetImpl::CreateSchemaRowset
- ATL::IDBSchemaRowsetImpl::CreateSchemaRowset
- CreateSchemaRowset
- IDBSchemaRowsetImpl.CreateSchemaRowset
- ATL.IDBSchemaRowsetImpl.CreateSchemaRowset
- IDBSchemaRowsetImpl::SetRestrictions
- SetRestrictions
- IDBSchemaRowsetImpl.SetRestrictions
- ATL::IDBSchemaRowsetImpl::GetRowset
- ATL.IDBSchemaRowsetImpl.GetRowset
- IDBSchemaRowsetImpl<SessionClass>::GetRowset
- IDBSchemaRowsetImpl.GetRowset
- IDBSchemaRowsetImpl::GetRowset
- ATL::IDBSchemaRowsetImpl<SessionClass>::GetRowset
- GetRowset
- ATL::IDBSchemaRowsetImpl::GetSchemas
- GetSchemas
- IDBSchemaRowsetImpl<SessionClass>::GetSchemas
- ATL.IDBSchemaRowsetImpl.GetSchemas
- ATL::IDBSchemaRowsetImpl<SessionClass>::GetSchemas
- IDBSchemaRowsetImpl.GetSchemas
- IDBSchemaRowsetImpl::GetSchemas
helpviewer_keywords:
- IDBSchemaRowsetImpl class
- CheckRestrictions method
- CreateSchemaRowset method
- SetRestrictions method
- GetRowset method
- GetSchemas method
ms.assetid: bd7bf0d7-a1c6-4afa-88e3-cfdbdf560703
ms.openlocfilehash: d78aa23469cc0fa94498f93e9a6975e0a7c827e9
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509038"
---
# <a name="idbschemarowsetimpl-class"></a>Classe IDBSchemaRowsetImpl

Fornece implementação para conjuntos de linhas de esquema.

## <a name="syntax"></a>Sintaxe

```cpp
template <class SessionClass>
class ATL_NO_VTABLE IDBSchemaRowsetImpl : public IDBSchemaRowset
```

### <a name="parameters"></a>Parâmetros

*SessionClass*<br/>
A classe pela qual `IDBSchemaRowsetImpl` é herdada. Normalmente, essa classe será a classe de sessão do usuário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[CheckRestrictions](#checkrestrictions)|Verifica a validade das restrições em relação a um conjunto de linhas de esquema.|
|[CreateSchemaRowset](#createschemarowset)|Implementa uma função de criador de objeto COM para o objeto especificado pelo parâmetro de modelo.|
|[SetRestrictions](#setrestrictions)|Especifica quais restrições são suportadas em um conjunto de linhas de esquema específico.|

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[GetRowset](#getrowset)|Retorna um conjunto de linhas de esquema.|
|[GetSchemas](#getschemas)|Retorna uma lista de conjuntos de linhas de esquema acessíveis por [IDBSchemaRowsetImpl:: GetRowset](#getrowset).|

## <a name="remarks"></a>Comentários

Essa classe implementa a interface [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) e a função modelos Creator [CreateSchemaRowset](#createschemarowset).

OLE DB usa conjuntos de linhas de esquema para retornar dados sobre os dados em um provedor. Esses dados são geralmente chamados de "metadados". Por padrão, um provedor deve sempre dar `DBSCHEMA_TABLES` suporte `DBSCHEMA_COLUMNS` a, e `DBSCHEMA_PROVIDER_TYPES` , conforme descrito em [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB*. Conjuntos de linhas de esquema são designados em um mapa de esquema. Para obter informações sobre as entradas de mapa de esquema, consulte [SCHEMA_ENTRY](./macros-for-ole-db-provider-templates.md#schema_entry).

O assistente de provedor de OLE DB, no assistente de objeto ATL, gera automaticamente o código para os conjuntos de linhas de esquema em seu projeto. (Por padrão, o assistente dá suporte aos conjuntos de linhas de esquema obrigatórios mencionados anteriormente.) Quando você cria um consumidor usando o assistente de objeto ATL, o assistente usa conjuntos de linhas de esquema para associar os dados corretos a um provedor. Se você não implementar seus conjuntos de linhas de esquema para fornecer os metadados corretos, o assistente não associará os dados corretos.

Para obter informações sobre como dar suporte a conjuntos de linhas de esquema em seu provedor, consulte [suporte a conjuntos](../../data/oledb/supporting-schema-rowsets.md)de linhas de esquema.

Para obter mais informações sobre conjuntos de linhas de esquema, consulte conjuntos de linhas de [esquema](/previous-versions/windows/desktop/ms712921(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="idbschemarowsetimplcheckrestrictions"></a><a name="checkrestrictions"></a> IDBSchemaRowsetImpl::CheckRestrictions

Verifica a validade das restrições em relação a um conjunto de linhas de esquema.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CheckRestrictions(REFGUID rguidSchema,
   ULONG cRestrictions,  const VARIANT rgRestrictions[]);
```

#### <a name="parameters"></a>Parâmetros

*rguidSchema*<br/>
no Uma referência ao GUID do conjunto de linhas de esquema solicitado (por exemplo, `DBSCHEMA_TABLES` ).

*cRestrictions*<br/>
no O número de restrições que o consumidor passou para o conjunto de linhas de esquema.

*rgRestrictions*<br/>
no Uma matriz de comprimento *cRestrictions* de valores de restrição a ser definida. Para obter mais informações, consulte a descrição do parâmetro *rgRestrictions* em [SetRestrictions](#setrestrictions).

### <a name="remarks"></a>Comentários

Use `CheckRestrictions` para verificar a validade das restrições em relação a um conjunto de linhas de esquema. Ele verifica as restrições para os conjuntos de linhas de `DBSCHEMA_TABLES` `DBSCHEMA_COLUMNS` esquema, e `DBSCHEMA_PROVIDER_TYPES` . Chame-o para determinar se a chamada de um consumidor para `IDBSchemaRowset::GetRowset` está correta. Se você quiser dar suporte a conjuntos de linhas de esquema diferentes daqueles listados acima, você deve criar sua própria função para realizar essa tarefa.

`CheckRestrictions` Determina se o consumidor está chamando [GetRowset](#getrowset) com a restrição correta e o tipo de restrição correto (por exemplo, um VT_BSTR para uma cadeia de caracteres) ao qual o provedor dá suporte. Ele também determina se há suporte para o número correto de restrições. Por padrão, `CheckRestrictions` o solicitará ao provedor, por meio da chamada [SetRestrictions](#setrestrictions) , quais restrições ele suporta em um determinado conjunto de linhas. Em seguida, ele compara as restrições do consumidor com as suportadas pelo provedor e é bem-sucedida ou falha.

Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

## <a name="idbschemarowsetimplcreateschemarowset"></a><a name="createschemarowset"></a> IDBSchemaRowsetImpl::CreateSchemaRowset

Implementa uma função de criador de objeto COM para o objeto especificado pelo parâmetro de modelo.

### <a name="syntax"></a>Sintaxe

```cpp
template template <class SchemaRowsetClass>
HRESULT CreateSchemaRowset(IUnknown *pUnkOuter,
   ULONG cRestrictions,
   const VARIANT rgRestrictions[],
   REFIID riid,
   ULONG cPropertySets,
   DBPROPSET rgPropertySets[],
   IUnknown** ppRowset,
   SchemaRowsetClass*& pSchemaRowset);
```

#### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
no Um [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) externo ao agregar, caso contrário, NULL.

*cRestrictions*<br/>
no A contagem de restrições aplicadas ao conjunto de linhas de esquema.

*rgRestrictions*<br/>
no Uma matriz de `cRestrictions` **variante**s a ser aplicada ao conjunto de linhas.

*riid*<br/>
no A interface para [QueryInterface](../../atl/queryinterface.md) na saída `IUnknown` .

*cPropertySets*<br/>
no O número de conjuntos de propriedades a serem definidos.

*rgPropertySets*<br/>
no Uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) que especificam as propriedades que estão sendo definidas.

*ppRowset*<br/>
fora A saída `IUnknown` solicitada por *riid*. Essa `IUnknown` é uma interface no objeto de conjunto de linhas de esquema.

*pSchemaRowset*<br/>
fora Um ponteiro para uma instância da classe de conjunto de linhas de esquema. Normalmente, esse parâmetro não é usado, mas pode ser usado se você precisar executar mais trabalho no conjunto de linhas de esquema antes de entregá-lo a um objeto COM. O tempo de vida de *pSchemaRowset* é associado por *ppRowset*.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função implementa um criador genérico para todos os tipos de conjuntos de linhas de esquema. Normalmente, o usuário não chama essa função. Ele é chamado pela implementação do mapa de esquema.

## <a name="idbschemarowsetimplsetrestrictions"></a><a name="setrestrictions"></a> IDBSchemaRowsetImpl:: SetRestrictions

Especifica quais restrições são suportadas em um conjunto de linhas de esquema específico.

### <a name="syntax"></a>Sintaxe

```cpp
void SetRestrictions(ULONG cRestrictions,
   GUID* /* rguidSchema */,
   ULONG* rgRestrictions);
```

#### <a name="parameters"></a>Parâmetros

*cRestrictions*<br/>
no O número de restrições na matriz *rgRestrictions* e o número de GUIDs na matriz *rguidSchema* .

*rguidSchema*<br/>
no Uma matriz dos GUIDs dos conjuntos de linhas do esquema para os quais buscar restrições. Cada elemento de matriz contém o GUID de um conjunto de linhas de esquema (por exemplo, `DBSCHEMA_TABLES` ).

*rgRestrictions*<br/>
no Uma matriz de comprimento *cRestrictions* de valores de restrição a ser definida. Cada elemento corresponde às restrições no conjunto de linhas de esquema identificado pelo GUID. Se o provedor não oferecer suporte a um conjunto de linhas de esquema, o elemento será definido como zero. Caso contrário, o valor **ULONG** contém uma máscara de bits que representa as restrições com suporte nesse conjunto de linhas de esquema. Para obter mais informações sobre quais restrições correspondem a um conjunto de linhas de esquema específico, consulte a tabela de GUIDs de conjunto de linhas de esquema em [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

### <a name="remarks"></a>Comentários

O `IDBSchemaRowset` objeto chama `SetRestrictions` para determinar quais restrições você dá suporte em um conjunto de linhas de esquema específico (ele é chamado por [GetSchemas](#getschemas) por meio de um ponteiro convertido). As restrições permitem que os consumidores busquem somente as linhas correspondentes (por exemplo, encontrar todas as colunas na tabela "MyTable"). As restrições são opcionais e, no caso em que nenhuma seja suportada (o padrão), todos os dados sempre serão retornados.

A implementação padrão desse método define os elementos da matriz *rgRestrictions* como 0. Substitua o padrão em sua classe de sessão para definir restrições diferentes do padrão.

Para obter informações sobre como implementar o suporte a conjunto de linhas de esquema, consulte Supporting [Schema sets](../../data/oledb/supporting-schema-rowsets.md).

Para obter um exemplo de um provedor que dá suporte a conjuntos de linhas de esquema, consulte o exemplo [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) .

Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

## <a name="idbschemarowsetimplgetrowset"></a><a name="getrowset"></a> IDBSchemaRowsetImpl:: GetRowset

Retorna um conjunto de linhas de esquema.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetRowset)(IUnknown *pUnkOuter,
   REFGUID rguidSchema,
   ULONG cRestrictions,
   const VARIANT rgRestrictions[],
   REFIID riid,
   ULONG cPropertySets,
   DBPROPSET rgPropertySets[],
   IUnknown **ppRowset);
```

#### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
no Uma externa `IUnknown` ao agregar; caso contrário, NULL.

*rguidSchema*<br/>
no Uma referência ao GUID do conjunto de linhas de esquema solicitado (por exemplo, `DBSCHEMA_TABLES` ).

*cRestrictions*<br/>
no Uma contagem de restrições a serem aplicadas ao conjunto de linhas.

*rgRestrictions*<br/>
no Uma matriz de `cRestrictions` **variante**s que representa as restrições.

*riid*<br/>
no O IID para a solicitação do conjunto de linhas de esquema recém-criado.

*cPropertySets*<br/>
no O número de conjuntos de propriedades a serem definidos.

*rgPropertySets*<br/>
[entrada/saída] Uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) a ser definida no conjunto de linhas de esquema recém-criado.

*ppRowset*<br/>
fora Um ponteiro para a interface solicitada no conjunto de linhas de esquema recém-criado.

### <a name="remarks"></a>Comentários

Esse método exige que o usuário tenha um mapa de esquema na classe de sessão. Usando as informações de mapa do esquema, `GetRowset` o criará um determinado objeto de conjunto de linhas se o parâmetro *rguidSchema* for igual a um dos GUIDs de entradas do mapa. Consulte [SCHEMA_ENTRY](./macros-for-ole-db-provider-templates.md#schema_entry) para obter uma descrição da entrada do mapa.

Consulte [IDBSchemaRowset:: GetRowset](/previous-versions/windows/desktop/ms722634(v=vs.85)) no SDK do Windows.

## <a name="idbschemarowsetimplgetschemas"></a><a name="getschemas"></a> IDBSchemaRowsetImpl:: GetSchemas

Retorna uma lista de conjuntos de linhas de esquema acessíveis por [IDBSchemaRowsetImpl:: GetRowset](#getrowset).

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetSchema s )(ULONG * pcSchemas,
   GUID ** prgSchemas,
   ULONG** prgRest);
```

#### <a name="parameters"></a>Parâmetros

*pcSchemas*<br/>
fora Um ponteiro para um **ULONG** que é preenchido com o número de esquemas.

*prgSchemas*<br/>
fora Um ponteiro para uma matriz de GUIDs que é preenchida com um ponteiro para uma matriz de GUIDs de conjunto de linhas de esquema.

*prgRest*<br/>
fora Um ponteiro para uma matriz de **ULONG**s que deve ser preenchido com a matriz de restrição.

### <a name="remarks"></a>Comentários

Esse método retorna uma matriz de todos os conjuntos de linhas de esquema suportados pelo provedor. Consulte [IDBSchemaRowset:: GetSchemas](/previous-versions/windows/desktop/ms719605(v=vs.85)) na SDK do Windows.

A implementação dessa função exige que o usuário tenha um mapa de esquema na classe de sessão. Usando as informações de mapa do esquema, ele responde com a matriz de GUIDs para os esquemas no mapa. Isso representa os esquemas compatíveis com o provedor.

## <a name="see-also"></a>Consulte também

[Classes de conjunto de linhas de esquema e classes de typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)<br/>
[Suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md)<br/>
[SCHEMA_ENTRY](./macros-for-ole-db-provider-templates.md#schema_entry)<br/>
[UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider)

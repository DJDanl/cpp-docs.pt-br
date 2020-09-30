---
title: Macros para modelos de provedor de banco de dados OLE
ms.date: 02/11/2019
f1_keywords:
- BEGIN_PROPERTY_SET
- BEGIN_PROPERTY_SET_EX
- BEGIN_PROPSET_MAP
- CHAIN_PROPERTY_SET
- END_PROPERTY_SET
- END_PROPSET_MAP
- PROPERTY_INFO_ENTRY
- PROPERTY_INFO_ENTRY_EX
- PROPERTY_INFO_ENTRY_VALUE
- BEGIN_PROVIDER_COLUMN_MAP
- END_PROVIDER_COLUMN_MAP
- PROVIDER_COLUMN_ENTRY
- PROVIDER_COLUMN_ENTRY_FIXED
- PROVIDER_COLUMN_ENTRY_GN
- PROVIDER_COLUMN_ENTRY_LENGTH
- PROVIDER_COLUMN_ENTRY_STR
- PROVIDER_COLUMN_ENTRY_TYPE_LENGTH
- PROVIDER_COLUMN_ENTRY_WSTR
- BEGIN_SCHEMA_MAP
- END_SCHEMA_MAP
- SCHEMA_ENTRY
helpviewer_keywords:
- OLE DB provider templates, macros
- macros, OLE DB Provider Templates
- Provider Template macros (OLE DB)
- OLE DB Provider Template macros
- BEGIN_PROPERTY_SET macro
- BEGIN_PROPERTY_SET_EX macro
- BEGIN_PROPSET_MAP macro
- CHAIN_PROPERTY_SET macro
- END_PROPERTY_SET macro
- END_PROPSET_MAP macro
- PROPERTY_INFO_ENTRY macro
- PROPERTY_INFO_ENTRY_EX macro
- PROPERTY_INFO_ENTRY_VALUE macro
- BEGIN_PROVIDER_COLUMN_MAP macro
- END_PROVIDER_COLUMN_MAP macro
- PROVIDER_COLUMN_ENTRY macro
- PROVIDER_COLUMN_ENTRY_FIXED macro
- PROVIDER_COLUMN_ENTRY_GN macro
- PROVIDER_COLUMN_ENTRY_LENGTH macro
- PROVIDER_COLUMN_ENTRY_STR macro
- PROVIDER_COLUMN_ENTRY_TYPE_LENGTH macro
- PROVIDER_COLUMN_ENTRY_WSTR macro
- BEGIN_SCHEMA_MAP macro
- END_SCHEMA_MAP macro
- SCHEMA_ENTRY macro
ms.assetid: 909482c5-64ab-4e52-84a9-1c07091db183
ms.openlocfilehash: e72204102bfa47a9dd162499030a38c07bbfe46c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504013"
---
# <a name="macros-for-ole-db-provider-templates"></a>Macros para modelos de provedor de banco de dados OLE

As macros do provedor de modelos OLE DB oferecem funcionalidade nas seguintes categorias:

## <a name="property-set-map-macros"></a>Macros de mapa do conjunto de propriedades

| Nome | Descrição |
|-|-|
|[BEGIN_PROPERTY_SET](#begin_property_set)|Marca o início de um conjunto de propriedades.|
|[BEGIN_PROPERTY_SET_EX](#begin_property_set_ex)|Marca o início de um conjunto de propriedades.|
|[BEGIN_PROPSET_MAP](#begin_propset_map)|Marca o início de um conjunto de propriedades que pode ser ocultado ou definido fora do escopo do provedor.|
|[CHAIN_PROPERTY_SET](#chain_property_set)|Grupos de propriedades de cadeias juntos.|
|[END_PROPERTY_SET](#end_property_set)|Marca o final de um conjunto de propriedades.|
|[END_PROPSET_MAP](#end_propset_map)|Marca o final de um mapa de conjunto de propriedades.|
|[PROPERTY_INFO_ENTRY](#property_info_entry)|Define uma propriedade específica em uma propriedade definida como um valor padrão.|
|[PROPERTY_INFO_ENTRY_EX](#property_info_entry_ex)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você. Também permite que você defina sinalizadores e opções.|
|[PROPERTY_INFO_ENTRY_VALUE](#property_info_entry_value)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você.|

## <a name="column-map-macros"></a>Macros de mapa de coluna

| Nome | Descrição |
|-|-|
|[BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map)|Marca o início das entradas de mapa da coluna do provedor.|
|[END_PROVIDER_COLUMN_MAP](#end_provider_column_map)|Marca o final das entradas de mapa da coluna do provedor.|
|[PROVIDER_COLUMN_ENTRY](#provider_column_entry)|Representa uma coluna específica à qual o provedor dá suporte.|
|[PROVIDER_COLUMN_ENTRY_FIXED](#provider_column_entry_fixed)|Representa uma coluna específica à qual o provedor dá suporte. Você pode especificar o tipo de dados da coluna.|
|[PROVIDER_COLUMN_ENTRY_GN](#provider_column_entry_gn)|Representa uma coluna específica à qual o provedor dá suporte. Você pode especificar o tamanho da coluna, o tipo de dados, a precisão, a escala e o GUID do conjunto de linhas do esquema.|
|[PROVIDER_COLUMN_ENTRY_LENGTH](#provider_column_entry_length)|Representa uma coluna específica à qual o provedor dá suporte. Você pode especificar o tamanho da coluna.|
|[PROVIDER_COLUMN_ENTRY_STR](#provider_column_entry_str)|Representa uma coluna específica à qual o provedor dá suporte. Ele assume que o tipo de coluna é uma cadeia de caracteres.|
|[PROVIDER_COLUMN_ENTRY_TYPE_LENGTH](#provider_column_entry_type_length)|Representa uma coluna específica à qual o provedor dá suporte. Como PROVIDER_COLUMN_ENTRY_LENGTH, mas também permite que você especifique o tipo de dados da coluna, bem como o tamanho.|
|[PROVIDER_COLUMN_ENTRY_WSTR](#provider_column_entry_wstr)|Representa uma coluna específica à qual o provedor dá suporte. Ele assume que o tipo de coluna é uma cadeia de caracteres Unicode.|

## <a name="schema-rowset-macros"></a>Macros de conjunto de linhas de esquema

| Nome | Descrição |
|-|-|
|[BEGIN_SCHEMA_MAP](#begin_schema_map)|Marca o início de um mapa de esquema.|
|[END_SCHEMA_MAP](#end_schema_map)|Marca o final de um mapa de esquema.|
|[SCHEMA_ENTRY](#schema_entry)|Associa um GUID a uma classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

### <a name="begin_property_set"></a><a name="begin_property_set"></a> BEGIN_PROPERTY_SET

Marca o início de um conjunto de propriedades em um mapa de conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROPERTY_SET(guid)
```

#### <a name="parameters"></a>Parâmetros

*guid*<br/>
no O GUID da propriedade.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="begin_property_set_ex"></a><a name="begin_property_set_ex"></a> BEGIN_PROPERTY_SET_EX

Marca o início de um conjunto de propriedades em um mapa de conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROPERTY_SET_EX(guid, flags)
```

#### <a name="parameters"></a>Parâmetros

*guid*<br/>
no O GUID da propriedade.

*sinalizadores*<br/>
no UPROPSET_HIDDEN para qualquer conjunto de propriedades que você não deseja expor ou UPROPSET_PASSTHROUGH para um provedor expondo propriedades definidas fora do escopo do provedor.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="begin_propset_map"></a><a name="begin_propset_map"></a> BEGIN_PROPSET_MAP

Marca o início das entradas do mapa do conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROPSET_MAP(Class)
```

#### <a name="parameters"></a>Parâmetros

*Classe*<br/>
no A classe na qual esse conjunto de propriedades é especificado. Um conjunto de propriedades pode ser especificado nos seguintes objetos de OLE DB:

- [Objetos de fonte de dados](/previous-versions/windows/desktop/ms721278(v=vs.85))

- [Objetos de sessão](/previous-versions/windows/desktop/ms711572(v=vs.85))

- [Comandos](/previous-versions/windows/desktop/ms724608(v=vs.85))

#### <a name="example"></a>Exemplo

Aqui está um mapa do conjunto de propriedades de exemplo:

[!code-cpp[NVC_OLEDB_Provider#3](../../data/oledb/codesnippet/cpp/begin-propset-map_1.h)]

### <a name="chain_property_set"></a><a name="chain_property_set"></a> CHAIN_PROPERTY_SET

Esta macro encadeia grupos de Propriedades juntos.

#### <a name="syntax"></a>Sintaxe

```cpp
CHAIN_PROPERTY_SET(ChainClass)
```

#### <a name="parameters"></a>Parâmetros

*ChainClass*<br/>
no O nome da classe para a qual as propriedades de cadeia são encadeados. Essa é uma classe gerada pelo assistente de projeto do ATL que já contém um mapa (como uma sessão, um comando ou uma classe de objeto de fonte de dados).

#### <a name="remarks"></a>Comentários

Você pode encadear um conjunto de propriedades de outra classe para sua própria classe e, em seguida, acessar as propriedades diretamente da sua classe.

> [!CAUTION]
> Use essa macro com moderação. O uso impróprio pode fazer com que um consumidor falhe na OLE DB testes de conformidade.

### <a name="end_property_set"></a><a name="end_property_set"></a> END_PROPERTY_SET

Marca o final de um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PROPERTY_SET(guid)
```

#### <a name="parameters"></a>Parâmetros

*guid*<br/>
no O GUID da propriedade.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="end_propset_map"></a><a name="end_propset_map"></a> END_PROPSET_MAP

Marca o final das entradas do mapa do conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PROPSET_MAP()
```

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="property_info_entry"></a><a name="property_info_entry"></a> PROPERTY_INFO_ENTRY

Representa uma propriedade específica em um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
PROPERTY_INFO_ENTRY(dwPropID)
```

#### <a name="parameters"></a>Parâmetros

*dwPropID*<br/>
no Um valor [DBPROPID](/previous-versions/windows/desktop/ms723882(v=vs.85)) que pode ser usado em conjunto com o GUID do conjunto de propriedades para identificar uma propriedade.

#### <a name="remarks"></a>Comentários

Essa macro define o valor da Propriedade do tipo `DWORD` como um valor padrão definido em ATLDB. H. Para definir a propriedade com um valor de sua escolha, use [PROPERTY_INFO_ENTRY_VALUE](#property_info_entry_value). Para definir o `VARTYPE` e [DBPROPFLAGS](/previous-versions/windows/desktop/ms724342(v=vs.85)) para a propriedade ao mesmo tempo, use [PROPERTY_INFO_ENTRY_EX](#property_info_entry_ex).

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="property_info_entry_ex"></a><a name="property_info_entry_ex"></a> PROPERTY_INFO_ENTRY_EX

Representa uma propriedade específica em um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
PROPERTY_INFO_ENTRY_EX(dwPropID, vt, dwFlags, value, options)
```

#### <a name="parameters"></a>Parâmetros

*dwPropID*<br/>
no Um valor [DBPROPID](/previous-versions/windows/desktop/ms723882(v=vs.85)) que pode ser usado em conjunto com o GUID do conjunto de propriedades para identificar uma propriedade.

*vt*<br/>
no O `VARTYPE` da entrada dessa propriedade. (Definido em wtypes. h)

*dwFlags*<br/>
no Um valor [DBPROPFLAGS](/previous-versions/windows/desktop/ms724342(v=vs.85)) que descreve essa entrada de propriedade.

*value*<br/>
no O valor da Propriedade do tipo `DWORD` .

*options*<br/>
DBPROPOPTIONS_REQUIRED ou DBPROPOPTIONS_SETIFCHEAP. Normalmente, um provedor não precisa definir *Opções* , já que ele é definido pelo consumidor.

#### <a name="remarks"></a>Comentários

Com essa macro, você pode especificar diretamente o valor da Propriedade do tipo, `DWORD` bem como opções e sinalizadores. Para simplesmente definir uma propriedade para um valor padrão definido em ATLDB. H, use [PROPERTY_INFO_ENTRY](#property_info_entry). Para definir uma propriedade com um valor de sua escolha, sem definir opções ou sinalizadores, use [PROPERTY_INFO_ENTRY_VALUE](#property_info_entry_value).

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="property_info_entry_value"></a><a name="property_info_entry_value"></a> PROPERTY_INFO_ENTRY_VALUE

Representa uma propriedade específica em um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
PROPERTY_INFO_ENTRY_VALUE(dwPropID, value)
```

#### <a name="parameters"></a>Parâmetros

*dwPropID*<br/>
no Um valor [DBPROPID](/previous-versions/windows/desktop/ms723882(v=vs.85)) que pode ser usado em conjunto com o GUID do conjunto de propriedades para identificar uma propriedade.

*value*<br/>
no O valor da Propriedade do tipo `DWORD` .

#### <a name="remarks"></a>Comentários

Com essa macro, você pode especificar diretamente o valor da Propriedade do tipo `DWORD` . Para definir a propriedade para o valor padrão definido em ATLDB. H, use [PROPERTY_INFO_ENTRY](#property_info_entry). Para definir o valor, os sinalizadores e as opções da propriedade, use [PROPERTY_INFO_ENTRY_EX](#property_info_entry_ex).

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROPSET_MAP](#begin_propset_map).

### <a name="begin_provider_column_map"></a><a name="begin_provider_column_map"></a> BEGIN_PROVIDER_COLUMN_MAP

Marca o início das entradas de mapa da coluna do provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROVIDER_COLUMN_MAP(theClass)
```

#### <a name="parameters"></a>Parâmetros

*Classe*<br/>
no O nome da classe à qual este mapa pertence.

#### <a name="example"></a>Exemplo

Aqui está um exemplo de mapa de coluna de provedor:

[!code-cpp[NVC_OLEDB_Provider#4](../../data/oledb/codesnippet/cpp/begin-provider-column-map_1.h)]

### <a name="end_provider_column_map"></a><a name="end_provider_column_map"></a> END_PROVIDER_COLUMN_MAP

Marca o final das entradas de mapa da coluna do provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PROVIDER_COLUMN_MAP()
```

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map).

### <a name="provider_column_entry"></a><a name="provider_column_entry"></a> PROVIDER_COLUMN_ENTRY

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY (name, ordinal, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*associado*<br/>
no A variável de membro no `dataClass` correspondente à coluna.

### <a name="provider_column_entry_fixed"></a><a name="provider_column_entry_fixed"></a> PROVIDER_COLUMN_ENTRY_FIXED

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_FIXED(name, ordinal, dbtype, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*DbType*<br/>
no O tipo de dados em [DbType](/previous-versions/windows/desktop/ms711251(v=vs.85)).

*associado*<br/>
no A variável de membro no `dataClass` que armazena os dados.

#### <a name="remarks"></a>Comentários

Permite que você especifique o tipo de dados da coluna.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map).

### <a name="provider_column_entry_gn"></a><a name="provider_column_entry_gn"></a> PROVIDER_COLUMN_ENTRY_GN

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_GN (name, ordinal, flags, colSize, dbtype, precision, scale, guid)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*sinalizadores*<br/>
no Especifica como os dados são retornados. Consulte a `dwFlags` Descrição em [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*Colunas*<br/>
no O tamanho da coluna.

*DbType*<br/>
no Indica o tipo de dados do valor. Consulte a `wType` Descrição em [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*precisão*<br/>
no Indica a precisão a ser usada ao obter dados se o *DbType* for DBTYPE_NUMERIC ou DBTYPE_DECIMAL. Consulte a `bPrecision` Descrição em [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*scale*<br/>
no Indica a escala a ser usada ao obter dados se o dbType for DBTYPE_NUMERIC ou DBTYPE_DECIMAL. Consulte a `bScale` Descrição em [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*guid*<br/>
Um GUID de conjunto de linhas de esquema. Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.

#### <a name="remarks"></a>Comentários

Permite especificar o tamanho da coluna, o tipo de dados, a precisão, a escala e o GUID do conjunto de linhas do esquema.

### <a name="provider_column_entry_length"></a><a name="provider_column_entry_length"></a> PROVIDER_COLUMN_ENTRY_LENGTH

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_LENGTH(name, ordinal, size, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*size*<br/>
no O tamanho da coluna em bytes.

*associado*<br/>
no A variável de membro no `dataClass` que armazena os dados da coluna.

#### <a name="remarks"></a>Comentários

Permite que você especifique o tamanho da coluna.

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map).

### <a name="provider_column_entry_str"></a><a name="provider_column_entry_str"></a> PROVIDER_COLUMN_ENTRY_STR

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_STR(name, ordinal, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*associado*<br/>
no A variável de membro na classe de dados que armazena os dados.

#### <a name="remarks"></a>Comentários

Use essa macro quando os dados da coluna forem considerados [DBTYPE_STR](/previous-versions/windows/desktop/ms711251(v=vs.85)).

#### <a name="example"></a>Exemplo

Consulte [BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map).

### <a name="provider_column_entry_type_length"></a><a name="provider_column_entry_type_length"></a> PROVIDER_COLUMN_ENTRY_TYPE_LENGTH

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_TYPE_LENGTH(name, ordinal, dbtype, size, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*DbType*<br/>
no O tipo de dados em [DbType](/previous-versions/windows/desktop/ms711251(v=vs.85)).

*size*<br/>
no O tamanho da coluna em bytes.

*associado*<br/>
no A variável de membro na classe de dados que armazena os dados.

#### <a name="remarks"></a>Comentários

Semelhante a [PROVIDER_COLUMN_ENTRY_LENGTH](#provider_column_entry_length) , mas também permite que você especifique o tipo de dados da coluna, bem como o tamanho.

### <a name="provider_column_entry_wstr"></a><a name="provider_column_entry_wstr"></a> PROVIDER_COLUMN_ENTRY_WSTR

Representa uma coluna específica à qual o provedor dá suporte.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_WSTR(name, ordinal, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
no O nome da coluna.

*numera*<br/>
no O número da coluna. A menos que a coluna seja uma coluna de indicador, o número da coluna não deve ser 0.

*associado*<br/>
no A variável de membro na classe de dados que armazena os dados.

#### <a name="remarks"></a>Comentários

Use esta macro quando os dados da coluna forem uma cadeia de caracteres Unicode terminada em NULL, [DBTYPE_WSTR](/previous-versions/windows/desktop/ms711251(v=vs.85)).

### <a name="begin_schema_map"></a><a name="begin_schema_map"></a> BEGIN_SCHEMA_MAP

Denota o início de um mapa de esquema.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_SCHEMA_MAP(SchemaClass);
```

#### <a name="parameters"></a>Parâmetros

*SchemaClass*<br/>
A classe que contém o mapa. Normalmente, essa será a classe de sessão.

#### <a name="remarks"></a>Comentários

Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) no SDK do Windows para obter mais informações sobre conjuntos de linhas de esquema.

### <a name="end_schema_map"></a><a name="end_schema_map"></a> END_SCHEMA_MAP

Denota o final do mapa do esquema.

#### <a name="syntax"></a>Sintaxe

```cpp
END_SCHEMA_MAP()
```

#### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md).

### <a name="schema_entry"></a><a name="schema_entry"></a> SCHEMA_ENTRY

Associa um GUID a uma classe.

#### <a name="syntax"></a>Sintaxe

```cpp
SCHEMA_ENTRY(guid,
   rowsetClass);
```

#### <a name="parameters"></a>Parâmetros

*guid*<br/>
Um GUID de conjunto de linhas de esquema. Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.

*rowsetClass*<br/>
A classe que será criada para representar o conjunto de linhas de esquema.

#### <a name="remarks"></a>Comentários

O [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) pode consultar o mapa para obter uma lista de GUIDs ou pode criar um conjunto de linhas se ele receber um GUID. O conjunto de linhas de esquema `IDBSchemaRowsetImpl` cria é semelhante a uma `CRowsetImpl` classe derivada padrão, exceto pelo fato de que ele deve fornecer um `Execute` método que tenha a seguinte assinatura:

```cpp
HRESULT Execute (LONG* pcRowsAffected,
    ULONG cRestrictions,
    const VARIANT* rgRestrictions);
```

Essa `Execute` função popula os dados do conjunto de linhas. O assistente de projeto do ATL cria, conforme descrito em [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador de OLE DB*, três conjuntos de linhas de esquema iniciais no projeto para cada um dos três esquemas de OLE DB obrigatórios:

- DBSCHEMA_TABLES

- DBSCHEMA_COLUMNS

- DBSCHEMA_PROVIDER_TYPES

O assistente também adiciona três entradas correspondentes no mapa de esquema. Consulte [criando um provedor de modelo de OLE DB](../../data/oledb/creating-an-ole-db-provider.md) para obter mais informações sobre como usar o assistente para criar um provedor.

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Criando um provedor de OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
[Referência de modelos de provedor de OLE DB](../../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Macros para modelos de provedor de OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)

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
ms.openlocfilehash: 5d29b2548102b056a21ebfccb037af3a766788ba
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369813"
---
# <a name="macros-for-ole-db-provider-templates"></a>Macros para modelos de provedor de banco de dados OLE

As macros Do OLE DB Templates Provider oferecem funcionalidade nas seguintes categorias:

## <a name="property-set-map-macros"></a>Macros do mapa do conjunto de propriedades

|||
|-|-|
|[BEGIN_PROPERTY_SET](#begin_property_set)|Marca o início de um conjunto de propriedades.|
|[BEGIN_PROPERTY_SET_EX](#begin_property_set_ex)|Marca o início de um conjunto de propriedades.|
|[BEGIN_PROPSET_MAP](#begin_propset_map)|Marca o início de um conjunto de propriedades que pode ser ocultado ou definido fora do escopo do provedor.|
|[CHAIN_PROPERTY_SET](#chain_property_set)|Acorrenta grupos de propriedades juntos.|
|[END_PROPERTY_SET](#end_property_set)|Marca o fim de um conjunto de propriedades.|
|[END_PROPSET_MAP](#end_propset_map)|Marca o fim de um mapa de conjunto de propriedades.|
|[PROPERTY_INFO_ENTRY](#property_info_entry)|Define uma propriedade específica em um conjunto de propriedades como um valor padrão.|
|[PROPERTY_INFO_ENTRY_EX](#property_info_entry_ex)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você. Também permite definir bandeiras e opções.|
|[PROPERTY_INFO_ENTRY_VALUE](#property_info_entry_value)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você.|

## <a name="column-map-macros"></a>Macros do mapa da coluna

|||
|-|-|
|[BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map)|Marca o início das entradas do mapa da coluna do provedor.|
|[END_PROVIDER_COLUMN_MAP](#end_provider_column_map)|Marca o fim das entradas do mapa da coluna do provedor.|
|[PROVIDER_COLUMN_ENTRY](#provider_column_entry)|Representa uma coluna específica suportada pelo provedor.|
|[PROVIDER_COLUMN_ENTRY_FIXED](#provider_column_entry_fixed)|Representa uma coluna específica suportada pelo provedor. Você pode especificar o tipo de dados da coluna.|
|[PROVIDER_COLUMN_ENTRY_GN](#provider_column_entry_gn)|Representa uma coluna específica suportada pelo provedor. Você pode especificar o tamanho da coluna, o tipo de dados, a precisão, a escala e o esquema do conjunto de linhas GUID.|
|[PROVIDER_COLUMN_ENTRY_LENGTH](#provider_column_entry_length)|Representa uma coluna específica suportada pelo provedor. Você pode especificar o tamanho da coluna.|
|[PROVIDER_COLUMN_ENTRY_STR](#provider_column_entry_str)|Representa uma coluna específica suportada pelo provedor. Ele assume que o tipo de coluna é uma string.|
|[PROVIDER_COLUMN_ENTRY_TYPE_LENGTH](#provider_column_entry_type_length)|Representa uma coluna específica suportada pelo provedor. Como PROVIDER_COLUMN_ENTRY_LENGTH, mas também permite especificar o tipo de dados da coluna, bem como o tamanho.|
|[PROVIDER_COLUMN_ENTRY_WSTR](#provider_column_entry_wstr)|Representa uma coluna específica suportada pelo provedor. Ele assume que o tipo de coluna é uma seqüência de caracteres Unicode.|

## <a name="schema-rowset-macros"></a>Macros do esquema rowset

|||
|-|-|
|[BEGIN_SCHEMA_MAP](#begin_schema_map)|Marca o início de um mapa de esquemas.|
|[END_SCHEMA_MAP](#end_schema_map)|Marca o fim de um mapa de esquemas.|
|[SCHEMA_ENTRY](#schema_entry)|Associa um GUID com uma classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

### <a name="begin_property_set"></a><a name="begin_property_set"></a>BEGIN_PROPERTY_SET

Marca o início de uma propriedade definida em um mapa de conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROPERTY_SET(guid)
```

#### <a name="parameters"></a>Parâmetros

*Guid*<br/>
[em] A propriedade GUID.

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="begin_property_set_ex"></a><a name="begin_property_set_ex"></a>BEGIN_PROPERTY_SET_EX

Marca o início de uma propriedade definida em um mapa de conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROPERTY_SET_EX(guid, flags)
```

#### <a name="parameters"></a>Parâmetros

*Guid*<br/>
[em] A propriedade GUID.

*Sinalizadores*<br/>
[em] UPROPSET_HIDDEN para quaisquer conjuntos de propriedades que você não deseja expor, ou UPROPSET_PASSTHROUGH para um provedor expondo propriedades definidas fora do escopo do provedor.

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="begin_propset_map"></a><a name="begin_propset_map"></a>Begin_propset_map

Marca o início das entradas do mapa do conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROPSET_MAP(Class)
```

#### <a name="parameters"></a>Parâmetros

*Classe*<br/>
[em] A classe na qual este conjunto de propriedades é especificado. Um conjunto de propriedades pode ser especificado nos seguintes objetos OLE DB:

- [Objetos de origem de dados](/previous-versions/windows/desktop/ms721278(v=vs.85))

- [Objetos de sessão](/previous-versions/windows/desktop/ms711572(v=vs.85))

- [Comandos](/previous-versions/windows/desktop/ms724608(v=vs.85))

#### <a name="example"></a>Exemplo

Aqui está um mapa do conjunto de propriedades de amostra:

[!code-cpp[NVC_OLEDB_Provider#3](../../data/oledb/codesnippet/cpp/begin-propset-map_1.h)]

### <a name="chain_property_set"></a><a name="chain_property_set"></a>CHAIN_PROPERTY_SET

Esta macro cadeia de propriedades se agrupa.

#### <a name="syntax"></a>Sintaxe

```cpp
CHAIN_PROPERTY_SET(ChainClass)
```

#### <a name="parameters"></a>Parâmetros

*ChainClass*<br/>
[em] O nome da classe para propriedades de cadeia para. Esta é uma classe gerada pelo Assistente de Projeto ATL que já contém um mapa (como uma sessão, comando ou classe de objeto de origem de dados).

#### <a name="remarks"></a>Comentários

Você pode acorrentar um conjunto de propriedades de outra classe para sua própria classe e, em seguida, acessar as propriedades diretamente de sua classe.

> [!CAUTION]
> Use esta macro com moderação. O uso inadequado pode fazer com que o consumidor falhe nos testes de conformidade do OLE DB.

### <a name="end_property_set"></a><a name="end_property_set"></a>END_PROPERTY_SET

Marca o fim de um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PROPERTY_SET(guid)
```

#### <a name="parameters"></a>Parâmetros

*Guid*<br/>
[em] A propriedade GUID.

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="end_propset_map"></a><a name="end_propset_map"></a>END_PROPSET_MAP

Marca o fim das entradas do mapa do conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PROPSET_MAP()
```

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="property_info_entry"></a><a name="property_info_entry"></a>PROPERTY_INFO_ENTRY

Representa uma propriedade específica em um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
PROPERTY_INFO_ENTRY(dwPropID)
```

#### <a name="parameters"></a>Parâmetros

*Dwpropid*<br/>
[em] Um valor [DBPROPID](/previous-versions/windows/desktop/ms723882(v=vs.85)) que pode ser usado em conjunto com o conjunto de propriedades GUID para identificar uma propriedade.

#### <a name="remarks"></a>Comentários

Esta macro define o `DWORD` valor de propriedade do tipo para um valor padrão definido no ATLDB. H. Para definir a propriedade como um valor de sua escolha, use [PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md). Para definir `VARTYPE` o [e DBPROPFLAGS](/previous-versions/windows/desktop/ms724342(v=vs.85)) para a propriedade ao mesmo tempo, use [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md).

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="property_info_entry_ex"></a><a name="property_info_entry_ex"></a>Property_info_entry_ex

Representa uma propriedade específica em um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
PROPERTY_INFO_ENTRY_EX(dwPropID, vt, dwFlags, value, options)
```

#### <a name="parameters"></a>Parâmetros

*Dwpropid*<br/>
[em] Um valor [DBPROPID](/previous-versions/windows/desktop/ms723882(v=vs.85)) que pode ser usado em conjunto com o conjunto de propriedades GUID para identificar uma propriedade.

*vt*<br/>
[em] A `VARTYPE` de entrada desta propriedade. (Definido em wtypes.h)

*dwFlags*<br/>
[em] Um valor [DBPROPFLAGS](/previous-versions/windows/desktop/ms724342(v=vs.85)) descrevendo esta entrada de propriedade.

*value*<br/>
[em] O valor da `DWORD`propriedade do tipo .

*Opções*<br/>
Seja DBPROPOPTIONS_REQUIRED ou DBPROPOPTIONS_SETIFCHEAP. Normalmente, um provedor não precisa definir *opções,* uma vez que é definido pelo consumidor.

#### <a name="remarks"></a>Comentários

Com esta macro, você pode especificar `DWORD` diretamente o valor da propriedade do tipo, bem como opções e bandeiras. Para definir apenas uma propriedade a um valor padrão definido no ATLDB. H, use [PROPERTY_INFO_ENTRY.](../../data/oledb/property-info-entry.md) Para definir um imóvel a um valor de sua escolha, sem definir opções ou bandeiras nele, use [PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md).

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="property_info_entry_value"></a><a name="property_info_entry_value"></a>Property_info_entry_value

Representa uma propriedade específica em um conjunto de propriedades.

#### <a name="syntax"></a>Sintaxe

```cpp
PROPERTY_INFO_ENTRY_VALUE(dwPropID, value)
```

#### <a name="parameters"></a>Parâmetros

*Dwpropid*<br/>
[em] Um valor [DBPROPID](/previous-versions/windows/desktop/ms723882(v=vs.85)) que pode ser usado em conjunto com o conjunto de propriedades GUID para identificar uma propriedade.

*value*<br/>
[em] O valor da `DWORD`propriedade do tipo .

#### <a name="remarks"></a>Comentários

Com esta macro, você pode especificar `DWORD`diretamente o valor da propriedade do tipo . Para definir a propriedade como valor padrão definido no ATLDB. H, use [PROPERTY_INFO_ENTRY.](../../data/oledb/property-info-entry.md) Para definir o valor, bandeiras e opções para a propriedade, use [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md).

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).

### <a name="begin_provider_column_map"></a><a name="begin_provider_column_map"></a>BEGIN_PROVIDER_COLUMN_MAP

Marca o início das entradas do mapa da coluna do provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_PROVIDER_COLUMN_MAP(theClass)
```

#### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
[em] O nome da classe a que este mapa pertence.

#### <a name="example"></a>Exemplo

Aqui está um mapa de coluna do provedor de amostras:

[!code-cpp[NVC_OLEDB_Provider#4](../../data/oledb/codesnippet/cpp/begin-provider-column-map_1.h)]

### <a name="end_provider_column_map"></a><a name="end_provider_column_map"></a>END_PROVIDER_COLUMN_MAP

Marca o fim das entradas do mapa da coluna do provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
END_PROVIDER_COLUMN_MAP()
```

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).

### <a name="provider_column_entry"></a><a name="provider_column_entry"></a>PROVIDER_COLUMN_ENTRY

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY (name, ordinal, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Membro*<br/>
[em] A variável `dataClass` membro correspondente à coluna.

### <a name="provider_column_entry_fixed"></a><a name="provider_column_entry_fixed"></a>PROVIDER_COLUMN_ENTRY_FIXED

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_FIXED(name, ordinal, dbtype, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Dbtype*<br/>
[em] O tipo de dados em [DBTYPE](/previous-versions/windows/desktop/ms711251(v=vs.85)).

*Membro*<br/>
[em] A variável `dataClass` membro em que armazena os dados.

#### <a name="remarks"></a>Comentários

Permite especificar o tipo de dados da coluna.

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).

### <a name="provider_column_entry_gn"></a><a name="provider_column_entry_gn"></a>PROVIDER_COLUMN_ENTRY_GN

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_GN (name, ordinal, flags, colSize, dbtype, precision, scale, guid)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Sinalizadores*<br/>
[em] Especifica como os dados são retornados. Consulte `dwFlags` a descrição em [ESTRUTURAS DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*colSize*<br/>
[em] O tamanho da coluna.

*Dbtype*<br/>
[em] Indica o tipo de dados do valor. Consulte `wType` a descrição em [ESTRUTURAS DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*precisão*<br/>
[em] Indica a precisão a ser usada ao obter dados se *o dbType* é DBTYPE_NUMERIC ou DBTYPE_DECIMAL. Consulte `bPrecision` a descrição em [ESTRUTURAS DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*scale*<br/>
[em] Indica a escala a ser usada ao obter dados se o dbType for DBTYPE_NUMERIC ou DBTYPE_DECIMAL. Consulte `bScale` a descrição em [ESTRUTURAS DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)).

*Guid*<br/>
Um esquema de linha GUIA. Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador OLE DB* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.

#### <a name="remarks"></a>Comentários

Permite especificar o tamanho da coluna, o tipo de dados, a precisão, a escala e o esquema do conjunto de linhas GUID.

### <a name="provider_column_entry_length"></a><a name="provider_column_entry_length"></a>PROVIDER_COLUMN_ENTRY_LENGTH

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_LENGTH(name, ordinal, size, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Tamanho*<br/>
[em] O tamanho da coluna em bytes.

*Membro*<br/>
[em] A variável `dataClass` membro em que armazena os dados da coluna.

#### <a name="remarks"></a>Comentários

Permite especificar o tamanho da coluna.

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).

### <a name="provider_column_entry_str"></a><a name="provider_column_entry_str"></a>PROVIDER_COLUMN_ENTRY_STR

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_STR(name, ordinal, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Membro*<br/>
[em] A variável membro na classe de dados que armazena os dados.

#### <a name="remarks"></a>Comentários

Use esta macro quando os dados da coluna forem [DBTYPE_STR](/previous-versions/windows/desktop/ms711251(v=vs.85)).

#### <a name="example"></a>Exemplo

Veja [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).

### <a name="provider_column_entry_type_length"></a><a name="provider_column_entry_type_length"></a>PROVIDER_COLUMN_ENTRY_TYPE_LENGTH

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_TYPE_LENGTH(name, ordinal, dbtype, size, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Dbtype*<br/>
[em] O tipo de dados em [DBTYPE](/previous-versions/windows/desktop/ms711251(v=vs.85)).

*Tamanho*<br/>
[em] O tamanho da coluna em bytes.

*Membro*<br/>
[em] A variável membro na classe de dados que armazena os dados.

#### <a name="remarks"></a>Comentários

Semelhante ao [PROVIDER_COLUMN_ENTRY_LENGTH](../../data/oledb/provider-column-entry-length.md) mas também permite especificar o tipo de dados da coluna, bem como o tamanho.

### <a name="provider_column_entry_wstr"></a><a name="provider_column_entry_wstr"></a>PROVIDER_COLUMN_ENTRY_WSTR

Representa uma coluna específica suportada pelo provedor.

#### <a name="syntax"></a>Sintaxe

```cpp
PROVIDER_COLUMN_ENTRY_WSTR(name, ordinal, member)
```

#### <a name="parameters"></a>Parâmetros

*name*<br/>
[em] O nome da coluna.

*Ordinal*<br/>
[em] O número da coluna. A menos que a coluna seja uma coluna marcador, o número da coluna não deve ser 0.

*Membro*<br/>
[em] A variável membro na classe de dados que armazena os dados.

#### <a name="remarks"></a>Comentários

Use esta macro quando os dados da coluna forem uma seqüência de caracteres Unicode nula, [DBTYPE_WSTR](/previous-versions/windows/desktop/ms711251(v=vs.85)).

### <a name="begin_schema_map"></a><a name="begin_schema_map"></a>BEGIN_SCHEMA_MAP

Denota o início de um mapa de esquemas.

#### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_SCHEMA_MAP(SchemaClass);
```

#### <a name="parameters"></a>Parâmetros

*Schemaclass*<br/>
A classe que contém o MAP. Normalmente esta será a aula de sessão.

#### <a name="remarks"></a>Comentários

Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) no Windows SDK para obter mais informações sobre conjuntos de linhas de esquema.

### <a name="end_schema_map"></a><a name="end_schema_map"></a>END_SCHEMA_MAP

Denota o fim do mapa do esquema.

#### <a name="syntax"></a>Sintaxe

```cpp
END_SCHEMA_MAP()
```

#### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IDBSchemaRowsetImpl Class](../../data/oledb/idbschemarowsetimpl-class.md).

### <a name="schema_entry"></a><a name="schema_entry"></a>SCHEMA_ENTRY

Associa um GUID com uma classe.

#### <a name="syntax"></a>Sintaxe

```cpp
SCHEMA_ENTRY(guid,
   rowsetClass);
```

#### <a name="parameters"></a>Parâmetros

*Guid*<br/>
Um esquema de linha GUIA. Consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) na *referência do programador OLE DB* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.

*conjunto de linhasClasse*<br/>
A classe que será criada para representar o conjunto de linhas de esquema.

#### <a name="remarks"></a>Comentários

[O IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) pode então consultar o mapa de uma lista de GUIDs, ou pode criar um conjunto de linhas se receber um GUID. O conjunto de `IDBSchemaRowsetImpl` linhas de esquema `CRowsetImpl`criado é semelhante a uma `Execute` classe derivada padrão, exceto que deve fornecer um método que tenha a seguinte assinatura:

```cpp
HRESULT Execute (LONG* pcRowsAffected,
    ULONG cRestrictions,
    const VARIANT* rgRestrictions);
```

Esta `Execute` função preenche os dados do conjunto de linhas. O Assistente de Projeto ATL cria, conforme descrito no [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85)) no *OLE DB Programmer's Reference*, três conjuntos de linhas de esquema inicial no projeto para cada um dos três esquemas obrigatórios do OLE DB:

- DBSCHEMA_TABLES

- DBSCHEMA_COLUMNS

- DBSCHEMA_PROVIDER_TYPES

O assistente também adiciona três entradas correspondentes no mapa do esquema. Consulte [Criando um Provedor de Modelos OLE DB](../../data/oledb/creating-an-ole-db-provider.md) para obter mais informações sobre o uso do assistente para criar um provedor.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura do modelo do provedor OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Criando um provedor OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
[Referência de modelos do provedor OLE DB](../../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Macros para modelos de provedor OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)

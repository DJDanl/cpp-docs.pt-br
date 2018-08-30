---
title: Macros para modelos de provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- vc.templates.ole
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e2456eed4f55fe5a5f68552cfe91e5785fc99cf5
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209015"
---
# <a name="macros-for-ole-db-provider-templates"></a>Macros para modelos de provedor de banco de dados OLE
As macros do provedor OLE DB modelos oferecem funcionalidade nas seguintes categorias:  
  
## <a name="property-set-map-macros"></a>Macros de mapa do conjunto de propriedade  
  
|||  
|-|-|  
|[BEGIN_PROPERTY_SET](#begin_property_set)|Marca o início de um conjunto de propriedades.|  
|[BEGIN_PROPERTY_SET_EX](#begin_property_set_ex)|Marca o início de um conjunto de propriedades.|  
|[BEGIN_PROPSET_MAP](#begin_propset_map)|As marcas de que início de uma propriedade definida que podem ser ocultadas ou definidas fora do escopo do provedor.|  
|[CHAIN_PROPERTY_SET](#chain_property_set)|Encadeia grupos de propriedades.|  
|[END_PROPERTY_SET](#end_property_set)|Marca o fim de um conjunto de propriedades.|  
|[END_PROPSET_MAP](#end_propset_map)|Marca o final de um mapa de conjunto de propriedade.|  
|[PROPERTY_INFO_ENTRY](#property_info_entry)|Define uma propriedade específica em uma propriedade definida como um valor padrão.|  
|[PROPERTY_INFO_ENTRY_EX](#property_info_entry_ex)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você. Também permite que você definir as opções e sinalizadores.|  
|[PROPERTY_INFO_ENTRY_VALUE](#property_info_entry_value)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você.|  
  
## <a name="column-map-macros"></a>Macros de mapa de coluna  
  
|||  
|-|-|  
|[BEGIN_PROVIDER_COLUMN_MAP](#begin_provider_column_map)|Marca o início das entradas de mapa de coluna de provedor.|  
|[END_PROVIDER_COLUMN_MAP](#end_provider_column_map)|Marca o fim das entradas de mapa de coluna de provedor.|  
|[PROVIDER_COLUMN_ENTRY](#provider_column_entry)|Representa uma coluna específica com suporte pelo provedor.|  
|[PROVIDER_COLUMN_ENTRY_FIXED](#provider_column_entry_fixed)|Representa uma coluna específica com suporte pelo provedor. Você pode especificar o tipo de dados de coluna.|  
|[PROVIDER_COLUMN_ENTRY_GN](#provider_column_entry_gn)|Representa uma coluna específica com suporte pelo provedor. Você pode especificar o tamanho da coluna, tipo de dados, precisão, escala e linhas de esquema GUID.|  
|[PROVIDER_COLUMN_ENTRY_LENGTH](#provider_column_entry_length)|Representa uma coluna específica com suporte pelo provedor. Você pode especificar o tamanho da coluna.|  
|[PROVIDER_COLUMN_ENTRY_STR](#provider_column_entry_str)|Representa uma coluna específica com suporte pelo provedor. Ele pressupõe que o tipo de coluna é uma cadeia de caracteres.|  
|[PROVIDER_COLUMN_ENTRY_TYPE_LENGTH](#provider_column_entry_type_length)|Representa uma coluna específica com suporte pelo provedor. Como PROVIDER_COLUMN_ENTRY_LENGTH, mas também permite que você especifique o tipo de dados da coluna, bem como o tamanho.|  
|[PROVIDER_COLUMN_ENTRY_WSTR](#provider_column_entry_wstr)|Representa uma coluna específica com suporte pelo provedor. Ele pressupõe que o tipo de coluna é uma cadeia de caracteres Unicode.|  
  
## <a name="schema-rowset-macros"></a>Macros de conjunto de linhas de esquema  
  
|||  
|-|-|  
|[BEGIN_SCHEMA_MAP](#begin_schema_map)|Marca o início de um mapa de esquema.|  
|[END_SCHEMA_MAP](#end_schema_map)|Marca o final de um mapa de esquema.|  
|[SCHEMA_ENTRY](#schema_entry)|Associa um GUID de uma classe.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  

### <a name="begin_property_set"></a> BEGIN_PROPERTY_SET
As marcas de de que início de uma propriedade definido em uma propriedade definir o mapa.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PROPERTY_SET(guid)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *guid*  
 [in] A propriedade GUID.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="begin_property_set_ex"></a> BEGIN_PROPERTY_SET_EX
As marcas de de que início de uma propriedade definido em uma propriedade definir o mapa.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PROPERTY_SET_EX(guid, flags)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *guid*  
 [in] A propriedade GUID.  
  
 *flags*  
 [in] UPROPSET_HIDDEN para quaisquer conjuntos de propriedades que você não deseja expor ou UPROPSET_PASSTHROUGH para um provedor de expor as propriedades definidas fora do escopo do provedor.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="begin_propset_map"></a> BEGIN_PROPSET_MAP
As marcas de início da propriedade definir entradas de mapa.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PROPSET_MAP(Class)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Class*  
 [in] A classe na qual essa propriedade definida é especificada. Um conjunto de propriedades pode ser especificado nos seguintes objetos OLE DB:  
  
-   [Objetos de fonte de dados](/previous-versions/windows/desktop/ms721278\(v=vs.85\))  
  
-   [Objetos de sessão](/previous-versions/windows/desktop/ms711572\(v=vs.85\))  
  
-   [Comandos](/previous-versions/windows/desktop/ms724608\(v=vs.85\))  
  
#### <a name="example"></a>Exemplo  
 Aqui está um exemplo de mapa de conjunto de propriedade:  
  
 [!code-cpp[NVC_OLEDB_Provider#3](../../data/oledb/codesnippet/cpp/begin-propset-map_1.h)]  

### <a name="chain_property_set"></a> CHAIN_PROPERTY_SET
Essa macro encadeia grupos de propriedades.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
CHAIN_PROPERTY_SET(ChainClass)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *ChainClass*  
 [in] O nome da classe para propriedades de cadeia para. Esta é uma classe gerada pelo Assistente de projeto de ATL que já contém um mapa (por exemplo, uma sessão, comando ou dados de origem classe de objeto).  
  
#### <a name="remarks"></a>Comentários  
 Você pode encadear um conjunto de propriedades de outra classe para sua própria classe e acessar as propriedades diretamente da sua classe.  
  
> [!CAUTION]
>  Use esta macro com moderação. Uso inadequado pode fazer com que um consumidor realizar os testes de conformidade com OLE DB.  

### <a name="end_property_set"></a> END_PROPERTY_SET
Marca o fim de um conjunto de propriedades.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_PROPERTY_SET(guid)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *guid*  
 [in] A propriedade GUID.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="end_propset_map"></a> END_PROPSET_MAP
As marcas de final de propriedade definir entradas de mapa.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_PROPSET_MAP()  
```  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="property_info_entry"></a> PROPERTY_INFO_ENTRY
Representa uma propriedade específica em um conjunto de propriedades.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROPERTY_INFO_ENTRY(dwPropID)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropID*  
 [in] Um [DBPROPID](/previous-versions/windows/desktop/ms723882\(v=vs.85\)) GUID para identificar uma propriedade do conjunto de valor que pode ser usado em conjunto com a propriedade.  
  
#### <a name="remarks"></a>Comentários  
 Essa macro define o valor da propriedade do tipo `DWORD` para um valor padrão definido em ATLDB. H. Para definir a propriedade como um valor de sua escolha, use [PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md). Para definir a [VARTYPE](https://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) e [DBPROPFLAGS](/previous-versions/windows/desktop/ms724342\(v=vs.85\)) para a propriedade ao mesmo tempo, use [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md).  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="property_info_entry_ex"></a> PROPERTY_INFO_ENTRY_EX
Representa uma propriedade específica em um conjunto de propriedades.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROPERTY_INFO_ENTRY_EX(dwPropID, vt, dwFlags, value, options)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropID*  
 [in] Um [DBPROPID](/previous-versions/windows/desktop/ms723882\(v=vs.85\)) GUID para identificar uma propriedade do conjunto de valor que pode ser usado em conjunto com a propriedade.  
  
 *vt*  
 [in] O [VARTYPE](https://msdn.microsoft.com/317b911b-1805-402d-a9cb-159546bc88b4) desta entrada de propriedade.  
  
 *dwFlags*  
 [in] Um [DBPROPFLAGS](/previous-versions/windows/desktop/ms724342\(v=vs.85\)) valor que descreve esta entrada de propriedade.  
  
 *value*  
 [in] O valor da propriedade do tipo `DWORD`.  
  
 *Opções*  
 DBPROPOPTIONS_REQUIRED ou DBPROPOPTIONS_SETIFCHEAP. Normalmente, um provedor não precisa definir *opções* , pois ele é definido pelo consumidor.  
  
#### <a name="remarks"></a>Comentários  
 Com essa macro, você pode especificar diretamente o valor da propriedade do tipo `DWORD` , bem como opções e os sinalizadores. Simplesmente definir uma propriedade para um valor padrão definido em ATLDB. H, use [PROPERTY_INFO_ENTRY](../../data/oledb/property-info-entry.md). Para definir uma propriedade com um valor de sua escolha, sem opções de configuração ou sinalizadores, use [PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md).  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="property_info_entry_value"></a> PROPERTY_INFO_ENTRY_VALUE
Representa uma propriedade específica em um conjunto de propriedades.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROPERTY_INFO_ENTRY_VALUE(dwPropID, value)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropID*  
 [in] Um [DBPROPID](/previous-versions/windows/desktop/ms723882\(v=vs.85\)) GUID para identificar uma propriedade do conjunto de valor que pode ser usado em conjunto com a propriedade.  
  
 *value*  
 [in] O valor da propriedade do tipo `DWORD`.  
  
#### <a name="remarks"></a>Comentários  
 Com essa macro, você pode especificar diretamente o valor da propriedade do tipo `DWORD`. Para definir a propriedade para o valor padrão definido no ATLDB. H, use [PROPERTY_INFO_ENTRY](../../data/oledb/property-info-entry.md). Para definir o valor, sinalizadores e opções para a propriedade, use [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md).  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

### <a name="begin_provider_column_map"></a> BEGIN_PROVIDER_COLUMN_MAP
Marca o início das entradas de mapa de coluna de provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PROVIDER_COLUMN_MAP(theClass)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *theClass*  
 [in] O nome da classe que esse mapa pertence.  
  
#### <a name="example"></a>Exemplo  
 Aqui está um exemplo de mapa de coluna de provedor:  
  
 [!code-cpp[NVC_OLEDB_Provider#4](../../data/oledb/codesnippet/cpp/begin-provider-column-map_1.h)]  

### <a name="end_provider_column_map"></a> END_PROVIDER_COLUMN_MAP
Marca o fim das entradas de mapa de coluna de provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_PROVIDER_COLUMN_MAP()  
```  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).  

### <a name="provider_column_entry"></a> PROVIDER_COLUMN_ENTRY
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY (name, ordinal, member)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *Membro*  
 [in] A variável de membro em `dataClass` corresponde à coluna.  

### <a name="provider_column_entry_fixed"></a> PROVIDER_COLUMN_ENTRY_FIXED
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_FIXED(name, ordinal, dbtype, member)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *DbType*  
 [in] O tipo de dados no [DBTYPE](/previous-versions/windows/desktop/ms711251\(v=vs.85\)).  
  
 *Membro*  
 [in] A variável de membro em `dataClass` que armazena os dados.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique o tipo de dados de coluna.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).  

### <a name="provider_column_entry_gn"></a> PROVIDER_COLUMN_ENTRY_GN
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_GN (name, ordinal, flags, colSize, dbtype, precision, scale, guid)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *flags*  
 [in] Especifica como os dados são retornados. Consulte a `dwFlags` descrição na [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845\(v=vs.85\)).  
  
 *colSize*  
 [in] O tamanho da coluna.  
  
 *DbType*  
 [in] Indica o tipo de dados do valor. Consulte a `wType` descrição na [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845\(v=vs.85\)).  
  
 *precision*  
 [in] Indica a precisão a ser usado ao obter dados, se *dbType* é DBTYPE_NUMERIC ou DBTYPE_DECIMAL. Consulte a `bPrecision` descrição na [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845\(v=vs.85\)).  
  
 *Escala*  
 [in] Indica a escala a ser usado ao obter dados, se o dbType é DBTYPE_NUMERIC ou DBTYPE_DECIMAL. Consulte a `bScale` descrição na [estruturas DBBINDING](/previous-versions/windows/desktop/ms716845\(v=vs.85\)).  
  
 *guid*  
 Um conjunto de linhas do esquema GUID. Ver [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) na *referência do programador DB OLE* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique o tamanho da coluna, tipo de dados, precisão, escala e linhas de esquema GUID.  

### <a name="provider_column_entry_length"></a> PROVIDER_COLUMN_ENTRY_LENGTH
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_LENGTH(name, ordinal, size, member)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *size*  
 [in] O tamanho da coluna em bytes.  
  
 *Membro*  
 [in] A variável de membro em `dataClass` que armazena os dados da coluna.  
  
#### <a name="remarks"></a>Comentários  
 Permite que você especifique o tamanho da coluna.  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md). 

### <a name="provider_column_entry_str"></a> PROVIDER_COLUMN_ENTRY_STR
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_STR(name, ordinal, member)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *Membro*  
 [in] A variável de membro na classe de dados que armazena os dados.  
  
#### <a name="remarks"></a>Comentários  
 Usar essa macro, quando os dados da coluna são considerados [DBTYPE_STR](/previous-versions/windows/desktop/ms711251\(v=vs.85\)).  
  
#### <a name="example"></a>Exemplo  
 Ver [BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md).   

### <a name="provider_column_entry_type_length"></a> PROVIDER_COLUMN_ENTRY_TYPE_LENGTH
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_TYPE_LENGTH(name, ordinal, dbtype, size, member)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *DbType*  
 [in] O tipo de dados no [DBTYPE](/previous-versions/windows/desktop/ms711251\(v=vs.85\)).  
  
 *size*  
 [in] O tamanho da coluna em bytes.  
  
 *Membro*  
 [in] A variável de membro na classe de dados que armazena os dados.  
  
#### <a name="remarks"></a>Comentários  
 Semelhante ao [PROVIDER_COLUMN_ENTRY_LENGTH](../../data/oledb/provider-column-entry-length.md) , mas também permite que você especifique o tipo de dados da coluna, bem como o tamanho.  

### <a name="provider_column_entry_wstr"></a> PROVIDER_COLUMN_ENTRY_WSTR
Representa uma coluna específica com suporte pelo provedor.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_WSTR(name, ordinal, member)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 *Ordinal*  
 [in] O número da coluna. A menos que a coluna for uma coluna de indicador, o número da coluna não deve ser 0.  
  
 *Membro*  
 [in] A variável de membro na classe de dados que armazena os dados.  
  
#### <a name="remarks"></a>Comentários  
 Usar essa macro, quando os dados da coluna são um valor nulo terminado em cadeia de caracteres de Unicode [DBTYPE_WSTR](/previous-versions/windows/desktop/ms711251\(v=vs.85\)).  

### <a name="begin_schema_map"></a> BEGIN_SCHEMA_MAP
Indica o início de um mapa de esquema.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_SCHEMA_MAP(SchemaClass);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *SchemaClass*  
 A classe que contém o mapa. Normalmente, isso será a classe de sessão.  
  
#### <a name="remarks"></a>Comentários  
 Ver [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) no SDK do Windows para obter mais informações sobre conjuntos de linhas de esquema.  

### <a name="end_schema_map"></a> END_SCHEMA_MAP
Indica o fim do mapa de esquema.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
END_SCHEMA_MAP()  
```  
  
#### <a name="see-also"></a>Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)

### <a name="schema_entry"></a> SCHEMA_ENTRY
Associa um GUID de uma classe.  
  
#### <a name="syntax"></a>Sintaxe  
  
```cpp
SCHEMA_ENTRY(guid,  
   rowsetClass);   
```  
  
#### <a name="parameters"></a>Parâmetros  
 *guid*  
 Um conjunto de linhas do esquema GUID. Ver [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) na *referência do programador DB OLE* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.  
  
 *rowsetClass*  
 A classe que será criada para representar o conjunto de linhas de esquema.  
  
#### <a name="remarks"></a>Comentários  
 [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) pode, em seguida, consulta o mapa para obter uma lista de GUIDs, ou pode criar um conjunto de linhas se ela recebe um GUID. O conjunto de linhas de esquema `IDBSchemaRowsetImpl` cria é semelhante a um padrão `CRowsetImpl`-derivado de classe, exceto que ele deve fornecer um `Execute` método que tem a seguinte assinatura:  
  
```cpp  
HRESULT Execute (LONG* pcRowsAffected,  
    ULONG cRestrictions,  
    const VARIANT* rgRestrictions);  
```  
  
 Isso `Execute` função preenche os dados do conjunto de linhas. A ATL Project Wizard cria, conforme descrito em [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) na *referência do programador DB OLE*, três inicial conjuntos de linhas de esquema no projeto para cada um dos três esquemas de banco de dados OLE obrigatórios:  
  
-   DBSCHEMA_TABLES  
  
-   DBSCHEMA_COLUMNS  
  
-   DBSCHEMA_PROVIDER_TYPES  
  
 O assistente também adiciona três entradas correspondentes no mapa de esquema. Ver [criando um provedor OLE DB modelo](../../data/oledb/creating-an-ole-db-provider.md) para obter mais informações sobre como usar o Assistente para criar um provedor.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)   
 [Referência de modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-reference.md)    
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
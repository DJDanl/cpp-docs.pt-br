---
title: Macros para modelos de provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- vc.templates.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE DB provider templates, macros
- macros, OLE DB Provider Templates
- Provider Template macros (OLE DB)
- OLE DB Provider Template macros
ms.assetid: 909482c5-64ab-4e52-84a9-1c07091db183
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ab7611c49f625a36023b4e31bf6aff47ab16f156
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33111726"
---
# <a name="macros-for-ole-db-provider-templates"></a>Macros para modelos de provedor de banco de dados OLE
As macros do provedor OLE DB modelos oferecem funcionalidade nas seguintes categorias:  
  
### <a name="property-set-map-macros"></a>Macros de mapa do conjunto de propriedade  
  
|||  
|-|-|  
|[BEGIN_PROPERTY_SET](../../data/oledb/begin-property-set.md)|Marca o início de um conjunto de propriedades.|  
|[BEGIN_PROPERTY_SET_EX](../../data/oledb/begin-property-set-ex.md)|Marca o início de um conjunto de propriedades.|  
|[BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md)|As marcas de que início de uma propriedade definida que podem ser ocultadas ou definidas fora do escopo do provedor.|  
|[CHAIN_PROPERTY_SET](../../data/oledb/chain-property-set.md)|Grupos de propriedade cadeias juntos.|  
|[END_PROPERTY_SET](../../data/oledb/end-property-set.md)|Marca o fim de um conjunto de propriedades.|  
|[END_PROPSET_MAP](../../data/oledb/end-propset-map.md)|Marca o fim de um mapa de conjunto de propriedade.|  
|[PROPERTY_INFO_ENTRY](../../data/oledb/property-info-entry.md)|Define uma propriedade específica em uma propriedade definida como um valor padrão.|  
|[PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você. Também permite que você definir as opções e sinalizadores.|  
|[PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md)|Define uma propriedade específica em uma propriedade definida como um valor fornecido por você.|  
  
### <a name="column-map-macros"></a>Macros de mapa de coluna  
  
|||  
|-|-|  
|[BEGIN_PROVIDER_COLUMN_MAP](../../data/oledb/begin-provider-column-map.md)|Marca o início das entradas do mapa de coluna do provedor.|  
|[END_PROVIDER_COLUMN_MAP](../../data/oledb/end-provider-column-map.md)|Marca o fim das entradas de mapa de coluna do provedor.|  
|[PROVIDER_COLUMN_ENTRY](../../data/oledb/provider-column-entry.md)|Representa uma coluna específica suportada pelo provedor.|  
|[PROVIDER_COLUMN_ENTRY_GN](../../data/oledb/provider-column-entry-gn.md)|Representa uma coluna específica suportada pelo provedor. Você pode especificar o tamanho da coluna, tipo de dados, precisão, escala e linhas de esquema GUID.|  
|[PROVIDER_COLUMN_ENTRY_FIXED](../../data/oledb/provider-column-entry-fixed.md)|Representa uma coluna específica suportada pelo provedor. Você pode especificar o tipo de dados de coluna.|  
|[PROVIDER_COLUMN_ENTRY_LENGTH](../../data/oledb/provider-column-entry-length.md)|Representa uma coluna específica suportada pelo provedor. Você pode especificar o tamanho da coluna.|  
|[PROVIDER_COLUMN_ENTRY_STR](../../data/oledb/provider-column-entry-str.md)|Representa uma coluna específica suportada pelo provedor. Ele pressupõe que o tipo de coluna é uma cadeia de caracteres.|  
|[PROVIDER_COLUMN_ENTRY_TYPE_LENGTH](../../data/oledb/provider-column-entry-type-length.md)|Representa uma coluna específica suportada pelo provedor. Como PROVIDER_COLUMN_ENTRY_LENGTH, mas também permite que você especifique o tipo de dados da coluna, bem como o tamanho.|  
|[PROVIDER_COLUMN_ENTRY_WSTR](../../data/oledb/provider-column-entry-wstr.md)|Representa uma coluna específica suportada pelo provedor. Ele pressupõe que o tipo de coluna é uma cadeia de caracteres Unicode.|  
  
### <a name="schema-rowset-macros"></a>Macros de conjunto de linhas de esquema  
  
|||  
|-|-|  
|[BEGIN_SCHEMA_MAP](../../data/oledb/begin-schema-map.md)|Marca o início de um mapa de esquema.|  
|[SCHEMA_ENTRY](../../data/oledb/schema-entry.md)|Associa um GUID de uma classe.|  
|[END_SCHEMA_MAP](../../data/oledb/end-schema-map.md)|Marca o fim de um mapa de esquema.|  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)   
 [Referência dos modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-reference.md)
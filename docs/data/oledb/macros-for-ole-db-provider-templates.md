---
title: "Macros para modelos de provedor de banco de dados OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.templates.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macros , Modelos de provedor de banco de dados OLE"
  - "Macros de Modelo de Provedor de OLE DB"
  - "modelos de provedor do OLE DB, Macros "
  - "Macros de Modelo de Provedor (OLE DB)"
ms.assetid: 909482c5-64ab-4e52-84a9-1c07091db183
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros para modelos de provedor de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Macros do provedor de modelos OLE DB oferecem funcionalidades nas seguintes categorias:  
  
### Macros do conjunto de propriedades  
  
|||  
|-|-|  
|[BEGIN\_PROPERTY\_SET](../../data/oledb/begin-property-set.md)|Marca o início de um conjunto de propriedades.|  
|[BEGIN\_PROPERTY\_SET\_EX](../../data/oledb/begin-property-set-ex.md)|Marca o início de um conjunto de propriedades.|  
|[BEGIN\_PROPSET\_MAP](../Topic/BEGIN_PROPSET_MAP.md)|Marca o início de um conjunto de propriedades que pode ser ocultado ou definido fora do escopo do provedor.|  
|[CHAIN\_PROPERTY\_SET](../Topic/CHAIN_PROPERTY_SET.md)|A propriedade das cadeias grupos juntos.|  
|[END\_PROPERTY\_SET](../../data/oledb/end-property-set.md)|Marca o fim de um conjunto de propriedades.|  
|[END\_PROPSET\_MAP](../../data/oledb/end-propset-map.md)|Marca o fim de um mapa do conjunto de propriedades.|  
|[PROPERTY\_INFORMATION\_ENTRY](../../data/oledb/property-info-entry.md)|Define uma propriedade específica em um conjunto de propriedades com um valor padrão.|  
|[PROPERTY\_INFORMATION\_ENTRY\_EX](../../data/oledb/property-info-entry-ex.md)|Define uma propriedade específica em um conjunto de propriedades a um valor fornecido por você.  Também permite definir sinalizadores as opções e.|  
|[PROPERTY\_INFORMATION\_ENTRY\_VALUE](../../data/oledb/property-info-entry-value.md)|Define uma propriedade específica em um conjunto de propriedades a um valor fornecido por você.|  
  
### Macros da coluna  
  
|||  
|-|-|  
|[BEGIN\_PROVIDER\_COLUMN\_MAP](../../data/oledb/begin-provider-column-map.md)|Marca o início das entradas da coluna do provedor.|  
|[END\_PROVIDER\_COLUMN\_MAP](../../data/oledb/end-provider-column-map.md)|Marca o término das entradas da coluna do provedor.|  
|[PROVIDER\_COLUMN\_ENTRY](../../data/oledb/provider-column-entry.md)|Representa uma coluna específica com suporte do provedor.|  
|[PROVIDER\_COLUMN\_ENTRY\_GN](../../data/oledb/provider-column-entry-gn.md)|Representa uma coluna específica com suporte do provedor.  Você pode especificar o tamanho, o tipo de dados, precisão, escala, e o conjunto de linhas de esquema GUID da coluna.|  
|[PROVIDER\_COLUMN\_ENTRY\_FIXED](../Topic/PROVIDER_COLUMN_ENTRY_FIXED.md)|Representa uma coluna específica com suporte do provedor.  Você pode especificar o tipo de dados da coluna.|  
|[PROVIDER\_COLUMN\_ENTRY\_LENGTH](../../data/oledb/provider-column-entry-length.md)|Representa uma coluna específica com suporte do provedor.  Você pode especificar o tamanho da coluna.|  
|[PROVIDER\_COLUMN\_ENTRY\_STR](../../data/oledb/provider-column-entry-str.md)|Representa uma coluna específica com suporte do provedor.  Assume o tipo de coluna for uma cadeia de caracteres.|  
|[PROVIDER\_COLUMN\_ENTRY\_TYPE\_LENGTH](../../data/oledb/provider-column-entry-type-length.md)|Representa uma coluna específica com suporte do provedor.  Como PROVIDER\_COLUMN\_ENTRY\_LENGTH, mas também permite que você especifique o tipo de dados assim como o tamanho da coluna.|  
|[PROVIDER\_COLUMN\_ENTRY\_WSTR](../../data/oledb/provider-column-entry-wstr.md)|Representa uma coluna específica com suporte do provedor.  Assume o tipo de coluna for uma cadeia de caracteres Unicode.|  
  
### Macros do conjunto de linhas de esquema  
  
|||  
|-|-|  
|[BEGIN\_SCHEMA\_MAP](../../data/oledb/begin-schema-map.md)|Marca o início de um mapa de esquema.|  
|[SCHEMA\_ENTRY](../../data/oledb/schema-entry.md)|Associa um GUID com uma classe.|  
|[END\_SCHEMA\_MAP](../../data/oledb/end-schema-map.md)|Marca o fim de um mapa de esquema.|  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)   
 [Referência dos modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-reference.md)
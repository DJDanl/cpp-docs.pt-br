---
title: "Classe IDBSchemaRowsetImpl | Microsoft Docs"
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
  - "IDBSchemaRowsetImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IDBSchemaRowsetImpl"
ms.assetid: bd7bf0d7-a1c6-4afa-88e3-cfdbdf560703
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IDBSchemaRowsetImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a implementação para conjuntos de linhas do esquema.  
  
## Sintaxe  
  
```  
template <class SessionClass>  
class ATL_NO_VTABLE IDBSchemaRowsetImpl : public IDBSchemaRowset  
```  
  
#### Parâmetros  
 `SessionClass`  
 A classe pelo qual `IDBSchemaRowsetImpl` é herdada. Normalmente, essa classe será classe da sessão do usuário.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CheckRestrictions](../../data/oledb/idbschemarowsetimpl-checkrestrictions.md)|Verifica a validade das restrições em relação a um conjunto de linhas do esquema.|  
|[CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md)|Implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.|  
|[SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md)|Especifica quais restrições de suporte em um conjunto de linhas de esquema específico.|  
  
### Métodos de interface  
  
|||  
|-|-|  
|[GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md)|Retorna um conjunto de linhas do esquema.|  
|[GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md)|Retorna uma lista de conjuntos de linhas de esquema acessível por [idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md).|  
  
## Comentários  
 Essa classe implementa o [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) interface e a função do criador de modelos [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md).  
  
 OLE DB usa conjuntos de linhas de esquema para retornar dados sobre os dados em um provedor. Esses dados geralmente são chamados de "metadados". Por padrão, um provedor deve oferecer suporte sempre `DBSCHEMA_TABLES`, **DBSCHEMA\_COLUMNS**, e **DBSCHEMA\_PROVIDER\_TYPES**, conforme descrito em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador DB OLE*. Conjuntos de linhas de esquema são indicados em um mapa de esquema. Para obter informações sobre as entradas de mapa de esquema, consulte [SCHEMA\_ENTRY](../../data/oledb/schema-entry.md).  
  
 O OLE DB Provider Wizard, no Assistente de objeto ATL, gera automaticamente o código para os conjuntos de linhas de esquema em seu projeto. \(Por padrão, o assistente oferece suporte os conjuntos de linhas de esquema obrigatório mencionados anteriormente.\) Quando você cria um consumidor usando o Assistente de objeto ATL, o assistente usa conjuntos de linhas de esquema para associar os dados corretos para um provedor. Se você não implementar seus conjuntos de linhas de esquema para fornecer os metadados correto, o assistente não irá vincular os dados corretos.  
  
 Para obter informações sobre como oferecer suporte a conjuntos de linhas de esquema no provedor, consulte [suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
 Para obter mais informações sobre conjuntos de linhas de esquema, consulte [conjuntos de linhas do esquema](https://msdn.microsoft.com/en-us/library/ms712921.aspx) no *referência do programador DB OLE*.  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [IDBSchemaRowsetImpl Class Members](http://msdn.microsoft.com/pt-br/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)   
 [Dando suporte a conjuntos de linhas do esquema](../../data/oledb/supporting-schema-rowsets.md)
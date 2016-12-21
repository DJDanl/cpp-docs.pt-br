---
title: "IDBSchemaRowsetImpl::CheckRestrictions | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CheckRestrictions"
  - "IDBSchemaRowsetImpl::CheckRestrictions"
  - "IDBSchemaRowsetImpl.CheckRestrictions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CheckRestrictions"
ms.assetid: 3c9d77d2-0e4b-48fa-80db-d735da19f1cf
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBSchemaRowsetImpl::CheckRestrictions
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica a validade das restrições em relação a um conjunto de linhas do esquema.  
  
## Sintaxe  
  
```  
  
HRESULT CheckRestrictions(  
   REFGUID   
rguidSchema  
,  
   ULONG   
cRestrictions  
,  
   const VARIANT   
rgRestrictions  
[]  
);  
  
```  
  
#### Parâmetros  
 `rguidSchema`  
 \[in\] Uma referência para o GUID do conjunto de linhas de esquema solicitado \(por exemplo, `DBSCHEMA_TABLES`\).  
  
 `cRestrictions`  
 \[in\] O número de restrições que o consumidor passado para o conjunto de linhas do esquema.  
  
 `rgRestrictions`  
 \[in\] Uma matriz de comprimento *cRestrictions* de valores de restrição a ser definido. Para obter mais informações, consulte a descrição do `rgRestrictions` parâmetro em [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).  
  
## Comentários  
 Use `CheckRestrictions` para verificar a validade das restrições em relação a um conjunto de linhas do esquema. Ele verifica restrições para `DBSCHEMA_TABLES`, **DBSCHEMA\_COLUMNS**, e **DBSCHEMA\_PROVIDER\_TYPES** conjuntos de linhas do esquema. Chamá\-lo para determinar se um consumidor chamar **IDBSchemaRowset:: Getrowset** está correto. Se você deseja oferecer suporte a conjuntos de linhas de esquema diferentes daqueles listados acima, você deve criar sua própria função para realizar essa tarefa.  
  
 `CheckRestrictions` Determina se o consumidor está chamando [GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) com a restrição correta e o tipo de restrição correto \(por exemplo, um `VT_BSTR` para uma cadeia de caracteres\) que o provedor oferece suporte. Ele também determina se o número correto de restrições é suportado. Por padrão, `CheckRestrictions` solicitará que o provedor, por meio de [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) chamar, quais restrições que ele oferece suporte em um determinado conjunto de linhas. Ele então compara as restrições do consumidor contra aqueles suportados pelo provedor e o êxito ou falha.  
  
 Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [IDBSchemaRowsetImpl Class Members](http://msdn.microsoft.com/pt-br/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)
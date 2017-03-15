---
title: "IDBSchemaRowsetImpl::SetRestrictions | Microsoft Docs"
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
  - "IDBSchemaRowsetImpl::SetRestrictions"
  - "SetRestrictions"
  - "IDBSchemaRowsetImpl.SetRestrictions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetRestrictions"
ms.assetid: 707d5065-b853-4d38-9b67-3066b4d3b279
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBSchemaRowsetImpl::SetRestrictions
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica quais restrições de suporte em um conjunto de linhas de esquema específico.  
  
## Sintaxe  
  
```  
  
void SetRestrictions(  
   ULONG   
cRestrictions  
,  
   GUID* /*   
rguidSchema  
*/,  
   ULONG*   
rgRestrictions  
);  
  
```  
  
#### Parâmetros  
 `cRestrictions`  
 \[in\] O número de restrições a `rgRestrictions` matriz e o número de GUIDs na `rguidSchema` matriz.  
  
 `rguidSchema`  
 \[in\] Uma matriz de GUIDs de conjuntos de linhas de esquema para o qual buscar restrições. Cada elemento da matriz contém o GUID do conjunto de linhas de um esquema \(por exemplo, `DBSCHEMA_TABLES`\).  
  
 `rgRestrictions`  
 \[in\] Uma matriz de comprimento `cRestrictions` dos valores de restrição a ser definido. Cada elemento corresponde às restrições no conjunto de linhas de esquema identificado pelo GUID. Se o provedor não dá suporte a um conjunto de linhas de esquema, o elemento é definido como zero. Caso contrário, o **ULONG** valor contém uma máscara de bits que representa as restrições de suporte nesse conjunto de linhas do esquema. Para obter mais informações nos quais restrições correspondem a um conjunto de linhas de esquema específico, consulte a tabela de linhas de esquema GUIDs em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Comentários  
 O **IDBSchemaRowset** objeto chamadas `SetRestrictions` para determinar quais restrições de suporte em um conjunto de linhas de esquema específico \(ele é chamado por [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) por meio de um ponteiro upcasted\). Restrições de permitir que os consumidores de busca somente as linhas correspondentes \(por exemplo, localizar todas as colunas na tabela "MyTable"\). As restrições são opcionais e, no caso em que nenhum são suportados \(o padrão\), todos os dados são sempre retornadas.  
  
 A implementação padrão desse método define a `rgRestrictions` matriz elementos como 0. Substitua o padrão em sua classe de sessão para definir restrições que não seja o padrão.  
  
 Para obter informações sobre como implementar o suporte ao conjunto de linhas de esquema, consulte [suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
 Para obter um exemplo de um provedor que dá suporte a conjuntos de linhas de esquema, consulte o [UpdatePV](../../top/visual-cpp-samples.md) exemplo.  
  
 Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [IDBSchemaRowsetImpl Class Members](http://msdn.microsoft.com/pt-br/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)   
 [Dando suporte a conjuntos de linhas do esquema](../../data/oledb/supporting-schema-rowsets.md)   
 [UpdatePV](../../top/visual-cpp-samples.md)
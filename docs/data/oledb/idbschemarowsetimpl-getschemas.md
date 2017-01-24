---
title: "IDBSchemaRowsetImpl::GetSchemas | Microsoft Docs"
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
  - "ATL::IDBSchemaRowsetImpl::GetSchemas"
  - "GetSchemas"
  - "IDBSchemaRowsetImpl<SessionClass>::GetSchemas"
  - "ATL.IDBSchemaRowsetImpl.GetSchemas"
  - "ATL::IDBSchemaRowsetImpl<SessionClass>::GetSchemas"
  - "IDBSchemaRowsetImpl.GetSchemas"
  - "IDBSchemaRowsetImpl::GetSchemas"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetSchemas"
ms.assetid: fbe725a6-3acd-45f8-bcaf-10a6c1239cd2
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBSchemaRowsetImpl::GetSchemas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna uma lista de conjuntos de linhas de esquema acessível por [idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md).  
  
## Sintaxe  
  
```  
  
STDMETHOD  
( GetSchema s )(  
   ULONG *   
pcSchemas  
,  
   GUID **   
prgSchemas  
,  
   ULONG**   
prgRest  
);  
  
```  
  
#### Parâmetros  
 *pcSchemas*  
 \[out\] Um ponteiro para um **ULONG** que é preenchido com o número de esquemas.  
  
 *prgSchemas*  
 \[out\] Um ponteiro para uma matriz de GUIDs que é preenchido com um ponteiro para uma matriz de GUIDs do conjunto de linhas de esquema.  
  
 *prgRest*  
 \[out\] Um ponteiro para uma matriz de **ULONG**s a ser preenchido com a matriz de restrição.  
  
## Comentários  
 Esse método retorna uma matriz de todos os conjuntos de linhas do esquema suportados pelo provedor. Consulte [IDBSchemaRowset::GetSchemas](https://msdn.microsoft.com/en-us/library/ms719605.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 A implementação dessa função exige que o usuário tenha um esquema do mapa na classe de sessão. Usando as informações de mapa de esquema, ele responde com a matriz de GUIDs para os esquemas no mapa. Isso representa os esquemas com suporte pelo provedor.  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [IDBSchemaRowsetImpl Class Members](http://msdn.microsoft.com/pt-br/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [IDBSchemaRowsetImpl::GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md)   
 [IDBSchemaRowset:: Getrowset](https://msdn.microsoft.com/en-us/library/ms722634.aspx)   
 [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)
---
title: "IDBSchemaRowsetImpl::GetRowset | Microsoft Docs"
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
  - "ATL::IDBSchemaRowsetImpl::GetRowset"
  - "ATL.IDBSchemaRowsetImpl.GetRowset"
  - "IDBSchemaRowsetImpl<SessionClass>::GetRowset"
  - "IDBSchemaRowsetImpl.GetRowset"
  - "IDBSchemaRowsetImpl::GetRowset"
  - "ATL::IDBSchemaRowsetImpl<SessionClass>::GetRowset"
  - "GetRowset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetRowset"
ms.assetid: 3ae28c22-e186-4a15-8591-b0192e784a6f
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBSchemaRowsetImpl::GetRowset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um conjunto de linhas do esquema.  
  
## Sintaxe  
  
```  
  
STDMETHOD (GetRowset)(  
   IUnknown *  
pUnkOuter  
,  
   REFGUID   
rguidSchema  
,  
   ULONG   
cRestrictions  
,  
   const VARIANT   
rgRestrictions  
[],  
   REFIID   
riid  
,  
   ULONG   
cPropertySets  
,  
   DBPROPSET   
rgPropertySets  
[],  
   IUnknown **  
ppRowset  
);  
  
```  
  
#### Parâmetros  
 `pUnkOuter`  
 \[in\] Um outer **IUnknown** quando agregação; caso contrário **nulo**.  
  
 `rguidSchema`  
 \[in\] Uma referência para o GUID do conjunto de linhas de esquema solicitado \(por exemplo, `DBSCHEMA_TABLES`\).  
  
 `cRestrictions`  
 \[in\] Uma contagem de restrições a serem aplicadas ao conjunto de linhas.  
  
 `rgRestrictions`  
 \[in\] Uma matriz de `cRestrictions` **VARIANT**que representam as restrições.  
  
 `riid`  
 \[in\] O IID da solicitação de linhas do esquema recém\-criado.  
  
 `cPropertySets`  
 \[in\] Define o número de propriedade para definir.  
  
 `rgPropertySets`  
 \[entrada\/saída\] Uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas para definir no conjunto de linhas de esquema criado recentemente.  
  
 `ppRowset`  
 \[out\] Um ponteiro para a interface solicitada no conjunto de linhas de esquema criado recentemente.  
  
## Comentários  
 Este método requer que o usuário tenha um esquema do mapa na classe de sessão. Usando as informações de mapa de esquema, `GetRowset` cria um objeto de conjunto de linhas determinado se o `rguidSchema` parâmetro for igual a uma das entradas de mapa GUIDs. Consulte [SCHEMA\_ENTRY](../../data/oledb/schema-entry.md) para obter uma descrição da entrada do mapa.  
  
 Consulte [IDBSchemaRowset:: Getrowset](https://msdn.microsoft.com/en-us/library/ms722634.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atldb.h  
  
## Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [IDBSchemaRowsetImpl Class Members](http://msdn.microsoft.com/pt-br/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [IDBSchemaRowsetImpl::GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md)   
 [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)
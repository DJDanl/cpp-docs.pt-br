---
title: 'Idbschemarowsetimpl:: Getschemas | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::IDBSchemaRowsetImpl::GetSchemas
- GetSchemas
- IDBSchemaRowsetImpl<SessionClass>::GetSchemas
- ATL.IDBSchemaRowsetImpl.GetSchemas
- ATL::IDBSchemaRowsetImpl<SessionClass>::GetSchemas
- IDBSchemaRowsetImpl.GetSchemas
- IDBSchemaRowsetImpl::GetSchemas
dev_langs: C++
helpviewer_keywords: GetSchemas method
ms.assetid: fbe725a6-3acd-45f8-bcaf-10a6c1239cd2
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ce07c59eb9dd806d2f297591e8f3b389b3f4ce54
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="idbschemarowsetimplgetschemas"></a>IDBSchemaRowsetImpl::GetSchemas
Retorna uma lista de conjuntos de linhas de esquema acessível por [idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD ( GetSchema s )(  
   ULONG * pcSchemas,  
   GUID ** prgSchemas,  
   ULONG** prgRest  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pcSchemas*  
 [out] Um ponteiro para um **ULONG** que é preenchido com o número de esquemas.  
  
 *prgSchemas*  
 [out] Um ponteiro para uma matriz de GUIDs que é preenchida com um ponteiro para uma matriz de GUIDs de linhas de esquema.  
  
 *prgRest*  
 [out] Um ponteiro para uma matriz de **ULONG**s que deve ser preenchida com a matriz de restrição.  
  
## <a name="remarks"></a>Comentários  
 Esse método retorna uma matriz de todos os conjuntos de linhas do esquema suportados pelo provedor. Consulte [IDBSchemaRowset::GetSchemas](https://msdn.microsoft.com/en-us/library/ms719605.aspx) no SDK do Windows.  
  
 A implementação dessa função exige que o usuário tenha um esquema do mapa na classe de sessão. Usando as informações de mapa de esquema, ele responde com a matriz de GUIDs para os esquemas no mapa. Isso representa os esquemas com suporte pelo provedor.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [Membros de classe IDBSchemaRowsetImpl](http://msdn.microsoft.com/en-us/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md)   
 [IDBSchemaRowset:: Getrowset](https://msdn.microsoft.com/en-us/library/ms722634.aspx)   
 [Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)
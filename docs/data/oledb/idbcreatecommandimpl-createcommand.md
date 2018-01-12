---
title: 'Idbcreatecommandimpl:: CreateCommand | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IDBCreateCommandImpl.CreateCommand
- CreateCommand
- IDBCreateCommandImpl::CreateCommand
dev_langs: C++
helpviewer_keywords: CreateCommand method
ms.assetid: 50ffbf8b-2c07-4bcb-96c5-ffce4519c7f7
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ff1f7e9815ae5cea9a96c95f7faad30340bf548d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="idbcreatecommandimplcreatecommand"></a>IDBCreateCommandImpl::CreateCommand
Cria um novo comando e retorna a interface solicitada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD(CreateCommand)(   
   IUnknown * pUnkOuter,   
   REFIID riid,   
   IUnknown ** ppvCommand    
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [idbcreatecommand:: CreateCommand](https://msdn.microsoft.com/en-us/library/ms709772.aspx) no *referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem a *referência do programador de DB OLE* parâmetros de nomes diferentes, que são descritos em **idbcreatecommand:: CreateCommand**:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do programador DB OLE* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*ppvCommand*|*ppCommand*|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBCreateCommandImpl](../../data/oledb/idbcreatecommandimpl-class.md)
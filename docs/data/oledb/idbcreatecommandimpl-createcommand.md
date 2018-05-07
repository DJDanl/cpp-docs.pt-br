---
title: 'Idbcreatecommandimpl:: CreateCommand | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBCreateCommandImpl.CreateCommand
- CreateCommand
- IDBCreateCommandImpl::CreateCommand
dev_langs:
- C++
helpviewer_keywords:
- CreateCommand method
ms.assetid: 50ffbf8b-2c07-4bcb-96c5-ffce4519c7f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 709f734ad0349ea7908466958e282a8ca2a5c2db
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="idbcreatecommandimplcreatecommand"></a>IDBCreateCommandImpl::CreateCommand
Cria um novo comando e retorna a interface solicitada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(CreateCommand)(IUnknown * pUnkOuter,   
   REFIID riid,   
   IUnknown ** ppvCommand);  
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
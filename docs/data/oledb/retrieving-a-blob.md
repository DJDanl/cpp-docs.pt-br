---
title: Recuperando um BLOB | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- retrieving BLOBs
- BLOB (binary large object), retrieving
- OLE DB, BLOBs (binary large objects)
ms.assetid: 2893eb0a-5c05-4016-8914-1e40ccbaf0b3
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 36ffc4fca7859b49067517e1085e1d854f733e24
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="retrieving-a-blob"></a>Recuperando um BLOB
Você pode recuperar um objeto binário grande (BLOB) de várias maneiras. Você pode usar **DBTYPE_BYTES** para recuperar o BLOB como uma sequência de bytes ou usar uma interface como `ISequentialStream`. Para obter mais informações, consulte [BLOBS e objetos OLE](https://msdn.microsoft.com/en-us/library/ms711511.aspx) no *referência do programador de DB OLE*.  
  
 O código a seguir mostra como recuperar um BLOB usando `ISequentialStream`. A macro [BLOB_ENTRY](../../data/oledb/blob-entry.md) permite que você especifique a interface e os sinalizadores usados para a interface. Depois de abrir a tabela, o código chama **leitura** repetidamente em `ISequentialStream` para ler os bytes do BLOB. O código chama **versão** de descartar o ponteiro de interface antes de chamar `MoveNext` para obter o próximo registro.  
  
```  
class CCategories  
{  
public:  
   ISequentialStream*   pPicture;  
  
BEGIN_COLUMN_MAP(CCategories)  
   BLOB_ENTRY(4, IID_ISequentialStream, STGM_READ, pPicture)  
END_COLUMN_MAP()  
};  
  
CTable<CAccessor<CCategories> > categories;  
ULONG          cb;  
BYTE            myBuffer[65536];  
  
categories.Open(session, "Categories");  
while (categories.MoveNext() == S_OK)  
{  
   do  
   {  
      categories.pPicture->Read(myBuffer, 65536, &cb);  
      // Do something with the buffer  
   } while (cb > 0);  
   categories.pPicture->Release();  
}  
```  
  
 Para obter mais informações sobre as macros que manipulam dados BLOB, consulte "Macros de mapa de coluna" [Macros e funções globais para modelos OLE DB consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Macros e funções globais para modelos de consumidor do OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)
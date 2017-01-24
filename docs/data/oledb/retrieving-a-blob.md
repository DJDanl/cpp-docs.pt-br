---
title: "Recuperando um BLOB | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BLOB (objeto binário grande), recuperando"
  - "OLE DB, BLOBs (objetos binários grandes)"
  - "recuperando BLOBs"
ms.assetid: 2893eb0a-5c05-4016-8914-1e40ccbaf0b3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recuperando um BLOB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode recuperar um objeto binário grande \(BLOB\) de várias maneiras.  Você pode usar **DBTYPE\_BYTES** para recuperar o BLOB com uma sequência de bytes ou para usar uma interface como `ISequentialStream`.  Para obter mais informações, consulte [Objetos de BLOBS e OLE](https://msdn.microsoft.com/en-us/library/ms711511.aspx)*na referência do programador de OLE DB*.  
  
 O código a seguir mostra como recuperar um BLOB usando `ISequentialStream`.  [BLOB\_ENTRY](../Topic/BLOB_ENTRY.md) macro permite que você especifique a interface e os sinalizadores usados para a interface.  Depois de abrir a tabela, o código a seguir chama **Ler** repetidamente em `ISequentialStream` para ler bytes de BLOB.  O código a seguir chama **Versão** para descartar do ponteiro de interface antes de chamar `MoveNext` para obter o registro.  
  
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
  
 Para obter mais informações sobre macros que manipulam dados BLOB, consulte “macros do mapa coluna” em [Macros e funções globais para modelos do consumidor OLE DB](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md).  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Macros e funções globais para modelos de consumidor de banco de dados OLE](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md)
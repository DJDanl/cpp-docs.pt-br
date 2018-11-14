---
title: Recuperando um BLOB
ms.date: 10/24/2018
helpviewer_keywords:
- retrieving BLOBs
- BLOB (binary large object), retrieving
- OLE DB, BLOBs (binary large objects)
ms.assetid: 2893eb0a-5c05-4016-8914-1e40ccbaf0b3
ms.openlocfilehash: 30551af0e74759d21cecae54714ca6eca1a37768
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556537"
---
# <a name="retrieving-a-blob"></a>Recuperando um BLOB

Você pode recuperar um objeto binário grande (BLOB) de várias maneiras. Você pode usar `DBTYPE_BYTES` para recuperar o BLOB como uma sequência de bytes ou usar uma interface como `ISequentialStream`. Para obter mais informações, consulte [BLOBS e objetos OLE](https://docs.microsoft.com/previous-versions/windows/desktop/ms711511(v=vs.85)) na **referência do programador DB OLE**.

O código a seguir mostra como recuperar um BLOB usando `ISequentialStream`. A macro [BLOB_ENTRY](../../data/oledb/blob-entry.md) permite que você especifique a interface e os sinalizadores usados para a interface. Depois de abrir a tabela, o código chama `Read` repetidamente em `ISequentialStream` para ler os bytes do BLOB. O código chama `Release` descartar o ponteiro de interface antes de chamar `MoveNext` para obter o próximo registro.

```cpp
class CCategories
{
public:
   ISequentialStream* pPicture;

BEGIN_COLUMN_MAP(CCategories)
   BLOB_ENTRY(4, IID_ISequentialStream, STGM_READ, pPicture)
END_COLUMN_MAP()
};
```

Em seguida, usado pelo código a seguir:

```cpp
CTable<CAccessor<CCategories>> categories;
ULONG cb;
BYTE myBuffer[65536];

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

Para obter mais informações sobre as macros que lidam com dados BLOB, consulte **Macros de mapa de coluna** na [Macros e funções globais para OLE DB modelos de consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)<br/>
[Macros e funções globais para modelos de consumidor do OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)<br/>

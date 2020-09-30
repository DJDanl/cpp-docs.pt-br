---
title: Recuperando um BLOB
ms.date: 10/24/2018
helpviewer_keywords:
- retrieving BLOBs
- BLOB (binary large object), retrieving
- OLE DB, BLOBs (binary large objects)
ms.assetid: 2893eb0a-5c05-4016-8914-1e40ccbaf0b3
ms.openlocfilehash: 352841595e8b197407ccb52a22c8b0502d314c98
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509506"
---
# <a name="retrieving-a-blob"></a>Recuperando um BLOB

Você pode recuperar um BLOB (objeto binário grande) de várias maneiras. Você pode usar `DBTYPE_BYTES` para recuperar o blob como uma sequência de bytes ou usar uma interface como `ISequentialStream` . Para obter mais informações, consulte [BLOBs e objetos OLE](/previous-versions/windows/desktop/ms711511(v=vs.85)) na **referência do programador de OLE DB**.

O código a seguir mostra como recuperar um BLOB usando o `ISequentialStream` . A [BLOB_ENTRY](./macros-and-global-functions-for-ole-db-consumer-templates.md#blob_entry) macro permite que você especifique a interface e os sinalizadores usados para a interface. Depois de abrir a tabela, o código é chamado `Read` repetidamente em `ISequentialStream` para ler bytes do blob. O código chama `Release` para descartar o ponteiro da interface antes `MoveNext` de chamar para obter o próximo registro.

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

Em seguida, usado pelo seguinte código:

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

Para obter mais informações sobre macros que lidam com dados de BLOB, consulte **macros de mapa de coluna** em [macros e funções globais para OLE DB modelos de consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)<br/>
[Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)<br/>

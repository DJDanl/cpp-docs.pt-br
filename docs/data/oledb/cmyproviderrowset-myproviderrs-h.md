---
title: CCustomRowset (CustomRS.H)
ms.date: 10/22/2018
f1_keywords:
- cmyproviderrowset
- myproviderrs.h
- ccustomrowset
- customrs.h
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderRowset class in MyProviderRS.H
- CCustomRowset class in CustomRS.H
ms.assetid: 7ba1a124-3842-40eb-a36b-302190a1af3a
ms.openlocfilehash: 9f9dcb97ecd6b5f37f1af2187abf8b5612eedce3
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59026143"
---
# <a name="ccustomrowset-customrsh"></a>CCustomRowset (CustomRS.H)

O assistente gera uma entrada para o objeto de conjunto de linhas. Nesse caso, ele é chamado `CCustomRowset`. O `CCustomRowset` classe herda de uma classe de provedor do OLE DB chamada `CRowsetImpl`, que implementa todas as interfaces necessárias para o objeto de conjunto de linhas. O código a seguir mostra a cadeia de herança para `CRowsetImpl`:

```cpp
template <class T, class Storage, class CreatorClass, 
   class ArrayType = CAtlArray<Storage>>
class CMyRowsetImpl:
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType, 
      CSimpleRow, IRowsetLocateImpl< T >>
```

`CRowsetImpl` também usa o `IAccessor` e `IColumnsInfo` interfaces. Ele usa essas interfaces para campos de saída nas tabelas. A classe também fornece uma implementação para `IRowsetIdentity`, que permite que o consumidor determinar se duas linhas são os mesmos. O `IRowsetInfo` interface implementa propriedades para o objeto de conjunto de linhas. O `IConvertType` interface permite que o provedor para resolver as diferenças entre tipos de dados solicitados pelo consumidor quanto os usados pelo provedor.

O `IRowset` interface realmente lida com a recuperação de dados. Primeiro, o consumidor chama um método chamado `GetNextRows` para retornar um identificador para uma linha, conhecida como um `HROW`. O consumidor, em seguida, chama `IRowset::GetData` com que `HROW` para recuperar os dados solicitados.

`CRowsetImpl` também pega vários parâmetros de modelo. Esses parâmetros permitem que você determine como o `CRowsetImpl` classe lida com os dados. O `ArrayType` argumento permite que você determine qual mecanismo de armazenamento é usado para armazenar os dados da linha. O *RowClass* parâmetro especifica qual classe contém um `HROW`.

O *RowsetInterface* parâmetro permite que você também usar o `IRowsetLocate` ou `IRowsetScroll` interface. O `IRowsetLocate` e `IRowsetScroll` interfaces ambos herdam `IRowset`. Portanto, os modelos de provedor do OLE DB devem fornecer um tratamento especial para essas interfaces. Se você quiser usar qualquer uma dessas interfaces, você precisará usar esse parâmetro.

## <a name="see-also"></a>Consulte também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)<br/>

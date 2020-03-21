---
title: CCustomRowset (CustomRS.H)
ms.date: 10/22/2018
f1_keywords:
- cmyproviderrowset
- ccustomrowset
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderRowset class in MyProviderRS.H
- CCustomRowset class in CustomRS.H
ms.assetid: 7ba1a124-3842-40eb-a36b-302190a1af3a
ms.openlocfilehash: 8e90db287bc7ac8994914766045eb210446dfd48
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079786"
---
# <a name="ccustomrowset-customrsh"></a>CCustomRowset (CustomRS.H)

O assistente gera uma entrada para o objeto de conjunto de linhas. Nesse caso, ele é chamado de `CCustomRowset`. A classe `CCustomRowset` herda de uma classe de provedor de OLE DB chamada `CRowsetImpl`, que implementa todas as interfaces necessárias para o objeto Rowset. O código a seguir mostra a cadeia de herança para `CRowsetImpl`:

```cpp
template <class T, class Storage, class CreatorClass,
   class ArrayType = CAtlArray<Storage>>
class CMyRowsetImpl:
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType,
      CSimpleRow, IRowsetLocateImpl< T >>
```

`CRowsetImpl` também usa as interfaces `IAccessor` e `IColumnsInfo`. Ele usa essas interfaces para campos de saída em tabelas. A classe também fornece uma implementação para `IRowsetIdentity`, que permite que o consumidor determine se duas linhas são iguais. A interface `IRowsetInfo` implementa propriedades para o objeto Rowset. A interface `IConvertType` permite que o provedor resolva as diferenças entre os tipos de dados solicitados pelo consumidor e os usados pelo provedor.

A interface `IRowset` realmente manipula a recuperação de dados. O consumidor primeiro chama um método chamado `GetNextRows` para retornar um identificador a uma linha, conhecido como um `HROW`. Em seguida, o consumidor chama `IRowset::GetData` com esse `HROW` para recuperar os dados solicitados.

`CRowsetImpl` também usa vários parâmetros de modelo. Esses parâmetros permitem que você determine como a classe de `CRowsetImpl` lida com os dados. O argumento `ArrayType` permite que você determine qual mecanismo de armazenamento é usado para armazenar os dados de linha. O parâmetro *maclass* especifica qual classe contém um `HROW`.

O parâmetro *RowsetInterface* permite que você também use a interface `IRowsetLocate` ou `IRowsetScroll`. As interfaces `IRowsetLocate` e `IRowsetScroll` herdam de `IRowset`. Portanto, os modelos de provedor de OLE DB devem fornecer tratamento especial para essas interfaces. Se você quiser usar qualquer uma dessas interfaces, precisará usar esse parâmetro.

## <a name="see-also"></a>Confira também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)<br/>

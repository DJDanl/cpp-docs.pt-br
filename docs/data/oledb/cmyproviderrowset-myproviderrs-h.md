---
title: CMyProviderRowset (myproviderrs. H) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- cmyproviderrowset
- myproviderrs.h
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderRowset class in MyProviderRS.H
ms.assetid: 7ba1a124-3842-40eb-a36b-302190a1af3a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c7c9830970f6e09d1993ac2fd78510b84068efaa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46021260"
---
# <a name="cmyproviderrowset-myproviderrsh"></a>CMyProviderRowset (MyProviderRS.H)

O assistente gera uma entrada para o objeto de conjunto de linhas. Nesse caso, ele é chamado `CMyProviderRowset`. O `CMyProviderRowset` classe herda de uma classe de provedor do OLE DB chamada `CRowsetImpl`, que implementa todas as interfaces necessárias para o objeto de conjunto de linhas. O código a seguir mostra a cadeia de herança para `CRowsetImpl`:  
  
```cpp  
template <class T, class Storage, class CreatorClass,   
   class ArrayType = CAtlArray<Storage>>  
class CMyRowsetImpl:  
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType,   
      CSimpleRow, IRowsetLocateImpl< T >>  
```  
  
`CRowsetImpl` também usa o `IAccessor` e `IColumnsInfo` interfaces. Ele usa essas interfaces para campos de saída nas tabelas. A classe também fornece uma implementação para `IRowsetIdentity`, que permite que o consumidor determinar se duas linhas são idênticas. O `IRowsetInfo` interface implementa propriedades para o objeto de conjunto de linhas. O `IConvertType` interface permite que o provedor para resolver as diferenças entre tipos de dados solicitados pelo consumidor quanto os usados pelo provedor.  
  
O `IRowset` interface realmente lida com a recuperação de dados. Primeiro, o consumidor chama um método chamado `GetNextRows` para retornar um identificador para uma linha, conhecida como um `HROW`. O consumidor, em seguida, chama `IRowset::GetData` com que `HROW` para recuperar os dados solicitados.  
  
`CRowsetImpl` também pega vários parâmetros de modelo. Esses parâmetros permitem que você determine como o `CRowsetImpl` classe lida com os dados. O `ArrayType` argumento permite que você determine qual mecanismo de armazenamento é usado para armazenar os dados da linha. O *RowClass* parâmetro especifica qual classe contém um `HROW`.  
  
O *RowsetInterface* parâmetro permite que você também usar o `IRowsetLocate` ou `IRowsetScroll` interface. O `IRowsetLocate` e `IRowsetScroll` interfaces ambos herdam `IRowset`. Portanto, os modelos de provedor do OLE DB devem fornecer um tratamento especial para essas interfaces. Se você quiser usar qualquer uma dessas interfaces, você precisará usar esse parâmetro.  
  
## <a name="see-also"></a>Consulte também  

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
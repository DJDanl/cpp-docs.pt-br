---
title: CMyProviderRowset (myproviderrs. H) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cmyproviderrowset
- myproviderrs.h
dev_langs: C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderRowset class in MyProviderRS.H
ms.assetid: 7ba1a124-3842-40eb-a36b-302190a1af3a
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 702a86d600a1ff3623ce86c1ad36da9b15876c61
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmyproviderrowset-myproviderrsh"></a>CMyProviderRowset (MyProviderRS.H)
O assistente gera uma entrada para o objeto de conjunto de linhas. Nesse caso, ele é chamado `CMyProviderRowset`. O `CMyProviderRowset` classe herda de uma classe de provedor do OLE DB chamada `CRowsetImpl`, que implementa todas as interfaces necessárias para o objeto de conjunto de linhas. O código a seguir mostra a cadeia de herança para `CRowsetImpl`:  
  
```  
template <class T, class Storage, class CreatorClass,   
   class ArrayType = CAtlArray<Storage> >  
class CMyRowsetImpl:  
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType,   
      CSimpleRow, IRowsetLocateImpl< T > >  
```  
  
 `CRowsetImpl`também usa o `IAccessor` e `IColumnsInfo` interfaces. Ele usa essas interfaces para campos nas tabelas de saída. A classe também fornece uma implementação de **IRowsetIdentity**, que permite que o consumidor determinar se duas linhas são idênticas. O `IRowsetInfo` interface implementa propriedades para o objeto de conjunto de linhas. O **IConvertType** interface permite que o provedor resolver as diferenças entre os tipos de dados solicitados pelo consumidor e aqueles usado pelo provedor.  
  
 O `IRowset` interface realmente lida com a recuperação de dados. O consumidor chama um método chamado primeiro `GetNextRows` para retornar um identificador para uma linha, conhecida como uma **HROW**. O consumidor chama **IRowset:: GetData** com que **HROW** para recuperar os dados solicitados.  
  
 `CRowsetImpl`também leva vários parâmetros de modelo. Esses parâmetros permitem que você determine como o `CRowsetImpl` classe manipula dados. O `ArrayType` argumento permite que você determine qual mecanismo de armazenamento é usado para armazenar os dados da linha. O **RowClass** parâmetro especifica qual classe contém um **HROW**.  
  
 O **RowsetInterface** parâmetro permite que você use também o `IRowsetLocate` ou `IRowsetScroll` interface. O `IRowsetLocate` e `IRowsetScroll` interfaces ambos herdam `IRowset`. Portanto, os modelos de provedor do OLE DB devem fornecer um tratamento especial para essas interfaces. Se você quiser usar uma dessas interfaces, você precisa usar esse parâmetro.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
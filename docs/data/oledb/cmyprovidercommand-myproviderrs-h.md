---
title: CMyProviderCommand (myproviderrs. H) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- cmyprovidercommand
- myproviderrs.h
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderCommand class in MyProviderRS.H
ms.assetid: b30b956e-cc91-4cf5-9fe6-f8b1ce9cc2a5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 919455c1f0e1bae0491226e2f2d0f53bb35f7ad8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46046596"
---
# <a name="cmyprovidercommand-myproviderrsh"></a>CMyProviderCommand (MyProviderRS.H)

O `CMyProviderCommand` classe é a implementação para o objeto de comando do provedor. Ele fornece a implementação para o `IAccessor`, `ICommandText`, e `ICommandProperties` interfaces. O `IAccessor` interface é o mesmo que o conjunto de linhas. O objeto de comando usa o acessador para especificar associações de parâmetros. O objeto de conjunto de linhas usa-os para especificar associações para colunas de saída. O `ICommandText` interface é uma maneira útil para especificar um comando textualmente. Este exemplo usa o `ICommandText` interface mais tarde, quando ele adiciona o código personalizado; ele também substitui o `ICommand::Execute` método. O `ICommandProperties` interface manipula todas as propriedades dos objetos de comando e o conjunto de linhas.  
  
```cpp  
// CMyProviderCommand  
class ATL_NO_VTABLE CMyProviderCommand :   
class ATL_NO_VTABLE CMyProviderCommand :   
   public CComObjectRootEx<CComSingleThreadModel>,  
   public IAccessorImpl<CMyProviderCommand>,  
   public ICommandTextImpl<CMyProviderCommand>,  
   public ICommandPropertiesImpl<CMyProviderCommand>,  
   public IObjectWithSiteImpl<CMyProviderCommand>,  
   public IConvertTypeImpl<CMyProviderCommand>,  
   public IColumnsInfoImpl<CMyProviderCommand>  
```  
  
O `IAccessor` interface gerencia todas as associações usadas em comandos e conjuntos de linhas. O consumidor chama `IAccessor::CreateAccessor` com uma matriz de `DBBINDING` estruturas. Cada `DBBINDING` estrutura contém informações sobre como as associações de coluna devem ser tratadas (como o tipo e comprimento). O provedor recebe as estruturas e, em seguida, determina como os dados devem ser transferidos e se todas as conversões são necessárias. O `IAccessor` no objeto de comando, a interface é usada para lidar com quaisquer parâmetros no comando.  
  
O objeto de comando também fornece uma implementação de `IColumnsInfo`. OLE DB exige o `IColumnsInfo` interface. A interface permite que o consumidor recuperar informações sobre os parâmetros do comando. O objeto de conjunto de linhas usa o `IColumnsInfo` interface para retornar informações sobre as colunas de saída para o provedor.  
  
O provedor também contém uma interface chamada `IObjectWithSite`. O `IObjectWithSite` interface foi implementada no ATL 2.0 e permite que o implementador passar informações sobre si mesmo para seu filho. O objeto de comando usa o `IObjectWithSite` informações dizer qualquer geradas objetos de conjunto de linhas sobre quem o criou.  
  
## <a name="see-also"></a>Consulte também  

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
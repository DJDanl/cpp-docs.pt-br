---
title: CCustomCommand (CustomRS.H) | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- cmyprovidercommand
- myproviderrs.h
- ccustomcommand
- customrs.h
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderCommand class in MyProviderRS.H
- CCustomCommand class in CustomRS.H
ms.assetid: b30b956e-cc91-4cf5-9fe6-f8b1ce9cc2a5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3d3f6b8775ab876834555e7c47e469c72d3a150b
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49807725"
---
# <a name="ccustomcommand-customrsh"></a>CCustomCommand (CustomRS.H)

O `CCustomCommand` classe é a implementação para o objeto de comando do provedor. Ele fornece a implementação para o `IAccessor`, `ICommandText`, e `ICommandProperties` interfaces. O `IAccessor` interface é o mesmo que o conjunto de linhas. O objeto de comando usa o acessador para especificar associações de parâmetros. O objeto de conjunto de linhas usa-os para especificar associações para colunas de saída. O `ICommandText` interface é uma maneira útil para especificar um comando textualmente. Este exemplo usa o `ICommandText` interface mais tarde, quando ele adiciona o código personalizado; ele também substitui o `ICommand::Execute` método. O `ICommandProperties` interface manipula todas as propriedades dos objetos de comando e o conjunto de linhas.  
  
```cpp  
// CCustomCommand  
class ATL_NO_VTABLE CCustomCommand :   
class ATL_NO_VTABLE CCustomCommand :   
   public CComObjectRootEx<CComSingleThreadModel>,  
   public IAccessorImpl<CCustomCommand>,  
   public ICommandTextImpl<CCustomCommand>,  
   public ICommandPropertiesImpl<CCustomCommand>,  
   public IObjectWithSiteImpl<CCustomCommand>,  
   public IConvertTypeImpl<CCustomCommand>,  
   public IColumnsInfoImpl<CCustomCommand>  
```  
  
O `IAccessor` interface gerencia todas as associações usadas em comandos e conjuntos de linhas. O consumidor chama `IAccessor::CreateAccessor` com uma matriz de `DBBINDING` estruturas. Cada `DBBINDING` estrutura contém informações sobre como as associações de coluna devem ser tratadas (como o tipo e comprimento). O provedor recebe as estruturas e, em seguida, determina como os dados devem ser transferidos e se todas as conversões são necessárias. O `IAccessor` no objeto de comando, a interface é usada para lidar com quaisquer parâmetros no comando.  
  
O objeto de comando também fornece uma implementação de `IColumnsInfo`. OLE DB exige o `IColumnsInfo` interface. A interface permite que o consumidor recuperar informações sobre os parâmetros do comando. O objeto de conjunto de linhas usa o `IColumnsInfo` interface para retornar informações sobre as colunas de saída para o provedor.  
  
O provedor também contém uma interface chamada `IObjectWithSite`. O `IObjectWithSite` interface foi implementada no ATL 2.0 e permite que o implementador passar informações sobre si mesmo para seu filho. O objeto de comando usa o `IObjectWithSite` informações dizer qualquer geradas objetos de conjunto de linhas sobre quem o criou.  
  
## <a name="see-also"></a>Consulte também  

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
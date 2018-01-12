---
title: CMyProviderCommand (myproviderrs. H) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cmyprovidercommand
- myproviderrs.h
dev_langs: C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderCommand class in MyProviderRS.H
ms.assetid: b30b956e-cc91-4cf5-9fe6-f8b1ce9cc2a5
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 67a394ce3c3b05e3f5eea49cbd3a234a0dd89df2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmyprovidercommand-myproviderrsh"></a>CMyProviderCommand (MyProviderRS.H)
O `CMyProviderCommand` classe é a implementação para o objeto de comando do provedor. Ele fornece a implementação para o `IAccessor`, `ICommandText`, e **ICommandProperties** interfaces. O `IAccessor` interface é o mesmo que o conjunto de linhas. O objeto de comando usa o acessador para especificar associações de parâmetros. O objeto de conjunto de linhas usa para especificar associações para colunas de saída. O `ICommandText` interface é uma maneira útil para especificar um comando textualmente. Este exemplo usa o `ICommandText` interface posteriormente quando ele adiciona o código personalizado; ele também substitui o `ICommand::Execute` método. O **ICommandProperties** interface trata todas as propriedades para os objetos de comando e o conjunto de linhas.  
  
```  
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
  
 O `IAccessor` interface gerencia todas as associações usadas em comandos e conjuntos de linhas. O consumidor chama **IAccessor:: CreateAccessor** com uma matriz de **DBBINDING** estruturas. Cada **DBBINDING** estrutura contém as informações sobre como as associações de coluna devem ser tratadas (como comprimento e tipo). O provedor recebe as estruturas e, em seguida, determina como os dados devem ser transferidos e se qualquer conversões são necessários. O `IAccessor` interface é usada no objeto de comando para lidar com todos os parâmetros de comando.  
  
 O objeto de comando também fornece uma implementação de `IColumnsInfo`. OLE DB requer o `IColumnsInfo` interface. A interface permite que o consumidor recuperar informações sobre os parâmetros do comando. O objeto de conjunto de linhas usa o `IColumnsInfo` interface para retornar informações sobre as colunas de saída para o provedor.  
  
 O provedor também contém uma interface chamada `IObjectWithSite`. O `IObjectWithSite` interface foi implementada no ATL 2.0 e permite que o implementador passar informações sobre si mesmo para seu filho. O objeto de comando usa o `IObjectWithSite` informações dizer qualquer geradas objetos de conjunto de linhas sobre quem o criou.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
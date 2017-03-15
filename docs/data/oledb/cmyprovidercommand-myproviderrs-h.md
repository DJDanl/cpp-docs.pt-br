---
title: "CMyProviderCommand (MyProviderRS.H) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "cmyprovidercommand"
  - ""myproviderrs.h""
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMyProviderCommand em MyProviderRS.H"
  - "Provedores OLE DB, arquivos gerados por assistente"
ms.assetid: b30b956e-cc91-4cf5-9fe6-f8b1ce9cc2a5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CMyProviderCommand (MyProviderRS.H)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMyProviderCommand` é a implementação do objeto de comando do provedor.  Fornece implementação para `IAccessor`, `ICommandText`, e interfaces de **ICommandProperties** .  A interface de `IAccessor` é a mesma que a do conjunto de linhas.  O objeto de comando usa o acessador para especificar associações de parâmetros.  O objeto de conjunto de linhas utilizados para especificar ligações para colunas de saída.  A interface de `ICommandText` é uma maneira útil de especificar textually um comando.  Este exemplo usa a interface de `ICommandText` posteriormente quando adiciona o código personalizado; também substitui o método de `ICommand::Execute` .  A interface de **ICommandProperties** trata todas as propriedades dos objetos de comando e do conjunto de linhas.  
  
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
  
 A interface de `IAccessor` gerencia todas as associações usadas em comandos e conjuntos de linhas.  O consumidor chama **IAccessor::CreateAccessor** com uma matriz de estruturas de **DBBINDING** .  Cada estrutura de **DBBINDING** contém informações sobre como as associações de coluna devem ser tratadas \(como o tipo e comprimento.\)  O provedor recebe as estruturas e determina como os dados devem ser transferidos e se qualquer conversão é necessária.  A interface de `IAccessor` é usada no objeto de comando para tratar todos os parâmetros no comando.  
  
 O objeto de comando também fornece uma implementação de `IColumnsInfo`.  O OLE DB requer a interface de `IColumnsInfo` .  A interface permite que o consumidor recupere informações sobre parâmetros do comando.  O objeto de conjunto de linhas usa a interface de `IColumnsInfo` para retornar informações sobre as colunas de saída ao provedor.  
  
 O provedor também contém uma interface chamada `IObjectWithSite`.  A interface de `IObjectWithSite` foi implementada em ATL 2,0 e permite que o implementador transmite informações sobre se a seu filho.  O objeto de comando usa as informações de `IObjectWithSite` para informar todos os objetos gerados no conjunto de linhas sobre quem criou o.  
  
## Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
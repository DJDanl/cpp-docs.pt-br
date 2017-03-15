---
title: "CMyProviderRowset (MyProviderRS.H) | Microsoft Docs"
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
  - "cmyproviderrowset"
  - ""myproviderrs.h""
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMyProviderRowset em MyProviderRS.H"
  - "Provedores OLE DB, arquivos gerados por assistente"
ms.assetid: 7ba1a124-3842-40eb-a36b-302190a1af3a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CMyProviderRowset (MyProviderRS.H)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O assistente gerenciar uma entrada para o objeto de conjunto de linhas.  Nesse caso, é chamado `CMyProviderRowset`.  A classe herda de `CMyProviderRowset` de uma classe do provedor OLE DB `CRowsetImpl`chamada, que implementa as interfaces necessárias para o objeto de conjunto de linhas.  O código a seguir mostra a cadeia de herança para `CRowsetImpl`:  
  
```  
template <class T, class Storage, class CreatorClass,   
   class ArrayType = CAtlArray<Storage> >  
class CMyRowsetImpl:  
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType,   
      CSimpleRow, IRowsetLocateImpl< T > >  
```  
  
 `CRowsetImpl` também usa `IAccessor` e `IColumnsInfo` interfaces.  O usa essas interfaces para campos de saída nas tabelas.  A classe também fornece uma implementação de **IRowsetIdentity**, que permite que o consumidor determine se duas linhas são idênticas.  As propriedades das ferramentas da interface de `IRowsetInfo` para o conjunto de linhas objeto.  A interface de **IConvertType** permite que o provedor resolve diferenças entre os tipos de dados solicitados pelo consumidor e aqueles usados pelo provedor.  
  
 A interface de `IRowset` controla de fato a recuperação de dados.  O consumidor chama um método chamado primeiro `GetNextRows` para retornar um identificador para uma linha, conhecida como **HROW**.  O consumidor pode chamar **IRowset::GetData** com esse **HROW** para recuperar os dados solicitados.  
  
 `CRowsetImpl` também aceita vários parâmetros do modelo.  Esses parâmetros permitem determinar como a classe de `CRowsetImpl` trata dados.  O argumento de `ArrayType` permite determinar que o mecanismo de armazenamento é usado para armazenar os dados de linha.  O parâmetro de **RowClass** especifica que a classe contém **HROW**.  
  
 O parâmetro de **RowsetInterface** permite que você também use a interface de `IRowsetLocate` ou de `IRowsetScroll` .  `IRowsetLocate` e `IRowsetScroll` interface ambos herdam de `IRowset`.  Consequentemente, os modelos do provedor OLE DB devem fornecer um tratamento especial para essas interfaces.  Se você quiser usar uma dessas interfaces, você precisa usar esse parâmetro.  
  
## Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)
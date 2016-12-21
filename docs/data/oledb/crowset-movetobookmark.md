---
title: "CRowset::MoveToBookmark | Microsoft Docs"
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
  - "ATL::CRowset::MoveToBookmark"
  - "ATL::CRowset<TAccessor>::MoveToBookmark"
  - "ATL.CRowset.MoveToBookmark"
  - "ATL.CRowset<TAccessor>.MoveToBookmark"
  - "MoveToBookmark"
  - "CRowset::MoveToBookmark"
  - "CRowset.MoveToBookmark"
  - "CRowset<TAccessor>::MoveToBookmark"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MoveToBookmark"
ms.assetid: 90124723-8daf-4692-ae2f-0db26b5db920
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::MoveToBookmark
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Busca a linha marcada por um medidor ou a linha em um deslocamento especificado \(`lSkip`\) desse indicador.  
  
## Sintaxe  
  
```  
  
      HRESULT MoveToBookmark(   
   const CBookmarkBase& bookmark,   
   LONG lSkip = 0    
) throw( );  
```  
  
#### Parâmetros  
 `bookmark`  
 \[in\] indicador de que marca o local do qual você deseja buscar dados.  
  
 `lSkip`  
 \[in\] a contagem do número de linhas de indicador à linha de destino.  Se `lSkip` for zero, a primeira linha buscada será a linha com indicador.  Se `lSkip` for 1, a primeira linha buscada será a linha após a linha com indicador.  Se `lSkip` será – 1, a primeira linha buscada está a linha antes da linha com indicador.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método exige a interface opcional `IRowsetLocate`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetLocate** a `VARIANT_TRUE` e a **DBPROP\_CANFETCHBACKWARDS** definido como `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
 Para obter informações sobre como usar o marca um endereço da Internet\) dos consumidores, consulte [Usando indicadores](../../data/oledb/using-bookmarks.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [CRowset::MoveNext](../../data/oledb/crowset-movenext.md)   
 [CRowset::MoveFirst](../../data/oledb/crowset-movefirst.md)   
 [IRowsetLocate::GetRowsAt](https://msdn.microsoft.com/en-us/library/ms723031.aspx)   
 [CRowset::MovePrev](../../data/oledb/crowset-moveprev.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)
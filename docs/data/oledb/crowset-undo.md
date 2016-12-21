---
title: "CRowset::Undo | Microsoft Docs"
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
  - "CRowset.Undo"
  - "ATL::CRowset<TAccessor>::Undo"
  - "CRowset<TAccessor>::Undo"
  - "ATL.CRowset.Undo"
  - "ATL.CRowset<TAccessor>.Undo"
  - "CRowset<TAccessor>.Undo"
  - "ATL::CRowset::Undo"
  - "CRowset::Undo"
  - "Undo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Undo"
ms.assetid: 1ccd70e2-3931-41c4-893e-a05d0e295410
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::Undo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Desfaz todas as alterações feitas em uma linha desde que o a última busca ou [Atualização](../Topic/CRowset::Update.md).  
  
## Sintaxe  
  
```  
  
      HRESULT Undo(   
   DBCOUNTITEM* pcRows = NULL,   
   HROW* phRow = NULL,   
   DBROWSTATUS* pStatus = NULL    
) throw( );  
```  
  
#### Parâmetros  
 `pcRows`  
 \[out\] o ponteiro do local onde **Desfazer** retorna o número de linhas ele tentou desfazer se necessário.  
  
 `phRow`  
 \[out\] o ponteiro do local onde **Desfazer** retorna uma matriz de identificadores a todas as linhas ele tentou desfazer se necessário.  
  
 `pStatus`  
 \[out\] ponteiro do local onde **Desfazer** retorna o valor de status de linha.  Nenhum status será retornado se `pStatus` for nulo.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método exige a interface opcional `IRowsetUpdate`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetUpdate** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [IRowsetUpdate::Undo](https://msdn.microsoft.com/en-us/library/ms719655.aspx)
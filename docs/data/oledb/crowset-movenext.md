---
title: "CRowset::MoveNext | Microsoft Docs"
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
  - "ATL.CRowset<TAccessor>.MoveNext"
  - "ATL.CRowset.MoveNext"
  - "ATL::CRowset<TAccessor>::MoveNext"
  - "CRowset<TAccessor>.MoveNext"
  - "CRowset.MoveNext"
  - "CRowset<TAccessor>::MoveNext"
  - "CRowset::MoveNext"
  - "ATL::CRowset::MoveNext"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MoveNext"
ms.assetid: 0df3288c-2bce-494f-99c0-6344b54a4adf
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::MoveNext
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move o cursor para o próximo registro.  
  
## Sintaxe  
  
```  
  
      HRESULT MoveNext( ) throw( );   
HRESULT MoveNext(   
   LONG lSkip,   
   bool bForward = true    
) throw( );  
```  
  
#### Parâmetros  
 `lSkip`  
 \[in\] o número de linhas a serem ignorados antes de buscar.  
  
 `bForward`  
 \[in\] passar **true** para avançar para o próximo registro, **false** a ser movido para trás.  
  
## Valor de retorno  
 `HRESULT`padrão.  Quando o final do conjunto de linhas foi atingido, retornará **DB\_S\_ENDOFROWSET**.  
  
## Comentários  
 Pesquisa sequencial a linha seguinte do objeto de `CRowset` , recordando a posição anterior.  Opcionalmente, você pode optar por ignorar linhas de `lSkip` ou para navegar para trás.  
  
 Esse método exige que você defina as seguintes propriedades antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas:  
  
-   **DBPROP\_CANSCROLLBACKWARDS** deve ser `VARIANT_TRUE` se `lSkip` \< 0  
  
-   **DBPROP\_CANFETCHBACKWARDS** deve ser `VARIANT_TRUE` se `bForward` \= false  
  
 Se não \(se `lSkip` \>\= 0 e `bForward` \= true\), você não precisa definir nenhuma propriedade adicional.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [CRowset::MoveFirst](../../data/oledb/crowset-movefirst.md)   
 [CRowset::MoveToBookmark](../../data/oledb/crowset-movetobookmark.md)   
 [CRowset::MovePrev](../../data/oledb/crowset-moveprev.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)
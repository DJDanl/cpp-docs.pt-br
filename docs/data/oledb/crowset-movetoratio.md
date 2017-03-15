---
title: "CRowset::MoveToRatio | Microsoft Docs"
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
  - "MoveToRatio"
  - "CRowset<TAccessor>::MoveToRatio"
  - "CRowset::MoveToRatio"
  - "CRowset<TAccessor>.MoveToRatio"
  - "ATL.CRowset.MoveToRatio"
  - "ATL::CRowset::MoveToRatio"
  - "CRowset.MoveToRatio"
  - "ATL.CRowset<TAccessor>.MoveToRatio"
  - "ATL::CRowset<TAccessor>::MoveToRatio"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MoveToRatio"
ms.assetid: 1fa313bd-8fd1-4608-8e85-44993b97dd88
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::MoveToRatio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Buscar linhas a partir de uma posição fracionário no conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      HRESULT MoveToRatio(   
   DBCOUNTITEM nNumerator,   
   DBCOUNTITEM nDenominator,   
   bool bForward = true    
) throw( );  
```  
  
#### Parâmetros  
 `nNumerator`  
 \[in\] o numerador usado para determinar o posicional fracionária do qual a busca de dados.  
  
 `nDenominator`  
 \[in\] o denominador usado para determinar o posicional fracionária do qual a busca de dados.  
  
 `bForward`  
 \[in\] indica se mover para frente ou para trás.  A opção é futuras.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 `MoveToRatio` busca as linhas que concordam aproximadamente a seguinte fórmula:  
  
 `( nNumerator *  RowsetSize ) / nDenominator`  
  
 onde `RowsetSize` é o tamanho do conjunto de linhas, medido nas linhas.  A precisão dessa fórmula depende do provedor específico.  Para obter detalhes, consulte [IRowsetScroll::GetRowsAtRatio](https://msdn.microsoft.com/en-us/library/ms709602.aspx).  
  
 Esse método exige a interface opcional `IRowsetScroll`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetScroll** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)
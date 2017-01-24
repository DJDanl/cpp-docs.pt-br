---
title: "CSession::Open | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL::CSession::Open"
  - "CSession::Open"
  - "CSession.Open"
  - "ATL.CSession.Open"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Open"
ms.assetid: c2050c2c-9817-4857-be49-189f346968f6
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CSession::Open
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre uma nova sessão para o objeto de fonte de dados.  
  
## Sintaxe  
  
```  
  
      HRESULT Open(  
   const CDataSource& ds,  
   DBPROPSET *pPropSet = NULL,  
   ULONG ulPropSets = 0  
) throw( );  
```  
  
#### Parâmetros  
 `ds`  
 \[in\] a fonte de dados para que a sessão deve ser aberta.  
  
 *pPropSet*  
 \[in\] o ponteiro da uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) a estrutura que contém as propriedades e dos valores a serem definidos.  Consulte [Conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx)*na referência do programador do* OLE DB em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `ulPropSets`  
 \[in\] o número de estruturas de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) transmitido no argumento *de pPropSet* .  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Você deve abrir o objeto de fonte de dados usando [CDataSource::Open](../../data/oledb/cdatasource-open.md) antes de passá\-lo para `CSession::Open`.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CSession](../../data/oledb/csession-class.md)
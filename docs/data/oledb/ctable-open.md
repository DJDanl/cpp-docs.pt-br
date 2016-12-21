---
title: "CTable::Open | Microsoft Docs"
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
  - "ATL.CTable.Open"
  - "ATL::CTable::Open"
  - "CTable::Open"
  - "CTable.Open"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Open"
ms.assetid: 5d006d95-74d7-4e2b-b243-a33bc53b5455
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CTable::Open
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre a tabela.  
  
## Sintaxe  
  
```  
  
      HRESULT Open(  
   const CSession& session,  
   LPCWSTR wszTableName,  
   DBPROPSET* pPropSet = NULL,  
   ULONG ulPropSets = 0  
) throw ( );  
HRESULT Open(  
   const CSession& session,  
   LPCSTR szTableName,  
   DBPROPSET* pPropSet = NULL,  
   ULONG ulPropSets = 0  
) throw ( );  
HRESULT Open(  
   const CSession& session,  
   DBID& dbid,  
   DBPROPSET* pPropSet = NULL,  
   ULONG ulPropSets = 0  
) throw ( );  
```  
  
#### Parâmetros  
 `session`  
 \[in\] a sessão para a qual a tabela é aberta.  
  
 *wszTableName*  
 \[in\] o nome da tabela para abrir, passado como uma cadeia de caracteres Unicode.  
  
 *szTableName*  
 \[in\] o nome da tabela para abrir, passado como uma cadeia de caracteres ANSI.  
  
 *dbid*  
 \[in\] **DBID** da tabela a ser aberta.  
  
 *pPropSet*  
 \[in\] o ponteiro da uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) a estrutura que contém as propriedades e dos valores a serem definidos.  Consulte [Conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx)*na referência do programador do* OLE DB em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  O valor padrão de NULL não especifica nenhuma propriedade.  
  
 `ulPropSets`  
 \[in\] o número de estruturas de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) transmitido no argumento *de pPropSet* .  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Para obter mais detalhes, consulte [IOpenRowset::OpenRowset](https://msdn.microsoft.com/en-us/library/ms716724.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CTable](../../data/oledb/ctable-class.md)
---
title: "CRestrictions::Open | Microsoft Docs"
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
  - "CRestrictions.Open"
  - "ATL::CRestrictions::Open"
  - "ATL.CRestrictions.Open"
  - "CRestrictions::Open"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Open"
ms.assetid: 0aff0cc3-543a-47d2-8d6b-ebb36926b6db
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRestrictions::Open
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um conjunto de resultados de acordo com as restrições usuário fornecidas.  
  
## Sintaxe  
  
```  
  
      HRESULT Open(  
   const CSession& session,  
   LPCTSTR lpszParam 1 = NULL,  
   LPCTSTR lpszParam 2 = NULL,  
   LPCTSTR lpszParam 3 = NULL,  
   LPCTSTR lpszParam 4 = NULL,  
   LPCTSTR lpszParam 5 = NULL,  
   LPCTSTR lpszParam 6 = NULL,  
   LPCTSTR lpszParam 7 = NULL,  
   bool bBind = true  
);  
```  
  
#### Parâmetros  
 `session`  
 \[in\] especifica um objeto de sessão existente usada para conectar\-se à fonte de dados.  
  
 *lpszParam*  
 \[in\] especifica as restrições no conjunto de linhas de esquema.  
  
 `bBind`  
 \[in\] especifica se associar automaticamente o mapa da coluna.  A opção é **true**, o que causa o mapa da coluna a ser associado automaticamente.  A configuração `bBind` a **false** impede a associação automático da coluna de forma que você possa se associar manualmente. \(A associação é manual de interesse específico aos usuários OLAP\).  
  
## Valor de retorno  
 Um dos valores padrão de `HRESULT` .  
  
## Comentários  
 Você pode especificar um máximo de sete limitações em um conjunto de linhas de esquema.  
  
 Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) para obter informações sobre restrições definidas em cada conjunto de linhas de esquema.  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)   
 [Classes Rowset do esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)
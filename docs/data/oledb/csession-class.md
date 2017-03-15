---
title: "Classe CSession | Microsoft Docs"
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
  - "CSession"
  - "ATL::CSession"
  - "ATL.CSession"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CSession"
ms.assetid: 83cd798f-b45d-4f11-a23c-29183390450c
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CSession
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma única sessão de acesso ao base de dados.  
  
## Sintaxe  
  
```  
class CSession  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Anular](../Topic/CSession::Abort.md)|Cancela a transação termina \(\).|  
|[Fechar](../../data/oledb/csession-close.md)|Fecha a sessão.|  
|[Confirmação](../../data/oledb/csession-commit.md)|Confirma a transação.|  
|[GetTransactionInfo](../../data/oledb/csession-gettransactioninfo.md)|Retorna informações relativas a uma transação.|  
|[Abrir](../../data/oledb/csession-open.md)|Abre uma nova sessão para o objeto de fonte de dados.|  
|[StartTransaction](../../data/oledb/csession-starttransaction.md)|Começa uma nova transação para essa sessão.|  
  
## Comentários  
 Uma ou mais sessões podem ser associadas a cada conexão do provedor \(fonte de dados\), que é representada por um objeto de [CDataSource](../Topic/CDataSource%20Class.md) .  Para criar um novo `CSession` para `CDataSource`, chame [CSession::Open](../../data/oledb/csession-open.md).  Para iniciar uma transação de base de dados, `CSession` fornece o método de `StartTransaction` .  Uma vez que uma transação é iniciada, você pode confirmar\-lhe que usa o método de **Confirmar** , ou cancelá\-lo que usa o método de **Anular** .  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [CatDB](../../top/visual-cpp-samples.md)   
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)
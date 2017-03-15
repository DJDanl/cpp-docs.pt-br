---
title: "M&#233;todo FtmBase::CreateGlobalInterfaceTable | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ftm/Microsoft::WRL::FtmBase::CreateGlobalInterfaceTable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateGlobalInterfaceTable"
ms.assetid: bb82a0c5-22b9-4844-9204-7922033d8b07
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo FtmBase::CreateGlobalInterfaceTable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma tabela global \(GIT\) da interface.  
  
## Sintaxe  
  
```  
static HRESULT CreateGlobalInterfaceTable(  
   __out IGlobalInterfaceTable **git  
);  
```  
  
#### Parâmetros  
 `git`  
 Quando esta operação concluir, um ponteiro para uma tabela global da interface.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; caso contrário, um HRESULT que declara o erro.  
  
## Comentários  
 Para obter mais informações, consulte o tópico “IGlobalInterfaceTable” “COM interfaces” subtópico de “do tópico de referência COM” na Biblioteca MSDN.  
  
## Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)
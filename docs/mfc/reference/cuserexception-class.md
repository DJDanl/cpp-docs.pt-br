---
title: "Classe de CUserException | Microsoft Docs"
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
  - "CUserException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CUserException"
  - "erros [C++], trapping"
  - "exceções, starter"
  - "operações [C++]"
  - "operações [C++], parando"
  - "gerar exceções, parando operações de usuário"
ms.assetid: 2156ba6d-2cce-415a-9000-6f02c26fcd7d
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CUserException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lançada para interromper uma operação de usuário final.  
  
## Sintaxe  
  
```  
class CUserException : public CSimpleException  
```  
  
## Comentários  
 Use `CUserException` quando você deseja usar o mecanismo de exceção throw\/para capturar exceções específicas do aplicativo. “  O usuário” no nome da classe pode ser interpretado como “my usuário faz algo excepcional que eu preciso de manipular.”  
  
 `CUserException` geralmente é lançado após chamar a função global `AfxMessageBox` para notificar o usuário que uma operação falhou.  Quando você escreve um manipulador de exceção, tratar a exceção especialmente desde que o usuário tiver sido notificado geralmente já de falha.  A estrutura lança esta exceção em alguns casos.  Para lançar `CUserException` você mesmo, alerte o usuário e então chame a função global `AfxThrowUserException`.  
  
 Em o exemplo abaixo, uma função que contém as operações que podem falhar alertas o usuário e lançam `CUserException`.  A função de chamada captura a exceção e tratá\-lo especialmente:  
  
 [!code-cpp[NVC_MFCExceptions#24](../../mfc/codesnippet/CPP/cuserexception-class_1.cpp)]  
  
 Para obter mais informações sobre como usar `CUserException`, consulte o artigo [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CUserException`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [AfxMessageBox](../Topic/AfxMessageBox.md)   
 [AfxThrowUserException](../Topic/AfxThrowUserException.md)   
 [Como: eu faço Crie minhas próprias classes de exceção personalizada?](http://go.microsoft.com/fwlink/?LinkId=128045)
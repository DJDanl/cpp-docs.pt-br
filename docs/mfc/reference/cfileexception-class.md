---
title: "Classe de CFileException | Microsoft Docs"
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
  - "CFileException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFile, exceções de"
  - "Classe de CFileException"
  - "exceções, tipo de arquivo"
ms.assetid: f6491bb9-bfbc-42fd-a952-b33f9b62323f
caps.latest.revision: 20
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFileException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção com relacionados.  
  
## Sintaxe  
  
```  
class CFileException : public CException  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileException::CFileException](../Topic/CFileException::CFileException.md)|Constrói um objeto de `CFileException` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileException::ErrnoToException](../Topic/CFileException::ErrnoToException.md)|Código de causa de retorna que corresponde a um número de erro em tempo de execução.|  
|[CFileException::GetErrorMessage](../Topic/CFileException::GetErrorMessage.md)|Recupera a mensagem descrevendo uma exceção.|  
|[CFileException::OsErrorToException](../Topic/CFileException::OsErrorToException.md)|Retorna um código causa de que corresponde a um código de erro do sistema operacional.|  
|[CFileException::ThrowErrno](../Topic/CFileException::ThrowErrno.md)|Gera uma exceção do arquivo com base em um número de erro em tempo de execução.|  
|[CFileException::ThrowOsError](../Topic/CFileException::ThrowOsError.md)|Gera uma exceção do arquivo com base em um número de erro do sistema operacional.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileException::m\_cause](../Topic/CFileException::m_cause.md)|O arquivo contém código que corresponde à causa de exceção.|  
|[CFileException::m\_lOsError](../Topic/CFileException::m_lOsError.md)|Contém o número de erro do sistema operacional relacionados.|  
|[CFileException::m\_strFileName](../Topic/CFileException::m_strFileName.md)|Contém o nome do arquivo para essa exceção.|  
  
## Comentários  
 A classe de `CFileException` inclui os dados membros públicos que contêm o código portátil e causa do erro número operar\-sistema\- específico.  A classe também fornece funções de membro estático para gerar exceções do arquivo e retornar códigos de causa para erros do sistema operacional e erros em tempo de execução de C.  
  
 Os objetos de`CFileException` são construídos e lançados em funções de membro de `CFile` e funções de membro de classes derivadas.  Você pode acessar esses objetos no escopo de uma expressão de **CATCH** .  Para a mobilidade, use somente o código seja transferido para obter a razão para uma exceção.  Para obter mais informações sobre as exceções, consulte o artigo [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CFileException`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Processamento de exceção](../../mfc/reference/exception-processing.md)
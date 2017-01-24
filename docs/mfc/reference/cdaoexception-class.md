---
title: "Classe de CDaoException | Microsoft Docs"
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
  - "CDaoException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoException"
  - "coleções, erros de DAO"
  - "DAO (objetos de acesso a dados), exceções"
  - "erros [C++], DAO"
  - "Coleção de erros, DAO"
  - "exceções, em classes MFC DAO"
ms.assetid: b2b01fa9-7ce2-42a1-842e-40f13dc50da4
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção que ocorre as classes de banco de dados MFC baseadas em objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
```  
class CDaoException : public CException  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoException::CDaoException](../Topic/CDaoException::CDaoException.md)|Constrói um objeto de `CDaoException` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoException::GetErrorCount](../Topic/CDaoException::GetErrorCount.md)|Retorna o número de erros na coleção de erros do mecanismo de banco de dados.|  
|[CDaoException::GetErrorInfo](../Topic/CDaoException::GetErrorInfo.md)|Informações de erro returns sobre um objeto específico de erro na coleção de erros.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoException::m\_nAfxDaoError](../Topic/CDaoException::m_nAfxDaoError.md)|Contém um código de erro estendido para qualquer erro em classes MFC DAO.|  
|[CDaoException::m\_pErrorInfo](../Topic/CDaoException::m_pErrorInfo.md)|Um ponteiro para um objeto de [CDaoErrorInfo](../../mfc/reference/cdaoerrorinfo-structure.md) que contém informações sobre um objeto de erro de DAO.|  
|[CDaoException::m\_scode](../Topic/CDaoException::m_scode.md)|O valor de [SCODE](../Topic/CDaoException::m_scode.md) associada ao erro.|  
  
## Comentários  
 A classe inclui membros públicos de dados que você pode usar para determinar a causa de exceção.  Os objetos de`CDaoException` são construídos e lançados por funções de membro das classes de banco de dados de DAO.  
  
> [!NOTE]
>  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  Você ainda pode acessar fontes de dados ODBC com as classes de DAO.  Em geral, as classes MFC com base em DAO mais são capazes das classes MFC baseado em ODBC; as classes base DAO\- podem acessar os dados, incluindo através dos drivers ODBC, através de seu próprio mecanismo de banco de dados.  As classes base DAO\- também suporta operações language \(DDL\) de definição de dados, como adicionar tabelas por meio de classes, sem precisar chamar diretamente DAO.  Para obter informações sobre as exceções geradas pelas classes ODBC, consulte [CDBException](../../mfc/reference/cdbexception-class.md).  
  
 Você pode acessar objetos de exceção no escopo de uma expressão de [CAPTURA](../Topic/CATCH.md) .  Você também pode lançar objetos de `CDaoException` do seu próprio código com a função global de [AfxThrowDaoException](../Topic/AfxThrowDaoException.md) .  
  
 Em o MFC, todos os erros de DAO são expressos exceções, do tipo `CDaoException`.  Quando você capturar uma exceção de esse tipo, você pode usar funções de membro de `CDaoException` para recuperar informações de todos os objetos de erro de DAO armazenados na coleção de erros do mecanismo de banco de dados.  Como cada erro ocorre, um ou mais objetos de erro são colocados na coleção de erros.  \(Geralmente a coleção contém somente um objeto de erro; se você estiver usando uma fonte de dados ODBC, você provavelmente obter mais objetos de erro.\) Quando outra operação de DAO gera um erro, a coleção de erros está desmarcada, e o novo objeto de erro é colocado na coleção de erros.  Operações de DAO que não produz um erro não tem efeito na coleção de erros.  
  
 Para códigos de erro de DAO, consulte. DAOERR.H o arquivo.  Para informações relacionadas, consulte o tópico “erros Interceptáveis de acesso a dados” na ajuda de DAO.  
  
 Para obter mais informações sobre manipulação de exceção em geral, ou sobre objetos de `CDaoException` , consulte os artigos [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md) e [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  O segundo artigo contém código de exemplo que ilustra a manipulação de exceção em DAO.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CDaoException`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)
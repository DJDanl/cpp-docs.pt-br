---
title: "Classe de CDaoFieldExchange | Microsoft Docs"
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
  - "CDaoFieldExchange"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoFieldExchange"
  - "DAO (objetos de acesso a dados), troca do campo do registro (DFX)"
  - "DFX (troca do campo do registro de DAO)"
  - "DFX (troca do campo do registro de DAO), Campo Exchange de registro de DAO"
  - "trocar dados entre bancos de dados e conjuntos de registros"
  - "troca do campo"
  - "troca do campo, registro para classes de DAO"
  - "RFX (troca do campo do registro)"
  - "RFX (troca do campo do registro), Classes de DAO"
ms.assetid: 350a663e-92ff-44ab-ad53-d94efa2e5823
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoFieldExchange
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta rotinas de troca do campo do registro de DAO \(DFX\) usadas pelas classes de banco de dados de DAO.  
  
## Sintaxe  
  
```  
class CDaoFieldExchange  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoFieldExchange::IsValidOperation](../Topic/CDaoFieldExchange::IsValidOperation.md)|Retorna diferente de zero se a operação atual é apropriado para o tipo de campo que está sendo atualizado.|  
|[CDaoFieldExchange::SetFieldType](../Topic/CDaoFieldExchange::SetFieldType.md)|Especifica o tipo de membro de dados do conjunto de registros — ou — coluna parâmetro representado por quaisquer chamadas subseqüentes a DFX funciona até a chamada a seguir `SetFieldType`.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoFieldExchange::m\_nOperation](../Topic/CDaoFieldExchange::m_nOperation.md)|A operação de DFX que está sendo executada pela chamada atual para a função de membro de `DoFieldExchange` do conjunto de registros.|  
|[CDaoFieldExchange::m\_prs](../Topic/CDaoFieldExchange::m_prs.md)|Um ponteiro ao conjunto de registros em que operações de DFX estão sendo executadas.|  
  
## Comentários  
 `CDaoFieldExchange` não tem uma classe base.  
  
 Use esta classe se você estiver escrevendo rotinas de troca de dados para tipos personalizados de dados; caso contrário, você não usará diretamente de essa classe.  Dados de troca de DFX entre os membros de dados do campo do seu objeto de [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e os campos correspondentes do registro atual na fonte de dados.  DFX gerencia a troca em ambas as direções, da fonte de dados e para a fonte de dados.  Consulte [Observe técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) para obter informações sobre rotinas personalizadas de escrita DFX.  
  
> [!NOTE]
>  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  Você ainda pode acessar fontes de dados ODBC com as classes de DAO.  Em geral, as classes MFC com base em DAO mais são capazes das classes MFC baseado em ODBC.  As classes base DAO\- podem acessar os dados, incluindo através dos drivers ODBC, através de seu próprio mecanismo de banco de dados.  Também suporta operações language \(DDL\) de definição de dados, como adicionar tabelas por meio de classes em vez de ter que chamar DAO você mesmo.  
  
> [!NOTE]
>  A troca do campo do registro de DAO \(DFX\) é muito semelhante à troca do campo do registro \(RFX\) ODBC com base nas classes de banco de dados MFC \(`CDatabase`, `CRecordset`\).  Se você entende RFX, você localizar\-o\-&z DFX fácil de usar.  
  
 Um objeto de `CDaoFieldExchange` fornece informações de contexto necessário para que a troca do campo do registro de DAO ocorra.  Os objetos de`CDaoFieldExchange` oferecem suporte a um número de operações, incluindo membros de associação de parâmetros e dados do campo e sinalizadores de configuração em vários campos de registro atual.  Operações de DFX são executadas em membros de dados de conjunto de registros\- classe de tipos definidos por `enum`**FieldType** em `CDaoFieldExchange`.  Os valores possíveis de **FieldType** são:  
  
-   **CDaoFieldExchange::outputColumn** para membros de dados do campo.  
  
-   **CDaoFieldExchange::param** para membros de dados do parâmetro.  
  
 A função de membro de [IsValidOperation](../Topic/CDaoFieldExchange::IsValidOperation.md) é fornecida escrevendo sua própria rotinas personalizadas DFX.  Você usará [SetFieldType](../Topic/CDaoFieldExchange::SetFieldType.md) com freqüência nas funções de [CDaoRecordset::DoFieldExchange](../Topic/CDaoRecordset::DoFieldExchange.md) .  Para obter detalhes sobre as funções globais de DFX, consulte [Funções de Exchange do campo do registro](../../mfc/reference/record-field-exchange-functions.md).  Para obter informações sobre rotinas personalizadas de escrita DFX para seus próprios tipos de dados, consulte [Observe técnica 53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md).  
  
## Hierarquia de herança  
 `CDaoFieldExchange`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
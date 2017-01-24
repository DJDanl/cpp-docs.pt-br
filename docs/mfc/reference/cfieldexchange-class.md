---
title: "Classe de CFieldExchange | Microsoft Docs"
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
  - "CFieldExchange"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFieldExchange"
  - "tipos de dados [C++], personalizado"
  - "enum FieldType"
  - "enum FieldType, CFieldExchange"
  - "Enumeração FieldType"
  - "RFX (troca do campo do registro) [C++]"
  - "RFX (troca do campo do registro) [C++], para classes"
ms.assetid: 24c5c0b3-06a6-430e-9b6f-005a2c65e29f
caps.latest.revision: 24
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFieldExchange
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Oferece suporte a troca do campo do registro \(RFX\) e rotinas de troca do campo do registro de volume \(RFX em massa\) usadas pelo banco de dados classe.  
  
## Sintaxe  
  
```  
  
class CFieldExchange  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFieldExchange::IsFieldType](../Topic/CFieldExchange::IsFieldType.md)|Retorna diferente de zero se a operação atual é apropriado para o tipo de campo que está sendo atualizado.|  
|[CFieldExchange::SetFieldType](../Topic/CFieldExchange::SetFieldType.md)|Especifica o tipo de membro de dados do conjunto de registros — ou — coluna parâmetro representado por quaisquer chamadas de RFX a seguir funciona até a chamada a seguir `SetFieldType`.|  
  
## Comentários  
 `CFieldExchange` não tem uma classe base.  
  
 Use esta classe se você estiver escrevendo rotinas de troca de dados para tipos personalizados de dados ou quando você estiver implementando buscar em massa de linha; caso contrário, você não usará diretamente de essa classe.  RFX e dados de troca em massa de RFX entre os membros de dados do campo do seu objeto do conjunto de registros e os campos correspondentes do registro atual na fonte de dados.  
  
> [!NOTE]
>  Se você estiver trabalhando com acesso a dados objetos de classes \(DAO\) em vez das classes de Open Database Connectivity \(ODBC\), use a classe [CDaoFieldExchange](../../mfc/reference/cdaofieldexchange-class.md) em vez de isso.  Para obter mais informações, consulte o artigo [visão geral: Programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 Um objeto de `CFieldExchange` fornece informações de contexto necessário para que a troca do campo do registro ou a troca do campo do registro de volume ocorra.  Os objetos de`CFieldExchange` oferecem suporte a um número de operações, incluindo membros de associação de parâmetros e dados do campo e sinalizadores de configuração em vários campos de registro atual.  RFX e operações em massa de RFX são executados em membros de dados de conjunto de registros\- classe de tipos definidos por `enum`**FieldType** em `CFieldExchange`.  Os valores possíveis de **FieldType** são:  
  
-   **CFieldExchange::outputColumn** para membros de dados do campo.  
  
-   **CFieldExchange::inputParam** ou **CFieldExchange::param** para membros de dados do parâmetro de entrada.  
  
-   **CFieldExchange::outputParam** para membros de dados do parâmetro de saída.  
  
-   **CFieldExchange::inoutParam** para membros de dados do parâmetro de arquivos entrada\/saída.  
  
 A maioria dos membros das funções de membro e dados de classe são fornecidos escrevendo sua própria rotinas personalizadas RFX.  Você usará `SetFieldType` com freqüência.  Para obter mais informações, consulte os artigos [Campo do registro Exchange \(RFX\)](../../data/odbc/record-field-exchange-rfx.md) e [Recordset \(ODBC\)](../../data/odbc/recordset-odbc.md).  Para obter informações sobre a linha em massa que pesquisa, consulte o artigo [conjunto de registros: Para buscar registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  Para obter detalhes sobre as funções globais de RFX e de volume RFX, consulte [Registrar funções de Exchange do campo](../../mfc/reference/record-field-exchange-functions.md) na seção de macros e de Globais MFC essa referência.  
  
## Hierarquia de herança  
 `CFieldExchange`  
  
## Requisitos  
 **Cabeçalho:** afxdb.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)
---
title: "Registrar fun&#231;&#245;es de troca de campos | Microsoft Docs"
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
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DAO (objetos de acesso de dados), a troca de campos de registro (DFX)"
  - "ODBC, funções da troca de dados RFX em massa"
  - "RFX (troca de campos de registro), classes ODBC"
  - "DFX (troca de campos de registro DAO), funções de troca de dados"
  - "Funções DFX"
  - "funções RFX em massa"
  - "DFX (troca de campos de registro DAO)"
  - "RFX (troca de campos de registro), classes DAO"
  - "ODBC, RFX"
  - "RFX (troca de campos de registro), funções de troca de dados"
  - "RFX (troca de campos de registro)"
ms.assetid: 6e4c5c1c-acb7-4c18-bf51-bf7959a696cd
caps.latest.revision: 13
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrar fun&#231;&#245;es de troca de campos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico lista a troca de campos do registro \([RFX](#_mfc_rfx_functions_.28.odbc.29), [RFX em massa](#_mfc_bulk_rfx_functions_.28.odbc.29), e [DFX](#_mfc_dfx_functions_.28.dao.29)\) funções usadas para automatizar a transferência de dados entre um objeto recordset e sua fonte de dados e executar outras operações nos dados.  
  
 Se você estiver usando as classes baseadas em ODBC e implementou busca de linhas em massa, você deve substituir manualmente o `DoBulkFieldExchange` função de membro `CRecordset` chamando as funções RFX em massa para cada membro de dados correspondente a uma coluna de fonte de dados.  
  
 Se você não implementou busca de linhas em massa nas classes com base em ODBC, ou se você estiver usando as classes baseadas em DAO, em seguida, ClassWizard substituirá o `DoFieldExchange` função de membro `CRecordset` ou `CDaoRecordset` chamando as funções RFX \(para classes do ODBC\) ou as funções DFX \(para classes DAO\) para cada membro de dados do campo de registros.  
  
 As funções de troca de campos de registro transferir dados cada vez que o framework chama `DoFieldExchange` ou `DoBulkFieldExchange`. Cada função transfere um tipo de dados específico.  
  
 Para obter mais informações sobre como essas funções são usadas, consulte os artigos [registrar troca de campos: como RFX Works \(ODBC\)](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: recuperando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Para colunas de dados que você associar dinamicamente, você também pode chamar as funções RFX ou DFX, conforme explicado nos artigos [Recordset: dinamicamente associando dados colunas \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md). Além disso, você pode escrever suas próprias rotinas RFX ou DFX personalizadas, conforme explicado na Observação técnica [43](../Topic/TN043:%20RFX%20Routines.md) \(para ODBC\) e nota técnica [53](../../mfc/tn053-custom-dfx-routines-for-dao-database-classes.md) \(para DAO\).  
  
 Para obter um exemplo de RFX e RFX em massa funciona como aparecem no `DoFieldExchange` e `DoBulkFieldExchange` funções, consulte [RFX\_Text](../Topic/RFX_Text.md) e [RFX\_Text\_Bulk](../Topic/RFX_Text_Bulk.md). Funções DFX são muito semelhantes às funções RFX.  
  
### Funções RFX \(ODBC\)  
  
|||  
|-|-|  
|[RFX\_Binary](../Topic/RFX_Binary.md)|Transferências de matrizes de bytes do tipo [CByteArray](../../mfc/reference/cbytearray-class.md).|  
|[RFX\_Bool](../Topic/RFX_Bool.md)|Transferências de dados booleano.|  
|[RFX\_Byte](../Topic/RFX_Byte.md)|Transfere um único byte de dados.|  
|[RFX\_Date](../Topic/RFX_Date.md)|Transferências de hora e data de dados usando [CTime](../Topic/CTime%20Class.md) ou **TIMESTAMP\_STRUCT**.|  
|[RFX\_Double](../Topic/RFX_Double.md)|Transferências de dados flutuante de precisão dupla.|  
|[RFX\_Int](../Topic/RFX_Int.md)|Transferências de dados inteiro.|  
|[RFX\_Long](../Topic/RFX_Long.md)|Transferências de dados integer de comprimento.|  
|[RFX\_LongBinary](../Topic/RFX_LongBinary.md)|Transfere os dados de objeto binário grande \(BLOB\) com um objeto de [CLongBinary](../../mfc/reference/clongbinary-class.md) classe.|  
|[RFX\_Single](../Topic/RFX_Single.md)|Transferências de dados de flutuação.|  
|[RFX\_Text](../Topic/RFX_Text.md)|Transferências de dados de cadeia de caracteres.|  
  
### Funções RFX em massa \(ODBC\)  
  
|||  
|-|-|  
|[RFX\_Binary\_Bulk](../Topic/RFX_Binary_Bulk.md)|Transferências de matrizes de bytes de dados.|  
|[RFX\_Bool\_Bulk](../Topic/RFX_Bool_Bulk.md)|Matrizes de dados booliano é transferido.|  
|[RFX\_Byte\_Bulk](../Topic/RFX_Byte_Bulk.md)|Transferências de matrizes de bytes simples.|  
|[RFX\_Date\_Bulk](../Topic/RFX_Date_Bulk.md)|Transfere conjuntos de dados do tipo **TIMESTAMP\_STRUCT**.|  
|[RFX\_Double\_Bulk](../Topic/RFX_Double_Bulk.md)|Transferências de conjuntos de dados de ponto flutuantes de precisão dupla.|  
|[RFX\_Int\_Bulk](../Topic/RFX_Int_Bulk.md)|Transferências de matrizes de dados inteiro.|  
|[RFX\_Long\_Bulk](../Topic/RFX_Long_Bulk.md)|Transferências de conjuntos de dados de inteiro longo.|  
|[RFX\_Single\_Bulk](../Topic/RFX_Single_Bulk.md)|Transferências de conjuntos de dados de ponto flutuante.|  
|[RFX\_Text\_Bulk](../Topic/RFX_Text_Bulk.md)|Transfere conjuntos de dados do tipo **LPSTR**.|  
  
### Funções DFX \(DAO\)  
  
|||  
|-|-|  
|[DFX\_Binary](../Topic/DFX_Binary.md)|Transferências de matrizes de bytes do tipo [CByteArray](../../mfc/reference/cbytearray-class.md).|  
|[DFX\_Bool](../Topic/DFX_Bool.md)|Transferências de dados booleano.|  
|[DFX\_Byte](../Topic/DFX_Byte.md)|Transfere um único byte de dados.|  
|[DFX\_Currency](../Topic/DFX_Currency.md)|Transfere dados de moeda, do tipo [COleCurrency](../Topic/COleCurrency%20Class.md).|  
|[DFX\_DateTime](../Topic/DFX_DateTime.md)|Transferências de dados de data e hora, do tipo [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md).|  
|[DFX\_Double](../Topic/DFX_Double.md)|Transferências de dados flutuante de precisão dupla.|  
|[DFX\_Long](../Topic/DFX_Long.md)|Transferências de dados integer de comprimento.|  
|[DFX\_LongBinary](../Topic/DFX_LongBinary.md)|Transfere os dados de objeto binário grande \(BLOB\) com um objeto de `CLongBinary` classe. Para o DAO, é recomendável que você use [DFX\_Binary](../Topic/DFX_Binary.md) em vez disso.|  
|[DFX\_Short](../Topic/DFX_Short.md)|Transferências de dados integer de curta.|  
|[DFX\_Single](../Topic/DFX_Single.md)|Transferências de dados de flutuação.|  
|[DFX\_Text](../Topic/DFX_Text.md)|Transferências de dados de cadeia de caracteres.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [CRecordset::DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md)   
 [CRecordset::DoBulkFieldExchange](../Topic/CRecordset::DoBulkFieldExchange.md)   
 [CDaoRecordset::DoFieldExchange](../Topic/CDaoRecordset::DoFieldExchange.md)
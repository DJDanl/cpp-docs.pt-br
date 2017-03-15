---
title: "Registrar troca de campos: usando as fun&#231;&#245;es RFX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de dados [C++], troca de campos de registro ODBC"
  - "Método DoFieldExchange, e funções RFX"
  - "chamadas de função, Funções RFX"
  - "ODBC [C++], tipos de dados"
  - "ODBC [C++], RFX"
  - "RFX (ODBC) [C++], tipos de dados"
  - "RFX (ODBC) [C++], sintaxe de função e parâmetros"
ms.assetid: c594300b-5a29-4119-a68b-e7ca32def696
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrar troca de campos: usando as fun&#231;&#245;es RFX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como usar as chamadas de função de RFX que compõem o corpo da substituição de `DoFieldExchange` .  
  
> [!NOTE]
>  Este tópico se aplicam às classes derivadas de [CRecordset](../Topic/CRecordset%20Class.md) no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, a troca do campo de registro em massa \(RFX em massa\) é implementada.  RFX em massa é semelhante a RFX.  Para entender as diferenças, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Trocar dados globais das funções de RFX entre as colunas da fonte de dados e membros de dados do campo em seu conjunto de registros.  Você escreve as chamadas de função de RFX na função de membro de [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) do conjunto de registros.  Este tópico descreve brevemente as funções e mostra os tipos de dados para as funções de RFX estão disponíveis.  [Observação 43 técnica](../Topic/TN043:%20RFX%20Routines.md) descreve como escrever suas próprias funções de RFX para tipos de dados adicionais.  
  
##  <a name="_core_rfx_function_syntax"></a> Sintaxe da função de RFX  
 Cada função de RFX usa três parâmetros \(e quaisquer faça um quarto ou quinto parâmetro opcional\):  
  
-   Um ponteiro para um objeto de [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) .  Você passa somente ao longo do ponteiro de `pFX` passado a `DoFieldExchange`.  
  
-   O nome da coluna conforme aparece na fonte de dados.  
  
-   O nome do membro de dados correspondente do campo ou do membro de dados do parâmetro na classe do conjunto de registros.  
  
-   \(Opcional\) Em qualquer uma das funções, o comprimento máximo de cadeia de caracteres ou matriz que está sendo transferida.  Isso será padronizado como 255 bytes, mas você pode querer alterá\-lo.  O tamanho máximo é baseado no tamanho máximo de um objeto de `CString` — 2.147.483.647\) bytes de **INT\_MAX** \(— mas você encontrará provavelmente os limites do driver antes da dimensão.  
  
-   \(Opcional\) No função de `RFX_Text` , você usa às vezes um quinto parâmetro para especificar o tipo de dados de uma coluna.  
  
 Para obter mais informações, consulte o RFX funções em [Macros e Globais](../Topic/Macros,%20Global%20Functions,%20and%20Global%20Variables.md)*na referência da biblioteca da classe*.  Para obter um exemplo de como você pode fazer uso especial os parâmetros, consulte [Conjunto de registros: Obtendo somas e outro a agregação resultados \(ODBC\)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md).  
  
##  <a name="_core_rfx_data_types"></a> Tipos de dados de RFX  
 A biblioteca de classe fornece funções de RFX para transferir muitos tipos de dados diferentes entre a fonte de dados e os conjuntos de registros.  A lista a seguir resume as funções de RFX o tipo de dados.  Em casos onde você deve escrever suas próprias chamadas de função de RFX dessas funções, selecione o tipo de dados.  
  
|Função|Tipo de dados|  
|------------|-------------------|  
|`RFX_Bool`|**BOOL**|  
|`RFX_Byte`|**BYTE**|  
|`RFX_Binary`|`CByteArray`|  
|`RFX_Double`|**double**|  
|`RFX_Single`|**float**|  
|`RFX_Int`|`int`|  
|`RFX_Long`|**long**|  
|`RFX_LongBinary`|`CLongBinary`|  
|`RFX_Text`|`CString`|  
|`RFX_Date`|`CTime`|  
  
 Para obter mais informações, consulte a documentação da função de RFX em [Macros e Globais](../Topic/Macros,%20Global%20Functions,%20and%20Global%20Variables.md)*na referência da biblioteca da classe*.  Para obter informações sobre como os tipos de dados do C\+\+ para tipos de dados do SQL, consulte os tipos de dados SQL ANSI de tabela mapeados para tipos de dados do C\+\+ em [SQL: SQL e tipos de dados do C\+\+ \(ODBC\)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).  
  
## Consulte também  
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)   
 [Registrar troca de campos: como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)   
 [Conjunto de registros: parametrizando um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)   
 [Conjunto de registros: associando dinamicamente colunas de dados \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)   
 [Classe de CFieldExchange](../../mfc/reference/cfieldexchange-class.md)
---
title: 'Registrar troca de campos: Usando as funções RFX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC [C++], data types
- data types [C++], ODBC record field exchange
- RFX (ODBC) [C++], function syntax and parameters
- DoFieldExchange method, and RFX functions
- ODBC [C++], RFX
- RFX (ODBC) [C++], data types
- function calls, RFX functions
ms.assetid: c594300b-5a29-4119-a68b-e7ca32def696
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bc49ede976fe8126e2996b72174c98f5abba780a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060709"
---
# <a name="record-field-exchange-using-the-rfx-functions"></a>Registrar troca de campos: usando as funções RFX

Este tópico explica como usar as chamadas de função RFX que compõem o corpo da sua `DoFieldExchange` substituir.

> [!NOTE]
>  Este tópico se aplica a classes derivadas [CRecordset](../../mfc/reference/crecordset-class.md) em qual linha em massa buscando não foi implementado. Se você estiver usando a busca de linhas em massa, é implementada em massa registrar troca de campos (RFX em massa). Em massa RFX é semelhante a RFX. Para entender as diferenças, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

As funções globais de RFX trocam dados entre as colunas nos dados de origem e campo dados membros no seu conjunto de registros. Você escreve a função RFX chama em seu conjunto de registros [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) função de membro. Este tópico descreve as funções rapidamente e mostra os tipos de dados para o qual RFX funções estão disponíveis. [43 de observação técnica](../../mfc/tn043-rfx-routines.md) descreve como escrever suas próprias funções RFX para tipos de dados adicionais.

##  <a name="_core_rfx_function_syntax"></a> Sintaxe da função RFX

Cada função RFX usa três parâmetros (e alguns de um parâmetro opcional do quarto ou quinto):

- Um ponteiro para um [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto. Você simplesmente passa a `pFX` ponteiro passado para `DoFieldExchange`.

- O nome da coluna como ele aparece na fonte de dados.

- O nome do membro de dados correspondente do campo ou membro de dados de parâmetro na classe de conjunto de registros.

- (Opcional) Em algumas das funções, o comprimento máximo da cadeia de caracteres ou matriz que estão sendo transferidos. Esse padrão é 255 bytes, mas você talvez queira alterá-lo. O tamanho máximo é com base no tamanho máximo de um `CString` objeto — **INT_MAX** (2.147.483.647) bytes — mas você provavelmente encontrará os limites de driver antes que o tamanho.

- (Opcional) No `RFX_Text` função, você às vezes usa um quinto parâmetro para especificar o tipo de dados de uma coluna.

Para obter mais informações, consulte as funções RFX sob [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência da biblioteca de classe*. Para obter um exemplo de quando você pode fazer especial usar os parâmetros, consulte [conjunto de registros: Obtendo SUMs e outros agregar resultados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md).

##  <a name="_core_rfx_data_types"></a> Tipos de dados RFX

A biblioteca de classes fornece funções RFX para transferir vários tipos de dados diferentes entre a fonte de dados e conjuntos de registros. A lista a seguir resume as funções RFX pelo tipo de dados. Em casos em que você deve escrever suas próprias chamadas de função RFX, selecione uma dessas funções pelo tipo de dados.

|Função|Tipo de dados|
|--------------|---------------|
|`RFX_Bool`|**BOOL**|
|`RFX_Byte`|**BYTE**|
|`RFX_Binary`|`CByteArray`|
|`RFX_Double`|**double**|
|`RFX_Single`|**float**|
|`RFX_Int`|**int**|
|`RFX_Long`|**long**|
|`RFX_LongBinary`|`CLongBinary`|
|`RFX_Text`|`CString`|
|`RFX_Date`|`CTime`|


Para obter mais informações, consulte a documentação da função RFX sob [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência da biblioteca de classe*. Para obter informações sobre como os tipos de dados C++ são mapeados para tipos de dados SQL, consulte a tabela ANSI SQL dados tipos mapeados para tipos de dados C++ na [SQL: SQL e tipos de dados do C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).

## <a name="see-also"></a>Consulte também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Troca de campo de registro: como a RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)<br/>
[Conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)<br/>
[Conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)
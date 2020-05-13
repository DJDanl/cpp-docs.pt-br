---
title: 'Registrar troca de campos: usando as funções RFX'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC [C++], data types
- data types [C++], ODBC record field exchange
- RFX (ODBC) [C++], function syntax and parameters
- DoFieldExchange method, and RFX functions
- ODBC [C++], RFX
- RFX (ODBC) [C++], data types
- function calls, RFX functions
ms.assetid: c594300b-5a29-4119-a68b-e7ca32def696
ms.openlocfilehash: f1afded360cfeff564f1f3d8bb9b294aa33cb733
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367127"
---
# <a name="record-field-exchange-using-the-rfx-functions"></a>Registrar troca de campos: usando as funções RFX

Este tópico explica como usar as chamadas de função `DoFieldExchange` RFX que compõem o corpo do seu dispositivo.

> [!NOTE]
> Este tópico se aplica às classes derivadas do [CRecordset,](../../mfc/reference/crecordset-class.md) nas quais a busca de linhas em massa não foi implementada. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

As funções globais do RFX trocam dados entre colunas na fonte de dados e membros de dados de campo em seu conjunto de registros. Você grava as chamadas de função RFX na função do membro [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) do seu conjunto de registros. Este tópico descreve as funções brevemente e mostra os tipos de dados para os quais as funções RFX estão disponíveis. [O Technical Note 43](../../mfc/tn043-rfx-routines.md) descreve como escrever suas próprias funções RFX para tipos de dados adicionais.

## <a name="rfx-function-syntax"></a><a name="_core_rfx_function_syntax"></a>Sintaxe de função RFX

Cada função RFX tem três parâmetros (e alguns tomam um quarto ou quinto parâmetro opcional):

- Um ponteiro para um objeto [CFieldExchange.](../../mfc/reference/cfieldexchange-class.md) Você simplesmente passa `pFX` ao `DoFieldExchange`longo do ponteiro passado para .

- O nome da coluna como aparece na fonte de dados.

- O nome do membro de dados de campo correspondente ou membro de dados de parâmetro na classe recordset.

- (Opcional) Em algumas das funções, o comprimento máximo da seqüência ou matriz está sendo transferido. Isso é padrão para 255 bytes, mas você pode querer alterá-lo. O tamanho máximo é baseado no `CString` tamanho máximo de um objeto — **INT_MAX** (2.147.483.647) bytes — mas você provavelmente encontrará limites de motorista antes desse tamanho.

- (Opcional) Na `RFX_Text` função, às vezes você usa um quinto parâmetro para especificar o tipo de dados de uma coluna.

Para obter mais informações, consulte as funções RFX em [Macros e Globals](../../mfc/reference/mfc-macros-and-globals.md) na *Referência da Biblioteca de Classe*. Para um exemplo de quando você pode fazer uso especial dos parâmetros, consulte [Recordset: Obtendo SUMs e Outros Resultados Agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md).

## <a name="rfx-data-types"></a><a name="_core_rfx_data_types"></a>Tipos de dados RFX

A biblioteca de classes fornece funções RFX para transferir muitos tipos de dados diferentes entre a fonte de dados e seus conjuntos de registros. A lista a seguir resume as funções RFX por tipo de dados. Nos casos em que você deve escrever suas próprias chamadas de função RFX, selecione entre essas funções por tipo de dados.

|Função|Tipo de dados|
|--------------|---------------|
|`RFX_Bool`|**Bool**|
|`RFX_Byte`|**Byte**|
|`RFX_Binary`|`CByteArray`|
|`RFX_Double`|**double**|
|`RFX_Single`|**float**|
|`RFX_Int`|**int**|
|`RFX_Long`|**Longas**|
|`RFX_LongBinary`|`CLongBinary`|
|`RFX_Text`|`CString`|
|`RFX_Date`|`CTime`|

Para obter mais informações, consulte a documentação da função RFX em [Macros e Globals](../../mfc/reference/mfc-macros-and-globals.md) na *Referência da Biblioteca de Classe*. Para obter informações sobre como os tipos de dados C++ mapeiam para os tipos de dados SQL, consulte a tabela ANSI SQL Data Types Mapapped to C++ Data Types in [SQL: SQL and C++ Data Types (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).

## <a name="see-also"></a>Confira também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Registrar troca de campos: como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)<br/>
[Conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)<br/>
[Conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CfieldExchange](../../mfc/reference/cfieldexchange-class.md)

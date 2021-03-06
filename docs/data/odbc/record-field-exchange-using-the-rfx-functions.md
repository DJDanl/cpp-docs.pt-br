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
ms.openlocfilehash: 4d621fbe2207114dd51845b819d309802a009690
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216525"
---
# <a name="record-field-exchange-using-the-rfx-functions"></a>Registrar troca de campos: usando as funções RFX

Este tópico explica como usar as chamadas de função suporte RFX que compõem o corpo da sua `DoFieldExchange` substituição.

> [!NOTE]
> Este tópico se aplica a classes derivadas de [CRecordset](../../mfc/reference/crecordset-class.md) em que a busca de linha em massa não foi implementada. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

As funções globais suporte RFX trocam dados entre colunas na fonte de dados e membros de dados de campo em seu conjunto de registros. Você escreve as chamadas de função suporte RFX na função de membro [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) do conjunto de registros. Este tópico descreve brevemente as funções e mostra os tipos de dados para os quais as funções suporte RFX estão disponíveis. A [Observação técnica 43](../../mfc/tn043-rfx-routines.md) descreve como escrever suas próprias funções suporte RFX para tipos de dados adicionais.

## <a name="rfx-function-syntax"></a><a name="_core_rfx_function_syntax"></a>Sintaxe da função suporte RFX

Cada função suporte RFX usa três parâmetros (e alguns usam um quarto ou quinto parâmetro opcional):

- Um ponteiro para um objeto [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) . Basta passar o `pFX` ponteiro passado para `DoFieldExchange` .

- O nome da coluna como aparece na fonte de dados.

- O nome do membro de dados do campo correspondente ou membro de dados de parâmetro na classe do conjunto de registros.

- Adicional Em algumas das funções, o comprimento máximo da cadeia de caracteres ou da matriz que está sendo transferida. O padrão é 255 bytes, mas talvez você queira alterá-lo. O tamanho máximo é baseado no tamanho máximo de um `CString` objeto – **INT_MAX** (2.147.483.647) bytes, mas você provavelmente encontrará limites de driver antes desse tamanho.

- Adicional Na `RFX_Text` função, você às vezes usa um quinto parâmetro para especificar o tipo de dados de uma coluna.

Para obter mais informações, consulte as funções suporte RFX em [macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência da biblioteca de classes*. Para obter um exemplo de quando você pode fazer uso especial dos parâmetros, consulte [conjunto de registros: Obtendo somas e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md).

## <a name="rfx-data-types"></a><a name="_core_rfx_data_types"></a>Tipos de dados suporte RFX

A biblioteca de classes fornece funções suporte RFX para transferir vários tipos de dados diferentes entre a fonte de dados e seus conjuntos de registros. A lista a seguir resume as funções suporte RFX por tipo de dados. Nos casos em que você deve escrever suas próprias chamadas de função suporte RFX, selecione essas funções por tipo de dados.

|Função|Tipo de dados|
|--------------|---------------|
|`RFX_Bool`|**BOOL**|
|`RFX_Byte`|**MINUCIOSA**|
|`RFX_Binary`|`CByteArray`|
|`RFX_Double`|**`double`**|
|`RFX_Single`|**`float`**|
|`RFX_Int`|**`int`**|
|`RFX_Long`|**`long`**|
|`RFX_LongBinary`|`CLongBinary`|
|`RFX_Text`|`CString`|
|`RFX_Date`|`CTime`|

Para obter mais informações, consulte a documentação da função suporte RFX em [macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência da biblioteca de classes*. Para obter informações sobre como os tipos de dados do C++ são mapeados para tipos de dados SQL, consulte a tabela tipos de dados SQL ANSI mapeados para tipos de dados do C++ em [SQL: tipos de dados SQL e C++ (ODBC)](../../data/odbc/sql-sql-and-cpp-data-types-odbc.md).

## <a name="see-also"></a>Confira também

[Gravar campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Gravar campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)<br/>
[Conjunto de registros: parametrização de um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)<br/>
[Conjunto de registros: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)

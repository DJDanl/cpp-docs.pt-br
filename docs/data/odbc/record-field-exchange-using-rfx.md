---
title: 'Registrar troca de campos: usando RFX'
ms.date: 11/04/2016
helpviewer_keywords:
- RFX (ODBC), implementing
ms.assetid: ada8f043-37e6-4d41-9db3-92c997a61957
ms.openlocfilehash: dc0cdcee758f4842b0738068a8a11c4e2e404155
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367141"
---
# <a name="record-field-exchange-using-rfx"></a>Registrar troca de campos: usando RFX

Este tópico explica o que você faz para usar o RFX em relação ao que o framework faz.

> [!NOTE]
> Este tópico se aplica às classes derivadas do [CRecordset,](../../mfc/reference/crecordset-class.md) nas quais a busca de linhas em massa não foi implementada. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Os seguintes tópicos contêm informações relacionadas:

- [Record Field Exchange: Working with the Wizard Code](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md) introduz os principais componentes do RFX e explica o código que o Assistente de Aplicativo do MFC e a Classe de **Adicionar** (conforme descrito em Adicionar [um MFC ODBC Consumer](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) escrevem para suportar o RFX e como você pode querer modificar o código assistente.

- [Troca de campo de registro: O uso das funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md) explica a gravação de chamadas para as funções RFX em sua `DoFieldExchange` substituição.

A tabela a seguir mostra o seu papel em relação ao que a estrutura faz por você.

### <a name="using-rfx-you-and-the-framework"></a>Usando o RFX: Você e o Framework

|Você|A estrutura|
|---------|-------------------|
|Declare suas classes de gravação com um assistente. Especifique nomes e tipos de dados de membros de dados de campo.|O assistente deriva `CRecordset` uma classe e escreve uma substituição [do DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) para você, incluindo uma chamada de função RFX para cada membro de dados de campo.|
|(Opcional) Adicione manualmente todos os membros de dados de parâmetronecessários à classe. Adicione manualmente uma chamada `DoFieldExchange` de função RFX para cada membro de dados de parâmetros, adicione uma chamada ao [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) para o grupo de parâmetros e especifique o número total de parâmetros em [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams). Ver [Conjunto de registros: Parametrização de um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).||
|(Opcional) Vincule manualmente colunas adicionais a membros de dados de campo. Incremente manualmente [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields). Ver [conjunto de registros: Colunas de dados de vinculação dinâmica (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||
|Construa um objeto de sua classe de gravação. Antes de usar o objeto, defina os valores de seus membros de dados de parâmetros, se houver.|Para eficiência, a estrutura pré-liga os parâmetros, utilizando ODBC. Quando você passa valores de parâmetro, a estrutura os passa para a fonte de dados. Apenas os valores dos parâmetros são enviados para requeries, a menos que as seqüências de tipo e/ou filtro tenham sido alteradas.|
|Abra um objeto de conjunto de registros usando [CRecordset::Open](../../mfc/reference/crecordset-class.md#open).|Executa a consulta do conjunto de registros, vincula colunas a membros `DoFieldExchange` de dados de campo do conjunto de registros e chama para trocar dados entre o primeiro registro selecionado e os membros de dados de campo do conjunto de registros.|
|Role no conjunto de registros usando [CRecordset::Move](../../mfc/reference/crecordset-class.md#move) ou um menu ou comando toolbar.|Chamadas `DoFieldExchange` para transferir dados para os membros de dados de campo do novo registro atual.|
|Adicione, atualize e exclua registros.|Chamadas `DoFieldExchange` para transferir dados para a fonte de dados.|

## <a name="see-also"></a>Confira também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Registrar troca de campos: como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)<br/>
[Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CfieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)

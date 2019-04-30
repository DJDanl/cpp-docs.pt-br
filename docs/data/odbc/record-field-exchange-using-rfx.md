---
title: 'Registrar troca de campos: Usando RFX'
ms.date: 11/04/2016
helpviewer_keywords:
- RFX (ODBC), implementing
ms.assetid: ada8f043-37e6-4d41-9db3-92c997a61957
ms.openlocfilehash: 2a029f653753363e08b3c4f8b9fceab6295924af
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395645"
---
# <a name="record-field-exchange-using-rfx"></a>Registrar troca de campos: Usando RFX

Este tópico explica o que fazer para usar RFX em relação a estrutura que funciona.

> [!NOTE]
>  Este tópico se aplica a classes derivadas [CRecordset](../../mfc/reference/crecordset-class.md) em qual linha em massa buscando não foi implementado. Se você estiver usando a busca de linhas em massa, é implementada em massa registrar troca de campos (RFX em massa). Em massa RFX é semelhante a RFX. Para entender as diferenças, consulte [conjunto de registros: Buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Os tópicos a seguir contêm informações relacionadas:

- [Registrar troca de campos: Trabalhando com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md) apresenta os principais componentes do RFX e explica o código que o Assistente de aplicativo do MFC e **Adicionar classe** (conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) de gravação para dar suporte a RFX e como você pode modificar o código do assistente.

- [Registrar troca de campos: Usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md) explica as chamadas de gravação para as funções RFX em seu `DoFieldExchange` substituir.

A tabela a seguir mostra a sua função em relação ao que a estrutura faz para você.

### <a name="using-rfx-you-and-the-framework"></a>Usando RFX: Você e a estrutura

|Você|A estrutura|
|---------|-------------------|
|Declare suas classes de conjunto de registros com um assistente. Especifique os nomes e tipos de dados de membros de dados do campo.|O assistente deriva uma `CRecordset` classe e gravações uma [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) substituir para você, incluindo um RFX chamada para cada membro de dados do campo de função.|
|(Opcional) Adicione manualmente quaisquer membros de dados de parâmetro necessários para a classe. Adicionar manualmente uma chamada de função para RFX `DoFieldExchange` para cada membro de dados de parâmetro, adicione uma chamada para [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) para o grupo de parâmetros e especifique o número total de parâmetros em [m_nParams ](../../mfc/reference/crecordset-class.md#m_nparams). Consulte [conjunto de registros: Parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).||
|(Opcional) Associe manualmente as colunas adicionais aos membros de dados do campo. Incrementar manualmente [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields). Consulte [conjunto de registros: Associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||
|Construa um objeto da sua classe de conjunto de registros. Antes de usar o objeto, defina os valores de seu parâmetro membros de dados, se houver.|Para obter eficiência, o framework prebinds os parâmetros, usando o ODBC. Quando você passa valores de parâmetro, o framework passa para a fonte de dados. Somente os valores de parâmetro são enviados para requeries, a menos que as cadeias de caracteres de classificação e/ou filtro foram alterados.|
|Abra um objeto de conjunto de registros usando [{1&gt;crecordset::Open&lt;1](../../mfc/reference/crecordset-class.md#open).|Executa a consulta do conjunto de registros, associa as colunas para membros de dados de campo do conjunto de registros e chamadas `DoFieldExchange` para trocar dados entre o primeiro registro selecionado e membros de dados de campo do conjunto de registros.|
|Rolagem no conjunto de registros usando [CRecordset::Move](../../mfc/reference/crecordset-class.md#move) ou um comando de menu ou barra de ferramentas.|Chamadas `DoFieldExchange` para transferir dados para os membros de dados do campo do novo registro atual.|
|Adicionar, atualizar e excluir registros.|Chamadas `DoFieldExchange` para transferir dados para a fonte de dados.|

## <a name="see-also"></a>Consulte também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Registrar troca de campos: como o RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)<br/>
[Conjunto de registros: obter SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)


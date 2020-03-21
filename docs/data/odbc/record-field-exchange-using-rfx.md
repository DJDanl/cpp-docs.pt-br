---
title: 'Registrar troca de campos: usando RFX'
ms.date: 11/04/2016
helpviewer_keywords:
- RFX (ODBC), implementing
ms.assetid: ada8f043-37e6-4d41-9db3-92c997a61957
ms.openlocfilehash: 70197d2a9130388e86bb94f0d670360bb35febeb
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075862"
---
# <a name="record-field-exchange-using-rfx"></a>Registrar troca de campos: usando RFX

Este tópico explica o que você faz para usar o suporte RFX em relação ao que a estrutura faz.

> [!NOTE]
>  Este tópico se aplica a classes derivadas de [CRecordset](../../mfc/reference/crecordset-class.md) em que a busca de linha em massa não foi implementada. Se você estiver usando o fetch de linha em massa, a RFX (troca de campos de registro) em massa será implementada. A RFX em massa é semelhante à RFX. Para entender as diferenças, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Os tópicos a seguir contêm informações relacionadas:

- [Gravar campo Exchange: trabalhar com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md) apresenta os principais componentes do suporte RFX e explica o código que o assistente de aplicativo do MFC e **adiciona a classe** (conforme descrito em [adicionando um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) Write para dar suporte a suporte RFX e como você pode querer modificar o código do assistente.

- [Gravar o campo Exchange: usar as funções suporte RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md) explica a gravação de chamadas para as funções suporte RFX em sua substituição de `DoFieldExchange`.

A tabela a seguir mostra sua função em relação ao que a estrutura faz para você.

### <a name="using-rfx-you-and-the-framework"></a>Usando suporte RFX: você e a estrutura

|Você|A estrutura|
|---------|-------------------|
|Declare as classes do conjunto de registros com um assistente. Especifique nomes e tipos de dados de membros de dados de campo.|O Assistente deriva uma classe `CRecordset` e grava uma substituição [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) para você, incluindo uma chamada de função suporte RFX para cada membro de dados de campo.|
|Adicional Adicione manualmente todos os membros de dados de parâmetro necessários à classe. Adicione manualmente uma chamada de função suporte RFX para `DoFieldExchange` para cada membro de dados de parâmetro, adicione uma chamada para [CFieldExchange:: SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) para o grupo de parâmetros e especifique o número total de parâmetros em [m_nParams](../../mfc/reference/crecordset-class.md#m_nparams). Confira [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).||
|Adicional Associe manualmente colunas adicionais a membros de dados de campo. Incrementar manualmente [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields). Consulte [conjunto de registros: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||
|Construa um objeto da sua classe recordset. Antes de usar o objeto, defina os valores de seus membros de dados de parâmetro, se houver.|Para eficiência, a estrutura preassocia os parâmetros usando o ODBC. Quando você passa valores de parâmetro, a estrutura passa-os para a fonte de dados. Somente os valores de parâmetro são enviados para reconsultas, a menos que as cadeias de caracteres de classificação e/ou de filtro tenham sido alteradas.|
|Abra um objeto Recordset usando [CRecordset:: Open](../../mfc/reference/crecordset-class.md#open).|Executa a consulta do conjunto de registros, associa colunas a membros de dados de campo do conjunto de registros e chama `DoFieldExchange` para trocar dados entre o primeiro registro selecionado e os membros de dados de campo do conjunto de registros.|
|Role no conjunto de registros usando [CRecordset:: move](../../mfc/reference/crecordset-class.md#move) ou um menu ou comando de barra de ferramentas.|Chama `DoFieldExchange` para transferir dados para os membros de dados de campo do novo registro atual.|
|Adicionar, atualizar e excluir registros.|Chama `DoFieldExchange` para transferir dados para a fonte de dados.|

## <a name="see-also"></a>Confira também

[RFX (troca de campo de registro)](../../data/odbc/record-field-exchange-rfx.md)<br/>
[Troca de campo de registro: como a RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md)<br/>
[Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)

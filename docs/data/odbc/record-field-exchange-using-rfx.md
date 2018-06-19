---
title: 'Registrar troca de campos: Usando RFX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- RFX (ODBC), implementing
ms.assetid: ada8f043-37e6-4d41-9db3-92c997a61957
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 296ae2e4f535e08924a77b8726b93778a6da5026
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33091992"
---
# <a name="record-field-exchange-using-rfx"></a>Registrar troca de campos: usando RFX
Este tópico explica o que fazer para usar RFX em relação a estrutura faz.  
  
> [!NOTE]
>  Este tópico se aplica a classes derivadas de [CRecordset](../../mfc/reference/crecordset-class.md) em qual linha em massa busca não foi implementada. Se você estiver usando a busca de linhas em massa, a troca de campos de registro em massa (RFX em massa) é implementada. Em massa RFX é semelhante a RFX. Para entender as diferenças, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
 Os tópicos a seguir contêm informações relacionadas:  
  
-   [Registrar troca de campos: Trabalhando com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md) apresenta os componentes principais do RFX e explica o código que o Assistente de aplicativo MFC e **Adicionar classe** (conforme descrito em [adicionando um consumidor de ODBC do MFC ](../../mfc/reference/adding-an-mfc-odbc-consumer.md)) dar suporte a RFX e como você pode modificar o código do Assistente de gravação.  
  
-   [Registrar troca de campos: Usando as funções RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md) explica chamadas de gravação para as funções RFX em seu `DoFieldExchange` substituir.  
  
 A tabela a seguir mostra a função em relação a estrutura que se faz para você.  
  
### <a name="using-rfx-you-and-the-framework"></a>Usando RFX: Você e o Framework  
  
|Você|A estrutura|  
|---------|-------------------|  

| Declare suas classes de conjunto de registros com um assistente. Especifique os nomes e tipos de dados de membros de dados do campo. | O assistente deriva um `CRecordset` classe e gravações um [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) substituir para você, incluindo um RFX chamada para cada membro de dados do campo de função. |  
| (Opcional) Adicione manualmente quaisquer membros de dados de parâmetro necessário para a classe. Adicionar manualmente uma chamada de função RFX para `DoFieldExchange` para cada membro de dados de parâmetro, adicione uma chamada para [CFieldExchange::SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) para o grupo de parâmetros e especifique o número total de parâmetros em [m_nParams ](../../mfc/reference/crecordset-class.md#m_nparams). Consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md). | |  
| (Opcional) Vincule manualmente colunas adicionais para membros de dados do campo. Incrementar manualmente [m_nFields](../../mfc/reference/crecordset-class.md#m_nfields). Consulte [conjunto de registros: associando dinamicamente colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md). | |  

| Construa um objeto da classe do conjunto de registros. Antes de usar o objeto, defina os valores de seu parâmetro membros de dados, se houver. | Para eficiência, o framework prebinds os parâmetros, usando o ODBC. Quando você passa valores de parâmetro, o framework passa para a fonte de dados. Somente os valores de parâmetro são enviados para requeries, a menos que as cadeias de caracteres de classificação e/ou filtro foram alterados. |  
| Abra um objeto de conjunto de registros usando [CRecordset::Open](../../mfc/reference/crecordset-class.md#open). | Executa a consulta do conjunto de registros, associa colunas a membros de dados do campo do conjunto de registros e chamadas `DoFieldExchange` para trocar dados entre o primeiro registro selecionado e membros de dados de campo do conjunto de registros. |  
| Role o conjunto de registros usando [CRecordset::Move](../../mfc/reference/crecordset-class.md#move) ou um comando de menu ou barra de ferramentas. | Chamadas `DoFieldExchange` para transferir dados para os membros de dados do campo do novo registro atual. |  
| Adicionar, atualizar e excluir registros. | Chamadas `DoFieldExchange` para transferir dados para a fonte de dados. |  
  
## <a name="see-also"></a>Consulte também  
 [Registrar troca de campos (RFX)](../../data/odbc/record-field-exchange-rfx.md)   
 [Troca de campos de registro: Como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)   
 [Conjunto de registros: Obtendo SUMs e outros resultados agregados (ODBC)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)   
 [Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)   
 [Macros, funções globais e variáveis globais](../../mfc/reference/mfc-macros-and-globals.md)


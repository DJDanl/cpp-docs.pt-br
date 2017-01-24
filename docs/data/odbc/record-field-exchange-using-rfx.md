---
title: "Registrar troca de campos: usando RFX | Microsoft Docs"
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
  - "RFX (ODBC), implementando"
ms.assetid: ada8f043-37e6-4d41-9db3-92c997a61957
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registrar troca de campos: usando RFX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica o que você usa para usar RFX com relação ao qual a estrutura faz.  
  
> [!NOTE]
>  Este tópico se aplicam às classes derivadas de [CRecordset](../Topic/CRecordset%20Class.md) no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, a troca do campo de registro em massa \(RFX em massa\) é implementada.  RFX em massa é semelhante a RFX.  Para entender as diferenças, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Os tópicos a seguir contêm informações relacionadas:  
  
-   [Exchange campo do registro: Trabalhando com o código do assistente](../../data/odbc/record-field-exchange-working-with-the-wizard-code.md) apresenta os componentes principais de RFX e explica o código que o assistente e **Adicionar Classe** do aplicativo MFC \(conforme descrito em [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)\) gravação para dar suporte a RFX e como você pode alterar o código do assistente.  
  
-   explica[Exchange campo do registro: Usando as funções de RFX](../../data/odbc/record-field-exchange-using-the-rfx-functions.md) chamadas de gravação às funções de RFX na substituição de `DoFieldExchange` .  
  
 A tabela a seguir mostra a função com relação ao qual a estrutura faz para você.  
  
### Usando RFX: Você e a estrutura  
  
|Você|A estrutura|  
|----------|-----------------|  
|Declare suas classes do conjunto de registros com um assistente.  Especificar nomes e tipos de dados de membros de dados do campo.|O assistente deve derivar uma classe de `CRecordset` e grava uma substituição de [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) para você, incluindo uma chamada de função de RFX para cada membro de dados do campo.|  
|\(Opcional\) Adicionar manualmente todos os membros de dados necessários do parâmetro à classe.  Adicionar manualmente uma chamada de função de RFX a `DoFieldExchange` para cada membro de dados do parâmetro, adicione uma chamada a [CFieldExchange::SetFieldType](../Topic/CFieldExchange::SetFieldType.md) para o grupo de parâmetros, e especifique o número total de parâmetros em [m\_nParams](../Topic/CRecordset::m_nParams.md).  Consulte [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).||  
|\(Opcional\) Associar colunas adicionais manualmente os membros de dados do campo.  Manualmente incremento [m\_nFields](../Topic/CRecordset::m_nFields.md).  Consulte [Conjunto de registros: Colunas de dados dinamicamente associação \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).||  
|Construir um objeto da sua classe do conjunto de registros.  Antes de usar o objeto, defina os valores dos membros de dados do parâmetro, se houver.|Para eficiência, os prebinds estrutura dos parâmetros, usando o ODBC.  Quando você passa valores de parâmetro, a estrutura passar à fonte de dados.  Somente os valores de parâmetro são enviados para repete, a menos que o tipo e\/ou as cadeias de caracteres de filtro são alterados.|  
|Abra um objeto do conjunto de registros usando [CRecordset::Open](../Topic/CRecordset::Open.md).|Executa a consulta do conjunto de registros, associa colunas aos membros de dados do campo do conjunto de registros, e chama `DoFieldExchange` para trocar dados entre o primeiro registro selecionado e os membros de dados do campo do conjunto de registros.|  
|Rolagem no conjunto de registros usando [CRecordset::Move](../Topic/CRecordset::Move.md) ou um menu ou um comando da barra de ferramentas.|Chama `DoFieldExchange` para transferir dados aos membros de dados do campo do novo registro atual.|  
|Adicionar, atualizar e excluir registros.|Chama `DoFieldExchange` para transferir dados à fonte de dados.|  
  
## Consulte também  
 [Registrar troca de campos \(RFX\)](../../data/odbc/record-field-exchange-rfx.md)   
 [Registrar troca de campos: como funciona RFX](../../data/odbc/record-field-exchange-how-rfx-works.md)   
 [Conjunto de registros: obtendo SUMs e outros resultados agregados \(ODBC\)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)   
 [Classe de CFieldExchange](../../mfc/reference/cfieldexchange-class.md)   
 [Macros, funções globais e variáveis globais](../Topic/Macros,%20Global%20Functions,%20and%20Global%20Variables.md)
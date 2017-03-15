---
title: "Conjunto de registros (ODBC) | Microsoft Docs"
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
  - "conjuntos de registros dinâmicos"
  - "dynasets"
  - "conjuntos de registros somente encaminhamento"
  - "conjunto de registros ODBC"
  - "conjunto de registros ODBC, Objetos CRecordset"
  - "conjuntos de registros, sobre conjuntos de registros"
  - "conjuntos de registros, criando"
  - "conjuntos de registros, dynasets"
  - "conjuntos de registros, instantâneos"
  - "instantâneos, conjunto de registros ODBC"
ms.assetid: 333337c5-575e-4d26-b5f6-47166ad7874d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Um objeto de [CRecordset](../Topic/CRecordset%20Class.md) representa um conjunto de registros selecionados de uma fonte de dados.  Os registros podem ser de:  
  
-   Uma tabela.  
  
-   Uma consulta.  
  
-   Um procedimento armazenado que acessa uma ou mais tabelas.  
  
 Um exemplo de um conjunto de registros com base em uma tabela é “todos os clientes”, que acessa uma tabela de cliente.  Um exemplo de uma consulta é “todas as faturas para Joe Smith”. Um exemplo de um conjunto de registros com base em um procedimento armazenado \(às vezes chamado de uma consulta predefinida\) é “todas as contas de delinquente”, que chamar um procedimento armazenado no base de dados back\-end.  Um conjunto de registros pode adicionar duas ou mais tabelas da mesma fonte de dados, mas não tabelas de diferentes fontes de dados.  
  
> [!NOTE]
>  Para obter informações sobre a derivação o conjunto de registros com classifica os assistentes, consulte [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) e [Suporte de base de dados do aplicativo, o assistente MFC](../../mfc/reference/database-support-mfc-application-wizard.md).  
  
> [!NOTE]
>  Exibições de suporte de alguns drivers ODBC da base de dados.  Uma exibição é nesse sentido uma consulta criada originalmente com a instrução SQL `CREATE VIEW` .  Os assistentes atualmente eles não dão suporte a exibições, mas é possível codificar esse suporte você mesmo.  
  
##  <a name="_core_recordset_capabilities"></a> Recursos do conjunto de registros  
 Todos os objetos do conjunto de registros compartilham os seguintes recursos:  
  
-   Se a fonte de dados não é somente leitura, você pode especificar que o conjunto de registros é [atualizável](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md), [appendable](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md), ou somente leitura.  Se o conjunto de registros é atualizável, você pode escolher métodos pessimistas ou otimistas de [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) , desde que o driver fornece suporte apropriado de bloqueio.  Se a fonte de dados for somente leitura, o conjunto de registros será somente leitura.  
  
-   Você pode chamar funções de membro a [rolagem](../Topic/Recordset:%20Scrolling%20\(ODBC\).md) por meio de registros selecionados.  
  
-   Você pode [filtro](../../data/odbc/recordset-filtering-records-odbc.md) os registros restringir\-se a qual os registros são selecionados disponível.  
  
-   Você pode [tipo](../../data/odbc/recordset-sorting-records-odbc.md) os registros em ordem crescente ou decrescente, com base em uma ou mais colunas.  
  
-   Você pode [parametrizar](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) o conjunto de registros qualificar a seleção do conjunto de registros em tempo de execução.  
  
##  <a name="_core_snapshots_and_dynasets"></a> Instantâneos e Dynasets  
 Há dois tipos principais conjuntos de registros: [instantâneos](../Topic/Snapshot.md) e [dynasets](../../data/odbc/dynaset.md).  Ambos são suportados pela classe `CRecordset`.  Cada compartilha as características comum de todos os conjuntos de registros, mas cada também estende a funcionalidade comum em sua própria forma especializada.  Os instantâneos fornecem uma exibição estática dos dados e são úteis para os relatórios e as outras situações em que você deseja uma exibição dos dados conforme existiam em um determinado momento.  Dynasets é útil quando você deseja que as atualizações feitas por outros usuários seja visível no conjunto de registros sem ter que você consulte novamente ou para atualizar o conjunto de registros.  Os instantâneos e os dynasets podem ser atualizada ou somente leitura.  Para refletir registros adicionou ou excluídas por outros usuários, chame [CRecordset::Requery](../Topic/CRecordset::Requery.md).  
  
 `CRecordset` também permite que os outros dois tipos de conjuntos de registros: conjuntos de registros dinâmicos e conjuntos de registros de somente avanço.  Os conjuntos de registros dinâmicos são semelhantes a dynasets; no entanto, os conjuntos de registros dinâmicos refletem todos os registros adicionados ou excluídos sem chamar `CRecordset::Requery`.  Por esse motivo, os conjuntos de registros dinâmicos são geralmente caros em relação à hora de processamento no DBMS, e muitos drivers ODBC não oferecem suporte a.  Ao contrário, os conjuntos de registros de somente avanço fornecem o método mais eficaz de acesso a dados para os conjuntos de registros que não requerem atualizações ou de rolagem para trás.  Por exemplo, você pode usar um conjunto de registros somente avanço para migrar dados de uma fonte de dados para outra, onde você só precisa mover com os dados em direção para frente.  Para usar um conjunto de registros somente avanço, você deve fazer o seguinte:  
  
-   Passar a opção **CRecordset::forwardOnly** como o parâmetro de `nOpenType` da função de membro de [Abrir](../Topic/CRecordset::Open.md) .  
  
-   Especifique **CRecordset::readOnly** no parâmetro de `dwOptions` de **Abrir**.  
  
    > [!NOTE]
    >  Para obter informações sobre os requisitos de driver ODBC para suporte ao dynaset, consulte [ODBC](../../data/odbc/odbc-basics.md).  Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C\+\+ e para obter informações sobre como obter drivers adicionais, consulte [Lista de driver ODBC](../../data/odbc/odbc-driver-list.md).  
  
##  <a name="_core_your_recordsets"></a> Os conjuntos de registros  
 Para cada tabela distinta, a exibição, ou o procedimento armazenado que deseja acessar, você definirá normalmente uma classe derivada de `CRecordset`. \(A exceção é uma junção do base de dados, na qual o conjunto de registros representa colunas de duas ou mais tabelas.\) Quando você deve derivar uma classe do conjunto de registros, você permite que o mecanismo de troca do campo de registro \(RFX\) ou o mecanismo em massa de troca do campo de registro \(RFX em massa\), que são semelhantes ao mecanismo de troca de dados da caixa de diálogo \(DDX\).  RFX e o volume RFX simplificam a transferência de dados da fonte de dados no conjunto de registros; Além disso RFX transfere dados do conjunto de registros na fonte de dados.  Para obter mais informações, consulte [Exchange campo de registro \(RFX\)](../../data/odbc/record-field-exchange-rfx.md) e [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Um objeto do conjunto de registros fornece acesso a todos os registros selecionados.  O rolar por meio de registros selecionados usando várias funções de membro de `CRecordset` , como `MoveNext` e `MovePrev`.  Ao mesmo tempo, um objeto do conjunto de registros representa apenas um dos registros selecionados, o registro atual.  Você pode examinar os campos do registro atual declarando variáveis do membro da classe do conjunto de registros que correspondem às colunas da tabela ou dos registros que resultam de consulta da base de dados.  Para obter informações sobre membros de dados do conjunto de registros, consulte [Conjunto de registros: Arquitetura \(ODBC\)](../../data/odbc/recordset-architecture-odbc.md).  
  
 Os tópicos a seguir explicam os detalhes de usar objetos do conjunto de registros.  Os tópicos são listados em categorias funcionais e um natural na ordem sequencial a permitir leitura.  
  
### Tópicos sobre os mecanismos de abertura, de leitura, e fechar conjuntos de registros  
  
-   [Conjunto de registros: Arquitetura \(ODBC\)](../../data/odbc/recordset-architecture-odbc.md)  
  
-   [Conjunto de registros: Declarando uma classe para uma tabela \(ODBC\)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md)  
  
-   [Conjunto de registros: Criando e fechando conjuntos de registros \(ODBC\)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md)  
  
-   [Conjunto de registros: Navegação \(ODBC\)](../Topic/Recordset:%20Scrolling%20\(ODBC\).md)  
  
-   [Conjunto de registros: Indicadores e posições absolutas \(ODBC\)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md)  
  
-   [Conjunto de registros: Filtrando registros \(ODBC\)](../../data/odbc/recordset-filtering-records-odbc.md)  
  
-   [Conjunto de registros: Classificando registros \(ODBC\)](../../data/odbc/recordset-sorting-records-odbc.md)  
  
-   [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)  
  
### Tópicos sobre os mecanismos de conjuntos de registros de alteração  
  
-   [Conjunto de registros: Adicionando, atualizando e excluindo registros \(ODBC\)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)  
  
-   [Conjunto de registros: Bloqueando registros \(ODBC\)](../../data/odbc/recordset-locking-records-odbc.md)  
  
-   [Conjunto de registros: Consultar um conjunto de registros \(ODBC\)](../../data/odbc/recordset-requerying-a-recordset-odbc.md)  
  
### Tópicos sobre técnicas um pouco mais avançados  
  
-   [Conjunto de registros: Ao executar uma junção \(ODBC\)](../Topic/Recordset:%20Performing%20a%20Join%20\(ODBC\).md)  
  
-   [Conjunto de registros: Declarando uma classe para uma consulta predefinido \(ODBC\)](../../data/odbc/recordset-declaring-a-class-for-a-predefined-query-odbc.md)  
  
-   [Conjunto de registros: Colunas de dados dinamicamente associação \(ODBC\)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md)  
  
-   [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md)  
  
-   [Conjunto de registros: Trabalhar com grandes itens de dados \(ODBC\)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)  
  
-   [Conjunto de registros: Obtendo somas e outro a agregação resultados \(ODBC\)](../../data/odbc/recordset-obtaining-sums-and-other-aggregate-results-odbc.md)  
  
### Os tópicos sobre como os conjuntos de registros funcionam  
  
-   [Conjunto de registros: Como os conjuntos de registros selecione os registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md)  
  
-   [Conjunto de registros: Como registros de atualização dos conjuntos de registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)   
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Transação \(ODBC\)](../../data/odbc/transaction-odbc.md)
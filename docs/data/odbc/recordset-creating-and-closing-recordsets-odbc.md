---
title: 'Conjunto de registros: Criando e fechando conjuntos de registros (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ODBC recordsets, creating
- recordsets, creating
- recordsets, opening
- recordsets, closing
- ODBC recordsets, closing
- ODBC recordsets, opening
ms.assetid: 8d2aac23-4396-4ce2-8c60-5ecf1b360d3d
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1dc9183d9007703de7025d77d5dcaf22d9860850
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="recordset-creating-and-closing-recordsets-odbc"></a>Conjunto de registros: criando e fechando conjuntos de registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Para usar um conjunto de registros, construir um objeto recordset e, em seguida, chamar seu **abrir** função de membro para executar a consulta do conjunto de registros e selecionar registros. Quando você concluir o conjunto de registros, feche e destruir o objeto.  
  
 Este tópico explica:  
  
-   [Quando e como criar um objeto recordset](#_core_creating_recordsets_at_run_time).  
  
-   [Quando e como você pode qualificar o comportamento do conjunto de registros por parametrização, filtragem, classificação ou bloqueá-la](#_core_setting_recordset_options).  
  
-   [Quando e como fechar um objeto de conjunto de registros](#_core_closing_a_recordset).  
  
##  <a name="_core_creating_recordsets_at_run_time"></a>Criando conjuntos de registros em tempo de execução  
 Antes de criar objetos de conjunto de registros em seu programa, você normalmente escrever classes de conjunto de registros específicos do aplicativo. Para obter mais informações sobre esta etapa preliminar, consulte [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).  
  
 Abra um objeto dynaset ou instantâneo quando você precisa selecionar os registros de uma fonte de dados. O tipo de objeto para criar depende do que você precisa fazer com os dados em seu aplicativo e em que o driver ODBC oferece suporte. Para obter mais informações, consulte [Dynaset](../../data/odbc/dynaset.md) e [instantâneo](../../data/odbc/snapshot.md).  
  
#### <a name="to-open-a-recordset"></a>Para abrir um conjunto de registros  
  
1.  Construir um objeto de seu `CRecordset`-classe derivada.  
  
     Você pode construir o objeto no heap ou no quadro de pilha de uma função.  
  
2.  Se desejar modificar o comportamento de conjunto de registros do padrão. Para as opções disponíveis, consulte [definindo opções de conjunto de registros](#_core_setting_recordset_options).  
  
3.  Chamar o objeto [abrir](../../mfc/reference/crecordset-class.md#open) função de membro.  
  
 No construtor, passe um ponteiro para um `CDatabase` do objeto ou passe **nulo** para usar um temporário o objeto de banco de dados que o framework cria e abre com base na cadeia de conexão retornada pelo [GetDefaultConnect ](../../mfc/reference/crecordset-class.md#getdefaultconnect) função de membro. O `CDatabase` objeto já pode estar conectado a uma fonte de dados.  
  
 A chamada para **abrir** usa SQL para selecionar registros da fonte de dados. O primeiro registro selecionado (se houver) é o registro atual. Os valores dos campos deste registro são armazenados em membros de dados de campo do conjunto de registros do objeto. Se os registros foram selecionados, tanto o `IsBOF` e `IsEOF` funções de membro retornam 0.  
  
 No seu [abrir](../../mfc/reference/crecordset-class.md#open) chamada, você pode:  
  
-   Especifique se o conjunto de registros é um dynaset ou instantâneo. Abra o conjunto de registros como instantâneos por padrão. Ou, você pode especificar um recordset somente de encaminhamento, que permite que apenas a roll-forward, um registro de cada vez.  
  
     Por padrão, um conjunto de registros usa o tipo padrão armazenado no `CRecordset` membro de dados **m_nDefaultType**. Assistentes de escrever código para inicializar **m_nDefaultType** para o tipo de conjunto de registros escolhido no assistente. Em vez de aceitar esse padrão, você pode substituir o outro tipo de conjunto de registros.  
  
-   Especifique uma cadeia de caracteres para substituir o padrão SQL **selecione** instrução constrói o conjunto de registros.  
  
-   Especifique se o conjunto de registros é somente leitura ou somente de acréscimo. Conjuntos de registros permitem completos de atualização por padrão, mas você pode limitar que para adicionar novos registros somente ou você pode desabilitar todas as atualizações.  
  
 O exemplo a seguir mostra como abrir um objeto de instantâneo somente leitura da classe `CStudentSet`, uma classe específica de aplicativo:  
  
```  
// Construct the snapshot object  
CStudentSet rsStudent( NULL );  
// Set options if desired, then open the recordset  
if(!rsStudent.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))  
    return FALSE;  
// Use the snapshot to operate on its records...  
```  
  
 Depois de chamar **abrir**, use os membros de funções e os dados de membro do objeto para trabalhar com os registros. Em alguns casos, você talvez queira Repetir ou atualizar o conjunto de registros para incluir as alterações que ocorreram na fonte de dados. Para obter mais informações, consulte [conjunto de registros: repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md).  
  
> [!TIP]
>  A cadeia de conexão, que você pode usar durante o desenvolvimento pode não ser a mesma cadeia de conexão que os usuários eventual precisam. Para obter ideias sobre generalizar seu aplicativo em relação a isso, consulte [fonte de dados: Gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md).  
  
##  <a name="_core_setting_recordset_options"></a>Definindo opções de conjunto de registros  
 Depois de construir o objeto de conjunto de registros, mas antes de chamar **abrir** para selecionar registros, talvez você queira definir algumas opções para controlar o comportamento do conjunto de registros. Para todos os conjuntos de registros, você pode:  
  
-   Especifique um [filtro](../../data/odbc/recordset-filtering-records-odbc.md) para restringir a seleção de registros.  
  
-   Especifique um [classificação](../../data/odbc/recordset-sorting-records-odbc.md) para que os registros.  
  
-   Especifique [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) para que você possa selecionar registros usando informações obtidas ou calculados em tempo de execução.  
  
 Você também pode definir a opção a seguir se as condições forem atendidas:  
  
-   Se o conjunto de registros é atualizável e dá suporte às opções de bloqueio, especifique o [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) método usado para atualizações.  
  
> [!NOTE]
>  Para afetar a seleção de registro, você deve definir essas opções antes de chamar o **abrir** função de membro.  
  
##  <a name="_core_closing_a_recordset"></a>Fechar um conjunto de registros  
 Quando você concluir o conjunto de registros, você deve utilizadas e desalocar sua memória.  
  
#### <a name="to-close-a-recordset"></a>Para fechar um conjunto de registros  
  
1.  Chamar o [fechar](../../mfc/reference/crecordset-class.md#close) função de membro.  
  
2.  Destrua o objeto de conjunto de registros.  
  
     Se você declarado no quadro de pilha de uma função, o objeto é destruído automaticamente quando o objeto sai do escopo. Caso contrário, use o **excluir** operador.  
  
 **Fechar** libera o conjunto de registros **HSTMT** tratar. Ele não destruir o objeto de C++.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)
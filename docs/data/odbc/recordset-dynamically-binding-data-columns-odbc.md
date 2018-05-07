---
title: 'Conjunto de registros: Associando dinamicamente colunas de dados (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC recordsets [C++], binding columns dynamically
- data binding [C++], recordset columns
- recordsets [C++], binding data
- data binding [C++], columns in recordsets
- columns [C++], binding to recordsets
ms.assetid: bff67254-d953-4ae4-9716-91c348cb840b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9fe71707de20ba02228039e5693cab9c9401d560
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="recordset-dynamically-binding-data-columns-odbc"></a>Conjunto de registros: associando dinamicamente colunas de dados (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Conjuntos de registros gerenciar colunas de tabela de associação que você especificou em tempo de design, mas há casos em que talvez você queira associar colunas que eram desconhecidas para você em tempo de design. Este tópico explica:  
  
-   [Quando você quiser associar colunas dinamicamente a um conjunto de registros](#_core_when_you_might_bind_columns_dynamically).  
  
-   [Como associar colunas dinamicamente em tempo de execução](#_core_how_to_bind_columns_dynamically).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa busca não foi implementada. As técnicas descritas geralmente não são recomendadas se você estiver usando a busca de linhas em massa. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_when_you_might_bind_columns_dynamically"></a> Quando você pode associar colunas dinamicamente  
 Em tempo de design, o Assistente de aplicativo do MFC ou [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) (de **Adicionar classe**) cria classes de conjunto de registros com base em tabelas conhecidas e colunas em sua fonte de dados. Bancos de dados podem ser alteradas entre quando você projeta-los e posteriormente, quando seu aplicativo usa essas tabelas e colunas em tempo de execução. Você ou outro usuário pode adicionar ou descartar uma tabela ou adicionar ou remover colunas em uma tabela que depende do conjunto de registros do aplicativo. Isso provavelmente não é uma preocupação para todos os aplicativos de acesso a dados, mas se ele estiver na sua, como pode você lidar com as alterações no esquema de banco de dados diferente da reprojetar e recompilar? O objetivo deste tópico é responder essa pergunta.  
  
 Este tópico descreve o caso mais comum em que você pode associar colunas dinamicamente — ter começado com um conjunto de registros com base em um esquema de banco de dados conhecido, que você deseja manipular colunas adicionais em tempo de execução. Ainda mais o tópico supõe que as colunas adicionais mapearem para `CString` campo membros de dados, o caso mais comum, embora as sugestões são fornecidas para ajudá-lo a gerenciar outros tipos de dados.  
  
 Com uma pequena quantidade de código extra, você pode:  
  
-   [Determinar quais colunas estão disponíveis em tempo de execução](#_core_how_to_bind_columns_dynamically).  
  
-   [Associar colunas adicionais para o conjunto de registros dinamicamente em tempo de execução](#_core_adding_the_columns).  
  
 O conjunto de registros contém membros de dados para as colunas que soubessem em tempo de design. Ele também contém uma pequena quantidade de código adicional que determina dinamicamente se novas colunas foram adicionadas à sua tabela de destino e, nesse caso, associa as novas colunas ao armazenamento alocado dinamicamente (em vez de membros de dados do conjunto de registros).  
  
 Este tópico não aborda outros casos de associação dinâmica, como colunas ou tabelas removidas. Para esses casos, você precisa usar chamadas de API de ODBC mais diretamente. Para obter informações, consulte o SDK do ODBC *referência do programador de* no CD de biblioteca do MSDN.  
  
##  <a name="_core_how_to_bind_columns_dynamically"></a> Como associar colunas dinamicamente  
 Para associar colunas dinamicamente, você deve saber (ou ser capaz de determinar) os nomes das colunas adicionais. Você também deve alocar armazenamento para os membros de dados do campo adicional, especifique seus nomes e seus tipos e especifique o número de colunas que você está adicionando.  
  
 A discussão a seguir apresenta dois conjuntos de registros diferentes. A primeira é o conjunto principal que seleciona os registros da tabela de destino. O segundo é um conjunto de registros de coluna especial usado para obter informações sobre as colunas em sua tabela de destino.  
  
###  <a name="_core_the_general_process"></a> Processo geral  
 Nível mais geral, em que você siga estas etapas:  
  
1.  Construa seu objeto recordset principal.  
  
     Opcionalmente, passe um ponteiro para um abrir `CDatabase` de objeto ou ser capaz de fornecer informações de conexão para o conjunto de registros de coluna de outra forma.  
  
2.  Etapas para adicionar colunas dinamicamente.  
  
     Consulte o processo descrito em adicionando as colunas a seguir.  
  
3.  Abra o conjunto de registros principal.  
  
     O conjunto de registros seleciona registros e usa a troca de campos de registro (RFX) para associar as colunas estáticas (aquelas que são mapeados para membros de dados de campo do conjunto de registros) e colunas dinâmicas (mapeadas para o armazenamento extra que você alocar).  
  
###  <a name="_core_adding_the_columns"></a> Adicionando colunas  
 Associando dinamicamente adicionadas colunas em tempo de execução exige as seguintes etapas:  
  
1.  Em tempo de execução, determine quais colunas são na tabela de destino. Extrai essas informações uma lista das colunas que foram adicionados à tabela como a classe de conjunto de registros foi projetada.  
  
     Uma boa abordagem é usar uma classe de conjunto de registros de coluna usada para consultar a fonte de dados para obter informações de coluna para a tabela de destino (como o tipo de dados e o nome da coluna).  
  
2.  Fornece armazenamento para os novos membros de dados do campo. Como a classe principal do conjunto de registros não têm membros de dados de campo para colunas desconhecidos, você deve fornecer um local para armazenar os nomes, valores de resultado e possivelmente informações de tipo de dados (se as colunas de diferentes tipos de dados).  
  
     Uma abordagem é criar uma ou mais listas dinâmicas, um para os nomes das colunas novas, outro para seus valores de resultado e um terceiro para seus tipos de dados (se necessário). Essas listas, especialmente a lista de valores, fornecem as informações e o armazenamento necessário para a associação. A figura a seguir ilustra a criação de listas.  
     ![Criando listas de colunas para associar dinamicamente](../../data/odbc/media/vc37w61.gif "vc37w61")  
Criando listas de colunas de associação dinamicamente  
  
3.  Adicionar uma chamada de função RFX em seu conjunto de registros principal `DoFieldExchange` função para cada coluna de adicionado. Essas chamadas RFX fazem o trabalho de busca de um registro, incluindo as colunas adicionais e as colunas de associação para membros de dados do conjunto de registros ou para seu armazenamento dinamicamente fornecido para eles.  
  
     Uma abordagem é adicionar um loop para seu conjunto de registros principal `DoFieldExchange` função percorre a lista de novas colunas, chamando a função RFX apropriada para cada coluna na lista. Em cada chamada RFX, transmitir um nome de coluna da lista de nomes de coluna e um local de armazenamento no membro correspondente da lista de valores de resultado.  
  
###  <a name="_core_lists_of_columns"></a> Lista de colunas  
 As quatro listas que você precisa para trabalhar com são mostradas na tabela a seguir.  
  
 **Atual--colunas de tabela (lista de 1 na ilustração)** uma lista das colunas atualmente na tabela na fonte de dados. Essa lista pode corresponder a lista de colunas associado no momento em seu conjunto de registros.  
  
 **Registros-colunas associadas (lista de 2 na ilustração)**  
 Uma lista de colunas associada em seu conjunto de registros. Essas colunas já tem instruções RFX em seu `DoFieldExchange` função.  
  
 **Colunas-para-Bind-dinamicamente (lista 3 na ilustração)**  
 Uma lista de colunas na tabela, mas não no seu conjunto de registros. Essas são as colunas que você deseja vincular dinamicamente.  
  
 **Dinâmico-coluna-valores (lista 4 na ilustração)**  
 Uma lista que contém o armazenamento para os valores recuperados de colunas que você vincular dinamicamente. Elementos dessa lista correspondem às colunas-para-Bind-dinamicamente, um para um.  
  
###  <a name="_core_building_your_lists"></a> Criando listas  
 Uma estratégia geral em mente, você pode ativar os detalhes. Os procedimentos no restante deste tópico mostram como criar as listas mostradas na [lista de colunas](#_core_lists_of_columns). Os procedimentos guiá-lo por meio de:  
  
-   [Determinando os nomes das colunas do conjunto de registros não](#_core_determining_which_table_columns_are_not_in_your_recordset).  
  
-   [Fornecer armazenamento dinâmico para colunas recentemente adicionadas à tabela](#_core_providing_storage_for_the_new_columns).  
  
-   [Adicionar dinamicamente RFX chama para novas colunas](#_core_adding_rfx_calls_to_bind_the_columns).  
  
###  <a name="_core_determining_which_table_columns_are_not_in_your_recordset"></a> Determinando o que são colunas de tabela não está em seu conjunto de registros  
 Crie uma lista (limite--colunas do conjunto, como em lista 2 na ilustração) que contém uma lista das colunas que já está associado no seu conjunto de registros principal. Em seguida, crie uma lista (colunas-para-Bind-dinamicamente, derivada de colunas da tabela atual e o limite de conjunto de registros de colunas) que contém nomes de coluna na tabela na fonte de dados, mas não no seu conjunto de registros principal.  
  
##### <a name="to-determine-the-names-of-columns-not-in-the-recordset-columns-to-bind-dynamically"></a>Para determinar os nomes das colunas não no conjunto de registros (colunas-para-Bind-dinamicamente)  
  
1.  Crie uma lista (colunas de conjunto de registros associado) das colunas já associado em seu conjunto de registros principal.  
  
     Uma abordagem é criar colunas de conjunto de registros de associadas no tempo de design. Visualmente, você pode examinar as chamadas de função RFX no conjunto de registros `DoFieldExchange` função para obter esses nomes. Em seguida, defina sua lista como uma matriz inicializada com os nomes.  
  
     Por exemplo, a ilustração mostra colunas associadas a-registros-(lista 2) com três elementos. Colunas de conjunto de registros associado está ausente na coluna de telefone mostrada em atual--colunas de tabela (lista de 1).  
  
2.  Compare colunas da tabela atual e colunas do conjunto de limite para criar uma lista (colunas-para-Bind-dinamicamente) das colunas que não esteja associado em seu conjunto de registros principal.  
  
     É uma abordagem percorrer a lista de colunas na tabela em tempo de execução (colunas de tabela atual) e a lista de colunas já associado em seu conjunto de registros (colunas de conjunto de registros associado) em paralelo. Em colunas-para-Bind-dinamicamente colocar todos os nomes em atual--colunas de tabela que não aparecem em colunas do conjunto de limite.  
  
     Por exemplo, a ilustração mostra colunas-para-Bind-dinamicamente (lista 3) com um elemento: a coluna Phone encontrada no atual--colunas de tabela (lista de 1), mas não em colunas associadas a-registros-(lista 2).  
  
3.  Crie uma lista dinâmica--de valores de coluna (como lista 4 na ilustração) no qual armazenar os valores de dados correspondentes a cada nome de coluna armazenado na lista de colunas para associar dinamicamente (colunas-para-Bind-dinamicamente).  
  
     Os elementos desta lista desempenham a função de conjunto de registros novos membros de dados do campo. Eles são os locais de armazenamento ao qual estão associadas as colunas dinâmicas. Para obter descrições das listas, consulte [lista de colunas](#_core_lists_of_columns).  
  
###  <a name="_core_providing_storage_for_the_new_columns"></a> Fornecer armazenamento para as novas colunas  
 Em seguida, configure locais de armazenamento para as colunas a ser vinculada dinamicamente. A ideia é fornecer um elemento de lista na qual deseja armazenar o valor de cada coluna. Esses locais de armazenamento paralelo as variáveis de membro do conjunto de registros, que armazenam as colunas associadas normalmente.  
  
##### <a name="to-provide-dynamic-storage-for-new-columns-dynamic-column-values"></a>Para fornecer armazenamento dinâmico para novas colunas (valores de coluna dinâmica)  
  
1.  Compilação dinâmica--valores de coluna, paralelos para colunas-para-Bind-dinamicamente, para conter o valor dos dados em cada coluna.  
  
     Por exemplo, a ilustração mostra dinâmico--valores de coluna (4 de lista) com um elemento: um `CString` objeto que contém o número de telefone real para o registro atual: "555-1212".  
  
     No caso mais comum, valores de coluna dinâmica tem elementos do tipo `CString`. Se você estiver lidando com colunas de diferentes tipos de dados, você precisa de uma lista que pode conter elementos de uma variedade de tipos.  
  
 O resultado dos procedimentos anteriores é duas listas principais: colunas-para-Bind-dinamicamente que contém os nomes de colunas e dinâmico--valores de coluna que contém os valores nas colunas para o registro atual.  
  
> [!TIP]
>  Se as novas colunas não são todas do mesmo tipo de dados, talvez seja um paralelo extra lista que contém itens que alguma forma definem o tipo de cada elemento correspondente na lista de colunas. (Você pode usar os valores **AFX_RFX_BOOL**, **AFX_RFX_BYTE**, e assim por diante, isso se você deseja. Essas constantes são definidos em AFXDB. H.) Escolha um tipo de lista com base em como você representa os tipos de dados de coluna.  
  
###  <a name="_core_adding_rfx_calls_to_bind_the_columns"></a> Adicionando chamadas RFX para associar as colunas  
 Por fim, organizar para a associação dinâmica ocorra colocando RFX chama as novas colunas em sua `DoFieldExchange` função.  
  
##### <a name="to-dynamically-add-rfx-calls-for-new-columns"></a>Para adicionar dinamicamente RFX chamadas para novas colunas  
  
1.  Em seu conjunto de registros principal `DoFieldExchange` membro de função, adicione o código que percorre a lista de novas colunas (colunas-para-Bind-dinamicamente). Em cada loop, extrai um nome de coluna de colunas-para-Bind-dinamicamente e um valor de resultado para a coluna de valores de coluna dinâmica. Passe esses itens para uma chamada de função RFX apropriado para o tipo de dados da coluna. Para obter descrições das listas, consulte [lista de colunas](#_core_lists_of_columns).  
  
 No caso comum, no seu `RFX_Text` extraídos de chamadas de função `CString` objetos das listas, como as seguintes linhas de código, onde é colunas-para-Bind-dinamicamente um `CStringList` chamado `m_listName` e valores de coluna dinâmica é um `CStringList` chamado `m_listValue`:  
  
```  
RFX_Text( pFX,   
            m_listName.GetNext( posName ),   
            m_listValue.GetNext( posValue ));  
```  
  
 Para obter mais informações sobre funções RFX, consulte [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) no *referência da biblioteca de classe*.  
  
> [!TIP]
>  Se as novas colunas são diferentes tipos de dados, use uma instrução switch em seu loop para chamar a função RFX apropriada para cada tipo.  
  
 Quando o framework chama `DoFieldExchange` durante o **abrir** processo para associar colunas no conjunto de registros, as chamadas RFX para as colunas estáticas associar as colunas. Em seguida, o loop repetidamente chama funções RFX para as colunas dinâmicas.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: trabalhando com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)
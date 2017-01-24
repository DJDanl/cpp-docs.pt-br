---
title: "Conjunto de registros: associando dinamicamente colunas de dados (ODBC) | Microsoft Docs"
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
  - "colunas [C++], associação a conjuntos de registros"
  - "associação de dados [C++], colunas em conjuntos de registros"
  - "associação de dados [C++], colunas de conjuntos de registros"
  - "conjuntos de registros ODBC [C++], associando colunas dinamicamente"
  - "conjunto de registros [C++], associando dados"
ms.assetid: bff67254-d953-4ae4-9716-91c348cb840b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: associando dinamicamente colunas de dados (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Os conjuntos de registros gerenciam as colunas da tabela de associação que você especifica em tempo de design, mas há casos em talvez você queira associar as colunas que eram desconhecidas em tempo de design.  Este tópico explica:  
  
-   [Quando você talvez queira associar colunas dinamicamente a um conjunto de registros](#_core_when_you_might_bind_columns_dynamically).  
  
-   [Como associar dinamicamente em tempo de execução colunas](#_core_how_to_bind_columns_dynamically).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  As técnicas descritas geralmente não são recomendadas se você estiver usando à busca em massa de linha.  Para obter mais informações sobre a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
##  <a name="_core_when_you_might_bind_columns_dynamically"></a> Quando você pode associar colunas dinamicamente  
 Em tempo de design, o assistente de aplicativo MFC ou [Assistente do consumidor MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) \(\) de **Adicionar Classe**criam as classes do conjunto de registros com base nas tabelas e colunas conhecidas na fonte de dados.  As bases de dados podem ser alterados entre quando forem criados e posterior quando seu aplicativo usa essas tabelas e colunas em tempo de execução.  Você ou outro usuário podem adicionar ou remover uma tabela ou adicionar ou remover colunas de uma tabela na qual o conjunto de registros de seu aplicativo confiasse.  Isso não é provavelmente um interesse para todos os aplicativos de acesso a dados, mas se é para o vosso, como você pode lidar com as alterações no esquema do base de dados, a não ser pela remodelação e recompile?  A finalidade deste tópico é responder a essa pergunta.  
  
 Este tópico descreve a maioria dos casos comuns nos quais você pode associar colunas dinamicamente — a partir de um conjunto de registros com base em um esquema conhecido da base de dados, você deseja manipular em tempo de execução colunas adicionais.  O tópico adicional presume que o mapa adicional aos membros de dados do campo de `CString` , a maioria dos casos comuns das colunas, embora as sugestões são fornecidas para ajudar a gerenciar outros tipos de dados.  
  
 Com uma quantidade pequena de código adicional, você pode:  
  
-   [Determinar quais colunas estão disponíveis em tempo de execução](#_core_to_determine_the_columns_in_a_table_at_run_time).  
  
-   [Associar colunas adicionais ao conjunto de registros, dinamicamente em tempo de execução](#_core_adding_the_columns).  
  
 O conjunto de registros ainda contém os membros de dados para as colunas que você soubesse aproximadamente em tempo de design.  Também contém uma pequena quantidade de código adicional que determina dinamicamente se qualquer nova coluna esteve adicionada à tabela de destino e, nesse caso, o associará essas colunas novas ao armazenamento atribuído dinamicamente \(em vez dos membros de dados do conjunto de registros\).  
  
 Este tópico não abrange outras caixas de associação dinâmico, como tabelas ou colunas descartadas.  Para esses casos, você precisa usar mais diretamente chamadas de API ODBC.  Para obter mais informações, consulte *a referência do programador* de ODBC SDK no CD da Biblioteca MSDN.  
  
##  <a name="_core_how_to_bind_columns_dynamically"></a> Como associar colunas dinamicamente  
 Para associar colunas dinamicamente, você deve saber \(ou\) para determinar os nomes das colunas adicionais.  Você também deve atribuir o armazenamento para os membros de dados adicionais do campo, especifique os nomes e os tipos, e especifique o número de colunas que você está adicionando.  
  
 A seguinte discussão mencione dois conjuntos de registros diferentes.  O primeiro é o conjunto de registros principal de selecionar registros da tabela de destino.  O segundo é um conjunto de registros especial de coluna usado para obter informações sobre as colunas da tabela de destino.  
  
###  <a name="_core_the_general_process"></a> Processo geral  
 No máximo geral em nível, siga estas etapas:  
  
1.  Construir seu objeto principal do conjunto de registros.  
  
     Opcionalmente, transmitir um ponteiro para um objeto aberto de `CDatabase` ou pode fornecer informações de conexão ao conjunto de registros de coluna em alguma outra forma.  
  
2.  Faça etapas para adicionar dinamicamente colunas.  
  
     Consulte o processo descrito em adicionar as colunas a seguir.  
  
3.  Abra o conjunto de registros principal.  
  
     O conjunto de registros selecionar registros e troca de campo do registro do RFX \(\) para associar as colunas estáticas \(aqueles mapeados para o conjunto de registros colocam os membros de dados\) e as colunas dinâmicas \(mapeadas para o armazenamento adicional que você atribui\).  
  
###  <a name="_core_adding_the_columns"></a> Adicionando colunas  
 Dinamicamente associar colunas unidas em tempo de execução exige as seguintes etapas:  
  
1.  Determine em tempo de execução as colunas que estão na tabela de destino.  Extrair informações de aquela uma lista das colunas que foram adicionadas à tabela desde sua classe do conjunto de registros foi criada.  
  
     Uma boa abordagem é usar uma classe do conjunto de registros da coluna criada para consultar a fonte de dados para informações de coluna para a tabela de destino \(como o nome da coluna e o tipo de dados\).  
  
2.  Fornecer armazenamento para os novos membros de dados do campo.  Porque sua classe principal do conjunto de registros não tem membros de dados do campo para colunas desconhecidas, você deve fornecer um local para armazenar os nomes, os valores de resultado, e possivelmente informações de tipo de dados \(se as colunas forem tipos de dados diferentes\).  
  
     Uma abordagem é criar uma ou várias listas dinâmicos, uma para os novos nomes de colunas, outra para seus valores de resultado, e um terço para seus tipos de dados \(se necessário\).  Estas listas, particularmente a lista de valores, fornecem informações e o armazenamento necessário para a associação.  A figura a seguir ilustra criar as listas.  
  
     ![Criar listas de colunas vincular dinamicamente](../../data/odbc/media/vc37w61.png "vc37W61")  
Criando lista de colunas para associar dinamicamente  
  
3.  Adicionar uma chamada de função de RFX na função de `DoFieldExchange` do conjunto de registros principal para cada coluna adicionada.  Essas chamadas de RFX fazem o trabalho de buscar um registro, de incluir colunas adicionais, e de associar as colunas para os membros de dados do conjunto de registros ou em seu armazenamento dinamicamente fornecido para eles.  
  
     Uma abordagem é adicionar um loop à função de `DoFieldExchange` do conjunto de registros principal que fornece um loop através da lista de colunas novas, chamando a função apropriada de RFX para cada coluna na lista.  Em cada chamada de RFX, passar um nome de coluna na lista de nomes de coluna e um local de armazenamento no membro correspondente da lista de valores de resultado.  
  
###  <a name="_core_lists_of_columns"></a> Listas de colunas  
 As quatro listas que você precisar trabalhar com são mostradas na tabela a seguir.  
  
 [Corrente\-Tabela\- colunas \(1 lista na ilustração\)](#_core_illustration_dynamic)  
 Uma lista das colunas que estão na tabela na fonte de dados.  Esta lista poderá corresponder à lista de colunas associada atualmente no conjunto de registros.  
  
 [Limite\-Conjunto de registros\- colunas \(2 lista na ilustração\)](#_core_illustration_dynamic)  
 Uma lista das colunas limita no conjunto de registros.  Essas colunas já têm instruções de RFX na função de `DoFieldExchange` .  
  
 [Associar a coluna \- Dinâmico \(3 lista na ilustração\)](#_core_illustration_dynamic)  
 Uma lista de colunas na tabela mas não no conjunto de registros.  Essas são as colunas que você quer associar dinamicamente.  
  
 [Dinâmico\-Coluna\- valores \(4 lista na ilustração\)](#_core_illustration_dynamic)  
 Uma lista que contém o armazenamento para os valores recuperados das colunas que você associa dinamicamente.  Os elementos desta lista correspondem aos de coluna associar \- Dinâmico, um a um.  
  
###  <a name="_core_building_your_lists"></a> Criando suas listas  
 Com uma estratégia geral em mente, você pode girar para obter detalhes.  Os procedimentos no restante deste tópico mostram como criar as listas mostradas em [Listas de colunas](#_core_lists_of_columns).  Os procedimentos orientarão por meio do:  
  
-   [Determinar os nomes das colunas não no conjunto de registros](#_core_determining_which_table_columns_are_not_in_your_recordset).  
  
-   [Fornecendo o armazenamento dinâmico para as colunas recém\-adicionado à tabela](#_core_providing_storage_for_the_new_columns).  
  
-   [Dinamicamente adicionando chamadas de RFX para novas colunas](#_core_adding_rfx_calls_to_bind_the_columns).  
  
###  <a name="_core_determining_which_table_columns_are_not_in_your_recordset"></a> Determinando quais colunas da tabela não estão no conjunto de registros  
 Crie uma lista \(Limite\-Conjunto de registros\- colunas, como na lista em [ilustração](#_core_illustration_dynamic)2\) que contém uma lista das colunas já associada ao conjunto de registros principal.  Depois criar uma lista \(coluna associar \- Dinâmico, derivado de Corrente\-Tabela\- colunas de Limite\-Conjunto de registros\- colunas\) que contém os nomes de colunas que estão na tabela na fonte de dados mas não no conjunto de registros principal.  
  
##### Para determinar os nomes das colunas não no conjunto de registros \(coluna associar \- Dinâmico\)  
  
1.  Crie uma lista \(Limite\-Conjunto de registros\- colunas\) das colunas já associada ao conjunto de registros principal.  
  
     Uma abordagem é criar em tempo de design Limite\-Conjunto de registros\- colunas.  Você pode examinar visualmente as chamadas de função de RFX na função de `DoFieldExchange` do conjunto de registros para obter esses nomes.  Em seguida, configure sua lista como uma matriz inicializada com os nomes.  
  
     Por exemplo, [ilustração](#_core_illustration_dynamic) mostra Limite\-Conjunto registros\- lista de colunas \(2\) com três elementos.  As Limite\-Conjunto de registros\- colunas estão faltando a coluna phone mostradas nas colunas Corrente\-Tabela\- lista \(1\).  
  
2.  Compare Corrente\-Tabela\- colunas e Limite\-Conjunto de registros\- colunas para compilar uma lista \(coluna associar \- Dinâmico\) das colunas já não associadas no conjunto de registros principal.  
  
     Uma abordagem é executar um loop em tempo de execução por meio de sua lista de colunas na tabela \(Corrente\-Tabela\- colunas\) e sua lista de colunas já associada ao conjunto de registros \(Limite\-Conjunto de registros\- colunas\) em paralelo.  No coluna associar \- Dinâmico colocado alguns nomes em Corrente\-Tabela\- colunas que não aparecem em Limite\-Conjunto de registros\- colunas.  
  
     Por exemplo, [ilustração](#_core_illustration_dynamic) mostra o associar a coluna \- Dinâmico lista \(3\) com um elemento: a coluna phone localizado em Corrente\-Tabela\- colunas lista \(1\) mas não em Limite\-Conjunto registros\- lista de colunas \(2\).  
  
3.  Criar uma lista de valores Dinâmico\-Coluna\- \(como na lista 4 em [ilustração](#_core_illustration_dynamic)\) no qual armazenar os valores de dados que correspondem a cada nome de coluna armazenados em sua lista de colunas para associar dinamicamente \(coluna associar \- Dinâmico\).  
  
     Os elementos nessa lista está executando a função de novos membros de dados do campo do conjunto de registros.  São locais de armazenamento no qual as colunas dinâmicas associadas.  Para obter descrições das listas, consulte [Listas de colunas](#_core_lists_of_columns).  
  
###  <a name="_core_providing_storage_for_the_new_columns"></a> Fornecendo o armazenamento para as novas colunas  
 Em seguida, locais de armazenamento configurados para que as colunas são associadas dinamicamente.  A exibição é fornecer um elemento da lista na qual o valor de cada coluna.  Esses locais de armazenamento paralelizam as variáveis do membro do conjunto de registros, que geralmente armazenam as colunas associadas.  
  
##### Para fornecer o armazenamento dinâmico para novas colunas \(Dinâmico\-Coluna\- valores\)  
  
1.  Criar Dinâmico\-Coluna\- valores, associar a coluna \- Dinâmico paralelos, para conter o valor dos dados em cada coluna.  
  
     Por exemplo, [ilustração](#_core_illustration_dynamic) mostra Dinâmico\-Coluna\- lista valores \(4\) com um elemento: um objeto de `CString` que contém o número de telefone real do registro atual: “555\-1212”.  
  
     Na maioria dos casos comuns, os Dinâmico\-Coluna\- valores têm elementos de tipo `CString`.  Se você estiver executando as colunas de tipos de dados de negócio, você precisa de uma lista que pode conter elementos de uma variedade de tipos.  
  
 O resultado dos procedimentos anteriores é duas listas: Associar a coluna \- Dinâmico que contém os nomes das colunas e Dinâmico\-Coluna\- valores que contêm os valores nas colunas do registro atual.  
  
> [!TIP]
>  Se as novas colunas não são todas do mesmo tipo de dados, você pode desejar uma lista paralela adicional que contém os itens que definem de alguma forma o tipo de cada elemento correspondente na lista de colunas. \(Você pode usar os valores **AFX\_RFX\_BOOL**, **AFX\_RFX\_BYTE**, e assim por diante, para este se você deseja.  Essas constantes são definidas em AFXDB.H.\) Escolher um tipo de lista com base em como você representa os tipos de dados da coluna.  
  
###  <a name="_core_adding_rfx_calls_to_bind_the_columns"></a> Adicionando chamadas de RFX para associar as colunas  
 Finalmente, organizar para que a associação dinâmico ocorre colocando chamadas de RFX para as novas colunas na função de `DoFieldExchange` .  
  
##### Para adicionar dinamicamente chamadas de RFX para novas colunas  
  
1.  Na função de membro de `DoFieldExchange` do conjunto de registros principal, adicione o código o loop através da lista de colunas novas \(coluna associar \- Dinâmico\).  Em cada loop, extrair um nome de coluna de coluna associar \- Dinâmico e um valor de resultado para a coluna de Dinâmico\-Coluna\- valores.  Passar esses itens a uma chamada de função de RFX apropriado para o tipo de dados da coluna.  Para obter descrições das listas, consulte [Listas de colunas](#_core_lists_of_columns).  
  
 Em casos comuns, nas chamadas de função de `RFX_Text` você extrai objetos de `CString` listas, como nas seguintes linhas de código, onde o associar a coluna \- Dinâmico é `CStringList` chamado `m_listName` e os Dinâmico\-Coluna\- valores são `CStringList` chamado `m_listValue`:  
  
```  
RFX_Text( pFX,   
            m_listName.GetNext( posName ),   
            m_listValue.GetNext( posValue ));  
```  
  
 Para obter mais informações sobre as funções de RFX, consulte [Macros e Globais](../../mfc/reference/mfc-macros-and-globals.md)*na referência da biblioteca da classe*.  
  
> [!TIP]
>  Se as novas colunas são tipos de dados diferentes, use uma instrução switch no loop para chamar a função apropriada de RFX para cada tipo.  
  
 Quando a estrutura chama `DoFieldExchange` durante o processo de **Abrir** para associar as colunas no conjunto de registros, chamadas de RFX para as colunas estáticos associam essas colunas.  No loop chama repetidamente funções de RFX para as colunas dinâmicas.  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: trabalhando com itens de dados grandes \(ODBC\)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)
---
title: 'Conjunto de registros: associar dinamicamente colunas de dados (ODBC)'
ms.date: 05/09/2019
helpviewer_keywords:
- ODBC recordsets [C++], binding columns dynamically
- data binding [C++], recordset columns
- recordsets [C++], binding data
- data binding [C++], columns in recordsets
- columns [C++], binding to recordsets
ms.assetid: bff67254-d953-4ae4-9716-91c348cb840b
ms.openlocfilehash: bde61348bbfb33eef42e36bd75830c23e5b2a5f5
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707942"
---
# <a name="recordset-dynamically-binding-data-columns-odbc"></a>Conjunto de registros: associar dinamicamente colunas de dados (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Os conjuntos de registros gerenciam a associação de colunas de tabela que você especifica em tempo de design, mas há casos em que você convém associar colunas que eram desconhecidas para você em tempo de design. Este tópico explica:

- [Quando talvez convenha associar colunas dinamicamente a um conjunto de registros](#_core_when_you_might_bind_columns_dynamically).

- [Como associar colunas dinamicamente em tempo de execução](#_core_how_to_bind_columns_dynamically).

> [!NOTE]
>  Este tópico aplica-se a objetos derivados de `CRecordset` nos quais o fetch de linha em massa não foi implementado. As técnicas descritas geralmente não são recomendadas se você está usando o fetch de linha em massa. Para saber mais sobre o fetch de linha em massa, confira [Conjunto de registros: como efetuar fetch de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="_core_when_you_might_bind_columns_dynamically"></a> Quando talvez convenha associar colunas dinamicamente

> [!NOTE] 
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Em tempo de execução, o Assistente de Aplicativo MFC ou o [Assistente de Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) (de **Adicionar Classe**) cria classes de conjunto de registros com base nas tabelas e colunas conhecidas em sua fonte de dados. Os bancos de dados podem mudar entre o momento da criação deles e posteriormente, quando seu aplicativo usar essas tabelas e colunas em tempo de execução. Você ou outro usuário pode adicionar ou remover uma tabela ou adicionar ou remover colunas de uma tabela das quais o conjunto de registros do seu aplicativo depende. Isso provavelmente não é uma preocupação para todos os aplicativos de acesso a dados, mas se for para o seu, como você poderá lidar com as alterações no esquema de banco de dados sem recriar e recompilar? A finalidade deste tópico é responder a essa pergunta.

Este tópico descreve o caso mais comum no qual você pode associar colunas dinamicamente – tendo começado com um conjunto de registros baseado em um esquema de banco de dados conhecido, convém manipular as colunas adicionais em tempo de execução. O tópico pressupõe ainda que as colunas adicionais são mapeadas para membros de dados do campo `CString`, o caso mais comum, embora sejam fornecidas sugestões para ajudar você a gerenciar outros tipos de dados.

Com uma pequena quantidade de código extra, é possível:

- [Determinar quais colunas estão disponíveis em tempo de execução](#_core_how_to_bind_columns_dynamically).

- [Associar mais colunas ao seu conjunto de registros dinamicamente, em tempo de execução](#_core_adding_the_columns).

Seu conjunto de registros ainda contém membros de dados para as colunas que você conhecia em tempo de design. Ele também contém uma pequena quantidade de código extra que determina dinamicamente se novas colunas foram adicionadas à sua tabela de destino; em caso afirmativo, associa essas novas colunas ao armazenamento alocado dinamicamente (em vez de aos membros de dados do conjunto de registros).

Este tópico não aborda outros casos de associação dinâmica, como tabelas ou colunas removidas. Para esses casos, é necessário usar chamadas à API ODBC mais diretamente. Para saber mais, confira a *Referência do Programador* do SDK ODBC no CD da Biblioteca MSDN.

##  <a name="_core_how_to_bind_columns_dynamically"></a> Como associar colunas dinamicamente

Para associar colunas dinamicamente, é necessário saber (ou poder determinar) os nomes de mais colunas. Também é necessário alocar armazenamento para mais membros de dados de campo. Especifique seus nomes e seus tipos e o número de colunas que você adicionará.

A discussão a seguir menciona dois conjuntos de registros diferentes. A primeira é o conjunto de registros principal que seleciona registros da tabela de destino. A segunda é um conjunto de registros especial usado para receber informações sobre as colunas em sua tabela de destino.

###  <a name="_core_the_general_process"></a> Processo Geral

No nível mais geral, você segue estas etapas:

1. Construa seu objeto de conjunto de registros principal.

   Opcionalmente, passe um ponteiro para um objeto `CDatabase` aberto ou forneça informações sobre a conexão para o conjunto de registros da coluna de alguma outra maneira.

1. Siga as etapas para adicionar colunas dinamicamente.

   Veja o processo descrito em Como Adicionar as Colunas abaixo.

1. Abra seu conjunto de registros principal.

   O conjunto de registros seleciona registros e usa a RFX (troca de campo de registro) para associar as colunas estáticas (as mapeadas para os membros de dados de campo do conjunto de registros) e as colunas dinâmicas (mapeadas para armazenamento extra que você aloca).

###  <a name="_core_adding_the_columns"></a> Como Adicionar as Colunas

Associar dinamicamente as colunas adicionadas em tempo de execução requer as seguintes etapas:

1. Determinar em tempo de execução quais colunas estão na tabela de destino. Extrair dessas informações uma lista das colunas que foram adicionadas à tabela, uma vez que sua classe de conjunto de registros foi criada.

   Uma boa abordagem é usar uma classe de conjunto de registros de coluna para consultar a fonte de dados quanto às informações da coluna para a tabela de destino (como nome da coluna e tipo de dados).

1. Fornecer armazenamento para os novos membros de dados de campo. Como sua classe de conjunto de registros principal não tem membros de dados de campo para colunas desconhecidas, é necessário fornecer um local para armazenar os nomes, os valores de resultado e, possivelmente, as informações sobre o tipo de dados (se as colunas forem tipos de dados diferentes).

   Uma abordagem é criar uma ou mais listas dinâmicas; uma para os nomes das novas colunas, outra para seus valores de resultado e uma terceira para seus tipos de dados (se necessário). Essas listas, principalmente a lista de valores, fornecem as informações e o armazenamento necessário para a associação. A imagem a seguir ilustra a criação das listas.

   ![Como criar listas de colunas a serem associadas dinamicamente](../../data/odbc/media/vc37w61.gif "Como criar listas de colunas a serem associadas dinamicamente")<br/>
   Como criar listas de colunas para associar dinamicamente

1. Adicione uma chamada de função da RFX na função `DoFieldExchange` do seu conjunto de registros principal para cada coluna adicionada. Essas chamadas RFX fazem o trabalho de execução de fetch de um registro, incluindo as colunas adicionais, e de associação das colunas a membros de dados do conjunto de registros ou ao seu armazenamento fornecido dinamicamente para elas.

   Uma abordagem é adicionar um loop à função `DoFieldExchange` do seu conjunto de registros principal que executa um loop em sua lista de novas colunas, chamando a função RFX apropriada para cada coluna na lista. Em cada chamada RFX, passe um nome de coluna da lista do nome da coluna e um local de armazenamento no membro correspondente da lista de valor de resultado.

###  <a name="_core_lists_of_columns"></a> Listas de Colunas

As quatro listas necessárias com as quais trabalhar são mostradas na tabela a seguir.

|||
|-|-|
|**Current-Table-Columns**| (Lista 1 na ilustração) Uma lista das colunas atualmente na tabela na fonte de dados. Essa lista pode corresponder à lista de colunas atualmente associadas em seu conjunto de registros.|
|**Bound-Recordset-Columns**| (Lista 2 na ilustração) Uma lista das colunas associadas em seu conjunto de registros. Essas colunas já têm instruções RFX em sua função `DoFieldExchange`.|
|**Columns-To-Bind-Dynamically**| (Lista 3 na ilustração) Uma lista de colunas na tabela, mas não em seu conjunto de registros. Essas são as colunas que você deseja associar dinamicamente.|
|**Dynamic-Column-Values**| (Lista 4 na ilustração) Uma lista que contém armazenamento para os valores recuperados das colunas que você associa dinamicamente. Os elementos dessa lista correspondem aos de Columns-to-Bind-Dynamically, um a um.|

###  <a name="_core_building_your_lists"></a> Como criar suas listas

Com uma estratégia geral em mente, é possível prestar atenção nos detalhes. Os procedimentos no restante deste tópico mostram como criar as listas mostradas nas [Listas de Colunas](#_core_lists_of_columns). Os procedimentos orientam você para:

- [Determinar os nomes das colunas que não estão em seu conjunto de registros](#_core_determining_which_table_columns_are_not_in_your_recordset).

- [Fornecer armazenamento dinâmico para colunas recém-adicionadas à tabela](#_core_providing_storage_for_the_new_columns).

- [Adicionar dinamicamente chamadas RFX para novas colunas](#_core_adding_rfx_calls_to_bind_the_columns).

###  <a name="_core_determining_which_table_columns_are_not_in_your_recordset"></a> Como determinar quais colunas da tabela não estão em seu conjunto de registros

Crie uma lista (Bound-Recordset-Columns, como na Lista 2 na ilustração) que contém uma lista das colunas já associadas em seu conjunto de registros principal. Em seguida, crie uma lista (Columns-Bind-Dynamically, derivado de Current-Table-Columns e Bound-Recordset-Columns) que contém os nomes de colunas que estão na tabela na fonte de dados, mas não em seu conjunto de registros principal.

##### <a name="to-determine-the-names-of-columns-not-in-the-recordset-columns-to-bind-dynamically"></a>Para determinar os nomes das colunas que não estão no conjunto de registros (Columns-to-Bind-Dynamically)

1. Crie uma lista (Bound-Recordset-Columns) das colunas já associadas em seu conjunto de registros principal.

   Uma abordagem é criar Bound-Recordset-Columns em tempo de design. É possível examinar visualmente as chamadas de função RFX na função `DoFieldExchange` do conjunto de registros para obter esses nomes. Em seguida, configure sua lista como uma matriz inicializada com os nomes.

   Por exemplo, a ilustração mostra Bound-Recordset-Columns (Lista 2) com três elementos. Bound-Recordset-Columns não tem a coluna Telefone mostrada em Current-Table-Columns (Lista 1).

1. Compare Current-Table-Columns e Bound-Recordset-Columns para criar uma lista (Columns-to-Bind-Dynamically) das colunas que ainda não estão associadas em seu conjunto de registros principal.

   Uma abordagem é executar um loop em sua lista de colunas na tabela em tempo de execução (Current-Table-Columns) e sua lista de colunas já associadas em seu conjunto de registros (Bound-Recordset-Columns) em paralelo. Em Columns-to-Bind-Dynamically, coloque os nomes em Current-Table-Columns, que não são exibidos em Bound-Recordset-Columns.

   Por exemplo, a ilustração mostra Columns-to-Bind-Dynamically (Lista 3) com um elemento: a coluna Telefone encontrada em Current-Table-Columns (Lista 1), mas não em Bound-Recordset-Columns (Lista 2).

1. Crie uma lista de Dynamic-Column-Values (como na Lista 4 na ilustração) na qual armazenar os valores de dados correspondentes a cada nome de coluna armazenado em sua lista de colunas a ser associada dinamicamente (Columns-to-Bind-Dynamically).

   Os elementos da lista desempenham a função de novos membros de dados de campo do conjunto de registros. Eles são os locais de armazenamento aos quais as colunas dinâmicas estão associadas. Para ver descrições das listas, confira [Listas de Colunas](#_core_lists_of_columns).

###  <a name="_core_providing_storage_for_the_new_columns"></a> Como fornecer armazenamento para novas colunas

Em seguida, configure os locais de armazenamento para as colunas a serem associadas dinamicamente. A ideia é fornecer um elemento de lista no qual armazenar o valor de cada coluna. Esses locais de armazenamento correspondem às variáveis de membro do conjunto de registros, que armazenam as colunas associadas normalmente.

#### <a name="to-provide-dynamic-storage-for-new-columns-dynamic-column-values"></a>Para fornecer armazenamento dinâmico para novas colunas (Dynamic-Column-Values)

1. Crie Dynamic-Column-Values, paralelo a Columns-to-Bind-Dynamically, para conter o valor dos dados em cada coluna.

   Por exemplo, a ilustração mostra Dynamic-Column-Values (Lista 4) com um elemento: um objeto `CString` que contém o número de telefone real para o registro atual: "555-1212".

   No caso mais comum, Dynamic-Column-Values tem elementos do tipo `CString`. Se estiver lidando com colunas de tipos de dados variados, será necessária uma lista que pode conter elementos de uma variedade de tipos.

O resultado dos procedimentos anteriores são duas listas principais: Columns-to-Bind-Dynamically, que contém os nomes de colunas, e Dynamic-Column-Values, que contém os valores nas colunas para o registro atual.

> [!TIP]
> Se as novas colunas não forem do mesmo tipo de dados, talvez convenha ter uma lista paralela extra que contenha itens que definem, de alguma forma, o tipo de cada elemento correspondente na lista de colunas. (Para isso, será possível usar os valores AFX_RFX_BOOL, AFX_RFX_BYTE e assim por diante, se desejar. Essas constantes são definidas em AFXDB.H.) Escolha um tipo de lista com base na maneira como você representa os tipos de dados de coluna.

###  <a name="_core_adding_rfx_calls_to_bind_the_columns"></a> Como adicionar chamadas RFX para associar as colunas

Por fim, organize a ocorrência da associação dinâmica inserindo chamadas RFX para as novas colunas em sua função `DoFieldExchange`.

##### <a name="to-dynamically-add-rfx-calls-for-new-columns"></a>Para adicionar dinamicamente chamadas RFX para novas colunas

1. Na função de membro `DoFieldExchange` do seu conjunto de registros principal, adicione código que executa um loop em sua lista de novas colunas (Columns-to-Bind-Dynamically). Em cada loop, extraia um nome de coluna de Columns-to-Bind-Dynamically e um valor de resultado para a coluna de Dynamic-Column-Values. Passe esses itens para uma chamada de função RFX apropriada para o tipo de dados da coluna. Para ver descrições das listas, confira [Listas de Colunas](#_core_lists_of_columns).

No caso comum, em suas chamadas de função `RFX_Text`, você extrai objetos `CString` das listas, como nas linhas de código a seguir, em que Columns-to-Bind-Dynamically é um `CStringList` chamado `m_listName` e Dynamic-Column-Values é um `CStringList` chamado `m_listValue`:

```cpp
RFX_Text( pFX,
            m_listName.GetNext( posName ),
            m_listValue.GetNext( posValue ));
```

Para saber mais sobre funções RFX, confira [Macros e Globais](../../mfc/reference/mfc-macros-and-globals.md) na *Referência da Biblioteca de Classes*.

> [!TIP]
> Se as novas colunas forem tipos de dados diferentes, use uma instrução switch em seu loop para chamar a função RFX apropriada para cada tipo.

Quando a estrutura chama `DoFieldExchange` durante o processo `Open` para associar colunas ao conjunto de registros, as chamadas RFX para as colunas estáticas associam essas colunas. Em seguida, seu loop chama repetidamente as funções RFX para as colunas dinâmicas.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: trabalhar com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)
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
ms.openlocfilehash: e03d71d79605d5de87fc25aa388d4ec27e423c13
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46054553"
---
# <a name="recordset-dynamically-binding-data-columns-odbc"></a>Conjunto de registros: associando dinamicamente colunas de dados (ODBC)

Este tópico se aplica às classes ODBC do MFC.  
  
Colunas da tabela de associação que você especificou em tempo de design de gerenciar conjuntos de registros, mas há casos em que você talvez queira vincular colunas que eram desconhecidas para você em tempo de design. Este tópico explica:  
  
- [Quando você talvez queira associar colunas dinamicamente para um conjunto de registros](#_core_when_you_might_bind_columns_dynamically).  
  
- [Como associar colunas dinamicamente em tempo de execução](#_core_how_to_bind_columns_dynamically).  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` em qual linha em massa buscando não foi implementado. As técnicas descritas geralmente não são recomendadas se você estiver usando a busca de linhas em massa. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
##  <a name="_core_when_you_might_bind_columns_dynamically"></a> Quando você pode associar colunas dinamicamente  

Em tempo de design, o Assistente de aplicativo do MFC ou [Assistente de consumidor ODBC MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) (da **Adicionar classe**) cria classes de conjunto de registros com base em tabelas conhecidas e colunas em sua fonte de dados. Bancos de dados podem ser alterados entre quando você cria-los e posteriormente, quando seu aplicativo usa essas tabelas e colunas em tempo de execução. Você ou outro usuário pode adicionar ou remover uma tabela ou adicionar ou descartar colunas de uma tabela que depende do conjunto de registros do seu aplicativo. Isso provavelmente não é uma preocupação para todos os aplicativos de acesso a dados, mas se for à sua organização, como pode você lidar com alterações no esquema de banco de dados, além de reprojetar e recompilar? O objetivo deste tópico é responder essa pergunta.  
  
Este tópico descreve o caso mais comum em que você pode associar colunas dinamicamente — ter começado com um conjunto de registros com base em um esquema de banco de dados conhecido, que você deseja manipular colunas adicionais no tempo de execução. Ainda mais o tópico supõe que as colunas adicionais são mapeadas para `CString` campo membros de dados, o caso mais comum, embora as sugestões são fornecidas para ajudá-lo a gerenciar outros tipos de dados.  
  
Com uma pequena quantidade de código extra, você pode:  
  
- [Determinar quais colunas estão disponíveis em tempo de execução](#_core_how_to_bind_columns_dynamically).  
  
- [Vincular dinamicamente, colunas adicionais ao seu conjunto de registros em tempo de execução](#_core_adding_the_columns).  
  
Seu conjunto de registros ainda contém membros de dados para as colunas que sabia sobre em tempo de design. Ele também contém uma pequena quantidade de código extra que determina dinamicamente se quaisquer novas colunas foram adicionadas à sua tabela de destino e, nesse caso, associa as novas colunas para o armazenamento alocado dinamicamente (em vez de membros de dados do conjunto de registros).  
  
Este tópico não aborda outros casos de associação dinâmica, como colunas ou tabelas removidas. Para esses casos, você precisa usar chamadas de API de ODBC mais diretamente. Para obter informações, consulte o SDK do ODBC *referência do programador* no CD da biblioteca MSDN.  
  
##  <a name="_core_how_to_bind_columns_dynamically"></a> Como associar colunas dinamicamente  

Para associar as colunas dinamicamente, você deve saber (ou ser capaz de determinar) os nomes das colunas adicionais. Você também deve alocar armazenamento para os membros de dados do campo adicional, especifique seus nomes e seus tipos e especifique o número de colunas que você está adicionando.  
  
A discussão a seguir menciona dois diferentes conjuntos de registros. A primeira é o principal conjunto de registros que seleciona os registros da tabela de destino. O segundo é um conjunto de registros de coluna especial usado para obter informações sobre as colunas em sua tabela de destino.  
  
###  <a name="_core_the_general_process"></a> Processo geral  

Nível mais geral, siga estas etapas:  
  
1. Construa seu objeto recordset principal.  
  
     Opcionalmente, passar um ponteiro para um aberto `CDatabase` de objeto ou ser capaz de fornecer informações de conexão para o conjunto de registros de coluna de alguma outra forma.  
  
1. Execute etapas para adicionar colunas dinamicamente.  
  
     Consulte o processo descrito em Adicionando colunas abaixo.  
  
1. Abra seu conjunto de registros principal.  
  
     O conjunto de registros seleciona os registros e usa a registrar troca de campos (RFX) para associar as colunas estáticas (aquelas que são mapeados para membros de dados do campo de conjunto de registros) e colunas dinâmicas (mapeadas para o armazenamento extra que você alocar).  
  
###  <a name="_core_adding_the_columns"></a> Adicionando colunas  

Associação dinâmica adicionados a colunas em tempo de execução exige as seguintes etapas:  
  
1. Em tempo de execução, determine quais colunas são na tabela de destino. Extrai essas informações uma lista das colunas que foram adicionados à tabela, pois sua classe de conjunto de registros foi criado.  
  
     Uma boa abordagem é usar uma classe de conjunto de registros de coluna usada para consultar a fonte de dados para obter informações de coluna para a tabela de destino (por exemplo, o tipo de dados e o nome da coluna).  
  
1. Fornece armazenamento para os novos membros de dados do campo. Porque sua classe de conjunto de registros principal não tem membros de dados de campo para colunas desconhecidos, você deve fornecer um local para armazenar os nomes, os valores de resultado e, possivelmente, informações de tipo de dados (se as colunas de diferentes tipos de dados).  
  
     Uma abordagem é criar uma ou mais listas dinâmicas, um para os nomes das novas colunas, outro para seus valores de resultado e um terceiro para seus tipos de dados (se necessário). Essas listas, especialmente a lista de valores, fornecem as informações e o armazenamento necessários para a associação. A figura a seguir ilustra a criação de listas.  
     ![Criando listas de colunas para associar dinamicamente](../../data/odbc/media/vc37w61.gif "vc37w61")  
Criar listas de colunas para associar dinamicamente  
  
1. Adicione uma chamada de função RFX em seu conjunto de registros principal `DoFieldExchange` de função para cada coluna de adicionado. Essas chamadas RFX fazem o trabalho de buscar um registro, incluindo as colunas adicionais e as colunas de associação para membros de dados do conjunto de registros ou para seu armazenamento dinamicamente fornecido para eles.  
  
     Uma abordagem é adicionar um loop para seu conjunto de registros principal `DoFieldExchange` função que executa um loop por meio de sua lista de novas colunas, chamando a função RFX apropriada para cada coluna na lista. Em cada chamada RFX, passe um nome de coluna da lista de nome de coluna e um local de armazenamento em que o membro correspondente da lista de valores de resultado.  
  
###  <a name="_core_lists_of_columns"></a> Listas de colunas  

As quatro listas com que você precisará trabalhar são mostradas na tabela a seguir.  

|||
|-|-|  
**Colunas da tabela atual**| (Lista de 1 na ilustração) Uma lista das colunas atualmente na tabela na fonte de dados. Essa lista pode corresponder a lista de colunas associadas no momento em seu conjunto de registros.|
|**Colunas do conjunto de associação**| (Lista de 2 na ilustração) Uma lista das colunas de limite no seu conjunto de registros. Essas colunas já ter instruções RFX seu `DoFieldExchange` função.|
|**Colunas-para-Bind-dinamicamente**| (Lista de 3 na ilustração) Uma lista de colunas na tabela, mas não em seu conjunto de registros. Essas são as colunas que você deseja associar dinamicamente.|
|**Valores de coluna dinâmica**| (Lista de 4 na ilustração) Uma lista que contém o armazenamento para os valores recuperados das colunas que você vincular dinamicamente. Os elementos dessa lista correspondem às colunas-para-Bind-dinamicamente, um para um.|

###  <a name="_core_building_your_lists"></a> Criação de suas listas  

Com uma estratégia geral em mente, você pode ativar os detalhes. Os procedimentos no restante deste tópico mostram como criar as listas mostradas na [lista de colunas](#_core_lists_of_columns). Os procedimentos a guiá-lo:  
  
- [Determinando os nomes das colunas do conjunto de registros não](#_core_determining_which_table_columns_are_not_in_your_recordset).  
  
- [Fornecendo armazenamento dinâmico para colunas adicionadas recentemente à tabela](#_core_providing_storage_for_the_new_columns).  
  
- [Adição dinâmica de RFX chama para novas colunas](#_core_adding_rfx_calls_to_bind_the_columns).  
  
###  <a name="_core_determining_which_table_columns_are_not_in_your_recordset"></a> Determinando o que são colunas de tabela não está em seu conjunto de registros  

Crie uma lista (limite--colunas do conjunto, como na lista de 2 na ilustração) que contém uma lista das colunas já associado em seu conjunto de registros principal. Em seguida, crie uma lista (colunas-para-Bind-dinamicamente, derivada de colunas da tabela atual e o limite de conjunto de registros de colunas) que contém os nomes de colunas que estão na tabela na fonte de dados, mas não em seu conjunto de registros principal.  
  
##### <a name="to-determine-the-names-of-columns-not-in-the-recordset-columns-to-bind-dynamically"></a>Para determinar os nomes das colunas não no conjunto de registros (colunas-para-Bind-dinamicamente)  
  
1. Crie uma lista (colunas de conjunto de registros associado) das colunas já associado em seu conjunto de registros principal.  
  
     Uma abordagem é criar colunas de conjunto de registros associado em tempo de design. Você pode examinar visualmente as chamadas de função RFX no conjunto de registros `DoFieldExchange` função para obter esses nomes. Em seguida, configure sua lista como uma matriz inicializada com os nomes.  
  
     Por exemplo, a ilustração mostra o limite--colunas do conjunto (2 de lista) com três elementos. Colunas de conjunto de registros associado está ausente na coluna de telefone mostrada na atual--colunas de tabela (1 de lista).  
  
1. Compare as colunas da tabela atual e colunas do conjunto de associação para criar uma lista (colunas-para-Bind-dinamicamente) das colunas que ainda não estiver vinculado em seu conjunto de registros principal.  
  
     Uma abordagem é executar um loop por meio de sua lista de colunas na tabela em tempo de execução (colunas de tabela atual) e sua lista de colunas já associado em seu conjunto de registros (colunas de conjunto de registros associado) em paralelo. Em colunas-para-Bind-dinamicamente colocar todos os nomes no atual--colunas de tabela que não aparecem em colunas de conjunto de registros associado.  
  
     Por exemplo, a ilustração mostra colunas-para-Bind-dinamicamente (lista de 3) com um elemento: a coluna telefone encontrada no atual--colunas de tabela (1 de lista), mas não no limite--colunas do conjunto (2 de lista).  
  
1. Crie uma lista de coluna-Dynamic-Values (como na lista 4 na ilustração) no qual armazenar os valores de dados correspondentes a cada nome de coluna armazenada em sua lista de colunas para associar dinamicamente (colunas-para-Bind-dinamicamente).  
  
     Os elementos dessa lista o papel do novo conjunto de registros membros de dados do campo. Eles são os locais de armazenamento para o qual as colunas dinâmicas são associadas. Para obter descrições das listas, consulte [lista de colunas](#_core_lists_of_columns).  
  
###  <a name="_core_providing_storage_for_the_new_columns"></a> Fornecer armazenamento para as novas colunas  

Em seguida, configure os locais de armazenamento para as colunas a ser associado dinamicamente. A ideia é fornecer um elemento de lista no qual armazenar o valor de cada coluna. Esses locais de armazenamento em paralelo as variáveis de membro do conjunto de registros, que armazenam as colunas associadas normalmente.  
  
##### <a name="to-provide-dynamic-storage-for-new-columns-dynamic-column-values"></a>Para fornecer armazenamento dinâmico para novas colunas (valores de coluna dinâmica)  
  
1. Compilação dinâmica--valores de coluna, paralelas para colunas-para-Bind-dinamicamente, para conter o valor dos dados em cada coluna.  
  
     Por exemplo, a ilustração mostra coluna-Dynamic-Values (4 de lista) com um elemento: um `CString` objeto que contém o número de telefone real para o registro atual: "555-1212".  
  
     No caso mais comum, os valores de coluna dinâmica com elementos do tipo `CString`. Se você estiver lidando com colunas de diferentes tipos de dados, você precisa de uma lista que pode conter elementos de uma variedade de tipos.  
  
O resultado dos procedimentos acima é duas listas principais: colunas-para-Bind-dinamicamente que contém os nomes de colunas e dinâmico--valores de coluna que contém os valores nas colunas para o registro atual.  
  
> [!TIP]
>  Se as novas colunas não são todos do mesmo tipo de dados, você pode ser um paralelo extra lista que contém itens que alguma forma, definem o tipo de cada elemento correspondente na lista de colunas. (Você pode usar os valores AFX_RFX_BOOL, AFX_RFX_BYTE, e assim por diante, para isso é se você deseja. Essas constantes são definidas em AFXDB. H.) Escolha um tipo de lista com base em como você representa os tipos de dados de coluna.  
  
###  <a name="_core_adding_rfx_calls_to_bind_the_columns"></a> Adicionando chamadas RFX para associar as colunas  

Por fim, fazer com que a associação dinâmica ocorrer, colocando RFX chama para novas colunas em sua `DoFieldExchange` função.  
  
##### <a name="to-dynamically-add-rfx-calls-for-new-columns"></a>Adicionar dinamicamente RFX chama para novas colunas  
  
1. Em seu conjunto de registros principal `DoFieldExchange` membro de função, adicione o código que executa um loop por meio de sua lista de novas colunas (colunas-para-Bind-dinamicamente). Em cada loop, extrai um nome de coluna de colunas-para-Bind-dinamicamente e um valor de resultado para a coluna de valores de coluna dinâmica. Passe esses itens para uma chamada de função RFX apropriado para o tipo de dados da coluna. Para obter descrições das listas, consulte [lista de colunas](#_core_lists_of_columns).  
  
No caso comum, no seu `RFX_Text` você extrair de chamadas de função `CString` objetos nas listas, como as seguintes linhas de código, onde colunas-para-Bind-dinamicamente um `CStringList` chamado `m_listName` e valores de coluna dinâmica é um `CStringList` chamado `m_listValue`:  
  
```cpp  
RFX_Text( pFX,   
            m_listName.GetNext( posName ),   
            m_listValue.GetNext( posValue ));  
```  
  
Para obter mais informações sobre as funções RFX, consulte [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md) na *referência da biblioteca de classe*.  
  
> [!TIP]
>  Se as novas colunas são os diferentes tipos de dados, use uma instrução switch em seu loop para chamar a função RFX apropriada para cada tipo.  
  
Quando o framework chama `DoFieldExchange` durante o `Open` processo para associar colunas no conjunto de registros, as chamadas RFX para essas colunas de associação de colunas estáticas. Em seguida, seu loop repetidamente chama funções RFX para as colunas dinâmicas.  
  
## <a name="see-also"></a>Consulte também  

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: trabalhando com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md)
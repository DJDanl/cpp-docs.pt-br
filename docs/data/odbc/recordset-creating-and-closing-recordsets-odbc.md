---
title: 'Conjunto de registros: criando e fechando conjuntos de registros (ODBC)'
ms.date: 05/09/2019
helpviewer_keywords:
- ODBC recordsets, creating
- recordsets, creating
- recordsets, opening
- recordsets, closing
- ODBC recordsets, closing
- ODBC recordsets, opening
ms.assetid: 8d2aac23-4396-4ce2-8c60-5ecf1b360d3d
ms.openlocfilehash: 41b1c11e2c820b6e5777e1af426c5e1253ed5468
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367085"
---
# <a name="recordset-creating-and-closing-recordsets-odbc"></a>Conjunto de registros: criando e fechando conjuntos de registros (ODBC)

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Este tópico aplica-se às classes ODBC do MFC.

Para usar um conjunto de registros, construa um objeto de conjunto de registros e, em seguida, chame sua função de membro `Open` para executar a consulta do conjunto de registros e selecionar registros. Quando você conclui o conjunto de registros, feche e destrua o objeto.

Este tópico explica:

- [Quando e como criar um objeto de conjunto de registros](#_core_creating_recordsets_at_run_time).

- [Quando e como é possível qualificar o comportamento do conjunto de registros por meio da parametrização, filtragem, classificação ou bloqueio dele](#_core_setting_recordset_options).

- [Quando e como fechar um objeto de conjunto de registros](#_core_closing_a_recordset).

## <a name="creating-recordsets-at-run-time"></a><a name="_core_creating_recordsets_at_run_time"></a> Como criar conjuntos de registros em tempo de execução

Antes de poder criar objetos recordset em seu programa, normalmente você escreve classes de conjunto de registros específicas do aplicativo. Para saber mais sobre essa etapa preliminar, confira [Como adicionar um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).

Abra um objeto de instantâneo ou dynaset quando você precisar selecionar registros de uma fonte de dados. O tipo de objeto a ser criado depende do que você precisa fazer com os dados em seu aplicativo e daquilo com o que o driver ODBC é compatível. Para saber mais, confira [Dynaset](../../data/odbc/dynaset.md) e [Instantâneo](../../data/odbc/snapshot.md).

#### <a name="to-open-a-recordset"></a>Para abrir um conjunto de registros

1. Construa um objeto da classe derivada pelo `CRecordset`.

   É possível construir o objeto no heap ou no registro de ativação de uma função.

1. Ou modifique o comportamento do conjunto de registros padrão. Para ver as opções disponíveis, confira [Como definir opções de conjunto de registros](#_core_setting_recordset_options).

1. Chame a função de membro [Open](../../mfc/reference/crecordset-class.md#open) do objeto.

No construtor, passe um ponteiro para um objeto `CDatabase` ou passe NULL para usar um objeto de banco de dados temporário que a estrutura constrói e abre com base na cadeia de conexão retornada pela função de membro [GetDefaultConnect](../../mfc/reference/crecordset-class.md#getdefaultconnect). O objeto `CDatabase` já pode estar conectado a uma fonte de dados.

A chamada para `Open` usa o SQL para selecionar registros da fonte de dados. O primeiro registro selecionado (se houver) é o registro atual. Os valores dos campos deste registro são armazenados nos membros de dados de campo do objeto de conjunto de registros. Se registros foram selecionados, as funções de membro `IsBOF` e `IsEOF` retornarão 0.

Em sua chamada [Open](../../mfc/reference/crecordset-class.md#open), você pode:

- Especificar se o conjunto de registros é um dynaset ou um instantâneo. Os conjuntos de registros são abertos como instantâneos por padrão. Ou pode especificar um conjunto de registros somente de encaminhamento, que permite apenas rolagem para frente, um registro por vez.

   Por padrão, um conjunto de registros usa o tipo padrão armazenado no membro de dados `CRecordset``m_nDefaultType`. Os assistentes escrevem código para inicializar `m_nDefaultType` para o tipo de conjunto de registros escolhido no assistente. Em vez de aceitar este padrão, é possível substituir outro tipo de conjunto de registros.

- Especificar uma cadeia de caracteres para substituir a instrução **SELECT** SQL padrão construída pelo conjunto de registros.

- Especificar se o conjunto de registros é somente leitura ou somente de acréscimo. Os conjuntos de registros permitem a atualização completa por padrão, mas é possível limitar isso à adição de novos registros somente ou é possível cancelar a permissão de todas as atualizações.

O exemplo a seguir mostra como abrir um objeto de instantâneo somente leitura da classe `CStudentSet`, uma classe específica do aplicativo:

```cpp
// Construct the snapshot object
CStudentSet rsStudent( NULL );
// Set options if desired, then open the recordset
if(!rsStudent.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
    return FALSE;
// Use the snapshot to operate on its records...
```

Após chamar `Open`, use as funções de membro e membros de dados do objeto para trabalhar com os registros. Em alguns casos, talvez convenha repetir a consulta ou atualizar o conjunto de registros para incluir alterações que ocorreram na fonte de dados. Para obter mais informações, consulte [Recordset: Requerying a Recordset (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md).

> [!TIP]
> A cadeia de conexão usada durante o desenvolvimento pode não ser a mesma cadeia de conexão de que seus usuários eventuais precisam. Para obter ideias sobre como generalizar sua aplicação nesse sentido, consulte [Fonte de Dados: Gerenciamento de Conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md).

## <a name="setting-recordset-options"></a><a name="_core_setting_recordset_options"></a> Como definir opções de conjunto de registros

Após construir seu objeto de conjunto de registros, mas antes de chamar `Open` para selecionar registros, talvez convenha definir algumas opções para controlar o comportamento do conjunto de registros. Para todos os conjuntos de registros, você pode:

- Especificar um [filtro](../../data/odbc/recordset-filtering-records-odbc.md) para restringir a seleção de registros.

- Especificar uma ordem de [classificação](../../data/odbc/recordset-sorting-records-odbc.md) para os registros.

- Especificar [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) para que você possa selecionar registros usando as informações obtidas ou calculadas em tempo de execução.

Também será possível definir a opção a seguir se as condições estiverem corretas:

- Se o conjunto de registros for atualizável e for compatível com opções de bloqueio, especifique o método de [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) usado para atualizações.

> [!NOTE]
> Para afetar a seleção de registros, é necessário definir essas opções antes de chamar a função de membro `Open`.

## <a name="closing-a-recordset"></a><a name="_core_closing_a_recordset"></a> Como fechar um conjunto de registros

Quando você concluir seu conjunto de registros, deverá descartá-lo e desalocar sua memória.

#### <a name="to-close-a-recordset"></a>Para fechar um conjunto de registros

1. Chame sua função de membro [Close](../../mfc/reference/crecordset-class.md#close).

1. Destrua o objeto de conjunto de registros.

   Se você o declarou no registro de ativação de uma função, o objeto é destruído automaticamente quando ele sai do escopo. Caso contrário, use o operador **delete**.

`Close` libera o manipulador `HSTMT` do conjunto de registros. Ele não destrói o objeto C++.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md)<br/>
[Conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)

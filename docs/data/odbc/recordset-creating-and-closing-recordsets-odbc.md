---
title: 'Conjunto de registros: Criando e fechando conjuntos de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC recordsets, creating
- recordsets, creating
- recordsets, opening
- recordsets, closing
- ODBC recordsets, closing
- ODBC recordsets, opening
ms.assetid: 8d2aac23-4396-4ce2-8c60-5ecf1b360d3d
ms.openlocfilehash: 5d5dae5bc766c0cfc31b4fb76f7fe104be0dbd74
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59041261"
---
# <a name="recordset-creating-and-closing-recordsets-odbc"></a>Conjunto de registros: Criando e fechando conjuntos de registros (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Para usar um conjunto de registros, construa um objeto de conjunto de registros e, em seguida, chame seu `Open` função de membro para executar a consulta do conjunto de registros e selecionar registros. Quando você terminar com o conjunto de registros, feche e destrua o objeto.

Este tópico explica:

- [Quando e como criar um objeto recordset](#_core_creating_recordsets_at_run_time).

- [Quando e como você pode qualificar o comportamento do conjunto de registros por parametrização, filtragem, classificação ou bloqueá-lo](#_core_setting_recordset_options).

- [Quando e como fechar um objeto recordset](#_core_closing_a_recordset).

##  <a name="_core_creating_recordsets_at_run_time"></a> Criando conjuntos de registros em tempo de execução

Antes de criar objetos de conjunto de registros em seu programa, você normalmente escreve classes de conjunto de registros específicos do aplicativo. Para obter mais informações sobre esta etapa preliminar, consulte [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md).

Abra um objeto de dynaset ou instantâneo quando você precisa selecionar registros da fonte de dados. O tipo de objeto a ser criado depende do que você precisa fazer com os dados em seu aplicativo e em que o driver ODBC dá suporte. Para obter mais informações, consulte [Dynaset](../../data/odbc/dynaset.md) e [instantâneo](../../data/odbc/snapshot.md).

#### <a name="to-open-a-recordset"></a>Para abrir um conjunto de registros

1. Construa um objeto da sua `CRecordset`-classe derivada.

   Você pode construir o objeto no heap ou no quadro da pilha de uma função.

1. Opcionalmente, modificar o comportamento do conjunto de registros padrão. Para as opções disponíveis, consulte [definindo opções de conjunto de registros](#_core_setting_recordset_options).

1. Chamar o objeto [abrir](../../mfc/reference/crecordset-class.md#open) função de membro.

No construtor, passe um ponteiro para um `CDatabase` do objeto ou passar nulo para usar um objeto de banco de dados temporário que constrói a estrutura e é aberto com base na cadeia de conexão retornada pelo [GetDefaultConnect](../../mfc/reference/crecordset-class.md#getdefaultconnect) função de membro. O `CDatabase` objeto já pode estar conectado a uma fonte de dados.

A chamada para `Open` usa SQL para selecionar registros da fonte de dados. O primeiro registro selecionado (se houver) é o registro atual. Os valores dos campos desse registro são armazenados em membros de dados de campo do objeto de conjunto de registros. Se todos os registros tiverem sido selecionados, tanto a `IsBOF` e `IsEOF` funções membro retornam 0.

No seu [abrir](../../mfc/reference/crecordset-class.md#open) chamada, você pode:

- Especifique se o conjunto de registros é um dynaset ou instantâneo. Conjuntos de registros aberto como instantâneos por padrão. Ou, você pode especificar um recordset somente de encaminhamento, o que permite que apenas roll-forward, um registro de cada vez.

   Por padrão, um conjunto de registros usa o tipo de padrão armazenado na `CRecordset` membro de dados `m_nDefaultType`. Assistentes de escrever código para inicializar `m_nDefaultType` para o tipo de conjunto de registros escolhida no assistente. Em vez de aceitar esse padrão, você pode substituir o outro tipo de conjunto de registros.

- Especifique uma cadeia de caracteres para substituir o padrão SQL **selecionar** instrução que constrói o conjunto de registros.

- Especifique se o conjunto de registros é somente leitura ou somente de acréscimo. Conjuntos de registros permitem completos de atualização por padrão, mas você pode limitar o que para adicionar novos registros somente ou você pode proibir todas as atualizações.

O exemplo a seguir mostra como abrir um objeto de instantâneo somente leitura da classe `CStudentSet`, uma classe específica do aplicativo:

```cpp
// Construct the snapshot object
CStudentSet rsStudent( NULL );
// Set options if desired, then open the recordset
if(!rsStudent.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
    return FALSE;
// Use the snapshot to operate on its records...
```

Depois de chamar `Open`, use os membros de dados e funções de membro do objeto para trabalhar com os registros. Em alguns casos, talvez você queira requery ou atualizar o conjunto de registros para incluir as alterações que ocorreram na fonte de dados. Para obter mais informações, consulte [conjunto de registros: Repetindo consulta a um conjunto de registros (ODBC)](../../data/odbc/recordset-requerying-a-recordset-odbc.md).

> [!TIP]
>  A cadeia de conexão que usar durante o desenvolvimento pode não ser a mesma cadeia de conectar-se que os usuários eventuais precisam. Para obter ideias sobre como generalizar o seu aplicativo em relação a isso, consulte [fonte de dados: Gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md).

##  <a name="_core_setting_recordset_options"></a> Definindo opções de conjunto de registros

Depois de construir o objeto de conjunto de registros, mas antes de chamar `Open` para selecionar registros, você talvez queira definir algumas opções para controlar o comportamento do conjunto de registros. Para todos os conjuntos de registros, você pode:

- Especifique um [filtro](../../data/odbc/recordset-filtering-records-odbc.md) para restringir a seleção de registros.

- Especifique um [classificação](../../data/odbc/recordset-sorting-records-odbc.md) para que os registros.

- Especificar [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) para que você possa selecionar registros usando as informações obtidas ou calculados em tempo de execução.

Você também pode definir a opção a seguir se as condições forem atendidas:

- Se o conjunto de registros é atualizável e dá suporte a opções de bloqueio, especifique o [bloqueio](../../data/odbc/recordset-locking-records-odbc.md) método usado para atualizar.

> [!NOTE]
>  Para afetar a seleção de registro, você deve definir essas opções antes de chamar o `Open` função de membro.

##  <a name="_core_closing_a_recordset"></a> Fechando um conjunto de registros

Quando você terminar com seu conjunto de registros, você deve descartá-la e desalocar sua memória.

#### <a name="to-close-a-recordset"></a>Para fechar um conjunto de registros

1. Chamar sua [fechar](../../mfc/reference/crecordset-class.md#close) função de membro.

1. Destrua o objeto de conjunto de registros.

   Se você declarou no quadro da pilha de uma função, o objeto é destruído automaticamente quando o objeto sai do escopo. Caso contrário, use o **excluir** operador.

`Close` libera o conjunto de registros `HSTMT` manipular. Ele não destrói o objeto de C++.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: Rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md)<br/>
[Conjunto de registros: Adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)
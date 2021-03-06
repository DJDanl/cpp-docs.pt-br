---
title: 'Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- SQL, retrieving aggregate values from recordsets
- recordsets, retrieving SQL aggregate values
- retrieving SQL aggregate values from recordsets
- ODBC recordsets, retrieving SQL aggregate values
- SQL aggregate values
- SQL Server projects, retrieving aggregate values from recordsets
- SQL aggregate values, retrieving from recordsets
ms.assetid: 94500662-22a4-443e-82d7-acbe6eca447b
ms.openlocfilehash: b9e70716ad90a14bbed552d47f48d5a3317e5a62
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225703"
---
# <a name="recordset-obtaining-sums-and-other-aggregate-results-odbc"></a>Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)

> [!NOTE]
> O Assistente de consumidor ODBC do MFC não está disponível no Visual Studio 2019 e posterior. É possível criar um consumidor manualmente.

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica como obter resultados agregados usando as seguintes palavras-chave [SQL](../../data/odbc/sql.md):

- **SUM** calcula o total dos valores em uma coluna com um tipo de dados numérico.

- **MIN** extrai o menor valor em uma coluna com um tipo de dados numérico.

- **MAX** extrai o maior valor em uma coluna com um tipo de dados numérico.

- **AVG** calcula um valor médio de todos os valores em uma coluna com um tipo de dados numérico.

- **COUNT** conta o número de registros em uma coluna de qualquer tipo de dados.

Use essas funções SQL para obter informações estatísticas sobre os registros em uma fonte de dados, em vez de extrair registros da fonte de dados. O conjunto de registros criado normalmente é composto de um único registro (se todas as colunas forem agregações) que contém um valor. (Pode haver mais de um registro se você usou uma cláusula **Group by** .) Esse valor é o resultado do cálculo ou extração executada pela função SQL.

> [!TIP]
> Para adicionar uma cláusula **GROUP BY** SQL (e, possivelmente, uma cláusula **HAVING**) à instrução SQL, acrescente-a ao final de `m_strFilter`. Por exemplo:

```
m_strFilter = "sales > 10 GROUP BY SALESPERSON_ID";
```

É possível limitar o número de registros usados para obter resultados agregados por meio da filtragem e da classificação das colunas.

> [!CAUTION]
> Alguns operadores de agregação retornam um tipo de dados diferente das colunas nas quais eles estão agregando.

- **Sum** e **AVG** podem retornar o próximo tipo de dados maior (por exemplo, chamar com **`int`** retornos **Long** ou **`double`** ).

- **COUNT** geralmente retorna **LONG**, independentemente do tipo de coluna de destino.

- **MAX** e **MIN** retornam o mesmo tipo de dados que as colunas que calculam.

     Por exemplo, o assistente para **Adicionar classe** cria **`long`** `m_lSales` para acomodar uma coluna vendas, mas você precisa substituir isso por um `double m_dblSumSales` membro de dados para acomodar o resultado agregado. Veja o exemplo a seguir.

#### <a name="to-obtain-an-aggregate-result-for-a-recordset"></a>Para obter um resultado de agregação para um conjunto de registros

1. Crie um conjunto de registros conforme descrito em [Como adicionar um consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) que contém as colunas das quais você deseja obter resultados agregados.

1. Modifique a função [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) para o conjunto de registros. Substitua a cadeia de caracteres que representa o nome da coluna (o segundo argumento das chamadas de função [RFX](../../data/odbc/record-field-exchange-using-rfx.md)) por uma cadeia de caracteres que representa a função de agregação na coluna. Por exemplo, substitua:

    ```
    RFX_Long(pFX, "Sales", m_lSales);
    ```

     por:

    ```
    RFX_Double(pFX, "Sum(Sales)", m_dblSumSales)
    ```

1. Abrir o conjunto de registros. O resultado da operação de agregação é deixado no `m_dblSumSales`.

> [!NOTE]
> Na verdade, o assistente atribui os nomes de membro de dados sem prefixos húngaros. Por exemplo, o assistente produziria `m_Sales` para uma coluna Vendas, em vez do nome `m_lSales` usado anteriormente para fins ilustrativos.

Se você estiver usando uma classe [CRecordView](../../mfc/reference/crecordview-class.md) para exibir os dados, será necessário alterar a chamada de função DDX para exibir o novo valor de membro de dados; nesse caso, alterando-o de:

```
DDX_FieldText(pDX, IDC_SUMSALES, m_pSet->m_lSales, m_pSet);
```

Para:

```
DDX_FieldText(pDX, IDC_SUMSALES, m_pSet->m_dblSumSales, m_pSet);
```

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como os Recordsets selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)

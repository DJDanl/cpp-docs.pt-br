---
title: 'Conjunto de registros: Obtendo SUMs e outros resultados agregados (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- SQL, retrieving aggregate values from recordsets
- recordsets, retrieving SQL aggregate values
- retrieving SQL aggregate values from recordsets
- ODBC recordsets, retrieving SQL aggregate values
- SQL aggregate values
- SQL Server projects, retrieving aggregate values from recordsets
- SQL aggregate values, retrieving from recordsets
ms.assetid: 94500662-22a4-443e-82d7-acbe6eca447b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8d78b6375736c35b7a1d49436c870d7f807f6c78
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032361"
---
# <a name="recordset-obtaining-sums-and-other-aggregate-results-odbc"></a>Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)

Este tópico se aplica às classes ODBC do MFC.  
  
Este tópico explica como obter resultados de agregação usando o seguinte [SQL](../../data/odbc/sql.md) palavras-chave:  
  
- **Soma** calcula o total dos valores em uma coluna com um tipo de dados numéricos.  
  
- **MIN** extrai o menor valor em uma coluna com um tipo de dados numéricos.  
  
- **MAX** extrai o maior valor em uma coluna com um tipo de dados numéricos.  
  
- **AVG** calcula um valor médio de todos os valores em uma coluna com um tipo de dados numéricos.  
  
- **Contagem de** conta o número de registros em uma coluna de qualquer tipo de dados.  
  
Você usar essas funções SQL para obter informações estatísticas sobre os registros em uma fonte de dados em vez de extrair os registros da fonte de dados. O conjunto de registros é criado normalmente consiste em um único registro (se todas as colunas são agregados) que contém um valor. (Pode haver mais de um registro que você usou uma **GROUP BY** cláusula.) Esse valor é o resultado do cálculo ou extração executadas pela função SQL.  
  
> [!TIP]
>  Para adicionar um SQL **GROUP BY** cláusula (e, possivelmente, um **HAVING** cláusula) à instrução SQL, acrescente-ao final da `m_strFilter`. Por exemplo:  
  
```  
m_strFilter = "sales > 10 GROUP BY SALESPERSON_ID";  
```  
  
Você pode limitar o número de registros que você pode usar para obter resultados agregados por filtragem e classificação por colunas.  
  
> [!CAUTION]
>  Alguns operadores de agregação retornam um tipo de dados diferentes das colunas em que elas são de agregação.  
  
- **Soma** e **AVG** pode retornar o tipo de dados maior (por exemplo, chamar com `int` retorna **longo** ou **double**).  
  
- **Contagem** geralmente retorna **longo** , independentemente do tipo de coluna de destino.  
  
- **MÁX** e **MIN** retornam o mesmo tipo de dados como colunas de calculam a eles.  
  
     Por exemplo, o **Add Class** assistente cria `long` `m_lSales` acomodar uma coluna de vendas, mas você precisa substituir isso com um `double m_dblSumSales` membro de dados para acomodar o resultado da agregação. Consulte o exemplo a seguir.  
  
#### <a name="to-obtain-an-aggregate-result-for-a-recordset"></a>Para obter um resultado de agregação para um conjunto de registros  
  
1. Crie um conjunto de registros, conforme descrito em [adicionando um consumidor de ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) que contém as colunas do qual você deseja obter resultados agregados.  
  
1. Modificar a [DoFieldExchange](../../mfc/reference/crecordset-class.md#dofieldexchange) função para o conjunto de registros. Substitua a cadeia de caracteres que representa o nome da coluna (o segundo argumento de [RFX](../../data/odbc/record-field-exchange-using-rfx.md) chamadas de função) com uma cadeia de caracteres que representa a função de agregação na coluna. Por exemplo, substitua:  
  
    ```  
    RFX_Long(pFX, "Sales", m_lSales);  
    ```  
  
     por:  
  
    ```  
    RFX_Double(pFX, "Sum(Sales)", m_dblSumSales)  
    ```  
  
1. Abra o conjunto de registros. O resultado da operação de agregação é deixado no `m_dblSumSales`.  
  
> [!NOTE]
>  O assistente, na verdade, atribui nomes de membro de dados sem prefixos húngaras. Por exemplo, o assistente produziria `m_Sales` para uma coluna de vendas, em vez de `m_lSales` nome usado anteriormente para fins ilustrativos.  
  
Se você estiver usando um [CRecordView](../../mfc/reference/crecordview-class.md) de classe para exibir os dados, você precisa alterar a chamada de função DDX para exibir o novo valor de membro de dados; nesse caso, alterando-o de:  
  
```  
DDX_FieldText(pDX, IDC_SUMSALES, m_pSet->m_lSales, m_pSet);  
```  
  
Para:  
  
```  
DDX_FieldText(pDX, IDC_SUMSALES, m_pSet->m_dblSumSales, m_pSet);  
```  
  
## <a name="see-also"></a>Consulte também  

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Conjunto de registros: como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)
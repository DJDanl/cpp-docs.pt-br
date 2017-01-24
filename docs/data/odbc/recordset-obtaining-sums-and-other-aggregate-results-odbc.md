---
title: "Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC) | Microsoft Docs"
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
  - "conjunto de registros ODBC, recuperando valores agregados SQL"
  - "conjuntos de registros, recuperando valores agregados SQL"
  - "recuperando valores agregados SQL de conjuntos de registros"
  - "valores agregados SQL"
  - "valores agregados SQL, recuperando a partir de conjuntos de registros"
  - "Projetos SQL Server, recuperando valores agregados de conjuntos de registros"
  - "SQL, recuperando valores agregados de conjuntos de registros"
ms.assetid: 94500662-22a4-443e-82d7-acbe6eca447b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: obtendo SUMs e outros resultados agregados (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como obter resultados agregados usando as seguintes palavras\-chave de [SQL](../../data/odbc/sql.md) :  
  
-   **SOMA** Calcula o total de valores em uma coluna com um tipo de dados numérico.  
  
-   **MÍN.** Extrai o menor valor de uma coluna com um tipo de dados numérico.  
  
-   **MÁX** Extrai o maior valor de uma coluna com um tipo de dados numérico.  
  
-   **MÉDIA** Calcula um valor médio de todos os valores em uma coluna com um tipo de dados numérico.  
  
-   **CONTAGEM** Conta o número de registros em uma coluna de qualquer tipo de dados.  
  
 Você usa estas funções do SQL para obter informações estatísticas sobre os registros em uma fonte de dados em vez de para extrair registros na fonte de dados.  O conjunto de registros que é criado normalmente consiste em um único registro \(se todas as colunas são agregações\) que contém um valor. \(Pode haver mais de um registro se você usou uma cláusula de **AGRUPAR POR** .\) Esse valor será o resultado de cálculo ou de extração executado pela função do SQL.  
  
> [!TIP]
>  Para adicionar uma cláusula do SQL **AGRUPAR POR** \(e possivelmente uma cláusula de **HAVING** \) à instrução SQL, acrescentar\-la ao final de **m\_strFilter**.  Por exemplo:  
  
```  
m_strFilter = "sales > 10 GROUP BY SALESPERSON_ID";  
```  
  
 Você pode limitar o número de registros que você usa para obter agregar resultados filtrando e classificando as colunas.  
  
> [!CAUTION]
>  Alguns operadores de agregação retornam um tipo de dados diferente das colunas em que estão agregando.  
  
-   **SOMA** e **MÉDIA** podem retornar o tipo de dados maior seguir \(por exemplo, chame com `int` retorna **LONG** ou **double**\).  
  
-   **CONTAGEM** geralmente retorna **LONG** independentemente do tipo da coluna de destino.  
  
-   **MÁX** e retorno de **MÍN.** o mesmo tipo de dados das colunas que calculam.  
  
     Por exemplo, o assistente de **Adicionar Classe** cria `long` `m_lSales` para acomodar uma coluna vendas, mas você precisa substituí\-lo por um membro de dados de `double m_dblSumSales` para acomodar o resultado de agregação.  Consulte o exemplo a seguir.  
  
#### Para obter um resultado de agregação para um conjunto de registros  
  
1.  Crie um conjunto de registros conforme descrito em [Adicionando um consumidor de MFC ODBC](../../mfc/reference/adding-an-mfc-odbc-consumer.md) que contém as colunas que você deseja obter resultados agregados.  
  
2.  Modifique a função de [DoFieldExchange](../Topic/CRecordset::DoFieldExchange.md) para o conjunto de registros.  Substituir a cadeia de caracteres que representa o nome da coluna \(o segundo argumento de chamadas de funções de [RFX](../../data/odbc/record-field-exchange-using-rfx.md) \) com uma cadeia de caracteres que representa a função de agregação na coluna.  Por exemplo, substitua:  
  
    ```  
    RFX_Long(pFX, "Sales", m_lSales);  
    ```  
  
     com:  
  
    ```  
    RFX_Double(pFX, "Sum(Sales)", m_dblSumSales)  
    ```  
  
3.  Abra o conjunto de registros.  O resultado da operação de agregação é deixado em `m_dblSumSales`.  
  
> [!NOTE]
>  O assistente atribui realmente nomes de membro de dados sem prefixos húngaros.  Por exemplo, o assistente gerará `m_Sales` para uma coluna vendas, em vez de anterior usado nome de `m_lSales` para ilustração.  
  
 Se você estiver usando uma classe de [CRecordView](../../mfc/reference/crecordview-class.md) para exibir os dados, você tem que alterar a chamada da função de DDX para exibir o novo valor do membro de dados; nesse caso, a alteração do:  
  
```  
DDX_FieldText(pDX, IDC_SUMSALES, m_pSet->m_lSales, m_pSet);  
```  
  
 :  
  
```  
DDX_FieldText(pDX, IDC_SUMSALES, m_pSet->m_dblSumSales, m_pSet);  
```  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: como conjuntos de registros selecionam registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md)
---
title: "Conjunto de registros: classificando registros (ODBC) | Microsoft Docs"
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
  - "conjunto de registros ODBC, classificando"
  - "conjuntos de registros, classificando"
  - "classificando dados, dados do conjunto de registros"
ms.assetid: b40b152e-0a91-452e-be7b-e5bc27f744c7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: classificando registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como classificar o conjunto de registros.  Você pode especificar uma ou mais colunas na qual basear o tipo, e você pode especificar a ordem crescente ou decrescente \(`ASC` ou **DESC**; `ASC` é o padrão\) para cada coluna especificada.  Por exemplo, se você especificar duas colunas, os registros são classificados primeiro na primeira coluna nomeada e na segunda coluna denominada.  Uma cláusula **ORDER BY** do SQL define uma classificação.  Quando a estrutura anexa a cláusula **ORDER BY** à consulta SQL do conjunto de registros, a cláusula controla a ordenação de seleção.  
  
 Você deve estabelecer a ordem de classificação de um conjunto de registros depois que você constrói o objeto mas antes de chamar a função de membro de **Abrir** \(ou antes de chamar a função de membro de **Requery** para um objeto existente do conjunto de registros cuja função de membro de **Abrir** ser chamada anteriormente\).  
  
#### Para especificar uma ordem de classificação para um conjunto de registros objeto  
  
1.  Cria um novo objeto do conjunto de registros \(ou preparar para chamar para **Requery** existente\).  
  
2.  Defina o valor do membro de dados de [m\_strSort](../Topic/CRecordset::m_strSort.md) do objeto.  
  
     O tipo é uma cadeia de caracteres com terminação nula.  O conteúdo da cláusula ORDER BY mas não da palavra\-chave **ORDER BY**.  Por exemplo, use:  
  
    ```  
    recordset.m_strSort = "LastName DESC, FirstName DESC";  
    ```  
  
     not  
  
    ```  
    recordset.m_strSort = "ORDER BY LastName DESC, FirstName DESC";  
    ```  
  
3.  Definir todas as outras opções que você precise, como um filtro, bloqueando o modo, ou os parâmetros.  
  
4.  Chame **Abrir** para o novo objeto \(ou **Requery** para um objeto existente\).  
  
 Os registros selecionados são ordenados como especificados.  Por exemplo, para classificar um conjunto de registros do estudante em ordem decrescente pelo sobrenome, o nome, faça o seguinte:  
  
```  
// Construct the recordset  
CStudentSet rsStudent( NULL );  
// Set the sort  
rsStudent.m_strSort = "LastName DESC, FirstName DESC";  
// Run the query with the sort in place  
rsStudent.Open( );  
```  
  
 O conjunto de registros contém todos os registros do aluno, classificados em ordem decrescente \(Z à\) pelo sobrenome, seguida pelo nome.  
  
> [!NOTE]
>  Se você escolher substituir a cadeia de caracteres padrão do SQL do conjunto de registros passando sua própria cadeia de caracteres SQL da **Abrir**, não defina um tipo se a cadeia de caracteres personalizado tem uma cláusula de **ORDER BY** .  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: parametrizando um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)   
 [Conjunto de registros: filtrando registros \(ODBC\)](../../data/odbc/recordset-filtering-records-odbc.md)
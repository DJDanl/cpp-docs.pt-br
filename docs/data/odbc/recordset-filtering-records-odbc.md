---
title: "Conjunto de registros: filtrando registros (ODBC) | Microsoft Docs"
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
  - "dados [MFC], filtragem"
  - "filtrando conjuntos de registros"
  - "filtros [C++], objeto de conjunto de registros"
  - "conjuntos de registros ODBC [C++], filtrando registros"
  - "conjunto de registros [C++], filtragem"
ms.assetid: 5c075f37-c837-464d-90c1-d028a9d1c175
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: filtrando registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como filtrar um conjunto de registros de modo que seleciona apenas um subconjunto específico de registros disponíveis.  Por exemplo, talvez você queira selecionar somente as seções da classe para um curso específico, como MATH101.  Um filtro é um critério de pesquisa definido pelos conteúdos de uma cláusula do SQL **WHERE** .  Quando a estrutura o acrescenta à instrução SQL do conjunto de registros, a cláusula de **WHERE** restringe a seleção.  
  
 Você deve estabelecer o filtro de um objeto do conjunto de registros depois que você constrói o objeto mas antes de chamar a função de membro de **Abrir** \(ou antes de chamar a função de membro de **Requery** para um objeto existente do conjunto de registros cuja função de membro de **Abrir** ser chamada anteriormente\).  
  
#### Para especificar um filtro para um conjunto de registros objeto  
  
1.  Cria um novo objeto do conjunto de registros \(ou preparar para chamar **Requery** para um objeto existente\).  
  
2.  Defina o valor do membro de dados de [m\_strFilter](../Topic/CRecordset::m_strFilter.md) do objeto.  
  
     O filtro é uma cadeia de caracteres com terminação nula que contém o conteúdo a cláusula FROM do SQL **WHERE** mas não da palavra\-chave **WHERE**.  Por exemplo, use:  
  
    ```  
    m_pSet->m_strFilter = "CourseID = 'MATH101'";  
    ```  
  
     not  
  
    ```  
    m_pSet->m_strFilter = "WHERE CourseID = 'MATH101'";  
    ```  
  
    > [!NOTE]
    >  A cadeia de caracteres literal “MATH101” é mostrada acima com aspas simples.  Na especificação de ODBC SQL, as aspas simples são usadas para denotar um literal de cadeia de caracteres.  Verifique a documentação do driver ODBC para os requisitos de citação do DBMS nessa situação.  Essa sintaxe é discutida também mais próximo do fim deste tópico.  
  
3.  Definir todas as outras opções que você precise, como a ordem de classificação, bloqueando o modo, ou os parâmetros.  Especificar um parâmetro é especialmente útil.  Para obter informações sobre a parametrização do filtro, consulte [Conjunto de registros: A parametrização de um conjunto de registros \(ODBC\)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
4.  Chame **Abrir** para o novo objeto \(ou **Requery** para um objeto aberto anteriormente\).  
  
> [!TIP]
>  Usar parâmetros no filtro é potencialmente o método mais eficiente para recuperar registros.  
  
> [!TIP]
>  Os filtros do conjunto de registros são úteis para tabelas de [adicionar](../Topic/Recordset:%20Performing%20a%20Join%20\(ODBC\).md) e para usar [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) com base nas informações obtidas calculada ou em tempo de execução.  
  
 O conjunto de registros selecionar somente os registros que atendem os critérios de pesquisa que você especificou.  Por exemplo, para especificar o filtro do curso descrito acima \(assumindo `strCourseID` variável definido atualmente, por exemplo, “MATH101”\), faça o seguinte:  
  
```  
// Using the recordset pointed to by m_pSet  
  
// Set the filter  
m_pSet->m_strFilter = "CourseID = " + strCourseID;   
  
// Run the query with the filter in place  
if ( m_pSet->Open( CRecordset::snapshot, NULL, CRecordset::readOnly ) )  
  
// Use the recordset  
```  
  
 O conjunto de registros contém registros para todas as seções da classe para MATH101.  
  
 Observe como a cadeia de caracteres de filtro foi definida no exemplo anterior, usando uma variável de cadeia de caracteres.  Este é o uso típico.  Mas suponha que você queria para especificar o valor literal 100 para a ID do curso  O código a seguir mostra como definir corretamente a cadeia de caracteres de filtro com um valor literal:  
  
```  
m_strFilter = "StudentID = '100'";   // correct  
```  
  
 Observe o uso de caracteres de aspas simples; se você definir a cadeia de caracteres de filtro diretamente, a cadeia de caracteres de filtro é **not**:  
  
```  
m_strFilter = "StudentID = 100";   // incorrect for some drivers  
```  
  
 A citação mostrada acima está em conformidade com a especificação de ODBC, mas algumas DBMSs pode exigir outros caracteres de aspas.  Para obter mais informações, consulte [SQL: Personalizando a instrução SQL do conjunto de registros \(ODBC\)](../../data/odbc/sql-customizing-your-recordset’s-sql-statement-odbc.md).  
  
> [!NOTE]
>  Se você escolher substituir a cadeia de caracteres padrão do SQL do conjunto de registros passando sua própria cadeia de caracteres SQL da **Abrir**, você não deve definir um filtro se a cadeia de caracteres personalizado tem uma cláusula de **WHERE** .  Para obter mais informações sobre como anular a opção SQL, consulte [SQL: Personalizando a instrução SQL do conjunto de registros \(ODBC\)](../../data/odbc/sql-customizing-your-recordset’s-sql-statement-odbc.md).  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: classificando registros \(ODBC\)](../../data/odbc/recordset-sorting-records-odbc.md)   
 [Conjunto de registros: como conjuntos de registros selecionam registros \(ODBC\)](../Topic/Recordset:%20How%20Recordsets%20Select%20Records%20\(ODBC\).md)   
 [Conjunto de registros: como conjuntos de registros atualizam registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)   
 [Conjunto de registros: bloqueando registros \(ODBC\)](../../data/odbc/recordset-locking-records-odbc.md)
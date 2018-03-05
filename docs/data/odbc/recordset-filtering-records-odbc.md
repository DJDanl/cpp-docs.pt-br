---
title: 'Conjunto de registros: Filtrando registros (ODBC) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- data [MFC], filtering
- recordsets [C++], filtering
- filtering recordsets
- ODBC recordsets [C++], filtering records
- filters [C++], recordset object
ms.assetid: 5c075f37-c837-464d-90c1-d028a9d1c175
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b6d6e8b41e67c9f33d643a2f64c7bdf2d2251eff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recordset-filtering-records-odbc"></a>Conjunto de registros: filtrando registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica como filtrar um conjunto de registros para que ele seleciona apenas um subconjunto específico de registros disponíveis. Por exemplo, você talvez queira selecionar apenas as seções de classe para um curso específico, como MATH101. Um filtro é uma condição de pesquisa definida pelo conteúdo de um SQL **onde** cláusula. Quando a estrutura acrescenta à instrução de SQL do conjunto de registros, o **onde** cláusula restringe a seleção.  
  
 Você deve estabelecer o filtro de um objeto conjunto de registros depois de construir o objeto, mas antes de chamar seus **abrir** função de membro (ou antes de chamar o **Requery** função de membro para um conjunto de registros existente objeto cujo **abrir** função membro foi chamada anteriormente).  
  
#### <a name="to-specify-a-filter-for-a-recordset-object"></a>Para especificar um filtro para um objeto de conjunto de registros  
  
1.  Criar um novo objeto de conjunto de registros (ou preparar para chamar **Requery** para um objeto existente).  
  
2.  Definir o valor do objeto [m_strFilter](../../mfc/reference/crecordset-class.md#m_strfilter) membro de dados.  
  
     O filtro é uma cadeia de caracteres terminada em nulo que contém o conteúdo do SQL **onde** cláusula, mas não a palavra-chave **onde**. Por exemplo, use:  
  
    ```  
    m_pSet->m_strFilter = "CourseID = 'MATH101'";  
    ```  
  
     not  
  
    ```  
    m_pSet->m_strFilter = "WHERE CourseID = 'MATH101'";  
    ```  
  
    > [!NOTE]
    >  A cadeia de caracteres literal "MATH101" é mostrada com aspas acima. Na especificação do ODBC SQL, aspas simples são usadas para denotar uma literal de cadeia de caracteres. Verifique a documentação do driver ODBC para os requisitos de cotação de DBMS nessa situação. Essa sintaxe também é discutida mais perto do final deste tópico.  
  
3.  Defina qualquer outra opção que você precisa, como ordem de classificação, o modo de bloqueio ou parâmetros. Especificar um parâmetro é especialmente útil. Para obter informações sobre parametrização seu filtro, consulte [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).  
  
4.  Chamar **abrir** para o novo objeto (ou **Requery** para um objeto aberto anteriormente).  
  
> [!TIP]
>  Usando parâmetros em seu filtro potencialmente é o método mais eficiente para recuperação de registros.  
  
> [!TIP]
>  Os filtros de conjunto de registros são úteis para [unindo](../../data/odbc/recordset-performing-a-join-odbc.md) tabelas e para o uso de [parâmetros](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) com base nas informações obtidas ou calculados em tempo de execução.  
  
 O conjunto de registros seleciona somente os registros que atendem à condição de pesquisa especificado. Por exemplo especificar o filtro de curso descrito acima (supondo que uma variável `strCourseID` definido no momento, por exemplo, como "MATH101"), faça o seguinte:  
  
```  
// Using the recordset pointed to by m_pSet  
  
// Set the filter  
m_pSet->m_strFilter = "CourseID = " + strCourseID;   
  
// Run the query with the filter in place  
if ( m_pSet->Open( CRecordset::snapshot, NULL, CRecordset::readOnly ) )  
  
// Use the recordset  
```  
  
 O conjunto de registros contém registros para todas as seções de classe para MATH101.  
  
 Observe como a cadeia de caracteres de filtro foi definida no exemplo acima, usando uma variável de cadeia de caracteres. Este é o uso típico. Mas suponha que você queira especificar o valor literal 100 para a ID do curso. O código a seguir mostra como definir a cadeia de caracteres de filtro corretamente com um valor literal:  
  
```  
m_strFilter = "StudentID = '100'";   // correct  
```  
  
 Observe o uso de caracteres de aspas simples. Se você definir a cadeia de caracteres de filtro diretamente, a cadeia de caracteres de filtro é **não**:  
  
```  
m_strFilter = "StudentID = 100";   // incorrect for some drivers  
```  
  
 A cotação mostrado acima está de acordo com a especificação de ODBC, mas alguns DBMSs podem exigir outros caracteres de aspas. Para obter mais informações, consulte [SQL: SQL instrução (ODBC do Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).  
  
> [!NOTE]
>  Se você optar por substituir a cadeia de caracteres do conjunto de registros padrão SQL passando sua própria cadeia de caracteres SQL para **abrir**, você não deve definir um filtro se sua cadeia de caracteres personalizada tiver um **onde** cláusula. Para obter mais informações sobre como substituir o padrão SQL, consulte [SQL: SQL instrução (ODBC do Personalizando seu conjunto de registros)](../../data/odbc/sql-customizing-your-recordsets-sql-statement-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md)   
 [Conjunto de registros: Como conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)   
 [Conjunto de registros: Como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md)   
 [Conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md)
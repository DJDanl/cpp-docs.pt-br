---
title: 'Conjunto de registros: Classificando registros (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- sorting data, recordset data
- ODBC recordsets, sorting
- recordsets, sorting
ms.assetid: b40b152e-0a91-452e-be7b-e5bc27f744c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ddb92016b7b911fc86f2feab27a698ce7fa55c45
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="recordset-sorting-records-odbc"></a>Conjunto de registros: classificando registros (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica como classificar o conjunto de registros. Você pode especificar uma ou mais colunas no qual basear a classificação, e você pode especificar a ordem crescente ou decrescente (`ASC` ou **DESC**; `ASC` é o padrão) para cada coluna de especificada. Por exemplo, se você especificar duas colunas, os registros são classificados primeiro na primeira coluna nomeada e, em seguida, a segunda coluna nomeada. Um SQL **ORDER BY** cláusula define uma classificação. Quando a estrutura acrescenta o **ORDER BY** cláusula SQL do conjunto de registros de consulta, os controles de cláusula a seleção da ordenação.  
  
 Você deve estabelecer a ordem de classificação do conjunto de registros depois de construir o objeto, mas antes de chamar seus **abrir** função de membro (ou antes de chamar o **Requery** função de membro de um objeto de conjunto de registros existentes cujo **abrir** função membro foi chamada anteriormente).  
  
#### <a name="to-specify-a-sort-order-for-a-recordset-object"></a>Para especificar uma ordem de classificação para um objeto de conjunto de registros  
  
1.  Criar um novo objeto de conjunto de registros (ou preparar para chamar **Requery** por um já existente).  
  
2.  Definir o valor do objeto [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort) membro de dados.  
  
     A classificação é uma cadeia de caracteres terminada em nulo. Ele contém o conteúdo a **ORDER BY** cláusula, mas não a palavra-chave **ORDER BY**. Por exemplo, use:  
  
    ```  
    recordset.m_strSort = "LastName DESC, FirstName DESC";  
    ```  
  
     not  
  
    ```  
    recordset.m_strSort = "ORDER BY LastName DESC, FirstName DESC";  
    ```  
  
3.  Defina qualquer outra opção que você precisa, como um filtro, o modo de bloqueio ou parâmetros.  
  
4.  Chamar **abrir** para o novo objeto (ou **Requery** para um objeto existente).  
  
 Os registros selecionados são ordenados conforme especificado. Por exemplo, para classificar um conjunto de registros de alunos em ordem decrescente pelo sobrenome e nome, faça o seguinte:  
  
```  
// Construct the recordset  
CStudentSet rsStudent( NULL );  
// Set the sort  
rsStudent.m_strSort = "LastName DESC, FirstName DESC";  
// Run the query with the sort in place  
rsStudent.Open( );  
```  
  
 O conjunto de registros contém todos os registros do aluno, classificados em ordem decrescente (Z a) por sobrenome, em seguida, por nome.  
  
> [!NOTE]
>  Se você optar por substituir a cadeia de caracteres do conjunto de registros padrão SQL passando sua própria cadeia de caracteres SQL para **abrir**, não defina uma classificação se a cadeia de caracteres personalizada tem uma **ORDER BY** cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: Parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)   
 [Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)
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
ms.openlocfilehash: c78603e12aec7653e7c5c62d9a0282241ccda99e
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39337824"
---
# <a name="recordset-sorting-records-odbc"></a>Conjunto de registros: classificando registros (ODBC)
Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica como classificar o conjunto de registros. Você pode especificar uma ou mais colunas no qual basear a classificação, e você pode especificar a ordem crescente ou decrescente (**ASC** ou **DESC**; **ASC** é o padrão) para cada coluna de especificado. Por exemplo, se você especificar duas colunas, os registros são classificados primeiro na primeira coluna nomeada e, em seguida, na segunda coluna nomeada. Um SQL **ORDER BY** cláusula define uma classificação. Quando o framework acrescenta a **ORDER BY** cláusula to SQL do conjunto de registros de consulta, os controles de cláusula a seleção da ordenação.  
  
 Você deve estabelecer a ordem de classificação do conjunto de registros depois que você construir o objeto, mas antes de chamar seus `Open` função de membro (ou antes de chamar o `Requery` função de membro para um conjunto de registros existente do objeto cuja `Open` tem sido a função de membro chamado anteriormente).  
  
#### <a name="to-specify-a-sort-order-for-a-recordset-object"></a>Para especificar uma ordem de classificação para um objeto recordset  
  
1.  Criar um novo objeto de conjunto de registros (ou se prepare para chamar `Requery` por um já existente).  
  
2.  Definir o valor do objeto [m_strSort](../../mfc/reference/crecordset-class.md#m_strsort) membro de dados.  
  
     A classificação é uma cadeia de caracteres terminada em nulo. Ele contém o conteúdo a **ORDER BY** cláusula, mas não a palavra-chave **ORDER BY**. Por exemplo, use:  
  
    ```  
    recordset.m_strSort = "LastName DESC, FirstName DESC";  
    ```  
  
     not  
  
    ```  
    recordset.m_strSort = "ORDER BY LastName DESC, FirstName DESC";  
    ```  
  
3.  Defina quaisquer outras opções que você precisa, como um filtro, o modo de bloqueio ou parâmetros.  
  
4.  Chame `Open` para o novo objeto (ou `Requery` para um objeto existente).  
  
 Os registros selecionados são ordenados conforme especificado. Por exemplo, para classificar um conjunto de registros de alunos em ordem decrescente por sobrenome e, em seguida, nome, faça o seguinte:  
  
```cpp  
// Construct the recordset  
CStudentSet rsStudent( NULL );  
// Set the sort  
rsStudent.m_strSort = "LastName DESC, FirstName DESC";  
// Run the query with the sort in place  
rsStudent.Open( );  
```  
  
 O conjunto de registros contém todos os registros de alunos, classificados em ordem decrescente (Z a) por sobrenome, em seguida, por nome.  
  
> [!NOTE]
>  Se você optar por substituir a cadeia de caracteres do conjunto de registros padrão SQL passando sua própria cadeia de caracteres SQL para `Open`, não defina uma classificação se sua cadeia de caracteres personalizada tem uma **ORDER BY** cláusula.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [O conjunto de registros: Parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md)   
 [Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)
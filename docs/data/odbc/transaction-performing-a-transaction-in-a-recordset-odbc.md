---
title: "Transação: Realizando uma transação em um conjunto de registros (ODBC) | Microsoft Docs"
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
- transactions, updating recordsets
ms.assetid: cf1d6b48-7fb8-4903-84f7-a1822054534d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bd412549c86c3ca8ddc004016183b64248bdf292
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="transaction-performing-a-transaction-in-a-recordset-odbc"></a>Transação: realizando uma transação em um conjunto de registros (ODBC)
Este tópico explica como executar uma transação em um conjunto de registros.  
  
> [!NOTE]
>  Há suporte para apenas um nível de transações; não é possível aninhar transações.  
  
#### <a name="to-perform-a-transaction-in-a-recordset"></a>Para executar uma transação em um conjunto de registros  
  
1.  Chamar o `CDatabase` do objeto **BeginTrans** função de membro.  
  
2.  Se você não implementou a busca de linhas em massa, chame o **AddNew/atualização**, **Editar/atualizar**, e **excluir** funções membro de um ou mais objetos de conjunto de registros da mesma banco de dados como quantas vezes forem necessárias. Para obter mais informações, consulte [conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md). Se você tiver implementado linhas em massa busca, você deve escrever suas próprias funções para atualizar a fonte de dados.  
  
3.  Finalmente, chame o `CDatabase` do objeto **CommitTrans** função de membro. Se ocorrer um erro em uma das atualizações ou decidir cancelar as alterações, chame seu **reversão** função de membro.  
  
 O exemplo a seguir usa dois conjuntos de registros para excluir o registro de um aluno de um banco de dados de registro de escola, removendo o aluno de todas as classes em que o aluno está registrado. Porque o **excluir** chamadas em ambos os conjuntos de registros devem ter êxito, uma transação é necessária. O exemplo supõe a existência de `m_dbStudentReg`, uma variável de membro de tipo `CDatabase` já está conectado à fonte de dados e as classes de conjunto de registros `CEnrollmentSet` e `CStudentSet`. O `strStudentID` variável contém um valor obtido do usuário.  
  
```  
BOOL CEnrollDoc::RemoveStudent( CString strStudentID )  
{  
    // remove student from all the classes  
    // the student is enrolled in  
  
    if ( !m_dbStudentReg.BeginTrans( ) )  
        return FALSE;  
  
    CEnrollmentSet rsEnrollmentSet(&m_dbStudentReg);  
    rsEnrollmentSet.m_strFilter = "StudentID = " + strStudentID;  
  
    if ( !rsEnrollmentSet.Open(CRecordset::dynaset) )  
        return FALSE;  
  
    CStudentSet rsStudentSet(&m_dbStudentReg);  
    rsStudentSet.m_strFilter = "StudentID = " + strStudentID;  
  
    if ( !rsStudentSet.Open(CRecordset::dynaset) )  
        return FALSE;  
  
    TRY  
    {  
        while ( !rsEnrollmentSet.IsEOF( ) )  
        {  
            rsEnrollmentSet.Delete( );  
            rsEnrollmentSet.MoveNext( );  
        }  
  
        // delete the student record  
        rsStudentSet.Delete( );  
  
        m_dbStudentReg.CommitTrans( );  
    }  
  
    CATCH_ALL(e)  
    {  
        m_dbStudentReg.Rollback( );  
        return FALSE;  
    }  
    END_CATCH_ALL  
  
    rsEnrollmentSet.Close( );  
    rsStudentSet.Close( );  
  
    return TRUE;  
  
}  
```  
  
> [!NOTE]
>  Chamando **BeginTrans** novamente sem chamar **CommitTrans** ou **reversão** é um erro.  
  
## <a name="see-also"></a>Consulte também  
 [Transação (ODBC)](../../data/odbc/transaction-odbc.md)   
 [Transação: Como transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)   
 [Classe CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)
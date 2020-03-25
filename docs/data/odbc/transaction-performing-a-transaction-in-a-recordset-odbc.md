---
title: 'Transação: realizando uma transação em um conjunto de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- transactions, updating recordsets
ms.assetid: cf1d6b48-7fb8-4903-84f7-a1822054534d
ms.openlocfilehash: 94177a27a1f99a8c9c37b7fce3f697fd0088b7c6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212557"
---
# <a name="transaction-performing-a-transaction-in-a-recordset-odbc"></a>Transação: realizando uma transação em um conjunto de registros (ODBC)

Este tópico explica como executar uma transação em um conjunto de registros.

> [!NOTE]
>  Há suporte para apenas um nível de transações; Não é possível aninhar transações.

#### <a name="to-perform-a-transaction-in-a-recordset"></a>Para executar uma transação em um conjunto de registros

1. Chame a função de membro `BeginTrans` do objeto de `CDatabase`.

1. Se você não tiver implementado a busca de linha em massa, chame as funções de membro `AddNew/Update`, `Edit/Update`e `Delete` de um ou mais objetos Recordset do mesmo banco de dados quantas vezes forem necessárias. Para obter mais informações, consulte [conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md). Se você tiver implementado a busca de linha em massa, deverá escrever suas próprias funções para atualizar a fonte de dados.

1. Por fim, chame a função de membro `CommitTrans` do objeto de `CDatabase`. Se ocorrer um erro em uma das atualizações ou se você decidir cancelar as alterações, chame sua função de membro `Rollback`.

O exemplo a seguir usa dois conjuntos de registros para excluir o registro de um aluno de um banco de dados de registro da escola, removendo o aluno de todas as classes nas quais o aluno está registrado. Como as chamadas de `Delete` em ambos os conjuntos de registros devem ter sucesso, uma transação é necessária. O exemplo pressupõe a existência de `m_dbStudentReg`, uma variável de membro do tipo `CDatabase` já conectado à fonte de dados e as classes de conjunto de registros `CEnrollmentSet` e `CStudentSet`. A variável `strStudentID` contém um valor obtido do usuário.

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
>  Chamar `BeginTrans` novamente sem chamar `CommitTrans` ou `Rollback` é um erro.

## <a name="see-also"></a>Confira também

[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação: como as transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)

---
title: 'Transação: Realizando uma transação em um conjunto de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- transactions, updating recordsets
ms.assetid: cf1d6b48-7fb8-4903-84f7-a1822054534d
ms.openlocfilehash: 9e06d61d3d86233e136b0b3fe78f149a6778649b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62329823"
---
# <a name="transaction-performing-a-transaction-in-a-recordset-odbc"></a>Transação: Realizando uma transação em um conjunto de registros (ODBC)

Este tópico explica como executar uma transação em um conjunto de registros.

> [!NOTE]
>  Há suporte para apenas um nível de transações; Você não pode aninhar transações.

#### <a name="to-perform-a-transaction-in-a-recordset"></a>Para executar uma transação em um conjunto de registros

1. Chame o `CDatabase` do objeto `BeginTrans` função de membro.

1. Se você não tiver implementado a busca de linhas em massa, chame o `AddNew/Update`, `Edit/Update`, e `Delete` funções de membro de um ou mais objetos de conjunto de registros do mesmo banco de dados quantas vezes forem necessárias. Para obter mais informações, consulte [conjunto de registros: Adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md). Se você tiver implementado a linha em massa que busca, você deve escrever suas próprias funções para atualizar a fonte de dados.

1. Por fim, chame o `CDatabase` do objeto `CommitTrans` função de membro. Se ocorrer um erro em uma das atualizações ou se você decidir cancelar as alterações, chame seu `Rollback` função de membro.

O exemplo a seguir usa dois conjuntos de registros para excluir o registro de um aluno de um banco de dados de registro de escola, removendo os estudantes de todas as classes em que o aluno está registrado. Porque o `Delete` chamadas em ambos os conjuntos de registros devem ter êxito, uma transação é necessária. O exemplo supõe a existência de `m_dbStudentReg`, uma variável de membro do tipo `CDatabase` já está conectado à fonte de dados e as classes de conjunto de registros `CEnrollmentSet` e `CStudentSet`. O `strStudentID` variável contém um valor obtido do usuário.

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
>  Chamando `BeginTrans` novamente sem chamar `CommitTrans` ou `Rollback` é um erro.

## <a name="see-also"></a>Consulte também

[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação: como as transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
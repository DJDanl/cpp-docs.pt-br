---
title: 'Transação: realizando uma transação em um conjunto de registros (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- transactions, updating recordsets
ms.assetid: cf1d6b48-7fb8-4903-84f7-a1822054534d
ms.openlocfilehash: 45ae414c318376b2c4d787498e9a288a0037af83
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358088"
---
# <a name="transaction-performing-a-transaction-in-a-recordset-odbc"></a>Transação: realizando uma transação em um conjunto de registros (ODBC)

Este tópico explica como realizar uma transação em um conjunto de registros.

> [!NOTE]
> Apenas um nível de transações é suportado; você não pode fazer transações.

#### <a name="to-perform-a-transaction-in-a-recordset"></a>Para realizar uma transação em um conjunto de registros

1. Ligue `CDatabase` para a `BeginTrans` função de membro do objeto.

1. Se você não tiver implementado a `AddNew/Update`busca `Edit/Update`em `Delete` linha em massa, ligue para as funções de membro e de um ou mais objetos de conjunto de registros do mesmo banco de dados quantas vezes fornecessário. Para obter mais informações, consulte [Recordset: Adicionando, Atualizando e Excluindo Registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md). Se você implementou a busca em linha em massa, você deve escrever suas próprias funções para atualizar a fonte de dados.

1. Por fim, `CDatabase` chame `CommitTrans` a função de membro do objeto. Se ocorrer um erro em uma das atualizações ou você `Rollback` decidir cancelar as alterações, ligue para sua função de membro.

O exemplo a seguir usa dois conjuntos de registros para excluir a matrícula de um aluno de um banco de dados de matrícula escolar, removendo o aluno de todas as classes em que o aluno está matriculado. Como `Delete` as chamadas em ambos os conjuntos de registros devem ter sucesso, uma transação é necessária. O exemplo assume a `m_dbStudentReg`existência de , `CDatabase` uma variável membro do tipo já `CEnrollmentSet` `CStudentSet`conectado à fonte de dados, e as classes de conjunto de registros e . A `strStudentID` variável contém um valor obtido do usuário.

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
> Ligar `BeginTrans` novamente `CommitTrans` sem ligar ou `Rollback` é um erro.

## <a name="see-also"></a>Confira também

[Transação (ODBC)](../../data/odbc/transaction-odbc.md)<br/>
[Transação: como as transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)

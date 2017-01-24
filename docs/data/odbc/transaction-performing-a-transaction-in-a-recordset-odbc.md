---
title: "Transa&#231;&#227;o: realizando uma transa&#231;&#227;o em um conjunto de registros (ODBC) | Microsoft Docs"
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
  - "transações, atualizando conjuntos de registros"
ms.assetid: cf1d6b48-7fb8-4903-84f7-a1822054534d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Transa&#231;&#227;o: realizando uma transa&#231;&#227;o em um conjunto de registros (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como executar uma transação em um conjunto de registros.  
  
> [!NOTE]
>  Só um nível de transações tiver suporte; não é possível aninhar transações.  
  
#### Para executar uma transação em um conjunto de registros  
  
1.  Chame a função de membro de **BeginTrans** do objeto de `CDatabase` .  
  
2.  Se você não tiver implementado a linha em massa que pesquisa, chame **AddNew\/Update**, **Edit\/Update**, e as funções de membro de **Excluir** de um ou mais objetos do conjunto de registros do mesmo base de dados tantas vezes quando necessário.  Para obter mais informações, consulte [Conjunto de registros: Adicionando, atualizando e excluindo registros \(ODBC\)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md).  Se você implementar a linha em massa que pesquisa, você deve escrever suas próprias funções para atualizar a fonte de dados.  
  
3.  Finalmente, chame a função de membro de **CommitTrans** do objeto de `CDatabase` .  Se ocorrer um erro em uma das atualizações ou você decidir cancelar as alterações, chame a função de membro de **Reverter** .  
  
 O exemplo a seguir usa dois conjuntos de registros para excluir o registro de um aluno de um base de dados de registro de escola, removendo o aluno de todas as classes em que o aluno é registrado.  Como as chamadas de **Excluir** em ambos os conjuntos de registros sejam bem\-sucedidas, uma transação é necessária.  O exemplo supõe a existência de `m_dbStudentReg`, uma variável de membro do tipo `CDatabase` já conectado à fonte de dados, e às classes `CEnrollmentSet` e `CStudentSet`conjunto de registros.  A variável de `strStudentID` contém um valor obtido do usuário.  
  
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
>  A chamada **BeginTrans** novamente sem chamar **CommitTrans** ou **Reverter** é um erro.  
  
## Consulte também  
 [Transação \(ODBC\)](../../data/odbc/transaction-odbc.md)   
 [Transação: como as transações afetam atualizações \(ODBC\)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)   
 [Classe de CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)
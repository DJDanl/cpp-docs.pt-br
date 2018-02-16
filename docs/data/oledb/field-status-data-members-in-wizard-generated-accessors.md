---
title: Campo de membros de dados de Status em acessadores gerados por assistente | Microsoft Docs
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
- OLE DB consumer templates, field status
- field status in OLE DB templates
ms.assetid: 66e4e223-c60c-471e-860d-d23abcdfe371
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ab099689af725c2b074f4caf4d2e9b13d16fbaf2
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="field-status-data-members-in-wizard-generated-accessors"></a>Membros de dados do status de campo em acessadores gerados por assistente
Quando você usar o Assistente de ATL OLE DB consumidor para criar um consumidor, o assistente gera um membro de dados na classe de registro de usuário para cada campo que você especificar em seu mapa de coluna. Cada membro de dados é do tipo `DWORD` e contém um valor de status correspondentes ao seu respectivo campo.  
  
 Por exemplo, para um membro de dados *m_OwnerID*, o assistente gera um membro de dados adicionais para o status de campo (*dwOwnerIDStatus*) e outra para o tamanho do campo (*dwOwnerIDLength*). Ela também gera um mapa de coluna com `COLUMN_ENTRY_LENGTH_STATUS` entradas.  
  
 Isso é mostrado no código a seguir:  
  
```  
[db_source("insert connection string")]  
[db_command(" \  
   SELECT \  
      Au_ID, \  
      Author, \  
      `Year Born`, \  
      FROM Authors")]  
  
class CAuthors  
{  
public:  
  
   // The following wizard-generated data members contain status   
   // values for the corresponding fields in the column map. You   
   // can use these values to hold NULL values that the database   
   // returns or to hold error information when the compiler returns   
   // errors. See "Field Status Data Members in Wizard-Generated   
   // Accessors" in the Visual C++ documentation for more information   
   // on using these fields.  
   DWORD m_dwAuIDStatus;  
   DWORD m_dwAuthorStatus;  
   DWORD m_dwYearBornStatus;  
  
   // The following wizard-generated data members contain length  
   // values for the corresponding fields in the column map.  
   DWORD m_dwAuIDLength;  
   DWORD m_dwAuthorLength;  
   DWORD m_dwYearBornLength;  
  
BEGIN_COLUMN_MAP(CAuthorsAccessor)  
   COLUMN_ENTRY_LENGTH_STATUS(1, m_AuID, dwAuIDLength, dwAuIDStatus)  
   COLUMN_ENTRY_LENGTH_STATUS(2, m_Author, dwAuthorLength, dwAuthorStatus)  
   COLUMN_ENTRY_LENGTH_STATUS(3, m_YearBorn, dwYearBornLength, dwYearBornStatus)  
END_COLUMN_MAP()  
  
   [ db_column(1, status=m_dwAuIDStatus, length=m_dwAuIDLength) ] LONG m_AuID;  
   [ db_column(2, status=m_dwAuthorStatus, length=m_dwAuthorLength) ] TCHAR m_Author[51];  
   [ db_column(3, status=m_dwYearBornStatus, length=m_dwYearBornLength) ] SHORT m_YearBorn;  
  
   void GetRowsetProperties(CDBPropSet* pPropSet)  
   {  
      pPropSet->AddProperty(DBPROP_IRowsetChange, true);  
      pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);  
   }  
};  
```  
  
> [!NOTE]
>  Se você modificar a classe de registro de usuário ou gravar seu próprio cliente, as variáveis de dados devem vir antes das variáveis de status e comprimento.  
  
 Você pode usar os valores de status para fins de depuração. Se o código gerado pelo Assistente de ATL OLE DB consumidor gera erros de compilação como **DB_S_ERRORSOCCURRED** ou **DB_E_ERRORSOCCURRED**, você deve primeiro examinar os valores atuais de status de campo membros de dados. Aqueles que têm valores diferentes de zero correspondem às colunas incorretas.  
  
 Você também pode usar os valores de status para definir um valor NULL para um determinado campo. Isso ajuda a casos em que você deseja diferenciar um valor de campo como NULL em vez de zero. Cabe a você decidir se NULL é um valor válido ou um valor especial e decidir como seu aplicativo deve tratá-la. OLE DB define **DBSTATUS_S_ISNULL** como o meio correto de especificar um valor NULL de genérico. Se o consumidor lê os dados e o valor for nulo, o campo de status é definido como **DBSTATUS_S_ISNULL**. Se o consumidor deseja definir um valor NULL, o consumidor define o valor de status **DBSTATUS_S_ISNULL** antes de chamar o provedor.  
  
 Em seguida, abra o OLEDB e procurar **DBSTATUSENUM**. Em seguida, você pode corresponder o valor numérico do status diferente de zero em relação a **DBSTATUSENUM** valores de enumeração. Se o nome de enumeração não é suficiente para informar o que há de errado, consulte o tópico "Status" na seção "Valores de dados de associação" o [guia do programador do DB OLE](http://go.microsoft.com/fwlink/p/?linkid=121548). Este tópico contém tabelas de valores de status usados ao obter ou definir dados. Para obter informações sobre valores de comprimento, consulte o tópico "Comprimento" na mesma seção.  
  
## <a name="retrieving-the-length-or-status-of-a-column"></a>Recuperando o Status de uma coluna ou o comprimento  
 Você pode recuperar o status de uma coluna ou o comprimento de uma coluna de comprimento variável (para verificar se há **DBSTATUS_S_ISNULL**, por exemplo):  
  
-   Para obter o comprimento, use o `COLUMN_ENTRY_LENGTH` macro.  
  
-   Para obter o status, use o `COLUMN_ENTRY_STATUS` macro.  
  
-   Para obter ambos, use `COLUMN_ENTRY_LENGTH_STATUS`, conforme mostrado abaixo.  
  
```  
class CProducts  
{  
public:  
   char      szName[40];  
   long      nNameLength;  
   DBSTATUS   nNameStatus;  
  
BEGIN_COLUMN_MAP(CProducts)  
// Bind the column to CProducts.m_ProductName.  
// nOrdinal is zero-based, so the column number of m_ProductName is 1.  
   COLUMN_ENTRY_LENGTH_STATUS(1, szName, nNameLength, nNameStatus)  
END_COLUMN_MAP()  
};  
  
CTable<CAccessor<CProducts >> product;  
  
product.Open(session, "Product");  

while (product.MoveNext() == S_OK)  
{  
   // Check the product name isn't NULL before tracing it  
   if (product.nNameStatus == DBSTATUS_S_OK)  
      ATLTRACE("%s is %d characters\n", szName, nNameLength);  
}  
```  
  
 Quando você usa `CDynamicAccessor`, o comprimento e o status associados para você automaticamente. Para recuperar os valores de comprimento e o status, use o `GetLength` e **GetStatus** funções de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)
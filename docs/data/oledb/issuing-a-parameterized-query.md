---
title: "Emitindo uma consulta parametrizada | Microsoft Docs"
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
  - "consultas de parâmetros, executando com a classe CCommand"
ms.assetid: aedb0fce-52a4-4c97-a5c9-b2114be6c3b0
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Emitindo uma consulta parametrizada
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O exemplo a seguir emite uma consulta parametrizada simples que recupera registros com um campo de idade \(que é maior que 30\) de uma tabela em uma base de dados do Microsoft Access.  Para oferecer suporte ao parâmetro, o registro de usuário deve ter um mapa adicional.  O código a seguir, em um projeto de ATL, use a classe de `CCommand` em vez da classe de `CTable` usada no exemplo anterior, [Por meio de um conjunto de linhas simples](../Topic/Traversing%20a%20Simple%20Rowset.md).  
  
```  
#include <atldbcli.h>  
  
CDataSource connection;  
CSession session;  
CCommand<CAccessor<CArtists> > artists;  
  
// Open the connection, session, and table, specifying authentication   
// using Windows NT integrated security. Hard-coding a password is a major   
// security weakness.  
connection.Open(CLSID_MSDASQL, "NWind", NULL, NULL,   
DBPROP_AUTH_INTEGRATED);  
session.Open(connection);  
  
// Set the parameter for the query  
artists.m_nAge = 30;  
artists.Open(session, "select * from artists where age > ?");  
  
// Get data from the rowset  
while (artists.MoveNext() == S_OK)  
{  
   cout << artists.m_szFirstName;  
   cout << artists.m_szLastName;  
}  
```  
  
 O registro do usuário, `CArtists`, poderia ficar assim:  
  
```  
class CArtists  
{  
public:  
// Data Elements  
   CHAR m_szFirstName[20];  
   CHAR m_szLastName[30];  
   short m_nAge;  
  
// Column binding map  
BEGIN_COLUMN_MAP(CArtists)  
   COLUMN_ENTRY(1, m_szFirstName)  
   COLUMN_ENTRY(2, m_szLastName)  
   COLUMN_ENTRY(3, m_nAge)  
END_COLUMN_MAP()  
  
// Parameter binding map  
BEGIN_PARAM_MAP(CArtists)  
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(1, m_nAge)  
END_PARAM_MAP()  
};  
```  
  
## Consulte também  
 [Trabalhando com modelos de consumidor de banco de dados OLE](../../data/oledb/working-with-ole-db-consumer-templates.md)
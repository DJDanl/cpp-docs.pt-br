---
title: "Simplificando acesso a dados com atributos de banco de dados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc-attr.db_param"
  - "vc-attr.db_column"
  - "vc-attr.db_accessor"
  - "vc-attr.db_command"
  - "vc-attr.db_table"
  - "vc-attr.db_source"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "atributos [C++], acesso a dados"
  - "atributos [C++], Banco de dados"
  - "atributos [C++], consumidor OLE DB"
  - "dados [C++], simplificando o acesso"
  - "acesso a dados [C++], atributos de banco de dados"
  - "atributos de banco de dados [C++]"
  - "bancos de dados [C++], atributos"
  - "consumidores OLE DB [C++], atributos de banco de dados"
ms.assetid: 560d2456-e307-4cb7-ba7b-4d0ed674697f
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Simplificando acesso a dados com atributos de banco de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico demonstra o uso de atributos da base de dados simplificar operações de base de dados.  
  
 A forma básica de acessar informações de um base de dados é criar uma classe command \(ou tabela\) e uma classe de registro de usuário para uma determinada tabela no base de dados.  Os atributos da base de dados são algumas das declarações de modelo que você anteriormente precisou fazer.  
  
 Para demonstrar o uso de atributos da base de dados, equivalente a tabela a seguir mostram dois seções e declarações da classe de registro do usuário: o primeiro usa os atributos e o segundo usa modelos OLE DB.  Esse código de declaração normalmente é colocado em um arquivo de cabeçalho nomeado para o objeto da tabela ou do comando, por exemplo, Authors.h.  
  
 Comparando os dois arquivos, você pode consultar quanto mais simples é usar atributos.  Entre as diferenças são:  
  
-   Usando atributos, você só precisa declarar uma classe: `CAuthors`, quando com modelos você tenha que declare dois: `CAuthorsNoAttrAccessor` e `CAuthorsNoAttr`.  
  
-   A chamada de `db_source` na versão atribuída é equivalente à chamada de `OpenDataSource()` na declaração do modelo.  
  
-   A chamada de **db\_table** na versão atribuída é equivalente à seguinte declaração do modelo:  
  
    ```  
    class CAuthorsNoAttr : public CTable<CAccessor<CAuthorsNoAttrAccessor> >  
    ```  
  
-   As chamadas de **db\_column** na versão atribuída são equivalentes no mapa da coluna \(consulte\) `BEGIN_COLUMN_MAP ... END_COLUMN_MAP`na declaração do modelo.  
  
 Os atributos injetam uma declaração de classe de registro do usuário para você.  A classe de registro do usuário é equivalente a `CAuthorsNoAttrAccessor` na declaração do modelo.  Se a sua classe de tabela é `CAuthors`, a classe de registro injetada do usuário é denominada `CAuthorsAccessor`, e você só pode exibir sua declaração no código SQL injetado.  Para obter mais informações, consulte “em atributo injetou classes de registro do usuário” em [Registros de usuário](../../data/oledb/user-records.md).  
  
 Observe que na alocada e o código templated, você deve definir propriedades de conjunto de linhas usando `CDBPropSet::AddProperty`.  
  
 Para obter informações sobre os atributos do discutidos neste tópico, consulte [Atributos do consumidor OLE DB](../../windows/ole-db-consumer-attributes.md).  
  
## Declaração de tabela e acessador usando atributos  
 Os seguintes `db_source` chamadas e **db\_table** de código na tabela de classificação.  `db_source` especifica a fonte de dados e a conexão a ser usada.  **db\_table** injeta código apropriada do modelo para declarar uma classe de tabela.  **db\_column** especifica o mapa da coluna e injeta a declaração do acessador.  Você pode usar atributos do consumidor OLE DB em qualquer projeto que ofereça suporte. ATL  
  
 Aqui está a declaração de tabela e acessador usando atributos:  
  
```  
//////////////////////////////////////////////////////////////////////  
// Table and accessor declaration using attributes  
// authors.h  
//////////////////////////////////////////////////////////////////////  
  
// Table class declaration  
// (Note that you must provide your own connection string for db_source.)  
[  
   db_source(L"your connection string"),  
   db_table("Authors")  
]  
class CAuthors  
{  
public:  
   DWORD m_dwAuIDStatus;  
   DWORD m_dwAuthorStatus;  
   DWORD m_dwYearBornStatus;  
   DWORD m_dwAuIDLength;  
   DWORD m_dwAuthorLength;  
   DWORD m_dwYearBornLength;  
   [ db_column(1, status=m_dwAuIDStatus, length=m_dwAuIDLength) ] LONG m_AuID;  
   [ db_column(2, status=m_dwAuthorStatus, length=m_dwAuthorLength) ] TCHAR m_Author[51];  
   [ db_column(3, status=m_dwYearBornStatus, length=m_dwYearBornLength) ] SHORT m_YearBorn;  
   void GetRowsetProperties(CDBPropSet* pPropSet)  
   {  
      pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true);  
      pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true);  
      pPropSet->AddProperty(DBPROP_IRowsetChange, true);  
   }  
};  
```  
  
## Declaração de tabela e acessador usando modelos  
 Aqui está a declaração de tabela e acessador usando modelos.  
  
```  
//////////////////////////////////////////////////////////////////////  
// Table and user record class declaration using templates  
// authors.h  
//////////////////////////////////////////////////////////////////////  
  
// User record class declaration  
class CAuthorsNoAttrAccessor  
{  
public:  
   DWORD m_dwAuIDStatus;  
   DWORD m_dwAuthorStatus;  
   DWORD m_dwYearBornStatus;  
   DWORD m_dwAuIDLength;  
   DWORD m_dwAuthorLength;  
   DWORD m_dwYearBornLength;  
   LONG m_AuID;  
   TCHAR m_Author[51];  
   SHORT m_YearBorn;  
   void GetRowsetProperties(CDBPropSet* pPropSet)  
   {  
      pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true);  
      pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true);  
      pPropSet->AddProperty(DBPROP_IRowsetChange, true);  
   }  
   HRESULT OpenDataSource()  
   {  
      CDataSource _db;  
      HRESULT hr;  
      hr = _db.OpenFromInitializationString(L"your connection string");  
      if (FAILED(hr))  
      {  
#ifdef _DEBUG  
         AtlTraceErrorRecords(hr);  
#endif  
         return hr;  
      }  
      return m_session.Open(_db);  
   }  
   void CloseDataSource()  
   {  
      m_session.Close();  
   }  
   operator const CSession&()  
   {  
      return m_session;  
   }  
   CSession m_session;  
   BEGIN_COLUMN_MAP(CAuthorsNoAttrAccessor)  
      COLUMN_ENTRY_LENGTH_STATUS(1, m_AuID, m_dwAuIDLength, m_dwAuIDStatus)  
      COLUMN_ENTRY_LENGTH_STATUS(2, m_Author, m_dwAuthorLength, m_dwAuthorStatus)  
      COLUMN_ENTRY_LENGTH_STATUS(3, m_YearBorn, m_dwYearBornLength, m_dwYearBornStatus)  
   END_COLUMN_MAP()  
};  
class CAuthorsNoAttr : public CTable<CAccessor<CAuthorsNoAttrAccessor> >  
{  
public:  
   HRESULT OpenAll()  
   {  
      HRESULT hr;  
      hr = OpenDataSource();  
      if (FAILED(hr))  
         return hr;  
      __if_exists(GetRowsetProperties)  
      {  
         CDBPropSet propset(DBPROPSET_ROWSET);  
         __if_exists(HasBookmark)  
         {  
            propset.AddProperty(DBPROP_IRowsetLocate, true);  
         }  
         GetRowsetProperties(&propset);  
         return OpenRowset(&propset);  
      }  
      __if_not_exists(GetRowsetProperties)  
      {  
         __if_exists(HasBookmark)  
         {  
            CDBPropSet propset(DBPROPSET_ROWSET);  
            propset.AddProperty(DBPROP_IRowsetLocate, true);  
            return OpenRowset(&propset);  
         }  
      }  
      return OpenRowset();  
   }  
   HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)  
   {  
      HRESULT hr = Open(m_session, "Authors", pPropSet);  
#ifdef _DEBUG  
      if(FAILED(hr))  
         AtlTraceErrorRecords(hr);  
#endif  
      return hr;  
   }  
   void CloseAll()  
   {  
      Close();  
      CloseDataSource();  
   }  
};  
```  
  
## Consulte também  
 [OLE DB Consumer Attributes](../../windows/ole-db-consumer-attributes.md)   
 [Attributes Walkthroughs](http://msdn.microsoft.com/pt-br/73df1d5d-261a-4521-98fb-06dcbf5ec0d0)
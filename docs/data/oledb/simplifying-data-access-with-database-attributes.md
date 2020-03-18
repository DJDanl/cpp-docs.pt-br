---
title: Simplificando acesso a dados com atributos de banco de dados
ms.date: 10/19/2018
helpviewer_keywords:
- attributes [C++], database
- attributes [C++], data access
- databases [C++], attributes
- data [C++], simplifying access
- data access [C++], database attributes
- database attributes [C++]
- OLE DB consumers [C++], database attributes
- attributes [C++], OLE DB consumer
ms.assetid: 560d2456-e307-4cb7-ba7b-4d0ed674697f
ms.openlocfilehash: 5fc30596058271523f64cc9108ee6f39eb5016fa
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444135"
---
# <a name="simplifying-data-access-with-database-attributes"></a>Simplificando acesso a dados com atributos de banco de dados

Este tópico demonstra o uso de atributos de banco de dados para simplificar operações de banco de dados.

A maneira básica de acessar informações de um banco de dados é criar uma classe de comando (ou tabela) e uma classe de registro de usuário para uma tabela específica no banco de dados. Os atributos do banco de dados simplificam algumas das declarações de modelo que você tinha que fazer anteriormente.

Para demonstrar o uso de atributos de banco de dados, as seções a seguir mostram duas declarações de classe de registro de usuário e tabela equivalentes: a primeira usa atributos e a segunda usa modelos de OLE DB. Esse código de declaração normalmente é colocado em um arquivo de cabeçalho chamado para a tabela ou objeto de comando, por exemplo, Authors. h.

Comparando os dois arquivos, você pode ver quanto mais simples é o uso de atributos. Entre as diferenças estão:

- Usando atributos, você só precisa declarar uma classe: `CAuthors`, enquanto com modelos você precisa declarar dois: `CAuthorsNoAttrAccessor` e `CAuthorsNoAttr`.

- A chamada `db_source` na versão atribuída é equivalente à chamada `OpenDataSource()` na declaração de modelo.

- A chamada `db_table` na versão atribuída é equivalente à seguinte declaração de modelo:

    ```cpp
    class CAuthorsNoAttr : public CTable<CAccessor<CAuthorsNoAttrAccessor>>
    ```

- As chamadas de `db_column` na versão atribuída são equivalentes ao mapa de coluna (consulte `BEGIN_COLUMN_MAP ... END_COLUMN_MAP`) na declaração de modelo.

Os atributos injetam uma declaração de classe de registro de usuário para você. A classe de registro de usuário é igual a `CAuthorsNoAttrAccessor` na declaração de modelo. Se a sua classe de tabela for `CAuthors`, a classe de registro de usuário injetado será nomeada `CAuthorsAccessor`e você só poderá exibir sua declaração no código injetado. Para obter mais informações, consulte "classes de registro de usuário injetadas de atributo" em [registros de usuário](../../data/oledb/user-records.md).

No código atribuído e no modelo, você deve definir propriedades de conjunto de linhas usando `CDBPropSet::AddProperty`.

Para obter informações sobre os atributos discutidos neste tópico, consulte [OLE DB atributos do consumidor](../../windows/ole-db-consumer-attributes.md).

> [!NOTE]
> As instruções de `include` a seguir são necessárias para compilar os exemplos abaixo:

> ```cpp
> #include <atlbase.h>
> #include <atlplus.h>
> #include <atldbcli.h>
> ```

## <a name="table-and-accessor-declaration-using-attributes"></a>Declaração de tabela e acessador usando atributos

O código a seguir chama `db_source` e `db_table` na classe da tabela. `db_source` especifica a fonte de dados e a conexão a ser usada. `db_table` injeta o código de modelo apropriado para declarar uma classe de tabela. `db_column` especificar o mapa de coluna e injetar a declaração de acessador. Você pode usar OLE DB atributos de consumidor em qualquer projeto que ofereça suporte à ATL.

Aqui está a declaração de tabela e acessador usando atributos:

```cpp
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
   DBSTATUS m_dwAuIDStatus;
   DBSTATUS m_dwAuthorStatus;
   DBSTATUS m_dwYearBornStatus;
   DBLENGTH m_dwAuIDLength;
   DBLENGTH m_dwAuthorLength;
   DBLENGTH m_dwYearBornLength;
   [db_column("1", status = "m_dwAuIDStatus", length = "m_dwAuIDLength")] LONG m_AuID;
   [db_column("2", status = "m_dwAuthorStatus", length = "m_dwAuthorLength")] TCHAR m_Author[51];
   [db_column("3", status = "m_dwYearBornStatus", length = "m_dwYearBornLength")] SHORT m_YearBorn;
   void GetRowsetProperties(CDBPropSet* pPropSet)
   {
      pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true);
      pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true);
      pPropSet->AddProperty(DBPROP_IRowsetChange, true);
   }
};
```

## <a name="table-and-accessor-declaration-using-templates"></a>Declaração de tabela e acessador usando modelos

Aqui está a declaração de tabela e acessador usando modelos.

```cpp
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
class CAuthorsNoAttr : public CTable<CAccessor<CAuthorsNoAttrAccessor>>
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

## <a name="see-also"></a>Consulte também

[Atributos de consumidor do OLE DB](../../windows/ole-db-consumer-attributes.md)

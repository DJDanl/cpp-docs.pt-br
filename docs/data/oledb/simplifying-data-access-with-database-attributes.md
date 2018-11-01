---
title: Simplificando acesso a dados com atributos de banco de dados
ms.date: 10/19/2018
f1_keywords:
- vc-attr.db_param
- vc-attr.db_column
- vc-attr.db_accessor
- vc-attr.db_command
- vc-attr.db_table
- vc-attr.db_source
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
ms.openlocfilehash: f31617959222e7abd3487263e32c5566fb9fb2ab
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50534820"
---
# <a name="simplifying-data-access-with-database-attributes"></a>Simplificando acesso a dados com atributos de banco de dados

Este tópico demonstra o uso de atributos de banco de dados para simplificar as operações de banco de dados.

A maneira básica de acessar informações de um banco de dados é criar uma classe de comando (ou tabela) e uma classe de registro de usuário para uma tabela específica no banco de dados. Os atributos de banco de dados simplificam algumas das declarações do modelo que você anteriormente tinha de fazer.

Para demonstrar o uso de atributos de banco de dados, as seções a seguir mostram dois tabela equivalente e declarações de classe de registro de usuário: o primeiro usa atributos e o segundo usa modelos OLE DB. Esse código de declaração normalmente é colocado em um arquivo de cabeçalho chamado para o objeto de tabela ou comando, por exemplo, Authors.h.

Comparando os dois arquivos, você pode ver como é muito mais simples é usar os atributos. Entre as diferenças são:

- Usando atributos, você só precisa declarar uma classe: `CAuthors`, enquanto com modelos é necessário declarar dois: `CAuthorsNoAttrAccessor` e `CAuthorsNoAttr`.

- O `db_source` chamada na versão atribuída é equivalente ao `OpenDataSource()` chamar na declaração de modelo.

- O `db_table` chamada em que a versão atribuída é equivalente à declaração de modelo a seguir:

    ```cpp
    class CAuthorsNoAttr : public CTable<CAccessor<CAuthorsNoAttrAccessor>>
    ```

- O `db_column` chamadas na versão atribuída são equivalentes ao mapa de coluna (consulte `BEGIN_COLUMN_MAP ... END_COLUMN_MAP`) na declaração de modelo.

Os atributos de injetam uma declaração de classe de registro de usuário para você. A classe de registro de usuário é igual a `CAuthorsNoAttrAccessor` na declaração de modelo. Se sua classe de tabela é `CAuthors`, a classe de registro do usuário injetada é chamada `CAuthorsAccessor`, e você só pode exibir sua declaração em código injetado. Para obter mais informações, consulte "Attribute-Injected Classes de registro de usuário" em [registros de usuário](../../data/oledb/user-records.md).

Tanto o atribuído e o código de modelo, você deve definir as propriedades do conjunto de linhas usando `CDBPropSet::AddProperty`.

Para obter informações sobre os atributos discutidos neste tópico, consulte [OLE DB atributos do consumidor](../../windows/ole-db-consumer-attributes.md).

> [!NOTE]
> O seguinte `include` instruções são necessárias para compilar os exemplos a seguir:
> ```cpp
> #include <atlbase.h>
> #include <atlplus.h>
> #include <atldbcli.h>
> ```

## <a name="table-and-accessor-declaration-using-attributes"></a>Tabela e a declaração do acessador usando atributos

O código a seguir chama `db_source` e `db_table` na classe da tabela. `db_source` Especifica a fonte de dados e a conexão a ser usado. `db_table` injeta o código de modelo apropriado para declarar uma classe de tabela. `db_column` especificar o mapa de coluna e inserir a declaração do acessador. Você pode usar atributos de consumidor do OLE DB em qualquer projeto que dá suporte a ATL.

Aqui está a declaração de tabela e o acessador usando atributos:

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

## <a name="table-and-accessor-declaration-using-templates"></a>Tabela e a declaração do acessador usando modelos

Aqui está a declaração de tabela e o acessador usando modelos.

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

---
title: Suporte do provedor para indicadores
ms.date: 11/04/2016
helpviewer_keywords:
- IRowsetLocate class, provider support for bookmarks
- OLE DB provider templates, bookmarks
- bookmarks, OLE DB
- IRowsetLocate class
- OLE DB providers, bookmark support
ms.assetid: 1b14ccff-4f76-462e-96ab-1aada815c377
ms.openlocfilehash: 326a52805cb78a3f31141d3eac6a0942a7fee477
ms.sourcegitcommit: 943c792fdabf01c98c31465f23949a829eab9aad
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2018
ms.locfileid: "51264717"
---
# <a name="provider-support-for-bookmarks"></a>Suporte do provedor para indicadores

O exemplo neste tópico adiciona o `IRowsetLocate` da interface para o `CCustomRowset` classe. Quase todos os casos, você começa pela adição de uma interface para um objeto COM existente. Em seguida, você pode testá-lo adicionando mais chamadas de modelos de consumidor. O exemplo demonstra como:

- Adicione uma interface para um provedor.

- Determine dinamicamente as colunas para retornar para o consumidor.

- Adicione suporte a indicadores.

A interface `IRowsetLocate` herda da interface `IRowset` . Para adicionar o `IRowsetLocate` interface, herdam `CCustomRowset` partir [IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md).

Adicionando o `IRowsetLocate` interface é um pouco diferente da maioria das interfaces. Para tornar a linha VTABLEs de backup, o OLE DB, modelos de provedor têm um parâmetro de modelo para lidar com a interface derivada. O código a seguir mostra a nova lista de herança:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

// CCustomRowset
class CCustomRowset : public CRowsetImpl< CCustomRowset,
      CTextData, CCustomCommand, CAtlArray<CTextData>,
      CSimpleRow,
          IRowsetLocateImpl<CCustomRowset, IRowsetLocate>>
```

O quarto, quinto e sexto parâmetros são adicionados. Este exemplo usa os padrões para o quarto e quintas parâmetros, mas especificarem `IRowsetLocateImpl` como o sexto parâmetro. `IRowsetLocateImpl` é uma classe de modelo de OLE DB que usa dois parâmetros de modelo: eles interligar o `IRowsetLocate` da interface para o `CCustomRowset` classe. Para adicionar a maioria das interfaces, você pode ignorar esta etapa e mover para o próximo. Somente o `IRowsetLocate` e `IRowsetScroll` interfaces precisam ser manipulados dessa maneira.

Em seguida, você precisa informar à `CCustomRowset` chamar `QueryInterface` para o `IRowsetLocate` interface. Adicione a linha `COM_INTERFACE_ENTRY(IRowsetLocate)` no mapa. O mapa de interface de `CCustomRowset` deve aparecer como mostrado no código a seguir:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

typedef CRowsetImpl< CCustomRowset, CTextData, CCustomCommand, CAtlArray<CTextData>, CSimpleRow, IRowsetLocateImpl<CCustomRowset, IRowsetLocate>> _RowsetBaseClass;

BEGIN_COM_MAP(CCustomRowset)
   COM_INTERFACE_ENTRY(IRowsetLocate)
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)
END_COM_MAP()
```

Você também precisa conectar seu mapa para o `CRowsetImpl` classe. Adicionar na macro COM_INTERFACE_ENTRY_CHAIN conectar no `CRowsetImpl` mapa. Além disso, crie um typedef chamado `RowsetBaseClass` que consiste em informações de herança. Este typedef é arbitrário e pode ser ignorado.

Por fim, lidar com o `IColumnsInfo::GetColumnsInfo` chamar. Você normalmente usa as macros PROVIDER_COLUMN_ENTRY para fazer isso. No entanto, um consumidor talvez queira usar indicadores. Você deve ser capaz de alterar as colunas que o provedor retorna dependendo se o consumidor solicita um indicador.

Para lidar com o `IColumnsInfo::GetColumnsInfo` chamar, excluir o mapa PROVIDER_COLUMN no `CTextData` classe. A macro PROVIDER_COLUMN_MAP define uma função `GetColumnInfo`. Definir seus próprios `GetColumnInfo` função. A declaração da função deve ter esta aparência:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.H

class CTextData
{
   ...
     // NOTE: Be sure you removed the PROVIDER_COLUMN_MAP!
   static ATLCOLUMNINFO* GetColumnInfo(CCustomRowset* pThis,
        ULONG* pcCols);
   static ATLCOLUMNINFO* GetColumnInfo(CCustomCommand* pThis,
        ULONG* pcCols);
...
};
```

Em seguida, implemente a `GetColumnInfo` funcionar a *personalizado*RS.cpp arquivos da seguinte maneira:

```cpp
////////////////////////////////////////////////////////////////////
// CustomRS.cpp

template <class TInterface>
ATLCOLUMNINFO* CommonGetColInfo(IUnknown* pPropsUnk, ULONG* pcCols)
{
   static ATLCOLUMNINFO _rgColumns[5];
   ULONG ulCols = 0;

   CComQIPtr<TInterface> spProps = pPropsUnk;

   CDBPropIDSet set(DBPROPSET_ROWSET);
   set.AddPropertyID(DBPROP_BOOKMARKS);
   DBPROPSET* pPropSet = NULL;
   ULONG ulPropSet = 0;
   HRESULT hr;

   if (spProps)
      hr = spProps->GetProperties(1, &set, &ulPropSet, &pPropSet);

   // Check the property flag for bookmarks, if it is set, set the
// zero ordinal entry in the column map with the bookmark
// information.

   if (pPropSet)
   {
      CComVariant var = pPropSet->rgProperties[0].vValue;
      CoTaskMemFree(pPropSet->rgProperties);
      CoTaskMemFree(pPropSet);

      if ((SUCCEEDED(hr) && (var.boolVal == VARIANT_TRUE)))
      {
         ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0,
                     sizeof(DWORD), DBTYPE_BYTES,
            0, 0, GUID_NULL, CAgentMan, dwBookmark,
                        DBCOLUMNFLAGS_ISBOOKMARK)
         ulCols++;
      }
   }

   // Next set the other columns up.
   ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Field1"), 1, 16, DBTYPE_STR,
          0xFF, 0xFF, GUID_NULL, CTextData, szField1)
   ulCols++;
   ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Field2"), 2, 16, DBTYPE_STR,
       0xFF, 0xFF, GUID_NULL, CTextData, szField2)
   ulCols++;

   if (pcCols != NULL)
      *pcCols = ulCols;

   return _rgColumns;
}

ATLCOLUMNINFO* CTextData::GetColumnInfo(CCustomCommand* pThis,
     ULONG* pcCols)
{
   return CommonGetColInfo<ICommandProperties>(pThis->GetUnknown(),
        pcCols);
}

ATLCOLUMNINFO* CAgentMan::GetColumnInfo(RUpdateRowset* pThis, ULONG* pcCols)
{
   return CommonGetColInfo<IRowsetInfo>(pThis->GetUnknown(), pcCols);
}
```

`GetColumnInfo` primeiro verifica para ver se uma propriedade chamada `DBPROP_IRowsetLocate` está definido. OLE DB tem propriedades para cada uma das interfaces opcionais desativar o objeto de conjunto de linhas. Se o consumidor deseja usar uma dessas interfaces opcionais, ele define uma propriedade como true. O provedor pode, em seguida, verifique se a propriedade e realizar ações especiais com base nele.

Em sua implementação, você pode obter a propriedade usando o ponteiro para o objeto de comando. O `pThis` ponteiro representa a classe de conjunto de linhas ou de comando. Como usar modelos aqui, você precisa passar isso como uma **void** ponteiro ou o código não compila.

Especifique uma matriz estática para manter as informações de coluna. Se o consumidor não deseja que a coluna de indicador, uma entrada na matriz é desperdiçada. É possível alocar dinamicamente essa matriz, mas seria necessário garantir que a destruí-la corretamente. Este exemplo define e usa as macros ADD_COLUMN_ENTRY e ADD_COLUMN_ENTRY_EX para inserir as informações na matriz. Você pode adicionar as macros para o *personalizado*RS. Arquivo de H, conforme mostrado no código a seguir:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

#define ADD_COLUMN_ENTRY(ulCols, name, ordinal, colSize, type, precision, scale, guid, dataClass, member) \
   _rgColumns[ulCols].pwszName = (LPOLESTR)name; \
   _rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \
   _rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \
   _rgColumns[ulCols].dwFlags = 0; \
   _rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \
   _rgColumns[ulCols].wType = (DBTYPE)type; \
   _rgColumns[ulCols].bPrecision = (BYTE)precision; \
   _rgColumns[ulCols].bScale = (BYTE)scale; \
   _rgColumns[ulCols].cbOffset = offsetof(dataClass, member);

#define ADD_COLUMN_ENTRY_EX(ulCols, name, ordinal, colSize, type, precision, scale, guid, dataClass, member, flags) \
   _rgColumns[ulCols].pwszName = (LPOLESTR)name; \
   _rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \
   _rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \
   _rgColumns[ulCols].dwFlags = flags; \
   _rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \
   _rgColumns[ulCols].wType = (DBTYPE)type; \
   _rgColumns[ulCols].bPrecision = (BYTE)precision; \
   _rgColumns[ulCols].bScale = (BYTE)scale; \
   _rgColumns[ulCols].cbOffset = offsetof(dataClass, member); \
   memset(&(_rgColumns[ulCols].columnid), 0, sizeof(DBID)); \
   _rgColumns[ulCols].columnid.uName.pwszName = (LPOLESTR)name;
```

Para testar o código no consumidor, você precisará fazer algumas alterações para o `OnRun` manipulador. A primeira alteração para a função é que você adicione código para adicionar uma propriedade ao conjunto de propriedades. O código define o `DBPROP_IRowsetLocate` propriedade como true, dizendo, portanto, o provedor que você deseja que a coluna de indicador. O `OnRun` código do manipulador deve aparecer da seguinte maneira:

```cpp
//////////////////////////////////////////////////////////////////////
// TestProv Consumer Application in TestProvDlg.cpp

void CTestProvDlg::OnRun()
{
   CCommand<CAccessor<CProvider>> table;
   CDataSource source;
   CSession   session;

   if (source.Open("Custom.Custom.1", NULL, NULL, NULL,
          NULL) != S_OK)
      return;

   if (session.Open(source) != S_OK)
      return;

   CDBPropSet propset(DBPROPSET_ROWSET);
   propset.AddProperty(DBPROP_IRowsetLocate, true);
   if (table.Open(session, _T("c:\\public\\testprf2\\myData.txt"),
          &propset) != S_OK)
      return;

   CBookmark<4> tempBookmark;
   ULONG ulCount=0;
   while (table.MoveNext() == S_OK)
   {

      DBCOMPARE compare;
      if (ulCount == 2)
         tempBookmark = table.bookmark;

HRESULT hr = table.Compare(table.dwBookmark, table.dwBookmark,
                 &compare);
      if (FAILED(hr))
         ATLTRACE(_T("Compare failed: 0x%X\n"), hr);
      else
         _ASSERTE(compare == DBCOMPARE_EQ);

      m_ctlString1.AddString(table.szField1);
      m_ctlString2.AddString(table.szField2);
      ulCount++;
   }

   table.MoveToBookmark(tempBookmark);
   m_ctlString1.AddString(table.szField1);
   m_ctlString2.AddString(table.szField2);
}
```

O **enquanto** loop contém código para chamar o `Compare` método no `IRowsetLocate` interface. O código que você precisa sempre deve passar porque você está comparando indicadores mesmos exatos. Além disso, armazenar um indicador em uma variável temporária para que possa usá-lo após o **enquanto** loop for concluído para chamar o `MoveToBookmark` função nos modelos de consumidor. O `MoveToBookmark` chamadas de função do `GetRowsAt` método na `IRowsetLocate`.

Você também precisará atualizar o registro do usuário no consumidor. Adicione uma entrada na classe para lidar com um indicador e uma entrada no COLUMN_MAP:

```cpp
///////////////////////////////////////////////////////////////////////
// TestProvDlg.cpp

class CProvider
{
// Attributes
public:
   CBookmark<4>    bookmark;  // Add this line
   char   szCommand[16];
   char   szText[256];

   // Binding Maps
BEGIN_ACCESSOR_MAP(CProvider, 1)
   BEGIN_ACCESSOR(0, true)   // auto accessor
      BOOKMARK_ENTRY(bookmark)  // Add this line
      COLUMN_ENTRY(1, szField1)
      COLUMN_ENTRY(2, szField2)
   END_ACCESSOR()
END_ACCESSOR_MAP()
};
```

Quando você atualizou o código, você deve ser capaz de compilar e executar o provedor com o `IRowsetLocate` interface.

## <a name="see-also"></a>Consulte também

[Técnicas de provedor avançadas](../../data/oledb/advanced-provider-techniques.md)
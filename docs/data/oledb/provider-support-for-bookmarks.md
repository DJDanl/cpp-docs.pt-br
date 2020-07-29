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
ms.openlocfilehash: 240cb4da03d6c8c1958b7a86e78171aca2dc30e9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216447"
---
# <a name="provider-support-for-bookmarks"></a>Suporte do provedor para indicadores

O exemplo neste tópico adiciona a `IRowsetLocate` interface à `CCustomRowset` classe. Em quase todos os casos, você começa adicionando uma interface a um objeto COM existente. Em seguida, você pode testá-lo adicionando mais chamadas dos modelos de consumidor. O exemplo demonstra como:

- Adicione uma interface a um provedor.

- Determine dinamicamente as colunas a serem retornadas ao consumidor.

- Adicionar suporte a indicadores.

A interface `IRowsetLocate` herda da interface `IRowset` . Para adicionar a `IRowsetLocate` interface, herde `CCustomRowset` de [IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md).

Adicionar a `IRowsetLocate` interface é um pouco diferente da maioria das interfaces. Para tornar a linha VTABLEs ativa, os modelos de provedor de OLE DB têm um parâmetro de modelo para manipular a interface derivada. O código a seguir mostra a nova lista de herança:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

// CCustomRowset
class CCustomRowset : public CRowsetImpl< CCustomRowset,
      CTextData, CCustomCommand, CAtlArray<CTextData>,
      CSimpleRow,
          IRowsetLocateImpl<CCustomRowset, IRowsetLocate>>
```

Os quarto, quinto e sexto parâmetros são todos adicionados. Este exemplo usa os padrões para o quarto e o quinto parâmetros, mas especifica `IRowsetLocateImpl` como o sexto parâmetro. `IRowsetLocateImpl`é uma classe de modelo de OLE DB que usa dois parâmetros de modelo: eles vinculam a `IRowsetLocate` interface à `CCustomRowset` classe. Para adicionar a maioria das interfaces, você pode ignorar esta etapa e mover para a próxima. Somente as `IRowsetLocate` `IRowsetScroll` interfaces e precisam ser manipuladas dessa maneira.

Em seguida, você precisa dizer ao `CCustomRowset` para chamar a `QueryInterface` `IRowsetLocate` interface. Adicione a linha `COM_INTERFACE_ENTRY(IRowsetLocate)` ao mapa. O mapa de interface para `CCustomRowset` deve aparecer como mostrado no código a seguir:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

typedef CRowsetImpl< CCustomRowset, CTextData, CCustomCommand, CAtlArray<CTextData>, CSimpleRow, IRowsetLocateImpl<CCustomRowset, IRowsetLocate>> _RowsetBaseClass;

BEGIN_COM_MAP(CCustomRowset)
   COM_INTERFACE_ENTRY(IRowsetLocate)
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)
END_COM_MAP()
```

Você também precisa vincular o mapa à `CRowsetImpl` classe. Adicione na macro COM_INTERFACE_ENTRY_CHAIN para conectar-se ao `CRowsetImpl` mapa. Além disso, crie um typedef chamado `RowsetBaseClass` que consiste nas informações de herança. Este typedef é arbitrário e pode ser ignorado.

Por fim, manipule a `IColumnsInfo::GetColumnsInfo` chamada. Normalmente, você usaria as macros PROVIDER_COLUMN_ENTRY para fazer isso. No entanto, um consumidor pode querer usar indicadores. Você deve ser capaz de alterar as colunas que o provedor retorna, dependendo se o consumidor solicita um indicador.

Para tratar a `IColumnsInfo::GetColumnsInfo` chamada, exclua o mapa de PROVIDER_COLUMN na `CTextData` classe. A macro PROVIDER_COLUMN_MAP define uma função `GetColumnInfo` . Defina sua própria `GetColumnInfo` função. A declaração da função deve ser assim:

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

Em seguida, implemente a `GetColumnInfo` função no arquivo RS. cpp *personalizado*da seguinte maneira:

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

`GetColumnInfo`o primeiro verifica se uma propriedade chamada `DBPROP_IRowsetLocate` está definida. OLE DB tem propriedades para cada uma das interfaces opcionais do objeto Rowset. Se o consumidor quiser usar uma dessas interfaces opcionais, ele definirá uma propriedade como true. O provedor pode, então, verificar essa propriedade e tomar uma ação especial com base nela.

Em sua implementação, você obtém a propriedade usando o ponteiro para o objeto de comando. O `pThis` ponteiro representa o conjunto de linhas ou a classe de comando. Como você usa modelos aqui, você precisa passar isso como um **`void`** ponteiro ou o código não é compilado.

Especifique uma matriz estática para manter as informações da coluna. Se o consumidor não quiser a coluna de indicadores, uma entrada na matriz será desperdiçada. Você pode alocar essa matriz dinamicamente, mas precisará se certificar de destruí-la corretamente. Este exemplo define e usa as macros ADD_COLUMN_ENTRY e ADD_COLUMN_ENTRY_EX para inserir as informações na matriz. Você pode adicionar as macros ao RS *personalizado*. Arquivo H, conforme mostrado no código a seguir:

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

Para testar o código no consumidor, você precisa fazer algumas alterações no `OnRun` manipulador. A primeira alteração na função é que você adiciona código para adicionar uma propriedade ao conjunto de propriedades. O código define a `DBPROP_IRowsetLocate` propriedade como true, informando assim o provedor que você deseja que a coluna de indicadores. O `OnRun` código do manipulador deve aparecer da seguinte maneira:

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

O **`while`** loop contém o código para chamar o `Compare` método na `IRowsetLocate` interface. O código que você deve sempre passar porque está comparando exatamente os mesmos indicadores. Além disso, armazene um indicador em uma variável temporária para que você possa usá-lo depois que o **`while`** loop for concluído para chamar a `MoveToBookmark` função nos modelos de consumidor. A `MoveToBookmark` função chama o `GetRowsAt` método em `IRowsetLocate` .

Você também precisa atualizar o registro de usuário no consumidor. Adicione uma entrada na classe para manipular um indicador e uma entrada no COLUMN_MAP:

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

Quando você atualizou o código, você deve ser capaz de criar e executar o provedor com a `IRowsetLocate` interface.

## <a name="see-also"></a>Confira também

[Técnicas de provedor avançado](../../data/oledb/advanced-provider-techniques.md)

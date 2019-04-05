---
title: Determinando dinamicamente colunas retornadas ao consumidor
ms.date: 10/26/2018
helpviewer_keywords:
- bookmarks [C++], dynamically determining columns
- dynamically determining columns [C++]
ms.assetid: 58522b7a-894e-4b7d-a605-f80e900a7f5f
ms.openlocfilehash: 81353581d22f3d075fd19d783591ec856c21e241
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037653"
---
# <a name="dynamically-determining-columns-returned-to-the-consumer"></a>Determinando dinamicamente colunas retornadas ao consumidor

As macros PROVIDER_COLUMN_ENTRY lidar normalmente com o `IColumnsInfo::GetColumnsInfo` chamar. No entanto, como um consumidor pode optar por usar indicadores, o provedor deve ser capaz de alterar as colunas retornadas, dependendo se o consumidor solicita um indicador.

Para lidar com o `IColumnsInfo::GetColumnsInfo` chamar, exclua o PROVIDER_COLUMN_MAP, que define uma função `GetColumnInfo`, da `CCustomWindowsFile` registro do usuário no *personalizado*RS.h e substituí-lo com a definição para seu próprio `GetColumnInfo` função:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.H
class CCustomWindowsFile
{
public:
   DWORD dwBookmark;
   static const int iSize = 256;
   TCHAR szCommand[iSize];
   TCHAR szText[iSize];
   TCHAR szCommand2[iSize];
   TCHAR szText2[iSize];
  
   static ATLCOLUMNINFO* GetColumnInfo(void* pThis, ULONG* pcCols);
   bool operator==(const CCustomWindowsFile& am)
   {
      return (lstrcmpi(szCommand, am.szCommand) == 0);
   }
};
```

Em seguida, implementar o `GetColumnInfo` funcionar *personalizado*RS.cpp, conforme mostrado no código a seguir.

`GetColumnInfo` verifica primeiro se a propriedade do OLE DB `DBPROP_BOOKMARKS` está definido. Para obter a propriedade `GetColumnInfo` usa um ponteiro (`pRowset`) para o objeto de conjunto de linhas. O `pThis` ponteiro representa a classe que criou o conjunto de linhas, que é a classe em que o mapa de propriedade é armazenado. `GetColumnInfo` typecasts a `pThis` ponteiro para um `RCustomRowset` ponteiro.

Para verificar se há o `DBPROP_BOOKMARKS` propriedade, `GetColumnInfo` usa o `IRowsetInfo` interface, que pode ser obtido chamando `QueryInterface` sobre o `pRowset` interface. Como alternativa, você pode usar uma ATL [CComQIPtr](../../atl/reference/ccomqiptr-class.md) método em vez disso.

```cpp
////////////////////////////////////////////////////////////////////
// CustomRS.cpp
ATLCOLUMNINFO* CCustomWindowsFile::GetColumnInfo(void* pThis, ULONG* pcCols)
{
   static ATLCOLUMNINFO _rgColumns[5];
   ULONG ulCols = 0;
  
   // Check the property flag for bookmarks; if it is set, set the zero 
   // ordinal entry in the column map with the bookmark information.
   CCustomRowset* pRowset = (CCustomRowset*) pThis;
   CComQIPtr<IRowsetInfo, &IID_IRowsetInfo> spRowsetProps = pRowset;
  
   CDBPropIDSet set(DBPROPSET_ROWSET);
   set.AddPropertyID(DBPROP_BOOKMARKS);
   DBPROPSET* pPropSet = NULL;
   ULONG ulPropSet = 0;
   HRESULT hr;
  
   if (spRowsetProps)
      hr = spRowsetProps->GetProperties(1, &set, &ulPropSet, &pPropSet);
  
   if (pPropSet)
   {
      CComVariant var = pPropSet->rgProperties[0].vValue;
      CoTaskMemFree(pPropSet->rgProperties);
      CoTaskMemFree(pPropSet);
  
      if (SUCCEEDED(hr) && (var.boolVal == VARIANT_TRUE))
      {
         ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0, sizeof(DWORD), 
         DBTYPE_BYTES, 0, 0, GUID_NULL, CCustomWindowsFile, dwBookmark, 
         DBCOLUMNFLAGS_ISBOOKMARK)
         ulCols++;
      }
   }
  
   // Next, set the other columns up.
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Command"), 1, 256, DBTYPE_STR, 0xFF, 0xFF, 
      GUID_NULL, CCustomWindowsFile, szCommand)
   ulCols++;
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Text"), 2, 256, DBTYPE_STR, 0xFF, 0xFF, 
      GUID_NULL, CCustomWindowsFile, szText)
   ulCols++;
  
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Command2"), 3, 256, DBTYPE_STR, 0xFF, 0xFF, 
      GUID_NULL, CCustomWindowsFile, szCommand2)
   ulCols++;
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Text2"), 4, 256, DBTYPE_STR, 0xFF, 0xFF, 
      GUID_NULL, CCustomWindowsFile, szText2)
   ulCols++;
  
   if (pcCols != NULL)
      *pcCols = ulCols;
  
   return _rgColumns;
}
```

Este exemplo usa uma matriz estática para conter as informações de coluna. Se o consumidor não deseja que a coluna de indicador, uma entrada na matriz é não utilizada. Para lidar com as informações, você deve criar duas macros a matriz: ADD_COLUMN_ENTRY e ADD_COLUMN_ENTRY_EX. ADD_COLUMN_ENTRY_EX aceita um parâmetro extra, *sinalizadores*, que é necessário se você designar uma coluna de indicador.

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

No `GetColumnInfo` função, a macro de indicador é usada da seguinte forma:

```cpp
ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0, sizeof(DWORD),
   DBTYPE_BYTES, 0, 0, GUID_NULL, CAgentMan, dwBookmark,
   DBCOLUMNFLAGS_ISBOOKMARK)
```

Agora você pode compilar e executar o provedor aprimorado. Para testar o provedor, modifique o consumidor de teste, conforme descrito na [implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md). Execute o consumidor de teste com o provedor e verifique se que o consumidor de teste recupera as cadeias de caracteres apropriadas do provedor.

## <a name="see-also"></a>Consulte também

[Melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)<br/>

---
title: "Determinando dinamicamente colunas retornadas ao consumidor | Microsoft Docs"
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
  - "indicadores [C++], determinando colunas dinamicamente"
  - "determinando colunas dinamicamente [C++]"
ms.assetid: 58522b7a-894e-4b7d-a605-f80e900a7f5f
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Determinando dinamicamente colunas retornadas ao consumidor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Macros de PROVIDER\_COLUMN\_ENTRY tratam normalmente a chamada de **IColumnsInfo::GetColumnsInfo** .  Porém, como um consumidor pode optar por usar indicadores, o provedor deve poder alterar as colunas retornadas dependendo se o consumidor solicita um medidor.  
  
 Para controlar a chamada de **IColumnsInfo::GetColumnsInfo** , para excluir o PROVIDER\_COLUMN\_MAP, que define uma função `GetColumnInfo`, do registro de usuário de `CAgentMan` em MyProviderRS.h e substitua\-o pela definição para sua própria função de `GetColumnInfo` :  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.H  
class CAgentMan  
{  
public:  
   DWORD dwBookmark;  
   TCHAR szCommand[256];  
   TCHAR szText[256];  
   TCHAR szCommand2[256];  
   TCHAR szText2[256];  
  
   static ATLCOLUMNINFO* GetColumnInfo(void* pThis, ULONG* pcCols);  
   bool operator==(const CAgentMan& am)  
   {  
      return (lstrcmpi(szCommand, am.szCommand) == 0);  
   }  
  
};  
```  
  
 Em seguida, implementa a função de `GetColumnInfo` em MyProviderRS.cpp, conforme mostrado no seguinte código.  
  
 `GetColumnInfo` verificará primeiramente se a propriedade **DBPROP\_BOOKMARKS** OLE DB é definida.  Para obter a propriedade, `GetColumnInfo` usa um ponteiro \(\)`pRowset`o objeto do conjunto de linhas.  O ponteiro de `pThis` representa a classe que criou o conjunto de linhas, que é a classe no mapa de propriedade é armazenado.  `GetColumnInfo` typecasts o ponteiro de `pThis` a um ponteiro de `RMyProviderRowset` .  
  
 Para verificar a propriedade de **DBPROP\_BOOKMARKS** , `GetColumnInfo` usa a interface de `IRowsetInfo` , que você pode obter chamando `QueryInterface` na interface de `pRowset` .  Como alternativa, você pode usar um método de ATL [CComQIPtr](../../atl/reference/ccomqiptr-class.md) em vez disso.  
  
```  
////////////////////////////////////////////////////////////////////  
// MyProviderRS.cpp  
ATLCOLUMNINFO* CAgentMan::GetColumnInfo(void* pThis, ULONG* pcCols)  
{  
   static ATLCOLUMNINFO _rgColumns[5];  
   ULONG ulCols = 0;  
  
   // Check the property flag for bookmarks; if it is set, set the zero   
   // ordinal entry in the column map with the bookmark information.  
   CAgentRowset* pRowset = (CAgentRowset*) pThis;  
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
         DBTYPE_BYTES, 0, 0, GUID_NULL, CAgentMan, dwBookmark,   
         DBCOLUMNFLAGS_ISBOOKMARK)  
         ulCols++;  
      }  
   }  
  
   // Next, set the other columns up.  
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Command"), 1, 256, DBTYPE_STR, 0xFF, 0xFF,   
      GUID_NULL, CAgentMan, szCommand)  
   ulCols++;  
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Text"), 2, 256, DBTYPE_STR, 0xFF, 0xFF,   
      GUID_NULL, CAgentMan, szText)  
   ulCols++;  
  
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Command2"), 3, 256, DBTYPE_STR, 0xFF, 0xFF,   
      GUID_NULL, CAgentMan, szCommand2)  
   ulCols++;  
   ADD_COLUMN_ENTRY(ulCols, OLESTR("Text2"), 4, 256, DBTYPE_STR, 0xFF, 0xFF,   
      GUID_NULL, CAgentMan, szText2)  
   ulCols++;  
  
   if (pcCols != NULL)  
      *pcCols = ulCols;  
  
   return _rgColumns;  
}  
```  
  
 Este exemplo usa uma matriz estático para conter informações da coluna.  Se o consumidor não quiser que a coluna do indicador, uma entrada na matriz não é usado.  Para manipular informações, você cria dois macros de matriz: ADD\_COLUMN\_ENTRY e ADD\_COLUMN\_ENTRY\_EX.  ADD\_COLUMN\_ENTRY\_EX assume um parâmetro adicional, `flags`, que é necessário se você designar uma coluna de indicador.  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
  
#define ADD_COLUMN_ENTRY(ulCols, name, ordinal, colSize, type, precision,   
scale, guid, dataClass, member) \  
   _rgColumns[ulCols].pwszName = (LPOLESTR)name; \  
   _rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \  
   _rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \  
   _rgColumns[ulCols].dwFlags = 0; \  
   _rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \  
   _rgColumns[ulCols].wType = (DBTYPE)type; \  
   _rgColumns[ulCols].bPrecision = (BYTE)precision; \  
   _rgColumns[ulCols].bScale = (BYTE)scale; \  
   _rgColumns[ulCols].cbOffset = offsetof(dataClass, member);  
  
#define ADD_COLUMN_ENTRY_EX(ulCols, name, ordinal, colSize, type,   
precision, scale, guid, dataClass, member, flags) \  
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
  
 Na função de `GetColumnInfo` , a macro do medidor é usado como este:  
  
```  
ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0, sizeof(DWORD),  
   DBTYPE_BYTES, 0, 0, GUID_NULL, CAgentMan, dwBookmark,   
   DBCOLUMNFLAGS_ISBOOKMARK)  
```  
  
 Agora você pode criar e executar o provedor aprimorado.  Para testar o provedor, modifique o consumidor de teste como descrito em [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md).  Execute o consumidor de teste com o provedor.  Verifique se o consumidor de teste recupera as cadeias de caracteres adequadas do provedor quando você clica no botão de **Executar** na caixa de diálogo de **Test Consumer** .  
  
## Consulte também  
 [Melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)
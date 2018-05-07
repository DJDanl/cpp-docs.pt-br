---
title: Colunas de associação dinâmicas no provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- columns [C++], dynamic column binding
- dynamic column binding
- providers [C++], dynamic column binding
ms.assetid: 45e811e3-f5a7-4627-98cc-bf817c4e556e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 566a7248fabc1fcdb66224ccbc302e3f8038c5f6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="dynamically-binding-columns-in-your-provider"></a>Colunas de associação dinâmicas no provedor
Verifique se que você realmente precisa de associação de coluna dinâmica. Pode ser necessário porque:  
  
-   As colunas do conjunto de linhas não são definidas em tempo de compilação.  
  
-   Suporte a um elemento como indicadores que adiciona colunas.  
  
### <a name="to-implement-dynamic-column-binding"></a>Para implementar a associação de coluna dinâmica  
  
1.  Remova qualquer **PROVIDER_COLUMN_MAP**s no seu código.  
  
2.  No registro de usuário (a estrutura), adicione a declaração a seguir:  
  
    ```  
    static ATLCOLUMNINFO* GetColumnInfo(void* pThis, ULONG* pcCols);  
    ```  
  
3.  Implementar o `GetColumnInfo` função. Essa função apresenta como as informações são armazenadas. Talvez seja necessário obter propriedades ou outras informações para esta função. Talvez você queira criar uma macro, como o [COLUMN_ENTRY](../../data/oledb/column-entry.md) macro para adicionar suas próprias informações.  
  
     A exemplo a seguir mostra um `GetColumnInfo` função.  
  
    ```  
    // Check the property flag for bookmarks, if it is set, set the zero  
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
          ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0, sizeof(DWORD), DBTYPE_BYTES,   
             0, 0, GUID_NULL, CAgentMan, dwBookmark, DBCOLUMNFLAGS_ISBOOKMARK)  
          ulCols++;  
       }  
    }  
  
    // Next, set up the other columns.  
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
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)
---
title: "Fazendo referência a uma propriedade no provedor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB providers, properties
- references, to properties in providers
- referencing properties in providers
ms.assetid: bfbb3851-5eed-467a-a179-4a97a9515525
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1e39d012f126d44477bcb27f43b0a1119583a7ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="referencing-a-property-in-your-provider"></a>Fazendo referência a uma propriedade no provedor
Localize o grupo de propriedades e a ID de propriedade para a propriedade que você deseja. Para obter mais informações, consulte [propriedades OLE DB](https://msdn.microsoft.com/en-us/library/ms722734.aspx) no *referência do programador de DB OLE*.  
  
 O exemplo a seguir pressupõe que você está tentando obter uma propriedade do conjunto de linhas. O código para usar o comando ou a sessão é semelhante, mas usa uma interface diferente.  
  
 Criar um [CDBPropSet](../../data/oledb/cdbpropset-class.md) usando o grupo de propriedades como o parâmetro para o construtor do objeto. Por exemplo:  
  
```  
CDBPropSet propset(DBPROPSET_ROWSET);  
```  
  
 Chamar [AddProperty](../../data/oledb/cdbpropset-addproperty.md), passando a ID de propriedade e um valor a ser atribuído à propriedade. O tipo do valor depende da propriedade que você está usando.  
  
```  
CDBPropSet propset(DBPROPSET_ROWSET);  
propset.AddProperty(DBPROP_IRowsetChange, true);  
propset.AddProperty(DBPROP_UPDATABILITY,  
DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);  
```  
  
 Use o `IRowset` interface para chamar **GetProperties**. Passe a propriedade definida como um parâmetro. Aqui está o código final:  
  
```  
CAgentRowset<CMyProviderCommand>* pRowset = (CAgentRowset<CMyProviderCommand>*) pThis;  
  
CComQIPtr<IRowsetInfo, &IID_IRowsetInfo> spRowsetProps = pRowset;  
  
DBPROPIDSET set;  
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
      ...  // Use property here  
   }  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)
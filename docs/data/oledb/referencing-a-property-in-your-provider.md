---
title: "Fazendo refer&#234;ncia a uma propriedade no provedor | Microsoft Docs"
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
  - "Provedores OLE DB, propriedades"
  - "referências, para propriedades em provedores"
  - "referenciando propriedades em provedores"
ms.assetid: bfbb3851-5eed-467a-a179-4a97a9515525
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fazendo refer&#234;ncia a uma propriedade no provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Localizar a ID do grupo de propriedade e a propriedade para a propriedade que você deseja.  Para obter mais informações, consulte [Propriedades do OLE DB](https://msdn.microsoft.com/en-us/library/ms722734.aspx)*na referência do programador de OLE DB*.  
  
 O exemplo a seguir assume que você está tentando obter uma propriedade do conjunto de linhas.  O código para usar a sessão ou o comando é semelhante, mas usa uma interface diferente.  
  
 Crie um objeto de [CDBPropSet](../Topic/CDBPropSet%20Class.md) usando o grupo de propriedades como o parâmetro para o construtor.  Por exemplo:  
  
```  
CDBPropSet propset(DBPROPSET_ROWSET);  
```  
  
 Chame [AddProperty](../../data/oledb/cdbpropset-addproperty.md), passando à ID de propriedade e um valor a ser atribuído à propriedade.  O tipo do valor depende da propriedade que você está usando.  
  
```  
CDBPropSet propset(DBPROPSET_ROWSET);  
propset.AddProperty(DBPROP_IRowsetChange, true);  
propset.AddProperty(DBPROP_UPDATABILITY,  
DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);  
```  
  
 Use a interface de `IRowset` para chamar **GetProperties**.  Passe o conjunto de propriedades como um parâmetro.  Segue o código final:  
  
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
  
## Consulte também  
 [Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)
---
title: Fazendo referência a uma propriedade no provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB providers, properties
- references, to properties in providers
- referencing properties in providers
ms.assetid: bfbb3851-5eed-467a-a179-4a97a9515525
ms.openlocfilehash: d70a1901c457d9fbdbe8712d84999e256a54d0c2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209751"
---
# <a name="referencing-a-property-in-your-provider"></a>Fazendo referência a uma propriedade no provedor

Localize o grupo de propriedades e a ID da propriedade que você deseja. Para obter mais informações, consulte [Propriedades de OLE DB](/previous-versions/windows/desktop/ms722734(v=vs.85)) na **referência do programador de OLE DB**.

O exemplo a seguir pressupõe que você está tentando obter uma propriedade do conjunto de linhas. O código para usar a sessão ou o comando é semelhante, mas usa uma interface diferente.

Crie um objeto [CDBPropSet](../../data/oledb/cdbpropset-class.md) usando o grupo de propriedades como o parâmetro para o construtor. Por exemplo:

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
```

Chame [AddProperty](../../data/oledb/cdbpropset-addproperty.md), passando a ID da propriedade e um valor a ser atribuído à propriedade. O tipo do valor depende da propriedade que você está usando.

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);

propset.AddProperty(DBPROP_IRowsetChange, true);

propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);
```

Use a interface `IRowset` para chamar `GetProperties`. Passe o conjunto de propriedades como um parâmetro. Este é o código final:

```cpp
CAgentRowset<CCustomCommand>* pRowset = (CAgentRowset<CCustomCommand>*) pThis;

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

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)

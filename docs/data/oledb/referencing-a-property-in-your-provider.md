---
title: Fazendo referência a uma propriedade no provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB providers, properties
- references, to properties in providers
- referencing properties in providers
ms.assetid: bfbb3851-5eed-467a-a179-4a97a9515525
ms.openlocfilehash: 642e6219f72e506205e8192770be7d8af5d0d817
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556446"
---
# <a name="referencing-a-property-in-your-provider"></a>Fazendo referência a uma propriedade no provedor

Localize o grupo de propriedades e a ID de propriedade para a propriedade desejada. Para obter mais informações, consulte [propriedades do OLE DB](https://docs.microsoft.com/previous-versions/windows/desktop/ms722734(v=vs.85)) na **referência do programador DB OLE**.

O exemplo a seguir pressupõe que você está tentando obter uma propriedade do conjunto de linhas. O código para usar a sessão ou o comando é semelhante, mas usa uma interface diferente.

Criar uma [CDBPropSet](../../data/oledb/cdbpropset-class.md) usando o grupo de propriedades como o parâmetro para o construtor do objeto. Por exemplo:

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
```

Chame [AddProperty](../../data/oledb/cdbpropset-addproperty.md), passando a ID de propriedade e um valor a ser atribuído à propriedade. O tipo do valor depende da propriedade que você está usando.

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);

propset.AddProperty(DBPROP_IRowsetChange, true);

propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);
```

Use o `IRowset` interface para chamar `GetProperties`. Passe a propriedade definida como um parâmetro. Aqui está o código final:

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

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)
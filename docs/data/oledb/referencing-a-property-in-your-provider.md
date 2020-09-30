---
title: Fazendo referência a uma propriedade no provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB providers, properties
- references, to properties in providers
- referencing properties in providers
ms.assetid: bfbb3851-5eed-467a-a179-4a97a9515525
ms.openlocfilehash: ecb11c54d4c5926fbead0196c441ec23e8b0891f
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509524"
---
# <a name="referencing-a-property-in-your-provider"></a>Fazendo referência a uma propriedade no provedor

Localize o grupo de propriedades e a ID da propriedade que você deseja. Para obter mais informações, consulte [Propriedades de OLE DB](/previous-versions/windows/desktop/ms722734(v=vs.85)) na **referência do programador de OLE DB**.

O exemplo a seguir pressupõe que você está tentando obter uma propriedade do conjunto de linhas. O código para usar a sessão ou o comando é semelhante, mas usa uma interface diferente.

Crie um objeto [CDBPropSet](../../data/oledb/cdbpropset-class.md) usando o grupo de propriedades como o parâmetro para o construtor. Por exemplo:

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
```

Chame [AddProperty](./cdbpropset-class.md#addproperty), passando a ID da propriedade e um valor a ser atribuído à propriedade. O tipo do valor depende da propriedade que você está usando.

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);

propset.AddProperty(DBPROP_IRowsetChange, true);

propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);
```

Use a `IRowset` interface para chamar `GetProperties` . Passe o conjunto de propriedades como um parâmetro. Este é o código final:

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

[Trabalhando com modelos de provedor de OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)

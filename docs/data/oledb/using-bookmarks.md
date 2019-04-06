---
title: Usando indicadores
ms.date: 10/24/2018
helpviewer_keywords:
- rowsets, bookmarks
- OLE DB provider templates, bookmarks
- bookmarks, OLE DB
- OLE DB providers, bookmark support
ms.assetid: 7fa1d1a8-5063-4aa9-93ee-815bb9c98fae
ms.openlocfilehash: 579e67151858904e877a34bf30467e3cb97fe2c4
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59028487"
---
# <a name="using-bookmarks"></a>Usando indicadores

Antes de abrir o conjunto de linhas, você deve instruir o provedor que você deseja usar indicadores. Para fazer isso, defina as `DBPROP_BOOKMARKS` propriedade para **verdadeiro** no conjunto de suas propriedades. O provedor recupera indicadores como coluna de zero, então você deve usar a macro especial BOOKMARK_ENTRY e o `CBookmark` classe se você estiver usando um acessador estática. `CBookmark` é uma classe de modelo em que o argumento é o comprimento em bytes do buffer indicador. O comprimento do buffer exigido para um indicador depende do provedor. Se você estiver usando o provedor OLE DB ODBC, conforme mostrado no exemplo a seguir, o buffer deve ser de 4 bytes.

```cpp
class CProducts
{
public:
   CBookmark<4> bookmark;

   BEGIN_COLUMN_MAP(CProducts)
      BOOKMARK_ENTRY(bookmark)
   END_COLUMN_MAP()
};
```

Em seguida, usado pelo código a seguir:

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
propset.AddProperty(DBPROP_BOOKMARKS, true);

CTable<CAccessor<CProducts>> product;
CSession session;
product.Open(session, "Products", &propset);
```

Se você usar `CDynamicAccessor`, o buffer é definido dinamicamente em tempo de execução. Nesse caso, você pode usar uma versão especializada do `CBookmark` para os quais você não especificar um comprimento de buffer. Use a função `GetBookmark` para recuperar o indicador do registro atual, conforme mostrado no exemplo de código:

```cpp
CTable<CDynamicAccessor> product;
CBookmark<> bookmark;
CDBPropSet propset(DBPROPSET_ROWSET);
CSession session;

propset.AddProperty(DBPROP_BOOKMARKS, true);
product.Open(session, "Products", &propset);
product.MoveNext();
product.GetBookmark(&bookmark);
```

Para obter informações sobre o suporte a indicadores em provedores, consulte [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md).

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)
---
title: Usar indicadores
ms.date: 10/24/2018
helpviewer_keywords:
- rowsets, bookmarks
- OLE DB provider templates, bookmarks
- bookmarks, OLE DB
- OLE DB providers, bookmark support
ms.assetid: 7fa1d1a8-5063-4aa9-93ee-815bb9c98fae
ms.openlocfilehash: 5a4a2d65ba7367b5568603b5f08a07c6d85cc4a5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209307"
---
# <a name="using-bookmarks"></a>Usar indicadores

Antes de abrir o conjunto de linhas, você deve informar ao provedor que deseja usar indicadores. Para fazer isso, defina a propriedade `DBPROP_BOOKMARKS` como **true** em seu conjunto de propriedades. O provedor recupera indicadores como uma coluna zero, portanto, você deve usar a macro especial BOOKMARK_ENTRY e a classe `CBookmark` se estiver usando um acessador estático. `CBookmark` é uma classe de modelo em que o argumento é o comprimento em bytes do buffer de indicadores. O comprimento do buffer necessário para um indicador depende do provedor. Se você estiver usando o provedor de OLE DB ODBC, conforme mostrado no exemplo a seguir, o buffer deverá ter 4 bytes.

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

Em seguida, usado pelo seguinte código:

```cpp
CDBPropSet propset(DBPROPSET_ROWSET);
propset.AddProperty(DBPROP_BOOKMARKS, true);

CTable<CAccessor<CProducts>> product;
CSession session;
product.Open(session, "Products", &propset);
```

Se você usar `CDynamicAccessor`, o buffer será definido dinamicamente em tempo de execução. Nesse caso, você pode usar uma versão especializada do `CBookmark` para o qual você não especifica um comprimento de buffer. Use a função `GetBookmark` para recuperar o indicador do registro atual, conforme mostrado neste exemplo de código:

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

Para obter informações sobre como dar suporte a indicadores em provedores, consulte [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md).

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)

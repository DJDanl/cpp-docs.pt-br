---
title: Usando indicadores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- rowsets, bookmarks
- OLE DB provider templates, bookmarks
- bookmarks, OLE DB
- OLE DB providers, bookmark support
ms.assetid: 7fa1d1a8-5063-4aa9-93ee-815bb9c98fae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5aa16d5f2a3a02d0e9fd6bb3dd5de71494e81d4a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33104481"
---
# <a name="using-bookmarks"></a>Usando indicadores
Antes de abrir o conjunto de linhas, você deve instruir o provedor que você deseja usar indicadores. Para fazer isso, defina o **DBPROP_BOOKMARKS** propriedade **true** no conjunto de suas propriedades. O provedor recupera indicadores como coluna de zero, você deve usar a macro especial `BOOKMARK_ENTRY` e `CBookmark` classe se você estiver usando um acessador estático. `CBookmark` é uma classe de modelo em que o argumento é o comprimento em bytes do buffer indicador. O comprimento do buffer necessário para um indicador depende do provedor. Se você estiver usando o provedor OLE DB ODBC, conforme mostrado no exemplo a seguir, o buffer deve ser 4 bytes.  
  
```  
class CProducts  
{  
public:  
   CBookmark<4>   bookmark;  
  
   BEGIN_COLUMN_MAP(CProducts)  
      BOOKMARK_ENTRY(bookmark)  
   END_COLUMN_MAP()  
};  
  
CDBPropSet propset(DBPROPSET_ROWSET);  

propset.AddProperty(DBPROP_BOOKMARKS, true);  
  

CTable<CAccessor<CProducts>> product;  
product.Open(session, "Products", &propset);  
```  
  
 Se você usar `CDynamicAccessor`, o buffer é alocado dinamicamente em tempo de execução. Nesse caso, você pode usar uma versão especializada do `CBookmark` para os quais você não especificar um comprimento de buffer. Use a função `GetBookmark` para recuperar o indicador do registro atual, conforme mostrado neste exemplo de código:  
  
```  
CTable<CDynamicAccessor> product;  
CBookmark<>              bookmark;  
CDBPropSet propset(DBPROPSET_ROWSET);  
  

propset.AddProperty(DBPROP_BOOKMARKS, true);  

product.Open(session, "Products", &propset);  

product.MoveNext();  

product.GetBookmark(&bookmark);  
```  
  
 Para obter informações sobre o suporte a indicadores em provedores, consulte [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)
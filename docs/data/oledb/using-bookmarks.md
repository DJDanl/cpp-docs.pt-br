---
title: "Usando indicadores | Microsoft Docs"
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
  - "indicadores, OLE DB"
  - "modelos de provedor do OLE DB, indicadores"
  - "Provedores OLE DB, suporte a indicadores"
  - "conjuntos de linhas, indicadores"
ms.assetid: 7fa1d1a8-5063-4aa9-93ee-815bb9c98fae
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando indicadores
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Antes de abrir o conjunto de linhas, você deve informar ao provedor que você deseja usar medidores.  Para fazer isso, defina a propriedade de **DBPROP\_BOOKMARKS** a **true** no conjunto de propriedades.  O provedor recupera indicadores como a coluna zero, assim você deve usar `BOOKMARK_ENTRY` macro especial e a classe de `CBookmark` se você estiver usando um acessador estático.  `CBookmark` é uma classe do modelo onde o argumento é um comprimento em bytes do buffer do medidor.  O comprimento do buffer exigido para um medidor depende do provedor.  Se você estiver usando o provedor OLE DB de ODBC, conforme mostrado no exemplo, o buffer deve ser 4 bytes.  
  
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
  
CTable<CAccessor<CProducts> > product;  
product.Open(session, "Products", &propset);  
```  
  
 Se você usar `CDynamicAccessor`, o buffer será atribuído dinamicamente em tempo de execução.  Nesse caso, você pode usar uma versão especializada de `CBookmark` para que você não especificar um comprimento do buffer.  Use a função `GetBookmark` para recuperar o indicador do registro atual, conforme mostrado neste exemplo de código:  
  
```  
CTable<CDynamicAccessor> product;  
CBookmark<>              bookmark;  
CDBPropSet propset(DBPROPSET_ROWSET);  
  
propset.AddProperty(DBPROP_BOOKMARKS, true);  
product.Open(session, "Products", &propset);  
product.MoveNext();  
product.GetBookmark(&bookmark);  
```  
  
 Para obter informações sobre os indicadores de suporte nos provedores, consulte [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md).  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)
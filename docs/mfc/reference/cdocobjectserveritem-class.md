---
title: Classe CDocObjectServerItem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDocObjectServerItem
dev_langs:
- C++
helpviewer_keywords:
- document object server
- CDocObjectServerItem class
- servers [C++], ActiveX documents
- docobject server
- servers [C++], doc objects
- ActiveX documents [C++], document server
ms.assetid: 530f7156-50c8-4806-9328-602c9133f622
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 06cf873512fbf43b729d9a70f185582a4e48cafc
ms.lasthandoff: 02/25/2017

---
# <a name="cdocobjectserveritem-class"></a>Classe CDocObjectServerItem
Verbos de servidor implementa OLE especificamente para servidores DocObject.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDocObjectServerItem : public COleServerItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocObjectServerItem::CDocObjectServerItem](#cdocobjectserveritem)|Constrói um objeto `CDocObjectServerItem`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocObjectServerItem::GetDocument](#getdocument)|Recupera um ponteiro para o documento que contém o item.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocObjectServerItem::OnHide](#onhide)|Lança uma exceção se o framework tenta ocultar um item DocObject.|  
|[CDocObjectServerItem::OnShow](#onshow)|Chamado pela estrutura para tornar o DocObject item no local ativa. Se o item não for um DocObject, chama [COleServerItem::OnShow](../../mfc/reference/coleserveritem-class.md#onshow).|  
  
## <a name="remarks"></a>Comentários  
 `CDocObjectServerItem`Define as funções de membro substituível: [OnHide](#onhide), [AoAbrir](http://msdn.microsoft.com/en-us/7a9b1363-6ad8-4732-9959-4e35c07644fd), e [OnShow](#onshow).  
  
 Usar `CDocObjectServerItem`, garantir que o [OnGetEmbeddedItem](../../mfc/reference/coleserverdoc-class.md#ongetembeddeditem) substituir em seu `COleServerDoc`-classe derivada retorna um novo `CDocObjectServerItem` objeto. Se você precisar alterar qualquer funcionalidade no item, você pode criar uma nova instância da sua própria `CDocObjectServerItem`-classe derivada.  
  
 Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md) no *referência da MFC*. Consulte também [Internet primeiras etapas: documentos ativos](../../mfc/active-documents-on-the-internet.md) e [documentos ativos](../../mfc/active-documents-on-the-internet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 [Classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md)  
  
 `CDocObjectServerItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdocob.h  
  
##  <a name="a-namecdocobjectserveritema--cdocobjectserveritemcdocobjectserveritem"></a><a name="cdocobjectserveritem"></a>CDocObjectServerItem::CDocObjectServerItem  
 Constrói um objeto `CDocObjectServerItem`.  
  
```  
CDocObjectServerItem(COleServerDoc* pServerDoc, BOOL bAutoDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pServerDoc`  
 Um ponteiro para o documento que conterá o novo item DocObject.  
  
 `bAutoDelete`  
 Indica se o objeto pode ser excluído quando um link para ele é liberado. Defina o argumento **FALSE** se o `CDocObjectServerItem` objeto é uma parte integral de dados do documento. Defina-o como **TRUE** se o objeto é uma estrutura secundária usada para identificar um intervalo de dados do documento que podem ser excluídos pelo framework.  
  
##  <a name="a-namegetdocumenta--cdocobjectserveritemgetdocument"></a><a name="getdocument"></a>CDocObjectServerItem::GetDocument  
 Recupera um ponteiro para o documento que contém o item.  
  
```  
COleServerDoc* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item; **Nulo** se o item não for parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Isso permite o acesso ao documento do servidor que é passado como um argumento para o [CDocObjectServerItem](#cdocobjectserveritem) construtor.  
  
##  <a name="a-nameonhidea--cdocobjectserveritemonhide"></a><a name="onhide"></a>CDocObjectServerItem::OnHide  
 Chamado pela estrutura para ocultar o item.  
  
```  
virtual void OnHide();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão gera uma exceção se o item for um DocObject. Não é possível ocultar um item DocObject ativo porque ele usa a exibição inteira. Você deve desativar o item DocObject para fazê-la desaparecer. Se o item não for um DocObject, chama a implementação padrão [COleServerItem::OnHide](../../mfc/reference/coleserveritem-class.md#onhide).  
  
##  <a name="a-nameonshowa--cdocobjectserveritemonshow"></a><a name="onshow"></a>CDocObjectServerItem::OnShow  
 Chamado pela estrutura para instruir o aplicativo do servidor para tornar o DocObject item no local ativa.  
  
```  
virtual void OnShow();
```  
  
### <a name="remarks"></a>Comentários  
 Se o item não for um DocObject, chama a implementação padrão [COleServerItem::OnShow](../../mfc/reference/coleserveritem-class.md#onopen). Substitua essa função se você deseja realizar processamento ao abrir um item DocObject especial.  
  
## <a name="see-also"></a>Consulte também  
 [Classe da classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md)   
 [Classe COleDocObjectItem](../../mfc/reference/coledocobjectitem-class.md)


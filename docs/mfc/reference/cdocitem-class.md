---
title: Classe CDocItem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDocItem
dev_langs:
- C++
helpviewer_keywords:
- items, document
- document items
- server documents, document items
- CDocItem class
- container document items
- client document items
- OLE documents, items
- server documents
ms.assetid: 84fb8610-a4c8-4211-adc0-e70e8d002c11
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
ms.openlocfilehash: 1ade88aa562180d5c3a6a7afe3fe26943a5d811d
ms.lasthandoff: 02/25/2017

---
# <a name="cdocitem-class"></a>Classe CDocItem
A classe base para itens de documento, que são componentes de dados do documento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDocItem : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocItem::GetDocument](#getdocument)|Retorna o documento que contém o item.|  
|[CDocItem::IsBlank](#isblank)|Determina se o item contém todas as informações.|  
  
## <a name="remarks"></a>Comentários  
 `CDocItem`objetos são usados para representar itens OLE em documentos de cliente e servidor.  
  
 Para obter mais informações, consulte o artigo [contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CDocItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="a-namegetdocumenta--cdocitemgetdocument"></a><a name="getdocument"></a>CDocItem::GetDocument  
 Chame essa função para obter o documento que contém o item.  
  
```  
CDocument* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item; **Nulo**, se o item não é parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função é substituída nas classes derivadas [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md), retorna um ponteiro para um uma [COleDocument](../../mfc/reference/coledocument-class.md), um [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md), ou uma [COleServerDoc](../../mfc/reference/coleserverdoc-class.md) objeto.  
  
##  <a name="a-nameisblanka--cdocitemisblank"></a><a name="isblank"></a>CDocItem::IsBlank  
 Chamado pela estrutura quando ocorre de serialização padrão.  
  
```  
virtual BOOL IsBlank() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item não contém nenhuma informação; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `CDocItem` objetos não estão em branco. [COleClientItem](../../mfc/reference/coleclientitem-class.md) objetos às vezes estão em branco porque elas derivam diretamente de `CDocItem`. No entanto, [classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md) objetos são sempre em branco. Por padrão, os aplicativos OLE contendo `COleClientItem` objetos que não têm nenhum x ou y extensão são serializados. Isso é feito retornando **TRUE** da substituição de `IsBlank` quando o item não tem x ou y extensão.  
  
 Substitua essa função se você deseja implementar outras ações durante a serialização.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe da classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)


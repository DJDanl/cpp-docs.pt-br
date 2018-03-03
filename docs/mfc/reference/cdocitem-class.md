---
title: Classe CDocItem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDocItem
- AFXOLE/CDocItem
- AFXOLE/CDocItem::GetDocument
- AFXOLE/CDocItem::IsBlank
dev_langs:
- C++
helpviewer_keywords:
- CDocItem [MFC], GetDocument
- CDocItem [MFC], IsBlank
ms.assetid: 84fb8610-a4c8-4211-adc0-e70e8d002c11
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8a4987554965674612eaf8d9aa78c659f7f28b75
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdocitem-class"></a>Classe CDocItem
A classe base para os itens do documento, que são componentes de dados do documento.  
  
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
  
##  <a name="getdocument"></a>CDocItem::GetDocument  
 Chame essa função para obter o documento que contém o item.  
  
```  
CDocument* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item; **Nulo**, se o item não é parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função é substituída nas classes derivadas [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [COleServerItem](../../mfc/reference/coleserveritem-class.md), retornando um ponteiro para um um [COleDocument](../../mfc/reference/coledocument-class.md), um [ COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md), ou um [COleServerDoc](../../mfc/reference/coleserverdoc-class.md) objeto.  
  
##  <a name="isblank"></a>CDocItem::IsBlank  
 Chamado pelo framework quando ocorre de serialização padrão.  
  
```  
virtual BOOL IsBlank() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item não contém nenhuma informação; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `CDocItem` objetos não estão em branco. [COleClientItem](../../mfc/reference/coleclientitem-class.md) objetos às vezes são em branco porque eles derivam diretamente `CDocItem`. No entanto, [COleServerItem](../../mfc/reference/coleserveritem-class.md) objetos estão sempre em branco. Por padrão, os aplicativos OLE contendo `COleClientItem` objetos que não têm nenhum x ou y extensão são serializados. Isso é feito retornando **TRUE** de uma substituição de `IsBlank` quando o item não possui x ou y extensão.  
  
 Substitua essa função se desejar implementar outras ações durante a serialização.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe de COleServerItem](../../mfc/reference/coleserveritem-class.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)

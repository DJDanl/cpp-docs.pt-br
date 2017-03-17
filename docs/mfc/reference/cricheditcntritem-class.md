---
title: Classe CRichEditCntrItem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRichEditCntrItem
- AFXRICH/CRichEditCntrItem
- AFXRICH/CRichEditCntrItem::CRichEditCntrItem
- AFXRICH/CRichEditCntrItem::SyncToRichEditObject
dev_langs:
- C++
helpviewer_keywords:
- CRichEditCntrItem class
- OLE items, in rich edit views
- rich edit controls, using
- rich edit controls, OLE items
ms.assetid: 6c0b4efe-0fb8-4621-b5e1-fdcb8ec48c3b
caps.latest.revision: 24
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: b29c7c3b80d24ef9ddb94e09c6b5c7bf2444bb4f
ms.lasthandoff: 02/25/2017

---
# <a name="cricheditcntritem-class"></a>Classe CRichEditCntrItem
Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), fornece a funcionalidade do controle de edição avançada dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditCntrItem : public COleClientItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditCntrItem::CRichEditCntrItem](#cricheditcntritem)|Constrói um objeto `CRichEditCntrItem`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditCntrItem::SyncToRichEditObject](#synctoricheditobject)|Ativa o item como outro tipo.|  
  
## <a name="remarks"></a>Comentários  
 "Controle rich edit" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE incorporados. Controles de edição avançados fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView`mantém o texto e as características de formatação de texto. `CRichEditDoc`mantém a lista de itens de cliente OLE que estão no modo de exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner para o item de cliente OLE.  
  
 Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas que executam versões do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter um exemplo de uso avançado de editar itens de contêiner em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 [COleClientItem](../../mfc/reference/coleclientitem-class.md)  
  
 `CRichEditCntrItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrich.h  
  
##  <a name="cricheditcntritem"></a>CRichEditCntrItem::CRichEditCntrItem  
 Chame essa função para criar um `CRichEditCntrItem` de objeto e adicioná-lo ao documento contêiner.  
  
```  
CRichEditCntrItem(
    REOBJECT* preo = NULL,  
    CRichEditDoc* pContainer = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *preo*  
 Ponteiro para uma [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído em torno deste item OLE. Se *preo* é **nulo**, o item do cliente está vazio.  
  
 `pContainer`  
 Ponteiro para o documento de contêiner que contém esse item. Se `pContainer` é **nulo**, você deve chamar explicitamente [COleDocument::AddItem](../../mfc/reference/coledocument-class.md#additem) para adicionar este item de cliente a um documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função não executa qualquer inicialização OLE.  
  
 Para obter mais informações, consulte o [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="synctoricheditobject"></a>CRichEditCntrItem::SyncToRichEditObject  
 Chame essa função para sincronizar o aspecto de dispositivo, [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318), isso **CRichEditCntrltem** especificado por *reo*.  
  
```  
void SyncToRichEditObject(REOBJECT& reo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *REO*  
 Referência a um [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura que descreve um item OLE.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)


---
title: Classe CRichEditCntrItem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CRichEditCntrItem
- AFXRICH/CRichEditCntrItem
- AFXRICH/CRichEditCntrItem::CRichEditCntrItem
- AFXRICH/CRichEditCntrItem::SyncToRichEditObject
dev_langs:
- C++
helpviewer_keywords:
- CRichEditCntrItem [MFC], CRichEditCntrItem
- CRichEditCntrItem [MFC], SyncToRichEditObject
ms.assetid: 6c0b4efe-0fb8-4621-b5e1-fdcb8ec48c3b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9a64950bcb0cc931b4528276e85f5d60e3b5cb08
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33368414"
---
# <a name="cricheditcntritem-class"></a>Classe CRichEditCntrItem
Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditCntrItem : public COleClientItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditCntrItem::CRichEditCntrItem](#cricheditcntritem)|Constrói um objeto `CRichEditCntrItem`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditCntrItem::SyncToRichEditObject](#synctoricheditobject)|Ativa o item como outro tipo.|  
  
## <a name="remarks"></a>Comentários  
 Um "controle de edição avançada" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE inseridos. Controles de edição avançada fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface de usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView` mantém a característica de formatação de texto e texto. `CRichEditDoc` mantém a lista de itens de cliente OLE que estão no modo de exibição. `CRichEditCntrItem` fornece acesso do lado do contêiner para o item de cliente OLE.  
  
 Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas que executam versões do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter um exemplo de como usar itens de contêiner de edição rica em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 [COleClientItem](../../mfc/reference/coleclientitem-class.md)  
  
 `CRichEditCntrItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrich.h  
  
##  <a name="cricheditcntritem"></a>  CRichEditCntrItem::CRichEditCntrItem  
 Chamar essa função para criar um `CRichEditCntrItem` de objeto e adicioná-lo ao documento contêiner.  
  
```  
CRichEditCntrItem(
    REOBJECT* preo = NULL,  
    CRichEditDoc* pContainer = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *preo*  
 Ponteiro para um [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído em torno deste item OLE. Se *preo* é **nulo**, o item do cliente está vazio.  
  
 `pContainer`  
 Ponteiro para o documento de contêiner que contém esse item. Se `pContainer` é **nulo**, você deve chamar explicitamente [COleDocument::AddItem](../../mfc/reference/coledocument-class.md#additem) para adicionar este item de cliente a um documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função não executa qualquer inicialização OLE.  
  
 Para obter mais informações, consulte o [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura no SDK do Windows.  
  
##  <a name="synctoricheditobject"></a>  CRichEditCntrItem::SyncToRichEditObject  
 Chamar essa função para sincronizar o aspecto de dispositivo, [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318), isso **CRichEditCntrltem** especificado por *reo*.  
  
```  
void SyncToRichEditObject(REOBJECT& reo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *REO*  
 Referência a um [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura que descreve um item OLE.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)

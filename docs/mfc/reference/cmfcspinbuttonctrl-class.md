---
title: Classe CMFCSpinButtonCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCSpinButtonCtrl
- AFXSPINBUTTONCTRL/CMFCSpinButtonCtrl
- AFXSPINBUTTONCTRL/CMFCSpinButtonCtrl::OnDraw
dev_langs:
- C++
helpviewer_keywords:
- CMFCSpinButtonCtrl [MFC], OnDraw
ms.assetid: 8773f259-4d3f-4bca-a71c-09e0c71bc843
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c3531fd45bbccd351bd8f95ce0d4bb26de846b01
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37039460"
---
# <a name="cmfcspinbuttonctrl-class"></a>Classe CMFCSpinButtonCtrl
O `CMFCSpinButtonCtrl` classe oferece suporte a um Gerenciador de visual que desenha um controle de botão de rotação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCSpinButtonCtrl : public CSpinButtonCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCSpinButtonCtrl::CMFCSpinButtonCtrl`|Construtor padrão.|  
|`CMFCSpinButtonCtrl::~CMFCSpinButtonCtrl`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCSpinButtonCtrl::OnDraw](#ondraw)|Redesenha o controle de botão de rotação atual.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um Gerenciador de visual para desenhar um controle de botão de rotação em seu aplicativo, substitua todas as instâncias do `CSpinButtonCtrl` classe com o `CMFCSpinButtonCtrl` classe.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto do `CMFCSpinButtonCtrl` classe e usar seu `Create` método.  
  
 [!code-cpp[NVC_MFC_RibbonApp#25](../../mfc/reference/codesnippet/cpp/cmfcspinbuttonctrl-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CSpinButtonCtrl](../../mfc/reference/cspinbuttonctrl-class.md)  
  
 [CMFCSpinButtonCtrl](../../mfc/reference/cmfcspinbuttonctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxspinbuttonctrl.h  
  
##  <a name="ondraw"></a>  CMFCSpinButtonCtrl::OnDraw  
 Redesenha o controle de botão de rotação atual.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 O framework chama o `CMFCSpinButtonCtrl::OnPaint` método para tratar o [CWnd::OnPaint](../../mfc/reference/cwnd-class.md#onpaint) mensagem e que método por sua vez chama `CMFCSpinButtonCtrl::OnDraw` método. Substitua este método para personalizar o modo como o framework desenha o controle de botão de rotação.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)

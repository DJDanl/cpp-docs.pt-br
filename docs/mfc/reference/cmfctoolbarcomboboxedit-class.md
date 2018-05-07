---
title: Classe CMFCToolBarComboBoxEdit | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCToolBarComboBoxEdit
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxEdit
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarComboBoxEdit [MFC], CMFCToolBarComboBoxEdit
ms.assetid: 4789c34a-ce58-48ba-a26f-38748b601352
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d541702d73befedab72ad7b130b56a125a5817aa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfctoolbarcomboboxedit-class"></a>Classe CMFCToolBarComboBoxEdit
A estrutura usa o `CMFCToolBarComboBoxEdit` classe para criar um botão de barra de ferramentas que se comporta como um controle de caixa de combinação editável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarComboBoxEdit : public CEdit  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit](#cmfctoolbarcomboboxedit)|Constrói um objeto `CMFCToolBarComboBoxEdit`.|  
|`CMFCToolBarComboBoxEdit::~CMFCToolBarComboBoxEdit`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCToolBarComboBoxEdit::PreTranslateMessage`|Converte as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|  
  
### <a name="remarks"></a>Comentários  
 Derivar uma classe a partir de `CMFCToolBarComboBoxEdit` classe para personalizar suas operações de edição.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CEdit](../../mfc/reference/cedit-class.md)  
  
 [CMFCToolBarComboBoxEdit](../../mfc/reference/cmfctoolbarcomboboxedit-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarcomboboxbutton.h  
  
##  <a name="cmfctoolbarcomboboxedit"></a>  CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit  
 Constrói um objeto `CMFCToolBarComboBoxEdit`.  
  
```  
CMFCToolBarComboBoxEdit(CMFCToolBarComboBoxButton& combo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `combo`  
 Uma referência a um [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md) objeto, que é um botão de barra de ferramentas que contém um controle de caixa de combinação.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCToolBarComboBoxEdit` classe. Este trecho de código é parte do [exemplo de demonstração do IE](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo#5](../../mfc/reference/codesnippet/cpp/cmfctoolbarcomboboxedit-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

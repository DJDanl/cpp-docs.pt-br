---
title: Classe CDialogBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDialogBar
- AFXEXT/CDialogBar
- AFXEXT/CDialogBar::CDialogBar
- AFXEXT/CDialogBar::Create
dev_langs:
- C++
helpviewer_keywords:
- dialog bars, Windows modeless dialog box
- CDialogBar class
- dialog boxes, modeless
ms.assetid: da2f7a30-970c-44e3-87f0-6094bd002cab
caps.latest.revision: 23
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
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: 33dc5f5f4d345745a4b9435e725f411f4387e287
ms.lasthandoff: 02/25/2017

---
# <a name="cdialogbar-class"></a>Classe CDialogBar
Fornece a funcionalidade de uma caixa de diálogo sem janela restrita do Windows em uma barra de controle.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDialogBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialogBar::CDialogBar](#cdialogbar)|Constrói um objeto `CDialogBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialogBar::Create](#create)|Cria uma barra de caixa de diálogo do Windows e anexa-o para o `CDialogBar` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma barra da caixa de diálogo é semelhante a uma caixa de diálogo que contém controles padrão do Windows que o usuário pode usar tab entre. Similaridade outra é que você criar um modelo de caixa de diálogo para representar a caixa de diálogo.  
  
 Criando e usando uma caixa de diálogo é semelhante a criar e usar um `CFormView` objeto. Primeiro, use o [editor de diálogo](../../windows/dialog-editor.md) para definir um modelo de caixa de diálogo com o estilo **WS_CHILD** e nenhum outro estilo. O modelo não deve ter o estilo **WS_VISIBLE**. No código do aplicativo, chame o construtor para construir o `CDialogBar` do objeto, em seguida, chame **criar** para criar a janela de diálogo barra e anexá-lo a `CDialogBar` objeto.  
  
 Para obter mais informações sobre `CDialogBar`, consulte o artigo [barras da caixa de diálogo](../../mfc/dialog-bars.md) e [técnico 31 Observação](../../mfc/tn031-control-bars.md), barras de controle.  
  
> [!NOTE]
>  Na versão atual, uma `CDialogBar` objeto não pode hospedar controles de formulários do Windows. Para obter mais informações sobre controles de Windows Forms no Visual C++, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CDialogBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="cdialogbar"></a>CDialogBar::CDialogBar  
 Constrói um objeto `CDialogBar`.  
  
```  
CDialogBar();
```  
  
##  <a name="create"></a>CDialogBar::Create  
 Carrega o modelo de recursos de caixa de diálogo especificado por `lpszTemplateName` ou `nIDTemplate`, cria a janela da caixa de diálogo barra, define seu estilo e associa o `CDialogBar` objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    LPCTSTR lpszTemplateName,  
    UINT nStyle,  
    UINT nID);

 
virtual BOOL Create(
    CWnd* pParentWnd,  
    UINT nIDTemplate,  
    UINT nStyle,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Um ponteiro para o pai `CWnd` objeto.  
  
 `lpszTemplateName`  
 Um ponteiro para o nome do `CDialogBar` modelo de recursos de caixa de diálogo do objeto.  
  
 `nStyle`  
 O estilo de barra de ferramentas. Estilos de barra de ferramentas adicionais com suporte são:  
  
- `CBRS_TOP`Barra de controle está no topo da janela do quadro.  
  
- `CBRS_BOTTOM`Barra de controle está na parte inferior da janela do quadro.  
  
- `CBRS_NOALIGN`Barra de controle não é reposicionada quando o pai for redimensionado.  
  
- `CBRS_TOOLTIPS`Barra de controle exibe dicas de ferramenta.  
  
- **CBRS_SIZE_DYNAMIC** barra de controle é dinâmica.  
  
- **CBRS_SIZE_FIXED** barra de controle é fixo.  
  
- **CBRS_FLOATING** barra de controle é flutuante.  
  
- `CBRS_FLYBY`Barra de status exibe informações sobre o botão.  
  
- **CBRS_HIDE_INPLACE** barra de controle não será exibida para o usuário.  
  
 `nID`  
 A ID do controle da barra de caixa de diálogo.  
  
 `nIDTemplate`  
 A ID de recurso de `CDialogBar` modelo de caixa de diálogo do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você especificar o `CBRS_TOP` ou `CBRS_BOTTOM` estilo de alinhamento, largura da barra de caixa de diálogo é que a janela do quadro e sua altura é que o recurso especificado por `nIDTemplate`. Se você especificar o `CBRS_LEFT` ou `CBRS_RIGHT` estilo de alinhamento, altura da barra de caixa de diálogo é que a janela do quadro e sua largura é que o recurso especificado por `nIDTemplate`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCMessageMaps&13;](../../mfc/reference/codesnippet/cpp/cdialogbar-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)


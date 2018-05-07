---
title: Classe CDialogBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDialogBar
- AFXEXT/CDialogBar
- AFXEXT/CDialogBar::CDialogBar
- AFXEXT/CDialogBar::Create
dev_langs:
- C++
helpviewer_keywords:
- CDialogBar [MFC], CDialogBar
- CDialogBar [MFC], Create
ms.assetid: da2f7a30-970c-44e3-87f0-6094bd002cab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7dbb2d8202e9b87d2825b7d40a0dde4323246aa0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdialogbar-class"></a>Classe CDialogBar
Fornece a funcionalidade de uma caixa de diálogo sem janela restrita do Windows em uma barra de controle.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDialogBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialogBar::CDialogBar](#cdialogbar)|Constrói um objeto `CDialogBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDialogBar::Create](#create)|Cria uma barra da caixa de diálogo de Windows e anexa-o para o `CDialogBar` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma barra da caixa de diálogo se assemelha a uma caixa de diálogo em que ele contém controles padrão do Windows que o usuário pode usar tab entre. Similaridade outra é que você criar um modelo de caixa de diálogo para representar a barra da caixa de diálogo.  
  
 Criando e usando uma caixa de diálogo é semelhante a criar e usar um `CFormView` objeto. Primeiro, use o [editor de caixa de diálogo](../../windows/dialog-editor.md) para definir um modelo de caixa de diálogo com o estilo **WS_CHILD** e nenhum outro estilo. O modelo não deve ter o estilo **WS_VISIBLE**. No código do aplicativo, chame o construtor para construir o `CDialogBar` do objeto e, em seguida, chamar **criar** para criar a janela de diálogo barra e anexá-lo para o `CDialogBar` objeto.  
  
 Para obter mais informações sobre `CDialogBar`, consulte o artigo [barras da caixa de diálogo](../../mfc/dialog-bars.md) e [31 de observação técnica](../../mfc/tn031-control-bars.md), barras de controle.  
  
> [!NOTE]
>  Na versão atual, um `CDialogBar` objeto não é possível hospedar controles de formulários do Windows. Para obter mais informações sobre controles de formulários do Windows em Visual C++, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CDialogBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="cdialogbar"></a>  CDialogBar::CDialogBar  
 Constrói um objeto `CDialogBar`.  
  
```  
CDialogBar();
```  
  
##  <a name="create"></a>  CDialogBar::Create  
 Carrega o modelo de recurso de caixa de diálogo especificado por `lpszTemplateName` ou `nIDTemplate`, cria a janela da caixa de diálogo da barra, define seu estilo e associa-o com o `CDialogBar` objeto.  
  
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
 Um ponteiro para o nome do `CDialogBar` modelo de recurso de caixa de diálogo do objeto.  
  
 `nStyle`  
 O estilo de barra de ferramentas. Estilos de barra de ferramentas adicionais com suporte são:  
  
- `CBRS_TOP` Barra de controle está na parte superior da janela do quadro.  
  
- `CBRS_BOTTOM` Barra de controle está na parte inferior da janela do quadro.  
  
- `CBRS_NOALIGN` Barra de controle é reposicionado de forma não quando o pai for redimensionado.  
  
- `CBRS_TOOLTIPS` Barra de controle exibe dicas de ferramenta.  
  
- **CBRS_SIZE_DYNAMIC** barra de controle é dinâmica.  
  
- **CBRS_SIZE_FIXED** barra de controle é fixo.  
  
- **CBRS_FLOATING** barra de controle é flutuante.  
  
- `CBRS_FLYBY` Barra de status exibe informações sobre o botão.  
  
- **CBRS_HIDE_INPLACE** barra de controle não será exibida para o usuário.  
  
 `nID`  
 A ID de controle da barra de caixa de diálogo.  
  
 `nIDTemplate`  
 A ID de recurso de `CDialogBar` modelo de caixa de diálogo do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você especificar o `CBRS_TOP` ou `CBRS_BOTTOM` estilo de alinhamento, largura da barra de caixa de diálogo é que a janela do quadro e sua altura é que o recurso especificado pela `nIDTemplate`. Se você especificar o `CBRS_LEFT` ou `CBRS_RIGHT` estilo de alinhamento, altura da barra de caixa de diálogo é que a janela do quadro e sua largura é que o recurso especificado pela `nIDTemplate`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCMessageMaps#13](../../mfc/reference/codesnippet/cpp/cdialogbar-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)

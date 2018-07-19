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
ms.openlocfilehash: 5ff69a4974cd85471b0cfa039f32ee0c1a76f82a
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37336378"
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
|[CDialogBar::Create](#create)|Cria uma barra de diálogo do Windows e anexa-o para o `CDialogBar` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Uma barra da caixa de diálogo é semelhante a uma caixa de diálogo que contém os controles padrão do Windows que o usuário pode pressionar tab entre. Similaridade de outra é que você crie um modelo de caixa de diálogo para representar a barra da caixa de diálogo.  
  
 Criando e usando uma caixa de diálogo são semelhante à criação e uso uma `CFormView` objeto. Primeiro, use o [editor de caixa de diálogo](../../windows/dialog-editor.md) para definir um modelo de caixa de diálogo com os estilos WS_CHILD e nenhum outro estilo. O modelo não deve ter o estilo WS_VISIBLE. No código do aplicativo, chame o construtor para construir o `CDialogBar` do objeto, em seguida, chame `Create` para criar a janela da barra da caixa de diálogo e anexá-lo para o `CDialogBar` objeto.  
  
 Para obter mais informações sobre `CDialogBar`, consulte o artigo [barras da caixa de diálogo](../../mfc/dialog-bars.md) e [31 de observação técnica](../../mfc/tn031-control-bars.md), barras de controle.  
  
> [!NOTE]
>  Na versão atual, um `CDialogBar` objeto não é possível hospedar controles dos Windows Forms. Para obter mais informações sobre controles de Windows Forms no Visual C++, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
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
 Carrega o modelo de recursos de caixa de diálogo especificado por `lpszTemplateName` ou `nIDTemplate`, cria a janela da barra da caixa de diálogo, define seu estilo e associa-o com o `CDialogBar` objeto.  
  
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
 *pParentWnd*  
 Um ponteiro para o pai `CWnd` objeto.  
  
 *lpszTemplateName*  
 Um ponteiro para o nome da `CDialogBar` modelo de recursos de caixa de diálogo do objeto.  
  
 *nStyle*  
 O estilo de barra de ferramentas. Estilos de barra de ferramentas adicionais com suporte são:  
  
- Barra de controle de CBRS_TOP está na parte superior da janela do quadro.  
  
- Barra de controle CBRS_BOTTOM é na parte inferior da janela do quadro.  
  
- Barra de controle de CBRS_NOALIGN não é reposicionada quando o pai for redimensionado.  
  
- Barra de controle CBRS_TOOLTIPS exibe dicas de ferramenta.  
  
- Barra de controle CBRS_SIZE_DYNAMIC é dinâmica.  
  
- Barra de controle CBRS_SIZE_FIXED é fixo.  
  
- Barra de controle CBRS_FLOATING é flutuante.  
  
- Barra de Status de CBRS_FLYBY exibe informações sobre o botão.  
  
- Barra de controle de CBRS_HIDE_INPLACE não é exibida ao usuário.  
  
 *nID*  
 A ID do controle da barra de diálogo.  
  
 *nIDTemplate*  
 A ID de recurso a `CDialogBar` modelo de caixa de diálogo do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você especificar o estilo de alinhamento CBRS_TOP ou CBRS_BOTTOM, largura da barra de diálogo é que da janela do quadro e sua altura é que um recurso especificado pela *nIDTemplate*. Se você especificar o estilo de alinhamento CBRS_LEFT ou CBRS_RIGHT, altura da barra de diálogo é que da janela do quadro e sua largura seja do recurso especificado pela *nIDTemplate*.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCMessageMaps#13](../../mfc/reference/codesnippet/cpp/cdialogbar-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)

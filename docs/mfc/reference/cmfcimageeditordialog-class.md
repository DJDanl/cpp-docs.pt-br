---
title: Classe CMFCImageEditorDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCImageEditorDialog
- AFXIMAGEEDITORDIALOG/CMFCImageEditorDialog
- AFXIMAGEEDITORDIALOG/CMFCImageEditorDialog::CMFCImageEditorDialog
dev_langs:
- C++
helpviewer_keywords:
- CMFCImageEditorDialog [MFC], CMFCImageEditorDialog
ms.assetid: 6a7d08f3-1ec2-4062-9b79-a0c2776b58d1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: af19a9dcb207afa482f54e26540a6b706d607ce0
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040763"
---
# <a name="cmfcimageeditordialog-class"></a>Classe CMFCImageEditorDialog
O `CMFCImageEditorDialog` classe oferece suporte a uma caixa de diálogo do editor de imagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCImageEditorDialog : public CDialogEx  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCImageEditorDialog::CMFCImageEditorDialog](#cmfcimageeditordialog)|Constrói um objeto `CMFCImageEditorDialog`.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCImageEditorDialog` classe fornece uma caixa de diálogo que inclui:  
  
-   Uma área de imagem que você usar para modificar pixels individuais em uma imagem.  
  
-   Ferramentas para modificar os pixels na área da imagem de desenho.  
  
-   Uma paleta de cores para especificar a cor que é usada pelas ferramentas de desenho.  
  
-   Uma área de visualização que exibe o efeito da sua edição.  
  
 A ilustração a seguir mostra um editor de imagem de caixa de diálogo.  
  
 ![Caixa de diálogo CMFCImageEditorDialog](../../mfc/reference/media/imageedit.png "imageedit")  
  
 Uma maneira de usar um `CMFCImageEditorDialog` objeto é passado um `CBitmap` imagem a ser editado. Não crie uma imagem grande porque a área de edição de imagem tem um tamanho limitado e o tamanho de pixel lógico é ajustado para caber na área. Chamar o `DoModal` método para iniciar a caixa de diálogo modal.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
 [CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afximageeditordialog.h  
  
##  <a name="cmfcimageeditordialog"></a>  CMFCImageEditorDialog::CMFCImageEditorDialog  
 Constrói um objeto `CMFCImageEditorDialog`.  
  
```  
CMFCImageEditorDialog(
    CBitmap* pBitmap,  
    CWnd* pParent=NULL,  
    int nBitsPixel=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pBitmap*  
 Ponteiro para uma imagem.  
  
 *pParent*  
 Ponteiro para a janela pai da caixa de diálogo de editor imagem atual.  
  
 *nBitsPixel*  
 O número de bits usados para representar a cor de um único pixel, que também é conhecida como profundidade de cor.  Se o *nBitsPixel* parâmetro é -1, a profundidade de cor é derivada da imagem especificada pelo *pBitmap* parâmetro. O valor padrão é -1.  
  
### <a name="return-value"></a>Valor de retorno  
 Para modificar uma imagem, passe um ponteiro de imagem para o `CMFCImageEditorDialog` construtor. Em seguida, chamar o `DoModal` método para abrir a caixa de diálogo modal. Quando o `DoModal` método retorna, o bitmap conterá a nova imagem.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCImageEditorDialog` classe. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#8](../../mfc/reference/codesnippet/cpp/cmfcimageeditordialog-class_1.cpp)]  
[!code-cpp[NVC_MFC_NewControls#40](../../mfc/reference/codesnippet/cpp/cmfcimageeditordialog-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

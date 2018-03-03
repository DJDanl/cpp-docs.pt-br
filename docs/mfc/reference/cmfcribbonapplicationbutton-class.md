---
title: Classe CMFCRibbonApplicationButton | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton::CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton::SetImage
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonApplicationButton [MFC], CMFCRibbonApplicationButton
- CMFCRibbonApplicationButton [MFC], SetImage
ms.assetid: beb81757-fabd-4641-9130-876ba8505b78
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8f5c8dac406a70edd5782e4ca1962aa36b0175ae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcribbonapplicationbutton-class"></a>Classe CMFCRibbonApplicationButton
Implementa um botão especial localizado no canto superior esquerdo da janela do aplicativo. Quando clicado, o botão abre um menu que geralmente contém comuns **arquivo** comandos como **abrir**, **salvar**, e **saída**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonApplicationButton : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonApplicationButton::CMFCRibbonApplicationButton](#cmfcribbonapplicationbutton)|Constrói e inicializa um objeto `CMFCRibbonApplicationButton`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonApplicationButton::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CMFCRibbonApplicationButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCRibbonApplicationButton::SetImage](#setimage)|Atribui uma imagem para o botão do aplicativo de faixa de opções.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonApplicationButton` classe. O exemplo mostra como atribuir uma imagem para o botão do aplicativo e como definir sua dica de ferramenta. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient#4](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_1.h)]  
[!code-cpp[NVC_MFC_DrawClient#5](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonBar.h  
  
##  <a name="cmfcribbonapplicationbutton"></a>CMFCRibbonApplicationButton::CMFCRibbonApplicationButton  
 Cria e inicializa um [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md) objeto.  
  
```  
CMFCRibbonApplicationButton();  
CMFCRibbonApplicationButton(UINT uiBmpResID);  
  CMFCRibbonApplicationButton(HBITMAP hBmp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uiBmpResID`  
 A ID de recurso da imagem será exibida no botão do aplicativo.  
  
 `hBmp`  
 Um identificador para um bitmap a ser exibido no botão do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 O botão faixa de opções do aplicativo é um botão especial que está localizado no canto superior esquerdo da janela do aplicativo. Quando um usuário clica neste botão, o aplicativo abre um menu que geralmente contém comuns **arquivo** comandos, como **abrir**, **salvar**, e **desaída**.  
  
##  <a name="setimage"></a>CMFCRibbonApplicationButton::SetImage  
 Atribui uma imagem para o botão do aplicativo.  
  
```  
void SetImage(UINT uiBmpResID);  
void SetImage(HBITMAP hBmp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiBmpResID`  
 A ID de recurso da imagem será exibida no botão do aplicativo.  
  
 [in] `hBmp`  
 Um identificador para um bitmap a ser exibido no botão do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para atribuir uma nova imagem para o botão faixa de opções do aplicativo depois de criar o botão. O botão do aplicativo está localizado no canto superior esquerdo da janela do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

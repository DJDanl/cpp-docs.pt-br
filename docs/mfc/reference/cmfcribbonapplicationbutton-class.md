---
title: Classe CMFCRibbonApplicationButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonApplicationButton
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonApplicationButton class
ms.assetid: beb81757-fabd-4641-9130-876ba8505b78
caps.latest.revision: 25
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: a6fc19c2af854f3cd4ee3dc3a3008abcb4714ba3
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonapplicationbutton-class"></a>Classe CMFCRibbonApplicationButton
Implementa um botão especial localizado no canto superior esquerdo da janela do aplicativo. Quando clicado, o botão abre um menu que geralmente contém comuns **arquivo** comandos como **abrir**, **salvar**, e **Exit**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonApplicationButton : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonApplicationButton::CMFCRibbonApplicationButton](#cmfcribbonapplicationbutton)|Constrói e inicializa um objeto `CMFCRibbonApplicationButton`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonApplicationButton::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|`CMFCRibbonApplicationButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCRibbonApplicationButton::SetImage](#setimage)|Atribui uma imagem para o botão do aplicativo de faixa de opções.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonApplicationButton` classe. O exemplo mostra como atribuir uma imagem para o botão do aplicativo e como definir sua dica de ferramenta. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient n º&4;](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_1.h)]  
[!code-cpp[NVC_MFC_DrawClient n º&5;](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonBar.h  
  
##  <a name="a-namecmfcribbonapplicationbuttona--cmfcribbonapplicationbuttoncmfcribbonapplicationbutton"></a><a name="cmfcribbonapplicationbutton"></a>CMFCRibbonApplicationButton::CMFCRibbonApplicationButton  
 Constrói e inicializa um [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md) objeto.  
  
```  
CMFCRibbonApplicationButton();  
CMFCRibbonApplicationButton(UINT uiBmpResID);  
  CMFCRibbonApplicationButton(HBITMAP hBmp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uiBmpResID`  
 A ID de recurso da imagem para exibir o botão de aplicativo.  
  
 `hBmp`  
 Um identificador para um bitmap para exibir o botão de aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Botão de aplicativo da faixa de opções é um botão especial que está localizado no canto superior esquerdo da janela do aplicativo. Quando um usuário clica nesse botão, o aplicativo abre um menu que geralmente contém comuns **arquivo** comandos, como **abrir**, **salvar**, e **Exit**.  
  
##  <a name="a-namesetimagea--cmfcribbonapplicationbuttonsetimage"></a><a name="setimage"></a>CMFCRibbonApplicationButton::SetImage  
 Atribui uma imagem para o botão do aplicativo.  
  
```  
void SetImage(UINT uiBmpResID);  
void SetImage(HBITMAP hBmp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiBmpResID`  
 A ID de recurso da imagem para exibir o botão de aplicativo.  
  
 [in] `hBmp`  
 Um identificador para um bitmap para exibir o botão de aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para atribuir uma nova imagem para o botão faixa de opções do aplicativo depois de criar o botão. O botão do aplicativo está localizado no canto superior esquerdo da janela do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)


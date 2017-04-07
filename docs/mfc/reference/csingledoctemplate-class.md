---
title: Classe CSingleDocTemplate | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSingleDocTemplate
- AFXWIN/CSingleDocTemplate
- AFXWIN/CSingleDocTemplate::CSingleDocTemplate
dev_langs:
- C++
helpviewer_keywords:
- templates, SDI
- document templates, single
- single document interface (SDI), applications
- CSingleDocTemplate class
ms.assetid: 4f3a8212-81ee-48a0-ad22-e0ed7c36a391
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
ms.openlocfilehash: 78e288dd958e73495a8d513d7fe3427ccc956a61
ms.lasthandoff: 02/25/2017

---
# <a name="csingledoctemplate-class"></a>Classe CSingleDocTemplate
Define um modelo de documento que implementa a interface de documento único (SDI).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSingleDocTemplate : public CDocTemplate  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSingleDocTemplate::CSingleDocTemplate](#csingledoctemplate)|Constrói um objeto `CSingleDocTemplate`.|  
  
## <a name="remarks"></a>Comentários  
 Um aplicativo de SDI usa a janela do quadro principal para exibir um documento. apenas um documento pode ser aberto por vez.  
  
 Um modelo de documento define a relação entre três tipos de classes:  
  
-   Uma classe de documento, que derivam de **CDocument**.  
  
-   Uma classe de exibição, que exibe dados de classe de documento listada acima. Você pode derivar dessa classe de `CView`, `CScrollView`, `CFormView`, ou `CEditView`. (Você também pode usar `CEditView` diretamente.)  
  
-   Uma classe de janela de quadro, que contém a exibição. Para um modelo de documento de SDI, você pode derivar dessa classe de `CFrameWnd`; se você não precisa personalizar o comportamento do principal janela do quadro, você pode usar `CFrameWnd` diretamente sem sua própria classe.  
  
 Um aplicativo SDI geralmente oferece suporte a um tipo de documento, para que ele tenha apenas um `CSingleDocTemplate` objeto. Apenas um documento pode ser aberto por vez.  
  
 Você não precisa chamar qualquer função de membro `CSingleDocTemplate` exceto o construtor. Os identificadores de framework `CSingleDocTemplate` objetos internamente.  
  
 Para obter mais informações sobre como usar o `CSingleDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocTemplate](../../mfc/reference/cdoctemplate-class.md)  
  
 `CSingleDocTemplate`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="csingledoctemplate"></a>CSingleDocTemplate::CSingleDocTemplate  
 Constrói um objeto `CSingleDocTemplate`.  
  
```  
CSingleDocTemplate(
    UINT nIDResource,  
    CRuntimeClass* pDocClass,  
    CRuntimeClass* pFrameClass,  
    CRuntimeClass* pViewClass);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDResource`  
 Especifica a identificação dos recursos usados com o tipo de documento. Isso pode incluir o menu, ícone, tabela de Aceleradores e recursos de cadeia de caracteres.  
  
 O recurso de cadeia de caracteres consiste em até sete subcadeias de caracteres separadas pelo caractere '\n' (o caractere '\n' é necessário como um espaço reservado se uma subcadeia de caracteres não estiver incluída; no entanto, os caracteres '\n' à direita não são necessários); Esses subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). Esse recurso de cadeia de caracteres é encontrado no arquivo de recurso do aplicativo. Por exemplo:  
  
 `// MYCALC.RC`  
  
 `STRINGTABLE PRELOAD DISCARDABLE`  
  
 `BEGIN`  
  
 `IDR_MAINFRAME "MyCalc Windows Application\nSheet\nWorksheet\n Worksheets (*.myc)\n.myc\nMyCalcSheet\n MyCalc Worksheet"`  
  
 `END`  
  
 Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira é exibida como uma única entrada no Editor de cadeia de caracteres, não como sete entradas separadas.  
  
 Para obter mais informações sobre esses tipos de recursos, consulte o [Editor de cadeia de caracteres](../../windows/string-editor.md).  
  
 `pDocClass`  
 Aponta para a `CRuntimeClass` objeto da classe do documento. Essa classe é um **CDocument**-definir para representar documentos de classe derivada.  
  
 `pFrameClass`  
 Aponta para a `CRuntimeClass` objeto da classe de janela de quadro. Essa classe pode ser um `CFrameWnd`-classe derivada, ou pode ser `CFrameWnd` em si, se você quiser o comportamento padrão para a janela do quadro principal.  
  
 `pViewClass`  
 Aponta para a `CRuntimeClass` objeto da classe de exibição. Essa classe é um `CView`-definir para exibir seus documentos de classe derivada.  
  
### <a name="remarks"></a>Comentários  
 Alocar dinamicamente um `CSingleDocTemplate` de objeto e passá-lo para `CWinApp::AddDocTemplate` do `InitInstance` a função de membro da classe de seu aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI&13;](../../mfc/codesnippet/cpp/csingledoctemplate-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCDocViewSDI&#14;](../../mfc/codesnippet/cpp/csingledoctemplate-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DOCKTOOL](../../visual-cpp-samples.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe de CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)


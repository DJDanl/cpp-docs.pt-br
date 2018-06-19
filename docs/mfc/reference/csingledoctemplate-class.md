---
title: Classe CSingleDocTemplate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSingleDocTemplate
- AFXWIN/CSingleDocTemplate
- AFXWIN/CSingleDocTemplate::CSingleDocTemplate
dev_langs:
- C++
helpviewer_keywords:
- CSingleDocTemplate [MFC], CSingleDocTemplate
ms.assetid: 4f3a8212-81ee-48a0-ad22-e0ed7c36a391
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 413b7b4a7cf11ff7e83596ecc61423d4bc4f0358
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33371615"
---
# <a name="csingledoctemplate-class"></a>Classe CSingleDocTemplate
Define um modelo de documento que implementa a interface de documento único (SDI).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSingleDocTemplate : public CDocTemplate  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSingleDocTemplate::CSingleDocTemplate](#csingledoctemplate)|Constrói um objeto `CSingleDocTemplate`.|  
  
## <a name="remarks"></a>Comentários  
 Um aplicativo SDI usa a janela do quadro principal para exibir um documento. apenas um documento pode ser aberto por vez.  
  
 Um modelo de documento define a relação entre três tipos de classes:  
  
-   Uma classe de documento, que derivam de **CDocument**.  
  
-   Uma classe de exibição, que exibe dados de classe de documento listado acima. Você pode derivar dessa classe de `CView`, `CScrollView`, `CFormView`, ou `CEditView`. (Você também pode usar `CEditView` diretamente.)  
  
-   Uma classe de janela de quadro, que contém a exibição. Para um modelo de documento SDI, você pode derivar dessa classe de `CFrameWnd`janela do quadro; se você não precisa personalizar o comportamento do principal, você pode usar `CFrameWnd` diretamente sem derivando sua própria classe.  
  
 Um aplicativo SDI geralmente oferece suporte a um tipo de documento, portanto, tem apenas um `CSingleDocTemplate` objeto. Apenas um documento pode ser aberto por vez.  
  
 Você não precisa chamadas de funções de qualquer membro `CSingleDocTemplate` exceto o construtor. Os identificadores de framework `CSingleDocTemplate` objetos internamente.  
  
 Para obter mais informações sobre como usar `CSingleDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocTemplate](../../mfc/reference/cdoctemplate-class.md)  
  
 `CSingleDocTemplate`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="csingledoctemplate"></a>  CSingleDocTemplate::CSingleDocTemplate  
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
 Especifica a ID dos recursos usados com o tipo de documento. Isso pode incluir recursos de cadeia de caracteres, ícone, tabela de Aceleradores e menu.  
  
 O recurso de cadeia de caracteres consiste em subcadeias de caracteres até sete separadas pelo caractere '\n' (o caractere '\n' é necessário como um espaço reservado, se uma subcadeia de caracteres não estiver incluída; no entanto, não são necessários caracteres à direita de '\n'); Esses subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). Esse recurso de cadeia de caracteres foi encontrado no arquivo de recurso do aplicativo. Por exemplo:  
  
 `// MYCALC.RC`  
  
 `STRINGTABLE PRELOAD DISCARDABLE`  
  
 `BEGIN`  
  
 `IDR_MAINFRAME "MyCalc Windows Application\nSheet\nWorksheet\n Worksheets (*.myc)\n.myc\nMyCalcSheet\n MyCalc Worksheet"`  
  
 `END`  
  
 Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira é exibida como uma única entrada no Editor de cadeia de caracteres, não como sete entradas separadas.  
  
 Para obter mais informações sobre esses tipos de recursos, consulte o [Editor de cadeia de caracteres](../../windows/string-editor.md).  
  
 `pDocClass`  
 Aponta para o `CRuntimeClass` objeto da classe do documento. Essa classe é um **CDocument**-definir para representar documentos de classe derivada.  
  
 `pFrameClass`  
 Aponta para o `CRuntimeClass` objeto da classe de janela do quadro. Essa classe pode ser um `CFrameWnd`-classe derivada, ou pode ser `CFrameWnd` em si, se você quiser o comportamento padrão para a janela do quadro principal.  
  
 `pViewClass`  
 Aponta para o `CRuntimeClass` objeto da classe de exibição. Essa classe é um `CView`-definir para exibir seus documentos de classe derivada.  
  
### <a name="remarks"></a>Comentários  
 Alocar dinamicamente um `CSingleDocTemplate` de objeto e passá-lo para `CWinApp::AddDocTemplate` do `InitInstance` a função de membro da classe do aplicativo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI#13](../../mfc/codesnippet/cpp/csingledoctemplate-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCDocViewSDI#14](../../mfc/codesnippet/cpp/csingledoctemplate-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DOCKTOOL](../../visual-cpp-samples.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)

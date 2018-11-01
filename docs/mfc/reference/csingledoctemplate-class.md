---
title: Classe CSingleDocTemplate
ms.date: 11/04/2016
f1_keywords:
- CSingleDocTemplate
- AFXWIN/CSingleDocTemplate
- AFXWIN/CSingleDocTemplate::CSingleDocTemplate
helpviewer_keywords:
- CSingleDocTemplate [MFC], CSingleDocTemplate
ms.assetid: 4f3a8212-81ee-48a0-ad22-e0ed7c36a391
ms.openlocfilehash: fffaa57fc6c04f051b40021c89dc6aaccb343b38
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50435588"
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

- Uma classe de documento, que derivam de `CDocument`.

- Uma classe de exibição, que exibe dados de classe de documento listada acima. Você pode derivar desta classe de `CView`, `CScrollView`, `CFormView`, ou `CEditView`. (Você também pode usar `CEditView` diretamente.)

- Uma classe de janela de quadro, que contém a exibição. Para um modelo de documento de SDI, você pode derivar desta classe de `CFrameWnd`janela de quadro; se você não precisa personalizar o comportamento da janela principal, você pode usar `CFrameWnd` diretamente sem sua própria classe.

Um aplicativo SDI geralmente oferece suporte a um tipo de documento, portanto, tem apenas um `CSingleDocTemplate` objeto. Apenas um documento pode ser aberto por vez.

Você não precisa chamar qualquer função de membro `CSingleDocTemplate` , exceto o construtor. Os identificadores de framework `CSingleDocTemplate` objetos internamente.

Para obter mais informações sobre como usar `CSingleDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocTemplate](../../mfc/reference/cdoctemplate-class.md)

`CSingleDocTemplate`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

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

*nIDResource*<br/>
Especifica a identificação dos recursos usados com o tipo de documento. Isso pode incluir recursos de cadeia de caracteres, ícone, tabela de Aceleradores e menu.

O recurso de cadeia de caracteres consiste em subcadeias de caracteres até sete separadas pelo caractere '\n' (o caractere '\n' é necessário como um espaço reservado, se uma subcadeia de caracteres não for incluída; no entanto, não são necessários de caracteres à direita de '\n'); Esses subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). Esse recurso de cadeia de caracteres for encontrado no arquivo de recurso do aplicativo. Por exemplo:

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_MAINFRAME "MyCalc Windows Application\nSheet\nWorksheet\n Worksheets (*.myc)\n.myc\nMyCalcSheet\n MyCalc Worksheet"
END
```

Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira é exibido como uma única entrada no Editor de cadeia de caracteres, não como sete entradas separadas.

Para obter mais informações sobre esses tipos de recursos, consulte a [Editor de cadeia de caracteres](../../windows/string-editor.md).

*pDocClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe do documento. Essa classe é um `CDocument`-derivado da classe que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe de janela do quadro. Essa classe pode ser um `CFrameWnd`-classe derivada, ou pode ser `CFrameWnd` em si, se você quiser o comportamento padrão para a janela do quadro principal.

*pViewClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe de exibição. Essa classe é um `CView`-derivado da classe que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Alocar dinamicamente um `CSingleDocTemplate` do objeto e passá-lo para `CWinApp::AddDocTemplate` do `InitInstance` função de membro de sua classe de aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocViewSDI#13](../../mfc/codesnippet/cpp/csingledoctemplate-class_1.cpp)]

[!code-cpp[NVC_MFCDocViewSDI#14](../../mfc/codesnippet/cpp/csingledoctemplate-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC DOCKTOOL](../../visual-cpp-samples.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)

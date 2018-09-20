---
title: Classe CMultiDocTemplate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMultiDocTemplate
- AFXWIN/CMultiDocTemplate
- AFXWIN/CMultiDocTemplate::CMultiDocTemplate
dev_langs:
- C++
helpviewer_keywords:
- CMultiDocTemplate [MFC], CMultiDocTemplate
ms.assetid: 5b8aa328-e461-41d0-b388-00594535e119
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e0a3c7c301feecaf00fbf2dffcd6288b11ecfc7b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380809"
---
# <a name="cmultidoctemplate-class"></a>Classe CMultiDocTemplate

Define um modelo de documento que implementa o interface de documentos múltiplos (MDI).

## <a name="syntax"></a>Sintaxe

```
class CMultiDocTemplate : public CDocTemplate
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiDocTemplate::CMultiDocTemplate](#cmultidoctemplate)|Constrói um objeto `CMultiDocTemplate`.|

## <a name="remarks"></a>Comentários

Um aplicativo MDI usa a janela do quadro principal como um espaço de trabalho no qual o usuário pode abrir janelas de quadro de documento zero ou mais, cada um deles exibindo um documento. Para obter uma descrição mais detalhada da MDI, consulte *Windows Interface Guidelines for Software Design*.

Um modelo de documento define as relações entre os três tipos de classes:

- Uma classe de documento, que derivam de [CDocument](../../mfc/reference/cdocument-class.md).

- Uma classe de exibição, que exibe dados de classe de documento listada acima. Você pode derivar desta classe de [CView](../../mfc/reference/cview-class.md), `CScrollView`, `CFormView`, ou `CEditView`. (Você também pode usar `CEditView` diretamente.)

- Uma classe de janela de quadro, que contém a exibição. Para um modelo de documento MDI, você pode derivar desta classe de `CMDIChildWnd`, ou, se você não precisa personalizar o comportamento de janelas com moldura de documento, você pode usar [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) diretamente sem sua própria classe.

Um aplicativo MDI pode dar suporte a mais de um tipo de documento e documentos de tipos diferentes podem ser abertos ao mesmo tempo. Seu aplicativo tem um modelo de documento para cada tipo de documento que ela dá suporte. Por exemplo, se seu aplicativo MDI dá suporte a planilhas e documentos de texto, o aplicativo tem dois `CMultiDocTemplate` objetos.

O aplicativo usa o modelo de documento (s) quando o usuário cria um novo documento. Se o aplicativo dá suporte a mais de um tipo de documento, o framework obtém os nomes dos tipos de documento com suporte os modelos de documento e exibe-os em uma lista na caixa de diálogo Novo arquivo. Depois que o usuário tiver selecionado um tipo de documento, o aplicativo cria um objeto de classe de documento, um objeto de janela de quadro e um objeto de exibição e anexa-os uns aos outros.

Você não precisa chamar qualquer função de membro `CMultiDocTemplate` , exceto o construtor. Os identificadores de framework `CMultiDocTemplate` objetos internamente.

Para obter mais informações sobre `CMultiDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocTemplate](../../mfc/reference/cdoctemplate-class.md)

`CMultiDocTemplate`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cmultidoctemplate"></a>  CMultiDocTemplate::CMultiDocTemplate

Constrói um objeto `CMultiDocTemplate`.

```
CMultiDocTemplate(
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
  IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"
END
```

Observe que a cadeia de caracteres começa com um caractere '\n'; Isso ocorre porque a primeira subcadeia de caracteres não é usada para aplicativos MDI e portanto, não está incluída. Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira é exibido como uma única entrada no Editor de cadeia de caracteres, não como sete entradas separadas.

Para obter mais informações sobre esses tipos de recursos, consulte [editores de recursos](../../windows/resource-editors.md).

*pDocClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe do documento. Essa classe é um `CDocument`-derivado da classe que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe de janela do quadro. Essa classe pode ser um `CMDIChildWnd`-classe derivada, ou pode ser `CMDIChildWnd` em si, se você quiser o comportamento padrão para as janelas de quadro do documento.

*pViewClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe de exibição. Essa classe é um `CView`-derivado da classe que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Alocar dinamicamente um `CMultiDocTemplate` objeto para cada tipo de documento que seu aplicativo dá suporte a e passar cada um deles `CWinApp::AddDocTemplate` do `InitInstance` função de membro de sua classe de aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#92](../../mfc/codesnippet/cpp/cmultidoctemplate-class_1.cpp)]

Aqui está um exemplo de segundo.

[!code-cpp[NVC_MFCDocView#93](../../mfc/codesnippet/cpp/cmultidoctemplate-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)

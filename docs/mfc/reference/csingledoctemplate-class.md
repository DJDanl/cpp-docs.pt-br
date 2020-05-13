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
ms.openlocfilehash: 5a014b35a6cd2d12367e190e4d6dd689e28eae66
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318343"
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

Um aplicativo SDI usa a janela do quadro principal para exibir um documento; apenas um documento pode ser aberto de cada vez.

Um modelo de documento define a relação entre três tipos de classes:

- Uma classe de documentos, `CDocument`da qual você deriva.

- Uma classe de exibição, que exibe dados da classe de documento listada acima. Você pode derivar `CView` `CScrollView`esta `CFormView`classe `CEditView`de, ou . (Você também `CEditView` pode usar diretamente.)

- Uma classe de janela de quadro, que contém a vista. Para um modelo de documento SDI, `CFrameWnd`você pode derivar esta classe de ; se você não precisar personalizar o comportamento da janela `CFrameWnd` principal do quadro, você pode usar diretamente sem derivar sua própria classe.

Um aplicativo SDI normalmente suporta um tipo de documento, por isso tem apenas um `CSingleDocTemplate` objeto. Apenas um documento pode ser aberto de cada vez.

Você não precisa chamar nenhuma função `CSingleDocTemplate` membro de exceto o construtor. A estrutura `CSingleDocTemplate` lida com objetos internamente.

Para obter mais `CSingleDocTemplate`informações sobre como usar, consulte [Modelos de documentos e o processo de criação de documentos/visualização.](../../mfc/document-templates-and-the-document-view-creation-process.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdoctemplate](../../mfc/reference/cdoctemplate-class.md)

`CSingleDocTemplate`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="csingledoctemplatecsingledoctemplate"></a><a name="csingledoctemplate"></a>CSingleDocTemplate::CSingleDocTemplate

Constrói um objeto `CSingleDocTemplate`.

```
CSingleDocTemplate(
    UINT nIDResource,
    CRuntimeClass* pDocClass,
    CRuntimeClass* pFrameClass,
    CRuntimeClass* pViewClass);
```

### <a name="parameters"></a>Parâmetros

*Nidresource*<br/>
Especifica o ID dos recursos utilizados com o tipo de documento. Isso pode incluir menu, ícone, tabela de acelerador e recursos de string.

O recurso string consiste em até sete substrings separadas pelo caractere '\n' (o caractere '\n' é necessário como espaço reservado se uma substring não estiver incluída; no entanto, caracteres '\n' não são necessários); essas substrings descrevem o tipo de documento. Para obter informações sobre as substrings, consulte [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). Esse recurso de string é encontrado no arquivo de recursos do aplicativo. Por exemplo:

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_MAINFRAME "MyCalc Windows Application\nSheet\nWorksheet\n Worksheets (*.myc)\n.myc\nMyCalcSheet\n MyCalc Worksheet"
END
```

Você pode editar esta seqüência usando o editor de seqüência; toda a seqüência aparece como uma única entrada no Editor de cordas, não como sete entradas separadas.

Para obter mais informações sobre esses tipos de recursos, consulte o [Editor de cordas](../../windows/string-editor.md).

*pDocClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe de documentos. Esta classe `CDocument`é uma classe derivada que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe da janela do quadro. Esta classe pode `CFrameWnd`ser uma classe derivada, ou pode ser `CFrameWnd` ela mesma se você quiser comportamento padrão para a janela do quadro principal.

*pViewClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe de exibição. Esta classe `CView`é uma classe derivada que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Aloque `CSingleDocTemplate` dinamicamente `CWinApp::AddDocTemplate` um `InitInstance` objeto e passe-o para a função membro da sua classe de aplicação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocViewSDI#13](../../mfc/codesnippet/cpp/csingledoctemplate-class_1.cpp)]

[!code-cpp[NVC_MFCDocViewSDI#14](../../mfc/codesnippet/cpp/csingledoctemplate-class_2.cpp)]

## <a name="see-also"></a>Confira também

[DockTOOL de amostra De MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)

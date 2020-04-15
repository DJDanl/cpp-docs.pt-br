---
title: Classe CMultiDocTemplate
ms.date: 11/04/2016
f1_keywords:
- CMultiDocTemplate
- AFXWIN/CMultiDocTemplate
- AFXWIN/CMultiDocTemplate::CMultiDocTemplate
helpviewer_keywords:
- CMultiDocTemplate [MFC], CMultiDocTemplate
ms.assetid: 5b8aa328-e461-41d0-b388-00594535e119
ms.openlocfilehash: 3b3f239b05b1cf7661929333e2d616acce6bedb0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319739"
---
# <a name="cmultidoctemplate-class"></a>Classe CMultiDocTemplate

Define um modelo de documento que implementa a interface de documento múltiplo (MDI).

## <a name="syntax"></a>Sintaxe

```
class CMultiDocTemplate : public CDocTemplate
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiDocTemplate::CMultiDocTemplate](#cmultidoctemplate)|Constrói um objeto `CMultiDocTemplate`.|

## <a name="remarks"></a>Comentários

Um aplicativo MDI usa a janela do quadro principal como um espaço de trabalho no qual o usuário pode abrir zero ou mais janelas de quadro de documento, cada uma das quais exibe um documento. Para obter uma descrição mais detalhada do MDI, consulte *As Diretrizes*de Interface do Windows para design de software .

Um modelo de documento define as relações entre três tipos de classes:

- Uma classe de documento, que você deriva de [CDocument](../../mfc/reference/cdocument-class.md).

- Uma classe de exibição, que exibe dados da classe de documento listada acima. Você pode derivar esta `CScrollView`classe `CFormView`de `CEditView` [CView,](../../mfc/reference/cview-class.md)ou . (Você também `CEditView` pode usar diretamente.)

- Uma classe de janela de quadro, que contém a vista. Para um modelo de documento MDI, `CMDIChildWnd`você pode derivar essa classe de , ou, se você não precisar personalizar o comportamento das janelas do quadro de documentos, você pode usar [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) diretamente sem derivar sua própria classe.

Um aplicativo MDI pode suportar mais de um tipo de documento, e documentos de diferentes tipos podem ser abertos ao mesmo tempo. Seu aplicativo tem um modelo de documento para cada tipo de documento que ele suporta. Por exemplo, se o aplicativo MDI suportar planilhas e `CMultiDocTemplate` documentos de texto, o aplicativo tem dois objetos.

O aplicativo usa os modelos de documentos quando o usuário cria um novo documento. Se o aplicativo suportar mais de um tipo de documento, o framework obtém os nomes dos tipos de documento suportados dos modelos de documento e os exibe em uma lista na caixa de diálogo Arquivo Novo. Uma vez que o usuário tenha selecionado um tipo de documento, o aplicativo cria um objeto de classe de documento, um objeto de janela de quadro e um objeto de exibição e os anexa entre si.

Você não precisa chamar nenhuma função `CMultiDocTemplate` membro de exceto o construtor. A estrutura `CMultiDocTemplate` lida com objetos internamente.

Para obter `CMultiDocTemplate`mais informações, consulte [Modelos de documentos e o processo de criação de documentos/visualização.](../../mfc/document-templates-and-the-document-view-creation-process.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdoctemplate](../../mfc/reference/cdoctemplate-class.md)

`CMultiDocTemplate`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cmultidoctemplatecmultidoctemplate"></a><a name="cmultidoctemplate"></a>CMultiDocTemplate::CMultiDocTemplate

Constrói um objeto `CMultiDocTemplate`.

```
CMultiDocTemplate(
    UINT nIDResource,
    CRuntimeClass* pDocClass,
    CRuntimeClass* pFrameClass,
    CRuntimeClass* pViewClass);
```

### <a name="parameters"></a>Parâmetros

*Nidresource*<br/>
Especifica o ID dos recursos utilizados com o tipo de documento. Isso pode incluir menu, ícone, tabela de acelerador e recursos de string.

O recurso de seqüência consiste em até sete substringões separadas pelo caractere '\n' (o caractere '\n' é necessário como titular de lugar se uma substring não estiver incluída; no entanto, caracteres '\n' não são necessários); essas substrings descrevem o tipo de documento. Para obter informações sobre as substrings, consulte [CDocTemplate::GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). Esse recurso de string é encontrado no arquivo de recursos do aplicativo. Por exemplo:

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"
END
```

Observe que a seqüência começa com um caractere '\n'; isso porque a primeira substring não é usada para aplicações MDI e, portanto, não está incluída. Você pode editar esta seqüência usando o editor de seqüência; toda a seqüência aparece como uma única entrada no Editor de cordas, não como sete entradas separadas.

Para obter mais informações sobre esses tipos de recursos, consulte [Resource Editors](../../windows/resource-editors.md).

*pDocClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe de documentos. Esta classe `CDocument`é uma classe derivada que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe frame-window. Esta classe pode `CMDIChildWnd`ser uma classe derivada, ou pode ser `CMDIChildWnd` ela mesma se você quiser comportamento padrão para as janelas do quadro de documentos.

*pViewClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe de exibição. Esta classe `CView`é uma classe derivada que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Aloque `CMultiDocTemplate` dinamicamente um objeto para cada tipo `CWinApp::AddDocTemplate` de `InitInstance` documento que seu aplicativo suporta e passe cada um para a função de membro da sua classe de aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#92](../../mfc/codesnippet/cpp/cmultidoctemplate-class_1.cpp)]

Aqui está um segundo exemplo.

[!code-cpp[NVC_MFCDocView#93](../../mfc/codesnippet/cpp/cmultidoctemplate-class_2.cpp)]

## <a name="see-also"></a>Confira também

[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)

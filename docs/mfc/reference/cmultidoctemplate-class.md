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
ms.openlocfilehash: af950d188c4e02a38a39ed3c672f0f8c4161bee8
ms.sourcegitcommit: 8fd49f8ac20457710ceb5403ca46fc73cb3f95f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/01/2020
ms.locfileid: "85737479"
---
# <a name="cmultidoctemplate-class"></a>Classe CMultiDocTemplate

Define um modelo de documento que implementa a interface de vários documentos (MDI).

## <a name="syntax"></a>Syntax

```
class CMultiDocTemplate : public CDocTemplate
```

## <a name="members"></a>Membros

As funções de membro para essa classe são virtuais. Consulte [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) e [CCmdTarget](../../mfc/reference/ccmdtarget-class.md) para obter a documentação.

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|[CMultiDocTemplate::CMultiDocTemplate](#cmultidoctemplate)|Constrói um objeto `CMultiDocTemplate`.|

## <a name="remarks"></a>Comentários

Um aplicativo MDI usa a janela principal do quadro como um espaço de trabalho no qual o usuário pode abrir zero ou mais janelas de quadro de documento, cada uma delas exibe um documento. Para obter uma descrição mais detalhada do MDI, consulte *diretrizes de interface do Windows para o design de software*.

Um modelo de documento define as relações entre três tipos de classes:

- Uma classe de documento, que você deriva de [CDocument](../../mfc/reference/cdocument-class.md).

- Uma classe de exibição, que exibe dados da classe de documento listada acima. Você pode derivar essa classe de [cvisualização](../../mfc/reference/cview-class.md), `CScrollView` , `CFormView` ou `CEditView` . (Você também pode usar `CEditView` diretamente.)

- Uma classe de janela do quadro, que contém a exibição. Para um modelo de documento MDI, você pode derivar essa classe de `CMDIChildWnd` ou, se não precisar personalizar o comportamento das janelas de quadros de documento, poderá usar [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) diretamente sem derivar sua própria classe.

Um aplicativo MDI pode dar suporte a mais de um tipo de documento, e documentos de tipos diferentes podem ser abertos ao mesmo tempo. Seu aplicativo tem um modelo de documento para cada tipo de documento ao qual ele dá suporte. Por exemplo, se seu aplicativo MDI oferecer suporte a planilhas e documentos de texto, o aplicativo terá dois `CMultiDocTemplate` objetos.

O aplicativo usa os modelos de documento quando o usuário cria um novo documento. Se o aplicativo oferecer suporte a mais de um tipo de documento, a estrutura obterá os nomes dos tipos de documento com suporte nos modelos de documento e os exibirá em uma lista na caixa de diálogo arquivo novo. Depois que o usuário tiver selecionado um tipo de documento, o aplicativo criará um objeto de classe de documento, um objeto de janela de quadro e um objeto de exibição e os anexará entre si.

Você não precisa chamar nenhuma função de membro de `CMultiDocTemplate` , exceto o construtor. A estrutura manipula `CMultiDocTemplate` objetos internamente.

Para obter mais informações sobre `CMultiDocTemplate` o, consulte [modelos de documentos e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocTemplate](../../mfc/reference/cdoctemplate-class.md)

`CMultiDocTemplate`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

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

*nIDResource*<br/>
Especifica a ID dos recursos usados com o tipo de documento. Isso pode incluir o menu, ícone, tabela de aceleração e recursos de cadeia de caracteres.

O recurso de cadeia de caracteres consiste em até sete subcadeias de caracteres separadas pelo caractere "\n" (o caractere "\n" é necessário como um espaço reservado se uma subcadeia de caracteres não estiver incluída; no entanto, os caracteres "\n" à direita não são necessários); essas subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [CDocTemplate:: GetDocString](../../mfc/reference/cdoctemplate-class.md#getdocstring). Esse recurso de cadeia de caracteres é encontrado no arquivo de recursos do aplicativo. Por exemplo:

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"
END
```

A cadeia de caracteres começa com um caractere ' \n ' porque a primeira subcadeia de caracteres não é usada para aplicativos MDI e, portanto, não está incluída. Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira aparece como uma única entrada no editor de cadeia de caracteres, não como sete entradas separadas.

Para obter mais informações sobre esses tipos de recursos, consulte [editores de recursos](../../windows/resource-editors.md).

*pDocClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe de documento. Essa classe é uma `CDocument` classe derivada que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe de janela de quadro. Essa classe pode ser uma `CMDIChildWnd` classe derivada ou pode ser ela `CMDIChildWnd` própria se você quiser o comportamento padrão para as janelas do quadro do documento.

*pViewClass*<br/>
Aponta para o `CRuntimeClass` objeto da classe View. Essa classe é uma `CView` classe derivada que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Aloque dinamicamente um `CMultiDocTemplate` objeto para cada tipo de documento ao qual seu aplicativo dá suporte e passe cada um deles a `CWinApp::AddDocTemplate` partir da `InitInstance` função membro de sua classe de aplicativo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#92](../../mfc/codesnippet/cpp/cmultidoctemplate-class_1.cpp)]

Este é um segundo exemplo.

[!code-cpp[NVC_MFCDocView#93](../../mfc/codesnippet/cpp/cmultidoctemplate-class_2.cpp)]

## <a name="see-also"></a>Veja também

[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)<br/>
[Classe CWinApp](../../mfc/reference/cwinapp-class.md)

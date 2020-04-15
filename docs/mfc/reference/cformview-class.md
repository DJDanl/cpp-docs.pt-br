---
title: Classe CFormView
ms.date: 11/04/2016
f1_keywords:
- CFormView
- AFXEXT/CFormView
- AFXEXT/CFormView::CFormView
- AFXEXT/CFormView::IsInitDlgCompleted
helpviewer_keywords:
- CFormView [MFC], CFormView
- CFormView [MFC], IsInitDlgCompleted
ms.assetid: a99ec313-36f0-4f28-9d2b-de11de14ac19
ms.openlocfilehash: a9b897c661731878f0bf78c9d04ae7c4ba28cd42
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373794"
---
# <a name="cformview-class"></a>Classe CFormView

A classe base usada para visualizações de formulários.

## <a name="syntax"></a>Sintaxe

```
class CFormView : public CScrollView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CformView::CFormView](#cformview)|Constrói um objeto `CFormView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFormView::IsInitDlgCompleted](#isinitdlgcompleted)|Usado para sincronização durante a inicialização.|

## <a name="remarks"></a>Comentários

Uma visão de formulário é essencialmente uma visão que contém controles. Esses controles são definidos com base em um recurso de modelo de diálogo. Use `CFormView` se quiser formulários em sua aplicação. Essas visualizações suportam rolagem, conforme necessário, usando a funcionalidade [CScrollView.](../../mfc/reference/cscrollview-class.md)

Quando você está [criando um aplicativo baseado em formulários,](../../mfc/reference/creating-a-forms-based-mfc-application.md)você pode basear sua classe de exibição, `CFormView`tornando-a um aplicativo baseado em formulários.

Você também pode inserir novos [Tópicos de Formulário](../../mfc/form-views-mfc.md) em aplicativos baseados em exibição de documentos. Mesmo que seu aplicativo não tenha suportado inicialmente formulários, o Visual C++ adicionará esse suporte quando você inserir um novo formulário.

O Assistente de Aplicativo MFC e o comando Adicionar classe são os métodos preferidos para criar aplicativos baseados em formulários. Se você precisar criar um aplicativo baseado em formulários sem usar esses métodos, consulte [Criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

`CFormView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="cformviewcformview"></a><a name="cformview"></a>CformView::CFormView

Constrói um objeto `CFormView`.

```
CFormView(LPCTSTR lpszTemplateName);
CFormView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma seqüência de seqüência de terminadas nula que é o nome de um recurso de modelo de diálogo.

*Nidtemplate*<br/>
Contém o número de ID de um recurso de modelo de diálogo.

### <a name="remarks"></a>Comentários

Quando você criar um objeto de `CFormView`um tipo derivado, invoque um dos construtores para criar o objeto de exibição e identifique o recurso de diálogo no qual a exibição é baseada. Você pode identificar o recurso pelo nome (passar uma string como argumento para o construtor) ou pelo seu ID (passar um inteiro não assinado como argumento).

A janela de visualização de formulário e `CWnd::Create` os controles de criança não são criados até que seja chamado. `CWnd::Create`é chamado pelo framework como parte do processo de criação de documentos e visualização, que é impulsionado pelo modelo do documento.

> [!NOTE]
> Sua classe derivada *deve* fornecer seu próprio construtor. No construtor, invoque o `CFormView::CFormView`construtor, com o nome do recurso ou ID como argumento como mostrado na visão geral da classe anterior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#90](../../mfc/codesnippet/cpp/cformview-class_1.h)]

[!code-cpp[NVC_MFCDocView#91](../../mfc/codesnippet/cpp/cformview-class_2.cpp)]

## <a name="cformviewisinitdlgcompleted"></a><a name="isinitdlgcompleted"></a>CFormView::IsInitDlgConcluído

Usado pelo MFC para garantir que a inicialização seja concluída antes de realizar outras operações.

```
BOOL IsInitDlgCompleted() const;
```

### <a name="return-value"></a>Valor retornado

É verdade se a função de inicialização desta caixa de diálogo tiver sido concluída.

## <a name="see-also"></a>Confira também

[Amostra de MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra VIEWEX](../../overview/visual-cpp-samples.md)<br/>
[Classe CScrollView](../../mfc/reference/cscrollview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Classe CScrollView](../../mfc/reference/cscrollview-class.md)

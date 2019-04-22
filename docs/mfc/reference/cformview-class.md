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
ms.openlocfilehash: 8a0c11352ffab37f50ede5c67aa810fa20e838ed
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58777266"
---
# <a name="cformview-class"></a>Classe CFormView

A classe base usada para modos de exibição de formulário.

## <a name="syntax"></a>Sintaxe

```
class CFormView : public CScrollView
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CFormView::CFormView](#cformview)|Constrói um objeto `CFormView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFormView::IsInitDlgCompleted](#isinitdlgcompleted)|Usado para sincronização durante a inicialização.|

## <a name="remarks"></a>Comentários

Um modo de exibição de formulário é essencialmente uma exibição que contém controles. Esses controles são dispostos com base em um recurso de modelo de caixa de diálogo. Use `CFormView` se você quiser formulários em seu aplicativo. Essas exibições dão suporte à rolagem, conforme necessário, usando o [CScrollView](../../mfc/reference/cscrollview-class.md) funcionalidade.

Quando você estiver [criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md), você pode basear sua classe de exibição em `CFormView`, tornando-o um aplicativo baseado em formulários.

Você também pode inserir novas [tópicos de formulário](../../mfc/form-views-mfc.md) em aplicativos com base no modo de exibição de documento. Mesmo se seu aplicativo não oferecia suporte inicialmente formulários, o Visual C++ adicionará esse suporte quando você insere um novo formulário.

O Assistente de aplicativo do MFC e o comando Adicionar classe são os métodos preferenciais para a criação de aplicativos baseados em formulários. Se você precisar criar um aplicativo baseado em formulários sem usar esses métodos, consulte [criando um aplicativo baseado em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

`CFormView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="cformview"></a>  CFormView::CFormView

Constrói um objeto `CFormView`.

```
CFormView(LPCTSTR lpszTemplateName);
CFormView(UINT nIDTemplate);
```

### <a name="parameters"></a>Parâmetros

*lpszTemplateName*<br/>
Contém uma cadeia de caracteres terminada em nulo que é o nome de um recurso de modelo de caixa de diálogo.

*nIDTemplate*<br/>
Contém o número de identificação de um recurso de modelo de caixa de diálogo.

### <a name="remarks"></a>Comentários

Quando você cria um objeto de um tipo derivado de `CFormView`, chamar um dos construtores para criar o objeto de exibição e identificar o recurso de caixa de diálogo na qual o modo de exibição se baseia. Você pode identificar o recurso por nome (passar uma cadeia de caracteres como o argumento para o construtor) ou pela sua ID (um inteiro sem sinal, como o argumento de passagem).

Os controles de janela e o filho de exibição de formulário não são criados até `CWnd::Create` é chamado. `CWnd::Create` é chamado pelo framework como parte do processo de criação documento e exibição, que é controlado pelo modelo de documento.

> [!NOTE]
>  Sua classe derivada *deve* fornecer seu próprio construtor. No construtor, invocar o construtor, `CFormView::CFormView`, com o nome do recurso ou ID como um argumento, como mostra a visão geral da classe anterior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#90](../../mfc/codesnippet/cpp/cformview-class_1.h)]

[!code-cpp[NVC_MFCDocView#91](../../mfc/codesnippet/cpp/cformview-class_2.cpp)]

##  <a name="isinitdlgcompleted"></a>  CFormView::IsInitDlgCompleted

Usado pelo MFC para garantir que a inicialização seja concluída antes de executar outras operações.

```
BOOL IsInitDlgCompleted() const;
```

### <a name="return-value"></a>Valor de retorno

True se a função de inicialização para essa caixa de diálogo foi concluída.

## <a name="see-also"></a>Consulte também

[Exemplo MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC VIEWEX](../../overview/visual-cpp-samples.md)<br/>
[Classe CScrollView](../../mfc/reference/cscrollview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Classe CScrollView](../../mfc/reference/cscrollview-class.md)

---
title: Classe CEditView
ms.date: 11/04/2016
f1_keywords:
- CEditView
- AFXEXT/CEditView
- AFXEXT/CEditView::CEditView
- AFXEXT/CEditView::FindText
- AFXEXT/CEditView::GetBufferLength
- AFXEXT/CEditView::GetEditCtrl
- AFXEXT/CEditView::GetPrinterFont
- AFXEXT/CEditView::GetSelectedText
- AFXEXT/CEditView::LockBuffer
- AFXEXT/CEditView::PrintInsideRect
- AFXEXT/CEditView::SerializeRaw
- AFXEXT/CEditView::SetPrinterFont
- AFXEXT/CEditView::SetTabStops
- AFXEXT/CEditView::UnlockBuffer
- AFXEXT/CEditView::OnFindNext
- AFXEXT/CEditView::OnReplaceAll
- AFXEXT/CEditView::OnReplaceSel
- AFXEXT/CEditView::OnTextNotFound
- AFXEXT/CEditView::dwStyleDefault
helpviewer_keywords:
- CEditView [MFC], CEditView
- CEditView [MFC], FindText
- CEditView [MFC], GetBufferLength
- CEditView [MFC], GetEditCtrl
- CEditView [MFC], GetPrinterFont
- CEditView [MFC], GetSelectedText
- CEditView [MFC], LockBuffer
- CEditView [MFC], PrintInsideRect
- CEditView [MFC], SerializeRaw
- CEditView [MFC], SetPrinterFont
- CEditView [MFC], SetTabStops
- CEditView [MFC], UnlockBuffer
- CEditView [MFC], OnFindNext
- CEditView [MFC], OnReplaceAll
- CEditView [MFC], OnReplaceSel
- CEditView [MFC], OnTextNotFound
- CEditView [MFC], dwStyleDefault
ms.assetid: bf38255c-fcbe-450c-95b2-3c5e35f86c37
ms.openlocfilehash: 33b5975eea534eeaf308f73b5ca7fca2cd76787f
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753190"
---
# <a name="ceditview-class"></a>Classe CEditView

Um tipo de classe de exibição que fornece a funcionalidade de um controle de edição do Windows e pode ser usado para implementar funcionalidades simples de editor de texto.

## <a name="syntax"></a>Sintaxe

```
class CEditView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CeditView::CEditView](#ceditview)|Constrói um objeto do tipo `CEditView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CEditView::FindText](#findtext)|Procura uma seqüência dentro do texto.|
|[CeditView::GetBufferLength](#getbufferlength)|Obtém o comprimento do buffer de caracteres.|
|[CEditView::GetEditCtrl](#geteditctrl)|Fornece acesso `CEdit` à parte `CEditView` de um objeto (o controle de edição do Windows).|
|[CeditView::GetPrinterFont](#getprinterfont)|Recupera a fonte atual da impressora.|
|[Ceditview::GetSelectedText](#getselectedtext)|Recupera a seleção de texto atual.|
|[CEditView::LockBuffer](#lockbuffer)|Bloqueia o tampão.|
|[CEditView::PrintInsideRect](#printinsiderect)|Renderiza texto dentro de um determinado retângulo.|
|[CEditView::SerializeRaw](#serializeraw)|Serializa um `CEditView` objeto para disco como texto bruto.|
|[CEditView::SetPrinterFont](#setprinterfont)|Define uma nova fonte de impressora.|
|[CeditView::Set's's](#settabstops)|Define as paradas de guia para exibição e impressão da tela.|
|[CEditView::UnlockBuffer](#unlockbuffer)|Desbloqueia o buffer.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CeditView::OnFindNext](#onfindnext)|Encontra a próxima ocorrência de uma seqüência de texto.|
|[CeditView::OnReplaceAll](#onreplaceall)|Substitui todas as ocorrências de uma determinada seqüência por uma nova seqüência.|
|[CeditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|
|[Ceditview::OnTextNotFound](#ontextnotfound)|Chamado quando uma operação de encontrar não corresponde a qualquer texto adicional.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CEditView::dwStyleDefault](#dwstyledefault)|Estilo padrão para `CEditView`objetos do tipo .|

## <a name="remarks"></a>Comentários

A `CEditView` classe fornece as seguintes funções adicionais:

- Imprimir.

- Encontre e substitua.

Como `CEditView` a classe é `CView`uma derivada da classe, objetos de classe `CEditView` podem ser usados com documentos e modelos de documentos.

O `CEditView` texto de cada controle é mantido em seu próprio objeto de memória global. Sua aplicação pode ter `CEditView` qualquer número de objetos.

Crie objetos `CEditView` de tipo se quiser uma janela de edição com a funcionalidade adicionada listada acima ou se você quiser uma funcionalidade simples de editor de texto. Um `CEditView` objeto pode ocupar toda a área do cliente de uma janela. Obtenha suas próprias classes `CEditView` para adicionar ou modificar a funcionalidade básica ou para declarar classes que podem ser adicionadas a um modelo de documento.

A implementação `CEditView` padrão da classe lida com os seguintes comandos: ID_EDIT_SELECT_ALL, ID_EDIT_FIND, ID_EDIT_REPLACE, ID_EDIT_REPEAT e ID_FILE_PRINT.

O limite de `CEditView` caractere padrão para \* é (1024 1024 - 1 = 1048575). Isso pode ser alterado chamando a função EM_LIMITTEXT do controle de edição subjacente. No entanto, os limites são diferentes dependendo do sistema operacional e do tipo de controle de edição (single ou multiline). Para obter mais informações sobre esses limites, consulte [EM_LIMITTEXT](/windows/win32/Controls/em-limittext).

Para alterar esse limite no seu `OnCreate()` controle, `CEditView` anule a função da sua classe e insira a seguinte linha de código:

[!code-cpp[NVC_MFCDocView#65](../../mfc/codesnippet/cpp/ceditview-class_1.cpp)]

Objetos `CEditView` de tipo (ou `CEditView`de tipos derivados) têm as seguintes limitações:

- `CEditView`não implementa a edição verdadeira do que você vê é o que você recebe (WYSIWYG) edição. Quando há uma escolha entre legibilidade na tela `CEditView` e saída impressa correspondente, opta pela legibilidade da tela.

- `CEditView`pode exibir texto em apenas uma fonte. Nenhuma formatação de caractere especial é suportada. Consulte a classe [CRichEditView](../../mfc/reference/cricheditview-class.md) para obter maiores recursos.

- A quantidade de `CEditView` texto que um pode conter é limitada. Os limites são os `CEdit` mesmos do controle.

Para obter `CEditView`mais informações sobre , consulte [Classes de exibição derivadas disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[Cctrlview](../../mfc/reference/cctrlview-class.md)

`CEditView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="ceditviewceditview"></a><a name="ceditview"></a>CeditView::CEditView

Constrói um objeto do tipo `CEditView`.

```
CEditView();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar a função [CWnd::Criar](../../mfc/reference/cwnd-class.md#create) antes que o controle de edição seja usado. Se você derivar `CEditView` uma classe e `CWinApp::AddDocTemplate`adicioná-la ao modelo usando, a estrutura chama tanto este construtor quanto a `Create` função.

## <a name="ceditviewdwstyledefault"></a><a name="dwstyledefault"></a>CEditView::dwStyleDefault

Contém o estilo `CEditView` padrão do objeto.

```
static const DWORD dwStyleDefault;
```

### <a name="remarks"></a>Comentários

Passe este membro estático como o parâmetro *dwStyle* da `Create` `CEditView` função para obter o estilo padrão para o objeto.

## <a name="ceditviewfindtext"></a><a name="findtext"></a>CEditView::FindText

Chame `FindText` a função `CEditView` para pesquisar o buffer de texto do objeto.

```
BOOL FindText(
    LPCTSTR lpszFind,
    BOOL bNext = TRUE,
    BOOL bCase = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser encontrado.

*bNext*<br/>
Especifica a direção da pesquisa. Se TRUE, a direção da pesquisa é no final do buffer. Se FALSO, a direção de busca é para o início do buffer.

*Bcase*<br/>
Especifica se a pesquisa é sensível ao caso. Se VERDADE, a busca é sensível ao caso. Se FALSO, a busca não é sensível ao caso.

### <a name="return-value"></a>Valor retornado

Não zero se o texto de pesquisa for encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função pesquisa o texto no buffer para o texto especificado pelo *lpszFind*, começando na seleção atual, na direção especificada por *bNext*, e com sensibilidade de caso especificada por *bCase*. Se o texto for encontrado, ele define a seleção para o texto encontrado e retorna um valor não zero. Se o texto não for encontrado, a função retorna 0.

Você normalmente não precisa `FindText` chamar a `OnFindNext`função a `FindText`menos que você anular, o que chama .

## <a name="ceditviewgetbufferlength"></a><a name="getbufferlength"></a>CeditView::GetBufferLength

Ligue para esta função de membro para obter o número de caracteres atualmente no buffer do controle de edição, sem incluir o exterminador nulo.

```
UINT GetBufferLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento da corda no buffer.

## <a name="ceditviewgeteditctrl"></a><a name="geteditctrl"></a>CEditView::GetEditCtrl

Chamada `GetEditCtrl` para obter uma referência ao controle de edição usado pela exibição de edição.

```
CEdit& GetEditCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência a um objeto `CEdit`.

### <a name="remarks"></a>Comentários

Este controle é do tipo [CEdit,](../../mfc/reference/cedit-class.md)então você pode `CEdit` manipular o controle de edição do Windows diretamente usando as funções do membro.

> [!CAUTION]
> O `CEdit` uso do objeto pode alterar o estado do controle de edição do Windows subjacente. Por exemplo, você não deve alterar as configurações da guia `CEditView` usando a função [CEdit::SetTabStops](../../mfc/reference/cedit-class.md#settabstops) porque armazena em cache essas configurações para uso tanto no controle de edição quanto na impressão. Em vez disso, use [CEditView::SetTabStops](#settabstops).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#66](../../mfc/codesnippet/cpp/ceditview-class_2.cpp)]

## <a name="ceditviewgetprinterfont"></a><a name="getprinterfont"></a>CeditView::GetPrinterFont

Chamada `GetPrinterFont` para obter um ponteiro para um objeto [CFont](../../mfc/reference/cfont-class.md) que descreve a fonte da impressora atual.

```
CFont* GetPrinterFont() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CFont` para um objeto que especifica a fonte da impressora atual; NULL se a fonte da impressora não tiver sido definida. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.

### <a name="remarks"></a>Comentários

Se a fonte da impressora não tiver sido `CEditView` definida, o comportamento de impressão padrão da classe será imprimir usando a mesma fonte usada para exibição.

Use esta função para determinar a fonte atual da impressora. Se não for a fonte de impressora desejada, use [CEditView::SetPrinterFont](#setprinterfont) para alterá-la.

## <a name="ceditviewgetselectedtext"></a><a name="getselectedtext"></a>Ceditview::GetSelectedText

Chamada `GetSelectedText` para copiar o `CString` texto selecionado em um objeto, até o final da seleção ou o caractere que precede o primeiro caractere de retorno de transporte na seleção.

```cpp
void GetSelectedText(CString& strResult) const;
```

### <a name="parameters"></a>Parâmetros

*strResult*<br/>
Uma referência `CString` ao objeto que deve receber o texto selecionado.

## <a name="ceditviewlockbuffer"></a><a name="lockbuffer"></a>CEditView::LockBuffer

Ligue para esta função de membro para obter um ponteiro para o buffer. O buffer não deve ser modificado.

```
LPCTSTR LockBuffer() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer do controle de edição.

## <a name="ceditviewonfindnext"></a><a name="onfindnext"></a>CeditView::OnFindNext

Pesquisa o texto no buffer para o texto especificado por *lpszFind*, na direção especificada por *bNext*, com sensibilidade do caso especificada por *bCase*.

```
virtual void OnFindNext(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser encontrado.

*bNext*<br/>
Especifica a direção da pesquisa. Se TRUE, a direção da pesquisa é no final do buffer. Se FALSO, a direção de busca é para o início do buffer.

*Bcase*<br/>
Especifica se a pesquisa é sensível ao caso. Se VERDADE, a busca é sensível ao caso. Se FALSO, a busca não é sensível ao caso.

### <a name="remarks"></a>Comentários

A pesquisa começa no início da seleção atual e é realizada através de uma chamada para [FindText](#findtext). Na implementação `OnFindNext` padrão, chama [OnTextNotFound](#ontextnotfound) se o texto não for encontrado.

Substituir `OnFindNext` para alterar a `CEditView`forma como um objeto derivado pesquisa texto. `CEditView`chamadas `OnFindNext` quando o usuário escolhe o botão Encontrar o próximo na caixa de diálogo Encontrar padrão.

## <a name="ceditviewonreplaceall"></a><a name="onreplaceall"></a>CeditView::OnReplaceAll

`CEditView`chamadas `OnReplaceAll` quando o usuário seleciona o botão Substituir todos na caixa de diálogo substituir padrão.

```
virtual void OnReplaceAll(
    LPCTSTR lpszFind,
    LPCTSTR lpszReplace,
    BOOL bCase);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser encontrado.

*lpszReplace*<br/>
O texto para substituir o texto de pesquisa.

*Bcase*<br/>
Especifica se a pesquisa é sensível ao caso. Se VERDADE, a busca é sensível ao caso. Se FALSO, a busca não é sensível ao caso.

### <a name="remarks"></a>Comentários

`OnReplaceAll`pesquisa o texto no buffer para o texto especificado pelo *lpszFind*, com sensibilidade de caso especificada por *bCase*. A busca começa no início da seleção atual. Cada vez que o texto de pesquisa é encontrado, esta função substitui essa ocorrência do texto pelo texto especificado pelo *lpszReplace*. A pesquisa é realizada através de uma chamada para [FindText](#findtext). Na implementação padrão, [OnTextNotFound](#ontextnotfound) é chamado se o texto não for encontrado.

Se a seleção atual não corresponder ao *lpszFind,* a seleção será atualizada para a primeira ocorrência do texto especificado pelo *lpszFind* e uma substituição não será realizada. Isso permite que o usuário confirme que é isso que deseja fazer quando a seleção não corresponde ao texto a ser substituído.

Substituir `OnReplaceAll` para alterar a `CEditView`forma como um objeto derivado substitui o texto.

## <a name="ceditviewonreplacesel"></a><a name="onreplacesel"></a>CeditView::OnReplaceSel

`CEditView`chamadas `OnReplaceSel` quando o usuário seleciona o botão Substituir na caixa de diálogo substituir padrão.

```
virtual void OnReplaceSel(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase,
    LPCTSTR lpszReplace);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser encontrado.

*bNext*<br/>
Especifica a direção da pesquisa. Se TRUE, a direção da pesquisa é no final do buffer. Se FALSO, a direção de busca é para o início do buffer.

*Bcase*<br/>
Especifica se a pesquisa é sensível ao caso. Se VERDADE, a busca é sensível ao caso. Se FALSO, a busca não é sensível ao caso.

*lpszReplace*<br/>
O texto para substituir o texto encontrado.

### <a name="remarks"></a>Comentários

Após a substituição da seleção, esta função pesquisa o texto no buffer para a próxima ocorrência do texto especificado pelo *lpszFind,* na direção especificada por *bNext,* com sensibilidade do caso especificada por *bCase*. A pesquisa é realizada através de uma chamada para [FindText](#findtext). Se o texto não for encontrado, [onTextNotFound](#ontextnotfound) será chamado.

Substituir `OnReplaceSel` para alterar a `CEditView`forma como um objeto derivado substitui o texto selecionado.

## <a name="ceditviewontextnotfound"></a><a name="ontextnotfound"></a>Ceditview::OnTextNotFound

Substituir essa função para alterar a implementação `MessageBeep`padrão, que chama a função Windows .

```
virtual void OnTextNotFound(LPCTSTR lpszFind);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser encontrado.

## <a name="ceditviewprintinsiderect"></a><a name="printinsiderect"></a>CEditView::PrintInsideRect

Chamada `PrintInsideRect` para imprimir texto no retângulo especificado por *rectLayout*.

```
UINT PrintInsideRect(
    CDC *pDC,
    RECT& rectLayout,
    UINT nIndexStart,
    UINT nIndexStop);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo da impressora.

*rectLayout*<br/>
Referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) especificando o retângulo no qual o texto deve ser renderizado.

*Nindexstart*<br/>
Indexe dentro do buffer do primeiro caractere a ser renderizado.

*nIndexStop*<br/>
Indexe dentro do buffer do caractere seguindo o último caractere a ser renderizado.

### <a name="return-value"></a>Valor retornado

O índice do próximo caractere a ser impresso (ou seja, o caractere que segue o último caractere renderizado).

### <a name="remarks"></a>Comentários

Se `CEditView` o controle não tiver o estilo ES_AUTOHSCROLL, o texto é enrolado no retângulo de renderização. Se o controle tiver o estilo ES_AUTOHSCROLL, o texto é cortado na borda direita do retângulo.

O `rect.bottom` elemento do objeto *rectLayout* é alterado de modo que as dimensões do retângulo definam a parte do retângulo original que é ocupada pelo texto.

## <a name="ceditviewserializeraw"></a><a name="serializeraw"></a>CEditView::SerializeRaw

Ligue `SerializeRaw` para `CArchive` que um objeto leia `CEditView` ou escreva o texto no objeto para um arquivo de texto.

```cpp
void SerializeRaw(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Referência ao `CArchive` objeto que armazena o texto serializado.

### <a name="remarks"></a>Comentários

`SerializeRaw`difere da `CEditView`implementação interna `Serialize` de que lê e grava apenas o texto, sem preceder dados de descrição do objeto.

## <a name="ceditviewsetprinterfont"></a><a name="setprinterfont"></a>CEditView::SetPrinterFont

Chamada `SetPrinterFont` para definir a fonte da impressora na fonte especificada por *pFont*.

```cpp
void SetPrinterFont(CFont* pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
Um ponteiro para um `CFont`objeto de tipo . Se NULL, a fonte usada para impressão é baseada na fonte de exibição.

### <a name="remarks"></a>Comentários

Se você quiser que sua visão use sempre uma `SetPrinterFont` fonte específica para `OnPreparePrinting` impressão, inclua uma chamada na função da sua classe. Esta função virtual é chamada antes da impressão ocorrer, de modo que a alteração de fonte ocorre antes que o conteúdo da exibição seja impresso.

## <a name="ceditviewsettabstops"></a><a name="settabstops"></a>CeditView::Set's's

Chame esta função para definir as guias de paradas usadas para exibição e impressão.

```cpp
void SetTabStops(int nTabStops);
```

### <a name="parameters"></a>Parâmetros

*Ntabstops*<br/>
Largura de cada guia parada, em unidades de diálogo.

### <a name="remarks"></a>Comentários

Apenas uma única largura de parada de guia é suportada. (objetos `CEdit` suportam várias larguras de guia.) As larguras estão em unidades de diálogo, que equivalem a um quarto da largura média do caractere (baseada apenas em caracteres alfabetos maiúsculos e minúsculos) da fonte usada no momento da impressão ou exibição. Você não `CEdit::SetTabStops` deve `CEditView` usar porque deve armazenar o valor de guia-stop.

Esta função modifica apenas as guias do objeto para o qual é chamado. Para alterar as guias para cada `CEditView` objeto em `SetTabStops` seu aplicativo, ligue para a função de cada objeto.

### <a name="example"></a>Exemplo

Este fragmento de código define as paradas de guia no controle para cada quarto caractere, medindo cuidadosamente a fonte que o controle usa.

[!code-cpp[NVC_MFCDocView#67](../../mfc/codesnippet/cpp/ceditview-class_3.cpp)]

## <a name="ceditviewunlockbuffer"></a><a name="unlockbuffer"></a>CEditView::UnlockBuffer

Ligue para esta função de membro para desbloquear o buffer.

```cpp
void UnlockBuffer() const;
```

### <a name="remarks"></a>Comentários

Ligue `UnlockBuffer` depois de terminar de usar o ponteiro retornado pelo [LockBuffer](#lockbuffer).

## <a name="see-also"></a>Confira também

[SuperPAD de amostra de MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)

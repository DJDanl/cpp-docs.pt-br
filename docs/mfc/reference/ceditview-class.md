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
ms.openlocfilehash: a2ce38dcd8879378f7d0e4ea3f074e461c51db75
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269845"
---
# <a name="ceditview-class"></a>Classe CEditView

Um tipo de classe de exibição que fornece a funcionalidade de um Windows controle de edição e pode ser usado para implementar a funcionalidade do editor de texto simples.

## <a name="syntax"></a>Sintaxe

```
class CEditView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CEditView::CEditView](#ceditview)|Constrói um objeto do tipo `CEditView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CEditView::FindText](#findtext)|Pesquisa uma cadeia de caracteres dentro do texto.|
|[CEditView::GetBufferLength](#getbufferlength)|Obtém o comprimento do buffer de caractere.|
|[CEditView::GetEditCtrl](#geteditctrl)|Fornece acesso para o `CEdit` parte de um `CEditView` (controle de edição do Windows) do objeto.|
|[CEditView::GetPrinterFont](#getprinterfont)|Recupera a fonte da impressora atual.|
|[CEditView::GetSelectedText](#getselectedtext)|Recupera a seleção de texto atual.|
|[CEditView::LockBuffer](#lockbuffer)|Bloqueia o buffer.|
|[CEditView::PrintInsideRect](#printinsiderect)|Renderiza o texto dentro de um retângulo determinado.|
|[CEditView::SerializeRaw](#serializeraw)|Serializa um `CEditView` objeto para o disco como texto não processado.|
|[CEditView::SetPrinterFont](#setprinterfont)|Define uma nova fonte de impressora.|
|[CEditView::SetTabStops](#settabstops)|Conjuntos de tabulações para exibição na tela e impressão.|
|[CEditView::UnlockBuffer](#unlockbuffer)|Libera o buffer.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CEditView::OnFindNext](#onfindnext)|Localiza a próxima ocorrência de uma cadeia de caracteres de texto.|
|[CEditView::OnReplaceAll](#onreplaceall)|Substitui todas as ocorrências de uma determinada cadeia de caracteres com uma nova cadeia de caracteres.|
|[CEditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|
|[CEditView::OnTextNotFound](#ontextnotfound)|Chamado quando uma operação de localização não corresponde a qualquer texto adicional.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CEditView::dwStyleDefault](#dwstyledefault)|Estilo de objetos do tipo padrão `CEditView`.|

## <a name="remarks"></a>Comentários

O `CEditView` classe fornece as seguintes funções adicionais:

- Imprima.

- Localizar e substituir.

Como classe `CEditView` é um derivado da classe `CView`, objetos da classe `CEditView` pode ser usado com documentos e modelos de documento.

Cada `CEditView` texto do controle é mantido em seu próprio objeto de memória global. O aplicativo pode ter qualquer número de `CEditView` objetos.

Criar objetos do tipo `CEditView` se desejar que uma janela de edição com a funcionalidade adicionada listada acima, ou se desejar a funcionalidade de editor de texto simples. Um `CEditView` objeto pode ocupar toda a área cliente de uma janela. Derivar suas próprias classes de `CEditView` para adicionar ou modificar a funcionalidade básica, ou para declarar classes que podem ser adicionadas a um modelo de documento.

A implementação padrão da classe `CEditView` lida com os seguintes comandos: ID_EDIT_SELECT_ALL, ID_EDIT_FIND, ID_EDIT_REPLACE, ID_EDIT_REPEAT, and ID_FILE_PRINT.

O limite de caracteres padrão para `CEditView` é (1024 \* 1024-1 = 1048575). Isso pode ser alterado, chamando a função EM_LIMITTEXT do controle de edição subjacente. No entanto, os limites são diferentes dependendo do sistema operacional e o tipo de editar o controle (única ou várias linhas). Para obter mais informações sobre esses limites, consulte [EM_LIMITTEXT](/windows/desktop/Controls/em-limittext).

Para alterar esse limite em seu controle, substitua os `OnCreate()` funcionar para sua `CEditView` de classe e insira a seguinte linha de código:

[!code-cpp[NVC_MFCDocView#65](../../mfc/codesnippet/cpp/ceditview-class_1.cpp)]

Objetos do tipo `CEditView` (ou de tipos derivados de `CEditView`) têm as seguintes limitações:

- `CEditView` não implementa true que você vê é o que você obtém a edição (WYSIWYG). Onde há uma escolha entre a legibilidade na tela e a saída impressa correspondente, `CEditView` opts para facilitar a leitura de tela.

- `CEditView` pode exibir texto em apenas uma única fonte. Não há suporte para nenhuma formatação de caractere especial. Consulte a classe [CRichEditView](../../mfc/reference/cricheditview-class.md) para mais recursos.

- A quantidade de texto um `CEditView` pode conter é limitado. Os limites são os mesmos para o `CEdit` controle.

Para obter mais informações sobre `CEditView`, consulte [derivado exibição Classes disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CCtrlView](../../mfc/reference/cctrlview-class.md)

`CEditView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="ceditview"></a>  CEditView::CEditView

Constrói um objeto do tipo `CEditView`.

```
CEditView();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar o [CWnd::Create](../../mfc/reference/cwnd-class.md#create) funcionar antes do controle de edição é usado. Se você derivar uma classe de `CEditView` e adicione-a usando o modelo `CWinApp::AddDocTemplate`, o framework chama este construtor os dois e o `Create` função.

##  <a name="dwstyledefault"></a>  CEditView::dwStyleDefault

Contém o estilo de padrão de `CEditView` objeto.

```
static const DWORD dwStyleDefault;
```

### <a name="remarks"></a>Comentários

Passar este membro estático como o *dwStyle* parâmetro do `Create` função para obter o estilo padrão para o `CEditView` objeto.

##  <a name="findtext"></a>  CEditView::FindText

Chame o `FindText` função para pesquisar o `CEditView` buffer de texto do objeto.

```
BOOL FindText(
    LPCTSTR lpszFind,
    BOOL bNext = TRUE,
    BOOL bCase = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser encontrado.

*bNext*<br/>
Especifica a direção da pesquisa. Se for TRUE, a direção de pesquisa é na direção do final do buffer. Se for FALSE, a direção de pesquisa é em direção ao início do buffer.

*bCase*<br/>
Especifica se a pesquisa diferencia maiusculas de minúsculas. Se for TRUE, a pesquisa diferencia maiusculas de minúsculas. Se for FALSE, a pesquisa não diferencia maiusculas de minúsculas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o texto de pesquisa for encontrado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função pesquisa o texto no buffer para o texto especificado pelo *lpszFind*, começando na seleção atual na direção especificada por *bAvançar*e com diferenciação de maiusculas especificado por *bCase*. Se o texto for encontrado, ele define a seleção para o texto localizado e retorna um valor diferente de zero. Se o texto não for encontrado, a função retorna 0.

Você normalmente não é necessário chamar o `FindText` funcionar, a menos que você substitui `OnFindNext`, que chama `FindText`.

##  <a name="getbufferlength"></a>  CEditView::GetBufferLength

Chame essa função de membro para obter o número de caracteres atualmente no buffer do controle de edição, não incluindo o terminador nulo.

```
UINT GetBufferLength() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento da cadeia de caracteres no buffer.

##  <a name="geteditctrl"></a>  CEditView::GetEditCtrl

Chamar `GetEditCtrl` para obter uma referência ao controle de edição usado pelo modo de exibição editar.

```
CEdit& GetEditCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência a um objeto `CEdit`.

### <a name="remarks"></a>Comentários

Esse controle é do tipo [CEdit](../../mfc/reference/cedit-class.md), portanto, você pode manipular o controle de edição do Windows diretamente usando o `CEdit` funções de membro.

> [!CAUTION]
>  Usando o `CEdit` pode alterar o estado do Windows subjacente controle de edição de objeto. Por exemplo, você não deve alterar as configurações de guia usando o [CEdit::SetTabStops](../../mfc/reference/cedit-class.md#settabstops) funcionar porque `CEditView` armazena em cache essas configurações para uso no controle de edição e na impressão. Em vez disso, use [CEditView::SetTabStops](#settabstops).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#66](../../mfc/codesnippet/cpp/ceditview-class_2.cpp)]

##  <a name="getprinterfont"></a>  CEditView::GetPrinterFont

Chame `GetPrinterFont` para obter um ponteiro para uma [CFont](../../mfc/reference/cfont-class.md) objeto que descreve a fonte da impressora atual.

```
CFont* GetPrinterFont() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CFont` objeto que especifica a fonte da impressora atual; NULL se a fonte da impressora não foi definida. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.

### <a name="remarks"></a>Comentários

Se a fonte da impressora não foi definida, o padrão de impressão de comportamento do `CEditView` classe é imprimir usando a mesma fonte usada para exibição.

Use esta função para determinar a fonte da impressora atual. Se não for a fonte da impressora desejado, use [CEditView::SetPrinterFont](#setprinterfont) alterá-la.

##  <a name="getselectedtext"></a>  CEditView::GetSelectedText

Chame `GetSelectedText` para copiar o texto selecionado em um `CString` objeto até o fim da seleção ou o caractere que precede o primeiro caractere de retorno de carro na seleção.

```
void GetSelectedText(CString& strResult) const;
```

### <a name="parameters"></a>Parâmetros

*strResult*<br/>
Uma referência para o `CString` objeto que receberá o texto selecionado.

##  <a name="lockbuffer"></a>  CEditView::LockBuffer

Chame essa função de membro para obter um ponteiro para o buffer. O buffer não deve ser modificado.

```
LPCTSTR LockBuffer() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer do controle de edição.

##  <a name="onfindnext"></a>  CEditView::OnFindNext

Pesquisa o texto no buffer para o texto especificado pelo *lpszFind*, na direção especificada por *bAvançar*, com diferenciação de maiusculas especificada por *bCase*.

```
virtual void OnFindNext(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser encontrado.

*bNext*<br/>
Especifica a direção da pesquisa. Se for TRUE, a direção de pesquisa é na direção do final do buffer. Se for FALSE, a direção de pesquisa é em direção ao início do buffer.

*bCase*<br/>
Especifica se a pesquisa diferencia maiusculas de minúsculas. Se for TRUE, a pesquisa diferencia maiusculas de minúsculas. Se for FALSE, a pesquisa não diferencia maiusculas de minúsculas.

### <a name="remarks"></a>Comentários

A pesquisa começa no início da seleção atual e é realizada por meio de uma chamada para [FindText](#findtext). Na implementação do padrão, `OnFindNext` chamadas [OnTextNotFound](#ontextnotfound) se o texto não for encontrado.

Substituir `OnFindNext` alterar a maneira como um `CEditView`-objeto derivado pesquisa de texto. `CEditView` chamadas `OnFindNext` quando o usuário escolhe o botão Localizar próxima na caixa de diálogo Localizar padrão.

##  <a name="onreplaceall"></a>  CEditView::OnReplaceAll

`CEditView` chamadas `OnReplaceAll` quando o usuário seleciona o botão Substituir tudo na caixa de diálogo Substituir padrão.

```
virtual void OnReplaceAll(
    LPCTSTR lpszFind,
    LPCTSTR lpszReplace,
    BOOL bCase);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser encontrado.

*lpszReplace*<br/>
O texto para substituir o texto de pesquisa.

*bCase*<br/>
Especifica se a pesquisa diferencia maiusculas de minúsculas. Se for TRUE, a pesquisa diferencia maiusculas de minúsculas. Se for FALSE, a pesquisa não diferencia maiusculas de minúsculas.

### <a name="remarks"></a>Comentários

`OnReplaceAll` pesquisa o texto no buffer para o texto especificado pelo *lpszFind*, com diferenciação de maiusculas especificada por *bCase*. A pesquisa começa no início da seleção atual. Cada vez que o texto de pesquisa for encontrado, essa função substitui essa ocorrência do texto com o texto especificado pelo *lpszReplace*. A pesquisa é realizada por meio de uma chamada para [FindText](#findtext). Na implementação do padrão, [OnTextNotFound](#ontextnotfound) é chamado se o texto não for encontrado.

Se a seleção atual não corresponder *lpszFind*, a seleção seja atualizada para a primeira ocorrência do texto especificado por *lpszFind* e uma substituição não é executada. Isso permite ao usuário confirmar que esse é o que desejam fazer quando a seleção não coincide com o texto a ser substituído.

Substituir `OnReplaceAll` alterar a maneira como um `CEditView`-objeto derivada substitui o texto.

##  <a name="onreplacesel"></a>  CEditView::OnReplaceSel

`CEditView` chamadas `OnReplaceSel` quando o usuário seleciona o botão de substituição na caixa de diálogo Substituir padrão.

```
virtual void OnReplaceSel(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase,
    LPCTSTR lpszReplace);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser encontrado.

*bNext*<br/>
Especifica a direção da pesquisa. Se for TRUE, a direção de pesquisa é na direção do final do buffer. Se for FALSE, a direção de pesquisa é em direção ao início do buffer.

*bCase*<br/>
Especifica se a pesquisa diferencia maiusculas de minúsculas. Se for TRUE, a pesquisa diferencia maiusculas de minúsculas. Se for FALSE, a pesquisa não diferencia maiusculas de minúsculas.

*lpszReplace*<br/>
O texto para substituir o texto localizado.

### <a name="remarks"></a>Comentários

Depois de substituir a seleção, essa função pesquisa o texto no buffer para a próxima ocorrência do texto especificado por *lpszFind*, na direção especificada por *bAvançar*, com diferenciação de maiusculas especificado pelo *bCase*. A pesquisa é realizada por meio de uma chamada para [FindText](#findtext). Se o texto não for encontrado, [OnTextNotFound](#ontextnotfound) é chamado.

Substituir `OnReplaceSel` alterar a maneira como um `CEditView`-objeto derivada substitui o texto selecionado.

##  <a name="ontextnotfound"></a>  CEditView::OnTextNotFound

Substituir essa função para alterar a implementação do padrão, que chama a função Windows `MessageBeep`.

```
virtual void OnTextNotFound(LPCTSTR lpszFind);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser encontrado.

##  <a name="printinsiderect"></a>  CEditView::PrintInsideRect

Chame `PrintInsideRect` para imprimir o texto no retângulo especificado por *rectLayout*.

```
UINT PrintInsideRect(
    CDC *pDC,
    RECT& rectLayout,
    UINT nIndexStart,
    UINT nIndexStop);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto de dispositivo de impressora.

*rectLayout*<br/>
Referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [estrutura RECT](/windows/desktop/api/windef/ns-windef-tagrect) especificando o retângulo no qual o texto deve ser renderizada.

*nIndexStart*<br/>
Indexar dentro do buffer do primeiro caractere a ser renderizado.

*nIndexStop*<br/>
Indexar dentro do buffer do caractere após o último caractere a ser renderizado.

### <a name="return-value"></a>Valor de retorno

O índice do próximo caractere a ser impressa (ou seja, o caractere após o último caractere renderizado).

### <a name="remarks"></a>Comentários

Se o `CEditView` controle não tem o estilo ES_AUTOHSCROLL, o texto é quebrado dentro do retângulo de renderização. Se o controle tem o estilo ES_AUTOHSCROLL, o texto é recortado na borda direita do retângulo.

O `rect.bottom` elemento do *rectLayout* objeto é alterado para que a parte do retângulo original que está ocupada pelo texto de definir as dimensões do retângulo.

##  <a name="serializeraw"></a>  CEditView::SerializeRaw

Chame `SerializeRaw` para ter um `CArchive` objeto ler ou gravar o texto `CEditView` objeto para um arquivo de texto.

```
void SerializeRaw(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Referência para o `CArchive` objeto que armazena o texto serializado.

### <a name="remarks"></a>Comentários

`SerializeRaw` difere `CEditView`da implementação interna de `Serialize` que lê e grava apenas o texto, sem precede os dados de descrição do objeto.

##  <a name="setprinterfont"></a>  CEditView::SetPrinterFont

Chame `SetPrinterFont` para definir a fonte da impressora para a fonte especificada por *pFont*.

```
void SetPrinterFont(CFont* pFont);
```

### <a name="parameters"></a>Parâmetros

*pFont*<br/>
Um ponteiro para um objeto do tipo `CFont`. Se for NULL, a fonte usada para impressão se baseia a fonte de exibição.

### <a name="remarks"></a>Comentários

Se você quiser sempre usar uma fonte específica para impressão em seu modo de exibição, incluir uma chamada para `SetPrinterFont` em sua classe `OnPreparePrinting` função. Essa função virtual é chamada antes que ocorra a impressão, portanto, a alteração de fonte ocorre antes que o conteúdo da exibição é impressos.

##  <a name="settabstops"></a>  CEditView::SetTabStops

Chame essa função para definir as paradas de tabulação usadas para exibição e impressão.

```
void SetTabStops(int nTabStops);
```

### <a name="parameters"></a>Parâmetros

*nTabStops*<br/>
Largura de cada parada de tabulação, em unidades de diálogo.

### <a name="remarks"></a>Comentários

Há suporte para apenas uma única largura de tabulação. ( `CEdit` objetos dão suporte a várias larguras de guia.) Larguras estão em unidades de caixa de diálogo, que é igual a um quarto da largura do caractere médio (com base em letras maiusculos e minúsculos somente caracteres alfabéticos) da fonte usada no momento da impressão ou exibição. Você não deve usar `CEdit::SetTabStops` porque `CEditView` deve armazenar em cache o valor de parada de tabulação.

Essa função modifica somente as guias do objeto para o qual ele é chamado. Para alterar a guia para para cada `CEditView` do objeto em seu aplicativo, chame a cada objeto `SetTabStops` função.

### <a name="example"></a>Exemplo

Este fragmento de código define as paradas de tabulação no controle para todos os caracteres quarto medindo cuidadosamente a fonte que usa o controle.

[!code-cpp[NVC_MFCDocView#67](../../mfc/codesnippet/cpp/ceditview-class_3.cpp)]

##  <a name="unlockbuffer"></a>  CEditView::UnlockBuffer

Chame essa função de membro para desbloquear o buffer.

```
void UnlockBuffer() const;
```

### <a name="remarks"></a>Comentários

Chame `UnlockBuffer` depois que você terminar de usar o ponteiro retornado por [LockBuffer](#lockbuffer).

## <a name="see-also"></a>Consulte também

[Exemplo MFC SUPERPAD](../../visual-cpp-samples.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)

---
title: Classe CPropertySheet
ms.date: 11/04/2016
f1_keywords:
- CPropertySheet
- AFXDLGS/CPropertySheet
- AFXDLGS/CPropertySheet::CPropertySheet
- AFXDLGS/CPropertySheet::AddPage
- AFXDLGS/CPropertySheet::Construct
- AFXDLGS/CPropertySheet::Create
- AFXDLGS/CPropertySheet::DoModal
- AFXDLGS/CPropertySheet::EnableStackedTabs
- AFXDLGS/CPropertySheet::EndDialog
- AFXDLGS/CPropertySheet::GetActiveIndex
- AFXDLGS/CPropertySheet::GetActivePage
- AFXDLGS/CPropertySheet::GetPage
- AFXDLGS/CPropertySheet::GetPageCount
- AFXDLGS/CPropertySheet::GetPageIndex
- AFXDLGS/CPropertySheet::GetTabControl
- AFXDLGS/CPropertySheet::MapDialogRect
- AFXDLGS/CPropertySheet::OnInitDialog
- AFXDLGS/CPropertySheet::PressButton
- AFXDLGS/CPropertySheet::RemovePage
- AFXDLGS/CPropertySheet::SetActivePage
- AFXDLGS/CPropertySheet::SetFinishText
- AFXDLGS/CPropertySheet::SetTitle
- AFXDLGS/CPropertySheet::SetWizardButtons
- AFXDLGS/CPropertySheet::SetWizardMode
- AFXDLGS/CPropertySheet::m_psh
helpviewer_keywords:
- CPropertySheet [MFC], CPropertySheet
- CPropertySheet [MFC], AddPage
- CPropertySheet [MFC], Construct
- CPropertySheet [MFC], Create
- CPropertySheet [MFC], DoModal
- CPropertySheet [MFC], EnableStackedTabs
- CPropertySheet [MFC], EndDialog
- CPropertySheet [MFC], GetActiveIndex
- CPropertySheet [MFC], GetActivePage
- CPropertySheet [MFC], GetPage
- CPropertySheet [MFC], GetPageCount
- CPropertySheet [MFC], GetPageIndex
- CPropertySheet [MFC], GetTabControl
- CPropertySheet [MFC], MapDialogRect
- CPropertySheet [MFC], OnInitDialog
- CPropertySheet [MFC], PressButton
- CPropertySheet [MFC], RemovePage
- CPropertySheet [MFC], SetActivePage
- CPropertySheet [MFC], SetFinishText
- CPropertySheet [MFC], SetTitle
- CPropertySheet [MFC], SetWizardButtons
- CPropertySheet [MFC], SetWizardMode
- CPropertySheet [MFC], m_psh
ms.assetid: 8461ccff-d14f-46e0-a746-42ad642ef94e
ms.openlocfilehash: 23d17aee2aacbc1484c0f3e181bc824546ab49a2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502819"
---
# <a name="cpropertysheet-class"></a>Classe CPropertySheet

Representa folhas de propriedades, também conhecidas como caixas de diálogo de tabulação.

## <a name="syntax"></a>Sintaxe

```
class CPropertySheet : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::CPropertySheet](#cpropertysheet)|Constrói um objeto `CPropertySheet`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::AddPage](#addpage)|Adiciona uma página à folha de propriedades.|
|[CPropertySheet::Construct](#construct)|Constrói um objeto `CPropertySheet`.|
|[CPropertySheet::Create](#create)|Exibe uma folha de propriedades sem janela restrita.|
|[CPropertySheet::DoModal](#domodal)|Exibe uma folha de propriedades modal.|
|[CPropertySheet::EnableStackedTabs](#enablestackedtabs)|Indica se a folha de propriedades usa guias empilhadas ou de rolagem.|
|[CPropertySheet::EndDialog](#enddialog)|Encerra a folha de propriedades.|
|[CPropertySheet::GetActiveIndex](#getactiveindex)|Recupera o índice da página ativa da folha de propriedades.|
|[CPropertySheet::GetActivePage](#getactivepage)|Retorna o objeto da página ativa.|
|[CPropertySheet::GetPage](#getpage)|Recupera um ponteiro para a página especificada.|
|[CPropertySheet::GetPageCount](#getpagecount)|Recupera o número de páginas na folha de propriedades.|
|[CPropertySheet::GetPageIndex](#getpageindex)|Recupera o índice da página especificada da folha de propriedades.|
|[CPropertySheet::GetTabControl](#gettabcontrol)|Recupera um ponteiro para um controle guia.|
|[CPropertySheet::MapDialogRect](#mapdialogrect)|Converte as unidades de caixa de diálogo de um retângulo em unidades de tela.|
|[CPropertySheet::OnInitDialog](#oninitdialog)|Substituir para aumentar a inicialização da folha de propriedades.|
|[CPropertySheet::PressButton](#pressbutton)|Simula a escolha do botão especificado em uma folha de propriedades.|
|[CPropertySheet::RemovePage](#removepage)|Remove uma página da folha de propriedades.|
|[CPropertySheet::SetActivePage](#setactivepage)|Define programaticamente o objeto de página ativa.|
|[CPropertySheet::SetFinishText](#setfinishtext)|Define o texto para o botão Concluir.|
|[CPropertySheet::SetTitle](#settitle)|Define a legenda da folha de propriedades.|
|[CPropertySheet::SetWizardButtons](#setwizardbuttons)|Habilita os botões do assistente.|
|[CPropertySheet::SetWizardMode](#setwizardmode)|Habilita o modo de assistente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::m_psh](#m_psh)|A estrutura [PROPSHEETHEADER](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2) do Windows. Fornece acesso aos parâmetros básicos da folha de propriedades.|

## <a name="remarks"></a>Comentários

Uma folha de propriedades consiste em `CPropertySheet` um objeto e um ou mais objetos [CPropertyPage](../../mfc/reference/cpropertypage-class.md) . A estrutura exibe uma folha de propriedades como uma janela com um conjunto de índices de tabulação e uma área que contém a página atualmente selecionada. O usuário navega para uma página específica usando a guia apropriada.

`CPropertySheet`fornece suporte para a estrutura expandida do [PROPSHEETHEADER](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2) introduzida no Windows 98 e no windows NT 2000. A estrutura contém sinalizadores e membros adicionais que dão suporte ao uso de um bitmap de plano de fundo "marca d' água".

Para exibir essas novas imagens automaticamente em seu objeto de folha de propriedades, passe os valores válidos para as imagens de bitmap e paleta na chamada para [CPropertySheet:: Construct](#construct) ou [CPropertySheet:: CPropertySheet](#cpropertysheet).

Embora `CPropertySheet` não seja derivado de [CDialog](../../mfc/reference/cdialog-class.md), o gerenciamento de `CPropertySheet` um objeto é como o `CDialog` gerenciamento de um objeto. Por exemplo, a criação de uma folha de propriedades requer a construção de duas partes: chame o construtor e, em seguida, chame [DoModal](#domodal) para uma folha de propriedades modal ou [crie](#create) para uma folha de propriedades sem janela restrita. `CPropertySheet`tem dois tipos de construtores: [CPropertySheet:: Construct](#construct) e [CPropertySheet:: CPropertySheet](#cpropertysheet).

Quando você constrói um `CPropertySheet` objeto, alguns [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) podem causar a ocorrência de uma exceção de primeira chance. Isso resulta do sistema tentando alterar o estilo da folha de propriedades antes da criação da planilha. Para evitar essa exceção, certifique-se de definir os seguintes estilos ao criar seu `CPropertySheet`:

- DS_3DLOOK

- DS_CONTROL

- WS_CHILD

- WS_TABSTOP

Os seguintes estilos são opcionais e não causarão a exceção de primeira chance:

- DS_SHELLFONT

- DS_LOCALEDIT

- WS_CLIPCHILDREN

Qualquer outro `Window Styles` é proibido e você não deve habilitá-los.

A troca de dados entre `CPropertySheet` um objeto e um objeto externo é semelhante à troca de dados com `CDialog` um objeto. A diferença importante é que as configurações de uma folha de propriedades normalmente são variáveis de membro `CPropertyPage` dos objetos em vez `CPropertySheet` do próprio objeto.

Você pode criar um tipo de caixa de diálogo de guia chamada assistente, que consiste em uma folha de propriedades com uma sequência de páginas de propriedades que orientam o usuário pelas etapas de uma operação, como a configuração de um dispositivo ou a criação de um boletim informativo. Em uma caixa de diálogo guia do tipo de assistente, as páginas de propriedades não têm guias e apenas uma página de propriedades é visível por vez. Além disso, em vez de ter botões **OK** e **aplicar agora** , uma caixa de diálogo guia do tipo de assistente tem um botão **voltar** , um botão de **Avançar** ou **concluir** , um botão **Cancelar** e um botão de **ajuda** .

Para criar uma caixa de diálogo de tipo de assistente, siga as mesmas etapas que você seguiria para criar uma folha de propriedades padrão, mas chame [SetWizardMode](#setwizardmode) antes de chamar [DoModal](#domodal). Para habilitar os botões do assistente, chame [SetWizardButtons](#setwizardbuttons), usando sinalizadores para personalizar sua função e aparência. Para habilitar o botão **concluir** , chame [SetFinishText](#setfinishtext) depois que o usuário executou a ação na última página do assistente.

Para obter mais informações sobre como usar `CPropertySheet` objetos, consulte as folhas de propriedades do artigo [e as páginas de propriedades](../../mfc/property-sheets-and-property-pages-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CPropertySheet`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="addpage"></a>  CPropertySheet::AddPage

Adiciona a página fornecida com a guia mais à direita na folha de propriedades.

```
void AddPage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
Aponta para a página a ser adicionada à folha de propriedades. Não pode ser NULL.

### <a name="remarks"></a>Comentários

Adicione páginas à folha de propriedades na ordem da esquerda para a direita que você deseja que elas apareçam.

`AddPage`Adiciona o objeto [CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage) à `CPropertySheet` lista de páginas do objeto, mas, na verdade, não cria a janela para a página. A estrutura adia a criação da janela para a página até que o usuário selecione essa página.

Quando você adiciona uma página de propriedades `AddPage`usando, `CPropertySheet` o `CPropertyPage`é o pai do. Para obter acesso à folha de propriedades da página de propriedades, chame [CWnd:: GetParent](../../mfc/reference/cwnd-class.md#getparent).

Não é necessário aguardar até a criação da janela da folha de propriedades para `AddPage`chamar. Normalmente, você chamará `AddPage` antes de chamar [DoModal](#domodal) ou [Create](#create).

Se você chamar `AddPage` depois de exibir a página de propriedades, a linha da guia refletirá a página recém-adicionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#129](../../mfc/codesnippet/cpp/cpropertysheet-class_1.cpp)]

##  <a name="construct"></a>CPropertySheet:: Construct

Constrói um objeto `CPropertySheet`.

```
void Construct(
    UINT nIDCaption,
    CWnd* pParentWnd = NULL,
    UINT iSelectPage = 0);

void Construct(
    LPCTSTR pszCaption,
    CWnd* pParentWnd = NULL,
    UINT iSelectPage = 0);

void Construct(
    UINT nIDCaption,
    CWnd* pParentWnd,
    UINT iSelectPage,
    HBITMAP hbmWatermark,
    HPALETTE hpalWatermark = NULL,
    HBITMAP hbmHeader = NULL);

void Construct(
    LPCTSTR pszCaption,
    CWnd* pParentWnd,
    UINT iSelectPage,
    HBITMAP hbmWatermark,
    HPALETTE hpalWatermark = NULL,
    HBITMAP hbmHeader = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDCaption*<br/>
ID da legenda a ser usada para a folha de propriedades.

*pParentWnd*<br/>
Ponteiro para a janela pai da folha de propriedades. Se for NULL, a janela pai será a janela principal do aplicativo.

*iSelectPage*<br/>
O índice da página que inicialmente estará no topo. O padrão é a primeira página adicionada à planilha.

*pszCaption*<br/>
Ponteiro para uma cadeia de caracteres que contém a legenda a ser usada para a folha de propriedades. Não pode ser NULL.

*hbmWatermark*<br/>
Identificador para o bitmap de marca d' água da página de propriedades.

*hpalWatermark*<br/>
Identificador para a paleta do bitmap de marca d' água e/ou bitmap de cabeçalho.

*hbmHeader*<br/>
Identificador para o bitmap de cabeçalho da página de propriedades.

### <a name="remarks"></a>Comentários

Chame essa função de membro se um dos construtores de classe ainda não tiver sido chamado. Por exemplo, chame `Construct` quando você declarar ou alocar matrizes de `CPropertySheet` objetos. No caso de matrizes, você deve chamar `Construct` para cada membro na matriz.

Para exibir a folha de propriedades, chame [DoModal](#domodal) ou [crie](#create). A cadeia de caracteres contida no primeiro parâmetro será colocada na barra de legenda da folha de propriedades.

Você pode exibir as imagens de marca d' água e/ou de cabeçalho automaticamente se usar o terceiro ou `Construct`o quarto protótipos de, listado acima, e passar valores válidos para os parâmetros *hbmWatermark*, *hpalWatermark*e/ou *hbmHeader* .

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra em que circunstâncias você chamaria `Construct`.

[!code-cpp[NVC_MFCDocView#130](../../mfc/codesnippet/cpp/cpropertysheet-class_2.cpp)]

##  <a name="cpropertysheet"></a>  CPropertySheet::CPropertySheet

Constrói um objeto `CPropertySheet`.

```
CPropertySheet();

explicit CPropertySheet(
    UINT nIDCaption,
    CWnd* pParentWnd = NULL,
    UINT iSelectPage = 0);

explicit CPropertySheet(
    LPCTSTR pszCaption,
    CWnd* pParentWnd = NULL,
    UINT iSelectPage = 0);

CPropertySheet(
    UINT nIDCaption,
    CWnd* pParentWnd,
    UINT iSelectPage,
    HBITMAP hbmWatermark,
    HPALETTE hpalWatermark = NULL,
    HBITMAP hbmHeader = NULL);

CPropertySheet(
    LPCTSTR pszCaption,
    CWnd* pParentWnd,
    UINT iSelectPage,
    HBITMAP hbmWatermark,
    HPALETTE hpalWatermark = NULL,
    HBITMAP hbmHeader = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDCaption*<br/>
ID da legenda a ser usada para a folha de propriedades.

*pParentWnd*<br/>
Aponta para a janela pai da folha de propriedades. Se for NULL, a janela pai será a janela principal do aplicativo.

*iSelectPage*<br/>
O índice da página que inicialmente estará no topo. O padrão é a primeira página adicionada à planilha.

*pszCaption*<br/>
Aponta para uma cadeia de caracteres que contém a legenda a ser usada para a folha de propriedades. Não pode ser NULL.

*hbmWatermark*<br/>
Um identificador para o bitmap em segundo plano da folha de propriedades.

*hpalWatermark*<br/>
Um identificador para a paleta do bitmap de marca d' água e/ou bitmap de cabeçalho.

*hbmHeader*<br/>
Um identificador para o bitmap de cabeçalho da página de propriedades.

### <a name="remarks"></a>Comentários

Para exibir a folha de propriedades, chame [DoModal](#domodal) ou [crie](#create). A cadeia de caracteres contida no primeiro parâmetro será colocada na barra de legenda da folha de propriedades.

Se você tiver vários parâmetros (por exemplo, se estiver usando uma matriz), use [Construct](#construct) em vez de `CPropertySheet`.

Você pode exibir as imagens de marca d' água e/ou de cabeçalho automaticamente se usar o terceiro ou `CPropertySheet`o quarto protótipos de, acima, e passar valores válidos para os parâmetros *hbmWatermark*, *hpalWatermark*e/ou *hbmHeader* .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#131](../../mfc/codesnippet/cpp/cpropertysheet-class_3.cpp)]

##  <a name="create"></a>CPropertySheet:: criar

Exibe uma folha de propriedades sem janela restrita.

```
virtual BOOL Create(CWnd* pParentWnd = NULL,
    DWORD dwStyle = (DWORD)-1,
    DWORD dwExStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Aponta para a janela pai. Se for NULL, o pai será a área de trabalho.

*dwStyle*<br/>
Estilos de janela para folha de propriedades. Para obter uma lista completa dos estilos disponíveis, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*dwExStyle*<br/>
Estilos de janela estendidos para folha de propriedades. Para obter uma lista completa dos estilos disponíveis, consulte [estilos de janela estendida](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles)

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de Propriedades for criada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A chamada para `Create` pode estar dentro do construtor ou você pode chamá-la depois que o Construtor for invocado.

O estilo padrão, expresso pela passagem-1 como *dwStyle*, é realmente WS_SYSMENU&#124;WS_POPUP&#124;WS_CAPTION&#124;DS_MODALFRAME&#124;&#124;DS_CONTEXTHELP WS_VISIBLE. O estilo de janela estendido padrão, expresso pela passagem de 0 como *dwExStyle*, é realmente WS_EX_DLGMODALFRAME.

A `Create` função de membro retorna imediatamente após a criação da folha de propriedades. Para destruir a folha de propriedades, chame [CWnd::D estroywindow](../../mfc/reference/cwnd-class.md#destroywindow).

As folhas de propriedades sem janela restrita exibidas com `Create` uma chamada para não têm os botões OK, cancelar, aplicar agora e ajudar como folhas de propriedades modais. Os botões desejados devem ser criados pelo usuário.

Para exibir uma folha de propriedades modal, chame [DoModal](#domodal) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#132](../../mfc/codesnippet/cpp/cpropertysheet-class_4.cpp)]

[!code-cpp[NVC_MFCDocView#133](../../mfc/codesnippet/cpp/cpropertysheet-class_5.cpp)]

##  <a name="domodal"></a>CPropertySheet::D oModal

Exibe uma folha de propriedades modal.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

IDOK ou IDCANCEL se a função foi bem-sucedida; caso contrário, 0 ou-1. Se a folha de propriedades tiver sido estabelecida como um assistente (consulte [SetWizardMode](#setwizardmode)), `DoModal` retornará ID_WIZFINISH ou IDCANCEL.

### <a name="remarks"></a>Comentários

O valor de retorno corresponde à ID do controle que fechou a folha de propriedades. Depois que essa função retornar, as janelas correspondentes à folha de propriedades e todas as páginas serão destruídas. Os próprios objetos ainda existirão. Normalmente, você irá recuperar dados dos objetos [CPropertyPage](../../mfc/reference/cpropertypage-class.md) depois `DoModal` de retornar IDOK.

Para exibir uma folha de propriedades sem janela restrita, chame [Create](#create) em seu lugar.

Quando uma página de propriedades é criada a partir de seu recurso de caixa de diálogo correspondente, ela pode causar uma exceção de primeira chance. Isso resulta da página de propriedades que altera o estilo do recurso de caixa de diálogo para o estilo necessário antes que a página seja criada. Como os recursos são geralmente somente leitura, isso causa uma exceção. O sistema manipula a exceção e faz uma cópia do recurso modificado. Portanto, a exceção de primeira chance pode ser ignorada.

> [!NOTE]
>  Essa exceção deve ser tratada pelo sistema operacional se você estiver Compilando com o modelo de manipulação de exceção assíncrona. Para obter mais informações sobre modelos de tratamento de exceções, consulte [/eh (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md). Nesse caso, não empacote chamadas para `CPropertySheet::DoModal` com um C++ bloco try-catch no qual o catch manipula todas as exceções, por exemplo, `catch (...)`. Esse bloco trataria a exceção destinada ao sistema operacional e causaria um comportamento imprevisível. No entanto, você pode usar C++ com segurança a manipulação de exceção com tipos de exceção específicos ou manipulação de exceção estruturada em que a exceção de violação de acesso é passada para o sistema operacional.

Para evitar a geração dessa exceção de primeira chance, você pode garantir manualmente que a folha de propriedades tenha os [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles)corretos. Você precisa definir os seguintes estilos para uma folha de propriedades:

- DS_3DLOOK

- DS_CONTROL

- WS_CHILD

- WS_TABSTOP

Você pode usar os seguintes estilos opcionais sem causar uma exceção de primeira chance:

- DS_SHELLFONT

- DS_LOCALEDIT

- WS_CLIPCHILDREN

Desabilite todos os outros estilos do Windows porque eles não são compatíveis com as folhas de propriedades. Este Conselho não se aplica a estilos estendidos. Definir esses estilos padrão de forma apropriada garantirá que a folha de propriedades não precise ser modificada e evitará gerar a exceção de primeira chance.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertySheet:: AddPage](#addpage).

##  <a name="enablestackedtabs"></a>  CPropertySheet::EnableStackedTabs

Indica se as linhas das guias devem ser empilhadas em uma folha de propriedades.

```
void EnableStackedTabs(BOOL bStacked);
```

### <a name="parameters"></a>Parâmetros

*bStacked*<br/>
Indica se as guias empilhadas estão habilitadas na folha de propriedades. Desabilite linhas empilhadas de marcas definindo *bStacked* como false.

### <a name="remarks"></a>Comentários

Por padrão, se uma folha de propriedades tiver mais guias do que couber em uma única linha na largura da folha de propriedades, as guias serão empilhadas em várias linhas. Para usar guias de rolagem em vez de guias de empilhamento, `EnableStackedTabs` chame with *bStacked* definido como false antes de chamar [DoModal](#domodal) ou [Create](#create).

Você deve chamar `EnableStackedTabs` ao criar uma folha de propriedades modal ou sem janela restrita. Para incorporar esse estilo em uma `CPropertySheet`classe derivada, escreva um manipulador de mensagens para WM_CREATE. Na versão substituída de [CWnd:: OnCreate](../../mfc/reference/cwnd-class.md#oncreate), chame `EnableStackedTabs( FALSE )` antes de chamar a implementação da classe base.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#134](../../mfc/codesnippet/cpp/cpropertysheet-class_6.cpp)]

##  <a name="enddialog"></a>CPropertySheet:: EndDialog

Encerra a folha de propriedades.

```
void EndDialog(int nEndID);
```

### <a name="parameters"></a>Parâmetros

*nEndID*<br/>
Identificador a ser usado como valor de retorno da folha de propriedades.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pela estrutura quando o botão OK, cancelar ou fechar é pressionado. Chamar essa função de membro se ocorrer um evento que deve fechar a folha de propriedades.

Essa função de membro é usada apenas com uma caixa de diálogo modal.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertySheet::P ressbutton](#pressbutton).

##  <a name="getactiveindex"></a>  CPropertySheet::GetActiveIndex

Obtém o número de índice da página ativa da janela da folha de propriedades e, em seguida, usa o número de `GetPage`índice retornado como o parâmetro para.

```
int GetActiveIndex() const;
```

### <a name="return-value"></a>Valor de retorno

O número de índice da página ativa.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertySheet:: GetActivePage](#getactivepage).

##  <a name="getactivepage"></a>  CPropertySheet::GetActivePage

Recupera a página ativa da janela da folha de propriedades.

```
CPropertyPage* GetActivePage() const;
```

### <a name="return-value"></a>Valor de retorno

O ponteiro para a página ativa.

### <a name="remarks"></a>Comentários

Use essa função de membro para executar alguma ação na página ativa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#135](../../mfc/codesnippet/cpp/cpropertysheet-class_7.cpp)]

##  <a name="getpage"></a>CPropertySheet:: GetPage

Retorna um ponteiro para a página especificada nesta folha de propriedades.

```
CPropertyPage* GetPage(int nPage) const;
```

### <a name="parameters"></a>Parâmetros

*nPage*<br/>
Índice da página desejada, começando em 0. Deve estar entre 0 e um menor que o número de páginas na folha de propriedades, inclusive.

### <a name="return-value"></a>Valor de retorno

O ponteiro para a página correspondente ao parâmetro *nconfiguração* .

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertyPage:: OnWizardFinish](../../mfc/reference/cpropertypage-class.md#onwizardfinish).

##  <a name="getpagecount"></a>CPropertySheet::GetPageCount

Determina o número de páginas atualmente na folha de propriedades.

```
int GetPageCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de páginas na folha de propriedades.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertyPage:: OnWizardFinish](../../mfc/reference/cpropertypage-class.md#onwizardfinish).

##  <a name="getpageindex"></a>  CPropertySheet::GetPageIndex

Recupera o número de índice da página especificada na folha de propriedades.

```
int GetPageIndex(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
Aponta para a página com o índice a ser encontrado. Não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

O número de índice de uma página.

### <a name="remarks"></a>Comentários

Por exemplo, você usaria `GetPageIndex` para obter o índice de página a fim de usar [SetActivePage](#setactivepage) ou [GetPage](#getpage).

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertySheet:: GetActivePage](#getactivepage).

##  <a name="gettabcontrol"></a>  CPropertySheet::GetTabControl

Recupera um ponteiro para um controle guia para fazer algo específico para o controle guia (ou seja, para usar qualquer uma das APIs no [CTabCtrl](../../mfc/reference/ctabctrl-class.md)).

```
CTabCtrl* GetTabControl() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um controle guia.

### <a name="remarks"></a>Comentários

Por exemplo, chame essa função de membro se desejar adicionar bitmaps a cada uma das guias durante a inicialização.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#136](../../mfc/codesnippet/cpp/cpropertysheet-class_8.cpp)]

##  <a name="m_psh"></a>CPropertySheet::m_psh

Uma estrutura cujos membros armazenam as características de [PROPSHEETHEADER](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2).

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência da folha de propriedades após sua construção, mas antes que ela seja exibida com a função de membro [DoModal](#domodal) . Por exemplo, defina o membro *dwSize* de `m_psh` como o tamanho que você deseja que a folha de propriedades tenha.

Para obter mais informações sobre essa estrutura, incluindo uma listagem de seus membros, consulte PROPSHEETHEADER no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#143](../../mfc/codesnippet/cpp/cpropertysheet-class_9.cpp)]

##  <a name="mapdialogrect"></a>CPropertySheet::MapDialogRect

Converte as unidades de caixa de diálogo de um retângulo em unidades de tela.

```
void MapDialogRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém as coordenadas da caixa de diálogo a serem convertidas.

### <a name="remarks"></a>Comentários

As unidades da caixa de diálogo são indicadas em termos da unidade base da caixa de diálogo atual derivada da largura média e da altura dos caracteres na fonte usada para o texto da caixa de diálogo. Uma unidade horizontal é uma quarta da unidade de largura base da caixa de diálogo e uma unidade vertical é um oitavo da unidade de altura base da caixa de diálogo.

A função [GetDialogBaseUnits](/windows/win32/api/winuser/nf-winuser-getdialogbaseunits) do Windows retorna informações de tamanho para a fonte do sistema, mas você pode especificar uma fonte diferente para cada folha de propriedades se usar o estilo DS_SETFONT no arquivo de definição de recurso. A função [MapDialogRect](/windows/win32/api/winuser/nf-winuser-mapdialogrect) do Windows, descrita na SDK do Windows, usa a fonte apropriada para essa caixa de diálogo.

A `MapDialogRect` função membro substitui as unidades da caixa de diálogo em *lpRect* por unidades de tela (pixels) para que o retângulo possa ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa.

##  <a name="oninitdialog"></a>CPropertySheet:: OnInitDialog

Substitui para aumentar a inicialização da folha de propriedades.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

Especifica se o aplicativo definiu o foco de entrada para um dos controles na folha de propriedades. Se `OnInitDialog` retornar zero, o Windows definirá o foco de entrada para o primeiro controle na folha de propriedades. O aplicativo só poderá retornar 0 se tiver definido explicitamente o foco de entrada para um dos controles na folha de propriedades.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada em resposta à mensagem WM_INITDIALOG. Essa mensagem é enviada para a folha de propriedades durante as chamadas [Create](#create) ou [DoModal](#domodal) , que ocorrem imediatamente antes da exibição da folha de propriedades.

Substitua essa função de membro se você precisar executar processamento especial quando a folha de Propriedades for inicializada. Na versão substituída, primeiro chame a classe `OnInitDialog` base, mas desconsidere seu valor de retorno. Normalmente, você retornará TRUE da sua função de membro substituída.

Você não precisa de uma entrada de mapa de mensagem para essa função de membro.

##  <a name="pressbutton"></a>CPropertySheet::P ressButton

Simula a escolha do botão especificado em uma folha de propriedades.

```
void PressButton(int nButton);
```

### <a name="parameters"></a>Parâmetros

*nButton*<br/>
Nnovo Identifica o botão a ser pressionado. Esse parâmetro pode ser um dos seguintes valores:

- PSBTN_BACK Escolhe o botão voltar.

- PSBTN_NEXT escolhe o botão Avançar.

- PSBTN_FINISH escolhe o botão Concluir.

- PSBTN_OK escolhe o botão OK.

- PSBTN_APPLYNOW Escolhe o botão Aplicar agora.

- PSBTN_CANCEL escolhe o botão Cancelar.

- PSBTN_HELP escolhe o botão ajuda.

### <a name="remarks"></a>Comentários

Consulte [PSM_PRESSBUTTON](/windows/win32/Controls/psm-pressbutton) para obter mais informações sobre a mensagem de PRESSBUTTON do SDK do Windows.

Uma chamada para `PressButton` não enviará a notificação [PSN_APPLY](/windows/win32/Controls/psn-apply) de uma página de propriedades para a estrutura. Para enviar essa notificação, chame [CPropertyPage:: OnOK](../../mfc/reference/cpropertypage-class.md#onok).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#137](../../mfc/codesnippet/cpp/cpropertysheet-class_10.cpp)]

##  <a name="removepage"></a>  CPropertySheet::RemovePage

Remove uma página da folha de propriedades e destrói a janela associada.

```
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
Aponta para a página a ser removida da folha de propriedades. Não pode ser NULL.

*nPage*<br/>
Índice da página a ser removida. Deve estar entre 0 e um menor que o número de páginas na folha de propriedades, inclusive.

### <a name="remarks"></a>Comentários

O objeto [CPropertyPage](../../mfc/reference/cpropertypage-class.md) em si não é destruído até que o proprietário `CPropertySheet` da janela seja fechado.

##  <a name="setactivepage"></a>  CPropertySheet::SetActivePage

Altera a página ativa.

```
BOOL SetActivePage(int nPage);
BOOL SetActivePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*nPage*<br/>
Índice da página a ser definida. Ele deve estar entre 0 e um menor que o número de páginas na folha de propriedades, inclusive.

*pPage*<br/>
Aponta para a página a ser definida na folha de propriedades. Não pode ser nulo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de Propriedades for ativada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por exemplo, use `SetActivePage` se a ação de um usuário em uma página deve fazer com que outra página se torne a página ativa.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CPropertySheet:: GetActivePage](#getactivepage).

##  <a name="setfinishtext"></a>  CPropertySheet::SetFinishText

Define o texto no botão de comando concluir.

```
void SetFinishText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para o texto a ser exibido no botão de comando concluir.

### <a name="remarks"></a>Comentários

Chame `SetFinishText` para exibir o texto no botão de comando concluir e ocultar os botões Avançar e voltar depois que o usuário concluir a ação na última página do assistente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#138](../../mfc/codesnippet/cpp/cpropertysheet-class_11.cpp)]

##  <a name="settitle"></a>CPropertySheet:: SetTitle

Especifica a legenda da folha de Propriedades (o texto exibido na barra de título de uma janela do quadro).

```
void SetTitle(
    LPCTSTR lpszText,
    UINT nStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
Especifica o estilo do título da folha de propriedades. O estilo deve ser especificado em 0 ou como PSH_PROPTITLE. Se o estilo for definido como PSH_PROPTITLE, a palavra "Propriedades" será exibida após o texto especificado como a legenda. Por exemplo, chamar `SetTitle`("Simple", PSH_PROPTITLE) resultará em uma legenda de folha de propriedades de "Propriedades simples".

*lpszText*<br/>
Aponta para o texto a ser usado como a legenda na barra de título da folha de propriedades.

### <a name="remarks"></a>Comentários

Por padrão, uma folha de propriedades usa o parâmetro Caption no construtor da folha de propriedades.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#139](../../mfc/codesnippet/cpp/cpropertysheet-class_12.cpp)]

##  <a name="setwizardbuttons"></a>CPropertySheet::SetWizardButtons

Habilita ou desabilita o botão voltar, avançar ou concluir em uma folha de propriedades do assistente.

```
void SetWizardButtons(DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um conjunto de sinalizadores que personalizam a função e a aparência dos botões do assistente. Esse parâmetro pode ser uma combinação dos seguintes valores:

- Botão voltar do PSWIZB_BACK

- Botão Avançar do PSWIZB_NEXT

- Botão Concluir PSWIZB_FINISH

- Botão Concluir do PSWIZB_DISABLEDFINISH desabilitado

### <a name="remarks"></a>Comentários

Chame `SetWizardButtons` somente depois que a caixa de diálogo estiver aberta; `SetWizardButtons` você não pode chamar antes de chamar [DoModal](#domodal). Normalmente, você deve chamar `SetWizardButtons` de [CPropertyPage:: OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).

Se você quiser alterar o texto no botão Concluir ou ocultar os botões Avançar e voltar depois que o usuário concluir o assistente, chame [SetFinishText](#setfinishtext). Observe que o mesmo botão é compartilhado para concluir e avançar. Você pode exibir um botão Concluir ou avançar ao mesmo tempo, mas não ambos.

### <a name="example"></a>Exemplo

Um `CPropertySheet` tem três páginas de propriedades do `CStylePage`assistente `CColorPage`:, `CShapePage`e.  O fragmento de código abaixo mostra como habilitar e desabilitar os botões **voltar** e **Avançar** na página de propriedades do assistente.

[!code-cpp[NVC_MFCDocView#140](../../mfc/codesnippet/cpp/cpropertysheet-class_13.cpp)]

[!code-cpp[NVC_MFCDocView#141](../../mfc/codesnippet/cpp/cpropertysheet-class_14.cpp)]

[!code-cpp[NVC_MFCDocView#138](../../mfc/codesnippet/cpp/cpropertysheet-class_11.cpp)]

##  <a name="setwizardmode"></a>CPropertySheet:: SetWizardMode

Estabelece uma página de propriedades como um assistente.

```
void SetWizardMode();
```

### <a name="remarks"></a>Comentários

Uma característica importante de uma página de propriedades do assistente é que o usuário navega usando os botões Avançar ou concluir, voltar e cancelar, em vez de guias.

Chame `SetWizardMode` antes de chamar [DoModal](#domodal). Depois de chamar `SetWizardMode`, `DoModal` o retornará ID_WIZFINISH (se o usuário fechar com o botão Concluir) ou IDCANCEL.

`SetWizardMode`define o sinalizador PSH_WIZARD.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#142](../../mfc/codesnippet/cpp/cpropertysheet-class_15.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de CMNCTRL1 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de CMNCTRL2 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de PROPDLG do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de SNAPVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

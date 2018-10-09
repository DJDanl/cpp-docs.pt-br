---
title: Classe CPropertySheet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 50b1816320521f8ad20ee64fc4a051f938e902ec
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48890771"
---
# <a name="cpropertysheet-class"></a>Classe CPropertySheet

Representa as folhas de propriedades, também conhecido como caixas de diálogo de guia.

## <a name="syntax"></a>Sintaxe

```
class CPropertySheet : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::CPropertySheet](#cpropertysheet)|Constrói um objeto `CPropertySheet`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::AddPage](#addpage)|Adiciona uma página para a folha de propriedades.|
|[CPropertySheet::Construct](#construct)|Constrói um objeto `CPropertySheet`.|
|[CPropertySheet::Create](#create)|Exibe uma folha de propriedades sem janela restrita.|
|[CPropertySheet::DoModal](#domodal)|Exibe uma folha de propriedades modais.|
|[CPropertySheet::EnableStackedTabs](#enablestackedtabs)|Indica se a folha de propriedades usa guias empilhadas ou de rolagem.|
|[CPropertySheet::EndDialog](#enddialog)|Encerra a folha de propriedades.|
|[CPropertySheet::GetActiveIndex](#getactiveindex)|Recupera o índice da página de folha de propriedades do Active Directory.|
|[CPropertySheet::GetActivePage](#getactivepage)|Retorna o objeto de página ativa.|
|[CPropertySheet::GetPage](#getpage)|Recupera um ponteiro para a página especificada.|
|[CPropertySheet::GetPageCount](#getpagecount)|Recupera o número de páginas na folha de propriedades.|
|[CPropertySheet::GetPageIndex](#getpageindex)|Recupera o índice da página da folha de propriedades especificada.|
|[CPropertySheet::GetTabControl](#gettabcontrol)|Recupera um ponteiro para um controle guia.|
|[CPropertySheet::MapDialogRect](#mapdialogrect)|Converte as unidades de caixa de diálogo de um retângulo em unidades de tela.|
|[CPropertySheet::OnInitDialog](#oninitdialog)|Ignorar para aumentar a inicialização de folha de propriedade.|
|[CPropertySheet::PressButton](#pressbutton)|Simula a escolha do botão especificado em uma folha de propriedades.|
|[CPropertySheet::RemovePage](#removepage)|Remove uma página da folha de propriedades.|
|[CPropertySheet::SetActivePage](#setactivepage)|Define programaticamente o objeto de página ativa.|
|[CPropertySheet::SetFinishText](#setfinishtext)|Define o texto para o botão Concluir.|
|[CPropertySheet::SetTitle](#settitle)|Define a legenda da folha de propriedades.|
|[CPropertySheet::SetWizardButtons](#setwizardbuttons)|Permite que os botões do assistente.|
|[CPropertySheet::SetWizardMode](#setwizardmode)|Habilita o modo de assistente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::m_psh](#m_psh)|O Windows [PROPSHEETHEADER](/windows/desktop/api/prsht/ns-prsht-_propsheetheadera_v2) estrutura. Fornece acesso aos parâmetros de folha de propriedade básico.|

## <a name="remarks"></a>Comentários

Consiste em uma folha de propriedades de um `CPropertySheet` objeto e um ou mais [CPropertyPage](../../mfc/reference/cpropertypage-class.md) objetos. O framework exibe uma folha de propriedades como uma janela com um conjunto de índices de guia e uma área que contém a página atualmente selecionada. O usuário navega para uma página específica usando a guia apropriada.

`CPropertySheet` fornece suporte para o expandida [PROPSHEETHEADER](/windows/desktop/api/prsht/ns-prsht-_propsheetheadera_v2) estrutura introduzida no Windows 98 e Windows NT 2000. A estrutura contém os sinalizadores adicionais e membros que dão suporte ao uso de um bitmap do plano de fundo de "marca d'água".

Para exibir essas novas imagens automaticamente em seu objeto de planilha de propriedade, passar os valores válidos para as imagens de bitmap e paleta na chamada para [CPropertySheet::Construct](#construct) ou [CPropertySheet::CPropertySheet](#cpropertysheet).

Embora `CPropertySheet` não é derivado de [CDialog](../../mfc/reference/cdialog-class.md), o gerenciamento um `CPropertySheet` objeto é como gerenciar um `CDialog` objeto. Por exemplo, a criação de uma folha de propriedades requer construção de duas partes: chamar o construtor e, em seguida, chame [DoModal](#domodal) para uma folha de propriedades modal ou [criar](#create) para uma folha de propriedades sem janela restrita. `CPropertySheet` tem dois tipos de construtores: [CPropertySheet::Construct](#construct) e [CPropertySheet::CPropertySheet](#cpropertysheet).

Quando você constrói uma `CPropertySheet` do objeto, algumas [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) pode causar uma exceção de primeira chance ocorra. Isso resulta no sistema tentar alterar o estilo da folha de propriedades antes que a planilha é criada. Para evitar essa exceção, certifique-se de que você defina os seguintes estilos quando você cria seu `CPropertySheet`:

- DS_3DLOOK

- DS_CONTROL

- WS_CHILD

- WS_TABSTOP

Os estilos a seguir são opcionais e não fará com que a exceção de primeira chance:

- DS_SHELLFONT

- DS_LOCALEDIT

- WS_CLIPCHILDREN

Qualquer outro `Window Styles` são proibidos e você não deve habilitá-los.

Troca de dados entre um `CPropertySheet` objeto e um objeto externo é semelhante a troca de dados com um `CDialog` objeto. A diferença importante é que as configurações de uma folha de propriedades são geralmente as variáveis de membro a `CPropertyPage` objetos, em vez do `CPropertySheet` objeto propriamente dito.

Você pode criar um tipo de caixa de diálogo de guia chamado um assistente, que consiste em uma folha de propriedades com uma sequência de páginas de propriedade que guiam o usuário pelas etapas de uma operação, como configuração de um dispositivo ou criando um boletim informativo. Na caixa de diálogo guia de tipo de assistente, as páginas de propriedade não tem as guias e página de apenas uma propriedade é visível por vez. Além disso, em vez de precisar **Okey** e **aplicar agora** botões, uma caixa de diálogo de tipo de assistente guia tem um **volta** botão, uma **Avançar** ou  **Terminar** botão, uma **Cancelar** botão e uma **ajuda** botão.

Para criar uma caixa de diálogo de tipo de assistente, siga as mesmas etapas que você seguiria para criar uma folha de propriedades padrão, mas chama [SetWizardMode](#setwizardmode) antes de chamar [DoModal](#domodal). Para habilitar os botões do assistente, chame [SetWizardButtons](#setwizardbuttons), usar sinalizadores para personalizar sua função e aparência. Para habilitar o **terminar** botão, chame [SetFinishText](#setfinishtext) depois que o usuário executou a ação na última página do assistente.

Para obter mais informações sobre como usar `CPropertySheet` objetos, consulte o artigo [folhas de propriedades e páginas de propriedade](../../mfc/property-sheets-and-property-pages-in-mfc.md).

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

*Página*<br/>
Aponta para a página a ser adicionado à folha de propriedades. Não pode ser NULL.

### <a name="remarks"></a>Comentários

Adicione páginas para a folha de propriedades na ordem esquerda para a direita, que você deseja exibi-los.

`AddPage` Adiciona o [CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage) do objeto para o `CPropertySheet` objeto da lista de páginas, mas não cria, na verdade, a janela para a página. O framework adia a criação da janela para a página até que o usuário seleciona nessa página.

Quando você adiciona uma página de propriedade usando `AddPage`, o `CPropertySheet` é o pai do `CPropertyPage`. Para acessar a folha de propriedades de página de propriedades, chame [CWnd::GetParent](../../mfc/reference/cwnd-class.md#getparent).

Não é necessário esperar até a criação da janela de folha de propriedade para chamar `AddPage`. Normalmente, você chamará `AddPage` antes de chamar [DoModal](#domodal) ou [criar](#create).

Se você chamar `AddPage` depois de exibir a página de propriedades, a linha da guia refletirá a página recém-adicionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#129](../../mfc/codesnippet/cpp/cpropertysheet-class_1.cpp)]

##  <a name="construct"></a>  CPropertySheet::Construct

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
ID da legenda a ser usado para a folha de propriedades.

*pParentWnd*<br/>
Ponteiro para a janela pai da folha de propriedades. Se for NULL, a janela pai será a janela principal do aplicativo.

*iSelectPage*<br/>
O índice da página que será inicialmente na parte superior. O padrão é a primeira página adicionada à folha.

*pszCaption*<br/>
Ponteiro para uma cadeia de caracteres que contém a legenda a ser usado para a folha de propriedades. Não pode ser NULL.

*hbmWatermark*<br/>
Identificador para o bitmap de marca d'água da página de propriedades.

*hpalWatermark*<br/>
Identificador para a paleta do bitmap de marca d'água e/ou o bitmap de cabeçalho.

*hbmHeader*<br/>
Identificador para o bitmap de cabeçalho da página de propriedades.

### <a name="remarks"></a>Comentários

Chame essa função de membro, se um dos construtores de classe já não tiver sido chamado. Por exemplo, chamar `Construct` quando você declarar ou alocar matrizes de `CPropertySheet` objetos. No caso de matrizes, você deve chamar `Construct` para cada membro da matriz.

Para exibir a folha de propriedades, chame [DoModal](#domodal) ou [criar](#create). A cadeia de caracteres contida no primeiro parâmetro será colocada na barra de legenda para a folha de propriedades.

Você pode exibir imagens de marca d'água e/ou cabeçalho automaticamente, se você usar os protótipos de terceiro ou quarto de `Construct`listados acima e passar os valores válidos o *hbmWatermark*, *hpalWatermark* , e/ou *hbmHeader* parâmetros.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra sob quais circunstâncias você chamaria `Construct`.

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
ID da legenda a ser usado para a folha de propriedades.

*pParentWnd*<br/>
Aponta para a janela pai da folha de propriedades. Se for NULL, a janela pai será a janela principal do aplicativo.

*iSelectPage*<br/>
O índice da página que será inicialmente na parte superior. O padrão é a primeira página adicionada à folha.

*pszCaption*<br/>
Aponta para uma cadeia de caracteres que contém a legenda a ser usado para a folha de propriedades. Não pode ser NULL.

*hbmWatermark*<br/>
Um identificador para o bitmap do plano de fundo da folha de propriedades.

*hpalWatermark*<br/>
Um identificador para a paleta do bitmap de marca d'água e/ou o bitmap de cabeçalho.

*hbmHeader*<br/>
Um identificador para o bitmap de cabeçalho da página de propriedades.

### <a name="remarks"></a>Comentários

Para exibir a folha de propriedades, chame [DoModal](#domodal) ou [criar](#create). A cadeia de caracteres contida no primeiro parâmetro será colocada na barra de legenda para a folha de propriedades.

Se você tiver vários parâmetros (por exemplo, se você estiver usando uma matriz), use [construir](#construct) em vez de `CPropertySheet`.

Você pode exibir imagens de marca d'água e/ou cabeçalho automaticamente, se você usar os protótipos de terceiro ou quarto de `CPropertySheet`, acima, e você passar os valores válidos o *hbmWatermark*, *hpalWatermark*, e / ou *hbmHeader* parâmetros.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#131](../../mfc/codesnippet/cpp/cpropertysheet-class_3.cpp)]

##  <a name="create"></a>  CPropertySheet::Create

Exibe uma folha de propriedades sem janela restrita.

```
virtual BOOL Create(CWnd* pParentWnd = NULL,
    DWORD dwStyle = (DWORD)-1,
    DWORD dwExStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Aponta para a janela pai. Se for NULL, o pai é a área de trabalho.

*dwStyle*<br/>
Estilos de janela para a folha de propriedades. Para obter uma lista completa de estilos disponíveis, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*dwExStyle*<br/>
Estilos de janela estendidos para a folha de propriedades. Para obter uma lista completa de estilos disponíveis, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles)

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de propriedades é criada com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A chamada para `Create` pode ser dentro do construtor, ou você pode chamá-lo depois que o construtor é invocado.

O estilo padrão, expressado, passando -1 como *dwStyle*, é realmente WS_SYSMENU&#124;WS_POPUP&#124;WS_CAPTION&#124;DS_MODALFRAME&#124;DS_CONTEXTHELP&#124;WS_VISIBLE. O padrão estilo estendido de janela, expressado, passando 0 como *dwExStyle*, é realmente WS_EX_DLGMODALFRAME.

O `Create` função membro retorna imediatamente depois de criar a folha de propriedades. Para destruir a folha de propriedades, chame [CWnd::DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow).

Folhas de propriedades sem janela restrita exibidas com uma chamada para `Create` possui botões Okey, cancelar, aplicar agora e ajuda como folhas de propriedades modais. Botões desejado devem ser criado pelo usuário.

Para exibir uma folha de propriedades modal, chame [DoModal](#domodal) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#132](../../mfc/codesnippet/cpp/cpropertysheet-class_4.cpp)]

[!code-cpp[NVC_MFCDocView#133](../../mfc/codesnippet/cpp/cpropertysheet-class_5.cpp)]

##  <a name="domodal"></a>  CPropertySheet::DoModal

Exibe uma folha de propriedades modais.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

IDOK ou IDCANCEL se a função for bem-sucedida; Caso contrário, 0 ou -1. Se a folha de propriedades foi estabelecida como um assistente (consulte [SetWizardMode](#setwizardmode)), `DoModal` retorna ID_WIZFINISH ou IDCANCEL.

### <a name="remarks"></a>Comentários

O valor retornado corresponde à ID do controle que fechou a folha de propriedades. Depois que essa função retornar, os windows correspondente para a folha de propriedades e todas as páginas serão tenham sido destruídos. Os objetos em si ainda existirão. Normalmente, você recuperará os dados a partir o [CPropertyPage](../../mfc/reference/cpropertypage-class.md) objetos após `DoModal` retorna IDOK.

Para exibir uma folha de propriedades sem janela restrita, chame [criar](#create) em vez disso.

Quando uma página de propriedades é criada a partir de seu recurso de caixa de diálogo correspondente, ele pode causar uma exceção de primeira chance. Isso resulta da página de propriedade alterando o estilo do recurso da caixa de diálogo para o estilo necessário antes que a página é criada. Como os recursos são geralmente somente leitura, isso faz com que uma exceção. O sistema manipula a exceção e faz uma cópia do recurso modificado. A exceção de primeira chance, portanto, pode ser ignorada.

> [!NOTE]
>  Essa exceção deve ser tratada pelo sistema operacional, se você estiver compilando com o modelo de tratamento de exceções assíncronas. Para obter mais informações sobre modelos de tratamento de exceções, consulte [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md). Nesse caso, não encapsulam chamadas para `CPropertySheet::DoModal` com um bloco try-catch de C++ que catch lida com todas as exceções, por exemplo, `catch (...)`. Este bloco lidaria com a exceção destinada para o sistema operacional e causa um comportamento imprevisível. No entanto, você pode usar com segurança C++ tratamento de exceções com os tipos de exceção específica ou tratamento de exceções estruturado em que a exceção de violação de acesso é passada para o sistema operacional.

Para evitar gerar essa exceção de primeira chance, você pode garantir manualmente que a folha de propriedades tem correto [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Você precisa definir os estilos para uma folha de propriedades a seguir:

- DS_3DLOOK

- DS_CONTROL

- WS_CHILD

- WS_TABSTOP

Você pode usar os seguintes estilos opcionais sem causar uma exceção de primeira chance:

- DS_SHELLFONT

- DS_LOCALEDIT

- WS_CLIPCHILDREN

Desabilite todos os outros estilos do Windows porque eles não são compatíveis com folhas de propriedades. Essa recomendação não se aplica estilos estendidos. Definir esses estilos padrão adequadamente garantirá que a folha de propriedades não tem que ser modificado e evitará gerando a exceção de primeira chance.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::AddPage](#addpage).

##  <a name="enablestackedtabs"></a>  CPropertySheet::EnableStackedTabs

Indica se linhas de guias em uma folha de propriedades de pilha.

```
void EnableStackedTabs(BOOL bStacked);
```

### <a name="parameters"></a>Parâmetros

*bStacked*<br/>
Indica se as guias empilhadas estão habilitadas na folha de propriedades. Desabilitar linhas empilhadas de marcas, definindo *bStacked* como FALSE.

### <a name="remarks"></a>Comentários

Por padrão, se uma folha de propriedades tem mais guias cabem em uma única linha na largura da folha de propriedades, as guias serão empilhados de várias linhas. Para usar guias de rolagem, em vez de empilhamento de guias, chame `EnableStackedTabs` com *bStacked* definido como FALSE antes de chamar [DoModal](#domodal) ou [criar](#create).

Você deve chamar `EnableStackedTabs` quando você cria uma modal ou uma folha de propriedades sem janela restrita. Para incorporar esse estilo em um `CPropertySheet`-classe, derivada escrever um manipulador de mensagens para WM_CREATE. Em que a versão de substituição [CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate), chame `EnableStackedTabs( FALSE )` antes de chamar a implementação da classe base.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#134](../../mfc/codesnippet/cpp/cpropertysheet-class_6.cpp)]

##  <a name="enddialog"></a>  CPropertySheet::EndDialog

Encerra a folha de propriedades.

```
void EndDialog(int nEndID);
```

### <a name="parameters"></a>Parâmetros

*nEndID*<br/>
Identificador a ser usado como valor de retorno da folha de propriedades.

### <a name="remarks"></a>Comentários

Essa função membro é chamada pelo framework quando o botão Fechar, cancelar ou Okey é pressionado. Chame essa função de membro se ocorre um evento que deve fechar a folha de propriedades.

Essa função de membro só é usada com uma caixa de diálogo modal.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::PressButton](#pressbutton).

##  <a name="getactiveindex"></a>  CPropertySheet::GetActiveIndex

Obtém o número de índice da página de Active Directory da janela de folha de propriedades e, em seguida, usa o número de índice retornado como o parâmetro para `GetPage`.

```
int GetActiveIndex() const;
```

### <a name="return-value"></a>Valor de retorno

O número de índice da página ativa.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::GetActivePage](#getactivepage).

##  <a name="getactivepage"></a>  CPropertySheet::GetActivePage

Recupera a página ativa da janela de folha de propriedades.

```
CPropertyPage* GetActivePage() const;
```

### <a name="return-value"></a>Valor de retorno

O ponteiro para a página ativa.

### <a name="remarks"></a>Comentários

Use esta função de membro para realizar alguma ação na página ativa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#135](../../mfc/codesnippet/cpp/cpropertysheet-class_7.cpp)]

##  <a name="getpage"></a>  CPropertySheet::GetPage

Retorna um ponteiro para a página especificada na folha de propriedades.

```
CPropertyPage* GetPage(int nPage) const;
```

### <a name="parameters"></a>Parâmetros

*nPage*<br/>
Índice da página desejada, começando em 0. Deve ser entre 0 e menor que o número de páginas na folha de propriedades, inclusive.

### <a name="return-value"></a>Valor de retorno

O ponteiro para a página correspondente para o *nPage* parâmetro.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertyPage::OnWizardFinish](../../mfc/reference/cpropertypage-class.md#onwizardfinish).

##  <a name="getpagecount"></a>  CPropertySheet::GetPageCount

Determina o número de páginas atualmente na folha de propriedades.

```
int GetPageCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de páginas na folha de propriedades.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertyPage::OnWizardFinish](../../mfc/reference/cpropertypage-class.md#onwizardfinish).

##  <a name="getpageindex"></a>  CPropertySheet::GetPageIndex

Recupera o número de índice da página especificada na folha de propriedades.

```
int GetPageIndex(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*Página*<br/>
Aponta para a página com o índice a ser localizada. Não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

O número de índice de uma página.

### <a name="remarks"></a>Comentários

Por exemplo, você usaria `GetPageIndex` para obter o índice de página para usar [SetActivePage](#setactivepage) ou [GetPage](#getpage).

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::GetActivePage](#getactivepage).

##  <a name="gettabcontrol"></a>  CPropertySheet::GetTabControl

Recupera um ponteiro para um controle de guia para fazer algo específico para o controle de guia (ou seja, para usar qualquer uma das APIs no [CTabCtrl](../../mfc/reference/ctabctrl-class.md)).

```
CTabCtrl* GetTabControl() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um controle guia.

### <a name="remarks"></a>Comentários

Por exemplo, chame essa função membro, se você quiser adicionar bitmaps em cada uma das guias durante a inicialização.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#136](../../mfc/codesnippet/cpp/cpropertysheet-class_8.cpp)]

##  <a name="m_psh"></a>  CPropertySheet::m_psh

Uma estrutura cujos membros armazenam as características dos [PROPSHEETHEADER](/windows/desktop/api/prsht/ns-prsht-_propsheetheadera_v2).

### <a name="remarks"></a>Comentários

Use essa estrutura para inicializar a aparência da folha de propriedades, depois que ele é construído, mas antes de ser exibido com o [DoModal](#domodal) função de membro. Por exemplo, defina a *dwSize* membro do `m_psh` ao tamanho você deseja ter a folha de propriedades.

Para obter mais informações sobre essa estrutura, incluindo uma lista de seus membros, consulte PROPSHEETHEADER no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#143](../../mfc/codesnippet/cpp/cpropertysheet-class_9.cpp)]

##  <a name="mapdialogrect"></a>  CPropertySheet::MapDialogRect

Converte as unidades de caixa de diálogo de um retângulo em unidades de tela.

```
void MapDialogRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) coordenadas do objeto que contém a caixa de diálogo a ser convertido.

### <a name="remarks"></a>Comentários

Unidades de caixa de diálogo são indicadas em termos de caixa de diálogo base unidade atual derivada a largura da média e a altura dos caracteres da fonte usada para o texto da caixa de diálogo. Uma unidade horizontal é um quarto da unidade de largura da base de caixa de diálogo e uma unidade vertical é um oitavo da unidade de base de altura de caixa de diálogo.

O [GetDialogBaseUnits](/windows/desktop/api/winuser/nf-winuser-getdialogbaseunits) função do Windows retorna informações sobre o tamanho da fonte do sistema, mas você pode especificar uma fonte diferente para cada folha de propriedades, se você usar o estilo DS_SETFONT no arquivo de definição de recurso. O [MapDialogRect](/windows/desktop/api/winuser/nf-winuser-mapdialogrect) função do Windows, descrita no SDK do Windows, usa a fonte apropriada para essa caixa de diálogo.

O `MapDialogRect` função de membro substitui as unidades de caixa de diálogo *lpRect* com tela unidades (pixels) para que o retângulo pode ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa.

##  <a name="oninitdialog"></a>  CPropertySheet::OnInitDialog

Substituições para aumentar a inicialização de folha de propriedade.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

Especifica se o aplicativo tiver definido o foco de entrada para um dos controles na folha de propriedades. Se `OnInitDialog` retorna diferente de zero, o Windows define o foco de entrada para o primeiro controle na folha de propriedades. O aplicativo pode retornar 0 somente se ele tiver definido explicitamente o foco de entrada para um dos controles na folha de propriedades.

### <a name="remarks"></a>Comentários

Essa função de membro é chamada em resposta à mensagem WM_INITDIALOG. Esta mensagem é enviada para a folha de propriedades durante o [Create](#create) ou [DoModal](#domodal) chamadas, o que ocorrerem imediatamente antes que a folha de propriedades é exibida.

Substitua essa função membro, se você precisar realizar processamento especial quando a folha de propriedades é inicializada. A versão substituída, chame a classe base `OnInitDialog` mas desconsiderar seu valor de retorno. Normalmente, você retornará TRUE da sua função de membro substituído.

Uma entrada de mapa de mensagem não é necessário para essa função de membro.

##  <a name="pressbutton"></a>  CPropertySheet::PressButton

Simula a escolha do botão especificado em uma folha de propriedades.

```
void PressButton(int nButton);
```

### <a name="parameters"></a>Parâmetros

*nButton*<br/>
nButton: identifica o botão seja pressionado. Esse parâmetro pode ser um dos seguintes valores:

- PSBTN_BACK escolhe o botão Voltar.

- PSBTN_NEXT escolhe o botão Avançar.

- PSBTN_FINISH escolhe o botão Concluir.

- PSBTN_OK escolhe o botão Okey.

- PSBTN_APPLYNOW escolhe o botão Aplicar agora.

- PSBTN_CANCEL escolhe o botão Cancelar.

- PSBTN_HELP escolhe o botão Ajuda.

### <a name="remarks"></a>Comentários

Ver [PSM_PRESSBUTTON](/windows/desktop/Controls/psm-pressbutton) para obter mais informações sobre a mensagem Pressbutton de SDK do Windows.

Uma chamada para `PressButton` não enviará o [PSN_APPLY](/windows/desktop/Controls/psn-apply) notificação de uma página de propriedades para a estrutura. Para enviar essa notificação, chame [CPropertyPage::OnOK](../../mfc/reference/cpropertypage-class.md#onok).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#137](../../mfc/codesnippet/cpp/cpropertysheet-class_10.cpp)]

##  <a name="removepage"></a>  CPropertySheet::RemovePage

Remove uma página de folha de propriedades e destrói a janela associada.

```
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```

### <a name="parameters"></a>Parâmetros

*Página*<br/>
Aponta para a página a ser removido da folha de propriedades. Não pode ser NULL.

*nPage*<br/>
Índice da página a ser removido. Deve ser entre 0 e menor que o número de páginas na folha de propriedades, inclusive.

### <a name="remarks"></a>Comentários

O [CPropertyPage](../../mfc/reference/cpropertypage-class.md) próprio objeto não será destruído até que o proprietário do `CPropertySheet` janela é fechada.

##  <a name="setactivepage"></a>  CPropertySheet::SetActivePage

Altera a página ativa.

```
BOOL SetActivePage(int nPage);
BOOL SetActivePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*nPage*<br/>
Índice da página para definir. Ele deve estar entre 0 e um a menos que o número de páginas na folha de propriedades, inclusive.

*Página*<br/>
Aponta para a página para definir na folha de propriedades. Ele não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a folha de propriedades é ativada com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Por exemplo, use `SetActivePage` se uma ação do usuário em uma página deve fazer com que outra página para se tornar a página ativa.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::GetActivePage](#getactivepage).

##  <a name="setfinishtext"></a>  CPropertySheet::SetFinishText

Define o texto no botão de comando final.

```
void SetFinishText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para o texto a ser exibido no botão de comando concluir.

### <a name="remarks"></a>Comentários

Chamar `SetFinishText` para exibir o texto no botão de comando concluir e ocultar os botões Avançar e voltar depois que o usuário concluir a ação na última página do assistente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#138](../../mfc/codesnippet/cpp/cpropertysheet-class_11.cpp)]

##  <a name="settitle"></a>  CPropertySheet::SetTitle

Especifica a legenda da folha de propriedades (o texto exibido na barra de título de uma janela de quadro).

```
void SetTitle(
    LPCTSTR lpszText,
    UINT nStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
Especifica o estilo do título da folha de propriedade. O estilo deve ser especificado em 0 ou como PSH_PROPTITLE. Se o estilo é definido como PSH_PROPTITLE, a palavra "Propriedades" será exibida após o texto especificado como a legenda. Por exemplo, chamar `SetTitle`("Simples", PSH_PROPTITLE) resultará em uma legenda de folha de propriedade de "Propriedades simples".

*lpszText*<br/>
Aponta para o texto a ser usado como a legenda na barra de título da folha de propriedades.

### <a name="remarks"></a>Comentários

Por padrão, uma folha de propriedades usa o parâmetro de legenda no construtor de folha de propriedade.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#139](../../mfc/codesnippet/cpp/cpropertysheet-class_12.cpp)]

##  <a name="setwizardbuttons"></a>  CPropertySheet::SetWizardButtons

Habilita ou desabilita o botão Voltar, Avançar ou concluir em uma folha de propriedades do assistente.

```
void SetWizardButtons(DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um conjunto de sinalizadores que personalizam a função e a aparência dos botões do assistente. Esse parâmetro pode ser uma combinação dos seguintes valores:

- Botão Voltar PSWIZB_BACK

- Botão Avançar PSWIZB_NEXT

- Botão Concluir PSWIZB_FINISH

- Botão PSWIZB_DISABLEDFINISH desabilitado concluir

### <a name="remarks"></a>Comentários

Chame `SetWizardButtons` somente depois que a caixa de diálogo está aberta; não é possível chamar `SetWizardButtons` antes de chamar [DoModal](#domodal). Normalmente, você deve chamar `SetWizardButtons` partir [CPropertyPage::OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).

Se você deseja alterar o texto no botão Concluir ou ocultar o próximo e Back botões assim que o usuário concluiu o assistente, chamada [SetFinishText](#setfinishtext). Observe que o mesmo botão é compartilhado para concluir e em Avançar. Você pode exibir um acabamento ou um botão próximo ao mesmo tempo, mas não ambos.

### <a name="example"></a>Exemplo

Um `CPropertySheet` tem três páginas de propriedade do assistente: `CStylePage`, `CColorPage`, e `CShapePage`.  O fragmento de código abaixo mostra como habilitar e desabilitar a **volta** e **próxima** botões na página de propriedade do assistente.

[!code-cpp[NVC_MFCDocView#140](../../mfc/codesnippet/cpp/cpropertysheet-class_13.cpp)]

[!code-cpp[NVC_MFCDocView#141](../../mfc/codesnippet/cpp/cpropertysheet-class_14.cpp)]

[!code-cpp[NVC_MFCDocView#138](../../mfc/codesnippet/cpp/cpropertysheet-class_11.cpp)]

##  <a name="setwizardmode"></a>  CPropertySheet::SetWizardMode

Estabelece uma página de propriedades como um assistente.

```
void SetWizardMode();
```

### <a name="remarks"></a>Comentários

Uma característica principal de uma página de propriedades do assistente é que o usuário navega usando lado ou concluir, fazer e Cancelar botões em vez de guias.

Chame `SetWizardMode` antes de chamar [DoModal](#domodal). Depois de chamar `SetWizardMode`, `DoModal` retornará ID_WIZFINISH (se o usuário fecha com o botão Concluir) ou IDCANCEL.

`SetWizardMode` Define o sinalizador PSH_WIZARD.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#142](../../mfc/codesnippet/cpp/cpropertysheet-class_15.cpp)]

## <a name="see-also"></a>Consulte também

[CMNCTRL1 de exemplo do MFC](../../visual-cpp-samples.md)<br/>
[CMNCTRL2 de exemplo do MFC](../../visual-cpp-samples.md)<br/>
[Exemplo MFC PROPDLG](../../visual-cpp-samples.md)<br/>
[Exemplo MFC SNAPVW](../../visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

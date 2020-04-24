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
ms.openlocfilehash: e8ab91b9a6fe76070d79ea2eee2e5765db2e99e3
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750977"
---
# <a name="cpropertysheet-class"></a>Classe CPropertySheet

Representa folhas de propriedade, também conhecidas como caixas de diálogo de guias.

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
|[CPropertySheet::Construir](#construct)|Constrói um objeto `CPropertySheet`.|
|[CPropertySheet::Criar](#create)|Exibe uma folha de propriedade modeless.|
|[CPropertySheet::DoModal](#domodal)|Exibe uma folha de propriedade modal.|
|[CPropertySheet::HabilitarStackedTabs](#enablestackedtabs)|Indica se a folha de propriedades usa guias empilhadas ou de rolagem.|
|[cPropertySheet::EndDialog](#enddialog)|Termina a folha de propriedades.|
|[CPropertySheet::GetActiveIndex](#getactiveindex)|Recupera o índice da página ativa da folha de propriedades.|
|[CPropertySheet::GetActivePage](#getactivepage)|Retorna o objeto de página ativa.|
|[CPropertySheet::GetPage](#getpage)|Recupera um ponteiro para a página especificada.|
|[CPropertySheet::GetPageCount](#getpagecount)|Recupera o número de páginas na folha de propriedades.|
|[CPropertySheet::GetPageIndex](#getpageindex)|Recupera o índice da página especificada da folha de propriedades.|
|[CPropertySheet::GettabControl](#gettabcontrol)|Recupera um ponteiro para um controle de guia.|
|[CPropertySheet::MapDialogRect](#mapdialogrect)|Converte as unidades da caixa de diálogo de um retângulo em unidades de tela.|
|[CPropertySheet::OnInitDialog](#oninitdialog)|Substituir para aumentar a inicialização da folha de propriedades.|
|[CPropertySheet::PressButton](#pressbutton)|Simula a escolha do botão especificado em uma folha de propriedade.|
|[CPropertySheet::RemovePage](#removepage)|Remove uma página da folha de propriedades.|
|[CPropertySheet::SetActivePage](#setactivepage)|Programar programáticamente o objeto de página ativa.|
|[CPropertySheet::SetFinishText](#setfinishtext)|Define o texto para o botão Concluir.|
|[CPropertySheet::SetTitle](#settitle)|Define a legenda da folha de propriedades.|
|[CPropertySheet::SetWizardButtons](#setwizardbuttons)|Habilita os botões do assistente.|
|[CPropertySheet::SetWizardMode](#setwizardmode)|Habilita o modo assistente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropertySheet::m_psh](#m_psh)|A estrutura [propsheetheader do](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2) Windows. Fornece acesso aos parâmetros básicos da folha de propriedades.|

## <a name="remarks"></a>Comentários

Uma folha de propriedade `CPropertySheet` consiste em um objeto e um ou mais objetos [CPropertyPage.](../../mfc/reference/cpropertypage-class.md) O framework exibe uma folha de propriedade como uma janela com um conjunto de índices de guias e uma área que contém a página selecionada no momento. O usuário navega para uma página específica usando a guia apropriada.

`CPropertySheet`fornece suporte para a estrutura [PROPSHEETHEADER](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2) expandida introduzida no Windows 98 e no Windows NT 2000. A estrutura contém sinalizadores adicionais e membros que suportam usando um bitmap de fundo "marca d'água".

Para exibir essas novas imagens automaticamente no objeto da folha de propriedades, passe valores válidos para as imagens bitmap e paleta na chamada para [CPropertySheet::Construct](#construct) ou [CPropertySheet::CPropertySheet](#cpropertysheet).

Embora `CPropertySheet` não seja derivado do [CDialog,](../../mfc/reference/cdialog-class.md)gerenciar `CPropertySheet` um `CDialog` objeto é como gerenciar um objeto. Por exemplo, a criação de uma folha de propriedade requer construção em duas partes: ligue para o construtor e, em seguida, chame [doModal](#domodal) para uma folha de propriedade modal ou [Criar](#create) para uma folha de propriedade modeless. `CPropertySheet`tem dois tipos de construtores: [CPropertySheet::Construct](#construct) e [CPropertySheet::CPropertySheet](#cpropertysheet).

Quando você `CPropertySheet` constrói um objeto, alguns [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) podem causar uma exceção de primeira chance. Isso resulta do sistema tentando alterar o estilo da folha de propriedades antes que a planilha seja criada. Para evitar essa exceção, certifique-se de definir `CPropertySheet`os seguintes estilos ao criar o :

- DS_3DLOOK

- DS_CONTROL

- Estilo

- Ws_tabstop

Os seguintes estilos são opcionais e não causarão a exceção de primeira chance:

- DS_SHELLFONT

- DS_LOCALEDIT

- Ws_clipchildren

Qualquer `Window Styles` outro é proibido e você não deve habilitá-los.

A troca de `CPropertySheet` dados entre um objeto e um `CDialog` objeto externo é semelhante à troca de dados com um objeto. A diferença importante é que as configurações de uma folha `CPropertyPage` de propriedade `CPropertySheet` são tipicamente variáveis de membros dos objetos em vez do objeto em si.

Você pode criar um tipo de caixa de diálogo de guia chamada assistente, que consiste em uma folha de propriedade com uma seqüência de páginas de propriedade que guiam o usuário através das etapas de uma operação, como configurar um dispositivo ou criar um boletim informativo. Em uma caixa de diálogo tipo assistente, as páginas de propriedade não têm guias e apenas uma página de propriedade é visível por vez. Além disso, em vez de ter botões **OK** e **Apply Now,** uma caixa de diálogo tipo assistente tem um botão **Voltar,** um botão **Next** ou **Finish,** um botão **Cancelar** e um botão **Ajudar.**

Para criar uma caixa de diálogo tipo assistente, siga os mesmos passos que seguiria para criar uma planilha de propriedade padrão, mas chame [SetWizardMode](#setwizardmode) antes de chamar [DoModal](#domodal). Para ativar os botões do assistente, chame [SetWizardButtons](#setwizardbuttons), usando sinalizadores para personalizar sua função e aparência. Para ativar o botão **Concluir,** ligue [setFinishText](#setfinishtext) depois que o usuário tiver tomado medidas na última página do assistente.

Para obter mais informações `CPropertySheet` sobre como usar objetos, consulte o artigo [Folhas de Propriedade e Páginas de Propriedade](../../mfc/property-sheets-and-property-pages-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CPropertySheet`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cpropertysheetaddpage"></a><a name="addpage"></a>CPropertySheet::AddPage

Adiciona a página fornecida com a guia mais à direita na folha de propriedades.

```cpp
void AddPage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
Aponta para a página a ser adicionada à folha de propriedades. Não pode ser NULL.

### <a name="remarks"></a>Comentários

Adicione páginas à folha de propriedades na ordem da esquerda para a direita que você deseja que elas apareçam.

`AddPage`adiciona o objeto [CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage) à lista de páginas do `CPropertySheet` objeto, mas não cria a janela para a página. O framework adia a criação da janela para a página até que o usuário selecione essa página.

Quando você adiciona uma `AddPage`página `CPropertySheet` de propriedade `CPropertyPage`usando, o é o pai do . Para obter acesso à folha de propriedades da página de propriedade, ligue para [CWnd::GetParent](../../mfc/reference/cwnd-class.md#getparent).

Não é necessário esperar até a criação da `AddPage`janela da folha de propriedades para chamar . Normalmente, você `AddPage` ligará antes de ligar para [doModal](#domodal) ou [Criar](#create).

Se você `AddPage` ligar depois de exibir a página de propriedade, a linha de guia susdial refletirá a página recém-adicionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#129](../../mfc/codesnippet/cpp/cpropertysheet-class_1.cpp)]

## <a name="cpropertysheetconstruct"></a><a name="construct"></a>CPropertySheet::Construir

Constrói um objeto `CPropertySheet`.

```cpp
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

*Pparentwnd*<br/>
Ponteiro para a janela pai da folha de propriedades. Se NULA, a janela pai será a janela principal do aplicativo.

*iSelectPage*<br/>
O índice da página que inicialmente estará no topo. Padrão é a primeira página adicionada à planilha.

*pszCaption*<br/>
Ponteiro para uma seqüência contendo a legenda a ser usada para a folha de propriedades. Não pode ser NULL.

*Hbmwatermark*<br/>
Manuseie o bitmap da marca d'água da página da propriedade.

*hpalWatermark*<br/>
Manuseie a paleta do bitmap da marca d'água e/ou do bitmap do cabeçalho.

*hbmHeader*<br/>
Manuseie o bitmap de cabeçalho da página de propriedade.

### <a name="remarks"></a>Comentários

Chame esta função de membro se um dos construtores de classe ainda não foi chamado. Por exemplo, `Construct` ligue quando declarar ou `CPropertySheet` alocar matrizes de objetos. No caso de matrizes, `Construct` você deve chamar para cada membro na matriz.

Para exibir a folha de propriedades, ligue para [DoModal](#domodal) ou [Criar](#create). A seqüência contida no primeiro parâmetro será colocada na barra de legendas da folha de propriedades.

Você pode exibir imagens de marca d'água e/ou cabeçalho `Construct`automaticamente se você usar o terceiro ou quarto protótipos de , listados acima, e passar valores válidos para os parâmetros *hbmWatermark,* *hpalWatermark*e/ou *hbmHeader.*

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra em `Construct`que circunstâncias você chamaria.

[!code-cpp[NVC_MFCDocView#130](../../mfc/codesnippet/cpp/cpropertysheet-class_2.cpp)]

## <a name="cpropertysheetcpropertysheet"></a><a name="cpropertysheet"></a>CPropertySheet::CPropertySheet

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

*Pparentwnd*<br/>
Aponta para a janela dos pais da folha de propriedades. Se NULA, a janela pai será a janela principal do aplicativo.

*iSelectPage*<br/>
O índice da página que inicialmente estará no topo. Padrão é a primeira página adicionada à planilha.

*pszCaption*<br/>
Aponta para uma string contendo a legenda a ser usada para a folha de propriedades. Não pode ser NULL.

*Hbmwatermark*<br/>
Uma alça para o bitmap de fundo da folha de propriedades.

*hpalWatermark*<br/>
Uma alça para a paleta do bitmap da marca d'água e/ou bitmap de cabeçalho.

*hbmHeader*<br/>
Uma alça para o bitmap de cabeçalho da página de propriedade.

### <a name="remarks"></a>Comentários

Para exibir a folha de propriedades, ligue para [DoModal](#domodal) ou [Criar](#create). A seqüência contida no primeiro parâmetro será colocada na barra de legendas da folha de propriedades.

Se você tiver vários parâmetros (por exemplo, [Construct](#construct) se estiver `CPropertySheet`usando uma matriz), use Construct em vez de .

Você pode exibir imagens de marca d'água e/ou cabeçalho automaticamente se você usar o terceiro ou quarto protótipos `CPropertySheet`de , acima, e passar valores válidos para os parâmetros *hbmWatermark,* *hpalWatermark*e/ou *hbmHeader.*

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#131](../../mfc/codesnippet/cpp/cpropertysheet-class_3.cpp)]

## <a name="cpropertysheetcreate"></a><a name="create"></a>CPropertySheet::Criar

Exibe uma folha de propriedade modeless.

```
virtual BOOL Create(CWnd* pParentWnd = NULL,
    DWORD dwStyle = (DWORD)-1,
    DWORD dwExStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Aponta para a janela dos pais. Se NULA, pai é a área de trabalho.

*Dwstyle*<br/>
Estilos de janela para folha de propriedade. Para obter uma lista completa de estilos disponíveis, consulte Estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*Dwexstyle*<br/>
Estilos de janela estendidos para folha de propriedade. Para obter uma lista completa de estilos disponíveis, consulte [Estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles)

### <a name="return-value"></a>Valor retornado

Não zero se a folha de propriedade for criada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A chamada `Create` pode estar dentro da construtora, ou você pode chamá-lo depois que o construtor é invocado.

O estilo padrão, expresso ao passar -1 como *dwStyle,* é realmente WS_SYSMENU&#124;&#124;WS_POPUP&#124;WS_CAPTION&#124;DS_MODALFRAME&#124;&#124;&#124;&#124;DS_CONTEXTHELP&#124;WS_VISIBLE. O estilo padrão de janela estendida, expresso passando 0 como *dwExStyle,* é realmente WS_EX_DLGMODALFRAME.

A `Create` função membro retorna imediatamente após a criação da folha de propriedades. Para destruir a folha de propriedades, ligue para [CWnd::DestroyWindow](../../mfc/reference/cwnd-class.md#destroywindow).

Folhas de propriedade modeless exibidas com uma chamada para `Create` não ter botões OK, Cancel, Apply Now e Help como as folhas de propriedade modais fazem. Os botões desejados devem ser criados pelo usuário.

Para exibir uma folha de propriedade modal, ligue para [o DoModal.](#domodal)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#132](../../mfc/codesnippet/cpp/cpropertysheet-class_4.cpp)]

[!code-cpp[NVC_MFCDocView#133](../../mfc/codesnippet/cpp/cpropertysheet-class_5.cpp)]

## <a name="cpropertysheetdomodal"></a><a name="domodal"></a>CPropertySheet::DoModal

Exibe uma folha de propriedade modal.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL se a função foi bem sucedida; caso contrário, 0 ou -1. Se a folha de propriedades tiver sido estabelecida como `DoModal` um assistente (consulte [SetWizardMode),](#setwizardmode)retorne ID_WIZFINISH ou IDCANCEL.

### <a name="remarks"></a>Comentários

O valor de devolução corresponde ao ID do controle que fechou a folha de imóveis. Após o retorno dessa função, as janelas correspondentes à folha de propriedade e todas as páginas terão sido destruídas. Os objetos em si ainda existirão. Normalmente, você recuperará dados dos objetos [CPropertyPage](../../mfc/reference/cpropertypage-class.md) após `DoModal` o retorno do IDOK.

Para exibir uma folha de propriedade modeless, ligue [para Criar.](#create)

Quando uma página de propriedade é criada a partir de seu recurso de diálogo correspondente, ela pode causar uma exceção de primeira chance. Isso resulta da página de propriedade alterando o estilo do recurso de diálogo para o estilo necessário antes de a página ser criada. Como os recursos são geralmente somente leitura, isso causa uma exceção. O sistema lida com a exceção e faz uma cópia do recurso modificado. A exceção de primeira chance pode, portanto, ser ignorada.

> [!NOTE]
> Esta exceção deve ser tratada pelo sistema operacional se você estiver compilando com o modelo de manipulação de exceções assíncrona. Para obter mais informações sobre modelos de tratamento de exceção, consulte [/EH (Modelo de Tratamento de Exceções)](../../build/reference/eh-exception-handling-model.md). Neste caso, não enrole `CPropertySheet::DoModal` chamadas para um bloco de tentativa de captura C++ no `catch (...)`qual a captura lida com todas as exceções, por exemplo, . Esse bloco lidaria com a exceção destinada ao sistema operacional e causaria comportamento imprevisível. No entanto, você pode usar com segurança o tratamento de exceção C++ com tipos específicos de exceção ou tratamento estruturado de exceção onde a exceção de Violação de Acesso é transmitida para o sistema operacional.

Para evitar gerar essa exceção de primeira chance, você pode garantir manualmente que a folha de propriedades tenha os [estilos de janela corretos](../../mfc/reference/styles-used-by-mfc.md#window-styles). Você precisa definir os seguintes estilos para uma folha de propriedades:

- DS_3DLOOK

- DS_CONTROL

- Estilo

- Ws_tabstop

Você pode usar os seguintes estilos opcionais sem causar uma exceção de primeira chance:

- DS_SHELLFONT

- DS_LOCALEDIT

- Ws_clipchildren

Desative todos os outros estilos do Windows porque eles não são compatíveis com folhas de propriedade. Este conselho não se aplica a estilos estendidos. Definir esses estilos padrão adequadamente garantirá que a folha de propriedades não precise ser modificada e evitará gerar a exceção de primeira chance.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::AddPage](#addpage).

## <a name="cpropertysheetenablestackedtabs"></a><a name="enablestackedtabs"></a>CPropertySheet::HabilitarStackedTabs

Indica se deve empilhar linhas de guias em uma folha de propriedade.

```cpp
void EnableStackedTabs(BOOL bStacked);
```

### <a name="parameters"></a>Parâmetros

*bStacked*<br/>
Indica se as guias empilhadas estão habilitadas na folha de propriedades. Desativar linhas de tags empilhadas definindo *bStacked* to FALSE.

### <a name="remarks"></a>Comentários

Por padrão, se uma folha de propriedade tiver mais guias do que caberá em uma única linha na largura da folha de propriedades, as guias serão empilhadas em várias linhas. Para usar guias de rolagem em `EnableStackedTabs` vez de empilhar guias, ligue com *bStacked* set para FALSE antes de chamar [DoModal](#domodal) ou [Create](#create).

Você deve `EnableStackedTabs` ligar quando criar um modal ou uma folha de propriedade modelada. Para incorporar esse `CPropertySheet`estilo em uma classe derivada, escreva um manipulador de mensagens para WM_CREATE. Na versão substituída de [CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate) `EnableStackedTabs( FALSE )` , chamada antes de chamar a implementação da classe base.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#134](../../mfc/codesnippet/cpp/cpropertysheet-class_6.cpp)]

## <a name="cpropertysheetenddialog"></a><a name="enddialog"></a>cPropertySheet::EndDialog

Termina a folha de propriedades.

```cpp
void EndDialog(int nEndID);
```

### <a name="parameters"></a>Parâmetros

*nEndID*<br/>
Identificador a ser usado como valor de devolução da folha de propriedade.

### <a name="remarks"></a>Comentários

Esta função de membro é chamada pela estrutura quando o botão OK, Cancel ou Close é pressionado. Ligue para esta função de membro se ocorrer um evento que deve fechar a folha de propriedades.

Esta função de membro só é usada com uma caixa de diálogo modal.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::PressButton](#pressbutton).

## <a name="cpropertysheetgetactiveindex"></a><a name="getactiveindex"></a>CPropertySheet::GetActiveIndex

Obtém o número de índice da página ativa da janela da folha de `GetPage`propriedade e, em seguida, usa o número de índice retornado como parâmetro para .

```
int GetActiveIndex() const;
```

### <a name="return-value"></a>Valor retornado

O número de índice da página ativa.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::GetActivePage](#getactivepage).

## <a name="cpropertysheetgetactivepage"></a><a name="getactivepage"></a>CPropertySheet::GetActivePage

Recupera a página ativa da janela da folha de propriedades.

```
CPropertyPage* GetActivePage() const;
```

### <a name="return-value"></a>Valor retornado

O ponteiro para a página ativa.

### <a name="remarks"></a>Comentários

Use esta função de membro para executar alguma ação na página ativa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#135](../../mfc/codesnippet/cpp/cpropertysheet-class_7.cpp)]

## <a name="cpropertysheetgetpage"></a><a name="getpage"></a>CPropertySheet::GetPage

Retorna um ponteiro para a página especificada nesta planilha de propriedades.

```
CPropertyPage* GetPage(int nPage) const;
```

### <a name="parameters"></a>Parâmetros

*Npage*<br/>
Índice da página desejada, a partir de 0. Deve ser entre 0 e um a menos do que o número de páginas na folha de propriedades, inclusive.

### <a name="return-value"></a>Valor retornado

O ponteiro para a página correspondente ao parâmetro *nPage.*

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertyPage::OnWizardFinish](../../mfc/reference/cpropertypage-class.md#onwizardfinish).

## <a name="cpropertysheetgetpagecount"></a><a name="getpagecount"></a>CPropertySheet::GetPageCount

Determina o número de páginas atualmente na planilha de propriedades.

```
int GetPageCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de páginas na folha de propriedades.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertyPage::OnWizardFinish](../../mfc/reference/cpropertypage-class.md#onwizardfinish).

## <a name="cpropertysheetgetpageindex"></a><a name="getpageindex"></a>CPropertySheet::GetPageIndex

Recupera o número de índice da página especificada na folha de propriedades.

```
int GetPageIndex(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
Aponta para a página com o índice a ser encontrado. Não pode ser NULL.

### <a name="return-value"></a>Valor retornado

O número de índice de uma página.

### <a name="remarks"></a>Comentários

Por exemplo, você `GetPageIndex` usaria para obter o índice de página para usar [SetActivePage](#setactivepage) ou [GetPage](#getpage).

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::GetActivePage](#getactivepage).

## <a name="cpropertysheetgettabcontrol"></a><a name="gettabcontrol"></a>CPropertySheet::GettabControl

Recupera um ponteiro para um controle de guia para fazer algo específico para o controle da guia (ou seja, para usar qualquer uma das APIs em [CTabCtrl](../../mfc/reference/ctabctrl-class.md)).

```
CTabCtrl* GetTabControl() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um controle de guia.

### <a name="remarks"></a>Comentários

Por exemplo, chame esta função de membro se quiser adicionar bitmaps a cada uma das guias durante a inicialização.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#136](../../mfc/codesnippet/cpp/cpropertysheet-class_8.cpp)]

## <a name="cpropertysheetm_psh"></a><a name="m_psh"></a>CPropertySheet::m_psh

Uma estrutura cujos membros armazenam as características do [PROPSHEETHEADER](/windows/win32/api/prsht/ns-prsht-propsheetheadera_v2).

### <a name="remarks"></a>Comentários

Use esta estrutura para inicializar o aparecimento da folha de propriedade depois que ela for construída, mas antes de ser exibida com a função [membro DoModal.](#domodal) Por exemplo, defina o `m_psh` membro *dwSize* para o tamanho que você deseja que a folha de propriedades tenha.

Para obter mais informações sobre esta estrutura, incluindo uma listagem de seus membros, consulte PROPSHEETHEADER no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#143](../../mfc/codesnippet/cpp/cpropertysheet-class_9.cpp)]

## <a name="cpropertysheetmapdialogrect"></a><a name="mapdialogrect"></a>CPropertySheet::MapDialogRect

Converte as unidades da caixa de diálogo de um retângulo em unidades de tela.

```cpp
void MapDialogRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém as coordenadas da caixa de diálogo a ser convertida.

### <a name="remarks"></a>Comentários

As unidades de caixa de diálogo são indicadas em termos da unidade base da caixa de diálogo atual derivada da largura e altura médiados caracteres na fonte usada para texto da caixa de diálogo. Uma unidade horizontal é um quarto da unidade de largura base da caixa de diálogo, e uma unidade vertical é um oitavo da unidade de altura da base da caixa de diálogo.

A função [GetDialogBaseUnits](/windows/win32/api/winuser/nf-winuser-getdialogbaseunits) Windows retorna informações de tamanho para a fonte do sistema, mas você pode especificar uma fonte diferente para cada folha de propriedade se você usar o estilo DS_SETFONT no arquivo de definição de recurso. A função [MapDialogRect](/windows/win32/api/winuser/nf-winuser-mapdialogrect) Windows, descrita no Windows SDK, usa a fonte apropriada para esta caixa de diálogo.

A `MapDialogRect` função membro substitui as unidades da caixa de diálogo em *lpRect* por unidades de tela (pixels) para que o retângulo possa ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa.

## <a name="cpropertysheetoninitdialog"></a><a name="oninitdialog"></a>CPropertySheet::OnInitDialog

Substitui-se para aumentar a inicialização da folha de propriedades.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

Especifica se o aplicativo definiu o foco de entrada para um dos controles na folha de propriedades. Se `OnInitDialog` retornar não zero, o Windows definirá o foco de entrada para o primeiro controle na folha de propriedades. O aplicativo só pode retornar 0 se tiver explicitamente definido o foco de entrada para um dos controles na folha de propriedades.

### <a name="remarks"></a>Comentários

Esta função membro é chamada em resposta à mensagem WM_INITDIALOG. Esta mensagem é enviada para a folha de propriedades durante as chamadas [Criar](#create) ou [DoModal,](#domodal) que ocorrem imediatamente antes da planilha de propriedades ser exibida.

Anular essa função de membro se você precisar realizar um processamento especial quando a folha de propriedade for inicializada. Na versão substituída, primeiro chame a `OnInitDialog` classe base, mas desconsidere seu valor de retorno. Você normalmente retornará TRUE de sua função de membro substituído.

Você não precisa de uma entrada de mapa de mensagem para esta função de membro.

## <a name="cpropertysheetpressbutton"></a><a name="pressbutton"></a>CPropertySheet::PressButton

Simula a escolha do botão especificado em uma folha de propriedade.

```cpp
void PressButton(int nButton);
```

### <a name="parameters"></a>Parâmetros

*nBotão*<br/>
nButton: Identifica o botão a ser pressionado. Este parâmetro pode ser um dos seguintes valores:

- PSBTN_BACK Escolha o botão Voltar.

- PSBTN_NEXT Escolha o botão Seguinte.

- PSBTN_FINISH Escolha o botão Terminar.

- PSBTN_OK Escolha o botão OK.

- PSBTN_APPLYNOW Escolha o botão Aplicar agora.

- PSBTN_CANCEL Escolha o botão Cancelar.

- PSBTN_HELP Escolha o botão Ajudar.

### <a name="remarks"></a>Comentários

Consulte [PSM_PRESSBUTTON](/windows/win32/Controls/psm-pressbutton) para obter mais informações sobre a mensagem do botão de botão do Windows SDK.

Uma chamada `PressButton` para não enviar a notificação [de PSN_APPLY](/windows/win32/Controls/psn-apply) de uma página de propriedade para o framework. Para enviar esta notificação, ligue para [CPropertyPage::OnOK](../../mfc/reference/cpropertypage-class.md#onok).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#137](../../mfc/codesnippet/cpp/cpropertysheet-class_10.cpp)]

## <a name="cpropertysheetremovepage"></a><a name="removepage"></a>CPropertySheet::RemovePage

Remove uma página da folha de propriedades e destrói a janela associada.

```cpp
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
Aponta para a página a ser removida da folha de propriedades. Não pode ser NULL.

*Npage*<br/>
Índice da página a ser removida. Deve ser entre 0 e um a menos do que o número de páginas na folha de propriedades, inclusive.

### <a name="remarks"></a>Comentários

O objeto [CPropertyPage](../../mfc/reference/cpropertypage-class.md) em si não `CPropertySheet` é destruído até que o proprietário da janela seja fechado.

## <a name="cpropertysheetsetactivepage"></a><a name="setactivepage"></a>CPropertySheet::SetActivePage

Altera a página ativa.

```
BOOL SetActivePage(int nPage);
BOOL SetActivePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*Npage*<br/>
Índice da página a definir. Deve ser entre 0 e um a menos do que o número de páginas na folha de propriedades, inclusive.

*pPage*<br/>
Aponta para a página a ser definida na folha de propriedades. Ele não pode ser NULL.

### <a name="return-value"></a>Valor retornado

Não zero se a folha de propriedade for ativada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por exemplo, `SetActivePage` use se a ação de um usuário em uma página fizer com que outra página se torne a página ativa.

### <a name="example"></a>Exemplo

Veja o exemplo de [CPropertySheet::GetActivePage](#getactivepage).

## <a name="cpropertysheetsetfinishtext"></a><a name="setfinishtext"></a>CPropertySheet::SetFinishText

Define o texto no botão de comando Concluir.

```cpp
void SetFinishText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para o texto a ser exibido no botão de comando Concluir.

### <a name="remarks"></a>Comentários

Ligue `SetFinishText` para exibir o texto no botão de comando Concluir e ocultar os botões Next e Back após o usuário concluir a ação na última página do assistente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#138](../../mfc/codesnippet/cpp/cpropertysheet-class_11.cpp)]

## <a name="cpropertysheetsettitle"></a><a name="settitle"></a>CPropertySheet::SetTitle

Especifica a legenda da folha de propriedades (o texto exibido na barra de título de uma janela de quadro).

```cpp
void SetTitle(
    LPCTSTR lpszText,
    UINT nStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
Especifica o estilo do título da folha de propriedades. O estilo deve ser especificado em 0 ou como PSH_PROPTITLE. Se o estilo for definido como PSH_PROPTITLE, a palavra "Propriedades" será exibida após o texto especificado como legenda. Por exemplo, `SetTitle`chamar ("Simples", PSH_PROPTITLE) resultará em uma legenda de folha de propriedade de "Propriedades Simples".

*lpszText*<br/>
Aponta para o texto a ser usado como legenda na barra de título da folha de propriedades.

### <a name="remarks"></a>Comentários

Por padrão, uma folha de propriedade usa o parâmetro de legenda no construtor de folha de propriedades.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#139](../../mfc/codesnippet/cpp/cpropertysheet-class_12.cpp)]

## <a name="cpropertysheetsetwizardbuttons"></a><a name="setwizardbuttons"></a>CPropertySheet::SetWizardButtons

Habilita ou desativa o botão Voltar, Seguir ou Concluir em uma folha de propriedade do assistente.

```cpp
void SetWizardButtons(DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um conjunto de sinalizadores que personalizam a função e a aparência dos botões do assistente. Este parâmetro pode ser uma combinação dos seguintes valores:

- botão PSWIZB_BACK Back

- PSWIZB_NEXT próximo botão

- botão PSWIZB_FINISH Finish

- PSWIZB_DISABLEDFINISH botão de acabamento desativado

### <a name="remarks"></a>Comentários

Chamada `SetWizardButtons` somente após a abertura da caixa de diálogo; você não pode `SetWizardButtons` ligar antes de chamar [doDoModal.](#domodal) Normalmente, você `SetWizardButtons` deve ligar para [CPropertyPage::OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).

Se você quiser alterar o texto no botão Concluir ou ocultar os botões Next e Back uma vez que o usuário tenha concluído o assistente, chame [SetFinishText](#setfinishtext). Observe que o mesmo botão é compartilhado para Finish e Next. Você pode exibir um acabamento ou um botão Next de uma só vez, mas não ambos.

### <a name="example"></a>Exemplo

A `CPropertySheet` tem três páginas `CStylePage` `CColorPage`de `CShapePage`propriedade de assistente: , e .  O fragmento de código abaixo mostra como ativar e desativar os botões **Voltar** e **Seguir** na página de propriedade do assistente.

[!code-cpp[NVC_MFCDocView#140](../../mfc/codesnippet/cpp/cpropertysheet-class_13.cpp)]

[!code-cpp[NVC_MFCDocView#141](../../mfc/codesnippet/cpp/cpropertysheet-class_14.cpp)]

[!code-cpp[NVC_MFCDocView#138](../../mfc/codesnippet/cpp/cpropertysheet-class_11.cpp)]

## <a name="cpropertysheetsetwizardmode"></a><a name="setwizardmode"></a>CPropertySheet::SetWizardMode

Estabelece uma página de propriedade como um assistente.

```cpp
void SetWizardMode();
```

### <a name="remarks"></a>Comentários

Uma característica chave de uma página de propriedade do assistente é que o usuário navega usando botões Next ou Finish, Back e Cancel em vez de guias.

Ligue `SetWizardMode` antes de ligar para [o DoModal](#domodal). Depois de `SetWizardMode` `DoModal` ligar, retornará ID_WIZFINISH (se o usuário fechar com o botão Concluir) ou IDCANCEL.

`SetWizardMode`define a bandeira PSH_WIZARD.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#142](../../mfc/codesnippet/cpp/cpropertysheet-class_15.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL1](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC CMNCTRL2](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC PROPDLG](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

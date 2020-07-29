---
title: Classe CPageSetupDialog
ms.date: 11/04/2016
f1_keywords:
- CPageSetupDialog
- AFXDLGS/CPageSetupDialog
- AFXDLGS/CPageSetupDialog::CPageSetupDialog
- AFXDLGS/CPageSetupDialog::CreatePrinterDC
- AFXDLGS/CPageSetupDialog::DoModal
- AFXDLGS/CPageSetupDialog::GetDeviceName
- AFXDLGS/CPageSetupDialog::GetDevMode
- AFXDLGS/CPageSetupDialog::GetDriverName
- AFXDLGS/CPageSetupDialog::GetMargins
- AFXDLGS/CPageSetupDialog::GetPaperSize
- AFXDLGS/CPageSetupDialog::GetPortName
- AFXDLGS/CPageSetupDialog::OnDrawPage
- AFXDLGS/CPageSetupDialog::PreDrawPage
- AFXDLGS/CPageSetupDialog::m_psd
helpviewer_keywords:
- CPageSetupDialog [MFC], CPageSetupDialog
- CPageSetupDialog [MFC], CreatePrinterDC
- CPageSetupDialog [MFC], DoModal
- CPageSetupDialog [MFC], GetDeviceName
- CPageSetupDialog [MFC], GetDevMode
- CPageSetupDialog [MFC], GetDriverName
- CPageSetupDialog [MFC], GetMargins
- CPageSetupDialog [MFC], GetPaperSize
- CPageSetupDialog [MFC], GetPortName
- CPageSetupDialog [MFC], OnDrawPage
- CPageSetupDialog [MFC], PreDrawPage
- CPageSetupDialog [MFC], m_psd
ms.assetid: 049c0ac8-f254-4854-9414-7a8271d1447a
ms.openlocfilehash: 280d75c3bcacd673107fd32ecaa39953b06a77c8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214068"
---
# <a name="cpagesetupdialog-class"></a>Classe CPageSetupDialog

Encapsula os serviços fornecidos pela caixa de diálogo configuração de página OLE comum do Windows com suporte adicional para definir e modificar as margens de impressão.

## <a name="syntax"></a>Sintaxe

```
class CPageSetupDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog)|Constrói um objeto `CPageSetupDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageSetupDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo para impressão.|
|[CPageSetupDialog::D oModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[CPageSetupDialog:: DeviceName](#getdevicename)|Retorna o nome do dispositivo da impressora.|
|[CPageSetupDialog:: getdevmode](#getdevmode)|Retorna o DEVMODE atual da impressora.|
|[CPageSetupDialog:: GetDriverName](#getdrivername)|Retorna o driver usado pela impressora.|
|[CPageSetupDialog:: GetMargins](#getmargins)|Retorna as configurações de margem atual da impressora.|
|[CPageSetupDialog:: getwhiteize](#getpapersize)|Retorna o tamanho do papel da impressora.|
|[CPageSetupDialog:: getportname](#getportname)|Retorna o nome da porta de saída.|
|[CPageSetupDialog::OnDrawPage](#ondrawpage)|Chamado pelo Framework para renderizar uma imagem de tela de uma página impressa.|
|[CPageSetupDialog::P reDrawPage](#predrawpage)|Chamado pelo Framework antes de renderizar uma imagem de tela de uma página impressa.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageSetupDialog:: m_psd](#m_psd)|Uma estrutura usada para personalizar um `CPageSetupDialog` objeto.|

## <a name="remarks"></a>Comentários

Essa classe foi projetada para assumir o lugar da caixa de diálogo Configurar impressão.

Para usar um `CPageSetupDialog` objeto, primeiro crie o objeto usando o `CPageSetupDialog` Construtor. Depois que a caixa de diálogo tiver sido construída, você poderá definir ou modificar quaisquer valores no `m_psd` membro de dados para inicializar os valores dos controles da caixa de diálogo. A estrutura de [m_psd](#m_psd) é do tipo PAGESETUPDLG.

Depois de inicializar os controles da caixa de diálogo, chame a `DoModal` função membro para exibir a caixa de diálogo e permitir que o usuário selecione opções de impressão. `DoModal`Retorna se o usuário selecionou o botão OK (IDOK) ou Cancel (IDCANCEL).

Se `DoModal` retornar IDOK, você poderá usar várias das `CPageSetupDialog` funções de membro de, ou acessar o `m_psd` membro de dados, para recuperar informações de entrada pelo usuário.

> [!NOTE]
> Depois que a caixa de diálogo configuração de página OLE comum for ignorada, as alterações feitas pelo usuário não serão salvas pela estrutura. Cabe ao próprio aplicativo salvar qualquer valor dessa caixa de diálogo em um local permanente, como membro do documento ou da classe de aplicativo do aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CPageSetupDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

## <a name="cpagesetupdialogcpagesetupdialog"></a><a name="cpagesetupdialog"></a>CPageSetupDialog::CPageSetupDialog

Chame essa função para construir um `CPageSetupDialog` objeto.

```
CPageSetupDialog(
    DWORD dwFlags = PSD_MARGINS | PSD_INWININIINTLMEASURE,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>parâmetros

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo. Os valores podem ser combinados usando o operador bit-a-OR. Esses valores têm estes significados:

- PSD_DEFAULTMINMARGINS define as larguras mínimas permitidas para que as margens da página sejam iguais aos mínimos da impressora. Esse sinalizador será ignorado se os sinalizadores de PSD_MARGINS e PSD_MINMARGINS também forem especificados.

- PSD_INWININIINTLMEASURE não implementado.

- PSD_MINMARGINS faz com que o sistema use os valores especificados no `rtMinMargin` membro como as larguras mínimas permitidas para as margens esquerda, superior, direita e inferior. O sistema impede que o usuário insira uma largura menor que o mínimo especificado. Se PSD_MINMARGINS não for especificado, o sistema definirá o mínimo de larguras permitidas para os permitidos pela impressora.

- PSD_MARGINS Ativa a área de controle de margem.

- PSD_INTHOUSANDTHSOFINCHES faz com que as unidades da caixa de diálogo sejam medidas em 1/1000 de uma polegada.

- PSD_INHUNDREDTHSOFMILLIMETERS faz com que as unidades da caixa de diálogo sejam medidas em 1/100 de milímetros.

- PSD_DISABLEMARGINS desabilita os controles da caixa de diálogo margem.

- PSD_DISABLEPRINTER desabilita o botão da impressora.

- PSD_NOWARNING Impede que a mensagem de aviso seja exibida quando não há uma impressora padrão.

- PSD_DISABLEORIENTATION desabilita o controle de caixa de diálogo orientação da página.

- PSD_RETURNDEFAULT faz com que `CPageSetupDialog` o retorne as estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) que são inicializadas para a impressora padrão do sistema sem exibir uma caixa de diálogo. Supõe-se que `hDevNames` e `hDevMode` sejam nulos; caso contrário, a função retornará um erro. Se a impressora padrão do sistema tiver suporte de um driver de impressora antigo (anterior à versão 3,0 do Windows), somente `hDevNames` será retornado; `hDevMode` será nulo.

- PSD_DISABLEPAPER desabilita o controle de seleção de papel.

- PSD_SHOWHELP faz com que a caixa de diálogo mostre o botão ajuda. O `hwndOwner` membro não deverá ser nulo se esse sinalizador for especificado.

- PSD_ENABLEPAGESETUPHOOK habilita a função de gancho especificada em `lpfnSetupHook` .

- PSD_ENABLEPAGESETUPTEMPLATE Faz com que o sistema operacional crie a caixa de diálogo usando a caixa de modelo de diálogo identificada por `hInstance` e `lpSetupTemplateName` .

- PSD_ENABLEPAGESETUPTEMPLATEHANDLE indica que `hInstance` identifica um bloco de dados que contém um modelo de caixa de diálogo pré-carregado. O sistema ignorará `lpSetupTemplateName` se esse sinalizador for especificado.

- PSD_ENABLEPAGEPAINTHOOK habilita a função de gancho especificada em `lpfnPagePaintHook` .

- PSD_DISABLEPAGEPAINTING desabilita a área de desenho da caixa de diálogo.

*pParentWnd*<br/>
Ponteiro para o pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Use a função [DoModal](../../mfc/reference/cdialog-class.md#domodal) para exibir a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#94](../../mfc/codesnippet/cpp/cpagesetupdialog-class_1.cpp)]

## <a name="cpagesetupdialogcreateprinterdc"></a><a name="createprinterdc"></a>CPageSetupDialog::CreatePrinterDC

Cria um contexto de dispositivo de impressora nas estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) .

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor retornado

Identificador para o DC (contexto de dispositivo de impressora) recém-criado.

## <a name="cpagesetupdialogdomodal"></a><a name="domodal"></a>CPageSetupDialog::D oModal

Chame essa função para exibir a caixa de diálogo configuração de página OLE comum do Windows e permitir que o usuário selecione várias opções de configuração de impressão, como as margens de impressão, o tamanho e a orientação do papel e a impressora de destino.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL. Se IDCANCEL for retornado, chame a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou cancelar.

### <a name="remarks"></a>Comentários

Além disso, o usuário pode acessar as opções de configuração da impressora, como local de rede e propriedades específicas da impressora selecionada.

Se você quiser inicializar as opções de caixa de diálogo de configuração de várias páginas definindo os membros da `m_psd` estrutura, deverá fazê-lo antes `DoModal` de chamar e, depois que o objeto da caixa de diálogo for construído. Depois de chamar `DoModal` , chame outras funções de membro para recuperar as configurações ou as informações inseridas pelo usuário na caixa de diálogo.

Se você quiser propagar as configurações atuais inseridas pelo usuário, faça uma chamada para [CWinApp:: SelectPrinter](../../mfc/reference/cwinapp-class.md#selectprinter). Essa função usa as informações do `CPageSetupDialog` objeto e inicializa e seleciona um novo DC de impressora com os atributos adequados.

[!code-cpp[NVC_MFCDocView#95](../../mfc/codesnippet/cpp/cpagesetupdialog-class_2.cpp)]

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CPageSetupDialog:: CPageSetupDialog](#cpagesetupdialog).

## <a name="cpagesetupdialoggetdevicename"></a><a name="getdevicename"></a>CPageSetupDialog:: DeviceName

Chame essa função depois `DoModal` de recuperar o nome da impressora selecionada no momento.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do dispositivo usado pelo `CPageSetupDialog` objeto.

## <a name="cpagesetupdialoggetdevmode"></a><a name="getdevmode"></a>CPageSetupDialog:: getdevmode

Chame essa função depois de chamar `DoModal` para recuperar informações sobre o contexto do dispositivo de impressora do `CPageSetupDialog` objeto.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor retornado

A estrutura de dados [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) , que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória usada por essa estrutura com a função [GlobalUnlock](/windows/win32/api/winbase/nf-winbase-globalunlock) do Windows, que é descrita no SDK do Windows.

## <a name="cpagesetupdialoggetdrivername"></a><a name="getdrivername"></a>CPageSetupDialog:: GetDriverName

Chame essa função depois de chamar [DoModal](../../mfc/reference/cprintdialog-class.md#domodal) para recuperar o nome do driver de dispositivo de impressora definido pelo sistema.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor retornado

Um `CString` especificando o nome do driver definido pelo sistema.

### <a name="remarks"></a>Comentários

Use um ponteiro para o `CString` objeto retornado pelo `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC:: CreateDC](../../mfc/reference/cdc-class.md#createdc).

## <a name="cpagesetupdialoggetmargins"></a><a name="getmargins"></a>CPageSetupDialog:: GetMargins

Chame essa função após uma chamada para `DoModal` para recuperar as margens do driver de dispositivo de impressora.

```cpp
void GetMargins(
    LPRECT lpRectMargins,
    LPRECT lpRectMinMargins) const;
```

### <a name="parameters"></a>parâmetros

*lpRectMargins*<br/>
Ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que descreve (em 1/1000 polegadas ou 1/100 mm) as margens de impressão para a impressora selecionada no momento. Passe NULL para este parâmetro, se você não estiver interessado neste retângulo.

*lpRectMinMargins*<br/>
Ponteiro para uma `RECT` estrutura ou `CRect` objeto que descreve (em 1/1000 polegadas ou 1/100 mm) as margens de impressão mínimas para a impressora selecionada no momento. Passe NULL para este parâmetro, se você não estiver interessado neste retângulo.

## <a name="cpagesetupdialoggetpapersize"></a><a name="getpapersize"></a>CPageSetupDialog:: getwhiteize

Chame essa função para recuperar o tamanho do papel selecionado para impressão.

```
CSize GetPaperSize() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que contém o tamanho do papel (em 1/1000 polegadas ou 1/100 mm) selecionado para impressão.

## <a name="cpagesetupdialoggetportname"></a><a name="getportname"></a>CPageSetupDialog:: getportname

Chame essa função depois `DoModal` de chamar para recuperar o nome da porta de impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da porta de impressora selecionada no momento.

## <a name="cpagesetupdialogm_psd"></a><a name="m_psd"></a>CPageSetupDialog:: m_psd

Uma estrutura do tipo PAGESETUPDLG, cujos membros armazenam as características do objeto da caixa de diálogo.

```
PAGESETUPDLG m_psd;
```

### <a name="remarks"></a>Comentários

Depois de construir um `CPageSetupDialog` objeto, você pode usar `m_psd` para definir vários aspectos da caixa de diálogo antes de chamar a `DoModal` função de membro.

Se você modificar o `m_psd` membro de dados diretamente, substituirá qualquer comportamento padrão.

Para obter mais informações sobre a estrutura [PAGESETUPDLG](/windows/win32/api/commdlg/ns-commdlg-pagesetupdlgw) , consulte a SDK do Windows.

Consulte o exemplo de [CPageSetupDialog:: CPageSetupDialog](#cpagesetupdialog).

## <a name="cpagesetupdialogondrawpage"></a><a name="ondrawpage"></a>CPageSetupDialog::OnDrawPage

Chamado pelo Framework para desenhar uma imagem de tela de uma página impressa.

```
virtual UINT OnDrawPage(
    CDC* pDC,
    UINT nMessage,
    LPRECT lpRect);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
Ponteiro para o contexto do dispositivo de impressora.

*nmensagem*<br/>
Especifica uma mensagem, indicando a área da página que está sendo desenhada no momento. Um dos seguintes pode ser feito:

- WM_PSD_FULLPAGERECT toda a área da página.

- WM_PSD_MINMARGINRECT margens mínimas atuais.

- WM_PSD_MARGINRECT margens atuais.

- WM_PSD_GREEKTEXTRECT conteúdo da página.

- Área de WM_PSD_ENVSTAMPRECT reservada para uma representação de carimbo de postagem.

- Área de WM_PSD_YAFULLPAGERECT para uma representação de endereço de retorno. Essa área se estende às bordas da área da página de exemplo.

*lpRect*<br/>
Ponteiro para um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [Rect](/windows/win32/api/windef/ns-windef-rect) que contém as coordenadas da área de desenho.

### <a name="return-value"></a>Valor retornado

Valor diferente de zero se for manipulado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa imagem é exibida como parte da caixa de diálogo de configuração de página OLE comum. A implementação padrão desenha uma imagem de uma página de texto.

Substitua essa função para personalizar o desenho de uma área específica da imagem ou a imagem inteira. Você pode fazer isso usando uma **`switch`** instrução com **`case`** instruções para verificar o valor de *nmensagem*. Por exemplo, para personalizar a renderização do conteúdo da imagem da página, você pode usar o seguinte código de exemplo:

[!code-cpp[NVC_MFCDocView#96](../../mfc/codesnippet/cpp/cpagesetupdialog-class_3.cpp)]

Observe que você não precisa lidar com todos os casos de *nmensagem*. Você pode optar por lidar com um componente da imagem, vários componentes da imagem ou toda a área.

## <a name="cpagesetupdialogpredrawpage"></a><a name="predrawpage"></a>CPageSetupDialog::P reDrawPage

Chamado pelo Framework antes de desenhar a imagem de tela de uma página impressa.

```
virtual UINT PreDrawPage(
    WORD wPaper,
    WORD wFlags,
    LPPAGESETUPDLG pPSD);
```

### <a name="parameters"></a>parâmetros

*wPaper*<br/>
Especifica um valor que indica o tamanho do papel. Esse valor pode ser um dos **DMPAPER_** valores listados na descrição da estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) .

*wFlags*<br/>
Indica a orientação do papel ou envelope e se a impressora é um dispositivo de matriz de pontos ou HPPCL (linguagem de controle de impressora da Hewlett Packard). Esse parâmetro pode ter um dos seguintes valores:

- Papel de 0x001 no modo paisagem (matriz de pontos)

- Papel de 0x003 no modo paisagem (HPPCL)

- Papel 0x005 no modo retrato (matriz de pontos)

- Papel 0x007 no modo retrato (HPPCL)

- Envelope 0x00b no modo paisagem (HPPCL)

- Envelope 0x00d no modo retrato (matriz de pontos)

- Envelope 0x019 no modo paisagem (matriz de pontos)

- Envelope 0x01f no modo retrato (matriz de pontos)

*pPSD*<br/>
Ponteiro para uma estrutura `PAGESETUPDLG`. Para obter mais informações sobre o [PAGESETUPDLG](/windows/win32/api/commdlg/ns-commdlg-pagesetupdlgw), consulte a SDK do Windows.

### <a name="return-value"></a>Valor retornado

Valor diferente de zero se for manipulado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar o desenho da imagem. Se você substituir essa função e retornar TRUE, você deverá desenhar a imagem inteira. Se você substituir essa função e retornar FALSE, toda a imagem padrão será desenhada pela estrutura.

## <a name="see-also"></a>Confira também

[Exemplo de WORDPAD do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)

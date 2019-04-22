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
ms.openlocfilehash: 01a320fbcd9760bab484f3c75553613852ca9aed
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58778085"
---
# <a name="cpagesetupdialog-class"></a>Classe CPageSetupDialog

Encapsula os serviços fornecidos pela caixa de diálogo de configuração de página OLE comum do Windows com suporte adicional para definir e modificar as margens de impressão.

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
|[CPageSetupDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressão.|
|[CPageSetupDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[CPageSetupDialog::GetDeviceName](#getdevicename)|Retorna o nome do dispositivo da impressora.|
|[CPageSetupDialog::GetDevMode](#getdevmode)|Retorna o DEVMODE atual da impressora.|
|[CPageSetupDialog::GetDriverName](#getdrivername)|Retorna o driver de impressora.|
|[CPageSetupDialog::GetMargins](#getmargins)|Retorna as atuais configurações de margem da impressora.|
|[CPageSetupDialog::GetPaperSize](#getpapersize)|Retorna o tamanho do papel da impressora.|
|[CPageSetupDialog::GetPortName](#getportname)|Retorna o nome da porta de saída.|
|[CPageSetupDialog::OnDrawPage](#ondrawpage)|Chamado pelo framework para renderizar uma imagem de tela de uma página impressa.|
|[CPageSetupDialog::PreDrawPage](#predrawpage)|Chamado pelo framework antes de renderizar uma imagem de tela de uma página impressa.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageSetupDialog::m_psd](#m_psd)|Uma estrutura usada para personalizar um `CPageSetupDialog` objeto.|

## <a name="remarks"></a>Comentários

Essa classe é projetada para tomar o lugar da caixa de diálogo Configurar impressão.

Para usar um `CPageSetupDialog` do objeto, primeiro crie o objeto usando o `CPageSetupDialog` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar quaisquer valores no `m_psd` membro de dados para inicializar os valores dos controles da caixa de diálogo. O [m_psd](#m_psd) estrutura é do tipo PAGESETUPDLG.

Depois de inicializar os controles de caixa de diálogo, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecionar as opções de impressão. `DoModal` Retorna se o usuário selecionou o botão Okey (IDOK) ou Cancelar (IDCANCEL).

Se `DoModal` retorna IDOK, você pode usar vários `CPageSetupDialog`do acesso, ou funções de membro, o `m_psd` membro de dados, para recuperar a entrada de informações pelo usuário.

> [!NOTE]
>  Depois que a caixa de diálogo de configuração de página OLE comum é descartada, todas as alterações feitas pelo usuário não serão salvo pela estrutura. É até o aplicativo para salvar quaisquer valores nessa caixa de diálogo para um local permanente, como membro da classe de aplicativo ou documento do aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CPageSetupDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="cpagesetupdialog"></a>  CPageSetupDialog::CPageSetupDialog

Chame essa função para construir um `CPageSetupDialog` objeto.

```
CPageSetupDialog(
    DWORD dwFlags = PSD_MARGINS | PSD_INWININIINTLMEASURE,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo. Os valores podem ser combinados usando o operador OR bit a bit. Esses valores têm os seguintes significados:

- PSD_DEFAULTMINMARGINS define larguras mínimas permitidas para as margens de página ser o mesmo que o mínimo da impressora. Esse sinalizador será ignorado se os sinalizadores PSD_MARGINS e PSD_MINMARGINS também são especificados.

- PSD_INWININIINTLMEASURE não implementado.

- PSD_MINMARGINS faz com que o sistema a usar os valores especificados no `rtMinMargin` membro como larguras mínimas permitidas para a esquerda, superior, direita e margens inferior. O sistema impede que o usuário inserir uma largura menor que o mínimo especificado. Se PSD_MINMARGINS não for especificado, o sistema define larguras mínimas permitidas para aqueles permitidos pela impressora.

- PSD_MARGINS ativa área de margem de controle.

- PSD_INTHOUSANDTHSOFINCHES faz com que as unidades de caixa de diálogo a ser medido em 1/1000 de polegada.

- PSD_INHUNDREDTHSOFMILLIMETERS faz com que as unidades de caixa de diálogo a ser medido em 1/100 de milímetro.

- PSD_DISABLEMARGINS desabilita os controles de caixa de diálogo de margem.

- PSD_DISABLEPRINTER desabilita o botão de impressora.

- PSD_NOWARNING impede que a mensagem de aviso seja exibido quando não há nenhuma impressora padrão.

- PSD_DISABLEORIENTATION desabilita o controle de caixa de diálogo de orientação de página.

- Faz com que o PSD_RETURNDEFAULT `CPageSetupDialog` para retornar [DEVMODE](/windows/desktop/api/wingdi/ns-wingdi-_devicemodea) e [DEVNAMES](/windows/desktop/api/commdlg/ns-commdlg-tagdevnames) estruturas que são inicializadas para a impressora padrão de sistema sem exibir uma caixa de diálogo. Supõe-se que as duas `hDevNames` e `hDevMode` são NULL; caso contrário, a função retornará um erro. Se a impressora padrão do sistema é compatível com um driver de impressora antigo (anterior ao Windows versão 3.0), apenas `hDevNames` será retornado; `hDevMode` é NULL.

- PSD_DISABLEPAPER desabilita o controle de seleção de papel.

- PSD_SHOWHELP faz com que a caixa de diálogo Mostrar o botão Ajuda. O `hwndOwner` membro não deve ser NULL se esse sinalizador for especificado.

- PSD_ENABLEPAGESETUPHOOK permite que a função de gancho especificada no `lpfnSetupHook`.

- PSD_ENABLEPAGESETUPTEMPLATE faz com que o sistema operacional criar a caixa de diálogo usando a caixa de diálogo modelo identificada por `hInstance` e `lpSetupTemplateName`.

- PSD_ENABLEPAGESETUPTEMPLATEHANDLE indica que `hInstance` identifica um bloco de dados que contém um modelo de caixa de diálogo pré-carregados. O sistema ignora `lpSetupTemplateName` se este sinalizador for especificado.

- PSD_ENABLEPAGEPAINTHOOK permite que a função de gancho especificada no `lpfnPagePaintHook`.

- PSD_DISABLEPAGEPAINTING desabilita a área de desenho da caixa de diálogo.

*pParentWnd*<br/>
Ponteiro para a caixa de diálogo pai ou proprietária.

### <a name="remarks"></a>Comentários

Use o [DoModal](../../mfc/reference/cdialog-class.md#domodal) função para exibir a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#94](../../mfc/codesnippet/cpp/cpagesetupdialog-class_1.cpp)]

##  <a name="createprinterdc"></a>  CPageSetupDialog::CreatePrinterDC

Cria um contexto de dispositivo de impressora a [DEVMODE](/windows/desktop/api/wingdi/ns-wingdi-_devicemodea) e [DEVNAMES](/windows/desktop/api/commdlg/ns-commdlg-tagdevnames) estruturas.

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor de retorno

Identificador para o contexto de dispositivo de impressora recém-criado (DC).

##  <a name="domodal"></a>  CPageSetupDialog::DoModal

Chame essa função para exibir a caixa de diálogo de configuração de página OLE comum do Windows e permitir que o usuário selecionar várias opções de configuração de impressão, como as margens de impressão, o tamanho e a orientação do papel e impressora de destino.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

IDOK ou IDCANCEL. Se IDCANCEL for retornado, chame o Windows [CommDlgExtendedError](/windows/desktop/api/commdlg/nf-commdlg-commdlgextendederror) função para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.

### <a name="remarks"></a>Comentários

Além disso, o usuário pode acessar as opções de instalação de impressora, como o local de rede e propriedades específicas para a impressora selecionada.

Se você quiser inicializar as várias opções de caixa de diálogo Configurar página definindo membros do `m_psd` estrutura, você deve fazer isso antes de chamar `DoModal`, e depois que o objeto de caixa de diálogo é construído. Depois de chamar `DoModal`, chamar funções para recuperar as configurações ou a entrada de informações do usuário na caixa de diálogo de outro membro.

Se você deseja propagar as configurações atuais inseridas pelo usuário, fazer uma chamada para [CWinApp::SelectPrinter](../../mfc/reference/cwinapp-class.md#selectprinter). Essa função usa as informações a partir de `CPageSetupDialog` do objeto e inicializa e seleciona uma nova impressora de controlador de domínio com os atributos apropriados.

[!code-cpp[NVC_MFCDocView#95](../../mfc/codesnippet/cpp/cpagesetupdialog-class_2.cpp)]

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog).

##  <a name="getdevicename"></a>  CPageSetupDialog::GetDeviceName

Chame essa função após `DoModal` para recuperar o nome da impressora selecionada no momento.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome do dispositivo usado pelo `CPageSetupDialog` objeto.

##  <a name="getdevmode"></a>  CPageSetupDialog::GetDevMode

Chame essa função após chamar `DoModal` para recuperar informações sobre o contexto de dispositivo de impressora a `CPageSetupDialog` objeto.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor de retorno

O [DEVMODE](/windows/desktop/api/wingdi/ns-wingdi-_devicemodea) estrutura de dados, que contém informações sobre o ambiente de um driver de impressão e a inicialização do dispositivo. Você deve desbloquear a memória usada por essa estrutura com o Windows [GlobalUnlock](/windows/desktop/api/winbase/nf-winbase-globalunlock) função, que é descrita no SDK do Windows.

##  <a name="getdrivername"></a>  CPageSetupDialog::GetDriverName

Chame essa função após chamar [DoModal](../../mfc/reference/cprintdialog-class.md#domodal) para recuperar o nome do driver de dispositivo da impressora definida pelo sistema.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor de retorno

Um `CString` especificando o nome do driver definida pelo sistema.

### <a name="remarks"></a>Comentários

Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).

##  <a name="getmargins"></a>  CPageSetupDialog::GetMargins

Chame essa função após uma chamada para `DoModal` para recuperar as margens do driver de dispositivo da impressora.

```
void GetMargins(
    LPRECT lpRectMargins,
    LPRECT lpRectMinMargins) const;
```

### <a name="parameters"></a>Parâmetros

*lpRectMargins*<br/>
Ponteiro para um [RECT](/windows/desktop/api/windef/ns-windef-tagrect) estrutura ou [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que descreve (em polegadas de 1/1000 ou 1/100 mm) as margens de impressão para a impressora atualmente selecionada. Passe NULL para esse parâmetro, se você não estiver interessado nesse retângulo.

*lpRectMinMargins*<br/>
Ponteiro para um `RECT` estrutura ou `CRect` objeto que descreve (em polegadas de 1/1000 ou 1/100 mm) as margens de impressão mínimo para a impressora atualmente selecionada. Passe NULL para esse parâmetro, se você não estiver interessado nesse retângulo.

##  <a name="getpapersize"></a>  CPageSetupDialog::GetPaperSize

Chame essa função para recuperar o tamanho de papel selecionado para impressão.

```
CSize GetPaperSize() const;
```

### <a name="return-value"></a>Valor de retorno

Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém o tamanho do papel (em polegadas de 1/1000 ou 1/100 mm) selecionado para impressão.

##  <a name="getportname"></a>  CPageSetupDialog::GetPortName

Chame essa função após a chamada `DoModal` para recuperar o nome da porta da impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome da porta da impressora selecionada no momento.

##  <a name="m_psd"></a>  CPageSetupDialog::m_psd

Uma estrutura do tipo PAGESETUPDLG, cujos membros armazenam as características do objeto de caixa de diálogo.

```
PAGESETUPDLG m_psd;
```

### <a name="remarks"></a>Comentários

Depois de criar uma `CPageSetupDialog` objeto, você pode usar `m_psd` para definir vários aspectos da caixa de diálogo antes de chamar o `DoModal` função de membro.

Se você modificar o `m_psd` membro de dados diretamente, você substituirá qualquer comportamento padrão.

Para obter mais informações sobre o [PAGESETUPDLG](/windows/desktop/api/commdlg/ns-commdlg-tagpsda) estrutura, consulte o SDK do Windows.

Veja o exemplo de [CPageSetupDialog::CPageSetupDialog](#cpagesetupdialog).

##  <a name="ondrawpage"></a>  CPageSetupDialog::OnDrawPage

Chamado pelo framework para desenhar uma imagem de tela de uma página impressa.

```
virtual UINT OnDrawPage(
    CDC* pDC,
    UINT nMessage,
    LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto de dispositivo de impressora.

*nMessage*<br/>
Especifica uma mensagem que indica a área da página no momento que está sendo desenhada. Pode ser uma das seguintes opções:

- WM_PSD_FULLPAGERECT área da página inteira.

- Margens mínimas WM_PSD_MINMARGINRECT atual.

- Margens WM_PSD_MARGINRECT atual.

- WM_PSD_GREEKTEXTRECT o conteúdo da página.

- Área de WM_PSD_ENVSTAMPRECT reservado para uma representação de carimbo de postagem.

- Área de WM_PSD_YAFULLPAGERECT para uma representação de endereço de retorno. Esta área se estende às bordas da área da página de exemplo.

*lpRect*<br/>
Ponteiro para um [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [RECT](/windows/desktop/api/windef/ns-windef-tagrect) objeto que contém as coordenadas da área de desenho.

### <a name="return-value"></a>Valor de retorno

Valor diferente de zero se manipulado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa imagem é exibida como parte da caixa de diálogo de configuração de página OLE comum. A implementação padrão desenha uma imagem de uma página de texto.

Substitua essa função para personalizar o desenho de uma área específica da imagem ou a imagem inteira. Você pode fazer isso usando um **alternar** instrução com **caso** instruções verificando o valor da *nMensagem*. Por exemplo, para personalizar a renderização do conteúdo da imagem da página, você pode usar o código de exemplo a seguir:

[!code-cpp[NVC_MFCDocView#96](../../mfc/codesnippet/cpp/cpagesetupdialog-class_3.cpp)]

Observe que você não precisa lidar com todos os casos de *nMensagem*. Você pode optar por lidar com um componente da imagem, vários componentes de imagem ou toda a área.

##  <a name="predrawpage"></a>  CPageSetupDialog::PreDrawPage

Chamado pelo framework antes de desenhar a imagem da tela de uma página impressa.

```
virtual UINT PreDrawPage(
    WORD wPaper,
    WORD wFlags,
    LPPAGESETUPDLG pPSD);
```

### <a name="parameters"></a>Parâmetros

*wPaper*<br/>
Especifica um valor que indica o tamanho do papel. Esse valor pode ser um dos **DMPAPER_** valores listados na descrição do [DEVMODE](/windows/desktop/api/wingdi/ns-wingdi-_devicemodea) estrutura.

*wFlags*<br/>
Indica a orientação do papel ou do envelope, e se a impressora é uma matriz de ponto ou dispositivo HPPCL (linguagem de controle de impressora do Hewlett Packard). Esse parâmetro pode ter um dos seguintes valores:

- 0x001 do papel em modo paisagem (matriz de ponto)

- 0x003 do papel em modo paisagem (HPPCL)

- 0x005 do papel em modo retrato (matriz de ponto)

- 0x007 do papel em modo retrato (HPPCL)

- 0x00b envelope em modo paisagem (HPPCL)

- 0x00d envelope em modo retrato (matriz de ponto)

- 0x019 envelope em modo paisagem (matriz de ponto)

- 0x01f envelope em modo retrato (matriz de ponto)

*pPSD*<br/>
Ponteiro para uma estrutura `PAGESETUPDLG`. Para obter mais informações sobre [PAGESETUPDLG](/windows/desktop/api/commdlg/ns-commdlg-tagpsda), consulte o SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Valor diferente de zero se manipulado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar o desenho da imagem. Se você substituir essa função e retorna TRUE, você deve desenhar a imagem inteira. Se você substituir essa função e retorna FALSE, a imagem padrão inteira é desenhada pela estrutura.

## <a name="see-also"></a>Consulte também

[Exemplo MFC WORDPAD](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

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
ms.openlocfilehash: 3664149ef0d7476b460ef06cddaf2b8145ade701
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753695"
---
# <a name="cpagesetupdialog-class"></a>Classe CPageSetupDialog

Encapsula os serviços fornecidos pela caixa de diálogo De configuração de página OLE comum do Windows com suporte adicional para definir e modificar margens de impressão.

## <a name="syntax"></a>Sintaxe

```
class CPageSetupDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageSetupDiálogo::CPageSetupDiálogo](#cpagesetupdialog)|Constrói um objeto `CPageSetupDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageConfiguração configuraçãoDiálogo::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo para impressão.|
|[CPageSetupDiálogo::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[CPageConfiguração configuraçãoDiálogo::Obternome do dispositivo](#getdevicename)|Retorna o nome do dispositivo da impressora.|
|[CPageConfiguraçãode configuraçãoDiálogo::GetDevMode](#getdevmode)|Retorna o DEVMODE atual da impressora.|
|[CPageConfiguraçãoconfiguraçãoDiálogo::GetDriverName](#getdrivername)|Devolve o driver usado pela impressora.|
|[CPageConfiguraçãoconfiguraçãoDiálogo::GetMargins](#getmargins)|Retorna as configurações atuais de margem da impressora.|
|[CPageConfiguração configuraçãoDiálogo::GetPaperSize](#getpapersize)|Retorna o tamanho do papel da impressora.|
|[CPageConfiguração configuraçãoDiálogo::GetPortName](#getportname)|Retorna o nome da porta de saída.|
|[CPageSetupDiálogo::OnDrawPage](#ondrawpage)|Chamado pela estrutura para renderizar uma imagem de tela de uma página impressa.|
|[CPageConfiguraçãode configuraçãoDiálogo::PreDrawPage](#predrawpage)|Chamado pelo framework antes de renderizar uma imagem de tela de uma página impressa.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPageConfiguraçãoconfiguraçãoDiálogo::m_psd](#m_psd)|Uma estrutura usada `CPageSetupDialog` para personalizar um objeto.|

## <a name="remarks"></a>Comentários

Esta classe foi projetada para tomar o lugar da caixa de diálogo Configuração de impressão.

Para usar `CPageSetupDialog` um objeto, primeiro `CPageSetupDialog` crie o objeto usando o construtor. Uma vez que a caixa de diálogo tenha sido `m_psd` construída, você pode definir ou modificar quaisquer valores no membro de dados para inicializar os valores dos controles da caixa de diálogo. A estrutura [m_psd](#m_psd) é do tipo PAGESETUPDLG.

Depois de inicializar os controles `DoModal` da caixa de diálogo, ligue para a função membro para exibir a caixa de diálogo e permita que o usuário selecione as opções de impressão. `DoModal`retorna se o usuário selecionou o botão OK (IDOK) ou Cancelar (IDCANCEL).

Se `DoModal` retornar o IDOK, `CPageSetupDialog`você pode usar várias `m_psd` das funções de membro ou acessar o membro de dados para recuperar informações inseridas pelo usuário.

> [!NOTE]
> Depois que a caixa de diálogo de configuração de página oLE comum for descartada, quaisquer alterações feitas pelo usuário não serão salvas pelo framework. Cabe ao próprio aplicativo salvar quaisquer valores desta caixa de diálogo para um local permanente, como membro do documento do aplicativo ou classe de aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`CPageSetupDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cpagesetupdialogcpagesetupdialog"></a><a name="cpagesetupdialog"></a>CPageSetupDiálogo::CPageSetupDiálogo

Chame esta função `CPageSetupDialog` para construir um objeto.

```
CPageSetupDialog(
    DWORD dwFlags = PSD_MARGINS | PSD_INWININIINTLMEASURE,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo. Os valores podem ser combinados usando o operador bitwise-OR. Esses valores têm estes significados:

- PSD_DEFAULTMINMARGINS Define as larguras mínimas permitidas para que as margens de página sejam as mesmas dos mínimos da impressora. Esta bandeira é ignorada se as bandeiras PSD_MARGINS e PSD_MINMARGINS também forem especificadas.

- PSD_INWININIINTLMEASURE não implementado.

- PSD_MINMARGINS faz com que o sistema `rtMinMargin` use os valores especificados no membro como as larguras mínimas permitidas para as margens esquerda, superior, direita e inferior. O sistema impede que o usuário inseri-lo em uma largura menor que o mínimo especificado. Se PSD_MINMARGINS não for especificado, o sistema definirá as larguras mínimas permitidas às permitidas pela impressora.

- PSD_MARGINS Ativa a área de controle de margem.

- PSD_INTHOUSANDTHSOFINCHES faz com que as unidades da caixa de diálogo sejam medidas em 1/1000 de polegada.

- PSD_INHUNDREDTHSOFMILLIMETERS faz com que as unidades da caixa de diálogo sejam medidas em 1/100 de um milímetro.

- PSD_DISABLEMARGINS Desativa os controles da caixa de diálogo de margem.

- PSD_DISABLEPRINTER desabilita o botão impressora.

- PSD_NOWARNING Impede que a mensagem de aviso seja exibida quando não há uma impressora padrão.

- PSD_DISABLEORIENTATION Desativa o controle da caixa de diálogo de orientação da página.

- PSD_RETURNDEFAULT `CPageSetupDialog` Causas para retornar estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) que são inicializadas para a impressora padrão do sistema sem exibir uma caixa de diálogo. Presume-se que `hDevNames` `hDevMode` ambos e são NULAS; caso contrário, a função retorna um erro. Se a impressora padrão do sistema for suportada por um driver `hDevNames` de impressora antigo (antes da versão 3.0 do Windows), apenas será devolvida; `hDevMode` é NULO.

- PSD_DISABLEPAPER desabilita o controle de seleção de papel.

- PSD_SHOWHELP Faz com que a caixa de diálogo mostre o botão Ajuda. O `hwndOwner` membro não deve ser NULO se esta bandeira for especificada.

- PSD_ENABLEPAGESETUPHOOK Habilita a função `lpfnSetupHook`de gancho especificada em .

- PSD_ENABLEPAGESETUPTEMPLATE faz com que o sistema operacional crie a `hInstance` caixa `lpSetupTemplateName`de diálogo usando a caixa de modelo de diálogo identificada por e .

- PSD_ENABLEPAGESETUPTEMPLATEHANDLE Indica `hInstance` que identifica um bloco de dados que contém um modelo de caixa de diálogo pré-carregado. O sistema `lpSetupTemplateName` ignora se este sinalizador for especificado.

- PSD_ENABLEPAGEPAINTHOOK Habilita a função `lpfnPagePaintHook`de gancho especificada em .

- PSD_DISABLEPAGEPAINTING Desativa a área de desenho da caixa de diálogo.

*Pparentwnd*<br/>
Ponteiro para o pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Use a função [DoModal](../../mfc/reference/cdialog-class.md#domodal) para exibir a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#94](../../mfc/codesnippet/cpp/cpagesetupdialog-class_1.cpp)]

## <a name="cpagesetupdialogcreateprinterdc"></a><a name="createprinterdc"></a>CPageConfiguração configuraçãoDiálogo::CreatePrinterDC

Cria um contexto de dispositivo de impressora a partir das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES.](/windows/win32/api/commdlg/ns-commdlg-devnames)

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor retornado

Manuseie o contexto do dispositivo de impressora recém-criado (DC).

## <a name="cpagesetupdialogdomodal"></a><a name="domodal"></a>CPageSetupDiálogo::DoModal

Chame esta função para exibir a caixa de diálogo de configuração de página oLE comum do Windows e permitir que o usuário selecione várias opções de configuração de impressão, como as margens de impressão, tamanho e orientação do papel e a impressora de destino.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL. Se o IDCANCEL for retornado, ligue para a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou Cancel.

### <a name="remarks"></a>Comentários

Além disso, o usuário pode acessar as opções de configuração da impressora, como localização da rede e propriedades específicas da impressora selecionada.

Se você quiser inicializar as várias opções de `m_psd` diálogo Configuração de página `DoModal`definindo membros da estrutura, você deve fazê-lo antes de chamar e depois que o objeto de diálogo for construído. Após `DoModal`a chamada, ligue para outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

Se você quiser propagar as configurações atuais inseridas pelo usuário, faça uma chamada para [CWinApp::SelectPrinter](../../mfc/reference/cwinapp-class.md#selectprinter). Esta função pega as `CPageSetupDialog` informações do objeto e inicializa e seleciona uma nova impressora DC com os atributos apropriados.

[!code-cpp[NVC_MFCDocView#95](../../mfc/codesnippet/cpp/cpagesetupdialog-class_2.cpp)]

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPageSetupDiálogo::CPageSetupDialog](#cpagesetupdialog).

## <a name="cpagesetupdialoggetdevicename"></a><a name="getdevicename"></a>CPageConfiguração configuraçãoDiálogo::Obternome do dispositivo

Chame esta `DoModal` função depois para recuperar o nome da impressora selecionada no momento.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do `CPageSetupDialog` dispositivo usado pelo objeto.

## <a name="cpagesetupdialoggetdevmode"></a><a name="getdevmode"></a>CPageConfiguraçãode configuraçãoDiálogo::GetDevMode

Ligue para esta `DoModal` função depois de ligar para `CPageSetupDialog` recuperar informações sobre o contexto do dispositivo da impressora do objeto.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor retornado

A estrutura de dados [DEVMODE,](/windows/win32/api/wingdi/ns-wingdi-devmodea) que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória tirada por esta estrutura com a função Windows [GlobalUnlock,](/windows/win32/api/winbase/nf-winbase-globalunlock) que é descrita no Windows SDK.

## <a name="cpagesetupdialoggetdrivername"></a><a name="getdrivername"></a>CPageConfiguraçãoconfiguraçãoDiálogo::GetDriverName

Ligue para esta função depois de ligar para o [DoModal](../../mfc/reference/cprintdialog-class.md#domodal) para recuperar o nome do driver de dispositivo de impressora definido pelo sistema.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor retornado

A `CString` especificar o nome do driver definido pelo sistema.

### <a name="remarks"></a>Comentários

Use um ponteiro `CString` para o `GetDriverName` objeto retornado como o valor de `lpszDriverName` uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).

## <a name="cpagesetupdialoggetmargins"></a><a name="getmargins"></a>CPageConfiguraçãoconfiguraçãoDiálogo::GetMargins

Ligue para esta função `DoModal` após uma chamada para recuperar as margens do driver do dispositivo da impressora.

```cpp
void GetMargins(
    LPRECT lpRectMargins,
    LPRECT lpRectMinMargins) const;
```

### <a name="parameters"></a>Parâmetros

*margens de lpRect*<br/>
Pointer para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) ou objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que descreve (em 1/1000 polegadas ou 1/100 mm) as margens de impressão para a impressora selecionada atualmente. Passe NULA para este parâmetro, se você não estiver interessado neste retângulo.

*margens de lpRectmin*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou objeto que descreve (em 1/1000 polegadas ou 1/100 mm) as margens mínimas de impressão para a impressora atualmente selecionada. Passe NULA para este parâmetro, se você não estiver interessado neste retângulo.

## <a name="cpagesetupdialoggetpapersize"></a><a name="getpapersize"></a>CPageConfiguração configuraçãoDiálogo::GetPaperSize

Chame esta função para recuperar o tamanho do papel selecionado para impressão.

```
CSize GetPaperSize() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) contendo o tamanho do papel (em 1/1000 polegadas ou 1/100 mm) selecionado para impressão.

## <a name="cpagesetupdialoggetportname"></a><a name="getportname"></a>CPageConfiguração configuraçãoDiálogo::GetPortName

Chame esta função `DoModal` depois de chamada para recuperar o nome da porta de impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da porta de impressora selecionada no momento.

## <a name="cpagesetupdialogm_psd"></a><a name="m_psd"></a>CPageConfiguraçãoconfiguraçãoDiálogo::m_psd

Uma estrutura do tipo PAGESETUPDLG, cujos membros armazenam as características do objeto de diálogo.

```
PAGESETUPDLG m_psd;
```

### <a name="remarks"></a>Comentários

Depois de `CPageSetupDialog` construir um objeto, você pode usar `m_psd` para definir `DoModal` vários aspectos da caixa de diálogo antes de chamar a função de membro.

Se você `m_psd` modificar o membro de dados diretamente, você substituirá qualquer comportamento padrão.

Para obter mais informações sobre a estrutura [PAGESETUPDLG,](/windows/win32/api/commdlg/ns-commdlg-pagesetupdlgw) consulte o SDK do Windows.

Veja o exemplo de [CPageSetupDiálogo::CPageSetupDialog](#cpagesetupdialog).

## <a name="cpagesetupdialogondrawpage"></a><a name="ondrawpage"></a>CPageSetupDiálogo::OnDrawPage

Chamado pelo framework para desenhar uma imagem de tela de uma página impressa.

```
virtual UINT OnDrawPage(
    CDC* pDC,
    UINT nMessage,
    LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para o contexto do dispositivo da impressora.

*nMessage*<br/>
Especifica uma mensagem, indicando a área da página atualmente sendo desenhada. Um dos seguintes pode ser feito:

- WM_PSD_FULLPAGERECT toda a área da página.

- WM_PSD_MINMARGINRECT as margens mínimas atuais.

- WM_PSD_MARGINRECT margens atuais.

- WM_PSD_GREEKTEXTRECT Conteúdo da página.

- WM_PSD_ENVSTAMPRECT Área reservada para uma representação de selo postal.

- WM_PSD_YAFULLPAGERECT Área para uma representação de endereço de retorno. Esta área se estende até as bordas da área da página de amostra.

*Lprect*<br/>
Ponteiro para um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [RECT](/windows/win32/api/windef/ns-windef-rect) contendo as coordenadas da área de desenho.

### <a name="return-value"></a>Valor retornado

Valor não zero se manipulado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa imagem é então exibida como parte da caixa de diálogo Deconfiguração de página OLE comum. A implementação padrão desenha uma imagem de uma página de texto.

Substituir esta função para personalizar o desenho de uma área específica da imagem ou de toda a imagem. Você pode fazer isso usando uma instrução **de switch** com declarações de **caso** verificando o valor do *nMessage*. Por exemplo, para personalizar a renderização do conteúdo da imagem da página, você pode usar o seguinte código de exemplo:

[!code-cpp[NVC_MFCDocView#96](../../mfc/codesnippet/cpp/cpagesetupdialog-class_3.cpp)]

Observe que você não precisa lidar com todos os casos de *nMessage*. Você pode optar por manusear um componente da imagem, vários componentes da imagem ou toda a área.

## <a name="cpagesetupdialogpredrawpage"></a><a name="predrawpage"></a>CPageConfiguraçãode configuraçãoDiálogo::PreDrawPage

Chamado pela estrutura antes de desenhar a imagem da tela de uma página impressa.

```
virtual UINT PreDrawPage(
    WORD wPaper,
    WORD wFlags,
    LPPAGESETUPDLG pPSD);
```

### <a name="parameters"></a>Parâmetros

*wPaper*<br/>
Especifica um valor que indique o tamanho do papel. Este valor pode ser um dos **valores DMPAPER_** listados na descrição da estrutura [DEVMODE.](/windows/win32/api/wingdi/ns-wingdi-devmodea)

*Wflags*<br/>
Indica a orientação do papel ou envelope e se a impressora é um dispositivo de matriz de pontos ou HPPCL (Hewlett Packard Printer Control Language). Esse parâmetro pode ter um dos seguintes valores:

- 0x001 Papel no modo paisagem (matriz de pontos)

- 0x003 Papel no modo paisagem (HPPCL)

- 0x005 Papel no modo retrato (matriz de pontos)

- 0x007 Papel no modo retrato (HPPCL)

- Envelope 0x00b no modo paisagem (HPPCL)

- Envelope 0x00d no modo retrato (matriz de pontos)

- 0x019 Envelope no modo paisagem (matriz de pontos)

- Envelope 0x01f no modo retrato (matriz de pontos)

*pPSD*<br/>
Ponteiro para uma estrutura `PAGESETUPDLG`. Para obter mais informações sobre [PAGESETUPDLG,](/windows/win32/api/commdlg/ns-commdlg-pagesetupdlgw)consulte o Windows SDK.

### <a name="return-value"></a>Valor retornado

Valor não zero se manipulado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar o desenho da imagem. Se você anular esta função e retornar TRUE, você deve desenhar toda a imagem. Se você substituir essa função e retornar FALSE, toda a imagem padrão será desenhada pela estrutura.

## <a name="see-also"></a>Confira também

[MFC Sample WORDPAD](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

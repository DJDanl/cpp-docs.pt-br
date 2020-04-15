---
title: Classe CprintDialog
ms.date: 11/04/2016
f1_keywords:
- CPrintDialog
- AFXDLGS/CPrintDialog
- AFXDLGS/CPrintDialog::CPrintDialog
- AFXDLGS/CPrintDialog::CreatePrinterDC
- AFXDLGS/CPrintDialog::DoModal
- AFXDLGS/CPrintDialog::GetCopies
- AFXDLGS/CPrintDialog::GetDefaults
- AFXDLGS/CPrintDialog::GetDeviceName
- AFXDLGS/CPrintDialog::GetDevMode
- AFXDLGS/CPrintDialog::GetDriverName
- AFXDLGS/CPrintDialog::GetFromPage
- AFXDLGS/CPrintDialog::GetPortName
- AFXDLGS/CPrintDialog::GetPrinterDC
- AFXDLGS/CPrintDialog::GetToPage
- AFXDLGS/CPrintDialog::PrintAll
- AFXDLGS/CPrintDialog::PrintCollate
- AFXDLGS/CPrintDialog::PrintRange
- AFXDLGS/CPrintDialog::PrintSelection
- AFXDLGS/CPrintDialog::m_pd
helpviewer_keywords:
- CPrintDialog [MFC], CPrintDialog
- CPrintDialog [MFC], CreatePrinterDC
- CPrintDialog [MFC], DoModal
- CPrintDialog [MFC], GetCopies
- CPrintDialog [MFC], GetDefaults
- CPrintDialog [MFC], GetDeviceName
- CPrintDialog [MFC], GetDevMode
- CPrintDialog [MFC], GetDriverName
- CPrintDialog [MFC], GetFromPage
- CPrintDialog [MFC], GetPortName
- CPrintDialog [MFC], GetPrinterDC
- CPrintDialog [MFC], GetToPage
- CPrintDialog [MFC], PrintAll
- CPrintDialog [MFC], PrintCollate
- CPrintDialog [MFC], PrintRange
- CPrintDialog [MFC], PrintSelection
- CPrintDialog [MFC], m_pd
ms.assetid: 5bdb2424-adf8-433d-a97c-df11a83bc4e4
ms.openlocfilehash: 6490e5488c5ab3b808a02e3608b75541e4063d8f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364063"
---
# <a name="cprintdialog-class"></a>Classe CprintDialog

Encapsula os serviços fornecidos pela caixa de diálogo comum do Windows para impressão.

## <a name="syntax"></a>Sintaxe

```
class CPrintDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CprintDialog::CPrintDialog](#cprintdialog)|Constrói um objeto `CPrintDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[diálogo cprint::CreatePrinterDC](#createprinterdc)|Cria um contexto do dispositivo da impressora sem exibir a caixa de diálogo Imprimir.|
|[CPrintDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[CprintDialog::GetCopies](#getcopies)|Recupera o número de cópias solicitadas.|
|[CPrintDialog::GetDefaults](#getdefaults)|Recupera os padrões do dispositivo sem exibir uma caixa de diálogo.|
|[CprintDialog::getNome do dispositivo](#getdevicename)|Recupera o nome do dispositivo de impressora selecionado no momento.|
|[CPrintDialog::GetDevMode](#getdevmode)|Recupera a `DEVMODE` estrutura.|
|[CprintDialog::GetDriverName](#getdrivername)|Recupera o nome do driver de impressora atualmente selecionado.|
|[CprintDialog::getFromPage](#getfrompage)|Recupera a página inicial da faixa de impressão.|
|[CprintDialog::GetPortName](#getportname)|Recupera o nome da porta de impressora selecionada no momento.|
|[Diálogo cprint::GetPrinterDC](#getprinterdc)|Recupera uma alça para o contexto do dispositivo da impressora.|
|[Cprintdialog::GetToPage](#gettopage)|Recupera a página final da faixa de impressão.|
|[CPrintDiálogo::PrintAll](#printall)|Determina se deve imprimir todas as páginas do documento.|
|[CPrintDialog::PrintCollate](#printcollate)|Determina se cópias colhidas são solicitadas.|
|[CPrintDialog::PrintRange](#printrange)|Determina se deve imprimir apenas um intervalo especificado de páginas.|
|[CPrintDiálogo::PrintSelection](#printselection)|Determina se deve imprimir apenas os itens selecionados no momento.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintDiálogo::m_pd](#m_pd)|Uma estrutura usada `CPrintDialog` para personalizar um objeto.|

## <a name="remarks"></a>Comentários

As caixas de diálogo de impressão comuns fornecem uma maneira fácil de implementar caixas de diálogo de configuração de impressão e impressão de forma consistente com os padrões do Windows.

> [!NOTE]
> A `CPrintDialogEx` classe encapsula os serviços fornecidos pela folha de propriedade Windows Print. Para obter mais informações, consulte a visão geral do [CPrintDialogEx.](../../mfc/reference/cprintdialogex-class.md)

`CPrintDialog`A funcionalidade é substituída pela do [CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md), que foi projetado para fornecer uma caixa de diálogo comum para a configuração de impressão e a configuração da página.

Você pode contar com a estrutura para lidar com muitos aspectos do processo de impressão para sua aplicação. Neste caso, a estrutura exibe automaticamente a caixa de diálogo comum do Windows para impressão. Você também pode ter a impressão da alça de estrutura para o seu aplicativo, mas substituir a caixa de diálogo imprimir comum com sua própria caixa de diálogo de impressão. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [Impressão](../../mfc/printing.md).

Se você quiser que seu aplicativo manuseie a `CPrintDialog` impressão sem o envolvimento da estrutura, você pode usar a `CPrintDialog` classe "como está" com o construtor fornecido, ou você pode obter sua própria classe de diálogo e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportarão como `CCommonDialog`caixas de diálogo MFC padrão porque são derivadas da classe .

Para usar `CPrintDialog` um objeto, primeiro `CPrintDialog` crie o objeto usando o construtor. Uma vez que a caixa de diálogo tenha sido construída, você pode definir ou modificar quaisquer valores na estrutura [m_pd](#m_pd) para inicializar os valores dos controles da caixa de diálogo. A `m_pd` estrutura é do tipo [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga). Para obter mais informações sobre esta estrutura, consulte o Windows SDK.

Se você não fornecer suas `m_pd` próprias `hDevMode` `hDevNames` alças para os membros `GlobalFree` e membros, certifique-se de chamar a função windows para essas alças quando você terminar com a caixa de diálogo. Ao usar a implementação de configuração `CWinApp::OnFilePrintSetup`de impressão da estrutura fornecida por , você não precisa liberar essas alças. As alças são `CWinApp` mantidas por `CWinApp`e são liberadas no destruidor. Só é necessário liberar essas alças ao usar `CPrintDialog` autônomo.

Depois de inicializar os controles `DoModal` da caixa de diálogo, ligue para a função membro para exibir a caixa de diálogo e permita que o usuário selecione as opções de impressão. `DoModal`retorna se o usuário selecionou o botão OK (IDOK) ou Cancelar (IDCANCEL).

Se `DoModal` retornar o IDOK, `CPrintDialog`você pode usar uma das funções de membro para recuperar a entrada de informações pelo usuário.

A `CPrintDialog::GetDefaults` função member é útil para recuperar os padrões atuais da impressora sem exibir uma caixa de diálogo. Esta função de membro não requer nenhuma interação do usuário.

Você pode usar `CommDlgExtendedError` a função Windows para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre esta função, consulte o SDK do Windows.

`CPrintDialog`conta com o COMMDLG. Arquivo DLL que é fornecido com as versões 3.1 do Windows e posteriores.

Para personalizar a caixa de `CPrintDialog`diálogo, obtenha uma classe, forneça um modelo de diálogo personalizado e adicione um mapa de mensagem para processar as mensagens de notificação dos controles estendidos. Quaisquer mensagens não processadas devem ser passadas para a classe base. Personalizar a função do gancho não é necessário.

Para processar a mesma mensagem de forma diferente, dependendo se a caixa de diálogo é Configuração de impressão ou impressão, você deve derivar uma classe para cada caixa de diálogo. Você também deve substituir `AttachOnSetup` a função Windows, que lida com a criação de uma nova caixa de diálogo quando o botão Configuração de impressão é selecionado dentro de uma caixa de diálogo Imprimir.

Para obter mais `CPrintDialog`informações sobre como usar, consulte [Classes de Diálogo Comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`CPrintDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cprintdialogcprintdialog"></a><a name="cprintdialog"></a>CprintDialog::CPrintDialog

Constrói um objeto de diálogo de configuração de impressão do Windows print ou de impressão.

```
CPrintDialog(
    BOOL bPrintSetupOnly,
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS | PD_HIDEPRINTTOFILE | PD_NOSELECTION,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Bprintsetuponly*<br/>
Especifica se a caixa de diálogo de impressão padrão do Windows ou a caixa de diálogo Imprimir de impressão é exibida. Defina este parâmetro como TRUE para exibir a caixa de diálogo configuração de impressão padrão do Windows. Defina-o como FALSO para exibir a caixa de diálogo Imprimir do Windows. Se *bPrintSetupOnly* for FALSE, um botão de opção De configuração de impressão ainda será exibido na caixa de diálogo Imprimir.

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas usando o operador bitwise OR. Por exemplo, o PD_ALLPAGES sinalizador define o intervalo de impressão padrão para todas as páginas do documento. Consulte a estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) no Windows SDK para obter mais informações sobre esses sinalizadores.

*Pparentwnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Esta função membro só constrói o objeto. Use `DoModal` a função membro para exibir a caixa de diálogo.

Observe que quando você chama o construtor com *bPrintSetupDefinidoapenas* definido como FALSE, o PD_RETURNDC sinalizador é usado automaticamente. Depois `DoModal`de `GetDefaults`ligar, ou `GetPrinterDC`, uma impressora `m_pd.hDC`DC será devolvida em . Este DC deve ser liberado com uma chamada `CPrintDialog`para [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) pelo chamador de .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#174](../../mfc/codesnippet/cpp/cprintdialog-class_1.cpp)]

## <a name="cprintdialogcreateprinterdc"></a><a name="createprinterdc"></a>diálogo cprint::CreatePrinterDC

Cria um contexto de dispositivo de impressora (DC) a partir das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES.](/windows/win32/api/commdlg/ns-commdlg-devnames)

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor retornado

Manuseie o contexto do dispositivo de impressora recém-criado.

### <a name="remarks"></a>Comentários

Presume-se que este DC dc da impressora atual, e quaisquer outros DCs de impressora sustais anteriormente devem ser excluídos pelo usuário. Esta função pode ser chamada, e a DC resultante foi usada, sem nunca exibir a caixa de diálogo Imprimir.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#106](../../mfc/codesnippet/cpp/cprintdialog-class_2.cpp)]

## <a name="cprintdialogdomodal"></a><a name="domodal"></a>CPrintDialog::DoModal

Exibe a caixa de diálogo de impressão comum do Windows e permite que o usuário selecione várias opções de impressão, como o número de cópias, o intervalo de páginas e se as cópias devem ser colhidas.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL. Se o IDCANCEL for retornado, ligue para a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou Cancel.

### <a name="remarks"></a>Comentários

Se você quiser inicializar as várias opções `m_pd` de diálogo de impressão `DoModal`definindo membros da estrutura, você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Depois `DoModal`de ligar, você pode ligar para outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

Observe que quando você chama o construtor com *bPrintSetupDefinidoapenas* definido como FALSE, o PD_RETURNDC sinalizador é usado automaticamente. Depois `DoModal`de `GetDefaults`ligar, ou `GetPrinterDC`, uma impressora `m_pd.hDC`DC será devolvida em . Este DC deve ser liberado com uma chamada `CPrintDialog`para [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) pelo chamador de .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::CreatePrinterDC](#createprinterdc).

## <a name="cprintdialoggetcopies"></a><a name="getcopies"></a>CprintDialog::GetCopies

Recupera o número de cópias solicitadas.

```
int GetCopies() const;
```

### <a name="return-value"></a>Valor retornado

O número de cópias solicitadas.

### <a name="remarks"></a>Comentários

Ligue para esta `DoModal` função depois de ligar para recuperar o número de cópias solicitadas.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::PrintCollate](#printcollate).

## <a name="cprintdialoggetdefaults"></a><a name="getdefaults"></a>CPrintDialog::GetDefaults

Recupera os padrões do dispositivo da impressora padrão sem exibir uma caixa de diálogo.

```
BOOL GetDefaults();
```

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os valores recuperados são `m_pd` colocados na estrutura.

Em alguns casos, uma chamada [constructor](#cprintdialog) para esta `CPrintDialog` função chamará o construtor para com *bPrintSetupOnly* definido como FALSE. Nestes casos, uma `hDevNames` impressora `hDevMode` DC e (duas `m_pd` alças localizadas no membro de dados) são automaticamente alocadas.

Se o construtor `CPrintDialog` for foi chamado com *bPrintSetupOnly* definido como `hDevNames` `hDevMode` FALSE, `m_pd.hDevNames` esta `m_pd.hDevMode`função não só retornará e localizará e ) para o chamador, mas também retornará uma impressora DC em `m_pd.hDC`. É responsabilidade do chamador excluir a impressora DC e chamar a função Windows [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree) nas alças quando terminar o `CPrintDialog` objeto.

### <a name="example"></a>Exemplo

Este fragmento de código obtém o contexto do dispositivo da impressora padrão e relata ao usuário a resolução da impressora em pontos por polegada. (Este atributo dos recursos da impressora é frequentemente referido como DPI.)

[!code-cpp[NVC_MFCDocView#107](../../mfc/codesnippet/cpp/cprintdialog-class_3.cpp)]

## <a name="cprintdialoggetdevicename"></a><a name="getdevicename"></a>CprintDialog::getNome do dispositivo

Recupera o nome do dispositivo de impressora selecionado no momento.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da impressora selecionada no momento.

### <a name="remarks"></a>Comentários

Ligue para esta função depois de ligar para o [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento ou depois de chamar [GetDefaults](#getdefaults) para recuperar os padrões atuais do dispositivo da impressora padrão. Use um ponteiro `CString` para o `GetDeviceName` objeto retornado como o valor de `lpszDeviceName` uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).

### <a name="example"></a>Exemplo

Este fragmento de código mostra o nome padrão da impressora do usuário e a porta a que está conectado, juntamente com o nome do spooler que a impressora usa. O código pode mostrar uma caixa de mensagem que diz: \\"Sua impressora padrão é HP LaserJet IIIP em \server\share usando winspool.", por exemplo.

[!code-cpp[NVC_MFCDocView#108](../../mfc/codesnippet/cpp/cprintdialog-class_4.cpp)]

## <a name="cprintdialoggetdevmode"></a><a name="getdevmode"></a>CPrintDialog::GetDevMode

Recupera a `DEVMODE` estrutura.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor retornado

A estrutura de dados [DEVMODE,](/windows/win32/api/wingdi/ns-wingdi-devmodea) que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória tirada por esta estrutura com a função Windows [GlobalUnlock,](/windows/win32/api/winbase/nf-winbase-globalunlock) que é descrita no Windows SDK.

### <a name="remarks"></a>Comentários

Ligue para esta função depois de ligar para [doModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::PrintCollate](#printcollate).

## <a name="cprintdialoggetdrivername"></a><a name="getdrivername"></a>CprintDialog::GetDriverName

Recupera o nome do driver de impressora atualmente selecionado.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor retornado

A `CString` especificar o nome do driver definido pelo sistema.

### <a name="remarks"></a>Comentários

Ligue para esta função depois de ligar para [doModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo de impressora definido pelo sistema. Use um ponteiro `CString` para o `GetDriverName` objeto retornado como o valor de `lpszDriverName` uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::GetDeviceName](#getdevicename).

## <a name="cprintdialoggetfrompage"></a><a name="getfrompage"></a>CprintDialog::getFromPage

Recupera a página inicial da faixa de impressão.

```
int GetFromPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da página inicial na faixa de páginas a ser impressa.

### <a name="remarks"></a>Comentários

Ligue para esta `DoModal` função depois de ligar para recuperar o número da página inicial na faixa de páginas a ser impressa.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).

## <a name="cprintdialoggetportname"></a><a name="getportname"></a>CprintDialog::GetPortName

Recupera o nome da porta de impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da porta de impressora selecionada no momento.

### <a name="remarks"></a>Comentários

Chame esta função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta de impressora selecionada no momento.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::GetDeviceName](#getdevicename).

## <a name="cprintdialoggetprinterdc"></a><a name="getprinterdc"></a>Diálogo cprint::GetPrinterDC

Recupera uma alça para o contexto do dispositivo da impressora.

```
HDC GetPrinterDC() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para o contexto do dispositivo da impressora se for bem-sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se o parâmetro *bPrintSetupOnly* da `CPrintDialog` construtora foi FALSO (indicando que a `GetPrinterDC` caixa de diálogo Imprimir está exibida), então retorna uma alça para o contexto do dispositivo da impressora. Você deve chamar a função Windows [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) para excluir o contexto do dispositivo quando terminar de usá-lo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#109](../../mfc/codesnippet/cpp/cprintdialog-class_5.cpp)]

## <a name="cprintdialoggettopage"></a><a name="gettopage"></a>Cprintdialog::GetToPage

Recupera a página final da faixa de impressão.

```
int GetToPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da página final na faixa de páginas a ser impressa.

### <a name="remarks"></a>Comentários

Ligue para esta `DoModal` função depois de ligar para recuperar o número da página final na faixa de páginas a ser impressa.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).

## <a name="cprintdialogm_pd"></a><a name="m_pd"></a>CPrintDiálogo::m_pd

Uma estrutura cujos membros armazenam as características do objeto de diálogo.

```
PRINTDLG& m_pd;
```

### <a name="remarks"></a>Comentários

Depois de `CPrintDialog` construir um objeto, você pode usar `m_pd` para definir vários aspectos da caixa de diálogo antes de chamar a função de membro [DoModal.](#domodal) Para obter mais `m_pd` informações sobre a estrutura, consulte [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) no Windows SDK.

Se você `m_pd` modificar o membro de dados diretamente, você substituirá qualquer comportamento padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#111](../../mfc/codesnippet/cpp/cprintdialog-class_6.cpp)]

## <a name="cprintdialogprintall"></a><a name="printall"></a>CPrintDiálogo::PrintAll

Determina se deve imprimir todas as páginas do documento.

```
BOOL PrintAll() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se todas as páginas do documento forem impressas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ligue para esta `DoModal` função após a chamada para determinar se deve imprimir todas as páginas do documento.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).

## <a name="cprintdialogprintcollate"></a><a name="printcollate"></a>CPrintDialog::PrintCollate

Determina se cópias colhidas são solicitadas.

```
BOOL PrintCollate() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário selecionar a caixa de seleção de cotar na caixa de diálogo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ligue para esta `DoModal` função após a chamada para determinar se a impressora deve reunir todas as cópias impressas do documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#110](../../mfc/codesnippet/cpp/cprintdialog-class_7.cpp)]

## <a name="cprintdialogprintrange"></a><a name="printrange"></a>CPrintDialog::PrintRange

Determina se deve imprimir apenas um intervalo especificado de páginas.

```
BOOL PrintRange() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se apenas uma gama de páginas no documento for impressa; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ligue para esta `DoModal` função após a chamada para determinar se deve imprimir apenas uma série de páginas no documento.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).

## <a name="cprintdialogprintselection"></a><a name="printselection"></a>CPrintDiálogo::PrintSelection

Determina se deve imprimir apenas os itens selecionados no momento.

```
BOOL PrintSelection() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se apenas os itens selecionados forem impressos; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame esta função `DoModal` após a chamada para determinar se deve imprimir apenas os itens selecionados no momento.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).

## <a name="see-also"></a>Confira também

[Amostra de MFC DIBLOOK](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)

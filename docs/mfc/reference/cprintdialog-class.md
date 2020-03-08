---
title: Classe CPrintDialog
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
ms.openlocfilehash: ccc673d665d6d5beb92f398b21e6ffd313a58fc9
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855420"
---
# <a name="cprintdialog-class"></a>Classe CPrintDialog

Encapsula os serviços fornecidos pela caixa de diálogo comum do Windows para impressão.

## <a name="syntax"></a>Sintaxe

```
class CPrintDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CPrintDialog::CPrintDialog](#cprintdialog)|Constrói um objeto `CPrintDialog`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CPrintDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora sem exibir a caixa de diálogo Imprimir.|
|[CPrintDialog::D oModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|
|[CPrintDialog:: getcopies](#getcopies)|Recupera o número de cópias solicitadas.|
|[CPrintDialog:: getpadrão](#getdefaults)|Recupera os padrões de dispositivo sem exibir uma caixa de diálogo.|
|[CPrintDialog:: DeviceName](#getdevicename)|Recupera o nome do dispositivo de impressora selecionado no momento.|
|[CPrintDialog:: getdevmode](#getdevmode)|Recupera a estrutura de `DEVMODE`.|
|[CPrintDialog:: GetDriverName](#getdrivername)|Recupera o nome do driver de impressora selecionado no momento.|
|[CPrintDialog::GetFromPage](#getfrompage)|Recupera a página inicial do intervalo de impressão.|
|[CPrintDialog:: getportname](#getportname)|Recupera o nome da porta de impressora selecionada no momento.|
|[CPrintDialog::GetPrinterDC](#getprinterdc)|Recupera um identificador para o contexto do dispositivo de impressora.|
|[CPrintDialog::GetToPage](#gettopage)|Recupera a página final do intervalo de impressão.|
|[CPrintDialog::P rintAll](#printall)|Determina se todas as páginas do documento devem ser impressas.|
|[CPrintDialog::P rintCollate](#printcollate)|Determina se as cópias agrupadas são solicitadas.|
|[CPrintDialog::P rintRange](#printrange)|Determina se um intervalo de páginas especificado deve ser impresso.|
|[CPrintDialog::P rintSelection](#printselection)|Determina se os itens atualmente selecionados devem ser impressos.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CPrintDialog:: m_pd](#m_pd)|Uma estrutura usada para personalizar um objeto de `CPrintDialog`.|

## <a name="remarks"></a>Comentários

As caixas de diálogo de impressão comuns fornecem uma maneira fácil de implementar caixas de diálogo de configuração de impressão e impressão de maneira consistente com os padrões do Windows.

> [!NOTE]
>  A classe `CPrintDialogEx` encapsula os serviços fornecidos pela folha de propriedades de impressão do Windows. Para obter mais informações, consulte a visão geral do [CPrintDialogEx](../../mfc/reference/cprintdialogex-class.md) .

a funcionalidade de `CPrintDialog`é substituída por aquela do [CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md), que é projetada para fornecer uma caixa de diálogo comum para configuração de impressão e configuração de página.

Você pode contar com a estrutura para lidar com vários aspectos do processo de impressão para seu aplicativo. Nesse caso, a estrutura exibe automaticamente a caixa de diálogo comum do Windows para impressão. Você também pode fazer com que o identificador de estrutura seja impresso para seu aplicativo, mas substitua a caixa de diálogo Imprimir comum por sua própria caixa de diálogo de impressão. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [imprimindo](../../mfc/printing.md).

Se você quiser que seu aplicativo manipule a impressão sem o envolvimento da estrutura, você pode usar a classe `CPrintDialog` "no estado em que se encontra" com o construtor fornecido ou pode derivar sua própria classe de diálogo de `CPrintDialog` e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportarão como caixas de diálogo padrão do MFC porque são derivadas da classe `CCommonDialog`.

Para usar um objeto `CPrintDialog`, primeiro crie o objeto usando o Construtor `CPrintDialog`. Depois que a caixa de diálogo tiver sido construída, você poderá definir ou modificar quaisquer valores na estrutura de [m_pd](#m_pd) para inicializar os valores dos controles da caixa de diálogo. A estrutura de `m_pd` é do tipo [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga). Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

Se você não fornecer seus próprios identificadores em `m_pd` para os membros `hDevMode` e `hDevNames`, certifique-se de chamar o `GlobalFree` de função do Windows para esses identificadores quando terminar a caixa de diálogo. Ao usar a implementação da configuração de impressão da estrutura fornecida pelo `CWinApp::OnFilePrintSetup`, você não precisa liberar esses identificadores. Os identificadores são mantidos por `CWinApp` e são liberados no destruidor de `CWinApp`. Só é necessário liberar esses identificadores ao usar `CPrintDialog` autônomos.

Depois de inicializar os controles da caixa de diálogo, chame a função membro `DoModal` para exibir a caixa de diálogo e permitir que o usuário selecione opções de impressão. `DoModal` retorna se o usuário selecionou o botão OK (IDOK) ou Cancel (IDCANCEL).

Se `DoModal` retornar IDOK, você poderá usar uma das funções de membro de `CPrintDialog`para recuperar a entrada de informações pelo usuário.

A função membro `CPrintDialog::GetDefaults` é útil para recuperar os padrões de impressora atuais sem exibir uma caixa de diálogo. Essa função de membro não requer interação do usuário.

Você pode usar a função `CommDlgExtendedError` do Windows para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre essa função, consulte a SDK do Windows.

`CPrintDialog` se baseia no COMMDLG. Arquivo DLL fornecido com o Windows versões 3,1 e posteriores.

Para personalizar a caixa de diálogo, derive uma classe de `CPrintDialog`, forneça um modelo de caixa de diálogo personalizado e adicione um mapa de mensagens para processar as mensagens de notificação dos controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base. A personalização da função Hook não é necessária.

Para processar a mesma mensagem de forma diferente, dependendo se a caixa de diálogo é configuração de impressão ou impressão, você deve derivar uma classe para cada caixa de diálogo. Você também deve substituir a função de `AttachOnSetup` do Windows, que manipula a criação de uma nova caixa de diálogo quando o botão configurar impressão é selecionado dentro de uma caixa de diálogo de impressão.

Para obter mais informações sobre como usar `CPrintDialog`, consulte [classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CPrintDialog`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxdlgs. h

##  <a name="cprintdialog"></a>CPrintDialog::CPrintDialog

Constrói um objeto de diálogo de configuração de impressão ou impressão do Windows.

```
CPrintDialog(
    BOOL bPrintSetupOnly,
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS | PD_HIDEPRINTTOFILE | PD_NOSELECTION,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*bPrintSetupOnly*<br/>
Especifica se a caixa de diálogo de impressão padrão do Windows ou a caixa de diálogo configuração de impressão é exibida. Defina esse parâmetro como TRUE para exibir a caixa de diálogo padrão de configuração de impressão do Windows. Defina-a como FALSE para exibir a caixa de diálogo de impressão do Windows. Se *bPrintSetupOnly* for false, um botão de opção de configuração de impressão ainda será exibido na caixa de diálogo Imprimir.

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas usando o operador OR Por exemplo, o sinalizador PD_ALLPAGES define o intervalo de impressão padrão para todas as páginas do documento. Consulte a estrutura [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) no SDK do Windows para obter mais informações sobre esses sinalizadores.

*pParentWnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Essa função de membro apenas constrói o objeto. Use a função de membro `DoModal` para exibir a caixa de diálogo.

Observe que, quando você chama o construtor com *bPrintSetupOnly* definido como false, o sinalizador PD_RETURNDC é usado automaticamente. Depois de chamar `DoModal`, `GetDefaults`ou `GetPrinterDC`, um controlador de domínio de impressora será retornado em `m_pd.hDC`. Esse DC deve ser liberado com uma chamada para [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) pelo chamador de `CPrintDialog`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#174](../../mfc/codesnippet/cpp/cprintdialog-class_1.cpp)]

##  <a name="createprinterdc"></a>CPrintDialog::CreatePrinterDC

Cria um DC (contexto de dispositivo de impressora) das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) .

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor retornado

Identificador para o contexto do dispositivo de impressora recém-criado.

### <a name="remarks"></a>Comentários

Esse controlador de domínio é considerado o DC de impressora atual e qualquer outro controlador de domínio de impressora obtido anteriormente deve ser excluído pelo usuário. Essa função pode ser chamada e o DC resultante usado, sem nunca exibir a caixa de diálogo Imprimir.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#106](../../mfc/codesnippet/cpp/cprintdialog-class_2.cpp)]

##  <a name="domodal"></a>CPrintDialog::D oModal

Exibe a caixa de diálogo impressão comum do Windows e permite que o usuário selecione várias opções de impressão, como o número de cópias, o intervalo de páginas e se as cópias devem ser agrupadas.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

IDOK ou IDCANCEL. Se IDCANCEL for retornado, chame a função [CommDlgExtendedError](/windows/win32/api/commdlg/nf-commdlg-commdlgextendederror) do Windows para determinar se ocorreu um erro.

IDOK e IDCANCEL são constantes que indicam se o usuário selecionou o botão OK ou cancelar.

### <a name="remarks"></a>Comentários

Se você quiser inicializar as várias opções da caixa de diálogo de impressão definindo membros da estrutura de `m_pd`, faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Depois de chamar `DoModal`, você pode chamar outras funções de membro para recuperar as configurações ou as informações inseridas pelo usuário na caixa de diálogo.

Observe que, quando você chama o construtor com *bPrintSetupOnly* definido como false, o sinalizador PD_RETURNDC é usado automaticamente. Depois de chamar `DoModal`, `GetDefaults`ou `GetPrinterDC`, um controlador de domínio de impressora será retornado em `m_pd.hDC`. Esse DC deve ser liberado com uma chamada para [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) pelo chamador de `CPrintDialog`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: CreatePrinterDC](#createprinterdc).

##  <a name="getcopies"></a>CPrintDialog:: getcopies

Recupera o número de cópias solicitadas.

```
int GetCopies() const;
```

### <a name="return-value"></a>Valor retornado

O número de cópias solicitadas.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para recuperar o número de cópias solicitadas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog::P rintcollate](#printcollate).

##  <a name="getdefaults"></a>CPrintDialog:: getpadrão

Recupera os padrões do dispositivo da impressora padrão sem exibir uma caixa de diálogo.

```
BOOL GetDefaults();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os valores recuperados são colocados na estrutura de `m_pd`.

Em alguns casos, uma chamada para essa função chamará o [Construtor](#cprintdialog) para `CPrintDialog` com *BPRINTSETUPONLY* definido como false. Nesses casos, um DC de impressora e `hDevNames` e `hDevMode` (dois identificadores localizados no membro de dados `m_pd`) são alocados automaticamente.

Se o construtor para `CPrintDialog` foi chamado com *bPrintSetupOnly* definido como false, essa função não retornará apenas `hDevNames` e `hDevMode` localizado em `m_pd.hDevNames` e `m_pd.hDevMode`) para o chamador, mas também retornará um controlador de domínio de impressora no `m_pd.hDC`. É responsabilidade do chamador excluir o controlador de domínio da impressora e chamar a função [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree) do Windows nos identificadores quando você terminar com o objeto `CPrintDialog`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Este fragmento de código obtém o contexto de dispositivo da impressora padrão e relata ao usuário a resolução da impressora em pontos por polegada. (Esse atributo dos recursos da impressora é geralmente referido como DPI.)

[!code-cpp[NVC_MFCDocView#107](../../mfc/codesnippet/cpp/cprintdialog-class_3.cpp)]

##  <a name="getdevicename"></a>CPrintDialog:: DeviceName

Recupera o nome do dispositivo de impressora selecionado no momento.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da impressora selecionada no momento.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento ou depois de chamar [GetDefaults](#getdefaults) para recuperar os padrões do dispositivo atual da impressora padrão. Use um ponteiro para o objeto `CString` retornado pelo `GetDeviceName` como o valor de `lpszDeviceName` em uma chamada para [CDC:: CreateDC](../../mfc/reference/cdc-class.md#createdc).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Esse fragmento de código mostra o nome da impressora padrão do usuário e a porta à qual ele está conectado, juntamente com o nome do spooler usado pela impressora. O código pode mostrar uma caixa de mensagem que diz "a sua impressora padrão é HP LaserJet IIIP no \\\server\share usando winspool.", por exemplo.

[!code-cpp[NVC_MFCDocView#108](../../mfc/codesnippet/cpp/cprintdialog-class_4.cpp)]

##  <a name="getdevmode"></a>CPrintDialog:: getdevmode

Recupera a estrutura de `DEVMODE`.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor retornado

A estrutura de dados [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) , que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória usada por essa estrutura com a função [GlobalUnlock](/windows/win32/api/winbase/nf-winbase-globalunlock) do Windows, que é descrita no SDK do Windows.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog::P rintcollate](#printcollate).

##  <a name="getdrivername"></a>CPrintDialog:: GetDriverName

Recupera o nome do driver de impressora selecionado no momento.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor retornado

Um `CString` especificando o nome do driver definido pelo sistema.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo de impressora definido pelo sistema. Use um ponteiro para o objeto `CString` retornado pelo `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC:: CreateDC](../../mfc/reference/cdc-class.md#createdc).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: DeviceName](#getdevicename).

##  <a name="getfrompage"></a>CPrintDialog::GetFromPage

Recupera a página inicial do intervalo de impressão.

```
int GetFromPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da página inicial no intervalo de páginas a ser impresso.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para recuperar o número da página inicial no intervalo de páginas a serem impressas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: m_pd](#m_pd).

##  <a name="getportname"></a>CPrintDialog:: getportname

Recupera o nome da porta de impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da porta de impressora selecionada no momento.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta de impressora selecionada no momento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: DeviceName](#getdevicename).

##  <a name="getprinterdc"></a>CPrintDialog::GetPrinterDC

Recupera um identificador para o contexto do dispositivo de impressora.

```
HDC GetPrinterDC() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o contexto do dispositivo de impressora se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se o parâmetro *bPrintSetupOnly* do construtor de `CPrintDialog` for false (indicando que a caixa de diálogo Imprimir é exibida), `GetPrinterDC` retornará um identificador para o contexto do dispositivo de impressora. Você deve chamar a função [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) do Windows para excluir o contexto do dispositivo quando terminar de usá-lo.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#109](../../mfc/codesnippet/cpp/cprintdialog-class_5.cpp)]

##  <a name="gettopage"></a>CPrintDialog::GetToPage

Recupera a página final do intervalo de impressão.

```
int GetToPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da página final no intervalo de páginas a ser impresso.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para recuperar o número da página final no intervalo de páginas a serem impressas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: m_pd](#m_pd).

##  <a name="m_pd"></a>CPrintDialog:: m_pd

Uma estrutura cujos membros armazenam as características do objeto da caixa de diálogo.

```
PRINTDLG& m_pd;
```

### <a name="remarks"></a>Comentários

Depois de construir um objeto de `CPrintDialog`, você pode usar `m_pd` para definir vários aspectos da caixa de diálogo antes de chamar a função de membro [DoModal](#domodal) . Para obter mais informações sobre a estrutura de `m_pd`, consulte [PRINTDLG](/windows/win32/api/commdlg/ns-commdlg-printdlga) no SDK do Windows.

Se você modificar o membro de dados `m_pd` diretamente, você substituirá qualquer comportamento padrão.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#111](../../mfc/codesnippet/cpp/cprintdialog-class_6.cpp)]

##  <a name="printall"></a>CPrintDialog::P rintAll

Determina se todas as páginas do documento devem ser impressas.

```
BOOL PrintAll() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se todas as páginas no documento forem impressas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para determinar se todas as páginas do documento devem ser impressas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: m_pd](#m_pd).

##  <a name="printcollate"></a>CPrintDialog::P rintCollate

Determina se as cópias agrupadas são solicitadas.

```
BOOL PrintCollate() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário marcar a caixa de seleção Agrupar na caixa de diálogo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para determinar se a impressora deve agrupar todas as cópias impressas do documento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#110](../../mfc/codesnippet/cpp/cprintdialog-class_7.cpp)]

##  <a name="printrange"></a>CPrintDialog::P rintRange

Determina se um intervalo de páginas especificado deve ser impresso.

```
BOOL PrintRange() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se apenas um intervalo de páginas no documento for impresso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para determinar se deseja imprimir apenas um intervalo de páginas no documento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: m_pd](#m_pd).

##  <a name="printselection"></a>CPrintDialog::P rintSelection

Determina se os itens atualmente selecionados devem ser impressos.

```
BOOL PrintSelection() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se apenas os itens selecionados forem impressos; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar `DoModal` para determinar se deseja imprimir somente os itens selecionados no momento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CPrintDialog:: m_pd](#m_pd).

## <a name="see-also"></a>Consulte também

[Exemplo de DIBLOOK do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)

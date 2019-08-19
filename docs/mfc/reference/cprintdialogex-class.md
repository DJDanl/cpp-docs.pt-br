---
title: Classe CPrintDialogEx
ms.date: 11/04/2016
f1_keywords:
- CPrintDialogEx
- AFXDLGS/CPrintDialogEx
- AFXDLGS/CPrintDialogEx::CPrintDialogEx
- AFXDLGS/CPrintDialogEx::CreatePrinterDC
- AFXDLGS/CPrintDialogEx::DoModal
- AFXDLGS/CPrintDialogEx::GetCopies
- AFXDLGS/CPrintDialogEx::GetDefaults
- AFXDLGS/CPrintDialogEx::GetDeviceName
- AFXDLGS/CPrintDialogEx::GetDevMode
- AFXDLGS/CPrintDialogEx::GetDriverName
- AFXDLGS/CPrintDialogEx::GetPortName
- AFXDLGS/CPrintDialogEx::GetPrinterDC
- AFXDLGS/CPrintDialogEx::PrintAll
- AFXDLGS/CPrintDialogEx::PrintCollate
- AFXDLGS/CPrintDialogEx::PrintCurrentPage
- AFXDLGS/CPrintDialogEx::PrintRange
- AFXDLGS/CPrintDialogEx::PrintSelection
- AFXDLGS/CPrintDialogEx::m_pdex
helpviewer_keywords:
- CPrintDialogEx [MFC], CPrintDialogEx
- CPrintDialogEx [MFC], CreatePrinterDC
- CPrintDialogEx [MFC], DoModal
- CPrintDialogEx [MFC], GetCopies
- CPrintDialogEx [MFC], GetDefaults
- CPrintDialogEx [MFC], GetDeviceName
- CPrintDialogEx [MFC], GetDevMode
- CPrintDialogEx [MFC], GetDriverName
- CPrintDialogEx [MFC], GetPortName
- CPrintDialogEx [MFC], GetPrinterDC
- CPrintDialogEx [MFC], PrintAll
- CPrintDialogEx [MFC], PrintCollate
- CPrintDialogEx [MFC], PrintCurrentPage
- CPrintDialogEx [MFC], PrintRange
- CPrintDialogEx [MFC], PrintSelection
- CPrintDialogEx [MFC], m_pdex
ms.assetid: 1d506703-ee1c-44cc-b4ce-4e778fec26b8
ms.openlocfilehash: 2334fb0a420e14aa4fa8b8b570671fb9a611de32
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502877"
---
# <a name="cprintdialogex-class"></a>Classe CPrintDialogEx

Encapsula os serviços fornecidos pela folha de propriedades de impressão do Windows.

## <a name="syntax"></a>Sintaxe

```
class CPrintDialogEx : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintDialogEx::CPrintDialogEx](#cprintdialogex)|Constrói um objeto `CPrintDialogEx`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintDialogEx::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora sem exibir a caixa de diálogo Imprimir.|
|[CPrintDialogEx::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça seleções.|
|[CPrintDialogEx::GetCopies](#getcopies)|Recupera o número de cópias solicitadas.|
|[CPrintDialogEx::GetDefaults](#getdefaults)|Recupera os padrões de dispositivo sem exibir uma caixa de diálogo.|
|[CPrintDialogEx::GetDeviceName](#getdevicename)|Recupera o nome do dispositivo de impressora selecionado no momento.|
|[CPrintDialogEx::GetDevMode](#getdevmode)|Recupera a `DEVMODE` estrutura.|
|[CPrintDialogEx::GetDriverName](#getdrivername)|Recupera o nome do driver de dispositivo de impressora definido pelo sistema.|
|[CPrintDialogEx::GetPortName](#getportname)|Recupera o nome da porta de impressora selecionada no momento.|
|[CPrintDialogEx::GetPrinterDC](#getprinterdc)|Recupera um identificador para o contexto do dispositivo de impressora.|
|[CPrintDialogEx::PrintAll](#printall)|Determina se todas as páginas do documento devem ser impressas.|
|[CPrintDialogEx::PrintCollate](#printcollate)|Determina se as cópias agrupadas são solicitadas.|
|[CPrintDialogEx::PrintCurrentPage](#printcurrentpage)|Determina se a página atual do documento deve ser impressa.|
|[CPrintDialogEx::PrintRange](#printrange)|Determina se um intervalo de páginas especificado deve ser impresso.|
|[CPrintDialogEx::PrintSelection](#printselection)|Determina se os itens atualmente selecionados devem ser impressos.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintDialogEx::m_pdex](#m_pdex)|Uma estrutura usada para personalizar um `CPrintDialogEx` objeto.|

## <a name="remarks"></a>Comentários

Você pode contar com a estrutura para lidar com vários aspectos do processo de impressão para seu aplicativo. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [imprimindo](../../mfc/printing.md).

Se você quiser que seu aplicativo manipule a impressão sem o envolvimento da estrutura, você pode usar `CPrintDialogEx` a classe "no estado em que se encontra" com o construtor fornecido ou pode derivar sua `CPrintDialogEx` própria classe de caixa de diálogo de e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportarão como caixas de diálogo padrão do MFC `CCommonDialog`porque são derivadas da classe.

Para usar um `CPrintDialogEx` objeto, primeiro crie o objeto usando o `CPrintDialogEx` Construtor. Depois que a caixa de diálogo tiver sido construída, você poderá definir ou modificar quaisquer valores na estrutura [m_pdex](#m_pdex) para inicializar os valores dos controles da caixa de diálogo. A `m_pdex` estrutura é do tipo [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-pdexw). Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

Se você não `m_pdex` fornecer seus próprios identificadores para os `hDevMode` Membros e `hDevNames` , certifique-se de chamar a função `GlobalFree` do Windows para esses identificadores quando terminar a caixa de diálogo.

Depois de inicializar os controles da caixa de diálogo `DoModal` , chame a função membro para exibir a caixa de diálogo e permitir que o usuário selecione opções de impressão. Quando `DoModal` retorna, você pode determinar se o usuário selecionou o botão OK, aplicar ou cancelar.

Se o usuário pressionou Ok, você pode `CPrintDialogEx`usar as funções de membro para recuperar a entrada de informações pelo usuário.

A `CPrintDialogEx::GetDefaults` função de membro é útil para recuperar os padrões de impressora atuais sem exibir uma caixa de diálogo. Esse método não requer interação do usuário.

Você pode usar a função `CommDlgExtendedError` do Windows para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre essa função, consulte a SDK do Windows.

Para obter mais informações sobre `CPrintDialogEx`como usar o, consulte [classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

`IObjectWithSite`

`IPrintDialogCallback`

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CPrintDialogEx`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="cprintdialogex"></a>  CPrintDialogEx::CPrintDialogEx

Constrói uma folha de propriedades de impressão do Windows.

```
CPrintDialogEx(
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS       | PD_HIDEPRINTTOFILE | PD_NOSELECTION | PD_NOCURRENTPAGE,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas usando o operador OR Por exemplo, o sinalizador PD_ALLPAGES define o intervalo de impressão padrão para todas as páginas do documento. Consulte a estrutura [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-pdexw) no SDK do Windows para obter mais informações sobre esses sinalizadores.

*pParentWnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Essa função de membro apenas constrói o objeto. Use a `DoModal` função membro para exibir a caixa de diálogo.

##  <a name="createprinterdc"></a>  CPrintDialogEx::CreatePrinterDC

Cria um DC (contexto de dispositivo de impressora) das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) .

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor de retorno

Identificador para o contexto do dispositivo de impressora recém-criado.

### <a name="remarks"></a>Comentários

O DC retornado também é armazenado no `hDC` membro de [m_pdex](#m_pdex).

Este DC é considerado o DC de impressora atual, e qualquer outro controlador de domínio de impressora obtido anteriormente deve ser excluído. Essa função pode ser chamada e o DC resultante usado, sem nunca exibir a caixa de diálogo Imprimir.

##  <a name="domodal"></a>  CPrintDialogEx::DoModal

Chame essa função para exibir a folha de propriedades de impressão do Windows e permitir que o usuário selecione várias opções de impressão, como o número de cópias, o intervalo de páginas e se as cópias devem ser agrupadas.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

O valor de retorno de INT_PTR é, na verdade, um HRESULT. Consulte a seção valores de retorno em [PRINTDLGEX](/previous-versions/windows/desktop/legacy/ms646942\(v=vs.85\)) na SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar as várias opções da caixa de diálogo de impressão definindo os `m_pdex` membros da estrutura, faça isso antes de `DoModal`chamar, mas depois que o objeto da caixa de diálogo for construído.

Depois de `DoModal`chamar, você pode chamar outras funções de membro para recuperar as configurações ou as informações inseridas pelo usuário na caixa de diálogo.

Se o sinalizador PD_RETURNDC for usado ao chamar `DoModal`, um controlador de domínio de impressora será retornado `hDC` no membro de [m_pdex](#m_pdex). Esse DC deve ser liberado com uma chamada para [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) pelo chamador de `CPrintDialogEx`.

##  <a name="getcopies"></a>  CPrintDialogEx::GetCopies

Chame essa função depois de `DoModal` chamar para recuperar o número de cópias solicitadas.

```
int GetCopies() const;
```

### <a name="return-value"></a>Valor de retorno

O número de cópias solicitadas.

##  <a name="getdefaults"></a>  CPrintDialogEx::GetDefaults

Chame essa função para recuperar os padrões do dispositivo da impressora padrão sem exibir uma caixa de diálogo.

```
BOOL GetDefaults();
```

### <a name="return-value"></a>Valor de retorno

TRUE se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Cria um DC (contexto de dispositivo de impressora) das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) .

`GetDefaults`não exibe a folha de propriedades de impressão. Em vez disso, ele `hDevNames` define `hDevMode` o e os membros de [m_pdex](#m_pdex) como identificadores para as estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) que são inicializadas para a impressora padrão do sistema. Ambos `hDevNames` `GetDefaults` e `hDevMode` devem ser nulos ou falhar.

Se o sinalizador PD_RETURNDC for definido, `hDevNames` essa função não retornará apenas e `hDevMode` (localizado em `m_pdex.hDevNames` e `m_pdex.hDevMode`) para o chamador, mas também retornará um controlador de domínio de impressora `m_pdex.hDC`no. É responsabilidade do chamador excluir o controlador de domínio da impressora e chamar a função [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree) do Windows nos identificadores quando você terminar com o `CPrintDialogEx` objeto.

##  <a name="getdevicename"></a>  CPrintDialogEx::GetDeviceName

Chame essa função depois de chamar [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento ou depois de chamar [GetDefaults](#getdefaults) para recuperar o nome da impressora padrão.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome da impressora selecionada no momento.

### <a name="remarks"></a>Comentários

Use um ponteiro para o `CString` objeto retornado pelo `GetDeviceName` como o valor de `lpszDeviceName` em uma chamada para [CDC:: CreateDC](../../mfc/reference/cdc-class.md#createdc).

##  <a name="getdevmode"></a>  CPrintDialogEx::GetDevMode

Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor de retorno

A estrutura de dados [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) , que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória usada por essa estrutura com a função [GlobalUnlock](/windows/win32/api/winbase/nf-winbase-globalunlock) do Windows, que é descrita no SDK do Windows.

##  <a name="getdrivername"></a>  CPrintDialogEx::GetDriverName

Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo de impressora definido pelo sistema.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor de retorno

Um `CString` especificando o nome do driver definido pelo sistema.

### <a name="remarks"></a>Comentários

Use um ponteiro para o `CString` objeto retornado pelo `GetDriverName` como o valor de *lpszDriverName* em uma chamada para [CDC:: CreateDC](../../mfc/reference/cdc-class.md#createdc).

##  <a name="getportname"></a>  CPrintDialogEx::GetPortName

Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta de impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor de retorno

O nome da porta de impressora selecionada no momento.

##  <a name="getprinterdc"></a>  CPrintDialogEx::GetPrinterDC

Retorna um identificador para o contexto do dispositivo de impressora.

```
HDC GetPrinterDC() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o contexto do dispositivo de impressora.

### <a name="remarks"></a>Comentários

Você deve chamar a função [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) do Windows para excluir o contexto do dispositivo quando terminar de usá-lo.

##  <a name="m_pdex"></a>  CPrintDialogEx::m_pdex

Uma estrutura PRINTDLGEX cujos membros armazenam as características do objeto da caixa de diálogo.

```
PRINTDLGEX m_pdex;
```

### <a name="remarks"></a>Comentários

Depois de construir um `CPrintDialogEx` objeto, você pode usar `m_pdex` para definir vários aspectos da caixa de diálogo antes de chamar a função de membro [DoModal](#domodal) . Para obter mais informações sobre `m_pdex` a estrutura, consulte [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-pdexw) no SDK do Windows.

Se você modificar o `m_pdex` membro de dados diretamente, substituirá qualquer comportamento padrão.

##  <a name="printall"></a>  CPrintDialogEx::PrintAll

Chame essa função depois de `DoModal` chamar para determinar se todas as páginas do documento devem ser impressas.

```
BOOL PrintAll() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se todas as páginas no documento forem impressas; caso contrário, FALSE.

##  <a name="printcollate"></a>  CPrintDialogEx::PrintCollate

Chame essa função depois de `DoModal` chamar para determinar se a impressora deve agrupar todas as cópias impressas do documento.

```
BOOL PrintCollate() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o usuário marcar a caixa de seleção Agrupar na caixa de diálogo; caso contrário, FALSE.

##  <a name="printcurrentpage"></a>  CPrintDialogEx::PrintCurrentPage

Chame essa função depois de `DoModal` chamar para determinar se deseja imprimir a página atual no documento.

```
BOOL PrintCurrentPage() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a **página Imprimir atual** estiver selecionada na caixa de diálogo Imprimir; caso contrário, FALSE.

##  <a name="printrange"></a>  CPrintDialogEx::PrintRange

Chame essa função depois de `DoModal` chamar para determinar se deseja imprimir apenas um intervalo de páginas no documento.

```
BOOL PrintRange() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se apenas um intervalo de páginas no documento for impresso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Os intervalos de páginas especificados podem ser determinados em [m_pdex](#m_pdex) ( `nPageRanges`consulte `nMaxPageRanges`, e `lpPageRanges` na estrutura [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-pdexw) no SDK do Windows).

##  <a name="printselection"></a>  CPrintDialogEx::PrintSelection

Chame essa função depois de `DoModal` chamar para determinar se deseja imprimir apenas os itens selecionados no momento.

```
BOOL PrintSelection() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se apenas os itens selecionados forem impressos; caso contrário, FALSE.

## <a name="see-also"></a>Consulte também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)

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
ms.openlocfilehash: 52e992cf021a592198daeddf0a4321fcea487f72
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364036"
---
# <a name="cprintdialogex-class"></a>Classe CPrintDialogEx

Encapsula os serviços fornecidos pela folha de propriedade Windows Print.

## <a name="syntax"></a>Sintaxe

```
class CPrintDialogEx : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CprintdialogEx::CprintdialogEx](#cprintdialogex)|Constrói um objeto `CPrintDialogEx`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CprintDialogEx::CreateprinterDC](#createprinterdc)|Cria um contexto do dispositivo da impressora sem exibir a caixa de diálogo Imprimir.|
|[CprintDialogEx::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça seleções.|
|[CprintdialogEx::getCopies](#getcopies)|Recupera o número de cópias solicitadas.|
|[CPrintDialogEx::GetDefaults](#getdefaults)|Recupera os padrões do dispositivo sem exibir uma caixa de diálogo.|
|[CprintDialogEx::getNome do dispositivo](#getdevicename)|Recupera o nome do dispositivo de impressora selecionado no momento.|
|[CPrintDialogEx::GetDevMode](#getdevmode)|Recupera a `DEVMODE` estrutura.|
|[CprintDialogEx::GetDriverName](#getdrivername)|Recupera o nome do driver de dispositivo de impressora definido pelo sistema.|
|[CprintDialogEx::GetPortName](#getportname)|Recupera o nome da porta de impressora selecionada no momento.|
|[CprintdialogEx::GetPrinterDC](#getprinterdc)|Recupera uma alça para o contexto do dispositivo da impressora.|
|[CPrintDialogEx::PrintAll](#printall)|Determina se deve imprimir todas as páginas do documento.|
|[CprintDialogEx::PrintCollate](#printcollate)|Determina se cópias colhidas são solicitadas.|
|[CPrintDialogEx::PrintCurrentPage](#printcurrentpage)|Determina se deve imprimir a página atual do documento.|
|[CPrintDialogEx::PrintRange](#printrange)|Determina se deve imprimir apenas um intervalo especificado de páginas.|
|[CPrintDialogEx::PrintSelection](#printselection)|Determina se deve imprimir apenas os itens selecionados no momento.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[cprintdialogex::m_pdex](#m_pdex)|Uma estrutura usada `CPrintDialogEx` para personalizar um objeto.|

## <a name="remarks"></a>Comentários

Você pode contar com a estrutura para lidar com muitos aspectos do processo de impressão para sua aplicação. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [Impressão](../../mfc/printing.md).

Se você quiser que seu aplicativo manuseie a `CPrintDialogEx` impressão sem o envolvimento da estrutura, você pode usar a `CPrintDialogEx` classe "como está" com o construtor fornecido, ou você pode obter sua própria classe de diálogo e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportarão como `CCommonDialog`caixas de diálogo MFC padrão porque são derivadas da classe .

Para usar `CPrintDialogEx` um objeto, primeiro `CPrintDialogEx` crie o objeto usando o construtor. Uma vez que a caixa de diálogo tenha sido construída, você pode definir ou modificar quaisquer valores na estrutura [m_pdex](#m_pdex) para inicializar os valores dos controles da caixa de diálogo. A `m_pdex` estrutura é do tipo [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-printdlgexw). Para obter mais informações sobre esta estrutura, consulte o Windows SDK.

Se você não fornecer suas `m_pdex` próprias `hDevMode` `hDevNames` alças para os membros `GlobalFree` e membros, certifique-se de chamar a função windows para essas alças quando você terminar com a caixa de diálogo.

Depois de inicializar os controles `DoModal` da caixa de diálogo, ligue para a função membro para exibir a caixa de diálogo e permita que o usuário selecione as opções de impressão. Quando `DoModal` retornar, você pode determinar se o usuário selecionou o botão OK, Aplicar ou Cancelar.

Se o usuário pressionou `CPrintDialogEx`OK, você pode usar as funções de membro para recuperar a entrada de informações pelo usuário.

A `CPrintDialogEx::GetDefaults` função member é útil para recuperar os padrões atuais da impressora sem exibir uma caixa de diálogo. Este método não requer nenhuma interação do usuário.

Você pode usar `CommDlgExtendedError` a função Windows para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre esta função, consulte o SDK do Windows.

Para obter mais `CPrintDialogEx`informações sobre como usar, consulte [Classes de Diálogo Comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

`IObjectWithSite`

`IPrintDialogCallback`

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`CPrintDialogEx`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cprintdialogexcprintdialogex"></a><a name="cprintdialogex"></a>CprintdialogEx::CprintdialogEx

Constrói uma folha de propriedade do Windows Print.

```
CPrintDialogEx(
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS       | PD_HIDEPRINTTOFILE | PD_NOSELECTION | PD_NOCURRENTPAGE,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas usando o operador bitwise OR. Por exemplo, o PD_ALLPAGES sinalizador define o intervalo de impressão padrão para todas as páginas do documento. Consulte a estrutura [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-printdlgexw) no Windows SDK para obter mais informações sobre esses sinalizadores.

*Pparentwnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

### <a name="remarks"></a>Comentários

Esta função membro só constrói o objeto. Use `DoModal` a função membro para exibir a caixa de diálogo.

## <a name="cprintdialogexcreateprinterdc"></a><a name="createprinterdc"></a>CprintDialogEx::CreateprinterDC

Cria um contexto de dispositivo de impressora (DC) a partir das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES.](/windows/win32/api/commdlg/ns-commdlg-devnames)

```
HDC CreatePrinterDC();
```

### <a name="return-value"></a>Valor retornado

Manuseie o contexto do dispositivo de impressora recém-criado.

### <a name="remarks"></a>Comentários

O DC retornado também `hDC` é armazenado no membro do [m_pdex](#m_pdex).

Presume-se que este DC dc da impressora atual, e quaisquer outros DCs de impressora sustais anteriormente devem ser excluídos. Esta função pode ser chamada, e a DC resultante foi usada, sem nunca exibir a caixa de diálogo Imprimir.

## <a name="cprintdialogexdomodal"></a><a name="domodal"></a>CprintDialogEx::DoModal

Chame esta função para exibir a folha de propriedade Do Windows Print e permita que o usuário selecione várias opções de impressão, como o número de cópias, o intervalo de páginas e se as cópias devem ser colhidas.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

O valor de retorno INT_PTR é na verdade um HRESULT. Consulte a seção Valores de retorno em [PrintDlgEx](/previous-versions/windows/desktop/legacy/ms646942\(v=vs.85\)) no Windows SDK.

### <a name="remarks"></a>Comentários

Se você quiser inicializar as várias opções `m_pdex` de diálogo de impressão `DoModal`definindo membros da estrutura, você deve fazer isso antes de chamar, mas depois que o objeto de diálogo for construído.

Depois `DoModal`de ligar, você pode ligar para outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

Se a bandeira PD_RETURNDC `DoModal`for usada ao ligar, uma `hDC` impressora DC será devolvida no membro do [m_pdex](#m_pdex). Este DC deve ser liberado com uma chamada `CPrintDialogEx`para [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) pelo chamador de .

## <a name="cprintdialogexgetcopies"></a><a name="getcopies"></a>CprintdialogEx::getCopies

Ligue para esta `DoModal` função depois de ligar para recuperar o número de cópias solicitadas.

```
int GetCopies() const;
```

### <a name="return-value"></a>Valor retornado

O número de cópias solicitadas.

## <a name="cprintdialogexgetdefaults"></a><a name="getdefaults"></a>CPrintDialogEx::GetDefaults

Chame esta função para recuperar os padrões do dispositivo da impressora padrão sem exibir uma caixa de diálogo.

```
BOOL GetDefaults();
```

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido, caso contrário FALSO.

### <a name="remarks"></a>Comentários

Cria um contexto de dispositivo de impressora (DC) a partir das estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES.](/windows/win32/api/commdlg/ns-commdlg-devnames)

`GetDefaults`não exibe a folha de propriedade Imprimir. `hDevNames` Em vez disso, `hDevMode` ele define os membros do [m_pdex](#m_pdex) para lidar com as estruturas [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) e [DEVNAMES](/windows/win32/api/commdlg/ns-commdlg-devnames) que são inicializadas para a impressora padrão do sistema. Ambos `hDevNames` `hDevMode` e devem ser `GetDefaults` NULOS, ou falham.

Se a bandeira PD_RETURNDC estiver definida, `hDevNames` esta `hDevMode` função não `m_pdex.hDevNames` `m_pdex.hDevMode`só retornará e (localizada dentro e `m_pdex.hDC`) para o chamador, mas também retornará uma impressora DC em . É responsabilidade do chamador excluir a impressora DC e chamar a função Windows [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree) nas alças quando terminar o `CPrintDialogEx` objeto.

## <a name="cprintdialogexgetdevicename"></a><a name="getdevicename"></a>CprintDialogEx::getNome do dispositivo

Ligue para esta função depois de ligar para o [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento ou depois de chamar [GetDefaults](#getdefaults) para recuperar o nome da impressora padrão.

```
CString GetDeviceName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da impressora selecionada no momento.

### <a name="remarks"></a>Comentários

Use um ponteiro `CString` para o `GetDeviceName` objeto retornado como o valor de `lpszDeviceName` uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).

## <a name="cprintdialogexgetdevmode"></a><a name="getdevmode"></a>CPrintDialogEx::GetDevMode

Ligue para esta função depois de ligar para [doModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.

```
LPDEVMODE GetDevMode() const;
```

### <a name="return-value"></a>Valor retornado

A estrutura de dados [DEVMODE,](/windows/win32/api/wingdi/ns-wingdi-devmodea) que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória tirada por esta estrutura com a função Windows [GlobalUnlock,](/windows/win32/api/winbase/nf-winbase-globalunlock) que é descrita no Windows SDK.

## <a name="cprintdialogexgetdrivername"></a><a name="getdrivername"></a>CprintDialogEx::GetDriverName

Ligue para esta função depois de ligar para [doModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo de impressora definido pelo sistema.

```
CString GetDriverName() const;
```

### <a name="return-value"></a>Valor retornado

A `CString` especificar o nome do driver definido pelo sistema.

### <a name="remarks"></a>Comentários

Use um ponteiro `CString` para o `GetDriverName` objeto retornado como o valor de *lpszDriverName* em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).

## <a name="cprintdialogexgetportname"></a><a name="getportname"></a>CprintDialogEx::GetPortName

Chame esta função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta de impressora selecionada no momento.

```
CString GetPortName() const;
```

### <a name="return-value"></a>Valor retornado

O nome da porta de impressora selecionada no momento.

## <a name="cprintdialogexgetprinterdc"></a><a name="getprinterdc"></a>CprintdialogEx::GetPrinterDC

Retorna uma alça ao contexto do dispositivo da impressora.

```
HDC GetPrinterDC() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para o contexto do dispositivo da impressora.

### <a name="remarks"></a>Comentários

Você deve chamar a função Windows [DeleteDC](/windows/win32/api/wingdi/nf-wingdi-deletedc) para excluir o contexto do dispositivo quando terminar de usá-lo.

## <a name="cprintdialogexm_pdex"></a><a name="m_pdex"></a>cprintdialogex::m_pdex

Uma estrutura PRINTDLGEX cujos membros armazenam as características do objeto de diálogo.

```
PRINTDLGEX m_pdex;
```

### <a name="remarks"></a>Comentários

Depois de `CPrintDialogEx` construir um objeto, você pode usar `m_pdex` para definir vários aspectos da caixa de diálogo antes de chamar a função de membro [DoModal.](#domodal) Para obter mais `m_pdex` informações sobre a estrutura, consulte [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-printdlgexw) no Windows SDK.

Se você `m_pdex` modificar o membro de dados diretamente, você substituirá qualquer comportamento padrão.

## <a name="cprintdialogexprintall"></a><a name="printall"></a>CPrintDialogEx::PrintAll

Ligue para esta `DoModal` função após a chamada para determinar se deve imprimir todas as páginas do documento.

```
BOOL PrintAll() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se todas as páginas do documento forem impressas; caso contrário, FALSO.

## <a name="cprintdialogexprintcollate"></a><a name="printcollate"></a>CprintDialogEx::PrintCollate

Ligue para esta `DoModal` função após a chamada para determinar se a impressora deve reunir todas as cópias impressas do documento.

```
BOOL PrintCollate() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o usuário selecionar a caixa de seleção de cotar na caixa de diálogo; caso contrário, FALSO.

## <a name="cprintdialogexprintcurrentpage"></a><a name="printcurrentpage"></a>CPrintDialogEx::PrintCurrentPage

Ligue para esta `DoModal` função após a chamada para determinar se deve imprimir a página atual no documento.

```
BOOL PrintCurrentPage() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se **A página impressa atual** estiver selecionada na caixa de diálogo imprimir; caso contrário, FALSO.

## <a name="cprintdialogexprintrange"></a><a name="printrange"></a>CPrintDialogEx::PrintRange

Ligue para esta `DoModal` função após a chamada para determinar se deve imprimir apenas uma série de páginas no documento.

```
BOOL PrintRange() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se apenas uma série de páginas no documento forem impressas; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Os intervalos de página especificados podem `nMaxPageRanges`ser `lpPageRanges` determinados a partir de [m_pdex](#m_pdex) (ver `nPageRanges`, e na estrutura [PRINTDLGEX](/windows/win32/api/commdlg/ns-commdlg-printdlgexw) no Windows SDK).

## <a name="cprintdialogexprintselection"></a><a name="printselection"></a>CPrintDialogEx::PrintSelection

Chame esta função `DoModal` após a chamada para determinar se deve imprimir apenas os itens selecionados no momento.

```
BOOL PrintSelection() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se apenas os itens selecionados forem impressos; caso contrário, FALSO.

## <a name="see-also"></a>Confira também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)

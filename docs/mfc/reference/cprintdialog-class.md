---
title: Classe CPrintDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d72b96e0be786aab18903e95f346eccd5364dd4b
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37079638"
---
# <a name="cprintdialog-class"></a>Classe CPrintDialog
Encapsula os serviços fornecidos pela caixa de diálogo comuns do Windows para impressão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPrintDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialog::CPrintDialog](#cprintdialog)|Constrói um objeto `CPrintDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora sem exibir a caixa de diálogo de impressão.|  
|[CPrintDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[CPrintDialog::GetCopies](#getcopies)|Recupera o número de cópias solicitado.|  
|[CPrintDialog::GetDefaults](#getdefaults)|Recupera os padrões do dispositivo sem exibir uma caixa de diálogo.|  
|[CPrintDialog::GetDeviceName](#getdevicename)|Recupera o nome do dispositivo de impressora atualmente selecionada.|  
|[CPrintDialog::GetDevMode](#getdevmode)|Recupera o `DEVMODE` estrutura.|  
|[CPrintDialog::GetDriverName](#getdrivername)|Recupera o nome do driver da impressora selecionada no momento.|  
|[CPrintDialog::GetFromPage](#getfrompage)|Recupera a página inicial do intervalo de impressão.|  
|[CPrintDialog::GetPortName](#getportname)|Recupera o nome da porta da impressora selecionada no momento.|  
|[CPrintDialog::GetPrinterDC](#getprinterdc)|Recupera um identificador para o contexto de dispositivo de impressora.|  
|[CPrintDialog::GetToPage](#gettopage)|Recupera a página final do intervalo de impressão.|  
|[CPrintDialog::PrintAll](#printall)|Determina se a impressão de todas as páginas do documento.|  
|[CPrintDialog::PrintCollate](#printcollate)|Determina se agrupados cópias são solicitadas.|  
|[CPrintDialog::PrintRange](#printrange)|Determina se imprimir apenas um intervalo de páginas especificado.|  
|[CPrintDialog::PrintSelection](#printselection)|Determina se imprimir apenas os itens selecionados no momento.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialog::m_pd](#m_pd)|Uma estrutura usada para personalizar um `CPrintDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo de impressão comuns fornecem uma maneira fácil de implementar as caixas de diálogo de impressão e Configurar impressão de maneira consistente com os padrões do Windows.  
  
> [!NOTE]
>  O `CPrintDialogEx` classe encapsula os serviços fornecidos por folha de propriedades de impressão do Windows. Para obter mais informações, consulte o [CPrintDialogEx](../../mfc/reference/cprintdialogex-class.md) visão geral.  
  
 `CPrintDialog`da funcionalidade é substituída de [CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md), que é projetado para fornecer uma caixa de diálogo comum para ambos imprimir a instalação e configuração de página.  
  
 Você pode contar com a estrutura para lidar com vários aspectos do processo de impressão de seu aplicativo. Nesse caso, o framework exibe automaticamente a caixa de diálogo comuns do Windows para impressão. Você também pode ter o identificador de estrutura de impressão para o seu aplicativo mas substituir a caixa de diálogo de impressão comuns com sua própria caixa de diálogo de impressão. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [impressão](../../mfc/printing.md).  
  
 Se você deseja que seu aplicativo para manipular a impressão sem o envolvimento do framework, você pode usar o `CPrintDialog` classe "como está" com o construtor fornecido, ou você pode derivar sua própria classe de caixa de diálogo de `CPrintDialog` e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportará como caixas de diálogo MFC padrão porque eles são derivados da classe `CCommonDialog`.  
  
 Para usar um `CPrintDialog` de objeto, primeiro crie o objeto usando o `CPrintDialog` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar valores no [m_pd](#m_pd) estrutura para inicializar os valores de controles da caixa de diálogo. O `m_pd` estrutura é do tipo [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843). Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.  
  
 Se você não fornecer seus próprios identificadores em `m_pd` para o **hDevMode** e **hDevNames** membros, certifique-se de chamar a função do Windows **GlobalFree** para esses identificadores Quando você terminar com a caixa de diálogo. Ao usar a implementação da configuração de impressão do framework fornecida pelo `CWinApp::OnFilePrintSetup`, você não precisa liberar essas alças. Os identificadores são mantidos por `CWinApp` e são liberadas de `CWinApp`do destruidor. Só é necessário liberar essas alças ao usar `CPrintDialog` autônomo.  
  
 Depois de inicializar os controles de caixa de diálogo, chamar o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecionar opções de impressão. `DoModal` Retorna se o usuário selecionou o Okey ( **IDOK**) ou Cancelar ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar um dos `CPrintDialog`de funções de membro para recuperar as informações de entrada do usuário.  
  
 O `CPrintDialog::GetDefaults` função de membro é útil para recuperar os padrões atuais de impressora sem exibir uma caixa de diálogo. Essa função de membro não requer nenhuma interação do usuário.  
  
 Você pode usar o Windows **CommDlgExtendedError** função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre essa função, consulte o SDK do Windows.  
  
 `CPrintDialog` depende do COMMDLG. Arquivo DLL que é fornecido com o Windows versão 3.1 e posterior.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CPrintDialog`, forneça um modelo de caixa de diálogo personalizada e adicionar um mapa de mensagem para processar as mensagens de notificação de controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base. Personalizando a função de gancho não é necessária.  
  
 Para processar a mesma mensagem de forma diferente dependendo se a caixa de diálogo é imprimir ou Configurar impressão, você deve derivar uma classe para cada caixa de diálogo. Você também deve sobrepor as janelas **AttachOnSetup** função, que manipula a criação de uma nova caixa de diálogo quando o botão Configurar impressão é selecionado na caixa de diálogo Imprimir.  
  
 Para obter mais informações sobre como usar `CPrintDialog`, consulte [Classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CPrintDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
##  <a name="cprintdialog"></a>  CPrintDialog::CPrintDialog  
 Constrói uma impressão do Windows ou Configurar impressão objeto de caixa de diálogo.  
  
```  
CPrintDialog(
    BOOL bPrintSetupOnly,  
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS | PD_HIDEPRINTTOFILE | PD_NOSELECTION,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bPrintSetupOnly*  
 Especifica se a caixa de diálogo de impressão do Windows padrão ou a caixa de diálogo Configurar impressão é exibida. Definir esse parâmetro como **TRUE** para exibir a caixa de diálogo de configuração de impressão do Windows padrão. Defina-a como **FALSE** para exibir a caixa de diálogo de impressão do Windows. Se *bPrintSetupOnly* é **FALSE**, um botão de opção de configurar impressão ainda é exibido na caixa de diálogo Imprimir.  
  
 *dwFlags*  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas que usam o operador OR bit a bit. Por exemplo, o **PD_ALLPAGES** sinalizador define o intervalo de impressão padrão para todas as páginas do documento. Consulte o [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) estrutura no SDK do Windows para obter mais informações sobre esses sinalizadores.  
  
 *pParentWnd*  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro apenas constrói o objeto. Use o `DoModal` a função de membro para exibir a caixa de diálogo.  
  
 Observe que, quando você chamar o construtor com `bPrintSetupOnly` definida como **FALSE**, o **PD_RETURNDC** sinalizador é usado automaticamente. Depois de chamar `DoModal`, `GetDefaults`, ou `GetPrinterDC`, será retornada uma controlador de domínio de impressora em `m_pd.hDC`. Este controlador de domínio deve ser liberado com uma chamada para [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) pelo chamador de `CPrintDialog`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#174](../../mfc/codesnippet/cpp/cprintdialog-class_1.cpp)]  
  
##  <a name="createprinterdc"></a>  CPrintDialog::CreatePrinterDC  
 Cria um contexto de dispositivo de impressora (DC) a partir de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
```  
HDC CreatePrinterDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o contexto de dispositivo de impressora recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Este controlador de domínio é considerado como a impressora atual controlador de domínio e qualquer outro obtido anteriormente impressora que controladores de domínio devem ser excluídos pelo usuário. Esta função pode ser chamada e o controlador de domínio resultante é usado, sem nunca exibir a caixa de diálogo de impressão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#106](../../mfc/codesnippet/cpp/cprintdialog-class_2.cpp)]  
  
##  <a name="domodal"></a>  CPrintDialog::DoModal  
 Exibe a caixa de diálogo de impressão comuns do Windows e permite que o usuário selecionar várias opções de impressão, como o número de cópias, intervalo de páginas, e se as cópias devem ser agrupadas.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo de impressão, definindo membros do `m_pd` estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Depois de chamar `DoModal`, você pode chamar outro membro funções para recuperar as configurações ou a entrada de informações pelo usuário na caixa de diálogo.  
  
 Observe que, quando você chamar o construtor com *bPrintSetupOnly* definida como **FALSE**, o **PD_RETURNDC** sinalizador é usado automaticamente. Depois de chamar `DoModal`, `GetDefaults`, ou `GetPrinterDC`, será retornada uma controlador de domínio de impressora em `m_pd.hDC`. Este controlador de domínio deve ser liberado com uma chamada para [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) pelo chamador de `CPrintDialog`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::CreatePrinterDC](#createprinterdc).  
  
##  <a name="getcopies"></a>  CPrintDialog::GetCopies  
 Recupera o número de cópias solicitado.  
  
```  
int GetCopies() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de cópias solicitado.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para recuperar o número de cópias solicitado.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::PrintCollate](#printcollate).  
  
##  <a name="getdefaults"></a>  CPrintDialog::GetDefaults  
 Recupera os padrões de dispositivo da impressora padrão sem exibir uma caixa de diálogo.  
  
```  
BOOL GetDefaults();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os valores recuperados são colocados no `m_pd` estrutura.  
  
 Em alguns casos, uma chamada para essa função chamará o [construtor](#cprintdialog) para `CPrintDialog` com *bPrintSetupOnly* definida como **FALSE**. Nesses casos, uma controlador de domínio de impressora e **hDevNames** e **hDevMode** (duas alças localizado no `m_pd` membro de dados) são alocados automaticamente.  
  
 Se o construtor para `CPrintDialog` foi chamado com `bPrintSetupOnly` definida como **FALSE**, essa função não retornará apenas **hDevNames** e **hDevMode** (localizado em **m_pd.hDevNames** e **m_pd.hDevMode**) para o chamador, mas também retornará uma impressora DC em **m_pd.hDC**. É responsabilidade do chamador para excluir a impressora DC e chamar o Windows [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579) função em identificadores quando tiver terminado com o `CPrintDialog` objeto.  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código obtém o contexto de dispositivo da impressora padrão e relatórios para o usuário a resolução da impressora em pontos por polegada. (Esse atributo de capacidades da impressora é conhecido como DPI.)  
  
 [!code-cpp[NVC_MFCDocView#107](../../mfc/codesnippet/cpp/cprintdialog-class_3.cpp)]  
  
##  <a name="getdevicename"></a>  CPrintDialog::GetDeviceName  
 Recupera o nome do dispositivo de impressora atualmente selecionada.  
  
```  
CString GetDeviceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da impressora selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento, ou depois de chamar [GetDefaults](#getdefaults) para recuperar os padrões atuais de dispositivo da impressora padrão. Usar um ponteiro para o `CString` objeto retornado por `GetDeviceName` como o valor de `lpszDeviceName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código mostra o nome da impressora padrão do usuário e a porta que ele está conectado, juntamente com o nome do spooler que usa a impressora. O código pode mostrar uma caixa de mensagem que diz "a impressora padrão é HP LaserJet IIIP em \\\server\share usando winspool.", por exemplo.  
  
 [!code-cpp[NVC_MFCDocView#108](../../mfc/codesnippet/cpp/cprintdialog-class_4.cpp)]  
  
##  <a name="getdevmode"></a>  CPrintDialog::GetDevMode  
 Recupera o `DEVMODE` estrutura.  
  
```  
LPDEVMODE GetDevMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura de dados, que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória usada por esta estrutura com o Windows [GlobalUnlock](http://msdn.microsoft.com/library/windows/desktop/aa366595) função, que é descrita no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::PrintCollate](#printcollate).  
  
##  <a name="getdrivername"></a>  CPrintDialog::GetDriverName  
 Recupera o nome do driver da impressora selecionada no momento.  
  
```  
CString GetDriverName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` especificando o nome do driver definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo de impressora definidas pelo sistema. Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::GetDeviceName](#getdevicename).  
  
##  <a name="getfrompage"></a>  CPrintDialog::GetFromPage  
 Recupera a página inicial do intervalo de impressão.  
  
```  
int GetFromPage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O página número inicial no intervalo de páginas a serem impressas.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para recuperar o número da página inicial do intervalo de páginas a serem impressas.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="getportname"></a>  CPrintDialog::GetPortName  
 Recupera o nome da porta da impressora selecionada no momento.  
  
```  
CString GetPortName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da porta da impressora selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta da impressora selecionada no momento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::GetDeviceName](#getdevicename).  
  
##  <a name="getprinterdc"></a>  CPrintDialog::GetPrinterDC  
 Recupera um identificador para o contexto de dispositivo de impressora.  
  
```  
HDC GetPrinterDC() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o contexto de dispositivo de impressora se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se o *bPrintSetupOnly* parâmetro o `CPrintDialog` construtor foi **FALSE** (indicando que a caixa de diálogo Imprimir é exibida,), em seguida, `GetPrinterDC` retorna um identificador para o dispositivo de impressora contexto. Você deve chamar o Windows [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) função para excluir o contexto de dispositivo quando você terminar de usá-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#109](../../mfc/codesnippet/cpp/cprintdialog-class_5.cpp)]  
  
##  <a name="gettopage"></a>  CPrintDialog::GetToPage  
 Recupera a página final do intervalo de impressão.  
  
```  
int GetToPage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O página número final no intervalo de páginas a serem impressas.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para recuperar o número da página final do intervalo de páginas a serem impressas.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="m_pd"></a>  CPrintDialog::m_pd  
 Uma estrutura cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PRINTDLG& m_pd;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `CPrintDialog` do objeto, você pode usar `m_pd` para definir vários aspectos da caixa de diálogo antes de chamar o [DoModal](#domodal) função de membro. Para obter mais informações sobre o `m_pd` estrutura, consulte [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) no SDK do Windows.  
  
 Se você modificar o `m_pd` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#111](../../mfc/codesnippet/cpp/cprintdialog-class_6.cpp)]  
  
##  <a name="printall"></a>  CPrintDialog::PrintAll  
 Determina se a impressão de todas as páginas do documento.  
  
```  
BOOL PrintAll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se todas as páginas do documento a ser impresso; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para determinar se todas as páginas do documento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="printcollate"></a>  CPrintDialog::PrintCollate  
 Determina se agrupados cópias são solicitadas.  
  
```  
BOOL PrintCollate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário seleciona a caixa de seleção collate na caixa de diálogo. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para determinar se a impressora deve agrupar impressas todas as cópias do documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#110](../../mfc/codesnippet/cpp/cprintdialog-class_7.cpp)]  
  
##  <a name="printrange"></a>  CPrintDialog::PrintRange  
 Determina se imprimir apenas um intervalo de páginas especificado.  
  
```  
BOOL PrintRange() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se apenas um intervalo de páginas do documento devem ser impressos; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para determinar se apenas um intervalo de páginas do documento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="printselection"></a>  CPrintDialog::PrintSelection  
 Determina se imprimir apenas os itens selecionados no momento.  
  
```  
BOOL PrintSelection() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se apenas os itens selecionados devem ser impressos; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função depois de chamar `DoModal` para determinar se apenas os itens selecionados no momento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPrintDialog::m_pd](#m_pd).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)   
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)

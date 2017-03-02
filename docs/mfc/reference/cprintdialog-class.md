---
title: Classe CPrintDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPrintDialog
dev_langs:
- C++
helpviewer_keywords:
- Print Setup dialog box
- Print dialog box
- CPrintDialog class
ms.assetid: 5bdb2424-adf8-433d-a97c-df11a83bc4e4
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: fe8b5a899169bf9dfd463278100384fde900a6a0
ms.lasthandoff: 02/25/2017

---
# <a name="cprintdialog-class"></a>Classe CPrintDialog
Encapsula os serviços fornecidos pela caixa de diálogo comum do Windows para impressão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPrintDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialog::CPrintDialog](#cprintdialog)|Constrói um objeto `CPrintDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialog::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora sem exibir a caixa de diálogo de impressão.|  
|[CPrintDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[CPrintDialog::GetCopies](#getcopies)|Recupera o número de cópias solicitadas.|  
|[CPrintDialog::GetDefaults](#getdefaults)|Recupera os padrões de dispositivo sem exibir uma caixa de diálogo.|  
|[CPrintDialog::GetDeviceName](#getdevicename)|Recupera o nome do dispositivo de impressora atualmente selecionada.|  
|[CPrintDialog::GetDevMode](#getdevmode)|Recupera o `DEVMODE` estrutura.|  
|[CPrintDialog::GetDriverName](#getdrivername)|Recupera o nome do driver da impressora selecionada no momento.|  
|[CPrintDialog::GetFromPage](#getfrompage)|Recupera a página inicial do intervalo de impressão.|  
|[CPrintDialog::GetPortName](#getportname)|Recupera o nome da porta da impressora selecionada no momento.|  
|[CPrintDialog::GetPrinterDC](#getprinterdc)|Recupera um identificador para o contexto de dispositivo da impressora.|  
|[CPrintDialog::GetToPage](#gettopage)|Recupera a página final do intervalo de impressão.|  
|[CPrintDialog::PrintAll](#printall)|Determina se deve imprimir todas as páginas do documento.|  
|[CPrintDialog::PrintCollate](#printcollate)|Determina se agrupadas cópias são solicitadas.|  
|[CPrintDialog::PrintRange](#printrange)|Determina se imprimir apenas um intervalo de páginas especificado.|  
|[CPrintDialog::PrintSelection](#printselection)|Determina se deve imprimir apenas os itens selecionados no momento.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialog::m_pd](#m_pd)|Uma estrutura usada para personalizar um `CPrintDialog` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo de impressão comuns fornecem uma maneira fácil de implementar caixas de diálogo de impressão e Configurar impressão de maneira consistente com os padrões do Windows.  
  
> [!NOTE]
>  O `CPrintDialogEx` classe encapsula os serviços fornecidos por folha de propriedades de impressão do Windows 2000. Para obter mais informações, consulte o [CPrintDialogEx](../../mfc/reference/cprintdialogex-class.md) visão geral.  
  
 `CPrintDialog`da funcionalidade é substituída por aquele do [CPageSetupDialog](../../mfc/reference/cpagesetupdialog-class.md), que é projetado para fornecer uma caixa de diálogo comum para ambos imprimir a instalação e configuração de página.  
  
 Você pode contar com a estrutura para lidar com muitos aspectos do processo de impressão para o seu aplicativo. Nesse caso, o framework exibe automaticamente a caixa de diálogo comuns do Windows para impressão. Você também pode ter a alça do framework impressão de seu aplicativo mas substituir a caixa de diálogo de impressão comuns com sua própria caixa de diálogo Imprimir. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [impressão](../../mfc/printing.md).  
  
 Se desejar que seu aplicativo para manipular a impressão sem o envolvimento do framework, você pode usar o `CPrintDialog` classe "como está" com o construtor fornecido, ou você pode derivar sua própria classe de caixa de diálogo de `CPrintDialog` e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportará como caixas de diálogo MFC padrão porque eles são derivados da classe `CCommonDialog`.  
  
 Para usar um `CPrintDialog` de objeto, primeiro crie o objeto usando o `CPrintDialog` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar qualquer valor de [m_pd](#m_pd) estrutura para inicializar os valores dos controles da caixa de diálogo. O `m_pd` estrutura é do tipo [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843). Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se você não fornecer seus próprios identificadores em `m_pd` para o **hDevMode** e **hDevNames** membros, certifique-se de chamar a função Windows **GlobalFree** para essas alças quando tiver terminado com a caixa de diálogo. Ao usar a implementação da configuração de impressão do framework fornecida pelo `CWinApp::OnFilePrintSetup`, você não precisa liberar essas alças. Os identificadores são mantidos pelo `CWinApp` e são liberados no `CWinApp`do destruidor. Só é necessário liberar essas alças ao usar `CPrintDialog` autônomo.  
  
 Depois de inicializar os controles de caixa de diálogo, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione as opções de impressão. `DoModal`Retorna se o usuário selecionou o Okey ( **IDOK**) ou Cancel ( **IDCANCEL**) botão.  
  
 Se `DoModal` retorna **IDOK**, você pode usar um dos `CPrintDialog`de funções de membro para recuperar as informações de entrada do usuário.  
  
 O `CPrintDialog::GetDefaults` função de membro é útil para recuperar os padrões atuais de impressora sem exibir uma caixa de diálogo. Essa função de membro não requer nenhuma interação do usuário.  
  
 Você pode usar o Windows **CommDlgExtendedError** função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e saiba mais sobre o erro. Para obter mais informações sobre essa função, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `CPrintDialog`depende do COMMDLG. Arquivo DLL que acompanha o Windows versões 3.1 e posteriores.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CPrintDialog`, fornecer um modelo de caixa de diálogo personalizada e adicionar um mapa da mensagem para processar as mensagens de notificação de controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base. Personalizando a função de gancho não é necessária.  
  
 Para processar a mesma mensagem de maneira diferente dependendo da caixa de diálogo Imprimir ou Configurar impressão, você deve derivar uma classe para cada caixa de diálogo. Você também deve substituir o Windows **AttachOnSetup** função, que manipula a criação de uma nova caixa de diálogo quando o botão Configurar impressão é selecionado em uma caixa de diálogo Imprimir.  
  
 Para obter mais informações sobre como usar o `CPrintDialog`, consulte [Classes comuns do diálogo](../../mfc/common-dialog-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CPrintDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs. h  
  
##  <a name="a-namecprintdialoga--cprintdialogcprintdialog"></a><a name="cprintdialog"></a>CPrintDialog::CPrintDialog  
 Constrói uma impressão do Windows ou Configurar impressão objeto de caixa de diálogo.  
  
```  
CPrintDialog(
    BOOL bPrintSetupOnly,  
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS | PD_HIDEPRINTTOFILE | PD_NOSELECTION,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bPrintSetupOnly`  
 Especifica se a caixa de diálogo de impressão do Windows padrão ou a caixa de diálogo Configurar impressão é exibida. Definir esse parâmetro como **TRUE** para exibir a caixa de diálogo de configuração de impressão do Windows padrão. Defina-o como **FALSE** para exibir a caixa de diálogo de impressão do Windows. Se `bPrintSetupOnly` é **FALSE**, um botão de opção de configurar impressão ainda é exibido na caixa de diálogo Imprimir.  
  
 `dwFlags`  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas com o operador OR bit a bit. Por exemplo, o **PD_ALLPAGES** sinalizador define o intervalo de impressão padrão para todas as páginas do documento. Consulte o [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre esses sinalizadores.  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro apenas constrói o objeto. Use o `DoModal` a função de membro para exibir a caixa de diálogo.  
  
 Observe que, quando você chama o construtor com `bPrintSetupOnly` definida como **FALSE**, o **PD_RETURNDC** sinalizador será usado automaticamente. Depois de chamar `DoModal`, `GetDefaults`, ou `GetPrinterDC`, uma impressora DC será retornada no `m_pd.hDC`. Esse controlador de domínio deve ser liberado com uma chamada para [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) pelo chamador de `CPrintDialog`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#174;](../../mfc/codesnippet/cpp/cprintdialog-class_1.cpp)]  
  
##  <a name="a-namecreateprinterdca--cprintdialogcreateprinterdc"></a><a name="createprinterdc"></a>CPrintDialog::CreatePrinterDC  
 Cria um contexto de dispositivo da impressora (DC) a partir de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
```  
HDC CreatePrinterDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o contexto de dispositivo da impressora recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Esse controlador de domínio é considerado como a impressora atual controlador de domínio e qualquer outro obtido anteriormente impressora que controladores de domínio devem ser excluídos pelo usuário. Essa função pode ser chamada, e o controlador de domínio resultante usada, sem nunca exibir a caixa de diálogo de impressão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#106;](../../mfc/codesnippet/cpp/cprintdialog-class_2.cpp)]  
  
##  <a name="a-namedomodala--cprintdialogdomodal"></a><a name="domodal"></a>CPrintDialog::DoModal  
 Exibe a caixa de diálogo comuns do Windows e permite ao usuário selecionar várias opções de impressão, como o número de cópias, intervalo de páginas, e se as cópias devem ser agrupadas.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo Imprimir definindo membros do `m_pd` estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Depois de chamar `DoModal`, você pode chamar outro membro funções para recuperar as configurações ou entrada de informações pelo usuário na caixa de diálogo.  
  
 Observe que, quando você chama o construtor com `bPrintSetupOnly` definida como **FALSE**, o **PD_RETURNDC** sinalizador será usado automaticamente. Depois de chamar `DoModal`, `GetDefaults`, ou `GetPrinterDC`, uma impressora DC será retornada no `m_pd.hDC`. Esse controlador de domínio deve ser liberado com uma chamada para [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) pelo chamador de `CPrintDialog`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::CreatePrinterDC](#createprinterdc).  
  
##  <a name="a-namegetcopiesa--cprintdialoggetcopies"></a><a name="getcopies"></a>CPrintDialog::GetCopies  
 Recupera o número de cópias solicitadas.  
  
```  
int GetCopies() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de cópias solicitadas.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para recuperar o número de cópias solicitadas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::PrintCollate](#printcollate).  
  
##  <a name="a-namegetdefaultsa--cprintdialoggetdefaults"></a><a name="getdefaults"></a>CPrintDialog::GetDefaults  
 Recupera os padrões de dispositivo da impressora padrão sem exibir uma caixa de diálogo.  
  
```  
BOOL GetDefaults();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os valores recuperados são colocados no `m_pd` estrutura.  
  
 Em alguns casos, uma chamada para essa função chamará o [construtor](#cprintdialog) para `CPrintDialog` com `bPrintSetupOnly` definida como **FALSE**. Nesses casos, uma controlador de domínio de impressora e **hDevNames** e **hDevMode** (duas alças localizado no `m_pd` membro de dados) são alocados automaticamente.  
  
 Se o construtor para `CPrintDialog` foi chamado com `bPrintSetupOnly` definida como **FALSE**, essa função não retornará apenas **hDevNames** e **hDevMode** (localizado em **m_pd.hDevNames** e **m_pd.hDevMode**) para o chamador, mas também retornará uma impressora DC em **m_pd.hDC**. É responsabilidade do chamador para excluir a impressora DC e chamar o Windows [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579) função com os identificadores quando tiver terminado com a `CPrintDialog` objeto.  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código obtém o contexto de dispositivo da impressora padrão e relatórios para o usuário a resolução da impressora em pontos por polegada. (Esse atributo dos recursos da impressora é conhecido como DPI.)  
  
 [!code-cpp[NVC_MFCDocView&#107;](../../mfc/codesnippet/cpp/cprintdialog-class_3.cpp)]  
  
##  <a name="a-namegetdevicenamea--cprintdialoggetdevicename"></a><a name="getdevicename"></a>CPrintDialog::GetDeviceName  
 Recupera o nome do dispositivo de impressora atualmente selecionada.  
  
```  
CString GetDeviceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da impressora selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento, ou depois de chamar [GetDefaults](#getdefaults) para recuperar os padrões atuais do dispositivo da impressora padrão. Usar um ponteiro para o `CString` objeto retornado por `GetDeviceName` como o valor de `lpszDeviceName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código mostra o nome da impressora padrão do usuário e a porta que está conectado, juntamente com o nome do spooler que de impressora utiliza. O código pode mostrar uma caixa de mensagem que diz: "a impressora padrão é HP LaserJet IIIP em \\\server\share usando winspool.", por exemplo.  
  
 [!code-cpp[NVC_MFCDocView&#108;](../../mfc/codesnippet/cpp/cprintdialog-class_4.cpp)]  
  
##  <a name="a-namegetdevmodea--cprintdialoggetdevmode"></a><a name="getdevmode"></a>CPrintDialog::GetDevMode  
 Recupera o `DEVMODE` estrutura.  
  
```  
LPDEVMODE GetDevMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura de dados, que contém informações sobre o ambiente de um driver de impressão e a inicialização do dispositivo. Você deve desbloquear a memória usada por essa estrutura com o Windows [GlobalUnlock](http://msdn.microsoft.com/library/windows/desktop/aa366595) função, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::PrintCollate](#printcollate).  
  
##  <a name="a-namegetdrivernamea--cprintdialoggetdrivername"></a><a name="getdrivername"></a>CPrintDialog::GetDriverName  
 Recupera o nome do driver da impressora selecionada no momento.  
  
```  
CString GetDriverName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` especificando o nome do driver definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo da impressora definida pelo sistema. Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::GetDeviceName](#getdevicename).  
  
##  <a name="a-namegetfrompagea--cprintdialoggetfrompage"></a><a name="getfrompage"></a>CPrintDialog::GetFromPage  
 Recupera a página inicial do intervalo de impressão.  
  
```  
int GetFromPage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O página número inicial no intervalo de páginas a serem impressas.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para recuperar o número da página inicial do intervalo de páginas a serem impressas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="a-namegetportnamea--cprintdialoggetportname"></a><a name="getportname"></a>CPrintDialog::GetPortName  
 Recupera o nome da porta da impressora selecionada no momento.  
  
```  
CString GetPortName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da porta da impressora selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta da impressora selecionada no momento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::GetDeviceName](#getdevicename).  
  
##  <a name="a-namegetprinterdca--cprintdialoggetprinterdc"></a><a name="getprinterdc"></a>CPrintDialog::GetPrinterDC  
 Recupera um identificador para o contexto de dispositivo da impressora.  
  
```  
HDC GetPrinterDC() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o contexto de dispositivo da impressora se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se o `bPrintSetupOnly` parâmetro do `CPrintDialog` construtor foi **FALSE** (indicando que é exibida a caixa de diálogo de impressão), em seguida, `GetPrinterDC` retorna um identificador para o contexto de dispositivo da impressora. Você deve chamar o Windows [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) função para excluir o contexto do dispositivo quando terminar de usá-lo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#109;](../../mfc/codesnippet/cpp/cprintdialog-class_5.cpp)]  
  
##  <a name="a-namegettopagea--cprintdialoggettopage"></a><a name="gettopage"></a>CPrintDialog::GetToPage  
 Recupera a página final do intervalo de impressão.  
  
```  
int GetToPage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O página número final no intervalo de páginas a serem impressas.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para recuperar o número da página final do intervalo de páginas a serem impressas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="a-namempda--cprintdialogmpd"></a><a name="m_pd"></a>CPrintDialog::m_pd  
 Uma estrutura cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PRINTDLG& m_pd;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um `CPrintDialog` do objeto, você pode usar `m_pd` para definir vários aspectos da caixa de diálogo antes de chamar o [DoModal](#domodal) função de membro. Para obter mais informações sobre o `m_pd` estrutura, consulte [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se você modificar o `m_pd` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#111;](../../mfc/codesnippet/cpp/cprintdialog-class_6.cpp)]  
  
##  <a name="a-nameprintalla--cprintdialogprintall"></a><a name="printall"></a>CPrintDialog::PrintAll  
 Determina se deve imprimir todas as páginas do documento.  
  
```  
BOOL PrintAll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se todas as páginas do documento devem ser impressos; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para determinar se deseja imprimir todas as páginas do documento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="a-nameprintcollatea--cprintdialogprintcollate"></a><a name="printcollate"></a>CPrintDialog::PrintCollate  
 Determina se agrupadas cópias são solicitadas.  
  
```  
BOOL PrintCollate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário seleciona a caixa de seleção collate na caixa de diálogo. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para determinar se a impressora deve agrupar as cópias impressas tudo do documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#110;](../../mfc/codesnippet/cpp/cprintdialog-class_7.cpp)]  
  
##  <a name="a-nameprintrangea--cprintdialogprintrange"></a><a name="printrange"></a>CPrintDialog::PrintRange  
 Determina se imprimir apenas um intervalo de páginas especificado.  
  
```  
BOOL PrintRange() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se apenas um intervalo de páginas do documento devem ser impressos; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para determinar se deve imprimir apenas um intervalo de páginas do documento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).  
  
##  <a name="a-nameprintselectiona--cprintdialogprintselection"></a><a name="printselection"></a>CPrintDialog::PrintSelection  
 Determina se deve imprimir apenas os itens selecionados no momento.  
  
```  
BOOL PrintSelection() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se apenas os itens selecionados devem ser impressos; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de chamar `DoModal` para determinar se apenas os itens selecionados no momento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPrintDialog::m_pd](#m_pd).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)   
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)


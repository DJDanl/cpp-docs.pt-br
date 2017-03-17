---
title: Classe CPrintDialogEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- Print Setup dialog box
- CPrintDialogEx class
- Print dialog box
ms.assetid: 1d506703-ee1c-44cc-b4ce-4e778fec26b8
caps.latest.revision: 22
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
ms.openlocfilehash: 8dc8f01eef42b54af18ed07520d547768c931748
ms.lasthandoff: 02/25/2017

---
# <a name="cprintdialogex-class"></a>Classe CPrintDialogEx
Encapsula os serviços fornecidos por folha de propriedades de impressão do Windows 2000.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPrintDialogEx : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialogEx::CPrintDialogEx](#cprintdialogex)|Constrói um objeto `CPrintDialogEx`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialogEx::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora sem exibir a caixa de diálogo de impressão.|  
|[CPrintDialogEx::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça as seleções.|  
|[CPrintDialogEx::GetCopies](#getcopies)|Recupera o número de cópias solicitadas.|  
|[CPrintDialogEx::GetDefaults](#getdefaults)|Recupera os padrões de dispositivo sem exibir uma caixa de diálogo.|  
|[CPrintDialogEx::GetDeviceName](#getdevicename)|Recupera o nome do dispositivo de impressora atualmente selecionada.|  
|[CPrintDialogEx::GetDevMode](#getdevmode)|Recupera o `DEVMODE` estrutura.|  
|[CPrintDialogEx::GetDriverName](#getdrivername)|Recupera o nome do driver de dispositivo da impressora definida pelo sistema.|  
|[CPrintDialogEx::GetPortName](#getportname)|Recupera o nome da porta da impressora selecionada no momento.|  
|[CPrintDialogEx::GetPrinterDC](#getprinterdc)|Recupera um identificador para o contexto de dispositivo da impressora.|  
|[CPrintDialogEx::PrintAll](#printall)|Determina se deve imprimir todas as páginas do documento.|  
|[CPrintDialogEx::PrintCollate](#printcollate)|Determina se agrupadas cópias são solicitadas.|  
|[CPrintDialogEx::PrintCurrentPage](#printcurrentpage)|Determina se deve imprimir a página atual do documento.|  
|[CPrintDialogEx::PrintRange](#printrange)|Determina se imprimir apenas um intervalo de páginas especificado.|  
|[CPrintDialogEx::PrintSelection](#printselection)|Determina se deve imprimir apenas os itens selecionados no momento.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialogEx::m_pdex](#m_pdex)|Uma estrutura usada para personalizar um `CPrintDialogEx` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Você pode contar com a estrutura para lidar com muitos aspectos do processo de impressão para o seu aplicativo. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [impressão](../../mfc/printing.md).  
  
 Se desejar que seu aplicativo para manipular a impressão sem o envolvimento do framework, você pode usar o `CPrintDialogEx` classe "como está" com o construtor fornecido, ou você pode derivar sua própria classe de caixa de diálogo de `CPrintDialogEx` e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportará como caixas de diálogo MFC padrão porque eles são derivados da classe `CCommonDialog`.  
  
 Para usar um `CPrintDialogEx` de objeto, primeiro crie o objeto usando o `CPrintDialogEx` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar qualquer valor de [m_pdex](#m_pdex) estrutura para inicializar os valores dos controles da caixa de diálogo. O `m_pdex` estrutura é do tipo [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844). Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se você não fornecer seus próprios identificadores em `m_pdex` para o **hDevMode** e **hDevNames** membros, certifique-se de chamar a função Windows **GlobalFree** para essas alças quando tiver terminado com a caixa de diálogo.  
  
 Depois de inicializar os controles de caixa de diálogo, chame o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecione as opções de impressão. Quando `DoModal` retorna, você pode determinar se o usuário selecionou o botão Okey, aplicar ou Cancelar.  
  
 Se o usuário pressionou Okey, você pode usar `CPrintDialogEx`de funções de membro para recuperar as informações de entrada do usuário.  
  
 O `CPrintDialogEx::GetDefaults` função de membro é útil para recuperar os padrões atuais de impressora sem exibir uma caixa de diálogo. Este método não requer nenhuma interação do usuário.  
  
 Você pode usar o Windows **CommDlgExtendedError** função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e saiba mais sobre o erro. Para obter mais informações sobre essa função, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre como usar o `CPrintDialogEx`, consulte [Classes comuns do diálogo](../../mfc/common-dialog-classes.md).  
  
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
  
##  <a name="cprintdialogex"></a>CPrintDialogEx::CPrintDialogEx  
 Constrói uma folha de propriedades de impressão do Windows 2000.  
  
```  
CPrintDialogEx(
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS       | PD_HIDEPRINTTOFILE | PD_NOSELECTION | PD_NOCURRENTPAGE,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas com o operador OR bit a bit. Por exemplo, o **PD_ALLPAGES** sinalizador define o intervalo de impressão padrão para todas as páginas do documento. Consulte o [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre esses sinalizadores.  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro apenas constrói o objeto. Use o `DoModal` a função de membro para exibir a caixa de diálogo.  
  
##  <a name="createprinterdc"></a>CPrintDialogEx::CreatePrinterDC  
 Cria um contexto de dispositivo da impressora (DC) a partir de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
```  
HDC CreatePrinterDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o contexto de dispositivo da impressora recém-criado.  
  
### <a name="remarks"></a>Comentários  
 O controlador de domínio retornado também é armazenada no **hDC** membro do [m_pdex](#m_pdex).  
  
 Esse controlador de domínio é considerado como a impressora atual controlador de domínio e qualquer outro obtido anteriormente impressora que controladores de domínio devem ser excluídos. Essa função pode ser chamada, e o controlador de domínio resultante usada, sem nunca exibir a caixa de diálogo de impressão.  
  
##  <a name="domodal"></a>CPrintDialogEx::DoModal  
 Chame essa função para exibir a folha de propriedades de impressão comuns do Windows 2000 e permite ao usuário selecionar várias opções de impressão, como o número de cópias, intervalo de páginas, e se as cópias devem ser agrupadas.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O INT_PTR valor de retorno é realmente um HRESULT. Consulte a seção valores de retorno em [PrintDlgEx](http://msdn.microsoft.com/library/windows/desktop/ms646942) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo Imprimir definindo membros do `m_pdex` estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Depois de chamar `DoModal`, você pode chamar outro membro funções para recuperar as configurações ou entrada de informações pelo usuário na caixa de diálogo.  
  
 Se o **PD_RETURNDC** sinalizador é usado ao chamar `DoModal`, uma impressora DC será retornada o **hDC** membro do [m_pdex](#m_pdex). Esse controlador de domínio deve ser liberado com uma chamada para [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) pelo chamador de `CPrintDialogEx`.  
  
##  <a name="getcopies"></a>CPrintDialogEx::GetCopies  
 Chame essa função depois de chamar `DoModal` para recuperar o número de cópias solicitadas.  
  
```  
int GetCopies() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de cópias solicitadas.  
  
##  <a name="getdefaults"></a>CPrintDialogEx::GetDefaults  
 Chame essa função para recuperar os padrões de dispositivo da impressora padrão sem exibir uma caixa de diálogo.  
  
```  
BOOL GetDefaults();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se for bem-sucedido, caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Cria um contexto de dispositivo da impressora (DC) a partir de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
 `GetDefaults`não exibe a folha de propriedades de impressão. Em vez disso, ele define o **hDevNames** e **hDevMode** membros da [m_pdex](#m_pdex) para identificadores para o [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas que são inicializadas para a impressora padrão do sistema. Ambos **hDevNames** e **hDevMode** deve ser NULL, ou `GetDefaults` falhar.  
  
 Se o **PD_RETURNDC** sinalizador estiver definido, essa função não retornará apenas **hDevNames** e **hDevMode** (localizado em **m_pdex.hDevNames** e **m_pdex.hDevMode**) para o chamador, mas também retornará uma impressora DC em **m_pdex.hDC**. É responsabilidade do chamador para excluir a impressora DC e chamar o Windows [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579) função com os identificadores quando tiver terminado com a `CPrintDialogEx` objeto.  
  
##  <a name="getdevicename"></a>CPrintDialogEx::GetDeviceName  
 Chame essa função depois de chamar [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento, ou depois de chamar [GetDefaults](#getdefaults) para recuperar o nome da impressora padrão.  
  
```  
CString GetDeviceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da impressora selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
 Usar um ponteiro para o `CString` objeto retornado por `GetDeviceName` como o valor de `lpszDeviceName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
##  <a name="getdevmode"></a>CPrintDialogEx::GetDevMode  
 Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.  
  
```  
LPDEVMODE GetDevMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura de dados, que contém informações sobre o ambiente de um driver de impressão e a inicialização do dispositivo. Você deve desbloquear a memória usada por essa estrutura com o Windows [GlobalUnlock](http://msdn.microsoft.com/library/windows/desktop/aa366595) função, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getdrivername"></a>CPrintDialogEx::GetDriverName  
 Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo da impressora definida pelo sistema.  
  
```  
CString GetDriverName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` especificando o nome do driver definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
##  <a name="getportname"></a>CPrintDialogEx::GetPortName  
 Chame essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta da impressora selecionada no momento.  
  
```  
CString GetPortName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da porta da impressora selecionada no momento.  
  
##  <a name="getprinterdc"></a>CPrintDialogEx::GetPrinterDC  
 Retorna um identificador para o contexto de dispositivo da impressora.  
  
```  
HDC GetPrinterDC() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o contexto de dispositivo da impressora.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o Windows [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) função para excluir o contexto do dispositivo quando terminar de usá-lo.  
  
##  <a name="m_pdex"></a>CPrintDialogEx::m_pdex  
 Uma estrutura PRINTDLGEX cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PRINTDLGEX m_pdex;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar um `CPrintDialogEx` do objeto, você pode usar `m_pdex` para definir vários aspectos da caixa de diálogo antes de chamar o [DoModal](#domodal) função de membro. Para obter mais informações sobre o `m_pdex` estrutura, consulte [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se você modificar o `m_pdex` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
##  <a name="printall"></a>CPrintDialogEx::PrintAll  
 Chame essa função depois de chamar `DoModal` para determinar se deseja imprimir todas as páginas do documento.  
  
```  
BOOL PrintAll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se todas as páginas do documento são impressos; caso contrário **FALSE**.  
  
##  <a name="printcollate"></a>CPrintDialogEx::PrintCollate  
 Chame essa função depois de chamar `DoModal` para determinar se a impressora deve agrupar as cópias impressas tudo do documento.  
  
```  
BOOL PrintCollate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o usuário selecionar a caixa de seleção collate na caixa de diálogo; caso contrário, **FALSE**.  
  
##  <a name="printcurrentpage"></a>CPrintDialogEx::PrintCurrentPage  
 Chame essa função depois de chamar `DoModal` para determinar se deve imprimir a página atual no documento.  
  
```  
BOOL PrintCurrentPage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se **Imprimir página atual** for selecionado na caixa de diálogo Imprimir; caso contrário **FALSE**.  
  
##  <a name="printrange"></a>CPrintDialogEx::PrintRange  
 Chame essa função depois de chamar `DoModal` para determinar se deve imprimir apenas um intervalo de páginas do documento.  
  
```  
BOOL PrintRange() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se apenas um intervalo de páginas do documento são impressos; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Os intervalos de página especificada podem ser determinados em [m_pdex](#m_pdex) (consulte **nPageRanges**, **nMaxPageRanges**, e **lpPageRanges** no [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]).  
  
##  <a name="printselection"></a>CPrintDialogEx::PrintSelection  
 Chame essa função depois de chamar `DoModal` para determinar se apenas os itens selecionados no momento.  
  
```  
BOOL PrintSelection() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se apenas os itens selecionados devem ser impressos; caso contrário **FALSE**.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)


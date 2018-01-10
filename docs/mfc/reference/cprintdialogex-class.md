---
title: Classe CPrintDialogEx | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
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
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 147a3d638f76f291a9732b340335331730f5b74d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cprintdialogex-class"></a>Classe CPrintDialogEx
Encapsula os serviços fornecidos por folha de propriedades de impressão do Windows 2000.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPrintDialogEx : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialogEx::CPrintDialogEx](#cprintdialogex)|Constrói um objeto `CPrintDialogEx`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialogEx::CreatePrinterDC](#createprinterdc)|Cria um contexto de dispositivo de impressora sem exibir a caixa de diálogo de impressão.|  
|[CPrintDialogEx::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça seleções.|  
|[CPrintDialogEx::GetCopies](#getcopies)|Recupera o número de cópias solicitado.|  
|[CPrintDialogEx::GetDefaults](#getdefaults)|Recupera os padrões do dispositivo sem exibir uma caixa de diálogo.|  
|[CPrintDialogEx::GetDeviceName](#getdevicename)|Recupera o nome do dispositivo de impressora atualmente selecionada.|  
|[CPrintDialogEx::GetDevMode](#getdevmode)|Recupera o `DEVMODE` estrutura.|  
|[CPrintDialogEx::GetDriverName](#getdrivername)|Recupera o nome do driver de dispositivo de impressora definidas pelo sistema.|  
|[CPrintDialogEx::GetPortName](#getportname)|Recupera o nome da porta da impressora selecionada no momento.|  
|[CPrintDialogEx::GetPrinterDC](#getprinterdc)|Recupera um identificador para o contexto de dispositivo de impressora.|  
|[CPrintDialogEx::PrintAll](#printall)|Determina se a impressão de todas as páginas do documento.|  
|[CPrintDialogEx::PrintCollate](#printcollate)|Determina se agrupados cópias são solicitadas.|  
|[CPrintDialogEx::PrintCurrentPage](#printcurrentpage)|Determina se deve imprimir a página atual do documento.|  
|[CPrintDialogEx::PrintRange](#printrange)|Determina se imprimir apenas um intervalo de páginas especificado.|  
|[CPrintDialogEx::PrintSelection](#printselection)|Determina se imprimir apenas os itens selecionados no momento.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintDialogEx::m_pdex](#m_pdex)|Uma estrutura usada para personalizar um `CPrintDialogEx` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Você pode contar com a estrutura para lidar com vários aspectos do processo de impressão de seu aplicativo. Para obter mais informações sobre como usar a estrutura para lidar com tarefas de impressão, consulte o artigo [impressão](../../mfc/printing.md).  
  
 Se você deseja que seu aplicativo para manipular a impressão sem o envolvimento do framework, você pode usar o `CPrintDialogEx` classe "como está" com o construtor fornecido, ou você pode derivar sua própria classe de caixa de diálogo de `CPrintDialogEx` e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportará como caixas de diálogo MFC padrão porque eles são derivados da classe `CCommonDialog`.  
  
 Para usar um `CPrintDialogEx` de objeto, primeiro crie o objeto usando o `CPrintDialogEx` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar valores no [m_pdex](#m_pdex) estrutura para inicializar os valores de controles da caixa de diálogo. O `m_pdex` estrutura é do tipo [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844). Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.  
  
 Se você não fornecer seus próprios identificadores em `m_pdex` para o **hDevMode** e **hDevNames** membros, certifique-se de chamar a função do Windows **GlobalFree** para esses identificadores Quando você terminar com a caixa de diálogo.  
  
 Depois de inicializar os controles de caixa de diálogo, chamar o `DoModal` a função de membro para exibir a caixa de diálogo e permitir que o usuário selecionar opções de impressão. Quando `DoModal` retorna, você pode determinar se o usuário selecionou o botão Okey, aplicar ou em Cancelar.  
  
 Se o usuário pressionou Okey, você pode usar `CPrintDialogEx`de funções de membro para recuperar as informações de entrada do usuário.  
  
 O `CPrintDialogEx::GetDefaults` função de membro é útil para recuperar os padrões atuais de impressora sem exibir uma caixa de diálogo. Esse método não requer nenhuma interação do usuário.  
  
 Você pode usar o Windows **CommDlgExtendedError** função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro. Para obter mais informações sobre essa função, consulte o SDK do Windows.  
  
 Para obter mais informações sobre como usar `CPrintDialogEx`, consulte [Classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).  
  
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
 **Cabeçalho:** afxdlgs.h  
  
##  <a name="cprintdialogex"></a>CPrintDialogEx::CPrintDialogEx  
 Constrói uma folha de propriedades de impressão do Windows 2000.  
  
```  
CPrintDialogEx(
    DWORD dwFlags = PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS       | PD_HIDEPRINTTOFILE | PD_NOSELECTION | PD_NOCURRENTPAGE,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas que usam o operador OR bit a bit. Por exemplo, o **PD_ALLPAGES** sinalizador define o intervalo de impressão padrão para todas as páginas do documento. Consulte o [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844) estrutura no SDK do Windows para obter mais informações sobre esses sinalizadores.  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai ou o proprietário da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro apenas constrói o objeto. Use o `DoModal` a função de membro para exibir a caixa de diálogo.  
  
##  <a name="createprinterdc"></a>CPrintDialogEx::CreatePrinterDC  
 Cria um contexto de dispositivo de impressora (DC) a partir de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
```  
HDC CreatePrinterDC();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o contexto de dispositivo de impressora recém-criado.  
  
### <a name="remarks"></a>Comentários  
 O controlador de domínio retornado também é armazenado no **hDC** membro [m_pdex](#m_pdex).  
  
 Este controlador de domínio é considerado como a impressora atual controlador de domínio e qualquer outro obtido anteriormente impressora que controladores de domínio devem ser excluídos. Esta função pode ser chamada e o controlador de domínio resultante é usado, sem nunca exibir a caixa de diálogo de impressão.  
  
##  <a name="domodal"></a>CPrintDialogEx::DoModal  
 Chamar essa função para exibir a folha de propriedades de impressão comuns do Windows 2000 e permitir que o usuário selecionar várias opções de impressão, como o número de cópias, intervalo de páginas, e se as cópias devem ser agrupadas.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O INT_PTR valor de retorno é realmente um HRESULT. Consulte a seção de valores de retorno em [PrintDlgEx](http://msdn.microsoft.com/library/windows/desktop/ms646942) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo de impressão, definindo membros do `m_pdex` estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Depois de chamar `DoModal`, você pode chamar outro membro funções para recuperar as configurações ou a entrada de informações pelo usuário na caixa de diálogo.  
  
 Se o **PD_RETURNDC** sinalizador é usado ao chamar `DoModal`, uma controlador de domínio de impressora será retornada o **hDC** membro [m_pdex](#m_pdex). Este controlador de domínio deve ser liberado com uma chamada para [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) pelo chamador de `CPrintDialogEx`.  
  
##  <a name="getcopies"></a>CPrintDialogEx::GetCopies  
 Chamar essa função depois de chamar `DoModal` para recuperar o número de cópias solicitado.  
  
```  
int GetCopies() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de cópias solicitado.  
  
##  <a name="getdefaults"></a>CPrintDialogEx::GetDefaults  
 Chame essa função para recuperar os padrões de dispositivo da impressora padrão sem exibir uma caixa de diálogo.  
  
```  
BOOL GetDefaults();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se for bem-sucedido, caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Cria um contexto de dispositivo de impressora (DC) a partir de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES](../../mfc/reference/devnames-structure.md) estruturas.  
  
 `GetDefaults`Não exibir a folha de propriedades de impressão. Em vez disso, ele define o **hDevNames** e **hDevMode** membros de [m_pdex](#m_pdex) para identificadores para o [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) e [DEVNAMES ](../../mfc/reference/devnames-structure.md) estruturas que são inicializadas para a impressora padrão do sistema. Ambos **hDevNames** e **hDevMode** deve ser NULL, ou `GetDefaults` falhar.  
  
 Se o **PD_RETURNDC** sinalizador for definido, essa função não retornará apenas **hDevNames** e **hDevMode** (localizado em **m_pdex.hDevNames** e **m_pdex.hDevMode**) para o chamador, mas também retornará uma impressora DC em **m_pdex.hDC**. É responsabilidade do chamador para excluir a impressora DC e chamar o Windows [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579) função em identificadores quando tiver terminado com o `CPrintDialogEx` objeto.  
  
##  <a name="getdevicename"></a>CPrintDialogEx::GetDeviceName  
 Chamar essa função depois de chamar [DoModal](#domodal) para recuperar o nome da impressora selecionada no momento, ou depois de chamar [GetDefaults](#getdefaults) para recuperar o nome da impressora padrão.  
  
```  
CString GetDeviceName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da impressora selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
 Usar um ponteiro para o `CString` objeto retornado por `GetDeviceName` como o valor de `lpszDeviceName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
##  <a name="getdevmode"></a>CPrintDialogEx::GetDevMode  
 Chamar essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar informações sobre o dispositivo de impressão.  
  
```  
LPDEVMODE GetDevMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura de dados, que contém informações sobre a inicialização do dispositivo e o ambiente de um driver de impressão. Você deve desbloquear a memória usada por esta estrutura com o Windows [GlobalUnlock](http://msdn.microsoft.com/library/windows/desktop/aa366595) função, que é descrita no SDK do Windows.  
  
##  <a name="getdrivername"></a>CPrintDialogEx::GetDriverName  
 Chamar essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome do driver de dispositivo de impressora definidas pelo sistema.  
  
```  
CString GetDriverName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` especificando o nome do driver definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 Usar um ponteiro para o `CString` objeto retornado por `GetDriverName` como o valor de `lpszDriverName` em uma chamada para [CDC::CreateDC](../../mfc/reference/cdc-class.md#createdc).  
  
##  <a name="getportname"></a>CPrintDialogEx::GetPortName  
 Chamar essa função depois de chamar [DoModal](#domodal) ou [GetDefaults](#getdefaults) para recuperar o nome da porta da impressora selecionada no momento.  
  
```  
CString GetPortName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da porta da impressora selecionada no momento.  
  
##  <a name="getprinterdc"></a>CPrintDialogEx::GetPrinterDC  
 Retorna um identificador para o contexto de dispositivo de impressora.  
  
```  
HDC GetPrinterDC() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o contexto de dispositivo de impressora.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o Windows [DeleteDC](http://msdn.microsoft.com/library/windows/desktop/dd183533) função para excluir o contexto de dispositivo quando você terminar de usá-lo.  
  
##  <a name="m_pdex"></a>CPrintDialogEx::m_pdex  
 Uma estrutura PRINTDLGEX cujos membros armazenam as características do objeto de caixa de diálogo.  
  
```  
PRINTDLGEX m_pdex;  
```  
  
### <a name="remarks"></a>Comentários  
 Depois de construir um `CPrintDialogEx` do objeto, você pode usar `m_pdex` para definir vários aspectos da caixa de diálogo antes de chamar o [DoModal](#domodal) função de membro. Para obter mais informações sobre o `m_pdex` estrutura, consulte [PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844) no SDK do Windows.  
  
 Se você modificar o `m_pdex` membro de dados diretamente, você substituirá qualquer comportamento padrão.  
  
##  <a name="printall"></a>CPrintDialogEx::PrintAll  
 Chamar essa função depois de chamar `DoModal` para determinar se todas as páginas do documento.  
  
```  
BOOL PrintAll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se todas as páginas do documento são impressos; caso contrário **FALSE**.  
  
##  <a name="printcollate"></a>CPrintDialogEx::PrintCollate  
 Chamar essa função depois de chamar `DoModal` para determinar se a impressora deve agrupar impressas todas as cópias do documento.  
  
```  
BOOL PrintCollate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o usuário seleciona a caixa de seleção collate na caixa de diálogo; caso contrário, **FALSE**.  
  
##  <a name="printcurrentpage"></a>CPrintDialogEx::PrintCurrentPage  
 Chamar essa função depois de chamar `DoModal` para determinar se deseja imprimir a página atual no documento.  
  
```  
BOOL PrintCurrentPage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se **imprimir a página atual** for selecionado na caixa de diálogo; caso contrário **FALSE**.  
  
##  <a name="printrange"></a>CPrintDialogEx::PrintRange  
 Chamar essa função depois de chamar `DoModal` para determinar se apenas um intervalo de páginas do documento.  
  
```  
BOOL PrintRange() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se apenas um intervalo de páginas do documento são impressos; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Os intervalos de página especificado podem ser determinados no [m_pdex](#m_pdex) (consulte **nPageRanges**, **nMaxPageRanges**, e **lpPageRanges** no [ PRINTDLGEX](http://msdn.microsoft.com/library/windows/desktop/ms646844) estrutura no SDK do Windows).  
  
##  <a name="printselection"></a>CPrintDialogEx::PrintSelection  
 Chamar essa função depois de chamar `DoModal` para determinar se apenas os itens selecionados no momento.  
  
```  
BOOL PrintSelection() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se apenas os itens selecionados devem ser impressos; caso contrário **FALSE**.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Estrutura CPrintInfo](../../mfc/reference/cprintinfo-structure.md)

---
title: "Funções globais do controle composto | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlhost/ATL::AtlAxDialogBox
- atlhost/ATL::AtlAxCreateDialog
- atlhost/ATL::AtlAxCreateControl
- atlhost/ATL::AtlAxCreateControlEx
- atlhost/ATL::AtlAxCreateControlLic
- atlhost/ATL::AtlAxCreateControlLicEx
- atlhost/ATL::AtlAxAttachControl
- atlhost/ATL::AtlAxGetHost
- atlhost/ATL::AtlAxGetControl
- atlhost/ATL::AtlSetChildSite
- atlhost/ATL::AtlAxWinInit
- atlhost/ATL::AtlAxWinTerm
- atlhost/ATL::AtlGetObjectSourceInterface
dev_langs:
- C++
helpviewer_keywords:
- composite controls, global functions
ms.assetid: 536884cd-e863-4c7a-ab0a-604dc60a0bbe
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d5a062ea9477df9db026c75bc775df804ed86da4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="composite-control-global-functions"></a>Funções globais do controle composto
Essas funções fornecem suporte para a criação de caixas de diálogo e para a criação, hospedagem e licenciando controles ActiveX.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlAxDialogBox](#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|  
|[AtlAxCreateDialog](#atlaxcreatedialog)|Cria uma caixa de diálogo sem modo a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|  
|[AtlAxCreateControl](#atlaxcreatecontrol)|Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.|  
|[AtlAxCreateControlEx](#atlaxcreatecontrolex)|Cria um controle ActiveX, inicializa, hospeda na janela especificada e recupera um ponteiro de interface (ou indicadores) do controle.|  
|[AtlAxCreateControlLic](#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|  
|[AtlAxCreateControlLicEx](#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa, hospeda na janela especificada e recupera um ponteiro de interface (ou indicadores) do controle.|  
|[AtlAxAttachControl](#atlaxattachcontrol)|Anexa um controle criado anteriormente à janela especificada.|  
|[AtlAxGetHost](#atlaxgethost)|Usado para obter um ponteiro de interface direta para o contêiner para um período especificado (se houver), dado seu identificador.|  
|[AtlAxGetControl](#atlaxgetcontrol)|Usado para obter um ponteiro de interface direta para o controle dentro de um período especificado (se houver), dado seu identificador.|  
|[AtlSetChildSite](#atlsetchildsite)|Inicializa o **IUnknown** do site filho.|  
|[AtlAxWinInit](#atlaxwininit)|Inicializa o código de hospedagem para objetos AxWin.|  
|[AtlAxWinTerm](#atlaxwinterm)|Uninitializes AxWin objetos com o código de hospedagem.|  
|[AtlGetObjectSourceInterface](#atlgetobjectsourceinterface)|Retorna informações sobre a interface de origem padrão de um objeto.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlhost.h  

##  <a name="atlaxdialogbox"></a>AtlAxDialogBox  
 Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo fornecido pelo usuário.  
   
```
ATLAPI_(int) AtlAxDialogBox(
    HINSTANCE hInstance,
    LPCWSTR lpTemplateName,
    HWND hWndParent,
    DLGPROC lpDialogProc,
    LPARAM dwInitParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 [in] Identifica uma instância do módulo cujo arquivo executável contém o modelo de caixa de diálogo.  
  
 `lpTemplateName`  
 [in] Identifica o modelo de caixa de diálogo. Esse parâmetro é o ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do modelo de caixa de diálogo ou um valor inteiro que especifica o identificador de recurso do modelo de caixa de diálogo. Se o parâmetro especifica um identificador de recurso, a palavra de ordem superior deve ser zero e a palavra de ordem inferior deve conter o identificador. Você pode usar o [MAKEINTRESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms648029) macro para criar esse valor.  
  
 `hWndParent`  
 [in] Identifica a janela que possui a caixa de diálogo.  
  
 `lpDialogProc`  
 [in] Aponta para o procedimento da caixa de diálogo. Para obter mais informações sobre o procedimento da caixa de diálogo, consulte [DialogProc](http://msdn.microsoft.com/library/windows/desktop/ms645469).  
  
 `dwInitParam`  
 [in] Especifica o valor para passar para a caixa de diálogo o **lParam** parâmetro o **WM_INITDIALOG** mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Para usar **AtlAxDialogBox** com um modelo de caixa de diálogo que contém um controle ActiveX, especifique uma opção válida **CLSID**, **APPID** ou cadeia de caracteres de URL como o *texto* campo o **controle** seção do recurso de caixa de diálogo, junto com "AtlAxWin80" como o *nome da classe* campo na mesma seção. A seguir demonstra que um válido **controle** seção pode parecer com:  
  
```  
CONTROL    "{04FE35E9-ADBC-4f1d-83FE-8FA4D1F71C7F}", IDC_TEST,  
    "AtlAxWin80", WS_GROUP | WS_TABSTOP, 0, 0, 100, 100  
```  
  
 Para obter mais informações sobre como editar scripts de recurso, consulte [como: abrir um arquivo de Script de recurso no formato de texto](../../windows/how-to-open-a-resource-script-file-in-text-format.md). Para obter mais informações sobre instruções de definição de recurso de controle, consulte [parâmetros comuns de controle](http://msdn.microsoft.com/library/windows/desktop/aa380902) no SDK do Windows*: ferramentas SDK*.  
  
 Para obter mais informações sobre caixas de diálogo, em geral, consulte [DialogBox](http://msdn.microsoft.com/library/windows/desktop/ms645452) e [CreateDialogParam](http://msdn.microsoft.com/library/windows/desktop/ms645445) no SDK do Windows.  
  
##  <a name="atlaxcreatedialog"></a>AtlAxCreateDialog  
 Cria uma caixa de diálogo sem modo a partir de um modelo de caixa de diálogo fornecido pelo usuário.  
  
```
ATLAPI_(HWND) AtlAxCreateDialog(
    HINSTANCE hInstance,
    LPCWSTR lpTemplateName,
    HWND hWndParent,
    DLGPROC lpDialogProc,
    LPARAM dwInitParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 [in] Identifica uma instância do módulo cujo arquivo executável contém o modelo de caixa de diálogo.  
  
 `lpTemplateName`  
 [in] Identifica o modelo de caixa de diálogo. Esse parâmetro é o ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do modelo de caixa de diálogo ou um valor inteiro que especifica o identificador de recurso do modelo de caixa de diálogo. Se o parâmetro especifica um identificador de recurso, a palavra de ordem superior deve ser zero e a palavra de ordem inferior deve conter o identificador. Você pode usar o [MAKEINTRESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms648029) macro para criar esse valor.  
  
 `hWndParent`  
 [in] Identifica a janela que possui a caixa de diálogo.  
  
 `lpDialogProc`  
 [in] Aponta para o procedimento da caixa de diálogo. Para obter mais informações sobre o procedimento da caixa de diálogo, consulte [DialogProc](http://msdn.microsoft.com/library/windows/desktop/ms645469).  
  
 `dwInitParam`  
 [in] Especifica o valor para passar para a caixa de diálogo o **lParam** parâmetro o **WM_INITDIALOG** mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo resultante pode conter controles ActiveX.  
  
 Consulte [CreateDialog](http://msdn.microsoft.com/library/windows/desktop/ms645434) e [CreateDialogParam](http://msdn.microsoft.com/library/windows/desktop/ms645445) no SDK do Windows.  
  
##  <a name="atlaxcreatecontrol"></a>AtlAxCreateControl  
 Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.  
  

```
ATLAPI AtlAxCreateControl(
    LPCOLESTR lpszName,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnkContainer);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado de uma das seguintes maneiras:  
  
-   ProgID, como "MSCAL. Calendar.7 "  
  
-   Um CLSID como "{8E27C92B-1264-101C-8A2F-040224009C02}"  
  
-   Uma URL, como "http://www.microsoft.com"  
  
-   Uma referência a um documento ativo como "file://\\\Documents\MyDoc.doc"  
  
-   Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"  
  
    > [!NOTE]
    >  "MSHTML:" deve preceder o fragmento de HTML para que ele é designado como um fluxo MSHTML.  
  
 `hWnd`  
 [in] Identificador para a janela que o controle será anexado ao.  
  
 `pStream`  
 [in] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser **nulo**.  
  
 `ppUnkContainer`  
 [out] O endereço de um ponteiro que receberá o **IUnknown** do contêiner. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Essa função global fornece o mesmo resultado de chamar [AtlAxCreateControlEx](#atlaxcreatecontrolex)( `lpszName` **,** `hWnd` **,** `pStream` **, Nulo, nulo, nulo, nulo** );.  
  
 Para criar um controle ActiveX licenciado, consulte [AtlAxCreateControlLic](#atlaxcreatecontrollic).  
  
##  <a name="atlaxcreatecontrolex"></a>AtlAxCreateControlEx  
 Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada. Um ponteiro de interface e um coletor de eventos para o novo controle também podem ser criados.  
  
```
ATLAPI AtlAxCreateControlEx(
    LPCOLESTR lpszName,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnkContainer,
    IUnknown** ppUnkControl,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado de uma das seguintes maneiras:  
  
-   ProgID, como "MSCAL. Calendar.7 "  
  
-   Um CLSID como "{8E27C92B-1264-101C-8A2F-040224009C02}"  
  
-   Uma URL, como "http://www.microsoft.com"  
  
-   Uma referência a um documento ativo como "file://\\\Documents\MyDoc.doc"  
  
-   Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"  
  
    > [!NOTE]
    >  "MSHTML:" deve preceder o fragmento de HTML para que ele é designado como um fluxo MSHTML.  
  
 `hWnd`  
 [in] Identificador para a janela que o controle será anexado ao.  
  
 `pStream`  
 [in] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser **nulo**.  
  
 `ppUnkContainer`  
 [out] O endereço de um ponteiro que receberá o **IUnknown** do contêiner. Pode ser **nulo**.  
  
 `ppUnkControl`  
 [out] O endereço de um ponteiro que receberá o **IUnknown** do controle criado. Pode ser **nulo**.  
  
 `iidSink`  
 O identificador de interface de uma interface saída o objeto contido.  
  
 *punkSink*  
 Um ponteiro para o **IUnknown** interface do objeto a ser conectado ao ponto de conexão especificado pelo coletor `iidSink` no objeto independente depois que o objeto contido foi criado com êxito.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 `AtlAxCreateControlEx`é semelhante a [AtlAxCreateControl](#atlaxcreatecontrol) , mas também permite que você receber um ponteiro de interface para o controle recém-criado e configurar um coletor de eventos para receber eventos disparados pelo controle.  
  
 Para criar um controle ActiveX licenciado, consulte [AtlAxCreateControlLicEx](#atlaxcreatecontrollicex).  
  
##  <a name="atlaxcreatecontrollic"></a>AtlAxCreateControlLic  
 Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.  

```
ATLAPI AtlAxCreateControlLic(
    LPCOLESTR lpszName,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnkContainer,
    BSTR bstrLic = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado de uma das seguintes maneiras:  
  
-   ProgID, como "MSCAL. Calendar.7 "  
  
-   Um CLSID como "{8E27C92B-1264-101C-8A2F-040224009C02}"  
  
-   Uma URL, como "http://www.microsoft.com"  
  
-   Uma referência a um documento ativo como "file://\\\Documents\MyDoc.doc"  
  
-   Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"  
  
    > [!NOTE]
    >  "MSHTML:" deve preceder o fragmento de HTML para que ele é designado como um fluxo MSHTML.  
  
 `hWnd`  
 Identificador para a janela que o controle será anexado ao.  
  
 `pStream`  
 Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser **nulo**.  
  
 `ppUnkContainer`  
 O endereço de um ponteiro que receberá o **IUnknown** do contêiner. Pode ser **nulo**.  
  
 `bstrLic`  
 BSTR que contém a licença para o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="example"></a>Exemplo  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo de como usar `AtlAxCreateControlLic`.  
  
##  <a name="atlaxcreatecontrollicex"></a>AtlAxCreateControlLicEx  
 Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada. Um ponteiro de interface e um coletor de eventos para o novo controle também podem ser criados.  
  
```
ATLAPI AtlAxCreateControlLicEx(
    LPCOLESTR lpszName,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnkContainer,
    IUnknown** ppUnkControl,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL,
    BSTR bstrLic = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado de uma das seguintes maneiras:  
  
-   ProgID, como "MSCAL. Calendar.7 "  
  
-   Um CLSID como "{8E27C92B-1264-101C-8A2F-040224009C02}"  
  
-   Uma URL, como "http://www.microsoft.com"  
  
-   Uma referência a um documento ativo como "file://\\\Documents\MyDoc.doc"  
  
-   Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"  
  
    > [!NOTE]
    >  "MSHTML:" deve preceder o fragmento de HTML para que ele é designado como um fluxo MSHTML.  
  
 `hWnd`  
 Identificador para a janela que o controle será anexado ao.  
  
 `pStream`  
 Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser **nulo**.  
  
 `ppUnkContainer`  
 O endereço de um ponteiro que receberá o **IUnknown** do contêiner. Pode ser **nulo**.  
  
 `ppUnkControl`  
 [out] O endereço de um ponteiro que receberá o **IUnknown** do controle criado. Pode ser **nulo**.  
  
 `iidSink`  
 O identificador de interface de uma interface saída o objeto contido.  
  
 *punkSink*  
 Um ponteiro para o **IUnknown** interface do objeto a ser conectado ao ponto de conexão especificado pelo coletor `iidSink` no objeto independente depois que o objeto contido foi criado com êxito.  
  
 `bstrLic`  
 BSTR que contém a licença para o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 `AtlAxCreateControlLicEx`é semelhante a [AtlAxCreateControlLic](#atlaxcreatecontrollic) , mas também permite que você receber um ponteiro de interface para o controle recém-criado e configurar um coletor de eventos para receber eventos disparados pelo controle.  
  
### <a name="example"></a>Exemplo  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo de como usar `AtlAxCreateControlLicEx`.  
  
##  <a name="atlaxattachcontrol"></a>AtlAxAttachControl  
 Anexa um controle criado anteriormente à janela especificada.  
  
```
ATLAPI AtlAxAttachControl(
    IUnknown* pControl,
    HWND hWnd,
    IUnknown** ppUnkContainer);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pControl`  
 [in] Um ponteiro para o **IUnknown** do controle.  
  
 `hWnd`  
 [in] Identificador para a janela que hospedará o controle.  
  
 `ppUnkContainer`  
 [out] Um ponteiro para um ponteiro para o **IUnknown** do objeto contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
### <a name="remarks"></a>Comentários  
 Use [AtlAxCreateControlEx](#atlaxcreatecontrolex) e [AtlAxCreateControl](#atlaxcreatecontrol) para criar e anexar um controle simultaneamente.  
  
> [!NOTE]
>  O objeto de controle que está sendo anexado deve ser inicializado corretamente antes de chamar `AtlAxAttachControl`.  
  
##  <a name="atlaxgethost"></a>AtlAxGetHost  
 Obtém um ponteiro de interface direta para o contêiner para uma janela especificada (se houver), de acordo com seu identificador.  
  
```
ATLAPI AtlAxGetHost(HWND h, IUnknown** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 [in] Um identificador para a janela que está hospedando o controle.  
  
 `pp`  
 [out] O **IUnknown** do contêiner do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="atlaxgetcontrol"></a>AtlAxGetControl  
 Obtém um ponteiro de interface direta para o controle contido em uma janela especificada de acordo com seu identificador.  
  
```
ATLAPI AtlAxGetControl(HWND h, IUnknown** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `h`  
 [in] Um identificador para a janela que está hospedando o controle.  
  
 `pp`  
 [out] O **IUnknown** do controle que está sendo hospedado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores HRESULT padrão.  
  
##  <a name="atlsetchildsite"></a>AtlSetChildSite  
 Chamar essa função para definir o site do objeto filho para o **IUnknown** do objeto pai.  
  
```
HRESULT AtlSetChildSite(IUnknown* punkChild, IUnknown* punkParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *punkChild*  
 [in] Um ponteiro para o **IUnknown** interface do filho.  
  
 `punkParent`  
 [in] Um ponteiro para o **IUnknown** interface do pai.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
##  <a name="atlaxwininit"></a>AtlAxWinInit  
 Essa função inicializa o controle do ATL código de hospedagem registrando o **"AtlAxWin80"** e **"AtlAxWinLic80"** classes de janela além de algumas mensagens de janela personalizada.  
  
```
ATLAPI_(BOOL) AtlAxWinInit();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização do controle de hospedagem de código foi bem-sucedida; Caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada antes de usar o controle ATL API de hospedagem. Após uma chamada para essa função, o **"AtlAxWin"** classe de janela pode ser usada em chamadas para [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) ou [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680), conforme descrito no SDK do Windows.  

##  <a name="atlaxwinterm"></a>AtlAxWinTerm  
 Essa função uninitializes hospedagem de código ao cancelar o registro de controle do ATL o **"AtlAxWin80"** e **"AtlAxWinLic80"** classes de janela.  
  
```
inline BOOL AtlAxWinTerm();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna **TRUE**.  
  
### <a name="remarks"></a>Comentários  
 Essa função simplesmente chama [UnregisterClass](http://msdn.microsoft.com/library/windows/desktop/ms644899) conforme descrito no SDK do Windows.  
  
 Chamar essa função para limpar depois que todas as janelas de host existente tiveram sido destruídas se você chamou [AtlAxWinInit](#atlaxwininit) e você não precisa criar janelas de host. Se você não chamar essa função, a classe de janela será cancelada automaticamente quando o processo é encerrado.  
  
##  <a name="atlgetobjectsourceinterface"></a>AtlGetObjectSourceInterface  
 Chame essa função para recuperar informações sobre a interface padrão de origem de um objeto.  
  
```
ATLAPI AtlGetObjectSourceInterface(
    IUnknown* punkObj,
    GUID* plibid,
    IID* piid,
    unsigned short* pdwMajor,
    unsigned short* pdwMinor);
```  
  
### <a name="parameters"></a>Parâmetros  
 `punkObj`  
 [in] Um ponteiro para o objeto para o qual as informações são a ser retornado.  
  
 `plibid`  
 [out] Um ponteiro para a ID da biblioteca do tipo de biblioteca que contém a definição da interface de origem.  
  
 `piid`  
 [out] Um ponteiro para a identificação da interface de origem do objeto padrão.  
  
 *pdwMajor*  
 [out] Um ponteiro para o número de versão principal da biblioteca de tipos que contém a definição da interface de origem.  
  
 *pdwMinor*  
 [out] Um ponteiro para o número de versão secundária do tipo de biblioteca que contém a definição da interface de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 `AtlGetObjectSourceInterface`pode fornecer a identificação da interface de origem padrão, juntamente com a ID da biblioteca e principais e números de versão secundária da biblioteca de tipos que descreve a interface.  
  
> [!NOTE]
>  Para esta função recuperar as informações solicitadas, o objeto representado pelo `punkObj` deve implementar `IDispatch` (e retornar informações de tipo por meio de **IDispatch:: GetTypeInfo**) e também deve implementar o `IProvideClassInfo2` ou `IPersist`. As informações de tipo para a interface de origem devem estar na biblioteca de tipos como as informações de tipo `IDispatch`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como você pode definir uma classe de coletor de eventos, `CEasySink`, que reduz o número de argumentos de modelo que você pode passar para `IDispEventImpl` para os itens essenciais. `EasyAdvise`e `EasyUnadvise` usar `AtlGetObjectSourceInterface` para inicializar o [IDispEventImpl](../../atl/reference/idispeventimpl-class.md) membros antes de chamar [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) ou [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise).  
  
 [!code-cpp[NVC_ATL_Windowing#93](../../atl/codesnippet/cpp/composite-control-global-functions_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)   
 [Macros de controle de composição](../../atl/reference/composite-control-macros.md)

---
title: Funções globais de controle de composição
ms.date: 11/04/2016
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
helpviewer_keywords:
- composite controls, global functions
ms.assetid: 536884cd-e863-4c7a-ab0a-604dc60a0bbe
ms.openlocfilehash: 3b4abc1afc99a00d83c25574df06ebfb27141c65
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694173"
---
# <a name="composite-control-global-functions"></a>Funções globais de controle de composição

Essas funções fornecem suporte para a criação de caixas de diálogo e para criação, hospedagem e licenciando controles ActiveX.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no tempo de execução do Windows.

|||
|-|-|
|[AtlAxDialogBox](#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|
|[AtlAxCreateDialog](#atlaxcreatedialog)|Cria uma caixa de diálogo sem modo a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|
|[AtlAxCreateControl](#atlaxcreatecontrol)|Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.|
|[AtlAxCreateControlEx](#atlaxcreatecontrolex)|Cria um controle ActiveX, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[AtlAxCreateControlLic](#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|
|[AtlAxCreateControlLicEx](#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[AtlAxAttachControl](#atlaxattachcontrol)|Anexa um controle criado anteriormente à janela especificada.|
|[AtlAxGetHost](#atlaxgethost)|Usado para obter um ponteiro de interface direta para o contêiner para uma janela especificada (se houver), acordo com seu identificador.|
|[AtlAxGetControl](#atlaxgetcontrol)|Usado para obter um ponteiro de interface direta para o controle contido em uma janela especificada (se houver), acordo com seu identificador.|
|[AtlSetChildSite](#atlsetchildsite)|Inicializa o `IUnknown` do site filho.|
|[AtlAxWinInit](#atlaxwininit)|Inicializa o código de hospedagem para objetos AxWin.|
|[AtlAxWinTerm](#atlaxwinterm)|O código de hospedagem para objetos AxWin cancela a inicialização.|
|[AtlGetObjectSourceInterface](#atlgetobjectsourceinterface)|Retorna informações sobre a interface de origem padrão de um objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlhost.h

##  <a name="atlaxdialogbox"></a>  AtlAxDialogBox

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

*hInstance*<br/>
[in] Identifica uma instância do módulo cujo arquivo executável contém o modelo de caixa de diálogo.

*lpTemplateName*<br/>
[in] Identifica o modelo de caixa de diálogo. Esse parâmetro é o ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do modelo de caixa de diálogo ou um valor inteiro que especifica o identificador de recurso do modelo de caixa de diálogo. Se o parâmetro especifica um identificador de recurso, sua palavra de ordem superior deve ser zero e a palavra de ordem inferior deve conter o identificador. Você pode usar o [MAKEINTRESOURCE](/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro para criar esse valor.

*hWndParent*<br/>
[in] Identifica a janela que possui a caixa de diálogo.

*lpDialogProc*<br/>
[in] Aponta para o procedimento de caixa de diálogo. Para obter mais informações sobre o procedimento de caixa de diálogo, consulte [DialogProc](https://msdn.microsoft.com/library/windows/desktop/ms645469).

*dwInitParam*<br/>
[in] Especifica o valor para passar para a caixa de diálogo do *lParam* parâmetro da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Para usar `AtlAxDialogBox` com um modelo de caixa de diálogo que contém um controle ActiveX, especifique uma cadeia CLSID, APPID ou URL válida, como o *texto* campo dos **controle** seção do recurso de caixa de diálogo, junto com " AtlAxWin80 "como o *nome da classe* campo sob a mesma seção. A seguir demonstra quais válida **controle** seção pode parecer com:

```
CONTROL    "{04FE35E9-ADBC-4f1d-83FE-8FA4D1F71C7F}", IDC_TEST,
    "AtlAxWin80", WS_GROUP | WS_TABSTOP, 0, 0, 100, 100
```

Para obter mais informações sobre como editar scripts de recurso, consulte [como: abrir um arquivo de Script de recurso no formato de texto](../../windows/how-to-open-a-resource-script-file-in-text-format.md). Para obter mais informações sobre instruções de definição de recurso de controle, consulte [parâmetros de controle comuns](/windows/desktop/menurc/common-control-parameters) no SDK do Windows: SDK Tools.

Para obter mais informações sobre caixas de diálogo em geral, consulte [DialogBox](/windows/desktop/api/winuser/nf-winuser-dialogboxa) e [CreateDialogParam](/windows/desktop/api/winuser/nf-winuser-createdialogparama) no SDK do Windows.

##  <a name="atlaxcreatedialog"></a>  AtlAxCreateDialog

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

*hInstance*<br/>
[in] Identifica uma instância do módulo cujo arquivo executável contém o modelo de caixa de diálogo.

*lpTemplateName*<br/>
[in] Identifica o modelo de caixa de diálogo. Esse parâmetro é o ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do modelo de caixa de diálogo ou um valor inteiro que especifica o identificador de recurso do modelo de caixa de diálogo. Se o parâmetro especifica um identificador de recurso, sua palavra de ordem superior deve ser zero e a palavra de ordem inferior deve conter o identificador. Você pode usar o [MAKEINTRESOURCE](/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro para criar esse valor.

*hWndParent*<br/>
[in] Identifica a janela que possui a caixa de diálogo.

*lpDialogProc*<br/>
[in] Aponta para o procedimento de caixa de diálogo. Para obter mais informações sobre o procedimento de caixa de diálogo, consulte [DialogProc](https://msdn.microsoft.com/library/windows/desktop/ms645469).

*dwInitParam*<br/>
[in] Especifica o valor para passar para a caixa de diálogo do *lParam* parâmetro da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

A caixa de diálogo resultante pode conter controles ActiveX.

Ver [CreateDialog](/windows/desktop/api/winuser/nf-winuser-createdialoga) e [CreateDialogParam](/windows/desktop/api/winuser/nf-winuser-createdialogparama) no Windows SDK.

##  <a name="atlaxcreatecontrol"></a>  AtlAxCreateControl

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.

```
ATLAPI AtlAxCreateControl(
    LPCOLESTR lpszName,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado em uma das seguintes maneiras:

- Um ProgID, como "MSCAL. Calendar.7 "

- Um CLSID, como "{8E27C92B-1264-101C-8A2F-040224009C02}"

- Uma URL, como "<http://www.microsoft.com>"

- Uma referência a um documento ativo, como "file://\\\Documents\MyDoc.doc"

- Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"

   > [!NOTE]
   > "MSHTML:" deve preceder o fragmento HTML para que ela é designada como sendo um fluxo de MSHTML.

*hWnd*<br/>
[in] Identificador da janela que o controle será anexado.

*pStream*<br/>
[in] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
[out] O endereço de um ponteiro que receberá o `IUnknown` do contêiner. Pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função global permite que você o mesmo resultado de chamar [AtlAxCreateControlEx](#atlaxcreatecontrolex)(*lpszName*, *hWnd*, *pStream*, NULL, NULL, NULL, NULL);.

Para criar um controle ActiveX licenciado, consulte [AtlAxCreateControlLic](#atlaxcreatecontrollic).

##  <a name="atlaxcreatecontrolex"></a>  AtlAxCreateControlEx

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

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado em uma das seguintes maneiras:

- Um ProgID, como "MSCAL. Calendar.7 "

- Um CLSID, como "{8E27C92B-1264-101C-8A2F-040224009C02}"

- Uma URL, como "<http://www.microsoft.com>"

- Uma referência a um documento ativo, como "file://\\\Documents\MyDoc.doc"

- Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"

   > [!NOTE]
   > "MSHTML:" deve preceder o fragmento HTML para que ela é designada como sendo um fluxo de MSHTML.

*hWnd*<br/>
[in] Identificador da janela que o controle será anexado.

*pStream*<br/>
[in] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
[out] O endereço de um ponteiro que receberá o `IUnknown` do contêiner. Pode ser NULL.

*ppUnkControl*<br/>
[out] O endereço de um ponteiro que receberá o `IUnknown` do controle criado. Pode ser NULL.

*iidSink*<br/>
O identificador de interface de uma interface de saída o objeto contido.

*punkSink*<br/>
Um ponteiro para o `IUnknown` interface do objeto coletor a ser conectado ao ponto de conexão especificado pela *iidSink* no objeto independente depois que o objeto contido foi criado com êxito.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlAxCreateControlEx` é semelhante à [AtlAxCreateControl](#atlaxcreatecontrol) , mas também permite que você receber um ponteiro de interface para o controle criado recentemente e configurar um coletor de eventos para receber eventos acionados pelo controle.

Para criar um controle ActiveX licenciado, consulte [AtlAxCreateControlLicEx](#atlaxcreatecontrollicex).

##  <a name="atlaxcreatecontrollic"></a>  AtlAxCreateControlLic

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

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado em uma das seguintes maneiras:

- Um ProgID, como "MSCAL. Calendar.7 "

- Um CLSID, como "{8E27C92B-1264-101C-8A2F-040224009C02}"

- Uma URL, como "<http://www.microsoft.com>"

- Uma referência a um documento ativo, como "file://\\\Documents\MyDoc.doc"

- Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"

   > [!NOTE]
   > "MSHTML:" deve preceder o fragmento HTML para que ela é designada como sendo um fluxo de MSHTML.

*hWnd*<br/>
Identificador da janela que o controle será anexado.

*pStream*<br/>
Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
O endereço de um ponteiro que receberá o `IUnknown` do contêiner. Pode ser NULL.

*bstrLic*<br/>
O BSTR contendo a licença para o controle.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo de como usar `AtlAxCreateControlLic`.

##  <a name="atlaxcreatecontrollicex"></a>  AtlAxCreateControlLicEx

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

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a serem passados para o controle. Deve ser formatado em uma das seguintes maneiras:

- Um ProgID, como "MSCAL. Calendar.7 "

- Um CLSID, como "{8E27C92B-1264-101C-8A2F-040224009C02}"

- Uma URL, como "<http://www.microsoft.com>"

- Uma referência a um documento ativo, como "file://\\\Documents\MyDoc.doc"

- Um fragmento de HTML, como "MSHTML:\<HTML >\<corpo > Esta é uma linha de texto\</BODY >\</HTML mais externas >"

   > [!NOTE]
   > "MSHTML:" deve preceder o fragmento HTML para que ela é designada como sendo um fluxo de MSHTML.

*hWnd*<br/>
Identificador da janela que o controle será anexado.

*pStream*<br/>
Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
O endereço de um ponteiro que receberá o `IUnknown` do contêiner. Pode ser NULL.

*ppUnkControl*<br/>
[out] O endereço de um ponteiro que receberá o `IUnknown` do controle criado. Pode ser NULL.

*iidSink*<br/>
O identificador de interface de uma interface de saída o objeto contido.

*punkSink*<br/>
Um ponteiro para o `IUnknown` interface do objeto coletor a ser conectado ao ponto de conexão especificado pela *iidSink* no objeto independente depois que o objeto contido foi criado com êxito.

*bstrLic*<br/>
O BSTR contendo a licença para o controle.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlAxCreateControlLicEx` é semelhante à [AtlAxCreateControlLic](#atlaxcreatecontrollic) , mas também permite que você receber um ponteiro de interface para o controle criado recentemente e configurar um coletor de eventos para receber eventos acionados pelo controle.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo de como usar `AtlAxCreateControlLicEx`.

##  <a name="atlaxattachcontrol"></a>  AtlAxAttachControl

Anexa um controle criado anteriormente à janela especificada.

```
ATLAPI AtlAxAttachControl(
    IUnknown* pControl,
    HWND hWnd,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
[in] Um ponteiro para o `IUnknown` do controle.

*hWnd*<br/>
[in] Identificador da janela que hospedará o controle.

*ppUnkContainer*<br/>
[out] Um ponteiro para um ponteiro para o `IUnknown` do objeto contêiner.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Use [AtlAxCreateControlEx](#atlaxcreatecontrolex) e [AtlAxCreateControl](#atlaxcreatecontrol) para criar e anexar um controle simultaneamente.

> [!NOTE]
>  O objeto de controle que está sendo anexado deve ser inicializado corretamente antes de chamar `AtlAxAttachControl`.

##  <a name="atlaxgethost"></a>  AtlAxGetHost

Obtém um ponteiro de interface direta para o contêiner para uma janela especificada (se houver), de acordo com seu identificador.

```
ATLAPI AtlAxGetHost(HWND h, IUnknown** pp);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
[in] Um identificador para a janela que está hospedando o controle.

*PP*<br/>
[out] O `IUnknown` do contêiner do controle.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="atlaxgetcontrol"></a>  AtlAxGetControl

Obtém um ponteiro de interface direta para o controle contido em uma janela especificada de acordo com seu identificador.

```
ATLAPI AtlAxGetControl(HWND h, IUnknown** pp);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
[in] Um identificador para a janela que está hospedando o controle.

*PP*<br/>
[out] O `IUnknown` do controle que está sendo hospedado.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

##  <a name="atlsetchildsite"></a>  AtlSetChildSite

Chame essa função para definir o site do objeto filho para o `IUnknown` do objeto pai.

```
HRESULT AtlSetChildSite(IUnknown* punkChild, IUnknown* punkParent);
```

### <a name="parameters"></a>Parâmetros

*punkChild*<br/>
[in] Um ponteiro para o `IUnknown` interface do filho.

*punkParent*<br/>
[in] Um ponteiro para o `IUnknown` interface do pai.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="atlaxwininit"></a>  AtlAxWinInit

Essa função inicializa o controle do ATL que hospeda o código Registrando as **"AtlAxWin80"** e **"AtlAxWinLic80"** classes de janela mais algumas mensagens personalizadas da janela.

```
ATLAPI_(BOOL) AtlAxWinInit();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização do controle de código de hospedagem foi bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes de usar o controle ATL que hospeda a API. Após uma chamada para essa função, o **"AtlAxWin"** classe de janela pode ser usado em chamadas para [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) ou [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa), conforme descrito no SDK do Windows.

##  <a name="atlaxwinterm"></a>  AtlAxWinTerm

Essa função cancela o controle do ATL que hospeda o código Cancelando o registro a **"AtlAxWin80"** e **"AtlAxWinLic80"** classes de janela.

```
inline BOOL AtlAxWinTerm();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Essa função simplesmente chama [UnregisterClass](/windows/desktop/api/winuser/nf-winuser-unregisterclassa) conforme descrito no SDK do Windows.

Chame essa função para limpar após todas as janelas existentes de host tenham sido destruídas se você chamasse [AtlAxWinInit](#atlaxwininit) e você não precisa criar host do windows. Se você não chamar essa função, a classe de janela será cancelada automaticamente quando o processo termina.

##  <a name="atlgetobjectsourceinterface"></a>  AtlGetObjectSourceInterface

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

*punkObj*<br/>
[in] Um ponteiro para o objeto para o qual informações deve ser retornado.

*plibid*<br/>
[out] Um ponteiro para o LIBID da biblioteca de tipos que contém a definição da interface de origem.

*piid*<br/>
[out] Um ponteiro para a ID de interface da interface de origem do objeto padrão.

*pdwMajor*<br/>
[out] Um ponteiro para o número de versão principal da biblioteca de tipos que contém a definição da interface de origem.

*pdwMinor*<br/>
[out] Um ponteiro para o número de versão secundária da biblioteca de tipos que contém a definição da interface de origem.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

`AtlGetObjectSourceInterface` pode fornecer a você com a ID de interface da interface de origem padrão, juntamente com a ID da biblioteca e principais e os números de versão secundária da biblioteca de tipos que descrevem essa interface.

> [!NOTE]
>  Para essa função recuperar as informações solicitadas, o objeto representado pelo *punkObj* deve implementar `IDispatch` (e retornar informações de tipo por meio de `IDispatch::GetTypeInfo`) além de também deve implementar a qualquer um dos `IProvideClassInfo2` ou `IPersist`. As informações de tipo para a interface de origem devem estar na biblioteca de tipos como informações de tipo para `IDispatch`.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como você pode definir uma classe de coletor de evento, `CEasySink`, que reduz o número de argumentos de modelo que você pode passar para `IDispEventImpl` para os itens essenciais. `EasyAdvise` e `EasyUnadvise` usar `AtlGetObjectSourceInterface` para inicializar o [IDispEventImpl](../../atl/reference/idispeventimpl-class.md) membros antes de chamar [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) ou [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise).

[!code-cpp[NVC_ATL_Windowing#93](../../atl/codesnippet/cpp/composite-control-global-functions_1.h)]

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de controle de composição](../../atl/reference/composite-control-macros.md)

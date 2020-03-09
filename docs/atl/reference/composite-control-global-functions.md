---
title: Funções globais de controle composto
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
ms.openlocfilehash: 525fc01247053a1e2bc993398978cb332262a1a5
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864711"
---
# <a name="composite-control-global-functions"></a>Funções globais de controle composto

Essas funções fornecem suporte para a criação de caixas de diálogo e para criação, hospedagem e licenciamento de controles ActiveX.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|||
|-|-|
|[AtlAxDialogBox](#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|
|[AtlAxCreateDialog](#atlaxcreatedialog)|Cria uma caixa de diálogo sem modo a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|
|[AtlAxCreateControl](#atlaxcreatecontrol)|Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.|
|[AtlAxCreateControlEx](#atlaxcreatecontrolex)|Cria um controle ActiveX, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[AtlAxCreateControlLic](#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|
|[AtlAxCreateControlLicEx](#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[AtlAxAttachControl](#atlaxattachcontrol)|Anexa um controle criado anteriormente à janela especificada.|
|[AtlAxGetHost](#atlaxgethost)|Usado para obter um ponteiro de interface direto para o contêiner de uma janela especificada (se houver), considerando seu identificador.|
|[AtlAxGetControl](#atlaxgetcontrol)|Usado para obter um ponteiro de interface direto para o controle contido dentro de uma janela especificada (se houver), considerando seu identificador.|
|[AtlSetChildSite](#atlsetchildsite)|Inicializa o `IUnknown` do site filho.|
|[AtlAxWinInit](#atlaxwininit)|Inicializa o código de hospedagem para objetos AxWin.|
|[AtlAxWinTerm](#atlaxwinterm)|Desinicializa o código de hospedagem para objetos AxWin.|
|[AtlGetObjectSourceInterface](#atlgetobjectsourceinterface)|Retorna informações sobre a interface de origem padrão de um objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlhost. h

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

### <a name="parameters"></a>parâmetros

*hInstance*<br/>
no Identifica uma instância do módulo cujo arquivo executável contém o modelo de caixa de diálogo.

*lpTemplateName*<br/>
no Identifica o modelo da caixa de diálogo. Esse parâmetro é o ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do modelo da caixa de diálogo ou um valor inteiro que especifica o identificador de recurso do modelo da caixa de diálogo. Se o parâmetro especificar um identificador de recurso, sua palavra de ordem superior deverá ser zero e sua palavra de ordem inferior deverá conter o identificador. Você pode usar a macro [MAKEINTRESOURCE](/windows/win32/api/winuser/nf-winuser-makeintresourcew) para criar esse valor.

*hWndParent*<br/>
no Identifica a janela que possui a caixa de diálogo.

*lpDialogProc*<br/>
no Aponta para o procedimento da caixa de diálogo. Para obter mais informações sobre o procedimento da caixa de diálogo, consulte [DialogProc](/windows/win32/api/winuser/nc-winuser-dlgproc).

*dwInitParam*<br/>
no Especifica o valor a ser passado para a caixa de diálogo no parâmetro *lParam* da mensagem de WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Para usar `AtlAxDialogBox` com um modelo de caixa de diálogo que contém um controle ActiveX, especifique uma cadeia de caracteres CLSID, APPID ou URL válida como o campo de *texto* da seção de **controle** do recurso de caixa de diálogo, juntamente com "AtlAxWin80" como o campo *nome da classe* na mesma seção. O exemplo a seguir demonstra o que uma seção de **controle** válida pode ter:

```
CONTROL    "{04FE35E9-ADBC-4f1d-83FE-8FA4D1F71C7F}", IDC_TEST,
    "AtlAxWin80", WS_GROUP | WS_TABSTOP, 0, 0, 100, 100
```

Para obter mais informações sobre como editar scripts de recursos, consulte [como abrir um arquivo de script de recurso em formato de texto](../../windows/how-to-open-a-resource-script-file-in-text-format.md). Para obter mais informações sobre como controlar as instruções de definição de recurso, consulte [parâmetros de controle comuns](/windows/win32/menurc/common-control-parameters) em SDK do Windows: SDK Tools.

Para obter mais informações sobre caixas de diálogo em geral, consulte [caixa](/windows/win32/api/winuser/nf-winuser-dialogboxw) e [CreateDialogParam](/windows/win32/api/winuser/nf-winuser-createdialogparamw) no SDK do Windows.

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

### <a name="parameters"></a>parâmetros

*hInstance*<br/>
no Identifica uma instância do módulo cujo arquivo executável contém o modelo de caixa de diálogo.

*lpTemplateName*<br/>
no Identifica o modelo da caixa de diálogo. Esse parâmetro é o ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do modelo da caixa de diálogo ou um valor inteiro que especifica o identificador de recurso do modelo da caixa de diálogo. Se o parâmetro especificar um identificador de recurso, sua palavra de ordem superior deverá ser zero e sua palavra de ordem inferior deverá conter o identificador. Você pode usar a macro [MAKEINTRESOURCE](/windows/win32/api/winuser/nf-winuser-makeintresourcew) para criar esse valor.

*hWndParent*<br/>
no Identifica a janela que possui a caixa de diálogo.

*lpDialogProc*<br/>
no Aponta para o procedimento da caixa de diálogo. Para obter mais informações sobre o procedimento da caixa de diálogo, consulte [DialogProc](/windows/win32/api/winuser/nc-winuser-dlgproc).

*dwInitParam*<br/>
no Especifica o valor a ser passado para a caixa de diálogo no parâmetro *lParam* da mensagem de WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

A caixa de diálogo resultante pode conter controles ActiveX.

Consulte [CreateDialog](/windows/win32/api/winuser/nf-winuser-createdialogw) e [CreateDialogParam](/windows/win32/api/winuser/nf-winuser-createdialogparamw) no SDK do Windows.

##  <a name="atlaxcreatecontrol"></a>AtlAxCreateControl

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.

```
ATLAPI AtlAxCreateControl(
    LPCOLESTR lpszName,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a ser passada para o controle. Deve ser formatada de uma das seguintes maneiras:

- Um ProgID como `"MSCAL.Calendar.7"`

- Um CLSID, como `"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como `"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como `"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como `"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"` deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
no Identificador para a janela à qual o controle será anexado.

*pStream*<br/>
no Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do contêiner. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função global fornece o mesmo resultado que chamar [AtlAxCreateControlEx](#atlaxcreatecontrolex)(*lpszName*, *HWND*, *pStream*, NULL, NULL, NULL, NULL);.

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

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a ser passada para o controle. Deve ser formatada de uma das seguintes maneiras:

- Um ProgID como `"MSCAL.Calendar.7"`

- Um CLSID, como `"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como `"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como `"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como `"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"` deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
no Identificador para a janela à qual o controle será anexado.

*pStream*<br/>
no Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do contêiner. Pode ser NULL.

*ppUnkControl*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do controle criado. Pode ser NULL.

*iidSink*<br/>
O identificador de interface de uma interface de saída no objeto contido.

*punkSink*<br/>
Um ponteiro para a interface de `IUnknown` do objeto de coletor a ser conectado ao ponto de conexão especificado por *iidSink* no objeto contido depois que o objeto contido tiver sido criado com êxito.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlAxCreateControlEx` é semelhante a [AtlAxCreateControl](#atlaxcreatecontrol) , mas também permite que você receba um ponteiro de interface para o controle recém-criado e configure um coletor de eventos para receber eventos acionados pelo controle.

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

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a ser passada para o controle. Deve ser formatada de uma das seguintes maneiras:

- Um ProgID como `"MSCAL.Calendar.7"`

- Um CLSID, como `"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como `"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como `"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como `"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"` deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
Identificador para a janela à qual o controle será anexado.

*pStream*<br/>
Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
O endereço de um ponteiro que receberá a `IUnknown` do contêiner. Pode ser NULL.

*bstrLic*<br/>
O BSTR que contém a licença do controle.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="example"></a>Exemplo

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo de como usar `AtlAxCreateControlLic`.

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

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres a ser passada para o controle. Deve ser formatada de uma das seguintes maneiras:

- Um ProgID como `"MSCAL.Calendar.7"`

- Um CLSID, como `"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como `"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como `"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como `"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"` deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
Identificador para a janela à qual o controle será anexado.

*pStream*<br/>
Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
O endereço de um ponteiro que receberá a `IUnknown` do contêiner. Pode ser NULL.

*ppUnkControl*<br/>
fora O endereço de um ponteiro que receberá a `IUnknown` do controle criado. Pode ser NULL.

*iidSink*<br/>
O identificador de interface de uma interface de saída no objeto contido.

*punkSink*<br/>
Um ponteiro para a interface de `IUnknown` do objeto de coletor a ser conectado ao ponto de conexão especificado por *iidSink* no objeto contido depois que o objeto contido tiver sido criado com êxito.

*bstrLic*<br/>
O BSTR que contém a licença do controle.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlAxCreateControlLicEx` é semelhante a [AtlAxCreateControlLic](#atlaxcreatecontrollic) , mas também permite que você receba um ponteiro de interface para o controle recém-criado e configure um coletor de eventos para receber eventos acionados pelo controle.

### <a name="example"></a>Exemplo

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo de como usar `AtlAxCreateControlLicEx`.

##  <a name="atlaxattachcontrol"></a>AtlAxAttachControl

Anexa um controle criado anteriormente à janela especificada.

```
ATLAPI AtlAxAttachControl(
    IUnknown* pControl,
    HWND hWnd,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>parâmetros

*pControl*<br/>
no Um ponteiro para a `IUnknown` do controle.

*hWnd*<br/>
no Identificador para a janela que hospedará o controle.

*ppUnkContainer*<br/>
fora Um ponteiro para um ponteiro para a `IUnknown` do objeto de contêiner.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Use [AtlAxCreateControlEx](#atlaxcreatecontrolex) e [AtlAxCreateControl](#atlaxcreatecontrol) para criar e anexar um controle simultaneamente.

> [!NOTE]
>  O objeto de controle que está sendo anexado deve ser inicializado corretamente antes de chamar `AtlAxAttachControl`.

##  <a name="atlaxgethost"></a>AtlAxGetHost

Obtém um ponteiro de interface direta para o contêiner para uma janela especificada (se houver), de acordo com seu identificador.

```
ATLAPI AtlAxGetHost(HWND h, IUnknown** pp);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
no Um identificador para a janela que está hospedando o controle.

*PP*<br/>
fora A `IUnknown` do contêiner do controle.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

##  <a name="atlaxgetcontrol"></a>AtlAxGetControl

Obtém um ponteiro de interface direta para o controle contido em uma janela especificada de acordo com seu identificador.

```
ATLAPI AtlAxGetControl(HWND h, IUnknown** pp);
```

### <a name="parameters"></a>parâmetros

*h*<br/>
no Um identificador para a janela que está hospedando o controle.

*PP*<br/>
fora O `IUnknown` do controle que está sendo hospedado.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

##  <a name="atlsetchildsite"></a>AtlSetChildSite

Chame essa função para definir o site do objeto filho como a `IUnknown` do objeto pai.

```
HRESULT AtlSetChildSite(IUnknown* punkChild, IUnknown* punkParent);
```

### <a name="parameters"></a>parâmetros

*punkChild*<br/>
no Um ponteiro para a interface de `IUnknown` do filho.

*punkParent*<br/>
no Um ponteiro para a interface de `IUnknown` do pai.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="atlaxwininit"></a>AtlAxWinInit

Essa função inicializa o código de hospedagem do controle da ATL ao registrar as classes de janela **"AtlAxWin80"** e **"AtlAxWinLic80"** , além de algumas mensagens de janela personalizadas.

```
ATLAPI_(BOOL) AtlAxWinInit();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a inicialização do código de hospedagem do controle foi bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes de usar a API de hospedagem do controle ATL. Após uma chamada para essa função, a classe de janela **"AtlAxWin"** pode ser usada em chamadas para [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) ou [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw), conforme descrito na SDK do Windows.

##  <a name="atlaxwinterm"></a>AtlAxWinTerm

Essa função cancela a inicialização do código de hospedagem do controle da ATL ao cancelar o registro das classes de janela **"AtlAxWin80"** e **"AtlAxWinLic80"** .

```
inline BOOL AtlAxWinTerm();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Essa função simplesmente chama [UnregisterClass](/windows/win32/api/winuser/nf-winuser-unregisterclassw) conforme descrito na SDK do Windows.

Chame essa função para limpar depois que todas as janelas de host existentes tiverem sido destruídas se você chamou [AtlAxWinInit](#atlaxwininit) e não precisar mais criar janelas de host. Se você não chamar essa função, a classe Window terá o registro cancelado automaticamente quando o processo for encerrado.

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

### <a name="parameters"></a>parâmetros

*punkObj*<br/>
no Um ponteiro para o objeto para o qual as informações serão retornadas.

*plibid*<br/>
fora Um ponteiro para o LIBID da biblioteca de tipos que contém a definição da interface de origem.

*piid*<br/>
fora Um ponteiro para a ID de interface da interface de origem padrão do objeto.

*pdwMajor*<br/>
fora Um ponteiro para o número de versão principal da biblioteca de tipos que contém a definição da interface de origem.

*pdwMinor*<br/>
fora Um ponteiro para o número de versão secundária da biblioteca de tipos que contém a definição da interface de origem.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlGetObjectSourceInterface` pode fornecer a ID de interface da interface de origem padrão, juntamente com os números de versão LIBID e Major e Minor da biblioteca de tipos que descreve essa interface.

> [!NOTE]
>  Para essa função recuperar com êxito as informações solicitadas, o objeto representado por *punkObj* deve implementar `IDispatch` (e informações de tipo de retorno por meio de `IDispatch::GetTypeInfo`) e também deve implementar `IProvideClassInfo2` ou `IPersist`. As informações de tipo para a interface de origem devem estar na mesma biblioteca de tipos que as informações de tipo para `IDispatch`.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como você pode definir uma classe de coletor de eventos, `CEasySink`, que reduz o número de argumentos de modelo que você pode passar para `IDispEventImpl` para o Essentials. `EasyAdvise` e `EasyUnadvise` use `AtlGetObjectSourceInterface` para inicializar os membros do [IDispEventImpl](../../atl/reference/idispeventimpl-class.md) antes de chamar [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) ou [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise).

[!code-cpp[NVC_ATL_Windowing#93](../../atl/codesnippet/cpp/composite-control-global-functions_1.h)]

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de controle de composição](../../atl/reference/composite-control-macros.md)

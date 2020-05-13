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
ms.openlocfilehash: 99ecd4cf04b3eb696f897d6ef5a5e3839d46ef17
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331608"
---
# <a name="composite-control-global-functions"></a>Funções globais de controle composto

Essas funções fornecem suporte para criar caixas de diálogo e para criar, hospedar e licenciar controles ActiveX.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AtlAxDialogBox](#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|
|[AtlAxCreateDialog](#atlaxcreatedialog)|Cria uma caixa de diálogo sem modo a partir de um modelo de caixa de diálogo fornecido pelo usuário. A caixa de diálogo resultante pode conter controles ActiveX.|
|[AtlAxCreateControl](#atlaxcreatecontrol)|Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada.|
|[AtlAxCreateControlEx](#atlaxcreatecontrolex)|Cria um controle ActiveX, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[AtlAxCreateControlLic](#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|
|[AtlAxCreateControlLicEx](#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|
|[AtlAxAttachControl](#atlaxattachcontrol)|Anexa um controle criado anteriormente à janela especificada.|
|[AtlAxGetHost](#atlaxgethost)|Usado para obter um ponteiro de interface direta para o recipiente para uma janela especificada (se houver), dada a sua alça.|
|[AtlAxGetControl](#atlaxgetcontrol)|Usado para obter um ponteiro de interface direta para o controle contido dentro de uma janela especificada (se houver), dada a sua alça.|
|[AtlSetChildSite](#atlsetchildsite)|Inicializa o `IUnknown` local da criança.|
|[AtlAxWinInit](#atlaxwininit)|Inicializa o código de hospedagem para objetos AxWin.|
|[AtlAxWinTerm](#atlaxwinterm)|Desinicializa o código de hospedagem para objetos AxWin.|
|[AtlGetObjectSourceInterface](#atlgetobjectsourceinterface)|Retorna informações sobre a interface de origem padrão de um objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlhost.h

## <a name="atlaxdialogbox"></a><a name="atlaxdialogbox"></a>AtlAxDialogBox

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
[em] Identifica uma instância do módulo cujo arquivo executável contém o modelo da caixa de diálogo.

*Lptemplatename*<br/>
[em] Identifica o modelo da caixa de diálogo. Este parâmetro é o ponteiro para uma seqüência de caracteres com término nulo que especifica o nome do modelo da caixa de diálogo ou um valor inteiro que especifica o identificador de recursos do modelo caixa de diálogo. Se o parâmetro especificar um identificador de recursos, sua palavra de alta ordem deve ser zero e sua palavra de baixa ordem deve conter o identificador. Você pode usar a macro [MAKEINTRESOURCE](/windows/win32/api/winuser/nf-winuser-makeintresourcew) para criar esse valor.

*Hwndparent*<br/>
[em] Identifica a janela que possui a caixa de diálogo.

*lpDialogProc*<br/>
[em] Aponta para o procedimento da caixa de diálogo. Para obter mais informações sobre o procedimento da caixa de diálogo, consulte [DialogProc](/windows/win32/api/winuser/nc-winuser-dlgproc).

*dwInitParam*<br/>
[em] Especifica o valor a ser repassar para a caixa de diálogo no parâmetro *lParam* da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Para `AtlAxDialogBox` usar com um modelo de diálogo que contenha um controle ActiveX, especifique uma seqüência válida de CLSID, APPID ou URL como o campo de *texto* da seção **CONTROL** do recurso de diálogo, juntamente com "AtlAxWin80" como o campo nome da *classe* na mesma seção. O seguinte demonstra como uma seção **de CONTROLE** válida pode parecer:

```
CONTROL    "{04FE35E9-ADBC-4f1d-83FE-8FA4D1F71C7F}", IDC_TEST,
    "AtlAxWin80", WS_GROUP | WS_TABSTOP, 0, 0, 100, 100
```

Para obter mais informações sobre a edição de scripts de recursos, consulte [Como: Abrir um arquivo de script de recurso em formato de texto](../../windows/how-to-open-a-resource-script-file-in-text-format.md). Para obter mais informações sobre instruções de definição de recursos de controle, consulte [Parâmetros comuns de controle](/windows/win32/menurc/common-control-parameters) no Windows SDK: SDK Tools.

Para obter mais informações sobre caixas de diálogo em geral, consulte [DialogBox](/windows/win32/api/winuser/nf-winuser-dialogboxw) e [CreateDialogParam](/windows/win32/api/winuser/nf-winuser-createdialogparamw) no Windows SDK.

## <a name="atlaxcreatedialog"></a><a name="atlaxcreatedialog"></a>AtlAxCreateDialog

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
[em] Identifica uma instância do módulo cujo arquivo executável contém o modelo da caixa de diálogo.

*Lptemplatename*<br/>
[em] Identifica o modelo da caixa de diálogo. Este parâmetro é o ponteiro para uma seqüência de caracteres com término nulo que especifica o nome do modelo da caixa de diálogo ou um valor inteiro que especifica o identificador de recursos do modelo caixa de diálogo. Se o parâmetro especificar um identificador de recursos, sua palavra de alta ordem deve ser zero e sua palavra de baixa ordem deve conter o identificador. Você pode usar a macro [MAKEINTRESOURCE](/windows/win32/api/winuser/nf-winuser-makeintresourcew) para criar esse valor.

*Hwndparent*<br/>
[em] Identifica a janela que possui a caixa de diálogo.

*lpDialogProc*<br/>
[em] Aponta para o procedimento da caixa de diálogo. Para obter mais informações sobre o procedimento da caixa de diálogo, consulte [DialogProc](/windows/win32/api/winuser/nc-winuser-dlgproc).

*dwInitParam*<br/>
[em] Especifica o valor a ser repassar para a caixa de diálogo no parâmetro *lParam* da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

A caixa de diálogo resultante pode conter controles ActiveX.

Consulte [CreateDialog](/windows/win32/api/winuser/nf-winuser-createdialogw) e [CreateDialogParam](/windows/win32/api/winuser/nf-winuser-createdialogparamw) no Windows SDK.

## <a name="atlaxcreatecontrol"></a><a name="atlaxcreatecontrol"></a>AtlAxCreateControl

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
Um ponteiro para uma seqüência a ser passada para o controle. Deve ser formatado de uma das seguintes maneiras:

- Um ProgID como`"MSCAL.Calendar.7"`

- Um CLSID como`"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como`"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como`"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como`"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"`deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
[em] Manuseie a janela à que o controle será anexado.

*pStream*<br/>
[em] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o do recipiente. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Esta função global lhe dá o mesmo resultado que chamar [AtlAxCreateControlEx](#atlaxcreatecontrolex)*(lpszName*, *hWnd*, *pStream*, NULL, NULL, NULL, NULL);

Para criar um controle ActiveX licenciado, consulte [AtlAxCreateControlLic](#atlaxcreatecontrollic).

## <a name="atlaxcreatecontrolex"></a><a name="atlaxcreatecontrolex"></a>Atlaxcreatecontrolex

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
Um ponteiro para uma seqüência a ser passada para o controle. Deve ser formatado de uma das seguintes maneiras:

- Um ProgID como`"MSCAL.Calendar.7"`

- Um CLSID como`"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como`"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como`"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como`"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"`deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
[em] Manuseie a janela à que o controle será anexado.

*pStream*<br/>
[em] Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o do recipiente. Pode ser NULL.

*ppUnkControl*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o controle criado. Pode ser NULL.

*Iidsink*<br/>
O identificador de interface de uma interface de saída no objeto contido.

*Punksink*<br/>
Um ponteiro `IUnknown` para a interface do objeto sink a ser conectado ao ponto de conexão especificado pelo *iidSink* no objeto contido após a criação do objeto contido.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

`AtlAxCreateControlEx`é semelhante ao [AtlAxCreateControl,](#atlaxcreatecontrol) mas também permite que você receba um ponteiro de interface para o controle recém-criado e configure um dissipador de eventos para receber eventos disparados pelo controle.

Para criar um controle ActiveX licenciado, consulte [AtlAxCreateControlLicEx](#atlaxcreatecontrollicex).

## <a name="atlaxcreatecontrollic"></a><a name="atlaxcreatecontrollic"></a>Atlaxcreatecontrollic

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
Um ponteiro para uma seqüência a ser passada para o controle. Deve ser formatado de uma das seguintes maneiras:

- Um ProgID como`"MSCAL.Calendar.7"`

- Um CLSID como`"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como`"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como`"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como`"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"`deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
Manuseie a janela à que o controle será anexado.

*pStream*<br/>
Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
O endereço de um ponteiro `IUnknown` que receberá o do recipiente. Pode ser NULL.

*bstrlic*<br/>
O BSTR contendo a licença para o controle.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando atl AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) `AtlAxCreateControlLic`para obter uma amostra de como usar .

## <a name="atlaxcreatecontrollicex"></a><a name="atlaxcreatecontrollicex"></a>Atlaxcreatecontrollicex

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
Um ponteiro para uma seqüência a ser passada para o controle. Deve ser formatado de uma das seguintes maneiras:

- Um ProgID como`"MSCAL.Calendar.7"`

- Um CLSID como`"{8E27C92B-1264-101C-8A2F-040224009C02}"`

- Uma URL como`"<https://www.microsoft.com>"`

- Uma referência a um documento ativo, como`"file://\\\Documents\MyDoc.doc"`

- Um fragmento de HTML, como`"MSHTML:\<HTML>\<BODY>This is a line of text\</BODY>\</HTML>"`

   > [!NOTE]
   > `"MSHTML:"`deve preceder o fragmento HTML para que ele seja designado como sendo um fluxo MSHTML.

*hWnd*<br/>
Manuseie a janela à que o controle será anexado.

*pStream*<br/>
Um ponteiro para um fluxo que é usado para inicializar as propriedades do controle. Pode ser NULL.

*ppUnkContainer*<br/>
O endereço de um ponteiro `IUnknown` que receberá o do recipiente. Pode ser NULL.

*ppUnkControl*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá o controle criado. Pode ser NULL.

*Iidsink*<br/>
O identificador de interface de uma interface de saída no objeto contido.

*Punksink*<br/>
Um ponteiro `IUnknown` para a interface do objeto sink a ser conectado ao ponto de conexão especificado pelo *iidSink* no objeto contido após a criação do objeto contido.

*bstrlic*<br/>
O BSTR contendo a licença para o controle.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

`AtlAxCreateControlLicEx`é semelhante ao [AtlAxCreateControlLic,](#atlaxcreatecontrollic) mas também permite que você receba um ponteiro de interface para o controle recém-criado e configure um dissipador de eventos para receber eventos disparados pelo controle.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando atl AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) `AtlAxCreateControlLicEx`para obter uma amostra de como usar .

## <a name="atlaxattachcontrol"></a><a name="atlaxattachcontrol"></a>AtlAxAttachControl

Anexa um controle criado anteriormente à janela especificada.

```
ATLAPI AtlAxAttachControl(
    IUnknown* pControl,
    HWND hWnd,
    IUnknown** ppUnkContainer);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
[em] Um ponteiro `IUnknown` para o controle.

*hWnd*<br/>
[em] Manuseie a janela que hospedará o controle.

*ppUnkContainer*<br/>
[fora] Um ponteiro para um `IUnknown` ponteiro para o objeto do recipiente.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Use [AtlAxCreateControlEx](#atlaxcreatecontrolex) e [AtlAxCreateControl](#atlaxcreatecontrol) para criar e anexar simultaneamente um controle.

> [!NOTE]
> O objeto de controle que está sendo `AtlAxAttachControl`anexado deve ser corretamente inicializado antes de chamar .

## <a name="atlaxgethost"></a><a name="atlaxgethost"></a>AtlAxGetHost

Obtém um ponteiro de interface direta para o contêiner para uma janela especificada (se houver), de acordo com seu identificador.

```
ATLAPI AtlAxGetHost(HWND h, IUnknown** pp);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
[em] Uma alça para a janela que está hospedando o controle.

*Pp*<br/>
[fora] O `IUnknown` do recipiente do controle.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="atlaxgetcontrol"></a><a name="atlaxgetcontrol"></a>AtlAxGetControl

Obtém um ponteiro de interface direta para o controle contido em uma janela especificada de acordo com seu identificador.

```
ATLAPI AtlAxGetControl(HWND h, IUnknown** pp);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
[em] Uma alça para a janela que está hospedando o controle.

*Pp*<br/>
[fora] O `IUnknown` controle que está sendo hospedado.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

## <a name="atlsetchildsite"></a><a name="atlsetchildsite"></a>AtlSetChildSite

Chame esta função para definir o local `IUnknown` do objeto filho para o objeto pai.

```
HRESULT AtlSetChildSite(IUnknown* punkChild, IUnknown* punkParent);
```

### <a name="parameters"></a>Parâmetros

*punkChild*<br/>
[em] Um ponteiro `IUnknown` para a interface da criança.

*punkParent*<br/>
[em] Um ponteiro `IUnknown` para a interface do pai.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="atlaxwininit"></a><a name="atlaxwininit"></a>Atlaxwininit

Esta função inicializa o código de hospedagem de controle da ATL registrando as classes de janela **"AtlAxWin80"** e **"AtlAxWinLic80",** além de algumas mensagens de janela personalizadas.

```
ATLAPI_(BOOL) AtlAxWinInit();
```

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização do código de hospedagem de controle foi bem sucedida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Esta função deve ser chamada antes de usar a API de hospedagem de controle ATL. Após uma chamada para esta função, a classe de janela **"AtlAxWin"** pode ser usada em chamadas para [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) ou [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw), conforme descrito no SDK do Windows.

## <a name="atlaxwinterm"></a><a name="atlaxwinterm"></a>AtlAxWinTerm

Esta função não inicializa o código de hospedagem de controle da ATL desregistrando as classes de janela **"AtlAxWin80"** e **"AtlAxWinLic80".**

```
inline BOOL AtlAxWinTerm();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Esta função simplesmente chama [UnregisterClass](/windows/win32/api/winuser/nf-winuser-unregisterclassw) como descrito no Windows SDK.

Chame esta função para limpar depois que todas as janelas de host existentes foram destruídas se você chamou [AtlAxWinInit](#atlaxwininit) e você não precisa mais criar janelas host. Se você não chamar essa função, a classe de janela será desregistrada automaticamente quando o processo terminar.

## <a name="atlgetobjectsourceinterface"></a><a name="atlgetobjectsourceinterface"></a>Atlgetobjectsourceinterface

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
[em] Um ponteiro para o objeto para o qual as informações devem ser devolvidas.

*plibid*<br/>
[fora] Um ponteiro para o LIBID da biblioteca do tipo contendo a definição da interface de origem.

*Piid*<br/>
[fora] Um ponteiro para o ID de interface da interface de origem padrão do objeto.

*pdwMajor*<br/>
[fora] Um ponteiro para o número da versão principal da biblioteca do tipo contendo a definição da interface de origem.

*pdwMinor*<br/>
[fora] Um ponteiro para o número de versão menor da biblioteca do tipo contendo a definição da interface de origem.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlGetObjectSourceInterface`pode fornecer-lhe o ID de interface da interface de origem padrão, juntamente com o LIBID e números de versão maiores e menores da biblioteca do tipo descrevendo essa interface.

> [!NOTE]
> Para que esta função recupere com sucesso as informações solicitadas, o objeto representado pelo *punkObj* deve `IDispatch` implementar (e retornar informações do tipo através `IDispatch::GetTypeInfo`) além de também implementar ou `IProvideClassInfo2` `IPersist`. As informações de tipo para a interface de origem devem `IDispatch`estar na mesma biblioteca do tipo para .

### <a name="example"></a>Exemplo

O exemplo abaixo mostra como você pode `CEasySink`definir uma classe de sumidouro `IDispEventImpl` de eventos, que reduz o número de argumentos de modelo que você pode passar para o essencial. `EasyAdvise`e `EasyUnadvise` `AtlGetObjectSourceInterface` usar para inicializar os membros [do IDispEventImpl](../../atl/reference/idispeventimpl-class.md) antes de ligar para [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) ou [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise).

[!code-cpp[NVC_ATL_Windowing#93](../../atl/codesnippet/cpp/composite-control-global-functions_1.h)]

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de controle composto](../../atl/reference/composite-control-macros.md)

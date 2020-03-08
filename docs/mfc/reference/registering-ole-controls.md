---
title: Registrando controles OLE
ms.date: 11/04/2016
helpviewer_keywords:
- registering OLE controls
- OLE controls [MFC], registering
ms.assetid: 73c45b7f-7dbc-43f5-bd17-dd77c6acec72
ms.openlocfilehash: 9fcbc002913cc6cce86276796a371231ef0f32e1
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856372"
---
# <a name="registering-ole-controls"></a>Registrando controles OLE

Os controles OLE, como outros objetos de servidor OLE, podem ser acessados por outros aplicativos que reconhecem OLE. Isso é obtido registrando-se a biblioteca de tipos e a classe do controle.

As funções a seguir permitem adicionar e remover a classe do controle, as páginas de propriedade e a biblioteca de tipos no banco de dados de registro do Windows:

### <a name="registering-ole-controls"></a>Registrando controles OLE

|||
|-|-|
|[AfxOleRegisterControlClass](#afxoleregistercontrolclass)|Adiciona a classe do controle ao banco de dados de registro.|
|[AfxOleRegisterPropertyPageClass](#afxoleregisterpropertypageclass)|Adiciona uma página de propriedades de controle ao banco de dados de registro.|
|[AfxOleRegisterTypeLib](#afxoleregistertypelib)|Adiciona a biblioteca de tipos do controle ao banco de dados de registro.|
|[AfxOleUnregisterClass](#afxoleunregisterclass)|Remove uma classe de controle ou uma classe de página de propriedades do banco de dados de registro.|
|[AfxOleUnregisterTypeLib](#afxoleunregistertypelib)|Remove a biblioteca de tipos do controle do banco de dados de registro.|

`AfxOleRegisterTypeLib` normalmente é chamado em uma implementação de DLL de controle de `DllRegisterServer`. Da mesma forma, `AfxOleUnregisterTypeLib` é chamado por `DllUnregisterServer`. `AfxOleRegisterControlClass`, `AfxOleRegisterPropertyPageClass`e `AfxOleUnregisterClass` normalmente são chamados pela função membro `UpdateRegistry` da fábrica de classes ou da página de propriedades de um controle.

##  <a name="afxoleregistercontrolclass"></a>AfxOleRegisterControlClass

Registra a classe de controle com o banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleRegisterControlClass(
    HINSTANCE hInstance,
    REFCLSID clsid,
    LPCTSTR pszProgID,
    UINT idTypeName,
    UINT idBitmap,
    int nRegFlags,
    DWORD dwMiscStatus,
    REFGUID tlid,
    WORD wVerMajor,
    WORD wVerMinor);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O identificador de instância do módulo associado à classe de controle.

*CLSID*<br/>
A ID de classe exclusiva do controle.

*pszProgID*<br/>
A ID de programa exclusiva do controle.

*idTypeName*<br/>
A ID de recurso da cadeia de caracteres que contém um nome de tipo legível pelo usuário para o controle.

*idBitmap*<br/>
A ID de recurso do bitmap usado para representar o controle OLE em uma barra de ferramentas ou paleta.

*nRegFlags*<br/>
Contém um ou mais dos seguintes sinalizadores:

- `afxRegInsertable` permite que o controle apareça na caixa de diálogo Inserir objeto para objetos OLE.

- `afxRegApartmentThreading` define o modelo de threading no registro como ThreadingModel = Apartment.

- `afxRegFreeThreading` define o modelo de threading no registro como ThreadingModel = Free.

   Você pode combinar os dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` para definir ThreadingModel = both. Consulte [InprocServer32](/windows/win32/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de Threading.

> [!NOTE]
>  Nas versões do MFC anteriores ao MFC 4,2, o parâmetro **int** *nRegFlags* era um parâmetro bool, *bInsertable*, que permitia ou não permitia que o controle fosse inserido na caixa de diálogo Inserir objeto.

*dwMiscStatus*<br/>
Contém um ou mais dos seguintes sinalizadores de status (para obter uma descrição dos sinalizadores, consulte enumeração OLEMISC no SDK do Windows):

- OLEMISC_RECOMPOSEONRESIZE

- OLEMISC_ONLYICONIC

- OLEMISC_INSERTNOTREPLACE

- OLEMISC_STATIC

- OLEMISC_CANTLINKINSIDE

- OLEMISC_CANLINKBYOLE1

- OLEMISC_ISLINKOBJECT

- OLEMISC_INSIDEOUT

- OLEMISC_ACTIVATEWHENVISIBLE

- OLEMISC_RENDERINGISDEVICEINDEPENDENT

- OLEMISC_INVISIBLEATRUNTIME

- OLEMISC_ALWAYSRUN

- OLEMISC_ACTSLIKEBUTTON

- OLEMISC_ACTSLIKELABEL

- OLEMISC_NOUIACTIVATE

- OLEMISC_ALIGNABLE

- OLEMISC_IMEMODE

- OLEMISC_SIMPLEFRAME

- OLEMISC_SETCLIENTSITEFIRST

*tlid*<br/>
A ID exclusiva da classe de controle.

*wVerMajor*<br/>
O número de versão principal da classe de controle.

*wVerMinor*<br/>
O número de versão secundária da classe de controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a classe de controle foi registrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso permite que o controle seja usado por contêineres que reconhecem o controle OLE. `AfxOleRegisterControlClass` atualiza o registro com o nome e o local do controle no sistema e também define o modelo de Threading ao qual o controle dá suporte no registro. Para obter mais informações, consulte a [Observação técnica 64](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Threading de modelo de apartamento em controles OLE" e [sobre processos e threads](/windows/win32/ProcThread/about-processes-and-threads) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCAxCtl#11](../../mfc/reference/codesnippet/cpp/registering-ole-controls_1.cpp)]

O exemplo acima demonstra como `AfxOleRegisterControlClass` é chamado com o sinalizador para insertável e o sinalizador para o modelo de apartamento or em conjunto para criar o sexto parâmetro:

[!code-cpp[NVC_MFCAxCtl#12](../../mfc/reference/codesnippet/cpp/registering-ole-controls_2.cpp)]

O controle será exibido na caixa de diálogo Inserir objeto para contêineres habilitados e será compatível com modelos de apartamento. Os controles de reconhecimento de modelos de apartamento devem garantir que os dados de classe estática sejam protegidos por bloqueios, de modo que, embora um controle em um apartamento esteja acessando os dados estáticos, ele não é desabilitado pelo Agendador antes de ser concluído e outra instância da mesma classe começa a usar os mesmos dados estáticos. Todos os acessos aos dados estáticos serão circundados pelo código de seção crítica.

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** afxctl. h

##  <a name="afxoleregisterpropertypageclass"></a>AfxOleRegisterPropertyPageClass

Registra a classe de página de propriedades com o banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleRegisterPropertyPageClass(
   HINSTANCE hInstance,
   REFCLSID  clsid,
   UINT idTypeName,
   int nRegFlags);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O identificador de instância do módulo associado à classe de página de propriedades.

*CLSID*<br/>
A ID de classe exclusiva da página de propriedades.

*idTypeName*<br/>
A ID de recurso da cadeia de caracteres que contém um nome legível pelo usuário para a página de propriedades.

*nRegFlags*<br/>
Pode conter o sinalizador:

- `afxRegApartmentThreading` define o modelo de threading no registro como ThreadingModel = Apartment.

> [!NOTE]
>  Nas versões do MFC anteriores ao MFC 4,2, o parâmetro **int** *nRegFlags* não estava disponível. Observe também que o sinalizador `afxRegInsertable` não é uma opção válida para páginas de propriedades e causará uma declaração no MFC, se estiver definido

### <a name="return-value"></a>Valor retornado

Diferente de zero se a classe de controle foi registrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso permite que a página de propriedades seja usada por contêineres que reconhecem o controle OLE. `AfxOleRegisterPropertyPageClass` atualiza o registro com o nome da página de propriedades e sua localização no sistema e também define o modelo de Threading ao qual o controle dá suporte no registro. Para obter mais informações, consulte a [Observação técnica 64](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Threading de modelo de apartamento em controles OLE" e [sobre processos e threads](/windows/win32/ProcThread/about-processes-and-threads) no SDK do Windows.

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** afxctl. h

##  <a name="afxoleregistertypelib"></a>AfxOleRegisterTypeLib

Registra a biblioteca de tipos com o banco de dados de registro do Windows e permite que a biblioteca de tipos seja usada por outros contêineres com reconhecimento de controle OLE.

```
BOOL AfxOleRegisterTypeLib(
    HINSTANCE hInstance,
    REFGUID tlid,
    LPCTSTR pszFileName = NULL,
    LPCTSTR pszHelpDir  = NULL);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O identificador de instância do aplicativo associado à biblioteca de tipos.

*tlid*<br/>
A ID exclusiva da biblioteca de tipos.

*pszFileName*<br/>
Aponta para o nome de arquivo opcional de uma biblioteca de tipos localizada (. TLB) para o controle.

*pszHelpDir*<br/>
O nome do diretório em que o arquivo de ajuda para a biblioteca de tipos pode ser encontrado. Se for NULL, o arquivo de ajuda será considerado no mesmo diretório que a própria biblioteca de tipos.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a biblioteca de tipos foi registrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função atualiza o registro com o nome da biblioteca de tipos e sua localização no sistema.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCAutomation#7](../../mfc/codesnippet/cpp/registering-ole-controls_3.cpp)]

[!code-cpp[NVC_MFCAutomation#8](../../mfc/codesnippet/cpp/registering-ole-controls_4.cpp)]

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** AFXDISP. h

##  <a name="afxoleunregisterclass"></a>AfxOleUnregisterClass

Remove a entrada de classe de página de controle ou de Propriedade do banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleUnregisterClass(REFCLSID clsID, LPCSTR pszProgID);
```

### <a name="parameters"></a>Parâmetros

*clsID*<br/>
A ID de classe exclusiva da página de controle ou de propriedade.

*pszProgID*<br/>
A ID de programa exclusiva da página de controle ou de propriedade.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a classe do controle ou da página de propriedades tiver sido cancelada com êxito; caso contrário, 0.

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** afxctl. h

##  <a name="afxoleunregistertypelib"></a>AfxOleUnregisterTypeLib

Chame essa função para remover a entrada da biblioteca de tipos do banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleUnregisterTypeLib(REFGUID tlID);
```

### <a name="parameters"></a>Parâmetros

*tlID*<br/>
A ID exclusiva da biblioteca de tipos.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a biblioteca de tipos tiver sido desregistrada com êxito; caso contrário, 0.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCAxCtl#13](../../mfc/reference/codesnippet/cpp/registering-ole-controls_5.cpp)]

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** AFXDISP. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

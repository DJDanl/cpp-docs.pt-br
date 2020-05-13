---
title: Registrando controles OLE
ms.date: 11/04/2016
helpviewer_keywords:
- registering OLE controls
- OLE controls [MFC], registering
ms.assetid: 73c45b7f-7dbc-43f5-bd17-dd77c6acec72
ms.openlocfilehash: 2f2d7872e8b9369b5eef283e5b52a54c29afd563
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372967"
---
# <a name="registering-ole-controls"></a>Registrando controles OLE

Os controles OLE, como outros objetos de servidor OLE, podem ser acessados por outros aplicativos com reconhecimento de OLE. Isso é conseguido registrando a biblioteca e a classe do tipo de controle.

As seguintes funções permitem adicionar e remover a classe do controle, páginas de propriedade e biblioteca de tipo no banco de dados de registro do Windows:

### <a name="registering-ole-controls"></a>Registrando controles OLE

|||
|-|-|
|[AfxOleRegisterControlClass](#afxoleregistercontrolclass)|Adiciona a classe do controle ao banco de dados de registro.|
|[AfxOleRegisterPropertyPageClass](#afxoleregisterpropertypageclass)|Adiciona uma página de propriedade de controle ao banco de dados de registro.|
|[AfxOleRegisterTypeLib](#afxoleregistertypelib)|Adiciona a biblioteca de tipo do controle ao banco de dados de registro.|
|[AfxOleUnregisterClass](#afxoleunregisterclass)|Remove uma classe de controle ou uma classe de página de propriedade do banco de dados de registro.|
|[AfxOleUnregisterTypeLib](#afxoleunregistertypelib)|Remove a biblioteca de tipos de controle do banco de dados de registro.|

`AfxOleRegisterTypeLib`é tipicamente chamado em um controle `DllRegisterServer`de implementação dll de . Da mesma `AfxOleUnregisterTypeLib` forma, `DllUnregisterServer`é chamado por . `AfxOleRegisterControlClass`, `AfxOleRegisterPropertyPageClass`e `AfxOleUnregisterClass` são tipicamente `UpdateRegistry` chamados pela função membro da fábrica de classe de um controle ou página de propriedade.

## <a name="afxoleregistercontrolclass"></a><a name="afxoleregistercontrolclass"></a>Afxoleregistercontrolclass

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
A alça de instância do módulo associada à classe de controle.

*clsid*<br/>
A identificação única da classe do controle.

*pszProgID*<br/>
A identificação única do programa do controle.

*idTypeName*<br/>
O ID de recurso da string que contém um nome de tipo legível pelo usuário para o controle.

*idBitmap*<br/>
O ID de recurso do bitmap usado para representar o controle OLE em uma barra de ferramentas ou paleta.

*nBandeiras de Reg*<br/>
Contém uma ou mais das seguintes bandeiras:

- `afxRegInsertable`Permite que o controle apareça na caixa de diálogo Inserir objeto para objetos OLE.

- `afxRegApartmentThreading`Define o modelo de rosca no registro como ThreadingModel=Apartment.

- `afxRegFreeThreading`Define o modelo de rosca no registro como ThreadingModel=Free.

   Você pode combinar `afxRegApartmentThreading` as `afxRegFreeThreading` duas bandeiras e definir ThreadingModel=Both. Consulte [InprocServer32](/windows/win32/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.

> [!NOTE]
> Nas versões MFC antes do MFC 4.2, o parâmetro **int** *nRegFlags* era um parâmetro BOOL, *bInsertable,* que permitia ou proibia que o controle fosse inserido na caixa de diálogo Insert Object.

*dwMiscStatus*<br/>
Contém uma ou mais das seguintes bandeiras de status (para uma descrição das bandeiras, consulte enumeração OLEMISC no SDK do Windows):

- OLEMISC_RECOMPOSEONRESIZE

- OLEMISC_ONLYICONIC

- OLEMISC_INSERTNOTREPLACE

- OLEMISC_STATIC

- OLEMISC_CANTLINKINSIDE

- OLEMISC_CANLINKBYOLE1

- OLEMISC_ISLINKOBJECT

- OLEMISC_INSIDEOUT

- Olemisc_activatewhenvisible

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
A identificação única da classe de controle.

*wVerMajor*<br/>
O número da versão principal da classe de controle.

*wVerMinor*<br/>
O número da versão menor da classe de controle.

### <a name="return-value"></a>Valor retornado

Não zero se a classe de controle foi registrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso permite que o controle seja usado por recipientes que estejam cientes do controle de OLE. `AfxOleRegisterControlClass`atualiza o registro com o nome e a localização do controle no sistema e também define o modelo de rosca que o controle suporta no registro. Para obter mais informações, consulte [Nota Técnica 64](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Threading de modelo de apartamento em controles OLE", e [sobre processos e threads](/windows/win32/ProcThread/about-processes-and-threads) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAxCtl#11](../../mfc/reference/codesnippet/cpp/registering-ole-controls_1.cpp)]

O exemplo acima `AfxOleRegisterControlClass` demonstra como é chamado com a bandeira para inserção e a bandeira para o modelo de apartamento ORed em conjunto para criar o sexto parâmetro:

[!code-cpp[NVC_MFCAxCtl#12](../../mfc/reference/codesnippet/cpp/registering-ole-controls_2.cpp)]

O controle aparecerá na caixa de diálogo Inserir objeto para recipientes habilitados e será um modelo de apartamento. Os controles de reconhecimento de modelo de apartamento devem garantir que os dados de classe estática sejam protegidos por bloqueios, de modo que, enquanto um controle em um apartamento está acessando os dados estáticos, ele não é desativado pelo agendador antes de ser concluído, e outra instância da mesma classe começa a usar os mesmos dados estáticos. Quaisquer acessos aos dados estáticos serão cercados por código de seção crítico.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="afxoleregisterpropertypageclass"></a><a name="afxoleregisterpropertypageclass"></a>AfxOleRegisterPropertyPageClass

Registra a classe de página de propriedade com o banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleRegisterPropertyPageClass(
   HINSTANCE hInstance,
   REFCLSID  clsid,
   UINT idTypeName,
   int nRegFlags);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
A alça de instância do módulo associada à classe de página de propriedade.

*clsid*<br/>
A identificação de classe única da página de propriedade.

*idTypeName*<br/>
O ID de recurso da string que contém um nome legível pelo usuário para a página de propriedade.

*nBandeiras de Reg*<br/>
Pode conter a bandeira:

- `afxRegApartmentThreading`Define o modelo de rosca no registro como ThreadingModel = Apartamento.

> [!NOTE]
> Nas versões MFC anteriores ao MFC 4.2, o parâmetro **int** *nRegFlags* não estava disponível. Observe também `afxRegInsertable` que o sinalizador não é uma opção válida para páginas de propriedade e causará um ASSERT no MFC se for definido

### <a name="return-value"></a>Valor retornado

Não zero se a classe de controle foi registrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso permite que a página de propriedade seja usada por contêineres que estejam cientes do controle oLE. `AfxOleRegisterPropertyPageClass`atualiza o registro com o nome da página de propriedade e sua localização no sistema e também define o modelo de rosca que o controle suporta no registro. Para obter mais informações, consulte [Nota Técnica 64](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Threading de modelo de apartamento em controles OLE", e [sobre processos e threads](/windows/win32/ProcThread/about-processes-and-threads) no SDK do Windows.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="afxoleregistertypelib"></a><a name="afxoleregistertypelib"></a>Afxoleregistertypelib

Registra a biblioteca de tipo com o banco de dados de registro do Windows e permite que a biblioteca do tipo seja usada por outros contêineres que estejam cientes do controle de OLE.

```
BOOL AfxOleRegisterTypeLib(
    HINSTANCE hInstance,
    REFGUID tlid,
    LPCTSTR pszFileName = NULL,
    LPCTSTR pszHelpDir  = NULL);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O punho de instância do aplicativo associado à biblioteca do tipo.

*tlid*<br/>
A identificação única da biblioteca do tipo.

*Pszfilename*<br/>
Aponta para o nome de arquivo opcional de uma biblioteca de tipo localizada (. Arquivo TLB) para o controle.

*pszHelpDir*<br/>
O nome do diretório onde o arquivo de ajuda para a biblioteca do tipo pode ser encontrado. Se NULL, o arquivo de ajuda é assumido como sendo no mesmo diretório que a própria biblioteca do tipo.

### <a name="return-value"></a>Valor retornado

Não zero se a biblioteca do tipo foi registrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função atualiza o registro com o nome da biblioteca do tipo e sua localização no sistema.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#7](../../mfc/codesnippet/cpp/registering-ole-controls_3.cpp)]

[!code-cpp[NVC_MFCAutomation#8](../../mfc/codesnippet/cpp/registering-ole-controls_4.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="afxoleunregisterclass"></a><a name="afxoleunregisterclass"></a>AfxOleUnregisterClass

Remove a entrada da classe de controle ou página de propriedade do banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleUnregisterClass(REFCLSID clsID, LPCSTR pszProgID);
```

### <a name="parameters"></a>Parâmetros

*Clsid*<br/>
O ID de classe exclusivo da página de controle ou propriedade.

*pszProgID*<br/>
O ID do programa exclusivo da página de controle ou propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a classe de controle ou página de propriedade não foi registrada com sucesso; caso contrário, 0.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="afxoleunregistertypelib"></a><a name="afxoleunregistertypelib"></a>AfxOleUnregisterTypeLib

Chame esta função para remover a entrada da biblioteca do tipo do banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleUnregisterTypeLib(REFGUID tlID);
```

### <a name="parameters"></a>Parâmetros

*iID*<br/>
A identificação única da biblioteca do tipo.

### <a name="return-value"></a>Valor retornado

Não zero se a biblioteca do tipo não foi registrada com sucesso; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAxCtl#13](../../mfc/reference/codesnippet/cpp/registering-ole-controls_5.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

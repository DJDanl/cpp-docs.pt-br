---
title: Registrando controles OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.ole
dev_langs:
- C++
helpviewer_keywords:
- registering OLE controls
- OLE controls [MFC], registering
ms.assetid: 73c45b7f-7dbc-43f5-bd17-dd77c6acec72
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 27e0589e7ba0b2428f4cfea1d2561ef5e666641e
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50054157"
---
# <a name="registering-ole-controls"></a>Registrando controles OLE

Controles OLE, como outros objetos de servidor OLE, podem ser acessados por outros aplicativos com reconhecimento de OLE. Isso é feito registrando a biblioteca de tipos e a classe do controle.

As funções a seguir permitem adicionar e remover a classe do controle, páginas de propriedades e biblioteca de tipos do banco de dados de registro do Windows:

### <a name="registering-ole-controls"></a>Registrando controles OLE

|||
|-|-|
|[AfxOleRegisterControlClass](#afxoleregistercontrolclass)|Adiciona a classe do controle para o banco de dados de registro.|
|[AfxOleRegisterPropertyPageClass](#afxoleregisterpropertypageclass)|Adiciona uma página de propriedades de controle para o banco de dados de registro.|
|[AfxOleRegisterTypeLib](#afxoleregistertypelib)|Adiciona a biblioteca de tipos do controle para o banco de dados de registro.|
|[AfxOleUnregisterClass](#afxoleunregisterclass)|Remove uma classe de controle ou uma classe de página de propriedade do banco de dados de registro.|
|[AfxOleUnregisterTypeLib](#afxoleunregistertypelib)|Remove a biblioteca de tipos do controle do banco de dados de registro.|

`AfxOleRegisterTypeLib` normalmente é chamado na implementação de uma DLL controle do `DllRegisterServer`. Da mesma forma, `AfxOleUnregisterTypeLib` é chamado pelo `DllUnregisterServer`. `AfxOleRegisterControlClass`, `AfxOleRegisterPropertyPageClass`, e `AfxOleUnregisterClass` normalmente são chamados pelo `UpdateRegistry` a função de membro da página de fábrica ou a propriedade de classe do controle.

##  <a name="afxoleregistercontrolclass"></a>  AfxOleRegisterControlClass

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
O identificador da instância do módulo associado com a classe de controle.

*clsid*<br/>
A ID exclusiva de classe do controle.

*pszProgID*<br/>
A ID exclusiva do programa do controle.

*idTypeName*<br/>
A ID de recurso da cadeia de caracteres que contém um nome de tipo legível pelo usuário para o controle.

*idBitmap*<br/>
A ID de recurso do bitmap usado para representar o controle OLE em uma barra de ferramentas ou paleta.

*nRegFlags*<br/>
Contém um ou mais dos seguintes sinalizadores:

- `afxRegInsertable` Permite que o controle apareça na caixa de diálogo Inserir objeto para objetos OLE.

- `afxRegApartmentThreading` Define o modelo de threading no registro para ThreadingModel = Apartment.

- `afxRegFreeThreading` Define o modelo de threading no registro para ThreadingModel = gratuito.

   Você pode combinar os dois sinalizadores `afxRegApartmentThreading` e `afxRegFreeThreading` definir ThreadingModel = Both. Ver [InprocServer32](/windows/desktop/com/inprocserver32) no SDK do Windows para obter mais informações sobre o registro do modelo de threading.

> [!NOTE]
>  Nas versões MFC antes 4.2 do MFC, o **int** *nRegFlags* parâmetro era um parâmetro BOOL *bInsertable*, que permitidos ou não o controle a ser inserido da inserção Caixa de diálogo do objeto.

*dwMiscStatus*<br/>
Contém um ou mais dos seguintes sinalizadores de status (para obter uma descrição dos sinalizadores, consulte a enumeração de OLEMISC no SDK do Windows):

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
A ID exclusiva da classe do controle.

*wVerMajor*<br/>
O número de versão principal da classe do controle.

*wVerMinor*<br/>
O número de versão secundária da classe do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a classe de controle tiver sido registrada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso permite que o controle a ser usada por contêineres que estão cientes de controle OLE. `AfxOleRegisterControlClass` atualiza o registro com o nome do controle e o local no sistema e também define o modelo de threading que permite o controle no registro. Para obter mais informações, consulte [64 de observação técnica](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Modelo Apartment Threading em OLE controles," e [sobre processos e Threads](/windows/desktop/ProcThread/about-processes-and-threads) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAxCtl#11](../../mfc/reference/codesnippet/cpp/registering-ole-controls_1.cpp)]

O exemplo acima demonstra como `AfxOleRegisterControlClass` é chamado com o sinalizador para inserível e o sinalizador do apartment ORed juntas para criar o sexto parâmetro do modelo:

[!code-cpp[NVC_MFCAxCtl#12](../../mfc/reference/codesnippet/cpp/registering-ole-controls_2.cpp)]

O controle será exibido na caixa de diálogo Inserir objeto para contêineres habilitados, e ele estará ciente de modelo de segmentação. Controles de reconhecimento de modelo de apartment devem garantir que dados são protegidos por bloqueios, de classe estática para que, enquanto um controle em um apartment está acessando os dados estáticos, ele não está desabilitado pelo Agendador antes que ele for concluído, e começa a usar outra instância da mesma classe os mesmos dados estáticos. Qualquer acessos aos dados estáticos ficará cercados por código de seção crítica.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="afxoleregisterpropertypageclass"></a>  AfxOleRegisterPropertyPageClass

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
O identificador da instância do módulo associado com a classe de página de propriedade.

*clsid*<br/>
A ID de classe exclusivos da página de propriedades.

*idTypeName*<br/>
A ID de recurso da cadeia de caracteres que contém um nome legível pelo usuário para a página de propriedades.

*nRegFlags*<br/>
Pode conter o sinalizador:

- `afxRegApartmentThreading` Define o modelo de threading no registro para ThreadingModel = Apartment.

> [!NOTE]
>  Nas versões MFC antes da MFC 4.2, o **int** *nRegFlags* parâmetro não estava disponível. Observe também que o `afxRegInsertable` sinalizador não é uma opção válida para páginas de propriedades e fará com que uma declaração no MFC se ela estiver definida

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a classe de controle tiver sido registrada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso permite que a página de propriedade a ser usada por contêineres que estão cientes de controle OLE. `AfxOleRegisterPropertyPageClass` atualiza o registro com o nome da página de propriedade e sua localização no sistema e também define o modelo de threading que permite o controle no registro. Para obter mais informações, consulte [64 de observação técnica](../../mfc/tn064-apartment-model-threading-in-activex-controls.md), "Modelo Apartment Threading em OLE controles," e [sobre processos e Threads](/windows/desktop/ProcThread/about-processes-and-threads) no SDK do Windows.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="afxoleregistertypelib"></a>  AfxOleRegisterTypeLib

Registra a biblioteca de tipos com o banco de dados de registro do Windows e permite que a biblioteca de tipos a ser usado por outros contêineres que estão cientes de controle OLE.

```
BOOL AfxOleRegisterTypeLib(
    HINSTANCE hInstance,
    REFGUID tlid,
    LPCTSTR pszFileName = NULL,
    LPCTSTR pszHelpDir  = NULL);
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
O identificador da instância do aplicativo associado com a biblioteca de tipos.

*tlid*<br/>
A ID exclusiva da biblioteca de tipos.

*pszFileName*<br/>
Aponta para o nome de arquivo opcional de uma biblioteca de tipo localizado (. Arquivo TLB) para o controle.

*pszHelpDir*<br/>
O nome do diretório onde o arquivo de Ajuda da biblioteca de tipos pode ser encontrado. Se for NULL, o arquivo de Ajuda deve para estar no mesmo diretório que a biblioteca de tipos.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a biblioteca de tipos foi registrada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função atualiza o registro com o nome da biblioteca de tipo e sua localização no sistema.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAutomation#7](../../mfc/codesnippet/cpp/registering-ole-controls_3.cpp)]

[!code-cpp[NVC_MFCAutomation#8](../../mfc/codesnippet/cpp/registering-ole-controls_4.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

##  <a name="afxoleunregisterclass"></a>  AfxOleUnregisterClass

Remove a entrada de classe de página de controle ou uma propriedade do banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleUnregisterClass(REFCLSID clsID, LPCSTR pszProgID);
```

### <a name="parameters"></a>Parâmetros

*clsID*<br/>
A ID de classe exclusivos da página de controle ou propriedade.

*pszProgID*<br/>
A ID exclusiva do programa do controle ou a propriedade da página.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a classe de página de controle ou uma propriedade foi cancelada com êxito; Caso contrário, 0.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

##  <a name="afxoleunregistertypelib"></a>  AfxOleUnregisterTypeLib

Chame essa função para remover a entrada de biblioteca de tipo do banco de dados de registro do Windows.

```
BOOL AFXAPI AfxOleUnregisterTypeLib(REFGUID tlID);
```

### <a name="parameters"></a>Parâmetros

*tlID*<br/>
A ID exclusiva da biblioteca de tipos.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a biblioteca de tipos foi cancelada com êxito; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAxCtl#13](../../mfc/reference/codesnippet/cpp/registering-ole-controls_5.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdisp.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

---
title: Macros e funções para gerenciar DLLs
ms.date: 03/27/2019
helpviewer_keywords:
- module macros in MFC
ms.assetid: 303f4161-cb5e-4099-81ad-acdb11aa60fb
ms.openlocfilehash: b27f8763b60dc7ce3ee074cad1365e7e1de3a7e6
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421334"
---
# <a name="macros-and-functions-for-managing-dlls"></a>Macros e funções para gerenciar DLLs

|||
|-|-|
|[AFX_EXT_CLASS](#afx_ext_class)]|Exporta classes.|
|[AFX_MANAGE_STATE](#afx_manage_state)|Proteger uma função exportada em uma DLL.|
|[AfxOleInitModule](#afxoleinitmodule)|Fornece suporte a OLE de uma DLL do MFC regular que é vinculada dinamicamente ao MFC.|
|[AfxNetInitModule](#afxnetinitmodule)|Fornece suporte a soquetes MFC de uma DLL do MFC regular que é vinculada dinamicamente ao MFC.|
|[AfxGetAmbientActCtx](#afxgetambientactctx)|Obtém o estado atual do sinalizador de estado por módulo.|
|[AfxGetStaticModuleState](#afxgetstaticmodulestate)|Define o estado do módulo antes da inicialização e/ou para restaurar o estado anterior do módulo após a limpeza.|
|[AfxInitExtensionModule](#afxinitextensionmodule)|Inicializa a DLL.|
|[AfxSetAmbientActCtx](#afxsetambientactctx)|Defina o sinalizador de estado por módulo, que afeta o comportamento de WinSxS do MFC.|
|[AfxTermExtensionModule](#afxtermextensionmodule)|Permite que o MFC Limpe a DLL de extensão do MFC quando cada processo é desanexado da DLL.|

## <a name="afx_ext_class"></a>AFX_EXT_CLASS

As [DLLs de extensão do MFC](../../build/extension-dlls.md) usam a macro AFX_EXT_CLASS para exportar classes; os executáveis que vinculam à DLL de extensão do MFC usam a macro para importar classes.

### <a name="remarks"></a>Comentários

Com a macro AFX_EXT_CLASS, os mesmos arquivos de cabeçalho usados para criar a DLL de extensão MFC podem ser usados com os executáveis vinculados à DLL.

No arquivo de cabeçalho para sua DLL, adicione a palavra-chave AFX_EXT_CLASS à declaração de sua classe da seguinte maneira:

```cpp
class AFX_EXT_CLASS CMyClass : public CDocument
{
// <body of class>
};
```

Para obter mais informações, consulte [exportar e importar usando o AFX_EXT_CLASS](../../build/exporting-and-importing-using-afx-ext-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXV_DLL. h

## <a name="afx_manage_state"></a>AFX_MANAGE_STATE

Chame essa macro para proteger uma função exportada em uma DLL.

### <a name="syntax"></a>Sintaxe

```
AFX_MANAGE_STATE(AFX_MODULE_STATE* pModuleState )
```

### <a name="parameters"></a>parâmetros

*pModuleState*<br/>
Um ponteiro para uma estrutura de `AFX_MODULE_STATE`.

### <a name="remarks"></a>Comentários

Quando essa macro é chamada, *pModuleState* é o estado de módulo efetivo para o restante do escopo de contenção imediato. Ao sair do escopo, o estado do módulo efetivo anterior será restaurado automaticamente.
A estrutura de `AFX_MODULE_STATE` contém dados globais para o módulo, ou seja, a parte do estado do módulo que é enviada por Push ou exibida.

Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Se você tiver uma função exportada em uma DLL, como uma que inicia uma caixa de diálogo na DLL, esse modelo será armazenado no módulo de DLL. Você precisa alternar o estado do módulo para que o identificador correto seja usado. Você pode fazer isso adicionando o seguinte código ao início da função:

```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
```

Isso troca o estado atual do módulo pelo estado retornado de [AfxGetStaticModuleState](#afxgetstaticmodulestate) até o final do escopo atual.

Para obter mais informações sobre os Estados de módulo e o MFC, consulte "Gerenciando os dados de estado dos módulos do MFC" em [criando novos documentos, janelas e exibições](../creating-new-documents-windows-and-views.md) e [Nota técnica 58](../tn058-mfc-module-state-implementation.md).

> [!NOTE]
>  Quando o MFC cria um contexto de ativação para um assembly, ele usa [AfxWinInit](application-information-and-management.md#afxwininit) para criar o contexto e `AFX_MANAGE_STATE` para ativá-lo e desativá-lo. Observe também que `AFX_MANAGE_STATE` está habilitada para bibliotecas do MFC estáticos, bem como DLLs do MFC, para permitir que o código MFC seja executado no contexto de ativação apropriado selecionado pela DLL do usuário. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../support-for-activation-contexts-in-the-mfc-module-state.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstat_. h

## <a name="a-nameafxoleinitmodulea-afxoleinitmodule"></a><a name="afxoleinitmodule"><a/> AfxOleInitModule

Para o suporte a OLE de uma DLL do MFC regular que é vinculada dinamicamente ao MFC, chame essa função na função `CWinApp::InitInstance` da DLL do MFC regular para inicializar a DLL OLE do MFC.

### <a name="syntax"></a>Sintaxe

```
void AFXAPI AfxOleInitModule( );
```

### <a name="remarks"></a>Comentários

A DLL OLE do MFC é uma DLL de extensão do MFC; para que uma DLL de extensão do MFC seja conectada a uma cadeia de `CDynLinkLibrary`, ela deve criar um objeto `CDynLinkLibrary` no contexto de cada módulo que a utilizará. `AfxOleInitModule` cria o objeto de `CDynLinkLibrary` no contexto da DLL do MFC regular para que ele seja conectado à cadeia de objetos `CDynLinkLibrary` da DLL do MFC regular.

Se você estiver criando um controle OLE e estiver usando `COleControlModule`, não deverá chamar `AfxOleInitModule` porque a função de membro `InitInstance` para chamadas de `COleControlModule` `AfxOleInitModule`.

### <a name="requirements"></a>Requisitos

**Cabeçalho**: \<afxdll_. h >

## <a name="afxnetinitmodule"></a>AfxNetInitModule

Para suporte a soquetes MFC de uma DLL do MFC regular que é vinculada dinamicamente ao MFC, adicione uma chamada para essa função na função `CWinApp::InitInstance` da DLL do MFC regular para inicializar a DLL de soquetes do MFC.

### <a name="syntax"></a>Sintaxe

```
void AFXAPI AfxNetInitModule( );
```

### <a name="remarks"></a>Comentários

A DLL de soquetes do MFC é uma DLL de extensão do MFC; para que uma DLL de extensão do MFC seja conectada a uma cadeia de `CDynLinkLibrary`, ela deve criar um objeto `CDynLinkLibrary` no contexto de cada módulo que a utilizará. `AfxNetInitModule` cria o objeto de `CDynLinkLibrary` no contexto da DLL do MFC regular para que ele seja conectado à cadeia de objetos `CDynLinkLibrary` da DLL do MFC regular.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** \<afxdll_. h >

## <a name="afxgetambientactctx"></a>AfxGetAmbientActCtx

Use essa função para obter o estado atual do sinalizador de estado por módulo, que afeta o comportamento de WinSxS do MFC.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxGetAmbientActCtx();
```

### <a name="return-value"></a>Valor retornado

Valor atual do sinalizador de estado do módulo.

### <a name="remarks"></a>Comentários

Quando o sinalizador é definido (que é o padrão) e um thread entra em um módulo do MFC (consulte [AFX_MANAGE_STATE](#afx_manage_state)), o contexto do módulo é ativado.

Se o sinalizador não estiver definido, o contexto do módulo não será ativado na entrada.

O contexto de um módulo é determinado de seu manifesto, normalmente inserido em recursos de módulo.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcomctl32. h

## <a name="afxgetstaticmodulestate"></a>AfxGetStaticModuleState

Chame essa função para definir o estado do módulo antes da inicialização e/ou para restaurar o estado anterior do módulo após a limpeza.

### <a name="syntax"></a>Sintaxe

```
AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState( );
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de `AFX_MODULE_STATE`.

### <a name="remarks"></a>Comentários

A estrutura de `AFX_MODULE_STATE` contém dados globais para o módulo, ou seja, a parte do estado do módulo que é enviada por Push ou exibida.

Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Se você tiver uma função exportada em uma DLL, como uma que inicia uma caixa de diálogo na DLL, esse modelo será armazenado no módulo de DLL. Você precisa alternar o estado do módulo para que o identificador correto seja usado. Você pode fazer isso adicionando o seguinte código ao início da função:

```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
```

Isso troca o estado atual do módulo pelo estado retornado de `AfxGetStaticModuleState` até o final do escopo atual.

Para obter mais informações sobre os Estados de módulo e o MFC, consulte "Gerenciando os dados de estado dos módulos do MFC" em [criando novos documentos, janelas e exibições](../creating-new-documents-windows-and-views.md) e [Nota técnica 58](../tn058-mfc-module-state-implementation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstat_. h

## <a name="afxinitextensionmodule"></a>AfxInitExtensionModule

Chame essa função em uma DLL de extensão do MFC `DllMain` para inicializar a DLL.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxInitExtensionModule( AFX_EXTENSION_MODULE& state,  HMODULE hModule );
```

### <a name="parameters"></a>parâmetros

*state*<br/>
Uma referência à estrutura de [estrutura de AFX_EXTENSION_MODULE](afx-extension-module-structure.md) que conterá o estado do módulo DLL de extensão do MFC após a inicialização. O estado inclui uma cópia dos objetos de classe de tempo de execução que foram inicializados pela DLL de extensão do MFC como parte da construção de objeto estático normal executada antes da `DllMain` ser inserida.

*hModule*<br/>
Um identificador do módulo DLL de extensão do MFC.

### <a name="return-value"></a>Valor retornado

TRUE se a DLL de extensão do MFC for inicializada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Por exemplo:

```cpp
static AFX_EXTENSION_MODULE NVC_MFC_DLLDLL = { NULL, NULL };
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    // Remove this if you use lpReserved
    UNREFERENCED_PARAMETER(lpReserved);

    if (dwReason == DLL_PROCESS_ATTACH)
    {
        TRACE0("NVC_MFC_DLL.DLL Initializing!\n");

        // MFC extension DLL one-time initialization
        if (!AfxInitExtensionModule(NVC_MFC_DLLDLL, hInstance))
            return 0;
...
```

`AfxInitExtensionModule` faz uma cópia do HMODULE da DLL e captura as classes de tempo de execução da DLL (estruturas de`CRuntimeClass`), bem como suas fábricas de objeto (`COleObjectFactory` objetos) para uso posterior quando o objeto `CDynLinkLibrary` é criado.
As DLLs de extensão do MFC precisam fazer duas coisas em sua função `DllMain`:

- Chame [AfxInitExtensionModule](#afxinitextensionmodule) e verifique o valor de retorno.

- Crie um objeto `CDynLinkLibrary` se a DLL estiver exportando objetos de [estrutura CRuntimeClass](cruntimeclass-structure.md) ou tiver seus próprios recursos personalizados.

Você pode chamar `AfxTermExtensionModule` para limpar a DLL de extensão do MFC quando cada processo se desanexar da DLL de extensão do MFC (que acontece quando o processo é encerrado, ou quando a DLL é descarregada como resultado de uma chamada de `AfxFreeLibrary`).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdll_. h

## <a name="afxsetambientactctx"></a>AfxSetAmbientActCtx

Use essa função para definir o sinalizador de estado por módulo, que afeta o comportamento de WinSxS do MFC.

### <a name="syntax"></a>Sintaxe

```
void AFXAPI AfxSetAmbientActCtx(BOOL bSet);
```

### <a name="parameters"></a>parâmetros

*bSet*<br/>
Novo valor do sinalizador de estado do módulo.

### <a name="remarks"></a>Comentários

Quando o sinalizador é definido (que é o padrão) e um thread entra em um módulo do MFC (consulte [AFX_MANAGE_STATE](#afx_manage_state)), o contexto do módulo é ativado.
Se o sinalizador não estiver definido, o contexto do módulo não será ativado na entrada.
O contexto de um módulo é determinado de seu manifesto, normalmente inserido em recursos de módulo.

### <a name="example"></a>Exemplo

```cpp
BOOL CMFCListViewApp::InitInstance()
{
   AfxSetAmbientActCtx(FALSE);
   // Remainder of function definition omitted.
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcomctl32. h

## <a name="afxtermextensionmodule"></a>AfxTermExtensionModule

Chame essa função para permitir que o MFC Limpe a DLL de extensão do MFC quando cada processo se desanexar da DLL (que acontece quando o processo é encerrado ou quando a DLL é descarregada como resultado de uma chamada de `AfxFreeLibrary`).

### <a name="syntax"></a>Sintaxe

```
void AFXAPI AfxTermExtensionModule(  AFX_EXTENSION_MODULE& state,  BOOL bAll  = FALSE );
```

### <a name="parameters"></a>parâmetros

*state*<br/>
Uma referência à estrutura de [AFX_EXTENSION_MODULE](afx-extension-module-structure.md) que contém o estado do módulo DLL de extensão do MFC.

*bTodos*<br/>
Se for TRUE, limpe todos os módulos DLL de extensão do MFC. Caso contrário, limpe apenas o módulo DLL atual.

### <a name="remarks"></a>Comentários

`AfxTermExtensionModule` excluirá qualquer armazenamento local anexado ao módulo e removerá todas as entradas do cache de mapa de mensagens. Por exemplo:

```cpp
static AFX_EXTENSION_MODULE NVC_MFC_DLLDLL = { NULL, NULL };
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    // Remove this if you use lpReserved
    UNREFERENCED_PARAMETER(lpReserved);

    if (dwReason == DLL_PROCESS_ATTACH)
    {
        TRACE0("NVC_MFC_DLL.DLL Initializing!\n");

        // MFC extension DLL one-time initialization
        if (!AfxInitExtensionModule(NVC_MFC_DLLDLL, hInstance))
            return 0;

        new CMyDynLinkLibrary(NVC_MFC_DLLDLL);

    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        TRACE0("NVC_MFC_DLL.DLL Terminating!\n");

        // Terminate the library before destructors are called
        AfxTermExtensionModule(NVC_MFC_DLLDLL);
    }
    return 1;   // ok
}
```

Se seu aplicativo carregar e liberar DLLs de extensão do MFC dinamicamente, certifique-se de chamar `AfxTermExtensionModule`. Como a maioria das DLLs de extensão MFC não são carregadas dinamicamente (geralmente, elas são vinculadas por meio de suas bibliotecas de importação), normalmente, a chamada para `AfxTermExtensionModule` não é necessária.

As DLLs de extensão do MFC precisam chamar [AfxInitExtensionModule](#afxinitextensionmodule) em seus `DllMain`. Se a DLL estiver exportando objetos [CRuntimeClass](cruntimeclass-structure.md) ou tiver seus próprios recursos personalizados, você também precisará criar um objeto `CDynLinkLibrary` no `DllMain`.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdll_. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox)<br/>
[Gerenciando os dados de estado dos módulos MFC](../managing-the-state-data-of-mfc-modules.md)<br/>

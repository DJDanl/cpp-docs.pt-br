---
title: Macros e funções para gerenciamento de DLLs
ms.date: 03/27/2019
helpviewer_keywords:
- module macros in MFC
ms.assetid: 303f4161-cb5e-4099-81ad-acdb11aa60fb
ms.openlocfilehash: 42a08ff2e806acae6713c9df3fe170f7e89f05af
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751591"
---
# <a name="macros-and-functions-for-managing-dlls"></a>Macros e funções para gerenciamento de DLLs

|||
|-|-|
|[AFX_EXT_CLASS]](#afx_ext_class)|Classes de exportação.|
|[AFX_MANAGE_STATE](#afx_manage_state)|Proteger uma função exportada em uma DLL.|
|[AfxOleInitModule](#afxoleinitmodule)|Fornece suporte ao OLE de um DLL MFC regular que está dinamicamente ligado ao MFC.|
|[AfxNetInitModule](#afxnetinitmodule)|Fornece suporte a Soquetes MFC de uma DLL MFC regular que está dinamicamente ligada ao MFC.|
|[AfxGetAmbientActCtx](#afxgetambientactctx)|Obtém o estado atual da bandeira de estado por módulo.|
|[AfxGetStaticModuleState](#afxgetstaticmodulestate)|Define o estado do módulo antes da inicialização e/ou para restaurar o estado anterior do módulo após a limpeza.|
|[AfxInitExtensionModule](#afxinitextensionmodule)|Inicializa o DLL.|
|[AfxSetAmbientActCtx](#afxsetambientactctx)|defina a bandeira de estado por módulo, que afeta o comportamento do WinSxS do MFC.|
|[AfxTermExtensionModule](#afxtermextensionmodule)|Permite que o MFC limpe a dLL de extensão MFC quando cada processo se desprende da DLL.|

## <a name="afx_ext_class"></a><a name="afx_ext_class"></a>Afx_ext_class

[Os DLLs de extensão MFC](../../build/extension-dlls.md) usam o AFX_EXT_CLASS de macro para exportar classes; os executáveis que se ligam à extensão MFC DLL usam a macro para importar classes.

### <a name="remarks"></a>Comentários

Com a AFX_EXT_CLASS macro, os mesmos arquivos de cabeçalho usados para construir o DLL de extensão MFC podem ser usados com os executáveis que se conectam à DLL.

No arquivo de cabeçalho da sua DLL, adicione a palavra-chave AFX_EXT_CLASS à declaração da sua classe da seguinte forma:

```cpp
class AFX_EXT_CLASS CMyClass : public CDocument
{
// <body of class>
};
```

Para obter mais informações, consulte [Exportação e Importação usando AFX_EXT_CLASS](../../build/exporting-and-importing-using-afx-ext-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxv_dll.h

## <a name="afx_manage_state"></a><a name="afx_manage_state"></a>Afx_manage_state

Chame esta macro para proteger uma função exportada em uma DLL.

### <a name="syntax"></a>Sintaxe

```
AFX_MANAGE_STATE(AFX_MODULE_STATE* pModuleState )
```

### <a name="parameters"></a>Parâmetros

*Pmodulestate*<br/>
Um ponteiro `AFX_MODULE_STATE` para uma estrutura.

### <a name="remarks"></a>Comentários

Quando esta macro é invocada, *pModuleState* é o estado de módulo efetivo para o restante do escopo de contenção imediata. Ao sair do escopo, o estado de módulo efetivo anterior será automaticamente restaurado.
A `AFX_MODULE_STATE` estrutura contém dados globais para o módulo, ou seja, a parte do estado do módulo que é empurrada ou estourada.

Por padrão, o MFC usa a alça de recurso do aplicativo principal para carregar o modelo de recurso. Se você tiver uma função exportada em uma DLL, como aquela que lança uma caixa de diálogo na DLL, este modelo será realmente armazenado no módulo DLL. Você precisa trocar o estado do módulo para que a alça correta seja usada. Você pode fazer isso adicionando o seguinte código ao início da função:

```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
```

Isso troca o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](#afxgetstaticmodulestate) até o final do escopo atual.

Para obter mais informações sobre estados de módulo e MFC, consulte "Gerenciando os Dados estaduais dos Módulos MFC" na [Criação de Novos Documentos, Windows e Visualizações](../creating-new-documents-windows-and-views.md) e [Nota Técnica 58](../tn058-mfc-module-state-implementation.md).

> [!NOTE]
> Quando o MFC cria um contexto de ativação para um conjunto, ele usa [o AfxWinInit](application-information-and-management.md#afxwininit) para criar o contexto e `AFX_MANAGE_STATE` ativá-lo e desativá-lo. Observe também `AFX_MANAGE_STATE` que está habilitado para bibliotecas MFC estáticas, bem como DLLs MFC, a fim de permitir que o código MFC seja executado no contexto de ativação adequado selecionado pelo DLL do usuário. Para obter mais informações, consulte [Suporte para Contextos de Ativação no Estado do Módulo MFC](../support-for-activation-contexts-in-the-mfc-module-state.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstat_.h

## <a name="a-nameafxoleinitmodule-afxoleinitmodule"></a><a name="afxoleinitmodule"><a/>Afxoleinitmodule

Para obter suporte ao OLE de uma DLL MFC regular que esteja dinamicamente `CWinApp::InitInstance` ligada ao MFC, ligue para esta função na função do MFC DLL regular para inicializar o DLL MFC OLE.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI AfxOleInitModule( );
```

### <a name="remarks"></a>Comentários

O MFC OLE DLL é uma dll de extensão MFC; para que uma DLL de extensão `CDynLinkLibrary` MFC seja conectada `CDynLinkLibrary` a uma cadeia, ela deve criar um objeto no contexto de cada módulo que irá usá-lo. `AfxOleInitModule`cria `CDynLinkLibrary` o objeto no contexto do DLL MFC regular para `CDynLinkLibrary` que ele seja conectado à cadeia de objetos do DLL MFC regular.

Se você estiver construindo um controle `COleControlModule`OLE e `AfxOleInitModule` estiver `InitInstance` usando, `COleControlModule` `AfxOleInitModule`você não deve ligar porque a função de membro para chamadas .

### <a name="requirements"></a>Requisitos

**Cabeçalho**: \<afxdll_.h>

## <a name="afxnetinitmodule"></a><a name="afxnetinitmodule"></a>Afxnetinitmodule

Para o suporte a Soquetes MFC de uma DLL MFC regular que está dinamicamente `CWinApp::InitInstance` ligada ao MFC, adicione uma chamada a esta função na função de DLL do MFC regular para inicializar o DLL do Soquete SopéM.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI AfxNetInitModule( );
```

### <a name="remarks"></a>Comentários

O DLL de soquetes MFC é uma dll de extensão MFC; para que uma DLL de extensão `CDynLinkLibrary` MFC seja conectada `CDynLinkLibrary` a uma cadeia, ela deve criar um objeto no contexto de cada módulo que irá usá-lo. `AfxNetInitModule`cria `CDynLinkLibrary` o objeto no contexto do DLL MFC regular para `CDynLinkLibrary` que ele seja conectado à cadeia de objetos do DLL MFC regular.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** \<afxdll_.h>

## <a name="afxgetambientactctx"></a><a name="afxgetambientactctx"></a>AfxGetAmbientActCtx

Use esta função para obter o estado atual da bandeira de estado por módulo, que afeta o comportamento WinSxS do MFC.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxGetAmbientActCtx();
```

### <a name="return-value"></a>Valor retornado

Valor atual da bandeira do estado do módulo.

### <a name="remarks"></a>Comentários

Quando o sinalizador é definido (que é o padrão) e um segmento entra em um módulo MFC (veja [AFX_MANAGE_STATE),](#afx_manage_state)o contexto do módulo é ativado.

Se o sinalizador não estiver definido, o contexto do módulo não será ativado na entrada.

O contexto de um módulo é determinado a partir de seu manifesto, geralmente incorporado em recursos de módulo.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcomctl32.h

## <a name="afxgetstaticmodulestate"></a><a name="afxgetstaticmodulestate"></a>Afxgetstaticmodulestate

Chame esta função para definir o estado do módulo antes da inicialização e/ou para restaurar o estado anterior do módulo após a limpeza.

### <a name="syntax"></a>Sintaxe

```
AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState( );
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `AFX_MODULE_STATE` para uma estrutura.

### <a name="remarks"></a>Comentários

A `AFX_MODULE_STATE` estrutura contém dados globais para o módulo, ou seja, a parte do estado do módulo que é empurrada ou estourada.

Por padrão, o MFC usa a alça de recurso do aplicativo principal para carregar o modelo de recurso. Se você tiver uma função exportada em uma DLL, como aquela que lança uma caixa de diálogo na DLL, este modelo será realmente armazenado no módulo DLL. Você precisa trocar o estado do módulo para que a alça correta seja usada. Você pode fazer isso adicionando o seguinte código ao início da função:

```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
```

Isso troca o estado atual do módulo `AfxGetStaticModuleState` com o estado retornado até o final do escopo atual.

Para obter mais informações sobre estados de módulo e MFC, consulte "Gerenciando os Dados estaduais dos Módulos MFC" na [Criação de Novos Documentos, Windows e Visualizações](../creating-new-documents-windows-and-views.md) e [Nota Técnica 58](../tn058-mfc-module-state-implementation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstat_.h

## <a name="afxinitextensionmodule"></a>AfxInitExtensionModule

Chame esta função em uma extensão `DllMain` MFC DLL's para inicializar o DLL.

### <a name="syntax"></a>Sintaxe

```
BOOL AFXAPI AfxInitExtensionModule( AFX_EXTENSION_MODULE& state,  HMODULE hModule );
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Uma referência à estrutura [AFX_EXTENSION_MODULE](afx-extension-module-structure.md) estrutura que conterá o estado do módulo DLL de extensão MFC após a inicialização. O estado inclui uma cópia dos objetos de classe de tempo de execução que foram inicializados `DllMain` pela extensão MFC DLL como parte da construção normal de objetos estáticos executadas antes de ser inserida.

*Hmodule*<br/>
Uma alça do módulo DLL de extensão MFC.

### <a name="return-value"></a>Valor retornado

TRUE se a dLL de extensão MFC for inicializada com sucesso; caso contrário, FALSE.

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

`AfxInitExtensionModule`faz uma cópia do HMODULE da DLL e captura as classes`CRuntimeClass` de tempo de execução (estruturas) da DLL, bem como suas fábricas de objetos (objetos)`COleObjectFactory` para uso posteriormente quando o `CDynLinkLibrary` objeto é criado.
Os DLLs de extensão MFC `DllMain` precisam fazer duas coisas em sua função:

- Ligue para [a AfxInitExtensionModule](#afxinitextensionmodule) e verifique o valor de retorno.

- Crie `CDynLinkLibrary` um objeto se a DLL estiver exportando objetos [cruntimeClass Structure](cruntimeclass-structure.md) ou tiver seus próprios recursos personalizados.

Você pode `AfxTermExtensionModule` ligar para limpar a dLL de extensão MFC quando cada processo se desprende da dLL de extensão MFC `AfxFreeLibrary` (que acontece quando o processo sai, ou quando o DLL é descarregado como resultado de uma chamada).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdll_.h

## <a name="afxsetambientactctx"></a><a name="afxsetambientactctx"></a>AfxSetAmbientActCtx

Use esta função para definir a bandeira de estado por módulo, que afeta o comportamento WinSxS do MFC.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI AfxSetAmbientActCtx(BOOL bSet);
```

### <a name="parameters"></a>Parâmetros

*bSet*<br/>
Novo valor da bandeira estadual do módulo.

### <a name="remarks"></a>Comentários

Quando o sinalizador é definido (que é o padrão) e um segmento entra em um módulo MFC (veja [AFX_MANAGE_STATE),](#afx_manage_state)o contexto do módulo é ativado.
Se o sinalizador não estiver definido, o contexto do módulo não será ativado na entrada.
O contexto de um módulo é determinado a partir de seu manifesto, geralmente incorporado em recursos de módulo.

### <a name="example"></a>Exemplo

```cpp
BOOL CMFCListViewApp::InitInstance()
{
   AfxSetAmbientActCtx(FALSE);
   // Remainder of function definition omitted.
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcomctl32.h

## <a name="afxtermextensionmodule"></a><a name="afxtermextensionmodule"></a>Afxtermextensionmodule

Chame esta função para permitir que o MFC limpe a dLL de extensão MFC quando cada processo se desprender da DLL (que acontece quando o processo sai, ou quando o DLL é descarregado como resultado de uma `AfxFreeLibrary` chamada).

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI AfxTermExtensionModule(  AFX_EXTENSION_MODULE& state,  BOOL bAll  = FALSE );
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Uma referência à estrutura [AFX_EXTENSION_MODULE](afx-extension-module-structure.md) que contém o estado do módulo DLL de extensão MFC.

*Bola*<br/>
Se TRUE, limpe todos os módulos DLL de extensão MFC. Caso contrário, limpe apenas o módulo DLL atual.

### <a name="remarks"></a>Comentários

`AfxTermExtensionModule`excluirá qualquer armazenamento local anexado ao módulo e removerá quaisquer entradas do cache do mapa de mensagens. Por exemplo:

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

Se o aplicativo carregar e liberar DLLs de extensão `AfxTermExtensionModule`MFC dinamicamente, certifique-se de ligar . Como a maioria dos DLLs de extensão MFC não são carregados dinamicamente (geralmente, eles são vinculados através de suas bibliotecas de importação), a chamada para `AfxTermExtensionModule` geralmente não é necessária.

Os DLLs de extensão MFC precisam chamar `DllMain` [AfxInitExtensionModule](#afxinitextensionmodule) em seu . Se a DLL estará exportando objetos [CRuntimeClass](cruntimeclass-structure.md) ou tiver seus `CDynLinkLibrary` próprios recursos personalizados, você também precisará criar um objeto em `DllMain`.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdll_.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox)<br/>
[Gerenciando os dados de estado dos módulos MFC](../managing-the-state-data-of-mfc-modules.md)<br/>

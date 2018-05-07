---
title: Macros e funções de gerenciamento de DLLs | Microsoft Docs
ms.custom: ''
ms.date: 04/03/2017
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- module macros in MFC
ms.assetid: 303f4161-cb5e-4099-81ad-acdb11aa60fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e5e79556bf6e3ae92f7a8d4975dbd30f199e2ca8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="macros-and-functions-for-managing-dlls"></a>Macros e funções de gerenciamento de DLLs

|||
|-|-|
|[AFX_EXT_CLASS](#afx_ext_class)]|Classes de exportações.|
|[AFX_MANAGE_STATE](#afx_manage_state)|Protege uma função exportada em uma DLL.|
|[AfxOleInitModule](#afxoleinitmodule)|Fornece suporte OLE de uma DLL MFC regular vinculada dinamicamente a MFC.|
|[AfxNetInitModule](#afxnetinitmodule)|Oferece que suporte a MFC soquetes de uma DLL MFC regular vinculada dinamicamente a MFC.|
|[AfxGetAmbientActCtx](#afxgetambientactctx)|Obtém o estado atual do sinalizador de estado por módulo.|
|[AfxGetStaticModuleState](#afxgetstaticmodulestate)|Define o estado do módulo antes da inicialização e/ou para restaurar o estado do módulo anterior após a limpeza.|
|[AfxInitExtensionModule]()#afxinitextensionmodule|Inicializa a DLL.|
|[AfxSetAmbientActCtx](#afxsetambientactctx)|Defina o sinalizador de estado por módulo, que afeta o comportamento de WinSxS do MFC.|
|[AfxTermExtensionModule]()#afxtermextensionmodule)|Permite MFC limpeza a DLL de extensão do MFC quando cada processo desanexado da DLL.|


## <a name="afx_ext_class"></a>  AFX_EXT_CLASS
[DLLs de extensão do MFC](../../build/extension-dlls.md) use a macro **AFX_EXT_CLASS** exportar classes; os executáveis que o link para a DLL de extensão do MFC usam a macro para importar classes.  
   
### <a name="remarks"></a>Comentários  
 Com o **AFX_EXT_CLASS** macro, o mesmo cabeçalho (s) usado para criar a DLL de extensão do MFC pode ser usado com os executáveis que o link para a DLL.  
  
 No arquivo de cabeçalho para a DLL, adicione o **AFX_EXT_CLASS** palavra-chave para a declaração da classe da seguinte maneira:  
  
```cpp
class AFX_EXT_CLASS CMyClass : public CDocument
{
// <body of class>
};
``` 
  
 Para obter mais informações, consulte [de exportação e importação usando AFX_EXT_CLASS](../../build/exporting-and-importing-using-afx-ext-class.md).  
   
### <a name="requirements"></a>Requisitos  
 Cabeçalho: **afxv_** dll.h  
   
## <a name="afx_manage_state"></a>  AFX_MANAGE_STATE
Chame essa macro para proteger uma função exportada em uma DLL.  
   
### <a name="syntax"></a>Sintaxe    
```
AFX_MANAGE_STATE(AFX_MODULE_STATE* pModuleState )  
```
### <a name="parameters"></a>Parâmetros  
 `pModuleState`  
 Um ponteiro para um `AFX_MODULE_STATE` estrutura.  
   
### <a name="remarks"></a>Comentários  
 Quando esta macro é invocada, `pModuleState` é o estado do módulo efetivo para o restante do imediata que contém o escopo. Após sair do escopo, o estado anterior do módulo efetivo será restaurado automaticamente.    
 O `AFX_MODULE_STATE` estrutura contém dados globais para o módulo, ou seja, a parte do estado do módulo que é enviada por push ou ser exibido.    
 Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Se você tiver uma função exportada em uma DLL, por exemplo, um que inicia uma caixa de diálogo na DLL, esse modelo, na verdade, é armazenado no módulo DLL. É necessário alternar o estado do módulo para o identificador correto a ser usado. Você pode fazer isso adicionando o código a seguir para o início da função:    
```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

```
 Isso alterna o estado atual do módulo com o estado retornado de [AfxGetStaticModuleState](#afxgetstaticmodulestate) até o término do escopo atual.    
 Para obter mais informações sobre estados de módulo e MFC, consulte "Gerenciando a dados do estado dos módulos de MFC" [criando novos documentos, janelas e modos de exibição](../creating-new-documents-windows-and-views.md) e [58 de observação técnica](../tn058-mfc-module-state-implementation.md).    
> [!NOTE]
>  Quando MFC cria um contexto de ativação para um assembly, ele usa [AfxWinInit](#afxwininit) para criar o contexto e `AFX_MANAGE_STATE` para ativar e desativar a ele. Observe também que `AFX_MANAGE_STATE` está habilitada para estático bibliotecas MFC, bem como MFC DLLs, para permitir que o código do MFC executar no contexto de ativação adequada selecionado pelo usuário DLL. Para obter mais informações, consulte [suporte para contextos de ativação no estado do módulo MFC](../support-for-activation-contexts-in-the-mfc-module-state.md).     
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxstat_.h  
   
### <a name="see-also"></a>Consulte também  
 [AfxGetStaticModuleState](#afxgetstaticmodulestate)

## <a name="a-nameafxoleinitmodulea-afxoleinitmodule"></a><a name="afxoleinitmodule"><a/> AfxOleInitModule
Para obter suporte OLE de uma DLL MFC regular vinculada dinamicamente ao MFC, chamar essa função em seu MFC DLL regular `CWinApp::InitInstance` função para inicializar o OLE DLL do MFC.  
   
### <a name="syntax"></a>Sintaxe    
```
void AFXAPI AfxOleInitModule( );  
```  
   
### <a name="remarks"></a>Comentários  
 O OLE DLL MFC é uma extensão MFC DLL; em ordem para uma DLL de extensão do MFC para obter conectados com um **CDynLinkLibrary** cadeia, é necessário criar um **CDynLinkLibrary** objeto no contexto de cada módulo que estará usando. `AfxOleInitModule` cria o **CDynLinkLibrary** do objeto no contexto de seu MFC DLL regulares para que ele obtém conectado com o **CDynLinkLibrary** cadeia da DLL MFC regular do objeto.  
  
 Se você estiver criando um controle OLE e estiver usando `COleControlModule`, você não deve chamar **AfxOleInitModule** porque o `InitInstance` a função de membro para `COleControlModule` chamadas `AfxOleInitModule`.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: < afxdll_.h >  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox)

## <a name="afxnetinitmodule"></a>  AfxNetInitModule
Para dar suporte a MFC soquetes de uma DLL MFC regular vinculada dinamicamente ao MFC, adicione uma chamada para essa função em seu MFC DLL regular **CWinApp::InitInstance** função para inicializar a DLL de Sockets do MFC.  
   
### <a name="syntax"></a>Sintaxe    
```
void AFXAPI AfxNetInitModule( );  
```  
   
### <a name="remarks"></a>Comentários  
 A DLL do MFC soquetes é uma extensão MFC DLL; em ordem para uma DLL de extensão do MFC para obter conectados com um **CDynLinkLibrary** cadeia, é necessário criar um **CDynLinkLibrary** objeto no contexto de cada módulo que estará usando. `AfxNetInitModule` cria o **CDynLinkLibrary** do objeto no contexto de seu MFC DLL regulares para que ele obtém conectado com o **CDynLinkLibrary** cadeia da DLL MFC regular do objeto.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** < afxdll_.h >  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxMessageBox](cstring-formatting-and-message-box-display.md#afxmessagebox)

## <a name="afxgetambientactctx"></a> AfxGetAmbientActCtx
Use esta função para obter o estado atual do sinalizador de estado por módulo, que afeta o comportamento de WinSxS do MFC.  
   
### <a name="syntax"></a>Sintaxe    
```  
BOOL AFXAPI AfxGetAmbientActCtx();   
```  
   
### <a name="return-value"></a>Valor de retorno  
 Valor atual do sinalizador do estado de módulo.  
   
### <a name="remarks"></a>Comentários  
 Quando o sinalizador é definido (que é o padrão) e um thread entra em um módulo MFC (consulte [AFX_MANAGE_STATE](#afx_manage_state)), o contexto do módulo é ativado.  
  
 Se o sinalizador não for definido, o contexto do módulo não está ativado na entrada.  
  
 O contexto de um módulo é determinado pelo seu manifesto, geralmente inserido em recursos do módulo.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcomctl32.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AFX_MANAGE_STATE](#afx_manage_state)   
 [Gerenciando os dados de estado dos módulos MFC](../managing-the-state-data-of-mfc-modules.md)   
 [AfxSetAmbientActCtx](#setambientactctx)
 
## <a name="afxgetstaticmodulestate"></a> AfxGetStaticModuleState
Chame essa função para definir o estado do módulo antes da inicialização e/ou para restaurar o estado do módulo anterior após a limpeza.  
   
### <a name="syntax"></a>Sintaxe    
```
AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState( );  
```  
   
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `AFX_MODULE_STATE` estrutura.  
   
### <a name="remarks"></a>Comentários  
 O `AFX_MODULE_STATE` estrutura contém dados globais para o módulo, ou seja, a parte do estado do módulo que é enviada por push ou ser exibido.  
  
 Por padrão, o MFC usa o identificador de recurso do aplicativo principal para carregar o modelo de recurso. Se você tiver uma função exportada em uma DLL, por exemplo, um que inicia uma caixa de diálogo na DLL, esse modelo, na verdade, é armazenado no módulo DLL. É necessário alternar o estado do módulo para o identificador correto a ser usado. Você pode fazer isso adicionando o código a seguir para o início da função:  
  
```cpp
AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

```
  
 Isso alterna o estado atual do módulo com o estado retornado de `AfxGetStaticModuleState` até o término do escopo atual.  
  
 Para obter mais informações sobre estados de módulo e MFC, consulte "Gerenciando a dados do estado dos módulos de MFC" [criando novos documentos, janelas e modos de exibição](../creating-new-documents-windows-and-views.md) e [58 de observação técnica](../tn058-mfc-module-state-implementation.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxstat_.h  
   

## <a name="afxinitextensionmodule"></a> AfxInitExtensionModule
Chamar essa função em uma extensão do MFC DLL `DllMain` para inicializar a DLL.  
   
### <a name="syntax"></a>Sintaxe    
```
BOOL AFXAPI AfxInitExtensionModule( AFX_EXTENSION_MODULE& state,  HMODULE hModule );  
```
### <a name="parameters"></a>Parâmetros  
 `state`  
 Uma referência para o [estrutura AFX_EXTENSION_MODULE](afx-extension-module-structure.md) estrutura que contém o estado do módulo DLL de extensão do MFC após a inicialização. O estado inclui uma cópia dos objetos de classe de tempo de execução que foram inicializados pela DLL de extensão do MFC como parte da construção de objeto estático normal executada antes do `DllMain` é inserido.  
  
 `hModule`  
 Um identificador do módulo DLL de extensão do MFC.  
   
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a DLL de extensão do MFC com êxito inicializado; caso contrário, **FALSE**.  
   
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

```
  
 `AfxInitExtensionModule` faz uma cópia da DLL do **HMODULE** e classes de tempo de execução do DLL de captura (`CRuntimeClass` estruturas), bem como as fábricas de seu objeto (`COleObjectFactory` objetos) para uso posteriormente, quando o **CDynLinkLibrary**objeto é criado.    
 Extensão do MFC DLLs precisa fazer duas coisas em seus `DllMain` função:    
-   Chamar [AfxInitExtensionModule](#_mfc_afxinitextensionmodule) e verifique se o valor de retorno.   
-   Criar um **CDynLinkLibrary** objeto se a DLL estiver exportando [CRuntimeClass estrutura](cruntimeclass-structure.md) objetos ou tem seus próprios recursos personalizados.    
 Você pode chamar `AfxTermExtensionModule` para limpar a DLL de extensão do MFC quando cada processo desanexado da DLL de extensão do MFC (que ocorre quando o processo foi encerrado, ou quando a DLL é descarregada como resultado de uma `AfxFreeLibrary` chamar).     

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdll_.h     

### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxTermExtensionModule](#afxtermextensionmodule)

 ## <a name="afxsetambientactctx"></a>  AfxSetAmbientActCtx
Use esta função para definir o sinalizador de estado por módulo, que afeta o comportamento de WinSxS do MFC.  
   
### <a name="syntax"></a>Sintaxe  
  ```
   void AFXAPI AfxSetAmbientActCtx( BOOL bSet  
);  
```
### <a name="parameters"></a>Parâmetros  
 `bSet`  
 Novo valor do sinalizador de estado do módulo.  
   
### <a name="remarks"></a>Comentários  
 Quando o sinalizador é definido (que é o padrão) e um thread entra em um módulo MFC (consulte [AFX_MANAGE_STATE](#afx_manage_state)), o contexto do módulo é ativado.    
 Se o sinalizador não for definido, o contexto do módulo não está ativado na entrada.    
 O contexto de um módulo é determinado pelo seu manifesto, geralmente inserido em recursos do módulo.  
   
### <a name="example"></a>Exemplo  
 ```cpp
BOOL CMFCListViewApp::InitInstance()
{
   AfxSetAmbientActCtx(FALSE);
   // Remainder of function definition omitted.
```
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcomctl32.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxGetAmbientActCtx](#afxgetambientactctx)   
 [AFX_MANAGE_STATE](#afx_manage_state)   
 [Gerenciando os dados de estado dos módulos MFC](../managing-the-state-data-of-mfc-modules.md) 

## <a name="afxtermextensionmodule"></a>  AfxTermExtensionModule

Chamar essa função para permitir que MFC limpeza a DLL de extensão do MFC quando cada processo desanexado da DLL (que ocorre quando o processo foi encerrado, ou quando a DLL é descarregada como resultado de uma `AfxFreeLibrary` chamar).  
   
### <a name="syntax"></a>Sintaxe  
  ```
void AFXAPI AfxTermExtensionModule(  AFX_EXTENSION_MODULE& state,  BOOL bAll  = FALSE );  
```
### <a name="parameters"></a>Parâmetros  
 `state`  
 Uma referência para o [AFX_EXTENSION_MODULE](afx-extension-module-structure.md) estrutura que contém o estado do módulo DLL de extensão do MFC.  
  
 *Bola*  
 Se **TRUE**, limpar todos os módulos DLL de extensão do MFC. Caso contrário, limpeza apenas o módulo DLL atual.  
   
### <a name="remarks"></a>Comentários  
 `AfxTermExtensionModule` excluirá qualquer anexado para o módulo de armazenamento local e remover todas as entradas do cache de mapa de mensagem. Por exemplo:  
  
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
  
 Se seu aplicativo carrega e libera DLLs de extensão do MFC dinamicamente, certifique-se de chamar `AfxTermExtensionModule`. Desde que a maioria das DLLs não são carregadas dinamicamente de extensão do MFC (normalmente, eles são vinculados por meio de suas bibliotecas de importação), a chamada para `AfxTermExtensionModule` geralmente não é necessário.  
  
 DLLs de extensão MFC precisam chamar [AfxInitExtensionModule](#afxinitextensionmodule) em seus `DllMain`. Se a DLL estiver exportando [CRuntimeClass](cruntimeclass-structure.md) objetos ou tem seus próprios recursos personalizados, você também precisa criar um **CDynLinkLibrary** objeto `DllMain`.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdll_.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxInitExtensionModule](#afxinitextensionmodule)
 





---
title: Classe CWinAppEx | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWinAppEx
- AFXWINAPPEX/CWinAppEx
- AFXWINAPPEX/CWinAppEx::CWinAppEx
- AFXWINAPPEX/CWinAppEx::CleanState
- AFXWINAPPEX/CWinAppEx::EnableLoadWindowPlacement
- AFXWINAPPEX/CWinAppEx::EnableTearOffMenus
- AFXWINAPPEX/CWinAppEx::EnableUserTools
- AFXWINAPPEX/CWinAppEx::ExitInstance
- AFXWINAPPEX/CWinAppEx::GetBinary
- AFXWINAPPEX/CWinAppEx::GetContextMenuManager
- AFXWINAPPEX/CWinAppEx::GetDataVersion
- AFXWINAPPEX/CWinAppEx::GetDataVersionMajor
- AFXWINAPPEX/CWinAppEx::GetDataVersionMinor
- AFXWINAPPEX/CWinAppEx::GetInt
- AFXWINAPPEX/CWinAppEx::GetKeyboardManager
- AFXWINAPPEX/CWinAppEx::GetMouseManager
- AFXWINAPPEX/CWinAppEx::GetObject
- AFXWINAPPEX/CWinAppEx::GetRegSectionPath
- AFXWINAPPEX/CWinAppEx::GetRegistryBase
- AFXWINAPPEX/CWinAppEx::GetSectionBinary
- AFXWINAPPEX/CWinAppEx::GetSectionInt
- AFXWINAPPEX/CWinAppEx::GetSectionObject
- AFXWINAPPEX/CWinAppEx::GetSectionString
- AFXWINAPPEX/CWinAppEx::GetShellManager
- AFXWINAPPEX/CWinAppEx::GetString
- AFXWINAPPEX/CWinAppEx::GetTooltipManager
- AFXWINAPPEX/CWinAppEx::GetUserToolsManager
- AFXWINAPPEX/CWinAppEx::InitContextMenuManager
- AFXWINAPPEX/CWinAppEx::InitKeyboardManager
- AFXWINAPPEX/CWinAppEx::InitMouseManager
- AFXWINAPPEX/CWinAppEx::InitShellManager
- AFXWINAPPEX/CWinAppEx::InitTooltipManager
- AFXWINAPPEX/CWinAppEx::IsResourceSmartUpdate
- AFXWINAPPEX/CWinAppEx::IsStateExists
- AFXWINAPPEX/CWinAppEx::LoadState
- AFXWINAPPEX/CWinAppEx::OnAppContextHelp
- AFXWINAPPEX/CWinAppEx::OnViewDoubleClick
- AFXWINAPPEX/CWinAppEx::OnWorkspaceIdle
- AFXWINAPPEX/CWinAppEx::SaveState
- AFXWINAPPEX/CWinAppEx::SetRegistryBase
- AFXWINAPPEX/CWinAppEx::ShowPopupMenu
- AFXWINAPPEX/CWinAppEx::WriteBinary
- AFXWINAPPEX/CWinAppEx::WriteInt
- AFXWINAPPEX/CWinAppEx::WriteObject
- AFXWINAPPEX/CWinAppEx::WriteSectionBinary
- AFXWINAPPEX/CWinAppEx::WriteSectionInt
- AFXWINAPPEX/CWinAppEx::WriteSectionObject
- AFXWINAPPEX/CWinAppEx::WriteSectionString
- AFXWINAPPEX/CWinAppEx::WriteString
- AFXWINAPPEX/CWinAppEx::LoadCustomState
- AFXWINAPPEX/CWinAppEx::LoadWindowPlacement
- AFXWINAPPEX/CWinAppEx::OnClosingMainFrame
- AFXWINAPPEX/CWinAppEx::PreLoadState
- AFXWINAPPEX/CWinAppEx::PreSaveState
- AFXWINAPPEX/CWinAppEx::ReloadWindowPlacement
- AFXWINAPPEX/CWinAppEx::SaveCustomState
- AFXWINAPPEX/CWinAppEx::StoreWindowPlacement
- AFXWINAPPEX/CWinAppEx::m_bForceImageReset
dev_langs:
- C++
helpviewer_keywords:
- CWinAppEx class
ms.assetid: a3d3e053-3e22-463f-9444-c73abb1bb9d7
caps.latest.revision: 37
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: b471749e1e0e2c3ed7b1d8913122c4758276e166
ms.lasthandoff: 03/31/2017

---
# <a name="cwinappex-class"></a>Classe CWinAppEx
`CWinAppEx`Controla o estado do aplicativo, salva o estado para o registro, carrega o estado do registro, inicializa os administradores de aplicativos e fornece links para esses gerenciadores de aplicativo mesmo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWinAppEx : public CWinApp  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinAppEx::CWinAppEx](#cwinappex)|Constrói um objeto `CWinAppEx`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinAppEx::CleanState](#cleanstate)|Remove informações sobre o aplicativo de registro do Windows.|  
|[CWinAppEx::EnableLoadWindowPlacement](#enableloadwindowplacement)|Especifica se o aplicativo carregará o tamanho inicial e o local da janela do quadro principal do registro.|  
|[CWinAppEx::EnableTearOffMenus](#enabletearoffmenus)|Habilita destacável menus para o aplicativo.|  
|[CWinAppEx::EnableUserTools](#enableusertools)|Permite que o usuário crie comandos de menu personalizados no aplicativo.|  
|[CWinAppEx::ExitInstance](#exitinstance)|Chamado pelo framework de dentro do `Run` a função de membro para sair dessa instância do aplicativo. (Substitui [CWinApp::ExitInstance](../../mfc/reference/cwinapp-class.md#exitinstance).)|  
|[CWinAppEx::GetBinary](#getbinary)|Lê dados binários que está associados com o valor do registro especificado.|  
|[CWinAppEx::GetContextMenuManager](#getcontextmenumanager)|Retorna um ponteiro para global [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) objeto.|  
|[CWinAppEx::GetDataVersion](#getdataversion)||  
|[CWinAppEx::GetDataVersionMajor](#getdataversionmajor)|Retorna a versão principal do aplicativo salva no registro do Windows.|  
|[CWinAppEx::GetDataVersionMinor](#getdataversionminor)|Retorna a versão secundária do aplicativo salva no registro do Windows.|  
|[CWinAppEx::GetInt](#getint)|Lê dados numéricos que está associados com o valor especificado do registro.|  
|[CWinAppEx::GetKeyboardManager](#getkeyboardmanager)|Retorna um ponteiro para global [CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md) objeto.|  
|[CWinAppEx::GetMouseManager](#getmousemanager)|Retorna um ponteiro para global [CMouseManager](../../mfc/reference/cmousemanager-class.md) objeto.|  
|[CWinAppEx::GetObject](#getobject)|Lê `CObject`-derivado de dados que está associados com o valor especificado do registro.|  
|[CWinAppEx::GetRegSectionPath](#getregsectionpath)|Retorna uma cadeia de caracteres que é o caminho de uma chave do registro. Esse caminho concatena o caminho relativo fornecido com o caminho do aplicativo.|  
|[CWinAppEx::GetRegistryBase](#getregistrybase)|Retorna o caminho do registro para o aplicativo.|  
|[CWinAppEx::GetSectionBinary](#getsectionbinary)|Lê dados binários que está associados com a chave especificada e o valor do registro.|  
|[CWinAppEx::GetSectionInt](#getsectionint)|Lê dados numéricos do registro associado com a chave especificada e o valor.|  
|[CWinAppEx::GetSectionObject](#getsectionobject)|Lê `CObject` dados associados com a chave especificada e o valor do registro.|  
|[CWinAppEx::GetSectionString](#getsectionstring)|Lê dados de cadeia de caracteres que está associados com a chave especificada e o valor do registro.|  
|[CWinAppEx::GetShellManager](#getshellmanager)|Retorna um ponteiro para global [CShellManager](../../mfc/reference/cshellmanager-class.md) objeto.|  
|[CWinAppEx::GetString](#getstring)|Lê dados de cadeia de caracteres que está associados com o valor especificado do registro.|  
|[CWinAppEx::GetTooltipManager](#gettooltipmanager)|Retorna um ponteiro para global [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) objeto.|  
|[CWinAppEx::GetUserToolsManager](#getusertoolsmanager)|Retorna um ponteiro para global [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) objeto.|  
|[CWinAppEx::InitContextMenuManager](#initcontextmenumanager)|Inicializa o objeto `CContextMenuManager`.|  
|[CWinAppEx::InitKeyboardManager](#initkeyboardmanager)|Inicializa o objeto `CKeyboardManager`.|  
|[CWinAppEx::InitMouseManager](#initmousemanager)|Inicializa o objeto `CMouseManager`.|  
|[CWinAppEx::InitShellManager](#initshellmanager)|Inicializa o `CShellManager` classe|  
|[CWinAppEx::InitTooltipManager](#inittooltipmanager)|Inicializa o `CTooltipManager` classe.|  
|[CWinAppEx::IsResourceSmartUpdate](#isresourcesmartupdate)||  
|[CWinAppEx::IsStateExists](#isstateexists)|Indica se a chave especificada está no registro.|  
|[CWinAppEx::LoadState](#loadstate)|Carrega o estado do aplicativo do registro.|  
|[CWinAppEx::OnAppContextHelp](#onappcontexthelp)|Chamado pelo framework quando o usuário solicita ajuda de contexto para o **personalização** caixa de diálogo.|  
|[CWinAppEx::OnViewDoubleClick](#onviewdoubleclick)|Chama o comando definido pelo usuário quando o usuário clica duas vezes em qualquer lugar no aplicativo.|  
|[CWinAppEx::OnWorkspaceIdle](#onworkspaceidle)||  
|[CWinAppEx::SaveState](#savestate)|Grava o estado da estrutura do aplicativo no registro do Windows.|  
|[CWinAppEx::SetRegistryBase](#setregistrybase)|Define o caminho da chave do registro padrão. Essa chave servirá como uma raiz de todas as chamadas subsequentes de registro.|  
|[CWinAppEx::ShowPopupMenu](#showpopupmenu)|Apresenta um menu popup.|  
|[CWinAppEx::WriteBinary](#writebinary)|Grava os dados binários para o valor do registro especificado.|  
|[CWinAppEx::WriteInt](#writeint)|Grava os dados numéricos para o valor do registro especificado.|  
|[CWinAppEx::WriteObject](#writeobject)|Grava os dados que são derivados do [classe CObject](../../mfc/reference/cobject-class.md) ao valor do registro especificado.|  
|[CWinAppEx::WriteSectionBinary](#writesectionbinary)|Grava os dados binários como um valor de chave do registro especificado.|  
|[CWinAppEx::WriteSectionInt](#writesectionint)|Grava os dados numéricos em um valor de chave do registro especificado.|  
|[CWinAppEx::WriteSectionObject](#writesectionobject)|Grava dados derivados de `CObject` classe como um valor de chave do registro especificado.|  
|[CWinAppEx::WriteSectionString](#writesectionstring)|Grava os dados de cadeia de caracteres em um valor de chave do registro especificado.|  
|[CWinAppEx::WriteString](#writestring)|Grava os dados de cadeia de caracteres para o valor do registro especificado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinAppEx::LoadCustomState](#loadcustomstate)|Chamado pelo framework quando o estado do aplicativo foi carregado.|  
|[CWinAppEx::LoadWindowPlacement](#loadwindowplacement)|Chamado pelo framework quando ele carrega o tamanho e o local do seu aplicativo do registro. Os dados carregados incluem o tamanho e o local do quadro principal no momento em que o aplicativo é fechado pela última vez.|  
|[CWinAppEx::OnClosingMainFrame](#onclosingmainframe)|Chamado pelo framework durante o processamento de uma janela do quadro principal `WM_CLOSE`.|  
|[CWinAppEx::PreLoadState](#preloadstate)|Chamado pelo framework imediatamente antes do estado do aplicativo é carregado.|  
|[CWinAppEx::PreSaveState](#presavestate)|Chamado pelo framework imediatamente antes do estado do aplicativo é salvo.|  
|[CWinAppEx::ReloadWindowPlacement](#reloadwindowplacement)|Recarrega o tamanho e o local da janela fornecida a partir do registro|  
|[CWinAppEx::SaveCustomState](#savecustomstate)|Chamado pelo framework depois que ele grava o estado do aplicativo no registro.|  
|[CWinAppEx::StoreWindowPlacement](#storewindowplacement)|Chamado pelo framework para gravar o tamanho e o local do quadro principal no registro.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinAppEx::m_bForceImageReset](#m_bforceimagereset)|Especifica se a estrutura redefinirá todas as imagens da barra de ferramentas quando a janela do quadro que contém a barra de ferramentas é carregada.|  
  
## <a name="remarks"></a>Comentários  
 Grande parte da funcionalidade fornecida pelo framework MFC depende de `CWinAppEx` classe. Você pode incorporar o `CWinAppEx` classe em seu aplicativo em uma das duas maneiras:  
  
-   Construir um `CWinAppEx` classe no thread principal.  
  
-   Derive a classe principal do aplicativo de `CWinAppEx`.  
  
 Depois que você incorpore `CWinAppEx` em seu aplicativo, você pode inicializar qualquer um dos gerenciadores de aplicativo. Antes de usar um Gerenciador de aplicativos, você deve inicializá-lo chamando o método initialize apropriado. Para obter um ponteiro para um determinado gerente, chame o método get associado. O `CWinAppEx` classe gerencia os seguintes gerenciadores de aplicativo: [CMouseManager classe](../../mfc/reference/cmousemanager-class.md), [CContextMenuManager classe](../../mfc/reference/ccontextmenumanager-class.md), [CKeyboardManager classe](../../mfc/reference/ckeyboardmanager-class.md), [CUserToolsManager classe](../../mfc/reference/cusertoolsmanager-class.md), e [CMenuTearOffManager classe](../../mfc/reference/cmenutearoffmanager-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 [CWinApp](../../mfc/reference/cwinapp-class.md)  
  
 [CWinAppEx](../../mfc/reference/cwinappex-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinappex.h  
  
##  <a name="cleanstate"></a>CWinAppEx::CleanState  
 Remove todas as informações sobre o aplicativo do registro do Windows.  
  
```  
virtual BOOL CleanState(LPCTSTR lpszSectionName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSectionName`  
 Uma cadeia de caracteres que contém um caminho de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método limpa os dados de aplicativo de uma seção específica do registro. Você pode especificar a seção limpar usando o parâmetro `lpszSectionName`. Se `lpszSectionName` é `NULL`, esse método usará o caminho de registro padrão armazenado no `CWinAppEx` objeto. Para obter o caminho de registro padrão, use [CWinAppEx::GetRegistryBase](#getregistrybase).  
  
##  <a name="cwinappex"></a>CWinAppEx::CWinAppEx  
 Constrói um objeto `CWinAppEx`.  
  
```  
CWinAppEx(BOOL bResourceSmartUpdate = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bResourceSmartUpdate`  
 Um parâmetro booleano que especifica se o objeto de espaço de trabalho deve detectar e lidar com atualizações de recursos.  
  
### <a name="remarks"></a>Comentários  
 O `CWinAppEx` classe tem métodos de inicialização, fornece a funcionalidade para salvar e carregar as informações do aplicativo para o registro e controla as configurações de aplicativo global. Ele também permite que você use gerenciadores global, como o [CKeyboardManager classe](../../mfc/reference/ckeyboardmanager-class.md) e [CUserToolsManager classe](../../mfc/reference/cusertoolsmanager-class.md). Cada aplicativo pode ter apenas uma instância do `CWinAppEx` classe.  
  
##  <a name="enableloadwindowplacement"></a>CWinAppEx::EnableLoadWindowPlacement  
 Especifica se o aplicativo carregará o tamanho inicial e o local da janela do quadro principal do registro.  
  
```  
void EnableLoadWindowPlacement(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Especifica se o aplicativo carrega o tamanho inicial e o local da janela do quadro principal do registro.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o tamanho e o local do quadro principal é carregado do registro junto com outras configurações de aplicativo. Isso ocorre durante a [CWinAppEx::LoadState](#loadstate). Se você não deseja carregar o posicionamento de janela inicial do registro, chamar este método com `bEnable` definido como `false`.  
  
##  <a name="enabletearoffmenus"></a>CWinAppEx::EnableTearOffMenus  
 Cria e inicializa um [CMenuTearOffManager](../../mfc/reference/cmenutearoffmanager-class.md) objeto.  
  
```  
BOOL EnableTearOffMenus(
    LPCTSTR lpszRegEntry,  
    const UINT uiCmdFirst,  
    const UINT uiCmdLast);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszRegEntry`  
 Uma cadeia de caracteres que contém o caminho de uma chave do registro. O aplicativo usa essa chave do registro para armazenar informações para os menus destacável.  
  
 [in] `uiCmdFirst`  
 ID do menu separar primeiro.  
  
 [in] `uiCmdLast`  
 O menu de separar última ID.  
  
### <a name="return-value"></a>Valor de retorno  
 `True`Se o `CMenuTearOffManager` é criado e inicializado com êxito; `false` se ocorrer um erro ou se o `CMenuTearOffManager` já existe.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para habilitar destacável menus no seu aplicativo. Você deve chamar essa função de `InitInstance`.  
  
##  <a name="enableusertools"></a>CWinAppEx::EnableUserTools  
 Permite que o usuário crie comandos de menu personalizados que reduzem pressionamentos de tecla em seu aplicativo. Esse método cria um [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) objeto.  
  
```  
BOOL EnableUserTools(
    const UINT uiCmdToolsDummy,  
    const UINT uiCmdFirst,  
    const UINT uiCmdLast,  
    CRuntimeClass* pToolRTC = RUNTIME_CLASS(CUserTool),  
    UINT uArgMenuID = 0,  
    UINT uInitDirMenuID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdToolsDummy`  
 Um inteiro sem sinal que a estrutura usa como um espaço reservado para a ID de comando do menu Ferramentas do usuário.  
  
 [in] `uiCmdFirst`  
 A ID de comando para o primeiro comando de ferramenta do usuário.  
  
 [in] `uiCmdLast`  
 A ID de comando para o último comando de ferramenta do usuário.  
  
 [in] `pToolRTC`  
 A classe que o `CUserToolsManager` objeto usa para criar novas ferramentas de usuário.  
  
 [in] `uArgMenuID`  
 A ID de menu do argumento.  
  
 [in] `uInitDirMenuID`  
 A ID de menu para o diretório inicial de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método cria e inicializa um `CUserToolsManager` do objeto; `FALSE` se o método falhar ou se um `CUserToolsManager` objeto já existe.  
  
### <a name="remarks"></a>Comentários  
 Quando você habilita ferramentas definidas pelo usuário, a estrutura suporta automaticamente um menu dinâmico que pode ser estendido durante a personalização. A estrutura associa cada novo item de um comando externo. O framework chama esses comandos quando o usuário seleciona o item apropriado do **ferramentas** menu.  
  
 Toda vez que o usuário adiciona um novo item, o framework cria um novo objeto. O tipo de classe para o novo objeto é definido por `pToolRTC`. O `pToolRTC` tipo de classe deve ser derivado de [CUserTool classe](../../mfc/reference/cusertool-class.md).  
  
 Para obter mais informações sobre as ferramentas de usuário e como incorporá-las em seu aplicativo, consulte [ferramentas definidas pelo usuário](../../mfc/user-defined-tools.md).  
  
##  <a name="exitinstance"></a>CWinAppEx::ExitInstance  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual int ExitInstance();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getbinary"></a>CWinAppEx::GetBinary  
 Lê dados binários de uma chave do Registro especificada.  
  
```  
BOOL GetBinary(
    LPCTSTR lpszEntry,  
    LPBYTE* ppData,  
    UINT* pBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro.  
  
 [out] `ppData`  
 Um ponteiro para o buffer que o método preenche com os dados binários.  
  
 [out] `pBytes`  
 Um ponteiro para um inteiro sem sinal que o método usa para gravar o número de bytes lidos.  
  
### <a name="return-value"></a>Valor de retorno  
 `True`Se for bem-sucedida; `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê dados binários gravados no registro. Para gravar dados no registro, use os métodos [CWinAppEx::WriteBinary](#writebinary) e [CWinAppEx::WriteSectionBinary](#writesectionbinary).  
  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getcontextmenumanager"></a>CWinAppEx::GetContextMenuManager  
 Retorna um ponteiro para global [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) objeto.  
  
```  
CContextMenuManager* GetContextMenuManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para global `CContextMenuManager` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto CContextMenuManager não foi inicializado, esta função chama [CWinAppEx::InitContextMenuManager](#initcontextmenumanager) antes de retornar um ponteiro.  
  
##  <a name="getdataversion"></a>CWinAppEx::GetDataVersion  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
int GetDataVersion() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdataversionmajor"></a>CWinAppEx::GetDataVersionMajor  
 Retorna a versão principal do aplicativo que é salva no registro do Windows quando você chamar [CWinAppEx::SaveState](#savestate).  
  
```  
int GetDataVersionMajor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que contém o número de versão principal.  
  
##  <a name="getdataversionminor"></a>CWinAppEx::GetDataVersionMinor  
 Retorna a versão secundária do aplicativo que é salva no registro do Windows quando você chamar [CWinAppEx::SaveState](#savestate).  
  
```  
int GetDataVersionMinor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que contém o número de versão secundária.  
  
##  <a name="getint"></a>CWinAppEx::GetInt  
 Lê dados de inteiro de uma chave do Registro especificada.  
  
```  
int GetInt(
    LPCTSTR lpszEntry,  
    int nDefault = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome de uma entrada de registro.  
  
 [in] `nDefault`  
 O valor padrão que o método retorna se a entrada do Registro especificada não existe.  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados de registro se o método teve êxito; Caso contrário, `nDefault`.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê dados de inteiro do registro. Se não há nenhum dado de inteiro associado com a chave de registro indicada pelo `lpszEntry`, esse método retornará `nDefault`. Para gravar dados no registro, use os métodos [CWinAppEx::WriteSectionInt](#writesectionint) e [CWinAppEx::WriteInt](#writeint).  
  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getkeyboardmanager"></a>CWinAppEx::GetKeyboardManager  
 Retorna um ponteiro para global [CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md) objeto.  
  
```  
CKeyboardManager* GetKeyboardManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para global `CKeyboardManager` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o Gerenciador de teclado não é inicializado, esta função chama [CWinAppEx::InitKeyboardManager](#initkeyboardmanager) antes de retornar um ponteiro.  
  
##  <a name="getmousemanager"></a>CWinAppEx::GetMouseManager  
 Retorna um ponteiro para global [CMouseManager](../../mfc/reference/cmousemanager-class.md) objeto.  
  
```  
CMouseManager* GetMouseManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para global `CMouseManager` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o Gerenciador de mouse não foi inicializado, esta função chama [CWinAppEx::InitMouseManager](#initmousemanager) antes de retornar um ponteiro.  
  
##  <a name="getobject"></a>CWinAppEx::GetObject  
 Lê [CObject](../../mfc/reference/cobject-class.md)- dervied dados do registro.  
  
```  
BOOL GetObject(
    LPCTSTR lpszEntry,  
    CObject& obj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o caminho relativo de uma entrada de registro.  
  
 [out] `obj`  
 Uma referência a um `CObject`. O método usa essa referência para armazenar os dados de registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê dados do registro que é derivado de `CObject`. Para gravar `CObject` dados no registro, use um [CWinAppEx::WriteObject](#writeobject) ou [CWinAppEx::WriteSectionObject](#writesectionobject).  
  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro que está localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getregistrybase"></a>CWinAppEx::GetRegistryBase  
 Recupera o caminho de registro padrão para o aplicativo.  
  
```  
LPCTSTR GetRegistryBase();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o caminho do local do registro padrão.  
  
### <a name="remarks"></a>Comentários  
 Todos os métodos do [CWinAppEx classe](../../mfc/reference/cwinappex-class.md) que acessar o início do registro em um local padrão. Use esse método para recuperar um caminho de local do registro padrão. Use [CWinAppEx::SetRegistryBase](#setregistrybase) para alterar o local de registro padrão.  
  
##  <a name="getregsectionpath"></a>CWinAppEx::GetRegSectionPath  
 Cria e retorna o caminho absoluto de uma chave do registro.  
  
```  
CString GetRegSectionPath(LPCTSTR szSectionAdd = _T(""));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `szSectionAdd`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o caminho absoluto de uma chave do registro.  
  
### <a name="remarks"></a>Comentários  
 Este método define o caminho absoluto da chave do registro, acrescentando o caminho relativo no `szSectionAdd` ao local de registro padrão para seu aplicativo. Para obter a chave de registro padrão, use o método [CWinAppEx::GetRegistryBase](#getregistrybase).  
  
##  <a name="getsectionbinary"></a>CWinAppEx::GetSectionBinary  
 Lê os dados binários do registro.  
  
```  
BOOL GetSectionBinary(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    LPBYTE* ppData,  
    UINT* pBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser lido.  
  
 [out] `ppData`  
 Um ponteiro para o buffer em que o método armazena os dados.  
  
 [out] `pBytes`  
 Um ponteiro para um inteiro sem sinal. O método grava o tamanho de `ppData` para esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 `True` caso bem-sucedido; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê dados binários que são gravados no registro usando os métodos [CWinAppEx::WriteBinary](#writebinary) e [CWinAppEx::WriteSectionBinary](#writesectionbinary).  
  
 O `lpszSubSection` parâmetro não é um caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getsectionint"></a>CWinAppEx::GetSectionInt  
 Lê dados de inteiro do registro.  
  
```  
int GetSectionInt(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    int nDefault = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser lido.  
  
 [in] `nDefault`  
 O valor padrão para retornar se o valor especificado não existe.  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados de inteiro que são armazenados no valor do registro especificado; `nDefault` se os dados não existe.  
  
### <a name="remarks"></a>Comentários  
 Use os métodos [CWinAppEx::WriteInt](#writeint) e [CWinAppEx::WriteSectionInt](#writesectionint) para gravar dados de inteiro para o registro.  
  
 O `lpszSubSection` parâmetro não é um caminho absoluto de uma entrada de registro. É um caminho relativo que é adicionado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getsectionobject"></a>CWinAppEx::GetSectionObject  
 Lê [CObject](../../mfc/reference/cobject-class.md) dados de registro do registro.  
  
```  
BOOL GetSectionObject(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    CObject& obj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser lido.  
  
 [out] `obj`  
 Uma referência a um `CObject`. O método utiliza `CObject` para armazenar os dados de registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê os dados do registro. Os dados de leitura é `CObject` dados ou dados de uma classe derivada de `CObject`. Para gravar `CObject` dados no registro, use um [CWinAppEx::WriteObject](#writeobject) ou [CWinAppEx::WriteSectionObject](#writesectionobject).  
  
 O `lpszSubSection` parâmetro não é um caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getsectionstring"></a>CWinAppEx::GetSectionString  
 Lê dados do registro de cadeia de caracteres.  
  
```  
CString GetSectionString(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    LPCTSTR lpszDefault = _T(""));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser lido.  
  
 [in] `lpszDefault`  
 O valor padrão para retornar se o valor especificado não existe.  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados de cadeia de caracteres armazenados no valor do registro especificado se os dados existem. Caso contrário, `lpszDefault`.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê dados de cadeia de caracteres gravados no registro. Use [CWinAppEx::WriteString](#writestring) e [CWinAppEx::WriteSectionString](#writesectionstring) para gravar dados de cadeia de caracteres do registro.  
  
 O `lpszSubSection` parâmetro não é um caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="getshellmanager"></a>CWinAppEx::GetShellManager  
 Retorna um ponteiro para global [CShellManager](../../mfc/reference/cshellmanager-class.md) objeto.  
  
```  
CShellManager* GetShellManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para global `CShellManager` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o `CShellManager` objeto não foi inicializado, esta função chama [CWinAppEx::InitShellManager](#initshellmanager) antes de retornar um ponteiro.  
  
##  <a name="getstring"></a>CWinAppEx::GetString  
 Lê dados de uma chave do Registro especificada da cadeia de caracteres.  
  
```  
CString GetString(
    LPCTSTR lpszEntry,  
    LPCTSTR lpzDefault= _T(""));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro  
  
 [in] `lpzDefault`  
 O valor padrão que o método retorna se a entrada do Registro especificada não existe.  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados de cadeia de caracteres armazenados no registro se for bem-sucedida; `lpszDefault` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Esse método lê dados de cadeia de caracteres gravados no registro. Para gravar dados no registro, use os métodos [CWinAppEx::WriteString](#writestring) ou [CWinAppEx::WriteSectionString](#writesectionstring).  
  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="gettooltipmanager"></a>CWinAppEx::GetTooltipManager  
 Retorna um ponteiro para global [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) objeto.  
  
```  
CTooltipManager* GetTooltipManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para global `CTooltipManager` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o `CTooltipManager` objeto não foi inicializado, esta função chama [CWinAppEx::InitTooltipManager](#inittooltipmanager) antes de retornar um ponteiro.  
  
##  <a name="getusertoolsmanager"></a>CWinAppEx::GetUserToolsManager  
 Retorna um ponteiro para global [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) objeto.  
  
```  
CUserToolsManager* GetUserToolsManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para global `CUserToolsManager` do objeto; `NULL` se as ferramentas de gerenciamento de usuário não está habilitada para o aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Antes de recuperar um ponteiro para o `CUserToolsManager` do objeto, você deve inicializar o Gerenciador de chamando [CWinAppEx::EnableUserTools](#enableusertools).  
  
##  <a name="initcontextmenumanager"></a>CWinAppEx::InitContextMenuManager  
 Inicializa o [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) objeto.  
  
```  
BOOL InitContextMenuManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método cria o objeto CContextMenuManager; 0 se o `CContextMenuManager` objeto já existe.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [CWinAppEx::GetContextMenuManager](#getcontextmenumanager), a implementação padrão do método chama `InitContextMenuManager`.  
  
 Se seu aplicativo já tem um Gerenciador de menu de contexto e você chamar `InitContextMenuManager`, seu aplicativo terá uma [ASSERT](diagnostic-services.md#assert) falha. Portanto, você não deve chamar `InitContextMenuManager` se você criar um `CContextMenuManager` diretamente do objeto. Se você não estiver usando um personalizado `CContextMenuManager`, você deve usar `GetContextMenuManager` para criar um `CContextMenuManager` objeto.  
  
##  <a name="initkeyboardmanager"></a>CWinAppEx::InitKeyboardManager  
 Inicializa o [CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md) objeto.  
  
```  
BOOL InitKeyboardManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método cria o `CKeyboardManager` objeto; 0 se o `CKeyboardManager` objeto já existe.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [CWinAppEx::GetKeyboardManager](#getkeyboardmanager), a implementação padrão do método chama `InitKeyboardManager`.  
  
 Se seu aplicativo já tem um Gerenciador de teclado e você chamar `InitKeyboardManager`, seu aplicativo terá uma [ASSERT](diagnostic-services.md#assert) falha. Portanto, você não deve chamar `InitKeyboardManager` se você criar um `CKeyboardManager` diretamente do objeto. Se você não estiver usando um personalizado `CKeyboardManager`, você deve usar `GetKeyboardManager` para criar um `CKeyboardManager` objeto.  
  
##  <a name="initmousemanager"></a>CWinAppEx::InitMouseManager  
 Inicializa o [CMouseManager](../../mfc/reference/cmousemanager-class.md) objeto.  
  
```  
BOOL InitMouseManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método cria o `CMouseManager` objeto; 0 se o `CMouseManager` objeto já existe.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [CWinAppEx::GetMouseManager](#getmousemanager), a implementação padrão do método chama `InitMouseManager`.  
  
 Se seu aplicativo já tem um Gerenciador de mouse e você chamar `InitMouseManager`, seu aplicativo terá uma [ASSERT](diagnostic-services.md#assert) falha. Portanto, você não deve chamar `InitMouseManager` se você criar um `CMouseManager` diretamente do objeto. Se você não estiver usando um personalizado `CMouseManager`, você deve usar `GetMouseManager` para criar um `CMouseManager` objeto.  
  
##  <a name="initshellmanager"></a>CWinAppEx::InitShellManager  
 Inicializa o [CShellManager](../../mfc/reference/cshellmanager-class.md) objeto.  
  
```  
BOOL InitShellManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método cria o `CShellManager` objeto; 0 se o `CShellManager` objeto já existe.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [CWinAppEx::GetShellManager](#getshellmanager), a implementação padrão do método chama `InitShellManager`.  
  
 Se seu aplicativo já tem um Gerenciador de shell e você chamar `InitShellManager`, seu aplicativo gera um [ASSERT](diagnostic-services.md#assert) falha. Portanto, não chame `InitShellManager` se você criar um `CShellManager` diretamente do objeto. Se você não estiver usando um personalizado `CShellManager`, use `GetShellManager` para criar um `CShellManager` objeto.  
  
##  <a name="inittooltipmanager"></a>CWinAppEx::InitTooltipManager  
 Inicializa o [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) objeto.  
  
```  
BOOL InitTooltipManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método cria o `CTooltipManager` objeto; 0 se o `CTooltipManager` objeto já existe.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [CWinAppEx::GetTooltipManager](#gettooltipmanager), a implementação padrão do método chama `InitTooltipManager`.  
  
 Se seu aplicativo já tem um Gerenciador de dica de ferramenta e você chamar `InitTooltipManager`, seu aplicativo terá uma [ASSERT](diagnostic-services.md#assert) falha. Portanto, você não deve chamar `InitTooltipManager` se você criar um `CTooltipManager` diretamente do objeto. Se você não estiver usando um personalizado `CTooltipManager`, você deve usar `GetTooltipManager` para criar um `CTooltipManager` objeto.  
  
##  <a name="isresourcesmartupdate"></a>CWinAppEx::IsResourceSmartUpdate  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsResourceSmartUpdate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isstateexists"></a>CWinAppEx::IsStateExists  
 Indica se a chave especificada está no registro.  
  
```  
BOOL IsStateExists(LPCTSTR lpszSectionName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSectionName`  
 Uma cadeia de caracteres que contém um caminho de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chave no registro. Caso contrário, 0.  
  
##  <a name="loadcustomstate"></a>CWinAppEx::LoadCustomState  
 O framework chama este método depois que ele carrega o estado do aplicativo do registro.  
  
```  
virtual void LoadCustomState();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se desejar fazer qualquer processamento depois que o aplicativo carrega o estado do registro. Por padrão, esse método não fará nada.  
  
 Para carregar informações de estado personalizado do registro, as informações devem ser salvo usando [CWinAppEx::SaveCustomState](#savecustomstate).  
  
##  <a name="loadstate"></a>CWinAppEx::LoadState  
 Lê o estado do aplicativo do registro do Windows.  
  
```  
BOOL LoadState(
    CMDIFrameWndEx* pFrame,  
    LPCTSTR lpszSectionName = NULL);

 
BOOL LoadState(
    CFrameWndEx* pFrame,  
    LPCTSTR lpszSectionName = NULL);

 
BOOL LoadState(
    COleIPFrameWndEx* pFrame,  
    LPCTSTR lpszSectionName = NULL);

 
virtual BOOL LoadState(
    LPCTSTR lpszSectionName = NULL,  
    CFrameImpl* pFrameImpl = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrame`  
 Um ponteiro para um objeto de janela do quadro. O método aplica-se as informações de estado no registro para essa janela do quadro.  
  
 [in] `lpszSectionName`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `pFrameImpl`  
 Um ponteiro para um `CFrameImpl` objeto. O método aplica-se as informações de estado no registro para essa janela do quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método carrega o estado do aplicativo e qualquer informação de estado para uma janela do quadro. As informações carregadas para a janela do quadro são aplicadas para a janela do quadro fornecido. Se você não fornecer uma janela do quadro, somente as informações de estado do aplicativo são carregadas. As informações do aplicativo incluem o estado do [CMouseManager classe](../../mfc/reference/cmousemanager-class.md), [CContextMenuManager classe](../../mfc/reference/ccontextmenumanager-class.md), [CKeyboardManager classe](../../mfc/reference/ckeyboardmanager-class.md)e o [CUserToolsManager classe](../../mfc/reference/cusertoolsmanager-class.md).  
  
 A implementação padrão de `CFrameImpl::OnLoadFrame` chamadas `LoadState`.  
  
 O `lpszSectionName` parâmetro não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="loadwindowplacement"></a>CWinAppEx::LoadWindowPlacement  
 Chamado pelo framework quando ele carrega o tamanho e o local da janela do quadro principal do registro.  
  
```  
virtual BOOL LoadWindowPlacement(
    CRect& rectNormalPosition,  
    int& nFlags,  
    int& nShowCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectNormalPosition`  
 Um retângulo que contém as coordenadas da janela do quadro principal quando ele está na posição restaurada.  
  
 [out] `nFlags`  
 Sinalizadores que controlam a posição da janela minimizada e como o sistema operacional alterna entre uma janela minimizada e uma janela restaurada.  
  
 [out] `nShowCmd`  
 Um inteiro que especifica o estado de Mostrar da janela. Para obter mais informações sobre os valores possíveis, consulte [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, MFC carrega automaticamente a posição anterior e o estado da janela do quadro principal quando o aplicativo for iniciado. Para obter mais informações sobre como essas informações são armazenadas no registro, consulte [CWinAppEx::StoreWindowPlacement](#storewindowplacement).  
  
 Substitua este método se você deseja carregar informações adicionais sobre a janela do quadro principal.  
  
##  <a name="m_bforceimagereset"></a>CWinAppEx::m_bForceImageReset  
 Especifica se a estrutura redefine todas as imagens da barra de ferramentas quando recarrega a janela do quadro que contém a barra de ferramentas.  
  
```  
BOOL m_bForceImageReset;  
```  
  
### <a name="remarks"></a>Comentários  
 O `m_bForceImageReset` membro de dados é uma variável protegida.  
  
##  <a name="onappcontexthelp"></a>CWinAppEx::OnAppContextHelp  
 O framework chama esse método quando o usuário solicita ajuda de contexto para o **personalização** caixa de diálogo.  
  
```  
virtual void OnAppContextHelp(
    CWnd* pWndControl,  
    const DWORD dwHelpIDArray[]);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndControl`  
 Um ponteiro para um objeto de janela para o qual o usuário acionasse ajuda de contexto.  
  
 [in] `dwHelpIDArray[]`  
 Um valor reservado.  
  
### <a name="remarks"></a>Comentários  
 Atualmente, esse método é reservado para uso futuro. A implementação padrão não faz nada e ele atualmente não é chamado pelo framework.  
  
##  <a name="onclosingmainframe"></a>CWinAppEx::OnClosingMainFrame  
 O framework chama esse método durante o processamento de uma janela do quadro `WM_CLOSE`.  
  
```  
virtual void OnClosingMainFrame(CFrameImpl* pFrameImpl);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrameImpl`  
 Um ponteiro para um `CFrameImpl` objeto.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desse método salva o estado da `pFrameImpl`.  
  
##  <a name="onviewdoubleclick"></a>CWinAppEx::OnViewDoubleClick  
 Chama o comando definido pelo usuário que está associado um modo de exibição quando o usuário clica duas vezes em qualquer lugar dentro dessa exibição.  
  
```  
virtual BOOL OnViewDoubleClick(
    CWnd* pWnd,  
    int iViewId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Um ponteiro para um objeto derivado de [classe CView](../../mfc/reference/cview-class.md).  
  
 [in] `iViewId`  
 A ID da exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 `True`Se a estrutura de encontrar um comando. Caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 Para oferecer suporte ao comportamento de mouse personalizado, você deve chamar essa função ao processar o `WM_LBUTTONDBLCLK` mensagem. Esse método executa o comando associado à ID de exibição fornecida pelo `iViewId`. Para obter mais informações sobre o comportamento do mouse personalizado, consulte [personalização de teclado e Mouse](../../mfc/keyboard-and-mouse-customization.md).  
  
##  <a name="onworkspaceidle"></a>CWinAppEx::OnWorkspaceIdle  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnWorkspaceIdle(CWnd*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CWnd*`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="preloadstate"></a>CWinAppEx::PreLoadState  
 O framework chama esse método imediatamente antes de carregar o estado do aplicativo do registro.  
  
```  
virtual void PreLoadState();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se desejar fazer qualquer processamento imediatamente antes do framework carrega o estado do aplicativo.  
  
##  <a name="presavestate"></a>CWinAppEx::PreSaveState  
 O framework chama esse método imediatamente antes de salvar o estado do aplicativo.  
  
```  
virtual void PreSaveState();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se desejar fazer qualquer processamento imediatamente antes do framework salva o estado do aplicativo.  
  
##  <a name="reloadwindowplacement"></a>CWinAppEx::ReloadWindowPlacement  
 Recarrega o tamanho e a localização de uma janela do registro.  
  
```  
virtual BOOL ReloadWindowPlacement(CFrameWnd* pFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrame`  
 Um ponteiro para uma janela do quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; 0 não se for de carga com falha ou se não houver nenhum dado a carregar.  
  
### <a name="remarks"></a>Comentários  
 Use a função [CWinAppEx::StoreWindowPlacement](#storewindowplacement) ao gravar o tamanho e a localização de uma janela para o registro.  
  
##  <a name="savecustomstate"></a>CWinAppEx::SaveCustomState  
 O framework chama este método depois que ele salva o estado do aplicativo para o registro.  
  
```  
virtual void SaveCustomState();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se desejar fazer qualquer processamento depois que o aplicativo salva o estado no registro. Por padrão, esse método não fará nada.  
  
##  <a name="savestate"></a>CWinAppEx::SaveState  
 Grava o estado do aplicativo no registro do Windows.  
  
```  
virtual BOOL SaveState(
    LPCTSTR lpszSectionName = NULL,  
    CFrameImpl* pFrameImpl = NULL);

 
BOOL SaveState(
    CMDIFrameWndEx* pFrame,  
    LPCTSTR lpszSectionName = NULL);

 
BOOL SaveState(
    CFrameWndEx* pFrame,  
    LPCTSTR lpszSectionName = NULL);

 
BOOL SaveState(
    COleIPFrameWndEx* pFrame,  
    LPCTSTR lpszSectionName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSectionName`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `pFrameImpl`  
 Um ponteiro para um `CFrameImpl` objeto. Este quadro é salva no registro do Windows.  
  
 [in] `pFrame`  
 Um ponteiro para um objeto de janela do quadro. Este quadro é salva no registro do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 `True`Se for bem-sucedida; `false` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Esse método salva o estado do aplicativo e qualquer informação de estado para a janela do quadro fornecido. Se você não fornecer uma janela do quadro, o método apenas salva o estado do aplicativo. As informações do aplicativo incluem o estado do [CMouseManager classe](../../mfc/reference/cmousemanager-class.md), [CContextMenuManager classe](../../mfc/reference/ccontextmenumanager-class.md), [CKeyboardManager classe](../../mfc/reference/ckeyboardmanager-class.md)e o [CUserToolsManager classe](../../mfc/reference/cusertoolsmanager-class.md).  
  
 O `lpszSectionName` parâmetro não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
##  <a name="setregistrybase"></a>CWinAppEx::SetRegistryBase  
 Define o caminho de registro padrão para o aplicativo.  
  
```  
LPCTSTR SetRegistryBase(LPCTSTR lpszSectionName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSectionName`  
 Uma cadeia de caracteres que contém o caminho de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o caminho do local do registro padrão.  
  
### <a name="remarks"></a>Comentários  
 Todos os métodos do [CWinAppEx classe](../../mfc/reference/cwinappex-class.md) que acessar o início do registro em um local padrão. Use esse método para alterar o local padrão do registro. Use [CWinAppEx::GetRegistryBase](#getregistrybase) para recuperar o local de registro padrão.  
  
##  <a name="showpopupmenu"></a>CWinAppEx::ShowPopupMenu  
 Apresenta um menu popup.  
  
```  
virtual BOOL ShowPopupMenu(
    UINT uiMenuResId,  
    const CPoint& point,  
    CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMenuResId`  
 Uma ID de recurso de menu.  
  
 [in] `point`  
 Um [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) que especifica a posição do menu em coordenadas da tela.  
  
 [in] `pWnd`  
 Um ponteiro para a janela que possui um menu pop-up.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu pop-up é exibido com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método exibe o menu associado `uiMenuResId`.  
  
 Para dar suporte a menus pop-up, você deve ter uma [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) objeto. Se você não tiver inicializado os `CContextMenuManager` objeto `ShowPopupMenu` falhará.  
  
##  <a name="storewindowplacement"></a>CWinAppEx::StoreWindowPlacement  
 Chamado pelo framework para gravar o tamanho e o local da janela do quadro principal no registro.  
  
```  
virtual BOOL StoreWindowPlacement(
    const CRect& rectNormalPosition,  
    int nFlags,  
    int nShowCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nFlags`  
 Sinalizadores que controlam a posição da janela minimizada e como o sistema operacional alterna entre uma janela minimizada e uma janela restaurada.  
  
 [in] `nShowCmd`  
 Um inteiro que especifica o estado de Mostrar da janela. Para obter mais informações sobre os valores possíveis, consulte [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow).  
  
 [in] `rectNormalPosition`  
 Um retângulo que contém as coordenadas da janela do quadro principal quando ela estiver no estado restaurado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o MFC salva automaticamente a posição e o estado da janela do quadro principal antes de sair do aplicativo. Essas informações são armazenadas no registro do Windows sob a chave WindowPlacement no local padrão do registro para o seu aplicativo. Para obter mais informações sobre o local de registro padrão do seu aplicativo, consulte [CWinAppEx::GetRegistryBase](#getregistrybase).  
  
 Substitua este método se você deseja armazenar informações adicionais sobre a janela do quadro principal.  
  
##  <a name="writebinary"></a>CWinAppEx::WriteBinary  
 Grava dados binários no registro.  
  
```  
BOOL WriteBinary(
    LPCTSTR lpszEntry,  
    LPBYTE pData,  
    UINT nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro.  
  
 [in] `pData`  
 Os dados a serem armazenados.  
  
 [in] `nBytes`  
 O tamanho de `pData` em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro que está localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
 Se a chave especificada por `lpszEntry` não existir, esse método irá criá-lo.  
  
##  <a name="writeint"></a>CWinAppEx::WriteInt  
 Grava dados numéricos no registro.  
  
```  
BOOL WriteInt(
    LPCTSTR lpszEntry,  
    int nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro.  
  
 [in] `nValue`  
 Os dados a serem armazenados.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
 Se a chave especificada por `lpszEntry` não existir, esse método irá criá-lo.  
  
##  <a name="writeobject"></a>CWinAppEx::WriteObject  
 Grava dados derivados de [classe CObject](../../mfc/reference/cobject-class.md) no registro.  
  
```  
BOOL WriteObject(
    LPCTSTR lpszEntry,  
    CObject& obj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser definido.  
  
 [in] `obj`  
 Uma referência a `CObject` dados que o método serão armazenados.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método grava o `obj` dados para o valor especificado na chave de registro padrão. Use [CWinAppEx::GetRegistryBase](#getregistrybase) para determinar a chave do registro atual.  
  
##  <a name="writesectionbinary"></a>CWinAppEx::WriteSectionBinary  
 Grava dados binários como um valor no registro.  
  
```  
BOOL WriteSectionBinary(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    LPBYTE pData,  
    UINT nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser definido.  
  
 [in] `pData`  
 Os dados para gravar no registro.  
  
 [in] `nBytes`  
 O tamanho de `pData` em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszSubSection` parâmetro não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
 Se a chave especificada por `lpszEntry` não existir, esse método irá criá-lo.  
  
##  <a name="writesectionint"></a>CWinAppEx::WriteSectionInt  
 Grava dados numéricos no registro.  
  
```  
BOOL WriteSectionInt(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    int nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser definido.  
  
 [in] `nValue`  
 Os dados para gravar no registro.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszSubSection` parâmetro não é um caminho absoluto para uma entrada de registro. É um caminho relativo que é anexado à chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
 Se a chave especificada por `lpszEntry` não existir, esse método irá criá-lo.  
  
##  <a name="writesectionobject"></a>CWinAppEx::WriteSectionObject  
 Grava dados derivados de [classe CObject](../../mfc/reference/cobject-class.md) para um valor de registro específicos.  
  
```  
BOOL WriteSectionObject(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    CObject& obj);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome do valor a ser definido.  
  
 [in] `obj`  
 Os dados a serem armazenados.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszSubSection` parâmetro não é um caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase), respectivamente.  
  
 Se o valor especificado por `lpszEntry` não existe sob a chave do Registro especificada pelo `lpszSubSection`, esse método criará esse valor.  
  
##  <a name="writesectionstring"></a>CWinAppEx::WriteSectionString  
 Grava dados de cadeia de caracteres para um valor no registro.  
  
```  
BOOL WriteSectionString(
    LPCTSTR lpszSubSection,  
    LPCTSTR lpszEntry,  
    LPCTSTR lpszValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszSubSection`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro.  
  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o valor a ser definido.  
  
 [in] `lpszValue`  
 Os dados de cadeia de caracteres para escrever no registro.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszSubSection` parâmetro não é um caminho absoluto para uma entrada de registro. É um caminho relativo que é acrescentado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase), respectivamente.  
  
 Se o valor especificado por `lpszEntry` não existe em `lpszSubSection`, esse método irá criá-lo.  
  
##  <a name="writestring"></a>CWinAppEx::WriteString  
 Grava dados de cadeia de caracteres no registro.  
  
```  
BOOL WriteString(
    LPCTSTR lpszEntry,  
    LPCTSTR lpszValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszEntry`  
 Uma cadeia de caracteres que contém o nome de uma chave do registro.  
  
 [in] `lpszValue`  
 Os dados a serem armazenados.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `lpszEntry` parâmetro é o nome de uma entrada de registro localizado sob a chave de registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](#getregistrybase) e [CWinAppEx::SetRegistryBase](#setregistrybase) respectivamente.  
  
 Se a chave especificada por `lspzEntry` não existir, esse método irá criá-lo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CWinApp](../../mfc/reference/cwinapp-class.md)   
 [Classe CMouseManager](../../mfc/reference/cmousemanager-class.md)   
 [Classe CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)   
 [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)   
 [Classe CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md)


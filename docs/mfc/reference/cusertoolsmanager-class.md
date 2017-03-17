---
title: Classe CUserToolsManager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CUserToolsManager
- AFXUSERTOOLSMANAGER/CUserToolsManager
- AFXUSERTOOLSMANAGER/CUserToolsManager::CUserToolsManager
- AFXUSERTOOLSMANAGER/CUserToolsManager::CreateNewTool
- AFXUSERTOOLSMANAGER/CUserToolsManager::FindTool
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetArgumentsMenuID
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetDefExt
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetFilter
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetInitialDirMenuID
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetMaxTools
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetToolsEntryCmd
- AFXUSERTOOLSMANAGER/CUserToolsManager::GetUserTools
- AFXUSERTOOLSMANAGER/CUserToolsManager::InvokeTool
- AFXUSERTOOLSMANAGER/CUserToolsManager::IsUserToolCmd
- AFXUSERTOOLSMANAGER/CUserToolsManager::LoadState
- AFXUSERTOOLSMANAGER/CUserToolsManager::MoveToolDown
- AFXUSERTOOLSMANAGER/CUserToolsManager::MoveToolUp
- AFXUSERTOOLSMANAGER/CUserToolsManager::RemoveTool
- AFXUSERTOOLSMANAGER/CUserToolsManager::SaveState
- AFXUSERTOOLSMANAGER/CUserToolsManager::SetDefExt
- AFXUSERTOOLSMANAGER/CUserToolsManager::SetFilter
dev_langs:
- C++
helpviewer_keywords:
- CUserToolsManager class
ms.assetid: bdfa37ae-efca-4616-abb5-9d0dcd2d335b
caps.latest.revision: 26
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 0b82adf0f9eba5ee334ada2c169546f27894c1dd
ms.lasthandoff: 02/25/2017

---
# <a name="cusertoolsmanager-class"></a>Classe CUserToolsManager
Mantém a coleção de [CUserTool classe](../../mfc/reference/cusertool-class.md) objetos em um aplicativo. Uma ferramenta de usuário é um item de menu que executa um aplicativo externo. O `CUserToolsManager` objeto permite que o usuário ou desenvolvedor adicione novas ferramentas de usuário para o aplicativo. Ele oferece suporte à execução dos comandos associados com as ferramentas do usuário, e ele também salva as informações sobre as ferramentas de usuário no registro do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CUserToolsManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserToolsManager::CUserToolsManager](#cusertoolsmanager)|Constrói um `CUserToolsManager`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserToolsManager::CreateNewTool](#createnewtool)|Cria uma nova ferramenta de usuário.|  
|[CUserToolsManager::FindTool](#findtool)|Retorna o ponteiro para o `CMFCUserTool` objeto que está associado com uma ID de comando especificado.|  
|[CUserToolsManager::GetArgumentsMenuID](#getargumentsmenuid)|Retorna a ID de recurso que está associada com o **argumentos** menu o **ferramentas** guia o **personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetDefExt](#getdefext)|Retorna a extensão padrão que o **abrir arquivo** caixa de diálogo ( [CFileDialog](../../mfc/reference/cfiledialog-class.md#cfiledialog)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetFilter](#getfilter)|Retorna o filtro de arquivo que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetInitialDirMenuID](#getinitialdirmenuid)|Retorna a ID de recurso que está associada com o **diretório inicial** menu o **ferramentas** guia o **personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetMaxTools](#getmaxtools)|Retorna o número máximo de ferramentas de usuário que podem ser alocados no aplicativo.|  
|[CUserToolsManager::GetToolsEntryCmd](#gettoolsentrycmd)|Retorna a ID do espaço reservado de item de menu de ferramentas do usuário.|  
|[CUserToolsManager::GetUserTools](#getusertools)|Retorna uma referência à lista de ferramentas do usuário.|  
|[CUserToolsManager::InvokeTool](#invoketool)|Executa um aplicativo associado com a ferramenta de usuário que tem uma ID de comando especificado.|  
|[CUserToolsManager::IsUserToolCmd](#isusertoolcmd)|Determina se uma ID de comando é associada uma ferramenta de usuário.|  
|[CUserToolsManager::LoadState](#loadstate)|Carrega informações sobre ferramentas de usuário no registro do Windows.|  
|[CUserToolsManager::MoveToolDown](#movetooldown)|Move a ferramenta de usuário especificado para baixo na lista de ferramentas do usuário.|  
|[CUserToolsManager::MoveToolUp](#movetoolup)|Move a ferramenta de usuário especificado para cima na lista de ferramentas do usuário.|  
|[CUserToolsManager::RemoveTool](#removetool)|Remove a ferramenta de usuário especificado do aplicativo.|  
|[CUserToolsManager::SaveState](#savestate)|Armazena informações sobre as ferramentas de usuário no registro do Windows.|  
|[CUserToolsManager::SetDefExt](#setdefext)|Especifica a extensão padrão que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.|  
|[CUserToolsManager::SetFilter](#setfilter)|Especifica o arquivo de filtro que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Para incorporar as ferramentas de usuário em seu aplicativo, você deve:  
  
 1. Reserve um item de menu e uma ID de comando associado para uma entrada de menu da ferramenta de usuário.  
  
 2. Reserve uma ID de comando sequencial para cada ferramenta de usuário que um usuário pode definir em seu aplicativo.  
  
 3. Chamar o [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) método e forneça os seguintes parâmetros: menu ID de comando, a ID de comando da ferramenta de usuário primeiro e último ID de usuário ferramenta comando.  
  
 Deve haver apenas um global `CUserToolsManager` objeto por aplicativo.  
  
 Para obter um exemplo de ferramentas de usuário, consulte o projeto de exemplo VisualStudioDemo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como recuperar uma referência a um `CUserToolsManager` objeto e como criar novas ferramentas de usuário. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&38;](../../mfc/codesnippet/cpp/cusertoolsmanager-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CUserToolsManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxusertoolsmanager.h  
  
##  <a name="createnewtool"></a>CUserToolsManager::CreateNewTool  
 Cria uma nova ferramenta de usuário.  
  
```  
CUserTool* CreateNewTool();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a ferramenta de usuário recém-criado ou `NULL` se o número de ferramentas de usuário excedeu o máximo. O tipo retornado é o mesmo que o tipo que é passado para `CWinAppEx::EnableUserTools` como o `pToolRTC` parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Esse método localiza a primeira ID de comando de menu disponíveis no intervalo fornecido na chamada para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) e atribui a ferramenta do usuário essa ID.  
  
 O método falhará se o número de ferramentas atingiu o máximo. Isso ocorre quando todas as IDs de comando dentro do intervalo são atribuídas às ferramentas do usuário. Você pode recuperar o número máximo de ferramentas chamando [CUserToolsManager::GetMaxTools](#getmaxtools). Você pode obter acesso à lista de ferramentas ao chamar o [CUserToolsManager::GetUserTools](#getusertools) método.  
  
##  <a name="cusertoolsmanager"></a>CUserToolsManager::CUserToolsManager  
 Constrói um `CUserToolsManager`. Cada aplicativo deve ter no máximo um gerente ferramentas de usuário.  
  
```  
CUserToolsManager();

 
CUserToolsManager(
    const UINT uiCmdToolsDummy,  
    const UINT uiCmdFirst,  
    const UINT uiCmdLast,  
    CRuntimeClass* pToolRTC=RUNTIME_CLASS(CUserTool),  
    UINT uArgMenuID=0,  
    UINT uInitDirMenuID=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdToolsDummy`  
 Um inteiro sem sinal que a estrutura usa como um espaço reservado para a ID de comando do menu Ferramentas do usuário.  
  
 [in] `uiCmdFirst`  
 A ID de comando para a primeira ferramenta de comando do usuário.  
  
 [in] `uiCmdLast`  
 A ID de comando para o último comando de ferramenta do usuário.  
  
 [in] `pToolRTC`  
 A classe que [CUserToolsManager::CreateNewTool](#createnewtool) cria. Ao usar essa classe, você pode usar um tipo derivado de [CUserTool classe](../../mfc/reference/cusertool-class.md) em vez da implementação do padrão.  
  
 [in] `uArgMenuID`  
 A ID de recurso do menu do menu pop-up de argumentos.  
  
 [in] `uInitDirMenuID`  
 A ID de recurso do menu do menu pop-up diretório inicial.  
  
### <a name="remarks"></a>Comentários  
 Não chame este construtor. Em vez disso, chame [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar user tools e chamada [CWinAppEx::GetUserToolsManager](../../mfc/reference/cwinappex-class.md#getusertoolsmanager) para obter um ponteiro para o `CUserToolsManager`. Para obter mais informações, consulte [ferramentas definidas pelo usuário](../../mfc/user-defined-tools.md).  
  
##  <a name="findtool"></a>CUserToolsManager::FindTool  
 Retorna o ponteiro para o [CUserTool classe](../../mfc/reference/cusertool-class.md) objeto que está associado com uma ID de comando especificado.  
  
```  
CUserTool* FindTool(UINT uiCmdId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdId`  
 Um identificador de comando de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CUserTool classe](../../mfc/reference/cusertool-class.md) ou `CUserTool`-objeto derivado se sucesso; caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Quando `FindTool` for bem-sucedida, o tipo retornado é o mesmo que o tipo do `pToolRTC` parâmetro [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).  
  
##  <a name="getargumentsmenuid"></a>CUserToolsManager::GetArgumentsMenuID  
 Retorna a ID de recurso que está associada com o **argumentos** menu o **ferramentas** guia o **personalizar** caixa de diálogo.  
  
```  
UINT GetArgumentsMenuID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um recurso do menu.  
  
### <a name="remarks"></a>Comentários  
 O `uArgMenuID` parâmetro do [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) Especifica a ID do recurso.  
  
##  <a name="getdefext"></a>CUserToolsManager::GetDefExt  
 Retorna a extensão padrão que o **abrir arquivo** caixa de diálogo ( [CFileDialog](../../mfc/reference/cfiledialog-class.md#cfiledialog)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.  
  
```  
const CString& GetDefExt() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o `CString` objeto que contém a extensão.  
  
##  <a name="getfilter"></a>CUserToolsManager::GetFilter  
 Retorna o filtro de arquivo que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.  
  
```  
const CString& GetFilter() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o `CString` objeto que contém o filtro.  
  
##  <a name="getinitialdirmenuid"></a>CUserToolsManager::GetInitialDirMenuID  
 Retorna a ID de recurso que está associada com o **diretório inicial** menu o **ferramentas** guia o **personalizar** caixa de diálogo.  
  
```  
UINT GetInitialDirMenuID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de recurso do menu.  
  
### <a name="remarks"></a>Comentários  
 A identificação retornada é especificada no `uInitDirMenuID` parâmetro do [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).  
  
##  <a name="getmaxtools"></a>CUserToolsManager::GetMaxTools  
 Retorna o número máximo de ferramentas de usuário que podem ser alocados no aplicativo.  
  
```  
int GetMaxTools() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de ferramentas de usuário que pode ser alocado.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número máximo de ferramentas que podem ser alocados no aplicativo. Esse número é o número de IDs no intervalo entre a `uiCmdFirst` por meio de `uiCmdLast` parâmetros que você passa para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).  
  
##  <a name="gettoolsentrycmd"></a>CUserToolsManager::GetToolsEntryCmd  
 Retorna a ID do espaço reservado de item de menu de ferramentas do usuário.  
  
```  
UINT GetToolsEntryCmd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando do espaço reservado.  
  
### <a name="remarks"></a>Comentários  
 Para habilitar as ferramentas de usuário, você chamar [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools). O `uiCmdToolsDummy` parâmetro especifica a ID de comando do comando de entrada de ferramentas. Esse método retorna o ID de comando de entrada de ferramentas. Sempre que essa ID é usada em um menu, ele será substituído pela lista de ferramentas do usuário quando o menu é exibido.  
  
##  <a name="getusertools"></a>CUserToolsManager::GetUserTools  
 Retorna uma referência à lista de ferramentas do usuário.  
  
```  
const CObList& GetUserTools() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Referência a uma constante para um [CObList classe](../../mfc/reference/coblist-class.md) objeto que contém uma lista de ferramentas do usuário.  
  
### <a name="remarks"></a>Comentários  
 Chamada para esse método para recuperar uma lista de usuários das ferramentas que o [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) objeto mantém. Cada ferramenta de usuário é representada por um objeto do tipo [CUserTool classe](../../mfc/reference/cusertool-class.md) ou um tipo derivado de `CUserTool`. O tipo é especificado o `pToolRTC` parâmetro ao chamar [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar ferramentas do usuário.  
  
##  <a name="invoketool"></a>CUserToolsManager::InvokeTool  
 Executa um aplicativo associado com a ferramenta de usuário que tem uma ID de comando especificado.  
  
```  
BOOL InvokeTool(UINT uiCmdId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdId`  
 A ID de comando de menu associada com a ferramenta do usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando associado à ferramenta de usuário foi executado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamada ferramenta desse método para executar um aplicativo associado ao usuário que possui a ID de comando especificada por `uiCmdId`.  
  
##  <a name="isusertoolcmd"></a>CUserToolsManager::IsUserToolCmd  
 Determina se uma ID de comando é associada uma ferramenta de usuário.  
  
```  
BOOL IsUserToolCmd(UINT uiCmdId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdId`  
 Uma ID de comando do item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um determinado comando ID está associada uma ferramenta de usuário. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método verifica se a ID de comando especificado está no intervalo de ID de comando. Especifique o intervalo ao chamar [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar ferramentas do usuário.  
  
##  <a name="loadstate"></a>CUserToolsManager::LoadState  
 Carrega informações sobre ferramentas de usuário no registro do Windows.  
  
```  
BOOL LoadState(LPCTSTR lpszProfileName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 O caminho da chave do registro do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o estado foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método carrega o estado do `CUserToolsManager` objeto do registro do Windows.  
  
 Normalmente, você não chamar esse método diretamente. [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate) chama como parte do processo de inicialização do espaço de trabalho.  
  
##  <a name="movetooldown"></a>CUserToolsManager::MoveToolDown  
 Move a ferramenta de usuário especificado para baixo na lista de ferramentas do usuário.  
  
```  
BOOL MoveToolDown(CUserTool* pTool);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTool`  
 Especifica a ferramenta Mover do usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ferramenta do usuário foi movida para baixo com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O método falhará se a ferramenta que o `pTool` especifica não está na lista interna ou se a ferramenta é o última da lista.  
  
##  <a name="movetoolup"></a>CUserToolsManager::MoveToolUp  
 Move a ferramenta de usuário especificado para cima na lista de ferramentas do usuário.  
  
```  
BOOL MoveToolUp(CUserTool* pTool);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTool`  
 Especifica a ferramenta Mover do usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ferramenta do usuário foi movida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O método falhará se a ferramenta que o `pTool` parâmetro especifica que não está na lista interna ou se a ferramenta é o primeiro item de ferramenta na lista.  
  
##  <a name="removetool"></a>CUserToolsManager::RemoveTool  
 Remove a ferramenta de usuário especificado do aplicativo.  
  
```  
BOOL RemoveTool(CUserTool* pTool);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pTool`  
 Um ponteiro para uma ferramenta de usuário a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a ferramenta for removida com êxito. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se a ferramenta for removida com êxito, esse método exclui `pTool`.  
  
##  <a name="savestate"></a>CUserToolsManager::SaveState  
 Armazena informações sobre as ferramentas de usuário no registro do Windows.  
  
```  
BOOL SaveState(LPCTSTR lpszProfileName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Um caminho para a chave de registro do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o estado salvo com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O método armazena o estado atual do `CUserToolsManager` objeto no registro do Windows.  
  
 Normalmente, você não precisa chamar esse método diretamente, [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate) chama automaticamente como parte do processo de serialização de espaço de trabalho do aplicativo.  
  
##  <a name="setdefext"></a>CUserToolsManager::SetDefExt  
 Especifica a extensão padrão que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.  
  
```  
void SetDefExt(const CString& strDefExt);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strDefExt`  
 Uma cadeia de caracteres de texto que contém a extensão de nome de arquivo padrão.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para especificar a extensão de nome de arquivo padrão no **abrir arquivo** caixa de diálogo que é exibida quando o usuário seleciona um aplicativo para associar com a ferramenta do usuário. O padrão é "exe".  
  
##  <a name="setfilter"></a>CUserToolsManager::SetFilter  
 Especifica o arquivo de filtro que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia do **personalizar** caixa de diálogo.  
  
```  
void SetFilter(const CString& strFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strFilter`  
 Especifica o filtro.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [Classe CUserTool](../../mfc/reference/cusertool-class.md)


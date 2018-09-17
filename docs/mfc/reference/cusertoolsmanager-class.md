---
title: Classe CUserToolsManager | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CUserToolsManager [MFC], CUserToolsManager
- CUserToolsManager [MFC], CreateNewTool
- CUserToolsManager [MFC], FindTool
- CUserToolsManager [MFC], GetArgumentsMenuID
- CUserToolsManager [MFC], GetDefExt
- CUserToolsManager [MFC], GetFilter
- CUserToolsManager [MFC], GetInitialDirMenuID
- CUserToolsManager [MFC], GetMaxTools
- CUserToolsManager [MFC], GetToolsEntryCmd
- CUserToolsManager [MFC], GetUserTools
- CUserToolsManager [MFC], InvokeTool
- CUserToolsManager [MFC], IsUserToolCmd
- CUserToolsManager [MFC], LoadState
- CUserToolsManager [MFC], MoveToolDown
- CUserToolsManager [MFC], MoveToolUp
- CUserToolsManager [MFC], RemoveTool
- CUserToolsManager [MFC], SaveState
- CUserToolsManager [MFC], SetDefExt
- CUserToolsManager [MFC], SetFilter
ms.assetid: bdfa37ae-efca-4616-abb5-9d0dcd2d335b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 19c2622802fe984f586bb3a8a7b3c67f52cc82b6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701669"
---
# <a name="cusertoolsmanager-class"></a>Classe CUserToolsManager
Mantém a coleção de [classe CUserTool](../../mfc/reference/cusertool-class.md) objetos em um aplicativo. Uma ferramenta de usuário é um item de menu que executa um aplicativo externo. O `CUserToolsManager` objeto permite que o usuário ou o desenvolvedor adicione novas ferramentas de usuário para o aplicativo. Ele oferece suporte à execução de comandos associados com as ferramentas do usuário, e ele também salva as informações sobre as ferramentas do usuário no registro do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CUserToolsManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserToolsManager::CUserToolsManager](#cusertoolsmanager)|Constrói um `CUserToolsManager`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUserToolsManager::CreateNewTool](#createnewtool)|Cria uma nova ferramenta de usuário.|  
|[CUserToolsManager::FindTool](#findtool)|Retorna o ponteiro para o `CMFCUserTool` objeto que está associado com uma ID de comando especificado.|  
|[CUserToolsManager::GetArgumentsMenuID](#getargumentsmenuid)|Retorna a ID de recurso que está associada com o **argumentos** menu a **ferramentas** guia dos **personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetDefExt](#getdefext)|Retorna a extensão padrão que o **abrir arquivo** caixa de diálogo ( [CFileDialog](../../mfc/reference/cfiledialog-class.md#cfiledialog)) usa no **comando** campo o **ferramentas** guia da **Personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetFilter](#getfilter)|Retorna o filtro de arquivo que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa no **comando** campo o **ferramentas** guia da **Personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetInitialDirMenuID](#getinitialdirmenuid)|Retorna a ID de recurso que está associada com o **diretório inicial** menu a **ferramentas** guia dos **personalizar** caixa de diálogo.|  
|[CUserToolsManager::GetMaxTools](#getmaxtools)|Retorna o número máximo de ferramentas de usuário que podem ser alocados no aplicativo.|  
|[CUserToolsManager::GetToolsEntryCmd](#gettoolsentrycmd)|Retorna a ID do espaço reservado de item de menu para as ferramentas do usuário.|  
|[CUserToolsManager::GetUserTools](#getusertools)|Retorna uma referência à lista de ferramentas do usuário.|  
|[CUserToolsManager::InvokeTool](#invoketool)|Executa um aplicativo associado com a ferramenta de usuário que tem uma ID de comando especificado.|  
|[CUserToolsManager::IsUserToolCmd](#isusertoolcmd)|Determina se uma ID de comando é associada uma ferramenta de usuário.|  
|[CUserToolsManager::LoadState](#loadstate)|Carrega informações sobre as ferramentas do usuário de registro do Windows.|  
|[CUserToolsManager::MoveToolDown](#movetooldown)|Move a ferramenta de usuário especificado para baixo na lista de ferramentas do usuário.|  
|[CUserToolsManager::MoveToolUp](#movetoolup)|Move a ferramenta de usuário especificado para cima na lista de ferramentas do usuário.|  
|[CUserToolsManager::RemoveTool](#removetool)|Remove a ferramenta de usuário especificado do aplicativo.|  
|[CUserToolsManager::SaveState](#savestate)|Armazena informações sobre as ferramentas do usuário no registro do Windows.|  
|[CUserToolsManager::SetDefExt](#setdefext)|Especifica a extensão padrão que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia dos **personalizar** caixa de diálogo.|  
|[CUserToolsManager::SetFilter](#setfilter)|Especifica o arquivo de filtro que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa no **comando** campo o **ferramentas** guia da **Personalizar** caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Para incorporar as ferramentas do usuário em seu aplicativo, faça o seguinte:  
  
 1. Reserve um item de menu e uma ID de comando associado para uma entrada de menu da ferramenta de usuário.  
  
 2. Reserve uma ID de comando sequenciais para cada ferramenta de usuário que um usuário pode definir em seu aplicativo.  
  
 3. Chame o [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) método e fornecer os seguintes parâmetros: menu ID de comando, a ID de comando da ferramenta de usuário primeiro e último usuário ferramenta ID de comando.  
  
 Deve haver apenas um global `CUserToolsManager` objeto por aplicativo.  
  
 Para obter um exemplo das ferramentas de usuário, consulte o projeto de exemplo VisualStudioDemo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como recuperar uma referência a um `CUserToolsManager` objeto e como criar novas ferramentas de usuário. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#38](../../mfc/codesnippet/cpp/cusertoolsmanager-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CUserToolsManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxusertoolsmanager.h  
  
##  <a name="createnewtool"></a>  CUserToolsManager::CreateNewTool  
 Cria uma nova ferramenta de usuário.  
  
```  
CUserTool* CreateNewTool();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a ferramenta de usuário recém-criados, ou nulo se o número de ferramentas do usuário excedeu o máximo. O tipo retornado é o mesmo que o tipo que é passado para `CWinAppEx::EnableUserTools` como o *pToolRTC* parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Esse método localiza a primeira ID de comando de menu disponíveis no intervalo que é fornecido na chamada para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) e atribui a ferramenta de usuário essa ID.  
  
 O método falhará se o número de ferramentas tiver atingido o máximo. Isso ocorre quando todas as IDs de comando dentro do intervalo são atribuídas às ferramentas do usuário. Você pode recuperar o número máximo de ferramentas, chamando [CUserToolsManager::GetMaxTools](#getmaxtools). Você pode obter acesso à lista de ferramentas, chamando o [CUserToolsManager::GetUserTools](#getusertools) método.  
  
##  <a name="cusertoolsmanager"></a>  CUserToolsManager::CUserToolsManager  
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
*uiCmdToolsDummy*<br/>
[in] Um inteiro sem sinal de que a estrutura usa como um espaço reservado para a ID de comando do menu de ferramentas do usuário.  
  
*uiCmdFirst*<br/>
[in] A ID de comando para o primeiro comando de ferramenta do usuário.  
  
*uiCmdLast*<br/>
[in] A ID de comando para o último comando de ferramenta do usuário.  
  
*pToolRTC*<br/>
[in] A classe que [CUserToolsManager::CreateNewTool](#createnewtool) cria. Ao usar essa classe, você pode usar um tipo derivado de [classe CUserTool](../../mfc/reference/cusertool-class.md) em vez da implementação do padrão.  
  
*uArgMenuID*<br/>
[in] A ID de recurso de menu do menu pop-up de argumentos.  
  
*uInitDirMenuID*<br/>
[in] A ID de recurso de menu do menu pop-up do diretório inicial.  
  
### <a name="remarks"></a>Comentários  
 Não chame este construtor. Em vez disso, chame [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) habilite as ferramentas de usuário e a chamada [CWinAppEx::GetUserToolsManager](../../mfc/reference/cwinappex-class.md#getusertoolsmanager) para obter um ponteiro para o `CUserToolsManager`. Para obter mais informações, consulte [ferramentas definidas pelo usuário](../../mfc/user-defined-tools.md).  
  
##  <a name="findtool"></a>  CUserToolsManager::FindTool  
 Retorna o ponteiro para o [classe CUserTool](../../mfc/reference/cusertool-class.md) objeto que está associado com uma ID de comando especificado.  
  
```  
CUserTool* FindTool(UINT uiCmdId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
*uiCmdId*<br/>
[in] Um identificador de comando de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [classe CUserTool](../../mfc/reference/cusertool-class.md) ou `CUserTool`-objeto derivado se êxito; caso contrário, NULL.  
  
### <a name="remarks"></a>Comentários  
 Quando `FindTool` é bem-sucedida, o tipo retornado é o mesmo que o tipo dos *pToolRTC* parâmetro [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).  
  
##  <a name="getargumentsmenuid"></a>  CUserToolsManager::GetArgumentsMenuID  
 Retorna a ID de recurso que está associada com o **argumentos** menu a **ferramentas** guia dos **personalizar** caixa de diálogo.  
  
```  
UINT GetArgumentsMenuID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um recurso de menu.  
  
### <a name="remarks"></a>Comentários  
 O *uArgMenuID* parâmetro do [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) Especifica a ID do recurso.  
  
##  <a name="getdefext"></a>  CUserToolsManager::GetDefExt  
 Retorna a extensão padrão que o **abrir arquivo** caixa de diálogo ( [CFileDialog](../../mfc/reference/cfiledialog-class.md#cfiledialog)) usa no **comando** campo o **ferramentas** guia da **Personalizar** caixa de diálogo.  
  
```  
const CString& GetDefExt() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o `CString` objeto que contém a extensão.  
  
##  <a name="getfilter"></a>  CUserToolsManager::GetFilter  
 Retorna o filtro de arquivo que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa no **comando** campo o **ferramentas** guia da **Personalizar** caixa de diálogo.  
  
```  
const CString& GetFilter() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para o `CString` objeto que contém o filtro.  
  
##  <a name="getinitialdirmenuid"></a>  CUserToolsManager::GetInitialDirMenuID  
 Retorna a ID de recurso que está associada com o **diretório inicial** menu a **ferramentas** guia dos **personalizar** caixa de diálogo.  
  
```  
UINT GetInitialDirMenuID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de recurso de menu.  
  
### <a name="remarks"></a>Comentários  
 A identificação retornada é especificada na *uInitDirMenuID* parâmetro do [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).  
  
##  <a name="getmaxtools"></a>  CUserToolsManager::GetMaxTools  
 Retorna o número máximo de ferramentas de usuário que podem ser alocados no aplicativo.  
  
```  
int GetMaxTools() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de ferramentas de usuário que podem ser alocados.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número máximo de ferramentas que podem ser alocados no aplicativo. Esse número é o número de IDs no intervalo entre a *uiCmdFirst* por meio de *uiCmdLast* parâmetros que você passa para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).  
  
##  <a name="gettoolsentrycmd"></a>  CUserToolsManager::GetToolsEntryCmd  
 Retorna a ID do espaço reservado de item de menu para as ferramentas do usuário.  
  
```  
UINT GetToolsEntryCmd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando do espaço reservado.  
  
### <a name="remarks"></a>Comentários  
 Para habilitar as ferramentas do usuário, você chama [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools). O *uiCmdToolsDummy* parâmetro especifica a ID de comando do comando de entrada de ferramentas. Esse método retorna a ID de comando de entrada de ferramentas. Independentemente de onde essa ID é usada em um menu, ele será substituído pela lista de ferramentas do usuário quando o menu é exibido.  
  
##  <a name="getusertools"></a>  CUserToolsManager::GetUserTools  
 Retorna uma referência à lista de ferramentas do usuário.  
  
```  
const CObList& GetUserTools() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência const para um [classe CObList](../../mfc/reference/coblist-class.md) objeto que contém uma lista de ferramentas do usuário.  
  
### <a name="remarks"></a>Comentários  
 Chamada para esse método para recuperar uma lista do usuário das ferramentas de que o [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) objeto mantém. Cada ferramenta de usuário é representada por um objeto do tipo [classe CUserTool](../../mfc/reference/cusertool-class.md) ou um tipo derivado de `CUserTool`. O tipo é especificado o *pToolRTC* parâmetro ao chamar [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar as ferramentas de usuário.  
  
##  <a name="invoketool"></a>  CUserToolsManager::InvokeTool  
 Executa um aplicativo associado com a ferramenta de usuário que tem uma ID de comando especificado.  
  
```  
BOOL InvokeTool(UINT uiCmdId);
```  
  
### <a name="parameters"></a>Parâmetros  
*uiCmdId*<br/>
[in] A ID de comando de menu associada com a ferramenta de usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o comando associado à ferramenta de usuário foi executado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamada de ferramenta desse método para executar um aplicativo associado ao usuário que tem a ID de comando especificada por *uiCmdId*.  
  
##  <a name="isusertoolcmd"></a>  CUserToolsManager::IsUserToolCmd  
 Determina se uma ID de comando é associada uma ferramenta de usuário.  
  
```  
BOOL IsUserToolCmd(UINT uiCmdId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
*uiCmdId*<br/>
[in] Uma ID de comando do item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma ID de comando fornecido está associada com uma ferramenta de usuário; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método verifica se a ID de comando especificada está no intervalo de ID de comando. Especifique o intervalo, quando você chama [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar as ferramentas de usuário.  
  
##  <a name="loadstate"></a>  CUserToolsManager::LoadState  
 Carrega informações sobre as ferramentas do usuário de registro do Windows.  
  
```  
BOOL LoadState(LPCTSTR lpszProfileName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
*lpszProfileName*<br/>
[in] O caminho da chave do registro do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o estado foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método carrega o estado do `CUserToolsManager` objeto do registro do Windows.  
  
 Normalmente, você não chamar este método diretamente. [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate) chama-o como parte do processo de inicialização do espaço de trabalho.  
  
##  <a name="movetooldown"></a>  CUserToolsManager::MoveToolDown  
 Move a ferramenta de usuário especificado para baixo na lista de ferramentas do usuário.  
  
```  
BOOL MoveToolDown(CUserTool* pTool);
```  
  
### <a name="parameters"></a>Parâmetros  
*pTool*<br/>
[in] Especifica a ferramenta de usuário para mover.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ferramenta de usuário foi movida para baixo com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O método falhará se a ferramenta de que o *pTool* especifica não está na lista interna ou se a ferramenta é por último na lista.  
  
##  <a name="movetoolup"></a>  CUserToolsManager::MoveToolUp  
 Move a ferramenta de usuário especificado para cima na lista de ferramentas do usuário.  
  
```  
BOOL MoveToolUp(CUserTool* pTool);
```  
  
### <a name="parameters"></a>Parâmetros  
*pTool*<br/>
[in] Especifica a ferramenta de usuário para mover.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ferramenta de usuário foi movida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O método falhará se a ferramenta de que o *pTool* parâmetro especifica que não está na lista interna ou se a ferramenta é o primeiro item na lista de ferramenta.  
  
##  <a name="removetool"></a>  CUserToolsManager::RemoveTool  
 Remove a ferramenta de usuário especificado do aplicativo.  
  
```  
BOOL RemoveTool(CUserTool* pTool);
```  
  
### <a name="parameters"></a>Parâmetros  
*pTool*<br/>
[no, out] Um ponteiro para uma ferramenta de usuário a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a ferramenta for removida com êxito. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Se a ferramenta for removida com êxito, este método exclui *pTool*.  
  
##  <a name="savestate"></a>  CUserToolsManager::SaveState  
 Armazena informações sobre as ferramentas do usuário no registro do Windows.  
  
```  
BOOL SaveState(LPCTSTR lpszProfileName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
*lpszProfileName*<br/>
[in] Um caminho para a chave de registro do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o estado foi salvo com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O método armazena o estado atual do `CUserToolsManager` objeto no registro do Windows.  
  
 Normalmente, você não precisará chamar este método diretamente, [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate) chama automaticamente como parte do processo de serialização de espaço de trabalho do aplicativo.  
  
##  <a name="setdefext"></a>  CUserToolsManager::SetDefExt  
 Especifica a extensão padrão que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa o **comando** campo o **ferramentas** guia dos **personalizar** caixa de diálogo.  
  
```  
void SetDefExt(const CString& strDefExt);
```  
  
### <a name="parameters"></a>Parâmetros  
*strDefExt*<br/>
[in] Uma cadeia de caracteres de texto que contém a extensão de nome de arquivo padrão.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para especificar uma extensão de nome de arquivo padrão na **abrir arquivo** caixa de diálogo que é exibida quando o usuário seleciona um aplicativo para associar com a ferramenta de usuário. O padrão é "exe".  
  
##  <a name="setfilter"></a>  CUserToolsManager::SetFilter  
 Especifica o arquivo de filtro que o **abrir arquivo** caixa de diálogo ( [classe CFileDialog](../../mfc/reference/cfiledialog-class.md)) usa no **comando** campo o **ferramentas** guia da **Personalizar** caixa de diálogo.  
  
```  
void SetFilter(const CString& strFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
*strFilter*<br/>
[in] Especifica o filtro.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [Classe CUserTool](../../mfc/reference/cusertool-class.md)

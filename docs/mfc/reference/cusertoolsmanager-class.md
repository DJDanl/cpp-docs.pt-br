---
title: Classe CUserToolsManager
ms.date: 11/04/2016
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
ms.openlocfilehash: c1f14657350c08679868299ce4878cca2ae10eec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373233"
---
# <a name="cusertoolsmanager-class"></a>Classe CUserToolsManager

Mantém a coleção de objetos [CUserTool Class](../../mfc/reference/cusertool-class.md) em um aplicativo. Uma ferramenta do usuário é um item de menu que executa um aplicativo externo. O `CUserToolsManager` objeto permite que o usuário ou desenvolvedor adicione novas ferramentas de usuário ao aplicativo. Ele suporta a execução dos comandos associados às ferramentas do usuário, e também salva informações sobre ferramentas do usuário no registro do Windows.

## <a name="syntax"></a>Sintaxe

```
class CUserToolsManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CuserToolsManager::CUserToolsManager](#cusertoolsmanager)|Constrói um `CUserToolsManager`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CuserToolsManager::CreateNewTool](#createnewtool)|Cria uma nova ferramenta de usuário.|
|[CuserToolsManager::FindTool](#findtool)|Retorna o ponteiro `CMFCUserTool` para o objeto associado a um ID de comando especificado.|
|[CUserToolsManager::GetArgumentsMenuID](#getargumentsmenuid)|Retorna o ID de recurso associado ao menu **Argumentos** na guia **Ferramentas** da caixa de diálogo **Personalizar.**|
|[CUserToolsManager::GetDefExt](#getdefext)|Retorna a extensão padrão que a caixa de diálogo **Arquivo Abrir** de Arquivos [(CFileDialog)](../../mfc/reference/cfiledialog-class.md#cfiledialog)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.**|
|[CuserToolsManager::GetFilter](#getfilter)|Retorna o filtro de arquivo que a caixa de diálogo **Arquivo Abrir** [(CFileDialog Class)](../../mfc/reference/cfiledialog-class.md)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.**|
|[Cusertoolsmanager::getinitialdirmenuid](#getinitialdirmenuid)|Retorna o ID de recurso associado ao menu **diretório inicial** na guia **Ferramentas** da caixa de diálogo **Personalizar.**|
|[CusertoolsManager::GetMaxTools](#getmaxtools)|Retorna o número máximo de ferramentas de usuário que podem ser alocadas no aplicativo.|
|[CUserToolsManager::GetToolsEntryCmd](#gettoolsentrycmd)|Retorna o ID de comando do espaço reservado do item do menu para as ferramentas do usuário.|
|[CuserToolsManager::GetUserTools](#getusertools)|Retorna uma referência à lista de ferramentas do usuário.|
|[CuserToolsManager::InvokeTool](#invoketool)|Executa um aplicativo associado à ferramenta do usuário que tenha um ID de comando especificado.|
|[CUserToolsManager::IsUserToolCmd](#isusertoolcmd)|Determina se um ID de comando está associado a uma ferramenta do usuário.|
|[CuserToolsManager::LoadState](#loadstate)|Carrega informações sobre ferramentas do usuário a partir do registro do Windows.|
|[CuserToolsManager::MovetoolDown](#movetooldown)|Move a ferramenta de usuário especificada para baixo na lista de ferramentas do usuário.|
|[CuserToolsManager::MovetoolUp](#movetoolup)|Move a ferramenta de usuário especificada para cima na lista de ferramentas do usuário.|
|[CuserToolsManager::RemoveTool](#removetool)|Remove a ferramenta de usuário especificada do aplicativo.|
|[CuserToolsManager::SaveState](#savestate)|Armazena informações sobre ferramentas do usuário no registro do Windows.|
|[CUserToolsManager::SetDefExt](#setdefext)|Especifica a extensão padrão que a caixa de diálogo [CFileDialog (CFileDialog Class)](../../mfc/reference/cfiledialog-class.md)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.** **File Open**|
|[CUserToolsManager::SetFilter](#setfilter)|Especifica o filtro de arquivo que a caixa de diálogo [CFileDialog (CFileDialog Class)](../../mfc/reference/cfiledialog-class.md)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.** **File Open**|

## <a name="remarks"></a>Comentários

Para incorporar as ferramentas do usuário em seu aplicativo, você deve:

1. Reserve um item do menu e um ID de comando associado para uma entrada no menu da ferramenta do usuário.

2. Reserve um ID de comando seqüencial para cada ferramenta de usuário que um usuário pode definir em seu aplicativo.

3. Ligue para o [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) método e forneça os seguintes parâmetros: menu comando ID, ID de comando da primeira ferramenta do usuário e ID de comando da última ferramenta do usuário.

Deve haver apenas `CUserToolsManager` um objeto global por aplicativo.

Para um exemplo de ferramentas do usuário, consulte o projeto de amostra VisualStudioDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CUserToolsManager` recuperar uma referência a um objeto e como criar novas ferramentas de usuário. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#38](../../mfc/codesnippet/cpp/cusertoolsmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CUserToolsManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxusertoolsmanager.h

## <a name="cusertoolsmanagercreatenewtool"></a><a name="createnewtool"></a>CuserToolsManager::CreateNewTool

Cria uma nova ferramenta de usuário.

```
CUserTool* CreateNewTool();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a ferramenta de usuário recém-criada, ou NULL se o número de ferramentas do usuário tiver excedido o máximo. O tipo retornado é o mesmo que `CWinAppEx::EnableUserTools` o tipo que é passado para o parâmetro *pToolRTC.*

### <a name="remarks"></a>Comentários

Este método encontra o primeiro ID de comando de menu disponível na faixa fornecida na chamada para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) e atribui à ferramenta do usuário este ID.

O método falha se o número de ferramentas tiver atingido o máximo. Isso ocorre quando todos os IDs de comando dentro do intervalo são atribuídos às ferramentas do usuário. Você pode recuperar o número máximo de ferramentas chamando [CUserToolsManager::GetMaxTools](#getmaxtools). Você pode ter acesso à lista de ferramentas chamando o método [CUserToolsManager::GetUserTools.](#getusertools)

## <a name="cusertoolsmanagercusertoolsmanager"></a><a name="cusertoolsmanager"></a>CuserToolsManager::CUserToolsManager

Constrói um `CUserToolsManager`. Cada aplicativo deve ter no máximo um gerenciador de ferramentas de usuário.

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
[em] Um inteiro não assinado que a estrutura usa como espaço reservado para o ID de comando do menu de ferramentas do usuário.

*uiCmdPrimeiro*<br/>
[em] O iD de comando para o primeiro comando da ferramenta do usuário.

*uiCmdLast*<br/>
[em] O iD de comando para o último comando da ferramenta do usuário.

*Ptoolrtc*<br/>
[em] A classe que [cUsertoolsmanager::CreateNewTool](#createnewtool) cria. Usando esta classe, você pode usar um tipo derivado de [Classe CUserTool](../../mfc/reference/cusertool-class.md) em vez da implementação padrão.

*uArgMenuID*<br/>
[em] O iD de recurso do menu de argumentos popup.

*uInitDirMenuID*<br/>
[em] O iD de recurso do menu popup do diretório inicial.

### <a name="remarks"></a>Comentários

Não chame isso de construtor. Em vez disso, ligue para [cwinappEx::HabilitarFerramentas de usuário](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar as ferramentas do `CUserToolsManager`usuário e chamar [CWinAppEx::GetUserToolsManager](../../mfc/reference/cwinappex-class.md#getusertoolsmanager) para obter um ponteiro para o . Para obter mais informações, consulte [Ferramentas definidas pelo usuário](../../mfc/user-defined-tools.md).

## <a name="cusertoolsmanagerfindtool"></a><a name="findtool"></a>CuserToolsManager::FindTool

Retorna o ponteiro para o objeto [CUserTool Class](../../mfc/reference/cusertool-class.md) que está associado a um ID de comando especificado.

```
CUserTool* FindTool(UINT uiCmdId) const;
```

### <a name="parameters"></a>Parâmetros

*uiCmdId*<br/>
[em] Um identificador de comando de menu.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma classe `CUserTool` [CUserTool](../../mfc/reference/cusertool-class.md) ou objeto derivado se for bem-; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Quando `FindTool` é bem-sucedido, o tipo retornado é o mesmo que o tipo de parâmetro *pToolRTC* para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).

## <a name="cusertoolsmanagergetargumentsmenuid"></a><a name="getargumentsmenuid"></a>CUserToolsManager::GetArgumentsMenuID

Retorna o ID de recurso associado ao menu **Argumentos** na guia **Ferramentas** da caixa de diálogo **Personalizar.**

```
UINT GetArgumentsMenuID() const;
```

### <a name="return-value"></a>Valor retornado

O identificador de um recurso de menu.

### <a name="remarks"></a>Comentários

O parâmetro *uArgMenuID* do [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) especifica o ID do recurso.

## <a name="cusertoolsmanagergetdefext"></a><a name="getdefext"></a>CUserToolsManager::GetDefExt

Retorna a extensão padrão que a caixa de diálogo **Arquivo Abrir** de Arquivos [(CFileDialog)](../../mfc/reference/cfiledialog-class.md#cfiledialog)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.**

```
const CString& GetDefExt() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência `CString` ao objeto que contém a extensão.

## <a name="cusertoolsmanagergetfilter"></a><a name="getfilter"></a>CuserToolsManager::GetFilter

Retorna o filtro de arquivo que a caixa de diálogo **Arquivo Abrir** [(CFileDialog Class)](../../mfc/reference/cfiledialog-class.md)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.**

```
const CString& GetFilter() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência `CString` ao objeto que contém o filtro.

## <a name="cusertoolsmanagergetinitialdirmenuid"></a><a name="getinitialdirmenuid"></a>Cusertoolsmanager::getinitialdirmenuid

Retorna o ID de recurso associado ao menu **diretório inicial** na guia **Ferramentas** da caixa de diálogo **Personalizar.**

```
UINT GetInitialDirMenuID() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador de recurso de menu.

### <a name="remarks"></a>Comentários

O ID retornado é especificado no parâmetro *uInitDirMenuID* do [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).

## <a name="cusertoolsmanagergetmaxtools"></a><a name="getmaxtools"></a>CusertoolsManager::GetMaxTools

Retorna o número máximo de ferramentas de usuário que podem ser alocadas no aplicativo.

```
int GetMaxTools() const;
```

### <a name="return-value"></a>Valor retornado

O número máximo de ferramentas de usuário que podem ser alocadas.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número máximo de ferramentas que podem ser alocadas no aplicativo. Este número é o número de IDs na faixa desde o *uiCmdFirst* até os parâmetros *uiCmdLast* que você passa para [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools).

## <a name="cusertoolsmanagergettoolsentrycmd"></a><a name="gettoolsentrycmd"></a>CUserToolsManager::GetToolsEntryCmd

Retorna o ID de comando do espaço reservado do item do menu para as ferramentas do usuário.

```
UINT GetToolsEntryCmd() const;
```

### <a name="return-value"></a>Valor retornado

O comando id do espaço reservado.

### <a name="remarks"></a>Comentários

Para habilitar as ferramentas do usuário, você chama [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools). O parâmetro *uiCmdToolsDummy* especifica o ID de comando do comando de entrada de ferramentas. Este método retorna o iD de comando de entrada de ferramentas. Onde quer que esse ID seja usado em um menu, ele é substituído pela lista de ferramentas do usuário quando o menu aparece.

## <a name="cusertoolsmanagergetusertools"></a><a name="getusertools"></a>CuserToolsManager::GetUserTools

Retorna uma referência à lista de ferramentas do usuário.

```
const CObList& GetUserTools() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência const a um objeto [CObList Class](../../mfc/reference/coblist-class.md) que contém uma lista de ferramentas do usuário.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar uma lista de ferramentas do usuário que o objeto [CUserToolsManager](../../mfc/reference/cusertoolsmanager-class.md) mantém. Cada ferramenta do usuário é representada por um objeto do `CUserTool`tipo [CUserTool Class](../../mfc/reference/cusertool-class.md) ou um tipo derivado de . O tipo é especificado pelo parâmetro *pToolRTC* quando você chama [CWinAppEx::EnableUserTools](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar ferramentas do usuário.

## <a name="cusertoolsmanagerinvoketool"></a><a name="invoketool"></a>CuserToolsManager::InvokeTool

Executa um aplicativo associado à ferramenta do usuário que tenha um ID de comando especificado.

```
BOOL InvokeTool(UINT uiCmdId);
```

### <a name="parameters"></a>Parâmetros

*uiCmdId*<br/>
[em] O ID de comando do menu associado à ferramenta do usuário.

### <a name="return-value"></a>Valor retornado

Não zero se o comando associado à ferramenta do usuário foi executado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame este método para executar um aplicativo associado à ferramenta do usuário que tenha o ID de comando especificado por *uiCmdId*.

## <a name="cusertoolsmanagerisusertoolcmd"></a><a name="isusertoolcmd"></a>CUserToolsManager::IsUserToolCmd

Determina se um ID de comando está associado a uma ferramenta do usuário.

```
BOOL IsUserToolCmd(UINT uiCmdId) const;
```

### <a name="parameters"></a>Parâmetros

*uiCmdId*<br/>
[em] Um ID de comando do item do menu.

### <a name="return-value"></a>Valor retornado

Não zero se um determinado ID de comando estiver associado a uma ferramenta do usuário; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método verifica se o ID de comando dado está no intervalo de identificação de comando. Você especifica o intervalo quando você chama [CWinAppEx::HabilitarFerramentas de usuário](../../mfc/reference/cwinappex-class.md#enableusertools) para habilitar as ferramentas do usuário.

## <a name="cusertoolsmanagerloadstate"></a><a name="loadstate"></a>CuserToolsManager::LoadState

Carrega informações sobre ferramentas do usuário a partir do registro do Windows.

```
BOOL LoadState(LPCTSTR lpszProfileName=NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] O caminho da chave de registro do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se o estado foi carregado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método carrega o `CUserToolsManager` estado do objeto a partir do registro do Windows.

Normalmente, você não chama esse método diretamente. [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate) chama-o como parte do processo de inicialização do espaço de trabalho.

## <a name="cusertoolsmanagermovetooldown"></a><a name="movetooldown"></a>CuserToolsManager::MovetoolDown

Move a ferramenta de usuário especificada para baixo na lista de ferramentas do usuário.

```
BOOL MoveToolDown(CUserTool* pTool);
```

### <a name="parameters"></a>Parâmetros

*pTool*<br/>
[em] Especifica a ferramenta do usuário para mover.

### <a name="return-value"></a>Valor retornado

Não zero se a ferramenta do usuário foi transferida com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O método falha se a ferramenta que o *pTool* especifica não estiver na lista interna ou se a ferramenta for a última da lista.

## <a name="cusertoolsmanagermovetoolup"></a><a name="movetoolup"></a>CuserToolsManager::MovetoolUp

Move a ferramenta de usuário especificada para cima na lista de ferramentas do usuário.

```
BOOL MoveToolUp(CUserTool* pTool);
```

### <a name="parameters"></a>Parâmetros

*pTool*<br/>
[em] Especifica a ferramenta do usuário para mover.

### <a name="return-value"></a>Valor retornado

Não zero se a ferramenta do usuário foi movida para cima com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O método falha se a ferramenta que o parâmetro *pTool* especifica não estiver na lista interna ou se a ferramenta for o primeiro item da ferramenta na lista.

## <a name="cusertoolsmanagerremovetool"></a><a name="removetool"></a>CuserToolsManager::RemoveTool

Remove a ferramenta de usuário especificada do aplicativo.

```
BOOL RemoveTool(CUserTool* pTool);
```

### <a name="parameters"></a>Parâmetros

*pTool*<br/>
[dentro, fora] Um ponteiro para uma ferramenta de usuário a ser removido.

### <a name="return-value"></a>Valor retornado

TRUE se a ferramenta for removida com sucesso. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se a ferramenta for removida com sucesso, este método excluirá *pTool*.

## <a name="cusertoolsmanagersavestate"></a><a name="savestate"></a>CuserToolsManager::SaveState

Armazena informações sobre ferramentas do usuário no registro do Windows.

```
BOOL SaveState(LPCTSTR lpszProfileName=NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Um caminho para a chave de registro do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se o estado foi salvo com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O método armazena o `CUserToolsManager` estado atual do objeto no registro do Windows.

Normalmente, você não precisa chamar esse método diretamente, [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate) chama-o automaticamente como parte do processo de serialização do espaço de trabalho do aplicativo.

## <a name="cusertoolsmanagersetdefext"></a><a name="setdefext"></a>CUserToolsManager::SetDefExt

Especifica a extensão padrão que a caixa de diálogo [CFileDialog (CFileDialog Class)](../../mfc/reference/cfiledialog-class.md)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.** **File Open**

```
void SetDefExt(const CString& strDefExt);
```

### <a name="parameters"></a>Parâmetros

*strDefExt*<br/>
[em] Uma seqüência de texto que contém a extensão de nome de arquivo padrão.

### <a name="remarks"></a>Comentários

Chame este método para especificar uma extensão de nome de arquivo padrão na caixa de diálogo **Abrir arquivos,** que é exibida quando o usuário seleciona um aplicativo para associar-se à ferramenta do usuário. O padrão é "exe".

## <a name="cusertoolsmanagersetfilter"></a><a name="setfilter"></a>CUserToolsManager::SetFilter

Especifica o filtro de arquivo que a caixa de diálogo [CFileDialog (CFileDialog Class)](../../mfc/reference/cfiledialog-class.md)usa no campo **Comando** na guia **Ferramentas** da caixa de diálogo **Personalizar.** **File Open**

```
void SetFilter(const CString& strFilter);
```

### <a name="parameters"></a>Parâmetros

*strFilter*<br/>
[em] Especifica o filtro.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)<br/>
[Classe CUserTool](../../mfc/reference/cusertool-class.md)

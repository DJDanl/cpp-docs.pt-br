---
title: Classe CmouseManager
ms.date: 11/04/2016
f1_keywords:
- CMouseManager
- AFXMOUSEMANAGER/CMouseManager
- AFXMOUSEMANAGER/CMouseManager::AddView
- AFXMOUSEMANAGER/CMouseManager::GetViewDblClickCommand
- AFXMOUSEMANAGER/CMouseManager::GetViewIconId
- AFXMOUSEMANAGER/CMouseManager::GetViewIdByName
- AFXMOUSEMANAGER/CMouseManager::GetViewNames
- AFXMOUSEMANAGER/CMouseManager::LoadState
- AFXMOUSEMANAGER/CMouseManager::SaveState
- AFXMOUSEMANAGER/CMouseManager::SetCommandForDblClk
helpviewer_keywords:
- CMouseManager [MFC], AddView
- CMouseManager [MFC], GetViewDblClickCommand
- CMouseManager [MFC], GetViewIconId
- CMouseManager [MFC], GetViewIdByName
- CMouseManager [MFC], GetViewNames
- CMouseManager [MFC], LoadState
- CMouseManager [MFC], SaveState
- CMouseManager [MFC], SetCommandForDblClk
ms.assetid: a4d05017-4e44-4a40-8b57-4ece0de20481
ms.openlocfilehash: 1394a1b47a86022e37b11e032b87ee2a2a369862
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752800"
---
# <a name="cmousemanager-class"></a>Classe CmouseManager

Permite que um usuário associe diferentes comandos a um objeto [CView](../../mfc/reference/cview-class.md) específico quando o usuário clica duas vezes dentro dessa exibição.

## <a name="syntax"></a>Sintaxe

```
class CMouseManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CmouseManager::AddView](#addview)|Adiciona `CView` um objeto à caixa de diálogo **Personalização.** A caixa de diálogo **Personalização** permite que o usuário associe um duplo clique com um comando para cada uma das visualizações listadas.|
|[CMouseManager::GetViewDblClickCommand](#getviewdblclickcommand)|Retorna o comando que é executado quando o usuário clica duas vezes dentro da exibição fornecida.|
|[CMouseManager::GetViewIconId](#getviewiconid)|Retorna o ícone associado ao ID de exibição fornecido.|
|[CMouseManager::GetViewIdByName](#getviewidbyname)|Retorna o ID de exibição associado ao nome de exibição fornecido.|
|[CMouseManager::GetViewNames](#getviewnames)|Recupera uma lista de todos os nomes de exibição adicionados.|
|[CMouseManager::LoadState](#loadstate)|Carrega o `CMouseManager` estado do registro do Windows.|
|[CMouseManager::SaveState](#savestate)|Escreve `CMouseManager` o estado no registro do Windows.|
|[CMouseManager::SetCommandForDblClk](#setcommandfordblclk)|Associa o comando fornecido e a visão fornecida.|

## <a name="remarks"></a>Comentários

A `CMouseManager` classe mantém `CView` uma coleção de objetos. Cada visualização é identificada por um nome e por um ID. Essas visualizações são mostradas na caixa de diálogo **Personalização.** O usuário pode alterar o comando associado a qualquer exibição através da caixa de diálogo **Personalização.** O comando associado é executado quando o usuário clica duas vezes nessa exibição. Para suportar isso de uma perspectiva de codificação, você deve processar a mensagem WM_LBUTTONDBLCLK e `CView` chamar a função [CWinAppEx::OnViewDoubleClick](../../mfc/reference/cwinappex-class.md#onviewdoubleclick) no código para esse objeto..

Você não deve `CMouseManager` criar um objeto manualmente. Ele será criado pela estrutura de sua aplicação. Ele também será destruído automaticamente quando o usuário sair do aplicativo. Para obter um ponteiro para o gerenciador do mouse para o seu aplicativo, ligue para [CWinAppEx::GetMouseManager](../../mfc/reference/cwinappex-class.md#getmousemanager).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMouseManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmousemanager.h

## <a name="cmousemanageraddview"></a><a name="addview"></a>CmouseManager::AddView

Registra um objeto [CView](../../mfc/reference/cview-class.md) com a [Classe CMouseManager](../../mfc/reference/cmousemanager-class.md) para suportar o comportamento personalizado do mouse.

```
BOOL AddView(
    int iViewId,
    UINT uiViewNameResId,
    UINT uiIconId = 0);

BOOL AddView(
    int iId,
    LPCTSTR lpszViewName,
    UINT uiIconId = 0);
```

### <a name="parameters"></a>Parâmetros

*iViewId*<br/>
[em] Uma id de vista.

*uiViewNameResId*<br/>
[em] Um ID de seqüência de recursos que faz referência ao nome da exibição.

*uiIconId*<br/>
[em] Um iD de ícone de exibição.

*Iid*<br/>
[em] Uma id de vista.

*lpszViewName*<br/>
[em] Um nome de vista.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para suportar o comportamento personalizado do mouse, uma `CMouseManager` exibição deve ser registrada com o objeto. Qualquer objeto derivado `CView` da classe pode ser registrado no gerenciador do mouse. A seqüência e o ícone associados a uma exibição são exibidos na guia **Mouse** da caixa de diálogo **Personalizar.**

É responsabilidade do programador criar e manter iDs de exibição, como *iViewId* e *iId*.

Para obter mais informações sobre como fornecer comportamento personalizado do mouse, consulte [Personalização do teclado e do mouse](../../mfc/keyboard-and-mouse-customization.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMouseManager` recuperar um `CWinAppEx::GetMouseManager` ponteiro `AddView` para um `CMouseManager` objeto usando o método e o método na classe. Este trecho de código faz parte da amostra da [Coleção Estadual.](../../overview/visual-cpp-samples.md)

[!code-cpp[NVC_MFC_StateCollection#4](../../mfc/reference/codesnippet/cpp/cmousemanager-class_1.cpp)]

## <a name="cmousemanagergetviewdblclickcommand"></a><a name="getviewdblclickcommand"></a>CMouseManager::GetViewDblClickCommand

Retorna o comando que é executado quando o usuário clica duas vezes dentro da exibição fornecida.

```
UINT GetViewDblClickCommand(int iId) const;
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O id de vista.

### <a name="return-value"></a>Valor retornado

O identificador de comando se a exibição estiver associada a um comando; caso contrário, 0.

## <a name="cmousemanagergetviewiconid"></a><a name="getviewiconid"></a>CMouseManager::GetViewIconId

Recupera o ícone associado a um ID de exibição.

```
UINT GetViewIconId(int iViewId) const;
```

### <a name="parameters"></a>Parâmetros

*iViewId*<br/>
[em] O id de vista.

### <a name="return-value"></a>Valor retornado

Um identificador de recurso de ícone se for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método falhará se a exibição não for registrada pela primeira vez usando [cmousemanager::AddView](#addview).

## <a name="cmousemanagergetviewidbyname"></a><a name="getviewidbyname"></a>CMouseManager::GetViewIdByName

Recupera o ID de exibição associado a um nome de exibição.

```
int GetViewIdByName(LPCTSTR lpszName) const;
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[em] O nome da vista.

### <a name="return-value"></a>Valor retornado

Um ID de exibição se for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método é pesquisado através de visualizações registradas usando [CMouseManager::AddView](#addview).

## <a name="cmousemanagergetviewnames"></a><a name="getviewnames"></a>CMouseManager::GetViewNames

Recupera uma lista de todos os nomes de exibição registrados.

```cpp
void GetViewNames(CStringList& listOfNames) const;
```

### <a name="parameters"></a>Parâmetros

*listOfNames*<br/>
[fora] Uma referência `CStringList` ao objeto.

### <a name="remarks"></a>Comentários

Este método preenche o `listOfNames` parâmetro com os nomes de todas as visualizações registradas usando [CMouseManager::AddView](#addview).

## <a name="cmousemanagerloadstate"></a><a name="loadstate"></a>CMouseManager::LoadState

Carrega o estado da [Classe CMouseManager](../../mfc/reference/cmousemanager-class.md) do registro.

```
BOOL LoadState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Um caminho de uma chave de registro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

As informações de estado carregadas no registro incluem as visualizações registradas, identificadores de visualização e os comandos associados. Se o parâmetro *lpszProfileName* for NULL, `CMouseManager` esta função carregará os dados do local de registro padrão controlado pela [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md).

Na maioria dos casos, você não precisa chamar essa função diretamente. É chamado como parte do processo de inicialização do espaço de trabalho. Para obter mais informações sobre o processo de inicialização do espaço de trabalho, consulte [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate).

## <a name="cmousemanagersavestate"></a><a name="savestate"></a>CMouseManager::SaveState

Escreve o estado da [Classe CMouseManager](../../mfc/reference/cmousemanager-class.md) no registro.

```
BOOL SaveState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Um caminho de uma chave de registro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

As informações de estado escritas no registro incluem todas as visualizações registradas, identificadores de visualização e os comandos associados. Se o parâmetro *lpszProfileName* for NULL, `CMouseManager` esta função grava os dados para o local de registro padrão controlado pela [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md).

Na maioria dos casos, você não precisa chamar essa função diretamente. É chamado como parte do processo de serialização do espaço de trabalho. Para obter mais informações sobre o processo de serialização do espaço de trabalho, consulte [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate).

## <a name="cmousemanagersetcommandfordblclk"></a><a name="setcommandfordblclk"></a>CMouseManager::SetCommandForDblClk

Associa um comando personalizado com uma visão que é registrada pela primeira vez com o gerenciador do mouse.

```cpp
void SetCommandForDblClk(
    int iViewId,
    UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*iViewId*<br/>
[em] O identificador de visualização.

*Uicmd*<br/>
[em] O identificador de comando.

### <a name="remarks"></a>Comentários

Para associar um comando personalizado a uma exibição, primeiro você deve registrar a exibição usando [CMouseManager::AddView](#addview). O `AddView` método requer um identificador de exibição como parâmetro de entrada. Depois de registrar uma exibição, você pode ligar `CMouseManager::SetCommandForDblClk` com o `AddView`mesmo parâmetro de entrada do identificador de exibição que você forneceu . Depois disso, quando o usuário clica duas vezes no mouse na exibição registrada, o aplicativo executará o comando indicado pelo *uiCmd.* Para suportar o comportamento personalizado do mouse, você também precisará personalizar a exibição registrada no gerenciador do mouse. Para obter mais informações sobre o comportamento personalizado do mouse, consulte [Personalização do teclado e do mouse](../keyboard-and-mouse-customization.md).

Se *uiCmd* estiver definido como 0, a exibição especificada não estará mais associada a um comando.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)<br/>
[Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)

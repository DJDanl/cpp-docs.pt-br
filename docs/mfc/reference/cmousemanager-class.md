---
title: Classe CMouseManager
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
ms.openlocfilehash: b3c5104038e6d715977a211af5a535cc9a5d916f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498144"
---
# <a name="cmousemanager-class"></a>Classe CMouseManager

Permite que um usuário associe comandos diferentes com um determinado [CView](../../mfc/reference/cview-class.md) objeto quando o usuário naquela exibição.

## <a name="syntax"></a>Sintaxe

```
class CMouseManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMouseManager::AddView](#addview)|Adiciona uma `CView` do objeto para o **personalização** caixa de diálogo. O **personalização** caixa de diálogo permite que o usuário associar um clique duplo com um comando para cada um dos modos de exibição listados.|
|[CMouseManager::GetViewDblClickCommand](#getviewdblclickcommand)|Retorna o comando que é executado quando o usuário clica duas vezes na exibição fornecida.|
|[CMouseManager::GetViewIconId](#getviewiconid)|Retorna o ícone associado com a ID do modo de exibição fornecido.|
|[CMouseManager::GetViewIdByName](#getviewidbyname)|Retorna a ID de exibição associada ao nome de exibição fornecido.|
|[CMouseManager::GetViewNames](#getviewnames)|Recupera uma lista de todos os nomes de exibição adicional.|
|[CMouseManager::LoadState](#loadstate)|Carrega o `CMouseManager` estado do registro do Windows.|
|[CMouseManager::SaveState](#savestate)|Grava o `CMouseManager` estado no registro do Windows.|
|[CMouseManager::SetCommandForDblClk](#setcommandfordblclk)|Associa o comando fornecido e o modo de exibição fornecido.|

## <a name="remarks"></a>Comentários

O `CMouseManager` classe mantém uma coleção de `CView` objetos. Cada modo de exibição é identificado por um nome e por uma ID. Essas exibições são mostradas na **personalização** caixa de diálogo. O usuário pode alterar o comando que está associado com qualquer exibição por meio de **personalização** caixa de diálogo. O comando associado é executado quando o usuário clica duas vezes nesse modo de exibição. Para suportar isso de uma perspectiva de codificação, você deve processar a mensagem WM_LBUTTONDBLCLK e a chamada a [CWinAppEx::OnViewDoubleClick](../../mfc/reference/cwinappex-class.md#onviewdoubleclick) função no código para fazer isso `CView` objeto...

Você não deve criar um `CMouseManager` objeto manualmente. Ele será criado pela estrutura do seu aplicativo. Ele também será destruído automaticamente quando o usuário sai do aplicativo. Para obter um ponteiro para o Gerenciador de mouse para o seu aplicativo, chame [CWinAppEx::GetMouseManager](../../mfc/reference/cwinappex-class.md#getmousemanager).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMouseManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmousemanager.h

##  <a name="addview"></a>  CMouseManager::AddView

Registra uma [CView](../../mfc/reference/cview-class.md) do objeto com o [classe CMouseManager](../../mfc/reference/cmousemanager-class.md) para dar suporte ao comportamento de mouse personalizado.

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
[in] Uma identificação de exibição.

*uiViewNameResId*<br/>
[in] Uma ID de cadeia de caracteres de recurso que faz referência ao nome de exibição.

*uiIconId*<br/>
[in] Um ID de ícone do modo de exibição.

*iId*<br/>
[in] Uma identificação de exibição.

*lpszViewName*<br/>
[in] Um nome de exibição.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para dar suporte ao comportamento de mouse personalizado, uma exibição deve ser registrada com o `CMouseManager` objeto. Qualquer objeto derivado de `CView` classe pode ser registrado com o Gerenciador de mouse. A cadeia de caracteres e o ícone associado a um modo de exibição são exibidos na **Mouse** guia o **personalizar** caixa de diálogo.

É responsabilidade do programador para criar e manter as IDs de exibição, como *iViewId* e *iId*.

Para obter mais informações sobre como fornecer o comportamento do mouse personalizado, consulte [personalização de teclado e Mouse](../../mfc/keyboard-and-mouse-customization.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar um ponteiro para um `CMouseManager` objeto usando o `CWinAppEx::GetMouseManager` método e o `AddView` método no `CMouseManager` classe. Este trecho de código é parte do [exemplo de coleção de estado](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StateCollection#4](../../mfc/reference/codesnippet/cpp/cmousemanager-class_1.cpp)]

##  <a name="getviewdblclickcommand"></a>  CMouseManager::GetViewDblClickCommand

Retorna o comando que é executado quando o usuário clica duas vezes na exibição fornecida.

```
UINT GetViewDblClickCommand(int iId) const;
```

### <a name="parameters"></a>Parâmetros

*iId*<br/>
[in] A ID do modo de exibição.

### <a name="return-value"></a>Valor de retorno

O identificador de comando se o modo de exibição estiver associado um comando; Caso contrário, 0.

##  <a name="getviewiconid"></a>  CMouseManager::GetViewIconId

Recupera o ícone associado a uma ID de exibição.

```
UINT GetViewIconId(int iViewId) const;
```

### <a name="parameters"></a>Parâmetros

*iViewId*<br/>
[in] A ID do modo de exibição.

### <a name="return-value"></a>Valor de retorno

Um identificador de recurso de ícone se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método irá falhar se o modo de exibição não é registrado pela primeira vez usando [CMouseManager::AddView](#addview).

##  <a name="getviewidbyname"></a>  CMouseManager::GetViewIdByName

Recupera a ID de exibição associada a um nome de exibição.

```
int GetViewIdByName(LPCTSTR lpszName) const;
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[in] O nome de exibição.

### <a name="return-value"></a>Valor de retorno

Uma ID de exibição se for bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método pesquisa por meio de exibições registradas usando [CMouseManager::AddView](#addview).

##  <a name="getviewnames"></a>  CMouseManager::GetViewNames

Recupera uma lista de todos os nomes de exibição registrado.

```
void GetViewNames(CStringList& listOfNames) const;
```

### <a name="parameters"></a>Parâmetros

*listOfNames*<br/>
[out] Uma referência ao `CStringList` objeto.

### <a name="remarks"></a>Comentários

Esse método preenche o parâmetro `listOfNames` com os nomes de todos os modos de exibição registrados usando [CMouseManager::AddView](#addview).

##  <a name="loadstate"></a>  CMouseManager::LoadState

Carrega o estado do [classe CMouseManager](../../mfc/reference/cmousemanager-class.md) do registro.

```
BOOL LoadState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
[in] Um caminho de uma chave do registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

As informações de estado carregadas do registro incluem os modos de exibição registrados, os identificadores de exibição e os comandos associados. Se o parâmetro *lpszProfileName* for NULL, essa função carrega o `CMouseManager` dados no local do registro padrão controlado pelo [classe CWinAppEx](../../mfc/reference/cwinappex-class.md).

Na maioria dos casos, você não precisa chamar essa função diretamente. Ele é chamado como parte do processo de inicialização do espaço de trabalho. Para obter mais informações sobre o processo de inicialização do espaço de trabalho, consulte [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate).

##  <a name="savestate"></a>  CMouseManager::SaveState

Grava o estado do [classe CMouseManager](../../mfc/reference/cmousemanager-class.md) no registro.

```
BOOL SaveState(LPCTSTR lpszProfileName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
[in] Um caminho de uma chave do registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

As informações de estado, gravadas no registro incluem todos os modos de exibição, identificadores de exibição e os comandos associados. Se o parâmetro *lpszProfileName* for NULL, essa função grava o `CMouseManager` dados para o local do registro padrão controlado pelo [classe CWinAppEx](../../mfc/reference/cwinappex-class.md).

Na maioria dos casos, você não precisa chamar essa função diretamente. Ele é chamado como parte do processo de serialização de espaço de trabalho. Para obter mais informações sobre o processo de serialização do espaço de trabalho, consulte [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate).

##  <a name="setcommandfordblclk"></a>  CMouseManager::SetCommandForDblClk

Associa um comando personalizado uma exibição que é registrada pela primeira vez com o Gerenciador de mouse.

```
void SetCommandForDblClk(
    int iViewId,
    UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*iViewId*<br/>
[in] O identificador da exibição.

*uiCmd*<br/>
[in] O identificador de comando.

### <a name="remarks"></a>Comentários

Para associar um comando personalizado um modo de exibição, você deve primeiro registrar o modo de exibição usando o [CMouseManager::AddView](#addview). O `AddView` método exige um identificador de exibição como um parâmetro de entrada. Quando você registra um modo de exibição, você pode chamar `CMouseManager::SetCommandForDblClk` com o mesma exibição identificador parâmetro de entrada que você forneceu para `AddView`. Depois disso, quando o usuário clica duas vezes o mouse no modo de exibição registrado, o aplicativo executará o comando indicado pelo *uiCmd.* Para dar suporte o comportamento de mouse personalizado, você também precisará personalizar o modo de exibição registrado com o Gerenciador de mouse. Para obter mais informações sobre o comportamento de mouse personalizado, consulte [personalização de teclado e Mouse](../keyboard-and-mouse-customization.md).

Se *uiCmd* é definido como 0, a exibição especificada não está mais associada um comando.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)<br/>
[Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)


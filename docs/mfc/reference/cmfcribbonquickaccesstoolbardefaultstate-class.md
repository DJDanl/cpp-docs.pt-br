---
title: Classe CMFCRibbonQuickAccessToolBarDefaultState
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonQuickAccessToolBarDefaultState
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::CMFCRibbonQuickAccessToolBarDefaultState
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::AddCommand
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::CopyFrom
- AFXRIBBONQUICKACCESSTOOLBAR/CMFCRibbonQuickAccessToolBarDefaultState::RemoveAll
helpviewer_keywords:
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], CMFCRibbonQuickAccessToolBarDefaultState
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], AddCommand
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], CopyFrom
- CMFCRibbonQuickAccessToolBarDefaultState [MFC], RemoveAll
ms.assetid: eca99200-b87b-47ba-b2e8-2f3f2444b176
ms.openlocfilehash: eb6b36066f34036ae599a94f4d1c07b2c633e730
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753517"
---
# <a name="cmfcribbonquickaccesstoolbardefaultstate-class"></a>Classe CMFCRibbonQuickAccessToolBarDefaultState

Uma classe auxiliar que gerencia o estado padrão para a barra de ferramentas de acesso rápido que está posicionada na barra de fita [(CMFCRibbonBar Class).](../../mfc/reference/cmfcribbonbar-class.md)

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonQuickAccessToolBarDefaultState
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonQuickAccessToolBarDefaultstate::CMFCRibbonQuickAccessToolbarDefaultState](#cmfcribbonquickaccesstoolbardefaultstate)|Constrói um objeto `CMFCRibbonQuickAccessToolbarDefaultState`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonQuickAccessToolBarDefaultstate::AddCommand](#addcommand)|Adiciona um comando ao estado padrão da barra de ferramentas de acesso rápido. Isso não muda a barra de ferramentas em si.|
|[CMFCRibbonQuickAccessToolBarDefaultstate::CopyFrom](#copyfrom)|Copia as propriedades de uma barra de ferramentas de acesso rápido para outra.|
|[CMFCRibbonQuickAccessToolbarDefaultstate::removeAll](#removeall)|Remove todos os comandos da barra de ferramentas de acesso rápido. Isso não muda a barra de ferramentas em si.|

## <a name="remarks"></a>Comentários

Depois de criar a barra de ferramentas de acesso rápido em seu aplicativo, recomendamos que você defina seu estado padrão ligando para [CMFCRibbonBar::SetQuickAccessDefaultState](../../mfc/reference/cmfcribbonbar-class.md#setquickaccessdefaultstate). Esse estado padrão é restaurado quando um usuário clica no botão **Redefinir** na página **Personalizar** da caixa de diálogo **Opções** do aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmfcribbonquickaccesstoolbardefaultstate](../../mfc/reference/cmfcribbonquickaccesstoolbardefaultstate-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonQuickAccessToolbarDefaultState` construir um objeto da classe e como adicionar um comando ao estado padrão da barra de ferramentas de acesso rápido.

[!code-cpp[NVC_MFC_RibbonApp#21](../../mfc/reference/codesnippet/cpp/cmfcribbonquickaccesstoolbardefaultstate-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonquickaccesstoolbar.h

## <a name="cmfcribbonquickaccesstoolbardefaultstateaddcommand"></a><a name="addcommand"></a>CMFCRibbonQuickAccessToolBarDefaultstate::AddCommand

Adiciona um comando ao estado padrão da barra de ferramentas de acesso rápido.

```cpp
void AddCommand(
    UINT uiCmd,
    BOOL bIsVisible=TRUE);
```

### <a name="parameters"></a>Parâmetros

*[in] uiCmd*<br/>
Especifica o ID de comando.

*[in] bIsVisible*<br/>
Define a visibilidade do comando quando a barra de ferramentas de acesso rápido estiver no estado padrão.

### <a name="remarks"></a>Comentários

Adicionar um comando ao CMFCRibbonQuickAccessToolBarDefaultState realiza três resultados. Primeiro, cada comando adicionado é listado no dropdown no lado direito da barra de ferramentas de acesso rápido. Desta forma, um usuário pode facilmente adicionar ou remover esse comando da barra de ferramentas de acesso rápido. Em segundo lugar, a barra de ferramentas de acesso rápido é redefinida para mostrar apenas os comandos listados como visíveis no estado padrão quando o usuário clica no botão **Redefinir** na caixa de diálogo **Personalizar.** Terceiro, se você não tiver chamado [CMFCRibbonBar::SetQuickAccessCommands](../../mfc/reference/cmfcribbonbar-class.md#setquickaccesscommands), a Barra de Ferramentas de Acesso Rápido usará os comandos visíveis desta lista como os comandos visíveis padrão na primeira vez que um usuário executa seu aplicativo. Depois de adicionar todos os comandos que deseja, ligue para [CMFCRibbonBar::SetQuickAccessDefaultState](../../mfc/reference/cmfcribbonbar-class.md#setquickaccessdefaultstate) para definir essa instância como o estado padrão para a barra de ferramentas de acesso rápido da Barra de Fita.

## <a name="cmfcribbonquickaccesstoolbardefaultstatecopyfrom"></a><a name="copyfrom"></a>CMFCRibbonQuickAccessToolBarDefaultstate::CopyFrom

Copia as propriedades de uma barra de ferramentas de acesso rápido para outra.

```cpp
void CopyFrom(const CMFCRibbonQuickAccessToolBarDefaultState& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] Uma referência ao `CMFCRibbonQuickAccessToolBarDefaultState` objeto de origem a ser copiado.

### <a name="remarks"></a>Comentários

Este método copia cada `CMFCRibbonQuickAccessToolBarDefaultState` comando do objeto de origem para este objeto usando o [CMFCRibbonQuickAccessToolDefaultState::AddCommand](#addcommand) method.

## <a name="cmfcribbonquickaccesstoolbardefaultstatecmfcribbonquickaccesstoolbardefaultstate"></a><a name="cmfcribbonquickaccesstoolbardefaultstate"></a>CMFCRibbonQuickAccessToolBarDefaultstate::CMFCRibbonQuickAccessToolbarDefaultState

Constrói o objeto de estado padrão da barra de ferramentas de acesso rápido.

```
CMFCRibbonQuickAccessToolBarDefaultState();
```

### <a name="remarks"></a>Comentários

Por padrão, a lista de comandos que a nova instância do [CMFRibbonQuickAccessToolBarDefaultState](../../mfc/reference/cmfcribbonquickaccesstoolbardefaultstate-class.md) está vazia.

## <a name="cmfcribbonquickaccesstoolbardefaultstateremoveall"></a><a name="removeall"></a>CMFCRibbonQuickAccessToolbarDefaultstate::removeAll

Limpa a lista de comandos padrão na barra de ferramentas de acesso rápido.

```cpp
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Esta função remove a partir desta instância todos os comandos que as chamadas anteriores para [CMFCRibbonQuickAccessToolBarDefaultState::AddCommand](#addcommand) adicionado.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)

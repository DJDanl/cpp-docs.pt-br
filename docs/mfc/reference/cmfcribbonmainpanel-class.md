---
title: Classe CMFCRibbonMainPanel
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonMainPanel
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::Add
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::AddRecentFilesList
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::AddToBottom
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::AddToRight
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::GetCommandsFrame
helpviewer_keywords:
- CMFCRibbonMainPanel [MFC], Add
- CMFCRibbonMainPanel [MFC], AddRecentFilesList
- CMFCRibbonMainPanel [MFC], AddToBottom
- CMFCRibbonMainPanel [MFC], AddToRight
- CMFCRibbonMainPanel [MFC], GetCommandsFrame
ms.assetid: 1af78798-5e75-4365-9c81-a54aa5679602
ms.openlocfilehash: 0fd1cd2fec31f9da0c2bec36d08586780f4f95c3
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753574"
---
# <a name="cmfcribbonmainpanel-class"></a>Classe CMFCRibbonMainPanel

Implementa um painel de fita que é exibido quando você clica no [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md).

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonMainPanel : public CMFCRibbonPanel
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonMainPanel::CMFCRibbonMainPanel`|Construtor padrão.|
|`CMFCRibbonMainPanel::~CMFCRibbonMainPanel`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonMainPanel::Adicionar](#add)|Adiciona um elemento de fita ao painel esquerdo do painel do botão de aplicação. (Substitui [cmfcribbonpanel::Adicionar](../../mfc/reference/cmfcribbonpanel-class.md#add).)|
|[CMFCRibbonMain::AddRecentFilesList](#addrecentfileslist)|Adiciona uma seqüência de texto ao menu de lista de arquivos recentes.|
|[CMFCRibbonmainpanel::Addtobottom](#addtobottom)|Adiciona um elemento de fita ao painel inferior do painel de aplicação da fita.|
|[CMFCRibbonmainpanel::Addtoright](#addtoright)|Adiciona um elemento de fita ao painel direito do painel do botão de aplicação.|
|`CMFCRibbonMainPanel::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCRibbonMain::GetCommandsFrame](#getcommandsframe)|Retorna um retângulo que representa a área do painel principal da fita.|
|`CMFCRibbonMainPanel::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|

## <a name="remarks"></a>Comentários

A estrutura `CMFCRibbonMainPanel` exibe quando você abre o painel de aplicação. Contém três painéis:

- O painel esquerdo contém comandos associados a arquivos, como **Open,** **Save,** **Print**e **Close**. Para adicionar um comando a este painel, chame [CMFCRibbonMainPanel::Add](#add).

- O painel direito contém opções que modificam o comando que você clica no painel esquerdo. Por exemplo, se você clicar **em Salvar como** no painel esquerdo, o painel direito pode exibir os tipos de arquivo disponíveis. Para adicionar um item a este painel, chame [CMFCRibbonMainPanel::AddToRight](#addtoright).

- O painel inferior contém botões que permitem alterar as configurações do aplicativo e sair do programa. Para adicionar um item a este painel, chame [CMFCRibbonMainPanel::AddToBottom](#addtobottom).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonpanel](../../mfc/reference/cmfcribbonpanel-class.md)

[Cmfcribbonmainpanel](../../mfc/reference/cmfcribbonmainpanel-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonMainPanel.h

## <a name="cmfcribbonmainpaneladd"></a><a name="add"></a>CMFCRibbonMainPanel::Adicionar

Adiciona um elemento de fita ao painel esquerdo do painel do botão de aplicação.

```
virtual void Add(CMFCRibbonBaseElement* pElem);
```

### <a name="parameters"></a>Parâmetros

*pElem*<br/>
[dentro, fora] Um ponteiro para o elemento de fita para adicionar ao painel principal.

### <a name="remarks"></a>Comentários

Adiciona um elemento de fita ao painel. Os elementos adicionados usando este método serão localizados na coluna esquerda do painel principal.

## <a name="cmfcribbonmainpaneladdrecentfileslist"></a><a name="addrecentfileslist"></a>CMFCRibbonMain::AddRecentFilesList

Adiciona uma seqüência de texto ao menu de lista de arquivos recentes.

```cpp
void AddRecentFilesList(
    LPCTSTR lpszLabel,
    int nWidth = 300);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
Especifica a seqüência para adicionar à lista de arquivos recentes.

*Nwidth*<br/>
Especifica a largura, em pixels, do painel de lista de arquivos recentes.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonmainpaneladdtobottom"></a><a name="addtobottom"></a>CMFCRibbonmainpanel::Addtobottom

Adiciona um elemento de fita ao painel inferior do painel de aplicação da fita.

```cpp
void AddToBottom(CMFCRibbonMainPanelButton* pElem);
```

### <a name="parameters"></a>Parâmetros

*pElem*<br/>
[dentro, fora] Um ponteiro para o elemento de fita para adicionar à parte inferior do painel principal.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonmainpaneladdtoright"></a><a name="addtoright"></a>CMFCRibbonmainpanel::Addtoright

Adiciona um elemento de fita ao painel direito do painel do botão de aplicação.

```cpp
void AddToRight(
    CMFCRibbonBaseElement* pElem,
    int nWidth = 300);
```

### <a name="parameters"></a>Parâmetros

*pElem*<br/>
Um ponteiro para um elemento de fita a ser adicionado ao lado direito do painel principal.

*Nwidth*<br/>
Especifica a largura, em pixels, do painel direito.

### <a name="remarks"></a>Comentários

Use esta função para adicionar um elemento de fita ao painel direito. O painel direito normalmente exibe a lista de arquivos recentes, mas você pode adicionar qualquer outro elemento de fita aqui.

## <a name="cmfcribbonmainpanelgetcommandsframe"></a><a name="getcommandsframe"></a>CMFCRibbonMain::GetCommandsFrame

Retorna um retângulo que representa a área do painel principal da fita.

```
CRect GetCommandsFrame() const;
```

### <a name="return-value"></a>Valor retornado

Um retângulo que representa a área do painel principal da fita.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)

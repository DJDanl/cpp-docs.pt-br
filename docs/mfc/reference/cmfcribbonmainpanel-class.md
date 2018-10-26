---
title: Classe CMFCRibbonMainPanel | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonMainPanel
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::Add
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::AddRecentFilesList
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::AddToBottom
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::AddToRight
- AFXRIBBONMAINPANEL/CMFCRibbonMainPanel::GetCommandsFrame
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonMainPanel [MFC], Add
- CMFCRibbonMainPanel [MFC], AddRecentFilesList
- CMFCRibbonMainPanel [MFC], AddToBottom
- CMFCRibbonMainPanel [MFC], AddToRight
- CMFCRibbonMainPanel [MFC], GetCommandsFrame
ms.assetid: 1af78798-5e75-4365-9c81-a54aa5679602
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e23e883c143b1c65d4f150092193a7a693a34269
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065233"
---
# <a name="cmfcribbonmainpanel-class"></a>Classe CMFCRibbonMainPanel

Implementa um painel de faixa de opções exibe quando você clica o [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md).

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonMainPanel : public CMFCRibbonPanel
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonMainPanel::CMFCRibbonMainPanel`|Construtor padrão.|
|`CMFCRibbonMainPanel::~CMFCRibbonMainPanel`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonMainPanel::Add](#add)|Adiciona um elemento de faixa de opções no painel esquerdo do painel de botão do aplicativo. (Substitui [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).)|
|[CMFCRibbonMainPanel::AddRecentFilesList](#addrecentfileslist)|Adiciona uma cadeia de caracteres de texto para o menu de lista de arquivos recentes.|
|[CMFCRibbonMainPanel::AddToBottom](#addtobottom)|Adiciona um elemento de faixa de opções no painel inferior do painel de aplicativo da faixa de opções.|
|[CMFCRibbonMainPanel::AddToRight](#addtoright)|Adiciona um elemento de faixa de opções para o painel à direita do painel de botão do aplicativo.|
|`CMFCRibbonMainPanel::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCRibbonMainPanel::GetCommandsFrame](#getcommandsframe)|Retorna um retângulo que representa a área do painel principal da faixa de opções.|
|`CMFCRibbonMainPanel::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|

## <a name="remarks"></a>Comentários

Exibe a estrutura de `CMFCRibbonMainPanel` quando você abre o painel do aplicativo. Ele contém três painéis:

- O painel esquerdo contém comandos associados a arquivos, como **aberto**, **salve**, **impressão**, e **fechar**. Para adicionar um comando para esse painel, chame [CMFCRibbonMainPanel::Add](#add).

- O painel direito contém opções que modificam o comando que você clicar no painel esquerdo. Por exemplo, se você clicar **Salvar como** no painel esquerdo, o painel à direita pode exibir tipos de arquivo disponíveis. Para adicionar um item para esse painel, chame [CMFCRibbonMainPanel::AddToRight](#addtoright).

- O painel inferior contém botões que permitem que você alterar as configurações do aplicativo e para sair do programa. Para adicionar um item para esse painel, chame [CMFCRibbonMainPanel::AddToBottom](#addtobottom).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)

[CMFCRibbonMainPanel](../../mfc/reference/cmfcribbonmainpanel-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonMainPanel.h

##  <a name="add"></a>  CMFCRibbonMainPanel::Add

Adiciona um elemento de faixa de opções no painel esquerdo do painel de botão do aplicativo.

```
virtual void Add(CMFCRibbonBaseElement* pElem);
```

### <a name="parameters"></a>Parâmetros

*pElem*<br/>
[no, out] Um ponteiro para o elemento de faixa de opções para adicionar ao painel principal.

### <a name="remarks"></a>Comentários

Adiciona um elemento de faixa de opções no painel. Elementos adicionados usando esse método estará localizados na coluna à esquerda do painel principal.

##  <a name="addrecentfileslist"></a>  CMFCRibbonMainPanel::AddRecentFilesList

Adiciona uma cadeia de caracteres de texto para o menu de lista de arquivos recentes.

```
void AddRecentFilesList(
    LPCTSTR lpszLabel,
    int nWidth = 300);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
Especifica a cadeia de caracteres para adicionar à lista de arquivos recentes.

*nWidth*<br/>
Especifica a largura, em pixels, do painel de lista de arquivos recentes.

### <a name="remarks"></a>Comentários

##  <a name="addtobottom"></a>  CMFCRibbonMainPanel::AddToBottom

Adiciona um elemento de faixa de opções no painel inferior do painel de aplicativo da faixa de opções.

```
void AddToBottom(CMFCRibbonMainPanelButton* pElem);
```

### <a name="parameters"></a>Parâmetros

*pElem*<br/>
[no, out] Um ponteiro para o elemento de faixa de opções para adicionar a parte inferior do painel principal.

### <a name="remarks"></a>Comentários

##  <a name="addtoright"></a>  CMFCRibbonMainPanel::AddToRight

Adiciona um elemento de faixa de opções para o painel à direita do painel de botão do aplicativo.

```
void AddToRight(
    CMFCRibbonBaseElement* pElem,
    int nWidth = 300);
```

### <a name="parameters"></a>Parâmetros

*pElem*<br/>
Um ponteiro para um elemento de faixa de opções a serem adicionadas ao lado direito do painel principal.

*nWidth*<br/>
Especifica a largura, em pixels, do painel à direita.

### <a name="remarks"></a>Comentários

Use esta função para adicionar um elemento de faixa de opções para o painel direito. O painel direito exibe a lista de arquivos recentes, mas você pode adicionar qualquer outro elemento de faixa de opções aqui.

##  <a name="getcommandsframe"></a>  CMFCRibbonMainPanel::GetCommandsFrame

Retorna um retângulo que representa a área do painel principal da faixa de opções.

```
CRect GetCommandsFrame() const;
```

### <a name="return-value"></a>Valor de retorno

Um retângulo que representa a área do painel principal da faixa de opções.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)

---
title: Classe CDockState
ms.date: 11/04/2016
f1_keywords:
- CDockState
- AFXADV/CDockState
- AFXADV/CDockState::Clear
- AFXADV/CDockState::GetVersion
- AFXADV/CDockState::LoadState
- AFXADV/CDockState::SaveState
- AFXADV/CDockState::m_arrBarInfo
helpviewer_keywords:
- CDockState [MFC], Clear
- CDockState [MFC], GetVersion
- CDockState [MFC], LoadState
- CDockState [MFC], SaveState
- CDockState [MFC], m_arrBarInfo
ms.assetid: 09e7c10b-3abd-4cb2-ad36-42420fe6bc36
ms.openlocfilehash: 1c76bcda6465ca86b8da4778d3653cb23001b78b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375558"
---
# <a name="cdockstate-class"></a>Classe CDockState

Uma classe `CObject` serializada que carrega, descarrega ou limpa o estado de uma ou mais barras de controle de acoplamento na memória persistente (um arquivo).

## <a name="syntax"></a>Sintaxe

```
class CDockState : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cdockState::Clear](#clear)|Limpa as informações do estado das docas.|
|[CDockState::GetVersion](#getversion)|Recupera o número da versão do estado da barra armazenada.|
|[cdockState::LoadState](#loadstate)|Recupera informações do estado do registro ou . Arquivo INI.|
|[cdockState::SaveState](#savestate)|Salva informações do estado no registro ou no arquivo INI.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDockState::m_arrBarInfo](#m_arrbarinfo)|Matriz de ponteiros para as informações do estado de doca armazenadas com uma entrada para cada barra de controle.|

## <a name="remarks"></a>Comentários

O estado das docas inclui o tamanho e a posição da barra e se ela está ou não ancorada. Ao recuperar o estado `CDockState` de doca armazenado, verifique a posição da barra e, `CDockState` se a barra não estiver visível com as configurações atuais da tela, dimensione a posição da barra para que ela fique visível. O objetivo `CDockState` principal é manter todo o estado de uma série de barras de controle e permitir que esse estado seja salvo e carregado no registro, no aplicativo. Arquivo INI, ou em forma binária como parte do conteúdo de um `CArchive` objeto.

A barra pode ser qualquer barra de controle ancorável, incluindo uma barra de ferramentas, barra de status ou barra de diálogo. `CDockState`objetos são escritos e lidos `CArchive` para ou a partir de um arquivo através de um objeto.

[CFrameWnd::GetDockState](../../mfc/reference/cframewnd-class.md#getdockstate) recupera as informações de estado de `CControlBar` todos os objetos da janela do quadro e as coloca no `CDockState` objeto. Em seguida, você pode `CDockState` escrever o conteúdo do objeto para armazenamento com [Serialize](../../mfc/reference/cobject-class.md#serialize) ou [CDockState::SaveState](#savestate). Mais tarde, se você quiser restaurar o estado das barras de `Serialize` controle na janela do quadro, você pode carregar o estado com ou [CDockState::LoadState,](#loadstate)em seguida, usar [CFrameWnd::SetDockState](../../mfc/reference/cframewnd-class.md#setdockstate) para aplicar o estado salvo nas barras de controle da janela do quadro.

Para obter mais informações sobre barras de controle de encaixe, consulte os artigos [Barras de Controle,](../../mfc/control-bars.md) [Barras de Ferramentas: Docking and Floating](../../mfc/docking-and-floating-toolbars.md)e Frame [Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDockState`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

## <a name="cdockstateclear"></a><a name="clear"></a>cdockState::Clear

Chame esta função para limpar todas `CDockState` as informações de acoplamento armazenadas no objeto.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Isso inclui não apenas se a barra está ancorada ou não, mas o tamanho e a posição da barra e se ela é visível ou não.

## <a name="cdockstategetversion"></a><a name="getversion"></a>CDockState::GetVersion

Ligue para esta função para recuperar o número da versão do estado da barra armazenada.

```
DWORD GetVersion();
```

### <a name="return-value"></a>Valor retornado

1 se as informações da barra armazenada forem mais antigas do que o estado atual da barra; 2 se as informações da barra armazenada forem as mesmas do estado atual da barra.

### <a name="remarks"></a>Comentários

O suporte à versão permite que uma barra revisada adicione novas propriedades persistentes e ainda seja capaz de detectar e carregar o estado persistente criado por uma versão anterior da barra.

## <a name="cdockstateloadstate"></a><a name="loadstate"></a>cdockState::LoadState

Ligue para esta função para recuperar informações do estado do registro ou . Arquivo INI.

```
void LoadState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
Aponta para uma seqüência de teclas anulada que especifica o nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde as informações do estado são armazenadas.

### <a name="remarks"></a>Comentários

O nome do perfil é a seção do aplicativo. Arquivo INI ou o registro que contém as informações do estado das barras. Você pode salvar informações do estado da barra de controle no registro ou . Arquivo INI `SaveState`com .

## <a name="cdockstatem_arrbarinfo"></a><a name="m_arrbarinfo"></a>CDockState::m_arrBarInfo

Um `CPtrArray` objeto que é um conjunto de ponteiros para as informações da barra `CDockState` de controle armazenada satisfaz cada barra de controle que salvou informações de estado no objeto.

```
CPtrArray m_arrBarInfo;
```

## <a name="cdockstatesavestate"></a><a name="savestate"></a>cdockState::SaveState

Ligue para esta função para salvar as informações do estado no registro ou . Arquivo INI.

```
void SaveState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
Aponta para uma seqüência de teclas anulada que especifica o nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde as informações do estado são armazenadas.

### <a name="remarks"></a>Comentários

O nome do perfil é a seção do aplicativo. Arquivo INI ou o registro que contém as informações do estado da barra de controle. `SaveState`também salva o tamanho atual da tela. Você pode recuperar informações da barra de controle do registro ou . Arquivo INI `LoadState`com .

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

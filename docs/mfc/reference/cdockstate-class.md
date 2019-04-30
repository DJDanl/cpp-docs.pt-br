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
ms.openlocfilehash: b8c4b80d7182795d8919adb64491d506325976ef
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391173"
---
# <a name="cdockstate-class"></a>Classe CDockState

Um serializado `CObject` classe que carrega, descarrega ou desmarca o estado de controle de encaixe de um ou mais barras na memória persistente (um arquivo).

## <a name="syntax"></a>Sintaxe

```
class CDockState : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDockState::Clear](#clear)|Limpa as informações de estado de encaixe.|
|[CDockState::GetVersion](#getversion)|Recupera o número de versão de armazenado estado da barra.|
|[CDockState::LoadState](#loadstate)|Recupera as informações do registro de estado ou. Arquivo INI.|
|[CDockState::SaveState](#savestate)|Salva informações de estado do registro ou no arquivo INI.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDockState::m_arrBarInfo](#m_arrbarinfo)|Matriz de ponteiros para armazenado encaixe informações de estado com uma entrada para cada barra de controle.|

## <a name="remarks"></a>Comentários

O estado de encaixe inclui o tamanho e posição da barra de e ou não está encaixado. Quando a recuperação armazenado encaixar estado, `CDockState` verifica a barra de posição e, se a barra não está visível com as configurações atuais da tela, `CDockState` dimensiona a barra posicionar para que ele fique visível. O principal objetivo do `CDockState` é manter todo o estado de um número de barras de controle e permitir que o estado salvo e carregado para o registro, o aplicativo. O arquivo INI, ou em formato binário como parte de um `CArchive` conteúdo do objeto.

A barra de pode ser qualquer encaixável barra de controle, incluindo uma barra de ferramentas, a barra de status ou a barra de diálogo. `CDockState` objetos são gravados e lido para ou de um arquivo por meio de um `CArchive` objeto.

[CFrameWnd::GetDockState](../../mfc/reference/cframewnd-class.md#getdockstate) recupera as informações de estado de todos os quadro da janela `CControlBar` objetos e coloca-o no `CDockState` objeto. Em seguida, você pode gravar o conteúdo do `CDockState` objeto para o armazenamento com [Serialize](../../mfc/reference/cobject-class.md#serialize) ou [CDockState::SaveState](#savestate). Se posteriormente você desejar restaurar o estado das barras de controle na janela do quadro, você poderá carregar o estado com `Serialize` ou [CDockState::LoadState](#loadstate), em seguida, use [CFrameWnd::SetDockState](../../mfc/reference/cframewnd-class.md#setdockstate) para aplicar a salvo estado para barras de controle da janela do quadro.

Para obter mais informações sobre barras de controle de encaixe, consulte os artigos [barras de controle](../../mfc/control-bars.md), [barras de ferramentas: Encaixando e flutuando](../../mfc/docking-and-floating-toolbars.md), e [quadro Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDockState`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

##  <a name="clear"></a>  CDockState::Clear

Chame essa função para limpar todas as informações de encaixe armazenadas do `CDockState` objeto.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Isso inclui não apenas se a barra é encaixada ou não, mas o tamanho e a posição da barra e se ele está visível ou não.

##  <a name="getversion"></a>  CDockState::GetVersion

Chame essa função para recuperar o número de versão de armazenado estado da barra.

```
DWORD GetVersion();
```

### <a name="return-value"></a>Valor de retorno

1 se a barra armazenada informações são mais antigas que o atual estado; da barra 2 se a barra armazenada informações são o mesmo que o atual estado da barra.

### <a name="remarks"></a>Comentários

Suporte de versão permite que uma barra revisada adicionar novas propriedades persistentes e ainda ser capaz de detectar e carregar o estado persistente criado por uma versão anterior da barra.

##  <a name="loadstate"></a>  CDockState::LoadState

Chame essa função para recuperar informações de estado do registro ou. Arquivo INI.

```
void LoadState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
Aponta para uma cadeia de caracteres teminated nulo que especifica o nome de uma seção no arquivo de inicialização ou uma chave do registro do Windows em que as informações de estado são armazenadas.

### <a name="remarks"></a>Comentários

O nome do perfil é a seção do aplicativo. Arquivo INI ou no registro que contém informações de estado dos barras. Você pode salvar a barra de informações de estado de controle para o registro ou. O arquivo INI com `SaveState`.

##  <a name="m_arrbarinfo"></a>  CDockState::m_arrBarInfo

Um `CPtrArray` objeto que é uma matriz de ponteiros para as informações da barra de controle armazenado para cada barra de controle que salva informações de estado no `CDockState` objeto.

```
CPtrArray m_arrBarInfo;
```

##  <a name="savestate"></a>  CDockState::SaveState

Chame essa função para salvar as informações de estado no registro ou. Arquivo INI.

```
void SaveState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
Aponta para uma cadeia de caracteres teminated nulo que especifica o nome de uma seção no arquivo de inicialização ou uma chave do registro do Windows em que as informações de estado são armazenadas.

### <a name="remarks"></a>Comentários

O nome do perfil é a seção do aplicativo. Arquivo INI ou no registro que contém informações de estado da barra de controle. `SaveState` também reduzem o tamanho da tela atual. Você pode recuperar informações da barra de controle do registro ou. O arquivo INI com `LoadState`.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

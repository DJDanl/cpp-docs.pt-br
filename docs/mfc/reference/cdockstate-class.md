---
title: Classe CDockState | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDockState
- AFXADV/CDockState
- AFXADV/CDockState::Clear
- AFXADV/CDockState::GetVersion
- AFXADV/CDockState::LoadState
- AFXADV/CDockState::SaveState
- AFXADV/CDockState::m_arrBarInfo
dev_langs:
- C++
helpviewer_keywords:
- CDockState [MFC], Clear
- CDockState [MFC], GetVersion
- CDockState [MFC], LoadState
- CDockState [MFC], SaveState
- CDockState [MFC], m_arrBarInfo
ms.assetid: 09e7c10b-3abd-4cb2-ad36-42420fe6bc36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fcfbe14743ffff91a4a1749f0394a6deb8f0547a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33367432"
---
# <a name="cdockstate-class"></a>Classe CDockState
Um serializado `CObject` classe que carrega, descarrega ou limpa o estado de controle de encaixe de uma ou mais barras em memória persistente (um arquivo).  
  
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
|[CDockState::SaveState](#savestate)|Salva informações de estado para o registro ou o arquivo INI.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockState::m_arrBarInfo](#m_arrbarinfo)|Matriz de ponteiros para armazenado encaixe informações de estado com uma entrada para cada barra de controle.|  
  
## <a name="remarks"></a>Comentários  
 O estado de encaixe inclui o tamanho e posição de barra e se ela estiver encaixada. Ao recuperar o armazenado encaixar estado, `CDockState` verifica a barra posição e, se a barra não estiver visível, com as configurações atuais da tela, `CDockState` dimensiona da barra de posição para que ele fique visível. O principal objetivo do `CDockState` é para manter todo o estado de um número de barras de controle e permitir que esse estado sejam salvos e carregados apenas no registro, o aplicativo. O arquivo INI, ou em formato binário como parte de um `CArchive` conteúdo do objeto.  
  
 A barra de pode ser qualquer encaixável barra de controle, incluindo uma barra de ferramentas, barras de status ou caixa de diálogo. `CDockState` objetos são escritos e ler de ou para um arquivo por meio de um `CArchive` objeto.  
  
 [CFrameWnd::GetDockState](../../mfc/reference/cframewnd-class.md#getdockstate) recupera as informações de estado de todos os quadros da janela `CControlBar` objetos e o coloca no `CDockState` objeto. Em seguida, você pode gravar o conteúdo do `CDockState` objeto para o armazenamento com [Serialize](../../mfc/reference/cobject-class.md#serialize) ou [CDockState::SaveState](#savestate). Se você desejar restaurar o estado das barras de controle na janela do quadro, você pode carregar o estado com `Serialize` ou [CDockState::LoadState](#loadstate), em seguida, use [CFrameWnd::SetDockState](../../mfc/reference/cframewnd-class.md#setdockstate) para aplicar a salvo estado para barras de controle da janela do quadro.  
  
 Para obter mais informações sobre barras de controle de encaixe, consulte os artigos [barras de controle](../../mfc/control-bars.md), [barras de ferramentas: Encaixando e flutuando](../../mfc/docking-and-floating-toolbars.md), e [janelas com moldura](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDockState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxadv.h  
  
##  <a name="clear"></a>  CDockState::Clear  
 Chamar essa função para limpar todas as informações de encaixe armazenadas no `CDockState` objeto.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Isso inclui não apenas se a barra é ancorada ou não, mas o tamanho e a posição da barra e se está visível ou não.  
  
##  <a name="getversion"></a>  CDockState::GetVersion  
 Chamar essa função para recuperar o número de versão de armazenado estado da barra.  
  
```  
DWORD GetVersion();
```  
  
### <a name="return-value"></a>Valor de retorno  
 1 se a barra armazenada informações são mais antigas que o atual estado; de barras 2 se a barra armazenada informações serão o mesmo que o atual estado da barra.  
  
### <a name="remarks"></a>Comentários  
 Suporte à versão permite uma barra revisada adicionar novas propriedades persistentes e ainda ser capaz de detectar e carregar o estado persistente criado por uma versão anterior da barra.  
  
##  <a name="loadstate"></a>  CDockState::LoadState  
 Chamar essa função para recuperar as informações de estado do registro ou. Arquivo INI.  
  
```  
void LoadState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProfileName`  
 Aponta para uma cadeia de caracteres null teminated que especifica o nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde informações de estado são armazenadas.  
  
### <a name="remarks"></a>Comentários  
 O nome do perfil é a seção do aplicativo. O arquivo INI ou registro que contém informações sobre o estado das barras. Você pode salvar a barra de informações de estado de controle no registro ou. O arquivo INI com `SaveState`.  
  
##  <a name="m_arrbarinfo"></a>  CDockState::m_arrBarInfo  
 Um `CPtrArray` objeto que é uma matriz de ponteiros para as informações da barra de controle armazenados para cada barra de controle que salva informações de estado no `CDockState` objeto.  
  
```  
CPtrArray m_arrBarInfo;  
```  
  
##  <a name="savestate"></a>  CDockState::SaveState  
 Chamar essa função para salvar as informações de estado no registro ou. Arquivo INI.  
  
```  
void SaveState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProfileName`  
 Aponta para uma cadeia de caracteres null teminated que especifica o nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde informações de estado são armazenadas.  
  
### <a name="remarks"></a>Comentários  
 O nome do perfil é a seção do aplicativo. O arquivo INI ou o registro que contém informações sobre o estado da barra de controle. `SaveState` também reduzem o tamanho atual da tela. Você pode recuperar informações de controle de barra de registro ou. O arquivo INI com `LoadState`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)


---
title: Classe CDockState | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- dock state
- size
- docking control bars
- CDockState class
- states, dockable control bar
- position, control bar
- size, control bar
- docking tool windows
ms.assetid: 09e7c10b-3abd-4cb2-ad36-42420fe6bc36
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: fc8beb80cc35c1816fbc305ece2bfbc5df2e7cd0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdockstate-class"></a>Classe CDockState
Serializados `CObject` classe que carrega, descarrega ou limpa o estado do controle de encaixe de um ou mais barras em memória persistente (um arquivo).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDockState : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockState::Clear](#clear)|Limpa as informações de estado de encaixe.|  
|[CDockState::GetVersion](#getversion)|Recupera o número de versão de armazenado barra de estado.|  
|[CDockState::LoadState](#loadstate)|Recupera as informações do registro de estado ou. Arquivo INI.|  
|[CDockState::SaveState](#savestate)|Salva informações de estado do registro ou do arquivo INI.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockState::m_arrBarInfo](#m_arrbarinfo)|Matriz de ponteiros para armazenado encaixe informações de estado com uma entrada para cada barra de controle.|  
  
## <a name="remarks"></a>Comentários  
 O estado de encaixe inclui o tamanho e a posição da barra e se ela estiver encaixada. Quando a recuperação armazenado encaixar estado, `CDockState` verifica a barra posição e, se a barra não está visível com as configurações atuais da tela, `CDockState` dimensiona a barra posicionar para que ele fique visível. O principal objetivo do `CDockState` é manter todo o estado de um número de barras de controle e permitir que esse estado sejam salvos e carregados apenas no registro, o aplicativo. O arquivo INI, ou em formato binário como parte de um `CArchive` conteúdo do objeto.  
  
 A barra pode ser qualquer acoplável barra de controle, incluindo uma barra de ferramentas, barra de status ou caixa de diálogo. `CDockState`objetos são gravados e ler de ou para um arquivo por meio de uma `CArchive` objeto.  
  
 [CFrameWnd::GetDockState](../../mfc/reference/cframewnd-class.md#getdockstate) recupera as informações de estado de todos os quadros da janela `CControlBar` objetos e coloca-o no `CDockState` objeto. Você pode escrever o conteúdo da `CDockState` objeto para o repositório com [Serialize](../../mfc/reference/cobject-class.md#serialize) ou [CDockState::SaveState](#savestate). Se posteriormente você desejar restaurar o estado das barras de controle na janela de quadro, você poderá carregar o estado com `Serialize` ou [CDockState::LoadState](#loadstate), em seguida, use [CFrameWnd::SetDockState](../../mfc/reference/cframewnd-class.md#setdockstate) para aplicar o estado salvo a barras de controle da janela de quadro.  
  
 Para obter mais informações sobre barras de controle de encaixe, consulte os artigos [barras de controle](../../mfc/control-bars.md), [barras de ferramentas: Encaixando e flutuando](../../mfc/docking-and-floating-toolbars.md), e [janelas com moldura](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDockState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxadv.h  
  
##  <a name="clear"></a>CDockState::Clear  
 Chame essa função para limpar todas as informações de encaixe armazenadas no `CDockState` objeto.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Isso inclui não apenas se a barra está encaixada ou não, mas o tamanho e a posição da barra e se ele está visível ou não.  
  
##  <a name="getversion"></a>CDockState::GetVersion  
 Chame essa função para recuperar o número de versão de armazenado barra de estado.  
  
```  
DWORD GetVersion();
```  
  
### <a name="return-value"></a>Valor de retorno  
 1 se a barra armazenada informações são mais antigas que atual barra estado; 2 se a barra armazenada informações são o mesmo que o atual estado da barra.  
  
### <a name="remarks"></a>Comentários  
 Suporte de versão permite uma barra revisada para adicionar novas propriedades persistentes e ainda ser capaz de detectar e carregar o estado persistente criado por uma versão anterior da barra.  
  
##  <a name="loadstate"></a>CDockState::LoadState  
 Chame essa função para recuperar as informações de estado do registro ou. Arquivo INI.  
  
```  
void LoadState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProfileName`  
 Aponta para uma cadeia de caracteres teminated nulo que especifica o nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde as informações de estado estão armazenadas.  
  
### <a name="remarks"></a>Comentários  
 O nome do perfil é a seção do aplicativo. Arquivo INI ou no registro que contém informações sobre o estado das barras. Você pode salvar a barra de informações de estado de controle no registro ou. Ini com `SaveState`.  
  
##  <a name="m_arrbarinfo"></a>CDockState::m_arrBarInfo  
 A `CPtrArray` que é uma matriz de ponteiros para as informações da barra de controle armazenado para cada barra de controle que salva informações de estado no objeto de `CDockState` objeto.  
  
```  
CPtrArray m_arrBarInfo;  
```  
  
##  <a name="savestate"></a>CDockState::SaveState  
 Chame essa função para salvar as informações de estado no registro ou. Arquivo INI.  
  
```  
void SaveState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProfileName`  
 Aponta para uma cadeia de caracteres teminated nulo que especifica o nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde as informações de estado estão armazenadas.  
  
### <a name="remarks"></a>Comentários  
 O nome do perfil é a seção do aplicativo. Arquivo INI ou no registro que contém informações sobre o estado da barra de controle. `SaveState`também salva o tamanho atual da tela. Você pode recuperar informações da barra de controle do registro ou. Ini com `LoadState`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)



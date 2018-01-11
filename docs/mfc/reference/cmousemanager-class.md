---
title: Classe CMouseManager | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
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
caps.latest.revision: "26"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f50b74731089346a9675b5340ba0ea1a0b2879f4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmousemanager-class"></a>Classe CMouseManager
Permite que um usuário associar comandos diferentes um determinado [CView](../../mfc/reference/cview-class.md) quando o usuário clica duas vezes em que modo de exibição do objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMouseManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMouseManager::AddView](#addview)|Adiciona um `CView` o objeto para o **personalização** caixa de diálogo. O **personalização** caixa de diálogo permite que o usuário associar um clique duplo com um comando para cada uma das visualizações listadas.|  
|[CMouseManager::GetViewDblClickCommand](#getviewdblclickcommand)|Retorna o comando que é executado quando o usuário clica duas vezes no modo de exibição fornecido.|  
|[CMouseManager::GetViewIconId](#getviewiconid)|Retorna o ícone associado com a ID de exibição fornecido.|  
|[CMouseManager::GetViewIdByName](#getviewidbyname)|Retorna a ID de exibição associada ao nome de exibição fornecido.|  
|[CMouseManager::GetViewNames](#getviewnames)|Recupera uma lista de todos os nomes de exibição adicionado.|  
|[CMouseManager::LoadState](#loadstate)|Carrega o `CMouseManager` estado do registro do Windows.|  
|[CMouseManager::SaveState](#savestate)|Grava o `CMouseManager` estado no registro do Windows.|  
|[CMouseManager::SetCommandForDblClk](#setcommandfordblclk)|Associa o comando fornecido e o modo de exibição fornecido.|  
  
## <a name="remarks"></a>Comentários  
 O `CMouseManager` classe mantém uma coleção de `CView` objetos. Cada exibição é identificada por um nome e uma ID. Essas exibições são mostradas no **personalização** caixa de diálogo. O usuário pode alterar o comando que está associado a qualquer exibição por meio de **personalização** caixa de diálogo. O comando associado é executado quando o usuário clica duas vezes no modo de exibição. Para dar suporte a isso uma perspectiva de codificação, você deve processar o `WM_LBUTTONDBLCLK` mensagem e chame o [CWinAppEx::OnViewDoubleClick](../../mfc/reference/cwinappex-class.md#onviewdoubleclick) função no código para que `CView` objeto.  
  
 Você não deve criar um `CMouseManager` objeto manualmente. Ele será criado pela estrutura do seu aplicativo. Ele será também destruído automaticamente quando o usuário sai do aplicativo. Para obter um ponteiro para o Gerenciador de mouse para seu aplicativo, chame [CWinAppEx::GetMouseManager](../../mfc/reference/cwinappex-class.md#getmousemanager).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMouseManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmousemanager.h  
  
##  <a name="addview"></a>CMouseManager::AddView  
 Registra um [CView](../../mfc/reference/cview-class.md) do objeto com o [CMouseManager classe](../../mfc/reference/cmousemanager-class.md) para dar suporte ao comportamento de mouse personalizado.  
  
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
 [in] `iViewId`  
 Uma ID de exibição.  
  
 [in] `uiViewNameResId`  
 Uma ID de cadeia de caracteres de recurso que faz referência ao nome de exibição.  
  
 [in] `uiIconId`  
 Uma ID de ícone do modo de exibição  
  
 [in] `iId`  
 Uma ID de exibição.  
  
 [in] `lpszViewName`  
 Um nome de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para oferecer suporte ao comportamento de mouse personalizado, uma exibição deve ser registrada com o `CMouseManager` objeto. Qualquer objeto derivado de `CView` classe pode ser registrada com o Gerenciador de mouse. A cadeia de caracteres e o ícone associado a um modo de exibição são exibidos na **Mouse** guia o **personalizar** caixa de diálogo.  
  
 É responsabilidade do programador para criar e manter as IDs de exibição, como `iViewId` e `iId`.  
  
 Para obter mais informações sobre como fornecer o comportamento do mouse personalizado, consulte [personalização de teclado e Mouse](../../mfc/keyboard-and-mouse-customization.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como recuperar um ponteiro para um `CMouseManager` objeto usando o `CWinAppEx::GetMouseManager` método e o `AddView` método o `CMouseManager` classe. Este trecho de código é parte do [amostra de coleta de estado](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StateCollection#4](../../mfc/reference/codesnippet/cpp/cmousemanager-class_1.cpp)]  
  
##  <a name="getviewdblclickcommand"></a>CMouseManager::GetViewDblClickCommand  
 Retorna o comando que é executado quando o usuário clica duas vezes no modo de exibição fornecido.  
  
```  
UINT GetViewDblClickCommand(int iId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iId`  
 A ID da exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de comando se o modo de exibição estiver associado um comando. Caso contrário, 0.  
  
##  <a name="getviewiconid"></a>CMouseManager::GetViewIconId  
 Recupera o ícone associado a uma ID de exibição.  
  
```  
UINT GetViewIconId(int iViewId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iViewId`  
 A ID da exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de recurso do ícone se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método irá falhar se o modo de exibição não é registrado pela primeira vez usando [CMouseManager::AddView](#addview).  
  
##  <a name="getviewidbyname"></a>CMouseManager::GetViewIdByName  
 Recupera a ID de exibição associada a um nome de exibição.  
  
```  
int GetViewIdByName(LPCTSTR lpszName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O nome de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma ID de exibição se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método de pesquisa por meio de exibições registradas usando [CMouseManager::AddView](#addview).  
  
##  <a name="getviewnames"></a>CMouseManager::GetViewNames  
 Recupera uma lista de todos os nomes de exibição registrados.  
  
```  
void GetViewNames(CStringList& listOfNames) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `listOfNames`  
 Uma referência a `CStringList` objeto.  
  
### <a name="remarks"></a>Comentários  
 Este método preenche o parâmetro `listOfNames` com os nomes de todas as exibições registrados usando [CMouseManager::AddView](#addview).  
  
##  <a name="loadstate"></a>CMouseManager::LoadState  
 Carrega o estado do [CMouseManager classe](../../mfc/reference/cmousemanager-class.md) do registro.  
  
```  
BOOL LoadState(LPCTSTR lpszProfileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Um caminho de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As informações de estado carregadas a partir do registro incluem os modos de exibição registrados, os identificadores de exibição e os comandos associados. Se o parâmetro `lpszProfileName` é `NULL`, essa função carrega o `CMouseManager` dados do local padrão do registro controlado pelo [CWinAppEx classe](../../mfc/reference/cwinappex-class.md).  
  
 Na maioria dos casos, você não precisa chamar essa função diretamente. Ele é chamado como parte do processo de inicialização do espaço de trabalho. Para obter mais informações sobre o processo de inicialização do espaço de trabalho, consulte [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate).  
  
##  <a name="savestate"></a>CMouseManager::SaveState  
 Grava o estado do [CMouseManager classe](../../mfc/reference/cmousemanager-class.md) no registro.  
  
```  
BOOL SaveState(LPCTSTR lpszProfileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Um caminho de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As informações de estado, gravadas para o registro incluem todos os modos de exibição, os identificadores de exibição e os comandos associados. Se o parâmetro `lpszProfileName` é `NULL`, essa função grava o `CMouseManager` dados no local padrão de registro controlado pelo [CWinAppEx classe](../../mfc/reference/cwinappex-class.md).  
  
 Na maioria dos casos, você não precisa chamar essa função diretamente. Ele é chamado como parte do processo de serialização de espaço de trabalho. Para obter mais informações sobre o processo de serialização do espaço de trabalho, consulte [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate).  
  
##  <a name="setcommandfordblclk"></a>CMouseManager::SetCommandForDblClk  
 Associa um comando personalizado um modo de exibição que primeiro é registrado com o Gerenciador de mouse.  
  
```  
void SetCommandForDblClk(
    int iViewId,  
    UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iViewId`  
 O identificador de modo de exibição.  
  
 [in] `uiCmd`  
 O identificador de comando.  
  
### <a name="remarks"></a>Comentários  
 Para associar um comando personalizado um modo de exibição, você deve primeiro registrar o modo de exibição usando [CMouseManager::AddView](#addview). O `AddView` método exige um identificador de exibição como um parâmetro de entrada. Quando você registra um modo de exibição, você pode chamar `CMouseManager::SetCommandForDblClk` com o mesma exibição identificador parâmetro de entrada que você forneceu para `AddView`. Depois disso, quando o usuário clica duas vezes o mouse na exibição de registrado, o aplicativo executará o comando indicado pelo `uiCmd.` para suportar o comportamento do mouse personalizado, você também precisará personalizar a exibição registrada com o Gerenciador de mouse. Para obter mais informações sobre o comportamento do mouse personalizado, consulte [personalização de teclado e Mouse] – brokenlink – (... / customization.md de mouse e teclado).  
  
 Se `uiCmd` for definido como 0, o modo de exibição especificado não está mais associado um comando.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)




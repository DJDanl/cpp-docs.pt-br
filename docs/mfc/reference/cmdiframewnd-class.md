---
title: Classe CMDIFrameWnd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMDIFrameWnd
- AFXWIN/CMDIFrameWnd
- AFXWIN/CMDIFrameWnd::CMDIFrameWnd
- AFXWIN/CMDIFrameWnd::CreateClient
- AFXWIN/CMDIFrameWnd::CreateNewChild
- AFXWIN/CMDIFrameWnd::GetWindowMenuPopup
- AFXWIN/CMDIFrameWnd::MDIActivate
- AFXWIN/CMDIFrameWnd::MDICascade
- AFXWIN/CMDIFrameWnd::MDIGetActive
- AFXWIN/CMDIFrameWnd::MDIIconArrange
- AFXWIN/CMDIFrameWnd::MDIMaximize
- AFXWIN/CMDIFrameWnd::MDINext
- AFXWIN/CMDIFrameWnd::MDIPrev
- AFXWIN/CMDIFrameWnd::MDIRestore
- AFXWIN/CMDIFrameWnd::MDISetMenu
- AFXWIN/CMDIFrameWnd::MDITile
dev_langs:
- C++
helpviewer_keywords:
- CMDIFrameWnd [MFC], CMDIFrameWnd
- CMDIFrameWnd [MFC], CreateClient
- CMDIFrameWnd [MFC], CreateNewChild
- CMDIFrameWnd [MFC], GetWindowMenuPopup
- CMDIFrameWnd [MFC], MDIActivate
- CMDIFrameWnd [MFC], MDICascade
- CMDIFrameWnd [MFC], MDIGetActive
- CMDIFrameWnd [MFC], MDIIconArrange
- CMDIFrameWnd [MFC], MDIMaximize
- CMDIFrameWnd [MFC], MDINext
- CMDIFrameWnd [MFC], MDIPrev
- CMDIFrameWnd [MFC], MDIRestore
- CMDIFrameWnd [MFC], MDISetMenu
- CMDIFrameWnd [MFC], MDITile
ms.assetid: fa8736e6-511b-4c51-8b4d-eba78378aeb9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bc40ac38d4f74848448b26284ad225faad04864e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmdiframewnd-class"></a>Classe CMDIFrameWnd
Fornece a funcionalidade de um Windows várias janelas de quadro MDI (interface) do documento, juntamente com os membros para gerenciar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMDIFrameWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIFrameWnd::CMDIFrameWnd](#cmdiframewnd)|Constrói um `CMDIFrameWnd`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIFrameWnd::CreateClient](#createclient)|Cria um Windows **MDICLIENT** janela para este `CMDIFrameWnd`. Chamado pelo `OnCreate` função de membro `CWnd`.|  
|[CMDIFrameWnd::CreateNewChild](#createnewchild)|Cria uma nova janela filho.|  
|[CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup)|Retorna o menu pop-up de janela.|  
|[CMDIFrameWnd::MDIActivate](#mdiactivate)|Ativa uma janela diferente do filho MDI.|  
|[CMDIFrameWnd::MDICascade](#mdicascade)|Organiza todas as janelas filho em um formato em cascata.|  
|[CMDIFrameWnd::MDIGetActive](#mdigetactive)|Recupera a janela de filho MDI ativa no momento, juntamente com um sinalizador que indica se ou não o filho é maximizado.|  
|[CMDIFrameWnd::MDIIconArrange](#mdiiconarrange)|Organiza todas as janelas filho de documento minimizada.|  
|[CMDIFrameWnd::MDIMaximize](#mdimaximize)|Maximiza a uma janela de filho MDI.|  
|[CMDIFrameWnd::MDINext](#mdinext)|Ativa a janela filho imediatamente por trás de janela filho ativo no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filho.|  
|[CMDIFrameWnd::MDIPrev](#mdiprev)|Ativa a janela filho anterior e coloca a janela ativa no momento filho imediatamente por trás dele.|  
|[CMDIFrameWnd::MDIRestore](#mdirestore)|Restaura uma janela de filho MDI do tamanho minimizado ou maximizado.|  
|[CMDIFrameWnd::MDISetMenu](#mdisetmenu)|Substitui o menu de uma janela de quadro MDI, no menu pop-up de janela ou ambos.|  
|[CMDIFrameWnd::MDITile](#mditile)|Organiza todas as janelas filho em um formato lado a lado.|  
  
## <a name="remarks"></a>Comentários  
 Para criar uma janela do quadro MDI úteis para seu aplicativo, derive uma classe de `CMDIFrameWnd`. Adicione variáveis de membro para a classe derivada para armazenar dados específicos do aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.  
  
 Você pode construir uma janela de quadro MDI chamando o [criar](../../mfc/reference/cframewnd-class.md#create) ou [LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe) função de membro `CFrameWnd`.  
  
 Antes de chamar **criar** ou `LoadFrame`, você deve construir o objeto de janela do quadro na pilha usando o C++ **novo** operador. Antes de chamar **criar** você também pode registrar uma classe de janela com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe do quadro.  
  
 Use o **criar** função de membro para passar parâmetros de criação do quadro imediatos como argumentos.  
  
 `LoadFrame`requer menos argumentos que **criar**e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessado por `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, **IDR_MAINFRAME**).  
  
 Embora **MDIFrameWnd** é derivado de `CFrameWnd`, derivado de uma classe de janela do quadro de `CMDIFrameWnd` não precisa ser declarado com `DECLARE_DYNCREATE`.  
  
 O `CMDIFrameWnd` classe herda grande parte da sua implementação do padrão de `CFrameWnd`. Para obter uma lista detalhada desses recursos, consulte o [CFrameWnd](../../mfc/reference/cframewnd-class.md) descrição de classe. O `CMDIFrameWnd` classe tem os seguintes recursos adicionais:  
  
-   Uma janela de quadro MDI gerencia o **MDICLIENT** janela, reposicione em conjunto com barras de controle. A janela do cliente MDI é o pai direto do windows de quadro filho MDI. O **WS_HSCROLL** e **WS_VSCROLL** estilos da janela especificados em uma `CMDIFrameWnd` se aplicam à janela do cliente MDI em vez da janela do quadro principal para o usuário pode rolar a área do cliente MDI (como o Windows Gerente do programa, por exemplo).  
  
-   Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus, quando há uma janela de filho MDI ativa. Quando há um filho MDI ativo, a barra de menus da janela de quadro MDI é automaticamente substituída pelo menu de janela filho MDI.  
  
-   Uma janela de quadro MDI funciona em conjunto com a janela filho MDI atual, se houver um. Por exemplo, mensagens de comando são delegadas para o filho MDI ativo atualmente antes da janela do quadro MDI.  
  
-   Uma janela de quadro MDI tem manipuladores de padrão para os seguintes comandos do menu janela padrão:  
  
    - **ID_WINDOW_TILE_VERT**  
  
    - **ID_WINDOW_TILE_HORZ**  
  
    - **ID_WINDOW_CASCADE**  
  
    - **ID_WINDOW_ARRANGE**  
  
-   Uma janela de quadro MDI também tem uma implementação de **ID_WINDOW_NEW**, que cria um novo quadro e o modo de exibição no documento atual. Um aplicativo pode substituir essas implementações padrão de comando para personalizar o tratamento de janela MDI.  
  
 Não use o C++ **excluir** operador destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto C++ quando a janela é destruída. Quando o usuário fecha a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CMDIFrameWnd`, consulte [janelas com moldura](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMDIFrameWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cmdiframewnd"></a>CMDIFrameWnd::CMDIFrameWnd  
 Constrói um objeto `CMDIFrameWnd`.  
  
```  
CMDIFrameWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o **criar** ou `LoadFrame` a função de membro para criar a janela do quadro MDI visível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#13](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_1.cpp)]  
  
##  <a name="createclient"></a>CMDIFrameWnd::CreateClient  
 Cria a janela do cliente MDI que gerencia o `CMDIChildWnd` objetos.  
  
```  
virtual BOOL CreateClient(
    LPCREATESTRUCT lpCreateStruct,  
    CMenu* pWindowMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCreateStruct`  
 Um ponteiro de tempo para um [CREATESTRUCT](../../mfc/reference/createstruct-structure.md) estrutura.  
  
 `pWindowMenu`  
 Um ponteiro para o menu pop-up de janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro deve ser chamada se você substituir o `OnCreate` diretamente a função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#14](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_2.cpp)]  
  
##  <a name="createnewchild"></a>CMDIFrameWnd::CreateNewChild  
 Cria uma nova janela filho.  
  
```  
CMDIChildWnd* CreateNewChild(
    CRuntimeClass* pClass,  
    UINT nResource,  
    HMENU hMenu = NULL,  
    HACCEL hAccel = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClass`  
 A classe de tempo de execução da janela filho a ser criado.  
  
 *nResource*  
 A ID de recursos compartilhados associados com a janela filho.  
  
 `hMenu`  
 Menu da janela filho.  
  
 `hAccel`  
 Acelerador da janela filho.  
  
### <a name="remarks"></a>Comentários  
 Use esta função crie janelas de uma janela de quadro MDI filho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#15](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_3.cpp)]  
  
 Este exemplo é um trecho do artigo da Base de dados de Conhecimento Q201045, "como: adicionar vários tipos de janela a um MDI não de documento/exibição aplicativo." Artigos da Base de dados de Conhecimento estão disponíveis em [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="getwindowmenupopup"></a>CMDIFrameWnd::GetWindowMenuPopup  
 Chame essa função de membro para obter um identificador para o menu pop-up atual denominado "Janela" (o menu pop-up com itens de menu para gerenciamento de janelas MDI).  
  
```  
virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMenuBar*  
 A barra de menu atual.  
  
### <a name="return-value"></a>Valor de retorno  
 No menu pop-up de janela se existe; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão procura um menu pop-up que contém comandos padrão do menu janela como **ID_WINDOW_NEW** e **ID_WINDOW_TILE_HORZ**.  
  
 Substitua essa função de membro, se você tiver um menu de janela que não usa o comando de menu padrão IDs.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#16](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_4.cpp)]  
  
##  <a name="mdiactivate"></a>CMDIFrameWnd::MDIActivate  
 Ativa uma janela diferente do filho MDI.  
  
```  
void MDIActivate(CWnd* pWndActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndActivate*  
 Aponta para a janela de filho MDI seja ativado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro envia o [WM_MDIACTIVATE](../../mfc/reference/cwnd-class.md#onmdiactivate) mensagem para a janela filho que está sendo ativado e a janela filho que está sendo desativado.  
  
 Essa é a mesma mensagem enviada se o usuário altera o foco para uma janela de filho MDI usando o mouse ou teclado.  
  
> [!NOTE]
>  Uma janela de filho MDI é ativada independentemente da janela do quadro MDI. Quando o quadro for ativo, a janela filho que foi ativada pela última vez é enviada um [WM_NCACTIVATE](../../mfc/reference/cwnd-class.md#onncactivate) mensagem para desenhar um quadro de janela ativa e a barra de legenda, mas ele não receberá outro `WM_MDIACTIVATE` mensagem.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup).  
  
##  <a name="mdicascade"></a>CMDIFrameWnd::MDICascade  
 Organiza todas as janelas filho MDI em um formato em cascata.  
  
```  
void MDICascade();  
void MDICascade(int nType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nType`  
 Especifica um sinalizador em cascata. Pode ser especificado apenas o seguinte sinalizador: `MDITILE_SKIPDISABLED`, que evita a desabilitado MDI filho do windows que está sendo em cascata.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão do `MDICascade`, sem parâmetros, organiza todas as janelas de filho MDI, incluindo desabilitado aqueles em cascata. A segunda versão opcionalmente faz não desabilitado MDI filho em cascata se você especificar `MDITILE_SKIPDISABLED` para o `nType` parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#17](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_5.cpp)]  
  
##  <a name="mdigetactive"></a>CMDIFrameWnd::MDIGetActive  
 Recupera a ativa janela filho MDI atual, junto com um sinalizador que indica se a janela filho é maximizada.  
  
```  
CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbMaximized*  
 Um ponteiro para um **BOOL** valor de retorno. Definido como **TRUE** no retorno se a janela é maximizada; caso contrário **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela filho MDI ativo.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).  
  
##  <a name="mdiiconarrange"></a>CMDIFrameWnd::MDIIconArrange  
 Organiza todas as janelas filho de documento minimizada.  
  
```  
void MDIIconArrange();
```  
  
### <a name="remarks"></a>Comentários  
 Ele não afeta as janelas filho que não sejam minimizadas.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMDIFrameWnd::MDICascade](#mdicascade).  
  
##  <a name="mdimaximize"></a>CMDIFrameWnd::MDIMaximize  
 Maximiza a janela de filho MDI especificada.  
  
```  
void MDIMaximize(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para maximizar a janela.  
  
### <a name="remarks"></a>Comentários  
 Quando uma janela filho é maximizada, Windows redimensiona para tornar sua área cliente preencher a janela do cliente. O Windows coloca menu controle da janela filho na barra de menu do quadro para que o usuário possa restaurar ou fechar a janela filho. Ele também adiciona o título da janela filho com o título da janela do quadro.  
  
 Se outra janela do filho MDI é ativada quando a janela de filho MDI ativa no momento é maximizada, o Windows restaura o filho ativo no momento e maximiza a janela filho recentemente ativado.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).  
  
##  <a name="mdinext"></a>CMDIFrameWnd::MDINext  
 Ativa a janela filho imediatamente por trás de janela filho ativo no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filho.  
  
```  
void MDINext();
```  
  
### <a name="remarks"></a>Comentários  
 Se a janela de filho MDI ativa no momento é maximizada, a função de membro restaura o filho ativo no momento e maximiza o filho recentemente ativado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#18](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_6.cpp)]  
  
##  <a name="mdiprev"></a>CMDIFrameWnd::MDIPrev  
 Ativa a janela filho anterior e coloca a janela ativa no momento filho imediatamente por trás dele.  
  
```  
void MDIPrev();
```  
  
### <a name="remarks"></a>Comentários  
 Se a janela de filho MDI ativa no momento é maximizada, a função de membro restaura o filho ativo no momento e maximiza o filho recentemente ativado.  
  
##  <a name="mdirestore"></a>CMDIFrameWnd::MDIRestore  
 Restaura uma janela de filho MDI do tamanho minimizado ou maximizado.  
  
```  
void MDIRestore(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela para restaurar.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMDIChildWnd::MDIRestore](../../mfc/reference/cmdichildwnd-class.md#mdirestore).  
  
##  <a name="mdisetmenu"></a>CMDIFrameWnd::MDISetMenu  
 Substitui o menu de uma janela de quadro MDI, no menu pop-up de janela ou ambos.  
  
```  
CMenu* MDISetMenu(
    CMenu* pFrameMenu,  
    CMenu* pWindowMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pFrameMenu*  
 Especifica o menu do novo menu janela do quadro. Se **nulo**, o menu não é alterado.  
  
 `pWindowMenu`  
 Especifica o menu do menu pop-up de nova janela. Se **nulo**, o menu não é alterado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o menu de janela com moldura substituído por esta mensagem. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `MDISetMenu`, um aplicativo deve chamar o [DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar) função de membro `CWnd` para atualizar a barra de menus.  
  
 Se essa chamada substitui o menu pop-up de janela, itens de menu janela filho MDI são removidas do menu janela anterior e adicionados ao menu pop-up de nova janela.  
  
 Se uma janela de filho MDI é maximizada e essa chamada substitui o menu de janela com moldura MDI, os controles de menu e a restauração de controle são removidos do menu janela do quadro anterior e adicionados ao menu novo.  
  
 Não chame essa função de membro, se você usar a estrutura de gerenciamento de janelas filho MDI.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#19](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_7.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing#20](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_8.cpp)]  
  
##  <a name="mditile"></a>CMDIFrameWnd::MDITile  
 Organiza todas as janelas filho em um formato lado a lado.  
  
```  
void MDITile();  
void MDITile(int nType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nType`  
 Especifica um sinalizador de lado a lado. Esse parâmetro pode ser qualquer um dos sinalizadores a seguir:  
  
- `MDITILE_HORIZONTAL`Blocos janelas filho MDI assim que uma janela aparece acima do outro.  
  
- `MDITILE_SKIPDISABLED`Impede que o windows de filho MDI desabilitados que está sendo colocada lado a lado.  
  
- `MDITILE_VERTICAL`Blocos janelas filho MDI assim que uma janela aparece ao lado do outro.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão do `MDITile`, sem parâmetros, blocos windows verticalmente em Windows versões 3.1 e posteriores. A segunda versão blocos windows verticalmente ou horizontalmente, dependendo do valor da `nType` parâmetro.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CMDIFrameWnd::MDICascade](#mdicascade).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)   
 [Exemplo MFC SNAPVW](../../visual-cpp-samples.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)

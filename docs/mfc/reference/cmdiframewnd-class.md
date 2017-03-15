---
title: Classe CMDIFrameWnd | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMDIFrameWnd
dev_langs:
- C++
helpviewer_keywords:
- MDI frame windows
- CMDIFrameWnd class
ms.assetid: fa8736e6-511b-4c51-8b4d-eba78378aeb9
caps.latest.revision: 22
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 0eae6c14038dd27a5779757d1807068fbe865b81
ms.lasthandoff: 02/25/2017

---
# <a name="cmdiframewnd-class"></a>Classe CMDIFrameWnd
Fornece a funcionalidade de um Windows várias janelas de quadro de interface (MDI) do documento, juntamente com os membros para gerenciar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMDIFrameWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIFrameWnd::CMDIFrameWnd](#cmdiframewnd)|Constrói um `CMDIFrameWnd`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIFrameWnd::CreateClient](#createclient)|Cria um Windows **MDICLIENT** janela para este `CMDIFrameWnd`. Chamando o `OnCreate` função de membro `CWnd`.|  
|[CMDIFrameWnd::CreateNewChild](#createnewchild)|Cria uma nova janela filho.|  
|[CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup)|Retorna o menu da janela pop-up.|  
|[CMDIFrameWnd::MDIActivate](#mdiactivate)|Ativa uma janela diferente do filho MDI.|  
|[CMDIFrameWnd::MDICascade](#mdicascade)|Organiza todas as janelas filho em um formato em cascata.|  
|[CMDIFrameWnd::MDIGetActive](#mdigetactive)|Recupera a janela ativa do filho MDI, juntamente com um sinalizador que indica se ou não o filho é maximizado.|  
|[CMDIFrameWnd::MDIIconArrange](#mdiiconarrange)|Organiza todas as janelas filho de documento minimizada.|  
|[CMDIFrameWnd::MDIMaximize](#mdimaximize)|Maximiza a uma janela filho MDI.|  
|[CMDIFrameWnd::MDINext](#mdinext)|Ativa a janela filho imediatamente atrás da janela filho ativa no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filho.|  
|[CMDIFrameWnd::MDIPrev](#mdiprev)|Ativa a janela filho anterior e coloca a janela filho ativa no momento imediatamente por trás dele.|  
|[CMDIFrameWnd::MDIRestore](#mdirestore)|Restaura uma janela filho MDI de tamanho maximizado ou minimizado.|  
|[CMDIFrameWnd::MDISetMenu](#mdisetmenu)|Substitui o menu de uma janela de quadro MDI, o menu da janela pop-up ou ambos.|  
|[CMDIFrameWnd::MDITile](#mditile)|Organiza todas as janelas filho em um formato lado a lado.|  
  
## <a name="remarks"></a>Comentários  
 Para criar uma janela de quadro MDI úteis para seu aplicativo, derive uma classe de `CMDIFrameWnd`. Adicione variáveis de membro para a classe derivada para armazenar dados específicos do aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.  
  
 Você pode construir uma janela de quadro MDI chamando o [criar](../../mfc/reference/cframewnd-class.md#create) ou [LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe) função de membro `CFrameWnd`.  
  
 Antes de chamar **criar** ou `LoadFrame`, você deve construir o objeto de janela de quadro na pilha usando o C++ **novo** operador. Antes de chamar **criar** você também pode registrar uma classe de janela com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe do quadro.  
  
 Use o **criar** função de membro para passar parâmetros de criação do quadro imediatos como argumentos.  
  
 `LoadFrame`requer menos argumentos que **criar**e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessado por `LoadFrame`, todos esses recursos devem ter o mesmo ID de recurso (por exemplo, **IDR_MAINFRAME**).  
  
 Embora **MDIFrameWnd** é derivado de `CFrameWnd`, uma classe de janela de quadro derivada de `CMDIFrameWnd` não precisa ser declarado com `DECLARE_DYNCREATE`.  
  
 O `CMDIFrameWnd` classe herda muito a implementação padrão de `CFrameWnd`. Para obter uma lista detalhada desses recursos, consulte o [CFrameWnd](../../mfc/reference/cframewnd-class.md) descrição da classe. O `CMDIFrameWnd` classe tem os seguintes recursos adicionais:  
  
-   Uma janela de quadro MDI gerencia o **MDICLIENT** janela, o reposicionamento em conjunto com barras de controle. A janela do cliente MDI é o pai de janelas de quadro MDI filho direto. O **WS_HSCROLL** e **WS_VSCROLL** estilos da janela especificados em uma `CMDIFrameWnd` se aplicam a janela do cliente MDI em vez da janela principal do quadro para que o usuário pode rolar a área do cliente MDI (como o Windows gerente de programa, por exemplo).  
  
-   Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando não há nenhuma janela ativa do filho MDI. Quando há um filho MDI ativo, barra de menus da janela de quadro MDI é substituída automaticamente pelo menu de janela filho MDI.  
  
-   Uma janela de quadro MDI funciona em conjunto com a janela filho MDI atual, se houver. Por exemplo, as mensagens de comando são delegadas para o filhos MDI ativo no momento antes da janela de quadro MDI.  
  
-   Uma janela de quadro MDI tem manipuladores padrão para os seguintes comandos do menu janela padrão:  
  
    - **ID_WINDOW_TILE_VERT**  
  
    - **ID_WINDOW_TILE_HORZ**  
  
    - **ID_WINDOW_CASCADE**  
  
    - **ID_WINDOW_ARRANGE**  
  
-   Uma janela de quadro MDI também tem uma implementação de **ID_WINDOW_NEW**, que cria um novo quadro e o modo de exibição no documento atual. Um aplicativo pode substituir essas implementações de comando padrão para personalizar a manipulação de janela MDI.  
  
 Não use o C++ **excluir** operador para destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto C++ quando a janela for destruída. Quando o usuário fechar a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CMDIFrameWnd`, consulte [janelas com moldura](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMDIFrameWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecmdiframewnda--cmdiframewndcmdiframewnd"></a><a name="cmdiframewnd"></a>CMDIFrameWnd::CMDIFrameWnd  
 Constrói um objeto `CMDIFrameWnd`.  
  
```  
CMDIFrameWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o **criar** ou `LoadFrame` a função de membro para criar a janela de quadro MDI visível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&13;](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_1.cpp)]  
  
##  <a name="a-namecreateclienta--cmdiframewndcreateclient"></a><a name="createclient"></a>CMDIFrameWnd::CreateClient  
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
 Um ponteiro para o menu da janela pop-up.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro deve ser chamada se você substituir o `OnCreate` diretamente a função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#14;](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_2.cpp)]  
  
##  <a name="a-namecreatenewchilda--cmdiframewndcreatenewchild"></a><a name="createnewchild"></a>CMDIFrameWnd::CreateNewChild  
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
 A ID de recursos compartilhados associados à janela filho.  
  
 `hMenu`  
 Menu da janela filho.  
  
 `hAccel`  
 Aceleração da janela filho.  
  
### <a name="remarks"></a>Comentários  
 Use esta função crie janelas de uma janela de quadro MDI filho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#15;](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_3.cpp)]  
  
 Este exemplo é um extrato do artigo da Base de dados de Conhecimento Q201045, "como: adicionar vários tipos de janelas para uma exibição de não-documentos MDI aplicativo." Artigos da Base de Conhecimento estão disponíveis na documentação da biblioteca MSDN Visual Studio ou no [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="a-namegetwindowmenupopupa--cmdiframewndgetwindowmenupopup"></a><a name="getwindowmenupopup"></a>CMDIFrameWnd::GetWindowMenuPopup  
 Chame essa função de membro para obter um identificador para o menu pop-up atual chamado "Janela" (o menu pop-up com itens de menu para gerenciamento de janelas MDI).  
  
```  
virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMenuBar*  
 A barra de menu atual.  
  
### <a name="return-value"></a>Valor de retorno  
 O menu pop-up janela se existe; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão procura um menu pop-up contendo os comandos do menu janela padrão como **ID_WINDOW_NEW** e **ID_WINDOW_TILE_HORZ**.  
  
 Substitua essa função de membro se você tem um menu de janela que não use o comando de menu padrão IDs.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&16;](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_4.cpp)]  
  
##  <a name="a-namemdiactivatea--cmdiframewndmdiactivate"></a><a name="mdiactivate"></a>CMDIFrameWnd::MDIActivate  
 Ativa uma janela diferente do filho MDI.  
  
```  
void MDIActivate(CWnd* pWndActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndActivate*  
 Aponta para a janela de filho MDI seja ativado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro envia o [WM_MDIACTIVATE](../../mfc/reference/cwnd-class.md#onmdiactivate) mensagem para a janela filho que está sendo ativado e a janela filho que está sendo desativado.  
  
 Essa é a mesma mensagem é enviada se o usuário altera o foco para uma janela de filho MDI, usando o mouse ou teclado.  
  
> [!NOTE]
>  Uma janela de filho MDI é ativada independentemente da janela de quadro MDI. Quando o quadro for ativo, a janela filho que foi ativada pela última vez é enviada uma [WM_NCACTIVATE](../../mfc/reference/cwnd-class.md#onncactivate) mensagem para desenhar um quadro de janela ativa e a barra de legenda, mas ele não recebe outro `WM_MDIACTIVATE` mensagem.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup).  
  
##  <a name="a-namemdicascadea--cmdiframewndmdicascade"></a><a name="mdicascade"></a>CMDIFrameWnd::MDICascade  
 Organiza todas as janelas filho MDI em um formato de cascata.  
  
```  
void MDICascade();  
void MDICascade(int nType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nType`  
 Especifica um sinalizador em cascata. Pode ser especificado apenas o seguinte sinalizador: `MDITILE_SKIPDISABLED`, que impede que desabilitado janelas MDI filhas sendo em cascata.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão do `MDICascade`, sem parâmetros, dispõe em cascata todas as janelas de filho MDI, incluindo aqueles desabilitado. A segunda versão faz opcionalmente não desabilitado MDI filho em cascata se você especificar `MDITILE_SKIPDISABLED` para o `nType` parâmetro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_5.cpp)]  
  
##  <a name="a-namemdigetactivea--cmdiframewndmdigetactive"></a><a name="mdigetactive"></a>CMDIFrameWnd::MDIGetActive  
 Recupera a ativa janela filho MDI atual, junto com um sinalizador que indica se a janela filho é maximizada.  
  
```  
CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbMaximized*  
 Um ponteiro para um **BOOL** valor de retorno. Definido como **TRUE** no retorno se a janela for maximizada; caso contrário **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela filho MDI ativa.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).  
  
##  <a name="a-namemdiiconarrangea--cmdiframewndmdiiconarrange"></a><a name="mdiiconarrange"></a>CMDIFrameWnd::MDIIconArrange  
 Organiza todas as janelas filho de documento minimizada.  
  
```  
void MDIIconArrange();
```  
  
### <a name="remarks"></a>Comentários  
 Ele não afeta janelas filho que não são minimizadas.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CMDIFrameWnd::MDICascade](#mdicascade).  
  
##  <a name="a-namemdimaximizea--cmdiframewndmdimaximize"></a><a name="mdimaximize"></a>CMDIFrameWnd::MDIMaximize  
 Maximiza a janela filho MDI especificada.  
  
```  
void MDIMaximize(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para maximizar a janela.  
  
### <a name="remarks"></a>Comentários  
 Quando uma janela filho é maximizada, Windows redimensiona para tornar sua área cliente preencher a janela do cliente. O Windows coloca menu controle da janela filho na barra de menus do quadro para que o usuário possa restaurar ou feche a janela filho. Ele também adiciona o título da janela filho para o título da janela de quadro.  
  
 Se outra janela do filho MDI é ativada quando a janela ativa do filho MDI é maximizada, Windows restaura o filho ativo no momento e maximiza a janela filho recentemente ativado.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).  
  
##  <a name="a-namemdinexta--cmdiframewndmdinext"></a><a name="mdinext"></a>CMDIFrameWnd::MDINext  
 Ativa a janela filho imediatamente atrás da janela filho ativa no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filho.  
  
```  
void MDINext();
```  
  
### <a name="remarks"></a>Comentários  
 Se a janela ativa do filho MDI é maximizada, a função de membro restaura o filho ativo no momento e maximiza o filho recentemente ativado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&18;](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_6.cpp)]  
  
##  <a name="a-namemdipreva--cmdiframewndmdiprev"></a><a name="mdiprev"></a>CMDIFrameWnd::MDIPrev  
 Ativa a janela filho anterior e coloca a janela filho ativa no momento imediatamente por trás dele.  
  
```  
void MDIPrev();
```  
  
### <a name="remarks"></a>Comentários  
 Se a janela ativa do filho MDI é maximizada, a função de membro restaura o filho ativo no momento e maximiza o filho recentemente ativado.  
  
##  <a name="a-namemdirestorea--cmdiframewndmdirestore"></a><a name="mdirestore"></a>CMDIFrameWnd::MDIRestore  
 Restaura uma janela filho MDI de tamanho maximizado ou minimizado.  
  
```  
void MDIRestore(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a janela restaurar.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CMDIChildWnd::MDIRestore](../../mfc/reference/cmdichildwnd-class.md#mdirestore).  
  
##  <a name="a-namemdisetmenua--cmdiframewndmdisetmenu"></a><a name="mdisetmenu"></a>CMDIFrameWnd::MDISetMenu  
 Substitui o menu de uma janela de quadro MDI, o menu da janela pop-up ou ambos.  
  
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
 Um ponteiro para o menu da janela de quadro substituído por esta mensagem. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `MDISetMenu`, um aplicativo deve chamar o [DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar) função de membro `CWnd` para atualizar a barra de menus.  
  
 Se essa chamada substitui o menu da janela pop-up, itens de menu de janela filho MDI são removidos do menu janela anterior e adicionados ao menu pop-up de nova janela.  
  
 Se uma janela de filho MDI é maximizada e essa chamada substitui o menu de janela de quadro MDI, os controles menu e restauração de controle são removidos do menu janela do quadro anterior e adicionados ao menu novo.  
  
 Não chame essa função de membro se você usar a estrutura de gerenciamento de janelas filho MDI.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_7.cpp)]  
  
 [!code-cpp[20 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_8.cpp)]  
  
##  <a name="a-namemditilea--cmdiframewndmditile"></a><a name="mditile"></a>CMDIFrameWnd::MDITile  
 Organiza todas as janelas filho em um formato lado a lado.  
  
```  
void MDITile();  
void MDITile(int nType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nType`  
 Especifica um sinalizador de lado a lado. Esse parâmetro pode ser qualquer um dos sinalizadores a seguir:  
  
- `MDITILE_HORIZONTAL`Blocos janelas filho MDI para que uma janela aparece acima do outro.  
  
- `MDITILE_SKIPDISABLED`Impede que desabilitado janelas MDI filhas que está sendo colocada lado a lado.  
  
- `MDITILE_VERTICAL`Blocos janelas filho MDI para que uma janela é exibida ao lado do outro.  
  
### <a name="remarks"></a>Comentários  
 A primeira versão do `MDITile`, sem parâmetros, os blocos do windows verticalmente em Windows versões 3.1 e posteriores. A segunda versão peças windows vertical ou horizontalmente, dependendo do valor da `nType` parâmetro.  
  
### <a name="example"></a>Exemplo  
 Veja o exemplo de [CMDIFrameWnd::MDICascade](#mdicascade).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)   
 [Exemplo MFC SNAPVW](../../visual-cpp-samples.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)


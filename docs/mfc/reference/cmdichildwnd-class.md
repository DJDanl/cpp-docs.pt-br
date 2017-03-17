---
title: Classe CMDIChildWnd | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMDIChildWnd
- AFXWIN/CMDIChildWnd
- AFXWIN/CMDIChildWnd::CMDIChildWnd
- AFXWIN/CMDIChildWnd::Create
- AFXWIN/CMDIChildWnd::GetMDIFrame
- AFXWIN/CMDIChildWnd::MDIActivate
- AFXWIN/CMDIChildWnd::MDIDestroy
- AFXWIN/CMDIChildWnd::MDIMaximize
- AFXWIN/CMDIChildWnd::MDIRestore
- AFXWIN/CMDIChildWnd::SetHandles
dev_langs:
- C++
helpviewer_keywords:
- MDI [C++], child windows
- windows [C++], MDI
- CMDIChildWnd class
- child windows, CMDIChildWnd class
ms.assetid: 6d07f5d4-9a3e-4723-9fa5-e65bb669fdd5
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 240af1fe5f3afa4cdb7d4d585dc74cc4836799cc
ms.lasthandoff: 02/25/2017

---
# <a name="cmdichildwnd-class"></a>Classe CMDIChildWnd
Fornece a funcionalidade de um Windows várias janelas de filho MDI (interface) do documento, juntamente com os membros para gerenciar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMDIChildWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIChildWnd::CMDIChildWnd](#cmdichildwnd)|Constrói um objeto `CMDIChildWnd`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIChildWnd::Create](#create)|Cria a janela filho MDI do Windows associada a `CMDIChildWnd` objeto.|  
|[CMDIChildWnd::GetMDIFrame](#getmdiframe)|Retorna o pai de quadro MDI da janela do cliente MDI.|  
|[CMDIChildWnd::MDIActivate](#mdiactivate)|Ativa esta janela de filho MDI.|  
|[CMDIChildWnd::MDIDestroy](#mdidestroy)|Destrói esta janela de filho MDI.|  
|[CMDIChildWnd::MDIMaximize](#mdimaximize)|Maximiza a essa janela de filho MDI.|  
|[CMDIChildWnd::MDIRestore](#mdirestore)|Restaura esta janela de filho MDI do tamanho maximizado ou minimizado.|  
|[CMDIChildWnd::SetHandles](#sethandles)|Define os identificadores de recursos de menu e acelerador.|  
  
## <a name="remarks"></a>Comentários  
 Uma janela de filho MDI parece muito com uma janela de quadro típica, exceto que a janela filho MDI aparece dentro de uma janela de quadro MDI em vez de na área de trabalho. Uma janela de filho MDI não tem uma barra de menus do seu próprio, mas em vez disso, compartilha o menu da janela de quadro MDI. O framework altera automaticamente o menu de quadro MDI para representar a janela ativa do filho MDI.  
  
 Para criar uma janela de filho MDI úteis para seu aplicativo, derive uma classe de `CMDIChildWnd`. Adicione variáveis de membro para a classe derivada para armazenar dados específicos do aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.  
  
 Há três maneiras de criar uma janela de filho MDI:  
  
-   Construir diretamente usando **criar**.  
  
-   Construir diretamente usando `LoadFrame`.  
  
-   Indiretamente construí-la por meio de um modelo de documento.  
  
 Antes de chamar **criar** ou `LoadFrame`, você deve construir o objeto de janela de quadro na pilha usando o C++ **novo** operador. Antes de chamar **criar** você também pode registrar uma classe de janela com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe do quadro.  
  
 Use o **criar** função de membro para passar parâmetros de criação do quadro imediatos como argumentos.  
  
 `LoadFrame`requer menos argumentos que **criar**e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessível por `LoadFrame`, todos esses recursos devem ter o mesmo ID de recurso (por exemplo, **IDR_MAINFRAME**).  
  
 Quando um `CMDIChildWnd` objeto contém documentos e exibições, são criadas indiretamente pelo framework em vez de diretamente pelo programador. O `CDocTemplate` objeto orquestra a criação do quadro, a criação de modos de exibição de conteúdo e a conexão dos modos de exibição para o documento apropriado. Os parâmetros do `CDocTemplate` construtor especificar o `CRuntimeClass` das três classes envolvidas (documento, frame e exibição). Um `CRuntimeClass` objeto é usado pelo framework para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o comando novo arquivo ou MDI janela nova).  
  
 Uma classe de janela com moldura derivada de `CMDIChildWnd` deve ser declarado com `DECLARE_DYNCREATE` para que os itens acima `RUNTIME_CLASS` mecanismo funcione corretamente.  
  
 O `CMDIChildWnd` classe herda muito a implementação padrão de `CFrameWnd`. Para obter uma lista detalhada desses recursos, consulte o [CFrameWnd](../../mfc/reference/cframewnd-class.md) descrição da classe. O `CMDIChildWnd` classe tem os seguintes recursos adicionais:  
  
-   Em conjunto com o `CMultiDocTemplate` classe, vários `CMDIChildWnd` objetos do mesmo modelo de documento compartilham o mesmo menu, economizar recursos de sistema do Windows.  
  
-   O menu da janela filho MDI ativo no momento substitui totalmente o menu da janela de quadro MDI e a legenda da janela filho MDI ativa no momento é adicionada à legenda da janela de quadro MDI. Para obter mais exemplos de funções de janela filho MDI que são implementados em conjunto com uma janela de quadro MDI, consulte o `CMDIFrameWnd` descrição da classe.  
  
 Não use o C++ **excluir** operador para destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto C++ quando a janela for destruída. Quando o usuário fechar a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CMDIChildWnd`, consulte [janelas com moldura](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMDIChildWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cmdichildwnd"></a>CMDIChildWnd::CMDIChildWnd  
 Chamada para construir uma `CMDIChildWnd` objeto.  
  
```  
CMDIChildWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar **criar** para criar a janela visível.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMDIChildWnd::Create](#create).  
  
##  <a name="create"></a>CMDIChildWnd::Create  
 Chame essa função de membro para criar uma janela de filho MDI do Windows e anexá-lo a `CMDIChildWnd` objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszClassName,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,  
    const RECT& rect = rectDefault,  
    CMDIFrameWnd* pParentWnd = NULL,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClassName`  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura). O nome da classe pode ser qualquer nome registrado com o [AfxRegisterWndClass](http://msdn.microsoft.com/library/62c7d4b1-7a29-4abb-86f7-dec541659db0) função global. Deve ser **nulo** para um padrão `CMDIChildWnd`.  
  
 `lpszWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que representa o nome da janela. Usado como texto da barra de título.  
  
 `dwStyle`  
 Especifica a janela [estilos](../../mfc/reference/window-styles.md) atributos. O **WS_CHILD** estilo é necessário.  
  
 `rect`  
 Contém o tamanho e a posição da janela. O `rectDefault` valor permite ao Windows especificar o tamanho e a posição do novo `CMDIChildWnd`.  
  
 `pParentWnd`  
 Especifica o pai da janela. Se **nulo**, a janela principal do aplicativo é usada.  
  
 `pContext`  
 Especifica um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Esse parâmetro pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A janela de quadro filho MDI ativa pode determinar a legenda da janela pai do quadro. Este recurso está desabilitado, desativando o **FWS_ADDTOTITLE** bit de estilo da janela filho do quadro.  
  
 O framework chama essa função de membro em resposta a um comando de usuário para criar uma janela filho e a estrutura usa a `pContext` parâmetro para se conectar corretamente a janela filho para o aplicativo. Quando você chama **criar**, `pContext` podem ser **nulo**.  
  
### <a name="example"></a>Exemplo  
 Exemplo 1:  
  
 [!code-cpp[NVC_MFCWindowing&#7;](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_1.cpp)]  
  
### <a name="example"></a>Exemplo  
 Exemplo 2:  
  
 [!code-cpp[NVC_MFCWindowing n º&8;](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_2.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing n º&9;](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_3.cpp)]  
  
##  <a name="getmdiframe"></a>CMDIChildWnd::GetMDIFrame  
 Chame essa função para retornar o quadro MDI pai.  
  
```  
CMDIFrameWnd* GetMDIFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela de quadro MDI pai.  
  
### <a name="remarks"></a>Comentários  
 O quadro retornado é dois pais removidos o `CMDIChildWnd` e é o pai da janela do tipo **MDICLIENT** que gerencia o `CMDIChildWnd` objeto. Chamar o [GetParent](../../mfc/reference/cwnd-class.md#getparent) a função de membro para retornar o `CMDIChildWnd` do objeto imediato **MDICLIENT** pai como um temporário `CWnd` ponteiro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMDIFrameWnd::MDISetMenu](../../mfc/reference/cmdiframewnd-class.md#mdisetmenu).  
  
##  <a name="mdiactivate"></a>CMDIChildWnd::MDIActivate  
 Chame essa função de membro para ativar uma janela de filho MDI independentemente da janela de quadro MDI.  
  
```  
void MDIActivate();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o quadro for ativo, a janela filho que foi ativada pela última vez também será ativada.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMDIFrameWnd::GetWindowMenuPopup](../../mfc/reference/cmdiframewnd-class.md#getwindowmenupopup).  
  
##  <a name="mdidestroy"></a>CMDIChildWnd::MDIDestroy  
 Chame essa função de membro para destruir uma janela filho MDI.  
  
```  
void MDIDestroy();
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro remove o título da janela filho da janela de quadro e desativa a janela filho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&10;](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_4.cpp)]  
  
##  <a name="mdimaximize"></a>CMDIChildWnd::MDIMaximize  
 Chame essa função de membro para maximizar uma janela filho MDI.  
  
```  
void MDIMaximize();
```  
  
### <a name="remarks"></a>Comentários  
 Quando uma janela filho é maximizada, Windows redimensiona para tornar sua área cliente preencher a área de cliente da janela do quadro. Windows coloca menu controle da janela filho na barra de menus do quadro para que o usuário possa restaurar ou feche a janela filho e adiciona o título da janela filho para o título da janela de quadro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing n º&11;](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_5.cpp)]  
  
##  <a name="mdirestore"></a>CMDIChildWnd::MDIRestore  
 Chame essa função de membro para restaurar uma janela de filho MDI de tamanho maximizado ou minimizado.  
  
```  
void MDIRestore();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#12;](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_6.cpp)]  
  
##  <a name="sethandles"></a>CMDIChildWnd::SetHandles  
 Define os identificadores de recursos de menu e acelerador.  
  
```  
void SetHandles(
    HMENU hMenu,  
    HACCEL hAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hMenu`  
 O identificador de um recurso do menu.  
  
 `hAccel`  
 O identificador de um recurso de aceleração.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir os recursos de menu e accelerator usados pelo objeto de janela filho MDI.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)   
 [Exemplo MFC SNAPVW](../../visual-cpp-samples.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)


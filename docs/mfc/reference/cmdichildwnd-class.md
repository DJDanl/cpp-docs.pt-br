---
title: Classe CMDIChildWnd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CMDIChildWnd [MFC], CMDIChildWnd
- CMDIChildWnd [MFC], Create
- CMDIChildWnd [MFC], GetMDIFrame
- CMDIChildWnd [MFC], MDIActivate
- CMDIChildWnd [MFC], MDIDestroy
- CMDIChildWnd [MFC], MDIMaximize
- CMDIChildWnd [MFC], MDIRestore
- CMDIChildWnd [MFC], SetHandles
ms.assetid: 6d07f5d4-9a3e-4723-9fa5-e65bb669fdd5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fe649a3ca8ef0fb5e0091136fc9160ac89c248a1
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37338656"
---
# <a name="cmdichildwnd-class"></a>Classe CMDIChildWnd
Fornece a funcionalidade de um Windows vários janela de filho de MDI (interface MDI) do documento, juntamente com os membros para gerenciar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMDIChildWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIChildWnd::CMDIChildWnd](#cmdichildwnd)|Constrói um objeto `CMDIChildWnd`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDIChildWnd::Create](#create)|Cria a janela filho MDI do Windows associada com o `CMDIChildWnd` objeto.|  
|[CMDIChildWnd::GetMDIFrame](#getmdiframe)|Retorna o pai de quadro MDI da janela de cliente do MDI.|  
|[CMDIChildWnd::MDIActivate](#mdiactivate)|Ativa esta janela filho da MDI.|  
|[CMDIChildWnd::MDIDestroy](#mdidestroy)|Destrói a essa janela filho da MDI.|  
|[CMDIChildWnd::MDIMaximize](#mdimaximize)|Maximiza a essa janela filho da MDI.|  
|[CMDIChildWnd::MDIRestore](#mdirestore)|Restaura esta janela filho da MDI de tamanho minimizado ou maximizado.|  
|[CMDIChildWnd::SetHandles](#sethandles)|Define os identificadores para os recursos de menu e acelerador.|  
  
## <a name="remarks"></a>Comentários  
 Uma janela filho MDI se parece muito com uma janela de quadro típicas, exceto que a janela filho MDI aparece dentro de uma janela de quadro MDI em vez de na área de trabalho. Uma janela filho MDI não tem uma barra de menus própria, mas em vez disso, compartilha o menu da janela de quadro MDI. O framework altera automaticamente o menu de quadro MDI para representar a janela filho da MDI ativa no momento.  
  
 Para criar uma janela de filho MDI úteis para seu aplicativo, derive uma classe de `CMDIChildWnd`. Adicione variáveis de membro à classe derivada para armazenar dados específicos ao seu aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.  
  
 Há três maneiras de construir uma janela filho MDI:  
  
-   Construir diretamente usando `Create`.  
  
-   Construir diretamente usando `LoadFrame`.  
  
-   Indiretamente construí-lo por meio de um modelo de documento.  
  
 Antes de chamar `Create` ou `LoadFrame`, você deve construir o objeto de janela do quadro na pilha usando o C++ **novos** operador. Antes de chamar `Create` você também pode registrar uma classe de janela com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe para o quadro.  
  
 Use o `Create` a função de membro para passar parâmetros de criação do quadro imediatos como argumentos.  
  
 `LoadFrame` requer menos argumentos que `Create`e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessível por `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, IDR_MAINFRAME).  
  
 Quando um `CMDIChildWnd` objeto contém documentos e exibições, são criadas indiretamente pelo framework em vez de diretamente pelo programador. O `CDocTemplate` objeto orquestra a criação de quadro, a criação dos modos de exibição que contém e a conexão dos modos de exibição para o documento apropriado. Os parâmetros do `CDocTemplate` construtor especifique o `CRuntimeClass` das três classes envolvidas (documento, quadro e exibição). Um `CRuntimeClass` objeto é usado pelo framework para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o comando novo arquivo ou o comando novo de janela MDI).  
  
 Uma classe de janela com moldura derivada de `CMDIChildWnd` deve ser declarado com DECLARE_DYNCREATE para que o mecanismo RUNTIME_CLASS acima funcione corretamente.  
  
 O `CMDIChildWnd` classe herda grande parte da sua implementação do padrão de `CFrameWnd`. Para obter uma lista detalhada desses recursos, consulte a [CFrameWnd](../../mfc/reference/cframewnd-class.md) descrição de classe. O `CMDIChildWnd` classe tem os seguintes recursos adicionais:  
  
-   Em conjunto com o `CMultiDocTemplate` classe, vários `CMDIChildWnd` objetos do mesmo modelo de documento compartilham o mesmo menu, economizar recursos de sistema do Windows.  
  
-   O menu da janela filho MDI ativo no momento inteiramente substitui o menu da janela de quadro MDI e, em seguida, a legenda da janela filho MDI ativa no momento é adicionada à legenda da janela de quadro MDI. Para obter mais exemplos de funções da janela filho MDI que são implementados em conjunto com uma janela de quadro MDI, consulte o `CMDIFrameWnd` descrição de classe.  
  
 Não use o C++ **excluir** operador para destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto de C++, quando a janela for destruída. Quando o usuário fechar a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CMDIChildWnd`, consulte [quadro Windows](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMDIChildWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cmdichildwnd"></a>  CMDIChildWnd::CMDIChildWnd  
 Chamada para construir um `CMDIChildWnd` objeto.  
  
```  
CMDIChildWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar `Create` para criar a janela visível.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMDIChildWnd::Create](#create).  
  
##  <a name="create"></a>  CMDIChildWnd::Create  
 Chame essa função de membro para criar uma janela filho MDI do Windows e anexá-lo para o `CMDIChildWnd` objeto.  
  
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
 *lpszClassName*  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura). O nome de classe pode ser qualquer nome registrado com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global. Deve ser NULL para um padrão `CMDIChildWnd`.  
  
 *lpszWindowName*  
 Aponta para uma cadeia de caracteres com terminação nula que representa o nome da janela. Usado como o texto da barra de título.  
  
 *dwStyle*  
 Especifica a janela [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) atributos. O estilo WS_CHILD é necessário.  
  
 *Rect*  
 Contém o tamanho e posição da janela. O `rectDefault` valor permite que o Windows especificar o tamanho e a posição do novo `CMDIChildWnd`.  
  
 *pParentWnd*  
 Especifica o pai da janela. Se for NULL, a janela principal do aplicativo é usada.  
  
 *pContext*  
 Especifica um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Esse parâmetro pode ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A janela de quadro filho MDI ativa no momento pode determinar a legenda da janela do quadro pai. Este recurso está desabilitado, desativando o bit de estilo FWS_ADDTOTITLE da janela de quadro filho.  
  
 O framework chama essa função de membro em resposta a um comando de usuário para criar uma janela filho e a estrutura usa a *pContext* parâmetro conectem corretamente a janela filho para o aplicativo. Quando você chama `Create`, *pContext* pode ser NULL.  
  
### <a name="example"></a>Exemplo  
 Exemplo 1:  
  
 [!code-cpp[NVC_MFCWindowing#7](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_1.cpp)]  
  
### <a name="example"></a>Exemplo  
 Exemplo 2:  
  
 [!code-cpp[NVC_MFCWindowing#8](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_2.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing#9](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_3.cpp)]  
  
##  <a name="getmdiframe"></a>  CMDIChildWnd::GetMDIFrame  
 Chame essa função para retornar o quadro do MDI pai.  
  
```  
CMDIFrameWnd* GetMDIFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela de quadro MDI pai.  
  
### <a name="remarks"></a>Comentários  
 O quadro retornado é dois pais retirados a `CMDIChildWnd` e é o pai da janela do tipo MDICLIENT que gerencia o `CMDIChildWnd` objeto. Chame o [GetParent](../../mfc/reference/cwnd-class.md#getparent) função de membro para retornar o `CMDIChildWnd` pai imediato de MDICLIENT do objeto como um temporário `CWnd` ponteiro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMDIFrameWnd::MDISetMenu](../../mfc/reference/cmdiframewnd-class.md#mdisetmenu).  
  
##  <a name="mdiactivate"></a>  CMDIChildWnd::MDIActivate  
 Chame essa função de membro para ativar uma janela filho da MDI independentemente da janela do quadro MDI.  
  
```  
void MDIActivate();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o quadro for ativo, a janela filho que foi ativada pela última vez também será ativada.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMDIFrameWnd::GetWindowMenuPopup](../../mfc/reference/cmdiframewnd-class.md#getwindowmenupopup).  
  
##  <a name="mdidestroy"></a>  CMDIChildWnd::MDIDestroy  
 Chame essa função de membro para destruir uma janela filho MDI.  
  
```  
void MDIDestroy();
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro remove o título da janela filho da janela de quadro e desativa a janela filho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#10](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_4.cpp)]  
  
##  <a name="mdimaximize"></a>  CMDIChildWnd::MDIMaximize  
 Chame essa função de membro para maximizar a uma janela filho MDI.  
  
```  
void MDIMaximize();
```  
  
### <a name="remarks"></a>Comentários  
 Quando uma janela filho é maximizada, Windows-lo para tornar sua área de cliente a preencher a área de cliente da janela do quadro é redimensionado. Windows coloca o menu de controle da janela filho na barra de menus do quadro para que o usuário possa restaurar ou feche a janela filho e adiciona o título da janela filho para o título da janela do quadro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#11](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_5.cpp)]  
  
##  <a name="mdirestore"></a>  CMDIChildWnd::MDIRestore  
 Chame essa função de membro para restaurar uma janela filho MDI do tamanho minimizado ou maximizado.  
  
```  
void MDIRestore();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#12](../../mfc/reference/codesnippet/cpp/cmdichildwnd-class_6.cpp)]  
  
##  <a name="sethandles"></a>  CMDIChildWnd::SetHandles  
 Define os identificadores para os recursos de menu e acelerador.  
  
```  
void SetHandles(
    HMENU hMenu,  
    HACCEL hAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMenu*  
 O identificador de um recurso de menu.  
  
 *hAccel*  
 O identificador de um recurso de acelerador.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir os recursos de menu e accelerator usados pelo objeto de janela filho MDI.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)   
 [Exemplo MFC SNAPVW](../../visual-cpp-samples.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)

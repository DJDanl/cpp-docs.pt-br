---
title: Classe CMiniFrameWnd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMiniFrameWnd
- AFXWIN/CMiniFrameWnd
- AFXWIN/CMiniFrameWnd::CMiniFrameWnd
- AFXWIN/CMiniFrameWnd::Create
- AFXWIN/CMiniFrameWnd::CreateEx
dev_langs: C++
helpviewer_keywords:
- CMiniFrameWnd [MFC], CMiniFrameWnd
- CMiniFrameWnd [MFC], Create
- CMiniFrameWnd [MFC], CreateEx
ms.assetid: b8f534ed-0532-4d8e-9657-5595cf677749
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 75fe37703e9956c8272226d33a1bb169c23ea916
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cminiframewnd-class"></a>Classe CMiniFrameWnd
Representa uma janela do quadro de meia altura geralmente Vista em torno de flutuando barras de ferramentas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMiniFrameWnd : public CFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMiniFrameWnd::CMiniFrameWnd](#cminiframewnd)|Constrói um objeto `CMiniFrameWnd`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMiniFrameWnd::Create](#create)|Cria um `CMiniFrameWnd` objeto após a construção.|  
|[CMiniFrameWnd::CreateEx](#createex)|Cria um `CMiniFrameWnd` objeto (com opções adicionais) após a construção.|  
  
## <a name="remarks"></a>Comentários  
 Essas janelas com minise moldura comportam como janelas com moldura normal, exceto que eles não têm botões minimizar/maximizar ou menus e você só precisa único clique no menu do sistema para descartá-los.  
  
 Para usar um `CMiniFrameWnd` de objeto, primeiro defina o objeto. Em seguida, chame o [criar](#create) função de membro para exibir a janela do mini quadro.  
  
 Para obter mais informações sobre como usar `CMiniFrameWnd` objetos, consulte o artigo [encaixe e barras de ferramentas flutuantes](../../mfc/docking-and-floating-toolbars.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMiniFrameWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cminiframewnd"></a>CMiniFrameWnd::CMiniFrameWnd  
 Constrói um `CMiniFrameWnd` do objeto, mas não criar a janela.  
  
```  
CMiniFrameWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Para criar a janela, chame [CMiniFrameWnd::Create](#create).  
  
##  <a name="create"></a>CMiniFrameWnd::Create  
 Cria a janela do mini-quadro Windows e anexa-o para o `CMiniFrameWnd` objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpClassName,  
    LPCTSTR lpWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd = NULL,  
    UINT nID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpClassName`  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função. Se **nulo**, a classe de janela será registrada para você pela estrutura. MFC fornece a classe padrão, os seguintes atributos e estilos:  
  
-   Conjuntos de bit de estilo **CS_DBLCLKS**, que envia duas vezes em mensagens para o procedimento de janela quando o usuário clica duas vezes o mouse.  
  
-   Conjuntos de bits de estilo **CS_HREDRAW** e **CS_VREDRAW**, que direcionam o conteúdo da área do cliente seja redesenhado quando a janela de tamanho é alterado.  
  
-   Define o cursor de classe com o padrão do Windows **IDC_ARROW**.  
  
-   Define o pincel do plano de fundo de classe **nulo**, portanto, a janela não apagará seu plano de fundo.  
  
-   Define o ícone de classe para o ícone do logotipo do Windows padrão, o sinalizador balançando.  
  
-   Define a janela para o tamanho padrão e a posição, conforme indicado pelo Windows.  
  
 `lpWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome da janela.  
  
 `dwStyle`  
 Especifica os atributos de estilo de janela. Eles podem incluir estilos de janela padrão e um ou mais dos seguintes estilos especiais:  
  
- **MFS_MOVEFRAME** permite que a janela do quadro simplificado a ser movido, basta clicar em qualquer borda da janela, não apenas a legenda.  
  
- **MFS_4THICKFRAME** desabilita o redimensionamento de janela do quadro simplificado.  
  
- **MFS_SYNCACTIVE** sincroniza a ativação da janela do quadro simplificado para a ativação de sua janela pai.  
  
- **MFS_THICKFRAME** permite que a janela do quadro simplificado ser dimensionados pequena de permitir que o conteúdo da área do cliente.  
  
- **MFS_BLOCKSYSMENU** desabilita o acesso ao menu do sistema e o menu de controle e converte-os em parte da legenda (barra de título).  
  
 Consulte [CWnd::Create](../../mfc/reference/cwnd-class.md#create) para obter uma descrição dos valores de estilo de janela possíveis. É a combinação de típica usada para janelas de mini-quadro **WS_POPUP &#124; WS_CAPTION &#124; WS_SYSMENU**.  
  
 `rect`  
 Um `RECT` estrutura especificando as dimensões desejadas da janela.  
  
 `pParentWnd`  
 Aponta para a janela pai. Use **nulo** para janelas de nível superior.  
  
 `nID`  
 Se a janela do quadro mini é criada como uma janela filho, esse é o identificador do controle filho; Caso contrário, 0.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 **Criar** inicializa o nome da classe da janela e o nome da janela e registra os valores padrão para seu estilo e pai.  
  
##  <a name="createex"></a>CMiniFrameWnd::CreateEx  
 Cria um objeto `CMiniFrameWnd`.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    LPCTSTR lpClassName,  
    LPCTSTR lpWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd = NULL,  
    UINT nID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Especifica o estilo estendido do `CMiniFrameWnd` que está sendo criado. Aplicar qualquer um do [estendidos estilos de janela](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) à janela.  
  
 `lpClassName`  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura). O nome da classe pode ser qualquer nome registrado com global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função ou qualquer um dos nomes predefinidos de classe de controle. Ele não deve ser **nulo**.  
  
 `lpWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome da janela.  
  
 `dwStyle`  
 Especifica os atributos de estilo de janela. Consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CWnd::Create](../../mfc/reference/cwnd-class.md#create) para obter uma descrição dos valores possíveis.  
  
 `rect`  
 O tamanho e posição da janela, em coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai.  
  
 `nID`  
 O identificador da janela filho.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O `CreateEx` parâmetros especificam o **WNDCLASS**, estilo de janela e posição inicial (opcionalmente) e o tamanho da janela. `CreateEx`também especifica a janela pai (se houver) e ID.  
  
 Quando `CreateEx` executa o Windows envia o [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo), [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate) mensagens na janela.  
  
 Para estender a manipulação de mensagem padrão, derive uma classe de `CMiniFrameWnd`, adicione um mapa de mensagem para a nova classe e fornecer funções de membro para as mensagens acima. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para uma nova classe.  
  
 Substituir mais **na***mensagem* adicionar mais funcionalidade a sua classe derivada de manipuladores de mensagens.  
  
 Se o **WS_VISIBLE** estilo for fornecido, o Windows envia a janela de todas as mensagens necessárias para ativar e mostrar a janela. Se o estilo da janela especifica uma barra de título, o título da janela apontada pelo `lpszWindowName` parâmetro é exibido na barra de título.  
  
 O `dwStyle` parâmetro pode ser qualquer combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
 Não há suporte para as janelas de ferramentas de paleta de estilo antigas. O estilo antigo, que não tem um botão "X" Fechar, tinha suporte durante a execução de um aplicativo MFC em versões anteriores do Windows, mas não há suporte para o Visual C++ .NET. Somente o novo `WS_EX_TOOLWINDOW` estilo agora tem suporte; para obter uma descrição desse estilo, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)

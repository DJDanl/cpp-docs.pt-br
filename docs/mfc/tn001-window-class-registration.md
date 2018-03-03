---
title: 'TN001: Registro da classe de janela | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.registration
dev_langs:
- C++
helpviewer_keywords:
- TN001
- WNDCLASS [MFC]
- AfxRegisterClass function
ms.assetid: 1abf678e-f220-4606-85e0-03df32f64c54
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f4560905660ea80524c3e26bf14a803a2bc74344
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn001-window-class-registration"></a>TN001: registro da classe Window
Esta anotação descreve as rotinas MFC que registrar especiais [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576)es necessárias pelo Microsoft Windows. Específico `WNDCLASS` atributos usados pelo MFC e Windows são discutidos.  
  
## <a name="the-problem"></a>O problema  
 Os atributos de uma [CWnd](../mfc/reference/cwnd-class.md) do objeto, como um `HWND` tratar no Windows, são armazenadas em dois locais: o objeto de janela e `WNDCLASS`. O nome do `WNDCLASS` é transmitido como funções de criação da janela geral [CWnd::Create](../mfc/reference/cwnd-class.md#create) e [CFrameWnd::Create](../mfc/reference/cframewnd-class.md#create) no `lpszClassName` parâmetro.  
  
 Isso `WNDCLASS` devem ser registrados por meio de quatro formas:  
  
-   Implicitamente, usando um MFC fornecido `WNDCLASS`.  
  
-   Implicitamente por subclasses de um controle do Windows (ou algum outro controle).  
  
-   Explicitamente chamando o MFC [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass) ou [AfxRegisterClass](../mfc/reference/application-information-and-management.md#afxregisterclass).  
  
-   Explicitamente chamando a rotina de Windows [RegisterClass](http://msdn.microsoft.com/library/windows/desktop/ms633586).  
  
## <a name="wndclass-fields"></a>Campos WNDCLASS  
 O `WNDCLASS` estrutura consiste em vários campos que descrevem uma classe de janela. A tabela a seguir mostra os campos e especifica como eles são usados em um aplicativo MFC:  
  
|Campo|Descrição|  
|-----------|-----------------|  
|`lpfnWndProc`|procedimento de janela, deve ser um`AfxWndProc`|  
|`cbClsExtra`|não usado (deve ser zero)|  
|`cbWndExtra`|não usado (deve ser zero)|  
|`hInstance`|preenchida automaticamente com [AfxGetInstanceHandle](../mfc/reference/application-information-and-management.md#afxgetinstancehandle)|  
|`hIcon`|ícone de janelas com moldura, consulte abaixo|  
|`hCursor`|o cursor para quando o mouse estiver sobre janela, consulte abaixo|  
|`hbrBackground`|cor do plano de fundo, consulte abaixo|  
|`lpszMenuName`|não usado (deve ser NULL)|  
|`lpszClassName`|nome de classe, consulte abaixo|  
  
## <a name="provided-wndclasses"></a>Fornecido WNDCLASSes  
 Versões anteriores do MFC (antes do MFC 4.0), fornecida várias classes de janela predefinidas. Essas classes de janela já não são fornecidos por padrão. Os aplicativos devem usar `AfxRegisterWndClass` com os parâmetros apropriados.  
  
 Se o aplicativo fornece um recurso com a ID de recurso especificado (por exemplo, AFX_IDI_STD_FRAME), MFC usará esse recurso. Caso contrário, ele usará o recurso de padrão. Para o ícone, será usado o ícone de aplicativo padrão e para o cursor, o cursor de seta padrão é usado.  
  
 Aplicativos MDI com tipos de documento único de suporte a dois ícones: um ícone do aplicativo principal, o outro ícone para ícone de documento/MDIChild windows. Para vários tipos de documento com ícones diferentes, você deve registrar adicionais `WNDCLASS`es ou use o [CFrameWnd::LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) função.  
  
 `CFrameWnd::LoadFrame`registrará um `WNDCLASS` usando a ID de ícone que você especificar como o primeiro parâmetro e os atributos padrão a seguir:  
  
-   classe de estilo: CS_DBLCLKS &#124; CS_HREDRAW &#124; CS_VREDRAW;  
  
-   ícone AFX_IDI_STD_FRAME  
  
-   cursor de seta  
  
-   Cor de plano de fundo COLOR_WINDOW  
  
 Os valores de cor de plano de fundo e o cursor para o [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) não são usados desde a área do cliente a `CMDIFrameWnd` está completamente coberta pelo **MDICLIENT** janela. Microsoft não incentive subclassificação o **MDICLIENT** janela para usar as cores padrão e os tipos de cursor quando possível.  
  
## <a name="subclassing-and-superclassing-controls"></a>Controles de Superclassing e subclassificação  
 Se você subclasse ou superclasse uma janela de controle (por exemplo, [CButton](../mfc/reference/cbutton-class.md)), em seguida, sua classe obtém automaticamente o `WNDCLASS` atributos fornecida na implementação do Windows desse controle.  
  
## <a name="the-afxregisterwndclass-function"></a>A função AfxRegisterWndClass  
 MFC fornece uma função auxiliar para registrar uma classe de janela. Dado um conjunto de atributos (estilo de classe de janela, cursor, Pincel de plano de fundo e ícone), um nome sintético é gerado e a classe de janela resultante é registrada. Por exemplo,  
  
```  
const char* AfxRegisterWndClass(UINT nClassStyle,
    HCURSOR hCursor,
    HBRUSH hbrBackground,
    HICON hIcon);
```  
  
 Essa função retorna uma cadeia de caracteres temporária do nome da classe de janela registrados gerados. Para obter mais informações sobre essa função, consulte [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass).  
  
 A cadeia de caracteres retornada é um ponteiro temporário para um buffer de cadeia de caracteres estática. Ele é válido até a próxima chamada para `AfxRegisterWndClass`. Se você quiser manter essa cadeia de caracteres ao redor, armazená-lo em uma [CString](../atl-mfc-shared/using-cstring.md) variável, como neste exemplo:  
  
```  
CString strWndClass = AfxRegisterWndClass(CS_DBLCLK, ...);

...  
CWnd* pWnd = new CWnd;  
pWnd->Create(strWndClass, ...);

...  
```  
  
 `AfxRegisterWndClass`lançará uma [CResourceException](../mfc/reference/cresourceexception-class.md) se a classe de janela Falha ao registrar (devido a parâmetros incorretos ou falta de memória do Windows).  
  
## <a name="the-registerclass-and-afxregisterclass-functions"></a>As funções de AfxRegisterClass e RegisterClass  
 Se você quiser fazer qualquer coisa mais sofisticadas do que `AfxRegisterWndClass` fornece, você pode chamar a API do Windows `RegisterClass` ou a função MFC `AfxRegisterClass`. O `CWnd`, [CFrameWnd](../mfc/reference/cframewnd-class.md) e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) `Create` funções usam um `lpszClassName` nome de cadeia de caracteres para a classe de janela como o primeiro parâmetro. Você pode usar qualquer nome de classe de janela registrado, independentemente do método usado para registrá-lo.  
  
 É importante usar `AfxRegisterClass` (ou `AfxRegisterWndClass`) em uma DLL no Win32. Win32 não automaticamente o registro classes registrados por uma DLL, portanto você deve explicitamente cancelar registro classes quando a DLL é finalizada. Usando `AfxRegisterClass` em vez de `RegisterClass` isso é tratado automaticamente para você. `AfxRegisterClass`mantém uma lista de classes exclusivos registrados por sua DLL e automaticamente cancelará-los quando a DLL é encerrado. Quando você usa `RegisterClass` em uma DLL, você deve garantir que todas as classes são não registradas quando a DLL é finalizada (em seu [DllMain](http://msdn.microsoft.com/library/windows/desktop/ms682583) função). Falha ao fazer isso pode causar `RegisterClass` falhe inesperadamente quando outro aplicativo cliente tenta usar a DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)


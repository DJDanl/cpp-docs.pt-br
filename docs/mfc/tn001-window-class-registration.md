---
title: 'TN001: Registro da classe de janela | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.registration
dev_langs:
- C++
helpviewer_keywords:
- TN001
- WNDCLASS [MFC]
- AfxRegisterClass function
ms.assetid: 1abf678e-f220-4606-85e0-03df32f64c54
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 03a9af119cd9730edaa4196958691c70d711fce4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221149"
---
# <a name="tn001-window-class-registration"></a>TN001: registro da classe Window
Essa observação descreve as rotinas MFC que registrar especiais [WNDCLASS](https://msdn.microsoft.com/library/windows/desktop/ms633576)es necessárias para o Microsoft Windows. Específico `WNDCLASS` atributos usados pelo MFC e Windows são discutidos.  
  
## <a name="the-problem"></a>O problema  
 Os atributos de uma [CWnd](../mfc/reference/cwnd-class.md) do objeto, como um `HWND` tratar no Windows, são armazenados em dois lugares: o objeto de janela e o `WNDCLASS`. O nome da `WNDCLASS` é passado para funções de criação da janela geral, como [CWnd::Create](../mfc/reference/cwnd-class.md#create) e [CFrameWnd::Create](../mfc/reference/cframewnd-class.md#create) no *lpszClassName* parâmetro.  
  
 Isso `WNDCLASS` deve ser registrado por meio de um dos quatro meios:  
  
-   Implicitamente, usando um MFC fornecido `WNDCLASS`.  
  
-   Implicitamente por subclasses de um controle do Windows (ou algum outro controle).  
  
-   Explicitamente chamando o MFC [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass) ou [AfxRegisterClass](../mfc/reference/application-information-and-management.md#afxregisterclass).  
  
-   Explicitamente, chamando a rotina do Windows [RegisterClass](https://msdn.microsoft.com/library/windows/desktop/ms633586).  
  
## <a name="wndclass-fields"></a>Campos WNDCLASS  
 O `WNDCLASS` estrutura consiste em vários campos que descrevem uma classe de janela. A tabela a seguir mostra os campos e especifica como eles são usados em um aplicativo MFC:  
  
|Campo|Descrição|  
|-----------|-----------------|  
|*lpfnWndProc*|procedimento de janela, deve ser um `AfxWndProc`|  
|*cbClsExtra*|não usado (deve ser zero)|  
|*cbWndExtra*|não usado (deve ser zero)|  
|*hInstance*|preenchida automaticamente com [AfxGetInstanceHandle](../mfc/reference/application-information-and-management.md#afxgetinstancehandle)|  
|*hIcon*|ícone para janelas de quadro, veja a seguir|  
|*hCursor*|o cursor para quando o mouse está sobre a janela, consulte abaixo|  
|*hbrBackground*|cor do plano de fundo, consulte abaixo|  
|*lpszMenuName*|não usado (deve ser nulo)|  
|*lpszClassName*|nome da classe, consulte abaixo|  
  
## <a name="provided-wndclasses"></a>Fornecido WNDCLASSes  
 Versões anteriores do MFC (MFC 4.0), fornecidas várias classes de janela predefinidas. Essas classes de janela não são mais fornecidas por padrão. Os aplicativos devem usar `AfxRegisterWndClass` com os parâmetros apropriados.  
  
 Se o aplicativo fornece um recurso com a ID de recurso especificado (por exemplo, AFX_IDI_STD_FRAME), MFC usa esse recurso. Caso contrário, ele usará o recurso padrão. Para o ícone, o ícone do aplicativo padrão é usado e o cursor, o cursor de seta padrão é usado.  
  
 Suportam a dois ícones de aplicativos MDI com tipos de documento único: um ícone para o aplicativo principal, outro ícone para o windows de documento/MDIChild icônico. Para vários tipos de documentos com ícones diferentes, você deve registrar adicionais `WNDCLASS`es ou usar o [CFrameWnd::LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) função.  
  
 `CFrameWnd::LoadFrame` registrará um `WNDCLASS` usando a ID de ícone que você especificar como o primeiro parâmetro e os atributos padrão a seguir:  
  
-   estilo da classe: CS_DBLCLKS &#124; CS_HREDRAW &#124; CS_VREDRAW;  
  
-   ícone AFX_IDI_STD_FRAME  
  
-   cursor de seta  
  
-   Cor do plano de fundo COLOR_WINDOW  
  
 Os valores de cor do plano de fundo e o cursor para o [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) não são usados desde a área do cliente a `CMDIFrameWnd` está completamente coberta pela **MDICLIENT** janela. Microsoft Incentive a criação de subclasses a **MDICLIENT** janela então usar as cores padrão e os tipos de cursor quando possível.  
  
## <a name="subclassing-and-superclassing-controls"></a>A criação de subclasses e controles de Superclassing  
 Se você subclasse ou um Windows da superclasse de controle (por exemplo, [CButton](../mfc/reference/cbutton-class.md)) e em seguida, sua classe obtém automaticamente a `WNDCLASS` atributos fornecidos na implementação do Windows desse controle.  
  
## <a name="the-afxregisterwndclass-function"></a>A função AfxRegisterWndClass  
 MFC fornece uma função auxiliar para registrar uma classe de janela. Dado um conjunto de atributos (estilo de classe de janela, cursor, Pincel de plano de fundo e ícone), um nome de sintético é gerado e a classe de janela resultante está registrada. Por exemplo,  
  
```  
const char* AfxRegisterWndClass(UINT nClassStyle,
    HCURSOR hCursor,
    HBRUSH hbrBackground,
    HICON hIcon);
```  
  
 Essa função retorna uma cadeia de caracteres temporária do nome da classe de janela registrada gerado. Para obter mais informações sobre essa função, consulte [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass).  
  
 A cadeia de caracteres retornada é um ponteiro temporário para um buffer de cadeia de caracteres estática. Ela é válida até a próxima chamada para `AfxRegisterWndClass`. Se você quiser manter essa cadeia de caracteres ao redor, armazene-o em um [CString](../atl-mfc-shared/using-cstring.md) variável, como neste exemplo:  
  
```  
CString strWndClass = AfxRegisterWndClass(CS_DBLCLK, ...);

...  
CWnd* pWnd = new CWnd;  
pWnd->Create(strWndClass, ...);

...  
```  
  
 `AfxRegisterWndClass` lançará uma [CResourceException](../mfc/reference/cresourceexception-class.md) se a classe de janela Falha ao registrar (devido a parâmetros incorretos, ou falta de memória do Windows).  
  
## <a name="the-registerclass-and-afxregisterclass-functions"></a>A RegisterClass e funções AfxRegisterClass  
 Se você quiser fazer algo mais sofisticado do que `AfxRegisterWndClass` fornece, você pode chamar a API do Windows `RegisterClass` ou a função MFC `AfxRegisterClass`. O `CWnd`, [CFrameWnd](../mfc/reference/cframewnd-class.md) e [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md) `Create` funções usam um *lpszClassName* nome de cadeia de caracteres para a classe de janela como o primeiro parâmetro. Você pode usar qualquer nome de classe de janela registrada, independentemente do método usado para registrá-lo.  
  
 É importante usar `AfxRegisterClass` (ou `AfxRegisterWndClass`) em uma DLL no Win32. Win32 não automaticamente o registro classes registradas por uma DLL, portanto, você deve cancelar o registro explicitamente classes quando a DLL é encerrada. Usando `AfxRegisterClass` em vez de `RegisterClass` isso é manipulado automaticamente para você. `AfxRegisterClass` mantém uma lista de classes exclusivas registrados pelo seu DLL e automaticamente cancelará-los quando a DLL é encerrado. Quando você usa `RegisterClass` em uma DLL, você deve garantir que todas as classes terão o registro canceladas quando a DLL é encerrada (em seu [DllMain](/windows/desktop/Dlls/dllmain) função). Falha ao fazer isso pode causar `RegisterClass` falhem inesperadamente quando outro aplicativo cliente tenta usar a sua DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)


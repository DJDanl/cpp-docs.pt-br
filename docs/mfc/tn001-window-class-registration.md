---
title: "TN001: registro da classe Window | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.registration"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função AfxRegisterClass"
  - "TN001"
  - "WNDCLASS"
ms.assetid: 1abf678e-f220-4606-85e0-03df32f64c54
caps.latest.revision: 16
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN001: registro da classe Window
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve as rotinas de MFC que registra o especiais [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576)es necessário pelo Microsoft Windows.  Os atributos específicos de `WNDCLASS` MFC usados pelo e as janelas são discutidos.  
  
## O problema  
 Os atributos de [CWnd](../Topic/CWnd%20Class.md) objeto, como um identificador de `HWND` no windows, são armazenados em dois locais: o objeto da janela e o `WNDCLASS`.  O nome de `WNDCLASS` é passado a funções gerais de criação da janela como [CWnd::Create](../Topic/CWnd::Create.md) e [CFrameWnd::Create](../Topic/CFrameWnd::Create.md) no parâmetro de `lpszClassName` .  
  
 Este `WNDCLASS` deve ser registrado em um dos quatro mídia:  
  
-   Usando implicitamente `WNDCLASS`MFC fornecido.  
  
-   Subclassing implicitamente um controle do windows \(ou qualquer outro controle\).  
  
-   Chamar explicitamente o MFC [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md) ou [AfxRegisterClass](../Topic/AfxRegisterClass.md).  
  
-   Chamando explicitamente a rotina [RegisterClass](http://msdn.microsoft.com/library/windows/desktop/ms633586)do windows.  
  
## Campos de WNDCLASS  
 A estrutura de `WNDCLASS` consiste em vários campos que descrevem uma classe da janela.  A tabela a seguir mostra os campos e especificar como elas são usadas em um aplicativo de MFC:  
  
|Campo|Descrição|  
|-----------|---------------|  
|`lpfnWndProc`|o processo de janela, deve ser `AfxWndProc`|  
|`cbClsExtra`|não usado \(deve ser zero\)|  
|`cbWndExtra`|não usado \(deve ser zero\)|  
|`hInstance`|preenchida automaticamente com [AfxGetInstanceHandle](../Topic/AfxGetInstanceHandle.md)|  
|`hIcon`|o ícone do windows do quadro, consulte abaixo|  
|`hCursor`|o cursor para quando o mouse for na janela, consulta abaixo|  
|`hbrBackground`|a cor do plano de fundo, consulte abaixo|  
|`lpszMenuName`|não deve ser usado \(NULL\)|  
|`lpszClassName`|o nome da classe, consulte abaixo|  
  
## WNDCLASSes fornecido  
 Versões anteriores \(MFC antes de MFC 4,0\), desde que vários a janela predefinida classifica.  Essas classes da janela não são fornecidas por padrão.  Os aplicativos devem usar `AfxRegisterWndClass` com os parâmetros apropriados.  
  
 Se o aplicativo fornece um recurso com a ID do recurso especificado \(por exemplo, AFX\_IDI\_STD\_FRAME MFC\), o usará esse recurso.  Se não usará o recurso padrão.  Para o ícone, o ícone de aplicativo padrão é usado, e para o cursor, o cursor padrão de seta é usado.  
  
 Dois ícones oferecem suporte a aplicativos MDI com tipos de valor único documento: um ícone para o aplicativo principal, o outro ícone do documento\/windows icônicos de MDIChild.  Para vários tipos de documento com ícones diferentes, você deverá registrar `WNDCLASS`adicional es ou usar a função de [CFrameWnd::LoadFrame](../Topic/CFrameWnd::LoadFrame.md) .  
  
 `CFrameWnd::LoadFrame` registrará `WNDCLASS` usando a ID do ícone que você especifica como o primeiro parâmetro e os seguintes atributos padrão:  
  
-   estilo da classe: CS\_DBLCLKS &#124; CS\_HREDRAW &#124; CS\_VREDRAW;  
  
-   ícone AFX\_IDI\_STD\_FRAME  
  
-   cursor de seta  
  
-   Cor do plano de fundo de COLOR\_WINDOW  
  
 Os valores para a cor do plano de fundo e o cursor para [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) não são usados desde que a área de cliente de `CMDIFrameWnd` é completamente coberta pela janela de **MDICLIENT** .  A Microsoft não incentiva subclassing a janela de **MDICLIENT** portanto use as cores e os tipos de cursor padrão quando possível.  
  
## Controles de Subclassing e de Superclassing  
 Se você subclasse ou superclass controla o windows \(por exemplo, [CButton](../mfc/reference/cbutton-class.md)\) na sua classe automaticamente obtém os atributos de `WNDCLASS` fornecidos na implementação do windows desse controle.  
  
## A função de AfxRegisterWndClass  
 MFC O fornece uma função auxiliar para registrar uma classe da janela.  Dado um conjunto de atributos \(estilo da classe da janela, cursor, escova em segundo plano, e o ícone\), um nome sintético é gerado, e a classe resultante da janela é registrada.  Por exemplo,  
  
```  
const char* AfxRegisterWndClass(UINT nClassStyle, HCURSOR hCursor, HBRUSH hbrBackground, HICON hIcon);  
```  
  
 Esta função retorna uma cadeia de caracteres temporária do nome da classe registrado gerado da janela.  Para obter mais informações sobre essa função, consulte [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md).  
  
 A cadeia de caracteres retornado é um ponteiro para um buffer temporário estática da cadeia de caracteres.  É válido até a próxima chamada a `AfxRegisterWndClass`.  Se você quiser manter em relação a essa cadeia de caracteres, armazená\-las em uma variável de [CString](../atl-mfc-shared/using-cstring.md) , como neste exemplo:  
  
```  
CString strWndClass = AfxRegisterWndClass(CS_DBLCLK, ...);  
...  
CWnd* pWnd = new CWnd;  
pWnd->Create(strWndClass, ...);  
...  
```  
  
 `AfxRegisterWndClass` lançará [CResourceException](../mfc/reference/cresourceexception-class.md) se a classe da janela não registrou \(devido aos parâmetros inválidos, ou fora de memória do windows\).  
  
## As funções de RegisterClass e de AfxRegisterClass  
 Se você quiser fazer nada mais sofisticado do que o `AfxRegisterWndClass` fornece, você pode chamar a API do windows `RegisterClass` ou a função `AfxRegisterClass`MFC.  `CWnd`, [CFrameWnd](../mfc/reference/cframewnd-class.md) e funções de [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)`Create` têm um nome de cadeia de caracteres de `lpszClassName` para a classe da janela como o primeiro parâmetro.  Você pode usar qualquer nome de classe registrado na janela, independentemente do método usado para registrar o.  
  
 É importante usar `AfxRegisterClass` \(ou `AfxRegisterWndClass`\) em uma DLL no Win32.  O Win32 não faz automaticamente as classes o registro registradas por uma DLL, assim você deve cancelar explicitamente classes da DLL é encerrado.  Usando `AfxRegisterClass` em vez de `RegisterClass` isso é tratado automaticamente para você.  `AfxRegisterClass` mantém uma lista de classes exclusivas registradas pelo DLL e cancelará eles automaticamente quando o DLL termina.  Quando você usa `RegisterClass` em uma DLL, você deve assegurar que todas as classes é registrado quando o é encerrado DLL \(na função de [DllMain](http://msdn.microsoft.com/library/windows/desktop/ms682583) \).  A falha isso pode fazer com que `RegisterClass` falhar inesperadamente quando outro aplicativo cliente tenta usar o DLL.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
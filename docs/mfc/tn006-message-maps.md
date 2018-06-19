---
title: 'TN006: Mapas de mensagem | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.messages.maps
dev_langs:
- C++
helpviewer_keywords:
- ON_UPDATE_COMMAND_UI macro [MFC]
- ON_NOTIFY_RANGE macro [MFC]
- ON_COMMAND macro [MFC]
- ON_CONTROL_RANGE macro [MFC]
- ON_REGISTERED_MESSAGE macro [MFC]
- ON_NOTIFY message [MFC]
- ON_COMMAND_RANGE_EX macro [MFC]
- ON_MESSAGE macro [MFC]
- Windows messages [MFC], message maps
- ON_COMMAND_RANGE macro [MFC]
- TN006
- ON_CONTROL macro [MFC]
- ON_COMMAND_EX macro [MFC]
- message maps [MFC], Windows messaging
ms.assetid: af4b6794-4b40-4f1e-ad41-603c3b7409bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 160b88a7069ac9a5851c0f472f756d694e59874e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33384691"
---
# <a name="tn006-message-maps"></a>TN006: mapas de mensagem
Esta anotação descreve o recurso de mapa de mensagem do MFC.  
  
## <a name="the-problem"></a>O problema  
 Microsoft Windows implementa funções virtuais nas classes de janela que usam seu recurso de mensagens. Devido ao grande número de mensagens envolvidos, fornecer uma função virtual separada para cada mensagem do Windows cria uma vtable extremamente grande.  
  
 Como o número de mensagens definidas pelo sistema do Windows é alterado ao longo do tempo e mapas de mensagem porque os aplicativos podem definir suas próprias mensagens do Windows, fornece um nível de erro que impede que as alterações de interface quebrar o código existente.  
  
## <a name="overview"></a>Visão geral  
 MFC fornece uma alternativa para a instrução switch que foi usada em programas baseados no Windows tradicionais para lidar com mensagens enviadas para uma janela. Um mapeamento de mensagens para métodos pode ser definido para que quando uma mensagem é recebida por uma janela, o método apropriado é chamado automaticamente. Esse recurso de mapa de mensagem foi projetado para ser semelhante a funções virtuais, mas tem benefícios adicionais não são possíveis com funções virtuais do C++.  
  
## <a name="defining-a-message-map"></a>Definindo um mapa de mensagem  
 O [DECLARE_MESSAGE_MAP](reference/message-map-macros-mfc.md#declare_message_map) macro declara três membros de uma classe.  
  
-   Uma matriz privada de `AFX_MSGMAP_ENTRY` entradas chamadas `_messageEntries`.  
  
-   Um protegido `AFX_MSGMAP` estrutura chamada `messageMap` que aponta para o `_messageEntries` matriz.  
  
-   Protegido de uma função virtual chamada `GetMessageMap` que retorna o endereço de `messageMap`.  
  
 Esta macro deve ser colocada na declaração de qualquer classe usando mapas de mensagem. Por convenção, é o final da declaração de classe. Por exemplo:  
  
```  
class CMyWnd : public CMyParentWndClass  
{ *// my stuff...  
 
protected: *//{{AFX_MSG(CMyWnd)  
    afx_msg void OnPaint();
*//}}AFX_MSG  
 
    DECLARE_MESSAGE_MAP() 
};  
```  
  
 Este é o formato gerado pelo AppWizard e ClassWizard quando eles criarem novas classes. O / / {{e / /}} parênteses são necessários para ClassWizard.  
  
 Tabela do mapa de mensagem é definida por meio de um conjunto de macros que se expande para entradas do mapa de mensagem. Uma tabela começa com um [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) chamada de macro, que define a classe que é tratada por este mapa de mensagem e a classe pai ao qual as mensagens sem tratamento são passadas. A tabela termina com a [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map) chamada de macro.  
  
 Entre essas chamadas de duas macro é uma entrada para cada mensagem tratada por esse mapa de mensagem. Todas as mensagens padrão do Windows tem uma macro do formulário ON_WM_*MESSAGE_NAME* que gera uma entrada para essa mensagem.  
  
 Uma assinatura de função padrão foi definida para descompactar os parâmetros de cada mensagem do Windows e fornecer a segurança de tipo. Essas assinaturas podem ser encontradas no arquivo Afxwin.h na declaração de [CWnd](../mfc/reference/cwnd-class.md). Cada um é marcado com a palavra-chave `afx_msg` para facilitar sua identificação.  
  
> [!NOTE]
>  ClassWizard requer que você use o `afx_msg` palavra-chave em suas declarações de manipulador de mapa de mensagem.  
  
 Essas assinaturas de função foram derivadas usando uma convenção simple. O nome da função sempre começa com `"On`". Isso é seguido pelo nome da mensagem de Windows com o "WM de _" removido e a primeira letra de cada palavra em letras maiusculas. A ordem dos parâmetros é `wParam` seguido por `LOWORD`(`lParam`), em seguida, `HIWORD`(`lParam`). Parâmetros não usados não são passados. Os identificadores que são quebrados pelo classes MFC são convertidos em ponteiros para os objetos apropriados do MFC. O exemplo a seguir mostra como tratar o `WM_PAINT` mensagem e fazer com que o `CMyWnd::OnPaint` função a ser chamada:  
  
```  
BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass) *//{{AFX_MSG_MAP(CMyWnd)  
    ON_WM_PAINT() *//}}AFX_MSG_MAP  
END_MESSAGE_MAP()  
```  
  
 A tabela de mapa de mensagem deve ser definida fora do escopo de qualquer definição de classe ou função. Não devem ser colocado em um bloco de extern "C".  
  
> [!NOTE]
>  ClassWizard modificará as entradas de mapa de mensagem que ocorrem entre o / / {{e / /}} colchete de comentário.  
  
## <a name="user-defined-windows-messages"></a>Mensagens do Windows definidos pelo usuário  
 Mensagens definidas pelo usuário podem ser incluídas em um mapa de mensagem usando o [ON_MESSAGE](reference/message-map-macros-mfc.md#on_message) macro. Esta macro aceita um número de mensagem e um método do formulário:  
  
' ' * / / dentro da declaração de classe  
    afx_msg OnMyMessage(WPARAM wParam, LPARAM lParam) LRESULT;

 
 #<a name="define-wmmymessage-wmuser--100"></a>Definir WM_MYMESSAGE (WM_USER + 100)  
 
BEGIN_MESSAGE_MAP (CMyWnd, CMyParentWndClass)  
    ON_MESSAGE (WM_MYMESSAGE, OnMyMessage)  
END_MESSAGE_MAP()  
```  
  
 In this example, we establish a handler for a custom message that has a Windows message ID derived from the standard `WM_USER` base for user-defined messages. The following example shows how to call this handler:  
  
```  
CWnd * pWnd =...;  
pWnd -> SendMessage(WM_MYMESSAGE);
```  
  
 The range of user-defined messages that use this approach must be in the range `WM_USER` to 0x7fff.  
  
> [!NOTE]
>  ClassWizard does not support entering `ON_MESSAGE` handler routines from the ClassWizard user interface. You must manually enter them from the Visual C++ editor. ClassWizard will parse these entries and let you browse them just like any other message-map entries.  
  
## Registered Windows Messages  
 The [RegisterWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms644947) function is used to define a new window message that is guaranteed to be unique throughout the system. The macro `ON_REGISTERED_MESSAGE` is used to handle these messages. This macro accepts a name of a `UINT NEAR` variable that contains the registered windows message ID. For example  
  
```  
classe CMyWnd: CMyParentWndClass pública  
{  
public:  
    CMyWnd();

 *//{{AFX_MSG(CMyWnd)  
    afx_msg OnFind(WPARAM wParam, LPARAM lParam) LRESULT; * //}}AFX_MSG  
 
    DECLARE_MESSAGE_MAP() 
};  
 
UINT estático próximo WM_FIND = RegisterWindowMessage("COMMDLG_FIND");

 
*//{{AFX_MSG_MAP(CMyWnd) BEGIN_MESSAGE_MAP (CMyWnd, CMyParentWndClass)  
    ON_REGISTERED_MESSAGE (WM_FIND, OnFind) * //}}AFX_MSG_MAP  
END_MESSAGE_MAP()  
```  
  
 The registered Windows message ID variable (WM_FIND in this example) must be a `NEAR` variable because of the way `ON_REGISTERED_MESSAGE` is implemented.  
  
 The range of user-defined messages that use this approach will be in the range 0xC000 to 0xFFFF.  
  
> [!NOTE]
>  ClassWizard does not support entering `ON_REGISTERED_MESSAGE` handler routines from the ClassWizard user interface. You must manually enter them from the text editor. ClassWizard will parse these entries and let you browse them just like any other message-map entries.  
  
## Command Messages  
 Command messages from menus and accelerators are handled in message maps with the `ON_COMMAND` macro. This macro accepts a command ID and a method. Only the specific `WM_COMMAND` message that has a `wParam` equal to the specified command ID is handled by the method specified in the message-map entry. Command handler member functions take no parameters and return `void`. The macro has the following form:  
  
```  
ON_COMMAND (id, memberFxn)  
```  
  
 Command update messages are routed through the same mechanism, but use the `ON_UPDATE_COMMAND_UI` macro instead. Command update handler member functions take a single parameter, a pointer to a [CCmdUI](../mfc/reference/ccmdui-class.md) object, and return `void`. The macro has the form  
  
```  
ON_UPDATE_COMMAND_UI (id, memberFxn)  
```  
  
 Advanced users can use the `ON_COMMAND_EX` macro, which is an extended form of command message handlers. The macro provides a superset of the `ON_COMMAND` functionality. Extended command-handler member functions take a single parameter, a `UINT` that contains the command ID, and return a `BOOL`. The return value should be `TRUE` to indicate that the command has been handled. Otherwise routing will continue to other command target objects.  
  
 Examples of these forms:  
  
-   Inside Resource.h (usually generated by Visual C++)  
  
 ```  
 #<a name="define----idmycmd------100"></a>Definir ID_MYCMD 100  
 #<a name="define----idcomplex----101"></a>Definir ID_COMPLEX 101  
 ```  
  
-   Inside the class declaration  
  
 ```  
    afx_msg void OnMyCommand();
afx_msg void OnUpdateMyCommand (CCmdUI * pCmdUI);

    afx_msg BOOL OnComplexCommand(UINT nID);

 ```  
  
-   Inside the message map definition  
  
 ```  
    ON_COMMAND(ID_MYCMD,
    OnMyCommand)  
    ON_UPDATE_COMMAND_UI(ID_MYCMD,
    OnUpdateMyCommand)  
    ON_COMMAND_EX(ID_MYCMD,
    OnComplexCommand)  
 ```  
  
-   In the implementation file  
  
 ```  
    void CMyClass::OnMyCommand()  
 {* / / tratar o comando  
 }  
 
    void CMyClass::OnUpdateMyCommand(CCmdUI* pCmdUI)  
 {* / / definir o estado da interface do usuário com pCmdUI  
 }  
 
    BOOL CMyClass::OnComplexCommand(UINT nID)  
 {* / / tratar o comando  
    retornar TRUE;  
 }  
 ```  
  
 Advanced users can handle a range of commands by using a single command handler: [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range) or `ON_COMMAND_RANGE_EX`. See the product documentation for more information about these macros.  
  
> [!NOTE]
>  ClassWizard supports creating `ON_COMMAND` and `ON_UPDATE_COMMAND_UI` handlers, but it does not support creating `ON_COMMAND_EX` or `ON_COMMAND_RANGE` handlers. However, Class Wizard will parse and let you browse all four command handler variants.  
  
## Control Notification Messages  
 Messages that are sent from child controls to a window have an extra bit of information in their message map entry: the control's ID. The message handler specified in a message map entry is called only if the following conditions are true:  
  
-   The control notification code (high word of `lParam`), such as BN_CLICKED, matches the notification code specified in the message-map entry.  
  
-   The control ID (`wParam`) matches the control ID specified in the message-map entry.  
  
 Custom control notification messages may use the [ON_CONTROL](reference/message-map-macros-mfc.md#on_control) macro to define a message map entry with a custom notification code. This macro has the form  
  
```  
ON_CONTROL (wNotificationCode, id, memberFxn)  
```  
  
 For advanced usage [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range) can be used to handle a specific control notification from a range of controls with the same handler.  
  
> [!NOTE]
>  ClassWizard does not support creating an `ON_CONTROL` or `ON_CONTROL_RANGE` handler in the user interface. You must manually enter them with the text editor. ClassWizard will parse these entries and let you browse them just like any other message map entries.  
  
 The Windows Common Controls use the more powerful [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) for complex control notifications. This version of MFC has direct support for this new message by using the `ON_NOTIFY` and `ON_NOTIFY_RANGE` macros. See the product documentation for more information about these macros.  
  
## See Also  
 [Technical Notes by Number](../mfc/technical-notes-by-number.md)   
 [Technical Notes by Category](../mfc/technical-notes-by-category.md)


---
title: "TN006: mapas de mensagem | Microsoft Docs"
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
  - "vc.messages.maps"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mapas de mensagem [C++], Mensagens do Windows"
  - "Macro ON_COMMAND"
  - "Macro ON_COMMAND_EX"
  - "Macro ON_COMMAND_RANGE"
  - "Macro ON_COMMAND_RANGE_EX"
  - "Macro ON_CONTROL"
  - "Macro ON_CONTROL_RANGE"
  - "Macro ON_MESSAGE"
  - "ON_NOTIFY (mensagem)"
  - "Macro ON_NOTIFY_RANGE"
  - "Macro ON_REGISTERED_MESSAGE"
  - "Macro ON_UPDATE_COMMAND_UI"
  - "TN006"
  - "mensagens do Windows [C++], mapas de mensagem"
ms.assetid: af4b6794-4b40-4f1e-ad41-603c3b7409bb
caps.latest.revision: 16
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN006: mapas de mensagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve a facilidade da mensagem MFC.  
  
## O problema  
 Microsoft Windows implementa funções virtuais nas classes da janela que usam a facilidade da mensagem.  Devido a grande número de mensagens envolvidas, forneça uma função virtual separada para cada mensagem do windows cria um vtable proibitiva grande.  
  
 Como o número de mensagens definidas pelo sistema do windows foi alterada com o passar do tempo, e porque os aplicativos podem definir suas próprias mensagens do windows, mapas de mensagem fornecem um nível de nomes indiretos que impede que as alterações de interface interrompam o código existente.  
  
## Visão Geral  
 MFC O fornece uma alternativa à instrução de alternância que foi usada em programas baseados no Windows tradicionais para tratar mensagens enviadas para uma janela.  Um mapeamento das mensagens para os métodos pode ser definido de modo que quando uma mensagem é recebida por uma janela do, o método é chamado apropriado automaticamente.  Essa facilidade retornadas o mapa é criada para ser semelhante às funções virtuais mas tem os benefícios adicionais não possíveis com funções virtuais C\+\+.  
  
## Definindo um mapa de mensagem  
 A macro de [DECLARE\_MESSAGE\_MAP](../Topic/DECLARE_MESSAGE_MAP.md) declara três membros para uma classe.  
  
-   Uma matriz privada de entradas de `AFX_MSGMAP_ENTRY` chamou `_messageEntries`.  
  
-   Uma estrutura protegidos de `AFX_MSGMAP` chamou `messageMap` que aponta para `_messageEntries` a matriz.  
  
-   Uma função protegida virtual chamado `GetMessageMap` que retorna o endereço de `messageMap`.  
  
 Esta macro deve ser colocado na declaração de qualquer classe que usa mapas da mensagem.  Por convenção, estiver no final de declaração da classe.  Por exemplo:  
  
```  
class CMyWnd : public CMyParentWndClass  
{  
    // my stuff...  
  
protected:  
    //{{AFX_MSG(CMyWnd)  
    afx_msg void OnPaint();  
    //}}AFX_MSG  
  
    DECLARE_MESSAGE_MAP()  
};  
```  
  
 Este é o formato gerado por AppWizard e ClassWizard quando cria novas classes.  Os colchetes de \/\/{} \/\/{e} são necessários para ClassWizard.  
  
 A tabela da mensagem é definida usando um conjunto de macros que se expandem em entradas da mensagem.  Início de uma tabela com uma chamada macro de [BEGIN\_MESSAGE\_MAP](../Topic/BEGIN_MESSAGE_MAP.md) , que define a classe que é tratada por esse mapa da mensagem e pela classe pai ao qual as mensagens não manipulados são transmitidas.  A tabela termina com a chamada macro de [END\_MESSAGE\_MAP](../Topic/END_MESSAGE_MAP.md) .  
  
 Entre esses dois chamadas macro é uma entrada para cada mensagem que será tratada por esse mapa da mensagem.  Cada mensagem padrão do windows tem uma macro do formulário ON\_WM\_*MESSAGE\_NAME* que gerencia uma entrada para essa mensagem.  
  
 Uma assinatura da função padrão foi definida desempacotando os parâmetros de cada mensagem do windows e fornecendo a segurança de tipo.  Essas assinaturas podem ser localizadas no arquivo Afxwin.h na declaração de [CWnd](../Topic/CWnd%20Class.md).  Cada um é marcado com a palavra\-chave `afx_msg` para a identificação fácil.  
  
> [!NOTE]
>  ClassWizard requer que você use a palavra\-chave de `afx_msg` em suas declarações de manipulador da mensagem.  
  
 Essas assinaturas da função foram derivadas usando uma convenção simples.  O nome da função sempre inicia com `"On`”.  Isso é seguido pelo nome da mensagem do windows com “WM\_” removido e a primeira letra de cada palavra colocar em maiúscula.  Ordem dos parâmetros é `wParam` seguido por `LOWORD`\(`lParam`\) em `HIWORD`\(`lParam`\).  Os parâmetros não usado não são passados.  Todos os identificadores que estão envolvidas por classes de MFC são convertidas em ponteiros para os objetos apropriados MFC.  O exemplo a seguir mostra como lidar com a mensagem de `WM_PAINT` e fazer com que a função de `CMyWnd::OnPaint` a ser chamada:  
  
```  
BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)  
    //{{AFX_MSG_MAP(CMyWnd)  
    ON_WM_PAINT()  
    //}}AFX_MSG_MAP  
END_MESSAGE_MAP()  
```  
  
 A tabela da mensagem deve ser definida fora do escopo da definição da função ou da classe.  Não deve ser colocada em um bloco extern de C “2.0”.  
  
> [!NOTE]
>  ClassWizard modificará as entradas da mensagem que ocorrem entre o colchete de fechamento de \/\/{} \/\/{e}.  
  
## Mensagens definidas pelo usuário do windows  
 As mensagens definidas pelo usuário podem ser incluídas em um mapa de mensagem usando a macro de [ON\_MESSAGE](../Topic/ON_MESSAGE.md) .  Esta macro aceita um número de mensagem e um método do formulário:  
  
```  
    // inside the class declaration  
    afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);  
  
    #define WM_MYMESSAGE (WM_USER + 100)  
  
BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)  
    ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)  
END_MESSAGE_MAP()  
```  
  
 Neste exemplo, é estabelecemos um manipulador para uma mensagem personalizada que tem um ID de mensagem do windows derivado da base de `WM_USER` padrão para mensagens definidas pelo usuário.  O exemplo a seguir mostra como chamar esse manipulador:  
  
```  
CWnd* pWnd = ...;  
pWnd->SendMessage(WM_MYMESSAGE);  
```  
  
 O intervalo das mensagens definidas pelo usuário que usam essa abordagem deve estar no intervalo `WM_USER` a 0x7fff.  
  
> [!NOTE]
>  ClassWizard não oferece suporte a inserir rotinas do manipulador de `ON_MESSAGE` da interface de usuário de ClassWizard.  Você deve digitar manualmente no publicador do Visual C\+\+.  ClassWizard analisará essas entradas e permitirá procurar\-las exatamente como todas as outras entradas retornadas mapa.  
  
## Mensagens registradas do windows  
 A função de [RegisterWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms644947) é usada para definir uma mensagem de nova janela que é garantida para ser exclusivo em todo o sistema.  A macro `ON_REGISTERED_MESSAGE` é usado para tratar essas mensagens.  Esta macro aceita um nome de uma variável de `UINT NEAR` que contém a ID de mensagem registrada do windows  Por exemplo  
  
```  
class CMyWnd : public CMyParentWndClass  
{  
public:  
    CMyWnd();  
  
    //{{AFX_MSG(CMyWnd)  
    afx_msg LRESULT OnFind(WPARAM wParam, LPARAM lParam);  
    //}}AFX_MSG  
  
    DECLARE_MESSAGE_MAP()  
};  
  
static UINT NEAR WM_FIND = RegisterWindowMessage("COMMDLG_FIND");  
  
BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)  
    //{{AFX_MSG_MAP(CMyWnd)  
    ON_REGISTERED_MESSAGE(WM_FIND, OnFind)  
    //}}AFX_MSG_MAP  
END_MESSAGE_MAP()  
```  
  
 A variável registrado da ID de mensagem do windows \(WM\_FIND neste exemplo\) deve ser uma variável de `NEAR` devido à maneira como `ON_REGISTERED_MESSAGE` é implementado.  
  
 O intervalo das mensagens definidas pelo usuário que usam essa abordagem será no intervalo 0xC000 a 0xFFFF.  
  
> [!NOTE]
>  ClassWizard não oferece suporte a inserir rotinas do manipulador de `ON_REGISTERED_MESSAGE` da interface de usuário de ClassWizard.  Você deve digitar manualmente no editor de texto.  ClassWizard analisará essas entradas e permitirá procurar\-las exatamente como todas as outras entradas retornadas mapa.  
  
## Mensagens de comando  
 As mensagens do comando nos menus e de aceleradores são tratadas em mapas de mensagem com a macro de `ON_COMMAND` .  Esta macro aceita um ID do comando e um método.  Somente a mensagem específica de `WM_COMMAND` que tem `wParam` igual ao ID especificado do comando é tratada pelo método especificado na entrada retornadas mapa.  As funções de membro do manipulador do comando não têm nenhum parâmetro e `void`de retorno.  A macro tem o seguinte formato:  
  
```  
ON_COMMAND(id, memberFxn)  
```  
  
 As mensagens de atualização de comando são roteadas através do mesmo mecanismo, mas usam a macro de `ON_UPDATE_COMMAND_UI` em vez disso.  As funções de membro do manipulador de atualização do comando têm um único parâmetro, um ponteiro para um objeto de [CCmdUI](../Topic/CCmdUI%20Class.md) , e `void`de retorno.  A macro tem o formato  
  
```  
ON_UPDATE_COMMAND_UI(id, memberFxn)  
```  
  
 Usuários avançados podem usar a macro de `ON_COMMAND_EX` , que é um formulário estendido de manipuladores de mensagem do comando.  A macro fornece um superconjunto da funcionalidade de `ON_COMMAND` .  As funções de membro estendidos de comando\- manipulador têm um único parâmetro, `UINT` que contém a ID do comando, e retornam `BOOL`.  O valor de retorno deve ser `TRUE` para indicar que o comando esteve tratado.  Se o roteamento não continuará a outros objetos de destino do comando.  
  
 Exemplos destes formatos:  
  
-   Resource.h interna \(geralmente gerado pelo Visual C\+\+\)  
  
    ```  
    #define    ID_MYCMD      100  
    #define    ID_COMPLEX    101  
    ```  
  
-   Na declaração de classe  
  
    ```  
    afx_msg void OnMyCommand();  
    afx_msg void OnUpdateMyCommand(CCmdUI* pCmdUI);  
    afx_msg BOOL OnComplexCommand(UINT nID);  
    ```  
  
-   Na definição da mensagem  
  
    ```  
    ON_COMMAND(ID_MYCMD, OnMyCommand)  
    ON_UPDATE_COMMAND_UI(ID_MYCMD, OnUpdateMyCommand)  
    ON_COMMAND_EX(ID_MYCMD, OnComplexCommand)  
    ```  
  
-   No arquivo de implementação  
  
    ```  
    void CMyClass::OnMyCommand()  
    {  
        // handle the command  
    }  
  
    void CMyClass::OnUpdateMyCommand(CCmdUI* pCmdUI)  
    {  
        // set the UI state with pCmdUI  
    }  
  
    BOOL CMyClass::OnComplexCommand(UINT nID)  
    {  
        // handle the command  
        return TRUE;  
    }  
    ```  
  
 Usuários avançados podem tratar um intervalo de comandos usando um manipulador de um único comando: [ON\_COMMAND\_RANGE](../Topic/ON_COMMAND_RANGE.md) ou `ON_COMMAND_RANGE_EX`.  Consulte a documentação do produto para obter mais informações sobre esses macros.  
  
> [!NOTE]
>  ClassWizard oferece suporte à criação de `ON_COMMAND` e de manipuladores de `ON_UPDATE_COMMAND_UI` , mas não da suporte à criação de `ON_COMMAND_EX` ou de manipuladores de `ON_COMMAND_RANGE` .  No entanto, o assistente da classe analisá\-lo\-á analisada e deixá\-l\-á procurar todas as quatro variantes de manipulador de comando.  
  
## Controle notificações  
 As mensagens que são enviadas dos controles filho a uma janela tem um bit adicional de informações na entrada da mensagem: a ID de controle  O manipulador de mensagens especificado em uma entrada da mensagem é chamado apenas se as seguintes condições forem verdadeiras:  
  
-   O código da notificação de controle \(palavras de alta `lParam`\), como BN\_CLICKED, corresponde ao código de notificação especificado na entrada retornadas mapa.  
  
-   A ID de controle \(`wParam`\) corresponde à ID do controle especificado na entrada retornadas mapa.  
  
 As notificações de controle personalizado podem usar a macro de [ON\_CONTROL](../Topic/ON_CONTROL.md) para definir uma entrada da mensagem com um código personalizado de notificação.  Esta macro tem o formato  
  
```  
ON_CONTROL(wNotificationCode, id, memberFxn)  
```  
  
 Para uso avançado [ON\_CONTROL\_RANGE](../Topic/ON_CONTROL_RANGE.md) pode ser usado para tratar uma notificação específica de controle de um intervalo de controles com o mesmo manipulador.  
  
> [!NOTE]
>  ClassWizard não oferece suporte à criação de um manipulador de `ON_CONTROL` ou de `ON_CONTROL_RANGE` na interface do usuário.  Você deve fazer logon com manualmente no editor de texto.  ClassWizard analisará essas entradas e permitirá procurar\-las exatamente como todas as outras entradas do mapa da mensagem.  
  
 Os controles comum do windows usam [WM\_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mais avançada para notificações complexas do controle.  Esta versão MFC tem suporte direto dessa nova mensagem usando as macros de `ON_NOTIFY` e de `ON_NOTIFY_RANGE` .  Consulte a documentação do produto para obter mais informações sobre esses macros.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
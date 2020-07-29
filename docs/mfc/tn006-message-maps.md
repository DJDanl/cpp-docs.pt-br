---
title: 'TN006: mapas de mensagem'
ms.date: 06/25/2018
f1_keywords:
- vc.messages.maps
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
ms.openlocfilehash: 6b387b851f5a76cd0d11957a87e57307d624759e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228525"
---
# <a name="tn006-message-maps"></a>TN006: mapas de mensagem

Esta observação descreve o recurso de mapa de mensagens do MFC.

## <a name="the-problem"></a>O problema

O Microsoft Windows implementa funções virtuais em classes de janela que usam seu recurso de mensagens. Devido ao grande número de mensagens envolvidas, o fornecimento de uma função virtual separada para cada mensagem do Windows criaria um extremamente grande vtable.

Como o número de mensagens do Windows definidas pelo sistema muda ao longo do tempo, e como os aplicativos podem definir suas próprias mensagens do Windows, os mapas de mensagens fornecem um nível de indireção que impede que as alterações de interface quebrem o código existente.

## <a name="overview"></a>Visão geral

O MFC fornece uma alternativa à instrução switch que foi usada em programas tradicionais baseados no Windows para lidar com as mensagens enviadas a uma janela. Um mapeamento de mensagens para métodos pode ser definido para que, quando uma mensagem for recebida por uma janela, o método apropriado seja chamado automaticamente. Esse recurso de mapa de mensagens foi projetado para se assemelhar a funções virtuais, mas tem benefícios adicionais que não são possíveis com as funções virtuais do C++.

## <a name="defining-a-message-map"></a>Definindo um mapa de mensagens

A macro [DECLARE_MESSAGE_MAP](reference/message-map-macros-mfc.md#declare_message_map) declara três membros para uma classe.

- Uma matriz privada de AFX_MSGMAP_ENTRY entradas chamadas *_messageEntries*.

- Uma estrutura de AFX_MSGMAP protegida chamada *messageMap* que aponta para a matriz *_messageEntries* .

- Uma função virtual protegida chamada `GetMessageMap` que retorna o endereço de *messageMap*.

Essa macro deve ser colocada na declaração de qualquer classe usando mapas de mensagem. Por convenção, ele está no final da declaração de classe. Por exemplo:

```cpp
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

Esse é o formato gerado por AppWizard e ClassWizard quando eles criam novas classes. Os colchetes//{{e//}} são necessários para ClassWizard.

A tabela do mapa de mensagens é definida usando um conjunto de macros que se expandem para entradas de mapa de mensagens. Uma tabela começa com uma chamada de macro [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) , que define a classe que é tratada por esse mapa de mensagem e a classe pai para a qual as mensagens não tratadas são passadas. A tabela termina com a chamada de macro [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map) .

Entre essas duas chamadas de macro está uma entrada para cada mensagem a ser tratada por esse mapa de mensagens. Cada mensagem padrão do Windows tem uma macro do formulário ON_WM_*MESSAGE_NAME* que gera uma entrada para essa mensagem.

Uma assinatura de função padrão foi definida para desempacotar os parâmetros de cada mensagem do Windows e fornecer segurança de tipo. Essas assinaturas podem ser encontradas no arquivo Afxwin. h na declaração de [CWnd](../mfc/reference/cwnd-class.md). Cada uma é marcada com a palavra-chave **afx_msg** para facilitar a identificação.

> [!NOTE]
> ClassWizard requer que você use a palavra-chave **afx_msg** em suas declarações do manipulador de mapa de mensagens.

Essas assinaturas de função foram derivadas usando uma convenção simples. O nome da função sempre começa com `"On` ". Isso é seguido pelo nome da mensagem do Windows com o "WM_" removido e a primeira letra de cada palavra em maiúsculas. A ordenação dos parâmetros é *wParam* seguido de `LOWORD` (*lParam*) then `HIWORD` (*lParam*). Os parâmetros não utilizados não são passados. Todos os identificadores encapsulados por classes MFC são convertidos em ponteiros para os objetos apropriados do MFC. O exemplo a seguir mostra como manipular a mensagem de WM_PAINT e fazer com que a `CMyWnd::OnPaint` função seja chamada:

```cpp
BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)
    //{{AFX_MSG_MAP(CMyWnd)
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()
```

A tabela de mapa de mensagens deve ser definida fora do escopo de qualquer função ou definição de classe. Ele não deve ser colocado em um bloco "C" externo.

> [!NOTE]
> ClassWizard modificará as entradas de mapa de mensagem que ocorrem entre o colchete de comentário//{{e//}}.

## <a name="user-defined-windows-messages"></a>Mensagens do Windows definidas pelo usuário

As mensagens definidas pelo usuário podem ser incluídas em um mapa de mensagens usando a macro [ON_MESSAGE](reference/message-map-macros-mfc.md#on_message) . Essa macro aceita um número de mensagem e um método do formulário:

```cpp
    // inside the class declaration
    afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);

    #define WM_MYMESSAGE (WM_USER + 100)

BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)
    ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()
```

Neste exemplo, estabelecemos um manipulador para uma mensagem personalizada que tem uma ID de mensagem do Windows derivada da base de WM_USER padrão para mensagens definidas pelo usuário. O exemplo a seguir mostra como chamar esse manipulador:

```cpp
CWnd* pWnd = ...;
pWnd->SendMessage(WM_MYMESSAGE);
```

O intervalo de mensagens definidas pelo usuário que usam essa abordagem deve estar no intervalo de WM_USER a 0x7FFF.

> [!NOTE]
> ClassWizard não dá suporte à inserção de rotinas do manipulador de ON_MESSAGE da interface do usuário do ClassWizard. Você deve inseri-los manualmente no editor de Visual C++. O ClassWizard analisará essas entradas e permitirá que você as navegue como qualquer outra entrada de mapa de mensagem.

## <a name="registered-windows-messages"></a>Mensagens registradas do Windows

A função [RegisterWindowMessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew) é usada para definir uma nova mensagem de janela que tem a garantia de ser exclusiva em todo o sistema. A macro ON_REGISTERED_MESSAGE é usada para lidar com essas mensagens. Essa macro aceita um nome de uma variável *uint Near* que contém a ID de mensagem do Windows registrada. Por exemplo

```cpp
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

A variável de ID de mensagem do Windows registrada (WM_FIND neste exemplo) deve ser uma variável *Near* devido à maneira como ON_REGISTERED_MESSAGE é implementada.

O intervalo de mensagens definidas pelo usuário que usam essa abordagem estará no intervalo 0xC000 a 0xFFFF.

> [!NOTE]
> ClassWizard não dá suporte à inserção de rotinas do manipulador de ON_REGISTERED_MESSAGE da interface do usuário do ClassWizard. Você deve inseri-los manualmente no editor de texto. O ClassWizard analisará essas entradas e permitirá que você as navegue como qualquer outra entrada de mapa de mensagem.

## <a name="command-messages"></a>Mensagens de comando

As mensagens de comando de menus e aceleradores são manipuladas em mapas de mensagens com a macro ON_COMMAND. Essa macro aceita uma ID de comando e um método. Somente a mensagem de WM_COMMAND específica que tem um *wParam* igual à ID de comando especificada é manipulada pelo método especificado na entrada de mapa de mensagem. As funções de membro do manipulador de comando não usam parâmetros e retornam **`void`** . A macro tem o seguinte formato:

```cpp
ON_COMMAND(id, memberFxn)
```

As mensagens de atualização de comando são roteadas por meio do mesmo mecanismo, mas usam a macro ON_UPDATE_COMMAND_UI em vez disso. As funções de membro do manipulador de atualização de comando usam um único parâmetro, um ponteiro para um objeto [CCmdUI](../mfc/reference/ccmdui-class.md) e retornam **`void`** . A macro tem o formato

```cpp
ON_UPDATE_COMMAND_UI(id, memberFxn)
```

Os usuários avançados podem usar a macro ON_COMMAND_EX, que é uma forma estendida de manipuladores de mensagens de comando. A macro fornece um superconjunto da funcionalidade de ON_COMMAND. As funções de membro de manipulador de comandos estendidas usam um único parâmetro, um **uint** que contém a ID de comando e retornam um **bool**. O valor de retorno deve ser **true** para indicar que o comando foi manipulado. Caso contrário, o roteamento continuará com outros objetos de destino de comando.

Exemplos desses formulários:

- Dentro de Resource. h (geralmente gerado por Visual C++)

    ```cpp
    #define    ID_MYCMD      100
    #define    ID_COMPLEX    101
    ```

- Dentro da declaração de classe

    ```cpp
    afx_msg void OnMyCommand();
    afx_msg void OnUpdateMyCommand(CCmdUI* pCmdUI);
    afx_msg BOOL OnComplexCommand(UINT nID);
    ```

- Dentro da definição do mapa de mensagens

    ```cpp
    ON_COMMAND(ID_MYCMD, OnMyCommand)
    ON_UPDATE_COMMAND_UI(ID_MYCMD, OnUpdateMyCommand)
    ON_COMMAND_EX(ID_MYCMD, OnComplexCommand)
    ```

- No arquivo de implementação

    ```cpp
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

Os usuários avançados podem manipular uma variedade de comandos usando um único manipulador de comando: [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range) ou ON_COMMAND_RANGE_EX. Consulte a documentação do produto para obter mais informações sobre essas macros.

> [!NOTE]
> O ClassWizard dá suporte à criação de manipuladores ON_COMMAND e ON_UPDATE_COMMAND_UI, mas não dá suporte à criação de manipuladores ON_COMMAND_EX ou ON_COMMAND_RANGE. No entanto, o assistente de classe analisará e permitirá que você navegue por todas as quatro variantes do manipulador de comandos.

## <a name="control-notification-messages"></a>Mensagens de notificação de controle

As mensagens enviadas de controles filho para uma janela têm um bit extra de informações em sua entrada de mapa de mensagens: a ID do controle. O manipulador de mensagens especificado em uma entrada de mapa de mensagens será chamado somente se as seguintes condições forem verdadeiras:

- O código de notificação de controle (palavra alta de *lParam*), como BN_CLICKED, corresponde ao código de notificação especificado na entrada de mapa de mensagem.

- A ID de controle (*wParam*) corresponde à ID de controle especificada na entrada de mapa de mensagem.

As mensagens de notificação de controle personalizado podem usar a macro [ON_CONTROL](reference/message-map-macros-mfc.md#on_control) para definir uma entrada de mapa de mensagem com um código de notificação personalizado. Esta macro tem a forma

```cpp
ON_CONTROL(wNotificationCode, id, memberFxn)
```

Para uso avançado [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range) pode ser usado para manipular uma notificação de controle específica de um intervalo de controles com o mesmo manipulador.

> [!NOTE]
> ClassWizard não dá suporte à criação de um manipulador de ON_CONTROL ou ON_CONTROL_RANGE na interface do usuário. Você deve inseri-los manualmente com o editor de texto. O ClassWizard analisará essas entradas e permitirá que você as navegue, assim como qualquer outra entrada de mapa de mensagens.

Os controles comuns do Windows usam o [WM_NOTIFY](/windows/win32/controls/wm-notify) mais poderoso para notificações de controle complexas. Esta versão do MFC tem suporte direto para essa nova mensagem usando as macros ON_NOTIFY e ON_NOTIFY_RANGE. Consulte a documentação do produto para obter mais informações sobre essas macros.

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)

---
title: 'TN006: Mapas de mensagem | Microsoft Docs'
ms.custom: ''
ms.date: 06/25/2018
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
ms.openlocfilehash: 2c4bc820c6b54e055235c1bd29bd55ccfc032c92
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37121670"
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

- Uma matriz privada de entradas AFX_MSGMAP_ENTRY chamado *_messageEntries*.

- Uma estrutura AFX_MSGMAP protegida chamado *messageMap* que aponta para o *_messageEntries* matriz.

- Protegido de uma função virtual chamada `GetMessageMap` que retorna o endereço de *messageMap*.

Esta macro deve ser colocada na declaração de qualquer classe usando mapas de mensagem. Por convenção, é o final da declaração de classe. Por exemplo:

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

Este é o formato gerado pelo AppWizard e ClassWizard quando eles criarem novas classes. O / / {{e / /}} parênteses são necessários para ClassWizard.

Tabela do mapa de mensagem é definida por meio de um conjunto de macros que se expande para entradas do mapa de mensagem. Uma tabela começa com um [BEGIN_MESSAGE_MAP](reference/message-map-macros-mfc.md#begin_message_map) chamada de macro, que define a classe que é tratada por este mapa de mensagem e a classe pai ao qual as mensagens sem tratamento são passadas. A tabela termina com a [END_MESSAGE_MAP](reference/message-map-macros-mfc.md#end_message_map) chamada de macro.

Entre essas chamadas de duas macro é uma entrada para cada mensagem tratada por esse mapa de mensagem. Todas as mensagens padrão do Windows tem uma macro do formulário ON_WM_*MESSAGE_NAME* que gera uma entrada para essa mensagem.

Uma assinatura de função padrão foi definida para descompactar os parâmetros de cada mensagem do Windows e fornecer a segurança de tipo. Essas assinaturas podem ser encontradas no arquivo Afxwin.h na declaração de [CWnd](../mfc/reference/cwnd-class.md). Cada um é marcado com a palavra-chave **afx_msg** para facilitar sua identificação.

> [!NOTE]
> ClassWizard requer que você use o **afx_msg** palavra-chave em suas declarações de manipulador de mapa de mensagem.

 Essas assinaturas de função foram derivadas usando uma convenção simple. O nome da função sempre começa com `"On`". Isso é seguido pelo nome da mensagem de Windows com o "WM de _" removido e a primeira letra de cada palavra em letras maiusculas. A ordem dos parâmetros é *wParam* seguido por `LOWORD`(*lParam*), em seguida, `HIWORD`(*lParam*). Parâmetros não usados não são passados. Os identificadores que são quebrados pelo classes MFC são convertidos em ponteiros para os objetos apropriados do MFC. O exemplo a seguir mostra como manipular a mensagem WM_PAINT e fazer com que o `CMyWnd::OnPaint` função a ser chamada:

```cpp
BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)
    //{{AFX_MSG_MAP(CMyWnd)
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()
```

 A tabela de mapa de mensagem deve ser definida fora do escopo de qualquer definição de classe ou função. Não devem ser colocado em um bloco de extern "C".

> [!NOTE]
> ClassWizard modificará as entradas de mapa de mensagem que ocorrem entre o / / {{e / /}} colchete de comentário.

## <a name="user-defined-windows-messages"></a>Mensagens do Windows definidos pelo usuário

Mensagens definidas pelo usuário podem ser incluídas em um mapa de mensagem usando o [ON_MESSAGE](reference/message-map-macros-mfc.md#on_message) macro. Esta macro aceita um número de mensagem e um método do formulário:

```cpp
    // inside the class declaration
    afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);

    #define WM_MYMESSAGE (WM_USER + 100)

BEGIN_MESSAGE_MAP(CMyWnd, CMyParentWndClass)
    ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()
```

Neste exemplo, estabelecemos um manipulador para uma mensagem personalizada que tem uma ID de mensagem do Windows provenientes de base WM_USER padrão para mensagens definidas pelo usuário. O exemplo a seguir mostra como chamar esse manipulador:

```cpp
CWnd* pWnd = ...;
pWnd->SendMessage(WM_MYMESSAGE);
```

O intervalo de mensagens definidas pelo usuário que usam essa abordagem deve estar no intervalo WM_USER a 0x7fff.

> [!NOTE]
> ClassWizard não oferece suporte a rotinas de manipulador ON_MESSAGE entrando na interface do usuário ClassWizard. Você deve inseri-los manualmente do editor do Visual C++. ClassWizard irá analisar essas entradas e permitem navegá-los assim como quaisquer outras entradas do mapa de mensagem.

## <a name="registered-windows-messages"></a>Mensagens do Windows registrados

O [RegisterWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms644947) função é usada para definir uma nova mensagem de janela é garantida como exclusivo em todo o sistema. A macro ON_REGISTERED_MESSAGE é usada para lidar com essas mensagens. Esta macro aceita um nome de um *UINT próximo* variável que contém a ID de mensagem do windows registrados. Por exemplo

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

A variável de ID da mensagem do Windows registrada (WM_FIND neste exemplo) deve ser um *NEAR* variável por causa da forma ON_REGISTERED_MESSAGE é implementado.

O intervalo de mensagens definidas pelo usuário que usam essa abordagem será no intervalo 0xC000 a 0xFFFF.

> [!NOTE]
> ClassWizard não oferece suporte a rotinas de manipulador ON_REGISTERED_MESSAGE entrando na interface do usuário ClassWizard. Você deve inseri-los manualmente do editor de texto. ClassWizard irá analisar essas entradas e permitem navegá-los assim como quaisquer outras entradas do mapa de mensagem.

## <a name="command-messages"></a>Mensagens de comando

Mensagens de comando de menus e aceleradores são manipuladas em mapas de mensagem com a macro ON_COMMAND. Esta macro aceita uma ID de comando e um método. Somente a mensagem WM_COMMAND específica tem um *wParam* igual para o comando especificado ID é tratado pelo método especificado na entrada do mapa de mensagem. Funções de membro de manipulador de comando não aceitam parâmetros e retornar **void**. A macro tem a seguinte forma:

```cpp
ON_COMMAND(id, memberFxn)
```

Mensagens de atualização de comando são roteadas por meio do mesmo mecanismo, mas usam a macro ON_UPDATE_COMMAND_UI em seu lugar. Funções de membro de manipulador de atualização de comando recebem um único parâmetro, um ponteiro para um [CCmdUI](../mfc/reference/ccmdui-class.md) de objeto e retornar **void**. A macro tem o formato

```cpp
ON_UPDATE_COMMAND_UI(id, memberFxn)
```

Os usuários avançados podem usar a macro ON_COMMAND_EX, que é uma forma estendida de manipuladores de mensagens de comando. A macro fornece um subconjunto da funcionalidade ON_COMMAND. Funções de membro estendido do manipulador de comando usam um único parâmetro, um **UINT** que contém a ID de comando e retornar um **BOOL**. O valor de retorno deve ser **TRUE** para indicar que o comando foi tratado. Caso contrário, o roteamento continuará a outros objetos de destino do comando.

Exemplos dessas formas:

- Resource.h dentro (geralmente, gerado pelo Visual C++)

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

- Dentro da definição de mapa de mensagem

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

 Usuários avançados podem manipular uma variedade de comandos usando um único manipulador de comandos: [ON_COMMAND_RANGE](reference/message-map-macros-mfc.md#on_command_range) ou ON_COMMAND_RANGE_EX. Consulte a documentação do produto para obter mais informações sobre essas macros.

> [!NOTE]
> ClassWizard dá suporte à criação de manipuladores ON_COMMAND e ON_UPDATE_COMMAND_UI, mas não dá suporte a criação de manipuladores ON_COMMAND_EX ou ON_COMMAND_RANGE. No entanto, o Assistente de classe analisará e lhe permitem procurar todas as variantes de manipulador de comando quatro.

## <a name="control-notification-messages"></a>Mensagens de notificação de controle

Mapa de mensagens que são enviadas de controles filho para uma janela tem um extra de bits de informações em sua mensagem de entrada: identificação. do controle O manipulador de mensagens especificado em uma entrada de mapa de mensagem é chamado apenas se as seguintes condições forem verdadeiras:

- O código de notificação de controle (palavra alta de *lParam*), como BN_CLICKED, corresponde ao código de notificação especificado na entrada do mapa de mensagem.

- A ID de controle (*wParam*) corresponde à ID do controle especificada na entrada do mapa de mensagem.

Mensagens de notificação do controle personalizado podem usar o [ON_CONTROL](reference/message-map-macros-mfc.md#on_control) macro para definir uma entrada de mapa de mensagem com um código de notificação personalizada. Esta macro tem o formato

```cpp
ON_CONTROL(wNotificationCode, id, memberFxn)
```

Uso avançado de [ON_CONTROL_RANGE](reference/message-map-macros-mfc.md#on_control_range) pode ser usada para manipular uma notificação de controle específicos de uma variedade de controles com o mesmo manipulador.

> [!NOTE]
> ClassWizard não oferece suporte à criação de um manipulador de ON_CONTROL ou ON_CONTROL_RANGE na interface do usuário. Manualmente, você deve inseri-los com o editor de texto. ClassWizard irá analisar essas entradas e permitem navegá-los assim como quaisquer outras entradas de mapa de mensagem.

Controles comuns do Windows usam mais poderoso [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) para notificações de controle complexo. Esta versão do MFC tem suporte direto para essa nova mensagem usando as macros ON_NOTIFY e ON_NOTIFY_RANGE. Consulte a documentação do produto para obter mais informações sobre essas macros.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)  
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)  

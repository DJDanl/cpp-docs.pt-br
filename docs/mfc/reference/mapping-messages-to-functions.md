---
title: Mapeando mensagens para funções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.mapping.msg.function
dev_langs:
- C++
helpviewer_keywords:
- Windows messages [MFC], adding message handlers
- message maps [MFC], mapping messages to functions
ms.assetid: a7727a62-f638-4b20-b7f5-131f47200d6a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b53175e46cfa858a73b581dfefc78047e96380d6
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50058941"
---
# <a name="mapping-messages-to-functions"></a>Mapeando mensagens para funções

A janela de propriedades permite que você vincule manipuladores de mensagens (funções de membro de classes de interface do usuário do MFC) as mensagens geradas por recursos de seu aplicativo. Eles usam [mapas de mensagens do MFC](../../mfc/messages-and-commands-in-the-framework.md) para criar uma associação.

Quando você usa o modo de exibição de classe para criar uma nova classe derivada de uma das classes do framework, ele automaticamente coloca um completo e funcional arquivos de classe no cabeçalho (. h) e na implementação (. cpp) que você especificar.

> [!NOTE]
>  Para adicionar uma nova classe que não processa mensagens, crie a classe diretamente no editor de texto.

### <a name="to-define-or-remove-a-message-handler-using-the-properties-window"></a>Para definir ou remover um manipulador de mensagens usando a janela Propriedades

1. Em Modo de Exibição de Classe, clique na classe.

1. Na janela Propriedades, clique o **mensagens** botão.

    > [!NOTE]
    >  O **mensagens** botão está disponível quando você seleciona o nome de classe no modo de exibição de classe ou quando você clica dentro da janela de código-fonte.

   Se o projeto tiver um manipulador para uma mensagem, o nome do manipulador é exibido na coluna direita ao lado da mensagem.

1. Se a mensagem não tiver nenhum manipulador, em seguida, clique na célula na coluna à direita na janela Propriedades para exibir o nome sugerido do manipulador de como \<Adicionar >*HandlerName*. (Por exemplo, o manipulador de mensagens WM_TIMER sugere \<Adicionar >`OnTimer`).

1. Clique no nome sugerido para adicionar um código de stub à função.

1. Para editar um manipulador de mensagens, clique duas vezes a mensagem no modo de exibição de classe e editar o código na janela de origem.

Para remover um manipulador de mensagens, clique duas vezes o manipulador na coluna à direita e selecione \<excluir >*HandlerName*. O código da função será comentado.

## <a name="see-also"></a>Consulte também

[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Adicionando manipuladores de eventos a controles de caixa de diálogo](../../windows/adding-event-handlers-for-dialog-box-controls.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)

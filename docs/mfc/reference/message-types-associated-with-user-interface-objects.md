---
title: Tipos associados a objetos de Interface do usuário de mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.uiobject.msgs
dev_langs:
- C++
helpviewer_keywords:
- message types and user interface objects [MFC]
ms.assetid: 681ee1a7-f6e6-4ea0-9fc6-1fb53a35516e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 48cbc561a7b47318749f490a209513019c2dc62e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426244"
---
# <a name="message-types-associated-with-user-interface-objects"></a>Tipos de mensagem associados a objetos de interface do usuário

A tabela a seguir mostra os tipos de objetos com os quais você trabalha e os tipos de mensagens associadas a eles.

### <a name="user-interface-objects-and-associated-messages"></a>Objetos de Interface do usuário e mensagens associadas

|ID de objeto|Mensagens|
|---------------|--------------|
|Nome da classe, que representa a janela que contém|Mensagens do Windows apropriado para um [CWnd](../../mfc/reference/cwnd-class.md)-classe derivada: uma caixa de diálogo, janela, filho, janela filho MDI ou janela de quadro de nível mais alto.|
|Identificador de menu ou acelerador|-Mensagem de comando (executa o programa funcionar).<br />-Mensagem UPDATE_COMMAND_UI (atualiza dinamicamente o item de menu).|
|Identificador de controle|Controlar mensagens de notificação para o tipo de controle selecionado.|

## <a name="see-also"></a>Consulte também

[Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)

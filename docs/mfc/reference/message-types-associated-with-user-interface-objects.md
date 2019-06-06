---
title: Tipos de mensagem associados a objetos de interface do usuário
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.uiobject.msgs
helpviewer_keywords:
- message types and user interface objects [MFC]
ms.assetid: 681ee1a7-f6e6-4ea0-9fc6-1fb53a35516e
ms.openlocfilehash: 37638d12c65986d40e7df9f0fbfdef4b8207e418
ms.sourcegitcommit: 65ed563a8a1d4d90f872a2a6edcb086f84ec9f77
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/06/2019
ms.locfileid: "66741568"
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
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)

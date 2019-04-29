---
title: Adicionando um manipulador de mensagens do ATL
ms.date: 11/04/2016
helpviewer_keywords:
- message handlers [C++]
- ATL, windows
- message handling [C++], ATL message handler
- windows [C++], ATL
- ATL, message handlers
ms.assetid: cdea38a1-0d9b-4f8d-bbd5-b4f063fb3eeb
ms.openlocfilehash: cc7631ac9e02891cee725b47133a273e756759d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62223461"
---
# <a name="adding-an-atl-message-handler"></a>Adicionando um manipulador de mensagens do ATL

Para adicionar um manipulador de mensagens (uma função de membro que lida com mensagens do Windows) para um controle, selecione o controle no modo de exibição de classe. Em seguida, abra o **propriedades** janela, selecione a **mensagens** ícone e clique na lista suspensa de controle na caixa oposta a mensagem necessária. Isso adicionará uma declaração para o manipulador de mensagens no arquivo de cabeçalho do controle e uma implementação de esqueleto do manipulador no arquivo. cpp do controle. Ele também adicionar o mapa de mensagem e adicione uma entrada para o manipulador.

Adicionar um manipulador de mensagens em ATL é semelhante a adicionar um manipulador de mensagens para uma classe do MFC. Ver [adicionando um manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md) para obter mais informações.

As seguintes condições se aplicam somente a adição de um manipulador de mensagem ATL:

- Os manipuladores de mensagem seguem a mesma convenção de nomenclatura do MFC.

- As novas entradas de mapa de mensagem são adicionadas para o mapa de mensagem principal. O assistente não reconhece mapas de mensagem alternativo e encadeamento.

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)

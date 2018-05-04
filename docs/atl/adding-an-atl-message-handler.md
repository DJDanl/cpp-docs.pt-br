---
title: Adicionando um manipulador de mensagem ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- message handlers [C++]
- ATL, windows
- message handling [C++], ATL message handler
- windows [C++], ATL
- ATL, message handlers
ms.assetid: cdea38a1-0d9b-4f8d-bbd5-b4f063fb3eeb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e79598b79ccbad13ad98c7fc1284808fe1b05cfc
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="adding-an-atl-message-handler"></a>Adicionando um manipulador de mensagem do ATL
Para adicionar um manipulador de mensagens (uma função de membro que manipula mensagens do Windows) para um controle, selecione o controle no modo de exibição de classe. Abra o **propriedades** janela, selecione o **mensagens** ícone e clique na lista suspensa de controle na caixa oposta a mensagem necessária. Isso adicionará uma declaração para o manipulador de mensagens no arquivo de cabeçalho do controle e uma implementação de esqueleto do manipulador no arquivo. cpp do controle. Ele também adicionar o mapa de mensagem e adicione uma entrada para o manipulador.  
  
 Adicionar um manipulador de mensagens em ATL é semelhante a adicionar um manipulador de mensagens para uma classe do MFC. Consulte [adicionando um manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md) para obter mais informações.  
  
 As seguintes condições se aplicam apenas a adição de um manipulador de mensagem ATL:  
  
-   Os manipuladores de mensagens seguem a mesma convenção de nomenclatura do MFC.  
  
-   As novas entradas de mapa de mensagem são adicionadas para o mapa de mensagem principal. O assistente não reconhece os mapas de mensagem alternativo e encadeamento.  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)


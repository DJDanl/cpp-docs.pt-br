---
title: Testando o controle DHTML da ATL modificado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- HTML controls, testing
- testing controls
- DHTML controls, testing
ms.assetid: 42316118-9433-410f-9d8a-0efcc1eff824
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9730f8ef9bfc89d65ffb89ddbbfe67ce247138e9
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43755586"
---
# <a name="testing-the-modified-atl-dhtml-control"></a>Testando o controle DHTML da ATL modificado

Experimente o novo controle para ver como ele funciona agora.

#### <a name="to-build-and-test-the-modified-control"></a>Para compilar e testar o controle modificado

1. Recompile o projeto e abra-o no contêiner de teste. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

     Redimensione o controle para mostrar todos os botões que você adicionou.

2. Examine os dois botões que você inseriu alterando o HTML. Cada botão tem o rótulo que você identificou na [modificando o controle DHTML da ATL](../atl/modifying-the-atl-dhtml-control.md): **atualize** e **HelloHTML**.

3. Teste os dois novos botões para ver como elas funcionam.

Os métodos que não fazem parte da interface do usuário de teste agora.

1. Realce o controle, portanto, a borda é ativada.

2. Sobre o **controle** menu, clique em **invocar métodos**.

Os métodos na lista rotulada **nome do método** são os métodos que o contêiner pode chamar: `MethodInvoked` e `GoToURL`. Todos os outros métodos são controlados pela interface do usuário.

1. Selecione um método para invocar e clique em `Invoke` para exibir a caixa de mensagem do método ou para navegar até www.microsoft.com.

2. No **invocar métodos** caixa de diálogo, clique em **fechar**.

Para saber mais sobre os vários elementos e arquivos que compõem um controle DHTML ATL, consulte [identificando os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md).

## <a name="see-also"></a>Consulte também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)


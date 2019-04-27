---
title: Testando o controle DHTML da ATL modificado
ms.date: 11/06/2018
helpviewer_keywords:
- HTML controls, testing
- testing controls
- DHTML controls, testing
ms.assetid: 42316118-9433-410f-9d8a-0efcc1eff824
ms.openlocfilehash: 55cdaba64ccb95ee5695c082a5e146b1e7dc2cf3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62196568"
---
# <a name="testing-the-modified-atl-dhtml-control"></a>Testando o controle DHTML da ATL modificado

Experimente o novo controle para ver como ele funciona agora.

## <a name="to-build-and-test-the-modified-control"></a>Para compilar e testar o controle modificado

1. Recompilar o projeto e abri-lo no **contêiner de teste**. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar **contêiner de teste**.

   Redimensione o controle para mostrar todos os botões que você adicionou.

1. Examine os dois botões que você inseriu alterando o HTML. Cada botão tem o rótulo que você identificou na [modificando o controle DHTML da ATL](../atl/modifying-the-atl-dhtml-control.md): **Atualize** e **HelloHTML**.

1. Teste os dois novos botões para ver como elas funcionam.

Os métodos que não fazem parte da interface do usuário de teste agora.

1. Realce o controle, portanto, a borda é ativada.

1. Sobre o **controle** menu, escolha **invocar métodos**.

   Os métodos na lista rotulada **nome do método** são os métodos que o contêiner pode chamar: `MethodInvoked` e `GoToURL`. Todos os outros métodos são controlados pela interface do usuário.

1. Selecione um método para invocar e escolha **Invoke** para exibir a caixa de mensagem do método ou para navegar até `www.microsoft.com`.

1. No **invocar métodos** diálogo caixa, escolha **fechar**.

Para saber mais sobre os vários elementos e arquivos que compõem um controle DHTML ATL, consulte [identificando os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md).

## <a name="see-also"></a>Consulte também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

---
title: Testando o controle DHTML da ATL | Microsoft Docs
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
- DHTML controls
- DHTML controls, testing
ms.assetid: 0e4b4358-80ce-4505-8b06-ef4f30b1d1f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea2301a85411cea8d5ffd6121f4fb4f45d3196eb
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860843"
---
# <a name="testing-the-atl-dhtml-control"></a>Testando o controle DHTML da ATL

Depois de criar seu projeto, você pode compilar e testar o controle de exemplo. Antes de fazer isso, use **Class View** e **Gerenciador de soluções** para examinar o projeto. Os elementos do seu projeto são descritos mais detalhadamente nos [identificando os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md).

## <a name="to-build-and-test-the-atl-dhtml-control"></a>Para compilar e testar o controle DHTML da ATL

1. Compile o projeto. Dos **construir** menu, clique em **compilar solução**.

1. Quando a compilação for concluída, abra **contêiner de teste**. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar **contêiner de teste**.

1. Na **contêiner de teste**, da **editar** menu, clique em **inserir o novo controle**.

1. No **Inserir controle** caixa de diálogo caixa, selecione o controle de caixa de listagem. Lembre-se de que seu nome é baseado no nome curto indicado no Assistente de controle de ATL. Clique em **OK**.

1. Examine o controle. Observe que ele tem uma barra de rolagem. Use as alças do controle para redimensionar o controle para ativar a barra de rolagem.

1. Teste os botões do controle. Altera a cor do plano de fundo para a cor indicada pelo botão.

1. Fechar **contêiner de teste**.

Em seguida, tente [modificando o controle DHTML](../atl/modifying-the-atl-dhtml-control.md).

## <a name="see-also"></a>Consulte também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)

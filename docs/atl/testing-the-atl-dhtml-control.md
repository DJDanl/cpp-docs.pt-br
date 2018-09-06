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
ms.openlocfilehash: be4bb44455fb97a61cb4af608667bd5c05f2756a
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43766286"
---
# <a name="testing-the-atl-dhtml-control"></a>Testando o controle DHTML da ATL

Depois de criar seu projeto, você pode compilar e testar o controle de exemplo. Antes de fazer isso, use o modo de exibição de classe e o Gerenciador de soluções para examinar o projeto. Os elementos do seu projeto são descritos mais detalhadamente nos [identificando os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md).

#### <a name="to-build-and-test-the-atl-dhtml-control"></a>Para compilar e testar o controle DHTML da ATL

1. Compile o projeto. Dos **construir** menu, clique em **compilar solução**.

2. Quando a compilação for concluída, abra o contêiner de teste. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

3. No contêiner de teste, do **edite** menu, clique em **inserir o novo controle**.

4. No **Inserir controle** caixa de diálogo caixa, selecione o controle de caixa de listagem. Lembre-se de que seu nome é baseado no nome curto indicado no Assistente de controle de ATL. Clique em **OK**.

5. Examine o controle. Observe que ele tem uma barra de rolagem. Use as alças do controle para redimensionar o controle para ativar a barra de rolagem.

6. Teste os botões do controle. Altera a cor do plano de fundo para a cor indicada pelo botão.

7. Feche o contêiner de teste.

Em seguida, tente [modificando o controle DHTML](../atl/modifying-the-atl-dhtml-control.md).

## <a name="see-also"></a>Consulte também

[Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)


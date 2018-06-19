---
title: Testando uma caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Test Dialog command
- testing, dialog boxes
- dialog boxes, testing
ms.assetid: 45034ee9-c554-4f4b-8c46-6ddefdee8951
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 57bb9e827caae0e328971077d902673f2428c80b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889531"
---
# <a name="testing-a-dialog-box"></a>Testando uma caixa de diálogo
Quando você estiver criando uma caixa de diálogo, você pode simular e testar seu comportamento de tempo de execução sem compilar seu programa. Nesse modo, você pode:  
  
-   Digite o texto, selecione na lista da caixa de combinação, ativar ou desativar as opções e escolher comandos.  
  
-   Teste a ordem de tabulação.  
  
-   Teste o agrupamento de controles, como caixas de seleção e botões de opção.  
  
-   Teste os atalhos de teclado para controles na caixa de diálogo.  
  
    > [!NOTE]
    >  Conexões feitas por meio de assistentes de código de caixa de diálogo não são incluídos na simulação.  
  
 Quando você testa uma caixa de diálogo, ele exibe em um local que é relativa à janela do programa principal. Se você definiu a propriedade de alinhar absoluto da caixa de diálogo como True, a caixa de diálogo exibe em uma posição em relação ao canto superior esquerdo da tela.  
  
### <a name="to-test-a-dialog-box"></a>Para testar uma caixa de diálogo  
  
1.  Quando o editor de caixa de diálogo é a janela ativa, na barra de menus, escolha **formato**, **caixa de diálogo de teste**.  
  
2.  Para encerrar a simulação, pressione Esc ou escolha o **fechar** botão na caixa de diálogo que você está testando.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Editor de caixa de diálogo](../windows/dialog-editor.md)   
 [Mostrando ou ocultando a barra de ferramentas do Editor de Caixa de Diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md)


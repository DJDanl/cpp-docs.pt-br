---
title: "Como: criar agentes que usam políticas de Agendador específicas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- scheduler policies, agents [Concurrency Runtime]
- creating agents that use specific policies [Concurrency Runtime]
ms.assetid: 46a3e265-0777-4ec3-a142-967bafc49d67
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d465b39e00bee0911fb5b04bbe60af68e1f296c5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-create-agents-that-use-specific-scheduler-policies"></a>Como cria agentes que usam políticas de agendador específicas
Um agente é um componente do aplicativo funciona de forma assíncrona com outros componentes para resolver as tarefas de computação maior. Normalmente, um agente tem um ciclo de vida definido e mantém o estado.  
  
 Todos os agentes podem ter requisitos de aplicativo único. Por exemplo, um agente que permite a interação do usuário (Recuperando entrada ou exibindo saída) pode exigir acesso de prioridade mais alto para recursos de computação. Políticas de Agendador permitem que você controle a estratégia que o Agendador usa quando ele gerencia as tarefas. Este tópico demonstra como criar agentes que usam políticas de Agendador específicas.  
  
 Para obter um exemplo básico que usa políticas de Agendador personalizado junto com os blocos de mensagens assíncronas, consulte [como: especificar políticas de Agendador específicas](../../parallel/concrt/how-to-specify-specific-scheduler-policies.md).  
  
 Este tópico usa a funcionalidade da biblioteca de agentes assíncrona, como agentes, blocos de mensagens e funções de transmissão de mensagens, para executar o trabalho. Para obter mais informações sobre a biblioteca de agentes assíncronos, consulte [biblioteca de agentes assíncrona](../../parallel/concrt/asynchronous-agents-library.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir define duas classes que derivam de [concurrency::agent](../../parallel/concrt/reference/agent-class.md): `permutor` e `printer`. O `permutor` classe calcula todas as permutações de uma determinada cadeia de caracteres de entrada. O `printer` classe imprime mensagens de progresso para o console. O `permutor` classe executa uma operação de computação intensa, que pode usar todos os recursos de computação disponíveis. Para ser útil, a `printer` classe deve imprimir cada mensagem de progresso de maneira oportuna.  
  
 Para fornecer o `printer` classe razoável acessar recursos de computação, este exemplo usa as etapas descritas em [como: gerenciar uma instância de Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância de agendador que tem uma política personalizada. A política personalizada Especifica a prioridade de thread para a classe de prioridade mais alta.  
  
 Para ilustrar os benefícios de usar um agendador que tem uma política personalizada, este exemplo executa a tarefa duas vezes. Primeiro, o exemplo usa o agendador padrão para agendar as duas tarefas. O exemplo usa o agendador padrão para agendar o `permutor` objeto e um agendador que tem uma política personalizada para agendar o `printer` objeto.  
  
 [!code-cpp[concrt-permute-strings#1](../../parallel/concrt/codesnippet/cpp/how-to-create-agents-that-use-specific-scheduler-policies_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
With default scheduler:  
Computing all permutations of 'Grapefruit'...  
100% complete...  
 
With higher context priority:  
Computing all permutations of 'Grapefruit'...  
100% complete...  
```  
  
 Embora os dois conjuntos de tarefas produzem o mesmo resultado, a versão que usa uma política personalizada permite que o `printer` objeto a ser executado em uma prioridade com privilégios elevados para que ele se comporta mais responsively.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `permute-strings.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **/EHsc cl.exe permute-strings.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Políticas de Agendador](../../parallel/concrt/scheduler-policies.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 


---
title: "Passo a passo: Criando um componente de tempo de execução básico do Windows com WRL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 6e3f0986-7905-4f94-90e5-22c2ebfc8cd0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5859f3ebfcb55427e239a0018d539e2f4df13800
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-creating-a-basic-windows-runtime-component-using-wrl"></a>Instruções passo a passo: criando um componente básico de Windows Runtime  com WRL
Este documento mostra como usar a biblioteca de modelo (WRL) do Windows em tempo de execução C++ para criar um componente básico do tempo de execução do Windows. O componente adiciona dois números e gera um evento quando o resultado é o principal. Este documento também demonstra como usar o componente de um aplicativo de plataforma Universal do Windows que usa JavaScript.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Experiência com o [tempo de execução do Windows](http://msdn.microsoft.com/library/windows/apps/br211377.aspx).  
  
-   Experiência com COM.  
  
### <a name="to-create-a-basic-windows-runtime-component-that-adds-two-numbers"></a>Para criar um componente básico do tempo de execução do Windows que adiciona dois números  
  
1.  No Visual Studio, crie um Visual C++ `WRLClassLibrary` projeto. O documento [modelo de projeto de biblioteca de classe](../windows/wrl-class-library-project-template.md) descreve como baixar o modelo. Nomeie o projeto `Contoso`.  
  
2.  No Contoso.cpp e Contoso.idl, substitua todas as instâncias de "WinRTClass" com "Calculadora".  
  
3.  Em Contoso.idl, adicione o `Add` método para o `ICalculator` interface.  
  
     [!code-cpp[wrl-basic-component#1](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_1.idl)]  
  
4.  Em Contoso.cpp, adicione o `Add` método para o `public` seção o `Calculator` classe.  
  
     [!code-cpp[wrl-basic-component#2](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_2.cpp)]  
  
    > [!IMPORTANT]
    >  Porque você está criando um componente COM, lembre-se de usar o `__stdcall` convenção de chamada.  
  
     Recomendamos que você use `_Out_` e outras anotações de linguagem (SAL) de anotação de origem para descrever como uma função usa os parâmetros. As anotações SAL também descrevem valores de retorno. Anotações SAL funcionam com o [ferramenta de análise de código C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview) para descobrir defeitos possíveis no C e C++ código-fonte. Erros de codificação comuns que são relatados pela ferramenta estão estouros de buffer, memória não inicializada, desreferências de ponteiro nulo e perdas de memória e recursos.  
  
### <a name="to-use-the-component-from-a-universal-windows-platform-app-that-uses-javascript"></a>Para usar o componente de um aplicativo de plataforma Universal do Windows que usa JavaScript  
  
1.  No Visual Studio, adicione um novo JavaScript `Blank App` de projeto para o `Contoso` solução. Nomeie o projeto `CalculatorJS`.  
  
2.  No `CalculatorJS` de projeto, adicione uma referência para o `Contoso` projeto.  
  
3.  No default.html, substitua o `body` seção com esses elementos de interface do usuário:  
  
     [!code-html[wrl-basic-component#3](../windows/codesnippet/Html/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_3.html)]  
  
4.  Em default.js, implementar a `OnClick` função.  
  
     [!code-javascript[wrl-basic-component#4](../windows/codesnippet/JavaScript/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_4.js)]  
  
    > [!NOTE]
    >  Em JavaScript, a primeira letra de um nome de método é alterada para minúscula para corresponder às convenções de nomenclatura padrão.  
  
### <a name="to-add-an-event-that-fires-when-a-prime-number-is-calculated"></a>Para adicionar um evento que é acionado quando um número primo é calculado  
  
1.  Em Contoso.idl, antes da declaração de `ICalculator`, defina o tipo de delegado `PrimeNumberEvent`, que fornece um `int` argumento.  
  
     [!code-cpp[wrl-basic-component#5](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_5.idl)]  
  
     Quando você usa o `delegate` palavra-chave, o compilador MIDL cria uma interface que contém um `Invoke` método que corresponda à assinatura do representante. Neste exemplo, o arquivo gerado Contoso_h.h define o `IPrimeNumberEvent` interface, que é usada neste procedimento.  
  
     [!code-cpp[wrl-basic-component#13](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_6.cpp)]  
  
2.  No `ICalculator` interface, defina o `PrimeNumberFound` evento. O `eventadd` e `eventremove` atributos especificam que o consumidor do `ICalculator` interface pode assinar e cancelar a assinatura desse evento.  
  
     [!code-cpp[wrl-basic-component#6](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_7.idl)]  
  
3.  Em Contoso.cpp, adicione um `private` [Microsoft::WRL::EventSource](../windows/eventsource-class.md) variável de membro para gerenciar os assinantes do evento e invocar o manipulador de eventos.  
  
     [!code-cpp[wrl-basic-component#7](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_8.cpp)]  
  
4.  Contoso.cpp, implementar a `add_PrimeNumberFound` e `remove_PrimeNumberFound` métodos.  
  
     [!code-cpp[wrl-basic-component#8](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_9.cpp)]  
  
### <a name="to-raise-the-event-when-a-prime-number-is-calculated"></a>Para gerar o evento quando um número primo é calculado  
  
1.  Em Contoso.cpp, adicione o `IsPrime` método para o `private` seção o `Calculator` classe.  
  
     [!code-cpp[wrl-basic-component#12](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_10.cpp)]  
  
2.  Modificar o `Calculator`do `Add` método para chamar o [Microsoft::WRL::EventSource::InvokeAll](../windows/eventsource-invokeall-method.md) método quando um número primo é calculado.  
  
     [!code-cpp[wrl-basic-component#11](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_11.cpp)]  
  
### <a name="to-handle-the-event-from-javascript"></a>Para tratar o evento de JavaScript  
  
1.  Em default.html, modifique o `body` seção para incluir uma área de texto que contém os números primos.  
  
     [!code-html[wrl-basic-component#9](../windows/codesnippet/Html/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_12.html)]  
  
2.  Em default.js, modifique o `Add` função para manipular o `PrimeNumberFound` evento. O manipulador de eventos acrescenta um número primo para a área de texto que foi definida pela etapa anterior.  
  
     [!code-javascript[wrl-basic-component#10](../windows/codesnippet/JavaScript/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_13.js)]  
  
    > [!NOTE]
    >  No JavaScript, os nomes de evento são alterados para minúsculas em são prefixados por "on" para corresponder às convenções de nomenclatura padrão.  
  
 A ilustração a seguir mostra o aplicativo de calculadora básico.  
  
 ![Aplicativo de calculadora básica usando JavaScript](../windows/media/wrl_basic_component.png "WRL_Basic_Component")  
  
## <a name="next-steps"></a>Próximas etapas  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md)   
 [Modelo de projeto de biblioteca de classe](../windows/wrl-class-library-project-template.md)   
 [Ferramenta de análise de código C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview)
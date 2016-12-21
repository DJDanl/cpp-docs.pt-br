---
title: "Instru&#231;&#245;es passo a passo: criando um componente b&#225;sico de Windows Runtime  com WRL | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: 6e3f0986-7905-4f94-90e5-22c2ebfc8cd0
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando um componente b&#225;sico de Windows Runtime  com WRL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento mostra como usar o [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] ([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]) para criar um basic [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] componente. O componente adiciona dois números e gera um evento quando o resultado é primo. Este documento também demonstra como usar o componente de um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativo que usa JavaScript.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Experiência com o [Windows Runtime](http://msdn.microsoft.com/library/windows/apps/br211377.aspx).  
  
-   Experiência com COM.  
  
### <a name="to-create-a-basic-includewrttokenwrtmdmd-component-that-adds-two-numbers"></a>Para criar um basic [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] componente que adiciona dois números  
  
1.  No Visual Studio, crie um Visual C++ `WRLClassLibrary` projeto. O documento [modelo de projeto de biblioteca de classes](../windows/wrl-class-library-project-template.md) descreve como baixar o modelo. Nomeie o projeto `Contoso`.  
  
2.  No Contoso.cpp e Contoso.idl, substitua todas as instâncias de "WinRTClass" com "Calculadora".  
  
3.  No Contoso.idl, adicione o `Add` método para o `ICalculator` interface.  
  
     [!code-cpp[wrl-basic-component#1](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_1.idl)]  
  
4.  No Contoso.cpp, adicione o `Add` método para o `public` seção o `Calculator` classe.  
  
     [!code-cpp[wrl-basic-component#2](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_2.cpp)]  
  
    > [!IMPORTANT]
    >  Como você está criando um componente COM, lembre-se de usar o `__stdcall` convenção de chamada.  
  
     É recomendável que você use `_Out_` e outras anotações de linguagem (SAL) fonte anotação para descrever como uma função usa seus parâmetros. As anotações SAL também descrevem valores de retorno. Anotações de SAL trabalhar com o [ferramenta de análise de código C/C++](../Topic/Code%20Analysis%20for%20C-C++%20Overview.md) para descobrir o código-fonte possíveis defeitos em C e C++. Erros de codificação comuns que são relatados pela ferramenta incluem saturações de buffer, memória não inicializada, cancela a referência de ponteiro nulo e vazamentos de memória e recursos.  
  
### <a name="to-use-the-component-from-a-includewin8appnamelongtokenwin8appnamelongmdmd-app-that-uses-javascript"></a>Usar o componente de um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativo que usa JavaScript  
  
1.  No Visual Studio, adicione um nova JavaScript `Blank App` de projeto para o `Contoso` solução. Nomeie o projeto `CalculatorJS`.  
  
2.  No `CalculatorJS` do projeto, adicione uma referência para o `Contoso` projeto.  
  
3.  No Default. HTML, substitua o `body` seção com esses elementos de interface do Usuário:  
  
     [!code-html[wrl-basic-component#3](../windows/codesnippet/Html/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_3.html)]  
  
4.  No Default. js, implemente o `OnClick` função.  
  
     [!code-javascript[wrl-basic-component#4](../windows/codesnippet/JavaScript/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_4.js)]  
  
    > [!NOTE]
    >  No JavaScript, a primeira letra do nome de um método é alterada para letras minúsculas para coincidir com as convenções de nomenclatura padrão.  
  
### <a name="to-add-an-event-that-fires-when-a-prime-number-is-calculated"></a>Para adicionar um evento é acionado quando um número primo é calculado  
  
1.  Em Contoso.idl, antes da declaração de `ICalculator`, definir o tipo de delegado, `PrimeNumberEvent`, que fornece um `int` argumento.  
  
     [!code-cpp[wrl-basic-component#5](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_5.idl)]  
  
     Quando você usa o `delegate` palavra-chave, o compilador MIDL cria uma interface que contém um `Invoke` método que corresponda à assinatura do delegado. Neste exemplo, o arquivo gerado Contoso_h.h define o `IPrimeNumberEvent` interface, que é usado posteriormente neste procedimento.  
  
     [!code-cpp[wrl-basic-component#13](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_6.cpp)]  
  
2.  No `ICalculator` da interface, definir o `PrimeNumberFound` evento. O `eventadd` e `eventremove` atributos especificam que o consumidor do `ICalculator` interface pode se inscrever e Cancelar inscrição desse evento.  
  
     [!code-cpp[wrl-basic-component#6](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_7.idl)]  
  
3.  No Contoso.cpp, adicione uma `private` [Microsoft::WRL::EventSource](../windows/eventsource-class.md) variável de membro para gerenciar os assinantes do evento e invocar o manipulador de eventos.  
  
     [!code-cpp[wrl-basic-component#7](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_8.cpp)]  
  
4.  No Contoso.cpp, implemente o `add_PrimeNumberFound` e `remove_PrimeNumberFound` métodos.  
  
     [!code-cpp[wrl-basic-component#8](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_9.cpp)]  
  
### <a name="to-raise-the-event-when-a-prime-number-is-calculated"></a>Para gerar o evento quando um número primo é calculado  
  
1.  No Contoso.cpp, adicione o `IsPrime` método para o `private` seção o `Calculator` classe.  
  
     [!code-cpp[wrl-basic-component#12](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_10.cpp)]  
  
2.  Modificar o `Calculator`do `Add` método para chamar o [Microsoft::WRL::EventSource::InvokeAll](../windows/eventsource-invokeall-method.md) método quando um número primo é calculado.  
  
     [!code-cpp[wrl-basic-component#11](../windows/codesnippet/CPP/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_11.cpp)]  
  
### <a name="to-handle-the-event-from-javascript"></a>Para manipular o evento de JavaScript  
  
1.  No Default. HTML, modifique o `body` seção para incluir uma área de texto que contém os números primos.  
  
     [!code-html[wrl-basic-component#9](../windows/codesnippet/Html/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_12.html)]  
  
2.  No Default. js, modifique o `Add` função para manipular o `PrimeNumberFound` evento. O manipulador de eventos acrescenta um número primo à área de texto que foi definida pela etapa anterior.  
  
     [!code-javascript[wrl-basic-component#10](../windows/codesnippet/JavaScript/walkthrough-creating-a-basic-windows-runtime-component-using-wrl_13.js)]  
  
    > [!NOTE]
    >  No JavaScript, os nomes de eventos são alterados para letras minúsculas em são prefixados com "on" para coincidir com as convenções de nomenclatura padrão.  
  
 A ilustração a seguir mostra o aplicativo de calculadora básico.  
  
 ![Aplicativo de calculadora básica usando JavaScript](../windows/media/wrl_basic_component.png "WRL_Basic_Component")  
  
## <a name="next-steps"></a>Próximas etapas  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)   
 [Modelo de projeto de biblioteca de classes](../windows/wrl-class-library-project-template.md)   
 [Ferramenta de análise de código C/C++](../Topic/Code%20Analysis%20for%20C-C++%20Overview.md)
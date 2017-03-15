---
title: "How to: Complete Asynchronous Operations Using WRL | Microsoft Docs"
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
ms.assetid: 02173eae-731b-49bc-b412-f1f69388b99d
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# How to: Complete Asynchronous Operations Using WRL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento mostra como usar [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\) para iniciar operações assíncronas e executar o trabalho quando as operações forem concluídos.  
  
 Este documento mostra dois exemplos.  O primeiro exemplo inicia um timer assíncrona e aguarda o timer para expirar.  Neste exemplo, você especifica a ação assíncrono quando você cria o objeto de timer.  O segundo exemplo executa um thread de trabalho em segundo plano.  Este exemplo mostra como trabalhar com um método de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] que retorna uma interface de `IAsyncInfo` .  A função de [Retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md) é uma parte importante de ambos os exemplos a seguir porque os habilita para especificar um manipulador de eventos para processar os resultados das operações assíncronas.  
  
 Para obter um exemplo mais básico que cria uma instância desse componente e recupera um valor de propriedade, consulte [Como ativar e usar um componente de Tempo de Execução do Windows](../windows/how-to-activate-and-use-a-windows-runtime-component-using-wrl.md).  
  
> [!TIP]
>  Esses exemplos usam expressões de lambda para definir os retornos de chamada.  Você também pode usar objetos de função \(functors\), ponteiros de função, ou objetos de [std::function](../standard-library/function-class.md) .  Para obter mais informações sobre expressões de lambda C\+\+, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  
  
## Exemplo: Trabalhando com um timer  
 As seguintes etapas iniciam um timer assíncrona e esperam o timer para expirar.  O exemplo completo a seguir.  
  
> [!WARNING]
>  Embora você normalmente usa [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , esse exemplo usa um aplicativo de console para ilustração.  Funções como `wprintf_s` não estão disponíveis em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] .  Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , consulte [Funções de CRT não suportadas por \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx) e [O Win32 e COM para aplicativos do Windows Store](http://msdn.microsoft.com/library/windows/apps/br205757.aspx).  
  
1.  Inclua \(\)`#include`qualquer [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]necessário, [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)], ou cabeçalhos de biblioteca padrão do C\+\+.  
  
     [!code-cpp[wrl-consume-async#2](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_1.cpp)]  
  
     Windows.System.Threading.h declara os tipos que são necessários para usar um timer assíncrona.  
  
     Recomendamos que você utiliza a política de `using namespace` no arquivo .cpp para tornar código mais legível.  
  
2.  Inicializar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
     [!code-cpp[wrl-consume-async#3](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_2.cpp)]  
  
3.  Crie uma fábrica de ativação para a interface de `ABI::Windows::System::Threading::IThreadPoolTimer` .  
  
     [!code-cpp[wrl-consume-async#4](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_3.cpp)]  
  
     Os nomes totalmente qualificados de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] para identificar tipos.  O parâmetro de `RuntimeClass_Windows_System_Threading_ThreadPoolTimer` é uma cadeia de caracteres que é fornecida por [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e contém o nome da classe necessário em tempo de execução.  
  
4.  Crie um objeto de [Evento](../windows/event-class-windows-runtime-cpp-template-library.md) que sincroniza o retorno de chamada de timer para o aplicativo principal.  
  
     [!code-cpp[wrl-consume-async#5](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_4.cpp)]  
  
    > [!NOTE]
    >  Esse evento é para demonstração somente como parte de um aplicativo de console.  Este exemplo usa o evento para assegurar que uma operação de async foi concluído antes que o aplicativo vai.  Na maioria dos aplicativos, você normalmente não espera operações de async para concluir.  
  
5.  Crie um objeto de `IThreadPoolTimer` que expire após dois segundos.  Use a função de `Callback` para criar o manipulador de eventos \(um objeto de `ABI::Windows::System::Threading::ITimerElapsedHandler` \).  
  
     [!code-cpp[wrl-consume-async#6](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_5.cpp)]  
  
6.  Imprime uma mensagem para o console e aguarde o retorno de chamada de timer para concluir.  Qualquer `ComPtr` e os objetos de RAII permitem o escopo e são liberados automaticamente.  
  
     [!code-cpp[wrl-consume-async#7](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_6.cpp)]  
  
 Aqui está o exemplo completo:  
  
 [!code-cpp[wrl-consume-async#1](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_7.cpp)]  
  
### Compilando o código  
 Para compilar o código, copie\-a e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `wrl-consume-async.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe wrl\-consume\-async.cpp runtimeobject.lib**  
  
## Exemplo: Trabalhando com um thread em segundo plano  
 As seguintes etapas iniciará um thread de trabalho e definem a ação que é executada por esse thread.  O exemplo completo a seguir.  
  
> [!TIP]
>  Este exemplo demonstra como trabalhar com a interface de `ABI::Windows::Foundation::IAsyncAction` .  Você pode aplicar esse padrão para qualquer interface que implementar `IAsyncInfo`: `IAsyncAction`, `IAsyncActionWithProgress`, `IAsyncOperation`, e `IAsyncOperationWithProgress`.  
  
1.  Inclua \(\)`#include`qualquer [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]necessário, [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)], ou cabeçalhos de biblioteca padrão do C\+\+.  
  
     [!code-cpp[wrl-consume-asyncOp#2](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_8.cpp)]  
  
     Windows.System.Threading.h declara os tipos que são necessários para usar um thread de trabalho.  
  
     Recomendamos que você use a política de `using namespace` no arquivo .cpp para tornar código mais legível.  
  
2.  Inicializar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
     [!code-cpp[wrl-consume-asyncOp#3](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_9.cpp)]  
  
3.  Crie uma fábrica de ativação para a interface de `ABI::Windows::System::Threading::IThreadPoolStatics` .  
  
     [!code-cpp[wrl-consume-asyncOp#4](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_10.cpp)]  
  
4.  Crie um objeto de [Evento](../windows/event-class-windows-runtime-cpp-template-library.md) que sincroniza a conclusão do thread de trabalho para o aplicativo principal.  
  
     [!code-cpp[wrl-consume-asyncOp#5](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_11.cpp)]  
  
    > [!NOTE]
    >  Esse evento é para demonstração somente como parte de um aplicativo de console.  Este exemplo usa o evento para assegurar que uma operação de async foi concluído antes que o aplicativo vai.  Na maioria dos aplicativos, você normalmente não espera operações de async para concluir.  
  
5.  Chame o método de `IThreadPoolStatics::RunAsync` para criar um thread de trabalho.  Use a função de `Callback` para definir a ação.  
  
     [!code-cpp[wrl-consume-asyncOp#6](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_12.cpp)]  
  
     A função de `IsPrime` é definida no exemplo completo a seguir.  
  
6.  Imprime uma mensagem para o console e aguarde o thread para concluir.  Qualquer `ComPtr` e os objetos de RAII permitem o escopo e são liberados automaticamente.  
  
     [!code-cpp[wrl-consume-asyncOp#7](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_13.cpp)]  
  
 Aqui está o exemplo completo:  
  
 [!code-cpp[wrl-consume-asyncOp#1](../windows/codesnippet/CPP/how-to-complete-asynchronous-operations-using-wrl_14.cpp)]  
  
### Compilando o código  
 Para compilar o código, copie\-a e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `wrl-consume-asyncOp.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe wrl\-consume\-asyncOp.cpp runtimeobject.lib**  
  
## Consulte também  
 [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)
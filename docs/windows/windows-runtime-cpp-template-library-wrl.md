---
title: Biblioteca de modelos C++ do Windows Runtime (WRL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
ms.assetid: b915afce-553b-44a7-b8dc-0ab601758eb0
caps.latest.revision: "32"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a37b20af7ee9ef43c64fc0df24b47a380000eb6b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="windows-runtime-c-template-library-wrl"></a>Biblioteca de Modelos C++ do Windows Runtime  (WRL)
A biblioteca de modelo (WRL) do Windows em tempo de execução C++ é uma biblioteca de modelo que fornece uma maneira de baixo nível para criar e usar componentes de tempo de execução do Windows.  
  
## <a name="benefits"></a>Benefícios  
 A biblioteca de modelos do Windows em tempo de execução C++ permite implementar mais facilmente e consumir componentes do modelo de objeto de componente (COM). Ele fornece técnicas de manutenção como contagem de referência gerenciar o tempo de vida de objetos e teste `HRESULT` valores para determinar se uma operação teve êxito ou falhou. Para poder usar a biblioteca de modelos do Windows em tempo de execução C++, você deve seguir atentamente essas regras e técnicas.  
  
 C + + CX é uma maneira de alto nível, com base no idioma usar componentes de tempo de execução do Windows. Tanto a biblioteca de modelos C++ do Windows Runtime e C + + CX simplifica a criação de código para o tempo de execução do Windows executar tarefas de manutenção automaticamente em seu nome.  
  
 A biblioteca de modelos C++ do Windows Runtime e C + + CX oferece benefícios diferentes. Aqui estão alguns motivos pelos quais você talvez queira usar a biblioteca de modelos do Windows em tempo de execução C++ em vez de C + + CX:  
  
-   Biblioteca de modelos C++ do Windows Runtime adiciona abstração pouco sobre o Windows Runtime aplicativo binário Interface (ABI), fornecendo a capacidade de controlar o código subjacente para melhor criar ou consumir APIs do Windows Runtime.  
  
-   C + + CX representa COM `HRESULT` valores como exceções. Se você acabou de herdar uma base de código que usa COM, ou um que não use exceções, talvez descubra que a biblioteca de modelos do Windows em tempo de execução C++ é uma forma mais natural para trabalhar com o tempo de execução do Windows porque você não precisa usar exceções.  
  
    > [!NOTE]
    >  Usa a biblioteca de modelos do Windows em tempo de execução C++ `HRESULT` valores e não gerar exceções. Além disso, a biblioteca de modelos do Windows em tempo de execução C++ usa ponteiros inteligentes e o padrão RAII para ajudar a garantir que os objetos são destruídos corretamente quando o código do aplicativo gera uma exceção. Para obter mais informações sobre como ponteiros inteligentes e RAII, consulte [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md) e [objetos próprios recursos (RAII)](../cpp/objects-own-resources-raii.md).  
  
-   A finalidade e o design da biblioteca de modelo do Windows Runtime C++ é inspirado por biblioteca de modelo ativa (ATL), a qual é um conjunto de classes C++ com base em modelo que simplifica a programação de objetos COM. Como biblioteca de modelos C++ do Windows Runtime usa C++ padrão para encapsular o tempo de execução do Windows, você pode mais facilmente porta e interagir com vários componentes COM existentes escritos em ATL no tempo de execução do Windows. Se você já souber ATL, você talvez descubra que a programação da biblioteca de modelos C++ do Windows em tempo de execução é mais fácil.  
  
## <a name="getting-started"></a>Guia de Introdução  
 Aqui estão alguns recursos que podem ajudá-lo a obter trabalhar com a biblioteca de modelos do Windows em tempo de execução C++ imediatamente.  
  
 [Biblioteca de tempo de execução do Windows (WRL)](http://channel9.msdn.com/Events/Windows-Camp/Developing-Windows-8-Metro-style-apps-in-Cpp/The-Windows-Runtime-Library-WRL-)  
 Neste vídeo do Channel 9, saiba mais sobre como a biblioteca de modelos do Windows em tempo de execução C++ ajuda a que escrever aplicativos de plataforma Universal do Windows e como criar e consumir componentes de tempo de execução do Windows.  
  
 [Como: ativar e usar um componente de tempo de execução do Windows](../windows/how-to-activate-and-use-a-windows-runtime-component-using-wrl.md)  
 Mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para inicializar o tempo de execução do Windows e ativar e usar um componente de tempo de execução do Windows.  
  
 [Como: executar operações assíncronas](../windows/how-to-complete-asynchronous-operations-using-wrl.md)  
 Mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para iniciar operações assíncronas e executar o trabalho quando as operações concluídas.  
  
 [Como: manipular eventos](../windows/how-to-handle-events-using-wrl.md)  
 Mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para assinar e tratar os eventos de um objeto de tempo de execução do Windows.  
  
 [Passo a passo: Criando um componente de tempo de execução básico do Windows](../windows/walkthrough-creating-a-basic-windows-runtime-component-using-wrl.md)  
 Mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para criar um componente básico do tempo de execução do Windows que adiciona dois números. Também demonstra como gerar eventos e usa o componente de um aplicativo de plataforma Universal do Windows que usa JavaScript.  
  
 [Passo a passo: criando um aplicativo da Windows Store usando a WRL e o Media Foundation](../windows/walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation.md)  
 Saiba como criar um aplicativo de plataforma Universal do Windows que usa [Microsoft Media Foundation](http://msdn.microsoft.com/library/windows/apps/ms694197).  
  
 [Como: criar um componente COM clássico](../windows/how-to-create-a-classic-com-component-using-wrl.md)  
 Mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para criar um componente básico e uma maneira simples de registrar e consumir o componente COM de um aplicativo de área de trabalho.  
  
 [Como instanciar componentes da WRL diretamente](../windows/how-to-instantiate-wrl-components-directly.md)  
 Saiba como usar o [Microsoft::WRL::Make](../windows/make-function.md) e [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md) funções para criar uma instância de um componente do módulo que o define.  
  
 [Como usar winmdidl.exe e midlrt.exe para criar arquivos .h com metadados do Windows](../windows/use-winmdidl-and-midlrt-to-create-h-files-from-windows-metadata.md)  
 Mostra como consumir componentes personalizados de Windows Runtime de WRL criando um arquivo IDL dos metadados. winmd.  
  
 [Instruções passo a passo: conexão usando tarefas e solicitações HTTP XML](../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)  
 Mostra como usar o [IXMLHTTPRequest2](http://msdn.microsoft.com/en-us/bbc11c4a-aecf-4d6d-8275-3e852e309908) e [IXMLHTTPRequest2Callback](http://msdn.microsoft.com/en-us/aa4b3f4c-6e28-458b-be25-6cce8865fc71) interfaces junto com as tarefas para enviar solicitações HTTP GET e POST para um serviço da web em um aplicativo de plataforma Universal do Windows.  
  
 [Exemplo do Bing Maps Trip Optimizer](http://code.msdn.microsoft.com/Bing-Maps-trip-optimizer-c4e037f7)  
 Usa o `HttpRequest` classe definida em [passo a passo: conectando usando tarefas e solicitações HTTP XML](../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md) no contexto de um aplicativo de plataforma Universal do Windows completo.  
  
 [Criando um componente de DLL de tempo de execução do Windows com o exemplo de C++](http://code.msdn.microsoft.com/windowsapps/Creating-a-Windows-Runtime-6c399797)  
 Mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para criar um componente DLL do processo e consumi-lo em C + + CX, JavaScript e c#.  
  
 [Exemplo do jogo marble maze DirectX](http://code.msdn.microsoft.com/windowsapps/DirectX-Marble-Maze-Game-e4806345)  
 Demonstra como usar a biblioteca de modelos do Windows em tempo de execução C++ para gerenciar o tempo de vida de componentes COM, como o DirectX e Media Foundation no contexto de um jogo 3D completo.  
  
 [Enviar notificações de exemplo de aplicativos de área de trabalho](http://code.msdn.microsoft.com/windowsdesktop/Sending-toast-notifications-71e230a2)  
 Demonstra como usar a biblioteca de modelos do Windows em tempo de execução C++ para trabalhar com notificações de um aplicativo de área de trabalho.  
  
## <a name="windows-runtime-c-template-library-compared-to-atl"></a>Biblioteca de modelos C++ do tempo de execução do Windows em comparação comparada ATL  
 Biblioteca de modelos C++ do Windows em tempo de execução é semelhante a biblioteca de modelo ativa (ATL) porque você pode usá-lo para criar pequena, rápidos objetos. Biblioteca de modelos C++ do Windows Runtime ATL compartilhar conceitos como a definição de objetos em módulos, registro explícito de interfaces e abra a criação de objetos usando fábricas. Você talvez esteja familiarizado com a biblioteca de modelos C++ do Windows Runtime se você estiver familiarizado com ATL.  
  
 Biblioteca de modelos C++ do Windows Runtime oferece suporte a funcionalidade COM que é necessária para aplicativos de plataforma Universal do Windows. Portanto, ele difere de ATL porque ele omite o suporte direto para os recursos de COM, como:  
  
-   Agregação  
  
-   implementações de estoque  
  
-   interfaces duplas (`IDispatch`)  
  
-   interfaces de enumerador padrão  
  
-   pontos de conexão  
  
-   interfaces destacável  
  
-   Inserção OLE  
  
-   Controles ActiveX  
  
-   COM+  
  
## <a name="concepts"></a>Conceitos  
 Biblioteca de modelos C++ do Windows Runtime fornece tipos que representam alguns conceitos básicos. As seções a seguir descrevem esses tipos.  
  
### <a name="comptr"></a>ComPtr  
 [ComPtr](../windows/comptr-class.md) é um *ponteiro inteligente* tipo que representa a interface que é especificada pelo parâmetro de modelo. Use `ComPtr` para declarar uma variável que pode acessar os membros de um objeto que é derivado da interface. `ComPtr`automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.  
  
### <a name="runtimeclass"></a>RuntimeClass  
 [RuntimeClass](../windows/runtimeclass-class.md) representa uma classe instanciada que herda de um conjunto de interfaces especificadas. Um `RuntimeClass` objeto puder fornecer uma combinação de suporte para uma ou mais interfaces COM tempo de execução do Windows ou uma referência fraca a um componente.  
  
### <a name="module"></a>Módulo  
 [Módulo](../windows/module-class.md) representa uma coleção de objetos relacionados. Um `Module` objeto gerencia fábricas de classe, que criam objetos e o registro, que permite que os outros aplicativos usar um objeto.  
  
### <a name="callback"></a>retorno de chamada  
 O [retorno de chamada](../windows/callback-function-windows-runtime-cpp-template-library.md) função cria um objeto cuja função de membro é um manipulador de eventos (um método de retorno de chamada). Use o `Callback` função gravar operações assíncronas.  
  
### <a name="eventsource"></a>EventSource  
 [EventSource](../windows/eventsource-class.md) é usado para gerenciar *delegar* manipuladores de eventos. Use a biblioteca de modelos C++ do Windows Runtime para implementar um delegado e usar `EventSource` para adicionar, remover e invocar delegados.  
  
### <a name="asyncbase"></a>AsyncBase  
 [AsyncBase](../windows/asyncbase-class.md) fornece métodos virtuais que representam o modelo de programação assíncrono do tempo de execução do Windows. Substitua os membros dessa classe para criar uma classe personalizada que podem iniciar, parar ou verificar o progresso de uma operação assíncrona.  
  
### <a name="ftmbase"></a>FtmBase  
 [FtmBase](../windows/ftmbase-class.md) representa um objeto de empacotamento de segmentação livre. `FtmBase`cria uma tabela de interface global (GIT) e ajuda a gerenciar objetos de proxy e de empacotamento.  
  
### <a name="weakref"></a>WeakRef  
 [WeakRef](../windows/weakref-class.md) é um tipo de ponteiro inteligente que representa um *referência fraca*, que faz referência a um objeto que pode ou não pode ser acessado. Um `WeakRef` objeto pode ser usado somente no tempo de execução do Windows e não por COM. clássico  
  
 Um `WeakRef` objeto normalmente representa um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, um `WeakRef` objeto pode fazer referência a um objeto de arquivo. Quando o arquivo é aberto, o `WeakRef` é válido e o arquivo referenciado está acessível. Porém, quando o arquivo seja fechado, o `WeakRef` é inválido e o arquivo não está acessível.  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|||  
|-|-|  
|[Modelo de projeto de biblioteca de classe](../windows/wrl-class-library-project-template.md)|Descreve como acessar o modelo de projeto de biblioteca de classes WRL. Este modelo o ajuda a simplificar a tarefa de usar o Visual Studio para criar componentes de tempo de execução do Windows.|  
|[APIs de chave por categoria](../windows/key-wrl-apis-by-category.md)|Realça principal biblioteca de modelos C++ do Windows Runtime tipos, funções e macros.|  
|[Referência](../windows/wrl-reference.md)|Contém informações de referência para a biblioteca de modelos do Windows em tempo de execução C++.|  
|[Referência rápida (tempo de execução do Windows e do Visual C++)](http://go.microsoft.com/fwlink/?LinkId=229180)|Descreve brevemente C + + recursos CX que oferecem suporte à execução do Windows.|  
|[Usando componentes de tempo de execução do Windows em Visual C++](http://go.microsoft.com/fwlink/?LinkId=229155)|Mostra como usar C + c++ /CX para criar um componente básico do tempo de execução do Windows.|
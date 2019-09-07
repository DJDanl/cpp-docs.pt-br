---
title: Biblioteca de Modelos C++ do Windows Runtime  (WRL)
ms.date: 11/04/2016
ms.topic: landing-page
ms.assetid: b915afce-553b-44a7-b8dc-0ab601758eb0
ms.openlocfilehash: 7a92676d198ed9ddffeae9a834ebd358c2c58e90
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740838"
---
# <a name="windows-runtime-c-template-library-wrl"></a>Biblioteca de Modelos C++ do Windows Runtime  (WRL)

A WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows) é uma biblioteca de modelos que fornece uma maneira de baixo nível para criar e usar componente do Windows Runtime.

> [!NOTE]
> O WRL agora é substituído pelo C++/WinRT, uma projeção de linguagem c++ 17 padrão para APIs Windows Runtime. C++O/WinRT está disponível no SDK do Windows 10 da versão 1803 em diante. C++O/WinRT é implementado inteiramente em arquivos de cabeçalho e projetado para fornecer a você acesso de primeira classe à API moderna do Windows.
>
> Com C++o/WinRT, você pode consumir e criar Windows Runtime APIs usando qualquer compilador c++ 17 compatível com padrões. C++O/WinRT normalmente tem um desempenho melhor e produz binários menores do que qualquer outra opção de idioma para o Windows Runtime. Continuaremos a dar suporte a C++/CX e WRL, mas recomendamos que os novos aplicativos usem o C++/WinRT. Saiba mais em [C++/WinRT](https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/index).

## <a name="benefits"></a>Benefícios

A Windows Runtime C++ biblioteca de modelos permite que você implemente e consuma com mais facilidade os componentes de Component Object Model (com). Ele fornece técnicas de manutenção como a contagem de referências para gerenciar o tempo de vida de objetos e testar valores HRESULT para determinar se uma operação teve êxito ou falhou. Para usar a biblioteca de modelos C++ do Windows Runtime com êxito, você deve seguir cuidadosamente essas regras e técnicas.

O C++/CX é uma maneira baseada em linguagem de alto nível para usar componentes Windows Runtime. Tanto a biblioteca C++ de modelos Windows Runtime C++quanto a/CX simplificam a escrita de código para o Windows Runtime executando automaticamente tarefas de manutenção em seu nome.

A biblioteca C++ de modelos Windows Runtime C++e o/CX fornecem benefícios diferentes. Aqui estão alguns motivos pelos quais você pode querer usar a C++ biblioteca de modelos Windows Runtime C++em vez de/CX:

- Windows Runtime C++ biblioteca de modelos adiciona pouca abstração sobre a Abi (interface binária de aplicativo Windows Runtime), oferecendo a capacidade de controlar o código subjacente para criar ou consumir melhor as APIs de Windows Runtime.

- C++/CX representa valores de HRESULT COM como exceções. Se você herdou uma base de código que usa COM, ou uma que não usa exceções, talvez descubra que a Windows Runtime C++ biblioteca de modelos é uma maneira mais natural de trabalhar com o Windows Runtime porque você não precisa usar exceções.

   > [!NOTE]
   > A biblioteca C++ de modelos de Windows runtime usa valores HRESULT e não gera exceções. Além disso, a Windows Runtime C++ biblioteca de modelos usa apontadores inteligentes e o padrão RAII para ajudar a garantir que os objetos sejam destruídos corretamente quando o código do aplicativo lançar uma exceção. Para obter mais informações sobre apontadores inteligentes e RAII, consulte [ponteiros inteligentes](../../cpp/smart-pointers-modern-cpp.md) e [recursos próprios de objetos (RAII)](../../cpp/objects-own-resources-raii.md).

- A finalidade e o design da biblioteca C++ de modelos de Windows Runtime é inspirado pelo Active Template Library (ATL), que é um conjunto de classes baseadas C++ em modelo que simplificam a programação de objetos com. Como Windows Runtime C++ biblioteca de modelos usa C++ o padrão para encapsular o Windows Runtime, você pode facilmente portar e interagir com muitos componentes com existentes gravados em ATL no Windows Runtime. Se você já conhece a ATL, pode descobrir que Windows Runtime C++ programação da biblioteca de modelos é mais fácil.

## <a name="getting-started"></a>Guia de Introdução

Aqui estão alguns recursos que podem ajudá-lo a começar a trabalhar C++ com a biblioteca de modelos do Windows Runtime imediatamente.

[A biblioteca de Windows Runtime (WRL)](https://channel9.msdn.com/Events/Windows-Camp/Developing-Windows-8-Metro-style-apps-in-Cpp/The-Windows-Runtime-Library-WRL-)<br/>
Neste vídeo do Channel 9, saiba mais sobre como a Windows Runtime C++ biblioteca de modelos ajuda você a escrever aplicativos plataforma universal do Windows (UWP) e como criar e consumir componentes de Windows Runtime.

[Como: Ativar e usar um componente Windows Runtime](how-to-activate-and-use-a-windows-runtime-component-using-wrl.md)<br/>
Mostra como usar a biblioteca de C++ modelos Windows Runtime para inicializar o Windows Runtime e ativar e usar um componente Windows Runtime.

[Como: Concluir operações assíncronas](how-to-complete-asynchronous-operations-using-wrl.md)<br/>
Mostra como usar a biblioteca de C++ modelos Windows Runtime para iniciar operações assíncronas e executar o trabalho quando as operações forem concluídas.

[Como: Manipular eventos](how-to-handle-events-using-wrl.md)<br/>
Mostra como usar a Windows Runtime C++ biblioteca de modelos para assinar e manipular os eventos de um objeto Windows Runtime.

[Passo a passo: como criar um aplicativo UWP usando WRL e Media Foundation](walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation.md)<br/>
Saiba como criar um aplicativo UWP que usa [Microsoft Media Foundation](/windows/win32/medfound/microsoft-media-foundation-sdk).

[Como: Criar um componente COM clássico](how-to-create-a-classic-com-component-using-wrl.md)<br/>
Mostra como usar a biblioteca de C++ modelos de Windows Runtime para criar um componente com básico e uma maneira básica de registrar e consumir o componente com de um aplicativo de área de trabalho.

[Como: instanciar componentes da WRL diretamente](how-to-instantiate-wrl-components-directly.md)<br/>
Saiba como usar as funções [Microsoft:: WRL:: Make](make-function.md) e [Microsoft:: WRL::D etalhes:: MakeAndInitialize](makeandinitialize-function.md) para criar uma instância de um componente do módulo que o define.

[Como: usar winmdidl.exe e midlrt.exe para criar arquivos .h com metadados do Windows](use-winmdidl-and-midlrt-to-create-h-files-from-windows-metadata.md)<br/>
Mostra como consumir componentes de Windows Runtime personalizados do WRL criando um arquivo IDL dos metadados. winmd.

[Passo a passo: Conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)<br/>
Mostra como usar as interfaces [IXMLHTTPRequest2](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/windows/win32/api/msxml6/nn-msxml6-ixmlhttprequest2callback) junto com as tarefas para enviar solicitações HTTP Get e post para um serviço Web em um aplicativo UWP.

[Exemplo de otimizador de viagens do Bing Maps](https://code.msdn.microsoft.com/Bing-Maps-trip-optimizer-c4e037f7)<br/>
Usa a `HttpRequest` classe que é definida em [Walkthrough: Conectar-se usando tarefas e solicitações](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md) http XML no contexto de um aplicativo UWP completo.

[Criando um componente DLL Windows Runtime com C++ exemplo](https://code.msdn.microsoft.com/windowsapps/Creating-a-Windows-Runtime-6c399797)<br/>
Mostra como usar a biblioteca de C++ modelos de Windows Runtime para criar um componente de dll em processo e consumi- C++lo de/CX, JavaScript C#e.

[Exemplo de jogo de labirinto de mármore DirectX](https://code.msdn.microsoft.com/windowsapps/DirectX-Marble-Maze-Game-e4806345)<br/>
Demonstra como usar a biblioteca de C++ modelos Windows Runtime para gerenciar o tempo de vida de componentes com, como DirectX e Media Foundation no contexto de um jogo 3D completo.

[Enviando notificações do sistema de exemplo de aplicativos da área de trabalho](https://code.msdn.microsoft.com/windowsdesktop/Sending-toast-notifications-71e230a2)<br/>
Demonstra como usar a Windows Runtime C++ biblioteca de modelos para trabalhar com notificações do sistema de um aplicativo de área de trabalho.

## <a name="windows-runtime-c-template-library-compared-to-atl"></a>Windows Runtime C++ biblioteca de modelos em comparação com a ATL

Windows Runtime C++ biblioteca de modelos se assemelha ao Active Template Library (ATL) porque você pode usá-lo para criar objetos com pequenos e rápidos. Windows Runtime C++ biblioteca de modelos e a ATL também compartilham conceitos como definição de objetos em módulos, registro explícito de interfaces e criação aberta de objetos usando fábricas. Você pode se sentir confortável com C++ Windows Runtime biblioteca de modelos se estiver familiarizado com a ATL.

Windows Runtime C++ biblioteca de modelos dá suporte à funcionalidade com que é necessária para aplicativos UWP. Portanto, ele difere da ATL porque omite o suporte direto para recursos COM, como:

- Aggregation

- implementações de estoque

- interfaces duplas`IDispatch`()

- interfaces de enumerador padrão

- pontos de conexão

- interfaces retiradas

- Inserção de OLE

- Controles ActiveX

- COM+

## <a name="concepts"></a>Conceitos

Windows Runtime C++ biblioteca de modelos fornece tipos que representam alguns conceitos básicos. As seções a seguir descrevem esses tipos.

### <a name="comptr"></a>ComPtr

[ComPtr](comptr-class.md) é um tipo de *ponteiro inteligente* que representa a interface que é especificada pelo parâmetro de modelo. Use `ComPtr` para declarar uma variável que pode acessar os membros de um objeto derivado da interface. `ComPtr`mantém automaticamente uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.

### <a name="runtimeclass"></a>RuntimeClass

[RuntimeClass](runtimeclass-class.md) representa uma classe instanciada que herda um conjunto de interfaces especificadas. Um `RuntimeClass` objeto pode fornecer uma combinação de suporte para uma ou mais interfaces com Windows Runtime ou uma referência fraca a um componente.

### <a name="module"></a>Módulo

O [módulo](module-class.md) representa uma coleção de objetos relacionados. Um `Module` objeto gerencia fábricas de classes, que criam objetos e registro, o que permite que outros aplicativos usem um objeto.

### <a name="callback"></a>Retorno

A função de [retorno de chamada](callback-function-wrl.md) cria um objeto cuja função de membro é um manipulador de eventos (um método de retorno de chamada). Use a `Callback` função para gravar operações assíncronas.

### <a name="eventsource"></a>EventSource

[EventSource](eventsource-class.md) é usado para gerenciar manipuladores de eventos de *Representante* . Use Windows Runtime C++ biblioteca de modelos para implementar um delegado e use `EventSource` para adicionar, remover e invocar delegados.

### <a name="asyncbase"></a>AsyncBase

O [AsyncBase](asyncbase-class.md) fornece métodos virtuais que representam o modelo de programação assíncrona Windows Runtime. Substitua os membros nessa classe para criar uma classe personalizada que possa iniciar, parar ou verificar o progresso de uma operação assíncrona.

### <a name="ftmbase"></a>FtmBase

[FtmBase](ftmbase-class.md) representa um objeto de marshaling com thread livre. `FtmBase`Cria uma tabela de interface global (GIT) e ajuda a gerenciar objetos de marshaling e proxy.

### <a name="weakref"></a>WeakRef

[WeakRef](weakref-class.md) é um tipo de ponteiro inteligente que representa uma *referência fraca*, que faz referência a um objeto que pode ou não estar acessível. Um `WeakRef` objeto pode ser usado apenas pelo Windows Runtime, e não pelo com clássico.

Um `WeakRef` objeto normalmente representa um objeto cuja existência é controlada por um thread ou aplicativo externo. Por exemplo, um `WeakRef` objeto pode fazer referência a um objeto de arquivo. Quando o arquivo é aberto, o `WeakRef` é válido e o arquivo referenciado é acessível. Mas quando o arquivo é fechado, o `WeakRef` é inválido e o arquivo não está acessível.

## <a name="related-topics"></a>Tópicos relacionados

|||
|-|-|
|[Principais APIs por categoria](key-wrl-apis-by-category.md)|Realça os tipos de C++ biblioteca de modelos, funções e macros do Windows Runtime primário.|
|[Referência](wrl-reference.md)|Contém informações de referência para a C++ biblioteca de modelos do Windows Runtime.|
|[Referência C++rápida/CX)](../../cppcx/quick-reference-c-cx.md)|Descreve brevemente os C++recursos do/CX que dão suporte ao Windows Runtime.|
|[Usando componentes Windows Runtime no VisualC++](/windows/uwp/winrt-components/walkthrough-creating-a-basic-windows-runtime-component-in-cpp-and-calling-it-from-javascript-or-csharp)|Mostra como usar C++o/CX para criar um componente Windows Runtime básico.|

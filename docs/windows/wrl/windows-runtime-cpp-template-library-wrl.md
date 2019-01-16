---
title: Biblioteca de Modelos C++ do Windows Runtime  (WRL)
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: b915afce-553b-44a7-b8dc-0ab601758eb0
ms.openlocfilehash: 5c1a4e7df424499f400dbd70d675956deef6bc5d
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335467"
---
# <a name="windows-runtime-c-template-library-wrl"></a>Biblioteca de Modelos C++ do Windows Runtime  (WRL)

A WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows) é uma biblioteca de modelos que fornece uma maneira de baixo nível para criar e usar componente do Windows Runtime.

> [!NOTE]
> WRL agora foi substituído por C + + c++ /CLI WinRT, uma padrão C + + 17 projeção de linguagem para APIs do Windows Runtime. C + + c++ /CLI WinRT está disponível no SDK do Windows 10, versão 1803 em diante. C + + c++ /CLI WinRT é implementado inteiramente em arquivos de cabeçalho e projetado para fornecer acesso de primeira classe à moderna API do Windows.
>
> Com C + + c++ /CLI WinRT, você pode consumir e criar APIs do Windows Runtime usando qualquer compilador que 17 compatível com os padrões C + +. C + + c++ /CLI WinRT normalmente tem um desempenho melhor e produz binários menores do que qualquer outra opção de idioma para o tempo de execução do Windows. Continuaremos a dar suporte a C + + c++ /CLI CX e WRL, mas altamente recomendável que usem novos aplicativos C + + c++ /CLI WinRT. Para obter mais informações, consulte [C + + c++ /CLI WinRT](https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/index).

## <a name="benefits"></a>Benefícios

A biblioteca de modelos de C++ de tempo de execução do Windows permite que você implementar com mais facilidade e consumir componentes do modelo de objeto de componente (COM). Ele fornece técnicas domésticas, como contagem de referência para gerenciar o tempo de vida de objetos e valores HRESULT para determinar se uma operação foi bem-sucedida ou falha de teste. Para poder usar a biblioteca de modelos C++ do Windows Runtime, você deve seguir cuidadosamente essas regras e técnicas.

O C + + c++ /CLI CX é uma maneira de alto nível, com base no idioma usar componentes de tempo de execução do Windows. Tanto a biblioteca de modelos de C++ do Windows Runtime e C + + c++ /CLI CX simplificam a escrita de código para o tempo de execução do Windows, automaticamente, executando tarefas de manutenção do sistema em seu nome.

A biblioteca de modelos de C++ do Windows Runtime e C + + c++ /CX oferece benefícios diferentes. Aqui estão alguns motivos, você talvez queira usar a biblioteca de modelos C++ do Windows Runtime em vez de C + + c++ /CX:

- Biblioteca de modelos de C++ de tempo de execução do Windows adiciona uma pequena abstração sobre o Windows Runtime aplicativo ABI (Interface binária), dando a você a capacidade de controlar o código subjacente para melhor criar ou consumir APIs do Windows Runtime.

- C + + c++ /CX representa valores COM HRESULT como exceções. Se você herdou uma base de código que usa COM, ou um que não usa exceções, você pode achar que a biblioteca de modelos C++ do Windows Runtime é uma maneira mais natural para trabalhar com o tempo de execução do Windows, porque você não precisa usar exceções.

   > [!NOTE]
   > A biblioteca de modelos C++ do Windows Runtime usa valores HRESULT e não lança exceções. Além disso, a biblioteca de modelos C++ do Windows Runtime usa ponteiros inteligentes e o padrão RAII para ajudar a garantir que os objetos sejam destruídos corretamente quando o código do aplicativo gera uma exceção. Para obter mais informações sobre ponteiros inteligentes e RAII, consulte [ponteiros inteligentes](../../cpp/smart-pointers-modern-cpp.md) e [recursos do objetos próprios (RAII)](../../cpp/objects-own-resources-raii.md).

- A finalidade e o design da biblioteca de modelo C++ do Windows Runtime inspirado pela biblioteca ATL (Active Template), que é um conjunto de classes C++ baseadas em modelos que simplifica a programação de objetos COM. Como biblioteca de modelos de C++ do Windows Runtime usa padrão do C++ para encapsular o tempo de execução do Windows, com mais facilidade a porta e interagir com vários componentes COM existentes escritos em ATL para o tempo de execução do Windows. Se você já conhecer o ATL, você pode achar que a programação da biblioteca de modelos de C++ de tempo de execução do Windows é mais fácil.

## <a name="getting-started"></a>Guia de Introdução

Aqui estão alguns recursos que podem ajudá-lo a começar a trabalhar com a biblioteca de modelos C++ do Windows Runtime imediatamente.

[A biblioteca de tempo de execução do Windows (WRL)](https://channel9.msdn.com/Events/Windows-Camp/Developing-Windows-8-Metro-style-apps-in-Cpp/The-Windows-Runtime-Library-WRL-)<br/>
Neste vídeo do Channel 9, saiba mais sobre como a biblioteca de modelos de C++ de tempo de execução do Windows ajuda a que escrever aplicativos da plataforma Universal do Windows (UWP) e como criar e consumir componentes de tempo de execução do Windows.

[Como: Ativar e usar um componente de tempo de execução do Windows](how-to-activate-and-use-a-windows-runtime-component-using-wrl.md)<br/>
Mostra como usar a biblioteca de modelos C++ do Windows Runtime para inicializar o tempo de execução do Windows e ativar e usar um componente de tempo de execução do Windows.

[Como: Executar operações assíncronas](how-to-complete-asynchronous-operations-using-wrl.md)<br/>
Mostra como usar a biblioteca de modelos de C++ de tempo de execução do Windows para iniciar operações assíncronas e executar o trabalho quando as operações forem concluídas.

[Como: Manipular eventos](how-to-handle-events-using-wrl.md)<br/>
Mostra como usar a biblioteca de modelos C++ do Windows Runtime para assinar e manipular os eventos de um objeto de tempo de execução do Windows.

[Passo a passo: Criando um aplicativo UWP usando WRL e Media Foundation](walkthrough-creating-a-windows-store-app-using-wrl-and-media-foundation.md)<br/>
Saiba como criar um aplicativo UWP que usa [Microsoft Media Foundation](/windows/desktop/medfound/microsoft-media-foundation-sdk).

[Como: Criar um componente COM clássico](how-to-create-a-classic-com-component-using-wrl.md)<br/>
Mostra como usar a biblioteca de modelos C++ do Windows Runtime para criar um componente básico COM e uma maneira básica de registrar e consumir o componente COM de um aplicativo da área de trabalho.

[Como: Instanciar componentes WRL diretamente](how-to-instantiate-wrl-components-directly.md)<br/>
Saiba como usar o [Microsoft::WRL::Make](make-function.md) e [Microsoft::WRL::Details::MakeAndInitialize](makeandinitialize-function.md) funções para criar uma instância de um componente do módulo que o define.

[Como: Usar winmdidl.exe e midlrt.exe para criar arquivos. h de metadados do windows](use-winmdidl-and-midlrt-to-create-h-files-from-windows-metadata.md)<br/>
Mostra como consumir componentes personalizados de tempo de execução do Windows do WRL criando um arquivo IDL de metadados. winmd.

[Passo a passo: Conexão usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md)<br/>
Mostra como usar o [IXMLHTTPRequest2](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) e [IXMLHTTPRequest2Callback](/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback) interfaces junto com tarefas enviar solicitações HTTP GET e POST para um serviço web em um aplicativo UWP.

[Exemplo do Bing Maps Trip Optimizer](https://code.msdn.microsoft.com/Bing-Maps-trip-optimizer-c4e037f7)<br/>
Usa o `HttpRequest` que é definido na classe [passo a passo: Conectando usando tarefas e solicitações HTTP XML](../../parallel/concrt/walkthrough-connecting-using-tasks-and-xml-http-requests.md) no contexto de um aplicativo da UWP completo.

[Criando um componente de DLL de tempo de execução do Windows com o exemplo do C++](https://code.msdn.microsoft.com/windowsapps/Creating-a-Windows-Runtime-6c399797)<br/>
Mostra como usar a biblioteca de modelos C++ do Windows Runtime para criar um componente DLL em processo e consumi-lo em C + + c++ /CX, JavaScript e c#.

[Exemplo do jogo marble maze DirectX](https://code.msdn.microsoft.com/windowsapps/DirectX-Marble-Maze-Game-e4806345)<br/>
Demonstra como usar a biblioteca de modelos de C++ de tempo de execução do Windows para gerenciar o tempo de vida de componentes COM, como o DirectX e Media Foundation no contexto de um jogo 3D completo.

[Enviando notificações de brinde do exemplo de aplicativos da área de trabalho](https://code.msdn.microsoft.com/windowsdesktop/Sending-toast-notifications-71e230a2)<br/>
Demonstra como usar a biblioteca de modelos C++ do Windows Runtime para trabalhar com notificações de brinde de um aplicativo da área de trabalho.

## <a name="windows-runtime-c-template-library-compared-to-atl"></a>Biblioteca de modelos C++ do tempo de execução do Windows em comparação comparada da ATL

Biblioteca de modelos de C++ de tempo de execução do Windows se parece com a biblioteca de modelo ativa (ATL) porque você pode usá-lo para criar pequenos e rápidos objetos de COM. Biblioteca de modelos de C++ de tempo de execução do Windows e ATL também compartilham conceitos, como a definição de objetos em módulos, registro explícito de interfaces e abra a criação de objetos usando fábricas. Você pode se sentir confortável com a biblioteca de modelos de C++ de tempo de execução do Windows se você estiver familiarizado com o ATL.

Biblioteca de modelos de C++ de tempo de execução do Windows oferece suporte à funcionalidade COM que é necessária para aplicativos UWP. Portanto, ele difere do ATL porque omite suporte direto para recursos COM tais como:

- aggregation

- implementações fixas

- interfaces duplas (`IDispatch`)

- interfaces do enumerador padrão

- pontos de conexão

- interfaces destacáveis

- Inserção OLE

- Controles ActiveX

- COM+

## <a name="concepts"></a>Conceitos

Biblioteca de modelos de C++ de tempo de execução do Windows fornece tipos que representam alguns conceitos básicos. As seções a seguir descrevem esses tipos.

### <a name="comptr"></a>ComPtr

[ComPtr](comptr-class.md) é um *ponteiro inteligente* tipo que representa a interface que é especificada pelo parâmetro de modelo. Use `ComPtr` para declarar uma variável que pode acessar os membros de um objeto que é derivada da interface. `ComPtr` automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.

### <a name="runtimeclass"></a>RuntimeClass

[RuntimeClass](runtimeclass-class.md) representa uma classe instanciada que herda de um conjunto de interfaces especificadas. Um `RuntimeClass` objeto puder fornecer uma combinação de suporte para uma ou mais interfaces COM tempo de execução do Windows ou uma referência fraca em um componente.

### <a name="module"></a>Módulo

[Módulo](module-class.md) representa uma coleção de objetos relacionados. Um `Module` objeto gerencia as fábricas de classes, que criam objetos e o registro, que permite que outros aplicativos para usar um objeto.

### <a name="callback"></a>retorno de chamada

O [retorno de chamada](callback-function-wrl.md) função cria um objeto cuja função de membro é um manipulador de eventos (um método de retorno de chamada). Use o `Callback` função para gravar operações assíncronas.

### <a name="eventsource"></a>EventSource

[EventSource](eventsource-class.md) é usado para gerenciar *delegar* manipuladores de eventos. Use a biblioteca de modelos de C++ de tempo de execução do Windows para implementar um delegado e usar `EventSource` para adicionar, remover e invocar representantes.

### <a name="asyncbase"></a>AsyncBase

[AsyncBase](asyncbase-class.md) fornece os métodos virtuais que representam o modelo de programação assíncrono do tempo de execução do Windows. Substitua os membros dessa classe para criar uma classe personalizada que podem iniciar, parar ou verificar o progresso de uma operação assíncrona.

### <a name="ftmbase"></a>FtmBase

[FtmBase](ftmbase-class.md) representa um objeto livre de marshaler. `FtmBase` cria uma tabela de interface global (GIT) e ajuda a gerenciar objetos de empacotamento e de proxy.

### <a name="weakref"></a>WeakRef

[WeakRef](weakref-class.md) é um tipo de ponteiro inteligente que representa uma *referência fraca*, que faz referência a um objeto que pode ou não ser acessível. Um `WeakRef` objeto pode ser usado apenas no tempo de execução do Windows e não com clássico.

Um `WeakRef` objeto normalmente representa um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, um `WeakRef` objeto pode fazer referência a um objeto de arquivo. Quando o arquivo está aberto, o `WeakRef` é válido e o arquivo referenciado está acessível. Mas quando o arquivo é fechado, o `WeakRef` é inválido e o arquivo não está acessível.

## <a name="related-topics"></a>Tópicos relacionados

|||
|-|-|
|[APIs de chave por categoria](key-wrl-apis-by-category.md)|Realça os tipos primários de biblioteca de modelos de C++ de tempo de execução do Windows, funções e as macros.|
|[Referência](wrl-reference.md)|Contém informações de referência para a biblioteca de modelos C++ do Windows Runtime.|
|[Referência rápida (tempo de execução do Windows e Visual C++)](../../cppcx/quick-reference-c-cx.md)|Descreve resumidamente a C + + / recursos CX que dão suporte ao tempo de execução do Windows.|
|[Usando componentes de tempo de execução do Windows no Visual C++](/windows/uwp/winrt-components/walkthrough-creating-a-basic-windows-runtime-component-in-cpp-and-calling-it-from-javascript-or-csharp)|Mostra como usar C + + c++ /CX para criar um componente básico do tempo de execução do Windows.|

---
title: 'Instruções passo a passo: criando uma rede de processamento de imagem'
ms.date: 04/25/2019
helpviewer_keywords:
- image-processing networks, creating [Concurrency Runtime]
- creating image-processing networks [Concurrency Runtime]
ms.assetid: 78ccadc9-5ce2-46cc-bd62-ce0f99d356b8
ms.openlocfilehash: 03d95be8fae3565a51811357ed9553c3a2649674
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140765"
---
# <a name="walkthrough-creating-an-image-processing-network"></a>Instruções passo a passo: criando uma rede de processamento de imagem

Este documento demonstra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagens.

A rede determina quais operações executar em uma imagem com base em suas características. Este exemplo usa o modelo de *Dataflow* para rotear imagens por meio da rede. No modelo de fluxo de dados, componentes independentes de um programa se comunicam uns com os outros enviando mensagens. Quando um componente recebe uma mensagem, ele pode executar alguma ação e, em seguida, passar o resultado dessa ação para outro componente. Compare isso com o modelo de *fluxo de controle* , no qual um aplicativo usa estruturas de controle, por exemplo, instruções condicionais, loops e assim por diante, para controlar a ordem das operações em um programa.

Uma rede baseada em Dataflow cria um *pipeline* de tarefas. Cada estágio do pipeline executa simultaneamente parte da tarefa geral. Como analogia, podemos usar uma linha de montagem de automóveis. À medida que cada veículo passa pela linha do assembly, uma estação monta o quadro, outro instala o mecanismo e assim por diante. Ao permitir que vários veículos sejam montados simultaneamente, a linha do assembly fornece uma melhor taxa de transferência do que a montagem de veículos completos, um de cada vez.

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

Leia os seguintes documentos antes de iniciar este passo a passos:

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)

- [Instruções passo a passo: criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)

Também recomendamos que você entenda os conceitos básicos do GDI+ antes de iniciar este passo a passos.

## <a name="top"></a>As

Este passo a passo contém as seguintes seções:

- [Definindo a funcionalidade de processamento de imagens](#functionality)

- [Criando a rede de processamento de imagens](#network)

- [O exemplo completo](#complete)

## <a name="functionality"></a>Definindo a funcionalidade de processamento de imagens

Esta seção mostra as funções de suporte que a rede de processamento de imagens usa para trabalhar com imagens que são lidas do disco.

As funções a seguir, `GetRGB` e `MakeColor`, extraem e combinam os componentes individuais da cor especificada, respectivamente.

[!code-cpp[concrt-image-processing-filter#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_1.cpp)]

A função a seguir, `ProcessImage`, chama o objeto [std:: function](../../standard-library/function-class.md) fornecido para transformar o valor de cor de cada pixel em um objeto de [bitmap](/windows/win32/api/gdiplusheaders/nl-gdiplusheaders-bitmap) GDI+. A função `ProcessImage` usa o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) para processar cada linha do bitmap em paralelo.

[!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_2.cpp)]

As funções a seguir, `Grayscale`, `Sepiatone`, `ColorMask`e `Darken`, chamam a função `ProcessImage` para transformar o valor de cor de cada pixel em um objeto `Bitmap`. Cada uma dessas funções usa uma expressão lambda para definir a transformação de cor de um pixel.

[!code-cpp[concrt-image-processing-filter#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_3.cpp)]

A função a seguir, `GetColorDominance`, também chama a função `ProcessImage`. No entanto, em vez de alterar o valor de cada cor, essa função usa objetos [Concurrency:: combináveis](../../parallel/concrt/reference/combinable-class.md) para computar se o componente de cor vermelho, verde ou azul domina a imagem.

[!code-cpp[concrt-image-processing-filter#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_4.cpp)]

A função a seguir, `GetEncoderClsid`, recupera o identificador de classe para o tipo MIME fornecido de um codificador. O aplicativo usa essa função para recuperar o codificador para um bitmap.

[!code-cpp[concrt-image-processing-filter#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_5.cpp)]

[[Superior](#top)]

## <a name="network"></a>Criando a rede de processamento de imagens

Esta seção descreve como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagens em todas as imagens JPEG (. jpg) em um determinado diretório. A rede executa as seguintes operações de processamento de imagem:

1. Para qualquer imagem criada por Tom, converta em escala de cinza.

1. Para qualquer imagem que tenha vermelho como a cor dominante, remova os componentes verde e azul e, em seguida, escurece-os.

1. Para qualquer outra imagem, aplique o Toning de sépia.

A rede aplica-se somente à primeira operação de processamento de imagem que corresponde a uma dessas condições. Por exemplo, se uma imagem for criada por Tom e tiver vermelho como sua cor dominante, a imagem só será convertida em escala de cinza.

Depois que a rede executa cada operação de processamento de imagem, ela salva a imagem em disco como um arquivo bitmap (. bmp).

As etapas a seguir mostram como criar uma função que implementa essa rede de processamento de imagens e aplica essa rede a todas as imagens JPEG em um determinado diretório.

#### <a name="to-create-the-image-processing-network"></a>Para criar a rede de processamento de imagens

1. Crie uma função, `ProcessImages`, que usa o nome de um diretório no disco.

   [!code-cpp[concrt-image-processing-filter#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_6.cpp)]

1. Na função `ProcessImages`, crie uma variável `countdown_event`. A classe `countdown_event` é mostrada mais adiante neste guia.

   [!code-cpp[concrt-image-processing-filter#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_7.cpp)]

1. Crie um objeto [std:: map](../../standard-library/map-class.md) que associa um objeto `Bitmap` com seu nome de arquivo original.

   [!code-cpp[concrt-image-processing-filter#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_8.cpp)]

1. Adicione o código a seguir para definir os membros da rede de processamento de imagens.

   [!code-cpp[concrt-image-processing-filter#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_9.cpp)]

1. Adicione o código a seguir para conectar a rede.

   [!code-cpp[concrt-image-processing-filter#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_10.cpp)]

1. Adicione o seguinte código para enviar ao início da rede o caminho completo de cada arquivo JPEG no diretório.

   [!code-cpp[concrt-image-processing-filter#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_11.cpp)]

1. Aguarde até que a variável de `countdown_event` alcance zero.

   [!code-cpp[concrt-image-processing-filter#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_12.cpp)]

A tabela a seguir descreve os membros da rede.

|{1&gt;Membro&lt;1}|Descrição|
|------------|-----------------|
|`load_bitmap`|Um objeto [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) que carrega um objeto `Bitmap` do disco e adiciona uma entrada ao objeto `map` para associar a imagem ao seu nome de arquivo original.|
|`loaded_bitmaps`|Um objeto [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) que envia as imagens carregadas para os filtros de processamento de imagem.|
|`grayscale`|Um objeto `transformer` que converte imagens que são criadas por Tom em escala de cinza. Ele usa os metadados da imagem para determinar seu autor.|
|`colormask`|Um objeto `transformer` que remove os componentes de cor verde e azul de imagens que têm vermelho como a cor dominante.|
|`darken`|Um objeto `transformer` que escurece as imagens que têm vermelho como a cor dominante.|
|`sepiatone`|Um objeto `transformer` que aplica Toning de sépia a imagens que não são criadas por Tom e não são predominantemente vermelhas.|
|`save_bitmap`|Um objeto `transformer` que salva o `image` processado em disco como um bitmap. `save_bitmap` recupera o nome do arquivo original do objeto `map` e altera sua extensão de nome de arquivo para. bmp.|
|`delete_bitmap`|Um objeto `transformer` que libera a memória para as imagens.|
|`decrement`|Um objeto [Concurrency:: Call](../../parallel/concrt/reference/call-class.md) que atua como o nó terminal na rede. Ele Decrementa o objeto `countdown_event` para sinalizar para o aplicativo principal que uma imagem foi processada.|

O buffer de mensagens `loaded_bitmaps` é importante porque, como um objeto `unbounded_buffer`, ele oferece `Bitmap` objetos a vários destinatários. Quando um bloco de destino aceita um objeto `Bitmap`, o objeto `unbounded_buffer` não oferece esse `Bitmap` objeto a quaisquer outros destinos. Portanto, a ordem na qual você vincula objetos a um objeto `unbounded_buffer` é importante. Os blocos de mensagens `grayscale`, `colormask`e `sepiatone` usam um filtro para aceitar apenas determinados objetos `Bitmap`. O buffer de mensagens de `decrement` é um destino importante do buffer de mensagens de `loaded_bitmaps` porque ele aceita todos os objetos de `Bitmap` rejeitados pelos outros buffers de mensagens. Um objeto `unbounded_buffer` é necessário para propagar mensagens na ordem. Portanto, um objeto `unbounded_buffer` é bloqueado até que um novo bloco de destino esteja vinculado a ele e aceite a mensagem se nenhum bloco de destino atual aceitar essa mensagem.

Se seu aplicativo exigir que vários blocos de mensagens processem a mensagem, em vez de apenas o bloco de mensagens que primeiro aceita a mensagem, você poderá usar outro tipo de bloco de mensagens, como `overwrite_buffer`. A classe `overwrite_buffer` mantém uma mensagem por vez, mas ela propaga essa mensagem para cada um de seus destinos.

A seguinte ilustração mostra a rede de processamento de imagem:

![Rede de processamento de imagens](../../parallel/concrt/media/concrt_imageproc.png "Rede de processamento de imagens")

O objeto `countdown_event` neste exemplo permite que a rede de processamento de imagens informe o aplicativo principal quando todas as imagens tiverem sido processadas. A classe `countdown_event` usa um objeto [Concurrency:: Event](../../parallel/concrt/reference/event-class.md) para sinalizar quando um valor de contador chegar a zero. O aplicativo principal incrementa o contador toda vez que envia um nome de arquivo para a rede. O nó terminal da rede diminui o contador depois que cada imagem é processada. Depois que o aplicativo principal atravessa o diretório especificado, ele aguarda o objeto `countdown_event` para sinalizar que seu contador atingiu o zero.

O exemplo a seguir mostra a classe `countdown_event`:

[!code-cpp[concrt-image-processing-filter#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_13.cpp)]

[[Superior](#top)]

## <a name="complete"></a>O exemplo completo

O código a seguir mostra um exemplo completo. A função `wmain` gerencia a biblioteca GDI+ e chama a função `ProcessImages` para processar os arquivos JPEG no diretório `Sample Pictures`.

[!code-cpp[concrt-image-processing-filter#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_14.cpp)]

A ilustração a seguir mostra a saída de exemplo. Cada imagem de origem está acima da imagem modificada correspondente.

![Exemplo de saída para o exemplo](../../parallel/concrt/media/concrt_imageout.png "Exemplo de saída para o exemplo")

`Lighthouse` é criado por Tom Alphin e, portanto, é convertido em escala de cinza. `Chrysanthemum`, `Desert`, `Koala`e `Tulips` têm vermelho como a cor dominante e, portanto, têm os componentes de cor azul e verde removidos e ficam mais escuros. `Hydrangeas`, `Jellyfish`e `Penguins` correspondem aos critérios padrão e, portanto, são toned de sépia.

[[Superior](#top)]

### <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `image-processing-network.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/DUNICODE/EHsc Image-Processing-Network. cpp/link Gdiplus. lib**

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

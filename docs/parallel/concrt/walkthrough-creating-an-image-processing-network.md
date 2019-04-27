---
title: 'Passo a passo: Criando uma rede de processamento de imagem'
ms.date: 04/25/2019
helpviewer_keywords:
- image-processing networks, creating [Concurrency Runtime]
- creating image-processing networks [Concurrency Runtime]
ms.assetid: 78ccadc9-5ce2-46cc-bd62-ce0f99d356b8
ms.openlocfilehash: 035d73190f3596044a35cbc45681807801385eab
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62205815"
---
# <a name="walkthrough-creating-an-image-processing-network"></a>Passo a passo: Criando uma rede de processamento de imagem

Este documento demonstra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem.

A rede determina quais operações serão executadas em uma imagem com base em suas características. Este exemplo usa o *fluxo de dados* modelo para encaminhar imagens por meio da rede. No modelo de fluxo de dados, componentes independentes de um programa se comunicam uns com os outros enviando mensagens. Quando um componente recebe uma mensagem, ele pode realizar alguma ação e, em seguida, passar o resultado dessa ação para outro componente. Compare isso com o *fluxo de controle* modelo, em que um aplicativo usa estruturas de controle, por exemplo, instruções condicionais, loops e assim por diante, para controlar a ordem das operações em um programa.

Uma rede com base no fluxo de dados cria uma *pipeline* de tarefas. Cada estágio do pipeline executa simultaneamente a parte da tarefa geral. Como analogia, podemos usar uma linha de montagem de automóveis. Como cada veículo que passa por meio da linha de assembly, uma estação monta a carroceria, outro instala o mecanismo e assim por diante. Habilitando vários veículos sejam montados ao mesmo tempo, a linha de assembly fornece a melhor taxa de transferência que montando veículos completos um por vez.

## <a name="prerequisites"></a>Pré-requisitos

Leia os documentos a seguir antes de começar este passo a passo:

- [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)

- [Como: Usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)

- [Passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)

Também recomendamos que você compreenda as Noções básicas do GDI+ antes de começar este passo a passo.

##  <a name="top"></a> Seções

Este passo a passo contém as seguintes seções:

- [Definindo a funcionalidade de processamento de imagens](#functionality)

- [Criar a rede de processamento de imagem](#network)

- [O exemplo completo](#complete)

##  <a name="functionality"></a> Definindo a funcionalidade de processamento de imagens

Esta seção mostra as funções de suporte que a rede de processamento de imagem usa para trabalhar com imagens que são lidas do disco.

As funções `GetRGB` e `MakeColor`, extraia e combinar os componentes individuais de determinada cor, respectivamente.

[!code-cpp[concrt-image-processing-filter#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_1.cpp)]

A seguinte função, `ProcessImage`, chamadas de determinada [std:: Function](../../standard-library/function-class.md) objeto para transformar o valor de cor de cada pixel em um GDI+ [Bitmap](/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) objeto. O `ProcessImage` função usa o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para processar cada linha do bitmap em paralelo.

[!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_2.cpp)]

As funções `Grayscale`, `Sepiatone`, `ColorMask`, e `Darken`, chamar o `ProcessImage` função para transformar o valor da cor de cada pixel em um `Bitmap` objeto. Cada uma dessas funções usa uma expressão lambda para definir a transformação de cor de um pixel.

[!code-cpp[concrt-image-processing-filter#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_3.cpp)]

A seguinte função, `GetColorDominance`, também chama o `ProcessImage` função. No entanto, em vez de alterar o valor de cada cor, essa função usa [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) objetos para calcular se o componente de cor vermelho, verde ou azul domina a imagem.

[!code-cpp[concrt-image-processing-filter#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_4.cpp)]

A seguinte função, `GetEncoderClsid`, recupera o identificador de classe para determinado tipo MIME de um codificador. O aplicativo usa essa função para recuperar o codificador para um bitmap.

[!code-cpp[concrt-image-processing-filter#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_5.cpp)]

[[Top](#top)]

##  <a name="network"></a> Criar a rede de processamento de imagem

Esta seção descreve como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagens em cada imagem JPEG (. jpg) em um determinado diretório. A rede executa as seguintes operações de processamento de imagem:

1. Para qualquer imagem que é de autoria de Tom, a conversão em escala de cinza.

1. Para qualquer imagem que tenha vermelho como a cor dominante, remova os componentes verdes e azuis e escurecer, em seguida, ele.

1. Para qualquer outra imagem, aplique a coloração sépia.

A rede se aplica somente a primeira operação de processamento de imagens que corresponde a uma dessas condições. Por exemplo, se uma imagem é de autoria de Tom e tem vermelho como sua cor dominante, a imagem somente é convertida em escala de cinza.

Depois que a rede executa cada operação de processamento de imagem, salva a imagem no disco como um arquivo de bitmap (. bmp).

As etapas a seguir mostram como criar uma função que implementa essa rede de processamento de imagens e se aplica a essa rede para cada imagem JPEG em um determinado diretório.

#### <a name="to-create-the-image-processing-network"></a>Para criar a rede de processamento de imagens

1. Criar uma função, `ProcessImages`, que usa o nome de um diretório no disco.

   [!code-cpp[concrt-image-processing-filter#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_6.cpp)]

1. No `ProcessImages` funcionar, crie um `countdown_event` variável. O `countdown_event` classe será mostrada posteriormente neste passo a passo.

   [!code-cpp[concrt-image-processing-filter#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_7.cpp)]

1. Criar uma [std:: Map](../../standard-library/map-class.md) objeto que associa um `Bitmap` objeto com o nome de arquivo original.

   [!code-cpp[concrt-image-processing-filter#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_8.cpp)]

1. Adicione o seguinte código para definir os membros da rede de processamento de imagem.

   [!code-cpp[concrt-image-processing-filter#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_9.cpp)]

1. Adicione o código a seguir para se conectar a rede.

   [!code-cpp[concrt-image-processing-filter#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_10.cpp)]

1. Adicione o seguinte código para enviar ao cabeçalho da rede o caminho completo de cada arquivo JPEG no diretório.

   [!code-cpp[concrt-image-processing-filter#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_11.cpp)]

1. Aguarde até que o `countdown_event` variável atinja zero.

   [!code-cpp[concrt-image-processing-filter#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_12.cpp)]

A tabela a seguir descreve os membros da rede.

|Membro|Descrição|
|------------|-----------------|
|`load_bitmap`|Um [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) objeto que carrega uma `Bitmap` do objeto de disco e adiciona uma entrada para o `map` objeto para associar a imagem com o nome de arquivo original.|
|`loaded_bitmaps`|Um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md) objeto que envia as imagens carregadas para os filtros de processamento de imagem.|
|`grayscale`|Um `transformer` objeto que converte imagens que são criadas com o Tom de cinza. Ele usa os metadados da imagem para determinar seu autor.|
|`colormask`|Um `transformer` objeto que remove os componentes de cor verde e azul de imagens que tenham vermelho como a cor dominante.|
|`darken`|Um `transformer` objeto que escurece imagens que tenham vermelho como a cor dominante.|
|`sepiatone`|Um `transformer` objeto que se aplica a coloração sépia para imagens que não são criadas com o Tom e não são predominantemente vermelhos.|
|`save_bitmap`|Um `transformer` objeto que salva o processado `image` no disco como um bitmap. `save_bitmap` recupera o nome do arquivo original do `map` do objeto e altera sua extensão de nome de arquivo para. bmp.|
|`delete_bitmap`|Um `transformer` objeto que libera a memória para as imagens.|
|`decrement`|Um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto que atua como nó terminal na rede. Ele diminui a `countdown_event` objeto para sinalizar para o aplicativo principal que uma imagem foi processada.|

O `loaded_bitmaps` buffer de mensagem é importante porque, como um `unbounded_buffer` do objeto, ele oferece `Bitmap` objetos para vários destinatários. Quando um bloco de destino aceita uma `Bitmap` objeto, o `unbounded_buffer` objeto não tem que `Bitmap` objeto para todos os outros destinos. Portanto, a ordem na qual você vincula objetos para um `unbounded_buffer` objeto é importante. O `grayscale`, `colormask`, e `sepiatone` mensagem blocos cada usam um filtro para aceitar apenas determinados `Bitmap` objetos. O `decrement` buffer de mensagem é um destino importante do `loaded_bitmaps` buffer de mensagens porque ele aceita todos `Bitmap` objetos que são rejeitados pelo buffers de mensagem. Um `unbounded_buffer` objeto é necessária para propagar as mensagens na ordem. Portanto, um `unbounded_buffer` objeto bloqueia até que um novo bloco de destino está vinculado a ele e aceita a mensagem se nenhum bloco de destino atual aceite essa mensagem.

Se seu aplicativo requer que mensagens múltiplas bloqueia o processo da mensagem, em vez de apenas o bloco de uma mensagem que aceita pela primeira vez a mensagem, você pode usar outro tipo de bloco de mensagem, como `overwrite_buffer`. O `overwrite_buffer` classe contém uma mensagem por vez, mas ele se propaga essa mensagem para cada um dos seus destinos.

A seguinte ilustração mostra a rede de processamento de imagem:

![Rede de processamento de imagem](../../parallel/concrt/media/concrt_imageproc.png "rede de processamento de imagem")

O `countdown_event` objeto neste exemplo permite que a rede de processamento de imagem informar o aplicativo principal quando todas as imagens tenham sido processadas. O `countdown_event` classe usa um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto para sinalizar quando um valor de contador chega a zero. O aplicativo principal incrementa o contador toda vez que ele envia um nome de arquivo para a rede. Nó terminal do diminui a rede o contador após o processamento de cada imagem. Depois que o aplicativo principal atravessa o diretório especificado, ele aguarda o `countdown_event` objeto para sinalizar que o seu contador chegou a zero.

A exemplo a seguir mostra o `countdown_event` classe:

[!code-cpp[concrt-image-processing-filter#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_13.cpp)]

[[Top](#top)]

##  <a name="complete"></a> O exemplo completo

O código a seguir mostra um exemplo completo. O `wmain` gerencia a função de biblioteca de GDI+ e chama o `ProcessImages` arquivos de função para processar o JPEG no `Sample Pictures` directory.

[!code-cpp[concrt-image-processing-filter#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_14.cpp)]

A ilustração a seguir mostra um exemplo de saída. Cada imagem de origem é acima de seu correspondente imagem modificada.

![Exemplo de saída para o exemplo](../../parallel/concrt/media/concrt_imageout.png "exemplo de saída para o exemplo")

`Lighthouse` é de autoria de Tom Alphin e, portanto, é convertido em escala de cinza. `Chrysanthemum`, `Desert`, `Koala`, e `Tulips` têm vermelho como a cor dominante e, portanto, os componentes de cor azul e verde removidos e são escurecidos. `Hydrangeas`, `Jellyfish`, e `Penguins` correspondem aos critérios padrão e, portanto, sépia toned.

[[Top](#top)]

### <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `image-processing-network.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /DUNICODE /EHsc image-processing-network.cpp /link gdiplus.lib**

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

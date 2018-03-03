---
title: 'Passo a passo: Criando uma rede de processamento de imagem | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- image-processing networks, creating [Concurrency Runtime]
- creating image-processing networks [Concurrency Runtime]
ms.assetid: 78ccadc9-5ce2-46cc-bd62-ce0f99d356b8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7b709179cb5bc0fefa3f342374c792656fa1e934
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-creating-an-image-processing-network"></a>Instruções passo a passo: criando uma rede de processamento de imagem
Este documento demonstra como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem.  
  
 A rede determina quais operações a serem executadas em uma imagem com base em suas características. Este exemplo usa o *fluxo de dados* modelo para imagens de rota por meio da rede. No modelo de fluxo de dados, componentes independentes de um programa se comunicar uns com os outros enviando mensagens. Quando um componente recebe uma mensagem, ele pode executar alguma ação e, em seguida, passe o resultado dessa ação para outro componente. Compare isso com o *fluxo de controle* modelo, em que um aplicativo usa estruturas de controle, por exemplo, instruções condicionais, loops e assim por diante, para controlar a ordem das operações em um programa.  
  
 Uma rede com base no fluxo de dados cria um *pipeline* de tarefas. Cada estágio do pipeline executa simultaneamente a parte da tarefa geral. Uma analogia para isso é uma linha de montagem para fabricação automóvel. Como cada veículo passa por meio da linha de assembly, uma estação monta o quadro, outro instala o mecanismo e assim por diante. Habilitando vários veículos ser montadas simultaneamente, a linha de assembly fornece melhor taxa de transferência que montar veículos completos um por vez.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os documentos a seguir antes de iniciar esta explicação passo a passo:  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
  
-   [Instruções passo a passo: criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)  
  
 Também é recomendável que você compreenda as Noções básicas de [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] antes de começar este passo a passo.  
  
##  <a name="top"></a>Seções  
 Este passo a passo contém as seguintes seções:  
  
-   [Definindo a funcionalidade de processamento de imagem](#functionality)  
  
-   [Criar a rede de processamento de imagem](#network)  
  
-   [O exemplo completo](#complete)  
  
##  <a name="functionality"></a>Definindo a funcionalidade de processamento de imagem  
 Esta seção mostra as funções de suporte que usa a rede de processamento de imagem para trabalhar com imagens que são lidas do disco.  
  
 As funções a seguir, `GetRGB` e `MakeColor`, extrair e combinar os componentes individuais de determinada cor, respectivamente.  
  
 [!code-cpp[concrt-image-processing-filter#2](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_1.cpp)]  
  

 A função a seguir, `ProcessImage`, chamadas de determinado [std:: Function](../../standard-library/function-class.md) objeto para transformar o valor da cor de cada pixel em um [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] [Bitmap](https://msdn.microsoft.com/library/ms534420.aspx) objeto. O `ProcessImage` função usa o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para processar cada linha do bitmap em paralelo.  

  
 [!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_2.cpp)]  
  
 As funções a seguir, `Grayscale`, `Sepiatone`, `ColorMask`, e `Darken`, chame o `ProcessImage` função para transformar o valor da cor de cada pixel em um `Bitmap` objeto. Cada uma dessas funções usa uma expressão lambda para definir a transformação de cor de um pixel.  
  
 [!code-cpp[concrt-image-processing-filter#4](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_3.cpp)]  
  
 A função a seguir, `GetColorDominance`, também chamadas de `ProcessImage` função. No entanto, em vez de alterar o valor de cada cor, essa função usa [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) objetos para calcular se o componente de cor verde, vermelho ou azul domina a imagem.  
  
 [!code-cpp[concrt-image-processing-filter#5](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_4.cpp)]  
  
 A função a seguir, `GetEncoderClsid`, recupera o identificador de classe para determinado tipo MIME de um codificador. O aplicativo usa essa função para recuperar o codificador para um bitmap.  
  
 [!code-cpp[concrt-image-processing-filter#6](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_5.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="network"></a>Criar a rede de processamento de imagem  
 Esta seção descreve como criar uma rede de blocos de mensagens assíncronas que executam o processamento de imagem em cada [!INCLUDE[TLA#tla_jpeg](../../parallel/concrt/includes/tlasharptla_jpeg_md.md)] imagem (. jpg) em um determinado diretório. A rede realiza as seguintes operações de processamento de imagem:  
  
1.  Para qualquer imagem que foi criada por Tom, converta em escala de cinza.  
  
2.  Para qualquer imagem que tenha vermelho como a cor dominante, remova os componentes de verdes e azuis e escureça, em seguida, ele.  
  
3.  Para qualquer outra imagem, aplica coloração sépia.  
  
 A rede se aplica somente a primeira operação de processamento de imagem que corresponde a uma das seguintes condições. Por exemplo, se uma imagem é criada por Tom e tem vermelho como sua cor dominante, a imagem somente é convertida em escala de cinza.  
  
 Depois que a rede executa cada operação de processamento de imagem, ele salva a imagem de disco como um arquivo de bitmap (bmp).  
  
 As etapas a seguir mostram como criar uma função que implementa essa rede de processamento de imagem e aplica-se a essa rede para cada [!INCLUDE[TLA#tla_jpeg](../../parallel/concrt/includes/tlasharptla_jpeg_md.md)] imagem em um determinado diretório.  
  
#### <a name="to-create-the-image-processing-network"></a>Para criar a rede de processamento de imagem  
  
1.  Criar uma função, `ProcessImages`, que usa o nome de um diretório no disco.  
  
     [!code-cpp[concrt-image-processing-filter#7](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_6.cpp)]  
  
2.  No `ProcessImages` funcionar, crie um `countdown_event` variável. O `countdown_event` classe é mostrada mais adiante neste passo a passo.  
  
     [!code-cpp[concrt-image-processing-filter#8](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_7.cpp)]  
  
3.  Criar um [std:: Map](../../standard-library/map-class.md) objeto que associa um `Bitmap` objeto com o nome de arquivo original.  
  
     [!code-cpp[concrt-image-processing-filter#9](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_8.cpp)]  
  
4.  Adicione o código a seguir para definir os membros da rede de processamento de imagem.  
  
     [!code-cpp[concrt-image-processing-filter#10](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_9.cpp)]  
  
5.  Adicione o código a seguir para conectar-se a rede.  
  
     [!code-cpp[concrt-image-processing-filter#11](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_10.cpp)]  
  
6.  Adicione o seguinte código para enviar para o início da rede, o caminho completo de cada [!INCLUDE[TLA#tla_jpeg](../../parallel/concrt/includes/tlasharptla_jpeg_md.md)] arquivo no diretório.  
  
     [!code-cpp[concrt-image-processing-filter#12](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_11.cpp)]  
  
7.  Aguarde até que o `countdown_event` variável para chegar a zero.  
  
     [!code-cpp[concrt-image-processing-filter#13](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_12.cpp)]  
  
 A tabela a seguir descreve os membros da rede.  
  
|Membro|Descrição|  
|------------|-----------------|  
|`load_bitmap`|Um [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) objeto carrega um `Bitmap` de objeto de disco e adiciona uma entrada para o `map` objeto para associar a imagem com o nome de arquivo original.|  
|`loaded_bitmaps`|Um [concurrency::unbounded_buffer](reference/unbounded-buffer-class.md) objeto que envia as imagens carregadas para os filtros de processamento de imagem.|  
|`grayscale`|Um `transformer` objeto que converte as imagens que são criadas por Tom de cinza. Ele usa os metadados da imagem para determinar seu autor.|  
|`colormask`|Um `transformer` objeto que remove os componentes de cor verde e azul de imagens que tenham vermelho como a cor dominante.|  
|`darken`|Um `transformer` objeto escurece imagens que tenham vermelho como a cor dominante.|  
|`sepiatone`|Um `transformer` objeto que se aplica a coloração sépia para imagens que não são criadas por Tom e não são predominantemente vermelho.|  
|`save_bitmap`|Um `transformer` objeto que salva o processado `image` no disco como um bitmap. `save_bitmap`recupera o nome de arquivo original do `map` do objeto e altera sua extensão de nome de arquivo para. bmp.|  
|`delete_bitmap`|Um `transformer` objeto que libera a memória para as imagens.|  
|`decrement`|Um [concurrency::call](../../parallel/concrt/reference/call-class.md) objeto que atua como o nó terminal na rede. Ele diminui a `countdown_event` objeto para sinalizar para o aplicativo principal que uma imagem foi processada.|  
  
 O `loaded_bitmaps` buffer de mensagem é importante porque, como um `unbounded_buffer` do objeto, ele oferece `Bitmap` objetos para vários destinatários. Quando um bloco de destino aceita um `Bitmap` objeto, o `unbounded_buffer` objeto não tem que `Bitmap` objeto para todos os outros destinos. Portanto, a ordem na qual você vincula objetos para um `unbounded_buffer` objeto é importante. O `grayscale`, `colormask`, e `sepiatone` mensagem blocos cada usam um filtro para aceitar apenas determinados `Bitmap` objetos. O `decrement` buffer de mensagem é um destino importante do `loaded_bitmaps` buffer de mensagem porque ele aceita todos os `Bitmap` objetos que foram rejeitados pelo buffers de mensagem. Um `unbounded_buffer` objeto é necessário para propagar as mensagens na ordem. Portanto, um `unbounded_buffer` objeto bloqueia até que um novo bloco de destino está vinculado a ele e aceita a mensagem se nenhum bloco de destino atual aceita essa mensagem.  
  
 Se seu aplicativo requer que essa mensagem de vários blocos processar a mensagem, em vez de apenas o bloco de uma mensagem que primeiro aceita a mensagem, você pode usar outro tipo de bloco de mensagens, como `overwrite_buffer`. O `overwrite_buffer` classe contém uma mensagem por vez, mas ele propaga essa mensagem para cada um de seus destinos.  
  
 A ilustração a seguir mostra a rede de processamento de imagem:  
  
 ![Rede de processamento de imagem](../../parallel/concrt/media/concrt_imageproc.png "concrt_imageproc")  
  
 O `countdown_event` objeto neste exemplo permite que a rede de processamento de imagem informar o aplicativo principal quando todas as imagens foram processadas. O `countdown_event` classe usa um [concurrency::event](../../parallel/concrt/reference/event-class.md) objeto para sinalizar quando um valor de contador chega a zero. O aplicativo principal incrementa o contador toda vez que ele envia um nome de arquivo para a rede. O nó terminal de diminui a rede contador após o processamento de cada imagem. Depois que o aplicativo principal atravessa o diretório especificado, ele aguarda o `countdown_event` objeto para sinalizar que seu contador chegou a zero.  
  
 A exemplo a seguir mostra o `countdown_event` classe:  
  
 [!code-cpp[concrt-image-processing-filter#14](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_13.cpp)]  
  
 [[Superior](#top)]  
  
##  <a name="complete"></a>O exemplo completo  
 O código a seguir mostra um exemplo completo. O `wmain` função gerencia o [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] biblioteca e chamadas a `ProcessImages` função para processar o [!INCLUDE[TLA#tla_jpeg](../../parallel/concrt/includes/tlasharptla_jpeg_md.md)] arquivos no `Sample Pictures` diretório.  
  
 [!code-cpp[concrt-image-processing-filter#15](../../parallel/concrt/codesnippet/cpp/walkthrough-creating-an-image-processing-network_14.cpp)]  
  
 A ilustração a seguir mostra um exemplo de saída. Cada imagem de origem está acima de sua imagem modificada correspondente.  
  
 ![Exemplo de saída para o exemplo](../../parallel/concrt/media/concrt_imageout.png "concrt_imageout")  
  
 `Lighthouse`é criado por Tom Alphin e, portanto, é convertido em escala de cinza. `Chrysanthemum`, `Desert`, `Koala`, e `Tulips` têm vermelho como a cor dominante e, portanto, os componentes de cor verde e azul removidos e são escurecidos. `Hydrangeas`, `Jellyfish`, e `Penguins` correspondem aos critérios padrão e, portanto, sépia toned.  
  
 [[Superior](#top)]  
  
### <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `image-processing-network.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /DUNICODE /EHsc /link network.cpp de processamento de imagem gdiplus.lib**  
  
## <a name="see-also"></a>Consulte também  
 [Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)

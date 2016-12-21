---
title: "Instru&#231;&#245;es passo a passo: criando uma rede de processamento de imagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "criando redes de processamento de imagem [Tempo de Execução de Simultaneidade]"
  - "redes de processamento de imagem, criando [Tempo de Execução de Simultaneidade]"
ms.assetid: 78ccadc9-5ce2-46cc-bd62-ce0f99d356b8
caps.latest.revision: 15
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando uma rede de processamento de imagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento demonstra como criar uma rede dos blocos assíncronas de mensagem que executam o processamento de imagem.  
  
 A rede determina quais operações em execução em uma imagem com base em suas características.  Este exemplo usa o modelo *de fluxo de dados* para rotear imagens pela rede.  No modelo de fluxo de dados, os componentes independentes de um programa um com o outro se comunicam enviando mensagens.  Quando um componente recebe uma mensagem, pode executar qualquer ação e depois passe o resultado dessa ação a outro componente.  Compare com o modelo *de fluxo de controle* , em que um aplicativo usa estruturas de controle, por exemplo, instruções condicionais, loop, e assim por diante, para controlar a ordem das operações em um programa.  
  
 Uma rede baseada no fluxo de dados cria *um pipeline* de tarefas.  Cada fase de pipeline é executada simultaneamente a parte da tarefa total.  Uma analogia a esta é uma cadeia de fabricação para a produção auto.  Conforme cada veículo passa pela cadeia de produção, uma estação monta o quadro, outro instalar o mecanismo, e assim por diante.  Habilitando os vários veículos a ser montados simultaneamente, a cadeia de produção fornece melhor transferência do que veículos completos de montagem um de cada vez.  
  
## Pré-requisitos  
 Leia os seguintes documentos antes de iniciar esta explicação passo a passo:  
  
-   [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)  
  
-   [Como usar um filtro de bloco de mensagens](../../parallel/concrt/how-to-use-a-message-block-filter.md)  
  
-   [Instruções passo a passo: criando um agente de fluxo de dados](../Topic/Walkthrough:%20Creating%20a%20Dataflow%20Agent.md)  
  
 Recomendamos também inclui os fundamentos de [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] antes de começar este passo a passo.  Para obter mais informações sobre como [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)], consulte [GDI\+](_gdiplus_GDI_start_cpp).  
  
##  <a name="top"></a> Seções  
 Essa explicação passo a passo contém as seguintes seções:  
  
-   [Definindo a funcionalidade de processamento de imagem](#functionality)  
  
-   [Criando a rede de processamento de imagem](#network)  
  
-   [O Exemplo Completo](#complete)  
  
##  <a name="functionality"></a> Definindo a funcionalidade de processamento de imagem  
 Esta seção mostra o suporte que suportam a rede de processamento de imagem trabalhar com imagens que são lidos do disco.  
  
 As seguintes funções, `GetRGB` e `MakeColor`, extração e combinam os componentes individuais de cor especificada, respectivamente.  
  
 [!code-cpp[concrt-image-processing-filter#2](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_1.cpp)]  
  
 A seguinte função, `ProcessImage`, chama o objeto determinado de [std::function](../../standard-library/function-class.md) para converter o valor da cor de cada x em um objeto de [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)][Bitmap](https://msdn.microsoft.com/en-us/library/ms534420.aspx) .  A função de `ProcessImage` usa o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) para processar em paralelo cada linha de bitmap.  
  
 [!code-cpp[concrt-image-processing-filter#3](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_2.cpp)]  
  
 As seguintes funções, `Grayscale`, `Sepiatone`, `ColorMask`, e `Darken`, chame a função de `ProcessImage` para converter o valor da cor de cada x em um objeto de `Bitmap` .  Cada uma dessas funções a seguir usa uma expressão de lambda para definir a transformação cor de um x.  
  
 [!code-cpp[concrt-image-processing-filter#4](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_3.cpp)]  
  
 A seguinte função, `GetColorDominance`, também chama a função de `ProcessImage` .  Porém, em vez de alterar o valor de cada cor, essa função usa objetos de [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) para computar se o componente, verde, vermelho ou azul de cor corresponde ao mestre a imagem.  
  
 [!code-cpp[concrt-image-processing-filter#5](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_4.cpp)]  
  
 A seguinte função, `GetEncoderClsid`, recupera o identificador da classe para o determinado tipo MIME de um codificador.  O aplicativo usa essa função para recuperar o codificador para um bitmap.  
  
 [!code-cpp[concrt-image-processing-filter#6](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_5.cpp)]  
  
 \[[Superior](#top)\]  
  
##  <a name="network"></a> Criando a rede de processamento de imagem  
 Esta seção descreve como criar uma rede dos blocos assíncronas de mensagem que executam o processamento de imagem em cada foto de [!INCLUDE[TLA#tla_jpeg](../Token/TLA%23tla_jpeg_md.md)]\(.jpg\) em um diretório especificado.  A rede executa as seguintes operações de processamento com:  
  
1.  Para qualquer imagem que é criada por Tom, converta à escala de cinza.  
  
2.  Para qualquer imagem que tenha vermelho como a cor dominante, remova os componentes verde e azul e escureça\-os em.  
  
3.  Para qualquer outra imagem, aplique a tonificação de sepia.  
  
 A rede aplica apenas a primeira operação de processamento que corresponde a uma destas condições.  Por exemplo, se uma imagem é criada por Tom e red como a cor dominante, a imagem é convertida apenas à escala de cinza.  
  
 Depois que a cada rede executa a operação de processamento, salva a imagem no disco como um arquivo de bitmap \(.bmp\).  
  
 As etapas a seguir mostram como criar uma função que implementa essa rede de processamento de imagem e rede que se aplicam a cada foto de [!INCLUDE[TLA#tla_jpeg](../Token/TLA%23tla_jpeg_md.md)] em um diretório especificado.  
  
#### Para criar a rede de processamento de imagem  
  
1.  Crie uma função, `ProcessImages`, que usa o nome de um diretório no disco.  
  
     [!code-cpp[concrt-image-processing-filter#7](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_6.cpp)]  
  
2.  Na função de `ProcessImages` , crie uma variável de `countdown_event` .  A classe de `countdown_event` é exibida mais adiante neste passo a passo.  
  
     [!code-cpp[concrt-image-processing-filter#8](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_7.cpp)]  
  
3.  Crie um objeto de [std::map](../Topic/map%20Class.md) que associa um objeto de `Bitmap` pelo nome de arquivo original.  
  
     [!code-cpp[concrt-image-processing-filter#9](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_8.cpp)]  
  
4.  Adicione o código a seguir para definir os membros da rede de processamento.  
  
     [!code-cpp[concrt-image-processing-filter#10](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_9.cpp)]  
  
5.  Adicione o código a seguir para conectar\-se a rede.  
  
     [!code-cpp[concrt-image-processing-filter#11](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_10.cpp)]  
  
6.  Adicione o seguinte código para enviar ao início da rede o caminho completo de todos os arquivos de [!INCLUDE[TLA#tla_jpeg](../Token/TLA%23tla_jpeg_md.md)] no diretório.  
  
     [!code-cpp[concrt-image-processing-filter#12](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_11.cpp)]  
  
7.  Aguarde a variável de `countdown_event` para alcançar zero.  
  
     [!code-cpp[concrt-image-processing-filter#13](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_12.cpp)]  
  
 A tabela a seguir descreve os membros de rede.  
  
|Membro|Descrição|  
|------------|---------------|  
|`load_bitmap`|Um objeto de [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) que carrega um objeto de `Bitmap` de disco e adiciona uma entrada ao objeto de `map` para associar a imagem com seu nome de arquivo original.|  
|`loaded_bitmaps`|Um objeto de [concurrency::unbounded\_buffer](../Topic/unbounded_buffer%20Class.md) que envia as imagens carregadas ao processamento de imagem filtros.|  
|`grayscale`|Um objeto de `transformer` que converte de imagens que são criadas por Tom à escala de cinza.  Usa os metadados de imagem para determinar o autor.|  
|`colormask`|Um objeto de `transformer` que remove os componentes verde e azul de cor das imagens que têm vermelho como a cor dominante.|  
|`darken`|Um objeto de `transformer` esmaece que as imagens que têm vermelho como a cor dominante.|  
|`sepiatone`|Um objeto de `transformer` que aplica o sepia que tonifica imagens que não são criadas por Tom e não são frequente vermelhas.|  
|`save_bitmap`|Um objeto de `transformer` que salva `image` processado no disco como um bitmap.  `save_bitmap` recupera o nome de arquivo original do objeto de `map` e alterar sua extensão de nome de arquivo como .bmp.|  
|`delete_bitmap`|Um objeto de `transformer` que libera memória para as imagens.|  
|`decrement`|Um objeto de [concurrency::call](../../parallel/concrt/reference/call-class.md) que atue como o nó terminal na rede.  Diminui o objeto de `countdown_event` ao sinal para o aplicativo principal que uma imagem esteve processada.|  
  
 O buffer de mensagem de `loaded_bitmaps` é importante porque, como um objeto de `unbounded_buffer` , oferece objetos de `Bitmap` a vários destinatários.  Quando um bloco de destino aceita um objeto de `Bitmap` , o objeto de `unbounded_buffer` não oferece que objeto de `Bitmap` com qualquer outro destinos.  Consequentemente, a ordem na qual você vincular objetos a um objeto de `unbounded_buffer` é importante.  `grayscale`, `colormask`, e a mensagem de `sepiatone` bloqueiam usam cada um filtro só aceitar determinado `Bitmap` objeto.  O buffer de mensagem de `decrement` é importante um destino de buffer de mensagem de `loaded_bitmaps` como aceita todos os objetos de `Bitmap` que são rejeitados por outros buffers de mensagem.  Um objeto de `unbounded_buffer` é necessário propagar mensagens na ordem.  Consequentemente, blocos de um objeto de `unbounded_buffer` até um novo pacote de destino ele esteja vinculado e aceitar a mensagem se nenhum pacote atual de destino aceita essa mensagem.  
  
 Se seu aplicativo requer que os blocos de mensagens múltiplas processa a mensagem, em vez de apenas um bloco de mensagem que aceita primeiro a mensagem, você pode usar outra mensagem em blocos, como `overwrite_buffer`.  A classe de `overwrite_buffer` contém uma mensagem de cada vez, mas propaga essa mensagem a cada um de seus destinos.  
  
 A ilustração a seguir mostra a rede de processamento de imagem:  
  
 ![A rede de processamento de imagem](../Image/ConcRT_ImageProc.png "ConcRT\_ImageProc")  
  
 O objeto de `countdown_event` neste exemplo permite a rede de processamento de imagem para informar o aplicativo principal quando todas as imagens foram processadas.  A classe de `countdown_event` usa um objeto de [concurrency::event](../Topic/event%20Class.md) para sinalizar quando alcança o contador zero de um valor.  O aplicativo principal incrementa o contador sempre que envia um nome de arquivo na rede.  O nó terminal de rede diminui o contador depois que cada foto foi processada.  Depois que o aplicativo principal atravessa o diretório especificado, aguarda o objeto de `countdown_event` para sinalizar que seu contador atingiu zero.  
  
 O exemplo a seguir mostra a classe de `countdown_event` :  
  
 [!code-cpp[concrt-image-processing-filter#14](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_13.cpp)]  
  
 \[[Superior](#top)\]  
  
##  <a name="complete"></a> O Exemplo Completo  
 O código a seguir mostra o exemplo completo.  A função de `wmain` gerencia a biblioteca de [!INCLUDE[ndptecgdiplus](../../parallel/concrt/includes/ndptecgdiplus_md.md)] e chama a função de `ProcessImages` para processar os arquivos de [!INCLUDE[TLA#tla_jpeg](../Token/TLA%23tla_jpeg_md.md)] no diretório de `Imagens de exemplo` .  
  
 [!code-cpp[concrt-image-processing-filter#15](../../parallel/concrt/codesnippet/CPP/walkthrough-creating-an-image-processing-network_14.cpp)]  
  
 A ilustração a seguir mostra a saída de exemplo.  Cada foto de origem está acima da imagem alterada correspondentes.  
  
 ![Exemplo de saída de exemplo](../../parallel/concrt/media/concrt_imageout.png "ConcRT\_ImageOut")  
  
 `Farol` é criado por Alphin Tom e como consequência convertido na escala de cinza.  `Crisântemo`, `Deserto`, `Koala`, e `Tulips` têm vermelho como a cor dominante e tem como consequência os componentes da cor verde e azul e são removidos escurecidos.  `Hortênsias`, `Medusa`, e correspondência de `Penguins` os critérios padrão e são consequentemente sepia tonificado.  
  
 \[[Superior](#top)\]  
  
### Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `image-processing-network.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/DUNICODE \/EHsc image\-processing\-network.cpp \/link gdiplus.lib**  
  
## Consulte também  
 [Instruções passo a passo do Tempo de Execução de Simultaneidade](../Topic/Concurrency%20Runtime%20Walkthroughs.md)
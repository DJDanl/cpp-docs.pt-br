---
title: "Altera&#231;&#227;o do c&#243;digo de desenho (Tutorial ATL, parte 4) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macro _ATL_MIN_CRT"
ms.assetid: 08ff14e8-aa49-4139-a110-5d071939cf1e
caps.latest.revision: 18
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Altera&#231;&#227;o do c&#243;digo de desenho (Tutorial ATL, parte 4)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, o código de desenho do controle exibe um quadrado e o texto **PolyCtl**.  Em esta etapa, você irá alterar o código para exibir algo interessante.  As seguintes tarefas são involvidas:  
  
-   Alterando o cabeçalho Arquivo  
  
-   Alterando a função de `OnDraw`  
  
-   Adicionando um método para calcular os pontos polygon  
  
-   Inicializando a cor de preenchimento  
  
## Alterando o cabeçalho Arquivo  
 Início adicionando\-se suporte para funções matemáticas `sin` e `cos`, que serão usados calculam os pontos de polígonos, e criar uma matriz para armazenar posições.  
  
#### Para modificar o arquivo de cabeçalho  
  
1.  Adicione a linha `#include <math.h>` à parte superior de PolyCtl.h.  A parte superior do arquivo deve ser assim:  
  
     [!code-cpp[NVC_ATL_Windowing#47](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_1.cpp)]  
  
2.  Uma vez que os pontos polygon são calculados, serão armazenados em uma matriz do tipo `POINT`, para adicionar a matriz após a definição de `m_nSides` em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#48](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_2.h)]  
  
## Alterando o método de OnDraw  
 Agora você deve modificar o método de `OnDraw` em PolyCtl.h.  O código que você adicionará cria uma nova caneta e pincel para desenhar com que seu polígonos, e então chama funções de `Ellipse` e de `Polygon` API do Win32 para executar desenho real.  
  
#### Para alterar a função de OnDraw  
  
1.  Substitua o método existente de `OnDraw` em PolyCtl.h com o seguinte código:  
  
     [!code-cpp[NVC_ATL_Windowing#49](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_3.cpp)]  
  
## Adicionando um método para calcular os pontos polygon  
 Adicione um método, `CalcPoints`chamado, calculará que as coordenadas de pontos que compõem o perímetro polígono.  Esses serão baseados em cálculos variável RECT que é passado para a função.  
  
#### Para adicionar o método de CalcPoints  
  
1.  Adicione a declaração de `CalcPoints` a seção pública de `IPolyCtl` da classe de `CPolyCtl` em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#50](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_4.h)]  
  
     A última parte da seção da classe pública de `CPolyCtl` deve se parecer como este:  
  
     [!code-cpp[NVC_ATL_Windowing#51](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_5.h)]  
  
2.  Adicionar essa implementação de função de `CalcPoints` ao final de PolyCtl.cpp:  
  
     [!code-cpp[NVC_ATL_Windowing#52](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_6.cpp)]  
  
## Inicializando a cor de preenchimento  
 Inicializar `m_clrFillColor` com uma cor padrão.  
  
#### Para inicializar a cor de preenchimento  
  
1.  Use o verde como a cor padrão adicionar essa linha para o construtor de `CPolyCtl` em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#53](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_7.h)]  
  
 O construtor agora tem a seguinte aparência:  
  
 [!code-cpp[NVC_ATL_Windowing#54](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_8.h)]  
  
## Compilação e teste o controle  
 Crie o controle.  Certifique\-se de que o arquivo PolyCtl.htm é fechado ainda está aberto, e clique em **Compile o polígonos** no menu de **Compilar** .  Você pode exibir o controle mais uma vez da página PolyCtl.htm, mas esse uso de tempo o contêiner de teste de controle ActiveX.  
  
#### Para usar o recipiente de teste do controle ActiveX  
  
1.  Criar e ligue o contêiner de teste de controle ActiveX.  Para obter mais informações, consulte [exemplo de TSTCON: Recipiente de teste do controle ActiveX](../top/visual-cpp-samples.md).  
  
2.  Em o contêiner de teste, no menu de **Editar** , clique em **Novo controle de inserção**.  
  
3.  Localize o controle, que será chamado `PolyCtl Class`, e clique **OK**.  Você verá um triângulo em um círculo verde.  
  
 Tente alterar o número de lados seguindo o procedimento a seguir.  Para alterar as propriedades de uma interface dupla de dentro do contêiner de teste, use **Invoke Methods**.  
  
#### Para alterar a propriedade de um controle dentro do contêiner de teste  
  
1.  Em o contêiner de teste, clique **Chamar métodos** no menu de **Controle** .  
  
     a caixa de diálogo de **Método invoke** é exibida.  
  
2.  Selecione a versão de **PropPut** da propriedade de **Sides** da lista suspensa de **Nome do Método** .  
  
3.  Digite `5` na caixa de **Valor do Parâmetro** , clique **Definir valor**, e clique **Invoke**.  
  
 Observe que o controle não muda.  Embora você altera o número de lados internamente definir a variável de `m_nSides` , isso não fez com que o controle repintasse.  Se você muda para outro aplicativo e alterne de volta para o contêiner de teste, você verá que o controle repintou e tem o número correto de lados.  
  
 Para corrigir esse problema, adicione uma chamada para a função de `FireViewChange` , definida em `IViewObjectExImpl`, após você definir o número de lados.  Se o controle está sendo executado em sua própria janela, `FireViewChange` chamar o método de `InvalidateRect` diretamente.  Se o controle é executado sem janelas, o método será chamado de `InvalidateRect` a interface do site do recipiente.  Isso força o controle para repintar\-se.  
  
#### Para adicionar uma chamada para FireViewChange  
  
1.  Atualizar PolyCtl.cpp adicionando a chamada a `FireViewChange` para o método de `put_Sides` .  Quando você terminar, o método de `put_Sides` deve ser assim:  
  
     [!code-cpp[NVC_ATL_Windowing#55](../atl/codesnippet/CPP/changing-the-drawing-code-atl-tutorial-part-4_9.cpp)]  
  
 Após adicionar `FireViewChange`, a recompilação e tentar novamente o controle no recipiente de teste de controle ActiveX.  De esta vez quando você altera o número de lados e clique `Invoke`, você deve ver a alteração do controle imediatamente.  
  
 Em o próximo passo, você adicionará um evento.  
  
 [De volta para a etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md) &#124; [a etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md)  
  
## Consulte também  
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)   
 [Testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md)
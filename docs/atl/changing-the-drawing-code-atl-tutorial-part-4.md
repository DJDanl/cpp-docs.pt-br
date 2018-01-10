---
title: "Alterar o código de desenho (Tutorial ATL, parte 4) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords: _ATL_MIN_CRT macro
ms.assetid: 08ff14e8-aa49-4139-a110-5d071939cf1e
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ccbf7dab7d39a80efa2b0b0b88b615c55cd9e56d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changing-the-drawing-code-atl-tutorial-part-4"></a>Alteração do código de desenho (Tutorial ATL, parte 4)
Por padrão, o código de desenho do controle exibe um quadrado e o texto **PolyCtl**. Nesta etapa, você irá alterar o código para exibir algo mais interessante. As seguintes tarefas envolvidas:  
  
-   Modificando o arquivo de cabeçalho  
  
-   Modificando o `OnDraw` função  
  
-   Adicionando um método para calcular os pontos do polígono  
  
-   Inicializando a cor de preenchimento  
  
## <a name="modifying-the-header-file"></a>Modificando o arquivo de cabeçalho  
 Comece adicionando suporte para as funções matemáticas `sin` e `cos`, que será usado calcula os pontos do polígono e criando uma matriz para armazenar posiciona.  
  
#### <a name="to-modify-the-header-file"></a>Para modificar o arquivo de cabeçalho  
  
1.  Adicione a linha `#include <math.h>` na parte superior da PolyCtl.h. A parte superior do arquivo deve ter esta aparência:  
  
     [!code-cpp[NVC_ATL_Windowing#47](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_1.cpp)]  
  
2.  Depois que os pontos do polígono são calculados, eles serão armazenados em uma matriz do tipo `POINT`, para adicionar a matriz após a definição de `m_nSides` em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#48](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_2.h)]  
  
## <a name="modifying-the-ondraw-method"></a>Modificar o método OnDraw  
 Agora você deve modificar o `OnDraw` método PolyCtl.h. O código que você irá adicionar cria um novo caneta e pincel com qual desenhar o polígono e, em seguida, chama o `Ellipse` e `Polygon` funções de API do Win32 para executar o desenho real.  
  
#### <a name="to-modify-the-ondraw-function"></a>Para modificar a função OnDraw  
  
1.  Substituir o `OnDraw` método PolyCtl.h com o código a seguir:  
  
     [!code-cpp[NVC_ATL_Windowing#49](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_3.cpp)]  
  
## <a name="adding-a-method-to-calculate-the-polygon-points"></a>Adicionando um método para calcular os pontos do polígono  
 Adicionar um método chamado `CalcPoints`, que calcula as coordenadas dos pontos que compõem o perímetro do polígono. Esses cálculos se baseará a variável de retângulo que é passada para a função.  
  
#### <a name="to-add-the-calcpoints-method"></a>Para adicionar o método CalcPoints  
  
1.  Adicione a declaração de `CalcPoints` para o `IPolyCtl` seção pública a `CPolyCtl` classe PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#50](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_4.h)]  
  
     A última parte da seção pública a `CPolyCtl` classe terá esta aparência:  
  
     [!code-cpp[NVC_ATL_Windowing#51](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_5.h)]  
  
2.  Adicione essa implementação do `CalcPoints` função ao final da PolyCtl.cpp:  
  
     [!code-cpp[NVC_ATL_Windowing#52](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_6.cpp)]  
  
## <a name="initializing-the-fill-color"></a>Inicializando a cor de preenchimento  
 Inicializar `m_clrFillColor` com uma cor padrão.  
  
#### <a name="to-initialize-the-fill-color"></a>Para inicializar a cor de preenchimento  
  
1.  Usar verde como a cor padrão adicionando esta linha para o `CPolyCtl` construtor em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#53](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_7.h)]  
  
 O construtor agora é semelhante a:  
  
 [!code-cpp[NVC_ATL_Windowing#54](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_8.h)]  
  
## <a name="building-and-testing-the-control"></a>Compilar e testar o controle  
 Recrie o controle. Verifique se o arquivo PolyCtl.htm está fechado, se ele ainda está aberto e, em seguida, clique em **criar polígono** no **criar** menu. Você pode exibir o controle novamente na página PolyCtl.htm, mas desta vez, use o contêiner de teste do controle ActiveX.  
  
#### <a name="to-use-the-activex-control-test-container"></a>Para usar o contêiner de teste do controle ActiveX  
  
1.  Criar e iniciar o contêiner de teste do controle ActiveX. Para obter mais informações, consulte [TSTCON exemplo: contêiner de teste do controle ActiveX](../visual-cpp-samples.md).  
  
2.  No contêiner de teste, no **editar** menu, clique em **Inserir novo controle**.  
  
3.  Localize o controle, que será chamado `PolyCtl Class`e clique em **Okey**. Você verá um triângulo verde dentro de um círculo.  
  
 Tente alterar o número de lados seguindo o procedimento a seguir. Para modificar as propriedades em uma interface dupla de dentro do contêiner de teste, use **invocar métodos**.  
  
#### <a name="to-modify-a-controls-property-from-within-the-test-container"></a>Para modificar a propriedade do controle de dentro do contêiner de teste  
  
1.  No contêiner de teste, clique em **invocar métodos** no **controle** menu.  
  
     O **invocar o método** caixa de diálogo é exibida.  
  
2.  Selecione o **PropPut** versão do **lados** propriedade o **nome do método** caixa de listagem suspensa.  
  
3.  Tipo `5` no **o valor do parâmetro** , clique em **definir valor**e clique em **Invoke**.  
  
 Observe que o controle não se altera. Embora você tenha alterado o número de lados internamente, definindo o `m_nSides` variável, isso não causou o controle seja redesenhado. Se você alterna para outro aplicativo e alterne de volta para o contêiner de teste, você descobrirá que o controle tem redesenhado e tem o número correto de lados.  
  
 Para corrigir esse problema, adicione uma chamada para o `FireViewChange` função, definida em `IViewObjectExImpl`, depois de definir o número de lados. Se o controle está sendo executado em sua própria janela `FireViewChange` chamará o `InvalidateRect` método diretamente. Se o controle está em execução sem janelas, o `InvalidateRect` método ser chamado na interface do local do contêiner. Isso força o controle a se redesenhar.  
  
#### <a name="to-add-a-call-to-fireviewchange"></a>Para adicionar uma chamada para FireViewChange  
  
1.  Atualizar PolyCtl.cpp adicionando a chamada para `FireViewChange` para o `put_Sides` método. Quando você terminar, o `put_Sides` método deve ter esta aparência:  
  
     [!code-cpp[NVC_ATL_Windowing#55](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_9.cpp)]  
  
 Depois de adicionar `FireViewChange`, recriar e tente o controle novamente no contêiner de teste do controle ActiveX. Neste momento, quando você alterar o número de lados e clique em `Invoke`, você deverá ver o controle de alteração imediatamente.  
  
 A próxima etapa, você adicionará um evento.  
  
 [Para a etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md) &#124; [Na etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)   
 [Testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md)


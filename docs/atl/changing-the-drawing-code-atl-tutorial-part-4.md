---
title: Alterar o código de desenho (Tutorial, parte 4 ATL) | Microsoft Docs
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- _ATL_MIN_CRT macro
ms.assetid: 08ff14e8-aa49-4139-a110-5d071939cf1e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fed83cd67ff596581440fa317355186653a0cbec
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43760419"
---
# <a name="changing-the-drawing-code-atl-tutorial-part-4"></a>Alteração do código de desenho (Tutorial ATL, parte 4)

Por padrão, o código de desenho do controle exibe o texto e um quadrado **PolyCtl**. Nesta etapa, você irá alterar o código para exibir algo mais interessante. As tarefas a seguir estão envolvidas:

- Modificando o arquivo de cabeçalho

- Modificando o `OnDraw` função

- Adicionando um método para calcular os pontos do polígono

- Inicializando a cor de preenchimento

## <a name="modifying-the-header-file"></a>Modificando o arquivo de cabeçalho

Comece adicionando suporte para as funções matemáticas `sin` e `cos`, que será usado calcular os pontos do polígono e criando uma matriz para armazenar posiciona.

#### <a name="to-modify-the-header-file"></a>Para modificar o arquivo de cabeçalho

1. Adicione a linha `#include <math.h>` na parte superior do polyctl. H. A parte superior do arquivo deve ter esta aparência:

     [!code-cpp[NVC_ATL_Windowing#47](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_1.cpp)]

2. Depois que os pontos do polígono são calculados, eles serão armazenados em uma matriz do tipo `POINT`, então, adicionar a matriz após a definição da `m_nSides` em polyctl. H:

     [!code-cpp[NVC_ATL_Windowing#48](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_2.h)]

## <a name="modifying-the-ondraw-method"></a>Modificando o método OnDraw

Agora você deve modificar o `OnDraw` método em polyctl. H. O código que você irá adicionar cria um novo caneta e pincel com o qual desenhar o polígono e, em seguida, chama o `Ellipse` e `Polygon` funções de API do Win32 para executar o desenho real.

#### <a name="to-modify-the-ondraw-function"></a>Para modificar a função OnDraw

1. Substitua o `OnDraw` método em polyctl. H com o código a seguir:

     [!code-cpp[NVC_ATL_Windowing#49](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_3.cpp)]

## <a name="adding-a-method-to-calculate-the-polygon-points"></a>Adicionando um método para calcular os pontos do polígono

Adicione um método, chamado `CalcPoints`, que irá calcular as coordenadas dos pontos que compõem o perímetro do polígono. Esses cálculos se basearão na variável RECT que é passado para a função.

#### <a name="to-add-the-calcpoints-method"></a>Para adicionar o método CalcPoints

1. Adicione a declaração da `CalcPoints` para o `IPolyCtl` seção pública do `CPolyCtl` classe em polyctl. H:

     [!code-cpp[NVC_ATL_Windowing#50](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_4.h)]

     A última parte da seção pública do `CPolyCtl` classe terá esta aparência:

     [!code-cpp[NVC_ATL_Windowing#51](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_5.h)]

2. Adicionar essa implementação do `CalcPoints` função ao final da PolyCtl.cpp:

     [!code-cpp[NVC_ATL_Windowing#52](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_6.cpp)]

## <a name="initializing-the-fill-color"></a>Inicializando a cor de preenchimento

Inicializar `m_clrFillColor` com uma cor padrão.

#### <a name="to-initialize-the-fill-color"></a>Para inicializar a cor de preenchimento

1. Usar verde como a cor padrão adicionando esta linha para o `CPolyCtl` construtor em polyctl. H:

     [!code-cpp[NVC_ATL_Windowing#53](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_7.h)]

O construtor agora aparece desta forma:

[!code-cpp[NVC_ATL_Windowing#54](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_8.h)]

## <a name="building-and-testing-the-control"></a>Compilar e testar o controle

Recompile o controle. Verifique se o arquivo de Polyctl seja fechado se ele ainda está aberto e, em seguida, clique em **compilar polígono** sobre o **Build** menu. Você pode exibir o controle mais uma vez na página Polyctl, mas desta vez use o contêiner de teste do controle ActiveX.

#### <a name="to-use-the-activex-control-test-container"></a>Para usar o contêiner de teste do controle ActiveX

1. Compilar e iniciar o contêiner de teste do controle ActiveX. Para obter mais informações, consulte [TSTCON exemplo: contêiner de teste do controle ActiveX](../visual-cpp-samples.md).

2. No contêiner de teste, sobre o **editar** menu, clique em **inserir o novo controle**.

3. Localize seu controle, que será chamado `PolyCtl Class`e clique em **Okey**. Você verá um triângulo verde dentro de um círculo.

Tente alterar o número de lados, seguindo o procedimento a seguir. Para modificar as propriedades em uma interface dupla de dentro do contêiner de teste, use **invocar métodos**.

#### <a name="to-modify-a-controls-property-from-within-the-test-container"></a>Para modificar a propriedade de um controle de dentro do contêiner de teste

1. No contêiner de teste, clique em **invocar métodos** sobre o **controle** menu.

     O **invocar método** caixa de diálogo é exibida.

2. Selecione o **PropPut** versão dos **lados** propriedade do **nome do método** caixa de listagem suspensa.

3. Tipo de `5` no **o valor do parâmetro** , clique em **definir valor**e clique em **Invoke**.

Observe que o controle não é alterado. Embora você tenha alterado o número de lados internamente, definindo o `m_nSides` variável, isso não causou o controle seja redesenhado. Se você alterna para outro aplicativo e, em seguida, alterna novamente para o contêiner de teste, você encontrará o que o controle foi redesenhado e tem o número correto de lados.

Para corrigir esse problema, adicione uma chamada para o `FireViewChange` função, definida em `IViewObjectExImpl`, depois de definir o número de lados. Se o controle está em execução em sua própria janela `FireViewChange` chamará o `InvalidateRect` método diretamente. Se o controle está em execução sem janelas, o `InvalidateRect` método será chamado na interface de site do contêiner. Isso força o controle seja redesenhado.

#### <a name="to-add-a-call-to-fireviewchange"></a>Para adicionar uma chamada para FireViewChange

1. Atualizar PolyCtl.cpp adicionando-se a chamada para `FireViewChange` para o `put_Sides` método. Quando você terminar, o `put_Sides` método deve ter esta aparência:

     [!code-cpp[NVC_ATL_Windowing#55](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_9.cpp)]

Depois de adicionar `FireViewChange`, recompile e tente o controle novamente no contêiner de teste do controle ActiveX. Desta vez, quando você alterar o número de lados e clique em `Invoke`, você deverá ver o controle alterar imediatamente.

A próxima etapa, você adicionará um evento.

[Volte para a etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md) &#124; [para a etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)   
[Testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md)


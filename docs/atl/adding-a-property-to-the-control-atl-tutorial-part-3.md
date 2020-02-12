---
title: Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)
ms.custom: get-started-article
ms.date: 09/26/2018
ms.assetid: f775fe34-103b-4f07-9999-400e987ee030
ms.openlocfilehash: 288dc9f5af57c02639d15a9a971419a633cfc08d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127581"
---
# <a name="adding-a-property-to-the-control-atl-tutorial-part-3"></a>Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)

`IPolyCtl` é a interface que contém os métodos e as propriedades personalizados do controle, e você adicionará uma propriedade a ele.

### <a name="to-add-the-property-definitions-to-your-project"></a>Para adicionar as definições de propriedade ao seu projeto

1. Em **modo de exibição de classe**, expanda a ramificação `Polygon`.

1. Clique com o botão direito do mouse em `IPolyCtl`.

1. No menu de atalho, clique em **Adicionar**e, em seguida, clique em **Adicionar Propriedade**. O assistente para **Adicionar Propriedade** será exibido.

1. Digite `Sides` como o **nome da propriedade**.

1. Na lista suspensa do **tipo de propriedade**, selecione `short`.

1. Clique em **OK** para concluir a adição da propriedade.

1. Em **Gerenciador de soluções**, abra Polygon. idl e substitua as seguintes linhas no final da interface `IPolyCtl : IDispatch`:

    ```cpp
    short get_Sides();
    void set_Sides(short value);
    ```

    por

    ```cpp
    [propget, id(1), helpstring("property Sides")] HRESULT Sides([out, retval] short *pVal);
    [propput, id(1), helpstring("property Sides")] HRESULT Sides([in] short newVal);
    ```

1. Em **Gerenciador de soluções**, abra PolyCtl. h e adicione as seguintes linhas após a definição de `m_clrFillColor`:

    [!code-cpp[NVC_ATL_Windowing#44](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_1.h)]

Embora agora você tenha funções de esqueleto para definir e recuperar a propriedade e uma variável para armazenar a propriedade, você deve implementar as funções adequadamente.

### <a name="to-update-the-get-and-put-methods"></a>Para atualizar os métodos get e put

1. Defina o valor padrão de `m_nSides`. Transforme a forma padrão em um triângulo adicionando uma linha ao Construtor em PolyCtl. h:

    [!code-cpp[NVC_ATL_Windowing#45](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_2.h)]

1. Implemente os métodos `Get` e `Put`. As declarações de função `get_Sides` e `put_Sides` foram adicionadas a PolyCtl. h. Agora, adicione o código para `get_Sides` e `put_Sides` a PolyCtl. cpp com o seguinte:

    [!code-cpp[NVC_ATL_Windowing#46](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_3.cpp)]

O método `get_Sides` retorna o valor atual da propriedade `Sides` por meio do ponteiro `pVal`. No método `put_Sides`, o código garante que o usuário esteja definindo a propriedade `Sides` com um valor aceitável. O mínimo deve ser 3 e, como uma matriz de pontos será usada para cada lado, 100 é um limite razoável para um valor máximo.

Agora você tem uma propriedade chamada `Sides`. Na próxima etapa, você alterará o código de desenho para usá-lo.

De [volta à etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md) &#124; [em para a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)

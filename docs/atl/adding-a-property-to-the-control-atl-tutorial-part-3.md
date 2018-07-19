---
title: Adicionando uma propriedade ao controle de (ATL Tutorial, parte 3) | Microsoft Docs
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f775fe34-103b-4f07-9999-400e987ee030
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7cbfb0b22579aceb5cbee196e3c5eda3079c9304
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848711"
---
# <a name="adding-a-property-to-the-control-atl-tutorial-part-3"></a>Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)
`IPolyCtl` é a interface que contém métodos do controle e propriedades personalizados, e você irá adicionar uma propriedade a ele.  
  
### <a name="to-add-a-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade usando o Assistente para adicionar propriedade  
  
1.  No modo de exibição de classe, expanda a ramificação do polígono.  
  
2.  Clique com botão direito IPolyCtl.  
  
3.  No menu de atalho, clique em **Add**e, em seguida, clique em **adicionar propriedade**.  
  
     O Assistente para adicionar propriedade será exibida.  
  
4.  Na lista suspensa de tipos de propriedade, selecione `SHORT`.  
  
5.  Tipo de *lados* como o **nome da propriedade.**  
  
6.  Clique em **concluir** para terminar de adicionar a propriedade.  
  
 Quando você adiciona a propriedade para a interface, MIDL (o programa que compila arquivos. idl) define um `Get` método para recuperar seu valor e um `Put` método para definir um novo valor. Os métodos são nomeados acrescentando `put_` e `get_` ao nome da propriedade.  
  
 O Assistente para adicionar propriedade adiciona as linhas necessárias para o arquivo. idl. Ele também adiciona o `Get` e `Put` protótipos à definição de classe em polyctl. H de função e adiciona uma implementação vazia para PolyCtl.cpp. Você pode verificar isso abrindo PolyCtl.cpp e procurando as funções `get_Sides` e `put_Sides`.  
  
 Embora agora você tem funções esqueleto para definir e recuperar a propriedade, ele precisa de um local a ser armazenado. Você criará uma variável para armazenar a propriedade e atualizar as funções adequadamente.  
  
#### <a name="to-create-a-variable-to-store-the-property-and-update-the-put-and-get-methods"></a>Para criar uma variável para armazenar a propriedade e atualizar o put e métodos get  
  
1.  No Gerenciador de soluções, abra o polyctl. H e adicione a seguinte linha após a definição da `m_clrFillColor`:  
  
     [!code-cpp[NVC_ATL_Windowing#44](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_1.h)]  
  
2.  Defina o valor padrão de `m_nSides`. Fazer com que o padrão de forma um triângulo com a adição de uma linha para o construtor em polyctl. H:  
  
     [!code-cpp[NVC_ATL_Windowing#45](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_2.h)]  
  
3.  Implemente os métodos `Get` e `Put`. O `get_Sides` e `put_Sides` declarações de função foram adicionadas ao polyctl. H. Substitua o código em PolyCtl.cpp para `get_Sides` e `put_Sides` com o código a seguir:  
  
     [!code-cpp[NVC_ATL_Windowing#46](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_3.cpp)]  
  
 O `get_Sides` método retorna o valor atual da `Sides` propriedade por meio de `pVal` ponteiro. No `put_Sides` método, o código garante que o usuário está definindo o `Sides` propriedade para um valor aceitável. O mínimo deve ser 3 e como uma matriz de pontos será usada para cada lado, 100 é um limite razoável para um valor máximo.  
  
 Agora você tem uma propriedade chamada `Sides`. Na próxima etapa, você irá alterar o código de desenho para usá-lo.  
  
 [Volte para a etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md) &#124; [para a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)


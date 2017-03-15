---
title: "Adicionando uma propriedade ao controle (Tutorial ATL, parte 3) | Microsoft Docs"
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
ms.assetid: f775fe34-103b-4f07-9999-400e987ee030
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`IPolyCtl` é a interface que contém os métodos personalizados e propriedades de controle, e você adicionar uma propriedade.  
  
### Para adicionar uma propriedade usando o assistente para adicionar propriedade  
  
1.  Em o modo da classe, expanda a ramificação polígono.  
  
2.  Clique com o botão direito do mouse IPolyCtl.  
  
3.  Em o menu de atalho, clique **Adicionar**, clique em **Adicionar Propriedade**.  
  
     O assistente de propriedade adicionar aparecerá.  
  
4.  Em a lista suspensa de tipos de propriedades, `SHORT`selecione.  
  
5.  Tipo `lados` como **Nome da propriedade.**  
  
6.  Clique em para concluir **Concluir** adicionar a propriedade.  
  
 Quando você adiciona a propriedade para a interface, MIDL \(o programa que compila arquivos de .idl\) define um método de `Get` para recuperar seu valor e um método de `Put` para definir um novo valor.  Os métodos são chamados prepending `put_` e `get_` ao nome da propriedade.  
  
 O assistente de propriedade adicionar adiciona as linhas necessárias para o arquivo de .idl.  Ele também adiciona os protótipos de função de `Get` e de `Put` a definição de classe em PolyCtl.h e adiciona uma implementação vazio a PolyCtl.cpp.  Você pode verificar isso PolyCtl.cpp abrindo e procurando as funções `get_Sides` e `put_Sides`.  
  
 Embora você tenha agora as funções de esqueleto para definir e recuperar a propriedade, precisa de um local de ser armazenada.  Você criará uma variável para armazenar a propriedade e para atualizar em conformidade com as funções.  
  
#### Para criar uma variável para armazenar a propriedade, e para atualizar colocado e métodos para obter  
  
1.  Em o solution Explorer, PolyCtl.h abertos e adicione a seguinte linha após a definição de `m_clrFillColor`:  
  
     [!code-cpp[NVC_ATL_Windowing#44](../atl/codesnippet/CPP/adding-a-property-to-the-control-atl-tutorial-part-3_1.h)]  
  
2.  Defina o valor padrão de `m_nSides`.  Faça a maneira padrão um triângulo adicionando uma linha para o construtor em PolyCtl.h:  
  
     [!code-cpp[NVC_ATL_Windowing#45](../atl/codesnippet/CPP/adding-a-property-to-the-control-atl-tutorial-part-3_2.h)]  
  
3.  Implementar métodos de `Get` e de `Put` .  Declarações de função de `get_Sides` e de `put_Sides` foram adicionados a PolyCtl.h.  Substitua o código em PolyCtl.cpp para `get_Sides` e em `put_Sides` com o seguinte código:  
  
     [!code-cpp[NVC_ATL_Windowing#46](../atl/codesnippet/CPP/adding-a-property-to-the-control-atl-tutorial-part-3_3.cpp)]  
  
 O método de `get_Sides` retorna o valor atual da propriedade de `Sides` através do ponteiro de `pVal` .  Em o método de `put_Sides` , o código garante que o usuário está definindo a propriedade de `Sides` a um valor aceitável.  O mínimo deve ser 2, e como uma matriz de pontos será usada para cada lado, 100 é um limite razoável para um valor máximo.  
  
 Agora você tem uma propriedade chamada `Sides`.  Em o próximo passo, você irá alterar o código de desenho usá\-lo.  
  
 [De volta para a etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md) &#124; [a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md)  
  
## Consulte também  
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)
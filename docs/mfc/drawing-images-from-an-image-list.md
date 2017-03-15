---
title: "Desenhando imagens a partir de uma lista de imagens | Microsoft Docs"
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
  - "Classe CImageList, desenhando imagens de"
  - "desenho, imagens de listas de imagens"
  - "listas de imagens [C++], desenhando imagens de"
  - "imagens [C++], desenho"
ms.assetid: 2f6063fb-1c28-45f8-a333-008c064db11c
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Desenhando imagens a partir de uma lista de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para desenhar uma imagem, use a função de membro de [CImageList::Draw](../Topic/CImageList::Draw.md) .  Você especificará um ponteiro para um objeto de contexto do dispositivo, o índice de imagem para desenhar, o local no contexto do dispositivo na qual desenhar a imagem, e um conjunto de sinalizadores para indicar o estilo de desenho.  
  
 Quando você especifica o estilo de `ILD_TRANSPARENT` , **Desenhar** usa um processo de duas etapas para desenhar uma imagem mascarada.  Primeiro, executa uma operação AND lógica em bits da imagem e em bits de máscara.  Executa uma operação realização de XOR nos resultados da primeira operação e em bits em segundo plano do contexto do dispositivo de destino.  Esse processo cria áreas transparentes na imagem resultante; ou seja, cada bit branco na máscara faz com que o bit correspondente na imagem resultante é transparente.  
  
 Antes de desenhando uma imagem mascarada em um plano de fundo de cor sólida, você deve usar a função de membro de [SetBkColor](../Topic/CImageList::SetBkColor.md) para definir a cor do plano de fundo da lista de imagem para a mesma cor do destino.  Definir a cor elimina a necessidade de criar áreas transparentes na imagem e habilita **Desenhar** para copiar apenas a imagem para o contexto do dispositivo de destino, resultando em um aumento significativo no desempenho.  Para desenhar a imagem, especifique o estilo de `ILD_NORMAL` quando você chama **Desenhar**.  
  
 Você pode definir a cor do plano de fundo para uma lista mascarada de imagem \(\)[CImageList](../Topic/CImageList%20Class.md)a qualquer momento de modo que desenhe corretamente em qualquer plano de fundo contínuo.  Definir a cor do plano de fundo para as causas de `CLR_NONE` imagens para ser desenhado transparente por padrão.  Para recuperar a cor do plano de fundo de uma lista de imagem, use a função de membro de [GetBkColor](../Topic/CImageList::GetBkColor.md) .  
  
 A exaltação que estilos de `ILD_BLEND25` e de `ILD_BLEND50` a imagem com o realce as cores do sistema.  Esses estilos são úteis se você usar uma imagem mascarada para representar um objeto que o usuário pode selecionar.  Por exemplo, você pode usar o estilo de `ILD_BLEND50` para desenhar a imagem quando o usuário seleciona o.  
  
 Uma imagem nonmasked será copiada no contexto do dispositivo de destino usando a operação de quadriculação de **SRCCOPY** .  As cores na imagem aparecem o mesmos independentemente da cor de plano de fundo do contexto do dispositivo.  Os estilos de desenho especificados em **Desenhar** também não têm nenhum efeito na aparência de uma imagem nonmasked.  
  
 Além da função de membro de descompasso, outra função, [DrawIndirect](../Topic/CImageList::DrawIndirect.md), estende a capacidade de renderização de uma imagem.  `DrawIndirect` ocupa, como um parâmetro, uma estrutura de [IMAGELISTDRAWPARAMS](http://msdn.microsoft.com/library/windows/desktop/bb761395) .  Essa estrutura pode ser usada para personalizar a renderização da imagem atual, inclusive o uso de códigos de \(ROP\) da operação de quadriculação.  Para obter mais informações sobre códigos de ROP, consulte [Código de operação de quadriculação](http://msdn.microsoft.com/library/windows/desktop/dd162892) e [Bitmaps como escovas](http://msdn.microsoft.com/library/windows/desktop/dd183378) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)
---
title: Imprimindo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- view classes [MFC], print operations
- documents [MFC], printing
- printing [MFC], from framework
- printing [MFC]
ms.assetid: be465e8d-b0c9-4fc5-9fa8-d10486064f76
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 48395276acfac71cd940be307c3b5f0735c356ca
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="printing"></a>Imprimindo
Microsoft Windows implementa independentes de dispositivo de exibição. Em MFC, isso significa que as chamadas de desenho mesmo, no `OnDraw` a função de membro da classe do modo de exibição, são responsáveis por desenho na tela e em outros dispositivos, como impressoras. Para visualização de impressão, o dispositivo de destino é uma saída de impressora simulada para a exibição.  
  
##  <a name="_core_your_role_in_printing_vs.._the_framework.92.s_role"></a>Sua função na impressão versus de função da estrutura  
 A classe de exibição tem as seguintes responsabilidades:  
  
-   Informe o framework é o número de páginas do documento.  
  
-   Quando for solicitado para imprimir uma página especificada, desenhe a parte do documento.  
  
-   Aloque e desaloque as fontes ou outros recursos GDI (interface) do dispositivo de gráficos necessários para impressão.  
  
-   Se necessário, envie qualquer escape códigos necessários para alterar o modo de impressora antes de imprimir uma determinada página, por exemplo, para alterar a orientação de impressão em uma base por página.  
  
 Responsabilidades da estrutura são da seguinte maneira:  
  
-   Exibição de **impressão** caixa de diálogo.  
  
-   Criar um [CDC](../mfc/reference/cdc-class.md) objeto para a impressora.  
  
-   Chamar o [StartDoc](../mfc/reference/cdc-class.md#startdoc) e [EndDoc](../mfc/reference/cdc-class.md#enddoc) funções de membro de `CDC` objeto.  
  
-   Chamar repetidamente o [StartPage](../mfc/reference/cdc-class.md#startpage) função membro do `CDC` objeto informar qual página deve ser impresso e chamar a classe de visualização a [EndPage](../mfc/reference/cdc-class.md#endpage) função membro do `CDC` objeto.  
  
-   Chame funções substituíveis no modo de exibição nos momentos apropriados.  
  
 Os artigos a seguir discutem como o framework oferece suporte à impressão e visualização de impressão:  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)  
  
-   [Documentos Multipágina](../mfc/multipage-documents.md)  
  
-   [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)  
  
-   [Alocando recursos GDI para impressão](../mfc/allocating-gdi-resources.md)  
  
-   [Visualizar impressão](../mfc/print-preview-architecture.md)  
  
## <a name="see-also"></a>Consulte também  
 [Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)


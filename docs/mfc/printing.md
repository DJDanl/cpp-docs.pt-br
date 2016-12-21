---
title: "Imprimindo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "documentos, imprimindo"
  - "imprimindo [MFC]"
  - "imprimindo [MFC], da estrutura"
  - "classes de exibição, operações de impressão"
ms.assetid: be465e8d-b0c9-4fc5-9fa8-d10486064f76
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Imprimindo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Exibição do dispositivo independentemente das ferramentas do Microsoft Windows.  MFC no, isso significa que os mesmos chamadas de desenho, na função de membro de `OnDraw` da sua classe da exibição, são responsáveis para desenhar na exibição e em outros dispositivos, como impressoras.  Para a visualização de impressão, o dispositivo de destino é uma saída de impressora simulada para a exibição.  
  
##  <a name="_core_your_role_in_printing_vs.._the_framework.92.s_role"></a> A função na impressão na função da estrutura  
 A classe de exibição tem responsabilidades as seguintes:  
  
-   Informe a estrutura quantas páginas estão no documento.  
  
-   Quando solicitado para imprimir uma página especificada, desenhar essa parte do documento.  
  
-   Aloque e desaloque todas as fontes ou outros recursos de \(GDI\) de graphics device interface necessárias para imprimir.  
  
-   Se necessário, enviar todos os códigos de escape necessários para alterar o modo de impressora antes de impressão uma página específica, por exemplo, para alterar a orientação de impressão em uma base por página.  
  
 As responsabilidades da estrutura são os seguintes:  
  
-   Exibir a caixa de diálogo de **Imprimir** .  
  
-   Crie um objeto de [CDC](../Topic/CDC%20Class.md) para a impressora.  
  
-   Chame as funções de membro de [StartDoc](../Topic/CDC::StartDoc.md) e de [EndDoc](../Topic/CDC::EndDoc.md) do objeto de `CDC` .  
  
-   Chamar repetidamente a função de membro de [StartPage](../Topic/CDC::StartPage.md) do objeto de `CDC` , informando a classe da exibição que a página deve ser impressa, e chamam a função de membro de [EndPage](../Topic/CDC::EndPage.md) do objeto de `CDC` .  
  
-   Chamar funções overridable na exibição nos momentos apropriados.  
  
 Os artigos a seguir discutem como a estrutura da suporte à impressão e a visualização de impressão:  
  
### Que você deseja saber mais?  
  
-   [Como usar como padrão a impressão é feita](../Topic/How%20Default%20Printing%20Is%20Done.md)  
  
-   [Documentos de várias páginas](../mfc/multipage-documents.md)  
  
-   [Cabeçalhos e rodapés](../mfc/headers-and-footers.md)  
  
-   [Alocando recursos de GDI para imprimir](../mfc/allocating-gdi-resources.md)  
  
-   [Visualizar impressão](../mfc/print-preview-architecture.md)  
  
## Consulte também  
 [Impressão e visualização de impressão](../mfc/printing-and-print-preview.md)
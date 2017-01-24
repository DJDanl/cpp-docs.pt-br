---
title: "Estrutura COLORADJUSTMENT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "COLORADJUSTMENT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura COLORADJUSTMENT"
ms.assetid: 67fc4e63-0e0e-4fcb-8c45-aa5ebfefa013
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura COLORADJUSTMENT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `COLORADJUSTMENT` define os valores de ajuste de cor usados por funções do windows `StretchBlt` e de **StretchDIBits** quando o modo de `StretchBlt` é **HALFTONE**.  
  
## Sintaxe  
  
```  
  
      typedef struct  tagCOLORADJUSTMENT {    /* ca */  
    WORD  caSize;  
    WORD  caFlags;  
    WORD  caIlluminantIndex;  
    WORD  caRedGamma;  
    WORD  caGreenGamma;  
    WORD  caBlueGamma;  
    WORD  caReferenceBlack;  
    WORD  caReferenceWhite;  
    SHORT caContrast;  
    SHORT caBrightness;  
    SHORT caColorfulness;  
    SHORT caRedGreenTint;  
} COLORADJUSTMENT;  
```  
  
#### Parâmetros  
 *caSize*  
 Especifica o tamanho da estrutura em bytes.  
  
 *caFlags*  
 Especifica como a imagem de saída deve ser preparada.  Esse membro pode ser definido como **nulo** ou qualquer combinação dos seguintes valores:  
  
-   **CA\_NEGATIVE** especifica que o negativo de imagem original deve ser exibido.  
  
-   **CA\_LOG\_FILTER** especifica que uma função logarítmica deve ser aplicada a densidade final das cores de saída.  Isso aumentará o contrário da cor quando a luminância é baixa.  
  
 *caIlluminantIndex*  
 Especifica a luminância da fonte luminosa no qual o objeto da imagem é exibido.  Esse membro pode ser definido como um dos seguintes valores:  
  
-   **ILLUMINANT\_EQUAL\_ENERGY**  
  
-   **ILLUMINANT\_A**  
  
-   **ILLUMINANT\_B**  
  
-   **ILLUMINANT\_C**  
  
-   **ILLUMINANT\_D50**  
  
-   **ILLUMINANT\_D55**  
  
-   **ILLUMINANT\_D65**  
  
-   **ILLUMINANT\_D75**  
  
-   **ILLUMINANT\_F2**  
  
-   **ILLUMINANT\_TURNGSTEN**  
  
-   **ILLUMINANT\_DAYLIGHT**  
  
-   **ILLUMINANT\_FLUORESCENT**  
  
-   **ILLUMINANT\_NTSC**  
  
 *caRedGamma*  
 Especifica o nth valor de gama\- correção do poder do vermelho primário de cores de origem.  O valor deve estar no intervalo de 2.500 a 65.000.  Um valor de 10.000 significa que nenhuma gama\- correção.  
  
 *caGreenGamma*  
 Especifica o nth valor de gama\- correção do poder para verde primário de cores de origem.  O valor deve estar no intervalo de 2.500 a 65.000.  Um valor de 10.000 significa que nenhuma gama\- correção.  
  
 *caBlueGamma*  
 Especifica o nth valor de gama\- correção do poder para azul primário de cores de origem.  O valor deve estar no intervalo de 2.500 a 65.000.  Um valor de 10.000 significa que nenhuma gama\- correção.  
  
 *caReferenceBlack*  
 Especifica a referência preta para as cores de origem.  Todas as cores com mais escuras dessa são tratadas como preto.  O valor deve estar no intervalo de 0 a 4.000.  
  
 *caReferenceWhite*  
 Especifica a referência branca para as cores de origem.  Todas as cores com mais claras dessa são tratadas como branco.  O valor deve estar no intervalo de 6.000 a 10.000.  
  
 *caContrast*  
 Especifica a quantidade de comparação a ser aplicado ao objeto de origem.  O valor deve estar no intervalo de \-100 a 100.  Um valor de 0 significa nenhum ajuste de comparação.  
  
 *caBrightness*  
 Especifica a quantidade de brilho a ser aplicado ao objeto de origem.  O valor deve estar no intervalo de \-100 a 100.  Um valor de 0 significa nenhum ajuste de brilho.  
  
 *caColorfulness*  
 Especifica a quantidade de colorfulness a ser aplicado ao objeto de origem.  O valor deve estar no intervalo de \-100 a 100.  Um valor de 0 significa nenhum ajuste de colorfulness.  
  
 *caRedGreenTint*  
 Especifica a quantidade de ajuste vermelho ou verde de matiz a ser aplicado ao objeto de origem.  O valor deve estar no intervalo de \-100 a 100.  Os números positivos ajustariam para vermelho e números negativos ajuste para verde.  Um 0 não significa nenhum ajuste do matiz.  
  
## Requisitos  
 **Header:** wingdi.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetColorAdjustment](../Topic/CDC::GetColorAdjustment.md)
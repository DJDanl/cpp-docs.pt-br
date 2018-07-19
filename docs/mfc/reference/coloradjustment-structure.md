---
title: Estrutura COLORADJUSTMENT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COLORADJUSTMENT
dev_langs:
- C++
helpviewer_keywords:
- COLORADJUSTMENT structure [MFC]
ms.assetid: 67fc4e63-0e0e-4fcb-8c45-aa5ebfefa013
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 03c5346a59ea52ca6b2428652d5da69aacf6ea5b
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37849079"
---
# <a name="coloradjustment-structure"></a>Estrutura COLORADJUSTMENT
O `COLORADJUSTMENT` estrutura define os valores de ajuste de cor usados pelo Windows `StretchBlt` e `StretchDIBits` funções quando o `StretchBlt` modo é o meio-tom.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct  tagCOLORADJUSTMENT {    /* ca */  
    WORD caSize;  
    WORD caFlags;  
    WORD caIlluminantIndex;  
    WORD caRedGamma;  
    WORD caGreenGamma;  
    WORD caBlueGamma;  
    WORD caReferenceBlack;  
    WORD caReferenceWhite;  
    SHORT caContrast;  
    SHORT caBrightness;  
    SHORT caColorfulness;  
    SHORT caRedGreenTint;  
} COLORADJUSTMENT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *caSize*  
 Especifica o tamanho da estrutura em bytes.  
  
 *caFlags*  
 Especifica como a imagem de saída deve ser preparada. Esse membro pode ser definido como nulo ou qualquer combinação dos valores a seguir:  
  
- CA_NEGATIVE Especifica que o negativo da imagem original deve ser exibido.  
  
- CA_LOG_FILTER Especifica que uma função logarítmica deve ser aplicada a densidade final das cores de saída. Isso aumentará o contraste de cores quando a luminosidade é baixa.  
  
 *caIlluminantIndex*  
 Especifica a luminosidade da fonte de luz sob a qual o objeto de imagem é exibido. Esse membro pode ser definido como um dos seguintes valores:  
  
- ILLUMINANT_EQUAL_ENERGY  
  
- ILLUMINANT_A  
  
- ILLUMINANT_B  
  
- ILLUMINANT_C  
  
- ILLUMINANT_D50  
  
- ILLUMINANT_D55  
  
- ILLUMINANT_D65  
  
- ILLUMINANT_D75  
  
- ILLUMINANT_F2  
  
- ILLUMINANT_TURNGSTEN  
  
- ILLUMINANT_DAYLIGHT  
  
- ILLUMINANT_FLUORESCENT  
  
- ILLUMINANT_NTSC  
  
 *caRedGamma*  
 Especifica o valor de correção gama enésimo energia para o primário vermelho das cores do código-fonte. O valor deve estar no intervalo entre 2.500 e 65.000. Um valor de 10.000 não significa nenhuma correção gama.  
  
 *caGreenGamma*  
 Especifica o valor de correção gama enésimo energia para o primário verde das cores do código-fonte. O valor deve estar no intervalo entre 2.500 e 65.000. Um valor de 10.000 não significa nenhuma correção gama.  
  
 *caBlueGamma*  
 Especifica o valor de correção gama enésimo energia para a cor azul primária das cores do código-fonte. O valor deve estar no intervalo entre 2.500 e 65.000. Um valor de 10.000 não significa nenhuma correção gama.  
  
 *caReferenceBlack*  
 Especifica a referência de preta para as cores de origem. Todas as cores mais escuras que isso são tratadas como preto. O valor deve estar no intervalo de 0 a 4.000.  
  
 *caReferenceWhite*  
 Especifica a referência de branca para as cores de origem. Todas as cores mais claras que isso são tratadas como em branco. O valor deve estar no intervalo de 6.000 a 10.000.  
  
 *caContrast*  
 Especifica a quantidade de contraste a ser aplicado ao objeto de origem. O valor deve estar no intervalo entre -100 e 100. Um valor de 0 significa que nenhum ajuste de contraste.  
  
 *caBrightness*  
 Especifica a quantidade de brilho a ser aplicado ao objeto de origem. O valor deve estar no intervalo entre -100 e 100. Um valor de 0 significa que nenhum ajuste de brilho.  
  
 *caColorfulness*  
 Especifica a quantidade de colorfulness a ser aplicado ao objeto de origem. O valor deve estar no intervalo entre -100 e 100. Um valor de 0 significa que nenhum ajuste colorfulness.  
  
 *caRedGreenTint*  
 Especifica a quantidade de ajuste de tom de vermelho ou verde a ser aplicado ao objeto de origem. O valor deve estar no intervalo entre -100 e 100. Números positivos seriam ajustado para vermelho e ajuste os números negativos para verde. 0 significa que nenhum ajuste de tonalidade.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetColorAdjustment](../../mfc/reference/cdc-class.md#getcoloradjustment)



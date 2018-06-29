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
ms.openlocfilehash: 1bb4cba5ef2eafa27a26c945f8754eb1a0ab0315
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37077949"
---
# <a name="coloradjustment-structure"></a>Estrutura COLORADJUSTMENT
O `COLORADJUSTMENT` estrutura define os valores de ajuste de cor usados pelo Windows `StretchBlt` e `StretchDIBits` funções quando o `StretchBlt` modo é **meio tom**.  
  
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
 Especifica como a imagem de saída deve ser preparada. Esse membro pode ser definido como **nulo** ou qualquer combinação dos valores a seguir:  
  
- **CA_NEGATIVE** Especifica que o negativo da imagem original deve ser exibido.  
  
- **CA_LOG_FILTER** Especifica que uma função logarítmica deve ser aplicada para a densidade final das cores de saída. Isso aumentará o contraste de cor quando a luminosidade é baixa.  
  
 *caIlluminantIndex*  
 Especifica a luminosidade da fonte de luz sob a qual o objeto de imagem é exibido. Esse membro pode ser definido como um dos valores a seguir:  
  
- **ILLUMINANT_EQUAL_ENERGY**  
  
- **ILLUMINANT_A**  
  
- **ILLUMINANT_B**  
  
- **ILLUMINANT_C**  
  
- **ILLUMINANT_D50**  
  
- **ILLUMINANT_D55**  
  
- **ILLUMINANT_D65**  
  
- **ILLUMINANT_D75**  
  
- **ILLUMINANT_F2**  
  
- **ILLUMINANT_TURNGSTEN**  
  
- **ILLUMINANT_DAYLIGHT**  
  
- **ILLUMINANT_FLUORESCENT**  
  
- **ILLUMINANT_NTSC**  
  
 *caRedGamma*  
 Especifica o valor de correção gama enésimo energia para o primário vermelho das cores do código-fonte. O valor deve ser no intervalo de 2.500 a 65.000. Um valor de 10.000 não significa nenhuma correção gama.  
  
 *caGreenGamma*  
 Especifica o valor de correção gama power enésimo para verde primário das cores do código-fonte. O valor deve ser no intervalo de 2.500 a 65.000. Um valor de 10.000 não significa nenhuma correção gama.  
  
 *caBlueGamma*  
 Especifica o valor de correção gama enésimo energia para o primário azul das cores do código-fonte. O valor deve ser no intervalo de 2.500 a 65.000. Um valor de 10.000 não significa nenhuma correção gama.  
  
 *caReferenceBlack*  
 Especifica a referência preta para as cores de fonte. As cores mais escuras que isso são tratadas como preto. O valor deve estar no intervalo de 0 a 4.000.  
  
 *caReferenceWhite*  
 Especifica a referência de branca para as cores de fonte. As cores mais claras que isso são tratadas como branco. O valor deve ser no intervalo de 6.000 a 10.000.  
  
 *caContrast*  
 Especifica a quantidade de contraste a ser aplicado ao objeto de origem. O valor deve ser no intervalo de 100 a 100. Um valor de 0 não significa que nenhum ajuste de contraste.  
  
 *caBrightness*  
 Especifica o valor de brilho a ser aplicado ao objeto de origem. O valor deve ser no intervalo de 100 a 100. Um valor de 0 não significa que nenhum ajuste de brilho.  
  
 *caColorfulness*  
 Especifica a quantidade de colorfulness a ser aplicado ao objeto de origem. O valor deve ser no intervalo de 100 a 100. Um valor de 0 não significa que nenhum ajuste de colorfulness.  
  
 *caRedGreenTint*  
 Especifica a quantidade de ajuste de tom de vermelho ou verde a ser aplicado ao objeto de origem. O valor deve ser no intervalo de 100 a 100. Números positivos deve ajustar para vermelho e ajuste os números negativos para verde. 0 não significa que nenhum ajuste de tom.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetColorAdjustment](../../mfc/reference/cdc-class.md#getcoloradjustment)



---
title: Constantes do tipo de parâmetro variante
ms.date: 11/04/2016
f1_keywords:
- VTS_YPOS_HIMETRIC
- VTS_PICTURE
- VTS_FONT
- VTS_XPOS_HIMETRIC
- VTS_XPOS_PIXELS
- VTS_XSIZE_HIMETRIC
- VTS_YPOS_PIXELS
- VTS_TRISTATE
- VTS_HANDLE
- VTS_YSIZE_HIMETRIC
- VTS_COLOR
- VTS_OPTEXCLUSIVE
- VTS_YSIZE_PIXELS
- VTS_XSIZE_PIXELS
helpviewer_keywords:
- VTS_XPOS_HIMETRIC constant [MFC]
- VTS_FONT constant [MFC]
- VTS_XPOS_PIXELS constant [MFC]
- VTS_COLOR constant [MFC]
- Variants [MFC]
- VTS_YPOS_PIXELS constant [MFC]
- VTS_YSIZE_HIMETRIC constant [MFC]
- VTS_YPOS_HIMETRIC constant [MFC]
- Variants, parameter type constants
- Variant data constants [MFC]
- VTS_PICTURE constant [MFC]
- VTS_TRISTATE constant [MFC]
- VTS_XSIZE_HIMETRIC constant [MFC]
- VTS_HANDLE constant [MFC]
- VTS_XSIZE_PIXELS constant [MFC]
- VTS_OPTEXCLUSIVE constant [MFC]
- VTS_YSIZE_PIXELS constant [MFC]
ms.assetid: de99c7a9-7aae-4dc4-b723-40c6380543ab
ms.openlocfilehash: 9627452d674aa48a84094665d9499e3a38a3bdf4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50632499"
---
# <a name="variant-parameter-type-constants"></a>Constantes do tipo de parâmetro variante

Este tópico lista as novas constantes que indicam os tipos de parâmetro variante projetados para uso com as classes de controle OLE da biblioteca Microsoft Foundation Class.

A seguir está uma lista de constantes de classe:

##  <a name="_mfc_variant_data_constants"></a> Constantes de dados Variant

- Inteiro de 32 bits do VTS_COLOR usado para representar um valor de cor RGB.

- Ponteiro de um VTS_FONT para o `IFontDisp` interface de um objeto de fonte OLE.

- Valor do identificador VTS_HANDLE um Windows.

- Ponteiro de um VTS_PICTURE para o `IPictureDisp` interface de um objeto de imagem OLE.

- Valor de 16 bits do VTS_OPTEXCLUSIVE usado para um controle que se destina a ser usado em um grupo de controles, como botões de opção. Esse tipo informa o contêiner que, se um controle em um grupo tem um valor TRUE, todos os outros devem ser FALSE.

- VTS_TRISTATE de 16 bits assinado inteiro usado para as propriedades que podem ter um dos três valores possíveis (marcados, desmarcados, indisponíveis), por exemplo, uma caixa de seleção.

- VTS_XPOS_HIMETRIC de 32 bits sem sinal número inteiro usado para representar uma posição ao longo do eixo x em unidades HIMETRIC.

- VTS_YPOS_HIMETRIC de 32 bits sem sinal número inteiro usado para representar uma posição ao longo do eixo y em unidades HIMETRIC.

- VTS_XPOS_PIXELS de 32 bits sem sinal número inteiro usado para representar uma posição ao longo do eixo x em pixels.

- VTS_YPOS_PIXELS de 32 bits sem sinal número inteiro usado para representar uma posição ao longo do eixo y em pixels.

- VTS_XSIZE_PIXELS de 32 bits sem sinal número inteiro usado para representar a largura de um objeto de tela em pixels.

- VTS_YSIZE_PIXELS de 32 bits sem sinal número inteiro usado para representar a altura de um objeto de tela em pixels.

- VTS_XSIZE_HIMETRIC de 32 bits sem sinal número inteiro usado para representar a largura de um objeto de tela em unidades HIMETRIC.

- VTS_YSIZE_HIMETRIC de 32 bits sem sinal número inteiro usado para representar a altura de um objeto de tela em unidades HIMETRIC.

    > [!NOTE]
    >  Constantes de variant adicionais foram definidos para todos os tipos variantes, com exceção do VTS_FONT e VTS_PICTURE, que fornecem um ponteiro para a constante de dados variant. Essas constantes são nomeadas usando o VTS_P`constantname` convenção. Por exemplo, VTS_PCOLOR é um ponteiro para uma constante VTS_COLOR.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

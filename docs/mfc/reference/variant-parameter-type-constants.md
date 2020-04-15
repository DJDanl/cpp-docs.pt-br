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
ms.openlocfilehash: f73c72830216679f8a91d0037d48c1e1b8e400c3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372861"
---
# <a name="variant-parameter-type-constants"></a>Constantes do tipo de parâmetro variante

Este tópico lista novas constantes que indicam tipos de parâmetros de variantes projetados para uso com as classes de controle OLE da Microsoft Foundation Class Library.

A seguir está uma lista de constantes de classe:

## <a name="variant-data-constants"></a><a name="_mfc_variant_data_constants"></a>Constantes de dados de variantes

- VTS_COLOR Um inteiro de 32 bits usado para representar um valor de cor RGB.

- VTS_FONT um ponteiro `IFontDisp` para a interface de um objeto de fonte OLE.

- VTS_HANDLE O valor do windows.

- VTS_PICTURE Um ponteiro `IPictureDisp` para a interface de um objeto de imagem OLE.

- VTS_OPTEXCLUSIVE Um valor de 16 bits usado para um controle que se destina a ser usado em um grupo de controles, como botões de rádio. Este tipo diz ao contêiner que se um controle em um grupo tem um valor TRUE, todos os outros devem ser FALSOs.

- VTS_TRISTATE Um inteiro assinado de 16 bits usado para propriedades que podem ter um dos três valores possíveis (selecionado, limpo, indisponível), por exemplo, uma caixa de seleção.

- VTS_XPOS_HIMETRIC Um inteiro não assinado de 32 bits usado para representar uma posição ao longo do eixo x em unidades HIMETRIC.

- VTS_YPOS_HIMETRIC Um inteiro não assinado de 32 bits usado para representar uma posição ao longo do eixo y em unidades HIMETRIC.

- VTS_XPOS_PIXELS Um inteiro não assinado de 32 bits usado para representar uma posição ao longo do eixo x em pixels.

- VTS_YPOS_PIXELS Um inteiro não assinado de 32 bits usado para representar uma posição ao longo do eixo y em pixels.

- VTS_XSIZE_PIXELS Um inteiro não assinado de 32 bits usado para representar a largura de um objeto de tela em pixels.

- VTS_YSIZE_PIXELS Um inteiro não assinado de 32 bits usado para representar a altura de um objeto de tela em pixels.

- VTS_XSIZE_HIMETRIC Um inteiro não assinado de 32 bits usado para representar a largura de um objeto de tela em unidades HIMETRIC.

- VTS_YSIZE_HIMETRIC Um inteiro não assinado de 32 bits usado para representar a altura de um objeto de tela em unidades HIMETRIC.

    > [!NOTE]
    >  Foram definidas constantes adicionais de variantes para todos os tipos de variantes, com exceção de VTS_FONT e VTS_PICTURE, que fornecem um ponteiro para a constante de dados da variante. Essas constantes são nomeadas usando a convenção VTS_P.`constantname` Por exemplo, VTS_PCOLOR é um ponteiro para uma VTS_COLOR constante.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

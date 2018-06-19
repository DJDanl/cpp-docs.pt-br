---
title: Constantes de tipo de parâmetro variante | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 13820ff4fb07c3743f36ba3ebe33ee56a3a79c7d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33379854"
---
# <a name="variant-parameter-type-constants"></a>Constantes do tipo de parâmetro variante
Este tópico lista as novas constantes que indicam os tipos de parâmetro variante projetados para uso com as classes de controle OLE da biblioteca Microsoft Foundation Class.  
  
 A seguir está uma lista das constantes de classe:  
  
##  <a name="_mfc_variant_data_constants"></a> Constantes de dados Variant  
  
-   **VTS_COLOR** A 32-bit inteiro usado para representar um valor de cor RGB.  
  
-   **VTS_FONT** um ponteiro para o **IFontDisp** interface de um objeto de fonte OLE.  
  
-   **VTS_HANDLE** Windows de um identificador de valor.  
  
-   **VTS_PICTURE** um ponteiro para o `IPictureDisp` interface de um objeto de imagem OLE.  
  
-   **VTS_OPTEXCLUSIVE** A 16 bits valor usado para um controle que se destina a ser usado em um grupo de controles, como botões de opção. Esse tipo informa o contêiner que se um controle em um grupo tem um **TRUE** valor, todos os outros devem ser **FALSE**.  
  
-   **VTS_TRISTATE** inteiro A 16 bits com sinal usado para propriedades que podem ter um dos três valores possíveis (selecionados, desmarcados, não está disponíveis), por exemplo, uma caixa de seleção.  
  
-   **VTS_XPOS_HIMETRIC** inteiro sem sinal de um de 32 bits usado para representar uma posição ao longo do eixo x **HIMETRIC** unidades.  
  
-   **VTS_YPOS_HIMETRIC** inteiro A 32 bits sem sinal usado para representar uma posição ao longo do eixo y no **HIMETRIC** unidades.  
  
-   **VTS_XPOS_PIXELS** inteiro sem sinal de um de 32 bits usado para representar uma posição ao longo do eixo x em pixels.  
  
-   **VTS_YPOS_PIXELS** inteiro A 32 bits sem sinal usado para representar uma posição no eixo y, em pixels.  
  
-   **VTS_XSIZE_PIXELS** inteiro A 32 bits sem sinal usado para representar a largura de um objeto de tela em pixels.  
  
-   **VTS_YSIZE_PIXELS** inteiro A 32 bits sem sinal usado para representar a altura de um objeto de tela em pixels.  
  
-   **VTS_XSIZE_HIMETRIC** inteiro sem sinal de um de 32 bits usado para representar a largura de um objeto de tela de **HIMETRIC** unidades.  
  
-   **VTS_YSIZE_HIMETRIC** inteiro sem sinal de um de 32 bits usado para representar a altura de um objeto de tela de **HIMETRIC** unidades.  
  
    > [!NOTE]
    >  Constantes variantes adicionais foram definidas para todos os tipos de variável, com exceção de **VTS_FONT** e **VTS_PICTURE**, que fornecem um ponteiro para a quantidade de dados variante co nstant. Essas constantes são nomeados por meio de **VTS_P** `constantname` convenção. Por exemplo, **VTS_PCOLOR** é um ponteiro para um **VTS_COLOR** constante.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

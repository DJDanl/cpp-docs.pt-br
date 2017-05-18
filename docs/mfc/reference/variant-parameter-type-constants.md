---
title: "Constantes de tipo de parâmetro variante | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
- VTS_XPOS_HIMETRIC constant
- VTS_FONT constant
- VTS_XPOS_PIXELS constant
- VTS_COLOR constant
- Variants
- VTS_YPOS_PIXELS constant
- VTS_YSIZE_HIMETRIC constant
- VTS_YPOS_HIMETRIC constant
- Variants, parameter type constants
- Variant data constants
- VTS_PICTURE constant
- VTS_TRISTATE constant
- VTS_XSIZE_HIMETRIC constant
- VTS_HANDLE constant
- VTS_XSIZE_PIXELS constant
- VTS_OPTEXCLUSIVE constant
- VTS_YSIZE_PIXELS constant
ms.assetid: de99c7a9-7aae-4dc4-b723-40c6380543ab
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3b09357859b8fc87252fba704de8f2a927981873
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="variant-parameter-type-constants"></a>Constantes do tipo de parâmetro variante
Este tópico lista as constantes novas que indicam os tipos de parâmetro variante projetados para uso com as classes de controle OLE da Microsoft Foundation Class Library.  
  
 A seguir está uma lista de constantes de classe:  
  
##  <a name="_mfc_variant_data_constants"></a>Constantes de dados Variant  
  
-   **VTS_COLOR** inteiro A 32 bits usado para representar um valor de cor RGB.  
  
-   **VTS_FONT** um ponteiro para o **IFontDisp** interface de um objeto de fonte OLE.  
  
-   **VTS_HANDLE** Windows de um valor de identificador.  
  
-   **VTS_PICTURE** um ponteiro para o `IPictureDisp` interface de um objeto de imagem OLE.  
  
-   **VTS_OPTEXCLUSIVE** valor A 16 bits usado para um controle que se destina a ser usado em um grupo de controles, como botões de opção. Esse tipo informa o contêiner que se um controle em um grupo tem um **TRUE** valor, todos os outros devem ser **FALSE**.  
  
-   **VTS_TRISTATE** inteiro A 16 bits usados para as propriedades que podem ter um dos três valores possíveis (selecionados, desmarcados, não está disponíveis), por exemplo, uma caixa de seleção.  
  
-   **VTS_XPOS_HIMETRIC** A 32-bit inteiro sem sinal usado para representar uma posição ao longo do eixo x **HIMETRIC** unidades.  
  
-   **VTS_YPOS_HIMETRIC** A 32-bit inteiro sem sinal usado para representar uma posição ao longo do eixo y no **HIMETRIC** unidades.  
  
-   **VTS_XPOS_PIXELS** A 32-bit inteiro sem sinal usado para representar uma posição ao longo do eixo x em pixels.  
  
-   **VTS_YPOS_PIXELS** inteiro A 32 bits sem sinal usado para representar uma posição no eixo y em pixels.  
  
-   **VTS_XSIZE_PIXELS** inteiro A 32 bits sem sinal usado para representar a largura de um objeto de tela em pixels.  
  
-   **VTS_YSIZE_PIXELS** inteiro A 32 bits sem sinal usado para representar a altura de um objeto de tela em pixels.  
  
-   **VTS_XSIZE_HIMETRIC** A 32-bit inteiro sem sinal usado para representar a largura de um objeto de tela de **HIMETRIC** unidades.  
  
-   **VTS_YSIZE_HIMETRIC** A 32-bit inteiro sem sinal usado para representar a altura de um objeto de tela de **HIMETRIC** unidades.  
  
    > [!NOTE]
    >  Constantes variantes adicionais foram definidas para todos os tipos variantes, com exceção de **VTS_FONT** e **VTS_PICTURE**, que fornecem um ponteiro para a constante de dados variant. Essas constantes são nomeados usando o **VTS_P** `constantname` convenção. Por exemplo, **VTS_PCOLOR** é um ponteiro para um **VTS_COLOR** constante.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)


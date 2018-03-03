---
title: Estrutura LOGPEN | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LOGPEN
dev_langs:
- C++
helpviewer_keywords:
- LOGPEN structure [MFC]
ms.assetid: a89e8690-6b61-4af5-990c-7c82da24f3b0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b7bfa598a59f62c11dbda13356559816b5bd47ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="logpen-structure"></a>Estrutura LOGPEN
O `LOGPEN` estrutura define o estilo, a largura e a cor de uma caneta, um objeto usado para desenhar linhas e bordas. O [CPen::CreatePenIndirect](../../mfc/reference/cpen-class.md#createpenindirect) função usa o `LOGPEN` estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagLOGPEN {  /* lgpn */  
    UINT lopnStyle;  
    POINT lopnWidth;  
    COLORREF lopnColor;  
} LOGPEN;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *lopnStyle*  
 Especifica o tipo de caneta. Esse membro pode ser um dos seguintes valores:  
  
- **PS_SOLID** cria uma caneta sólida.  
  
- **PS_DASH** cria uma caneta tracejada. (Válido somente quando a largura da caneta é 1).  
  
- **PS_DOT** cria uma caneta pontilhada. (Válido somente quando a largura da caneta é 1).  
  
- **PS_DASHDOT** cria uma caneta com alternando traços e pontos. (Válido somente quando a largura da caneta é 1).  
  
- **PS_DASHDOTDOT** cria uma caneta com traços e pontos duplos alternados. (Válido somente quando a largura da caneta é 1).  
  
- **PS_NULL** cria uma caneta nulo.  
  
- **PS_INSIDEFRAME** cria uma caneta que desenha uma linha dentro do quadro de formas fechadas gerados por GDI saída funções que especificam um retângulo delimitador (por exemplo, o **elipse**, **retângulo**, `RoundRect`, `Pie`, e `Chord` funções de membro). Quando este estilo é usado com GDI saída funções que não especificam um retângulo delimitador (por exemplo, o `LineTo` função de membro), a área de desenho da caneta não é limitada por um quadro.  
  
     Se tiver uma caneta o **PS_INSIDEFRAME** estilo e uma cor que não corresponde a uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor pontilhada. O **PS_SOLID** estilo da caneta não pode ser usado para criar uma caneta com uma cor pontilhada. O **PS_INSIDEFRAME** estilo é idêntico ao **PS_SOLID** se a largura da caneta é menor ou igual a 1.  
  
     Quando o **PS_INSIDEFRAME** estilo é usado com objetos GDI produzidos por funções diferentes de **elipse**, **retângulo**, e `RoundRect`, a linha não pode ser completamente dentro do quadro especificado.  
  
 *lopnWidth*  
 Especifica a largura da caneta, em unidades lógicas. Se o **lopnWidth** membro é 0, a caneta é 1 pixel de largura em dispositivos de varredura independentemente do modo de mapeamento atual.  
  
 *lopnColor*  
 Especifica a cor da caneta.  
  
## <a name="remarks"></a>Comentários  
 O **y** valor o [ponto](../../mfc/reference/point-structure1.md) estrutura o **lopnWidth** membro não é usado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CPen::CreatePenIndirect](../../mfc/reference/cpen-class.md#createpenindirect)


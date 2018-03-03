---
title: Estrutura DEVNAMES | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DEVNAMES
dev_langs:
- C++
helpviewer_keywords:
- DEVNAMES [MFC]
ms.assetid: aac97f60-2169-471a-ba5d-c0baed9eed9a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a3627af10dfb6fd18c54f772d26c33123127613a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="devnames-structure"></a>Estrutura DEVNAMES
O `DEVNAMES` estrutura contém cadeias de caracteres que identificam o driver, dispositivos e nomes de porta de saída para uma impressora.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagDEVNAMES { /* dvnm */  
    WORD wDriverOffset;  
    WORD wDeviceOffset;  
    WORD wOutputOffset;  
    WORD wDefault; */* driver,
    device,
    and port-name strings follow wDefault */  
} DEVNAMES;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *wDriverOffset*  
 (Entrada/saída) Especifica o deslocamento de caracteres em uma cadeia de caracteres terminada em nulo que contém o nome do arquivo (sem a extensão) do driver de dispositivo. Na entrada, essa cadeia de caracteres é usada para determinar a impressora seja exibida inicialmente na caixa de diálogo.  
  
 *wDeviceOffset*  
 (Entrada/saída) Especifica o deslocamento de caracteres para a cadeia terminada em nulo (máximo de 32 bytes incluindo o nulo) que contém o nome do dispositivo. Essa cadeia de caracteres deve ser idêntica de **dmDeviceName** membro o [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura.  
  
 *wOutputOffset*  
 (Entrada/saída) Especifica o deslocamento de caracteres para a cadeia de caracteres terminada em nulo que contém o nome de dispositivo para a mídia de saída físico (porta de saída).  
  
 *wDefault*  
 Especifica se as cadeias de caracteres dentro de `DEVNAMES` estrutura identificar a impressora padrão. Essa cadeia de caracteres é usada para verificar se a impressora padrão não foi alterado desde a última operação de impressão. Na saída, se o **DN_DEFAULTPRN** sinalizador for definido, os outros valores `DEVNAMES` estrutura são verificados em relação a impressora padrão atual. Se qualquer uma das cadeias de caracteres não corresponderem, será exibida uma mensagem de aviso informando ao usuário que o documento talvez precisem ser reformatado. Na saída, o **wDefault** membro é alterado apenas se a caixa de diálogo Configurar impressão foi exibida e o usuário escolhe o botão Okey. O **DN_DEFAULTPRN** sinalizador será definido se a impressora padrão foi selecionada. Se uma impressora específica for selecionada, o sinalizador não está definido. Todos os outros bits nesse membro são reservados para uso interno pelo procedimento de caixa de diálogo de impressão.  
  
## <a name="remarks"></a>Comentários  
 O **PrintDlg** função usa essas cadeias de caracteres para inicializar os membros na caixa de diálogo de impressão definidas pelo sistema. Quando o usuário fecha a caixa de diálogo, serão retornadas informações sobre a impressora selecionada nessa estrutura.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** commdlg.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CPrintDialog::CreatePrinterDC](../../mfc/reference/cprintdialog-class.md#createprinterdc)



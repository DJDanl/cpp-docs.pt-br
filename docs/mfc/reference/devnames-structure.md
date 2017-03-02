---
title: Estrutura DEVNAMES | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DEVNAMES
dev_langs:
- C++
helpviewer_keywords:
- DEVNAMES
ms.assetid: aac97f60-2169-471a-ba5d-c0baed9eed9a
caps.latest.revision: 11
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 698a338c94dfa402dd51fa4f683b92a5d30cc0cd
ms.lasthandoff: 02/25/2017

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
 (Entrada/saída) Especifica o deslocamento em caracteres para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo (sem a extensão) do driver de dispositivo. Na entrada, essa cadeia de caracteres é usada para determinar a impressora será exibido inicialmente na caixa de diálogo.  
  
 *wDeviceOffset*  
 (Entrada/saída) Especifica o deslocamento em caracteres para a sequência terminada em nulo (máximo de 32 bytes, incluindo a nula) que contém o nome do dispositivo. Essa cadeia de caracteres deve ser idêntica do **dmDeviceName** membro do [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) estrutura.  
  
 *wOutputOffset*  
 (Entrada/saída) Especifica o deslocamento em caracteres para a cadeia de caracteres terminada em nulo que contém o nome de dispositivo para a mídia de saída física (porta de saída).  
  
 *wDefault*  
 Especifica se as cadeias de caracteres contidos no `DEVNAMES` estrutura identificam a impressora padrão. Essa cadeia de caracteres é usada para verificar se a impressora padrão não foi alterado desde a última operação de impressa. Na saída, se o **DN_DEFAULTPRN** sinalizador estiver definido, os outros valores `DEVNAMES` estrutura são verificados em relação a impressora padrão atual. Se qualquer uma das cadeias de caracteres não corresponderem, será exibida uma mensagem de aviso informando ao usuário que o documento talvez precise ser reformatado. Na saída, o **wDefault** membro é alterado somente se a caixa de diálogo Configurar impressão foi exibida e o usuário escolhe o botão Okey. O **DN_DEFAULTPRN** sinalizador é definido se a impressora padrão foi selecionada. Se uma impressora específica for selecionada, o sinalizador não está definido. Todos os outros bits nesse membro são reservados para uso interno pelo procedimento de caixa de diálogo Imprimir.  
  
## <a name="remarks"></a>Comentários  
 O **PrintDlg** função usa essas cadeias para inicializar membros na caixa de diálogo de impressão definidas pelo sistema. Quando o usuário fecha a caixa de diálogo, informações sobre a impressora selecionada são retornadas nessa estrutura.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** commdlg.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CPrintDialog::CreatePrinterDC](../../mfc/reference/cprintdialog-class.md#createprinterdc)




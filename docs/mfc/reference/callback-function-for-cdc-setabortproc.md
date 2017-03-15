---
title: "Função de retorno de chamada para CDC:: SetAbortProc | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Callback Function for CDC::SetAbortProc
dev_langs:
- C++
helpviewer_keywords:
- callback functions, for CDC::SetAbortProc
ms.assetid: daa36d5d-15de-40fc-8d37-a865d06c4710
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
ms.openlocfilehash: 1ba16ea60d8b18abd1962ded2da7e11ff2ef09a1
ms.lasthandoff: 02/25/2017

---
# <a name="callback-function-for-cdcsetabortproc"></a>Função de retorno de chamada para CDC::SetAbortProc
O nome *AbortFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
BOOL CALLBACK EXPORT AbortFunc(
    HDC hPr,  
    int code);
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hPr*  
 Identifica o contexto do dispositivo.  
  
 `code`  
 Especifica se um erro ocorreu. Ele é 0 se nenhum erro tiver ocorrido. É **SP_OUTOFDISK** se o Gerenciador de impressão está sem espaço em disco e mais espaço em disco estará disponível se o aplicativo espera. Se `code` é **SP_OUTOFDISK**, o aplicativo não precisa interromper o trabalho de impressão. Se não estiver, ele deve produzir para o Gerenciador de impressão chamando o **PeekMessage** ou **GetMessage** função do Windows.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor de retorno da função de manipulador de anulação é diferente de zero se o trabalho de impressão é continuar e 0 se for cancelado.  
  
## <a name="remarks"></a>Comentários  
 O nome real deve ser exportado conforme descrito na seção comentários de [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc)



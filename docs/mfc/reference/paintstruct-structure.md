---
title: Estrutura PAINTSTRUCT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- PAINTSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- PAINTSTRUCT structure
ms.assetid: 81ce4993-3e89-43b2-8c98-7946f1314d24
caps.latest.revision: 12
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 07b79b9ae20bd6e5648c67fa277ddde2929028c7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="paintstruct-structure"></a>Estrutura PAINTSTRUCT
O `PAINTSTRUCT` estrutura contém informações que podem ser usadas para pintar a área cliente de uma janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagPAINTSTRUCT {  
    HDC hdc;  
    BOOL fErase;  
    RECT rcPaint;  
    BOOL fRestore;  
    BOOL fIncUpdate;  
    BYTE rgbReserved[16];  
} PAINTSTRUCT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hDC*  
 Identifica o contexto de exibição a ser usada para pintura.  
  
 *fErase*  
 Especifica se o plano de fundo precisa ser redesenhado. Não é 0 se o aplicativo deve redesenhar o plano de fundo. O aplicativo é responsável por desenhar o plano de fundo se uma classe de janela do Windows é criada sem um pincel em segundo plano (consulte a descrição do **hbrBackground** membro do [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]).  
  
 *rcPaint*  
 Especifica a parte superior esquerda e inferior direita cantos do retângulo no qual a pintura é solicitada.  
  
 *fRestore*  
 Membro reservado. Ele é usado internamente pelo Windows.  
  
 *fIncUpdate*  
 Membro reservado. Ele é usado internamente pelo Windows.  
  
 *rgbReserved [16]*  
 Membro reservado. Um bloco reservado de memória usada internamente pelo Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CPaintDC::m_ps](../../mfc/reference/cpaintdc-class.md#m_ps)



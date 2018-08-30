---
title: Estrutura PAINTSTRUCT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- PAINTSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- PAINTSTRUCT structure [MFC]
ms.assetid: 81ce4993-3e89-43b2-8c98-7946f1314d24
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dddf9c117f2366496609f8bdf4ffc2f069f66ace
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43199567"
---
# <a name="paintstruct-structure"></a>Estrutura PAINTSTRUCT
O `PAINTSTRUCT` estrutura contém informações que podem ser usadas para pintar a área de cliente de uma janela.  
  
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
 Identifica o contexto de exibição a ser usado para pintura.  
  
 *fErase*  
 Especifica se o plano de fundo precisa ser redesenhado. Não é 0 se o aplicativo deve redesenhar a tela de fundo. O aplicativo é responsável por desenhar a tela de fundo se uma classe de janela do Windows é criada sem um pincel de plano de fundo (consulte a descrição do `hbrBackground` membro do [WNDCLASS](https://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura no SDK do Windows).  
  
 *rcPaint*  
 Especifica o canto superior esquerdo e inferior direita cantos do retângulo no qual a pintura é solicitada.  
  
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


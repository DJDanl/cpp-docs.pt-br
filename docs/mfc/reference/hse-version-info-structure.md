---
title: Estrutura HSE_VERSION_INFO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- HSE_VERSION_INFO
dev_langs:
- C++
helpviewer_keywords:
- HSE_VERSION_INFO structure [MFC]
ms.assetid: 4837312d-68c8-4d05-9afa-1934d7d49b20
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: daf1565c2fe2d7a4620f83b765671fea80502102
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37335809"
---
# <a name="hseversioninfo-structure"></a>Estrutura HSE_VERSION_INFO
Essa estrutura é apontada pelo *objasperror* parâmetro no `CHttpServer::GetExtensionVersion` função de membro. Ele fornece o número de versão do ISA e uma descrição de texto do ISA.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _HSE_VERSION_INFO {  
    DWORD dwExtensionVersion;  
    CHAR lpszExtensionDesc[HSE_MAX_EXT_DLL_NAME_LEN];  
} HSE_VERSION_INFO, *LPHSE_VERSION_INFO;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwExtensionVersion*  
 O número de versão dos ISA.  
  
 *lpszExtensionDesc*  
 Texto de descrição do ISA. A implementação padrão fornece o texto do espaço reservado; substituir `CHttpServer::GetExtensionVersion` para fornecer sua própria descrição.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** httpext.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)


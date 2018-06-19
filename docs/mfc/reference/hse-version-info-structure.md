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
ms.openlocfilehash: acdf63e062aab1407daee461e22f00f5d3c59cee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33369880"
---
# <a name="hseversioninfo-structure"></a>Estrutura HSE_VERSION_INFO
Essa estrutura é apontada pelo `pVer` parâmetro o `CHttpServer::GetExtensionVersion` função de membro. Ele fornece o número de versão do ISA e uma descrição textual do ISA.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _HSE_VERSION_INFO {  
    DWORD dwExtensionVersion;  
    CHAR lpszExtensionDesc[HSE_MAX_EXT_DLL_NAME_LEN];  
} HSE_VERSION_INFO, *LPHSE_VERSION_INFO;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwExtensionVersion*  
 O número de versão do ISA.  
  
 *lpszExtensionDesc*  
 Texto de descrição do ISA. A implementação padrão fornece o texto do espaço reservado; substituir `CHttpServer::GetExtensionVersion` para fornecer sua própria descrição.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** httpext.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)


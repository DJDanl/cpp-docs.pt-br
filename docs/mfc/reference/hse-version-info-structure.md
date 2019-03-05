---
title: Estrutura HSE_VERSION_INFO
ms.date: 11/04/2016
f1_keywords:
- HSE_VERSION_INFO
helpviewer_keywords:
- HSE_VERSION_INFO structure [MFC]
ms.assetid: 4837312d-68c8-4d05-9afa-1934d7d49b20
ms.openlocfilehash: 97f34bebae8a486a825d04b23c5a92fbd4aefa42
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57267830"
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

*dwExtensionVersion*<br/>
O número de versão dos ISA.

*lpszExtensionDesc*<br/>
Texto de descrição do ISA. A implementação padrão fornece o texto do espaço reservado; substituir `CHttpServer::GetExtensionVersion` para fornecer sua própria descrição.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** httpext.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)

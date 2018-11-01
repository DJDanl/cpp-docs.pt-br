---
title: Estrutura HSE_VERSION_INFO
ms.date: 11/04/2016
f1_keywords:
- HSE_VERSION_INFO
helpviewer_keywords:
- HSE_VERSION_INFO structure [MFC]
ms.assetid: 4837312d-68c8-4d05-9afa-1934d7d49b20
ms.openlocfilehash: 6bdb668be037dfaa07e1121e4b61ea332e430e31
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50577275"
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


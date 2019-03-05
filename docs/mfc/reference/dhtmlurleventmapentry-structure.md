---
title: Estrutura DHtmlUrlEventMapEntry
ms.date: 11/04/2016
f1_keywords:
- DHtmlUrlEventMapEntry
helpviewer_keywords:
- DHtmlUrlEventMapEntry structure [MFC]
ms.assetid: 43117c1f-1a51-406c-aa2f-fea647080049
ms.openlocfilehash: c9b58067a9c8b6a71cd22b654a2f82ba0f8bfe36
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57292647"
---
# <a name="dhtmlurleventmapentry-structure"></a>Estrutura DHtmlUrlEventMapEntry

O `DHtmlUrlEventMapEntry` estrutura oferece suporte ao mapa de evento de várias URLs.

## <a name="syntax"></a>Sintaxe

```
struct DHtmlUrlEventMapEntry
{
LPCTSTR szUrl;
const DHtmlEventMapEntry *pEventMap;
};
```

#### <a name="parameters"></a>Parâmetros

*szUrl*<br/>
A URL.

*pEventMap*<br/>
O mapa de evento associado à URL.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdhtml.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)

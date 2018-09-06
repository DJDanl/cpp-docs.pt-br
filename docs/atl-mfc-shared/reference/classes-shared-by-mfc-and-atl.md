---
title: Classes compartilhadas por MFC e ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- shared classes, classes
ms.assetid: ca8b4b6b-744d-430b-b31f-d5b2f17bf210
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 566164f40f8795c8402b04c9c25e13dda036961d
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43765431"
---
# <a name="classes-shared-by-mfc-and-atl"></a>Classes compartilhadas por MFC e ATL

A tabela a seguir lista as classes compartilhadas entre MFC e ATL.

|Classe|Descrição|Arquivo de cabeçalho|
|-----------|-----------------|-----------------|
|[CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md)|Fornece métodos para gerenciar os valores de data e hora associados a um arquivo.|atltime.h|
|[CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)|Fornece métodos para gerenciamento de data relativa e valores de tempo associados com um arquivo.|atltime.h|
|[CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md)|Representa um objeto de cadeia de caracteres com um buffer de caracteres fixa.|cstringt.h|
|[CImage](../../atl-mfc-shared/reference/cimage-class.md)|fornece suporte a bitmap aprimorada, incluindo a capacidade de carregar e salvar imagens em formatos GIF, JPEG, BMP e elementos gráficos PNG (Portable Network).|atlimage.h|
|[COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)|Encapsula o tipo de dados de data usado na automação OLE.|atlcomtime|
|[COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md)|Representa um tempo relativo, um período de tempo.|atlcomtime|
|[CPoint](../../atl-mfc-shared/reference/cpoint-class.md)|Uma classe semelhante do Windows [ponto](../../mfc/reference/point-structure1.md) estrutura que também inclui funções de membro para manipular `CPoint` e `POINT` estruturas.|atltypes. h|
|[CRect](../../atl-mfc-shared/reference/crect-class.md)|Uma classe semelhante de um Windows [RECT](../../mfc/reference/rect-structure1.md) estrutura que também inclui funções de membro para manipular `CRect` objetos e Windows `RECT` estruturas.|atltypes. h|
|[CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)|Representa um `CSimpleStringT` objeto.|atlsimpstr.h|
|[CSize](../../atl-mfc-shared/reference/csize-class.md)|Uma classe semelhante à estrutura de tamanho do Windows, que implementa uma coordenada ou posição relativa.|atltypes. h|
|[CStrBufT](../../atl-mfc-shared/reference/cstrbuft-class.md)|Fornece a limpeza de recursos automáticos `GetBuffer` e `ReleaseBuffer` chama um existente `CStringT` objeto.|atlsimpstr.h|
|[CStringData](../../atl-mfc-shared/reference/cstringdata-class.md)|Representa os dados de um objeto de cadeia de caracteres.|atlsimpstr.h|
|[CStringT](../../atl-mfc-shared/reference/cstringt-class.md)|Representa um `CStringT` objeto.|cstringt. h (dependente do MFC) atlstr. h (independente do MFC)|
|[CTime](../../atl-mfc-shared/reference/ctime-class.md)|Representa uma data e a hora absoluta.|atltime.h|
|[CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)|Um valor de tempo, que é armazenado internamente como o número de segundos no período de tempo.|atltime.h|
|[IAtlStringMgr](../../atl-mfc-shared/reference/iatlstringmgr-class.md)|Representa a interface para um `CStringT` Gerenciador de memória.|atlsimpstr.h|

## <a name="see-also"></a>Consulte também

[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)


---
title: Classes compartilhadas pelos MFC e ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords: shared classes, classes
ms.assetid: ca8b4b6b-744d-430b-b31f-d5b2f17bf210
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5e74a0fb32a9f0dc95837b9c8d633001ac79da8a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="classes-shared-by-mfc-and-atl"></a>Classes compartilhadas pelos MFC e ATL
A tabela a seguir lista as classes compartilhadas entre MFC e ATL.  
  
|Classe|Descrição|Arquivo de cabeçalho|  
|-----------|-----------------|-----------------|  
|[CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md)|Fornece métodos para gerenciar os valores de data e hora associados a um arquivo.|atltime.h|  
|[CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)|Fornece métodos para o gerenciamento de data relativa e valores de tempo associados a um arquivo.|atltime.h|  
|[CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md)|Representa um objeto de cadeia de caracteres com um buffer de caracteres fixa.|cstringt.h|  
|[CImage](../../atl-mfc-shared/reference/cimage-class.md)|Fornece suporte de bitmap aprimorada, incluindo a capacidade de carregar e salvar imagens em formatos JPEG, GIF, BMP e elementos gráficos PNG (Portable Network).|atlimage.h|  
|[COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)|Encapsula o **data** tipo de dados usado na automação OLE.|atlcomtime.h|  
|[COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md)|Representa uma hora relativa, um período de tempo.|atlcomtime.h|  
|[CPoint](../../atl-mfc-shared/reference/cpoint-class.md)|Uma classe semelhante para o Windows [ponto](../../mfc/reference/point-structure1.md) estrutura que também inclui funções de membro para manipular `CPoint` e **ponto** estruturas.|atltypes.h|  
|[CRect](../../atl-mfc-shared/reference/crect-class.md)|Uma classe semelhante a um Windows [RECT](../../mfc/reference/rect-structure1.md) estrutura que também inclui funções de membro para manipular `CRect` objetos e Windows `RECT` estruturas.|atltypes.h|  
|[CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)|Representa uma `CSimpleStringT` objeto.|atlsimpstr.h|  
|[CSize](../../atl-mfc-shared/reference/csize-class.md)|Uma classe é semelhante à estrutura de tamanho do Windows, que implementa uma coordenada relativa ou posição.|atltypes.h|  
|[CStrBufT](../../atl-mfc-shared/reference/cstrbuft-class.md)|Fornece a limpeza automática de recursos de `GetBuffer` e `ReleaseBuffer` chama um existente `CStringT` objeto.|atlsimpstr.h|  
|[CStringData](../../atl-mfc-shared/reference/cstringdata-class.md)|Representa os dados de um objeto de cadeia de caracteres.|atlsimpstr.h|  
|[CStringT](../../atl-mfc-shared/reference/cstringt-class.md)|Representa uma `CStringT` objeto.|cstringt.h (MFC dependente) atlstr.h (independente do MFC)|  
|[CTime](../../atl-mfc-shared/reference/ctime-class.md)|Representa uma data e hora absoluta.|atltime.h|  
|[CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)|Um valor de tempo, que é armazenado internamente como o número de segundos em que o período de tempo.|atltime.h|  
|[IAtlStringMgr](../../atl-mfc-shared/reference/iatlstringmgr-class.md)|Representa a interface para um `CStringT` Gerenciador de memória.|atlsimpstr.h|  
  
## <a name="see-also"></a>Consulte também  
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



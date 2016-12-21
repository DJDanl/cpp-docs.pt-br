---
title: "Classes compartilhadas por MFC e ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes compartilhadas, classes"
ms.assetid: ca8b4b6b-744d-430b-b31f-d5b2f17bf210
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes compartilhadas por MFC e ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir lista as classes compartilhadas entre MFC e ATL.  
  
|Classe|Descrição|Arquivo de cabeçalho|  
|-----------|-----------------|-----------------|  
|[CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md)|Fornece métodos para gerenciar os valores de data e hora associados a um arquivo.|atltime.h|  
|[CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)|Fornece métodos para gerenciamento de data relativa e valores de tempo associadas a um arquivo.|atltime.h|  
|[CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md)|Representa um objeto de cadeia de caracteres com um buffer de caracteres fixa.|cstringt. h|  
|[CImage](../../atl-mfc-shared/reference/cimage-class.md)|Fornece suporte a bitmap aprimorada, incluindo a capacidade de carregar e salvar imagens em formatos JPEG, GIF, BMP e elementos gráficos PNG (Portable Network).|atlimage.h|  
|[COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)|Encapsula o **DATA** tipo de dados usado na automação OLE.|atlcomtime.h|  
|[COleDateTimeSpan](../Topic/COleDateTimeSpan%20Class.md)|Representa um tempo relativo, um período de tempo.|atlcomtime.h|  
|[CPoint](../Topic/CPoint%20Class.md)|Uma classe semelhante do Windows [PONTO](../../mfc/reference/point-structure1.md) estrutura também inclui funções de membro para manipular `CPoint` e **PONTO** estruturas.|atltypes. h|  
|[CRect](../../atl-mfc-shared/reference/crect-class.md)|Uma classe semelhante a um Windows [RECT](RECT%20Structure1.md) estrutura também inclui funções de membro para manipular `CRect` objetos e Windows `RECT` estruturas.|atltypes. h|  
|[CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)|Representa uma `CSimpleStringT` objeto.|atlsimpstr.h|  
|[CSize](../../atl-mfc-shared/reference/csize-class.md)|Uma classe semelhante à estrutura de TAMANHO do Windows, que implementa uma coordenada relativa ou posição.|atltypes. h|  
|[CStrBufT](../../atl-mfc-shared/reference/cstrbuft-class.md)|Fornece a limpeza de recursos automáticos para `GetBuffer` e `ReleaseBuffer` chama um existente `CStringT` objeto.|atlsimpstr.h|  
|[CStringData](../../atl-mfc-shared/reference/cstringdata-class.md)|Representa os dados de um objeto de cadeia de caracteres.|atlsimpstr.h|  
|[CStringT](../../atl-mfc-shared/reference/cstringt-class.md)|Representa uma `CStringT` objeto.|atlstr.h cstringt. h (dependente do MFC) (independente do MFC)|  
|[CTime](../Topic/CTime%20Class.md)|Representa uma data e hora absoluta.|atltime.h|  
|[CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)|Um valor de tempo, que é armazenado internamente como o número de segundos no período de tempo.|atltime.h|  
|[IAtlStringMgr](../Topic/IAtlStringMgr%20Class.md)|Representa a interface para um `CStringT` Gerenciador de memória.|atlsimpstr.h|  
  
## <a name="see-also"></a>Consulte também  
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)



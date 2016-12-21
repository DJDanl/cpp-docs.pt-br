---
title: "Classe de CD2DBitmap | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "afxrendertarget/CD2DBitmap"
  - "CD2DBitmap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CD2DBitmap"
ms.assetid: 2b3686f1-812c-462b-b449-9f0cb6949bf6
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CD2DBitmap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1Bitmap.  
  
## Sintaxe  
  
```  
class CD2DBitmap : public CD2DResource;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBitmap::CD2DBitmap](../Topic/CD2DBitmap::CD2DBitmap.md)|Sobrecarregado.  Constrói um objeto de CD2DBitmap de HBITMAP.|  
|[CD2DBitmap::~CD2DBitmap](../Topic/CD2DBitmap::~CD2DBitmap.md)|O destrutor.  Chamado quando um objeto bitmap de D2D é destruído.|  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBitmap::CD2DBitmap](../Topic/CD2DBitmap::CD2DBitmap.md)|Sobrecarregado.  Constrói um objeto de CD2DBitmap.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBitmap::Attach](../Topic/CD2DBitmap::Attach.md)|O recurso existente de anexa interfaces para o objeto|  
|[CD2DBitmap::CopyFromBitmap](../Topic/CD2DBitmap::CopyFromBitmap.md)|Copia a região especificada de bitmap especificado no projeto atual|  
|[CD2DBitmap::CopyFromMemory](../Topic/CD2DBitmap::CopyFromMemory.md)|Copia a região especificada de memória de bitmap atual|  
|[CD2DBitmap::CopyFromRenderTarget](../Topic/CD2DBitmap::CopyFromRenderTarget.md)|Copia a região especificada de especificado processam o alvo atual no bitmap|  
|[CD2DBitmap::Create](../Topic/CD2DBitmap::Create.md)|Cria um CD2DBitmap.  Overrides \( [CD2DResource::Create](../Topic/CD2DResource::Create.md).\)|  
|[CD2DBitmap::Destroy](../Topic/CD2DBitmap::Destroy.md)|For um objeto de CD2DBitmap.  Overrides \( [CD2DResource::Destroy](../Topic/CD2DResource::Destroy.md).\)|  
|[CD2DBitmap::Detach](../Topic/CD2DBitmap::Detach.md)|Dispara a interface de recurso de objeto|  
|[CD2DBitmap::Get](../Topic/CD2DBitmap::Get.md)|Interface de retorna ID2D1Bitmap|  
|[CD2DBitmap::GetDPI](../Topic/CD2DBitmap::GetDPI.md)|Retornar os pontos por polegada \(DPI\) de bitmap|  
|[CD2DBitmap::GetPixelFormat](../Topic/CD2DBitmap::GetPixelFormat.md)|Recupera o formato de pixel e o modo alfa de bitmap|  
|[CD2DBitmap::GetPixelSize](../Topic/CD2DBitmap::GetPixelSize.md)|Retorna o tamanho, em unidades de dependente de dispositivo \(pixels\), de bitmap|  
|[CD2DBitmap::GetSize](../Topic/CD2DBitmap::GetSize.md)|Retorna o tamanho, em pixels independentes \(DIPs\), de bitmap|  
|[CD2DBitmap::IsValid](../Topic/CD2DBitmap::IsValid.md)|Validade de recursos das verificações \(Substitui [CD2DResource::IsValid](../Topic/CD2DResource::IsValid.md)\).|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBitmap::CommonInit](../Topic/CD2DBitmap::CommonInit.md)|Inicializa o objeto|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBitmap::operator ID2D1Bitmap\*](../Topic/CD2DBitmap::operator%20ID2D1Bitmap*.md)|Interface de retorna ID2D1Bitmap|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DBitmap::m\_bAutoDestroyHBMP](../Topic/CD2DBitmap::m_bAutoDestroyHBMP.md)|RECTIFIQUE se o m\_hBmpSrc é destruído; se não FALSO.|  
|[CD2DBitmap::m\_hBmpSrc](../Topic/CD2DBitmap::m_hBmpSrc.md)|Identificador de bitmap de origem.|  
|[CD2DBitmap::m\_lpszType](../Topic/CD2DBitmap::m_lpszType.md)|Tipo de recurso.|  
|[CD2DBitmap::m\_pBitmap](../Topic/CD2DBitmap::m_pBitmap.md)|Armazena um ponteiro para um objeto de ID2D1Bitmap.|  
|[CD2DBitmap::m\_sizeDest](../Topic/CD2DBitmap::m_sizeDest.md)|Tamanho de destino de bitmap.|  
|[CD2DBitmap::m\_strPath](../Topic/CD2DBitmap::m_strPath.md)|Caminho de arquivo Botmap.|  
|[CD2DBitmap::m\_uiResID](../Topic/CD2DBitmap::m_uiResID.md)|Identificação do recurso de bitmap|  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CD2DResource](../Topic/CD2DResource%20Class.md)  
  
 [CD2DBitmap](../../mfc/reference/cd2dbitmap-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)
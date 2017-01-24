---
title: "Classe de CBitmap | Microsoft Docs"
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
  - "CBitmap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CBitmap"
  - "desenhar, ferramentas"
  - "GDI de bitmap"
ms.assetid: 3980616a-c59d-495a-86e6-62bd3889c84c
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CBitmap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula um bitmap de \(GDI\) de interface do dispositivo de elementos gráficos do windows e fornece funções de membro para manipular o projeto.  
  
## Sintaxe  
  
```  
class CBitmap : public CGdiObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmap::CBitmap](../Topic/CBitmap::CBitmap.md)|Constrói um objeto de `CBitmap` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmap::CreateBitmap](../Topic/CBitmap::CreateBitmap.md)|Inicializa o objeto com um bitmap de memória de dependente de dispositivo que tenha uma largura, uma altura, e um padrão de bits especificados.|  
|[CBitmap::CreateBitmapIndirect](../Topic/CBitmap::CreateBitmapIndirect.md)|Inicializa o objeto com um bitmap com a largura, altura, e o padrão de bits \(se ela é especificado\) dado em uma estrutura de **BITMAP** .|  
|[CBitmap::CreateCompatibleBitmap](../Topic/CBitmap::CreateCompatibleBitmap.md)|Inicializa o objeto com um bitmap de modo que seja compatível com um dispositivo especificado.|  
|[CBitmap::CreateDiscardableBitmap](../Topic/CBitmap::CreateDiscardableBitmap.md)|Inicializa o objeto com um bitmap discardable que é compatível com um dispositivo especificado.|  
|[CBitmap::FromHandle](../Topic/CBitmap::FromHandle.md)|Retorna um ponteiro para um objeto de `CBitmap` quando dado um identificador para um bitmap de `HBITMAP` do windows.|  
|[CBitmap::GetBitmap](../Topic/CBitmap::GetBitmap.md)|Preenche uma estrutura de **BITMAP** com informações sobre o projeto.|  
|[CBitmap::GetBitmapBits](../Topic/CBitmap::GetBitmapBits.md)|Copia os bits de bitmap especificado em buffer especificado.|  
|[CBitmap::GetBitmapDimension](../Topic/CBitmap::GetBitmapDimension.md)|Retorna a largura e altura de bitmap.  A altura e a largura são assumidas para ter sido definidas anteriormente pela função de membro de [SetBitmapDimension](../Topic/CBitmap::SetBitmapDimension.md) .|  
|[CBitmap::LoadBitmap](../Topic/CBitmap::LoadBitmap.md)|Inicializa o objeto carregando um recurso chamado de bitmap do arquivo executável do aplicativo e anexando o bitmap para o objeto.|  
|[CBitmap::LoadMappedBitmap](../Topic/CBitmap::LoadMappedBitmap.md)|Carrega um bitmap e mapeia cores para as cores atuais do sistema.|  
|[CBitmap::LoadOEMBitmap](../Topic/CBitmap::LoadOEMBitmap.md)|Inicializa o objeto carregando um bitmap predefinido do windows e anexando o bitmap para o objeto.|  
|[CBitmap::SetBitmapBits](../Topic/CBitmap::SetBitmapBits.md)|Define os bits de um bitmap de bits para valores especificados.|  
|[CBitmap::SetBitmapDimension](../Topic/CBitmap::SetBitmapDimension.md)|Atribui uma largura e altura em um bitmap em unidades de 0,1 mm.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmap::operator HBITMAP](../Topic/CBitmap::operator%20HBITMAP.md)|Retorna o identificador do windows anexada ao objeto de `CBitmap` .|  
  
## Comentários  
 Para usar um objeto de `CBitmap` , construir o objeto, anexar\-lhe uma alça de bitmap com uma das funções de membro de inicialização, e chame nas funções de membro objeto.  
  
 Para obter mais informações sobre como usar objetos gráficos de `CBitmap`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CBitmap`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Exemplo de documentos múltiplos MFC](../../top/visual-cpp-samples.md)   
 [Classe de CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
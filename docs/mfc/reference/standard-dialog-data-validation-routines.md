---
title: "Rotinas de valida&#231;&#227;o dos dados da caixa de di&#225;logo padr&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "caixa de diálogo padrão, rotinas de validação de dados"
ms.assetid: 44dbc222-a897-4949-925e-7660e8964ccd
caps.latest.revision: 13
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Rotinas de valida&#231;&#227;o dos dados da caixa de di&#225;logo padr&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico lista as rotinas padrão de \(DDV\) de validação de dados na caixa de diálogo usadas para controles comuns da caixa de diálogo MFC.  
  
> [!NOTE]
>  As rotinas de troca de dados da caixa de diálogo padrão são definidas no arquivo de cabeçalho. afxdd\_.h.  No entanto, os aplicativos devem incluir afxwin.h.  
  
### Funções DDV  
  
|||  
|-|-|  
|[DDV\_MaxChars](../Topic/DDV_MaxChars.md)|Verifica o número de caracteres em um valor fornecido de controle não excede o máximo especificado.|  
|[DDV\_MinMaxByte](../Topic/DDV_MinMaxByte.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **BYTE** .|  
|[DDV\_MinMaxDateTime](../Topic/DDV_MinMaxDateTime.md)|Verifica um valor fornecido de controle não excede um intervalo de tempo determinado.|  
|[DDV\_MinMaxDouble](../Topic/DDV_MinMaxDouble.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **double** .|  
|[DDV\_MinMaxDWord](../Topic/DDV_MinMaxDWord.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **DWORD** .|  
|[DDV\_MinMaxFloat](../Topic/DDV_MinMaxFloat.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **float** .|  
|[DDV\_MinMaxInt](../Topic/DDV_MinMaxInt.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **int** .|  
|[DDV\_MinMaxLong](../Topic/DDV_MinMaxLong.md)|Verifica um valor fornecido de controle não exceder um intervalo **long** determinado.|  
|[DDV\_MinMaxLongLong](../Topic/DDV_MinMaxLongLong.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **LONGLONG** .|  
|[DDV\_MinMaxMonth](../Topic/DDV_MinMaxMonth.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de data.|  
|[DDV\_MinMaxShort](../Topic/DDV_MinMaxShort.md)|Verifica um valor atribuído de controle não exceda um intervalo **short** determinado.|  
|[DDV\_MinMaxSlider](../Topic/DDV_MinMaxSlider.md)|Verifica um valor atribuído de controle deslizante está dentro do intervalo especificado.|  
|[DDV\_MinMaxUInt](../Topic/DDV_MinMaxUInt.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **UINT** .|  
|[DDV\_MinMaxULongLong](../Topic/DDV_MinMaxULongLong.md)|Verifica um valor atribuído de controle não exceda um determinado intervalo de **ULONGLONG** .|  
  
## Consulte também  
 [Rotinas de troca de dados da caixa de diálogo padrão](../Topic/Standard%20Dialog%20Data%20Exchange%20Routines.md)   
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
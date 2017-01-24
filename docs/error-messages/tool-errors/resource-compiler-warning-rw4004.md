---
title: "Aviso RW4004 (compilador de recurso) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "RW4004"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RW4004"
ms.assetid: 596b6a89-9ce7-4ba7-bdcb-e8054c7efafa
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso RW4004 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Caractere ASCII não equivalente ao código chave virtual  
  
 Um literal de cadeia de caracteres foi usada para o código chave virtual em um acelerador do tipo de VIRTKEY.  
  
 Esse aviso que permite continuar, mas lembre\-se de que as teclas de aceleração geradas podem não corresponder a cadeia de caracteres que você indicou. \(Códigos chaves diferentes de uso de VIRTKEYs do que aceleradores ASCII.\)  
  
 Quando as cadeias literais são sintaticamente válidas, você só pode garantir que terá um acelerador que você deseja usando os valores de **VK\_\* \#define** em WINDOWS.h.
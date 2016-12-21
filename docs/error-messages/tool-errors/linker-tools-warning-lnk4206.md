---
title: "Aviso LNK4206 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4206"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4206"
ms.assetid: 6c108e33-00cf-4c5a-830d-d65d470930a7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4206 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

pré\-compilado informações de tipo não encontrada; “nome de arquivo” não vinculado ou não substituído; vinculando o objeto como se nenhuma informação de depuração  
  
 O arquivo de objeto fornecido, compilado com [\/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando de LINK ou foi substituído.  
  
 Um cenário comum para esse aviso é quando o .obj que foi criado com \/Yc está em uma biblioteca, e onde há nenhum símbolo faz referência a .obj de seu código.  Nesse caso, o vinculador não usará \(consulte\) ou até mesmo para o arquivo de .obj.  Nessa situação, deverá recompilar seu código e usar [\/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) para os objetos restantes \(os objetos que não são compilados com \/Yc\).
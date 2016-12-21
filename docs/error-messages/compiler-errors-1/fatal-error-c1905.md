---
title: "Erro fatal C1905 | Microsoft Docs"
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
  - "C1905"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1905"
ms.assetid: fefc6769-477f-45a2-9878-6f0a5f42472c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1905
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Front\-end e back\-end não compatíveis \(devem usar o mesmo processador\)  
  
 Este erro ocorre quando um arquivo .obj é gerado por um front\-end do compilador \(C1.dll\) que tem como alvo um processador, como x86, ARM ou [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], mas é lido por um back\-end \(C2.dll\) que é destinado a um processador diferente.  
  
 Para corrigir esse problema, certifique\-se de que você está usando um front\-end e um back\-end correspondentes.  Esse é o padrão para projetos criados no Visual Studio.  Este erro pode ocorrer se você editou o arquivo de projeto e usou caminhos diferentes para as ferramentas do compilador.  Se você não tiver definido o caminho para as ferramentas do compilador especificamente, este erro pode ocorrer se a instalação do Visual Studio estiver corrompida.  Por exemplo, talvez você tenha copiado os arquivos .dll do compilador de um local para outro.  Use **Programas e Recursos** no Painel de Controle do Windows para reparar ou reinstalar o Visual Studio.
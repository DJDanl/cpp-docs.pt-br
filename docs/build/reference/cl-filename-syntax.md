---
title: "Sintaxe do nome de arquivo CL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "cl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, sintaxe de nome de arquivo"
  - "extensões, especificando para compilador"
  - "nomes de arquivos [C++]"
  - "nomes de arquivos [C++], compilador CL"
  - "caminhos, sintaxe de nome de arquivo de compilador CL"
  - "sintaxe, nome de arquivo de compilador"
ms.assetid: 3ca72586-75be-4477-b323-a1be232e80d4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sintaxe do nome de arquivo CL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

CL aceita arquivos com nomes que sigam as convenções de nomenclatura FAT, HPFS ou NTFS.  Qualquer nome de arquivo pode incluir um caminho completo ou parcial.  Um caminho completo inclui um nome de unidade e um ou mais nomes de diretório.  CL aceita nomes de arquivos separados por barras invertidas \(\\\) ou barras \(\/\).  Nomes de arquivos que contêm espaços devem ser colocados entre aspas duplas.  Um caminho parcial omite o nome da unidade, o qual é assumido por CL como a unidade atual.  Se você não especificar um caminho, o CL pressupõe que o arquivo está no diretório atual.  
  
 A extensão de nome de arquivo determina como os arquivos serão processados.  Os arquivos C e C\+\+, que têm a extensão. c, .cxx ou .cpp, são compilados.  Outros arquivos, incluindo arquivos .obj, bibliotecas \(.lib\) e arquivos de definição de módulo \(.def\) são passados para o vinculador sem terem sido processados.  
  
## Consulte também  
 [Sintaxe da linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)
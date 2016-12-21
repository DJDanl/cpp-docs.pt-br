---
title: "Erro RC2144 (compilador de recurso) | Microsoft Docs"
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
  - "RC2144"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC2144"
ms.assetid: 1b3ff39a-92cd-4a04-b1a3-b1fa6a805813
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro RC2144 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

ID DE IDIOMA PRIMÁRIO não é um número  
  
 A ID DE IDIOMA PRIMÁRIO deve ser uma ID de idioma hexadecimal.  Consulte [Idioma e Cadeias de Caracteres de País\/Região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md) em *Referência de Biblioteca de Tempo de Execução* para obter uma lista de IDs de Idioma válida.  
  
 Esse erro também pode ocorrer se os recursos forem adicionados e excluídos do arquivo .RC usando uma ferramenta.  Para corrigir esse problema, abra o arquivo .RC em um editor de texto e limpe quaisquer recursos não usados manualmente.
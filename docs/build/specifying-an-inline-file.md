---
title: "Especificando um arquivo embutido | Microsoft Docs"
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
  - "Arquivos  [C++], embutidas"
  - "arquivos embutidos [C++], especificando NMAKE"
  - "programa NMAKE, arquivos embutidos"
ms.assetid: 393eccfb-3fc9-4bac-a30c-8ac8d221cca3
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especificando um arquivo embutido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especificar dois colchetes angulares \(\<\<\) no comando onde *o nome de arquivo* é exibida.  Os colchetes angulares não pode ser uma macro expansão.  
  
## Sintaxe  
  
```  
<<[filename]  
```  
  
## Comentários  
 Quando o comando é executado, os colchetes angulares são substituídos *por nome de arquivo*, se especificados, ou por um nome NMAKE\- exclusivo gerado.  Se especificado, *o nome do arquivo* deve seguir os colchetes angulares sem espaço ou uma guia.  Um caminho é permitido.  Nenhuma extensão é necessária ou assumida.  Se *o nome de arquivo* é especificado, o arquivo é criado no escopo atual ou no diretório especificado, substituindo qualquer arquivo existente por esse nome; caso contrário, é criado no diretório de TMP \(ou no diretório atual, se a variável de ambiente de TMP não é definido\).  Se *um nome de arquivo* anterior for reutilizado, NMAKE substitui o arquivo anterior.  
  
## Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)
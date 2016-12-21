---
title: "implementation_only | Microsoft Docs"
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
  - "implementation_only"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Atributo implementation_only"
ms.assetid: d8cabc86-4425-45a0-9587-d57536980088
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# implementation_only
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Suprime geração do arquivo de cabeçalho .tlh \(o arquivo de cabeçalho primário\).  
  
## Sintaxe  
  
```  
implementation_only  
```  
  
## Comentários  
 Esse arquivo contém todas as declarações usadas para expor o conteúdo da biblioteca de tipos.  O arquivo de cabeçalho .tli, com as implementações de funções membro de wrapper, será gerado e incluído na compilação.  
  
 Quando esse atributo é especificado, o conteúdo do cabeçalho .tli está no mesmo namespace do geralmente usado no cabeçalho .tlh.  Além disso, as funções membro não são declaradas como embutidas.  
  
 O uso do atributo `implementation_only` é pretendido para o atributo [no\_implementation](../preprocessor/no-implementation.md), como uma maneira de manter as implementações fora do arquivo de cabeçalho pré\-compilado \(PCH\).  Uma instrução `#import` com o atributo `no_implementation` é colocada na região de origem usada para criar o PCH.  O PCH resultante é usado por diversos arquivos de origem.  Uma instrução `#import` com o atributo de `implementation_only` é então usada fora da região de PCH.  É necessário usar essa instrução somente uma vez em um dos arquivos de origem.  Isso gerará todas as funções membro de wrapper necessárias, sem recompilação adicional para cada arquivo de origem.  
  
> [!NOTE]
>  O atributo `implementation_only` em uma instrução `#import` deve ser usado junto à outra instrução `#import`, da mesma biblioteca de tipo, com o atributo `no_implementation`.  Caso contrário, serão gerados erros do compilador.  Isso ocorre porque as definições da classe wrapper, geradas pela instrução `#import` com o atributo `no_implementation`, são necessárias para compilar as implementações geradas pelo atributo `implementation_only`.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)
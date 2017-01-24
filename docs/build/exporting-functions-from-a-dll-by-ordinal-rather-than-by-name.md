---
title: "Exportando fun&#231;&#245;es a partir de uma DLL por ordinal e n&#227;o por nome | Microsoft Docs"
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
  - "NONAME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "exportando DLLs [C++], valores ordinais"
  - "exportando funções [C++], valores ordinais"
  - "Atributo NONAME"
  - "exportações ordinais [C++]"
ms.assetid: 679719fd-d965-4df3-9f7a-7d86ad831702
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando fun&#231;&#245;es a partir de uma DLL por ordinal e n&#227;o por nome
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira mais simples de exportar funções do DLL é executar sua exportação por nome.  Este é o que acontece quando você usa **\_\_declspec\(dllexport\)**, por exemplo.  Mas você pode exportar em vez de funções por ordinal.  Com essa técnica, você deve usar um arquivo .def em vez de **\_\_declspec\(dllexport\)**.  Para especificar o valor ordinal de uma função, acrescente o ordinal do nome da função no arquivo .def.  Para obter informações sobre como especificar ordinais, consulte [Exportar de uma DLL usando arquivos de .def](../build/exporting-from-a-dll-using-def-files.md).  
  
> [!TIP]
>  Se você deseja otimizar o tamanho do arquivo de DLL, use o atributo de **NONAME** em cada função exportada.  Com o atributo de **NONAME** , os ordinais são armazenados na tabela de exportação da DLL em vez dos nomes de função.  Isso pode ser algum aumento se você estiver exportando muitas funções.  
  
## O que você deseja fazer?  
  
-   [Use um arquivo .def assim que eu consigo exportar por ordinal](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Use o \_\_declspec \(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)
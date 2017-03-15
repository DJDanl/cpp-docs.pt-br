---
title: "Importando e exportando | Microsoft Docs"
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
  - "Palavra-chave __declspec(dllimport) [C++]"
  - "DLLs [C++], exportando a partir de"
  - "DLLs [C++], importando"
  - "exportando DLLs [C++]"
  - "importando DLLs [C++]"
ms.assetid: 7c44c2aa-2117-4cec-9615-a65bfd3f8f7b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Importando e exportando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode importar símbolos públicos em um aplicativo ou exportar funções de uma DLL usando dois métodos:  
  
-   Use um arquivo de definição de módulo \(.def\) durante a criação do DLL  
  
-   Use as palavras\-chave **\_\_declspec\(dllimport\)** ou **\_\_declspec\(dllexport\)** em uma definição de função no aplicativo principal  
  
## Usando um arquivo .def  
 Arquivo de definição de módulo \(.def\) é um arquivo de texto que contém uma ou mais instruções de módulo que descrevem vários atributos de uma DLL.  Se você não usar **\_\_declspec\(dllimport\)** ou **\_\_declspec\(dllexport\)** para exportar as funções de uma DLL, a DLL requer um arquivo .def.  
  
 Você pode usar arquivos .def da [importação em um aplicativo](../build/importing-using-def-files.md) ou a [exportação de uma DLL](../build/exporting-from-a-dll-using-def-files.md).  
  
## Usando \_\_declspec  
 Usa **\_\_declspec\(dllimport\)** e **\_\_declspec\(dllexport\)** do Visual C\+\+ substituir a palavra\-chave de **\_\_export** usado anteriormente em versões de 16 bits do Visual C\+\+.  
  
 Você não precisa usar **\_\_declspec\(dllimport\)** para seu código para criar corretamente, mas essa forma que o compilador gerencia o melhor código.  O compilador pode produzir a melhor código porque pode determinar se uma função existir em uma DLL ou não, que permite que o compilador gerencia o código que salta um nível de nomes indiretos que normalmente estão presentes em uma chamada de função que atravessa um limite da DLL.  Porém, você deve usar **\_\_declspec\(dllimport\)** para importar as variáveis usadas em uma DLL.  
  
 Com a seção EXPORTS adequada do arquivo .def, **\_\_declspec\(dllexport\)** não é necessário.  **\_\_declspec\(dllexport\)** foi adicionado para fornecer uma maneira fácil exportar funções de um arquivo ou arquivo .dll sem usar um arquivo .def.  
  
 O formato portátil executável Win32 é criado para minimizar o número de páginas que devem ser tocadas para corrigir importações.  Para fazer isso, coloque todos os endereços de importação para qualquer programa em um local chamada a tabela de endereço de importação.  Isso permite que o carregador modificar somente uma ou duas páginas ao acessar essas importações.  
  
## O que você deseja fazer?  
  
-   [Importação em um aplicativo](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Exportar de uma DLL](../build/exporting-from-a-dll.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)
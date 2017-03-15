---
title: "Importando para um aplicativo usando __declspec(dllimport) | Microsoft Docs"
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
  - "__declspec"
  - "dllimport"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec(dllimport) [C++]"
  - "importando DLLs [C++], __declspec(dllimport)"
ms.assetid: edb4da4e-f83a-44cf-a668-9239d49dbe42
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Importando para um aplicativo usando __declspec(dllimport)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um programa que usa símbolos públicos definidos por uma DLL é considerado como e.  Quando você cria arquivos de cabeçalho dos aplicativos que usa seus dlls para criar o, use **\_\_declspec\(dllimport\)** em declarações de símbolos públicos.  A palavra\-chave **\_\_declspec\(dllimport\)** funcionará se você exportar com arquivos de .def ou com a palavra\-chave de **\_\_declspec\(dllexport\)** .  
  
 Para fazer seu código mais legível, defina uma macro para **\_\_declspec\(dllimport\)** e então use a macro para declarar cada símbolo importado:  
  
```  
#define DllImport   __declspec( dllimport )  
  
DllImport int  j;  
DllImport void func();  
```  
  
 Usar **\_\_declspec\(dllimport\)** é opcional em declarações de função, mas o compilador gerencia um código mais eficiente se você usar essa palavra\-chave.  Porém, você deve usar **\_\_declspec\(dllimport\)** para que o executável importando acesse os símbolos e os objetos de dados públicos da DLL.  Observe que os usuários do DLL ainda precisam vincular a uma biblioteca de importação.  
  
 Você pode usar o mesmo arquivo de cabeçalho para a DLL e o aplicativo cliente.  Para fazer isso, use um símbolo de pré\-processador especial que indica se você estiver criando o DLL ou está criando o aplicativo cliente.  Por exemplo:  
  
```  
#ifdef _EXPORTING  
   #define CLASS_DECLSPEC    __declspec(dllexport)  
#else  
   #define CLASS_DECLSPEC    __declspec(dllimport)  
#endif  
  
class CLASS_DECLSPEC CExampleA : public CObject  
{ ... class definition ... };  
```  
  
## O que você deseja fazer?  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [Importando e exportando funções embutidas](../Topic/Importing%20and%20Exporting%20Inline%20Functions.md)  
  
-   [Importações Mútuas](../Topic/Mutual%20Imports.md)  
  
## Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)
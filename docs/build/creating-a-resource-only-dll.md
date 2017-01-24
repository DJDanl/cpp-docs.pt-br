---
title: "Criando uma DLL somente de recurso | Microsoft Docs"
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
  - "DLLs [C++], criando"
  - "DLLs somente de recursos [C++], criando"
ms.assetid: e6b1d4da-7275-467f-a58c-a0a8a5835199
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Criando uma DLL somente de recurso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma DLL de recurso somente é uma DLL que não contém nenhum mas recursos, como ícones, bitmaps, cadeias de caracteres, e caixas de diálogo.  Usar uma DLL de recurso somente é uma boa maneira de compartilhar o mesmo conjunto de recursos entre vários programas.  Também é uma boa maneira de fornecer um aplicativo com os recursos encontrados em vários idiomas [Recursos encontrados em aplicativos de MFC: DLL satélite](../build/localized-resources-in-mfc-applications-satellite-dlls.md)\(consulte\).  
  
 Para criar uma DLL de recurso somente leitura, você cria um novo projeto da DLL do Win32 \(não MFC\) e adiciona seus recursos ao projeto.  
  
-   O projeto selecionado do Win32 na caixa de diálogo de **Novo Projeto** e especifica um tipo de projeto da DLL no assistente de projeto do Win32.  
  
-   Crie um novo script de recursos que contém os recursos \(como uma cadeia de caracteres ou um menu\) para a DLL e salve o arquivo de .rc.  
  
-   No menu de **Projeto** , clique **Adicionar Item Existente**, e insira o novo arquivo de .rc no projeto.  
  
-   Especifique a opção do vinculador de [\/NOENTRY](../build/reference/noentry-no-entry-point.md) . \/NOENTRY impede que o vinculador vincula uma referência ao \_main na DLL; essa opção é obrigatória para criar uma DLL de recurso somente.  
  
-   Criar a DLL.  
  
 O aplicativo que usa a DLL de recurso somente deve chamar **LoadLibrary** a [explicitamente link para a DLL](../build/loadlibrary-and-afxloadlibrary.md).  Para acessar os recursos, chame as funções **FindResource** genéricas e **LoadResource**, que trabalham em qualquer tipo de recursos, ou chame um das seguintes funções específicas de recurso:  
  
-   `FormatMessage`  
  
-   **LoadAccelerators**  
  
-   `LoadBitmap`  
  
-   `LoadCursor`  
  
-   `LoadIcon`  
  
-   `LoadMenu`  
  
-   `LoadString`  
  
 O aplicativo deve chamar **FreeLibrary** quando terminar de usar os recursos do.  
  
## Que você deseja saber mais?  
  
-   [DELETE\_PENDING\_Editing Resources](http://msdn.microsoft.com/pt-br/c29d31c7-2d94-40ca-8aa0-c7262883529c)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)
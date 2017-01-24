---
title: "/ENTRY (s&#237;mbolo do ponto de entrada) | Microsoft Docs"
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
  - "/entry"
  - "VC.Project.VCLinkerTool.EntryPointSymbol"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ENTRY"
  - "opção de vinculador ENTRY"
  - "opção de vinculador -ENTRY"
  - "endereço inicial"
ms.assetid: 26c62ba2-4f52-4882-a7bd-7046a0abf445
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ENTRY (s&#237;mbolo do ponto de entrada)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ENTRY:function  
```  
  
## Comentários  
 onde:  
  
 *função*  
 Uma função que especifica um endereço inicial definido pelo usuário para um arquivo .exe ou uma DLL.  
  
## Comentários  
 A opção \/ENTRY especifica uma função do ponto de entrada como o endereço inicial de um arquivo .exe ou uma DLL.  
  
 A função deve ser definida com `__stdcall` que chama a convenção.  Os parâmetros e o valor de retorno dependerá se o programa é um aplicativo de console, um aplicativo do windows ou um DLL.  É recomendado que você deixar o vinculador definir o ponto de entrada de modo que a biblioteca de tempo de execução C é inicializada corretamente, os construtores e do C\+\+ para objetos estáticos são executados.  
  
 Por padrão, o endereço inicial for um nome de função de biblioteca de tempo de execução C.  Selecione o vinculador de acordo com os atributos do programa, como mostra a tabela a seguir.  
  
|Nome da função|Opção para|  
|--------------------|----------------|  
|**mainCRTStartup** \(ou **wmainCRTStartup**\)|Um aplicativo usando \/SUBSYSTEM:**CONSOLE**; chamadas **main** \(ou **wmain**\)|  
|**WinMainCRTStartup** \(ou **wWinMainCRTStartup**\)|Um aplicativo usando \/SUBSYSTEM:**JANELAS**; chamadas `WinMain` \(ou **wWinMain**\), que devem ser definidos com `__stdcall`|  
|**\_DllMainCRTStartup**|UMA DLL; chama `DllMain`, que devem ser definidos com `__stdcall`, caso existam|  
  
 Se a opção de [\/DLL](../../build/reference/dll-build-a-dll.md) ou de [\/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) não for especificada, o vinculador selecionar um ponto do subsistema de entrada e dependendo se **main** ou `WinMain` estão definidos.  
  
 As funções **main**, `WinMain`, e `DllMain` são os três formulários de ponto de entrada definido pelo usuário.  
  
 Ao criar uma imagem gerenciado, a função especificada com \/ENTRY deve ter uma assinatura de LPVOID \( *var1*, DWORD *var2*, LPVOID *var3*\).  
  
 Para obter informações sobre como definir seu próprio ponto de entrada de DllMain, consulte [Comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) .  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Avançado** .  
  
4.  Modifique a propriedade de **Ponto de entrada** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EntryPointSymbol%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)
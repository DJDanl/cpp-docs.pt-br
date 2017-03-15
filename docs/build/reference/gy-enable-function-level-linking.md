---
title: "/Gy (habilitar vincula&#231;&#227;o do n&#237;vel de fun&#231;&#227;o) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.EnableFunctionLevelLinking"
  - "/gy"
  - "VC.Project.VCCLWCECompilerTool.EnableFunctionLevelLinking"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Gy (C++)"
  - "Função COMDAT"
  - "habilitar Opção de compilador de vinculação no nível da função [C++]"
  - "Opção de compilador Gy [C++]"
  - "Opção de compilador -Gy [C++]"
  - "funções empacotadas"
ms.assetid: 0d3cf14c-ed7d-4ad3-b4b6-104e56f61046
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Gy (habilitar vincula&#231;&#227;o do n&#237;vel de fun&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que o compilador empacote funções individuais na forma de funções empacotadas \(COMDATs\).  
  
## Sintaxe  
  
```  
/Gy[-]  
```  
  
## Comentários  
 O vinculador requer que as funções são empacotadas separadamente como COMDATs para excluir ou ordenar funções individuais em uma DLL ou no arquivo .exe.  
  
 Você pode usar a opção [\/OPT \(Otimizações\)](../../build/reference/opt-optimizations.md) do vinculador excluir funções empacotadas não referenciada do arquivo .exe.  
  
 Você pode usar a opção [\/ORDER \(colocar funções na ordem\)](../../build/reference/order-put-functions-in-order.md) do vinculador incluir funções empacotados na ordem especificada no arquivo .exe.  
  
 As funções embutidas são empacotadas sempre se são criadas uma instância do como chamadas \(que ocorre, por exemplo, se inlining está ou você faça um endereço de função\).  Além disso, as funções de membro C\+\+ definidas na declaração de classe são empacotadas automaticamente; outras funções não são, e selecione esta opção é necessário empacotadas como funções. construa  
  
> [!NOTE]
>  A opção de [\/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) , usada para a edição e continuar, define automaticamente a opção de **\/Gy** .  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Geração de Código** .  
  
4.  Modifique a propriedade de **Habilita Vinculação a Nível de Função** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFunctionLevelLinking%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
---
title: "/Zl (omitir nome da biblioteca padr&#227;o) | Microsoft Docs"
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
  - "/zi"
  - "VC.Project.VCCLCompilerTool.OmitDefaultLibName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Zl (C++)"
  - "bibliotecas padrão, omitindo nomes"
  - "Opção de compilador Omitir Nome de Biblioteca Padrão"
  - "Opção de compilador ZI"
  - "Opção de compilador -Zl [C++]"
ms.assetid: b27d39d0-44d6-498c-84ae-27c1326fee59
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zl (omitir nome da biblioteca padr&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Omite o nome da biblioteca padrão de tempo de execução C do arquivo de .obj.  Por padrão, o compilador coloca o nome da biblioteca no arquivo de .obj para direcionar o vinculador a biblioteca correta.  
  
## Sintaxe  
  
```  
/Zl  
```  
  
## Comentários  
 Para obter mais informações sobre a biblioteca padrão, consulte [Use a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
 Você pode usar **\/Zl** para criar arquivos de .obj você planeja colocar em uma biblioteca.  Embora omitindo o nome da biblioteca salva apenas uma pequena quantidade de espaço para um único arquivo de .obj, o espaço total salvo for significativo em uma biblioteca que contém muitos módulos do objeto.  
  
 Essa opção é uma opção avançada.  Definindo essa opção remove determinado suporte à biblioteca de tempo de execução C que pode ser necessário para seu aplicativo, resultando em erros de link\- hora se seu aplicativo dependem desse suporte.  Se você usar esta opção é necessário fornecer os componentes necessários em alguma outra forma.  
  
 Use [\/NODEFAULTLIB \(ignorar bibliotecas\)](../../build/reference/nodefaultlib-ignore-libraries.md). para direcionar o vinculador para ignorar referências de biblioteca em todos os arquivos de .obj.  
  
 Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 Ao criar com **\/Zl**, `_VC_NODEFAULTLIB` é definido.  Por exemplo:  
  
```  
// vc_nodefaultlib.cpp  
// compile with: /Zl  
void Test() {  
   #ifdef _VC_NODEFAULTLIB  
      int i;  
   #endif  
  
   int i;   // C2086  
}  
```  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Avançado** .  
  
4.  Modifique a propriedade de **Omitir Nomes de Biblioteca Padrão** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitDefaultLibName%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
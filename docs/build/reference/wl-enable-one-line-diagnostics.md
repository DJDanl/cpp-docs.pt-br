---
title: "/WL (habilitar diagn&#243;stico de uma linha) | Microsoft Docs"
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
  - "/wl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /WL (C++)"
  - "Opção de compilador WL [C++]"
  - "Opção de compilador -WL [C++]"
ms.assetid: 332cadb4-8ea6-45fe-b67d-33ddec1f2c2e
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /WL (habilitar diagn&#243;stico de uma linha)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Acrescenta informações adicionais a um erro ou uma mensagem de aviso.  
  
## Sintaxe  
  
```  
/WL  
```  
  
## Comentários  
 O erro e mensagens de aviso do compilador C\+\+ podem ser seguido pela informações adicionais que aparece, por padrão, em uma nova linha.  Quando você compila de linha de comando, a linha adicional de informações podem ser acrescentada ao erro ou a mensagem de aviso.  Isso pode ser desejável se você captura a saída de compilação para um arquivo de log e processará o log para localizar todos os erros e avisos.  Um ponto\-e\-vírgula separará o erro ou a mensagem de aviso de linha adicional.  
  
 Não qualquer erro e mensagens de aviso têm uma linha adicional de informações.  O código a seguir gerará um erro que tem uma linha adicional de informações; permitirá testar o efeito quando você usa **\/WL**.  
  
```  
// compiler_option_WL.cpp  
// compile with: /WL  
#include <queue>  
int main() {  
   std::queue<int> q;  
   q.fromthecontinuum();   // C2039  
}  
```  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
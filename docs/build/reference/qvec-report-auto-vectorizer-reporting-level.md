---
title: "/Qvec-report (n&#237;vel de relat&#243;rios do vetorizador autom&#225;tico) | Microsoft Docs"
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
ms.assetid: 4778c9a3-0692-4085-9b05-1bfeadf4c74a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Qvec-report (n&#237;vel de relat&#243;rios do vetorizador autom&#225;tico)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita o recurso relatório do compilador [Automático \- Vectorizer](../../parallel/auto-parallelization-and-auto-vectorization.md) e especifica o nível das mensagens informativas para saída durante a compilação.  
  
## Sintaxe  
  
```  
/Qvec-report:{1}{2}  
```  
  
## Comentários  
 **\/Qvec\-report:1**  
 Gera uma mensagem informativa para o loop que são vectorized.  
  
 **\/Qvec\-report:2**  
 Gera uma mensagem informativa para o loop que são vectorized e para o loop que não são vectorized, junto com um código do motivo.  
  
 Para obter informações sobre códigos e de mensagens do motivo, consulte [Mensagens do vetorizador e do paralelizador](../../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
### Para definir a opção do compilador do \/Qvec\-report no Visual Studio  
  
1.  Em **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**.  
  
2.  Na caixa de diálogo de **Páginas de Propriedades** , em **C\/C\+\+**, **Linha de Comando**selecione.  
  
3.  Na caixa de **Opções Adicionais** , entre em `/Qvec-report: 1` ou em `/Qvec-report: 2`.  
  
### Para definir programaticamente a opção de compilador do \/Qvec\-report  
  
-   Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/Q Opções \(operações de nível baixo\)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Programação paralelo em código nativo](http://go.microsoft.com/fwlink/?LinkId=263662)
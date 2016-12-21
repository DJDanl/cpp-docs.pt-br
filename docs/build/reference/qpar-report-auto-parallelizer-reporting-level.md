---
title: "/Qpar-report (n&#237;vel de relat&#243;rios do paralelizador autom&#225;tico) | Microsoft Docs"
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
ms.assetid: 562673b9-02da-4bf8-bb64-70bc25ef4651
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Qpar-report (n&#237;vel de relat&#243;rios do paralelizador autom&#225;tico)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que o recurso de relatório do compilador [Paralelizador Automático](../../parallel/auto-parallelization-and-auto-vectorization.md) e especifica o nível de mensagens de informação para a saída durante a compilação.  
  
## Sintaxe  
  
```  
/Qpar-report:{1}{2}  
```  
  
## Comentários  
 **\/Qpar\-report:1**  
 Gera uma mensagem informativa para loops que são colocados em paralelo.  
  
 **\/Qpar\-report:2**  
 Gera uma mensagem informativa para loops que são colocados em paralelo e também para loops que não são colocados em paralelo, juntamente com um código de motivo.  
  
 As mensagens são relatadas para stdout.  Se nenhuma mensagem informativa for relatada, o código não contém nenhum loops ou o nível de relatório não foi definido para loops de relatório que não são colocados em paralelo.  Para obter mais informações sobre códigos de motivo e mensagens, consulte [Mensagens do vetorizador e do paralelizador](../../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
### Para definir a opção de compilador \/Qpar\-report no Visual Studio  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho do projeto e selecione **Propriedades**.  
  
2.  Na caixa de diálogo **Páginas de Propriedades**, em **C\/C\+\+**, selecione **Linha de Comando**.  
  
3.  Na caixa **Opções Adicionais**, digite `/Qpar-report:1` ou `/Qpar-report:2`.  
  
### Para definir a opção do compilador \/Qpar\-report programaticamente  
  
-   Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/Q Opções \(operações de nível baixo\)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Programação de Paralelo no Código Nativo](http://go.microsoft.com/fwlink/?LinkId=263662)
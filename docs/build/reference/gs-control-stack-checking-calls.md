---
title: "/Gs (controlar chamadas de verifica&#231;&#227;o da pilha) | Microsoft Docs"
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
  - "/GS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /GS (C++)"
  - "desabilitando sondas de pilha"
  - "Opção de compilador GS [C++]"
  - "Opção de compilador -GS [C++]"
  - "chamadas de verificação de pilha"
  - "sondas de pilha"
  - "stack, sondas de pilha"
ms.assetid: 40daed7c-f942-4085-b872-01e12b37729e
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Gs (controlar chamadas de verifica&#231;&#227;o da pilha)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Controla investigações de pilha.  
  
## Sintaxe  
  
```  
/Gs[size]  
```  
  
## Argumentos  
 `size`  
 \(Opcional\) O número de bytes que as variáveis locais podem ocupar antes que uma sonda de pilha seja iniciada.  Se a opção **\/Gs** for especificada sem um argumento `size`, é o mesmo que especificar **\/Gs0**,  
  
## Comentários  
 Uma sonda de pilha é uma sequência de códigos que o compilador insere em cada chamada de função.  Quando iniciada, uma sonda de pilha atinge de maneira favorável a memória pela quantidade de espaço necessária para armazenar as variáveis locais da função.  
  
 Se uma função exigir mais que `size` bytes de espaço de pilha para variáveis locais, sua sonda de pilha é iniciada.  Por padrão, o compilador gera o código que inicia uma sonda de pilha quando uma função exige mais de uma página de espaço de pilha.  Isso equivale a uma opção do compilador de **\/Gs4096** para x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], e plataformas de ARM.  Esse valor permite que um aplicativo e o gerenciador de memória do Windows aumentem a quantidade de memória confirmada dinamicamente para a pilha do programa no tempo de execução.  
  
> [!NOTE]
>  O valor padrão de **\/Gs4096** permite que a pilha de aplicativos do programa para Windows aumente corretamente no tempo de execução.  Recomendamos que o valor padrão não seja alterado a menos que você saiba exatamente por que deve alterá\-lo.  
  
 Alguns programas, por exemplo, drivers de dispositivo virtual, não requerem esse mecanismo de aumento de pilha padrão.  Nesses casos, as sondas de pilha não são necessárias e você pode fazer com que o compilador deixe de gerá\-las configurando `size` para um valor maior que aquilo que qualquer função exigirá para o armazenamento local da variável.  Não é permitido espaço entre **\/Gs** e `size`.  
  
 **\/Gs0** ativa sondas de pilha para cada chamada de função que requer armazenamento para variáveis locais.  Isso pode causar um impacto negativo no desempenho.  
  
 É possível ativar ou desativar as sondas de pilha usando [check\_stack](../../preprocessor/check-stack.md).  **\/Gs** e o pragma `check_stack` não tem efeito sobre as rotinas da biblioteca padrão C; eles afetam somente as funções compiladas.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
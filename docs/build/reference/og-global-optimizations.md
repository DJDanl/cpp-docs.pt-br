---
title: "-Og (otimiza&#231;&#245;es globais) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.GlobalOptimizations"
  - "/og"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador -Og [C++]"
  - "Opção de compilador otimizações globais [C++]"
  - "alocação de registro automática"
  - "Opção de compilador /Og (C++)"
  - "estruturas de loop, otimização"
  - "eliminação de subexpressão comum"
  - "Opção de compilador Og [C++]"
ms.assetid: d10630cc-b9cf-4e97-bde3-8d7ee79e9435
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Og (otimiza&#231;&#245;es globais)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preterido. Fornece otimizações de locais e globais, o registro automático alocação e otimização de loop.  
  
## Sintaxe  
  
```  
/Og  
```  
  
## Comentários  
 **\/Og** foi preterido. Geralmente, essas otimizações agora são habilitadas por padrão. Para obter mais informações sobre otimizações, consulte [\/O1, \/O2 \(minimizar tamanho, maximizar velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou [\/Ox \(otimização total\)](../../build/reference/ox-full-optimization.md).  
  
 As seguintes otimizações estão disponíveis em **\/Og**:  
  
-   Eliminação de subexpressão comum locais e globais  
  
     Dessa otimização, o valor de uma subexpressão comum é calculado uma vez. No exemplo a seguir, se os valores de `b` e `c` não alterar entre as três expressões, o compilador pode atribuir o cálculo de `b + c` a uma variável temporária e substitua a variável `b + c`:  
  
    ```  
    a = b + c;  
    d = b + c;  
    e = b + c;  
    ```  
  
     Para otimizar a subexpressão comum local, o compilador examina curtas seções de código para subexpressões comuns. Para otimizar a subexpressão comum global, o compilador pesquisa funções inteiras para subexpressões comuns.  
  
-   Alocação de registro automático  
  
     Essa otimização permite que o compilador repositório usado variáveis e subexpressões em registros; o `register` palavra\-chave é ignorado.  
  
-   Otimização de loop  
  
     Essa otimização remove subexpressões invariáveis do corpo de um loop. Um loop ideal contém somente as expressões cujos valores são alterados por meio de cada execução do loop. No exemplo a seguir, a expressão `x + y` não é alterado no corpo do loop:  
  
    ```  
    i = -100;  
    while( i < 0 ) {  
        i += x + y;  
    }  
    ```  
  
     Depois da otimização, `x + y` é calculada uma vez em vez de sempre que o loop é executado:  
  
    ```  
    i = -100;  
    t = x + y;  
    while( i < 0 ) {  
        i += t;  
    }  
    ```  
  
     Otimização de loop é muito mais eficaz quando o compilador não pode assumir nenhum alias, definido com [Restrict](../../cpp/extension-restrict.md), [noalias](../../cpp/noalias.md), ou [restringir](../../cpp/restrict.md).  
  
    > [!NOTE]
    >  Você pode habilitar ou desabilitar a otimização global em uma base por função de função usando o `optimize` pragma com o `g` opção.  
  
 **\/Og** também permite a otimização de valor de retorno de chamada, o que elimina o construtor de cópia e o destruidor de um valor de retorno de pilha com base. Consulte [\/O1, \/O2 \(minimizar tamanho, maximizar velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) para obter mais informações.  
  
 Para obter informações relacionadas, consulte [Gerar funções intrínsecas \(\/Oi\)](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md) e [otimização completa \(\/ Ox\)](../../build/reference/ox-full-optimization.md).  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique o **C\/C\+\+** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **Opções adicionais** caixa.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
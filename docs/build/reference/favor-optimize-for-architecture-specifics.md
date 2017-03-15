---
title: "/favor (Otimizar para especifica&#231;&#245;es da arquitetura) | Microsoft Docs"
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
  - "/favor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "-favor [C++] - Opção de compilador"
  - "/favor [C++] - Opção de compilador"
ms.assetid: ad264df2-e30f-4d68-8bd0-10d6bee71a2a
caps.latest.revision: 31
caps.handback.revision: 31
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /favor (Otimizar para especifica&#231;&#245;es da arquitetura)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**\/favor:** `option` gerencia o código que é otimizado para uma arquitetura específica ou das especificações de micro\- em arquiteturas AMD e as arquiteturas Intel.  
  
## Sintaxe  
  
```  
/favor:{blend | ATOM | AMD64 | INTEL64}  
```  
  
## Comentários  
 **\/favor:blend**  
 \(x86 e x64\) gerencia o código que é otimizado para as especificações de micro\- em arquiteturas AMD e as arquiteturas Intel.  Quando **\/favor:blend** não pode fornecer melhor desempenho possível em um processador específico, é criado para dar o melhor desempenho através de uma ampla gama de processadores de x86 e x64.  Por padrão, **\/favor:blend** é aplicado.  
  
 **\/favor:ATOM**  
 \(x86 e x64\) gerencia o código que é otimizado para específicos da tecnologia de processador do atom processador Intel e atom Intel Centrino.  Código que é gerado usando **\/favor:ATOM** também pode gerar instruções Intel SSSE3, de SSE3, de SSE2, e de SSE para processadores Intel.  
  
 **\/favor:AMD64**  
 \(somente\) x64 otimiza o código gerado para AMD Opteron, e os processadores de Athlon que oferecem extensões de 64 bits.  O código otimizado pode executar em todas as plataformas correspondentes em x64.  Código que é gerado usando **\/favor:AMD64** pode acelerar o desempenho pior em processadores Intel que oferecem suporte a Intel64.  
  
 **\/favor:INTEL64**  
 \(somente\) x64 otimiza o código gerado para os processadores Intel que oferecem suporte a Intel64, que gerencie normalmente melhor desempenho para a plataforma.  O código resultante pode ser executada em qualquer plataforma de x64.  Código que é gerado com **\/favor:INTEL64** pode acelerar o desempenho pior em AMD Opteron, e os processadores de Athlon que oferecem suporte para extensões de 64 bits.  
  
> [!NOTE]
>  A arquitetura Intel64 foi previamente conhecida como a tecnologia estendido de memória 64, e a opção correspondente do compilador foi **\/favor:EM64T**.  
  
 Para obter informações sobre como programar para a arquitetura de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] , consulte [Convenções de software x64](../../build/x64-software-conventions.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Insira a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
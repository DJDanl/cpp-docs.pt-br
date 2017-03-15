---
title: "/Gw (Otimizar dados globais) | Microsoft Docs"
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
  - "/Gw"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Gw [C++]"
  - "Opção de compilador -Gw [C++]"
ms.assetid: 6f90f4e9-5eb8-4c47-886e-631278a5a4a9
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Gw (Otimizar dados globais)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Pacotes dados globais em seções de COMDAT para otimização.  
  
## Sintaxe  
  
```  
/Gw[-]  
```  
  
## Comentários  
 A opção de **\/Gw** faz com que o compilador a dados globais do pacote nas seções individuais de COMDAT.  Por padrão, **\/Gw** é e deve ser explicitamente habilitado.  Para desabilitar explicitamente, use **\/Gw\-**.  Quando **\/Gw** e [\/GL](../../build/reference/gl-whole-program-optimization.md) estão habilitados, o vinculador usa otimização do total programa para comparar seções de COMDAT em vários arquivos de objeto para excluir dados globais não referenciados ou mesclar dados globais somente leitura idênticos.  Isso pode reduzir significativamente o tamanho do executável binário resultante.  
  
 Quando você compila e vincular separada, você pode usar a opção do vinculador de [\/OPT: Referência](../../build/reference/opt-optimizations.md) excluir do executável que os dados globais não referenciados em arquivos de objeto foi criada com a opção de **\/Gw** .  
  
 Você também pode usar [\/OPT: ICF](../../build/reference/opt-optimizations.md) e opções do vinculador de [\/LTCG](../../build/reference/ltcg-link-time-code-generation.md) mesclagem junto no executável que todos os dados globais somente leitura idênticos em vários arquivos de objeto foi criada com a opção de **\/Gw** .  
  
 Para [Apresentando a opção do compilador do \/Gw](http://blogs.msdn.com/b/vcblog/archive/2013/09/11/introducing-gw-compiler-switch.aspx) obter mais informações, consulte o blog da equipe do Visual C\+\+.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Modifique a propriedade **Opções Adicionais** para incluir **\/Gw** e então escolha **OK**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)
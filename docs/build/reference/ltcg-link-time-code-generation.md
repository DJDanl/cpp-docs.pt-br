---
title: "/LTCG (gera&#231;&#227;o de c&#243;digo do tempo de vincula&#231;&#227;o) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.LinkTimeCodeGeneration"
  - "VC.Project.VCConfiguration.WholeProgramOptimization"
  - "VC.Project.VCCLWCECompilerTool.WholeProgramOptimization"
  - "/ltcg"
  - "VC.Project.VCCLCompilerTool.WholeProgramOptimization"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /LTCG"
  - "geração de código para link-time no vinculador C++"
  - "opção de vinculador LTCG"
  - "opção de vinculador -LTCG"
ms.assetid: 788c6f52-fdb8-40c2-90af-4026ea2cf2e2
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /LTCG (gera&#231;&#227;o de c&#243;digo do tempo de vincula&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/LTCG[:INCREMENTAL|:NOSTATUS|:STATUS|:OFF|:PGINSTRUMENT|:PGOPTIMIZE|:PGUPDATE]  
```  
  
## Comentários  
 : INCREMENTAL \(opcional\)  
 Especifica que o vinculador aplica somente a todo o programa otimização ou tempo de link de geração de código \(\/ltcg\) para o conjunto de arquivos afetados por uma edição, em vez de todo o projeto. Por padrão, esse sinalizador não é definido quando\/\/ltcg for especificado e todo o projeto vinculado usando a otimização de programa total.  
  
 : NOSTATUS &#124;: STATUS \(opcional\)  
 Especifica se o vinculador exibe um indicador de progresso que mostra a porcentagem do link for concluída. Por padrão, essas informações de status não são exibidas.  
  
 : OFF \(opcional\)  
 desabilita a geração de código para link\-time. Esse comportamento é o mesmo que quando \/LTCG não for especificado na linha de comando.  
  
 : \(Opcional\) PGINSTRUMENT  
 essa opção é preterida. Em vez disso, use **\/LTCG** e  **\/GENPROFILE** ou **\/FASTGENPROFILE** para gerar uma compilação instrumentada para Otimização Guiada por perfil.  
  
 Os dados que são coletados de execuções instrumentadas são usados para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). a forma curta dessa opção é \/LTCG:PGI.  
  
 : \(Opcional\) PGOPTIMIZE  
 essa opção é preterida. Em vez disso, use **\/LTCG** e  **\/USEPROFILE** para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). a forma curta dessa opção é \/LTCG:PGO.  
  
 : \(Opcional\) PGUPDATE  
 essa opção é preterida. Em vez disso, use **\/LTCG** e  **\/USEPROFILE** para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). a forma curta dessa opção é \/LTCG:PGU.  
  
 a opção \/LTCG instrui o vinculador para chamar o compilador e executar a otimização de programa total. Você também pode fazer Otimização Guiada por perfil. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md).  
  
 With the following exceptions, you cannot add linker options to the PGO combination of \/LTCG and \/USEPROFILE that were not specified in the previous PGO initialization combination of  \/LTCG and \/GENPROFILE options:  
  
-   [\/BASE](../../build/reference/base-base-address.md)  
  
-   [\/FIXED](../../build/reference/fixed-fixed-base-address.md)  
  
-   \/LTCG  
  
-   [\/MAP](../../build/reference/map-generate-mapfile.md)  
  
-   [\/MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md)  
  
-   [\/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md)  
  
-   [\/OUT](../../build/reference/out-output-file-name.md)  
  
-   [\/PGD](../../build/reference/pgd-specify-database-for-profile-guided-optimizations.md)  
  
-   [\/PDB](../../build/reference/pdb-use-program-database.md)  
  
-   [\/PDBSTRIPPED](../../build/reference/pdbstripped-strip-private-symbols.md)  
  
-   [\/STUB](../../build/reference/stub-ms-dos-stub-file-name.md)  
  
-   [\/verbose](../../build/reference/verbose-print-progress-messages.md)  
  
 qualquer opção de vinculador especificada junto com as opções \/LTCG e \/GENPROFILE inicializar PGO não precisa ser especificado quando você cria usando \/LTCG e \/USEPROFILE; elas estão implícitas.  
  
 o restante deste tópico aborda \/LTCG em termos de geração de código para link\-time.  
  
 \/\/Ltcg está implícita com [\/GL](../../build/reference/gl-whole-program-optimization.md).  
  
 o vinculador invoca a geração de código para link\-time se ele for passado um módulo que foi compilado usando **\/GL** ou um módulo MSIL \(consulte [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md)\). Se você não especificar explicitamente **\/LTCG** quando você passa **\/GL** ou módulos MSIL para o vinculador, o vinculador eventualmente detecta isso e reinicia o link usando **\/LTCG**. Especificar explicitamente **\/LTCG** quando você passa **\/GL** e desempenho de compilação de módulos MSIL para o vinculador para o mais rápido possível.  
  
 Para desempenho mais rápido, use **\/LTCG:INCREMENTAL**. Essa opção informa o vinculador apenas otimizar novamente o conjunto de arquivos que é afetado por uma alteração de arquivo de origem, em vez de todo o projeto. Isso pode reduzir significativamente o tempo de link necessárias. Isso não é a mesma opção como vinculação incremental.  
  
 **\/LTCG** não é válido para uso com [\/incremental](../../build/reference/incremental-link-incrementally.md).  
  
When **\/LTCG** is used to link modules compiled by using [\/Og](../../build/reference/og-global-optimizations.md), [\/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [\/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), or [\/Ox](../../build/reference/ox-full-optimization.md), the following optimizations are performed:  
  
-   Cross\-module inlining  
  
-   Interprocedural register allocation \(64\-bit operating systems only\)  
  
-   Custom calling convention \(x86 only\)  
  
-   Small TLS displacement \(x86 only\)  
  
-   Stack double alignment \(x86 only\)  
  
-   Improved memory disambiguation \(better interference information for global variables and input parameters\)  
  
> [!NOTE]
> o vinculador determina quais otimizações foram usadas para compilar cada função e aplica as mesmas otimizações em tempo de vinculação.  
  
Usando **\/LTCG** e **\/Ogt** faz com que a otimização de alinhamento de duplo.  
  
Se **\/LTCG** e **\/Ogs** forem especificados, alinhamento double não é executado. Se a maioria das funções em um aplicativo é compilada para velocidade, com algumas funções compiladas por tamanho \(por exemplo, usando o [otimizar](../../preprocessor/optimize.md) pragma\), o compilador duplo alinha as funções que são otimizadas para tamanho se chamam funções que exigem alinhamento double.  
  
Se o compilador pode identificar todos os sites de chamada de uma função, o compilador ignora modificadores de convenção de chamada explícitas em uma função e tenta otimizar a convenção de chamada da função:  
  
-   passar parâmetros em registros  
  
-   reordenar parâmetros para o alinhamento  
  
-   remover parâmetros não utilizados  
  
se uma função é chamada por meio de um ponteiro de função, ou se uma função é chamada de fora de um módulo que é compilado usando **\/GL**, o compilador não tenta otimizar a convenção de chamada da função.  
  
> [!NOTE]
> Se você usar **\/LTCG** e redefinir mainCRTStartup, seu aplicativo pode ter um comportamento imprevisível relacionada ao código do usuário que executa antes que objetos globais são inicializados.  Há três maneiras de resolver esse problema: não redefinir mainCRTStartup, não compilar o arquivo que contém o mainCRTStartup usando **\/LTCG**, ou inicializar variáveis globais e objetos estaticamente.  
  
## \/LTCG e módulos MSIL  
Os módulos são compilados usando [\/GL](../../build/reference/gl-whole-program-optimization.md) e [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) pode ser usado como entrada para o vinculador quando **\/LTCG** for especificado.  
  
-   **\/LTCG** pode aceitar arquivos de objeto nativo, os arquivos de objeto nativo\/gerenciado misturados \(compilado usando **\/clr**\) e os arquivos de objeto puro \(compilado usando **\/clr:pure**\) e os arquivos de objeto de segurança \(compilado usando **\/clr:safe**\)  
  
-   **\/LTCG** pode aceitar netmodules seguros, que podem ser criados usando **\/clr:safe \/LN** no Visual C\+\+ e **\/target:module** em qualquer outro compilador do Visual Studio. . Netmodules produzida usando**\/clr** ou **\/clr:pure** não são aceitas pelo **\/LTCG**.  
  
-   \/LTCG:PGI não aceita módulos nativos compilados usando **\/GL** e **\/clr**, ou módulos puros \(produzida usando **\/clr:pure**\)  
  
#### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **Propriedades de configuração** pasta.  
  
3.  Selecione o **geral** página de propriedades.  
  
4.  Modificar o **otimização de programa total** propriedade.  
  
Você também pode aplicar **\/LTCG** para compilações específicas, escolhendo **criar**, **Otimização Guiada por perfil** na barra de menus ou escolhendo uma das opções de Otimização Guiada por perfil no menu de atalho para o projeto.  
  
#### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkTimeCodeGeneration%2A>.  
  
## Consulte também  
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
[Opções de vinculador](../../build/reference/linker-options.md)
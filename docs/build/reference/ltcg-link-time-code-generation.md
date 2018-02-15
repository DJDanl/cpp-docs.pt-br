---
title: "-/LTCG (geração de código para Link-time) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.LinkTimeCodeGeneration
- VC.Project.VCConfiguration.WholeProgramOptimization
- VC.Project.VCCLWCECompilerTool.WholeProgramOptimization
- /ltcg
- VC.Project.VCCLCompilerTool.WholeProgramOptimization
dev_langs:
- C++
helpviewer_keywords:
- link-time code generation in C++ linker
- /LTCG linker option
- -LTCG linker option
- LTCG linker option
ms.assetid: 788c6f52-fdb8-40c2-90af-4026ea2cf2e2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 69e67755ce5015cdd63ad36625e71380a303d2d4
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ltcg-link-time-code-generation"></a>/LTCG (geração de código do tempo de vinculação)
```  
/LTCG[:INCREMENTAL|:NOSTATUS|:STATUS|:OFF|:PGINSTRUMENT|:PGOPTIMIZE|:PGUPDATE]  
```  
  
## <a name="remarks"></a>Comentários  
 : INCREMENTAL (opcional)  
 Especifica que o vinculador só se aplica todo o programa otimização ou link-time geração de código (/ltcg) para o conjunto de arquivos afetados por uma edição, em vez de todo o projeto. Por padrão, esse sinalizador não é definido quando /LTCG for especificado, e o projeto inteiro é vinculado usando a otimização de programa inteiro.  
  
 :NOSTATUS &#124; :STATUS (optional)  
 Especifica se o vinculador exibe um indicador de progresso que mostra a porcentagem do link for concluída. Por padrão, essas informações de status não são exibidas.  
  
 : Desativado (opcional)  
 Desabilita a geração de código para link-time. Esse comportamento é igual a quando /LTCG não for especificado na linha de comando.  
  
 : PGINSTRUMENT (opcional)  
 Essa opção é preterida. Em vez disso, use **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** para gerar uma compilação instrumentada para Otimização Guiada por perfil.  
  
 Os dados que são coletados de execuções instrumentadas são usados para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). A forma abreviada dessa opção é /LTCG:PGI.  
  
 : PGOPTIMIZE (opcional)  
 Essa opção é preterida. Em vez disso, use **/LTCG** e **/USEPROFILE** para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). A forma abreviada dessa opção é /LTCG:PGO.  
  
 : PGUPDATE (opcional)  
 Essa opção é preterida. Em vez disso, use **/LTCG** e **/USEPROFILE** para criar uma imagem otimizada. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md). A forma abreviada dessa opção é /LTCG:PGU.  
  
 A opção /LTCG informa o vinculador para chamar o compilador e executará a otimização de programa inteiro. Você também pode fazer Otimização Guiada por perfil. Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md).  
  
 Com as seguintes exceções, você não pode adicionar opções de vinculador para a combinação PGO /LTCG e /USEPROFILE que não foram especificados na combinação das opções /LTCG e /GENPROFILE inicialização PGO anterior:  
  
-   [/BASE](../../build/reference/base-base-address.md)  
  
-   [/FIXED](../../build/reference/fixed-fixed-base-address.md)  
  
-   /LTCG  
  
-   [/MAP](../../build/reference/map-generate-mapfile.md)  
  
-   [/MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md)  
  
-   [/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md)  
  
-   [/OUT](../../build/reference/out-output-file-name.md)  
  
-   [/PGD](../../build/reference/pgd-specify-database-for-profile-guided-optimizations.md)  
  
-   [/PDB](../../build/reference/pdb-use-program-database.md)  
  
-   [/PDBSTRIPPED](../../build/reference/pdbstripped-strip-private-symbols.md)  
  
-   [/STUB](../../build/reference/stub-ms-dos-stub-file-name.md)  
  
-   [/VERBOSE](../../build/reference/verbose-print-progress-messages.md)  
  
 Quaisquer opções do vinculador especificados junto com o /LTCG e opções /GENPROFILE inicializar PGO não precisa ser especificado quando você cria usando /LTCG e /USEPROFILE; eles são implícita.  
  
 O restante deste tópico discute /LTCG em termos de geração de código para link-time.  
  
 /LTCG é indicado com [/GL](../../build/reference/gl-whole-program-optimization.md).  
  
 O vinculador invoca a geração de código para link-time se ele é passado um módulo que foi compilado usando **/GL** ou um módulo MSIL (consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md)). Se você não especificar explicitamente **/LTCG** quando você passa **/GL** ou módulos MSIL para o vinculador, eventualmente o vinculador detecta isso e reinicia o link **/LTCG**. Especificar explicitamente **/LTCG** quando você passa **/GL** e desempenho de compilação de módulos MSIL para o vinculador para o mais rápido possível.  
  
 Para desempenho mais rápido, use **/LTCG: INCREMENTAL**. Essa opção informa o vinculador para otimizar apenas o conjunto de arquivos que é afetado por uma alteração de arquivo de origem, em vez de todo o projeto. Isso pode reduzir significativamente o tempo de link necessário. Isso não é a mesma opção como vínculo incremental.  
  
 **/LTCG** não é válido para uso com [/incremental](../../build/reference/incremental-link-incrementally.md).  
  
 Quando **/LTCG** é usado para vincular os módulos compilados usando [/Og](../../build/reference/og-global-optimizations.md), [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md), [/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md), ou [/Ox](../../build/reference/ox-full-optimization.md), o otimizações seguintes são executadas:  
  
-   Inlining de módulo cruzado  
  
-   Alocação de registro interprocedural (apenas sistemas de operacionais de 64 bits)  
  
-   Convenção de chamada personalizada (somente x86)  
  
-   Deslocamento de TLS pequeno (somente x86)  
  
-   Alinhamento de pilha duplo (somente x86)  
  
-   Ambiguidades de memória aprimorados (informações de interferência melhor para variáveis globais e parâmetros de entrada)  
  
> [!NOTE]
>  O vinculador determina quais otimizações foram usadas para compilar cada função e aplica as mesmas otimizações em tempo de link.  
  
 Usando **/LTCG** e **/Ogt** faz com que a otimização de alinhamento de duplo.  
  
 Se **/LTCG** e **/Ogs** forem especificados, alinhamento duplo não é executado. Se a maioria das funções em um aplicativo é compilada para agilizar, com algumas funções compiladas para tamanho (por exemplo, usando o [otimizar](../../preprocessor/optimize.md) pragma), o compilador duplo alinha as funções que são otimizadas para tamanho se chamam funções que exigem alinhamento duplo.  
  
 Se o compilador pode identificar todos os sites de chamada de uma função, o compilador ignora modificadores de convenção de chamada explícitas em uma função e tenta otimizar a convenção de chamada da função:  
  
-   passar parâmetros nos registros  
  
-   reordenar parâmetros para o alinhamento  
  
-   Remova os parâmetros não utilizados  
  
 Se uma função é chamada por meio de um ponteiro de função, ou se uma função é chamada de fora de um módulo compilado usando **/GL**, o compilador não tenta otimizar a convenção de chamada da função.  
  
> [!NOTE]
>  Se você usar **/LTCG** e redefinir mainCRTStartup, seu aplicativo pode ter um comportamento imprevisível relacionada ao código do usuário que seja executado antes de objetos globais são inicializados.  Há três maneiras de resolver esse problema: não redefinir mainCRTStartup, não compilar o arquivo que contém mainCRTStartup usando **/LTCG**, ou inicializar variáveis globais e objetos estaticamente.  
  
## <a name="ltcg-and-msil-modules"></a>/LTCG e módulos MSIL  
 Os módulos que são compilados usando [/GL](../../build/reference/gl-whole-program-optimization.md) e [/clr](../../build/reference/clr-common-language-runtime-compilation.md) pode ser usado como entrada para o vinculador quando **/LTCG** for especificado.  
  
-   **/LTCG** pode aceitar arquivos de objeto nativo e arquivos de objeto nativo/gerenciado misto (compilados usando **/clr**). As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
-   /LTCG:PGI não aceita módulos nativos compilados usando **/GL** e **/clr**  
  
#### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **propriedades de configuração** pasta.  
  
3.  Selecione o **geral** página de propriedades.  
  
4.  Modificar o **otimização de programa total** propriedade.  
  
 Você também pode aplicar **/LTCG** para compilações específicas, escolhendo **criar**, **Otimização Guiada por perfil** na barra de menus ou escolhendo uma da otimização guiada por perfil Opções no menu de atalho para o projeto.  
  
#### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LinkTimeCodeGeneration%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)
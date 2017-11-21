---
title: Ferramentas de vinculador LNK2001 erro | Microsoft Docs
ms.custom: 
ms.date: 05/17/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2001
dev_langs: C++
helpviewer_keywords: LNK2001
ms.assetid: dc1cf267-c984-486c-abd2-fd07c799f7ef
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 7f9d0e4f3b3e45d9eace17084bceb84f49385663
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-error-lnk2001"></a>Erro das Ferramentas de Vinculador LNK2001
símbolo externo não resolvido "*símbolo*"  
  
O código compilado faz uma referência ou uma chamada para *símbolo*, mas esse símbolo não está definido em qualquer uma das bibliotecas ou arquivos de objeto especificados para o vinculador.  
  
Essa mensagem de erro é seguida por erro fatal [LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Você deve corrigir todos os LNK2001 e LNK2019 erros para corrigir o erro LNK1120.  
  
## <a name="possible-causes"></a>Causas possíveis  
  
Há muitas maneiras de obter esse erro, mas todos eles envolvem uma referência a uma função ou variável que não é possível o vinculador *resolver*, ou localizar uma definição para. O compilador pode identificar quando um símbolo não é *declarado*, mas não quando ele não está *definido*, porque a definição pode estar em um arquivo de origem diferente ou na biblioteca. Se um símbolo é chamado, mas nunca é definido, o vinculador gerará um erro.  
  
### <a name="coding-issues"></a>Problemas de codificação  
  
Esse erro pode ser causado por caso não correspondente no seu código-fonte ou a definição de módulo (. def) arquivos. Por exemplo, se você nomear uma variável `var1` em C++ de um arquivo de origem e tentar acessá-lo como `VAR1` em outro, esse erro é gerado. Para corrigir esse problema, use consistentemente escrito e nomes de maiusculas e minúsculas.  
  
Esse erro pode ocorrer em um projeto que usa [inlining de função](../../error-messages/tool-errors/function-inlining-problems.md) se você definir as funções em um arquivo de origem em vez de um arquivo de cabeçalho. Funções embutidas não podem ser vistas fora do arquivo de origem que defini-los. Para corrigir esse problema, defina as funções embutidas em cabeçalhos de onde eles são declarados.  
  
Esse erro pode ocorrer se você chamar uma função de C a partir de um programa C++ sem usar um `extern "C"` declaração da função de C. O compilador usa convenções de nomenclatura de símbolo internos diferentes para código C e C++, e é o nome do símbolo interno que o vinculador procura durante a resolução de símbolos. Para corrigir esse problema, use um `extern "C"` wrapper em torno de todas as declarações de funções de C usadas no seu código C++, o que faz com que o compilador para usar a convenção de nomenclatura interna C para os símbolos. Opções do compilador [/Tp](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) e [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) fazer com que o compilador compilar arquivos como C++ ou C, respectivamente, independentemente da extensão de nome de arquivo. Essas opções podem causar nomes de função interna diferentes da esperada.  
  
Esse erro pode ser causado por uma tentativa de fazer referência a funções ou dados que não tem ligação externa. No C++, funções embutidas e `const` dados tem vinculação interna, a menos que explicitamente especificado como `extern`. Para corrigir esse problema, use explícita `extern` declarações em símbolos chamado fora do arquivo de origem de definição.  
  
Esse erro pode ser causado por um [corpo da função ou variável ausente](../../error-messages/tool-errors/missing-function-body-or-variable.md) definição. Esse erro é comum quando você declarar, mas não define, variáveis, funções ou classes no seu código. O compilador só precisa de um protótipo de função ou `extern` declaração de variável para gerar um arquivo de objeto sem erro, mas o vinculador não pode resolver uma chamada para a função ou uma referência à variável porque não há nenhum espaço de código ou variável de função reservado. Para corrigir esse problema, certifique-se de que cada função referenciada e a variável está totalmente definida em uma biblioteca incluída em seu link ou o arquivo de origem.  
  
Esse erro pode ser causado por uma chamada de função que usa tipos de retorno e parâmetro ou convenções de chamada que não coincide com a definição da função. Nos arquivos de objeto C++, [decoração de nome](../../error-messages/tool-errors/name-decoration.md) incorpora a convenção de chamada, escopo de classe ou namespace e tipos de retorno e parâmetro de uma função para o nome de função decorados final, que é usado como o símbolo para fazer a correspondência quando chama a a função de outros arquivos de objeto são resolvidos. Para corrigir esse problema, verifique se a declaração, definição e chamadas para a função todos usam os mesmos escopos, tipos e convenções de chamada.  
  
Esse erro pode ser causado no código C++, quando você incluir um protótipo de função em uma definição de classe, mas não conseguir [incluem a implementação](../../error-messages/tool-errors/missing-function-body-or-variable.md) da função e, em seguida, chamá-lo. Para corrigir esse problema, certifique-se de fornecer uma definição para todas as chamadas declarado como membros de uma classe.  
  
Esse erro pode ser causado por uma tentativa de chamar uma função virtual pura de uma classe base abstrata. Uma função virtual pura não tem nenhuma implementação de classe base. Para corrigir esse problema, verifique se todas as chamadas de funções virtuais são implementadas.  
  
Esse erro pode ser causado pela tentativa de usar uma variável declarada dentro de uma função ([uma variável local](../../error-messages/tool-errors/automatic-function-scope-variables.md)) fora do escopo dessa função. Para corrigir esse problema, remova a referência à variável que não está no escopo ou mover a variável para um escopo mais alto.  
  
Esse erro pode ocorrer quando você criar uma versão de lançamento de um projeto de ATL produzir uma mensagem de que o código de inicialização do CRT é necessário. Para corrigir esse problema, faça o seguinte  
  
-   Remover `_ATL_MIN_CRT` da lista de pré-processador define para permitir que o código de inicialização do CRT ser incluído. Consulte [página de propriedade geral (projeto)](../../ide/general-property-page-project.md) para obter mais informações.  
  
-   Se possível, remova as chamadas a funções de CRT que exigem o código de inicialização do CRT. Em vez disso, use seus equivalentes do Win32. Por exemplo, use `lstrcmp` em vez de `strcmp`. Funções conhecidas que exigem o código de inicialização do CRT são algumas das funções de ponto flutuante e cadeia de caracteres.  
  
### <a name="compilation-and-link-issues"></a>Problemas de compilação e link  
  
Esse erro pode ocorrer quando o projeto está faltando uma referência a uma biblioteca (. LIB) ou o objeto (. Arquivo OBJ). Para corrigir esse problema, adicione uma referência para o arquivo de objeto ou uma biblioteca necessária ao seu projeto. Para obter mais informações, consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).  
  
Esse erro pode ocorrer se você usar o [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) ou [/Zl](../../build/reference/zl-omit-default-library-name.md) opções. Quando você especificar essas opções, bibliotecas que contenham código necessário não estão vinculadas para o projeto, a menos que você os ter incluído explicitamente. Para corrigir esse problema, inclua explicitamente todas as bibliotecas que você usa na linha de comando de link. Se você vir muitos nomes de funções CRT ou biblioteca padrão ausentes quando você usar essas opções, inclua explicitamente os arquivos CRT e DLLs de biblioteca padrão ou biblioteca no link.  

Se você compilar usando o **/clr** opção, pode haver faltando uma referência a cctor. Para corrigir esse problema, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) para obter mais informações.  
  
Esse erro pode ocorrer se você vincular as bibliotecas de modo de versão ao criar uma versão de depuração de um aplicativo. Da mesma forma, se você usar opções **/MTd** ou **/MDd** ou definir `_DEBUG` e, em seguida, um link para as bibliotecas de versão, você deve esperar que muitos externos não resolvidos potenciais, entre outros problemas. Vincular um build de modo de versão com as bibliotecas de depuração também causa problemas semelhantes. Para corrigir esse problema, verifique se você usar as bibliotecas de depuração em compilações de depuração e bibliotecas de varejo no seu varejo cria.  
  
Esse erro pode ocorrer se o código se refere a um símbolo de uma versão de uma biblioteca, mas você fornecer uma versão diferente da biblioteca para o vinculador. Em geral, você não pode misturar arquivos de objeto ou bibliotecas que são criadas para diferentes versões do compilador. As bibliotecas que são enviados em uma nova versão podem conter símbolos que não podem ser encontrados nas bibliotecas do incluídos com versões anteriores e vice-versa. Para corrigir esse problema, crie todos os arquivos de objeto e bibliotecas com a mesma versão do compilador antes de vinculá-los juntos.  
  
-  As ferramentas de &#124; Opções &#124; Projetos &#124; Caixa de diálogo diretórios VC + +, sob a seleção de arquivos de biblioteca, permite que você altere a ordem de pesquisa de biblioteca. A pasta de vinculador na caixa de diálogo páginas de propriedades do projeto também pode conter caminhos que podem estar desatualizados.  
  
-  Esse problema pode aparecer quando um novo SDK está instalado (talvez em um local diferente), e a ordem de pesquisa não é atualizada para apontar para o novo local. Normalmente, você deve colocar o caminho para o novo SDK incluem e lib diretórios na frente do local do Visual C++ padrão. Além disso, um projeto que contém os caminhos inseridos ainda pode apontar para antigos caminhos que são válidos, mas atualizadas para a nova funcionalidade adicionada pela nova versão que está instalada em um local diferente.  
  
-   Se você compilar na linha de comando e criar suas próprias variáveis de ambiente, verifique se os caminhos para arquivos de cabeçalho, bibliotecas e ferramentas Ir para uma versão consistente. Para obter mais informações, consulte [definir o caminho e as variáveis de ambiente para compilações de linha de comando](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md)
  
Atualmente, há um padrão para [C++ nomenclatura](../../error-messages/tool-errors/name-decoration.md) entre os fornecedores de compilador ou até mesmo entre versões diferentes de um compilador. Portanto, vincular arquivos de objeto compilados com outros compiladores pode não produzir o mesmo esquema de nomenclatura e, portanto, causar erro LNK2001.  
  
[Opções de compilação de mixagem embutido e não embutido](../../error-messages/tool-errors/function-inlining-problems.md) em módulos diferentes pode causar LNK2001. Se uma biblioteca C++ é criada com a função inlining ativada (**/Ob1** ou **/Ob2**), mas o arquivo de cabeçalho que descrevem as funções tem inlining desativado (nenhum `inline` palavra-chave), este erro ocorre. Para corrigir esse problema, defina as funções `inline` no arquivo de cabeçalho incluem em outros arquivos de origem.  
  
Se você usar o `#pragma inline_depth` compilador diretiva, não se esqueça de você ter um [valor 2 ou maior conjunto](../../error-messages/tool-errors/function-inlining-problems.md)e verifique se você usar também o [/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md) opção de compilador.  
  
Esse erro pode ocorrer se você omitir o LINK opção /NOENTRY quando você criar uma DLL somente de recursos. Para corrigir esse problema, adicione a opção /NOENTRY para o comando de link.  
  
Esse erro pode ocorrer se você usar configurações de /ENTRY ou /SUBSYSTEM incorreta em seu projeto. Por exemplo, se você escreve um aplicativo de console e especificar /Subsystem: Windows, um erro externo não resolvido é gerado para `WinMain`. Para corrigir esse problema, certifique-se de que corresponde às opções para o tipo de projeto. Para obter mais informações sobre essas opções e os pontos de entrada, consulte o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) e [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções do vinculador.  
  
### <a name="exported-symbol-issues"></a>Problemas de símbolo exportado  
  
Esse erro ocorre quando uma exportação listada em um arquivo. def não foi encontrada. Isso pode ser porque não existe, está escrito incorretamente ou usa nomes decorados do C++. Um arquivo. def não tem nomes decorados. Para corrigir esse problema, remova exportações desnecessárias e usar `extern "C"` declarações para símbolos exportados.  
  
## <a name="what-is-an-unresolved-external-symbol"></a>O que é um símbolo externo não resolvido?  
  
Um *símbolo* é o nome de uma função ou variável global usado internamente por um arquivo de objeto compilado ou biblioteca. É um símbolo *definido* no arquivo de objeto em que o armazenamento é alocado para uma variável global, ou uma função, onde o código compilado para o corpo da função é colocado. Um *símbolo externo* é um símbolo que *referenciado*, ou seja, usado ou chamado no arquivo de um objeto, mas definidos em um arquivo de biblioteca ou objeto diferente. Um *exportado símbolo* é aquele que é disponibilizado publicamente, o arquivo de objeto ou a biblioteca que o define. O vinculador deve *resolver*, ou localizar a definição correspondente para cada símbolo externo referenciado por um arquivo de objeto quando ele está vinculado em um aplicativo ou DLL. O vinculador gerará um erro quando ele não é possível resolver um símbolo externo ao localizar um correspondência símbolo exportado em qualquer um dos arquivos vinculados.    
  
## <a name="use-the-decorated-name-to-find-the-error"></a>Use o nome decorado para localizar o erro
  
O uso de compilador e vinculador C++ [decoração do nome](../../error-messages/tool-errors/name-decoration.md), também conhecido como *desconfiguração nome*para codificar informações extras sobre o tipo de uma variável ou o tipo de retorno, tipos de parâmetro, escopo e chamada convenção de uma função no nome do símbolo. Esse nome decorado é o nome do símbolo procura o vinculador para resolver os símbolos externos.  
  
Como as informações extras se torna parte do nome do símbolo, um erro de link pode acontecer se a declaração de uma função ou variável corresponder exatamente a definição da função ou variável. Isso pode ocorrer mesmo que o mesmo arquivo de cabeçalho é usado no código de chamada e o código de definição, se os sinalizadores de compilador diferentes são usados ao compilar os arquivos de origem. Por exemplo, você pode obter esse erro se a compilação do código para usar o `__vectorcall` convenção de chamada, mas você vincular a uma biblioteca que espera que os clientes chamá-la usando o padrão `__cdecl` ou `__fastcall` convenção de chamada. Nesse caso, os símbolos não coincidem porque as convenções de chamada são diferentes   
  
Para ajudá-lo a encontrar a causa desse tipo de erro, a mensagem de erro do vinculador mostra ambos o "nome amigável," o nome usado no código-fonte e o nome decorado (entre parênteses) para o símbolo externo não resolvido. Você não precisa saber como converter o nome decorado para poder compará-lo com outros nomes decorados. Você pode usar ferramentas de linha de comando que estão incluídas com o compilador para comparar o nome do símbolo esperado e o nome do símbolo real:  

-   O [/EXPORTA](../../build/reference/dash-exports.md) e [/símbolos](../../build/reference/symbols.md) opções da ferramenta de linha de comando DUMPBIN podem ajudá-lo a descobrir quais símbolos são definidos nos arquivos. dll e o objeto ou a biblioteca. Você pode usar isso para verificar se o exportado decorado correspondência de nomes que de decorado nomeia o vinculador procura.  
  
Em alguns casos, o vinculador só pode relatar o nome decorado para um símbolo. Você pode usar a ferramenta de linha de comando UNDNAME para obter o formulário não decorado de nome decorado.  
  
## <a name="additional-resources"></a>Recursos adicionais  
  
Para obter mais informações sobre possíveis causas e soluções LNK2001, consulte a pergunta de estouro de pilha [o que é um erro de símbolo externo indefinido referência/não resolvidos e como corrigi-lo?](http://stackoverflow.com/q/12573816/2002113).  


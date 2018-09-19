---
title: Ferramentas de vinculador LNK2001 erro | Microsoft Docs
ms.custom: ''
ms.date: 05/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2001
dev_langs:
- C++
helpviewer_keywords:
- LNK2001
ms.assetid: dc1cf267-c984-486c-abd2-fd07c799f7ef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb8e560e46da06c4312ab4261016ccd5a5ddda68
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46017841"
---
# <a name="linker-tools-error-lnk2001"></a>Erro das Ferramentas de Vinculador LNK2001

símbolo externo não resolvido "*símbolo*"

O código compilado faz uma referência ou uma chamada para *símbolo*, mas esse símbolo não está definido em qualquer uma das bibliotecas ou arquivos de objeto especificados para o vinculador.

Essa mensagem de erro é seguida por um erro fatal [das LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Você deve corrigir os erros de todos os LNK2001 e LNK2019 para corrigir o erro das LNK1120.

## <a name="possible-causes"></a>Possíveis causas

Há várias maneiras de obter esse erro, mas todos eles envolvem uma referência a uma função ou variável que o vinculador não pode *resolver*, ou encontrar uma definição. O compilador pode identificar quando um símbolo não é *declarado*, mas não quando ele não está *definidos*, porque a definição pode estar em um arquivo de origem diferente ou uma biblioteca. Se um símbolo é referenciado, mas nunca definido, o vinculador gera um erro.

### <a name="coding-issues"></a>Problemas de codificação

Esse erro pode ser causado por caso incompatível em seu código-fonte ou a definição de módulo (. def) arquivos. Por exemplo, se você nomear uma variável `var1` em um C++ arquivo de origem e tente acessá-lo como `VAR1` em outro, esse erro é gerado. Para corrigir esse problema, use consistentemente escrito e nomes de maiusculas e minúsculas.

Esse erro pode ser causado em um projeto que usa [inlining de função](../../error-messages/tool-errors/function-inlining-problems.md) se você definir as funções em um arquivo de origem em vez de em um arquivo de cabeçalho. Funções embutidas não podem ser vistas fora do arquivo de origem que os define. Para corrigir esse problema, defina as funções embutidas nos cabeçalhos de onde eles são declarados.

Esse erro pode ser causado se você chamar uma função de C a partir de um programa C++ sem usar um `extern "C"` declaração para a função C. O compilador usa as convenções de nomenclatura diferentes símbolos interno para código C e C++ e é o nome do símbolo internos que o vinculador procura durante a resolução de símbolos. Para corrigir esse problema, use um `extern "C"` wrapper em torno de todas as declarações das funções C usadas no seu código C++, que faz com que o compilador a usar a convenção de nomenclatura interna de C para esses símbolos. Opções do compilador [/Tp](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) e [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) fazer com que o compilador compilar os arquivos como C++ ou C, respectivamente, independentemente da extensão de nome de arquivo. Essas opções podem fazer com que os nomes de função interna diferentes da esperada.

Esse erro pode ser causado por uma tentativa de fazer referência a funções ou dados que não têm vinculação externa. No C++, funções embutidas e `const` dados tem vinculação interna, a menos que explicitamente especificada como `extern`. Para corrigir esse problema, use explícita `extern` declarações de símbolos chamados fora do arquivo de definição de fonte.

Esse erro pode ser causado por uma [corpo da função ou variável ausente](../../error-messages/tool-errors/missing-function-body-or-variable.md) definição. Esse erro é comum quando você declarar, mas não define, variáveis, funções ou classes em seu código. O compilador precisa apenas de um protótipo de função ou `extern` declaração de variável para gerar um arquivo de objeto sem erro, mas o vinculador não pode resolver uma chamada para a função ou uma referência à variável porque não há nenhum espaço de código ou uma variável de função reservado. Para corrigir esse problema, certifique-se de que cada função referenciada e a variável está totalmente definida em um arquivo de origem ou incluídos em seu link de biblioteca.

Esse erro pode ser causado por uma chamada de função que usa tipos de retorno e de parâmetro ou convenções de chamada que não correspondem na definição de função. Em arquivos de objeto de C++ [decoração de nome](../../error-messages/tool-errors/name-decoration.md) incorpora a convenção de chamada, escopo de classe ou namespace e tipos de retorno e parâmetro de uma função o nome decorado de função final, que é usado como o símbolo para correspondência quando chamadas para a função de outros arquivos de objeto são resolvidas. Para corrigir esse problema, certifique-se de que a declaração, definição e chamadas para a função todas as usam os mesmos escopos, tipos e as convenções de chamada.

Esse erro pode ser causado no código C++, quando você incluir um protótipo de função em uma definição de classe, mas não conseguir [incluem a implementação](../../error-messages/tool-errors/missing-function-body-or-variable.md) da função e, em seguida, chamá-lo. Para corrigir esse problema, certifique-se de fornecer uma definição para todas as chamadas declarados como membros de uma classe.

Esse erro pode ser causado por uma tentativa de chamar uma função virtual pura de uma classe base abstrata. Uma função virtual pura não tem nenhuma implementação de classe base. Para corrigir esse problema, verifique se todas as chamadas de funções virtuais são implementadas.

Esse erro pode ser causado pela tentativa de usar uma variável declarada dentro de uma função ([uma variável local](../../error-messages/tool-errors/automatic-function-scope-variables.md)) fora do escopo dessa função. Para corrigir esse problema, remova a referência à variável que não está no escopo ou mover a variável para um escopo mais alto.

Esse erro pode ocorrer quando você cria uma versão de lançamento de um projeto ATL, produzir uma mensagem de que o código de inicialização do CRT é necessário. Para corrigir esse problema, faça o seguinte

- Remover `_ATL_MIN_CRT` da lista de pré-processador define para permitir que o código de inicialização do CRT ser incluído. Ver [página de propriedades gerais (projeto)](../../ide/general-property-page-project.md) para obter mais informações.

- Se possível, remova as chamadas para funções de CRT que exigem que o código de inicialização do CRT. Em vez disso, use seus equivalentes do Win32. Por exemplo, use `lstrcmp` em vez de `strcmp`. Funções conhecidas que exigem o código de inicialização do CRT são algumas das funções de ponto flutuante e cadeia de caracteres.

### <a name="compilation-and-link-issues"></a>Problemas de compilação e link

Esse erro pode ocorrer quando o projeto está faltando uma referência a uma biblioteca (. LIB) ou o objeto (. Arquivo OBJ). Para corrigir esse problema, adicione uma referência para o arquivo de objeto ou uma biblioteca necessária ao seu projeto. Para obter mais informações, consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).

Esse erro pode ocorrer se você usar o [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) ou [/Zl](../../build/reference/zl-omit-default-library-name.md) opções. Quando você especificar essas opções, bibliotecas que contêm o código necessário não estão vinculadas ao projeto, a menos que você os ter incluído explicitamente. Para corrigir esse problema, inclua explicitamente todas as bibliotecas que você usa na linha de comando de link. Se você vir muitos nomes de função CRT ou a biblioteca padrão ausentes quando você usar essas opções, inclua explicitamente os arquivos de biblioteca e DLLs de biblioteca padrão ou CRT no link.

Se você compilar usando o **/clr** opção, pode haver uma referência ausente ao cctor. Para corrigir esse problema, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) para obter mais informações.

Esse erro pode ocorrer se você vincular para as bibliotecas de modo de versão ao criar uma versão de depuração de um aplicativo. Da mesma forma, se você usar as opções **/MTd** ou **/MDd** ou definir `_DEBUG` e, em seguida, um link para as bibliotecas de versão, você deve esperar que muitos externos não resolvidos potencias, entre outros problemas. Vincular uma compilação de modo de versão com as bibliotecas de depuração também faz com que problemas semelhantes. Para corrigir esse problema, verifique se você usar as bibliotecas de depuração em suas compilações de depuração e bibliotecas de varejo no seu comercial se baseia.

Esse erro pode ocorrer se seu código se refere a um símbolo de uma versão de uma biblioteca, mas você fornecer uma versão diferente da biblioteca para o vinculador. Em geral, você não pode misturar os arquivos de objeto ou bibliotecas que são criadas para versões diferentes do compilador. As bibliotecas que são fornecidos em uma nova versão podem conter símbolos que não foi encontrados nas bibliotecas fornecidas com versões anteriores e vice-versa. Para corrigir esse problema, crie todos os arquivos de objeto e bibliotecas com a mesma versão do compilador antes de vinculá-los juntos.

-  As ferramentas do &#124; opções &#124; projetos &#124; caixa de diálogo diretórios VC + +, sob a seleção de arquivos de biblioteca, permite que você altere a ordem de pesquisa de biblioteca. A pasta do vinculador na caixa de diálogo páginas de propriedades do projeto também pode conter caminhos que poderiam estar desatualizados.

-  Esse problema pode aparecer quando um novo SDK está instalado (talvez para um local diferente) e a ordem de pesquisa não é atualizada para apontar para o novo local. Normalmente, você deve colocar o caminho para o novo SDK incluem e lib diretórios na frente do local padrão do Visual C++. Além disso, um projeto que contém os caminhos inseridos ainda pode apontar para caminhos antigos que são válidos, mas é atualizado para a nova funcionalidade adicionada pela nova versão que está instalada em um local diferente.

- Se você compilar na linha de comando e tiver criado suas próprias variáveis de ambiente, verifique se que os caminhos para arquivos de cabeçalho, bibliotecas e ferramentas de ir para uma versão consistente. Para obter mais informações, consulte [definir o caminho e variáveis de ambiente para Builds de linha de comando](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md)

Atualmente, há um padrão para [C++ nomenclatura](../../error-messages/tool-errors/name-decoration.md) entre fornecedores de compilador ou até mesmo entre diferentes versões de um compilador. Portanto, vinculação de arquivos de objeto compilados com outros compiladores pode não produzir o mesmo esquema de nomenclatura e, portanto, causam erro LNK2001.

[Opções de compilação de mixagem embutido e não ser embutida](../../error-messages/tool-errors/function-inlining-problems.md) em módulos diferentes pode causar LNK2001. Se uma biblioteca C++ é criada com o inlining de função ativada (**/Ob1** ou **/Ob2**), mas o arquivo de cabeçalho correspondente que descreve as funções tem inlining desativado (nenhum `inline` palavra-chave), esse erro ocorre. Para corrigir esse problema, defina as funções `inline` no arquivo de cabeçalho que você incluir em outros arquivos de origem.

Se você usar o `#pragma inline_depth` compilador a diretiva, verifique se você tem uma [valor de 2 ou maior conjunto](../../error-messages/tool-errors/function-inlining-problems.md)e verifique se você usa também o [/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md) opção de compilador.

Esse erro pode ocorrer se você omitir o LINK opção /NOENTRY quando você cria uma DLL somente recurso. Para corrigir esse problema, adicione a opção /NOENTRY ao comando de link.

Esse erro pode ocorrer se você usar configurações de /ENTRY ou /SUBSYSTEM incorreta em seu projeto. Por exemplo, se você escreve um aplicativo de console e especificar /Subsystem: Windows, um erro externo não resolvido é gerado para `WinMain`. Para corrigir esse problema, verifique se que você combinar as opções para o tipo de projeto. Para obter mais informações sobre essas opções e os pontos de entrada, consulte a [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) e [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções do vinculador.

### <a name="exported-symbol-issues"></a>Problemas de símbolo exportado

Esse erro ocorre quando uma exportação listada em um arquivo. def não for encontrada. Isso pode ser porque ele não existe, está escrito incorretamente ou usa nomes de C++ decoradas. Um arquivo. def não utilize nomes decorados. Para corrigir esse problema, remova exportações desnecessárias e usar `extern "C"` declarações para símbolos exportados.

## <a name="what-is-an-unresolved-external-symbol"></a>O que é um símbolo externo não resolvido?

Um *símbolo* é o nome de uma função ou variável global usado internamente por um arquivo de objeto compilado ou biblioteca. É um símbolo *definidas* no arquivo de objeto em que o armazenamento é alocado para uma variável global ou para uma função, em que o código compilado para o corpo da função é colocado. Uma *símbolo externo* é um símbolo que *referenciado*, ou seja, usado ou chamados no arquivo de um objeto, mas definidos em um arquivo de biblioteca ou objeto diferente. Uma *exportados símbolo* é aquele que se torna disponível publicamente pelo arquivo de objeto ou a biblioteca que o define. O vinculador deve *resolver*, ou encontrar a definição correspondente para cada símbolo externo referenciada por um arquivo de objeto quando ele está vinculado em um aplicativo ou DLL. O vinculador gera um erro quando ele não consegue resolver um símbolo externo ao localizar um símbolo exportado correspondente em qualquer um dos arquivos vinculados.

## <a name="use-the-decorated-name-to-find-the-error"></a>Use o nome decorado para localizar o erro

O uso de compilador e vinculador C++ [decoração de nome](../../error-messages/tool-errors/name-decoration.md), também conhecido como *a desconfiguração de nome*, para codificar as informações adicionais sobre o tipo de uma variável ou o tipo de retorno, tipos de parâmetro, escopo e chamar convenção de uma função no nome do símbolo. Esse nome decorado é o nome do símbolo o vinculador procura para resolver símbolos externos.

Como as informações extras se tornam parte do nome do símbolo, um erro de link pode resultar se a declaração de uma variável ou função corresponde exatamente a definição da função ou variável. Isso pode acontecer mesmo que o mesmo arquivo de cabeçalho é usado no código de chamada e o código de definição, se os sinalizadores de compilador diferentes são usados ao compilar os arquivos de origem. Por exemplo, você pode obter esse erro se o seu código é compilado para usar o `__vectorcall` convenção de chamada, mas você vincular a uma biblioteca que espera que os clientes para chamá-lo usando o padrão `__cdecl` ou `__fastcall` convenção de chamada. Nesse caso, os símbolos não coincidem porque as convenções de chamada são diferentes

Para ajudá-lo a encontrar a causa desse tipo de erro, a mensagem de erro de vinculador mostra os dois o "nome amigável," o nome usado no código-fonte e o nome decorado (entre parênteses) para o símbolo externo não resolvido. Você não precisa saber como traduzir o nome decorado para poder compará-lo com outros nomes decorados. Você pode usar ferramentas de linha de comando que estão incluídas com o compilador para comparar o nome do símbolo esperado e o nome do símbolo real:

- O [/EXPORTA](../../build/reference/dash-exports.md) e [/símbolos](../../build/reference/symbols.md) opções da ferramenta de linha de comando DUMPBIN podem ajudá-lo a descobrir quais símbolos são definidos em seus arquivos. dll e biblioteca ou objeto. Você pode usar isso para verificar que o exportado decorado o decorado nomeia o vinculador procura de correspondência de nomes.

Em alguns casos, o vinculador só pode relatar o nome decorado de um símbolo. Você pode usar a ferramenta de linha de comando UNDNAME para obter o formato não decorado de um nome decorado.

## <a name="additional-resources"></a>Recursos adicionais

Para obter mais informações sobre possíveis causas e soluções para LNK2001, consulte a pergunta do Stack Overflow [o que é um erro de símbolo externo indefinido referência/não resolvido e como corrigi-lo?](http://stackoverflow.com/q/12573816/2002113).


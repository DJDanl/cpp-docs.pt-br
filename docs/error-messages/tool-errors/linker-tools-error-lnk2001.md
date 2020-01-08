---
title: Erro das Ferramentas de Vinculador LNK2001
ms.date: 12/19/2019
f1_keywords:
- LNK2001
helpviewer_keywords:
- LNK2001
ms.assetid: dc1cf267-c984-486c-abd2-fd07c799f7ef
ms.openlocfilehash: b6d1e53d8f057ddc93e2dfde65cb951d247dfcc0
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302127"
---
# <a name="linker-tools-error-lnk2001"></a>Erro das Ferramentas de Vinculador LNK2001

> símbolo externo "*Symbol*" não resolvido

O código compilado faz uma referência ou uma chamada para *símbolo*. O símbolo não é definido em nenhuma biblioteca ou arquivos de objeto pesquisados pelo vinculador.

Essa mensagem de erro é seguida pelo erro fatal [LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Para corrigir o erro LNK1120, primeiro corrija todos os erros LNK2001 e LNK2019.

Há várias maneiras de obter erros de LNK2001. Todos eles envolvem uma *referência* a uma função ou variável que o vinculador não pode *resolver*, ou encontrar uma definição para. O compilador pode identificar quando seu código não *declara* um símbolo, mas não quando ele não *define* um. Isso ocorre porque a definição pode estar em um arquivo ou biblioteca de origem diferente. Se o seu código se referir a um símbolo, mas ele nunca for definido, o vinculador gerará um erro.

## <a name="what-is-an-unresolved-external-symbol"></a>O que é um símbolo externo não resolvido?

Um *símbolo* é o nome interno de uma função ou variável global. É a forma do nome usado ou definido em um arquivo de objeto compilado ou biblioteca. Uma variável global é definida no arquivo de objeto onde o armazenamento é alocado para ele. Uma função é definida no arquivo de objeto onde o código compilado para o corpo da função é colocado. Um *símbolo externo* é referenciado em um arquivo de objeto, mas definido em um arquivo de biblioteca ou de objeto diferente. Um *símbolo exportado* é aquele disponibilizado publicamente pelo arquivo de objeto ou pela biblioteca que o define.

Para criar um aplicativo ou DLL, cada símbolo usado deve ter uma definição. O vinculador deve *resolver*ou localizar a definição correspondente para, todos os símbolos externos referenciados por cada arquivo de objeto. O vinculador gera um erro quando não consegue resolver um símbolo externo. Isso significa que o vinculador não encontrou uma definição de símbolo exportada correspondente em nenhum dos arquivos vinculados.

## <a name="compilation-and-link-issues"></a>Problemas de compilação e link

Esse erro pode ocorrer:

- Quando o projeto não tem uma referência a uma biblioteca (. LIB) ou objeto (. OBJ). Para corrigir esse problema, adicione uma referência à biblioteca ou ao arquivo de objeto necessário ao seu projeto. Para obter mais informações, consulte [arquivos lib como entrada do vinculador](../../build/reference/dot-lib-files-as-linker-input.md).

- Quando o projeto tem uma referência a uma biblioteca (. LIB) ou objeto (. OBJ) que, por sua vez, requer símbolos de outra biblioteca. Isso pode acontecer mesmo se você não chamar funções que causam a dependência. Para corrigir esse problema, adicione uma referência à outra biblioteca ao seu projeto. Para obter mais informações, consulte [noções básicas sobre o modelo clássico para vinculação: pegar símbolos para a jornada](https://devblogs.microsoft.com/oldnewthing/20130108-00/?p=5623).

- Se você usar as opções [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) ou [/zl](../../build/reference/zl-omit-default-library-name.md) . Quando você especifica essas opções, as bibliotecas que contêm o código necessário não são vinculadas ao projeto, a menos que você as tenha explicitamente incluído. Para corrigir esse problema, inclua explicitamente todas as bibliotecas que você usa na linha de comando do link. Se você vir muitos nomes de função de biblioteca padrão ou CRT ausentes ao usar essas opções, inclua explicitamente as DLLs de biblioteca CRT e padrão ou os arquivos de biblioteca no link.

- Se você compilar usando a opção **/CLR** . Pode haver uma referência ausente para `.cctor`. Para obter mais informações sobre como corrigir esse problema, consulte [inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).

- Se você vincular às bibliotecas de modo de liberação ao criar uma versão de depuração de um aplicativo. Da mesma forma, se você usar as opções **/MTD** ou **/MDd** ou definir `_DEBUG` e, em seguida, vincular às bibliotecas de versão, deverá esperar muitas externas potenciais não resolvidas, entre outros problemas. Vincular uma compilação de modo de versão com as bibliotecas de depuração também causa problemas semelhantes. Para corrigir esse problema, certifique-se de usar as bibliotecas de depuração em suas compilações de depuração e as bibliotecas de varejo em suas compilações de varejo.

- Se o seu código se refere a um símbolo de uma versão de biblioteca, mas você vincula uma versão diferente da biblioteca. Em geral, você não pode misturar arquivos de objeto ou bibliotecas criadas para versões diferentes do compilador. As bibliotecas que vêm em uma versão podem conter símbolos que não podem ser encontrados nas bibliotecas incluídas com outras versões. Para corrigir esse problema, crie todos os arquivos de objeto e bibliotecas com a mesma versão do compilador antes de vinculá-los. Para obter mais informações, consulte [ C++ compatibilidade binária 2015-2019](../../porting/binary-compat-2015-2017.md).

- Se os caminhos de biblioteca estiverem desatualizados. A caixa de diálogo **ferramentas > opções > projetos > vc + + em diretórios** , na seleção **arquivos de biblioteca** , permite alterar a ordem de pesquisa da biblioteca. A pasta do vinculador na caixa de diálogo páginas de propriedades do projeto também pode conter caminhos que podem estar desatualizados.

- Quando um novo SDK do Windows é instalado (talvez em um local diferente). A ordem de pesquisa da biblioteca deve ser atualizada para apontar para o novo local. Normalmente, você deve colocar o caminho para novos diretórios do SDK include e lib na frente do local do C++ Visual padrão. Além disso, um projeto que contém caminhos inseridos ainda pode apontar para caminhos antigos que são válidos, mas desatualizados. Atualize os caminhos para a nova funcionalidade adicionada pela nova versão instalada em um local diferente.

- Se você criar na linha de comando e tiver criado suas próprias variáveis de ambiente. Verifique se os caminhos para ferramentas, bibliotecas e arquivos de cabeçalho vão para uma versão consistente. Para obter mais informações, consulte [definir o caminho e as variáveis de ambiente para compilações de linha de comando](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md)

## <a name="coding-issues"></a>Problemas de codificação

Esse erro pode ser causado por:

- Caso incompatível no código-fonte ou no arquivo de definição de módulo (. def). Por exemplo, se você nomear uma variável `var1` em C++ um arquivo de origem e tentar acessá-la como `VAR1` em outro, esse erro será gerado. Para corrigir esse problema, use nomes escritos consistentemente e em maiúsculas.

- Um projeto que usa a [função de linhagem](../../error-messages/tool-errors/function-inlining-problems.md). Isso pode ocorrer quando você define as funções como `inline` em um arquivo de origem, em vez de em um arquivo de cabeçalho. As funções embutidas não podem ser vistas fora do arquivo de origem que as define. Para corrigir esse problema, defina as funções embutidas nos cabeçalhos onde elas estão declaradas.

- Chamar uma função C de um C++ programa sem usar uma declaração de `extern "C"` para a função c. O compilador usa convenções de nomenclatura de símbolos internas diferentes para C++ C e code. O nome do símbolo interno é o que o vinculador procura ao resolver os símbolos. Para corrigir esse problema, use um wrapper de `extern "C"` em volta de todas as declarações de funções C++ C usadas em seu código, o que faz com que o compilador use a Convenção de nomenclatura interna C para esses símbolos. As opções de compilador [/TP](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) e [/TC](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) fazem com que o compilador C++ compile arquivos como ou C, respectivamente, não importa qual é a extensão de nome de arquivo. Essas opções podem causar nomes de funções internas diferentes do esperado.

- Uma tentativa de fazer referência a funções ou dados que não têm vínculo externo. No C++, funções embutidas e dados de `const` têm ligação interna, a menos que sejam explicitamente especificados como `extern`. Para corrigir esse problema, use declarações de `extern` explícitas em símbolos referenciados fora da definição do arquivo de origem.

- Um [corpo de função ou definição de variável ausente](../../error-messages/tool-errors/missing-function-body-or-variable.md) . Esse erro é comum quando você declara, mas não define, variáveis, funções ou classes em seu código. O compilador precisa apenas de um protótipo de função ou `extern` declaração de variável para gerar um arquivo de objeto sem erro, mas o vinculador não pode resolver uma chamada para a função ou uma referência à variável porque não há nenhum código de função ou espaço variável reservado. Para corrigir esse problema, certifique-se de definir todas as funções e variáveis referenciadas em um arquivo ou biblioteca de origem vinculado.

- Uma chamada de função que usa tipos de retorno e parâmetro ou convenções de chamada que não correspondem àqueles na definição de função. Em C++ arquivos de objeto, a [decoração de nome](../../error-messages/tool-errors/name-decoration.md) codifica a Convenção de chamada, o escopo da classe ou do namespace e os tipos de retorno e parâmetro de uma função. A cadeia de caracteres codificada se torna parte do nome da função decorada final. Esse nome é usado pelo vinculador para resolver, ou corresponder, chamadas para a função de outros arquivos de objeto. Para corrigir esse problema, verifique se a declaração de função, a definição e as chamadas usam os mesmos escopos, tipos e convenções de chamada.

- C++código que você chama, quando inclui um protótipo de função em uma definição de classe, mas não [inclui a implementação](../../error-messages/tool-errors/missing-function-body-or-variable.md) da função. Para corrigir esse problema, certifique-se de fornecer uma definição para todos os membros de classe que você chama.

- Uma tentativa de chamar uma função virtual pura a partir de uma classe base abstrata. Uma função virtual pura não tem nenhuma implementação de classe base. Para corrigir esse problema, verifique se todos os chamados funções virtuais foram implementados.

- Tentando usar uma variável declarada dentro de uma função ([uma variável local](../../error-messages/tool-errors/automatic-function-scope-variables.md)) fora do escopo dessa função. Para corrigir esse problema, remova a referência à variável que não está no escopo ou mova a variável para um escopo superior.

- Quando você cria uma versão de lançamento de um projeto do ATL, produzindo uma mensagem informando que o código de inicialização do CRT é necessário. Para corrigir esse problema, siga um destes procedimentos,

  - Remova `_ATL_MIN_CRT` da lista de pré-processador define para permitir que o código de inicialização CRT seja incluído. Para obter mais informações, consulte [página de propriedades geral (projeto)](../../build/reference/general-property-page-project.md).

  - Se possível, remova as chamadas para funções CRT que exigem código de inicialização CRT. Em vez disso, use seus equivalentes do Win32. Por exemplo, use `lstrcmp` em vez de `strcmp`. Funções conhecidas que exigem código de inicialização CRT são algumas das funções de cadeia de caracteres e ponto flutuante.

## <a name="consistency-issues"></a>Problemas de consistência

Atualmente, não há padrão para [ C++ decoração de nome](../../error-messages/tool-errors/name-decoration.md) entre fornecedores de compilador ou mesmo entre diferentes versões do mesmo compilador. Arquivos de objeto compilados com compiladores diferentes não podem usar o mesmo esquema de nomenclatura. Vinculá-los pode causar o erro LNK2001.

[Misturar opções de compilação embutidas e não embutidas](../../error-messages/tool-errors/function-inlining-problems.md) em diferentes módulos pode causar LNK2001. Se uma C++ biblioteca for criada com o inlineação de função ativado ( **/Ob1** ou **/Ob2**), mas o arquivo de cabeçalho correspondente que descreve as funções tiver o inlineing desativado (sem `inline` palavra-chave), esse erro ocorrerá. Para corrigir esse problema, defina as funções `inline` no arquivo de cabeçalho que você inclui em outros arquivos de origem.

Se você usar a diretiva de compilador `#pragma inline_depth`, certifique-se de que você definiu um [valor de 2 ou maior](../../error-messages/tool-errors/function-inlining-problems.md)e que também usa a opção de compilador [/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md) .

Esse erro pode ocorrer se você omitir a opção de LINK/NOENTRY ao criar uma DLL somente de recursos. Para corrigir esse problema, adicione a opção/NOENTRY ao comando link.

Esse erro pode ocorrer se você usar configurações incorretas de/SUBSYSTEM ou/ENTRY em seu projeto. Por exemplo, se você escrever um aplicativo de console e especificar/SUBSYSTEM: WINDOWS, um erro externo não resolvido será gerado para `WinMain`. Para corrigir esse problema, certifique-se de que você corresponde às opções para o tipo de projeto. Para obter mais informações sobre essas opções e pontos de entrada, consulte as opções do vinculador [/Subsystem](../../build/reference/subsystem-specify-subsystem.md) e [/entry](../../build/reference/entry-entry-point-symbol.md) .

## <a name="exported-def-file-symbol-issues"></a>Problemas de símbolo de arquivo. def exportado

Esse erro ocorre quando uma exportação listada em um arquivo. def não é encontrada. Pode ser porque a exportação não existe, está grafada incorretamente ou usa C++ nomes decorados. Um arquivo. def não tem nomes decorados. Para corrigir esse problema, remova as exportações desnecessárias e use `extern "C"` declarações para símbolos exportados.

## <a name="use-the-decorated-name-to-find-the-error"></a>Use o nome decorado para localizar o erro

O C++ compilador e o vinculador usam [decoração de nome](../../error-messages/tool-errors/name-decoration.md), também conhecido como o *dimensionamento de nome*. A decoração de nome codifica informações extras sobre o tipo de uma variável em seu nome de símbolo. O nome do símbolo de uma função codifica seu tipo de retorno, tipos de parâmetro, escopo e Convenção de chamada. Esse nome decorado é o nome do símbolo que o vinculador procura para resolver símbolos externos.

Um erro de link pode ocorrer se a declaração de uma função ou variável não corresponder *exatamente* à definição da função ou variável. Isso ocorre porque qualquer diferença se torna parte do nome do símbolo para corresponder. O erro pode ocorrer mesmo que o mesmo arquivo de cabeçalho seja usado tanto no código de chamada quanto no código de definição. Uma maneira que pode ocorrer é se você compilar os arquivos de origem usando diferentes sinalizadores de compilador. Por exemplo, se seu código for compilado para usar o `__vectorcall` Convenção de chamada, mas você vincular a uma biblioteca que espera que os clientes o chamem usando o `__cdecl` padrão ou `__fastcall` Convenção de chamada. Nesse caso, os símbolos não correspondem, pois as convenções de chamada são diferentes.

Para ajudá-lo a encontrar a causa, a mensagem de erro mostra duas versões do nome. Ele exibe o "nome amigável", o nome usado no código-fonte e o nome decorado (entre parênteses). Você não precisa saber como interpretar o nome decorado. Você ainda pode pesquisar e compará-lo com outros nomes decorados. As ferramentas de linha de comando podem ajudar a localizar e comparar o nome de símbolo esperado e o nome de símbolo real:

- As opções [/Exports](../../build/reference/dash-exports.md) e [/Symbols](../../build/reference/symbols.md) da ferramenta de linha de comando DUMPBIN são úteis aqui. Eles podem ajudá-lo a descobrir quais símbolos são definidos em seus arquivos. dll e de objeto ou de biblioteca. Você pode usar a lista de símbolos para verificar se os nomes decorados exportados correspondem aos nomes decorados que o vinculador pesquisa.

- Em alguns casos, o vinculador só pode relatar o nome decorado para um símbolo. Você pode usar a ferramenta de linha de comando UNDNAME para obter a forma não decorada de um nome decorado.

## <a name="additional-resources"></a>Recursos adicionais

Para obter mais informações, consulte a Stack Overflow pergunta ["o que é um erro de símbolo externo de referência não definido/não resolvido e como corrigi-lo?"](https://stackoverflow.com/q/12573816/2002113).

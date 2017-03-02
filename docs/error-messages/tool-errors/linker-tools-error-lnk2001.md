---
title: Ferramentas de vinculador LNK2001 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2001
dev_langs:
- C++
helpviewer_keywords:
- LNK2001
ms.assetid: dc1cf267-c984-486c-abd2-fd07c799f7ef
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 9dee257bec0f09bd729bf10c4a1468ecb20dfa61
ms.openlocfilehash: 3629075e5659cb89ab751b011f3ce2cbf89397cc
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2001"></a>Erro das Ferramentas de Vinculador LNK2001
símbolo externo não resolvido "símbolo"  
  
 Código fizer referência a algo (como uma função, variável ou rótulo) que não é possível localizar o vinculador em bibliotecas e arquivos de objeto.  
  
 Essa mensagem de erro é seguida por um erro fatal [LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md).  
  
 **Possíveis causas**  
  
-   Ao atualizar uma biblioteca gerenciada ou um projeto de serviço web do Visual C++ 2003, o **/Zl** opção de compilador é adicionada para o **linha de comando** página de propriedades. Isso fará com que LNK2001.  
  
     Para resolver esse erro, adicione Msvcrt e msvcmrt.lib a propriedade de dependências adicionais do vinculador. Ou, remover **/Zl** do **linha de comando** página de propriedades. Para obter mais informações, consulte [/Zl (omitir a nome de biblioteca padrão)](../../build/reference/zl-omit-default-library-name.md) e [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
-   O que o código solicita não existe (o símbolo é escrito incorretamente ou usa o caso errado, por exemplo).  
  
-   O código solicita algo errado (você está usando diferentes versões das bibliotecas, alguns a partir de uma versão do produto, outras pessoas de outra versão).  
  
 **Causas específicas**  
  
 **Problemas de codificação**  
  
-   Se o texto de diagnóstico LNK2001 relata que `__check_commonlanguageruntime_version` é um símbolo externo não resolvido, consulte [LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md) para obter informações sobre como resolver.  
  
-   A definição de modelo de membro está fora da classe. Visual C++ tem uma limitação na qual os modelos de membro devem ser totalmente definidos dentro da classe delimitadora. Consulte o artigo Q239436 para obter mais informações sobre modelos LNK2001 e membro.  
  
-   Incompatível caso em seu código ou a definição de módulo (. def) o arquivo pode causar LNK2001. Por exemplo, se você nomeou uma variável `var1` em um C++ arquivo de origem e tentou acessá-lo como `VAR1` em outro.  
  
-   Um projeto que usa [inlining de função](../../error-messages/tool-errors/function-inlining-problems.md) ainda define as funções em um arquivo. cpp, em vez de no cabeçalho do arquivo pode causar LNK2001.  
  
-   Chamar uma função de C a partir de um programa C++ sem usar `extern` "C" (que faz com que o compilador para usar a convenção de nomenclatura de C) pode causar LNK2001. Opções do compilador [/Tp](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) e [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) fazer com que o compilador compilar arquivos como C++ ou C, respectivamente, independentemente da extensão de nome de arquivo. Essas opções podem causar nomes de função diferentes do esperado.  
  
-   Tentativa de fazer referência a funções ou dados que não têm vinculação externa pode causar LNK2001. No C++, funções embutidas e `const` dados tem vinculação interna, a menos que explicitamente especificada como `extern`.  
  
-   A [corpo da função ou variável ausente](../../error-messages/tool-errors/missing-function-body-or-variable.md) pode causar LNK2001. Com apenas um protótipo de função ou `extern` declaração o compilador pode continuar sem erro, mas o vinculador não pode resolver uma chamada para um endereço ou uma referência a uma variável porque não há nenhum código de função ou variável espaço reservado.  
  
-   Chamar uma função com os tipos de parâmetro que não corresponderem na declaração de função pode causar LNK2001. [Decoração de nome](../../error-messages/tool-errors/name-decoration.md) incorpora os parâmetros de uma função o nome decorado de função final.  
  
-   Incorretamente protótipos incluídos, o que fazer com que o compilador espera um corpo da função que não é fornecido podem causar LNK2001. Se você tiver uma classe e a classe não implementação de uma função `F`, lembre-se das regras de resolução de escopo do C++.  
  
-   Ao usar o C++, incluindo um protótipo de função em uma definição de classe e deixar de [incluem a implementação](../../error-messages/tool-errors/missing-function-body-or-variable.md) da função para essa classe pode causar LNK2001.  
  
-   Tentar chamar uma função virtual pura de construtor ou destruidor de uma classe base abstrata pode causar LNK2001. Uma função virtual pura não tem nenhuma implementação da classe base.  
  
-   Tentativa de usar uma variável declarada dentro de uma função ([uma variável local](../../error-messages/tool-errors/automatic-function-scope-variables.md)) fora do escopo dessa função pode causar LNK2001.  
  
-   Ao criar uma versão de um projeto ATL, indica que o código de inicialização do CRT é necessário. Para corrigir, faça o seguinte  
  
    -   Remover `_ATL_MIN_CRT` da lista de pré-processador define para permitir que o código de inicialização CRT ser incluído. Consulte [página de propriedade de configurações de configuração geral](../../ide/general-property-page-project.md) para obter mais informações.  
  
    -   Se possível, remova chamadas a funções de CRT que exigem o código de inicialização do CRT. Em vez disso, use o seus equivalentes no Win32. Por exemplo, use `lstrcmp` em vez de `strcmp`. Funções conhecidas que exigem o código de inicialização CRT são algumas das funções de ponto flutuante e cadeia de caracteres.  
  
 **Compilando e vinculando problemas**  
  
-   O projeto não tem uma referência a uma biblioteca (. LIB) ou objeto (. Arquivos OBJ). Consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md) para obter mais informações.  
  
-   Se você usar [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) ou [/Zl](../../build/reference/zl-omit-default-library-name.md), bibliotecas que contém o código necessário não serão vinculadas ao projeto, a menos que você os tenha incluído explicitamente. (Ao compilar com **/clr** ou **/clr: puro**, você verá uma referência ao cctor; consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) para obter mais informações.)  
  
-   Se você estiver usando Unicode e MFC, você obterá um externo não resolvido em `_WinMain@16` se você não criar um ponto de entrada para `wWinMainCRTStartup`; use o [/ENTRY](../../build/reference/entry-entry-point-symbol.md). Consulte [resumo de programação Unicode](../../text/unicode-programming-summary.md).  
  
     Consulte os seguintes artigos da Base de dados de Conhecimento, localizados na biblioteca do MSDN para obter mais informações. Na biblioteca do MSDN, clique o **pesquisa** guia, cole o número ou o título do artigo na caixa de texto e, em seguida, clique em **Listar tópicos**. Se você procurar o número do artigo, verifique se o **pesquisar somente títulos** opção é clara.  
  
    -   Q125750 "PRB: Error LNK2001: '_WinMain@16': não resolvidos símbolo externo"  
  
    -   Q131204 "PRB: seleção do projeto incorreto causa LNK2001 em _WinMain@16"  
  
    -   Q100639 "suporte Unicode no Microsoft Foundation Class Library"  
  
    -   Q291952 "PRB: Link Error LNK2001: Main símbolo externo não resolvido"  
  
-   Vinculação de código compilado com /MT com a biblioteca de libc. lib causa LNK2001 em `_beginthread`, `_beginthreadex`, `_endthread`, e `_endthreadex`.  
  
-   Vinculação de código que exigem as bibliotecas multithread (qualquer código MFC ou código compilado com [/MT](../../build/reference/md-mt-ld-use-run-time-library.md)) faz com que o LNK2001 em [beginthread](../../c-runtime-library/reference/beginthread-beginthreadex.md), `_beginthreadex`, [endthread](../../c-runtime-library/reference/endthread-endthreadex.md), e `_endthreadex`. Consulte o seguinte artigo da Base de dados de conhecimento para obter mais informações:  
  
    -   Q126646 "PRB: mensagem de erro: LNK2001 em __beginthreadex e \_endthreadex"  
  
    -   Q128641 "INFO: /Mx opções do compilador e o LIBC, LIBCMT, as bibliotecas do MSVCRT"  
  
    -   Q166504 "PRB: MFC e CRT devem corresponder em debug/release e estáticas e dinâmicas"  
  
-   Ao compilar com **/MD**, uma referência ao "func" em sua fonte se torna uma referência "`__imp__func`" no objeto desde que todo o tempo de execução agora é mantido em uma DLL. Se você tentar vincular com as bibliotecas estáticas libc. lib ou libcmt, você obterá LNK2001 em `__imp__func`. Se você tentar vincular com MSVCxx.lib ao compilar sem /MD sempre não obterá LNK2001, mas você provavelmente terá problemas.  
  
-   Vinculação com as bibliotecas de modo de versão ao criar uma versão de depuração de um aplicativo pode causar LNK2001. Da mesma forma, usando um **/Mxd** opção (**/MTd**, ou **/MDd**) e/ou definindo `_DEBUG` e, em seguida, vincular com as bibliotecas de versão dê potenciais externos não resolvidos (entre outros). Vincular uma compilação de modo de versão com as bibliotecas de depuração também causará problemas semelhantes.  
  
-   Mistura de versões de bibliotecas da Microsoft e produtos de compilador pode ser problemático. Bibliotecas de uma versão do compilador novo podem conter novos símbolos que não podem ser encontrados nas bibliotecas incluídas com versões anteriores. Você talvez queira alterar a ordem dos diretórios no caminho de pesquisa ou alterá-los para apontar para a versão atual.  
  
     As ferramentas | Opções | Projetos | Caixa de diálogo diretórios VC + +, sob a seleção de arquivos de biblioteca, permite que você altere a ordem de pesquisa. A pasta do vinculador na caixa de diálogo páginas de propriedades do projeto também pode conter caminhos que podem estar desatualizados.  
  
     Este problema pode ocorrer quando um novo SDK está instalado (talvez em outro local) e a ordem de pesquisa não é atualizada para apontar para o novo local. Normalmente, você deve colocar o caminho para os novos SDKs incluem e lib diretórios na frente o local padrão do Visual C++. Além disso, um projeto que contém os caminhos inseridos ainda pode apontar para caminhos antigos válido, mas é atualizado para a nova funcionalidade adicionada pela nova versão que está instalado em um local diferente.  
  
-   Atualmente, há um padrão para [C++ nomenclatura](../../error-messages/tool-errors/name-decoration.md) entre fornecedores de compilador ou até mesmo entre versões diferentes de um compilador. Portanto, vincular arquivos de objeto compilados com outros compiladores pode não produzir o mesmo esquema de nomenclatura e, portanto, causar erro LNK2001.  
  
-   [Opções de compilação de mixagem embutido e não embutida](../../error-messages/tool-errors/function-inlining-problems.md) nos diferentes módulos podem causar LNK2001. Se uma biblioteca C++ é criada pela função inlining ativada (**/Ob1** ou **/Ob2**), mas o arquivo de cabeçalho correspondente que descreve as funções tem inlining desativado (nenhum `inline` palavra-chave), você receberá esse erro. Para evitar esse problema, as funções embutidas definiu com `inline` no arquivo de cabeçalho que você pretende incluir em outros arquivos.  
  
-   Se você estiver usando o `#pragma inline_depth` compilador diretiva, verifique se você tem uma [valor de conjunto 2 ou posterior](../../error-messages/tool-errors/function-inlining-problems.md)e verifique se você estiver usando o [/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md) opção de compilador.  
  
-   Omitindo a opção LINK /NOENTRY durante a criação de uma DLL somente recurso fará com que LNK2001.  
  
-   O uso de configurações incorretas de /SUBSYSTEM ou /ENTRY pode causar LNK2001. Por exemplo, se você escreve um aplicativo baseado em caracteres (um aplicativo de console) e especificar /SUBSYSTEM:WINDOWS, obterá um externo não resolvido para `WinMain`. Para obter mais informações sobre essas opções e os pontos de entrada, consulte o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) e [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções do vinculador.  
  
 **Problemas de exportação**  
  
-   Quando você estiver portando um aplicativo de 16 a 32 ou 64 bits, LNK2001 podem ocorrer. A sintaxe do arquivo de definição de módulo (. def) atual requer que `__cdecl`, `__stdcall`, e `__fastcall` funções listado na seção EXPORTS sem sublinhados (não decorados). Isso difere da sintaxe de 16 bits, onde eles devem ser listados com sublinhados (decorados). Para obter mais informações, consulte a descrição do [exportações](../../build/reference/exports.md) seção dos arquivos de definição de módulo.  
  
-   LNK2001 fará com que qualquer exportação listados no arquivo. def e não encontrado. Isso pode ser porque ele não existe, está escrito incorretamente ou usa nomes decorado C++ (arquivos. def não têm nomes decorados)  
  
 **Interpretando a saída**  
  
 Quando um símbolo é não resolvido, você pode obter informações sobre a função as seguintes diretrizes:  
  
 Em x86 plataformas, a decoração de convenção de chamada para nomes compilado em C, ou para extern "C" nomes em C++, é:  
  
 `__cdecl`  
 Função tem um prefixo de sublinhado (_).  
  
 `__stdcall`  
 Função tem um prefixo de sublinhado (_) e um @ sufixo seguido dword alinhado tamanho dos parâmetros na pilha.  
  
 `__fastcall`  
 Função tem um prefixo @ e um @ sufixo seguido dword alinhado tamanho dos parâmetros na pilha.  
  
 Use undname.exe para obter o formato não decorado de um nome decorado.  
  
 Para obter mais informações sobre algumas das causas listadas acima, consulte [decoração de nome](../../error-messages/tool-errors/name-decoration.md).

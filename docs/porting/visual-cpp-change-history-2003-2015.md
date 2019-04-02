---
title: Histórico de alterações de 2003 a 2015 do Visual C++
ms.date: 08/30/2017
helpviewer_keywords:
- breaking changes [C++]
ms.assetid: b38385a9-a483-4de9-99a6-797488bc5110
ms.openlocfilehash: 9be4db9e0f7c50054dc6e6ca498b1c9d49715a8d
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58775407"
---
# <a name="visual-c-change-history-2003---2015"></a>Histórico de alterações de 2003 a 2015 do Visual C++

Este artigo descreve todas as alterações significativas, partindo do Visual Studio 2015 e voltando até o Visual Studio 2003 e os termos "novo comportamento" ou "agora" neste artigo referem-se ao Visual Studio 2015 e às versões posteriores. Os termos "comportamento antigo" e "antes" referem-se ao Visual Studio 2013 e versões anteriores.

Para obter informações sobre o Visual Studio 2017, consulte [Novidades do Visual C++ no Visual Studio 2017](../overview/what-s-new-for-visual-cpp-in-visual-studio.md) e [Melhorias de conformidade no Visual C++ no Visual Studio 2017](../overview/cpp-conformance-improvements-2017.md).

> [!NOTE]
> Não há alterações significativas binárias entre o Visual Studio 2015 e Visual Studio 2017.

Ao fazer a atualização para uma nova versão do Visual Studio, você pode encontrar erros de compilação e/ou de tempo de execução no código que foi compilado anteriormente e executado corretamente. As alterações na nova versão que causam tais problemas são conhecidas como *alterações significativas* e, normalmente, são exigidas pelas modificações no padrão da linguagem C++, nas assinaturas de função ou no layout de objetos na memória.

Para evitar os erros de tempo de execução que são difíceis de detectar e diagnosticar, é recomendável nunca vincular estaticamente a binários compilados usando uma versão diferente do compilador. Além disso, ao fazer atualização de um projeto EXE ou DLL, assegure-se de atualizar as bibliotecas às quais ele se vincula. Não passe tipos CRT (Tempo de execução de C) ou de Biblioteca do C++ Standard entre binários (incluindo DLLs) compilados usando diferentes versões do compilador. Para obter mais informações, consulte [Erros potenciais ao passar objetos CRT entre limites de DLL](../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md).

Você nunca deve escrever código que dependa de um determinado layout de um objeto que não seja uma interface COM ou um objeto POD. Se você escrever tal código, será preciso garantir que ele funcione após a atualização. Para obter mais informações, consulte [Portabilidade em limites ABI](../cpp/portability-at-abi-boundaries-modern-cpp.md).

Além disso, aprimoramentos contínuos para a conformidade do compilador podem alterar como o compilador compreende seu código-fonte existente. Por exemplo, você poderá encontrar erros novos ou diferentes durante o build ou até diferenças de comportamento no código que foi compilado anteriormente e parecia executar corretamente. Embora essas melhorias não sejam alterações da falha, ao contrário daquelas discutidas neste documento, pode ser necessário fazer alterações no código-fonte para resolver estes problemas:

- [Alterações significativas na Biblioteca CRT (Tempo de execução de C)](#BK_CRT)

- [Alterações significativas no C++ Padrão e na Biblioteca Padrão do C++](#BK_STL)

- [Alterações significativas de MFC e ATL](#BK_MFC)

- [Alterações significativas de Tempo de Execução de Simultaneidade](#BK_ConcRT)

## <a name="VC_2015"></a> Alterações de conformidade do Visual C++ 2015

###  <a name="BK_CRT"></a> Biblioteca CRT (Tempo de execução de C)

#### <a name="general-changes"></a>Alterações gerais

- **Binários refatorados**

   A biblioteca CRT foi refatorada em dois binários diferentes, um CRT Universal (ucrtbase), que contém a maior parte da funcionalidade padrão e uma Biblioteca em Tempo de Execução do VC (vcruntime). A biblioteca vcruntime contém a funcionalidade relacionada ao compilador, como tratamento de exceção e intrínsecos. Se você estiver usando as configurações padrão de projeto, essa alteração não afetará você, pois o vinculador usará automaticamente as novas bibliotecas padrão. Se tiver definido a propriedade **Ignorar Todas as Bibliotecas Padrão** do **Vinculador** do projeto como **Sim** ou se estiver usando a opção de vinculador `/NODEFAULTLIB` na linha de comando, você deverá atualizar sua lista de bibliotecas (na propriedade **Dependências Adicionais**) para incluir as novas bibliotecas refatoradas. Substitua as bibliotecas CRT antigas (libcmt.lib, libcmtd.lib, msvcrt.lib, msvcrtd.lib) pelas bibliotecas refatoradas equivalentes. Para cada uma das duas bibliotecas refatoradas, há versões estáticas (.lib) e dinâmicas (.dll) e versões release (sem sufixo) e versões de depuração (com o sufixo "d"). As versões dinâmicas têm uma biblioteca de importação com a qual você faz o vínculo. As duas bibliotecas refatoradas são CRT Universal, especificamente ucrtbase.dll ou ucrtbase.lib, ucrtbased.dll ou ucrtbased.lib e a biblioteca de tempo de execução do VC, libvcruntime.lib, vcruntime*versão*.dll, libvcruntimed.lib e vcruntimed*versão*.dll. A *versão* no Visual Studio 2015 e no Visual Studio 2017 é 140. Consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

#### <a name="localeh"></a>\<locale.h>

- **localeconv**

   A função [localeconv](../c-runtime-library/reference/localeconv.md) declarada em locale.h agora funciona corretamente quando [localidade por thread](../parallel/multithreading-and-locales.md) está habilitada. Nas versões anteriores da biblioteca, essa função retornaria os dados `lconv` para a localidade global e não para a localidade do thread.

   Se usar localidades por thread, você deverá verificar o uso de `localeconv`. Se o código pressupõe que os dados de `lconv` retornados são para a localidade global, você deve corrigi-lo.

#### <a name="mathh"></a>\<math.h>

- **Sobrecargas de C++ de funções de biblioteca de matemática**

   Nas versões anteriores, \<math.h> definia algumas, mas não todas, sobrecargas de C++ para as funções de biblioteca de matemática. O restante das sobrecargas estavam no cabeçalho \<cmath>. O código que incluía somente \<math.h> poderia ter problemas com resolução de sobrecarga de função. Agora, as sobrecargas de C++ foram removidas de \<math.h> e estão presentes apenas em \<cmath>.

   Para resolver os erros, inclua \<cmath> para obter as declarações das funções que foram removidas de \<math.h>. Estas funções foram movidas:

  - `double abs(double)` e `float abs(float)`

  - `double pow(double, int)`, `float pow(float, float)`, `float pow(float, int)`, `long double pow(long double, long double)`, `long double pow(long double, int)`

  - Versões `float` e `long double` das funções de ponto flutuante `acos`, `acosh`, `asin`, `asinh`, `atan`, `atanh`, `atan2`, `cbrt`, `ceil`, `copysign`, `cos`, `cosh`, `erf`, `erfc`, `exp`, `exp2`, `expm1`, `fabs`, `fdim`, `floor`, `fma`, `fmax`, `fmin`, `fmod`, `frexp`, `hypot`, `ilogb`, `ldexp`, `lgamma`, `llrint`, `llround`, `log`, `log10`, `log1p`, `log2`, `lrint`, `lround`, `modf`, `nearbyint`, `nextafter`, `nexttoward`, `remainder`, `remquo`, `rint`, `round`, `scalbln`, `scalbn`, `sin`, `sinh`, `sqrt`, `tan`, `tanh`, `tgamma` e `trunc`

  Se você tem código que usa `abs` com um tipo de ponto flutuante que inclui apenas o cabeçalho \<math.h>, as versões de ponto flutuante não estarão mais disponíveis. A chamada agora resolve para `abs(int)`, mesmo com um argumento de ponto flutuante, que produz o erro:

    ```Output
    warning C4244: 'argument' : conversion from 'float' to 'int', possible loss of data
    ```

  A correção para esse aviso é substituir a chamada de `abs` por uma versão de ponto flutuante de `abs`, como `fabs` para um argumento double ou `fabsf` para um argumento float, ou incluir o cabeçalho \<cmath> e continuar usando `abs`.

- **Conformidade de ponto flutuante**

   Muitas alterações foram feitas à biblioteca de matemática para melhorar a conformidade com as especificações IEEE-754 e C11 Anexo F em relação a entradas de caso especial, como NaNs e infinitos. Por exemplo, as entradas silenciosas de NaN, que geralmente eram tratadas como erros nas versões anteriores da biblioteca, não são mais tratadas como erros. Consulte o [Padrão IEEE 754](https://standards.ieee.org/standard/754-2008.html) e o Anexo F do [Padrão C11](http://www.iso-9899.info/wiki/The_Standard).

   Essas alterações não causarão erros de tempo de compilação, mas poderão fazer com que os programas se comportem de maneira diferente e de maneira mais correta de acordo com o padrão.

- **FLT_ROUNDS**

   No Visual Studio 2013, a macro FLT_ROUNDS expandia-se para uma expressão constante, o que era incorreto, porque o modo de arredondamento é configurável no tempo de execução, por exemplo, pela chamada de fesetround. A macro FLT_ROUNDS agora é dinâmica e reflete corretamente o modo de arredondamento atual.

#### <a name="new-and-newh"></a>\<new> e \<new.h>

- **new e delete**

   Nas versões anteriores da biblioteca, as funções new e delete do operador definido pela implementação foram exportadas da biblioteca de tempo de execução DLL (por exemplo, msvcr120.dll). Essas funções de operador agora estão sempre vinculadas estaticamente em seus binários, mesmo ao usar as bibliotecas de tempo de execução DLLs.

   Essa não é uma alteração da falha para o código nativo ou misto (`/clr`), no entanto, para o código compilado como [/clr:pure](../build/reference/clr-common-language-runtime-compilation.md), essa alteração pode causar falha ao compilar seu código. Se você compilar o código como `/clr:pure`, talvez seja necessário adicionar `#include <new>` ou `#include <new.h>` para contornar erros de build devidos a essa alteração. A opção `/clr:pure` foi preterida no Visual Studio 2015 e não tem suporte no Visual Studio 2017. Os códigos que precisarem ser "puros" deverão ser movidos para C#.

#### <a name="processh"></a>\<process.h>

- **_beginthread e _beginthreadex**

   As funções [_beginthread](../c-runtime-library/reference/beginthread-beginthreadex.md) e [_beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md) agora mantêm uma referência ao módulo no qual o procedimento de thread é definido para a duração do thread. Isso ajuda a garantir que os módulos não sejam descarregados até que um thread seja executado até a conclusão.

#### <a name="stdargh"></a>\<stdarg.h>

- **va_start e tipos de referência**

   Ao compilar código C++, o [va_start](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) agora valida em tempo de compilação que o argumento passado para ele não é de tipo de referência. Argumentos de tipo de referência são proibidos pelo Padrão C++.

#### <a name="stdioh-and-conioh"></a>\<stdio.h> e \<conio.h>

- **A família de funções printf e scanf agora são definidas embutidas.**

   As definições de todas as funções `printf` e `scanf` foram movidas embutidas para \<stdio.h>, \<conio.h> e outros cabeçalhos de CRT. Essa alteração da falha leva a um erro de vinculador (LNK2019, símbolo externo não resolvido) para todos os programas que declararam essas funções localmente, sem incluir os cabeçalhos de CRT apropriados. Se possível, você deve atualizar o código para incluir os cabeçalhos de CRT (ou seja, adicionar `#include <stdio.h>`) e as funções embutidas, mas, se você não deseja modificar o código para incluir esses arquivos de cabeçalho, uma solução alternativa é adicionar outra biblioteca, legacy_stdio_definitions.lib, à entrada do vinculador.

   Para adicionar essa biblioteca a sua entrada de vinculador no IDE, abra o menu de contexto do nó do projeto, escolha **Propriedades** e, em seguida, na caixa de diálogo **Propriedades do Projeto**, escolha **Vinculador** e edite a **Entrada do Vinculador** para adicionar `legacy_stdio_definitions.lib` à lista separada por ponto-e-vírgulas.

   Se seu projeto se vincula a bibliotecas estáticas que foram compiladas com uma versão do Visual Studio anterior a 2015, o vinculador pode relatar um símbolo externo não resolvido. Esses erros podem fazer referência a definições internas de `_iob`, `_iob_func` ou importações relacionadas de determinadas funções \<stdio.h> na forma de _imp_\*. A Microsoft recomenda que você recompile todas as bibliotecas estáticas com a versão mais recente do compilador e das bibliotecas do C++ ao atualizar um projeto. Se a biblioteca é uma biblioteca de terceiros cuja fonte não está disponível, você deve solicitar ao terceiro um binário atualizado ou encapsular o uso dessa biblioteca em uma DLL separada que você compila com a versão mais antiga do compilador e das bibliotecas.

    > [!WARNING]
    > Se você estiver vinculando com SDK do Windows 8.1 ou anterior, você poderá se deparar com esses erros de símbolo externo não resolvido. Nesse caso, você deve resolver o erro adicionando a legacy_stdio_definitions.lib ao vinculador de entrada conforme descrito anteriormente.

   Para solucionar problemas de erros de símbolo não resolvido, você pode tentar usar o [dumpbin.exe](../build/reference/dumpbin-reference.md) para examinar os símbolos definidos em um binário. Experimente a seguinte linha de comando para exibir os símbolos definidos em uma biblioteca.

    ```cpp
    dumpbin.exe /LINKERMEMBER somelibrary.lib
    ```

- **gets e _getws**

   As funções [gets](../c-runtime-library/gets-getws.md) e [_getws](../c-runtime-library/gets-getws.md) foram removidas. A função gets foi removida da Biblioteca do C Standard na C11 porque ela não pode ser usada com segurança. A função _getws era uma extensão da Microsoft que era equivalente a gets mas para cadeias de caracteres largas. Como alternativas para essas funções, considere o uso de [fgets](../c-runtime-library/reference/fgets-fgetws.md), [fgetws](../c-runtime-library/reference/fgets-fgetws.md), [gets_s](../c-runtime-library/reference/gets-s-getws-s.md) e [_getws_s](../c-runtime-library/reference/gets-s-getws-s.md).

- **_cgets e _cgetws**

   As funções [_cgets](../c-runtime-library/cgets-cgetws.md) e [_cgetws](../c-runtime-library/cgets-cgetws.md) foram removidas. Como alternativas para essas funções, considere o uso de [_cgets_s](../c-runtime-library/reference/cgets-s-cgetws-s.md) e [_cgetws_s](../c-runtime-library/reference/cgets-s-cgetws-s.md).

- **Formatação de infinito e NaN**

   Nas versões anteriores, infinitos e NaNs eram formatados usando um conjunto de cadeias de caracteres de sentinela específico do MSVC.

  - Infinity: 1.#INF

  - NaN silencioso: 1.#QNAN

  - Sinalização de NaN: 1.#SNAN

  - NaN indefinido: 1.#IND

  Qualquer um desses formatos poderia ser prefixado por um sinal e poderia ser formatado de forma ligeiramente diferente, dependendo da largura do campo e da precisão (às vezes, com efeitos incomuns, por exemplo, `printf("%.2f\n", INFINITY)` imprimiria 1.#J porque o #INF seria "arredondado" com uma precisão de 2 dígitos). O C99 introduziu novos requisitos a respeito de como os infinitos e NaNs devem ser formatados. A implementação do MSVC agora está em conformidade com esses requisitos. As novas cadeias de caracteres são as seguintes:

  - Infinito: inf

  - NaN silencioso: nan

  - NaN sinalizado: nan(snan)

  - NaN indefinido: nan(ind)

  Todas podem ser prefixadas por um sinal. Se um especificador de formato maiúsculo for usado (%F, em vez de %f), as cadeias de caracteres serão impressas em letras maiúsculas (`INF` em vez de `inf`), conforme necessário.

  As funções [scanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md) foram modificadas para analisar essas novas cadeias de caracteres, portanto, essas cadeias de caracteres farão viagem de ida e volta entre `printf` e `scanf`.

- **Formatação e análise de ponto flutuante**

   Novos algoritmos de formatação e análise de ponto flutuante foram introduzidos para melhorar a exatidão. Essa alteração afeta as famílias de funções [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) e [scanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md), bem como funções como a [strtod](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md).

   Os algoritmos de formatação antiga gerariam apenas um número limitado de dígitos e preencheriam as casas decimais restantes com zeros. Eles normalmente poderiam gerar cadeias de caracteres que fariam uma viagem de ida para o valor de ponto flutuante original, mas não eram ideais se você desejasse o valor exato (ou sua representação decimal mais próxima). Os novos algoritmos de formatação geram tantos dígitos quanto necessário para representar o valor (ou para preencher a precisão especificada). Como um exemplo do aperfeiçoamento, considere os resultados ao imprimir uma grande potência de dois:

    ```cpp
    printf("%.0f\n", pow(2.0, 80))
    ```

   Saída antiga:

    ```Output
    1208925819614629200000000
    ```

   Nova saída:

    ```Output
    1208925819614629174706176
    ```

   Os algoritmos de análise antigos considerariam até 17 dígitos significativos da cadeia de entrada e descartariam o restante dos dígitos. Essa abordagem é suficiente para gerar uma aproximação do valor representado pela cadeia de caracteres e o resultado é normalmente muito próximo do resultado corretamente arredondado. A nova implementação considera todos os dígitos presentes e produz o resultado arredondado corretamente para todas as entradas (até 768 dígitos). Além disso, essas funções agora respeitam o modo de arredondamento (controlável por meio de fesetround).  Essa é uma alteração de comportamento potencialmente significativa porque essas funções podem gerar resultados diferentes. Os novos resultados sempre são mais corretos que os resultados antigos.

- **Análise de ponto flutuante hexadecimal e infinito/NaN**

   Os algoritmos de análise de ponto flutuante agora analisarão cadeias de caracteres de ponto flutuante hexadecimais (como aquelas geradas pelos especificadores de formato printf %a e %A) e todas as cadeias de caracteres de infinito e NaN geradas pelas funções `printf`, conforme descrito acima.

- **Preenchimento de zero %a e %A**

   Os especificadores de formato %a e %A formatam um número de ponto flutuante como uma mantissa hexadecimal e expoente binário. Nas versões anteriores, as funções `printf` preencheriam incorretamente as cadeias de caracteres com zero. Por exemplo, `printf("%07.0a\n", 1.0)` imprimiria 00x1p+0, mas deveria imprimir 0x01p+0. Essa falha foi corrigida.

- **Precisão %A e %a**

   A precisão padrão dos especificadores de formato %A e %a era de 6 nas versões anteriores da biblioteca. A precisão padrão agora é de 13 para conformidade com o Padrão C.

   Essa é uma alteração de comportamento de tempo de execução na saída de qualquer função que usa uma cadeia de caracteres de formato com %A ou %a. No comportamento antigo, a saída usando o especificador %A seria "1.1A2B3Cp+111". Agora, a saída para o mesmo valor é "1.1A2B3C4D5E6F7p+111". Para obter o comportamento antigo, você pode especificar a precisão, por exemplo, %.6A. Consulte [Especificação da precisão](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md#precision).

- **Especificador %F**

   Agora há suporte para o especificador de formato/conversão %F. Ele é funcionalmente equivalente ao especificador de formato %f, exceto que os infinitos e NaNs são formatados usando letras maiúsculas.

   Nas versões anteriores, a implementação costumava analisar F e N como modificadores de comprimento. Esse comportamento remonta à época dos espaços de endereçamento segmentado: esses modificadores de comprimento eram usados para indicar ponteiros distantes e próximos como em %Fp ou %Ns, respectivamente. Esse comportamento foi removido. Se %F for encontrado, será tratado como o especificador de formato %F; se %N for encontrado, será tratado como um parâmetro inválido.

- **Formatação de expoente**

   Os especificadores formato %e e %E formatam um número de ponto flutuante como uma mantissa e um expoente decimais. Os especificadores de formato %g e %G também formatam números nesse formato em alguns casos. Nas versões anteriores, o CRT sempre geraria cadeias de caracteres com expoentes de três dígitos. Por exemplo, `printf("%e\n", 1.0)` imprimiria 1.000000e+000, o que seria incorreto. o C exige que se o expoente é representável usando apenas um ou dois dígitos, apenas dois dígitos devem ser impressos.

   No Visual Studio 2005 foi adicionada uma opção de conformidade global: [_set_output_format](../c-runtime-library/set-output-format.md). Um programa poderia chamar essa função com o argumento _TWO_DIGIT_EXPONENT, para habilitar a impressão de expoente em conformidade. O comportamento padrão mudou para o modo de impressão expoente em conformidade com padrões.

- **Validação de cadeia de caracteres de formato**

   Nas versões anteriores, as funções `printf` e `scanf` aceitariam silenciosamente muitas cadeias de caracteres de formato inválido, às vezes, com efeitos incomuns. Por exemplo, %hlhlhld seria tratada como %d. Todas as cadeias de caracteres de formato inválidas são tratadas agora como parâmetros inválidos.

- **Validação de cadeia de caracteres de modo fopen**

   Nas versões anteriores, a família de funções `fopen` aceitava silenciosamente algumas cadeias de caracteres de modo inválidas, tais como `r+b+`. As cadeias de caracteres de modo inválidas agora são detectadas e tratadas como parâmetros inválidos.

- **Modo _O_U8TEXT**

   A função [_setmode](../c-runtime-library/reference/setmode.md) agora relata corretamente o modo para fluxos abertos no modo _O_U8TEXT. Nas versões anteriores da biblioteca, tais fluxos poderiam ser relatados como sendo abertos em _O_WTEXT.

   Essa é uma alteração significativa se seu código interpreta o modo _O_WTEXT para fluxos nos quais a codificação é UTF-8. Se seu aplicativo não oferece suporte a UTF_8, considere adicionar suporte para essa codificação cada vez mais comum.

- **snprintf e vsnprintf**

   As funções [snprintf](../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md) e [vsnprintf](../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md) agora estão implementadas. O código anterior geralmente fornecia definições de versões macro dessas funções porque elas não foram implementadas pela biblioteca CRT, mas elas não são mais necessárias nas versões mais recentes. Se [snprintf](../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md) ou [vsnprintf](../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md) forem definidas como uma macro antes de incluir \<stdio.h>, a compilação falhará com um erro que indica o local em que a macro foi definida.

   Normalmente, a correção para esse problema é excluir todas as declarações de `snprintf` ou `vsnprintf` no código do usuário.

- **tmpnam gera nomes de arquivo utilizáveis**

   Nas versões anteriores, as funções `tmpnam` e `tmpnam_s` geravam nomes de arquivo na raiz da unidade (por exemplo, \sd3c.). Essas funções agora geram caminhos de nome de arquivo utilizáveis em um diretório temporário.

- **Encapsulamento de FILE**

   Nas versões anteriores, o tipo FILE completo era definido publicamente em \<stdio.h>, portanto, era possível que o código de usuário acessasse um FILE e modificasse seu conteúdo interno. A biblioteca foi alterada para ocultar os detalhes da implementação. Como parte dessa alteração, o FILE conforme definido em \<stdio.h> agora é um tipo opaco e seus membros estão inacessíveis de fora do próprio CRT.

- **_outp e _inp**

   As funções [_outp](../c-runtime-library/outp-outpw-outpd.md), [_outpw](../c-runtime-library/outp-outpw-outpd.md), [_outpd](../c-runtime-library/outp-outpw-outpd.md), [_inp](../c-runtime-library/inp-inpw-inpd.md), [_inpw](../c-runtime-library/inp-inpw-inpd.md) e [_inpd](../c-runtime-library/inp-inpw-inpd.md) foram removidas.

#### <a name="stdlibh-malloch-and-sysstath"></a>\<stdlib.h>, \<malloc.h> e \<sys/stat.h>

- **strtof e wcstof**

   As funções `strtof` e `wcstof` falhavam ao definir `errno` como ERANGE quando o valor não era representável como um float. Esse erro era específico dessas duas funções; as funções `strtod`, `wcstod`, `strtold` e `wcstold` não foram afetadas. Esse problema foi corrigido e é uma alteração da falha de tempo de execução.

- **Funções de alocação alinhada**

   Nas versões anteriores, as funções de alocação alinhada (`_aligned_malloc`, `_aligned_offset_malloc` etc.) aceitariam silenciosamente as solicitações de um bloco com um alinhamento 0. O alinhamento solicitado deve ser uma potência de dois, que o zero não é. Um alinhamento solicitado de 0 agora é tratado como um parâmetro inválido. Esse problema foi corrigido e é uma alteração da falha de tempo de execução.

- **Funções heap**

   As funções `_heapadd`, `_heapset` e `_heapused` foram removidas. Essas funções não estão funcionando desde que o CRT foi atualizado para usar o heap do Windows.

- **smallheap**

   A opção de link `smallheap` foi removida. Consulte [Opções de link](../c-runtime-library/link-options.md).

#### <a name="stringh"></a>\<string.h>

- **wcstok**

   A assinatura da função `wcstok` foi alterada para corresponder ao que é exigido pelo Padrão C. Nas versões anteriores da biblioteca a assinatura dessa função era:

    ```cpp
    wchar_t* wcstok(wchar_t*, wchar_t const*)
    ```

   Ela usava um contexto por thread interno para controlar o estado entre chamadas, como é feito para `strtok`. A função agora tem a assinatura `wchar_t* wcstok(wchar_t*, wchar_t const*, wchar_t**)` e requer que o chamador passe o contexto como um terceiro argumento para a função.

   Foi adicionada uma nova função `_wcstok` com a assinatura antiga para facilitar a portabilidade. Ao compilar o código C++, também há uma sobrecarga embutida de `wcstok` que tem a assinatura antiga. Essa sobrecarga é declarada como preterida. No código C, você pode definir _CRT_NON_CONFORMING_WCSTOK para fazer com que `_wcstok` seja usada no lugar de `wcstok`.

#### <a name="timeh"></a>\<time.h>

- **clock**

   Nas versões anteriores, a função [clock](../c-runtime-library/reference/clock.md) foi implementada usando a API [GetSystemTimeAsFileTime](/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime) do Windows. Com essa implementação, a função clock era sensível à hora do sistema e, portanto, não era necessariamente monotônica. A função clock foi reimplementada em termos de [QueryPerformanceCounter](https://msdn.microsoft.com/library/windows/desktop/ms644904.aspx) e agora é monotônica.

- **fstat e _utime**

   Nas versões anteriores, as funções [_stat](../c-runtime-library/reference/stat-functions.md), [fstat](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md) e [_utime](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) lidavam com o horário de verão de maneira incorreta. Antes do Visual Studio 2013, todas essas funções ajustavam incorretamente as horas do horário padrão como se estivessem no horário de verão.

   No Visual Studio 2013, o problema foi corrigido na família de funções **_stat**, mas os problemas semelhantes não foram corrigidos nas famílias de funções **fstat** e **_utime**. Essa correção parcial resultou em problemas devido à inconsistência entre as funções. As famílias de funções **fstat** e **_utime** agora foram corrigidas, portanto todas essas funções agora lidam com o horário de verão de maneira correta e uniforme.

- **asctime**

   Nas versões anteriores, a função [asctime](../c-runtime-library/reference/asctime-wasctime.md) preencheria dias de dígito único com um zero à esquerda, por exemplo: `Fri Jun 06 08:00:00 2014`. A especificação exige que esses dias sejam preenchidos com um espaço à esquerda, por exemplo, `Fri Jun  6 08:00:00 2014`. Esse problema foi corrigido.

- **strftime e wcsftime**

   As funções `strftime` e `wcsftime` agora dão suporte aos especificadores de formato %C, %D, %e, %F, %g, %G, %h, %n, %r, %R, %t, %T, %u e %V. Além disso, os modificadores E e O são analisados, mas ignorados.

   O especificador de formato %c é especificado como produzindo uma "representação adequada de data e hora" para a localidade atual. Na localidade de C, essa representação deve ser o mesmo que `%a %b %e %T %Y`, o mesmo formato que é produzido por `asctime`. Nas versões anteriores, o especificador de formato %c formatava horas incorretamente, usando uma representação `MM/DD/YY HH:MM:SS`. Esse problema foi corrigido.

- **timespec e TIME_UTC**

   O cabeçalho \<time.h> agora define o tipo `timespec` e a função `timespec_get` do Padrão C11. Além disso, a macro TIME_UTC, para ser usada com a função `timespec_get`, agora está definida. Essa atualização é uma alteração da falha para o código que tem uma definição em conflito para qualquer um destes identificadores.

- **CLOCKS_PER_SEC**

   A macro CLOCKS_PER_SEC agora se expande para um inteiro de tipo `clock_t`, conforme exigido pela linguagem C.

####  <a name="BK_STL"></a> Biblioteca Padrão do C++

Para habilitar novas otimizações e verificações de depuração, a implementação da Biblioteca Padrão do C++ do Visual Studio desfaz intencionalmente a compatibilidade binária de uma versão para a próxima. Desse modo, quando a Biblioteca Padrão do C++ é usada, os arquivos de objeto e as bibliotecas estáticas que são compiladas usando versões diferentes não podem ser combinados em um binário (EXE ou DLL), e os objetos da Biblioteca Padrão do C++ não podem ser passados entre binários que são compilados usando versões diferentes. Tal combinação emite erros de vinculador sobre as incompatibilidades de _MSC_VER. (_MSC_VER é a macro que contém a versão principal do compilador, por exemplo, 1800 para o Visual Studio 2013). Essa verificação não pode detectar a combinação de DLL e não pode detectar uma combinação que envolva Visual Studio 2008 ou anterior.

- **Arquivos de inclusão da Biblioteca Padrão do C++**

   Algumas alterações foram feitas na estrutura de inclusão nos cabeçalhos da Biblioteca Padrão do C++. Os cabeçalhos da Biblioteca Padrão do C++ podem ser incluídos uns nos outros de formas não especificadas. Em geral, você deve escrever seu código para que ele inclua cuidadosamente todos os cabeçalhos que são necessários de acordo com o padrão C++ e não dependa de quais cabeçalhos da Biblioteca do C++ Standard inclui outros cabeçalhos de Biblioteca do C++ Standard. Isso torna o código portátil entre plataformas e versões. Pelo menos duas alterações de cabeçalho no Visual Studio 2015 afetam o código do usuário. Primeiro, \<string> não inclui mais \<iterator>. Segundo, \<tuple> agora declara `std::array` sem incluir tudo de \<array>, o que pode interromper o código por meio da seguinte combinação de construções de código: o código tem uma variável chamada "array" e você tem uma diretiva de uso "using namespace std;" e você inclui um cabeçalho de Biblioteca Padrão do C++ (como \<functional>) que inclui \<tuple>, que agora declara `std::array`.

- **steady_clock**

   A implementação \<chrono> de [steady_clock](../standard-library/steady-clock-struct.md) foi alterada para atender aos requisitos de constância e monotonicidade do Padrão C++. `steady_clock` agora é baseado em [QueryPerformanceCounter](https://msdn.microsoft.com/library/windows/desktop/ms644904.aspx) e `high_resolution_clock` agora é uma typedef de `steady_clock`. Como resultado, no Visual Studio `steady_clock::time_point` agora é uma typedef de `chrono::time_point<steady_clock>`; no entanto, esse não é necessariamente o caso para outras implementações.

- **Alocadores e const**

   Agora exigimos que as comparações de igualdade/desigualdade de alocador aceitem argumentos const em ambos os lados. Se os alocadores definem esses operadores conforme demonstrado a seguir,

    ```cpp
    bool operator==(const MyAlloc& other)
    ```

   então você deve atualizá-los e declará-los como membros const:

    ```cpp
    bool operator==(const MyAlloc& other) const
    ```

- **Elementos const**

   O padrão C++ sempre proibiu contêineres de elementos const (como vector\<const T> ou set\<const T>). O Visual Studio 2013 e versões anteriores aceitavam esses contêineres. Na versão atual, esses contêineres falham ao compilar.

- **std::allocator::deallocate**

   No Visual Studio 2013 e versões anteriores, `std::allocator::deallocate(p, n)` ignorava o argumento passado para *n*.  O padrão C++ sempre exigiu que *n* fosse igual ao valor passado como o primeiro argumento para a invocação de `allocate` que retornava *p*. No entanto, na versão atual, o valor de *n* é inspecionado. O código que passa argumentos para *n* que diferem do que o padrão exige pode falhar em tempo de execução.

- **hash_map e hash_set**

   Os arquivos de cabeçalho não padrão \<hash_map e \<hash_set estão preteridos no Visual Studio 2015 e serão removidos em uma versão futura. Em vez disso, use o \<unordered_map> e o \<unordered_set>.

- **Comparadores e operador()**

   Os contêineres associativos (a família \<map>) agora exigem que seus comparadores tenham operadores de chamada de função chamáveis por const. O código a seguir, em uma declaração de classe de comparador, agora falha ao compilar:

    ```cpp
    bool operator()(const X& a, const X& b)
    ```

   Para resolver esse erro, altere a declaração de função para:

    ```cpp
    bool operator()(const X& a, const X& b) const
    ```

- **Características de tipo**

   Os nomes antigos para características de tipo de uma versão anterior do padrão de rascunho C++ foram removidos. Elas foram alteradas no C++11 e foram atualizadas para os valores de C++11 no Visual Studio 2015. A tabela a seguir mostra os nomes antigos e os novos.

   |Nome antigo|Novo nome|
   |--------------|--------------|
   |add_reference|add_lvalue_reference|
   |has_default_constructor|is_default_constructible|
   |has_copy_constructor|is_copy_constructible|
   |has_move_constructor|is_move_constructible|
   |has_nothrow_constructor|is_nothrow_default_constructible|
   |has_nothrow_default_constructor|is_nothrow_default_constructible|
   |has_nothrow_copy|is_nothrow_copy_constructible|
   |has_nothrow_copy_constructor|is_nothrow_copy_constructible|
   |has_nothrow_move_constructor|is_nothrow_move_constructible|
   |has_nothrow_assign|is_nothrow_copy_assignable|
   |has_nothrow_copy_assign|is_nothrow_copy_assignable|
   |has_nothrow_move_assign|is_nothrow_move_assignable|
   |has_trivial_constructor|is_trivially_default_constructible|
   |has_trivial_default_constructor|is_trivially_default_constructible|
   |has_trivial_copy|is_trivially_copy_constructible|
   |has_trivial_move_constructor|is_trivially_move_constructible|
   |has_trivial_assign|is_trivially_copy_assignable|
   |has_trivial_move_assign|is_trivially_move_assignable|
   |has_trivial_destructor|is_trivially_destructible|

- **Políticas launch::any e launch::sync**

   As políticas `launch::any` e `launch::sync` não padrão foram removidas. Em vez disso, para `launch::any`, use `launch:async | launch:deferred`. Para `launch::sync`, use `launch::deferred`. Consulte [Enumeração de inicialização](../standard-library/future-enums.md#launch).

####  <a name="BK_MFC"></a> MFC e ATL

- **MFC (Microsoft Foundation Classes)**

   não está mais incluído em uma instalação "Típica" do Visual Studio devido ao seu tamanho grande. Para instalar o MFC, escolha a opção de instalação **Personalizada** na configuração do Visual Studio 2015. Se já tiver o Visual Studio 2015 instalado, você poderá instalar o MFC executando a instalação do **Visual Studio** novamente. Escolha a opção de instalação **Personalizada** e, em seguida, escolha **Microsoft Foundation Classes**. Você pode executar a instalação do **Visual Studio** no **Painel de Controle**, de **Programas e Recursos** ou da mídia de instalação.

   O Pacote Redistribuível do Visual C++ ainda inclui esta biblioteca.

####  <a name="BK_ConcRT"></a> Tempo de Execução de Simultaneidade

- **Macro Yield do Windows.h em conflito com concurrency::Context::Yield**

   O Tempo de Execução de Simultaneidade usava `#undef` anteriormente para excluir as definições da macro Yield para evitar conflitos entre a macro Yield definida no Windows.h e a função `concurrency::Context::Yield`. Esta `#undef` foi removida e uma nova chamada à API equivalente não conflitante [concurrency::Context::YieldExecution](../parallel/concrt/reference/context-class.md#yieldexecution) foi adicionada. Para resolver conflitos com Yield, atualize seu código para chamar a função `YieldExecution` no lugar da Yield ou coloque o nome de função `Yield` entre parênteses em sites de chamada, como no exemplo a seguir:

    ```cpp
    (concurrency::Context::Yield)();
    ```

## <a name="compiler-conformance-improvements-in-visual-studio-2015"></a>Aprimoramentos de conformidade do compilador no Visual Studio 2015

Ao atualizar o código de versões anteriores, você também pode encontrar erros de compilador devido aos aprimoramentos de conformidade feitos no Visual Studio 2015. Esses aprimoramentos não interrompem a compatibilidade binária de versões anteriores do Visual Studio, mas podem produzir erros de compilador em locais em que nunca houve erros anteriormente. Para obter mais informações, consulte [Novidades no Visual C++ de 2003 até 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md).

Algumas vezes, os aprimoramentos contínuos no Visual Studio 2015 para conformidade do compilador podem alterar a maneira pela qual o compilador compreende seu código-fonte existente. Como resultado, você poderá encontrar erros novos ou diferentes durante o build ou até diferenças de comportamento no código que foi compilado anteriormente e parecia executar corretamente.

Felizmente, essas diferenças têm pouco ou nenhum impacto na maior parte do seu código-fonte. Quando o código-fonte ou outras alterações são necessárias para resolver essas diferenças, as correções tendem a ser pequenas e simples. Incluímos muitos exemplos de código-fonte que eram aceitáveis e que, talvez, precisem ser alterados *(antes)* e as correções para corrigi-los *(depois)*.

Embora essas diferenças possam afetar seu código-fonte ou outros artefatos de build, elas não afetam a compatibilidade binária entre as atualizações de versões do Visual Studio. Uma *alteração da falha* é mais severa e pode afetar a compatibilidade binária, mas esses tipos de interrupções de compatibilidade binária ocorrem somente entre as versões principais do Visual Studio, por exemplo, entre o Visual Studio 2013 e o Visual Studio 2015. Para obter informações sobre as alterações significativas que ocorreram entre o Visual Studio 2013 e o Visual Studio 2015, consulte [Alterações de conformidade do Visual Studio 2015](#VC_2015).

- [Melhorias de conformidade no Visual Studio 2015](#VS_RTM)

- [Aprimoramentos de conformidade na Atualização 1](#VS_Update1)

- [Aprimoramentos de conformidade na Atualização 2](#VS_Update2)

- [Aprimoramentos de conformidade na Atualização 3](#VS_Update3)

###  <a name="VS_RTM"></a> Melhorias de conformidade no Visual Studio 2015

- Opção /Zc:forScope-

   A opção do compilador `/Zc:forScope-` foi preterida e será removida em uma versão futura.

    ```cpp
    Command line warning  D9035: option 'Zc:forScope-' has been deprecated and will be removed in a future release
    ```

   Essa opção foi comumente usada para permitir código não padrão que usa variáveis de loop após o momento em que deveriam ter saído do escopo, de acordo com o padrão. Ela só era necessária para compilar com a opção `/Za`, uma vez que sem `/Za`, o uso de uma variável for loop após o final do loop sempre é permitido. Se a conformidade com os padrões não for importante nesse caso (por exemplo, se o código não se destinar à portabilidade para outros compiladores), você poderá desabilitar a opção `/Za` (ou definir a propriedade **Desabilitar extensões de linguagem** como **Não**). Se você deseja escrever código portátil e em conformidade com os padrões, você deve reescrever o código, movendo a declaração de tais variáveis para um ponto fora do loop, para ficar em conformidade com o padrão.

    ```cpp
    // C2065 expected
    int main() {
        // Uncomment the following line to resolve.
        // int i;
        for (int i = 0; i < 1; i++);
        i = 20;   // i has already gone out of scope under /Za
    }
    ```

- Opção do compilador `/Zg`

   A opção do compilador `/Zg` (Gerar Protótipos de Função) não está mais disponível. Essa opção do compilador foi anteriormente preterida.

- Não é possível executar testes de unidade com C++/CLI na linha de comando com mstest.exe. Em vez disso, use vstest.console.exe. Consulte [Opções de linha de comando de VSTest.Console.exe](/visualstudio/test/vstest-console-options).

- **palavra-chave mutable**

   O especificador de classe de armazenamento **mutable** não é mais permitido em locais em que anteriormente era compilado sem erros. Agora, o compilador gera um erro C2071 (classe de armazenamento inválida). Segundo o padrão, o especificador **mutable** só pode ser aplicado a nomes de membros de dados de classe e não pode ser aplicado a nomes declarados const ou static e também não pode ser aplicado para fazer referência a membros.

   Por exemplo, considere o seguinte código:

    ```cpp
    struct S
    {
        mutable int &r;
    };
    ```

   Versões anteriores do compilador aceitavam isso, mas agora o compilador retorna o seguinte erro:

    ```Output
    error C2071: 'S::r': illegal storage class
    ```

   Para corrigir o erro, remova a palavra-chave redundante **mutable**.

- **char_16_t e char32_t**

   Você não pode mais usar `char16_t` nem `char32_t` como aliases em um **typedef**, porque esses tipos agora são tratados como internos. É comum que usuários e autores de biblioteca definam `char16_t` e `char32_t` como aliases de `uint16_t` e `uint32_t`, respectivamente.

    ```cpp
    #include <cstdint>

    typedef uint16_t char16_t; //C2628
    typedef uint32_t char32_t; //C2628

    int main(int argc, char* argv[])
    {
        uint16_t x = 1; uint32_t y = 2;
        char16_t a = x;
        char32_t b = y;
        return 0;
    }
    ```

   Para atualizar o código, remova as declarações de **typedef** e renomeie todos os outros identificadores que estiverem em conflito com esses nomes.

- **Parâmetros de modelo de não tipo**

   Alguns códigos que envolvem os parâmetros de modelo de não tipo agora têm a compatibilidade de tipo corretamente verificada quando você fornece argumentos de modelo explícitos. Por exemplo, o seguinte código compilado sem erros nas versões anteriores do Visual Studio.

    ```cpp
    struct S1
    {
        void f(int);
        void f(int, int);
    };

    struct S2
    {
        template <class C, void (C::*Function)(int) const> void f() {}
    };

    void f()
    {
        S2 s2;
        s2.f<S1, &S1::f>();
    }
    ```

   O compilador atual corretamente apresentará um erro, porque o tipo de parâmetro de modelo não corresponde ao argumento de modelo (o parâmetro é um ponteiro para um membro const, mas a função f é não const):

    ```Output
    error C2893: Failed to specialize function template 'void S2::f(void)'note: With the following template arguments:note: 'C=S1'note: 'Function=S1::f'
    ```

   Para resolver esse erro em seu código, verifique se o tipo do argumento de modelo que você usa corresponde ao tipo declarado do parâmetro do modelo.

- **__declspec(align)**

   O compilador não aceita mais `__declspec(align)` em funções. Esse constructo sempre foi ignorado, mas agora produz um erro do compilador.

    ```cpp
    error C3323: 'alignas' and '__declspec(align)' are not allowed on function declarations
    ```

   Para corrigir esse problema, remova `__declspec(align)` da declaração da função. Uma vez que ela não tinha efeito, removê-la não altera nada.

- **Tratamento de exceções**

   Há algumas alterações para o tratamento de exceções. Primeiro, os objetos de exceção precisam ser copiáveis ou móveis. O código a seguir era compilado no Visual Studio 2013, mas não é compilado no Visual Studio 2015:

    ```cpp
    struct S
    {
    public:
        S();
    private:
        S(const S &);
    };

    int main()
    {
        throw S(); // error
    }
    ```

   O problema é que o construtor de cópia é particular, portanto o objeto não pode ser copiado como acontece no curso normal de tratamento de exceção. O mesmo se aplica quando o construtor de cópia é declarado como **explicit**.

    ```cpp
    struct S
    {
        S();
        explicit S(const S &);
    };

    int main()
    {
        throw S(); // error
    }
    ```

   Para atualizar o código, verifique se o construtor de cópia do objeto de exceção é **público** e não está marcado como **explicit**.

   A captura de uma exceção pelo valor também exige que o objeto de exceção seja copiável. O código a seguir era compilado no Visual Studio 2013, mas não é compilado no Visual Studio 2015:

    ```cpp
    struct B
    {
    public:
        B();
    private:
        B(const B &);
    };

    struct D : public B {};

    int main()
    {
        try
        {
        }
        catch (D d) // error
        {
        }
    }
    ```

   Você pode corrigir esse problema alterando o tipo de parâmetro de **catch** para uma referência.

    ```cpp
    catch (D& d)
    {
    }
    ```

- **Literais de cadeia de caracteres seguidos de macros**

   Agora o compilador dá suporte a literais definidos pelo usuário. Como consequência, os literais de cadeia de caracteres seguidos de macros sem qualquer espaço em branco de intervenção são interpretados como literais definidos pelo usuário, o que pode causar erros ou resultados inesperados. Por exemplo, nos compiladores anteriores o seguinte código foi compilado com êxito:

    ```cpp
    #define _x "there"
    char* func() {
        return "hello"_x;
    }
    int main()
    {
        char * p = func();
        return 0;
    }
    ```

   O compilador interpretou esse código como uma cadeia de caracteres literal "hello" seguida por uma macro, que é expandida em "there" e, em seguida, os dois literais de cadeia de caracteres foram concatenados em um. No Visual Studio 2015, o compilador interpreta essa sequência como um literal definido pelo usuário, mas como não há nenhum literal `_x` definido pelo usuário correspondente, ele gera um erro.

    ```Output
    error C3688: invalid literal suffix '_x'; literal operator or literal operator template 'operator ""_x' not found
    note: Did you forget a space between the string literal and the prefix of the following string literal?
    ```

   Para corrigir esse problema, adicione um espaço entre o literal de cadeia de caracteres e a macro.

- **Literais de cadeia de caracteres adjacentes**

   Assim como os anteriores, devido a alterações na análise de cadeia de caracteres, os literais de cadeia de caracteres adjacentes (literais de cadeia de caracteres largos ou estreitos) sem nenhum espaço em branco foram interpretados como uma única cadeia de caracteres concatenada nas versões anteriores do Visual C++. No Visual Studio 2015, agora você precisa adicionar um espaço em branco entre as duas cadeias de caracteres. Por exemplo, o código a seguir deve ser alterado:

    ```cpp
    char * str = "abc""def";
    ```

   Para corrigir esse problema, adicione um espaço entre as duas cadeias de caracteres:

    ```cpp
    char * str = "abc" "def";
    ```

- **Posicionamento de new e delete**

   Uma alteração foi feita no operador **delete** para colocá-lo em conformidade com o padrão C++14. Detalhes da alteração dos padrões podem ser encontrados em [Desalocação dimensionada de C++](http://isocpp.org/files/papers/n3778.html). As alterações adicionam uma forma do operador **delete** global que usa um parâmetro de tamanho. A alteração da falha é que, se você já estava usando um operador **delete** com a mesma assinatura (para corresponder a um operador **placement new**), ocorre um erro do compilador (C2956, que ocorre no ponto em que placement new é usado, já que essa é a posição no código em que o compilador tenta identificar um operador **delete** correspondente apropriado).

   A função `void operator delete(void *, size_t)` era um operador **placement delete** correspondente à função `void * operator new(size_t, size_t)` de **placement new** no C++11. Com a desalocação dimensionada de C++14, essa função delete agora é uma *função de desalocação comum* (operador **delete** global). O padrão exige que, se o uso de um new de posicionamento procura uma função delete correspondente e localiza uma função de desalocação comum, o programa está mal formado.

   Por exemplo, suponha que seu código defina um **placement new** e um **placement delete**:

    ```cpp
    void * operator new(std::size_t, std::size_t);
    void operator delete(void*, std::size_t) noexcept;
    ```

   O problema ocorre devido à correspondência nas assinaturas de função entre um operador **placement delete** que você definiu e o novo operador **delete** de dimensionamento global. Considere se você pode usar um tipo diferente de `size_t` para operadores **placement new** e **delete**. O tipo de **typedef** `size_t` depende do compilador. Trata-se de um **typedef** de **unsigned int** no MSVC. Uma boa solução é usar um tipo enumerado como este:

    ```cpp
    enum class my_type : size_t {};
    ```

   Em seguida, altere sua definição de **placement new** e **delete** para usar esse tipo como o segundo argumento, em vez de `size_t`. Você também precisará atualizar as chamadas a placement new para passar o novo tipo (por exemplo, usando `static_cast<my_type>` para converter do valor inteiro) e atualizar a definição de **new** e **delete** para retroceder ao tipo inteiro. Você não precisa usar uma **enumeração** para isso. Um tipo de uma classe com um membro `size_t` também funciona.

   Uma solução alternativa é que você poderá eliminar completamente o **placement new**. Se seu código usar **placement new** para implementar um pool de memória no qual o argumento de posicionamento é o tamanho do objeto que está sendo alocado ou excluído, o recurso de desalocação dimensionada poderá ser adequado para substituir seu próprio código de pool de memória personalizado e você poderá abandonar as funções de posicionamento e simplesmente usar seu próprio operador **delete** de dois argumentos em vez das funções de posicionamento.

   Se não quiser atualizar o código imediatamente, você poderá reverter para o comportamento antigo usando a opção do compilador `/Zc:sizedDealloc-`. Se você usar essa opção, as funções delete de dois argumentos não existirão e não causarão conflito com o operador **placement delete**.

- **Membros de dados de união**

   Membros de dados de uniões não podem mais ter tipos de referência. O código a seguir era compilado com êxito no Visual Studio 2013, mas gera um erro no Visual Studio 2015.

    ```cpp
    union U1
    {
        const int i;
    };
    union U2
    {
        int & i;
    };
    union U3
    {
        struct { int & i; };
    };
    ```

   O código anterior produz os seguintes erros:

    ```Output
    test.cpp(67): error C2625: 'U2::i': illegal union member; type 'int &' is reference type
    test.cpp(70): error C2625: 'U3::i': illegal union member; type 'int &' is reference type
    ```

   Para resolver esse problema, altere os tipos de referência para um ponteiro ou um valor. Alterar o tipo para um ponteiro exige alterações no código que usa o campo de união. Alterar o código para um valor alteraria os dados armazenados na união, o que afeta outros campos, pois os campos nos tipos de união compartilham a mesma memória. Dependendo do tamanho do valor, ele também pode alterar o tamanho da união.

- As uniões anônimas são agora mais compatíveis com o padrão. As versões anteriores do compilador geravam um construtor e um destruidor explícitos de uniões anônimas. Essas funções geradas pelo compilador são excluídas no Visual Studio 2015.

    ```cpp
    struct S
    {
        S();
    };

    union
    {
        struct
        {
            S s;
        };
    } u; // C2280
    ```

   O código anterior gera o seguinte erro no Visual Studio 2015:

    ```cpp
    error C2280: '<unnamed-type-u>::<unnamed-type-u>(void)': attempting to reference a deleted function
    note: compiler has generated '<unnamed-type-u>::<unnamed-type-u>' here
    ```

   Para resolver esse problema, forneça suas próprias definições do construtor e/ou do destruidor.

    ```cpp
    struct S
    {
        // Provide a default constructor by adding an empty function body.
        S() {}
    };

    union
    {
        struct
        {
            S s;
        };
    } u;
    ```

- **Uniões com structs anônimos**

   Para entrar em conformidade com o padrão, o comportamento do tempo de execução foi alterado para membros de estruturas anônimas em uniões. O construtor para membros de estrutura anônima em uma união não é mais implicitamente chamado quando a união é criada. Além disso, o destruidor para membros de estrutura anônima em uma união não é mais implicitamente chamado quando a união sai do escopo. Considere o código a seguir, em que uma união U contém uma estrutura anônima que contém uma estrutura membro nomeada S que tem um destruidor.

    ```cpp
    #include <stdio.h>
    struct S
    {
        S() { printf("Creating S\n"); }
        ~S() { printf("Destroying S\n"); }
    };
    union U
    {
        struct {
            S s;
        };
        U() {}
        ~U() {}
    };

    void f()
    {
        U u;
        // Destructor implicitly called here.
    }

    int main()
    {
        f();

        char s[1024];
        printf("Press any key.\n");
        gets_s(s);
        return 0;
    }
    ```

   No Visual Studio 2013, o construtor para S é chamado quando a união é criada, e o destruidor para S é chamado quando a pilha da função f é limpa. Mas, no Visual Studio 2015, nem o construtor e nem o destruidor são chamados. O compilador dá um aviso sobre essa alteração de comportamento.

    ```Output
    warning C4587: 'U::s': behavior change: constructor is no longer implicitly calledwarning C4588: 'U::s': behavior change: destructor is no longer implicitly called
    ```

   Para restaurar o comportamento original, nomeie a estrutura anônima. O comportamento de tempo de execução de estruturas não anônimas é o mesmo, independentemente da versão do compilador.

    ```cpp
    #include <stdio.h>

    struct S
    {
        S() { printf("Creating S.\n"); }
        ~S() { printf("Destroying S\n"); }
    };
    union U
    {
        struct
        {
            S s;
        } namedStruct;
        U() {}
        ~U() {}
    };

    void f()
    {
        U u;
    }

    int main()
    {
        f();

        char s[1024];
        printf("Press any key.\n");
        gets_s(s);
        return 0;
    }
    ```

   Como alternativa, tente mover o código do construtor e do destruidor para novas funções e adicionar chamadas para essas funções do construtor e do destruidor da união.

    ```cpp
    #include <stdio.h>

    struct S
    {
        void Create() { printf("Creating S.\n"); }
        void Destroy() { printf("Destroying S\n"); }
    };
    union U
    {
        struct
        {
            S s;
        };
        U() { s.Create(); }
        ~U() { s.Destroy(); }
    };

    void f()
    {
        U u;
    }

    int main()
    {
        f();

        char s[1024];
        printf("Press any key.\n");
        gets_s(s);
        return 0;
    }
    ```

- **Resolução de modelo**

   Foram feitas alterações na resolução de nomes dos modelos. No C++, esse pode ser o caso de um ou mais nomes em consideração como correspondências possíveis causando uma instanciação de modelo inválida, ao considerar candidatos para a resolução de um nome. Essas instanciações inválidas normalmente não causam erros de compilador, um princípio que é conhecido como SFINAE (Substitution Failure Is Not An Error – Falha de substituição não é um erro).

   Agora, se o SFINAE exige que o compilador instancie a especialização de um modelo de classe, os erros que ocorrem durante esse processo são erros de compilador. Nas versões anteriores, o compilador ignoraria esses erros. Por exemplo, considere o seguinte código:

    ```cpp
    #include <type_traits>

    template< typename T>
    struct S
    {
        S() = default;
        S(const S&);
        S(S& &);

        template< typename U, typename = typename std::enable_if< std::is_base_of< T, U> ::value> ::type>
        S(S< U> & &);
    };

    struct D;

    void f1()
    {
        S< D> s1;
        S< D> s2(s1);
    }

    struct B
    {
    };

    struct D : public B
    {
    };

    void f2()
    {
        S< D> s1;
        S< D> s2(s1);
    }
    ```

   Se você compilar com o compilador atual, você obterá o seguinte erro:

    ```Output
    type_traits(1110): error C2139: 'D': an undefined class is not allowed as an argument to compiler intrinsic type trait '__is_base_of'
    ..\t331.cpp(14): note: see declaration of 'D'
    ..\t331.cpp(10): note: see reference to class template instantiation 'std::is_base_of<T,U>' being compiled
    with
    [
        T=D,
        U=D
    ]
    ```

   Isso ocorre porque no momento da primeira invocação de is_base_of, a classe `D` ainda não foi definida.

   Nesse caso, a correção é não usar essas características de tipo até que a classe seja definida. Se você mover as definições de `B` e `D` para o início do arquivo de código, o erro será resolvido. Se as definições estiverem em arquivos de cabeçalho, verifique a ordem das instruções include dos arquivos de cabeçalho para certificar-se de que nenhuma definição de classe é compilada antes que os modelos problemáticos sejam usados.

- **Construtores de cópia**

   No Visual Studio 2013 e Visual Studio 2015, o compilador gera um construtor de cópia para uma classe quando essa classe tem um construtor de movimento definido pelo usuário, mas nenhum construtor de cópia definido pelo usuário. No Dev14, esse construtor de cópia implicitamente gerado também é marcado "= delete".

<!--From here to VS_Update1 added 04/21/2017-->

- **principal declarado como "C" externo agora requer um tipo de retorno.**

   Agora, o código a seguir produz C4430.

    ```cpp
    extern "C" __cdecl main(){} // C4430
    ```

   Para corrigir o erro, adicione o tipo de retorno:

    ```cpp
    extern "C" int __cdecl main(){} // OK
    ```

- **typename não é permitido em um inicializador de membro**

   Agora, o código a seguir produz C2059:

    ```cpp
    template<typename T>
    struct S1 : public T::type
    {
        S1() : typename T::type() // C2059
        {
        }
    };

    struct S2 {
        typedef S2 type;
    };

    S1<S2> s;
    ```

   Para corrigir o erro, remova `typename` do inicializador:

    ```cpp
    S1() : T::type() // OK
    ...
    ```

- **A classe de armazenamento em especializações explícitas é ignorada.**

   No código a seguir, o especificador de classe de armazenamento estático é ignorado

    ```cpp
    template <typename T>
    void myfunc(T h)
    {
    }

    template<>
    static void myfunc(double h) // static is ignored
    {
    }
    ```

- **Uma constante usada em um static_assert dentro de um modelo de classe sempre falhará.**

   O código a seguir faz com que `static_assert` sempre falhe:

    ```cpp
    template <size_t some_value>
    struct S1
    {
        static_assert(false, "default not valid"); // always invoked

    };

    //other partial specializations here
    ```

   Para contornar esse problema, encapsule o valor em um **struct**:

    ```cpp
    template <size_t some_value>
    struct constant_false {
        static const bool value = false;
    };

    template <size_t some_value>
    struct S1
    {
        static_assert(constant_false<some_value>::value, "default not valid");
    };

    //other partial specializations here
    ```

- **Regras impostas para declarações de encaminhamento. (Aplica-se somente a C.)**

   Agora, o código a seguir produz C2065:

    ```cpp
    struct token_s;
    typedef int BOOL;
    typedef int INT;

    typedef int(*PFNTERM)(PTOKEN, BOOL, INT); // C2065: 'PTOKEN' : undeclared identifier
    ```

   Para corrigir esse problema, adicione as declarações de encaminhamento apropriadas:

    ```cpp
    struct token_s;
    typedef int BOOL;
    typedef int INT;

    // forward declarations:
    typedef struct token_s TOKEN;
    typedef TOKEN *PTOKEN;

    typedef int(*PFNTERM)(PTOKEN, BOOL, INT);
    ```

- **Imposição mais consistente de tipos de ponteiro de função**

   Agora, o código a seguir produz C2197:

    ```cpp
    typedef int(*F1)(int);
    typedef int(*F2)(int, int);

    void func(F1 f, int v1, int v2)
    {
        f(v1, v2); // C2197
    }
    ```

- **Chamadas ambíguas a funções sobrecarregadas**

   Agora, o código a seguir produz C266: 'N::bind': chamada ambígua à função sobrecarregada

    ```cpp
    template<typename R, typename T, typename T1, typename A1>
    void bind(R(T::*)(T1), A1&&);

    namespace N
    {
        template <typename T, typename R, typename ... Tx>
        void bind(R(T::*)(Tx...), T* ptr);
    }

    using namespace N;

    class Manager
    {
    public:
        void func(bool initializing);

        void mf()
        {
            bind(&Manager::func, this); //C2668
        }
    };
    ```

   Para corrigir o erro, você pode qualificar totalmente a chamada para `bind: N::bind(...)`. No entanto, se essa alteração for manifestada por meio de um identificador não declarado (C2065), poderá ser apropriado corrigir isso com uma declaração **using**.

   Esse padrão acontece frequentemente com ComPtr e com outros tipos no namespace `Microsoft::WRL`.

- **Corrija o endereço incorreto de**

   Agora, o código a seguir produz C2440:  '=': não é possível converter de 'type *' para 'type'. Para corrigir o erro, altere (type) para (type) e (&f()) para (f()).

    ```cpp
    // C
    typedef void (*type)(void);

    void f(int i, type p);
    void g(int);
    void h(void)
    {
        f(0, &(type)g);
    }

    // C++
    typedef void(*type)(void);

    type f();

    void g(type);

    void h()
    {
        g(&f());
    }
    ```

- **O literal de cadeia de caracteres é uma matriz constante**

   Agora, o código a seguir produz C2664: 'void f(void *)': não é possível converter o argumento 1 de 'const char (*) [2]' para 'void *'

    ```cpp
    void f(void *);

    void h(void)
    {
        f(&__FUNCTION__);
        void *p = &"";
    }
    ```

   Para corrigir o erro, altere o tipo de parâmetro de função para `const void*`, caso contrário, altere o corpo de `h` para ter a aparência deste exemplo:

    ```cpp
    void h(void)
    {
        char name[] = __FUNCTION__;
        f( name);
        void *p = &"";
    }
    ```

- **Cadeias de caracteres C++11 UDL**

   Agora, o código a seguir produz o erro C3688: sufixo de literal inválido 'L'; operador literal ou modelo de operador literal 'operator ""L' não encontrado

    ```cpp
    #define MACRO

    #define STRCAT(x, y) x\#\#y

    int main(){

        auto *val1 = L"string"MACRO;
        auto *val2 = L"hello "L"world";

        std::cout << STRCAT(L"hi ", L"there");
    }
    ```

   Para corrigir o erro, altere o código para adicionar um espaço:

    ```cpp
    #define MACRO

    // Remove ##. Strings are automatically
    // concatenated so they aren't needed
    #define STRCAT(x, y) x y

    int main(){
        //Add space after closing quote
        auto *val1 = L"string" MACRO;
        auto *val2 = L"hello " L"world";

        std::cout << STRCAT(L"hi ", L"there");
    }
    ```

   No exemplo acima, `MACRO` não é analisado como dois tokens (uma cadeia de caracteres seguida de uma macro). Agora, é analisado como um único UDL token. O mesmo se aplica a L""L"", que era analisado anteriormente como L"" e L"" e agora é analisado como L""L e "".

   As regras de concatenação de cadeia de caracteres também foram colocadas em conformidade com o padrão, o que significa que L "a" "b" é equivalente a L "ab". As edições anteriores do Visual Studio não aceitavam a concatenação de cadeias de caracteres com larguras de caracteres diferentes.

- **Caractere vazio C++11 removido**

   Agora, o código a seguir produz o erro C2137: constante de caractere vazio

    ```cpp
    bool check(wchar_t c){
        return c == L''; //implicit null character
    }
    ```

   Para corrigir o erro, altere o código para tornar o nulo explícito:

    ```cpp
    bool check(wchar_t c){
        return c == L'\0';
    }
    ```

- **As exceções de MFC não podem ser detectadas pelo valor porque não podem ser copiadas**

   O código a seguir em um aplicativo MFC agora causa o erro C2316: 'D': não pode ser detectado porque o destruidor e/ou o construtor de cópia estão inacessíveis ou foram excluídos

    ```cpp
    struct B {
    public:
        B();
    private:
        B(const B &);
    };

    struct D : public B {
    };

    int main()
    {
        try
        {
        }
        catch (D) // C2316
        {
        }
    }
    ```

   Para corrigir o código, você pode alterar o bloco catch para `catch (const D &)`, mas a melhor solução normalmente é usar as macros MFC TRY/CATCH.

- **alignof agora é uma palavra-chave**

   Agora, o código a seguir produz o erro C2332: 'class': nome de marca ausente. Para corrigir o código, você precisará renomear a classe ou, se a classe estiver executando o mesmo trabalho que **alignof**, basta substituir a classe pela palavra-chave nova.

    ```cpp
    class alignof{}
    ```

- **constexpr agora é uma palavra-chave**

   Agora, o código a seguir produz o erro C2059: erro de sintaxe: ')'. Para corrigir o código, você deve renomear qualquer função ou nomes de variáveis que são chamados de "constexpr".

    ```cpp
    int constexpr() {return 1;}
    ```

- **Tipos que podem ser movidos não podem ser const**

   Quando uma função retorna um tipo que se destina a ser movido, seu tipo de retorno não deve ser **const**.

- **Construtores de cópia excluídos**

   Agora, o código a seguir produz C2280 'S::S(S &&)': tentativa de fazer referência a uma função excluída:

    ```cpp
    struct S{
        S(int, int);
        S(const S&) = delete;
        S(S&&) = delete;
    };

    S s2 = S(2, 3); //C2280
    ```

   Para corrigir o erro, use a inicialização direta para `S2`:

    ```cpp
    struct S{
        S(int, int);
        S(const S&) = delete;
        S(S&&) = delete;
    };

    S s2 = {2,3}; //OK
    ```

- **Conversão em ponteiro de função gerado somente quando não há nenhuma captura de lambda**

   O código a seguir produz C2664 no Visual Studio 2015.

    ```cpp
    void func(int(*)(int)) {}

    int main() {

        func([=](int val) { return val; });
    }
    ```

   Para corrigir o erro, remova o `=` da lista de captura.

- **Chamadas ambíguas que envolvem operadores de conversão**

   Agora, o código a seguir produz o erro C2440: 'type cast': não é possível converter de 'S2' para 'S1':

    ```cpp
    struct S1 {
        S1(int);
    };

    struct S2 {
        operator S1();
        operator int();
    };

    void f(S2 s2)
    {
        (S1)s2;
    }
    ```

   Para corrigir o erro, chame explicitamente o operador de conversão:

    ```cpp
    void f(S2 s2)
    {
        //Explicitly call the conversion operator
        s2.operator S1();
        // Or
        S1((int)s2);
    }
    ```

   Agora, o código a seguir produz o erro C2593: 'operator =' é ambíguo:

    ```cpp
    struct S1 {};

    struct S2 {
        operator S1&();
        operator S1() const;
    };

    void f(S1 *p, S2 s)
    {
        *p = s;
    }
    ```

   Para corrigir o erro, chame explicitamente o operador de conversão:

    ```cpp
    void f(S1 *p, S2 s)
    {
        *p = s.operator S1&();
    }
    ```

- **Corrigir a inicialização de cópia inválida na inicialização de membro de dados não estáticos (NSDMI)**

   Agora, o código a seguir produz o erro C2664: 'S1::S1(S1 &&)': não é possível converter o argumento 1 de 'bool' em 'const S1 &':

    ```cpp
    struct S1 {
        explicit S1(bool);
    };

    struct S2 {
        S1 s2 = true; // error
    };
    ```

   Para corrigir o erro, use a inicialização direta:

    ```cpp
    struct S2 {
    S1 s1{true}; // OK
    };
    ```

- **Acesso aos construtores dentro de instruções decltype**

   Agora, o código a seguir produz C2248: 'S::S': não pode acessar o membro privado declarado na 'S':

    ```cpp
    class S {
        S();
    public:
        int i;
    };

    class S2 {
        auto f() -> decltype(S().i);
    };
    ```

   Para corrigir o erro, adicione uma declaração de amigo para `S2` em `S`:

    ```cpp
    class S {
        S();
        friend class S2; // Make S2 a friend
    public:
        int i;
    };
    ```

- **O construtor padrão de lambda é excluído implicitamente**

   Agora, o código a seguir produz o erro C3497: não é possível construir uma instância de um lambda:

    ```cpp
    void func(){
        auto lambda = [](){};

        decltype(lambda) other;
    }
    ```

   Para corrigir o erro, remova a necessidade de que o construtor padrão seja chamado. Se o lambda não capturar nada, poderá ser convertido em um ponteiro de função.

- **Lambdas com um operador de atribuição excluída**

   Agora, o código a seguir produz o erro C2280:

    ```cpp
    #include <memory>
    #include <type_traits>

    template <typename T, typename D>
    std::unique_ptr<T, typename std::remove_reference<D &&>::type> wrap_unique(T *p, D &&d);

    void f(int i)
    {
        auto encodedMsg = wrap_unique<unsigned char>(nullptr, [i](unsigned char *p) {
        });
        encodedMsg = std::move(encodedMsg);
    }
    ```

   Para corrigir o erro, substitua o lambda por uma classe functor ou remova a necessidade de usar o operador de atribuição.

- **Tentativa de mover um objeto com o construtor de cópia excluído**

   Agora, o código a seguir produz o erro C2280: 'moveable::moveable(const moveable &)': tentativa de fazer referência a uma função excluída

    ```cpp
    struct moveable {

        moveable() = default;
        moveable(moveable&&) = default;
        moveable(const moveable&) = delete;
    };

    struct S {
        S(moveable && m) :
            m_m(m)//copy constructor deleted
        {}
        moveable m_m;
    };
    ```

   Para corrigir o erro, use `std::move` em vez disso:

    ```cpp
    S(moveable && m) :
        m_m(std::move(m))
    ```

- **A classe local não pode fazer referência a outra classe local definida mais tarde na mesma função**

   Agora, o código a seguir produz o erro C2079: 's' usa undefined struct 'main::S2'

    ```cpp
    int main()
    {
        struct S2;
        struct S1 {
            void f() {
                S2 s;
            }
        };
        struct S2 {};
    }
    ```

   Para corrigir o erro, mova a definição de `S2` para cima:

    ```cpp
    int main()
    {
        struct S2 { //moved up
        };

    struct S1 {
        void f() {
            S2 s;
            }
        };
    }
    ```

- **Não é possível chamar um construtor base protegido no corpo do construtor derivado.**

   Agora, o código a seguir produz o erro C2248: 'S1::S1': não é possível acessar membro protegido declarado na classe 'S1'

    ```cpp
    struct S1 {
    protected:
        S1();
    };

    struct S2 : public S1 {
        S2() {
            S1();
        }
    };
    ```

   Para corrigir o erro, em `S2`, remova a chamada para `S1()` do construtor e, se for necessário, coloque-o em outra função.

- **{} impede a conversão em ponteiro**

   Agora, o código a seguir produz C2439 'S::p': não foi possível inicializar o membro

    ```cpp
    struct S {
        S() : p({ 0 }) {}
        void *p;
    };
    ```

   Para corrigir o erro, remova as chaves em torno de `0`. Caso contrário, use **nulo** em vez disso, conforme mostrado neste exemplo:

    ```cpp
    struct S {
        S() : p(nullptr) {}
        void *p;
    };
    ```

- **Definição de macro incorreta e uso com parênteses**

   Agora, o exemplo a seguir produz o erro C2008: ';': inesperado na definição de macro

    ```cpp
    #define A; //cause of error

    struct S {
        A(); // error
    };
    ```

   Para corrigir o problema, altere a linha superior para `#define A();`

   O código a seguir produz o erro C2059: erro de sintaxe: ')'

    ```cpp
    //notice the space after 'A'
    #define A () ;

    struct S {
        A();
    };
    ```

   Para corrigir o código, remova o espaço entre A e ().

   O código a seguir produz o erro C2091: a função retorna a função:

    ```cpp
    #define DECLARE void f()

    struct S {
        DECLARE();
    };
    ```

   Para corrigir o erro, remova os parênteses após DECLARE em S: `DECLARE;`.

   O código a seguir gera o erro C2062: tipo 'int' inesperado

    ```cpp
    #define A (int)

    struct S {
        A a;
    };
    ```

   Para corrigir o problema, defina `A` da seguinte forma:

    ```cpp
    #define A int
    ```

- **Parênteses extras em declarações**

   O código a seguir gera o erro C2062: tipo 'int' inesperado

    ```cpp
    struct S {
        int i;
        (int)j;
    };
    ```

   Para corrigir o erro, remova os parênteses em torno de `j`. Se os parênteses forem necessários para maior clareza, use uma **typedef**.

- **__Declspec(novtable) e construtores gerados pelo compilador**

   No Visual Studio 2015, há uma probabilidade maior de que construtores embutidos gerados pelo compilador de classes abstratas com classes base virtuais exponham o uso inapropriado de `__declspec(novtable)` quando usado em combinação com `__declspec(dllimport)`.

- **auto requer uma expressão única na inicialização de lista direta**

   Agora, o código a seguir produz o erro C3518: 'testPositions': em um contexto de inicialização de lista direta, o tipo 'auto' só pode ser deduzido de uma expressão de inicializador única

    ```cpp
    auto testPositions{
        std::tuple<int, int>{13, 33},
        std::tuple<int, int>{-23, -48},
        std::tuple<int, int>{38, -12},
        std::tuple<int, int>{-21, 17}
    };
    ```

   Para corrigir o erro, uma possibilidade é inicializar `testPositions` da seguinte maneira:

    ```cpp
    std::tuple<int, int> testPositions[]{
        std::tuple<int, int>{13, 33},
        std::tuple<int, int>{-23, -48},
        std::tuple<int, int>{38, -12},
        std::tuple<int, int>{-21, 17}
    };
    ```

- **Verificar tipos versus ponteiros para tipos de is_convertible**

   Agora, o código a seguir faz com que a asserção estática falhe.

    ```cpp
    struct B1 {
    private:
        B1(const B1 &);
    };
    struct B2 : public B1 {};
    struct D : public B2 {};

    static_assert(std::is_convertible<D, B2>::value, "fail");
    ```

   Para corrigir o erro, altere `static_assert` para que ele compare os ponteiros para `D` e `B2`:

    ```cpp
    static_assert(std::is_convertible<D*, B2*>::value, "fail");
    ```

- **declarações de declspec(novtable) precisam ser consistentes**

   Declarações `__declspec` precisam ser consistentes em todas as bibliotecas. Agora, o código a seguir produzirá uma violação de regra de definição de um (ODR):

    ```cpp
    //a.cpp
    class __declspec(dllexport)
        A {
    public:
        A();
        A(const A&);
        virtual ~A();
    private:
        int i;
    };

    A::A() {}
    A::~A() {}
    A::A(const A&) {}

    //b.cpp
    // compile with cl.exe /nologo /LD /EHsc /Osx b.cpp
    #pragma comment(lib, "A")
    class __declspec(dllimport) A
    {
    public: A();
            A(const A&);
            virtual ~A();
    private:
        int i;
    };

    struct __declspec(novtable) __declspec(dllexport) B
        : virtual public A {
        virtual void f() = 0;
    };

    //c.cpp
    #pragma comment(lib, "A")
    #pragma comment(lib, "B")
    class __declspec(dllimport) A
    {
    public:
        A();
        A(const A&);
        virtual ~A();
    private:
        int i;
    };
    struct  /* __declspec(novtable) */ __declspec(dllimport) B // Error. B needs to be novtable here also.
        : virtual public A
    {
        virtual void f() = 0;
    };

    struct C : virtual B
    {
        virtual void f();
    };

    void C::f() {}
    C c;
    ```

###  <a name="VS_Update1"></a> Aprimoramentos de conformidade na Atualização 1

- **Classes base virtuais particulares e herança indireta**

   As versões anteriores do compilador permitiam que uma classe derivada chamasse funções membro de suas classes base `private virtual` derivadas indiretamente. Esse comportamento antigo estava incorreto e não está em conformidade com o padrão C++. O compilador não aceita mais código escrito dessa maneira e emite o erro do compilador C2280 como resultado.

    ```Output
    error C2280: 'void *S3::__delDtor(unsigned int)': attempting to reference a deleted function
    ```

   Exemplo (antes)

    ```cpp
    class base
    {
    protected:
        base();
        ~base();
    };

    class middle : private virtual base {}; class top : public virtual middle {};

    void destroy(top *p)
    {
        delete p;  //
    }
    ```

   Exemplo (depois)

    ```cpp
    class base;  // as above

    class middle : protected virtual base {};
    class top : public virtual middle {};

    void destroy(top *p)
    {
        delete p;
    }
    ```

   \- ou -

    ```cpp
    class base;  // as above

    class middle : private virtual base {};
    class top : public virtual middle, private virtual bottom {};

    void destroy(top *p)
    {
        delete p;
    }
    ```

- **Operador new sobrecarregado e operador delete**

   Versões anteriores do compilador permitiam que o não membro **operator new** e o não membro **operator delete** fossem declarados como estáticos e fossem declarados em namespaces diferentes do namespace global.  Esse comportamento antigo criava um risco de o programa não chamar a implementação do operador **new** ou **delete** pretendida pelo programador, resultando em um comportamento incorreto e silencioso do tempo de execução. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C2323.

    ```Output
    error C2323: 'operator new': non-member operator new or delete functions may not be declared static or in a namespace other than the global namespace.
    ```

   Exemplo (antes)

    ```cpp
    static inline void * __cdecl operator new(size_t cb, const std::nothrow_t&)  // error C2323
    ```

   Exemplo (depois)

    ```cpp
    void * __cdecl operator new(size_t cb, const std::nothrow_t&)  // removed 'static inline'
    ```

   Além disso, embora o compilador não forneça um diagnóstico específico, o operador **new** embutido é considerado malformado.

- **Chamar 'operator *type*()' (conversão definida pelo usuário) em tipos de não classe**

   As versões anteriores do compilador permitiam que o 'operator *type*()' fosse chamado em tipos de não classe ignorando-o silenciosamente. Esse comportamento antigo criava um risco de geração silenciosa de código incorreto, resultando em um comportamento imprevisível do tempo de execução. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C2228.

    ```Output
    error C2228: left of '.operator type' must have class/struct/union
    ```

   Exemplo (antes)

    ```cpp
    typedef int index_t;
    void bounds_check(index_t index);
    void login(int column)
    {
        bounds_check(column.operator index_t());  // error C2228
    }
    ```

   Exemplo (depois)

    ```cpp
    typedef int index_t;
    void bounds_check(index_t index);
    void login(int column)
    {
        bounds_check(column);  // removed cast to 'index_t', 'index_t' is an alias of 'int'
    }
    ```

- **Typename redundante em especificadores de tipo elaborados**

   As versões anteriores do compilador permitiam **typename** em um especificador de tipo elaborado, mas o código escrito dessa maneira é semanticamente incorreto. O compilador não aceita mais código escrito dessa maneira e, em vez disso, emite o erro do compilador C3406.

    ```Output
    error C3406: 'typename' cannot be used in an elaborated type specifier
    ```

   Exemplo (antes)

    ```cpp
    template <typename class T>
    class container;
    ```

   Exemplo (depois)

    ```cpp
    template <class T>  // alternatively, could be 'template <typename T>'; 'typename' is not elaborating a type specifier in this case
    class container;
    ```

- **Dedução de tipo de matrizes de uma lista de inicializadores**

   As versões anteriores do compilador não ofereciam suporte à dedução de tipo de matrizes de uma lista de inicializadores. Agora o compilador oferece suporte a essa forma de dedução de tipo e, como resultado, as chamadas de modelos de função usando listas de inicializadores podem ser ambíguas ou pode ser escolhida uma sobrecarga diferente das versões anteriores do compilador. Para resolver esses problemas, o programa agora deve especificar explicitamente a sobrecarga pretendida pelo programador.

   Quando esse novo comportamento faz com que a resolução de sobrecarga considere um candidato adicional que é igualmente tão bom quanto o candidato histórico, a chamada se torna ambígua e o compilador emite o erro do compilador C2668 como resultado.

    ```Output
    error C2668: 'function' : ambiguous call to overloaded function.
    ```

   Exemplo 1: chamada ambígua à função sobrecarregada (antes)

    ```cpp
    // In previous versions of the compiler, code written in this way would unambiguously call f(int, Args...)
    template < typename... Args>
    void f(int, Args...);  //

    template < int N, typename... Args>
    void f(const int(&)[N], Args...);

    int main()
    {
        // The compiler now considers this call ambiguous, and issues a compiler error
         f({ 3 });   error C2668 : 'f' ambiguous call to overloaded function
    }
    ```

   Exemplo 1: chamada ambígua a função sobrecarregada (depois)

    ```cpp
    template < typename... Args>
    void f(int, Args...);  //

    template < int N, typename... Args>
    void f(const int(&)[N], Args...);

    int main()
    {
        // To call f(int, Args...) when there is just one expression in the initializer list, remove the braces from it.
        f(3);
    }
    ```

   Quando esse novo comportamento faz com que a resolução de sobrecarga considere um candidato adicional que seja uma melhor correspondência que o candidato histórico, a chamada resolve-se, sem ambiguidade, no novo candidato, causando uma alteração no comportamento do programa que é, provavelmente, diferente do que o programador pretendia.

   Exemplo 2: alteração na resolução de sobrecarga (antes)

    ```cpp
    // In previous versions of the compiler, code written in this way would unambiguously call f(S, Args...)
    struct S
    {
        int i;
        int j;
    };

    template < typename... Args>
    void f(S, Args...);

    template < int N, typename... Args>
    void f(const int *&)[N], Args...);

    int main()
    {
        // The compiler now resolves this call to f(const int (&)[N], Args...) instead
         f({ 1, 2 });
    }
    ```

   Exemplo 2: alteração na resolução de sobrecarga (depois)

    ```cpp
    struct S;  // as before

    template < typename... Args>
    void f(S, Args...);

    template < int N, typename... Args>
    void f(const int *&)[N], Args...);

    int main()
    {
        // To call f(S, Args...), perform an explicit cast to S on the initializer list.
        f(S{ 1, 2 });
    }
    ```

- **Restauração de avisos de instrução switch**

   Uma versão anterior do compilador removeu alguns avisos relacionados a instruções **switch**. Esses avisos agora foram restaurados. Agora o compilador emite os avisos restaurados e os avisos relacionados a casos específicos (incluindo o caso padrão) são emitidos na linha que contém o caso com problema, em vez de na última linha da instrução switch. Como resultado da emissão desses avisos em linhas diferentes do que era no passado, os avisos que anteriormente eram suprimidos usando `#pragma warning(disable:####)` não podem mais ser suprimidos como esperado. Para suprimir esses avisos conforme o esperado, talvez seja necessário mover a diretriz `#pragma warning(disable:####)` para uma linha acima do primeiro caso problemático. A seguir estão os avisos restaurados:

    ```Output
    warning C4060: switch statement contains no 'case' or 'default' labels
    ```

    ```Output
    warning C4061: enumerator 'bit1' in switch of enum 'flags' is not explicitly handled by a case label
    ```

    ```Output
    warning C4062: enumerator 'bit1' in switch of enum 'flags' is not handled
    ```

    ```Output
    warning C4063: case 'bit32' is not a valid value for switch of enum 'flags'
    ```

    ```Output
    warning C4064: switch of incomplete enum 'flags'
    ```

    ```Output
    warning C4065: switch statement contains 'default' but no 'case' labels
    ```

    ```Output
    warning C4808: case 'value' is not a valid value for switch condition of type 'bool'
    ```

    ```Output
    Warning C4809: switch statement has redundant 'default' label; all possible 'case' labels are given
    ```

   Exemplo de C4063 (antes)

    ```cpp
    class settings
    {
    public:
        enum flags
        {
            bit0 = 0x1,
            bit1 = 0x2,
            ...
        };
        ...
    };

    int main()
    {
        auto val = settings::bit1;

        switch (val)
        {
        case settings::bit0:
            break;

        case settings::bit1:
            break;

             case settings::bit0 | settings::bit1:  // warning C4063
                break;
        }
    };
    ```

   Exemplo de C4063 (depois)

    ```cpp
    class settings { ... };  // as above
    int main()
    {
        // since C++11, use std::underlying_type to determine the underlying type of an enum
        typedef std::underlying_type< settings::flags> ::type flags_t;

            auto val = settings::bit1;

        switch (static_cast< flags_t> (val))
        {
        case settings::bit0:
            break;

        case settings::bit1:
            break;

        case settings::bit0 | settings::bit1:  // ok
            break;
        }
    };
    ```

   Os exemplos dos outros avisos restaurados são fornecidos em suas respectivas documentações.

- **#include: uso do especificador do diretório pai '..' no nome de caminho** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam o uso do especificador '..' de diretório pai no nome do caminho de diretivas `#include`. O código escrito dessa maneira geralmente se destina a incluir cabeçalhos que existem fora do projeto usando caminhos relativos de projeto de forma incorreta. Esse comportamento antigo criava um risco de que o programa poderia ser compilado pela inclusão de um arquivo de origem diferente do pretendido pelo programador ou desses caminhos relativos não serem portáteis para outros ambientes de build. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C4464 opcional, caso esteja habilitado.

    ```Output
    warning C4464: relative include path contains '..'
    ```

   Exemplo (antes)

    ```cpp
    #include "..\headers\C4426.h"  // emits warning C4464
    ```

   Exemplo (depois)

    ```cpp
    #include "C4426.h"  // add absolute path to 'headers\' to your project's include directories
    ```

   Além disso, embora o compilador não forneça um diagnóstico específico, também é recomendável que o especificador ".." de diretório pai não seja usado para especificar diretórios de inclusão de seu projeto.

- **#pragma optimize() ultrapassa o fim do arquivo de cabeçalho** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam alterações nas configurações de sinalizador de otimização que escapam de um arquivo de cabeçalho incluído em uma unidade de tradução. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C4426 opcional no local do `#include` problemático, caso esteja habilitado. Esse aviso será emitido apenas se as alterações estiverem em conflito com os sinalizadores de otimização definidos por argumentos de linha de comando para o compilador.

    ```Output
    warning C4426: optimization flags changed after including header, may be due to #pragma optimize()
    ```

   Exemplo (antes)

    ```cpp
    // C4426.h
    #pragma optimize("g", off)
    ...
    // C4426.h ends

    // C4426.cpp
    #include "C4426.h"  // warning C4426
    ```

   Exemplo (depois)

    ```cpp
    // C4426.h
    #pragma optimize("g", off)
                ...
    #pragma optimize("", on)  // restores optimization flags set via command-line arguments
    // C4426.h ends

    // C4426.cpp
    #include "C4426.h"
    ```

- **#pragma warning(push)** e **#pragma warning(pop) incompatíveis** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam a combinação de alterações de estado `#pragma warning(push)` com alterações de estado `#pragma warning(pop)` em um arquivo de origem diferente, o que é raramente pretendido. Esse comportamento antigo criava um risco do programa ser compilado com um conjunto de avisos habilitados diferentes do que o programador pretendia, resultando, possivelmente, em comportamento silencioso de tempo de execução incorreto. Agora o compilador detecta e notifica o programador do código escrito dessa maneira e emite um aviso do compilador C5031 opcional no local do `#pragma warning(pop)` correspondente, caso esteja habilitado. Esse aviso inclui uma observação que faz referência ao local do #pragma warning(push) correspondente.

    ```Output
    warning C5031: #pragma warning(pop): likely mismatch, popping warning state pushed in different file
    ```

   Exemplo (antes)

    ```cpp
    // C5031_part1.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    // C5031_part1.h ends without #pragma warning(pop)

    // C5031_part2.h
    ...
    #pragma warning(pop)  // pops a warning state not pushed in this source file
    ...
    // C5031_part1.h ends

    // C5031.cpp
    #include "C5031_part1.h" // leaves #pragma warning(push) 'dangling'
    ...
    #include "C5031_part2.h" // matches 'dangling' #pragma warning(push), resulting in warning C5031
    ...
    ```

   Exemplo (depois)

    ```cpp
    // C5031_part1.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    #pragma warning(pop)  // pops the warning state pushed in this source file
    // C5031_part1.h ends without #pragma warning(pop)

    // C5031_part2.h
    #pragma warning(push)  // pushes the warning state pushed in this source file
    #pragma warning(disable:####)
    ...
    #pragma warning(pop)
    // C5031_part1.h ends

    // C5031.cpp
    #include "C5031_part1.h" // #pragma warning state changes are self-contained and independent of other source files or their #include order.
    ...
    #include "C5031_part2.h"
    ...
    ```

   Embora incomum, às vezes o código é escrito intencionalmente dessa maneira. O código escrito dessa maneira é sensível às alterações na ordem `#include`; quando possível, é recomendável que os arquivos de código-fonte gerenciem o estado de aviso de forma autocontida.

- **#pragma warning(push) sem correspondência** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador não detectavam alterações de estado `#pragma warning(push)` sem correspondência no final de uma unidade de tradução. O compilador agora detecta e notifica o programador sobre código escrito dessa maneira e emite um aviso C5032 opcional do compilador no local do `#pragma warning(push)` sem correspondência, quando habilitado. Esse aviso será emitido somente se não houver erros de compilação na unidade de tradução.

    ```Output
    warning C5032: detected #pragma warning(push) with no corresponding #pragma warning(pop)
    ```

   Exemplo (antes)

    ```cpp
    // C5032.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    // C5032.h ends without #pragma warning(pop)

    // C5032.cpp
    #include "C5032.h"
    ...
    // C5032.cpp ends -- the translation unit is completed without #pragma warning(pop), resulting in warning C5032 on line 1 of C5032.h
    ```

   Exemplo (depois)

    ```cpp
    // C5032.h
    #pragma warning(push)
    #pragma warning(disable:####)
    ...
    #pragma warning(pop) // matches #pragma warning (push) on line 1
    // C5032.h ends

    // C5032.cpp
    #include "C5032.h"
    ...
    // C5032.cpp ends -- the translation unit is completed without unmatched #pragma warning(push)
    ```

- **Avisos adicionais podem ser emitidos como resultado de um controle de estado de aviso #pragma aprimorado**

   As versões anteriores do compilador controlavam as alterações de estado de aviso #pragma de forma insuficientemente adequada para emitir todos os avisos pretendidos. Esse comportamento criava um risco de que certos avisos seriam efetivamente suprimidos em circunstâncias diferentes das que o programador pretendia. Agora o compilador acompanha o estado de `#pragma warning` de uma forma melhor, principalmente com relação às alterações de estado de `#pragma warning` dentro de modelos e, opcionalmente, emite novos avisos C5031 e C5032 para ajudar o programador a localizar usos não intencionais de `#pragma warning(push)` e `#pragma warning(pop)`.

   Como resultado da melhoria do controle de alterações de estado de `#pragma warning`, os avisos que antes eram suprimidos incorretamente ou os avisos relacionados a problemas que eram mal diagnosticados agora podem ser emitidos.

- **Identificação aprimorada de código inacessível**

   As alterações da Biblioteca Padrão do C++ e capacidade aprimorada para chamadas de função embutida em relação às versões anteriores do compilador podem permitir que o compilador comprove que determinado código está inacessível no momento. Esse novo comportamento pode resultar em emissões novas e mais frequentes de instâncias do aviso C4720.

    ```Output
    warning C4720: unreachable code
    ```

   Em muitos casos, esse aviso só pode ser emitido durante a compilação com otimizações habilitadas, já que as otimizações podem embutir mais chamadas de função, eliminar código redundante ou, caso contrário, possibilitar a determinação de que determinado código está inacessível. Observamos que as novas instâncias do aviso C4720 ocorriam frequentemente nos blocos **try/catch**, principalmente em relação ao uso de [std::find](assetId:///std::find?qualifyHint=False&autoUpgrade=True).

   Exemplo (antes)

    ```cpp
    try
    {
        auto iter = std::find(v.begin(), v.end(), 5);
    }
    catch (...)
    {
        do_something();   // ok
    }
    ```

   Exemplo (depois)

    ```cpp
    try
    {
        auto iter = std::find(v.begin(), v.end(), 5);
    }
    catch (...)
    {
        do_something();   // warning C4702: unreachable code
    }
    ```

###  <a name="VS_Update2"></a> Aprimoramentos de conformidade na Atualização 2

- **Erros e avisos adicionais podem ser emitidos como resultado do suporte parcial à expressão SFINAE**

   As versões anteriores do compilador não analisavam determinados tipos de expressões dentro de especificadores **decltype** devido à falta de suporte para a expressão SFINAE. Esse comportamento antigo estava incorreto e não está em conformidade com o padrão C++. Agora o compilador analisa essas expressões e tem suporte parcial à expressão SFINAE devido às melhorias contínuas de conformidade. Como resultado, o compilador emite avisos e erros encontrados nas expressões que as versões anteriores do compilador não analisavam.

   Quando esse novo comportamento analisa uma expressão **decltype** que inclui um tipo que ainda não foi declarado, o compilador emite o erro do compilador C2039 como resultado.

    ```Output
    error C2039: 'type': is not a member of '`global namespace''
    ```

   Exemplo 1: uso de um tipo não declarado (antes)

    ```cpp
    struct s1
    {
        template < typename T>
        auto f() - > decltype(s2< T> ::type::f());  // error C2039

        template< typename>
        struct s2 {};
    }
    ```

   Exemplo 1 (depois)

    ```cpp
    struct s1
    {
        template < typename>  // forward declare s2struct s2;

            template < typename T>
        auto f() - > decltype(s2< T> ::type::f());

        template< typename>
        struct s2 {};
    }
    ```

   Quando esse novo comportamento analisa uma expressão **decltype** na qual está ausente um uso necessário da palavra-chave **typename** para especificar que um nome dependente é um tipo, o compilador emite o aviso do compilador C4346 junto com o erro do compilador C2923.

    ```Output
    warning C4346: 'S2<T>::Type': dependent name is not a type
    ```

    ```Output
    error C2923: 's1': 'S2<T>::Type' is not a valid template type argument for parameter 'T'
    ```

   Exemplo 2: o nome dependente não é um tipo (antes)

    ```cpp
    template < typename T>
    struct s1
    {
        typedef T type;
    };

    template < typename T>
    struct s2
    {
        typedef T type;
    };

    template < typename T>
    T declval();

    struct s
    {
        template < typename T>
        auto f(T t) - > decltype(t(declval< S1< S2< T> ::type> ::type> ()));  // warning C4346, error C2923
    };
    ```

   Exemplo 2 (depois)

    ```cpp
    template < typename T> struct s1 { ... };  // as above
    template < typename T> struct s2 { ... };  // as above

    template < typename T>
    T declval();

    struct s
    {
        template < typename T>
        auto f(T t) - > decltype(t(declval< S1< typename S2< T> ::type> ::type> ()));
    };
    ```

- `volatile` **variáveis de membro impedem construtores e operadores de atribuição implicitamente definidos**

   As versões anteriores do compilador permitiam que uma classe que tem variáveis de membro **volatile** tivesse construtores padrão copiar/mover e operadores de atribuição padrão copiar/mover gerados automaticamente. Esse comportamento antigo estava incorreto e não está em conformidade com o padrão C++. Agora, o compilador considera que uma classe que tem variáveis de membro **volatile** tenha operadores de construção e de atribuição não triviais que impedem que as implementações padrão desses operadores sejam geradas automaticamente. Quando essa classe for um membro de uma união (ou uma união anônima dentro de uma classe), os construtores copiar/mover e os operadores de atribuição copiar/mover da união (ou a classe que contém a união anônima) serão implicitamente definidos como excluídos. A tentativa de construir ou copiar a união (ou a classe que contém a união anônima) sem defini-los explicitamente é um erro e o compilador emitirá um erro de compilador C2280 como resultado.

    ```Output
    error C2280: 'B::B(const B &)': attempting to reference a deleted function
    ```

   Exemplo (antes)

    ```cpp
    struct A
    {
        volatile int i;
        volatile int j;
    };

    extern A* pa;

    struct B
    {
        union
        {
            A a;
            int i;
        };
    };

    B b1{ *pa };
    B b2(b1);  // error C2280
    ```

   Exemplo (depois)

    ```cpp
    struct A
    {
        int i; int j;
    };

    extern volatile A* pa;

    A getA()  // returns an A instance copied from contents of pa
    {
        A a;
        a.i = pa - > i;
        a.j = pa - > j;
        return a;
    }

    struct B;  // as above

    B b1{ GetA() };
    B b2(b1);  // error C2280
    ```

- **Funções de membro estático não dão suporte a qualificadores cv.**

   As versões anteriores do Visual Studio 2015 permitiam que funções de membro estático tivessem qualificadores cv. Esse comportamento era devido a uma regressão no Visual Studio 2015 e no Visual Studio 2015 Atualização 1. O Visual Studio 2013 e as versões anteriores do compilador rejeitam o código escrito dessa maneira. O comportamento do Visual Studio 2015 e do Visual Studio 2015 Atualização 1 está incorreto e não está em conformidade com o padrão C++.  O Visual Studio 2015 Atualização 2 rejeita o código escrito dessa maneira e, em vez disso, emite o erro do compilador C2511.

    ```Output
    error C2511: 'void A::func(void) const': overloaded member function not found in 'A'
    ```

   Exemplo (antes)

    ```cpp
    struct A
    {
        static void func();
    };

    void A::func() const {}  // C2511
    ```

   Exemplo (depois)

    ```cpp
    struct A
    {
        static void func();
    };

    void A::func() {}  // removed const
    ```

- **A declaração de encaminhamento de enum não é permitida no código do WinRT** (afeta apenas `/ZW`)

   O código compilado para o WinRT (Windows Runtime) não permite que tipos **enum** sejam declarados como de encaminhamento, de forma semelhante a quando o código C++ gerenciado é compilado para o .NET Framework usando a opção de compilador `/clr`. Esse comportamento garante que o tamanho de uma enumeração seja sempre conhecido e seja projetado corretamente para o sistema de tipos WinRT. O compilador rejeita o código escrito dessa maneira e emite um erro do compilador C2599 junto com o erro do compilador C3197.

    ```Output
    error C2599: 'CustomEnum': the forward declaration of a WinRT enum is not allowed
    ```

    ```Output
    error C3197: 'public': can only be used in definitions
    ```

   Exemplo (antes)

    ```cpp
    namespace A {
        public enum class CustomEnum : int32;  // forward declaration; error C2599, error C3197
    }

    namespace A {
        public enum class CustomEnum : int32
        {
            Value1
        };
    }

    public ref class Component sealed
    {
    public:
        CustomEnum f()
        {
            return CustomEnum::Value1;
        }
    };
    ```

   Exemplo (depois)

    ```cpp
              // forward declaration of CustomEnum removed
    namespace A {
        public enum class CustomEnum : int32
        {
            Value1
        };
    }

    public ref class Component sealed
    {
    public:
        CustomEnum f()
        {
            return CustomEnum::Value1;
        }
    };
    ```

- **Operador new de não membro sobrecarregado e operador delete não podem ser declarados embutidos** (Nível 1 (`/W1`) ativado por padrão)

   As versões anteriores do compilador não emitem um aviso quando o operador new de não membro e as funções do operador delete são declarados embutidos. O código escrito dessa maneira é mal formado (não é necessário nenhum diagnóstico) e pode causar problemas de memória resultantes de operadores new e delete incompatíveis (especialmente quando usado em conjunto com desalocação dimensionada) que podem ser difíceis de diagnosticar. Agora o compilador emite o aviso do compilador C4595 para ajudar a identificar o código escrito dessa forma.

    ```Output
    warning C4595: 'operator new': non-member operator new or delete functions may not be declared inline
    ```

   Exemplo (antes)

    ```cpp
    inline void* operator new(size_t sz)  // warning C4595
    {
        ...
    }
    ```

   Exemplo (depois)

    ```cpp
    void* operator new(size_t sz)  // removed inline
    {
        ...
    }
    ```

   A correção do código escrito dessa maneira pode exigir que as definições de operador sejam retiradas de um arquivo de cabeçalho e movidas para um arquivo de origem correspondente.

###  <a name="VS_Update3"></a> Aprimoramentos de conformidade na Atualização 3

- **std::is_convertable agora detecta a autoatribuição** (biblioteca padrão)

   As versões anteriores das característica de tipo `std::is_convertable` não detectavam corretamente a autoatribuição de um tipo de classe quando seu construtor de cópia era excluído ou particular. Agora, `std::is_convertable<>::value` é definido corretamente como **false** quando aplicado a um tipo de classe com um construtor de cópia particular ou excluído.

   Não há nenhum diagnóstico de compilador associado a essa alteração.

   Exemplo

    ```cpp
    #include <type_traits>

    class X1
    {
                public:
                X1(const X1&) = delete;
                };

    class X2
    {
                private:
                X2(const X2&);
                };

    static_assert(std::is_convertible<X1&, X1>::value, "BOOM");static_assert(std::is_convertible<X2&, X2>::value, "BOOM");
    ```

   Nas versões anteriores do compilador, as asserções estáticas na parte inferior deste exemplo passam porque `std::is_convertable<>::value` era definido incorretamente como **true**. Agora, `std::is_convertable<>::value` é definido corretamente como **false**, fazendo com que as asserções estáticas falhem.

- **Construtores triviais de cópia e movimentação padronizados ou excluídos respeitam especificadores de acesso**

   As versões anteriores do compilador não verificavam o especificador de acesso dos construtores triviais de cópia e movimentação padronizados ou excluídos antes de permitir que fossem chamados. Esse comportamento antigo estava incorreto e não está em conformidade com o padrão C++. Em alguns casos, esse comportamento antigo criava um risco de geração silenciosa de código incorreto, resultando em um comportamento imprevisível do tempo de execução. Agora o compilador verifica o especificador de acesso dos construtores triviais de cópia e movimentação padronizados ou excluídos para determinar se podem ser chamados e se não puderem, emite um aviso do compilador C2248 como resultado.

    ```Output
    error C2248: 'S::S' cannot access private member declared in class 'S'
    ```

   Exemplo (antes)

    ```cpp
    class S {
    public:
        S() = default;
    private:
        S(const S&) = default;
    };

    void f(S);  // pass S by value

    int main()
    {
        S s;
        f(s);  // error C2248, can't invoke private copy constructor
    }
    ```

   Exemplo (depois)

    ```cpp
    class S {
    public:
        S() = default;
    private:
        S(const S&) = default;
    };

    void f(const S&);  // pass S by reference

    int main()
    {
        S s;
        f(s);
    }
    ```

- **Preterimento do suporte a código ATL atribuído** (Nível 1 [`/W1`] ativado por padrão)

   As versões anteriores do compilador ofereciam suporte ao código ATL atribuído. Como um passo seguinte da remoção do suporte ao código ATL atribuído que [começou no Visual Studio 2008](https://msdn.microsoft.com/library/bb384632), o código ATL atribuído foi preterido. Agora o compilador emite o aviso do compilador C4467 para ajudar a identificar esse tipo de código preterido.

    ```Output
    warning C4467: Usage of ATL attributes is deprecated
    ```

   Se você deseja continuar usando o código ATL atribuído até que o suporte seja removido do compilador, você pode desabilitar esse aviso passando os argumentos de linha de comando `/Wv:18` ou `/wd:4467` para o compilador ou adicionando `#pragma warning(disable:4467)` em seu código-fonte.

   Exemplo 1 (antes)

    ```cpp
              [uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")]
    class A {};
    ```

   Exemplo 1 (depois)

    ```cpp
    __declspec(uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")) A {};
    ```

   Talvez você queira ou seja necessário criar um arquivo IDL para evitar o uso de atributos ATL preteridos, como no código de exemplo abaixo

   Exemplo 2 (antes)

    ```cpp
    [emitidl];
    [module(name = "Foo")];

    [object, local, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb")]
    __interface ICustom {
        HRESULT Custom([in] long l, [out, retval] long *pLong);
        [local] HRESULT CustomLocal([in] long l, [out, retval] long *pLong);
    };

    [coclass, appobject, uuid("9e66a294-4365-11d2-a997-00c04fa37ddb")]
    class CFoo : public ICustom
    {
        // ...
    };
    ```

   Primeiro, crie o arquivo *.idl; o arquivo vc140.idl gerado pode ser usado para obter um arquivo \*.idl que contém as interfaces e as anotações.

   Em seguida, adicione uma etapa MIDL ao seu build para certificar-se de que as definições de interface de C++ são geradas.

   Exemplo 2 IDL (depois)

    ```cpp
    import "docobj.idl";

    [
        object, local, uuid(9e66a290 - 4365 - 11d2 - a997 - 00c04fa37ddb)
    ]

    interface ICustom : IUnknown {
        HRESULT  Custom([in] long l, [out, retval] long *pLong);
        [local] HRESULT  CustomLocal([in] long l, [out, retval] long *pLong);
    };

    [version(1.0), uuid(29079a2c - 5f3f - 3325 - 99a1 - 3ec9c40988bb)]
    library Foo
    {
        importlib("stdole2.tlb");
    importlib("olepro32.dll");
    [
        version(1.0),
        appobject,uuid(9e66a294 - 4365 - 11d2 - a997 - 00c04fa37ddb)
    ]

    coclass CFoo {
        interface ICustom;
    };
    }
    ```

   Em seguida, use a ATL diretamente no arquivo de implementação, como no código de exemplo abaixo.

   Exemplo 2 Implementação (Depois)

    ```cpp
    #include <idl.header.h>
    #include <atlbase.h>

    class ATL_NO_VTABLE CFooImpl :
        public ICustom,
        public ATL::CComObjectRootEx< CComMultiThreadModel>
    {
    public:
        BEGIN_COM_MAP(CFooImpl)
            COM_INTERFACE_ENTRY(ICustom)
        END_COM_MAP()
    };
    ```

- **Arquivos de PCH (cabeçalho pré-compilado) e diretivas #include incompatíveis** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador aceitavam diretivas `#include` incompatíveis em arquivos de origem entre compilações `-Yc` e `-Yu` ao usar arquivos de PCH (cabeçalho pré-compilado). O código escrito dessa maneira não é mais aceito pelo compilador.   Agora o compilador emite o aviso do compilador CC4598 para ajudar a identificar diretivas `#include` incompatíveis ao usar arquivos de PCH.

    ```Output
    warning C4598: 'b.h': included header file specified for Ycc.h at position 2 does not match Yuc.h at that position
    ```

   Exemplo (antes):

   X.cpp (-Ycc.h)

    ```cpp
    #include "a.h"
    #include "b.h"
    #include "c.h"
    ```

   Z.cpp (-Yuc.h)

    ```cpp
    #include "b.h"
    #include "a.h"  // mismatched order relative to X.cpp
    #include "c.h"
    ```

   Exemplo (depois)

   X.cpp (-Ycc.h)

    ```cpp
    #include "a.h"
    #include "b.h"
    #include "c.h"
    ```

   Z.cpp (-Yuc.h)

    ```cpp
    #include "a.h"
    #include "b.h" // matched order relative to X.cpp
    #include "c.h"
    ```

- **Arquivos de PCH (cabeçalho pré-compilado) e diretórios #include incompatíveis** (afeta apenas `/Wall` `/WX`)

   As versões anteriores do compilador aceitavam argumentos de linha de comando de diretórios de inclusão incompatíveis (`-I`) para o compilador entre compilações `-Yc` e `-Yu` ao usar arquivos de PCH (cabeçalho pré-compilado). O código escrito dessa maneira não é mais aceito pelo compilador. Agora o compilador emite o aviso do compilador CC4599 para ajudar a identificar argumentos de linha de comando de diretórios de inclusão incompatíveis (`-I`) ao usar arquivos de PCH.

    ```Output
    warning C4599: '-I..' : specified for Ycc.h at position 1 does not match Yuc.h at that position
    ```

   Exemplo (antes)

    ```ms-dos
    cl /c /Wall /Ycc.h -I.. X.cpp
    cl /c /Wall /Yuc.h Z.cpp
    ```

   Exemplo (depois)

    ```ms-dos
    cl /c /Wall /Ycc.h -I.. X.cpp
    cl /c /Wall /Yuc.h -I.. Z.cpp
    ```

## <a name="visual-studio-2013-conformance-changes"></a>Alterações de conformidade do Visual Studio 2013

### <a name="compiler"></a>Compilador

- A palavra-chave **final** agora gera um erro de símbolo não resolvido no local em que ela seria compilada anteriormente:

    ```cpp
    struct S1 {
        virtual void f() = 0;
    };

    struct S2 final : public S1 {
        virtual void f();
    };

    int main(S2 *p)
    {
        p->f();
    }
    ```

   Nas versões anteriores, um erro não era emitido porque a chamada era **virtual**; no entanto, podia haver pane do programa no tempo de execução. Agora, um erro de vinculador é emitido porque a classe é conhecida como final. Neste exemplo, para corrigir o erro, você faria um vínculo com o objeto que contém a definição de `S2::f`.

- Ao usar funções friend em namespaces, você deve declarar novamente a função friend antes de fazer referência a ela ou um erro será obtido, pois o compilador agora está de acordo com o ISO C++ Standard. Por exemplo, esse código não compila mais:

    ```cpp
    namespace NS {
        class C {
            void func(int);
            friend void func(C* const) {}
        };

        void C::func(int) {
            NS::func(this);  // error
        }
    }
    ```

   Para corrigir esse código, declare a função **friend**:

    ```cpp
    namespace NS {
        class C {
            void func(int);
            friend void func(C* const) {}
        };

        void func(C* const);  // conforming fix

        void C::func(int) {
            NS::func(this);
        }
    ```

- O C++ Standard não permite a especialização explícita em uma classe. Embora o compilador do Microsoft Visual C++ permita isso em alguns casos, em casos como no exemplo a seguir, um erro será gerado porque o compilador não considera a segunda função como sendo uma especialização da primeira.

    ```cpp
    template < int N>
    class S {
    public:
        template  void f(T& val);
        template < > void f(char val);
    };

    template class S< 1>;
    ```

   Para corrigir esse código, modifique a segunda função:

    ```cpp
    template <> void f(char& val);
    ```

- O compilador não tenta mais remover a ambiguidade das duas funções no exemplo a seguir e agora emite um erro:

    ```cpp
    template< typename T> void Func(T* t = nullptr);
    template< typename T> void Func(...);

    int main() {
        Func< int>(); // error
    }
    ```

   Para corrigir esse código, esclareça a chamada:

    ```cpp
    template< typename T> void Func(T* t = nullptr);
    template< typename T> void Func(...);

    int main() {
        Func< int>(nullptr); // ok
    }
    ```

- Antes de fazer com que o compilador ficasse em conformidade com o ISO C++11, o seguinte código seria compilado e faria com que `x` fosse resolvido para o tipo **int**:

    ```cpp
    auto x = {0};
    int y = x;
    ```

   Esse código agora resolve `x` para um tipo de `std::initializer_list<int>` e causa um erro na próxima linha que tenta atribuir `x` ao tipo **int**. (Não há nenhuma conversão por padrão.) Para corrigir esse código, use **int** para substituir **auto**:

    ```cpp
    int x = {0};
    int y = x;
    ```

- A inicialização de agregação não é mais permitida quando o tipo do valor do lado direito não corresponde ao tipo do valor do lado esquerdo que está sendo inicializado e um erro é emitido porque o ISO C++11 Standard exige inicialização uniforme para funcionar sem conversões redutoras. Antes, se uma conversão redutora estivesse disponível, um [Aviso do Compilador (nível 4) C4242](../error-messages/compiler-warnings/compiler-warning-level-4-c4242.md) seria emitido e não um erro.

    ```cpp
    int i = 0;
    char c = {i}; // error
    ```

   Para corrigir esse código, adicione uma conversão de redução explícita:

    ```cpp
    int i = 0;
    char c = {static_cast<char>(i)};
    ```

- A seguinte inicialização não é mais permitida:

    ```cpp
    void *p = {{0}};
    ```

   Para corrigir esse código, use qualquer uma destas formas:

    ```cpp
    void *p = 0;
    // or
    void *p = {0};
    ```

- O nome da pesquisa foi alterada. O código a seguir é resolvido de forma diferente no compilador C++ no Visual Studio 2012 e no Visual Studio 2013:

    ```cpp
    enum class E1 { a };
    enum class E2 { b };

    int main()
    {
        typedef E2 E1;
        E1::b;
    }
    ```

   No Visual Studio 2012, o `E1` na expressão `E1::b` é resolvido para `::E1` no escopo global. No Visual Studio 2013, `E1` na expressão `E1::b` é resolvido para a definição `typedef E2` em `main()` e tem o tipo `::E2`.

- O layout do objeto foi alterado. No x64, o layout do objeto de uma classe pode ser alterado em relação às versões anteriores. Se ele tiver uma função **virtual**, mas não tiver uma classe base que tenha uma função **virtual**, o modelo de objeto do compilador inserirá um ponteiro em uma tabela de função **virtual** após o layout do membro de dados. Isso significa que o layout pode não ser ideal em todos os casos. Em versões anteriores, uma otimização para o x64 tentaria melhorar o layout para você, mas como ela falhou em funcionar corretamente em situações de código complexas, ela foi removida no Visual Studio 2013. Por exemplo, pense neste código:

    ```cpp
    __declspec(align(16)) struct S1 {
    };

    struct S2 {
        virtual ~S2();
        void *p;
        S1 s;
    };
    ```

- No Visual Studio 2013, o resultado de `sizeof(S2)` no x64 é 48, mas em versões anteriores, ele era avaliado como 32. Para fazer com que ele seja avaliado como 32 no compilador C++ no Visual Studio 2013 para x64, adicione uma classe base fictícia que tenha uma função **virtual**:

    ```cpp
    __declspec(align(16)) struct S1 {
    };

    struct dummy {
        virtual ~dummy() {}
    };
    struct S2 : public dummy {
        virtual ~S2();
        void *p;
        S1 s;
    };
    ```

   Para encontrar locais no seu código que uma versão anterior tentou otimizar, use um compilador dessa versão juntamente com a opção de compilador `/W3` e ative o Aviso 4370. Por exemplo:

    ```cpp
    #pragma warning(default:4370)

    __declspec(align(16)) struct S1 {
    };

    struct S2 {
        virtual ~S2();
        void *p;
        S1 s;
    };
    ```

   Antes do Visual Studio 2013, esse código gera esta mensagem: "aviso C4370: 'S2': layout da classe foi alterado de uma versão anterior do compilador devido ao melhor empacotamento".

   O compilador x86 tem o mesmo problema de layout de qualidade inferior em todas as versões do compilador. Por exemplo, se este código foi compilado por x86:

    ```cpp
    struct S {
        virtual ~S();
        int i;
        double d;
    };
    ```

   O resultado de `sizeof(S)` será 24. No entanto, isso poderá ser reduzido para 16 se você usar a solução alternativa mencionada para x64:

    ```cpp
    struct dummy {
        virtual ~dummy() {}
    };

    struct S : public dummy {
        virtual ~S();
        int i;
        double d;
    };
    ```

### <a name="standard-library"></a>Biblioteca Padrão

O compilador C++ no Visual Studio 2013 detecta incompatibilidades em _ITERATOR_DEBUG_LEVEL, que foi implementado no Visual Studio 2010, bem como incompatibilidades de RuntimeLibrary. Essas incompatibilidades ocorrem quando as opções de compilador `/MT` (versão estática), `/MTd` (depuração estática), `/MD` (versão dinâmica) e `/MDd` (depuração dinâmica) são combinadas.

- Se seu código reconhecer os modelos de alias simulados da versão anterior, você terá que alterá-lo. Por exemplo, em vez de `allocator_traits<A>::rebind_alloc<U>::other`, agora você precisa expressar `allocator_traits<A>::rebind_alloc<U>`. Embora `ratio_add<R1, R2>::type` agora não seja mais necessário e seja recomendado que você explicite `ratio_add<R1, R2>`, o antigo ainda será compilado porque é obrigatório que `ratio<N, D>` tenha um "tipo" typedef para um índice reduzido, que será o mesmo tipo se já tiver sido reduzido.

- Você deve usar `#include <algorithm>` ao chamar `std::min()` ou `std::max()`.

- Se o seu código existente usa enumerações com escopo simuladas da versão anterior — enumerações sem escopo tradicionais envolvidas em namespaces — será necessário alterá-lo. Por exemplo, se você fez referência ao tipo `std::future_status::future_status`, agora é preciso expressar `std::future_status`. No entanto, a maioria dos códigos não é afetada, por exemplo, `std::future_status::ready` ainda é compilado.

- `explicit operator bool()` é mais estrito que o operador unspecified-bool-type(). `explicit operator bool()` permite conversões explícitas para bool – por exemplo, dado `shared_ptr<X> sp`, `static_cast<bool>(sp)` e `bool b(sp)` são válidos – e "conversões contextuais" testáveis por booliano para bool – por exemplo, `if (sp)`, `!sp`, `sp &&`. No entanto, `explicit operator bool()` proíbe conversões implícitas para bool, portanto, você não pode expressar `bool b = sp;` e, dado um tipo de retorno bool, você não pode expressar `return sp`.

- Agora que os modelos reais variadic estão implementados, _VARIADIC_MAX e as macros relacionadas não têm efeito. Se você ainda estiver definindo _VARIADIC_MAX, ele será ignorado. Se você reconheceu a maquinaria da macro com suporte a modelos variadic simulados de qualquer outra maneira, será preciso modificar seu código.

- Além de palavras-chave comuns, os cabeçalhos da Biblioteca do C++ Standard agora proíbem a substituição de macros das palavras-chave **override** e **final** sensíveis ao contexto.

- `reference_wrapper`, `ref()` e `cref()` agora proíbem a associação a objetos temporários.

- \<random> agora impõe rigidamente suas pré-condições de tempo de compilação.

- Diversas características de tipo da Biblioteca Padrão do C++ têm a pré-condição "T deve ser um tipo completo". Embora o compilador agora imponha isso de forma mais rígida, essa pré-condição não pode ser imposta em todas as situações. (Como as violações de pré-condição da Biblioteca Padrão do C++ disparam o comportamento indefinido, o Padrão não assegura a imposição.)

- A Biblioteca do C++ Standard não dá suporte a `/clr:oldSyntax`.

- A especificação C++11 para common_type<> teve consequências inesperadas e indesejadas. Particularmente, ela faz common_type\<int, int>::type retornar int&&. Portanto, o compilador implementa a publicação 2141 da Resolução proposta para o grupo de trabalho de bibliotecas, que faz common_type\<int, int="">::type retornar int.

   Como um efeito colateral dessa alteração, o caso de identidade não funciona mais (common_type\<T> nem sempre resulta no tipo T). Esse comportamento segue a resolução proposta, mas interrompe qualquer código que depende do comportamento anterior.

   Se você exigir uma característica de tipo de identidade, não use o `std::identity` não padrão definido em \<, pois ele não funcionará para \<void>. Em vez disso, implemente sua própria característica de tipo de identidade para atender às suas necessidades. Veja um exemplo:

    ```cpp
    template < typename T> struct Identity {
        typedef T type;
    };
    ```

### <a name="mfc-and-atl"></a>MFC e ATL

- **Apenas Visual Studio 2013**: A Biblioteca MFC MBCS não está incluída no Visual Studio porque o Unicode é muito popular e o uso de MBCS foi significativamente reduzido. Essa alteração também mantém o MFC alinhado de forma mais próxima ao próprio Windows SDK, uma vez que vários dos controles e mensagens novos são somente Unicode. No entanto, se for preciso continuar usando a biblioteca MFC MBCS, você poderá baixá-la no Centro de Download do MSDN em [Multibyte MFC Library for Visual Studio 2013](https://www.microsoft.com/download/details.aspx?id=40770) (Biblioteca MFC multibyte para Visual Studio 2013). O Pacote Redistribuível do Visual C++ ainda inclui esta biblioteca.  (Observação: a DLL do MBCS está incluída nos componentes de instalação do C++ no Visual Studio 2015 e posteriores).

- A acessibilidade para a faixa de opções do MFC foi alterada.  Em vez de uma arquitetura de um nível, há agora uma arquitetura hierárquica. Você ainda pode usar o comportamento antigo chamando `CRibbonBar::EnableSingleLevelAccessibilityMode()`.

- O método `CDatabase::GetConnect` foi removido. Para melhorar a segurança, a cadeia de conexão agora é armazenada criptografada e é descriptografada somente quando necessário; ela não pode ser retornada como texto sem formatação.  A cadeia de caracteres pode ser obtida usando o método `CDatabase::Dump`.

- A assinatura de `CWnd::OnPowerBroadcast` foi alterada. A assinatura desse manipulador de mensagens foi alterada para obter um LPARAM como o segundo parâmetro.

- As assinaturas são alteradas para acomodar manipuladores de mensagens. As listas de parâmetros das seguintes funções foram alteradas para usar manipuladores de mensagens ON_WM_* recém-adicionados:

   - `CWnd::OnDisplayChange` foi alterado para (UINT, int, int) em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_DISPLAYCHANGE possa ser usada no mapa de mensagens.

   - `CFrameWnd::OnDDEInitiate` foi alterado para (CWnd*, UINT, UNIT) em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_DDE_INITIATE possa ser usada no mapa de mensagens.

   - `CFrameWnd::OnDDEExecute` foi alterado para (CWnd*, HANDLE) em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_DDE_EXECUTE possa ser usada no mapa de mensagens.

   - `CFrameWnd::OnDDETerminate` foi alterado para (CWnd*) como o parâmetro, em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_DDE_TERMINATE possa ser usada no mapa de mensagens.

   - `CMFCMaskedEdit::OnCut` foi alterado para sem parâmetros em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_CUT possa ser usada no mapa de mensagens.

   - `CMFCMaskedEdit::OnClear` foi alterado para sem parâmetros em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_CLEAR possa ser usada no mapa de mensagens.

   - `CMFCMaskedEdit::OnPaste` foi alterado para sem parâmetros em vez de (WPARAM, LPARAM) para que a nova macro ON_WM_PASTE possa ser usada no mapa de mensagens.

- As diretivas `#ifdef` nos arquivos de cabeçalho MFC foram removidas. Várias diretivas `#ifdef` nos arquivos de cabeçalho MFC relacionados a versões sem suporte do Windows (WINVER &lt; 0x0501) foram removidas.

- ATL DLL (atl120.dll) foi removida. A ATL agora é fornecida como cabeçalhos e uma biblioteca estática (atls.lib).

- Atlsd.lib, atlsn.lib e atlsnd.lib foram removidas. Atls.lib não tem dependências ou código de conjunto de caracteres que seja específico para a depuração/versão. Como ela funciona da mesma forma para Unicode/ANSI e depuração/versão, somente uma versão da biblioteca é necessária.

- A ferramenta Rastreamento de ATL/MFC foi removida com a ATL DLL e o mecanismo de rastreamento foi simplificado. O construtor `CTraceCategory` agora usa um parâmetro (o nome da categoria) e as macros TRACE chamam as funções de relatório de depuração de CRT.

## <a name="visual-c-2012-breaking-changes"></a>Alterações significativas do Visual C++ 2012

### <a name="compiler"></a>Compilador

- A opção do compilador `/Yl` foi alterada. Por padrão, o compilador usa essa opção, o que pode levar a erros LNK2011 em determinadas condições. Para obter mais informações, consulte [/Yl (Injetar referência de PCH para Biblioteca de Depuração)](../build/reference/yl-inject-pch-reference-for-debug-library.md).

- No código que é compilado usando `/clr`, a palavra-chave de classe **enum** define uma enumeração de C++11 e não uma enumeração de CLR (Common Language Runtime). Para definir um enum de CLR, você deve ser explícito sobre sua acessibilidade.

- Use a palavra-chave do modelo para remover a ambiguidade explicitamente de um nome dependente (conformidade com o Padrão de Linguagem C++). No exemplo a seguir, a palavra-chave realçada do modelo é obrigatória para resolver a ambiguidade. Para obter mais informações, consulte [Resolução de nomes de tipos dependentes](../cpp/name-resolution-for-dependent-types.md).

    ```cpp
    template < typename X = "", typename = "" AY = "">
    struct Container { typedef typename AY::template Rebind< X> ::Other AX; };
    ```

- A expressão constante de tipo float não é mais permitida como um argumento de modelo, conforme mostrado no exemplo a seguir.

    ```cpp
    template<float n=3.14>
    struct B {};  // error C2993: 'float': illegal type for non-type template parameter 'n'
    ```

- O código que é compilado usando a opção de linha de comando `/GS` e que tenha uma vulnerabilidade off-by-one pode levar à finalização do processo em tempo de execução, conforme mostrado no exemplo de pseudocódigo a seguir.

    ```cpp
    char buf[MAX]; int cch; ManipulateString(buf, &cch); // ... buf[cch] = '\0'; // if cch >= MAX, process will terminate
    ```

- A arquitetura padrão para compilações x86 é alterada para SSE2. Portanto, o compilador pode emitir instruções SSE e usará os registros XMM para executar cálculos de ponto flutuante. Se você quiser reverter para o comportamento anterior, use o sinalizador de compilador `/arch:IA32` para especificar a arquitetura como IA32.

- O compilador pode emitir avisos [Aviso do Compilador (nível 4) C4703](../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md) e C4701 quando anteriormente não emitia. O compilador aplica verificações mais fortes para o uso de variáveis locais não inicializadas do tipo ponteiro.

- Quando o novo sinalizador de vinculador `/HIGHENTROPYVA` é especificado, o Windows 8 geralmente faz com que as alocações de memória retornem um endereço de 64 bits. (Antes do Windows 8, essas alocações retornavam, com mais frequência, endereços que eram menores que 2 GB). Essa alteração pode expor bugs de truncamento de ponteiro no código existente. Por padrão, essa opção está ativada. Para desabilitar esse comportamento, especifique `/HIGHENTROPYVA:NO`.

- O compilador gerenciado (Visual Basic/C#) também dá suporte a `/HIGHENTROPYVA` para builds gerenciados.  No entanto, nesse caso, a opção `/HIGHENTROPYVAswitch` está desativada por padrão.

### <a name="ide"></a>IDE

- Apesar de recomendarmos que você não crie Aplicativos do Windows Forms em C++/CLI, há suporte para a manutenção de aplicativos de interface do usuário de C++/CLI existentes. Se você tiver que criar um Aplicativo do Windows Forms ou qualquer outro aplicativo de interface do usuário do .NET, use o C# ou o Visual Basic. Usar o C++/CLI somente para fins de interoperabilidade.

### <a name="parallel-patterns-library-and-concurrency-runtime-library"></a>Biblioteca de Padrões Paralelos e Biblioteca de Tempo de Execução de Simultaneidade

A enumeração `SchedulerType` de `UmsThreadDefault` foi preterida. A especificação de `UmsThreadDefault` produz um aviso de preterido e mapeia internamente de volta para o `ThreadScheduler`.

### <a name="standard-library"></a>Biblioteca Padrão

- Após uma alteração da falha entre os padrões C++98/03 e C++11, o uso de argumentos de modelo explícitos para chamar `make_pair()` – como `make_pair<int, int>(x, y)` – normalmente não é compilado no Visual C++ no Visual Studio 2012. A solução sempre é chamar `make_pair() `sem argumentos de modelo explícitos – como `make_pair(x, y)`. O fornecimento de argumentos de modelo explícitos anula a finalidade da função. Se precisar de controle preciso sobre o tipo resultante, use `pair` em vez de `make_pair` – como `pair<short, short>(int1, int2)`.

- Outra alteração da falha entre os padrões C++98/03 e C++11: quando A é implicitamente conversível para B e B é implicitamente conversível para C, mas A não é implicitamente conversível para C, o C++98/03 e o Visual C++ 2010 permitiam que `pair<A, X>` fosse convertido (implícita ou explicitamente) para `pair<C, X>`. (O tipo X não é de interesse aqui e isso não é específico ao primeiro tipo no par.) O compilador C++ no Visual Studio 2012 detecta que A não é implicitamente conversível para C e remove a conversão de par da resolução de sobrecarga. Essa é uma alteração positiva para muitos cenários. Por exemplo, sobrecarregar `func(const pair<int, int>&)` e `func(const pair<string, string>&)` e chamar `func()` com `pair<const char *, const char *>` compilará com essa alteração. No entanto, essa alteração interrompe o código que baseava-se em conversões de par agressivas. Esse código geralmente pode ser corrigido executando explicitamente uma parte da conversão – por exemplo, passando `make_pair(static_cast<B>(a), x)` para uma função que espera `pair<C, X>`.

- O Visual C++ 2010 simulava modelos variadic – por exemplo, `make_shared<T>(arg1, arg2, argN)` – até o limite de 10 argumentos, marcando sobrecargas e especializações com o mecanismo do pré-processador. No Visual Studio 2012, esse limite é reduzido a cinco argumentos para melhorar os tempos de compilação e o consumo de memória do compilador para a maioria dos usuários. No entanto, você pode configurar o limite anterior definindo explicitamente _VARIADIC_MAX como 10 em todo o projeto.

- O C++11 17.6.4.3.1 [macro.names]/2 proíbe a substituição de palavras-chave por macros quando os cabeçalhos da Biblioteca do C++ Standard estão incluídos. Os cabeçalhos agora emitem erros do compilador se detectam palavras-chave substituídas por macros. (A definição de _ALLOW_KEYWORD_MACROS permite que esse código seja compilado, mas nós não recomendamos esse uso). Como uma exceção, a forma de macro `new` é permitida por padrão, porque os cabeçalhos de defendem de forma abrangente usando `#pragma push_macro("new")`/`#undef new`/`#pragma pop_macro("new")`. A definição de _ENFORCE_BAN_OF_MACRO_NEW faz exatamente o que seu nome sugere.

- Para implementar várias otimizações e verificações de depuração, a implementação da Biblioteca Padrão do C++ interrompe intencionalmente a compatibilidade binária entre as versões do Visual Studio (2005, 2008, 2010, 2012). Quando a Biblioteca do C++ Standard é usada, isso proíbe a mistura de arquivos de objeto e das bibliotecas estáticas que são compiladas usando versões diferentes em um binário (EXE ou DLL) e proíbe a passagem dos objetos da Biblioteca do C++ Standard entre binários que são compilados usando versões diferentes. A mistura de arquivos-objetos e bibliotecas estáticas usando a Biblioteca do C++ Standard que foi compilada usando o Visual C++ 2010 com aquelas que foram compiladas usando o compilador C++ no Visual Studio 2012, emite erros de vinculador sobre a incompatibilidade de _MSC_VER, em que _MSC_VER é a macro que contém a versão principal do compilador (1700 para o Visual C++ no Visual Studio 2012). Essa verificação não pode detectar a combinação de DLL e não pode detectar uma combinação que envolva Visual C++ 2008 ou anterior.

- Além de detectar incompatibilidades de _ITERATOR_DEBUG_LEVEL, que foi implementado no Visual C++ 2010, o compilador C++ no Visual Studio 2012 detecta incompatibilidades de Biblioteca em Tempo de Execução. Essas incompatibilidades ocorrem quando as opções de compilador `/MT` (versão estática), `/MTd` (depuração estática), `/MD` (versão dinâmica) e `/MDd` (depuração dinâmica) são combinadas.

- `operator<()`, `operator>()`, `operator<=()` e `operator>=()` estavam disponíveis anteriormente para as famílias de contêineres `std::unordered_map` e `stdext::hash_map`, embora suas implementações não fossem úteis. Esses operadores não padrão foram removidos do Visual C++ no Visual Studio 2012. Além disso, a implementação de `operator==()` e `operator!=()` para a família `std::unordered_map` foi estendida para cobrir a família `stdext::hash_map`. (É recomendável que você evite o uso da família `stdext::hash_map` no novo código.)

- C++11 22.4.1.4 [locale.codecvt] especifica que `codecvt::length()` e `codecvt::do_length()` devem usar parâmetros `stateT&` modificáveis, mas o Visual C++ 2010 usava `const stateT&`. O compilador C++ no Visual Studio 2012 usa `stateT&` conforme designado pelo padrão. Essa diferença é significativa para qualquer pessoa que esteja tentando substituir a função virtual `do_length()`.

### <a name="crt"></a>CRT

- O heap do CRT (Tempo de execução de C), que é usado para new e malloc(), não é mais particular. O CRT agora usa o heap do processo. Isso significa que o heap não será destruído quando uma DLL for descarregada, portanto as DLLs vinculadas estaticamente à CRT devem garantir que a memória alocada pelo código da DLL seja limpa antes de ser descarregada.

- A função `iscsymf()` faz declarações com valores negativos.

- O struct `threadlocaleinfostruct` foi alterado para acomodar as alterações nas funções de localidade.

- As funções de CRT que têm intrínsecos correspondentes como `memxxx()`, `strxxx()` foram removidas de intrin.h. Se você incluiu intrin.h apenas para essas funções, agora você deverá incluir os cabeçalhos de CRT correspondentes.

### <a name="mfc-and-atl"></a>MFC e ATL

- O suporte à Fusão (afxcomctl32.h) foi removido. Portanto, todos os métodos que foram definidos em \<afxcomctl32.h> foram removidos. Os arquivos de cabeçalho \<afxcomctl32.h> e \<afxcomctl32.inl> foram excluídos.

- O nome de `CDockablePane::RemoveFromDefaultPaneDividier` foi alterado para `CDockablePane::RemoveFromDefaultPaneDivider`.

- A assinatura de `CFileDialog::SetDefExt` foi alterada para usar LPCTSTR. Portanto, os builds de Unicode foram afetados.

- As categorias de rastreamento de ATL obsoletas foram removidas.

- A assinatura de `CBasePane::MoveWindow` foi alterada para usar um `const CRect`.

- A assinatura de `CMFCEditBrowseCtrl::EnableBrowseButton` foi alterada.

- `m_fntTabs` e `m_fntTabsBold` foram removidos de `CMFCBaseTabCtrl`.

- Foi adicionado um parâmetro aos construtores `CMFCRibbonStatusBarPane`. (É um parâmetro padrão e, portanto, não causa interrupção de código-fonte.)

- Foi adicionado um parâmetro ao construtor `CMFCRibbonCommandsListBox`. (É um parâmetro padrão e, portanto, não causa interrupção de código-fonte.)

- A API `AFXTrackMouse` foi removida (e o temporizador proc relacionado). Use a API `TrackMouseEvent` do Win32 em vez disso.

- Foi adicionado um parâmetro ao construtor `CFolderPickerDialog`. (É um parâmetro padrão e, portanto, não causa interrupção de código-fonte.)

- O tamanho da estrutura `CFileStatus` mudou: o membro `m_attribute` foi alterado de BYTE para DWORD (para corresponder ao valor retornado de `GetFileAttributes`).

- `CRichEditCtrl` e `CRichEditView` usam MSFTEDIT_CLASS (controle RichEdit 4.1) em vez de RICHEDIT_CLASS (controle RichEdit 3.0) em builds de Unicode.

- `AFX_GLOBAL_DATA::IsWindowsThemingDrawParentBackground` foi removido porque é sempre TRUE no Windows Vista, Windows 7 e Windows 8.

- `AFX_GLOBAL_DATA::IsWindowsLayerSupportAvailable` foi removido porque é sempre TRUE no Windows Vista, Windows 7 e Windows 8.

- `AFX_GLOBAL_DATA::DwmExtendFrameIntoClientArea` foi removido. Chame a API do Windows diretamente no Windows Vista, Windows 7 e Windows 8.

- `AFX_GLOBAL_DATA::DwmDefWindowProc` foi removido. Chame a API do Windows diretamente no Windows Vista, Windows 7 e Windows 8.

- `AFX_GLOBAL_DATA::DwmIsCompositionEnabled` foi renomeado como `IsDwmCompositionEnabled` para eliminar a colisão de nomes.

- Os identificadores foram alterados para um número de temporizadores internos do MFC e as definições foram movidas para afxres.h (AFX_TIMER_ID_*).

- A assinatura do método `OnExitSizeMove` foi alterada para concordar com a macro ON_WM_EXITSIZEMOVE:

   - `CFrameWndEx`

   - `CMDIFrameWndEx`

   - `CPaneFrameWnd`

- O nome e a assinatura de `OnDWMCompositionChanged` foram alterados para concordar com a macro ON_WM_DWMCOMPOSITIONCHANGED:

   - `CFrameWndEx`

   - `CMDIFrameWndEx`

   - `CPaneFrameWnd`

- A assinatura do método `OnMouseLeave` foi alterada para concordar com a macro ON_WM_MOUSELEAVE:

   - `CMFCCaptionBar`

   - `CMFCColorBar`

   - `CMFCHeaderCtrl`

   - `CMFCProperySheetListBox`

   - `CMFCRibbonBar`

   - `CMFCRibbonPanelMenuBar`

   - `CMFCRibbonRichEditCtrl`

   - `CMFCSpinButtonCtrl`

   - `CMFCToolBar` ReplaceThisText

   - `CMFCToolBarComboBoxEdit`

   - `CMFCToolBarEditCtrl`

   - `CMFCAutoHideBar`

- A assinatura de `OnPowerBroadcast` foi alterada para concordar com a macro ON_WM_POWERBROADCAST:

   - `CFrameWndEx`

   - `CMDIFrameWndEx`

- A assinatura de `OnStyleChanged` foi alterada para concordar com a macro ON_WM_STYLECHANGED:

   - `CMFCListCtrl`

   - `CMFCStatusBar`

- O método interno `FontFamalyProcFonts` foi renomeado para `FontFamilyProcFonts`.

- Vários objetos globais estáticos `CString` foram removidos para eliminar perdas de memória em algumas situações (substituídos por #defines) e as seguintes variáveis de membro de classe:

   - `CKeyBoardManager::m_strDelimiter`

   - `CMFCPropertyGridProperty::m_strFormatChar`

   - `CMFCPropertyGridProperty::m_strFormatShort`

   - `CMFCPropertyGridProperty::m_strFormatLong`

   - `CMFCPropertyGridProperty::m_strFormatUShort`

   - `CMFCPropertyGridProperty::m_strFormatULong`

   - `CMFCPropertyGridProperty::m_strFormatFloat`

   - `CMFCPropertyGridProperty::m_strFormatDouble`

   - `CMFCToolBarImages::m_strPngResType`

   - `CMFCPropertyGridProperty::m_strFormat`

- A assinatura de `CKeyboardManager::ShowAllAccelerators` foi alterada e o parâmetro delimitador de acelerador foi removido.

- `CPropertyPage::GetParentSheet` foi adicionado e, na classe `CPropertyPage`, chame-o em vez de chamar `GetParent` para obter a janela de folha pai correta, que pode ser uma janela pai ou avô para `CPropertyPage`. Você pode precisar alterar o código para chamar `GetParentSheet` em vez de `GetParent`.

- #pragma warning(push) desbalanceado foi corrigido em ATLBASE.H, que causava avisos sendo desabilitados incorretamente. Agora, esses avisos estão corretamente habilitados depois que ATLBASE.H foi analisado.

- Métodos relacionados a D2D foram movidos de AFX_GLOBAL_DATA para _AFX_D2D_STATE:

   - `GetDirectD2dFactory`

   - `GetWriteFactory`

   - `GetWICFactory`

   - `InitD2D`

   - `ReleaseD2DRefs`

   - `IsD2DInitialized`

   - `D2D1MakeRotateMatrix`

   - Em vez de chamar, por exemplo, `afxGlobalData.IsD2DInitialized`, chame `AfxGetD2DState->IsD2DInitialized`.

- Arquivos ATL*.CPP obsoletos foram removidos da pasta \atlmfc\include\.

- A inicialização `afxGlobalData` foi movida para sob demanda em vez de no momento da inicialização CRT, para atender aos requisitos de `DLLMain`.

- O método `RemoveButtonByIndex` foi adicionado à classe `CMFCOutlookBarPane`.

- `CMFCCmdUsageCount::IsFreqeuntlyUsedCmd` foi corrigido para `IsFrequentlyUsedCmd`.

- Várias instâncias de `RestoreOriginalstate` foram corrigidas para `RestoreOriginalState (CMFCToolBar, CMFCMenuBar, CMFCOutlookBarPane)`.

- Métodos não utilizados foram removidos de `CDockablePane`: `SetCaptionStyle`, `IsDrawCaption`, `IsHideDisabledButtons`, `GetRecentSiblingPaneInfo` e `CanAdjustLayout`.

- As variáveis de membro estático `m_bCaptionText` e `m_bHideDisabledButtons` foram removidas de `CDockablePane`.

- Foi adicionado um método `DeleteString` de substituição para `CMFCFontComboBox`.

- Métodos não utilizados foram removidos de `CPane`: `GetMinLength` e `IsLastPaneOnLastRow`.

- `CPane::GetDockSiteRow(CDockingPanesRow *)` renomeado para `CPane::SetDockSiteRow`.

## <a name="visual-c-2010-breaking-changes"></a>Alterações significativas do Visual C++ 2010

### <a name="compiler"></a>Compilador

- A palavra-chave **auto** tem um significado padrão novo. Como uso do antigo significado é raro, a maioria dos aplicativos não será afetada por essa alteração.

- A nova palavra-chave **static_assert** foi introduzida, o que causará um conflito de nome se já existir um identificador com esse nome no seu código.

- O suporte para a nova notação lambda exclui o suporte para a codificação de um GUID sem aspas em um atributo de UUID IDL.

- O .NET Framework 4 apresenta o conceito de exceções de estado corrompido, que são exceções que deixam um processo em um estado corrompido irrecuperável. Por padrão, você não pode capturar uma exceção de estado corrompido, mesmo com a opção do compilador /EHa, que captura todas as outras exceções.                 Para capturar explicitamente uma exceção de estado corrompido, use instruções __try-\__except. Ou aplique o atributo [HandledProcessCorruptedStateExceptions] para habilitar uma função para capturar exceções de estado corrompido.  Essa alteração afeta principalmente os programadores de sistema que podem ter que capturar uma exceção de estado corrompido. As oito exceções são: STATUS_ACCESS_VIOLATION, STATUS_STACK_OVERFLOW, EXCEPTION_ILLEGAL_INSTRUCTION,                 EXCEPTION_IN_PAGE_ERROR, EXCEPTION_INVALID_DISPOSITION, EXCEPTION_NONCONTINUABLE_EXCEPTION, EXCEPTION_PRIV_INSTRUCTION, STATUS_UNWIND_CONSOLIDATE.                 Para obter mais informações sobre essas exceções, consulte a macro [GetExceptionCode](/windows/desktop/Debug/getexceptioncode).

- A opção do compilador `/GS` revisada protege contra estouros de buffer de maneira mais abrangente do que nas versões anteriores. Essa versão pode inserir verificações de segurança adicionais na pilha que podem diminuir o desempenho. Use a nova palavra-chave `__declspec(safebuffers)` para instruir o compilador a não inserir verificações de segurança para uma função específica.

- Se você compilar com as opções de compilador `/GL` (Otimização do Programa Inteiro) e `/clr` (Compilação Common Language Runtime), a opção `/GL` será ignorada. Essa alteração foi feita porque a combinação de opções do compilador fornecia poucos benefícios. Como resultado dessa alteração, o desempenho do build foi aprimorado.

- Por padrão, o suporte para trígrafos está desabilitado no Visual C++ 2010. Use a opção do compilador `/Zc:trigraphs` para habilitar o suporte a trígrafos. Um trígrafo consiste em dois pontos de interrogação consecutivos ("??") seguidos por um terceiro caractere exclusivo. O compilador substitui um trígrafo por um caractere de pontuação correspondente. Por exemplo, o compilador substitui o trígrafo `??=` pelo caractere '#'. Use trígrafos em arquivos de origem de C que usam um conjunto de caracteres que não contém representações gráficas convenientes para alguns caracteres de pontuação.

- O vinculador não oferece mais suporte à otimização para o Windows 98. A opção `/OPT` (Otimizações) produzirá um erro em tempo de compilação se você especificar `/OPT:WIN98` ou `/OPT:NOWIN98`.

- As opções do compilador padrão que são especificadas pelas propriedades de sistema de build RuntimeLibrary e DebugInformationFormat foram alteradas. Por padrão, essas propriedades de build são especificadas em projetos que são criados pelo Visual C++, versões 7.0 à 10.0. Se você migrar um projeto que foi criado pelo Visual C++ 6.0, considere se deve especificar um valor para essas propriedades.

- No Visual C++ 2010, RuntimeLibrary = MultiThreaded (`/MD`) e DebugInformationFormat = ProgramDatabase (`/Zi`). No Visual C++ 9.0, RuntimeLibrary = MultiThreaded (`/MT`) e DebugInformationFormat = Desabilitado.

### <a name="clr"></a>CLR

- Os compiladores Microsoft C# e Visual Basic agora podem produzir um não PIA (não assembly de interoperabilidade primário). Um assembly não PIA pode usar tipos COM sem a implantação do PIA (assembly de interoperabilidade primário) relevante. Ao consumir assemblies não PIA produzidos pelo Visual C# ou Visual Basic, você deve fazer referência ao assembly PIA no comando de compilação antes de referenciar qualquer assembly não PIA que usa a biblioteca.

### <a name="visual-c-projects-and-msbuild"></a>Projetos do Visual C++ e MSBuild

- Os projetos do Visual C++ agora são baseados na ferramenta MSBuild. Consequentemente, os arquivos de projeto usam um novo formato de arquivo XML e um sufixo de arquivo .vcxproj. O Visual C++ 2010 converte automaticamente os arquivos de projeto de versões anteriores do Visual Studio para o novo formato de arquivo. Um projeto existente será afetado se depender da ferramenta de build anterior, VCBUILD.exe ou do sufixo de arquivo de projeto .vcproj.

- Em versões anteriores, o Visual C++ oferecia suporte para a avaliação tardia de folhas de propriedades. Por exemplo, uma folha de propriedades pai poderia importar uma folha de propriedades filho e a pai poderia usar uma variável definida na filho para definir outras variáveis. Avaliação tardia habilitava a folha pai a usar a variável de filho antes mesmo que a folha de propriedades filho fosse importada. No Visual C++ 2010, uma variável de folha de projeto não pode ser usada antes de ser definida porque o MSBuild somente dá suporte à avaliação adiantada.

### <a name="ide"></a>IDE

- A caixa de diálogo de encerramento do aplicativo não termina mais um aplicativo. Em versões anteriores, quando a função `abort()` ou `terminate()` fechava o build de varejo de um aplicativo, a Biblioteca em tempo de execução de C exibia uma mensagem de encerramento do aplicativo em uma caixa de diálogo ou janela de console. A mensagem dizia, em parte, "Este aplicativo solicitou que o Tempo de execução terminasse de maneira incomum. Entre em contato com equipe de suporte do aplicativo para obter mais informações." A mensagem de encerramento do aplicativo era redundante, pois o Windows exibia posteriormente o manipulador de encerramento atual, que geralmente era a caixa de diálogo de Relatório de Erros do Windows (Dr. Watson) ou o depurador do Visual Studio. Do Visual Studio 2010 em diante, a Biblioteca em tempo de execução de C não exibe a mensagem. Além disso, o tempo de execução impede que o aplicativo finalize antes do início de um depurador. Essa só é uma alteração da falha se você depende do comportamento anterior da mensagem de encerramento do aplicativo.

- Especificamente para o Visual Studio 2010, o IntelliSense não funciona para código ou atributos de C++/CLI, **Localizar Todas as Referências** não funciona para variáveis locais e o Modelo de Código não recupera nomes de tipo de assemblies importados ou não resolve tipos para seus nomes totalmente qualificados.

### <a name="libraries"></a>Libraries

- A classe SafeInt está incluída no Visual C++ e não está mais em um download separado. Essa é uma alteração da falha somente se você desenvolveu uma classe que também é chamada de "SafeInt".

- O modelo de implantação de bibliotecas não usa mais manifestos para localizar uma versão específica de uma biblioteca de vínculo dinâmico. Em vez disso, o nome de cada biblioteca de vínculo dinâmico contém seu número de versão e você usa esse nome para localizar a biblioteca.

- Nas versões anteriores do Visual Studio, era possível recompilar as bibliotecas em tempo de execução. O Visual C++ 2010 não oferece mais suporte ao build de suas próprias cópias de arquivos de biblioteca em tempo de execução de C.

### <a name="standard-library"></a>Biblioteca Padrão

- O cabeçalho \<iterator> não é mais incluído automaticamente por muitos outros arquivos de cabeçalho. Em vez disso, inclua esse cabeçalho explicitamente se você precisar de suporte para os iteradores autônomos definidos no cabeçalho. Um projeto existente será afetado se depender da ferramenta de build anterior, VCBUILD.exe ou do sufixo de arquivo de projeto .vcproj.iterator.

- No cabeçalho \<algorithm>, as funções checked_* e unchecked_\* foram removidas. E, no cabeçalho \<iterator>>, a classe `checked_iterator` foi removida e a classe `unchecked_array_iterator` foi adicionada.

- O construtor `CComPtr::CComPtr(int)` foi removido. Esse construtor permitia que um objeto `CComPtr` fosse construído por meio macro NULL, mas era desnecessário e permitia construções absurdas de inteiros diferentes de zero.

   Um `CComPtr` ainda pode ser construído de NULL, que é definido como 0, mas falhará se for construído de um valor inteiro diferente de 0 literal. Em vez disso, use **nullptr**.

- As seguintes funções de membro de `ctype` foram removidas: `ctype::_Do_narrow_s`, `ctype::_Do_widen_s`, `ctype::_narrow_s`, `ctype::_widen_s`. Se um aplicativo usa uma dessas funções de membro, você deve substituí-la pela versão não segura correspondente: `ctype::do_narrow`, `ctype::do_widen`, `ctype::narrow`, `ctype::widen`.

### <a name="crt-mfc-and-atl-libraries"></a>Bibliotecas ATL, MFC e CRT

- Foi removido o suporte para que os usuários compilem as bibliotecas CRT, MFC e ATL. Por exemplo, nenhum arquivo NMAKE apropriado é fornecido. No entanto, os usuários ainda terão acesso ao código-fonte dessas bibliotecas. E um documento que descreve as opções do MSBuild que a Microsoft usa para criar essas bibliotecas provavelmente será publicado em um Blog da Equipe do Visual C++.

- O suporte ao MFC para IA64 foi removido. No entanto, ainda é fornecido suporte para CRT e ATL em IA64.

- Os ordinais não são mais reutilizados em arquivos de definição de módulo (.def) do MFC. Essa alteração significa que os ordinais não serão diferentes entre as versões secundárias e a compatibilidade binária para service packs e versões de engenharia de correção rápida será aprimorada.

- Uma função virtual nova foi adicionada à classe `CDocTemplate`. Essa nova função virtual é a [Classe CDocTemplate](../mfc/reference/cdoctemplate-class.md). A versão anterior de `OpenDocumentFile` tinha dois parâmetros. A nova versão tem três parâmetros. Para dar suporte ao gerenciador de reinicialização, qualquer classe derivada de `CDocTemplate` deve implementar a versão que tem três parâmetros. O novo parâmetro é `bAddToMRU`.

### <a name="macros-and-environment-variables"></a>Macros e Variáveis de Ambiente

- Não há mais suporte para a variável de ambiente __MSVCRT_HEAP_SELECT. Essa variável de ambiente foi removida e não há substituta.

### <a name="microsoft-macro-assembler-reference"></a>Referência do Microsoft Macro Assembler

- Várias diretivas foram removidas do compilador de referência Macro Assembler da Microsoft. As diretivas removidas são `.186`, `.286`, `.286P`, `.287`, `.8086`, `.8087` e `.NO87`.

## <a name="visual-c-2008-breaking-changes"></a>Alterações significativas do Visual C++ 2008

### <a name="compiler"></a>Compilador

- Não há mais suporte para as plataformas Windows 95, Windows 98, Windows ME e Windows NT. Esses sistemas operacionais foram removidos da lista de plataformas de destino.

- O compilador não oferece mais suporte a vários atributos que foram diretamente associados com o Servidor ATL. Não há mais suporte para os seguintes atributos:

   - perf_counter

   - perf_object

   - perfmon

   - request_handler

   - soap_handler

   - soap_header

   - soap_method

   - tag_name

### <a name="visual-c-projects"></a>Projetos Visual C++

- Ao atualizar projetos de versões anteriores do Visual Studio, você talvez precise modificar as macros WINVER e _WIN32_WINNT para que elas sejam maiores ou iguais a 0x0500.

- Do Visual Studio 2008 em diante, o assistente de novo projeto não tem uma opção para criar um projeto do SQL Server do C++. Os projetos do SQL Server criados usando uma versão anterior do Visual Studio ainda serão compilados e funcionarão corretamente.

- O arquivo de cabeçalho de API do Windows Winable.h foi removido. Inclua Winuser.h no lugar dele.

- A biblioteca de API do Windows Rpcndr.lib foi removida. Vincule com rpcrt4.lib no lugar dela.

### <a name="crt"></a>CRT

- O suporte para Windows 95, Windows 98, Windows Millennium Edition e Windows NT 4.0 foi removido.

- As seguintes variáveis globais foram removidas:

   - _osplatform

   - _osver

   - _winmajor

   - _winminor

   - _winver

- As seguintes funções foram removidas. Use as funções de API do Windows `GetVersion` ou `GetVersionEx` em vez disso:

   - _get_osplatform

   - _get_osver

   - _get_winmajor

   - _get_winminor

   - _get_winver

- A sintaxe para Anotações SAL foi alterada. Para obter mais informações, consulte [Anotações SAL](../c-runtime-library/sal-annotations.md).

- O filtro de IEEE agora oferece suporte ao conjunto de instruções SSE 4.1. Para obter mais informações, consulte [_fpieee_flt](../c-runtime-library/reference/fpieee-flt.md)_fpieee_flt.

- As Bibliotecas em tempo de execução de C que vêm com o Visual Studio não são mais dependentes da DLL de sistema msvcrt.dll.

### <a name="standard-library"></a>Biblioteca Padrão

- O suporte para Windows 95, Windows 98, Windows Millennium Edition e Windows NT 4.0 foi removido.

- Ao compilar no modo de depuração com _HAS_ITERATOR_DEBUGGING definido (substituído por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) após o Visual Studio 2010), um aplicativo agora declarará quando um iterador tenta incrementar ou decrementar além dos limites do contêiner subjacente.

- A variável de membro c da pilha Class agora é declarada protegida. Anteriormente, essa variável de membro era declarada pública.

- O comportamento de `money_get::do_get` foi alterado. Antes, ao analisar um valor monetário com mais dígitos de fração do que era chamado por `frac_digits`, `do_get` costumava consumir todos eles. Agora, `do_get` para a análise após consumir, no máximo, os caracteres de `frac_digits`.

### <a name="atl"></a>ATL

- A ATL não pode ser compilada sem uma dependência de CRT. Em versões anteriores do Visual Studio, você poderia usar #define ATL_MIN_CRT para tornar um projeto ATL minimamente dependente de CRT. No Visual C++ 2008, todos os projetos ATL dependem minimamente de CRT, independentemente de ATL_MIN_CRT estar definido.

- A base de código do servidor ATL foi lançada como um projeto de código-fonte compartilhado no CodePlex e não é instalado como parte do Visual Studio. As classes de codificação e decodificação de dados de funções atlenc.h e utilitários e as classes de atlutil.h e atlpath.h foram mantidas e agora fazem parte da biblioteca ATL. Vários arquivos associados ao servidor ATL não fazem mais parte do Visual Studio.

- Algumas funções não estão mais incluídas na DLL. Elas ainda estão localizadas na biblioteca de importação. Isso não afetará o código que usa as funções estaticamente. Isso afetará apenas o código que usa essas funções dinamicamente.

- As macros PROP_ENTRY e PROP_ENTRY_EX foram preteridas e substituídas pelas macros PROP_ENTRY_TYPE e PROP_ENTRY_TYPE_EX por motivos de segurança.

### <a name="atlmfc-shared-classes"></a>Classes compartilhadas ATL/MFC

- A ATL não pode ser compilada sem uma dependência de CRT. Em versões anteriores do Visual Studio, você poderia usar `#define ATL_MIN_CRT` para tornar um projeto ATL minimamente dependente de CRT. No Visual C++ 2008, todos os projetos ATL dependem minimamente de CRT, independentemente de ATL_MIN_CRT estar definido.

- A base de código do servidor ATL foi lançada como um projeto de código-fonte compartilhado no CodePlex e não é instalado como parte do Visual Studio. As classes de codificação e decodificação de dados de funções atlenc.h e utilitários e as classes de atlutil.h e atlpath.h foram mantidas e agora fazem parte da biblioteca ATL. Vários arquivos associados ao servidor ATL não fazem mais parte do Visual Studio.

- Algumas funções não estão mais incluídas na DLL. Elas ainda estão localizadas na biblioteca de importação. Isso não afetará o código que usa as funções estaticamente. Isso afetará apenas o código que usa essas funções dinamicamente.

### <a name="mfc"></a>MFC

- Classe `CTime`: A classe `CTime` agora aceita datas a partir de 1/1/1900 D.C. em vez de 1/1/1970 D.C.

- Ordem de tabulação dos controles em caixas de diálogo do MFC: a ordem de tabulação correta de vários controles em uma caixa de diálogo do MFC será afetada se um controle ActiveX MFC for inserido na ordem de tabulação. Essa alteração corrige esse problema.

   Por exemplo, crie um aplicativo de caixa de diálogo do MFC que tem um controle ActiveX e vários controles de edição. Posicione o controle ActiveX no meio da ordem de tabulação dos controles de edição. Inicie o aplicativo, clique em um controle de edição cuja ordem de tabulação é depois do controle ActiveX e, em seguida, TAB. Antes dessa mudança, o foco ia para o controle de edição depois do controle ActiveX em vez do próximo controle de edição na ordem de tabulação.

- Classe `CFileDialog`: os modelos personalizados para a classe `CFileDialog` não podem ser automaticamente transferidos para o Windows Vista. Eles ainda podem ser usados, mas não terão a funcionalidade adicional ou a aparência das caixas de diálogo do estilo Windows Vista.

- Classe `CWnd` e classe `CFrameWnd`: o método `CWnd::GetMenuBarInfo` foi removido.

   O método `CFrameWnd::GetMenuBarInfo` agora é um método não virtual. Para obter mais informações, consulte **Função GetMenuBarInfo** no SDK do Windows.

- Suporte a ISAPI do MFC: o MFC não dá mais suporte ao build de aplicativos com a interface ISAPI. Se você deseja criar um aplicativo ISAPI, chame diretamente as extensões ISAPI.

- APIs ANSI preteridas: as versões ANSI de vários métodos MFC foram preteridas. Use as versões Unicode desses métodos em seus aplicativos futuros. Para obter mais informações, consulte **Requisitos de build para controles comuns do Windows Vista**.

## <a name="visual-c-2005-breaking-changes"></a>Alterações significativas do Visual C++ 2005

### <a name="crt"></a>CRT

- Muitas funções foram preteridas. Consulte **Funções CRT preteridas**.

- Agora, muitas funções validam seus parâmetros, interrompendo a execução se determinados parâmetros forem inválidos. Essa validação pode interromper o código que passa parâmetros inválidos e depende da função ignorá-los ou apenas retornar um código de erro. Consulte **Validação de Parâmetro**.

- O valor do descritor de arquivo -2 agora é usado para indicar que `stdout` e `stderr` não estão disponíveis para a saída, como, por exemplo, em um aplicativo do Windows que não tem nenhuma janela de console. O valor usado anteriormente era -1. Para obter mais informações, consulte [_fileno](../c-runtime-library/reference/fileno.md).

- As bibliotecas CRT de thread único, libc.lib e libcd.lib, foram removidas. Use as bibliotecas CRT com multithread. Não há mais suporte para o sinalizador do compilador `/ML`. Versões de não bloqueio de algumas funções foram adicionadas em casos em que a diferença de desempenho entre o código com multithread e o código de thread único era potencialmente significativa.

- A sobrecarga de pow, double pow(int, int), foi removida para melhor conformidade com o padrão.

- O especificador de formato %n não é mais compatível por padrão em qualquer uma das famílias ou funções printf porque é inerentemente inseguro. Se %n for encontrado, o comportamento padrão será invocar o manipulador de parâmetro inválido. Para habilitar o suporte a %n, use `_set_printf_count_output` (consulte também `_get_printf_count_output`).

- Agora, `sprintf` imprime o sinal negativo de um zero com sinal.

- `swprintf` foi alterado para conformidade com o Padrão. Agora, ele exige um parâmetro de tamanho. A forma de `swprintf` sem um parâmetro de tamanho foi preterida.

- `_set_security_error_handler` foi removido. Remova as chamadas a essa função. O manipulador padrão é uma maneira muito mais segura de lidar com erros de segurança.

- `time_t` agora é um valor de 64 bits (a menos que _USE_32BIT_TIME_T seja definido).

- As funções `_spawn`, `_wspawn` deixam `errno` inalterado com êxito, conforme especificado pelo C Standard.

- O RTC agora usa caracteres largos por padrão.

- As funções de suporte de palavra de controle de ponto flutuante foram preteridas por aplicativos compilados com `/CLR` ou `/CLR:PURE`. As funções afetadas são `_clear87`, `_clearfp`, `_control87`, `_controlfp`, `_fpreset`, `_status87`, `_statusfp`. Você pode desabilitar o aviso de substituição ao definir _CRT_MANAGED_FP_NO_DEPRECATE, mas o uso dessas funções em código gerenciado é imprevisível e não tem suporte.

- Agora, algumas funções retornam ponteiros const. O comportamento antigo não const pode ser restabelecido definindo _CONST_RETURN. As funções afetadas são

   - memchr, wmemchr

   - strchr, wcschr, _mbschr, _mbschr_l

   - strpbrk, wcspbrk, _mbspbrk, _mbspbrk_l

   - strrchr, wcsrchr, _mbsrchr, _mbsrchr_l

   - strstr, wcsstr, _mbsstr, _mbsstr_l

- Ao vincular com Setargv.obj ou Wsetargv.obj, não é mais possível suprimir a expansão de um caractere curinga na linha de comando colocando-o entre aspas duplas. Para obter mais informações, consulte [Expandindo Argumentos de Curinga](../c-language/expanding-wildcard-arguments.md).

### <a name="standard-library-2005"></a>Biblioteca Padrão (2005)

- A classe de exceção (localizada no cabeçalho \<exception>) foi movida para o namespace `std`. Nas versões anteriores, esta classe estava no namespace global. Para resolver os erros indicando que a classe de exceção não pode ser encontrada, adicione a seguinte instrução de uso seu código: `using namespace std;`

- Ao chamar `valarray::resize()`, o conteúdo de `valarray` será perdido e será substituído por valores padrão. O método `resize()` é destinado para reinicializar o `valarray` em vez de aumentá-lo dinamicamente como um vetor.

- Iteradores de depuração: aplicativos criados com uma versão de depuração da Biblioteca em tempo de execução de C e que usam iteradores de maneira incorreta, podem começar a ver declarações em tempo de execução. Para desabilitar essas declarações, você deve definir _HAS_ITERATOR_DEBUGGING (substituída por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) após o Visual Studio 2010) como 0. Para obter mais informações, consulte [Suporte a iterador de depuração](../standard-library/debug-iterator-support.md)

## <a name="visual-c-net-2003-breaking-changes"></a>Alterações significativas do Visual C++ .NET 2003

### <a name="compiler"></a>Compilador

- O parênteses de fechamento agora é necessário de acordo com a diretiva definida de pré-processador (C2004).

- As especializações explícitas não encontram mais os parâmetros de modelo do modelo primário ([Erro do Compilador C2146](../error-messages/compiler-errors-1/compiler-error-c2146.md)).

- Um membro protegido (n) só pode ser acessado através de uma função de membro de uma classe (B) que herda da classe (A) da qual (n) é um membro ([Erro do Compilador C2247](../error-messages/compiler-errors-1/compiler-error-c2247.md)).

- Verificações de acessibilidade aprimoradas no compilador agora detectam classes base inacessíveis ([Erro do Compilador C2248](../error-messages/compiler-errors-1/compiler-error-c2248.md)).

- Uma exceção não poderá ser capturada se o destruidor e/ou construtor de cópia estiver inacessível (C2316).

- Os argumentos padrão em ponteiros para funções não são mais permitidos ([Erro do Compilador C2383](../error-messages/compiler-errors-1/compiler-error-c2383.md)).

- Um membro de dados estático não pode ser inicializado via classe derivada ([Erro do Compilador C2477](../error-messages/compiler-errors-1/compiler-error-c2477.md)).

- A inicialização de uma **typedef** não é permitida pelo padrão e agora gera um erro do compilador ([Erro do Compilador C2513](../error-messages/compiler-errors-2/compiler-error-c2513.md)).

- **bool** agora é um tipo adequado ([Erro do Compilador C2632](../error-messages/compiler-errors-2/compiler-error-c2632.md)).

- Um UDC agora pode criar ambiguidade com operadores sobrecarregados ([C2666](../error-messages/compiler-errors-2/compiler-error-c2666.md)).

- Mais expressões agora são consideradas constantes de ponteiro nulo válido ([Erro do Compilador C2668](../error-messages/compiler-errors-2/compiler-error-c2668.md)).

- template<> agora é necessário em locais em que o compilador anteriormente iria sugeri-lo ([Erro do Compilador C2768](../error-messages/compiler-errors-2/compiler-error-c2768.md)).

- A especialização explícita de uma função de membro fora da classe não será válida se a função já tiver sido especializada explicitamente por meio de uma especialização de classe de modelo ([Erro do Compilador C2910](../error-messages/compiler-errors-2/compiler-error-c2910.md)).

- Parâmetros de modelo de não tipo de ponto flutuante não são mais permitidos ([Erro do Compilador C2993](../error-messages/compiler-errors-2/compiler-error-c2993.md)).

- Modelos de classe não são permitidos como argumentos de tipo de modelo (C3206).

- Nomes de função friend não são mais apresentados em namespace que o contenha ([Erro do Compilador C3767](../error-messages/compiler-errors-2/compiler-error-c3767.md)).

- O compilador não aceitará mais vírgulas adicionais em uma macro (C4002).

- Um objeto de tipo POD construído com um inicializador da forma () será inicializado de modo padrão (C4345).

- typename agora é necessário se um nome dependente deve ser tratado como um tipo ([Aviso do Compilador (nível 1) C4346](../error-messages/compiler-warnings/compiler-warning-level-1-c4346.md)).

- Funções que foram incorretamente consideradas especializações de modelo não são mais consideradas assim (C4347).

- Membros de dados estáticos não podem ser inicializados via classe derivada (C4356).

- Uma especialização de modelo de classe precisa ser definida antes de ser usada em um tipo de retorno ([Aviso do Compilador (nível 3) C4686](../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md)).

- O compilador agora relata código inacessível (C4702).

## <a name="see-also"></a>Consulte também

[Novidades do Visual C++ no Visual Studio](../overview/what-s-new-for-visual-cpp-in-visual-studio.md)

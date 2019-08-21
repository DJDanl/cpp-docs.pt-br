---
title: Tabela de conformidade com a linguagem Microsoft C++
ms.date: 08/12/2019
ms.technology: cpp-language
ms.assetid: 475da6e9-0d78-4b4e-bd23-f41c406c4efe
author: corob-msft
ms.author: corob
ms.openlocfilehash: 15226d41991d5a09d104d2edbfb3dbf2f7432b65
ms.sourcegitcommit: db1ed91fa7451ade91c3fb76bc7a2b857f8a5eef
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2019
ms.locfileid: "68980522"
---
# <a name="microsoft-c-language-conformance-table"></a>Tabela de conformidade com a linguagem Microsoft C++

Este tópico resume a conformidade com os padrões de linguagem ISO C++03, C++11, C++14, C++17 e C++20 dos recursos do compilador e dos recursos da Biblioteca Padrão para o compilador Microsoft C++ no Visual Studio 2019 e versões anteriores. Cada nome de recurso da Biblioteca Padrão e do compilador é vinculado ao documento de proposta ISO C++ Standard que descreve o recurso, caso ele esteja disponível no momento da publicação. A coluna Com suporte lista a versão do Visual Studio no qual o suporte para o recurso apareceu pela primeira vez.

Para obter detalhes sobre melhorias de conformidade e outras mudanças no Visual Studio 2017 ou Visual Studio 2019, defina o seletor de versão no canto superior esquerdo desta página e confira [Melhorias de conformidade com C++ no Visual Studio](cpp-conformance-improvements.md) e [Novidades do Visual C++ no Visual Studio](what-s-new-for-visual-cpp-in-visual-studio.md). Para alterações de compatibilidade em versões anteriores, consulte [Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md) e [Novidades do Visual C++ de 2003 a 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md). Para saber mais sobre as últimas notícias da equipe do C++, visite o [blog da equipe do C++](https://devblogs.microsoft.com/cppblog/).

> [!NOTE]
> Não há alterações da falha do binário entre o Visual Studio 2015, Visual Studio 2017 e Visual Studio 2019.

## <a name="compiler-features"></a>Recursos do compilador

| | |
|----|---|
|__Principais recursos da linguagem C++03/11__|__Com suporte__|
|&nbsp;&nbsp;O restante|VS 2015 <sup>[A](#note_A)</sup>|
|&nbsp;&nbsp;Pesquisa de nome de duas fases|VS 2017 15.7 <sup>[B](#note_B)</sup>|
|&nbsp;&nbsp;[N2634 Expressão SFINAE](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2634.html)|VS 2017 15.7|
|&nbsp;&nbsp;[N1653 Pré-processador C99](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1653.htm)|Parcial <sup>[C](#note_C)</sup>|
|__Principais recursos da linguagem C++14__|__Com suporte__|
|&nbsp;&nbsp;[N3323 Palavras ajustadas para conversões contextuais](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3323.pdf)|VS 2013|
|&nbsp;&nbsp;[N3472 Literais binários](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472.pdf)|VS 2015|
|&nbsp;&nbsp;[N3638 Tipos de retorno auto e decltype(auto)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3638.html)|VS 2015|
|&nbsp;&nbsp;[N3648 Capturas de init](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3648.html)|VS 2015|
|&nbsp;&nbsp;[N3649 Lambdas genéricos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3649.html)|VS 2015|
|&nbsp;&nbsp;[N3760 \[\[Atributo\]\] preterido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3760.html)|VS 2015|
|&nbsp;&nbsp;[N3778 Desalocação dimensionada](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3778.html)|VS 2015|
|&nbsp;&nbsp;[N3781 Separadores de dígito](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf)|VS 2015|
|&nbsp;&nbsp;[N3651 Modelos de variável](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3651.pdf)|VS 2015.2|
|&nbsp;&nbsp;[N3652 Constexpr estendido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html)|VS 2017 15.0|
|&nbsp;&nbsp;[N3653 Inicializadores de membro padrão para agregações](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3653.html)|VS 2017 15.0|
|__Principais recursos da linguagem C++17__|__Com suporte__|
|&nbsp;&nbsp;[N4086 Removendo trígrafos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4086.html)|VS 2010 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N3922 Novas regras para automático com listas de inicialização entre chaves](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4051 Nome de tipo em parâmetros de modelo do modelo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4051.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4266 Atributos para namespaces e enumeradores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4267 Literais de caracteres u8](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4230 Definições de namespace aninhado](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230.html)|VS 2015.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[N3928 Static_assert resumido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf)|VS 2017 15.0 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0184R0 Range-based for-loops generalizado](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html)|VS 2017 15.0 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0188R1 \[\[Atributo\]\]fallthrough](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r1.pdf)|VS 2017 15.0 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0001R1 Removendo a palavra-chave de registro](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0002R1 Removendo operator++ de bool](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0002r1.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0018R3 Capturando *this por valor](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0028R4 Usando namespaces de atributo sem repetição](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0028r4.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0061R1 \_\_has_include](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0061r1.html)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0138R2 Inicialização de lista direta de enumerações fixas de inteiros](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0138r2.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0170R1 Lambdas de constexpr](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0189R1 \[\[Atributo\]\] nodiscard](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0189r1.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0212R1 \[\[Atributo\]\] maybe_unused](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0212r1.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0217R3 Associações estruturadas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0217r3.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0292R2 Instruções constexpr if](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0292r2.html)|VS 2017 15.3 <sup>[D](#note_D)</sup>|
|&nbsp;&nbsp;[P0305R1 Instruções de seleção com inicializadores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0305r1.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0245R1 Literais de hexfloat](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[N4268 Permitindo mais argumentos de modelo sem tipo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[N4295 Expressões de dobra](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0003R5 Removendo especificações de exceção dinâmica](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0012R1 Adicionando noexcept ao sistema de tipos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0012r1.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0035R4 Alocação de memória dinâmica com excesso de alinhamento](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0035r4.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0386R2 Variáveis embutidas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0386r2.pdf)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0522R0 Fazendo a correspondência de parâmetros de modelo do modelo com argumentos compatíveis](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0522r0.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0036R0 Removendo algumas dobras unárias vazias](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0.pdf)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[N4261 Corrigindo conversões de qualificação](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4261.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0017R1 Inicialização de agregação estendida](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0091R3 Dedução de argumento de modelo para modelos de classe](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html)<br/>&nbsp;&nbsp;[P0512R0 Problemas de dedução de argumento de modelo de classe](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0512r0.pdf)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0127R2 Declarando parâmetros de modelo sem tipo com automático](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0127r2.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0135R1 Garantia de elisão de cópia](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0135r1.html)|VS 2017 15.6|
|&nbsp;&nbsp;[P0136R1 Reescrevendo construtores de herança](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0136r1.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0137R1 std::launder](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0137r1.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0145R3 Refinando a ordem de avaliação de expressão](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0145r3.pdf)<br/>&nbsp;&nbsp;[P0400R0 Ordem de avaliação de argumentos de função](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0400r0.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0195R2 Expansões de pacote em declarações using](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0195r2.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0283R2 Ignorando atributos não reconhecidos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0283r2.html)|VS 2015 <sup>[14](#note_14)</sup>|
|__Principais recursos da linguagem C++17 (relatórios de defeito)__|__Com suporte__|
|&nbsp;&nbsp;[P0702R1 Corrigindo dedução de argumento de modelo de classe para construtores de lista de inicializadores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0702r1.html)|VS 2017 15.7 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0961R1 Como relaxar as regras de localização do ponto de personalização de associações estruturadas](http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0961r1.html)|VS 2019 16.0 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0969R0 Permitir associações estruturadas para membros acessíveis](http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0969r0.pdf)|VS 2019 16.0 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0588R1 Simplificar captura de lambda implícita](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0588r1.html)|Não|
|&nbsp;&nbsp;[P0962R2 Relaxar as regras de localização do ponto de personalização do loop range-for](http://open-std.org/JTC1/SC22/WG21/docs/papers/2018/p0962r1.html)|Não|
|&nbsp;&nbsp;[P0929R2 Como verificar se há tipos de classe abstrata](https://wg21.link/P0929R2)|Não|
|&nbsp;&nbsp;[P1009R2 Dedução de tamanho da matriz em expressões novas](https://wg21.link/P1009R2)|Não|
|&nbsp;&nbsp;[P1286R2 Contra CWG DR1778](https://wg21.link/P1286R2)|Não|
|__Principais recursos da linguagem C++20__|__Com suporte__|
|&nbsp;&nbsp;[P0704R1 Corrigindo ponteiros qualificados por referência de construtores lvalue para membros](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0704r1.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P1041R4 Transformar literais de cadeia de caracteres char16_t/char32_t em UTF-16/32](https://wg21.link/P1041R4)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P1330R0 Alteração do membro ativo de uma união dentro de constexpr](https://wg21.link/P1330R0)|VS 2017 15.0 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0972R0 noexcept para \<chrono> zero(), min(), max()](https://wg21.link/P0972R0)|VS 2017 15.7 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0329R4 Inicialização designada](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0329r4.pdf)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0409R2 Como permitir a captura de lambda \[=, this\]](http://open-std.org/JTC1/SC22/WG21/docs/papers/2017/p0409r2.html)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0515R3 Comparação de três vias (espaçonave) <=>](https://wg21.link/P0515R3)|VS 2019 16.0 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0941R2 Macros de teste de recurso](https://wg21.link/P0941R2)|VS 2019 16.0 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P1008R1 Como proibir agregações com construtores declarados pelo usuário](https://wg21.link/P1008R1)|VS 2019 16.0 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0846R0 Modelos de função e ADL que não são visíveis](https://wg21.link/P0846R0)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0641R2 Incompatibilidade de const com o construtor de cópia padrão](https://wg21.link/P0641R2)|Parcial|
|&nbsp;&nbsp;[P0306R4 Adição de \_\_VA_OPT\_\_ para omissão e exclusão de vírgulas](https://wg21.link/P0306R4)|Não|
|&nbsp;&nbsp;[P0315R4 Como permitir lambdas em contextos não avaliados](https://wg21.link/P0315R4)|Não|
|&nbsp;&nbsp;[P0428R2 Sintaxe familiar de modelo para lambdas genéricas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0428r2.pdf)|Não|
|&nbsp;&nbsp;[P0479R5 Atributos \[\[likely\]\] e \[\[unlikely\]\] ](https://wg21.link/P0479R5)|Não|
|&nbsp;&nbsp;[P0542R5 Contratos](https://wg21.link/P0542R5)|Não|
|&nbsp;&nbsp;[P0614R1 Com base em intervalo para loops com inicializadores](https://wg21.link/P0614R1)|Não|
|&nbsp;&nbsp;[P0624R2 Lambdas padrão stateless construíveis e atribuíveis](https://wg21.link/P0624R2)|Não|
|&nbsp;&nbsp;[P0634R3 Ir para baixo com typename!](https://wg21.link/P0634R3)|Não|
|&nbsp;&nbsp;[P0683R1 Inicializadores de membro padrão para campos de bits](https://wg21.link/P0683R1)|Não|
|&nbsp;&nbsp;[P0692R1 Como relaxar a verificação de acesso em especializações](https://wg21.link/P0692R1)|Não|
|&nbsp;&nbsp;[P0722R3 Exclusão de tamanho eficiente para classes de tamanho variável](https://wg21.link/P0722R3)|Não|
|&nbsp;&nbsp;[P0732R2 Tipos de classe nos parâmetros de modelo sem tipo](https://wg21.link/P0732R2)|Não|
|&nbsp;&nbsp;[P0734R0 Conceitos](https://wg21.link/P0734R0)|Não|
|&nbsp;&nbsp;[P0780R2 Como permitir a expansão de pacote em init-capture de lambda](https://wg21.link/P0780R2)|Não|
|&nbsp;&nbsp;[P0806R2 Substituir captura implícita desta via \[=\]](https://wg21.link/P0806R2)|Não|
|&nbsp;&nbsp;[P0840R2 Atributo \[\[no_unique_address\]\] ](https://wg21.link/P0840R2)|Não|
|&nbsp;&nbsp;[P0857R0 Correção de lacunas de funcionalidade em restrições](https://wg21.link/P0857R0)|Não|
|&nbsp;&nbsp;[P0892R2 Condicional explícita](https://wg21.link/P0892R2)|Não|
|&nbsp;&nbsp;[P0912R5 Corrotinas](https://wg21.link/P0912R5)|Não|
|&nbsp;&nbsp;[P0960R3 Permitir agregações de inicialização de uma lista de valores entre parênteses](https://wg21.link/P0960R3)|Não|
|&nbsp;&nbsp;[P1002R1 Blocos try-catch em funções constexpr](https://wg21.link/P1002R1)|Não|
|&nbsp;&nbsp;[P1064R0 Como permitir chamadas de função virtual em expressões de constante](https://wg21.link/P1064R0)|Não|
|&nbsp;&nbsp;[P1073R3 Funções imediatas](https://wg21.link/P1073R3)|Não|
|&nbsp;&nbsp;[P1084R2 Requisitos de tipo de retorno de hoje são insuficientes](https://wg21.link/P1084R2)|Não|
|&nbsp;&nbsp;[P1091R3 Como estender as associações estruturadas para serem mais como declarações de variáveis](https://wg21.link/P1091R3)|Não|
|&nbsp;&nbsp;[P1094R2 Namespaces embutidos aninhados](https://wg21.link/P1094R2)|Não|
|&nbsp;&nbsp;[P1103R3 Módulos](https://wg21.link/P1103R3)|Não|
|&nbsp;&nbsp;[P1120R0 Aprimoramentos de consistência para <=> e outros operadores de comparação](https://wg21.link/P1120R0)|Não|
|&nbsp;&nbsp;[P1139R2 Resolver problemas de expressão relacionados ao ISO 10646](https://wg21.link/P1139R2)|Não|
|&nbsp;&nbsp;[P1141R2 Ainda outra abordagem para declarações restritas](https://wg21.link/P1141R2)|Não|
|&nbsp;&nbsp;[P1185R2 \<=\> != ==](https://wg21.link/P1185R2)|Não|
|&nbsp;&nbsp;[P1236R1 Inteiros com sinal são complemento de dois](https://wg21.link/P1236R1)|Não|
|&nbsp;&nbsp;[P1289R1 Controle de acesso nas condições do contrato](https://wg21.link/P1289R1)|Não|
|&nbsp;&nbsp;[P1323R2 Pós-condições do contrato e dedução do tipo de retorno](https://wg21.link/P1323R2)|Não|
|&nbsp;&nbsp;[P1327R1 Como permitir dynamic_cast, polymorphic typeid em expressões constantes](https://wg21.link/P1327R1)|Não|
|&nbsp;&nbsp;[P1353R0 Macros de teste de recurso ausentes](https://wg21.link/P1353R0)|Não|
|&nbsp;&nbsp;[P1381R1 Captura de referência de associações estruturadas](https://wg21.link/P1381R1)|Não|

## <a name="standard-library-features"></a>Recursos da biblioteca padrão

| | |
|---|---|
|__Recursos da biblioteca padrão C++20__|__Com suporte__|
|&nbsp;&nbsp;[P0809R0 Comparar contêineres desordenados](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0809r0.pdf)| VS 2010 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0858R0 Requisitos de iterador constexpr](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0858r0.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0777R1 Como evitar o decaimento desnecessário](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0777r1.pdf)|VS 2017 15.7 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0550R2 remove_cvref](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0550r2.pdf)|VS 2019 16.0 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0318R1 unwrap_reference, unwrap_ref_decay](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0318r1.pdf)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0457R2 starts_with()/ends_with() para basic_string/basic_string_view](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0457r2.html)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0458R2 contains() para contêineres associativos ordenados e não ordenados](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0458r2.html)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0646R1 list/forward_list remove()/remove_if()/unique() retornam size_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0646r1.pdf)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0769R2 shift_left(), shift_right()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0769r2.pdf)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0887R1 type_identity](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0887r1.pdf)|VS 2019 16.1 <sup>[20](#note_20)</sup>|
|&nbsp;&nbsp;[P0019R8 atomic_ref](https://wg21.link/P0019R8)|Não|
|&nbsp;&nbsp; [P0020R6 atomic\<float>, atomic\<double>, atomic\<long double>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0020r6.html)|Não|
|&nbsp;&nbsp;[P0053R7 \<syncstream>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0053r7.pdf)<br/>&nbsp;&nbsp; [P0753R2 Manipuladores osyncstream](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0753r2.pdf)|Não|
|&nbsp;&nbsp;[P0122R7 \<span>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0122r7.pdf)|Não|
|&nbsp;&nbsp;[P0202R3 constexpr para \<algorithm> e exchange()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0202r3.html)|Não|
|&nbsp;&nbsp;[P0339R6 polymorphic_allocator<>](https://wg21.link/P0339R6)|Não|
|&nbsp;&nbsp;[P0340R3 underlying_type amigável de SFINAE](https://wg21.link/P0340R3)|Não|
|&nbsp;&nbsp;[P0355R7 \<chrono> Calendários e fusos horários](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0355r7.html)|Não|
|&nbsp;&nbsp;[P0356R5 bind_front()](https://wg21.link/P0356R5)|Não|
|&nbsp;&nbsp;[P0357R3 Dando suporte aos tipos incompletos em reference_wrapper](https://wg21.link/P0357R3)|Não|
|&nbsp;&nbsp;[P0415R1 constexpr para \<complex> (novamente)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0415r1.html)|Não|
|&nbsp;&nbsp;[P0439R0 classe de enumeração memory_order](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0439r0.html)|Não|
|&nbsp;&nbsp;[P0463R1 endian](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0463r1.html)|Não|
|&nbsp;&nbsp;[P0475R1 Omissão da cópia garantida para construção em trechos](https://wg21.link/P0475R1)|Não|
|&nbsp;&nbsp;[P0476R2 <bit> bit_cast](https://wg21.link/P0476R2)|Não|
|&nbsp;&nbsp;[P0482R6 char8_t: Um tipo para caracteres e cadeia de caracteres UTF-8](https://wg21.link/P0482R6)|Não|
|&nbsp;&nbsp;[P0487R1 Corrigindo operador>>(basic_istream&, CharT*)](https://wg21.link/P0487R1)|Não|
|&nbsp;&nbsp;[P0528R3 Comparação e troca atômica com bits de preenchimento](https://wg21.link/P0528R3)|Não|
|&nbsp;&nbsp;[P0556R3 <bit> ispow2(), ceil2(), floor2(), log2p1()](https://wg21.link/P0556R3)|Não|
|&nbsp;&nbsp;[P0591R4 Funções de utilitário para construção de alocadores para usos](https://wg21.link/P0591R4)|Não|
|&nbsp;&nbsp;[P0600R1 \[\[nodiscard\]\] para o STL, parte 1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0600r1.pdf)|Não|
|&nbsp;&nbsp;[P0608R3 Como melhorar o construtor/atribuição de conversão da variante](https://wg21.link/P0608R3)|Não|
|&nbsp;&nbsp;[P0616R0 Uso de move() em \<numeric>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0616r0.pdf)|Não|
|&nbsp;&nbsp;[P0619R4 Remoção de recursos preteridos pelo C++17 no C++20](https://wg21.link/P0619R4)|Não|
|&nbsp;&nbsp;[P0653R2 to_address()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0653r2.html)|Não|
|&nbsp;&nbsp;[P0655R1 visit<R>()](https://wg21.link/P0655R1)|Não|
|&nbsp;&nbsp;[P0674R1 make_shared() para matrizes](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0674r1.html)|Não|
|&nbsp;&nbsp;[P0718R2 atomic\<shared_ptr\<T>>, atomic\<weak_ptr\<T>>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0718r2.html)|Não|
|&nbsp;&nbsp;[P0738R2 Limpeza de istream_iterator](https://wg21.link/P0738R2)|Não|
|&nbsp;&nbsp;[P0754R2 \<version>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0754r2.pdf)|Não|
|&nbsp;&nbsp;[P0758R1 is_nothrow_convertible](https://wg21.link/P0758R1)|Não|
|&nbsp;&nbsp;[P0767R1 Preterindo is_pod](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0767r1.html)|Não|
|&nbsp;&nbsp;[P0768R1 Suporte à biblioteca para o operador de comparação espaçonave \<=>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0768r1.pdf)|Não|
|&nbsp;&nbsp;[P0771R1 noexcept para Construtor de Movimento de std::function](https://wg21.link/P0771R1)|Não|
|&nbsp;&nbsp;[P0811R3 midpoint(), lerp()](https://wg21.link/P0811R3)|Não|
|&nbsp;&nbsp;[P0879R0 constexpr para funções de troca](https://wg21.link/P0879R0)|Não|
|&nbsp;&nbsp;[P0896R4 \<intervalos\>](https://wg21.link/P0896R4)|Não|
|&nbsp;&nbsp;[P0898R3 Conceitos de biblioteca padrão](https://wg21.link/P0898R3)|Não|
|&nbsp;&nbsp;[P0912R5 Suporte à biblioteca para corrotinas](https://wg21.link/P0912R5)|Não|
|&nbsp;&nbsp;[P0919R3 Pesquisa heterogênea por contêineres não ordenados](https://wg21.link/P0919R3)|Não|
|&nbsp;&nbsp;[P0920R2 Pesquisa de valor de hash pré-calculado](https://wg21.link/P0920R2)|Não|
|&nbsp;&nbsp;[P0935R0 Como eliminar construtores padrão desnecessariamente explícitos](https://wg21.link/P0935R0)|Não|
|&nbsp;&nbsp;[P0966R1 string::reserve() Não deve ser reduzido](https://wg21.link/P0966R1)|Não|
|&nbsp;&nbsp;[P1001R2 execution::unseq](https://wg21.link/P1001R2)|Não|
|&nbsp;&nbsp;[P1006R1 constexpr para pointer_traits<T*>::pointer_to()](https://wg21.link/P1006R1)|Não|
|&nbsp;&nbsp;[P1007R3 assume_aligned()](https://wg21.link/P1007R3)|Não|
|&nbsp;&nbsp;[P1020R1 Criação de ponteiro inteligente com inicialização padrão](https://wg21.link/P1020R1)|Não|
|&nbsp;&nbsp;[P1023R0 constexpr para comparações de std::array](https://wg21.link/P1023R0)|Não|
|&nbsp;&nbsp;[P1032R1 constexpr diversos](https://wg21.link/P1032R1)|Não|
|&nbsp;&nbsp;[P1165R1 Propagando consistentemente alocadores com estado no operador+() de basic_string](https://wg21.link/P1165R1)|Não|
|&nbsp;&nbsp;[P1209R0 erase_if(), erase()](https://wg21.link/P1209R0)|Não|
|&nbsp;&nbsp;[P1227R2 std::ssize() com sinal, span::size() sem sinal](https://wg21.link/P1227R2)|Não|
|&nbsp;&nbsp;[P1285R0 Como melhorar requisitos de integridade para características de tipo](https://wg21.link/P1285R0)|Não|
|&nbsp;&nbsp;[P1357R1 is_bounded_array, is_unbounded_array](https://wg21.link/P1357R1)|Não|
|__Recursos da biblioteca padrão C++17__|__Com suporte__|
|&nbsp;&nbsp;[LWG 2221 Operador de saída formatado para nullptr](https://cplusplus.github.io/LWG/issue2221)|VS 2019 16.1|
|&nbsp;&nbsp;[N3911 void_t](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3911.pdf)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4089 Conversões seguras em unique_ptr\<T[]>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4089.pdf)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4169 invoke()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4169.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4190 Removendo auto_ptr, random_shuffle() e \<itens functional>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4190.htm) antigos|VS 2015 <sup>[rem](#note_rem)</sup>|
|&nbsp;&nbsp;[N4258 Limpezas de noexcept](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4258.pdf)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4259 uncaught_exceptions()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4259.pdf)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4277 reference_wrapper facilmente copiado](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4277.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4279 insert_or_assign()/try_emplace() para map/unordered_map](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4279.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4280 size(), empty(), data()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4280.pdf)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4366 Atribuição unique_ptr de restrição precisa](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4366.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4387 Melhorando o par e a tupla](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4387.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4389 bool_constant](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4389.html)|VS 2015 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4508 shared_mutex (sem tempo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4508.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4510 Dando suporte a tipos incompletos em vector/list/forward_list](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4510.html)|VS 2013 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: \<algorithm> sample()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#alg.random.sample)|VS 2017 15.0|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<any>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#any)|VS 2017 15.0|
|&nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: \<memory_resource>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#memory.resource.synop)<br/>&nbsp;&nbsp;[P0337R0 Excluindo a atribuição polymorphic_allocator](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0337r0.html)|VS 2017 15.6|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<optional>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#optional)|VS 2017 15.0|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<string_view>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#string.view)|VS 2017 15.0|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<tuple> apply()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#tuple)|VS 2017 15.0|
|&nbsp;&nbsp;[Conceitos básicos da biblioteca N4562: Pesquisa Boyer-Moore()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#func.searchers.boyer_moore)<br/>&nbsp;&nbsp;[P0253R1 Corrigindo tipos de retorno da ferramenta de pesquisa](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0253r1.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0003R5 Removendo Especificações de Exceção Dinâmica](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0004R1 Removendo aliases iostreams preteridos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0004r1.html)|VS 2015.2 <sup>[rem](#note_rem)</sup>|
|&nbsp;&nbsp;[P0005R4 not_fn()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0005r4.html)<br/>&nbsp;&nbsp;[P0358R1 Correções para not_fn()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0358r1.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0006R0 Modelos de variável para características de tipo (is_same_v, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0006r0.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0007R1 as_const()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0007r1.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0013R1 Características de tipo do operador lógico (conjunção, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0013r1.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0024R2 Algoritmos paralelos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html)<br/>&nbsp;&nbsp;[P0336R1 Renomeando políticas de execução paralela](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0336r1.pdf)<br/>&nbsp;&nbsp;[P0394R4 Algoritmos paralelos devem conter terminate() para exceções](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0394r4.html)<br/>&nbsp;&nbsp;[P0452R1 Unificar algoritmos paralelos \<numeric>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0452r1.html)|VS 2017 15.7|
|&nbsp;&nbsp;[P0025R1 clamp()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0025r1.html)|VS 2015.3|
|&nbsp;&nbsp;[P0030R1 hypot(x, y, z)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0030r1.pdf)|VS 2017 15.7|
|&nbsp;&nbsp;[P0031R0 constexpr para \<array> (Novamente) e \<iterator>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0031r0.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0032R3 Interface homogênea de variant/any/optional](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0032r3.pdf)|VS 2017 15.0|
|&nbsp;&nbsp;[P0033R1 Reescrevendo enable_shared_from_this](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0033r1.html)|VS 2017 15.5 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0040R3 Estendendo as ferramentas de gerenciamento de memória](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0040r3.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0063R3 Biblioteca Padrão C11](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0063r3.html)|VS 2015 <sup>[C11](#note_C11), [14](#note_14)</sup>|
|&nbsp;&nbsp;[P0067R5 Conversões de cadeia de caracteres elementar](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html)|VS 2017 15.7 <sup>[charconv](#note_charconv)</sup>|
|&nbsp;&nbsp;[P0074R0 owner_less\<>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0074r0.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0077R2 is_callable, is_nothrow_callable](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0077r2.html)|VS 2017 15.0|
|&nbsp;&nbsp;[P0083R3 Unindo mapas e conjuntos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3.pdf)<br/>&nbsp;&nbsp;[P0508R0 Esclarecendo insert_return_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0508r0.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0084R2 Tipo de retorno emplace](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0084r2.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0088R3 \<variant>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0088r3.html)|VS 2017 15.0|
|&nbsp;&nbsp;[P0092R1 \<chrono> floor(), ceil(), round(), abs()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0092r1.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0152R1 atomic::is_always_lock_free](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0152r1.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0154R1 hardware_destructive_interference_size, etc.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0154r1.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0156R0 lock_guard variadic](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0156r0.html)|VS 2015.2 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0156R2 Como renomear Variadic lock\_guard para scoped\_lock](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0156r2.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0163R0 shared_ptr::weak_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0163r0.html)|VS 2017 15.0|
|&nbsp;&nbsp;[P0174R2 Preterindo partes residuais da biblioteca](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0174r2.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0185R1 is_swappable, is_nothrow_swappable](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0185r1.html)|VS 2015.3|
|&nbsp;&nbsp;[P0209R2 make_from_tuple()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0209r2.pdf)|VS 2017 15.0|
|&nbsp;&nbsp;[P0218R1 \<filesystem>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0218r1.html)<br/>&nbsp;&nbsp;[P0219R1 Caminhos relativos para o sistema de arquivos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0219r1.html)<br/>&nbsp;&nbsp;[P0317R1 Cache de entrada de diretório para sistema de arquivos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0317r1.html)<br/>&nbsp;&nbsp;[P0392R0 Dando suporte a string_view em caminhos do sistema de arquivos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0392r0.pdf)<br/>&nbsp;&nbsp;[P0430R2 Suporte a sistemas de arquivos não POSIX](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0430r2.pdf)<br/>&nbsp;&nbsp;[P0492R2 Resolução de comentários NB para o sistema de arquivos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0492r2.html)|VS 2017 15.7 <sup>[E](#note_E)</sup>|
|&nbsp;&nbsp;[P0220R1 Conceitos básicos da biblioteca V1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html)|VS 2017 15.6|
|&nbsp;&nbsp;[P0226R1 Funções matemáticas especiais](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0226r1.pdf)|VS 2017 15.7|
|&nbsp;&nbsp;[P0254R2 Integrando string_view e std::string](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0254r2.pdf)|VS 2017 15.0|
|&nbsp;&nbsp;[P0258R2 has_unique_object_representations](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0258r2.html)|VS 2017 15.3 <sup>[G](#note_G)</sup>|
|&nbsp;&nbsp;[P0272R1 Non-const basic_string::data()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0272r1.html)|VS 2015.3|
|&nbsp;&nbsp;[P0295R0 gcd(), lcm()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0295r0.pdf)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0298R3 std::byte](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0298r3.pdf)|VS 2017 15.3 <sup>[17](#note_17),&nbsp;[byte](#note_byte)</sup>|
|&nbsp;&nbsp;[P0302R1 Removendo o suporte ao alocador em std::function](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0302r1.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0307R2 Criando Greater Equal opcional novamente](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0307r2.pdf)|VS 2017 15.0|
|&nbsp;&nbsp;[P0393R3 Variante Greater Equal](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0393r3.html)|VS 2017 15.0|
|&nbsp;&nbsp;[P0403R1 UDLs para \<string_view> ("meow"sv, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0403r1.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0414R2 shared_ptr\<T[]>, shared_ptr\<T[N]>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0414r2.html)<br/>&nbsp;&nbsp;[P0497R0 Corrigindo shared_ptr para matrizes](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0497r0.html)|VS 2017 15.5 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0418R2 Requisitos de compare_exchange memory_order atômico](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0418r2.html)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0426R1 constexpr para char_traits](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0426r1.html)|VS 2017 15.7|
|&nbsp;&nbsp;[P0433R2 Integração da dedução de modelo para modelos de classe na Biblioteca Padrão](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0433r2.html)<br/>&nbsp;&nbsp;[P0739R0 Como melhorar a integração da dedução de argumento de modelo de classe na Biblioteca Padrão](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0739r0.html)|VS 2017 15.7|
|&nbsp;&nbsp;[P0435R1 Revisando common_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0435r1.pdf)<br/>&nbsp;&nbsp;[P0548R1 Ajustar o tipo\_comum e a duração](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0548r1.pdf)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0504R0 Revisitando in_place_t/in_place_type_t\<T>/in_place_index_t\<I>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0504r0.html)|VS 2017 15.0|
|&nbsp;&nbsp;[P0505R0 constexpr para \<chrono> (Novamente)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0505r0.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0510R0 Rejeitando variantes de nada, matrizes, referências e tipos incompletos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0510r0.html)|VS 2017 15.0|
|&nbsp;&nbsp;[P0513R0 Hash de suspeita](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0513r0.pdf)<br/>&nbsp;&nbsp;[P0599R1 hash de noexcept](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0599r1.pdf)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0516R0 Marcando a cópia de shared_future como noexcept](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0516r0.html)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0517R0 Construindo future_error com base em future_errc](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0517r0.html)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0521R0 Preterindo shared_ptr::unique()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0521r0.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0558R1 Resolução de inconsistências de classe base nomeadas atomic\<T>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0558r1.pdf)|VS 2017 15.3 <sup>[14](#note_14)</sup>|
|&nbsp;&nbsp;[P0595R2 std::is_constant_evaluated()](https://wg21.link/P0595R2)|Não|
|&nbsp;&nbsp;[P0602R4 Propagação da trivialidade Copiar/Mover em variante/opcional](https://wg21.link/P0602R4)|VS 2017 15.3<sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0604R0 Como alterar is\_callable/result\_of para invoke\_result, is\_invocable, is\_nothrow\_invocable](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0604r0.html)|VS 2017 15.3 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0607R0 Variáveis embutidas para a Biblioteca Padrão](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0607r0.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0618R0 Substituição de \<codecvt>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0618r0.html)|VS 2017 15.5 <sup>[17](#note_17)</sup>|
|&nbsp;&nbsp;[P0682R1 Reparação de conversões da cadeia de caracteres elementares](https://wg21.link/P0682R1)|VS 2015 15.7 <sup>[17](#note_17)</sup>|
|__Recursos da biblioteca padrão C++14__|__Com suporte__|
|&nbsp;&nbsp;[N3462 result_of amigável do SFINAE](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3462.html)|VS 2015.2|
|&nbsp;&nbsp;[N3302 constexpr para \<complex>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3302.html)|VS 2015|
|&nbsp;&nbsp;[N3469 constexpr para \<chrono>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3469.html)|VS 2015|
|&nbsp;&nbsp;[N3470 constexpr para \<array>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3470.html)|VS 2015|
|&nbsp;&nbsp;[N3471 constexpr para \<initializer_list>, \<tuple>, \<utility>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3471.html)|VS 2015|
|&nbsp;&nbsp;[N3545 integral_constant::operator()()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3545.pdf)|VS 2015|
|&nbsp;&nbsp;[N3642 UDLs para \<chrono>, \<string> (1729ms, "meow"s, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3642.pdf)|VS 2015|
|&nbsp;&nbsp;[N3644 Iteradores de avanço nulo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3644.pdf)|VS 2015|
|&nbsp;&nbsp;[N3654 quoted()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3654.html)|VS 2015|
|&nbsp;&nbsp;[N3657 Pesquisa associativa heterogênea](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3657.htm)|VS 2015|
|&nbsp;&nbsp;[N3658 integer_sequence](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3658.html)|VS 2015|
|&nbsp;&nbsp;[N3659 shared_mutex (com tempo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3659.html)|VS 2015|
|&nbsp;&nbsp;[N3668 exchange()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3668.html)|VS 2015|
|&nbsp;&nbsp;[N3669 Corrigindo funções membro constexpr sem const](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3669.pdf)|VS 2015|
|&nbsp;&nbsp;[N3670 get\<T>()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3670.html)|VS 2015|
|&nbsp;&nbsp;[N3671 equal(), is_permutation(), mismatch() de intervalo duplo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3671.html)|VS 2015|
|&nbsp;&nbsp;[N3778 Desalocação Dimensionada](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3778.html)|VS 2015|
|&nbsp;&nbsp;[N3779 UDLs para \<complex> (3.14i, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3779.pdf)|VS 2015|
|&nbsp;&nbsp;[N3789 constexpr para \<functional>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3789.htm)|VS 2015|
|&nbsp;&nbsp;[N3887 tuple_element_t](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3887.pdf)|VS 2015|
|&nbsp;&nbsp;[N3891 Renomeando shared_mutex (com tempo) como shared_timed_mutex](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3891.htm)|VS 2015|
|&nbsp;&nbsp;[N3346 Requisitos mínimos de elementos contêiner](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3346.pdf)|VS 2013|
|&nbsp;&nbsp;[N3421 Functores de operador transparentes (less\<>, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3421.htm)|VS 2013|
|&nbsp;&nbsp;[N3655 Modelos de alias para \<type_traits> (decay_t, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3655.pdf)|VS 2013|
|&nbsp;&nbsp;[N3656 make_unique()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3656.htm)|VS 2013|

Um grupo de documentos listados juntos indica que um recurso foi votado no Padrão e, em seguida, um ou mais documentos para melhorar ou expandir esse recurso também foram votados. Esses recursos são implementados juntos.

### <a name="supported-values"></a>Valores com suporte

__Não__ significa ainda não implementado.<br/>
__Parcial__ significa que a implementação está incompleta. Para obter mais detalhes, consulte a seção Observações.<br/>
__VS 2010__ indica os recursos que tem suporte no Visual Studio 2010.<br/>
__VS 2013__ indica os recursos que tem suporte no Visual Studio 2013.<br/>
__VS 2015__ indica os recursos com suporte no Visual Studio 2015 RTW.<br/>
__VS 2015.2__ e __VS 2015.3__ indicam os recursos com suporte no Visual Studio 2015 Atualização 2 e no Visual Studio 2015 Atualização 3, respectivamente.<br/>
__VS 2017 15.0__ indica os recursos com suporte no Visual Studio 2017 versão 15.0 (RTW).<br/>
__VS 2017 15.3__ indica os recursos com suporte no Visual Studio 2017 versão 15.3.<br/>
__VS 2017 15.5__ indica os recursos com suporte no Visual Studio 2017 versão 15.5.<br/>
__VS 2017 15.7__ indica os recursos com suporte no Visual Studio 2017 versão 15.7.<br/>
__VS 2019 16.0__ indica os recursos com suporte no Visual Studio 2019 versão 16.0 (RTW).<br/>
__VS 2019 16.1__ indica os recursos com suporte no Visual Studio 2019 versão 16.1.

### <a name="notes"></a>Observações

<a name="note_A"></a>__A__ No modo [/std:c++14](../build/reference/std-specify-language-standard-version.md), especificações de exceções dinâmicas permanecem não implementadas, e `throw()` ainda é tratado como um sinônimo para `__declspec(nothrow)`. No C++17, as especificações de exceções dinâmicas foram, em grande parte, removidas por P0003R5, deixando um vestígio: `throw()` foi preterido e obrigado a se comportar como um sinônimo de `noexcept`. No modo [/std:c++17](../build/reference/std-specify-language-standard-version.md), agora o MSVC está em conformidade com o padrão, fornecendo a `throw()` o mesmo comportamento de `noexcept`, ou seja, a imposição por meio de encerramento.

A opção do compilador [/Zc:noexceptTypes](../build/reference/zc-noexcepttypes.md) solicita nosso antigo comportamento de `__declspec(nothrow)`. É provável que `throw()` seja removido em C++20. Para ajudar com a migração do código em resposta a essas alterações no padrão e nossa implementação, novos avisos do compilador para problemas de especificação de exceção foram adicionados em [/std:c++17](../build/reference/std-specify-language-standard-version.md) e [/permissive-](../build/reference/permissive-standards-conformance.md).

<a name="note_B"></a>__B__ Com suporte no modo [/permissive-](../build/reference/permissive-standards-conformance.md) no Visual Studio 2017 versão 15.7. Veja [Suporte à pesquisa de nome em duas fases chega ao MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/09/11/two-phase-name-lookup-support-comes-to-msvc/) para obter mais informações.

<a name="note_C"></a>__C__ O suporte do compilador às regras do Pré-processador C99 está incompleto no Visual Studio 2017. Há suporte para macros variadic, mas existem diversos bugs no comportamento do pré-processador. Estamos revisando o pré-processador e enviaremos experimentalmente essas alterações com o modo [/ permissive-](../build/reference/permissive-standards-conformance.md) em breve.

<a name="note_D"></a>__D__ Com suporte em [/std:c++14](../build/reference/std-specify-language-standard-version.md) com um aviso suprimível, C4984.

<a name="note_E"></a>__E__ Essa é uma implementação completamente nova, incompatível com a versão `std::experimental` anterior, que precisava de suporte a symlink, correções de bugs e alterações no comportamento exigido pelo padrão. Atualmente, a inclusão de \<filesystem> fornece o novo `std::filesystem` e o `std::experimental::filesystem` anterior, e a inclusão de \<experimental/filesystem> fornece somente a implementação antiga experimental. A implementação experimental será REMOVIDA na próxima versão ABI recente das bibliotecas.

<a name="note_G"></a>__G__ Compatível com um compilador intrínseco.

<a name="note_14"></a>__14__ Esses recursos do C++17/20 estarão sempre habilitados, mesmo quando [/std:c++14](../build/reference/std-specify-language-standard-version.md) (o padrão) estiver especificado. Isso ocorre porque o recurso foi implementado antes da introdução das opções **/std** ou porque a implementação condicional era complexa de maneira indesejável.

<a name="note_17"></a>__17__ Esses recursos estão habilitados pela opção do compilador [/std:c++17](../build/reference/std-specify-language-standard-version.md) (ou [/std:c++latest](../build/reference/std-specify-language-standard-version.md)).

<a name="note_20"></a>__20__ Esses recursos são habilitados pela opção do compilador [/std:c++latest](../build/reference/std-specify-language-standard-version.md). Quando a implementação de C++20 estiver concluída, uma nova opção do compilador **/std:c++20** será adicionada, na qual esses recursos também estarão disponíveis.

<a name="note_byte"></a>__byte__ `std::byte` é habilitado por [/std:c++17](../build/reference/std-specify-language-standard-version.md) (ou [/std:c++latest](../build/reference/std-specify-language-standard-version.md)), mas, como ele pode entrar em conflito com os cabeçalhos do SDK do Windows em alguns casos, ele tem uma macro de recusa refinada. Ele pode ser desabilitado, definindo `_HAS_STD_BYTE` como `0`.

<a name="note_C11"></a>__C11__ O Universal CRT implementou as partes da Biblioteca Padrão do C11 que são exigidas pelo C++17, com exceção de especificadores de conversão alternativa de E/S do C99 `strftime()`, modo exclusivo do C11 `fopen()` e C11 `aligned_alloc()`. O segundo é improvável de ser implementado, porque C11 especificou `aligned_alloc()` de forma que seja incompatível com a implementação da Microsoft do `free()`, ou seja, que `free()` deve ser capaz de lidar com alocações altamente alinhadas.

<a name="note_rem"></a>__rem__ Recursos removidos quando a opção do compilador [/std:c++17](../build/reference/std-specify-language-standard-version.md) (ou [/std:c++latest](../build/reference/std-specify-language-standard-version.md)) for especificada. Esses recursos podem ser habilitados novamente de modo a facilitar a transição para os modos de idioma mais recentes pelo uso destas macros: `_HAS_AUTO_PTR_ETC`, `_HAS_FUNCTION_ALLOCATOR_SUPPORT`, `_HAS_OLD_IOSTREAMS_MEMBERS` e `_HAS_UNEXPECTED`.

<a name="note_charconv"></a>__charconv__ `from_chars()` e `to_chars()` estão disponíveis para números inteiros. A linha do tempo para o ponto flutuante `from_chars()` e ponto flutuante `to_chars()` é da seguinte maneira:
- VS 2017 15.7: Inteiro `from_chars()` e `to_chars()`.
- VS 2017 15.8: Ponto flutuante `from_chars()`.
- VS 2017 15.9: as sobrecargas do ponto flutuante `to_chars()` para decimal mais curto.
- VS 2019 16.0: as sobrecargas do ponto flutuante `to_chars()` para hexadecimal mais curto e hexadecimal de precisão.
- VS 2019 16.2: as sobrecargas do ponto flutuante `to_chars()` para precisão fixa e precisão científica.
- Ainda não implementado: a sobrecarga do ponto flutuante `to_chars()` para precisão geral. 

<a name ="note_parallel"></a> __parallel__ Biblioteca de algoritmos paralelos do C++17 concluída. Isso não significa que cada algoritmo é paralelizado em todos os casos; os algoritmos mais importantes foram paralelizados, e assinaturas de política de execução são fornecidas mesmo se os algoritmos não foram paralelizados. O cabeçalho interno central da nossa implementação, yvals_core.h, contém as seguintes "Notas de algoritmos paralelos": O C++ permite a implementação de algoritmos paralelos como chamadas para os algoritmos seriais.  Essa implementação paraleliza várias chamadas de algoritmo comum, mas não todas.

Os seguintes algoritmos são paralelizados:

- `adjacent_difference`, `adjacent_find`, `all_of`, `any_of`, `count`, `count_if`, `equal`, `exclusive_scan`, `find`, `find_end`, `find_first_of`, `find_if`, `find_if_not`, `for_each`, `for_each_n`, `inclusive_scan`, `is_heap`, `is_heap_until`, `is_partitioned`, `is_sorted`, `is_sorted_until`, `mismatch`, `none_of`, `partition`, `reduce`, `remove`, `remove_if`, `replace`, `replace_if`, `search`, `search_n`, `set_difference`, `set_intersection`, `sort`, `stable_sort`, `transform`, `transform_exclusive_scan`, `transform_inclusive_scan`, `transform_reduce`

Os seguintes itens não estão paralelizados no momento:

- Nenhuma melhoria aparente no desempenho de paralelismo em hardware de destino; todos os algoritmos que simplesmente copiam ou permutam elementos sem nenhuma ramificação são tipicamente limitados por largura de banda de memória:
  - `copy`, `copy_n`, `fill`, `fill_n`, `move`, `reverse`, `reverse_copy`, `rotate`, `rotate_copy`, `shift_left`, `shift_right`, `swap_ranges`
- Há confusão sobre requisitos de paralelismo de usuário. Provavelmente na categoria acima mesmo assim:
  - `generate`, `generate_n`
- Paralelismo efetivo com suspeita de não ser viável:
  - `partial_sort`, `partial_sort_copy`
- Ainda não avaliado; o paralelismo pode ser implementado em uma versão futura e acredita-se que seja benéfico:
  - `copy_if`, `includes`, `inplace_merge`, `lexicographical_compare`, `max_element`, `merge`, `min_element`, `minmax_element`, `nth_element`, `partition_copy`, `remove_copy`, `remove_copy_if`, `replace_copy`, `replace_copy_if`, `set_symmetric_difference`, `set_union`, `stable_partition`, `unique`, `unique_copy`

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
[Aprimoramentos de conformidade do C++ no Visual Studio](cpp-conformance-improvements.md)<br/>
[Novidades do Visual C++ no Visual Studio](what-s-new-for-visual-cpp-in-visual-studio.md)<br/>
[Histórico de alterações de 2003 a 2015 do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)<br/>
[O que há de novo no Visual C++ de 2003 até 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md)<br/>
[Blog da equipe do C++](https://devblogs.microsoft.com/cppblog/)

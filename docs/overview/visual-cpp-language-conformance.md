---
title: Tabela de conformidade com a linguagem Microsoft C++
description: Tabela de atualizações de conformidade Microsoft C++ pela versão do Visual Studio.
ms.date: 03/17/2020
ms.technology: cpp-language
ms.assetid: 475da6e9-0d78-4b4e-bd23-f41c406c4efe
author: corob-msft
ms.author: corob
ms.openlocfilehash: 18f8db28fab83f795baced82a346f07d73256716
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365231"
---
# <a name="microsoft-c-language-conformance-table"></a>Tabela de conformidade com a linguagem Microsoft C++

A conformidade de padrões para o compilador Microsoft C++ no Visual Studio (MSVC) é um trabalho em andamento. Aqui está um resumo da nossa linguagem ISO Standard C++ e conformidade de biblioteca pela versão do Visual Studio. Cada compilador e o nome do recurso de biblioteca padrão vinculam-se ao documento de proposta ISO Standard C++ que descreve o recurso, se um estiver disponível no momento da publicação. A coluna **Suportada** lista a versão do Visual Studio na qual o suporte para o recurso apareceu pela primeira vez.

Para obter detalhes sobre o Visual Studio 2017 ou visual Studio 2019 MSVC melhorias de conformidade, consulte [melhorias de conformidade C++ no Visual Studio](cpp-conformance-improvements.md). Para obter uma lista de outras alterações, consulte [o que há de novo para visual C++ no Visual Studio](what-s-new-for-visual-cpp-in-visual-studio.md). Para alterações de compatibilidade em versões anteriores, consulte [Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md) e [Novidades do Visual C++ de 2003 a 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md). Para saber mais sobre as últimas notícias da equipe do C++, visite o [blog da equipe do C++](https://devblogs.microsoft.com/cppblog/).

> [!NOTE]
> Não há alterações da falha do binário entre o Visual Studio 2015, Visual Studio 2017 e Visual Studio 2019. Para obter mais informações, consulte [a compatibilidade binária C++ entre o Visual Studio 2015, 2017 e 2019](../porting/binary-compat-2015-2017.md)

## <a name="compiler-features"></a>Recursos do compilador

|  |  |
|--|--|
| __C++03/11 Características principais do idioma__ | __Com suporte__ |
| &nbsp;&nbsp;O restante | VS 2015 <sup>[A](#note_A)</sup> |
| &nbsp;&nbsp;Pesquisa de nome de duas fases | VS 2017 15.7 <sup>[B](#note_B)</sup> |
| &nbsp;&nbsp;[N2634 Expressão SFINAE](https://wg21.link/N2634) | VS 2017 15.7 |
| &nbsp;&nbsp;[N1653 Pré-processador C99](https://wg21.link/N1653) | Parcial <sup> [C](#note_C)</sup> |
| __C++14 Características principais do idioma__ | __Com suporte__ |
| &nbsp;&nbsp;[N3323 Palavras ajustadas para conversões contextuais](https://wg21.link/N3323) | VS 2013 |
| &nbsp;&nbsp;[N3472 Literais binários](https://wg21.link/N3472) | VS 2015 |
| &nbsp;&nbsp;[N3638 Tipos de retorno auto e decltype(auto)](https://wg21.link/n3638) | VS 2015 |
| &nbsp;&nbsp;[N3648 Capturas de init](https://wg21.link/n3648) | VS 2015 |
| &nbsp;&nbsp;[N3649 Lambdas genéricos](https://wg21.link/n3649) | VS 2015 |
| &nbsp;&nbsp;[Atributo preterido \[ \[\] \] n3760](https://wg21.link/n3760) | VS 2015 |
| &nbsp;&nbsp;[N3778 Desalocação dimensionada](https://wg21.link/n3778) | VS 2015 |
| &nbsp;&nbsp;[N3781 Separadores de dígito](https://wg21.link/n3781) | VS 2015 |
| &nbsp;&nbsp;[N3651 Modelos de variável](https://wg21.link/n3651) | VS 2015.2 |
| &nbsp;&nbsp;[N3652 Constexpr estendido](https://wg21.link/n3652) | VS 2017 15.0 |
| &nbsp;&nbsp;[N3653 Inicializadores de membro padrão para agregações](https://wg21.link/n3653) | VS 2017 15.0 |
| __C++17 Características principais do idioma__ | __Com suporte__ |
| &nbsp;&nbsp;[N4086 Removendo trígrafos](https://wg21.link/n4086) | VS 2010 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N3922 Novas regras para automático com listas de inicialização entre chaves](https://wg21.link/n3922) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4051 Nome de tipo em parâmetros de modelo do modelo](https://wg21.link/n4051) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4266 Atributos para namespaces e enumeradores](https://wg21.link/n4266) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4267 Literais de caracteres u8](https://wg21.link/n4267) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4230 Definições de namespace aninhado](https://wg21.link/n4230) | VS 2015.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[N3928 Static_assert resumido](https://wg21.link/n3928) | VS 2017 15.0 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0184R0 Range-based for-loops generalizado](https://wg21.link/p0184r0) | VS 2017 15.0 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[Atributo p0188R1 \[ \[\] \]](https://wg21.link/p0188r1) | VS 2017 15.0 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0001R1 Removendo a palavra-chave de registro](https://wg21.link/p0001r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0002R1 Removendo operator++ de bool](https://wg21.link/p0002r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0018R3 Capturando *this por valor](https://wg21.link/p0018r3) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0028R4 Usando namespaces de atributo sem repetição](https://wg21.link/p0028r4) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[has_include P0061R1 \_ \_](https://wg21.link/p0061r1) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0138R2 Inicialização de lista direta de enumerações fixas de inteiros](https://wg21.link/p0138r2) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0170R1 Lambdas de constexpr](https://wg21.link/p0170r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[Atributo nodiscard \[ \[\] \] p0189R1](https://wg21.link/p0189r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[Atributo \[ \[maybe_unused\] \] P0212R1](https://wg21.link/p0212r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0217R3 Associações estruturadas](https://wg21.link/p0217r3) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0292R2 Instruções constexpr if](https://wg21.link/p0292r2) | VS 2017 15.3 <sup>[D](#note_D)</sup> |
| &nbsp;&nbsp;[P0305R1 Instruções de seleção com inicializadores](https://wg21.link/p0305r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0245R1 Literais de hexfloat](https://wg21.link/p0245r1) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[N4268 Permitindo mais argumentos de modelo sem tipo](https://wg21.link/n4268) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[N4295 Expressões de dobra](https://wg21.link/n4295) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0003R5 Removendo especificações de exceção dinâmica](https://wg21.link/p0003r5) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0012R1 Adicionando noexcept ao sistema de tipos](https://wg21.link/p0012r1) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0035R4 Alocação de memória dinâmica com excesso de alinhamento](https://wg21.link/p0035r4) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0386R2 Variáveis embutidas](https://wg21.link/p0386r2) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0522R0 Fazendo a correspondência de parâmetros de modelo do modelo com argumentos compatíveis](https://wg21.link/p0522r0) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0036R0 Removendo algumas dobras unárias vazias](https://wg21.link/p0036r0) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[N4261 Corrigindo conversões de qualificação](https://wg21.link/n4261) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0017R1 Inicialização de agregação estendida](https://wg21.link/p0017r1) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0091R3 Dedução de argumento de modelo para modelos de classe](https://wg21.link/p0091r3)<br/>&nbsp;&nbsp;[P0512R0 Problemas de dedução de argumento de modelo de classe](https://wg21.link/p0512r0) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0127R2 Declarando parâmetros de modelo sem tipo com automático](https://wg21.link/p0127r2) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0135R1 Garantia de elisão de cópia](https://wg21.link/p0135r1) | VS 2017 15.6 |
| &nbsp;&nbsp;[P0136R1 Reescrevendo construtores de herança](https://wg21.link/p0136r1) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0137R1 std::launder](https://wg21.link/p0137r1) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0145R3 Refinando a ordem de avaliação de expressão](https://wg21.link/p0145r3)<br/>&nbsp;&nbsp;[P0400R0 Ordem de avaliação de argumentos de função](https://wg21.link/p0400r0) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0195R2 Expansões de pacote em declarações using](https://wg21.link/p0195r2) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0283R2 Ignorando atributos não reconhecidos](https://wg21.link/p0283r2) | VS 2015 <sup>[14](#note_14)</sup> |
| __C++17 Recursos de linguagem principal (relatórios de defeitos)__ | __Com suporte__ |
| &nbsp;&nbsp;[P0702R1 Corrigindo dedução de argumento de modelo de classe para construtores de lista de inicializadores](https://wg21.link/p0702r1) | VS 2017 15.7 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0961R1 Como relaxar as regras de localização do ponto de personalização de associações estruturadas](https://wg21.link/p0961r1) | VS 2019 16.0 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0969R0 Permitir associações estruturadas para membros acessíveis](https://wg21.link/p0969r0) | VS 2019 16.0 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0588R1 Simplificar captura de lambda implícita](https://wg21.link/p0588r1) | VS 2019 16.4 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P1771R1 \[ \[nodiscard\] \] para construtores](https://wg21.link/p1771r1) | VS 2019 16.4 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P1825R0 Mesclada redação para P0527R1 e P1155R3, movimentos mais implícitos](https://wg21.link/p1825r0) | VS 2019 16.4 <sup> [17](#note_17)</sup> |
| &nbsp;&nbsp;[P0929R2 Como verificar se há tipos de classe abstrata](https://wg21.link/P0929R2) | Não |
| &nbsp;&nbsp;[P0962R2 Relaxar as regras de localização do ponto de personalização do loop range-for](https://wg21.link/p0962r1) | Não |
| &nbsp;&nbsp;[P0859R0 CWG 1581: Quando são definidas as funções do membro constexpr](https://wg21.link/p0859r0) | Não |
| &nbsp;&nbsp;[P1009R2 Dedução de tamanho da matriz em expressões novas](https://wg21.link/P1009R2) | Não |
| &nbsp;&nbsp;[P1286R2 Contra CWG DR1778](https://wg21.link/P1286R2) | Não |
| __C++20 Características principais do idioma__ | __Com suporte__ |
| &nbsp;&nbsp;[P0704R1 Corrigindo ponteiros qualificados por referência de construtores lvalue para membros](https://wg21.link/p0704r1) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P1041R4 Transformar literais de cadeia de caracteres char16_t/char32_t em UTF-16/32](https://wg21.link/P1041R4) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P1330R0 Alteração do membro ativo de uma união dentro de constexpr](https://wg21.link/P1330R0) | VS 2017 15.0 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0972R0 noexcept para \<chrono> zero(), min(), max()](https://wg21.link/P0972R0) | VS 2017 15.7 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0515R3 Comparação de três vias (espaçonave) <=>](https://wg21.link/P0515R3) | VS 2019 16.0 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0941R2 Macros de teste de recurso](https://wg21.link/P0941R2) | VS 2019 16.0 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P1008R1 Como proibir agregações com construtores declarados pelo usuário](https://wg21.link/P1008R1) | VS 2019 16.0 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0329R4 Inicialização designada](https://wg21.link/p0329r4) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0846R0 Modelos de função e ADL que não são visíveis](https://wg21.link/P0846R0) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0409R2 Como permitir a captura de lambda \[=, this\]](https://wg21.link/p0409r2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0428R2 Sintaxe familiar de modelo para lambdas genéricas](https://wg21.link/p0428r2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0624R2 Lambdas padrão stateless construíveis e atribuíveis](https://wg21.link/P0624R2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0780R2 Como permitir a expansão de pacote em init-capture de lambda](https://wg21.link/P0780R2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0806R2 Deprecar captura implícita deste via\[=\]](https://wg21.link/P0806R2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P1120R0 Aprimoramentos de consistência para <=> e outros operadores de comparação](https://wg21.link/P1120R0) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P1185R2 \< = \> != ==](https://wg21.link/P1185R2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0734R0 Conceitos](https://wg21.link/P0734R0) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0857R0 Correção de lacunas de funcionalidade em restrições](https://wg21.link/P0857R0) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1084R2 Requisitos de tipo de retorno de hoje são insuficientes](https://wg21.link/P1084R2) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0892R2 Condicional explícita](https://wg21.link/P0892R2) | VS 2019 16.4 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1091R3 Como estender as associações estruturadas para serem mais como declarações de variáveis](https://wg21.link/P1091R3) | VS 2019 16.4 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1099R5 Usando enum](https://wg21.link/P1099R5) | VS 2019 16.4 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1186R3 Quando você realmente usa\<=>](https://wg21.link/P1186R3) | VS 2019 16.4 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[A nave espacial P1630R1 precisa de um ajuste](https://wg21.link/P1630R1) | VS 2019 16.4 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0306R4 \_ \_Adicionando VA_OPT\_ \_ para omissão de comma e exclusão de ma](https://wg21.link/P0306R4) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0614R1 Com base em intervalo para loops com inicializadores](https://wg21.link/P0614R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0683R1 Inicializadores de membro padrão para campos de bits](https://wg21.link/P0683R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1002R1 Blocos try-catch em funções constexpr](https://wg21.link/P1002R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1161R3 Deprecate usos do operador de comma em expressões de subscrição](https://wg21.link/P1161R3) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1301R4 \[ \[nodiscard ("mensagem")\]\]](https://wg21.link/P1301R4) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1703R1 Reconhecer as importações da unidade de cabeçalho requer pré-processamento total](https://wg21.link/P1703R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1946R0 Permitir comparações padrão por valor](https://wg21.link/P1946R0) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0641R2 Incompatibilidade de const com o construtor de cópia padrão](https://wg21.link/P0641R2) | Parcial |
| &nbsp;&nbsp;[P0912R5 Corrotinas](https://wg21.link/P0912R5) | Parcial |
| &nbsp;&nbsp;[P1103R3 Módulos](https://wg21.link/P1103R3) | Parcial |
| &nbsp;&nbsp;[P0315R4 Como permitir lambdas em contextos não avaliados](https://wg21.link/P0315R4) | Não |
| &nbsp;&nbsp;[P0388R4 Conversão de permissão para matrizes de limite desconhecido](https://wg21.link/P0388R4) | Não |
| &nbsp;&nbsp;[P0479R5 \[ \[\] \] atributos prováveis \[ \[e improváveis\] \]](https://wg21.link/P0479R5) | Não |
| &nbsp;&nbsp;[P0634R3 Ir para baixo com typename!](https://wg21.link/P0634R3) | Não |
| &nbsp;&nbsp;[P0692R1 Como relaxar a verificação de acesso em especializações](https://wg21.link/P0692R1) | Não |
| &nbsp;&nbsp;[P0722R3 Exclusão de tamanho eficiente para classes de tamanho variável](https://wg21.link/P0722R3) | Não |
| &nbsp;&nbsp;[P0732R2 Tipos de classe nos parâmetros de modelo sem tipo](https://wg21.link/P0732R2) | Não |
| &nbsp;&nbsp;[Interação p0735R1 de memory_order_consume com sequências de lançamento](https://wg21.link/P0735R1) | Não |
| &nbsp;&nbsp;[P0784R7 Mais recipientes constexpr](https://wg21.link/P0784R7) | Não |
| &nbsp;&nbsp;[Atributo de no_unique_address \[ \[\] \] P0840R2](https://wg21.link/P0840R2) | Não |
| &nbsp;&nbsp;[P0848R3 Condicionalmente trivial funções especiais de membro](https://wg21.link/P0848R3) | Não |
| &nbsp;&nbsp;[P0960R3 Permitir agregações de inicialização de uma lista de valores entre parênteses](https://wg21.link/P0960R3) | Não |
| &nbsp;&nbsp;[P1064R0 Como permitir chamadas de função virtual em expressões de constante](https://wg21.link/P1064R0) | Não |
| &nbsp;&nbsp;[P1073R3 Funções imediatas](https://wg21.link/P1073R3) | Não |
| &nbsp;&nbsp;[P1094R2 Namespaces embutidos aninhados](https://wg21.link/P1094R2) | Não |
| &nbsp;&nbsp;[P1139R2 Resolver problemas de expressão relacionados ao ISO 10646](https://wg21.link/P1139R2) | Não |
| &nbsp;&nbsp;[P1141R2 Ainda outra abordagem para declarações restritas](https://wg21.link/P1141R2) | Não |
| &nbsp;&nbsp;[Constinit P1143R2](https://wg21.link/P1143R2) | Não |
| &nbsp;&nbsp;[P1152R4 Depreciando volátil](https://wg21.link/P1152R4) | Não |
| &nbsp;&nbsp;[P1236R1 Inteiros com sinal são complemento de dois](https://wg21.link/P1236R1) | Não |
| &nbsp;&nbsp;[P1327R1 Como permitir dynamic_cast, polymorphic typeid em expressões constantes](https://wg21.link/P1327R1) | Não |
| &nbsp;&nbsp;[P1331R2 Permitindo inicialização trivial de padrão em contextos constexpr](https://wg21.link/P1331R2) | Não |
| &nbsp;&nbsp;[P1353R0 Macros de teste de recurso ausentes](https://wg21.link/P1353R0) | Não |
| &nbsp;&nbsp;[P1381R1 Captura de referência de associações estruturadas](https://wg21.link/P1381R1) | Não |
| &nbsp;&nbsp;[P1452R2 Na semântica não uniforme dos requisitos de devolução](https://wg21.link/P1452R2) | Não |
| &nbsp;&nbsp;[P1616R1 Usando TTPs sem restrições com modelos restritos](https://wg21.link/P1616R1) | Não |
| &nbsp;&nbsp;[P1668R1 Permitindo montagem inline não avaliada em funções constexpr](https://wg21.link/P1668R1) | Não |
| &nbsp;&nbsp;[P1766R1 Mitigando módulos menores](https://wg21.link/P1766R1) | Não |
| &nbsp;&nbsp;[P1811R0 Restrições relaxantes de redefinição para robustez de reexportação](https://wg21.link/P1811R0) | Não |
| &nbsp;&nbsp;[CTAD P1814R0 para modelos de alias](https://wg21.link/P1814R0) | Não |
| &nbsp;&nbsp;[CTAD P1816R0 para agregados](https://wg21.link/P1816R0) | Não |
| &nbsp;&nbsp;[Ordem de Inicialização Dinâmica P1874R1 de Variáveis Não Locais em Módulos](https://wg21.link/P1874R1) | Não |
| &nbsp;&nbsp;[Inconsistências P1907R1 com parâmetros de modelo não-tipo](https://wg21.link/P1907R1) | Não |
| &nbsp;&nbsp;[P1971R0 Principais Mudanças para NB Comentários na reunião de novembro de 2019 (Belfast)](https://wg21.link/P1971R0) | Não |
| &nbsp;&nbsp;[P1972R0 US105 Verifique a satisfação das restrições para não-modelos ao formar ponteiro para funcionar](https://wg21.link/P1972R0) | Não |
| &nbsp;&nbsp;[P1975R0 Fixação da redação da inicialização agregada parêntese](https://wg21.link/P1975R0) | Não |
| &nbsp;&nbsp;[Resolução P1979R0 para US086](https://wg21.link/P1979R0) | Não |
| &nbsp;&nbsp;[P1980R0 CA096: Correspondência de declaração para não-dependentes requer cláusulas](https://wg21.link/P1980R0) | Não |

## <a name="standard-library-features"></a>Recursos da biblioteca padrão

|  |  |
|--|--|
| __C++20 Recursos padrão da biblioteca__ | __Com suporte__ |
| &nbsp;&nbsp;[P0809R0 Comparar contêineres desordenados](https://wg21.link/p0809r0) | VS 2010 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0858R0 Requisitos de iterador constexpr](https://wg21.link/p0858r0) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0777R1 Como evitar o decaimento desnecessário](https://wg21.link/p0777r1) | VS 2017 15.7 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P1164R1 tornando create_directory() intuitivo](https://wg21.link/P1164R1) | VS 2019 16.0 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0550R2 remove_cvref](https://wg21.link/p0550r2) | VS 2019 16.0 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0318R1 unwrap_reference, unwrap_ref_decay](https://wg21.link/p0318r1) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0457R2 starts_with()/ends_with() para basic_string/basic_string_view](https://wg21.link/p0457r2) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0458R2 contains() para contêineres associativos ordenados e não ordenados](https://wg21.link/p0458r2) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0646R1 list/forward_list remove()/remove_if()/unique() retornam size_type](https://wg21.link/p0646r1) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0769R2 shift_left(), shift_right()](https://wg21.link/p0769r2) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0887R1 type_identity](https://wg21.link/p0887r1) | VS 2019 16.1 <sup>[20](#note_20)</sup> |
| &nbsp;&nbsp;[P0020R6 atomic\<float>, atomic\<double>, atomic\<long double>](https://wg21.link/p0020r6) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0463R1 endian](https://wg21.link/p0463r1) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0482R6 char8_t: Um tipo para caracteres e strings UTF-8](https://wg21.link/P0482R6) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0600R1 \[ \[nodiscard\] \] Para o STL, Parte 1](https://wg21.link/p0600r1) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0653R2 to_address()](https://wg21.link/p0653r2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0754R2 \<version>](https://wg21.link/p0754r2) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0771R1 noexcept para Construtor de Movimento de std::function](https://wg21.link/P0771R1) | VS 2019 <sup> [16.220](#note_20)</sup> |
| &nbsp;&nbsp;[P0487R1 Corrigindo operador>>(basic_istream&, CharT*)](https://wg21.link/P0487R1) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0616R0 Uso de move() em \<numeric>](https://wg21.link/p0616r0) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0758R1 is_nothrow_convertible](https://wg21.link/P0758R1) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0898R3 Conceitos de biblioteca padrão](https://wg21.link/P0898R3) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0919R3 Pesquisa heterogênea por contêineres não ordenados](https://wg21.link/P0919R3) | VS 2019 16.3 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1754R1 Renomear conceitos para standard_case](https://wg21.link/P1754R1) | VS 2019 16.4 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0325R4 to_array do LFTS com atualizações](https://wg21.link/P0325R4) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0340R3 underlying_type amigável de SFINAE](https://wg21.link/P0340R3) | VS 2019 16.5 <sup> [14](#note_14)</sup> |
| &nbsp;&nbsp;[P0356R5 bind_front()](https://wg21.link/P0356R5) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0439R0 classe de enumeração memory_order](https://wg21.link/p0439r0) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0553R4 \<bit> funções rotativas e de contagem](https://wg21.link/P0553R4) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0556R3 \<bit> ispow2(), ceil2(), piso2(), log2p1()](https://wg21.link/P0556R3) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0595R2 is_constant_evaluated()](https://wg21.link/P0595R2) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[Números p0631R8 \<> Constantos matemáticas](https://wg21.link/P0631R8) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0738R2 Limpeza de istream_iterator](https://wg21.link/P0738R2) | VS 2019 16.5 <sup> [14](#note_14)</sup> |
| &nbsp;&nbsp;[P0767R1 Preterindo is_pod](https://wg21.link/P0767R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0966R1 string::reserve() Não deve ser reduzido](https://wg21.link/P0966R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1209R0 erase_if(), erase()](https://wg21.link/P1209R0) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1227R2 std::ssize() com sinal, span::size() sem sinal](https://wg21.link/P1227R2) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[Contrato estreito P1355R2 para ceil2()](https://wg21.link/P1355R2) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1357R1 is_bounded_array, is_unbounded_array](https://wg21.link/P1357R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1612R1 Realocando endian \<para bit>](https://wg21.link/P1612R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1651R0 bind_front() Não deve desembrulhar reference_wrapper](https://wg21.link/P1651R0) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1690R1 Refinando busca heterogênea para contêineres não ordenados](https://wg21.link/P1690R1) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P1902R1 Faltam macros de teste de recursos 2017-2019](https://wg21.link/P1902R1) | VS 2019 16.5 <sup> [14](#note_14)</sup> |
| &nbsp;&nbsp;[P0019R8 atomic_ref](https://wg21.link/P0019R8) | Não |
| &nbsp;&nbsp;[P0053R7 \<syncstream>](https://wg21.link/p0053r7)<br/>&nbsp;&nbsp;[P0753R2 Manipuladores osyncstream](https://wg21.link/p0753r2) | Não |
| &nbsp;&nbsp;[P0122R7 \<span>](https://wg21.link/p0122r7) | Não |
| &nbsp;&nbsp;[P0202R3 constexpr para \<algorithm> e exchange()](https://wg21.link/p0202r3) | Não |
| &nbsp;&nbsp;[P0339R6 polymorphic_allocator<>](https://wg21.link/P0339R6) | Não |
| &nbsp;&nbsp;[P0355R7 \<chrono> Calendários e fusos horários](https://wg21.link/p0355r7) | Não |
| &nbsp;&nbsp;[P0357R3 Dando suporte aos tipos incompletos em reference_wrapper](https://wg21.link/P0357R3) | Não |
| &nbsp;&nbsp;[P0415R1 constexpr para \<complex> (novamente)](https://wg21.link/p0415r1) | Não |
| &nbsp;&nbsp;[P0475R1 Omissão da cópia garantida para construção em trechos](https://wg21.link/P0475R1) | Não |
| &nbsp;&nbsp;[bit_cast de> de \<bits P0476R2](https://wg21.link/P0476R2) | Não |
| &nbsp;&nbsp;[P0528R3 Comparação e troca atômica com bits de preenchimento](https://wg21.link/P0528R3) | Não |
| &nbsp;&nbsp;[P0591R4 Funções de utilitário para construção de alocadores para usos](https://wg21.link/P0591R4) | Não |
| &nbsp;&nbsp;[P0608R3 Como melhorar o construtor/atribuição de conversão da variante](https://wg21.link/P0608R3) | Não |
| &nbsp;&nbsp;[P0619R4 Remoção de recursos preteridos pelo C++17 no C++20](https://wg21.link/P0619R4) | Não |
| &nbsp;&nbsp;[P0653R2 to_address()](https://wg21.link/p0653r2) | Não |
| &nbsp;&nbsp;[P0655R1\<visitar R>()](https://wg21.link/P0655R1) | Não |
| &nbsp;&nbsp;[P0674R1 make_shared() para matrizes](https://wg21.link/p0674r1) | Não |
| &nbsp;&nbsp;[P0718R2 atomic\<shared_ptr\<T>>, atomic\<weak_ptr\<T>>](https://wg21.link/p0718r2) | Não |
| &nbsp;&nbsp;[Suporte à biblioteca P0768R1 para o operador de comparação de naves espaciais\<=>](https://wg21.link/p0768r1) | Não |
| &nbsp;&nbsp;[P0811R3 midpoint(), lerp()](https://wg21.link/P0811R3) | Não |
| &nbsp;&nbsp;[P0879R0 constexpr para funções de troca](https://wg21.link/P0879R0) | Não |
| &nbsp;&nbsp;[P0896R4 \<intervalos\>](https://wg21.link/P0896R4) | Não |
| &nbsp;&nbsp;[P0912R5 Suporte à biblioteca para corrotinas](https://wg21.link/P0912R5) | Não |
| &nbsp;&nbsp;[P0920R2 Pesquisa de valor de hash pré-calculado](https://wg21.link/P0920R2) | Não |
| &nbsp;&nbsp;[P0935R0 Como eliminar construtores padrão desnecessariamente explícitos](https://wg21.link/P0935R0) | Não |
| &nbsp;&nbsp;[P1001R2 execution::unseq](https://wg21.link/P1001R2) | Não |
| &nbsp;&nbsp;[P1006R1 constexpr para pointer_traits<T*>::pointer_to()](https://wg21.link/P1006R1) | Não |
| &nbsp;&nbsp;[P1007R3 assume_aligned()](https://wg21.link/P1007R3) | Não |
| &nbsp;&nbsp;[P1020R1 Criação de ponteiro inteligente com inicialização padrão](https://wg21.link/P1020R1) | Não |
| &nbsp;&nbsp;[P1023R0 constexpr para comparações de std::array](https://wg21.link/P1023R0) | Não |
| &nbsp;&nbsp;[P1032R1 constexpr diversos](https://wg21.link/P1032R1) | Não |
| &nbsp;&nbsp;[P1165R1 Propagando consistentemente alocadores com estado no operador+() de basic_string](https://wg21.link/P1165R1) | Não |
| &nbsp;&nbsp;[P1285R0 Como melhorar requisitos de integridade para características de tipo](https://wg21.link/P1285R0) | Não |
| __C++17 Recursos padrão da biblioteca__ | __Com suporte__ |
| &nbsp;&nbsp;[LWG 2221 Operador de saída formatado para nullptr](https://cplusplus.github.io/LWG/issue2221) | VS 2019 16.1 |
| &nbsp;&nbsp;[N3911 void_t](https://wg21.link/n3911) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4089 Conversões seguras em unique_ptr\<T[]>](https://wg21.link/n4089) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4169 invoke()](https://wg21.link/n4169) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4190 Removendo auto_ptr, random_shuffle() e \<itens functional>](https://wg21.link/n4190) antigos | VS 2015 <sup>[rem](#note_rem)</sup> |
| &nbsp;&nbsp;[N4258 Limpezas de noexcept](https://wg21.link/n4258) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4259 uncaught_exceptions()](https://wg21.link/n4259) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4277 reference_wrapper facilmente copiado](https://wg21.link/n4277) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4279 insert_or_assign()/try_emplace() para map/unordered_map](https://wg21.link/n4279) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4280 size(), empty(), data()](https://wg21.link/n4280) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4366 Atribuição unique_ptr de restrição precisa](https://wg21.link/n4366) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4387 Melhorando o par e a tupla](https://wg21.link/n4387) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4389 bool_constant](https://wg21.link/n4389) | VS 2015 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4508 shared_mutex (sem tempo)](https://wg21.link/n4508) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4510 Dando suporte a tipos incompletos em vector/list/forward_list](https://wg21.link/n4510) | VS 2013 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: \<algorithm> sample()](https://wg21.link/n4562#alg.random.sample) | VS 2017 15.0 |
| &nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<any>](https://wg21.link/n4562#any) | VS 2017 15.0 |
| &nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: \<memory_resource>](https://wg21.link/n4562#memory.resource.synop)<br/>&nbsp;&nbsp;[P0337R0 Excluindo a atribuição polymorphic_allocator](https://wg21.link/p0337r0) | VS 2017 15.6 |
| &nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<optional>](https://wg21.link/n4562#optional) | VS 2017 15.0 |
| &nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<string_view>](https://wg21.link/n4562#string.view) | VS 2017 15.0 |
| &nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<tuple> apply()](https://wg21.link/n4562#tuple) | VS 2017 15.0 |
| &nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: Boyer-Moore search()](https://wg21.link/n4562#func.searchers.boyer_moore)<br/>&nbsp;&nbsp;[P0253R1 Corrigindo tipos de retorno da ferramenta de pesquisa](https://wg21.link/p0253r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0003R5 Removendo Especificações de Exceção Dinâmica](https://wg21.link/p0003r5) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0004R1 Removendo aliases iostreams preteridos](https://wg21.link/p0004r1) | VS 2015.2 <sup>[rem](#note_rem)</sup> |
| &nbsp;&nbsp;[P0005R4 not_fn()](https://wg21.link/p0005r4)<br/>&nbsp;&nbsp;[P0358R1 Correções para not_fn()](https://wg21.link/p0358r1) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0006R0 Modelos de variável para características de tipo (is_same_v, etc.)](https://wg21.link/p0006r0) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0007R1 as_const()](https://wg21.link/p0007r1) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0013R1 Características de tipo do operador lógico (conjunção, etc.)](https://wg21.link/p0013r1) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0024R2 Algoritmos paralelos](https://wg21.link/p0024r2)<br/>&nbsp;&nbsp;[P0336R1 Renomeando políticas de execução paralela](https://wg21.link/p0336r1)<br/>&nbsp;&nbsp;[P0394R4 Algoritmos paralelos devem conter terminate() para exceções](https://wg21.link/p0394r4)<br/>&nbsp;&nbsp;[P0452R1 Unificando \<algoritmos numéricos> paralelos](https://wg21.link/p0452r1) | VS 2017 15.7 |
| &nbsp;&nbsp;[P0025R1 clamp()](https://wg21.link/p0025r1) | VS 2015.3 |
| &nbsp;&nbsp;[P0030R1 hypot(x, y, z)](https://wg21.link/p0030r1) | VS 2017 15.7 |
| &nbsp;&nbsp;[P0031R0 constexpr para \<array> (Novamente) e \<iterator>](https://wg21.link/p0031r0) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0032R3 Interface homogênea de variant/any/optional](https://wg21.link/p0032r3) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0033R1 Reescrevendo enable_shared_from_this](https://wg21.link/p0033r1) | VS 2017 15.5 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0040R3 Estendendo as ferramentas de gerenciamento de memória](https://wg21.link/p0040r3) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0063R3 Biblioteca Padrão C11](https://wg21.link/p0063r3) | VS 2015 <sup>[C11](#note_C11), [14](#note_14)</sup> |
| &nbsp;&nbsp;[P0067R5 Conversões de cadeia de caracteres elementar](https://wg21.link/p0067r5) | VS 2019 16.4 <sup> [charconv](#note_charconv)</sup> |
| &nbsp;&nbsp;[owner_less P00074R0\<>](https://wg21.link/p0074r0) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0077R2 is_callable, is_nothrow_callable](https://wg21.link/p0077r2) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0083R3 Unindo mapas e conjuntos](https://wg21.link/p0083r3)<br/>&nbsp;&nbsp;[P0508R0 Esclarecendo insert_return_type](https://wg21.link/p0508r0) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0084R2 Tipo de retorno emplace](https://wg21.link/p0084r2) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0088R3 \<variant>](https://wg21.link/p0088r3) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0092R1 \<chrono> floor(), ceil(), round(), abs()](https://wg21.link/p0092r1) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0152R1 atomic::is_always_lock_free](https://wg21.link/p0152r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0154R1 hardware_destructive_interference_size, etc.](https://wg21.link/p0154r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0156R0 lock_guard variadic](https://wg21.link/p0156r0) | VS 2015.2 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0156R2 Como renomear Variadic lock\_guard para scoped\_lock](https://wg21.link/p0156r2) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0163R0 shared_ptr::weak_type](https://wg21.link/p0163r0) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0174R2 Preterindo partes residuais da biblioteca](https://wg21.link/p0174r2) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0185R1 is_swappable, is_nothrow_swappable](https://wg21.link/p0185r1) | VS 2015.3 |
| &nbsp;&nbsp;[P0209R2 make_from_tuple()](https://wg21.link/p0209r2) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0218R1 \<filesystem>](https://wg21.link/p0218r1)<br/>&nbsp;&nbsp;[P0219R1 Caminhos relativos para o sistema de arquivos](https://wg21.link/p0219r1)<br/>&nbsp;&nbsp;[P0317R1 Cache de entrada de diretório para sistema de arquivos](https://wg21.link/p0317r1)<br/>&nbsp;&nbsp;[P0392R0 Dando suporte a string_view em caminhos do sistema de arquivos](https://wg21.link/p0392r0)<br/>&nbsp;&nbsp;[P0430R2 suportando sistemas de arquivos não POSIX](https://wg21.link/p0430r2)<br/>&nbsp;&nbsp;[P0492R2 Resolução de comentários NB para o sistema de arquivos](https://wg21.link/p0492r2) | VS 2017 15.7 <sup>[E](#note_E)</sup> |
| &nbsp;&nbsp;[P0220R1 Conceitos básicos da biblioteca V1](https://wg21.link/p0220r1) | VS 2017 15.6 |
| &nbsp;&nbsp;[P0226R1 Funções matemáticas especiais](https://wg21.link/p0226r1) | VS 2017 15.7 |
| &nbsp;&nbsp;[P0254R2 Integrando string_view e std::string](https://wg21.link/p0254r2) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0258R2 has_unique_object_representations](https://wg21.link/p0258r2) | VS 2017 15.3 <sup>[G](#note_G)</sup> |
| &nbsp;&nbsp;[P0272R1 Non-const basic_string::data()](https://wg21.link/p0272r1) | VS 2015.3 |
| &nbsp;&nbsp;[P0295R0 gcd(), lcm()](https://wg21.link/p0295r0) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0298R3 std::byte](https://wg21.link/p0298r3) | VS 2017 15.3 <sup>[17](#note_17),&nbsp;[byte](#note_byte)</sup> |
| &nbsp;&nbsp;[P0302R1 Removendo o suporte ao alocador em std::function](https://wg21.link/p0302r1) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0307R2 Criando Greater Equal opcional novamente](https://wg21.link/p0307r2) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0393R3 Variante Greater Equal](https://wg21.link/p0393r3) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0403R1 UDLs para \<string_view> ("meow"sv, etc.)](https://wg21.link/p0403r1) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0414R2 shared_ptr\<T[]>, shared_ptr\<T[N]>](https://wg21.link/p0414r2)<br/>&nbsp;&nbsp;[P0497R0 Corrigindo shared_ptr para matrizes](https://wg21.link/p0497r0) | VS 2017 15.5 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0418R2 Requisitos de compare_exchange memory_order atômico](https://wg21.link/p0418r2) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0426R1 constexpr para char_traits](https://wg21.link/p0426r1) | VS 2017 15.7 |
| &nbsp;&nbsp;[P0433R2 Integração da dedução de modelo para modelos de classe na Biblioteca Padrão](https://wg21.link/p0433r2)<br/>&nbsp;&nbsp;[P0739R0 Como melhorar a integração da dedução de argumento de modelo de classe na Biblioteca Padrão](https://wg21.link/p0739r0) | VS 2017 15.7 |
| &nbsp;&nbsp;[P0435R1 Revisando common_type](https://wg21.link/p0435r1)<br/>&nbsp;&nbsp;[P0548R1 Ajustando o tipo e a duração comuns\_](https://wg21.link/p0548r1) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0504R0 Revisitando in_place_t/in_place_type_t\<T>/in_place_index_t\<I>](https://wg21.link/p0504r0) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0505R0 constexpr para \<chrono> (Novamente)](https://wg21.link/p0505r0) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0510R0 Rejeitando variantes de nada, matrizes, referências e tipos incompletos](https://wg21.link/p0510r0) | VS 2017 15.0 |
| &nbsp;&nbsp;[P0513R0 Hash de suspeita](https://wg21.link/p0513r0)<br/>&nbsp;&nbsp;[P0599R1 não exceto hash](https://wg21.link/p0599r1) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0516R0 Marcando a cópia de shared_future como noexcept](https://wg21.link/p0516r0) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0517R0 Construindo future_error com base em future_errc](https://wg21.link/p0517r0) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0521R0 Preterindo shared_ptr::unique()](https://wg21.link/p0521r0) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0558R1 Resolução de inconsistências de classe base nomeadas atomic\<T>](https://wg21.link/p0558r1) | VS 2017 15.3 <sup>[14](#note_14)</sup> |
| &nbsp;&nbsp;[P0595R2 std::is_constant_evaluated()](https://wg21.link/P0595R2) | VS 2019 16.5 <sup> [20](#note_20)</sup> |
| &nbsp;&nbsp;[P0602R4 Propagação da trivialidade Copiar/Mover em variante/opcional](https://wg21.link/P0602R4) | VS 2017 15.3<sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0604R0 Como alterar is\_callable/result\_of para invoke\_result, is\_invocable, is\_nothrow\_invocable](https://wg21.link/p0604r0) | VS 2017 15.3 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0607R0 Variáveis embutidas para a Biblioteca Padrão](https://wg21.link/p0607r0) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[>codecvt dedepreciação P0618R0 \<](https://wg21.link/p0618r0) | VS 2017 15.5 <sup>[17](#note_17)</sup> |
| &nbsp;&nbsp;[P0682R1 Reparação de conversões da cadeia de caracteres elementares](https://wg21.link/P0682R1) | VS 2015 15.7 <sup>[17](#note_17)</sup> |
| __C++14 Recursos padrão da biblioteca__ | __Com suporte__ |
| &nbsp;&nbsp;[N3462 result_of amigável do SFINAE](https://wg21.link/n3462) | VS 2015.2 |
| &nbsp;&nbsp;[N3302 constexpr para \<complex>](https://wg21.link/n3302) | VS 2015 |
| &nbsp;&nbsp;[N3469 constexpr para \<chrono>](https://wg21.link/n3469) | VS 2015 |
| &nbsp;&nbsp;[N3470 constexpr para \<array>](https://wg21.link/n3470) | VS 2015 |
| &nbsp;&nbsp;[N3471 constexpr para \<initializer_list>, \<tuple>, \<utility>](https://wg21.link/n3471) | VS 2015 |
| &nbsp;&nbsp;[N3545 integral_constant::operator()()](https://wg21.link/n3545) | VS 2015 |
| &nbsp;&nbsp;[N3642 UDLs para \<chrono>, \<string> (1729ms, "meow"s, etc.)](https://wg21.link/n3642) | VS 2015 |
| &nbsp;&nbsp;[N3644 Iteradores de avanço nulo](https://wg21.link/n3644) | VS 2015 |
| &nbsp;&nbsp;[N3654 quoted()](https://wg21.link/n3654) | VS 2015 |
| &nbsp;&nbsp;[N3657 Pesquisa associativa heterogênea](https://wg21.link/n3657) | VS 2015 |
| &nbsp;&nbsp;[N3658 integer_sequence](https://wg21.link/n3658) | VS 2015 |
| &nbsp;&nbsp;[N3659 shared_mutex (com tempo)](https://wg21.link/n3659) | VS 2015 |
| &nbsp;&nbsp;[N3668 exchange()](https://wg21.link/n3668) | VS 2015 |
| &nbsp;&nbsp;[N3669 Corrigindo funções membro constexpr sem const](https://wg21.link/n3669) | VS 2015 |
| &nbsp;&nbsp;[N3670 get\<T>()](https://wg21.link/n3670) | VS 2015 |
| &nbsp;&nbsp;[N3671 equal(), is_permutation(), mismatch() de intervalo duplo](https://wg21.link/n3671) | VS 2015 |
| &nbsp;&nbsp;[Alocação do tamanho de N3778](https://wg21.link/n3778) | VS 2015 |
| &nbsp;&nbsp;[N3779 UDLs para \<complex> (3.14i, etc.)](https://wg21.link/n3779) | VS 2015 |
| &nbsp;&nbsp;[N3789 constexpr para \<functional>](https://wg21.link/n3789) | VS 2015 |
| &nbsp;&nbsp;[N3887 tuple_element_t](https://wg21.link/n3887) | VS 2015 |
| &nbsp;&nbsp;[N3891 Renomeando shared_mutex (com tempo) como shared_timed_mutex](https://wg21.link/n3891) | VS 2015 |
| &nbsp;&nbsp;[N3346 Requisitos mínimos de elementos contêiner](https://wg21.link/n3346) | VS 2013 |
| &nbsp;&nbsp;[N3421 Functores de operador transparentes (less\<>, etc.)](https://wg21.link/n3421) | VS 2013 |
| &nbsp;&nbsp;[N3655 Modelos de alias para \<type_traits> (decay_t, etc.)](https://wg21.link/n3655) | VS 2013 |
| &nbsp;&nbsp;[N3656 make_unique()](https://wg21.link/n3656) | VS 2013 |

Um grupo de artigos listados em conjunto indica um recurso Standard juntamente com uma ou mais melhorias ou expansões aprovadas. Esses recursos são implementados juntos.

### <a name="supported-values"></a>Valores com suporte

__Não__ significa ainda não implementado.\
__Parcial__ significa que a implementação está incompleta. Para obter mais informações, consulte a seção Notas.\
__VS 2010__ indica recursos que são suportados no Visual Studio 2010.\
__VS 2013__ indica recursos que são suportados no Visual Studio 2013.\
__VS 2015__ indica recursos que são suportados no Visual Studio 2015 (RTW).\
__VS 2015.2__ e __VS 2015.3__ indicam recursos que são suportados no Visual Studio 2015 Update 2 e Visual Studio 2015 Update 3, respectivamente.\
__VS 2017 15.0__ indica recursos que são suportados no Visual Studio 2017 versão 15.0 (RTW).\
__VS 2017 15.3__ indica recursos que são suportados no Visual Studio 2017 versão 15.3.\
__VS 2017 15.5__ indica recursos que são suportados no Visual Studio 2017 versão 15.5.\
__VS 2017 15.7__ indica recursos que são suportados no Visual Studio 2017 versão 15.7.\
__VS 2019 16.0__ indica recursos que são suportados no Visual Studio 2019 versão 16.0 (RTW).\
__VS 2019 16.1__ indica recursos que são suportados no Visual Studio 2019 versão 16.1.\
__VS 2019 16.2__ indica recursos que são suportados no Visual Studio 2019 versão 16.2.\
__VS 2019 16.3__ indica recursos que são suportados no Visual Studio 2019 versão 16.3.\
__VS 2019 16.4__ indica recursos que são suportados no Visual Studio 2019 versão 16.4.\
__VS 2019 16.5__ indica recursos que são suportados no Visual Studio 2019 versão 16.5.

### <a name="notes"></a>Observações

<a name="note_A"></a> __A__ No modo [/std:c++14](../build/reference/std-specify-language-standard-version.md), especificações de exceções dinâmicas permanecem não implementadas, e `throw()` ainda é tratado como um sinônimo para `__declspec(nothrow)`. No C++17, as especificações de exceções dinâmicas foram, em grande parte, removidas por P0003R5, deixando um vestígio: `throw()` foi preterido e obrigado a se comportar como um sinônimo de `noexcept`. No modo [/std:c++17,](../build/reference/std-specify-language-standard-version.md) o MSVC agora `throw()` está em `noexcept`conformidade com a Norma, dando o mesmo comportamento que , ou seja, a execução via rescisão.

A opção do compilador [/Zc:noexceptTypes](../build/reference/zc-noexcepttypes.md) solicita nosso antigo comportamento de `__declspec(nothrow)`. É provável que `throw()` seja removido em C++20. Para ajudar com a migração do código em resposta a essas alterações no padrão e nossa implementação, novos avisos do compilador para problemas de especificação de exceção foram adicionados em [/std:c++17](../build/reference/std-specify-language-standard-version.md) e [/permissive-](../build/reference/permissive-standards-conformance.md).

<a name="note_B"></a> __B__ Com suporte no modo [/permissive-](../build/reference/permissive-standards-conformance.md) no Visual Studio 2017 versão 15.7. Para obter mais informações, consulte [O suporte à busca de nomes em duas fases chega ao MSVC](https://devblogs.microsoft.com/cppblog/two-phase-name-lookup-support-comes-to-msvc/).

<a name="note_C"></a>__C__ O suporte do compilador para as regras do Pré-processador C99 está incompleto no Visual Studio 2017. Estamos revisando o pré-processador, e começamos a enviar essas mudanças na versão 15.8 do Visual Studio 2017 com o interruptor [/experimental:pré-processador](../build/reference/experimental-preprocessor.md) compilador.

<a name="note_D"></a> __D__ Com suporte em [/std:c++14](../build/reference/std-specify-language-standard-version.md) com um aviso suprimível, [C4984](../error-messages/compiler-warnings/compiler-warning-c4984.md).

<a name="note_E"></a>__E__ Esta é uma implementação totalmente nova, incompatível com a versão anterior, `std::experimental` necessária pelo suporte ao symlink, correções de bugs e alterações no comportamento padrão necessário. Atualmente, a inclusão de \<filesystem> fornece o novo `std::filesystem` e o `std::experimental::filesystem` anterior, e a inclusão de \<experimental/filesystem> fornece somente a implementação antiga experimental. A implementação experimental será REMOVIDA na próxima versão ABI recente das bibliotecas.

<a name="note_G"></a> __G__ Compatível com um compilador intrínseco.

<a name="note_14"></a> __14__ Esses recursos do C++17/20 estarão sempre habilitados, mesmo quando [/std:c++14](../build/reference/std-specify-language-standard-version.md) (o padrão) estiver especificado. A razão é porque o recurso foi implementado antes da introdução das opções **/std,** ou porque a implementação condicional era indesejávelmente complexa.

<a name="note_17"></a> __17__ Esses recursos estão habilitados pela opção do compilador [/std:c++17](../build/reference/std-specify-language-standard-version.md) (ou [/std:c++latest](../build/reference/std-specify-language-standard-version.md)).

<a name="note_20"></a> __20__ Esses recursos são habilitados pela opção do compilador [/std:c++latest](../build/reference/std-specify-language-standard-version.md). Quando a implementação de C++20 estiver concluída, uma nova opção do compilador **/std:c++20** será adicionada, na qual esses recursos também estarão disponíveis.

<a name="note_byte"></a> __byte__ `std::byte` é habilitado por [/std:c++17](../build/reference/std-specify-language-standard-version.md) (ou [/std:c++latest](../build/reference/std-specify-language-standard-version.md)), mas, como ele pode entrar em conflito com os cabeçalhos do SDK do Windows em alguns casos, ele tem uma macro de recusa refinada. Ele pode ser desabilitado, definindo `_HAS_STD_BYTE` como `0`.

<a name="note_C11"></a> __C11__ O Universal CRT implementou as partes da Biblioteca Padrão do C11 que são exigidas pelo C++17, com exceção de especificadores de conversão alternativa de E/S do C99 `strftime()`, modo exclusivo do C11 `fopen()` e C11 `aligned_alloc()`. Este último é improvável de ser implementado, `aligned_alloc()` porque o C11 especificou `free()`de uma `free()` forma incompatível com a implementação da Microsoft de : ou seja, que deve ser capaz de lidar com alocações altamente alinhadas.

<a name="note_rem"></a> __rem__ Recursos removidos quando a opção do compilador [/std:c++17](../build/reference/std-specify-language-standard-version.md) (ou [/std:c++latest](../build/reference/std-specify-language-standard-version.md)) for especificada. Esses recursos podem ser habilitados novamente de modo a facilitar a transição para os modos de idioma mais recentes pelo uso destas macros: `_HAS_AUTO_PTR_ETC`, `_HAS_FUNCTION_ALLOCATOR_SUPPORT`, `_HAS_OLD_IOSTREAMS_MEMBERS` e `_HAS_UNEXPECTED`.

<a name="note_charconv"></a> __charconv__ `from_chars()` e `to_chars()` estão disponíveis para números inteiros. A linha do tempo para o ponto flutuante `from_chars()` e ponto flutuante `to_chars()` é da seguinte maneira:

- VS 2017 15.7: `from_chars()` Inteiro `to_chars()`e .
- VS 2017 15.8: `from_chars()`Ponto flutuante .
- VS 2017 15.9: `to_chars()` Sobrecargas de ponto flutuante para decimal mais curto.
- VS 2019 16.0: `to_chars()` Sobrecargas de ponto flutuante para hexox mais curto e hexa de precisão.
- VS 2019 16.2: `to_chars()` Sobrecargas de ponto flutuante para precisão fixa e científica de precisão.
- VS 2019 16.4: A `to_chars()` sobrecarga de ponto flutuante para geral de precisão.

<a name ="note_parallel"></a>__paralelo__ A biblioteca de algoritmos paralelos da C++17 está completa. Completo não significa que cada algoritmo é paraparador em todos os casos. Os algoritmos mais importantes foram paraparados, e as assinaturas da política de execução são fornecidas mesmo quando os algoritmos não são paraparados. O cabeçalho interno central de nossa implementação, yvals_core.h, contém as seguintes "Notas de Algoritmos Paralelos": C++ permite que uma implementação implemente algoritmos paralelos como chamadas para os algoritmos seriais. Essa implementação paraleliza várias chamadas de algoritmo comum, mas não todas.

Os seguintes algoritmos são paralelizados:

- `adjacent_difference`, `adjacent_find`, `all_of`, `any_of`, `count`, `count_if`, `equal`, `exclusive_scan`, `find`, `find_end`, `find_first_of`, `find_if`, `find_if_not`, `for_each`, `for_each_n`, `inclusive_scan`, `is_heap`, `is_heap_until`, `is_partitioned`, `is_sorted`, `is_sorted_until`, `mismatch`, `none_of`, `partition`, `reduce`, `remove`, `remove_if`, `replace`, `replace_if`, `search`, `search_n`, `set_difference`, `set_intersection`, `sort`, `stable_sort`, `transform`, `transform_exclusive_scan`, `transform_inclusive_scan`, `transform_reduce`

Os seguintes não estão atualmente paraparados:

- Nenhuma melhoria de desempenho perceptível do paralelismo no hardware alvo; todos os algoritmos que simplesmente copiam ou permutam elementos sem ramificações são tipicamente limitados à largura de banda de memória:
  - `copy`, `copy_n`, `fill`, `fill_n`, `move`, `reverse`, `reverse_copy`, `rotate`, `rotate_copy`, `shift_left`, `shift_right`, `swap_ranges`
- Há confusão sobre requisitos de paralelismo de usuário. Provavelmente na categoria acima mesmo assim:
  - `generate`, `generate_n`
- Paralelismo efetivo com suspeita de não ser viável:
  - `partial_sort`, `partial_sort_copy`
- Ainda não avaliado; o paralelismo pode ser implementado em uma versão futura e acredita-se que seja benéfico:
  - `copy_if`, `includes`, `inplace_merge`, `lexicographical_compare`, `max_element`, `merge`, `min_element`, `minmax_element`, `nth_element`, `partition_copy`, `remove_copy`, `remove_copy_if`, `replace_copy`, `replace_copy_if`, `set_symmetric_difference`, `set_union`, `stable_partition`, `unique`, `unique_copy`

## <a name="see-also"></a>Confira também

[Referência de linguagem C++](../cpp/cpp-language-reference.md)\
[Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md)\
[Melhorias na conformidade C++ no Visual Studio](cpp-conformance-improvements.md)\
[Novidades para o Visual C++ no Visual Studio](what-s-new-for-visual-cpp-in-visual-studio.md)\
[História da mudança visual C++ de 2003 a 2015](../porting/visual-cpp-change-history-2003-2015.md)\
[Visual C++ Novidades 2003 a 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md)\
[Blog da equipe do C++](https://devblogs.microsoft.com/cppblog/)

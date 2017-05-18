---
title: Conformidade com a linguagem Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 3/1/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 475da6e9-0d78-4b4e-bd23-f41c406c4efe
caps.latest.revision: 11
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 705a5fd040b3cba1d3e8be1ac9e2a22ef1f98eb9
ms.openlocfilehash: 8e21a77e42a90571c73ff0f207f5d799ff722bd3
ms.contentlocale: pt-br
ms.lasthandoff: 04/05/2017

---
# <a name="visual-c-language-conformance"></a>Conformidade com a linguagem Visual C++ 
Este tópico resume a conformidade com os padrões de linguagem ISO C++03, C++11, C++14 e Draft C++17 dos recursos do compilador e dos recursos da STL (Biblioteca Padrão) para o Visual C++ no Visual Studio 2017 e versões anteriores. Cada nome de recurso da STL e do compilador é vinculado ao documento de proposta ISO C++ Standard que descreve o recurso, caso ele esteja disponível no momento da publicação. A coluna Com suporte lista a versão do Visual Studio no qual o suporte para o recurso apareceu pela primeira vez.  
  
Para detalhes sobre melhorias de conformidade e outras mudanças no Visual Studio 2017, consulte [Melhorias de conformidade no C++ no Visual Studio 2017](cpp-conformance-improvements-2017.md) e [Novidades do Visual C++ no Visual Studio 2017](what-s-new-for-visual-cpp-in-visual-studio.md). Para alterações de compatibilidade em versões anteriores, consulte [Histórico de alterações do Visual C++](porting/visual-cpp-change-history-2003-2015.md) e [Novidades do Visual C++ de 2003 a 2015](porting/visual-cpp-what-s-new-2003-through-2015.md). Para saber mais sobre as últimas notícias da equipe do C++, visite o [blog da equipe do Visual C++](http://blogs.msdn.microsoft.com/vcblog/).  

 > [!NOTE]
 > Não há alterações significativas binárias entre o Visual Studio 2015 e Visual Studio 2017.
  
## <a name="compiler-features"></a>Recursos do compilador  
  
|Área de recursos| |  
|----|---|  
|__Principais recursos da linguagem C++03/11__|__Com suporte__|
|&nbsp;&nbsp;O restante|VS 2015 <sup>[1](#note_1)</sup>|
|&nbsp;&nbsp;Pesquisa de nome de duas fases|Não|
|&nbsp;&nbsp;[N2634 Expressão SFINAE](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2634.html)|Parcial <sup>[2](#note_2)</sup>|
|&nbsp;&nbsp;[N1653 Pré-processador C99](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1653.htm)|Parcial <sup>[3](#note_3)</sup>|
|&nbsp;&nbsp;[N1988 Tipos inteiros estendidos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n1988.pdf)|N/D <sup>[4](#note_4)</sup>|
|__Principais recursos da linguagem C++14__|__Com suporte__|
|&nbsp;&nbsp;[N3664 Evitando/combinando alocações](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3664.html)|N/D <sup><sup>[5](#note_5)</sup></sup>|
|&nbsp;&nbsp;[N3323 Palavras ajustadas para conversões contextuais](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3323.pdf)|VS 2013|
|&nbsp;&nbsp;[N3472 Literais binários](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472.pdf)|VS 2015|
|&nbsp;&nbsp;[N3638 Tipos de retorno auto e decltype(auto)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3638.html)|VS 2015|
|&nbsp;&nbsp;[N3648 Capturas de init](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3648.html)|VS 2015|
|&nbsp;&nbsp;[N3649 Lambdas genéricos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3649.html)|VS 2015|
|&nbsp;&nbsp;[N3651 Modelos de variável](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3651.pdf)|VS 2015.2|
|&nbsp;&nbsp;[N3652 Constexpr estendido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html)|VS 2017|
|&nbsp;&nbsp;[N3653 NSDMIs para agregações](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3653.html)|VS 2017|
|&nbsp;&nbsp;[N3760 Atributo [[preterido]]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3760.html)|VS 2015|
|&nbsp;&nbsp;[N3778 Desalocação dimensionada](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3778.html)|VS 2015|
|&nbsp;&nbsp;[N3781 Separadores de dígito](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf)|VS 2015|
|__Principais recursos da linguagem C++17__|__Com suporte__|
|&nbsp;&nbsp;[N3922 Novas regras para automático com listas de inicialização entre chaves](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html)|VS 2015|
|&nbsp;&nbsp;[N3928 Static_assert resumido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf)|VS 2017 [*](#note_star)|
|&nbsp;&nbsp;[N4051 Nome de tipo em parâmetros de modelo do modelo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4051.html)|VS 2015|
|&nbsp;&nbsp;[N4086 Removendo trígrafos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4086.html)|VS 2010|
|&nbsp;&nbsp;[N4230 Definições de namespace aninhado](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230.html)|VS 2015.3 [*](#note_star)|
|&nbsp;&nbsp;[N4261 Corrigindo conversões de qualificação](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4261.html)|Não|
|&nbsp;&nbsp;[N4266 Atributos para namespaces e enumeradores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html)|VS 2015|
|&nbsp;&nbsp;[N4267 Literais de caracteres u8](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html)|VS 2015|
|&nbsp;&nbsp;[N4268 Permitindo mais argumentos de modelo sem tipo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268.html)|Não|
|&nbsp;&nbsp;[N4295 Expressões de dobra](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html)|Não|
|&nbsp;&nbsp;[P0036R0 Removendo algumas dobras unárias vazias](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0.pdf)|Não|
|&nbsp;&nbsp;[P0001R1 Removendo a palavra-chave de registro](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1.html)|VS 2017.x [*](#note_star)|
|&nbsp;&nbsp;[P0002R1 Removendo operator++ de bool](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0002r1.html)|Não|
|&nbsp;&nbsp;[P0012R1 Adicionando noexcept ao sistema de tipos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0012r1.html)|Não|
|&nbsp;&nbsp;[P0017R1 Inicialização de agregação estendida](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html)|Não|
|&nbsp;&nbsp;[P0018R3 Capturando *this por valor](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html)|VS 2017.x [*](#note_star)|
|&nbsp;&nbsp;[P0061R1 __has_include](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0061r1.html)|Não|
|&nbsp;&nbsp;[P0136R1 Reescrevendo construtores de herança](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0136r1.html)|Não|
|&nbsp;&nbsp;[P0138R2 Inicialização de lista direta de enumerações fixas de inteiros](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0138r2.pdf)|VS 2017.x [*](#note_star)|
|&nbsp;&nbsp;[P0170R1 Lambdas de constexpr](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1.pdf)|Não|
|&nbsp;&nbsp;[P0184R0 Range-based for-loops generalizado](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html)|VS 2017|
|&nbsp;&nbsp;[P0188R1 Atributo [[fallthrough]]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r1.pdf)|VS 2017 [*](#note_star)|
|&nbsp;&nbsp;[P0189R1 Atributo [[nodiscard]]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0189r1.pdf)|Não|
|&nbsp;&nbsp;[P0212R1 Atributo [[maybe_unused]]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0212r1.pdf)|VS 2017.x [*](#note_star)|
|&nbsp;&nbsp;[P0245R1 Literais de hexfloat](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1.html)|Não|
|&nbsp;&nbsp;[P0028R4 Usando namespaces de atributo sem repetição](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0028r4.html)|Não|
|&nbsp;&nbsp;[P0035R4 Alocação de memória dinâmica com excesso de alinhamento](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0035r4.html)|Não|
|&nbsp;&nbsp;[P0091R3 Dedução de argumento de modelo para modelos de classe](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html)|Não|
|&nbsp;&nbsp;[P0127R2 Declarando parâmetros de modelo sem tipo com automático](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0127r2.html)|Não|
|&nbsp;&nbsp;[P0135R1 Garantia de elisão de cópia](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0135r1.html)|Não|
|&nbsp;&nbsp;[P0145R3 Refinando a ordem de avaliação de expressão](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0145r3.pdf)|Não|
|&nbsp;&nbsp;[P0217R3 Associações estruturadas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0217r3.html)|Não|
|&nbsp;&nbsp;[P0283R2 Ignorando atributos não reconhecidos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0283r2.html)|Não|
|&nbsp;&nbsp;[P0292R2 Instruções constexpr if](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0292r2.html)|Não|
|&nbsp;&nbsp;[P0305R1 Instruções de seleção com inicializadores](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0305r1.html)|Não|
|&nbsp;&nbsp;[P0386R2 Variáveis embutidas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0386r2.pdf)|Não|
|&nbsp;&nbsp;[P0522R0 Fazendo a correspondência de parâmetros de modelo do modelo com argumentos compatíveis](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0522r0.html)|Não|
|&nbsp;&nbsp;[P0003R5 Removendo especificações de exceção dinâmica](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5.html)|Não|
|&nbsp;&nbsp;[P0195R2 Expansões de pacote em declarações using](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0195r2.html)|Não|

## <a name="standard-library--stl-features"></a>Recursos da Biblioteca Padrão/STL

|Área de recursos| |
|---|---|
|__Recursos da Biblioteca Padrão C++17__|__Com suporte__|
|&nbsp;&nbsp;P0433R2 Guias de dedução da STL|Não|
|&nbsp;&nbsp;P0607R0 Variáveis embutidas para a STL (opções A e B2)|Não|
|&nbsp;&nbsp;[P0258R2 has_unique_object_representations](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0258r2.html)|Não|
|&nbsp;&nbsp;[P0426R1 constexpr para char_traits](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0426r1.html)|Não|
|&nbsp;&nbsp;P0604R0 Alterar \_callable/result\_ para \_invocable/invoke\_result (Opções A e B)|Não|
|&nbsp;&nbsp;P0156R2 Renomeando Variadic lock\_guard para scoped\_lock|Não|
|&nbsp;&nbsp;P0558R1 Resolvendo inconsistências de classe Base nomeadas atômicas<T>|Não|
|&nbsp;&nbsp;P0298R3 std::byte|Não|
|&nbsp;&nbsp;[P0063R3 Biblioteca Padrão C11](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0063r3.html)|Não|
|&nbsp;&nbsp;[P0030R1 hypot(x, y, z)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0030r1.pdf)|Não|
|&nbsp;&nbsp;[P0435R1 Revisando common_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0435r1.pdf)<br />&nbsp;&nbsp;P0548R1 Ajustar o tipo\_comum e a duração|Não|
|&nbsp;&nbsp;[P0513R0 Hash de suspeita](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0513r0.pdf)<br />&nbsp;&nbsp;P0599R1 Hash de noexcept|Não|
|&nbsp;&nbsp;[P0033R1 Reescrevendo enable_shared_from_this](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0033r1.html)|Não|
|&nbsp;&nbsp;[P0220R1 Conceitos básicos da biblioteca V1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html)|Parcial <sup>[6](#note_6)</sup>|
|&nbsp;&nbsp;[P0414R2 shared_ptr\<T[]>, shared_ptr\<T[N]>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0414r2.html)<br />&nbsp;&nbsp;[P0497R0 Corrigindo shared_ptr para matrizes](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0497r0.html)|Não|
|&nbsp;&nbsp;[P0084R2 Tipo de retorno emplace](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0084r2.pdf)|Não|
|&nbsp;&nbsp;[P0083R3 Unindo mapas e conjuntos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3.pdf)<br />&nbsp;&nbsp;[P0508R0 Esclarecendo insert_return_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0508r0.html)|Não|
|&nbsp;&nbsp;[P0031R0 constexpr para \<array> (Novamente) e \<iterator>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0031r0.html)|Não|
|&nbsp;&nbsp;[P0505R0 constexpr para \<chrono> (Novamente)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0505r0.html)|Não|
|&nbsp;&nbsp;[P0005R4 not_fn()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0005r4.html)<br />&nbsp;&nbsp;[P0358R1 Correções para not_fn()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0358r1.html)|Não|
|&nbsp;&nbsp;[P0295R0 gcd(), lcm()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0295r0.pdf)|Não|
|&nbsp;&nbsp;[P0154R1 hardware_destructive_interference_size, etc.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0154r1.html)|Não|
|&nbsp;&nbsp;[P0067R5 Conversões de cadeia de caracteres elementar](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html)|Não|
|&nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: Boyer-Moore search()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#func.searchers.boyer_moore)<br/>&nbsp;&nbsp;[P0253R1 Corrigindo tipos de retorno da ferramenta de pesquisa](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0253r1.pdf)|Não|
|&nbsp;&nbsp;P0618R0 Reprovando \<codecvt>|Não|
|&nbsp;&nbsp;[P0521R0 Preterindo shared_ptr::unique()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0521r0.html)|Não|
|&nbsp;&nbsp;[P0174R2 Preterindo partes residuais da biblioteca](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0174r2.html)|Não|
|&nbsp;&nbsp;[P0003R5 Removendo Especificações de Exceção Dinâmica](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5.html)|Não|
|&nbsp;&nbsp;[P0302R1 Removendo o suporte ao alocador em std::function](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0302r1.html)|Não|
|&nbsp;&nbsp;[P0040R3 Estendendo as ferramentas de gerenciamento de memória](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0040r3.html)|Não|
|&nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: \<memory_resource>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#memory.resource.synop)<br />&nbsp;&nbsp;[P0337R0 Excluindo a atribuição polymorphic_allocator](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0337r0.html)|Não|
|&nbsp;&nbsp;[P0024R2 Algoritmos paralelos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html)<br />&nbsp;&nbsp;[P0336R1 Renomeando políticas de execução paralela](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0336r1.pdf)<br />&nbsp;&nbsp;[P0394R4 Algoritmos paralelos devem conter terminate() para exceções](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0394r4.html)<br />&nbsp;&nbsp;P0452R1 Unificar algoritmos paralelos \<numeric>|Não|
|&nbsp;&nbsp;[P0226R1 Funções matemáticas especiais](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0226r1.pdf)|Não|
|&nbsp;&nbsp;[P0218R1 \<filesystem>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0218r1.html)<br />&nbsp;&nbsp;[P0219R1 Caminhos relativos para o sistema de arquivos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0219r1.html)<br />&nbsp;&nbsp;[P0392R0 Dando suporte a string_view em caminhos do sistema de arquivos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0392r0.pdf)<br />&nbsp;&nbsp;P0430R2 Suporte a sistemas de arquivos não POSIX<br />&nbsp;&nbsp;P0492R2 Resolvendo comentários NB para o sistema de arquivos|Não <sup>[7](#note_7)</sup>|
|&nbsp;&nbsp;[P0152R1 atomic::is_always_lock_free](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0152r1.html)|VS 2017.x|
|&nbsp;&nbsp;[P0403R1 UDLs para \<string_view> ("meow"sv, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0403r1.html)|VS 2017.x|
|&nbsp;&nbsp;[P0418R2 Requisitos de compare_exchange memory_order atômico](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0418r2.html)|VS 2017.x|
|&nbsp;&nbsp;[P0516R0 Marcando a cópia de shared_future como noexcept](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0516r0.html)|VS 2017.x|
|&nbsp;&nbsp;[P0517R0 Construindo future_error com base em future_errc](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0517r0.html)|VS 2017.x|
|&nbsp;&nbsp;[N4562 Conceitos básicos de biblioteca: \<algorithm> sample()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#alg.random.sample)|VS 2017|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<any>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#any)|VS 2017|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<optional>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#optional)|VS 2017|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<string_view>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#string.view)|VS 2017|
|&nbsp;&nbsp;[N4562 Conceitos básicos da biblioteca: \<tuple> apply()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4562.html#tuple)|VS 2017|
|&nbsp;&nbsp;[P0032R3 Interface homogênea de variant/any/optional](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0032r3.pdf)|VS 2017|
|&nbsp;&nbsp;[P0077R2 is_callable, is_nothrow_callable](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0077r2.html)|VS 2017|
|&nbsp;&nbsp;[P0088R3 \<variant>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0088r3.html)|VS 2017|
|&nbsp;&nbsp;[P0163R0 shared_ptr::weak_type](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0163r0.html)|VS 2017|
|&nbsp;&nbsp;[P0209R2 make_from_tuple()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0209r2.pdf)|VS 2017|
|&nbsp;&nbsp;[P0254R2 Integrando string_view e std::string](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0254r2.pdf)|VS 2017|
|&nbsp;&nbsp;[P0307R2 Criando Greater Equal opcional novamente](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0307r2.pdf)|VS 2017|
|&nbsp;&nbsp;[P0393R3 Variante Greater Equal](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0393r3.html)|VS 2017|
|&nbsp;&nbsp;[P0504R0 Revisitando in_place_t/in_place_type_t\<T>/in_place_index_t\<I>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0504r0.html)|VS 2017|
|&nbsp;&nbsp;[P0510R0 Rejeitando variantes de nada, matrizes, referências e tipos incompletos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0510r0.html)|VS 2017|
|&nbsp;&nbsp;[P0025R1 clamp()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0025r1.html)|VS 2015.3|
|&nbsp;&nbsp;[P0185R1 is_swappable, is_nothrow_swappable](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0185r1.html)|VS 2015.3|
|&nbsp;&nbsp;[P0272R1 Non-const basic_string::data()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0272r1.html)|VS 2015.3|
|&nbsp;&nbsp;[N4387 Melhorando o par e a tupla](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4387.html)|VS 2015.2|
|&nbsp;&nbsp;[N4508 shared_mutex (sem tempo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4508.html)|VS 2015.2|
|&nbsp;&nbsp;[P0004R1 Removendo aliases iostreams preteridos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0004r1.html)|VS 2015.2|
|&nbsp;&nbsp;[P0006R0 Modelos de variável para características de tipo (is_same_v, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0006r0.html)|VS 2015.2|
|&nbsp;&nbsp;[P0007R1 as_const()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0007r1.html)|VS 2015.2|
|&nbsp;&nbsp;[P0013R1 Características de tipo do operador lógico (conjunção, etc.)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0013r1.html)|VS 2015.2|
|&nbsp;&nbsp;[P0074R0 owner_less\<>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0074r0.html)|VS 2015.2|
|&nbsp;&nbsp;[P0092R1 \<chrono> floor(), ceil(), round(), abs()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0092r1.html)|VS 2015.2|
|&nbsp;&nbsp;[P0156R0 lock_guard variadic](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0156r0.html)|VS 2015.2|
|&nbsp;&nbsp;[N3911 void_t](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3911.pdf)|VS 2015|
|&nbsp;&nbsp;[N4089 Conversões seguras em unique_ptr\<T[]>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4089.pdf)|VS 2015|
|&nbsp;&nbsp;[N4169 invoke()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4169.html)|VS 2015|
|&nbsp;&nbsp;[N4190 Removendo auto_ptr, random_shuffle() e \<itens functional>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4190.htm) antigos|VS 2015|
|&nbsp;&nbsp;[N4258 Limpezas de noexcept](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4258.pdf)|VS 2015|
|&nbsp;&nbsp;[N4259 uncaught_exceptions()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4259.pdf)|VS 2015|
|&nbsp;&nbsp;[N4277 reference_wrapper facilmente copiado](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4277.html)|VS 2015|
|&nbsp;&nbsp;[N4279 insert_or_assign()/try_emplace() para map/unordered_map](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4279.html)|VS 2015|
|&nbsp;&nbsp;[N4280 size(), empty(), data()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4280.pdf)|VS 2015|
|&nbsp;&nbsp;[N4366 Atribuição unique_ptr de restrição precisa](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4366.html)|VS 2015|
|&nbsp;&nbsp;[N4389 bool_constant](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4389.html)|VS 2015|
|&nbsp;&nbsp;[N4510 Dando suporte a tipos incompletos em vector/list/forward_list](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4510.html)|VS 2013|
|&nbsp;&nbsp;[N4284 Iteradores contíguos](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4284.html)|N/D|
|&nbsp;&nbsp;[P0175R1 Sinopses para a biblioteca C](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0175r1.html)|N/D|
|&nbsp;&nbsp;[P0180R2 Reservando namespaces para padronização futura](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0180r2.html)|N/D|
|&nbsp;&nbsp;[P0346R1 Um ajuste de nomenclatura \<random>](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0346r1.pdf)|N/D|
|&nbsp;&nbsp;[P0371R1 Desencorajando memory_order_consume](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0371r1.html)|N/D|
|&nbsp;&nbsp;P0467R2 Exigir iteradores de encaminhamento algoritmos paralelos|N/D|
|&nbsp;&nbsp;[P0502R0 Algoritmos paralelos devem conter terminate() para exceções, geralmente](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0502r0.html)|N/D|
|&nbsp;&nbsp;[P0503R0 Corrigindo o uso da biblioteca de “tipo literal”](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0503r0.html)|N/D|
|&nbsp;&nbsp;[P0509R1 Atualizando “Restrições na manipulação de exceção”](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0509r1.pdf)|N/D|
|&nbsp;&nbsp;P0518R1 Copiando elementos construíveis de cópia trivialmente em algoritmos paralelos|N/D|
|&nbsp;&nbsp;P0523R1 Relaxando requisitos de complexidade de algoritmos paralelos (geral)|N/D|
|&nbsp;&nbsp;P0574R1 Relaxando requisitos de complexidade de algoritmos paralelos (específico)|N/D|
|&nbsp;&nbsp;P0623R0 Correções de algoritmos paralelos C++17 finais|N/D|
|__Recursos da Biblioteca Padrão C++14__|__Com suporte__|
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
|&nbsp;&nbsp;[N3924 Desencorajando rand()](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3924.pdf)|N/D|  
  
Um grupo de documentos listados juntos indica que um recurso foi votado no Padrão e, em seguida, um ou mais documentos para melhorar ou expandir esse recurso também foram votados. Esses recursos são implementados juntos.  
  
### <a name="supported-values"></a>Valores com suporte  
__Não__ significa ainda não implementado.  
__Parcial__ significa que a implementação no Visual Studio 2017 está incompleta. Para obter mais detalhes, consulte a seção Observações.  
__N/D__ significa que os documentos de proposta não descrevem recursos. Esses documentos alteraram a linguagem do padrão, mas não criou nenhum trabalho para implementadores. Eles estão listados aqui para integridade.  
__VS 2010__ indica os recursos que tem suporte no Visual Studio 2010.  
__VS 2013__ indica os recursos que tem suporte no Visual Studio 2013.  
__VS 2015__ indica os recursos com suporte no Visual Studio 2015 RTM.  
__VS 2015.2__ e __VS 2015.3__ indicam os recursos com suporte no Visual Studio 2015 Atualização 2 e no Visual Studio 2015 Atualização 3, respectivamente.  
__VS 2017__ indica os recursos com suporte no Visual Studio 2017 RTM.  
__VS 2017.x__ indica os recursos planejados para uma atualização futura do Visual Studio 2017.  
  
### <a name="notes"></a>Observações  
<a name="note_1"></a>__1__ Isso ignora as especificações de exceção dinâmica do C++03, que foram preteridas no C++11. Não há nenhum plano para implementá-las, na expectativa de que elas serão removidas de um futuro Padrão do C++.  
<a name="note_2"></a>__2__ O suporte do compilador da Expressão SFINAE era suficiente para a Biblioteca Padrão desde o Visual Studio 2015 Atualização 2, mas o suporte permanece incompleto.  
<a name="note_3"></a>__3__ O suporte do compilador às regras do Pré-processador C99 está incompleto no Visual Studio 2017. Há suporte para macros variadic, mas existem diversos bugs no comportamento do pré-processador.  
<a name="note_4"></a>__4__ Isso está marcado como Não Aplicável, pois os compiladores são permitidos, mas não obrigatórios, para dar suporte a tipos inteiros estendidos.  Como GCC e Clang, decidimos não dar suporte a eles.  
<a name="note_5"></a>__5__ Da mesma forma, isso é marcado como Não Aplicável, pois os compiladores são permitidos, mas não obrigatórios, para implementar essa otimização.  
<a name="note_6"></a>__6__ Recursos que não foram concluídos no Visual Studio 2015 são divididos em outro lugar na tabela.  
<a name="note_7"></a>__7__ O Filesystem TS é implementado em \<experimental/filesystem> e \<filesystem> por razões históricas, mas sua implementação deve ser corrigida antes que o namespace seja movido. Até que isso seja concluído, o recurso é marcado como ainda não implementado.  
<a name="note_star"></a>__*__ Esses recursos estão protegidos pela opção do compilador [/std:c++latest](./build/reference/std-specify-language-standard-version.md).  
  
## <a name="see-also"></a>Consulte também  
[Referência da linguagem C++](cpp/cpp-language-reference.md)  
[Biblioteca padrão C++](standard-library/cpp-standard-library-reference.md)   
[Aprimoramentos de conformidade do C++ no Visual Studio 2017](cpp-conformance-improvements-2017.md)  
[Novidades do Visual C++ no Visual Studio 2017](what-s-new-for-visual-cpp-in-visual-studio.md)  
[Histórico de alterações de 2003 a 2015 do Visual C++](porting/visual-cpp-change-history-2003-2015.md)  
[O que há de novo no Visual C++ de 2003 até 2015](porting/visual-cpp-what-s-new-2003-through-2015.md)  
[Blog da equipe do Visual C++](http://blogs.msdn.microsoft.com/vcblog/)  


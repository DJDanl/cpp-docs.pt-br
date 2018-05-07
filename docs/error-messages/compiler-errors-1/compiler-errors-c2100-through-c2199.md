---
title: Erros C2100 a C2199 | Microsoft Docs
ms.custom: ''
ms.date: 11/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2119
- C2123
- C2125
- C2126
- C2127
- C2131
- C2136
- C2176
- C2187
- C2189
helpviewer_keywords:
- C2119
- C2123
- C2125
- C2126
- C2127
- C2131
- C2136
- C2176
- C2187
- C2189
dev_langs:
- C++
ms.assetid: 1ccab076-0954-4386-b959-d3112a6793ae
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f276776028fde88e4ef1e4559f0dd4db08abfe03
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-errors-c2100-through-c2199"></a>Erros C2100 a C2199 (compilador)

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C2100](compiler-error-c2100.md)|indireção ilegal|
|[Erro do compilador C2101](compiler-error-c2101.md)|' &' na constante|
|[Erro do compilador C2102](compiler-error-c2102.md)|' &' requer valor l|
|[Erro do compilador C2103](compiler-error-c2103.md)|' &' registrar na variável|
|[Erro do compilador C2104](compiler-error-c2104.md)|' &' no campo de bits ignorado|
|[Erro do compilador C2105](compiler-error-c2105.md)|'*operador*' precisa de valor de l|
|[Erro do compilador C2106](compiler-error-c2106.md)|'*operador*': operando da esquerda deve ser o valor de l|
|[Erro do compilador C2107](compiler-error-c2107.md)|índice inválido, indireção não permitida|
|[Erro do compilador C2108](compiler-error-c2108.md)|subscrito não é do tipo integral|
|[Erro do compilador C2109](compiler-error-c2109.md)|subscrito requer tipo de ponteiro ou matriz|
|[Erro do compilador C2110](compiler-error-c2110.md)|'+': não é possível adicionar dois ponteiros|
|[Erro do compilador C2111](compiler-error-c2111.md)|'+': ponteiro requer operando integral|
|[Erro do compilador C2112](compiler-error-c2112.md)|'-': subtração de ponteiros requer operando integral ou ponteiro|
|[Erro do compilador C2113](compiler-error-c2113.md)|'-': ponteiro só pode ser subtraído de outro ponteiro|
|[Erro do compilador C2114](compiler-error-c2114.md)|'*operador*': ponteiro esquerda; necessidades valor integral à direita|
|[Erro do compilador C2115](compiler-error-c2115.md)|'*operador*': tipos incompatíveis|
|[Erro do compilador C2116](compiler-error-c2116.md)|listas de parâmetros de função diferente|
|[Erro do compilador C2117](compiler-error-c2117.md)|'*identificador*': estouro nos limites da matriz|
|[Erro do compilador C2118](compiler-error-c2118.md)|subscrito negativo|
|C2119 de erro do compilador|'*identificador*': o tipo para '*tipo*' não pode ser deduzido por meio de um inicializador vazio|
|[Erro do compilador C2120](compiler-error-c2120.md)|'void' inválido com todos os tipos|
|[Erro do compilador C2121](compiler-error-c2121.md)|'#': caractere inválido: possivelmente o resultado de uma expansão de macro|
|[Erro do compilador C2122](compiler-error-c2122.md)|'*identificador*': parâmetro de protótipo na lista de nomes inválido|
|C2123 de erro do compilador|'*identificador*': modelos de alias não podem ser explicitamente ou parcialmente especializados|
|[Erro do compilador C2124](compiler-error-c2124.md)|divisão ou mod por zero|
|C2125 de erro do compilador|'constexpr' não é compatível com '*token*'|
|C2126 de erro do compilador|'*identificador*' não pode ser declarado com o especificador 'constexpr'|
|C2127 de erro do compilador|'*identificador*': inicialização ilegal da entidade 'constexpr' com uma expressão não constante|
|[Erro do compilador C2128](compiler-error-c2128.md)|'*função*': alloc_text/same_seg aplicável apenas a funções com vínculo a C|
|[Erro do compilador C2129](compiler-error-c2129.md)|função static '*identificador*' declarada mas não definido|
|[Erro do compilador C2130](compiler-error-c2130.md)|#line esperada uma cadeia de caracteres que contém o nome do arquivo, encontrado '*token*'|
|C2131 de erro do compilador|expressão não foi avaliada como uma constante|
|[Erro do compilador C2132](compiler-error-c2132.md)|Erro de sintaxe: identificador inesperado|
|[Erro do compilador C2133](compiler-error-c2133.md)|'*identificador*': tamanho desconhecido|
|[Erro do compilador C2134](compiler-error-c2134.md)|'*função*': chamada não resulta em uma expressão constante|
|[Erro do compilador C2135](compiler-error-c2135.md)|'*operador*': operação de campo de bits inválida|
|C2136 de erro do compilador|contrato de API de criação não permitido|
|[Erro do compilador C2137](compiler-error-c2137.md)|constante de caractere vazio|
|[Erro do compilador C2138](compiler-error-c2138.md)|não é possível definir uma enumeração sem nenhum membro|
|[Erro do compilador C2139](compiler-error-c2139.md)|'*classe*': uma classe indefinida não é permitida como um argumento para a característica de tipo intrínseco do compilador '*característica*'|
|[Erro do compilador C2140](compiler-error-c2140.md)|'*tipo*': um tipo que é dependente de um parâmetro de tipo genérico não é permitido como um argumento para a característica de tipo intrínseco do compilador '*característica*'|
|[Erro do compilador C2141](compiler-error-c2141.md)|estouro de tamanho de matriz|
|[Erro do compilador C2142](compiler-error-c2142.md)|declarações de função diferem, parâmetros variáveis especificados em apenas uma delas|
|[Erro do compilador C2143](compiler-error-c2143.md)|Erro de sintaxe: faltando '*token1*'before'*token2*'|
|[Erro do compilador C2144](compiler-error-c2144.md)|Erro de sintaxe: '*tipo*'deve ser precedido por'*token2*'|
|[Erro do compilador C2145](compiler-error-c2145.md)|Erro de sintaxe: faltando '*token*' antes do identificador|
|[Erro do compilador C2146](compiler-error-c2146.md)|Erro de sintaxe: faltando '*token*'antes do identificador'*identificador*'|
|[Erro do compilador C2147](compiler-error-c2147.md)|Erro de sintaxe: '*token*' é uma palavra-chave new|
|[Erro do compilador C2148](compiler-error-c2148.md)|tamanho total da matriz não deve exceder 0x*valor* bytes|
|[Erro do compilador C2149](compiler-error-c2149.md)|'*identificador*': campo de bits nomeado não pode ter largura zero|
|[Erro do compilador C2150](compiler-error-c2150.md)|'*identificador*': campo de bits deve possuir tipo 'int', 'signed int' ou 'unsigned int'|
|[Erro do compilador C2151](compiler-error-c2151.md)|mais de um atributo de idioma|
|[Erro do compilador C2152](compiler-error-c2152.md)|'*identificador*': ponteiros para funções com atributos diferentes|
|[Erro do compilador C2153](compiler-error-c2153.md)|literais inteiros devem ter pelo menos um dígito|
|[Erro do compilador C2154](compiler-error-c2154.md)|'*tipo*': somente tipo de enumeração é permitido como um argumento para a característica de tipo intrínseco do compilador '*característica*'|
|[Erro do compilador C2155](compiler-error-c2155.md)|'?': operando esquerdo inválido, esperado aritmética ou tipo de ponteiro|
|[Erro do compilador C2156](compiler-error-c2156.md)|pragma deve estar fora da função|
|[Erro do compilador C2157](compiler-error-c2157.md)|'*identificador*': deve ser declarado antes do uso em lista de pragma|
|[Erro do compilador C2158](compiler-error-c2158.md)|'*tipo*': #pragma make_public diretiva atualmente há suporte para tipos não template nativos somente|
|[Erro do compilador C2159](compiler-error-c2159.md)|mais de uma classe de armazenamento especificada|
|[Erro do compilador C2160](compiler-error-c2160.md)|' # # ' não pode ocorrer no início de uma definição de macro|
|[Erro do compilador C2161](compiler-error-c2161.md)|' # # ' não pode ocorrer no final de uma definição de macro|
|[Erro do compilador C2162](compiler-error-c2162.md)|parâmetro formal de macro esperado|
|[Erro do compilador C2163](compiler-error-c2163.md)|'*função*': não disponível como uma função intrínseca|
|[Erro do compilador C2164](compiler-error-c2164.md)|'*função*': função intrínseca não declarada|
|[Erro do compilador C2165](compiler-error-c2165.md)|'*modificador*': não é possível modificar ponteiros para dados|
|[Erro do compilador C2166](compiler-error-c2166.md)|l-value Especifica objeto const|
|[Erro do compilador C2167](compiler-error-c2167.md)|'*função*': muitos parâmetros reais para função intrínseca|
|[Erro do compilador C2168](compiler-error-c2168.md)|'*função*': poucos parâmetros reais para função intrínseca|
|[Erro do compilador C2169](compiler-error-c2169.md)|'*função*': função intrínseca, não pode ser definido|
|[Erro do compilador C2170](compiler-error-c2170.md)|'*identificador*': não é declarada como uma função, não pode ser intrínseco|
|[Erro do compilador C2171](compiler-error-c2171.md)|'*operador*': inválido em operandos do tipo '*tipo*'|
|[Erro do compilador C2172](compiler-error-c2172.md)|'*função*': parâmetro real não é um ponteiro: parâmetro *número*|
|[Erro do compilador C2173](compiler-error-c2173.md)|'*função*': parâmetro real não é um ponteiro: parâmetro *número*, lista de parâmetros *número*|
|[Erro do compilador C2174](compiler-error-c2174.md)|'*função*': parâmetro real possui tipo 'void': parâmetro *número*, lista de parâmetros *número*|
|[Erro do compilador C2175](compiler-error-c2175.md)|'*localidade*': localidade inválida|
|C2176 de erro do compilador|uma instrução return não pode aparecer no manipulador de um função de bloco try associado com um construtor|
|[Erro do compilador C2177](compiler-error-c2177.md)|constante muito grande|
|[Erro do compilador C2178](compiler-error-c2178.md)|'*identificador*'não pode ser declarado com'*especificador*' especificador|
|[Erro do compilador C2179](compiler-error-c2179.md)|'*tipo*': um argumento de atributo não é possível usar parâmetros de tipo|
|[Erro do compilador C2180](compiler-error-c2180.md)|expressão de controle tem o tipo '*tipo*'|
|[Erro do compilador C2181](compiler-error-c2181.md)|else inválido sem if correspondente|
|[Erro do compilador C2182](compiler-error-c2182.md)|'*identificador*': uso inválido do tipo 'void'|
|[Erro do compilador C2183](compiler-error-c2183.md)|Erro de sintaxe: unidade de tradução está vazia|
|[Erro do compilador C2184](compiler-error-c2184.md)|'*tipo*': tipo inválido para expressão except|
|[Erro do compilador C2185](compiler-error-c2185.md)|'*identificador*': alocação based inválida|
|[Erro do compilador C2186](compiler-error-c2186.md)|'*operador*': operando inválido do tipo 'void'|
|C2187 de erro do compilador|Erro de sintaxe: '*token*' era esperado aqui|
|[Erro do compilador C2188](compiler-error-c2188.md)|'*número*': muito grande para caractere largo|
|C2189 de erro do compilador|o atributo 'alignas' não pode ser aplicado a um campo de bits, um parâmetro de função, uma declaração de exceção ou uma variável declarada com 'Registrar' classe de armazenamento|
|[Erro do compilador C2190](compiler-error-c2190.md)|primeira lista de parâmetros mais de segundo|
|[Erro do compilador C2191](compiler-error-c2191.md)|segunda lista de parâmetro maior do que o primeiro|
|[Erro do compilador C2192](compiler-error-c2192.md)|parâmetro '*número*' diferente de declaração|
|[Erro do compilador C2193](compiler-error-c2193.md)|'*identificador*': já está em um segmento|
|[Erro do compilador C2194](compiler-error-c2194.md)|'*identificador*': é um segmento de texto|
|[Erro do compilador C2195](compiler-error-c2195.md)|'*identificador*': é um segmento de dados|
|[Erro do compilador C2196](compiler-error-c2196.md)|Caso o valor '*valor*' já foi usado|
|[Erro do compilador C2197](compiler-error-c2197.md)|'*função*': muitos argumentos para chamada|
|[Erro do compilador C2198](compiler-error-c2198.md)|'*função*': poucos argumentos para chamada|
|[Erro do compilador C2199](compiler-error-c2199.md)|Erro de sintaxe: encontrado '*identificador* (' no escopo global (uma declaração estava planejada?)|  
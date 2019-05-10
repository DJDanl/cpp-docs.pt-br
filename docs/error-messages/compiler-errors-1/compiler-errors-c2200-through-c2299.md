---
title: Erros do compilador C2200 a C2299
ms.date: 04/21/2019
f1_keywords:
- C2202
- C2209
- C2210
- C2211
- C2214
- C2215
- C2221
- C2225
- C2230
- C2235
- C2237
- C2239
- C2240
- C2257
- C2260
- C2263
- C2265
- C2269
- C2278
- C2281
- C2282
- C2288
- C2291
- C2294
helpviewer_keywords:
- C2202
- C2209
- C2210
- C2211
- C2214
- C2215
- C2221
- C2225
- C2230
- C2235
- C2237
- C2239
- C2240
- C2257
- C2260
- C2263
- C2265
- C2269
- C2278
- C2281
- C2282
- C2288
- C2291
- C2294
ms.assetid: 9b36d11b-9510-4390-96f1-0c9235124d14
ms.openlocfilehash: 5af97ab46a97d3019abcc937cc0a74c5f865a9ff
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64857101"
---
# <a name="compiler-errors-c2200-through-c2299"></a>Erros do compilador C2200 a C2299

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C2200](compiler-error-c2200.md)|'*função*': função já foi definida|
|[Erro do compilador C2201](compiler-error-c2201.md)|'*identificador*': deve ter vinculação externa para ser exportado/importado|
|Erro do compilador C2202|'*função*': nem todos os caminhos de controle retornam um valor|
|[Erro do compilador C2203](compiler-error-c2203.md)|Excluir operador não é possível especificar limites para uma matriz|
|[Erro do compilador C2204](compiler-error-c2204.md)|'*tipo*': definição de tipo encontrada dentro dos parênteses|
|[Erro do compilador C2205](compiler-error-c2205.md)|'*identificador*': não é possível inicializar variáveis extern com escopo de bloco|
|[Erro do compilador C2206](compiler-error-c2206.md)|'*função*': typedef não pode ser usado para definição de função|
|[Erro do compilador C2207](compiler-error-c2207.md)|'*membro*': um membro de um modelo de classe não é possível adquirir um tipo de função|
|[Erro do compilador C2208](compiler-error-c2208.md)|'*tipo*': nenhum membro definido usando esse tipo|
|Erro do compilador C2209|'*identificador*': aliases não podem ser usados em declarações de construtor|
|Erro do compilador C2210|'*identificador*': expansões de pacote não podem ser usados como argumentos para parâmetros não incluídos nos modelos de alias|
|Erro do compilador C2211|Um destruidor não virtual em uma classe ref derivado de uma classe ref com um destruidor público também deve ser público|
|[Erro do compilador C2212](compiler-error-c2212.md)|'*identificador*': based não disponível para ponteiros para funções|
|[Erro do compilador C2213](compiler-error-c2213.md)|'*identificador*': argumento inválido para based|
|Erro do compilador C2214|ponteiros baseados em 'void' requerem o uso de: >|
|Erro do compilador C2215|'*palavra-chave*' não pode ser usado com ' / /arch: SSE'|
|[Erro do compilador C2216](compiler-error-c2216.md)|'*palavrachave1*'não pode ser usado com'*keyword2*'|
|[Erro do compilador C2217](compiler-error-c2217.md)|'*attribute1*'requer'*attribute2*'|
|[Erro do compilador C2218](compiler-error-c2218.md)|'*calltype*' não pode ser usado com ' / arch:IA32 '|
|[Erro do compilador C2219](compiler-error-c2219.md)|Erro de sintaxe: qualificador de tipo deve ser posterior a ' *'|
|[Erro do compilador C2220](compiler-error-c2220.md)|Aviso tratado como erro - não '*filetype*' arquivo gerado|
|Erro do compilador C2221|Obsoleto.|
|[Erro do compilador C2222](compiler-error-c2222.md)|tipo inesperado '*tipo*': uma classe base ou membro era esperado|
|[Erro do compilador C2223](compiler-error-c2223.md)|esquerda de ' ->*identificador*' deve apontar para struct/union|
|[Erro do compilador C2224](compiler-error-c2224.md)|esquerda de '. *identificador*' deve possuir tipo struct/union|
|Erro do compilador C2225|Obsoleto.|
|[Erro do compilador C2226](compiler-error-c2226.md)|Erro de sintaxe: tipo inesperado '*tipo*'|
|[Erro do compilador C2227](compiler-error-c2227.md)|esquerda de ' ->*identificador*' deve apontar para o tipo de classe/struct/union/generic|
|[Erro do compilador C2228](compiler-error-c2228.md)|esquerda de '. *identificador*' deve ter a classe/struct/union|
|[Erro do compilador C2229](compiler-error-c2229.md)|classe/struct/union '*tipo*' tem uma matriz de tamanho zero ilegal|
|Erro do compilador C2230|não foi possível localizar o módulo '*nome*'|
|[Erro do compilador C2231](compiler-error-c2231.md)|'. *identificador*': operando da esquerda aponta para 'class/struct/union', use '->'|
|[Erro do compilador C2232](compiler-error-c2232.md)|' ->*identificador*': operando esquerdo tiver ' class/struct/union ' tipo,'.' use|
|[Erro do compilador C2233](compiler-error-c2233.md)|'*identificador*': matrizes de objetos contendo matrizes de tamanho zero são inválidas|
|[Erro do compilador C2234](compiler-error-c2234.md)|*identificador*': matrizes de referências são inválidas|
|Erro do compilador C2235|Obsoleto.|
|[Erro do compilador C2236](compiler-error-c2236.md)|token inesperado '*token*'. Você esqueceu um ';'?|
|Erro do compilador C2237|declaração de vários módulos|
|[Erro do compilador C2238](compiler-error-c2238.md)|tokens inesperados anteriores '*token*'|
|Erro do compilador C2239|'*função*': tentativa de excluir uma função de dllexport|
|Erro do compilador C2240|Obsoleto.|
|[Erro do compilador C2241](compiler-error-c2241.md)|'*identificador*': acesso de membro é restrito|
|[Erro do compilador C2242](compiler-error-c2242.md)|nome de TypeDef não pode seguir classe/struct/union|
|[Erro do compilador C2243](compiler-error-c2243.md)|'*conversion_type*': conversão de '*type1*'para'*type2*' existe, mas está inacessível|
|[Erro do compilador C2244](compiler-error-c2244.md)|'*identificador*': não é possível corresponder a definição de função para uma declaração existente|
|[Erro do compilador C2245](compiler-error-c2245.md)|função de membro não existente '*função*' especificada como friend (assinatura de função de membro não corresponde a nenhuma sobrecarga)|
|[Erro do compilador C2246](compiler-error-c2246.md)|'*identificador*': membro de dados static inválido em classe definida localmente|
|[Erro do compilador C2247](compiler-error-c2247.md)|'*identificador*' não está acessível porque '*class1*'usa'*especificador*' para herdar de'*class2*'|
|[Erro do compilador C2248](compiler-error-c2248.md)|'*identificador*': não é possível acessar *acessibilidade* *membro* declarado na classe*classe*'|
|[Erro do compilador C2249](compiler-error-c2249.md)|'*identificador*': nenhum caminho acessível para *acessibilidade* *membro* declarado na base virtual '*classe*'|
|[Erro do compilador C2250](compiler-error-c2250.md)|'*identificador*': herança ambígua de *classe*::*membro*'|
|[Erro do compilador C2251](compiler-error-c2251.md)|namespace '*namespace*'não tem um membro'*identificador*'-você quis dizer '*membro*'?|
|[Erro do compilador C2252](compiler-error-c2252.md)|uma instanciação explícita de um modelo só pode ocorrer no escopo do namespace|
|[Erro do compilador C2253](compiler-error-c2253.md)|'*função*': especificador puro ou abstract permitido apenas em função virtual de especificador de substituição|
|[Erro do compilador C2254](compiler-error-c2254.md)|'*função*': especificador puro ou substituição abstract especificador não permitido em função friend|
|[Erro do compilador C2255](compiler-error-c2255.md)|'*elemento*': não é permitida fora de uma definição de classe|
|[Erro do compilador C2256](compiler-error-c2256.md)|Uso inválido de especificador friend em '*função*'|
|Erro do compilador C2257|'*especificador*': especificador não permitido no tipo de retorno à direita|
|[Erro do compilador C2258](compiler-error-c2258.md)|sintaxe pura inválida, deve ser '= 0'|
|[Erro do compilador C2259](compiler-error-c2259.md)|'*classe*': não é possível instanciar a classe abstrata|
|Erro do compilador C2260|'*especificador*': especificador de assembly de amigo InternalsVisibleToAttribute inválido|
|[Erro do compilador C2261](compiler-error-c2261.md)|'*cadeia de caracteres*': referência de assembly é inválida e não pode ser resolvida|
|[Erro do compilador C2262](compiler-error-c2262.md)|'*specifier*': Declarações InternalsVisibleTo não podem ter uma arquitetura de versão, cultura ou processador especificada|
|Erro do compilador C2263|Obsoleto.|
|[Erro do compilador C2264](compiler-error-c2264.md)|'*função*': erro na declaração ou definição de função; função não chamada|
|Erro do compilador C2265|Obsoleto.|
|[Erro do compilador C2266](compiler-error-c2266.md)|'*identificador*': referência a uma matriz de limite não constante é ilegal|
|[Erro do compilador C2267](compiler-error-c2267.md)|'*função*': funções static com escopo de bloco são ilegais|
|[Erro do compilador C2268](compiler-error-c2268.md)|'*função*' é um auxiliar de biblioteca do compilador predefinido. Biblioteca não são suportadas com /GL; Compilar arquivo de objeto '*filename*' sem /GL.|
|Erro do compilador C2269|não é possível criar um ponteiro ou referência a um tipo de função qualificado (requer o ponteiro para membro)|
|[Erro do compilador C2270](compiler-error-c2270.md)|'*função*': modificadores não permitidos em funções não membro|
|[Erro do compilador C2271](compiler-error-c2271.md)|'*função*': new/delete não podem ter modificadores de lista formal|
|[Erro do compilador C2272](compiler-error-c2272.md)|'*função*': modificadores não permitidos em funções de membro estático|
|[Erro do compilador C2273](compiler-error-c2273.md)|'*tipo*': inválido como lado direito do operador '->'|
|[Erro do compilador C2274](compiler-error-c2274.md)|'*tipo*': inválido como lado direito de '.' operador|
|[Erro do compilador C2275](compiler-error-c2275.md)|'*tipo*': uso inválido deste tipo como uma expressão|
|[Erro do compilador C2276](compiler-error-c2276.md)|'*operador*': operação inválida na expressão de função de membro associada|
|[Erro do compilador C2277](compiler-error-c2277.md)|'*função*': não é possível tomar o endereço dessa função de membro|
|Erro do compilador C2278|Obsoleto.|
|[Erro do compilador C2279](compiler-error-c2279.md)|especificação de exceção não pode aparecer em uma declaração de typedef|
|[Erro do compilador C2280](compiler-error-c2280.md)|'*classe*::*função*': tentativa de fazer referência a uma função excluída|
|Erro do compilador C2281|'*classe*::*função*': uma função só pode ser excluída na primeira declaração|
|Erro do compilador C2282|'*função1*'não pode substituir'*função2*'|
|[Erro do compilador C2283](compiler-error-c2283.md)|'*identificador*': especificador puro ou substituição abstract especificador não permitido na classe/struct sem nome|
|Erro do compilador C2284|'*função*': argumento inválido para função intrínseca, parâmetro *número*|
|[Erro do compilador C2285](compiler-error-c2285.md)|ponteiros para representação de membros já foi determinada - pragma ignorado|
|[Erro do compilador C2286](compiler-error-c2286.md)|ponteiros para membros de '*identificador*' representação já está definida como *herança* -declaração ignorada|
|[Erro do compilador C2287](compiler-error-c2287.md)|'*identificador*': representação de herança: '*inheritiance*'é menos geral do que o necessário'*herança*'|
|Erro do compilador C2288|Obsoleto.|
|[Erro do compilador C2289](compiler-error-c2289.md)|mesmo qualificador de tipo usado mais de uma vez|
|[Erro do compilador C2290](compiler-error-c2290.md)|Sintaxe de 'asm' C++ ignorado. Use ASM.|
|Erro do compilador C2291|Um namespace anônimo não pode ser exportado.|
|[Erro do compilador C2292](compiler-error-c2292.md)|'*identificador*': representação de herança de melhor caso: *inheritance1*' declarado mas '*e herança 2*' necessária|
|[Erro do compilador C2293](compiler-error-c2293.md)|'*identificador*': ilegal para ter uma variável de membro como um especificador based|
|Erro do compilador C2294|não é possível exportar o símbolo '*identificador*' porque ele tem vinculação interna|
|[Erro do compilador C2295](compiler-error-c2295.md)|escape '*caractere*': é ilegal na definição de macro|
|[Erro do compilador C2296](compiler-error-c2296.md)|'*operador*': inválido, operando esquerdo possui tipo '*tipo*'|
|[Erro do compilador C2297](compiler-error-c2297.md)|'*operador*': inválido, operando direito possui tipo '*tipo*'|
|[Erro do compilador C2298](compiler-error-c2298.md)|chamada para limite de ponteiro para função de membro ausente|
|[Erro do compilador C2299](compiler-error-c2299.md)|'*função*': alteração de comportamento: uma especialização explícita não pode ser um construtor de cópia ou operador de atribuição de cópia|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 - C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)

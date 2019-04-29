---
title: Erros do compilador C2000 a C2099
ms.date: 04/21/2019
f1_keywords:
- C2000
- C2016
- C2023
- C2024
- C2025
- C2029
- C2031
- C2035
- C2037
- C2038
- C2049
- C2068
- C2076
- C2080
- C2096
- C2098
helpviewer_keywords:
- C2000
- C2016
- C2023
- C2024
- C2025
- C2029
- C2031
- C2035
- C2037
- C2038
- C2049
- C2068
- C2076
- C2080
- C2096
- C2098
ms.assetid: d99a19eb-eeeb-4181-9b33-9cbe4459767b
ms.openlocfilehash: cf1d2f647c13b589463624749e29dc277f6f1d3e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360483"
---
# <a name="compiler-errors-c2000-through-c2099"></a>Erros do compilador C2000 a C2099

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|Erro do compilador C2000|Erro desconhecido, escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|
|[Erro do compilador C2001](compiler-error-c2001.md)|Newline em constante|
|[Erro do compilador C2002](compiler-error-c2002.md)|constante de caractere largo inválida|
|[Erro do compilador C2003](compiler-error-c2003.md)|esperado 'defined id'|
|[Erro do compilador C2004](compiler-error-c2004.md)|esperado 'defined (ID)'|
|[Erro do compilador C2005](compiler-error-c2005.md)|#line esperado um número de linha, encontrado '*token*'|
|[Erro do compilador C2006](compiler-error-c2006.md)|'*diretiva*': esperado um nome de arquivo, encontrado '*token*'|
|[Erro do compilador C2007](compiler-error-c2007.md)|#define sintaxe|
|[Erro do compilador C2008](compiler-error-c2008.md)|'*caractere*': inesperado na definição de macro|
|[Erro do compilador C2009](compiler-error-c2009.md)|reutilização de macro formal '*identificador*'|
|[Erro do compilador C2010](compiler-error-c2010.md)|'*caractere*': inesperado na lista de parâmetros formais de macro|
|[Erro do compilador C2011](compiler-error-c2011.md)|'*identificador*': '*tipo*' redefinição do tipo|
|[Erro do compilador C2012](compiler-error-c2012.md)|faltando nome após ' <'|
|[Erro do compilador C2013](compiler-error-c2013.md)|faltando ' >'|
|[Erro do compilador C2014](compiler-error-c2014.md)|comando de pré-processador deve começar como primeiro caractere diferente de espaço|
|[Erro do compilador C2015](compiler-error-c2015.md)|número excessivo de caracteres na constante|
|Erro do compilador C2016|C requer que uma struct ou união tem pelo menos um membro|
|[Erro do compilador C2017](compiler-error-c2017.md)|sequência de escape ilegal|
|[Erro do compilador C2018](compiler-error-c2018.md)|caractere desconhecido ' 0 x*valor*'|
|[Erro do compilador C2019](compiler-error-c2019.md)|esperada diretiva de pré-processador, encontrado '*caractere*'|
|[Erro do compilador C2020](compiler-error-c2020.md)|'*membro*': '*classe*' redefinição de membro|
|[Erro do compilador C2021](compiler-error-c2021.md)|esperado valor de expoente, não '*caractere*'|
|[Erro do compilador C2022](compiler-error-c2022.md)|'*número*': muito grande para caractere|
|Erro do compilador C2023|'*identifier*': Alinhamento (*Número1*) diferente da declaração anterior (*Número2*)|
|Erro do compilador C2024|o atributo 'alignas' se aplica a variáveis, membros de dados e somente os tipos de marcas|
|Erro do compilador C2025|arquivo de interface de módulo binário corrompido ou inválido: '*filename*'|
|[Erro do compilador C2026](compiler-error-c2026.md)|cadeia de caracteres muito grande, caracteres truncados à direita|
|[Erro do compilador C2027](compiler-error-c2027.md)|uso do tipo indefinido '*tipo*'|
|[Erro do compilador C2028](compiler-error-c2028.md)|membro de struct/union deve estar dentro de uma struct/union|
|Erro do compilador C2029|esquerda de '*token*'especifica indefinido class/struct/interface'*identificador*'|
|[Erro do compilador C2030](compiler-error-c2030.md)|um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'selada'|
|Erro do compilador C2031|um destruidor virtual com '*acessibilidade*' acessibilidade não é permitida para esse tipo|
|[Erro do compilador C2032](compiler-error-c2032.md)|'*identificador*': função não pode ser membro de struct/union '*tipo*'|
|[Erro do compilador C2033](compiler-error-c2033.md)|'*identificador*': campo de bits não pode possuir indireção|
|[Erro do compilador C2034](compiler-error-c2034.md)|'*identificador*': tipo de campo de bits muito pequeno para número de bits|
|Erro do compilador C2035|um destruidor não virtual com '*acessibilidade*' acessibilidade não é permitida para esse tipo|
|[Erro do compilador C2036](compiler-error-c2036.md)|'*identificador*': tamanho desconhecido|
|Erro do compilador C2037|esquerda de '*identificador*'especifica struct/union indefinida'*tipo*'|
|Erro do compilador C2038|o namespace std não pode ser embutido|
|[Erro do compilador C2039](compiler-error-c2039.md)|'*identifier1*': não é um membro de '*identifier2*'|
|[Erro do compilador C2040](compiler-error-c2040.md)|'*operador*': '*identifier1*'difere em níveis de indireção de'*identifier2*'|
|[Erro do compilador C2041](compiler-error-c2041.md)|dígito inválido '*caractere*'para base'*número*'|
|[Erro do compilador C2042](compiler-error-c2042.md)|não assinado/assinado palavras-chave mutuamente exclusivas|
|[Erro do compilador C2043](compiler-error-c2043.md)|break inválido|
|[Erro do compilador C2044](compiler-error-c2044.md)|continue inválido|
|[Erro do compilador C2045](compiler-error-c2045.md)|'*identificador*': rótulo redefinido|
|[Erro do compilador C2046](compiler-error-c2046.md)|case inválido|
|[Erro do compilador C2047](compiler-error-c2047.md)|default inválido|
|[Erro do compilador C2048](compiler-error-c2048.md)|mais de um padrão|
|Erro do compilador C2049|'*identificador*': namespace não embutido não pode ser reaberto como embutido|
|[Erro do compilador C2050](compiler-error-c2050.md)|expressão de switch não integral|
|[Erro do compilador C2051](compiler-error-c2051.md)|expressão case não constante|
|[Erro do compilador C2052](compiler-error-c2052.md)|'*tipo*': tipo inválido para expressão case|
|[Erro do compilador C2053](compiler-error-c2053.md)|'*identificador*': incompatibilidade de cadeia de caracteres largos|
|[Erro do compilador C2054](compiler-error-c2054.md)|esperado ' (' a seguir '*identificador*'|
|[Erro do compilador C2055](compiler-error-c2055.md)|esperada lista de parâmetros formais, não uma lista de tipos|
|[Erro do compilador C2056](compiler-error-c2056.md)|Expressão ilegal|
|[Erro do compilador C2057](compiler-error-c2057.md)|expressão de constante esperada|
|[Erro do compilador C2058](compiler-error-c2058.md)|expressão de constante não é integral|
|[Erro do compilador C2059](compiler-error-c2059.md)|Erro de sintaxe: '*token*'|
|[Erro do compilador C2060](compiler-error-c2060.md)|Erro de sintaxe: final do arquivo encontrado|
|[Erro do compilador C2061](compiler-error-c2061.md)|Erro de sintaxe: identificador '*identificador*'|
|[Erro do compilador C2062](compiler-error-c2062.md)|tipo '*tipo*' inesperado|
|[Erro do compilador C2063](compiler-error-c2063.md)|'*identificador*': não é uma função|
|[Erro do compilador C2064](compiler-error-c2064.md)|termo não é avaliada como tendo uma função *número* argumentos|
|[Erro do compilador C2065](compiler-error-c2065.md)|'*identificador*': identificador não declarado|
|[Erro do compilador C2066](compiler-error-c2066.md)|conversão para tipo de função é inválida|
|[Erro do compilador C2067](compiler-error-c2067.md)|conversão para tipo de matriz é inválida|
|Erro do compilador C2068|uso ilegal de função sobrecarregada. Lista de argumentos ausente?|
|[Erro do compilador C2069](compiler-error-c2069.md)|Converter do termo 'void' para não 'void'|
|[Erro do compilador C2070](compiler-error-c2070.md)|'*tipo*': operando de sizeof inválido|
|[Erro do compilador C2071](compiler-error-c2071.md)|'*identificador*': classe de armazenamento inválida|
|[Erro do compilador C2072](compiler-error-c2072.md)|'*identificador*': inicialização de uma função|
|[Erro do compilador C2073](compiler-error-c2073.md)|'*identificador*': elementos de matriz parcialmente inicializada devem ter um construtor padrão|
|[Erro do compilador C2074](compiler-error-c2074.md)|'*identificador*': '*tipo*' inicialização requer uma lista de inicializadores entre chaves|
|[Erro do compilador C2075](compiler-error-c2075.md)|'*identificador*': inicialização de matriz requer uma lista de inicializadores entre chaves|
|Erro do compilador C2076|uma lista de inicializadores entre chaves não pode ser usada em uma expressão new cujo tipo contém '*tipo*'|
|[Erro do compilador C2077](compiler-error-c2077.md)|inicializador de campo não escalar '*identificador*'|
|[Erro do compilador C2078](compiler-error-c2078.md)|Muitos inicializadores|
|[Erro do compilador C2079](compiler-error-c2079.md)|'*identificador*'usa indefinido em class/struct/union'*tipo*'|
|Erro do compilador C2080|'*identificador*': o tipo para '*tipo*' só pode ser deduzido de uma expressão de inicializador único|
|[Erro do compilador C2081](compiler-error-c2081.md)|'*identificador*': nome ilegal da lista de parâmetros formais|
|[Erro do compilador C2082](compiler-error-c2082.md)|redefinição de parâmetro formal '*identificador*'|
|[Erro do compilador C2083](compiler-error-c2083.md)|comparação de struct/union inválida|
|[Erro do compilador C2084](compiler-error-c2084.md)|função '*identificador*' já tem um corpo|
|[Erro do compilador C2085](compiler-error-c2085.md)|'*identificador*': não está na lista de parâmetros formais|
|[Erro do compilador C2086](compiler-error-c2086.md)|'*identificador*': redefinição|
|[Erro do compilador C2087](compiler-error-c2087.md)|'*identificador*': faltando subscrito|
|[Erro do compilador C2088](compiler-error-c2088.md)|'*operador*': inválido para classe/struct/union|
|[Erro do compilador C2089](compiler-error-c2089.md)|'*identificador*': '*tipo*' muito grande|
|[Erro do compilador C2090](compiler-error-c2090.md)|função retorna matriz|
|[Erro do compilador C2091](compiler-error-c2091.md)|função retorna função|
|[Erro do compilador C2092](compiler-error-c2092.md)|'*identificador*' tipo de elemento de matriz não pode ser uma função|
|[Erro do compilador C2093](compiler-error-c2093.md)|'*identifier1*': não pode ser inicializado usando endereço da variável automática '*identifier2*'|
|[Erro do compilador C2094](compiler-error-c2094.md)|rótulo '*identificador*' estava indefinido|
|[Erro do compilador C2095](compiler-error-c2095.md)|'*função*': parâmetro real possui tipo 'void': parâmetro *número*|
|Erro do compilador C2096|'*identifier*': Um membro de dados não pode ser inicializado com um inicializador entre parênteses|
|[Erro do compilador C2097](compiler-error-c2097.md)|inicialização inválida|
|Erro do compilador C2098|token inesperado após o membro de dados '*identificador*'|
|[Erro do compilador C2099](compiler-error-c2099.md)|inicializador não é uma constante|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 - C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)

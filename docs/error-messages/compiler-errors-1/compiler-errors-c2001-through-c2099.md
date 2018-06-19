---
title: C2000 de erros do compilador por meio de C2099 | Microsoft Docs
ms.custom: ''
ms.date: 11/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
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
dev_langs:
- C++
ms.assetid: d99a19eb-eeeb-4181-9b33-9cbe4459767b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f847581673b9410ee9c803ec6928b58c5a4d6927
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33237974"
---
# <a name="compiler-errors-c2000-through-c2099"></a>C2000 de erros do compilador por meio de C2099

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|C2000 de erro do compilador|Erro desconhecido, escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abrir o arquivo de Ajuda do suporte técnico para obter mais informações|
|[Erro do compilador C2001](compiler-error-c2001.md)|nova linha em constante|
|[Erro do compilador C2002](compiler-error-c2002.md)|constante de caractere largo inválido|
|[Erro do compilador C2003](compiler-error-c2003.md)|esperado 'id definida'|
|[Erro do compilador C2004](compiler-error-c2004.md)|esperado 'defined(id)'|
|[Erro do compilador C2005](compiler-error-c2005.md)|#line esperado um número de linha, encontrado '*token*'|
|[Erro do compilador C2006](compiler-error-c2006.md)|'*diretiva*': esperado um nome de arquivo, encontrado '*token*'|
|[Erro do compilador C2007](compiler-error-c2007.md)|#define sintaxe|
|[Erro do compilador C2008](compiler-error-c2008.md)|'*caracteres*': inesperado na definição de macro|
|[Erro do compilador C2009](compiler-error-c2009.md)|reutilização de formal de macro '*identificador*'|
|[Erro do compilador C2010](compiler-error-c2010.md)|'*caracteres*': inesperado na lista de parâmetros formais de macro|
|[Erro do compilador C2011](compiler-error-c2011.md)|'*identificador*': '*tipo*' tipo de redefinição|
|[Erro do compilador C2012](compiler-error-c2012.md)|faltando nome após ' <'|
|[Erro do compilador C2013](compiler-error-c2013.md)|ausente ' >'|
|[Erro do compilador C2014](compiler-error-c2014.md)|comando de pré-processador deve começar como primeiro caractere diferente de espaço|
|[Erro do compilador C2015](compiler-error-c2015.md)|número excessivo de caracteres na constante|
|C2016 de erro do compilador|C requer que uma struct ou união tem pelo menos um membro|
|[Erro do compilador C2017](compiler-error-c2017.md)|sequência de escape ilegal|
|[Erro do compilador C2018](compiler-error-c2018.md)|caractere desconhecido ' 0 x*valor*'|
|[Erro do compilador C2019](compiler-error-c2019.md)|diretiva de pré-processamento esperada, encontrada '*caracteres*'|
|[Erro do compilador C2020](compiler-error-c2020.md)|'*membro*': '*classe*' redefinição de membro|
|[Erro do compilador C2021](compiler-error-c2021.md)|esperado o valor exponencial, não '*caracteres*'|
|[Erro do compilador C2022](compiler-error-c2022.md)|'*número*': muito grande para caractere|
|C2023 de erro do compilador|'*identificador*': alinhamento (*Número1*) diferente da declaração anterior (*Número2*)|
|C2024 de erro do compilador|o atributo 'alignas' se aplica a variáveis, membros de dados e somente os tipos de marcas|
|C2025 de erro do compilador|arquivo de interface de módulo binário corrompido ou inválido: '*filename*'|
|[Erro do compilador C2026](compiler-error-c2026.md)|cadeia de caracteres muito grande, caracteres truncados à direita|
|[Erro do compilador C2027](compiler-error-c2027.md)|uso do tipo indefinido '*tipo*'|
|[Erro do compilador C2028](compiler-error-c2028.md)|membro de struct/union deve estar dentro de uma struct/união|
|C2029 de erro do compilador|esquerda de '*token*'especifica indefinido classe/struct/interface'*identificador*'|
|[Erro do compilador C2030](compiler-error-c2030.md)|um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'lacrada'|
|C2031 de erro do compilador|um destruidor virtual com '*acessibilidade*' acessibilidade não é permitida para este tipo|
|[Erro do compilador C2032](compiler-error-c2032.md)|'*identificador*': função não pode ser membro de struct/união '*tipo*'|
|[Erro do compilador C2033](compiler-error-c2033.md)|'*identificador*': campo de bits não pode possuir indireção|
|[Erro do compilador C2034](compiler-error-c2034.md)|'*identificador*': tipo de campo de bits muito pequeno para número de bits|
|C2035 de erro do compilador|um destruidor não virtual com '*acessibilidade*' acessibilidade não é permitida para este tipo|
|[Erro do compilador C2036](compiler-error-c2036.md)|'*identificador*': tamanho desconhecido|
|C2037 de erro do compilador|esquerda de '*identificador*'especifica struct/union indefinida'*tipo*'|
|C2038 de erro do compilador|o namespace std não pode ser embutido|
|[Erro do compilador C2039](compiler-error-c2039.md)|'*identifier1*': não é um membro de '*identifier2*'|
|[Erro do compilador C2040](compiler-error-c2040.md)|'*operador*': '*identifier1*'difere em níveis de indireção de'*identifier2*'|
|[Erro do compilador C2041](compiler-error-c2041.md)|dígitos inválidos '*caracteres*'para base'*número*'|
|[Erro do compilador C2042](compiler-error-c2042.md)|conectado/unsigned palavras-chave mutuamente exclusivas|
|[Erro do compilador C2043](compiler-error-c2043.md)|interrupção ilegal|
|[Erro do compilador C2044](compiler-error-c2044.md)|continuar ilegal|
|[Erro do compilador C2045](compiler-error-c2045.md)|'*identificador*': rótulo redefinido|
|[Erro do compilador C2046](compiler-error-c2046.md)|Caso ilegal|
|[Erro do compilador C2047](compiler-error-c2047.md)|padrão inválido|
|[Erro do compilador C2048](compiler-error-c2048.md)|mais de um padrão|
|C2049 de erro do compilador|'*identificador*': namespace não embutido não pode ser reaberto como embutido|
|[Erro do compilador C2050](compiler-error-c2050.md)|expressão de switch não integral|
|[Erro do compilador C2051](compiler-error-c2051.md)|expressão case não constante|
|[Erro do compilador C2052](compiler-error-c2052.md)|'*tipo*': tipo inválido para expressão case|
|[Erro do compilador C2053](compiler-error-c2053.md)|'*identificador*': incompatibilidade de cadeia de caracteres larga|
|[Erro do compilador C2054](compiler-error-c2054.md)|esperado ' (' a seguir '*identificador*'|
|[Erro do compilador C2055](compiler-error-c2055.md)|lista de parâmetros formais, não uma lista de tipo de espera|
|[Erro do compilador C2056](compiler-error-c2056.md)|Expressão ilegal|
|[Erro do compilador C2057](compiler-error-c2057.md)|expressão de constante esperada|
|[Erro do compilador C2058](compiler-error-c2058.md)|expressão de constante não é integral|
|[Erro do compilador C2059](compiler-error-c2059.md)|Erro de sintaxe: '*token*'|
|[Erro do compilador C2060](compiler-error-c2060.md)|Erro de sintaxe: final do arquivo encontrado|
|[Erro do compilador C2061](compiler-error-c2061.md)|Erro de sintaxe: identificador '*identificador*'|
|[Erro do compilador C2062](compiler-error-c2062.md)|tipo de '*tipo*' inesperado|
|[Erro do compilador C2063](compiler-error-c2063.md)|'*identificador*': não é uma função|
|[Erro do compilador C2064](compiler-error-c2064.md)|termo não é avaliada como obter uma função *número* argumentos|
|[Erro do compilador C2065](compiler-error-c2065.md)|'*identificador*': identificador não declarada|
|[Erro do compilador C2066](compiler-error-c2066.md)|conversão para tipo de função é inválida|
|[Erro do compilador C2067](compiler-error-c2067.md)|conversão para tipo de matriz é inválida|
|C2068 de erro do compilador|uso ilegal de função sobrecarregada. Lista de argumentos ausente?|
|[Erro do compilador C2069](compiler-error-c2069.md)|conversão de termo 'void' não 'void'|
|[Erro do compilador C2070](compiler-error-c2070.md)|'*tipo*': operando de sizeof inválido|
|[Erro do compilador C2071](compiler-error-c2071.md)|'*identificador*': classe de armazenamento inválida|
|[Erro do compilador C2072](compiler-error-c2072.md)|'*identificador*': a inicialização de uma função|
|[Erro do compilador C2073](compiler-error-c2073.md)|'*identificador*': elementos de matriz parcialmente inicializada devem ter um construtor padrão|
|[Erro do compilador C2074](compiler-error-c2074.md)|'*identificador*': '*tipo*' inicialização requer uma lista de inicializadores entre chaves|
|[Erro do compilador C2075](compiler-error-c2075.md)|'*identificador*': inicialização de matriz requer uma lista de inicializadores entre chaves|
|C2076 de erro do compilador|uma lista de inicializadores entre chaves não pode ser usada em uma new-expression cujo tipo contém '*tipo*'|
|[Erro do compilador C2077](compiler-error-c2077.md)|inicializador de campo não escalar '*identificador*'|
|[Erro do compilador C2078](compiler-error-c2078.md)|número excessivo de inicializadores|
|[Erro do compilador C2079](compiler-error-c2079.md)|'*identificador*'usa indefinido em classe/struct/união'*tipo*'|
|C2080 de erro do compilador|'*identificador*': o tipo para '*tipo*' só pode ser deduzido a partir de uma expressão de inicializador único|
|[Erro do compilador C2081](compiler-error-c2081.md)|'*identificador*': nome ilegal da lista de parâmetros formais|
|[Erro do compilador C2082](compiler-error-c2082.md)|redefinição de parâmetro formal '*identificador*'|
|[Erro do compilador C2083](compiler-error-c2083.md)|comparação de struct/união ilegal|
|[Erro do compilador C2084](compiler-error-c2084.md)|função '*identificador*' já tem um corpo|
|[Erro do compilador C2085](compiler-error-c2085.md)|'*identificador*': não está na lista de parâmetros formais|
|[Erro do compilador C2086](compiler-error-c2086.md)|'*identificador*': redefinição|
|[Erro do compilador C2087](compiler-error-c2087.md)|'*identificador*': faltando subscrito|
|[Erro do compilador C2088](compiler-error-c2088.md)|'*operador*': inválido para classe/struct/união|
|[Erro do compilador C2089](compiler-error-c2089.md)|'*identificador*': '*tipo*' muito grande|
|[Erro do compilador C2090](compiler-error-c2090.md)|função retorna a matriz|
|[Erro do compilador C2091](compiler-error-c2091.md)|função retorna a função|
|[Erro do compilador C2092](compiler-error-c2092.md)|'*identificador*' tipo de elemento de matriz não pode ser uma função|
|[Erro do compilador C2093](compiler-error-c2093.md)|'*identifier1*': não pode ser inicializado usando endereço da variável automática '*identifier2*'|
|[Erro do compilador C2094](compiler-error-c2094.md)|rótulo '*identificador*' não definida|
|[Erro do compilador C2095](compiler-error-c2095.md)|'*função*': parâmetro real possui tipo 'void': parâmetro *número*|
|C2096 de erro do compilador|'*identificador*': um membro de dados não pode ser inicializado com um inicializador entre parênteses|
|[Erro do compilador C2097](compiler-error-c2097.md)|inicialização ilegal|
|C2098 de erro do compilador|token inesperado após o membro de dados '*identificador*'|
|[Erro do compilador C2099](compiler-error-c2099.md)|inicializador não é uma constante|

---
title: '#definir a diretiva (C/C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '#define'
dev_langs:
- C++
helpviewer_keywords:
- define directive (#define), syntax
- preprocessor, directives
- define directive (#define)
- '#define directive, syntax'
- '#define directive'
ms.assetid: 33cf25c6-b24e-40bf-ab30-9008f0391710
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8875c2b2c744a16f936fd2220826f23413a0e6c9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="define-directive-cc"></a>Diretiva #define (C/C++)
O `#define` cria um *macro*, que é a associação de um identificador ou identificador com parâmetros com uma cadeia de caracteres de token. Após a definição da macro, o compilador pode substituir a cadeia de caracteres de token para cada ocorrência do identificador no arquivo de origem.  
  
## <a name="syntax"></a>Sintaxe  
 `#define` *identificador* *cadeia de caracteres de token*aceitar  
  
 `#define` *identificador* `(` *identificador*aceitação`,`*...*  `,` *identificador*aceitação`)`*cadeia de caracteres de token*aceitar  
  
## <a name="remarks"></a>Comentários  
 O `#define` diretiva faz com que o compilador substituir *cadeia de caracteres de token* para cada ocorrência do *identificador* no arquivo de origem. O *identificador* é substituído somente quando constitui um token. Ou seja, *identificador* não será substituído se ele for exibido em um comentário em uma cadeia de caracteres ou como parte de um identificador de mais tempo. Para obter mais informações, consulte [Tokens](../cpp/tokens-cpp.md).  
  
 O *cadeia de caracteres de token* argumento consiste em uma série de símbolos, como palavras-chave, constantes ou instruções concluídas. Um ou mais caracteres de espaço em branco necessário separar *cadeia de caracteres de token* de *identificador*. Esse espaço em branco não é considerado parte do texto substituído, nem de qualquer espaço em branco que siga o último token do texto.  
  
 Um `#define` sem um *cadeia de caracteres de token* remove ocorrências de *identificador* do arquivo de origem. O *identificador* permanece definido e pode ser testado usando o `#if defined` e `#ifdef` diretivas.  
  
 A segunda forma de sintaxe define uma macro do tipo função com parâmetros. Essa forma aceita uma lista opcional de parâmetros que devem aparecer entre parênteses. Depois que a macro é definida, cada subsequentes de *identificador*( *identificador*opt,..., *identificador*aceitar) é substituído por uma versão do  *cadeia de caracteres de token* argumento que tem argumentos reais substituídos por parâmetros formais.  
  
 Os nomes de parâmetro formal aparecem na *cadeia de caracteres de token* para marcar os locais onde os valores reais são substituídos. Cada nome de parâmetro pode aparecer várias vezes em *cadeia de caracteres de token*, e os nomes podem aparecer em qualquer ordem. O número de argumentos na chamada deve coincidir com o número de parâmetros na definição da macro. O uso liberal dos parênteses garante que os argumentos complexos reais sejam interpretados corretamente.  
  
 Os parâmetros formais na lista são separados por vírgulas. Cada nome da lista deve ser exclusivo, e a lista deve ser colocada entre parênteses. Sem espaços podem separar *identificador* e o parêntese de abertura. Use a concatenação de linha — coloque uma barra invertida (`\`) imediatamente antes do caractere de nova linha — para diretivas longo em várias linhas de origem. Amplia o escopo de um nome de parâmetro formal para a nova linha que termina *cadeia de caracteres de token*.  
  
 Quando uma macro é definida na segunda forma de sintaxe, as instâncias textuais subsequentes seguidas por uma lista de argumentos indicam uma chamada de macro. Os argumentos reais que segue uma instância de *identificador* no arquivo de origem são comparados com os parâmetros formais correspondentes na definição de macro. Cada parâmetro formal *cadeia de caracteres de token* que não for precedido por um stringizing (`#`), de caracterização (`#@`), ou a colagem de token (`##`) operador, ou não seguido por um `##` operador, é substituído pelo argumento correspondente. As macros no argumento real são expandidas antes da política substituir o parâmetro formal. (Os operadores são descritos na [operadores de pré-processador](../preprocessor/preprocessor-operators.md).)  
  
 Os exemplos de macros com argumentos a seguir ilustram a segunda forma da sintaxe `#define`:  
  
```  
// Macro to define cursor lines   
#define CURSOR(top, bottom) (((top) << 8) | (bottom))  
  
// Macro to get a random integer with a specified range   
#define getrandom(min, max) \  
    ((rand()%(int)(((max) + 1)-(min)))+ (min))  
```  
  
 Os argumentos com efeitos colaterais às vezes fazem com que as macros produzam resultados inesperados. Um determinado parâmetro formal pode aparecer mais de uma vez na *cadeia de caracteres de token*. Se o parâmetro formal for substituído por uma expressão com efeitos colaterais, a expressão, com seus efeitos colaterais, poderá ser avaliada mais de uma vez. (Consulte os exemplos em [operador de colagem de Token (#)](../preprocessor/token-pasting-operator-hash-hash.md).)  
  
 A política `#undef` faz com que a definição de pré-processador de um identificador seja esquecida. Consulte [a diretiva #undef](../preprocessor/hash-undef-directive-c-cpp.md) para obter mais informações.  
  
 Se o nome da macro que está sendo definido ocorre em *cadeia de caracteres de token* (mesmo em decorrência de expansão de macro outro), ele não está expandido.  
  
 Um segundo `#define` para uma macro com o mesmo nome gera um aviso, a menos que a segunda sequência de token seja idêntica à primeira.  
  
 **Seção específica da Microsoft**  
  
 O Microsoft C/C++ permite que você redefina uma macro se a nova definição for sintaticamente idêntica à definição original. Ou seja, as duas definições podem ter nomes de parâmetro diferentes. Esse comportamento difere do [!INCLUDE[vcpransi](../atl-mfc-shared/reference/includes/vcpransi_md.md)] C, que requer que as duas definições sejam lexicalmente idênticas.  
  
 Por exemplo, as duas macros a seguir são idênticas, exceto os nomes de parâmetro. [!INCLUDE[vcpransi](../atl-mfc-shared/reference/includes/vcpransi_md.md)] C não suporta tal uma redefinição, mas a Microsoft C/C++ compila sem erro.  
  
```  
#define multiply( f1, f2 ) ( f1 * f2 )  
#define multiply( a1, a2 ) ( a1 * a2 )  
```  
  
 Por outro lado, as duas macros a seguir não são idênticas e irão gerar um aviso no Microsoft C/C++.  
  
```  
#define multiply( f1, f2 ) ( f1 * f2 )  
#define multiply( a1, a2 ) ( b1 * b2 )  
```  
  
 **Fim da seção específica da Microsoft**  
  
 Este exemplo ilustra a política `#define`:  
  
```  
#define WIDTH       80  
#define LENGTH      ( WIDTH + 10 )  
```  
  
 A primeira declaração define o identificador `WIDTH` como a constante inteira 80 e define `LENGTH` em termos de `WIDTH` e da constante inteira 10. Cada ocorrência de `LENGTH` é substituída por (`WIDTH + 10`). Por sua vez, cada ocorrência de `WIDTH + 10` é substituída pela expressão (`80 + 10`). Os parênteses em torno de `WIDTH + 10` são importantes porque controlam a interpretação em instruções como esta:  
  
```  
var = LENGTH * 20;  
```  
  
 Após o estágio de pré-processamento, a instrução se torna:  
  
```  
var = ( 80 + 10 ) * 20;  
```  
  
 que é avaliado em 1800. Sem parênteses, o resultado é:  
  
```  
var = 80 + 10 * 20;  
```  
  
 que é avaliada como 280.  
  
 **Seção específica da Microsoft**  
  
 Definindo macros e constantes com o [/D](../build/reference/d-preprocessor-definitions.md) opção de compilador tem o mesmo efeito que usar um `#define` diretiva de pré-processamento no início do arquivo. Até 30 macros podem ser definidas usando a opção /D.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)
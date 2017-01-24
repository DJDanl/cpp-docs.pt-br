---
title: "Diretiva #define (C/C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "#define"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #define"
  - "Diretiva #define, sintaxe"
  - "diretiva define (#define)"
  - "diretiva define (#define), sintaxe"
  - "pré-processador, Diretivas ()"
ms.assetid: 33cf25c6-b24e-40bf-ab30-9008f0391710
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretiva #define (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`#define` cria uma *macro*, que é a associação de um identificador ou de identificador parametrizado a uma cadeia de caracteres de token.  Após a definição da macro, o compilador pode substituir a cadeia de caracteres de token para cada ocorrência do identificador no arquivo de origem.  
  
## Sintaxe  
 `#define` *identifier* *token\-string*opt  
  
 `#define` *identifier*`(` *identifier*opt`,` *...* `,` *identifier*opt `)` *token\-string*opt  
  
## Comentários  
 A política `#define` faz com que o compilador substitua *token\-string* para cada ocorrência de *identifier* no arquivo de origem.  O *identifier* só será substituído quando formar um token.  Ou seja, *identifier* não será substituído se aparecer em um comentário, em uma cadeia de caracteres ou como parte de um identificador mais longo.  Para obter mais informações, consulte [Tokens](../cpp/tokens-cpp.md).  
  
 O argumento *token\-string* consiste em uma série de tokens, como palavras\-chave, constantes ou instruções completas.  Um ou mais caracteres de espaço em branco devem separar *token\-string* de *identifier*.  Esse espaço em branco não é considerado parte do texto substituído, nem de qualquer espaço em branco que siga o último token do texto.  
  
 `#define` sem *token\-string* remove as ocorrências de *identifier* do arquivo de origem.  *identifier* permanece definido e pode ser testado usando as políticas `#if defined` e `#ifdef`.  
  
 A segunda forma de sintaxe define uma macro do tipo função com parâmetros.  Essa forma aceita uma lista opcional de parâmetros que devem aparecer entre parênteses.  Após a definição da macro, cada ocorrência subsequente de *identifier* \(*identifier*opt, ..., *identifier*opt\) é substituída por uma versão do argumento *token\-string* que possui os argumentos reais substituídos por parâmetros formais.  
  
 Os nomes de parâmetros formais aparecem em *token\-string* para marcar os locais onde os valores reais são substituídos.  Cada nome de parâmetro pode aparecer várias vezes em *token\-string*, e os nomes podem aparecer em qualquer ordem.  O número de argumentos na chamada deve coincidir com o número de parâmetros na definição da macro.  O uso liberal dos parênteses garante que os argumentos complexos reais sejam interpretados corretamente.  
  
 Os parâmetros formais na lista são separados por vírgulas.  Cada nome da lista deve ser exclusivo, e a lista deve ser colocada entre parênteses.  Nenhum espaço pode separar *identifier* e o parêntese de abertura.  Use a concatenação de linha – coloque uma barra invertida \(`\`\) imediatamente antes do caractere de nova linha – para políticas longas em várias linhas de código\-fonte.  O escopo de um nome de parâmetro formal estende\-se à nova linha que termina *token\-string*.  
  
 Quando uma macro é definida na segunda forma de sintaxe, as instâncias textuais subsequentes seguidas por uma lista de argumentos indicam uma chamada de macro.  Os argumentos reais que seguem uma instância de *identifier* no arquivo de origem são correlacionados aos parâmetros formais na definição da macro.  Cada parâmetro formal em *token\-string* que não é precedido de um operador stringizing \(`#`\), charizing \(`#@`\) ou token\-pasting \(`##`\), ou não é seguido por um operador `##`, é substituído pelo argumento correspondente real.  As macros no argumento real são expandidas antes da política substituir o parâmetro formal. \(Os operadores são descritos em [Operadores do pré\-processador](../preprocessor/preprocessor-operators.md).\)  
  
 Os exemplos de macros com argumentos a seguir ilustram a segunda forma da sintaxe `#define`:  
  
```  
// Macro to define cursor lines   
#define CURSOR(top, bottom) (((top) << 8) | (bottom))  
  
// Macro to get a random integer with a specified range   
#define getrandom(min, max) \  
    ((rand()%(int)(((max) + 1)-(min)))+ (min))  
```  
  
 Os argumentos com efeitos colaterais às vezes fazem com que as macros produzam resultados inesperados.  Um parâmetro formal determinado pode aparecer mais de uma vez em *token\-string*.  Se o parâmetro formal for substituído por uma expressão com efeitos colaterais, a expressão, com seus efeitos colaterais, poderá ser avaliada mais de uma vez. \(Consulte os exemplos em [Operador Token\-Pasting \(\#\#\)](../preprocessor/token-pasting-operator-hash-hash.md).\)  
  
 A política `#undef` faz com que a definição de pré\-processador de um identificador seja esquecida.  Consulte [A política \#undef](../preprocessor/hash-undef-directive-c-cpp.md) para obter mais informações.  
  
 Se o nome da macro que está sendo definida ocorrer em *token\-string* \(mesmo em resultado de outra expansão de macro\), ele não será expandido.  
  
 Um segundo `#define` para uma macro com o mesmo nome gera um aviso, a menos que a segunda sequência de token seja idêntica à primeira.  
  
 **Específico da Microsoft**  
  
 O Microsoft C\/C\+\+ permite que você redefina uma macro se a nova definição for sintaticamente idêntica à definição original.  Ou seja, as duas definições podem ter nomes de parâmetro diferentes.  Esse comportamento difere do [!INCLUDE[vcpransi](../preprocessor/includes/vcpransi_md.md)] C, que requer que as duas definições sejam lexicalmente idênticas.  
  
 Por exemplo, as duas macros a seguir são idênticas, exceto os nomes de parâmetro.  O [!INCLUDE[vcpransi](../preprocessor/includes/vcpransi_md.md)] C não permite uma redefinição, mas o Microsoft C\/C\+\+ compila sem erro.  
  
```  
#define multiply( f1, f2 ) ( f1 * f2 )  
#define multiply( a1, a2 ) ( a1 * a2 )  
```  
  
 Por outro lado, as duas macros a seguir não são idênticas e irão gerar um aviso no Microsoft C\/C\+\+.  
  
```  
#define multiply( f1, f2 ) ( f1 * f2 )  
#define multiply( a1, a2 ) ( b1 * b2 )  
```  
  
 **FIM de Específico da Microsoft**  
  
 Este exemplo ilustra a política `#define`:  
  
```  
#define WIDTH       80  
#define LENGTH      ( WIDTH + 10 )  
```  
  
 A primeira declaração define o identificador `WIDTH` como a constante inteira 80 e define `LENGTH` em termos de `WIDTH` e da constante inteira 10.  Cada ocorrência de `LENGTH` é substituída por \(`WIDTH + 10`\).  Por sua vez, cada ocorrência de `WIDTH + 10` é substituída pela expressão \(`80 + 10`\).  Os parênteses em torno de `WIDTH + 10` são importantes porque controlam a interpretação em instruções como esta:  
  
```  
var = LENGTH * 20;  
```  
  
 Após o estágio de pré\-processamento, a instrução se torna:  
  
```  
var = ( 80 + 10 ) * 20;  
```  
  
 que é avaliado em 1800.  Sem parênteses, o resultado é:  
  
```  
var = 80 + 10 * 20;  
```  
  
 que é avaliado em 280.  
  
 **Específico da Microsoft**  
  
 A definição de macros e constantes com a opção do compilador [\/D](../build/reference/d-preprocessor-definitions.md) tem o mesmo efeito que usar uma política de pré\-processamento `#define` no início do arquivo.  Até 30 macros podem ser definidas usando a opção \/D.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)
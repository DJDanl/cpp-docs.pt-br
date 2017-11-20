---
title: "Protótipos de função | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- function prototypes
- function return types, function prototypes
- data types [C], function return types
- functions [C], return types
- prototypes [C++], function
ms.assetid: d152f8e6-971e-432c-93ca-5a91400653c2
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ceccc88737b90e8833c2a9e087dfa9540dfa13d0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="function-prototypes"></a>Protótipos de função
Uma declaração de função precede a definição de função e especifica o nome, o tipo de retorno, a classe de armazenamento e os outros atributos de uma função. Para ser um protótipo, a declaração de função também deve estabelecer os tipos e identificadores dos argumentos da função.  
  
## <a name="syntax"></a>Sintaxe  
 `declaration`:  
 *declaration-specifiers attribute-seq* opt*init-declarator-list* opt**;**  
  
 /\* *attribute-seq* opt é específico da Microsoft */  
  
 *declaration-specifiers*:  
 *storage-class-specifier declaration-specifiers* opt  
  
 *type-specifier declaration-specifiers* opt  
  
 *type-qualifier declaration-specifiers* opt  
  
 *init-declarator-list*:  
 *init-declarator*  
  
 *init-declarator-list*  **,**  *init-declarator*  
  
 *init-declarator*:  
 *declarator*  
  
 *declarator = initializer*  
  
 `declarator`:  
 *pointer* opt*direct-declarator*  
  
 *direct-declarator*: /\* Um declarador de função \*/  
 *direct-declarator*  **(**  *parameter-type-list*  **)**  /* Declarador de novo estilo \*/  
  
 *direct-declarator*  **(**  *identifier-list* opt**)** /* Declarador de estilo obsoleto \*/  
  
 O protótipo tem o mesmo formato que a definição de função, exceto que é ele é encerrado por um ponto-e-vírgula imediatamente depois do parêntese de fechamento e, portanto, não tem corpo. Em ambos os casos, o tipo de retorno deve concordar com o tipo de retorno especificado na definição de função.  
  
 Os protótipos de função têm os seguintes usos importantes:  
  
-   Eles estabelecem o tipo de retorno para funções que retornam tipos diferentes de `int`. Embora as funções que retornem valores `int` não precisem de protótipos, os protótipos são recomendados.  
  
-   Sem protótipos completos, as conversões padrão são feitas, mas nenhuma tentativa será feita para verificar o tipo ou o número de argumentos com o número de parâmetros.  
  
-   Os protótipos são usados para inicializar ponteiros para as funções antes que essas funções sejam definidas.  
  
-   A lista de parâmetros é usada para verificar a correspondência de argumentos na chamada de função com os parâmetros na definição de função.  
  
 O tipo convertido de cada parâmetro determina a interpretação dos argumentos que a chamada de função coloca na pilha. Uma incompatibilidade entre um argumento e um parâmetro pode fazer com que os argumentos na pilha sejam interpretados incorretamente. Por exemplo, em um computador de 16 bits, se um ponteiro de 16 bits for passado como um argumento e então declarado como um parâmetro **long**, os primeiros 32 bits da pilha serão interpretados como um parâmetro **long**. Esse erro cria problemas não somente com o parâmetro **long**, mas com todos os parâmetros que o seguem. Você pode detectar erros desse tipo declarando protótipos de função completos para todas as funções.  
  
 Um protótipo estabelece os atributos de uma função de forma que as chamadas para a função que precedem sua definição (ou ocorrem em outros arquivos de origem) possam ser verificadas quanto a incompatibilidades de tipo de argumento e de retorno. Por exemplo, se você especificar o especificador de classe de armazenamento **static** em um protótipo, também deve especificar a classe de armazenamento **static** na definição de função.  
  
 As declarações completas de parâmetro (`int a`) podem ser combinadas com os declaradores abstratos (`int`) na mesma instrução. Por exemplo, a declaração a seguir é aceitável:  
  
```  
int add( int a, int );  
```  
  
 O protótipo pode incluir o tipo e um identificador para cada expressão que é passada como um argumento. Porém, tais identificadores têm escopo apenas até o final da declaração. O protótipo também pode refletir o fato de que o número de argumentos é variável ou que nenhum argumento é passado. Sem essa lista, as incompatibilidades podem não ser reveladas, para que o compilador não gere mensagens de diagnóstico relacionadas a elas. Consulte [Argumentos](../c-language/arguments.md) para obter mais informações sobre verificação de tipo.  
  
 O escopo de protótipo no compilador do Microsoft C agora está em conformidade com ANSI ao compilar com a opção do compilador /Za. Isso significa que se você declarar uma marca `struct` ou **union** dentro de um protótipo, a marca é inserida nesse escopo em vez do escopo global. Por exemplo, ao compilar com /Za para estar em conformidade com ANSI, você nunca pode chamar essa função sem receber um erro de incompatibilidade:  
  
```  
void func1( struct S * );  
```  
  
 Para corrigir seu código, defina ou declare o `struct` ou **union** no escopo global antes de protótipo da função:  
  
```  
struct S;  
void func1( struct S * );  
```  
  
 Em /Ze, a marca ainda é inserida no escopo global.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../c-language/functions-c.md)
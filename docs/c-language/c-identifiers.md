---
title: Identificadores C | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- identifiers, C
- naming identifiers
- identifiers
- symbols, C identifiers
- identifiers, case sensitivity
- symbols, case sensitivity
ms.assetid: d02edbbc-85a0-4118-997b-84ee6b972eb6
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dfe8ab231d6bf4051cc730ff1beb23f93a8f301d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-identifiers"></a>Identificadores C
Os "identificadores" ou "símbolos" são os nomes que você fornece para variáveis, tipos, funções e rótulos em seu programa. Os nomes de identificadores devem ser diferentes na ortografia e nas maiúsculas e minúsculas de todas as palavras-chave. Você não pode usar palavras-chave (no C ou Microsoft) como identificadores; elas são reservadas para uso especial. Você cria um identificador especificando-o na declaração de variável, tipo ou função. Neste exemplo, `result` é um identificador para uma variável de inteiro, e `main` e `printf` são nomes de identificadores para funções.  
  
```  
#include <stdio.h>  
  
int main()  
{  
    int result;  
  
    if ( result != 0 )  
        printf_s( "Bad file handle\n" );  
}  
```  
  
 Após a declaração, você pode usar o identificador em instruções de programa posteriores para fazer referência ao valor associado.  
  
 Um tipo especial de identificador, chamado de rótulo da instrução, pode ser usado em instruções `goto`. (Declarações são descritas em [Declarações e tipos](../c-language/declarations-and-types.md) Rótulos de instrução são descritos em [Instruções goto e rotuladas](../c-language/goto-and-labeled-statements-c.md).)  
  
## <a name="syntax"></a>Sintaxe  
 *identifier*:  
 *nondigit*  
  
 *identifier nondigit*  
  
 *identifier digit*  
  
 `nondigit`: um de  
 **_ a b c d e f g h i j k l m n o p q r s t u v w x y z**  
  
 **A B C D E F G H I J K L M N O P Q R S T U V W X Y Z**  
  
 `digit`: um de  
 **0 1 2 3 4 5 6 7 8 9**  
  
 O primeiro caractere do nome de identificador deve ser `nondigit` (ou seja, o primeiro caractere deve ser um sublinhado ou letra maiúscula ou minúscula). Permite seis caracteres ANSI significativos em um nome de identificador externo e 31 para nomes (dentro de uma função) de identificadores internos. Os identificadores externos (os declarados no escopo global ou declarados com a classe de armazenamento `extern`) podem estar sujeitos às restrições de nomeação adicionais, pois esses identificadores precisam ser processados por outro software, como vinculadores.  
  
 **Seção específica da Microsoft**  
  
 Ainda que o ANSI permita 6 caracteres significativos em nomes de identificadores externos e 31 para nomes (dentro de uma função) de identificadores internos, o compilador do C da Microsoft permite 247 caracteres em um nome de identificador interno ou externo. Se você não tiver preocupado com compatibilidade de ANSI, pode alterar esse padrão para um número menor ou maior usando a opção /H (restringe o comprimento dos nomes externos).  
  
 **Fim da seção específica da Microsoft**  
  
 O compilador do C considerará as letras maiúsculas e minúsculas como caracteres distintos. Esse recurso, chamado de "diferenciação de maiúsculas e minúsculas" permite que você crie identificadores distintos que têm a mesma ortografia mas maiúsculas e minúsculas diferentes para uma ou mais letras. Por exemplo, cada um dos seguintes identificadores é exclusivo:  
  
```  
add  
ADD  
Add  
aDD  
```  
  
 **Seção específica da Microsoft**  
  
 Não selecione nomes dos identificadores que comecem com dois sublinhados ou com um sublinhado seguido por uma letra maiúscula. O padrão ANSI C permite que os nomes dos identificadores que começam com essas combinações de caracteres sejam reservados para uso pelo compilador. Os identificadores com escopo no nível de arquivo não devem ser nomeados com um sublinhado e uma letra minúscula como as duas primeiras letras. Os nomes de identificadores que começam com esses caracteres também são reservados. Por convenção, a Microsoft usa um sublinhado e uma letra maiúscula para iniciar nomes de macro e sublinhados duplos para nomes de palavras-chave específicos da Microsoft. Para evitar conflitos de nomenclatura, sempre selecione nomes do identificador que não comecem com um ou os dois sublinhados, ou os nomes que comecem com um sublinhado seguido por uma letra maiúscula.  
  
 **Fim da seção específica da Microsoft**  
  
 Os exemplos a seguir são identificadores válidos em conformidade com restrições de nome de ANSI ou Microsoft:  
  
```  
j  
count  
temp1  
top_of_page  
skip12  
LastNum  
```  
  
 **Seção específica da Microsoft**  
  
 Ainda que os identificadores nos arquivos de origem tenham diferenciação de maiúsculas e minúsculas por padrão, os símbolos nos arquivos de objeto não são. O Microsoft C trata os identificadores em uma unidade de compilação com diferenciação de maiúsculas e minúsculas.  
  
 O vinculador da Microsoft faz diferenciação de maiúsculas e minúsculas. Você deve especificar todos os identificadores consistentemente de acordo com maiúsculas e minúsculas.  
  
 O "conjunto de caracteres de origem" é o conjunto de caracteres válidos que podem aparecer nos arquivos de origem. Para o Microsoft C, o conjunto de origem é o conjunto de caracteres ASCII padrão. O conjunto de caracteres de origem e o conjunto de caracteres de execução incluem os caracteres ASCII usados como sequências de escape. Consulte [Constantes de caractere](../c-language/c-character-constants.md) para obter informações sobre o conjunto de caracteres de execução.  
  
 **Fim da seção específica da Microsoft**  
  
 Um identificador tem “escopo”, que é a região de programa em que é conhecido, e “vinculação”, que determina se o mesmo nome em outro escopo faz referência ao mesmo identificador. Esses tópicos são explicados em [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md).  
  
## <a name="see-also"></a>Consulte também  
 [Elementos de C](../c-language/elements-of-c.md)